Paging Intro
---

Page页：固定大小的内存分片

page table 页表：实现虚拟页和物理页的地址转换

通常虚拟地址会分为两部分：虚拟地址页序号（virtual page number VPN）、页内偏移量(offset)

物理页表项(page table  entry) 包含两部分：物理地址页序号(page frame number PFN)、多个标志位，标志位通常有：
- 有效位valid bit: 确定改地址是否被使用
- 保护位protection bit: 是否可读写
- 存在位present bit: 是在物理内存中还是swap磁盘区
- 访问位accessed bit: 是否被访问过，用于确定哪些也很受欢迎
- 脏位dirty bit: 分配后是否被修改过


