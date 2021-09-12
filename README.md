# leetcode

leetcode 刷题记录

- 想起来就刷
- 有空了刷
- 开发语言可能是 __c__,__c++__,__java__,__python__

## 刷题过程中的积累

### 位操作

- a ^ b = c 则 c ^ a = b 且 c ^b = a 异或操作
- x=x & (x−1) 将x的最后一个1变为0
- x 除以 2 的余数可以通过 x & 1 得到

- 进制转换 任意k进制转十进制 int(n,k) n为字符串,十进制转任意进制 

```python
b=[]
while True:
    s=n//x  # 商
    y=n%x  # 余数
    b=b+[y]
    if s==0:
        break
    n=s
b.reverse()
```

- 返回两个整数的最大值 int((abs(a-b)+a+b)/2)

- 求所有子集合

### 链表

- 快慢节点法
- 通常最后一个节点会有特殊情况处理时应特别注意
- 对于需要分割链表节点的题目，可以分设两个头节点，遍历过程中将节点分别连接到对应头节点之后，最后再将各个链表首位链接 (86)

- 使用c语言时注意编译的命令为

```bash
gcc -O -g -fsanitize=address 696.c
```

可模拟leetcode编译过程

## c语言中操作速度对比

- 判断等于比判断不等于更快
- if 判断比 三元运算符更快
- 互相等效的多句算数运算比单句算数运算慢

## c struct 结构体使用tips

- 使用结构体，结构体的属性需要初始化，初始化代码

```.c
struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
```

## c 字符操作

## c 多维数组

## c 指针

## 动态规划题集

[https://www.nowcoder.com/practice/f9c6f980eeec43ef85be20755ddbeaf4?tpId=37&tags=&title=&diffculty=0&judgeStatus=0&rp=1&tab=answerKey] 背包问题

[https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/]连续子数组最大和

## 知识点

- 暴力解法
- DP
- DFS
- WFS
- 狄杰斯特拉算法
- 二叉树
- 组合数学
- 逆元
- 位运算
- 二分法

## dp类型

- 最长子字符串 dp[i][j] 表示第t字符串i个位置与s字符串第j个位置的最大子串字符数 dp[i][j] = max{dp[i][j-1]+1,dp[i][j-1]}
- 爬楼梯与斐波那契数列 dp[i] = dp[i-1]+dp[i-2]
- 投资股票问题dp[i]
- 从棋盘拿价值最大棋子
- 01背包问题
- 最长回文子串

索引
文件
回表
常用容器
内存管理
线程安全
redis
