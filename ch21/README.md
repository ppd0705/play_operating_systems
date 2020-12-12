Beyond physical memory
---

swap space交换空间：用于武王城内存页的移入移出

PTE增加present bit存在位表示页是否在物理内存中

page fault页错误：访问页时在硬盘中，随之操作系统会被唤起执行page-fault-handler页错误处理程序

页错误处理程序执行流程
    - 找到一个可用的物理页
    - 读入硬盘数据
    - present bit标记为true
   

