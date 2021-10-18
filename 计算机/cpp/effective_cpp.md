# effective cpp

## 视 C++ 为一个语言联邦（C、Object-Oriented C++、Template C++、STL)

## 宁可以编译器替换预处理器（尽量以 const、enum、inline 替换 #define）

对于单纯常量，使用const或者enums代替#defines
对于形似函数的宏，使用inline代替

## 尽可能使用 const

- const 可以让编译器帮助完成值不变的约束。可以用在作用域内的对象，函数参数，函数返回类型，成员函数本身。
    const 出现在*左边，表示被指物是常量。
    const 出现在*右边，表示指针本身是常量
- 编译器默认使用bitwise constness，但编写程序时应使用概念上的常量性（const用于成员函数时）
    bitwise：成员函数不改变对象的任何成员属性
    概念性：一个const成员函数可以修改处理对象的某些属性（在对客户端透明的情况下）

- 当const和non-const成员函数有着实质等价的实现时，另non-const版本调用const版本。

## 确定对象被使用前已先被初始化(构造时赋值（copy 构造函数）比 default 构造后赋值（copy assignment）效率高)

- 通常使用类C部分的c++代码，不会保证初始化，而使用c++的部分代码会保证初始化（Oriented C++、Template C++、STL）
- 永远在使用对象前进行初始化
- 在构造函数中将每一个属性都进行初始化（使用成员初始化列表而不是在构造函数中进行赋值）
- 为避免跨编译单元初始化次序问题，以 __local static__ 对象替换 __non-local static__ 对象（单例模式*）

## 了解 C++ 默默编写并调用哪些函数（编译器暗自为 class 创建 default 构造函数、copy 构造函数、copy assignment 操作符、析构函数）

- copy  将来源对象的每一个non-static成员变量拷贝到目标对象
- copy assignment cpp不会自动生成内含reference成员的类的赋值操作 __operator=__,如果基类的修饰符是private，则不会为派生类生成代码
- deconstructor  给编译器一个地方，放置默认代码且编译器产出的析构函数是non-virtual的
- constructor

## 若不想使用编译器自动生成的函数，就应该明确拒绝（将不想使用的成员函数声明为 private，并且不予实现）

- 将不想使用的成员函数声明为 private，并且不予实现，或者使用像Uncopyable这样的基类也可以
