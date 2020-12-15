Event-Based Concurrency
---


## 事件循环

```C
while(1) {
    events = getEvents();
    for (e in events)
        processEvent(e);
}

```

- [5中IO模型](https://www.cnblogs.com/findumars/p/6361627.html)