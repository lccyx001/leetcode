# class 与 struct

## '.'和'->'运算符

1、“.”是成员运算符，用于调取成员变量和成员函数；符号“.”的左边必须是实例对象（具体对象），举例为绿色字体；

2、“->”是地址运算符，用于引用成员变量和成员函数；符号“->”的左边是实例对象的地址或者类名（结构名），举例为黄色字体；

3、等价形式：d.msg() 和 (*cpt).msg() 等价；c.cid 和 (*spt).cid；

## 构造函数

与类名字一样

### 使用初始化列表初始化字段

```cpp
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//equals to 
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()  {this->val=0;this->next=nullptr;}
    ListNode(int x)  {this->val=0;this->next=nullptr;}
    ListNode(int x, ListNode *next)  {this->val=0;this->next=next;}
};
```
