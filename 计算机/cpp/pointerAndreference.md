# 指针与引用

## 区别

- 不存在空引用。引用必须连接到一块合法的内存。
- 一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。
- 引用必须在创建时被初始化。指针可以在任何时间被初始化。

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
