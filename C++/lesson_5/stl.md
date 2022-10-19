# STL

## 什么是STL

STL(standard template libaray标准模板库)：是C++标准库的重要组成部分，不仅是一个可复用的组件库，而且是一个包罗数据结构与算法的软件框架。

## STL的版本

- 原始版本

  Alexander Stepanov、 Meng Lee 在惠普实验室完成的原始版本，本着开源精神，他们声明允许任何人任意运用、拷贝、修改、传播、商业使用这些代码，无需付费。唯一的条件就是也需要向原始版本一样做开源使用。HP版本-所有STL实现版本的始祖。

- P.J.版本 

  由P.J.Plauger开发，继承自HP版本，被Windows Visual C++采用，不能公开或修改，缺陷：可读性比较低，符号命名比较怪异。

- RW版本

  由Rouge Wage公司开发，继承自HP版本，被C++ Builder 采用，不能公开或修改，可读性一般。

- SGI版本

  由Silicon Graphics Computer Systems， Inc公司开发，继承自HP版 本。被GCC(Linux)采用，可移植性好，可公开、修改甚至贩卖，从命名风格和编程 风格上看，阅读性非常高。**我们后面学习STL要阅读部分源代码，主要参考的就是这个版本。**

## STL的六大组件

```mermaid
		graph TD
A(STL)--->B(仿函数)
A--->C(算法)
A--->D(迭代器)
A--->E(空间配置器)
A--->F(容器)
A--->G(配接器)
B--->greater
B--->less
B--->....
C--->find
C--->swap
C--->reverse
C--->sort
C--->merge
C--->....
D--->iterator
D--->const_iterator
D--->reverse_iterator
D--->const_reverse_iterator
E--->allocator
F--->string
F--->vector
F--->list
F--->deque
F--->map
F--->set
F--->multimap
F--->multiset
G--->stack
G--->queue
G--->priority_queue
```

学习STL的三个境界：能用，明理，能扩展。

## STL的缺陷

1. STL库的更新太慢了。这个得严重吐槽，上一版靠谱是C++98，中间的C++03基本一些修订。C++11出来已经相隔了13年，STL才进一步更新。
2. STL现在都没有支持线程安全。并发环境下需要我们自己加锁。且锁的粒度是比较大的。
3. STL极度的追求效率，导致内部比较复杂。比如类型萃取，迭代器萃取。
4. STL的使用会有代码膨胀的问题，比如使用vector/vector/vector这样会生成多份代码，当然这是模板语法本身导致的。