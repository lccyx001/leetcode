# 笔记

## c语言判断空指针

```
int* ptr;
if (!prt) (常用)
if (ptr == NULL)

```

## 使用malloc函数

动态数组需要使用malloc函数声明
调用malloc函数之后，要检查返回的指针是否为空，检查os无法分配内存的情况
