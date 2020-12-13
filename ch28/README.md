Lock
---

## 实现一个锁

### 锁的评价标准

- 提供互斥 mutual exclusion
- 公平性 fairness
- 性能 performance

### 可能的方式

#### 1. 控制中断：在 critical sections关闭中断机制


```C
var lock () {
    DisableInterrupts();
}
var unlock() {
    EnableInterrupts();
}
```
优点：简单
缺点：
    - 需要相信任意一个程序不会滥用这个机制
    - 不支持多处理器
    - 开/关中断效率比较低

#### 2. test-and-set 
```C
typedef struct lock_t { int flag; } lock_t;

void init(lock_t *mutex) {
    // 0: lock is available, 1: held
    mutex->flag = 0;
}

int TestAndSet(int *old_ptr, int new) {
    int old = *old_ptr;
    *old_ptr = new;
    return old;
}

void lock(lock_t *mutex) {
    // while (mutex->flag ==1)
    //    ;
    // mutex->flag = 1;
    
    while (TestAndSet(mutex->flag, 1) == 1)
        ;
}

void unlock(lock_t *mutex) {
    mutex->flaf = 0;
}
```
优点：可以保证互斥
缺点：
    - 一直spin自旋，浪费CPU
    - 不保证公平性
    
x86有一个类似的原子指令CAS
```C
int CompareAndSwap(int *ptr, int expected, int new) {
    int actual = *ptr;
    if (actual == expected) 
        *ptr = new;
    return actual;

}
```

#### 3 fetch-and-add
保证了互斥和公平性
```C
int FetchAndAdd(int *ptr) {
    int old = *ptr;
    *ptr = old + 1;
    return old;
}

typedef struct lock_t {
    int ticket;
    int turn;
} lock_t;

void lock_init(lock_t lock) {
    lock->ticket = 0;
    lock->turn = 0;
}

void lock(lock_t lock) {
    int myturn = FetchAndAdd(&lock->ticket);
    while (lock->turn != myturn)
        ;
}

void unlock(lock_t *lock) {
    FetchAndSet(&lock->turn);
}
```

自旋的解决方案

- yield
    - 两个线程以上的场景可能会反复处于让出-运行的状态；也可能会发生饥饿
- 队列
    
#### 4 queue  
```C
typedef struct lock_t {
    int flag;
    int guard;
    queue_t *q;
} lock_t;


void lock_init(lock_t *m) {
    m->flag = 0;
    m->guard = 0;
    queue_init(m->q) = 0;
}

void lock(lock_t *m) {
    while (TestAndSet(&m->guard, 1) ==1)
        ;
        
    if (m->flag == 0) {
        m->flag = 1;
        m->guard = 0;
    } else {
        queue_add(m->q, getid());
        m->guard = 0;
        park();
    }
}

void unlokc(lock_t *m) {
    while (TestAndSet(&m->guard, 1) == 1)
        ;
    
    if (queue_empty(m->q))
        m->flag = 0;
    else
        unpark(queue_remove(m->q));
        
    m-guard = 0;    
}
```
优点：
    - 引入队列保证公平性
缺点
    - 仍有自旋
    - 有可能在线程A准备park时线程B释放锁这样导致线程A永远不会唤醒，这种情况称之为wakeup/waiting race

#### 5 linux基于futex的实现

利用一个int32的数据来同时激励锁是否被持有(最高位)和等待者的个数(其余所有位)

```C
viod mutex_lock (int *mutex) {
    int v;
    // 当mux高位为0时表示锁没有被持有
    if (atomic_bit_test_set(mutex, 31) == 0)
        return
        
    atomic_increment(mutex);
    while(1) {
        if (atomic_bit_test_set(mutex, 31) == 0) {
            aotmic_decrement(mutex);
            return;
        }
        
        // 再次检查v,以免wakeup/waiting race
        v = *mutex;
        if(v>=0)
            continue;
            
        futex_wait(mutex, v);
    }
}

void mutex_unlock(int *mutex)  {
    // 无其他线程在等待
    if (atomic_add_zero(mutex, 0x80000000))
        return;
    
    futex_wake(mutex);
}

```

#### 6 two-phase-lock
- 首先自旋多次
- 还是锁冲突调用futex_wait


    
