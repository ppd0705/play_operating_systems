TLB translation-lookaside-buffer
---


地址转换旁路缓冲(TLB)也称地址转换缓存(address translation cache)，缓存虚拟地址和物理地址转换

TLB组成 
    - VPN: 页表索引
    - PFN: 物理地址 
    - 其他标识位：是否有效、是否全局共享等
    
处理TLB
- 硬件：如x86架构，硬件知道页表基址，页表的结构固定
- 软件：灵活，可以使用任意结构实现页表，硬件比较简单


上下文切换
- 清空TLB，将有效位都置为0
- 在TLB中增加地址空间标识符(Address Space Identifier)，可以看作进程标识符，以区分不同进程