Memory API
---

### 内存类型

- 栈：编译器帮忙申请和释放内存
- 堆：程序员自主申请和释放

```C
void func() {
    int *x = (int *)malloc(sizeof(int));
    ...
    free(x)
}
```


### 其他

malloc和free只是库函数，本身建立在brk等系统调用之上