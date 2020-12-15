Condition Variable
---

条件变量

- 接口

```C
pthread_cond_wait(&cond, &mutex)  // 释放锁并等待
pthread_cond_signal(&cond)  // 唤醒一个等待线程
pthread_cond_broadcast(&cond)  // 唤醒所有的等待线程
```