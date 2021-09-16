# c语言

- 使用c语言时注意编译时使用下面的命令，可模拟leetcode编译过程

```bash
gcc -O -g -fsanitize=address 696.c
```

- 判断等于比判断不等于更快
- if 判断比 三元运算符更快
- 互相等效的多句算数运算比单句算数运算慢
- 使用结构体，结构体的属性需要初始化，初始化代码例子

```.c
struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
```
