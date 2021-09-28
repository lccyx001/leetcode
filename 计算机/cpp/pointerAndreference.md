# 指针与引用

## 操作符

指针使用 __*__ 或者 __->__，引用使用 __&__

## 左值引用

常规引用，一般表示对象的身份。

## 右值引用

右值引用就是必须绑定到右值（一个临时对象、将要销毁的对象）的引用，一般表示对象的值。

右值引用可实现转移语义（Move Sementics）和精确传递（Perfect Forwarding），它的主要目的有两个方面：

- 消除两个对象交互时不必要的对象拷贝，节省运算存储资源，提高效率。
- 能够更简洁明确地定义泛型函数。

## 引用折叠

- X& &、X& &&、X&& & 可折叠成 X&
- X&& && 可折叠成 X&&

## 区别

- 没有null reference, reference总是代表一个对象。如果一个变量总是代表一个对象，则应该使用reference。

```cpp
// 不可以写以下代码，将会导致未知情况
char *p=0;
char &rp=*p;
```

- reference 可能会比pointer效率更高，因为不用检测有效性
- reference 总是指向最初被赋值的对象，pointer可以被重新赋值

## NULL 与 nullptr

- NULL是宏定义，nullptr是关键字
- 理论上指针可以完全沿用NULL，编译器也是完全支持的
- 如果是一个全新的项目，使用nullptr来标示指针
- 如果C++项目中大量使用了NULL，为保持统一，用NULL吧
- C/C++混合开发，用NULL
  
## const reference

考虑下面三段代码

```cpp
string concatenate (string a, string b)
{
  return a+b;
}
```

```cpp
string concatenate (string& a, string& b)
{
  return a+b;
}
```

```cpp
string concatenate (const string& a, const string& b)
{
  return a+b;
}
```

第一段代码运行时，会拷贝a,b的值然后进行计算，第二段不会进行拷贝操作，效率会高一点，第三段代码在第二段的基础上避免了a，b被修改的风险.
const reference 的左右就是第三段和第二段的总和,即避免值拷贝的低效率，避免引用值被修改的风险
