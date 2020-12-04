Multiprocessor Scheduling 
---
局部性
- 时间局部性：一个数据被访问后，很可能不久会被再次访问
- 空间局部性：当程序访问地址为x的数据时，有可能会接着访问x周围的数据


调度策略
- 单队列调度 Single Queue Multiprocessor Scheduling
    - 可扩展性(scalability)问题：多个CPU竞争同一个锁，CPU越多，竞争越激烈
    - 缓存亲和性(cache affinity)问题，任务在多个CPU间调度，cache没有复用
    
- 多队列调度 Multi-Queue Multiprocessor Scheduling
  - 每个CPU一个队列，每个队列可以使用不同的调度规则
  - 任务在队列间负载可能不均，通过空间的CPU任务窃取work stealing，实现负载均衡

### Link

[调度系统设计精要](https://draveness.me/system-design-scheduler)

[Linux O(1)调度](https://zhuanlan.zhihu.com/p/33461281)

[cache coherence缓存一致性](https://juejin.cn/post/6844903877024677896)