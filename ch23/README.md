virtual memory system
---


- 代码段永远不会主从第0叶开始，该页被标记为不可访问，以便检测空指针(null-pointer)
- 内核被映射到每个每个space string,这样用户程序就可以应以的访问了

- demand zeroing: 分配的页直到真正使用时才将其置零
- copy on write: 将页映射到目标地址空间，在页有写入时才新分配一个页，填充数据