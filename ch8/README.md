The Multi-Level Feedback Queue
---


每个队列有不同的优先级，一个任务只能存在于一个队列，一个队列可能有多个任务


- 如果A的优先级>B的优先级，运行A
- 如果A的优先级=B的优先级，轮转运行A和B
- 任务进入系统时，先放在最高优先队列
- 任务一旦用完了骑在某一优先级队列的时间配额（无论中间主动放弃多少次），将降低其优先级
- 经过一段时间S，就将系统中所有工作重新加入最高优先级队列