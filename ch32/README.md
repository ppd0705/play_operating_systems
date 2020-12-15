Concurrency Bugs
---


常见死锁原因
- atomicity violation 违反原子性
- ordering violation 违反顺序性

死锁产生的4个必要条件
- 互斥
- 持有并等待
- 非抢占
- 循环等待
 
解决思路
- 按顺序获取锁
- 使用trylock
- 使用原子指令来替换锁