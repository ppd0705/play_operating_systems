page replacement policy
---


平均内存访问时间(Average Memory Access Time AMMT) = P.Hit * T.M + P.Miss * T.D
即内存访问时间*缓存命中率+磁盘访问时间*缓存未命中率


- 最优替换策略（理想情况）：替换内存中在最远将来才会被访问的页
- FIFIO
- Random
- LRU
    - 近似LRU实现：时钟算法clock algorithm,使用一个时钟指针开始时指向一个随机的页，逐个扫描，直到扫到使用位位0的页
    
    
       