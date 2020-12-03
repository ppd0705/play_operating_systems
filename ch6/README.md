Limited Direct Execution
---

执行系统调用，普通进程从user mode trap到 kernel mode


进程切换的方式

- cooperative协作式
  - 假定进程会合理运行，运行过长的进程会定期放弃CPU,通过显示的yield系统调用，让出控制权
  - 非法操作也会陷入(trap)，操作系统也会重新获得控制权

- timer interrupt方式
  - 每隔几毫秒产生一次中断，产生中断后会运行interrupt handler，随之操作系统获得控制权
  - 时钟中断时会用硬件保存当前运行进程的寄存器