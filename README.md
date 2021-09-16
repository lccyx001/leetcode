# leetcode

这是一个leetcode 刷题记录的项目，同时会记录刷题过程中对编程语言，算法等知识的总结。刷题频率随个人空闲时间变化。使用的开发语言随不同时间工作业务需要可能是
__c__,__c++__,__java__,__python__

## 刷题过程中的积累

### [c语言](./总结/c.md)

### [编码技巧与最佳实践](./总结/code.md)

### [位操作](./总结/bitoperator.md)

### [链表](./总结/linklist.md)

### [字符串](./总结/string.md)

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

## 面试问题

索引
文件
回表
常用容器
内存管理
线程安全
redis
