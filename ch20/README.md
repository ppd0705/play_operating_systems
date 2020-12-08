Smaller Tables
---

问题：线性页表占用内存过高，假设页大小4KB, 页表项PTE大小4Byte，地址空间为32位则页表占用内存2**32 / 2**12 * 4  / 1024/1024 = 4MB

方案
- 更大的页
- 分页和分段配合
- 多级页表multi-level page table
- 反向表 inverted page table: 所有进程共享一个page table, page table记录哪个进程正在使用某页，对应的虚拟地址是什么

多级页表multi-level page table

- 将多个PTE看成一个目录项Page Directory Entry(PDE), PDE有一个有效位，无效是整个PDE内的PTE都无效，所以不用分配内存

- 此时虚拟地址组成： |PDE index|PTE index|offset|其他标志位|