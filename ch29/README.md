Lock-based Concurrent Data Structures
---


操作系统在过渡到多核处理器时代时都是用一把大锁(BKL big kernel lock)保证安全

Linux直到2.6版本才移除BKL,采用更细粒度的锁以及引入RCU等无锁机制


ref
- [BKL-wiki](https://en.wikipedia.org/wiki/Giant_lock)

- [RCU介绍](https://www.ibm.com/developerworks/cn/linux/l-rcu/)