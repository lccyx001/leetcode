# 常用关键字

## const

```cpp
const int a = 7;
// a 的值不可再改变

const int *b = 8;
// 指针指向的内容不可改变 8 不可变

int* const c = &a;
//  指针指向的内容可变，指针不可指向其他地方

const int* const d=&a;
// 所有内容都不可变

void func(const int a){
    // 函数中参数a 的值不能改变
}

void func1(int* const a){
    // 函数中指针a不可被修改
}

void func2(const ClassName& cn)
{
    // 传递复合类型的引用
    cout<<cn.get_cm();
}

// 修饰自定义类型的返回值
// 修饰类成员函数
```
