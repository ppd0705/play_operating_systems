THREADING API
---

### 线程
- create
```C
int pthread_create(
    pthread_t * thread;
    const pthread_attr_t  attr;
    void * (*start_routine)(void *);
    void * arg;
    )
```

- join

```C
pthread_join(pthread_t*, void * (return_val))
```

### 锁
### 条件变量



