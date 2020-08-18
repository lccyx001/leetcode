# leetcode

leetcode 刷题记录

- 想起来就刷
- 有空了刷
- 开发语言可能是 __c__,__c++__,__java__,__python__

## 刷题过程中的积累

- 使用c语言时注意编译的命令为

```bash
gcc -O -g -fsanitize=address 696.c
```

可模拟leetcode编译过程

## c语言中操作速度对比

- 判断等于比判断不等于更快
- if 判断比 三元运算符更快

## c struct 结构体使用tips

- 使用结构体，结构体的属性需要初始化，初始化代码

```.c
struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
```
