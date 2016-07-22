# g++编译C++程序

## 单源文件到可执行文件

```cpp
/* helloworld.cc */
#include <iostream>
int main(int argc, char** argv)
{
    std::cout << "hello, world\n";
    return 0;
}
```

    $ g++ helloworld.cc
    $ g++ helloworld.cc -o helloworld
    $ gcc helloworld.cc -lstdc++ -o helloworld
    $ c++ helloworld.cc -o helloworld


## 多源文件到可执行文件

speak.h
```cpp
/* speak.h */
#include <iosteam>
#include <string>
class Speak 
{
public:
    void sayHello(std::string &str);
};
```

speak.cc
```cpp
/* speak.cc */
#include "speak.h"
void Speak::sayHello(const string& str)
{
    std::cout << "Hello " << str << std::endl;
}
```

    $ g++ hellospeak.cc speak.cc -o hellospeak

## 源文件到目标文件

    $ g++ -c hellospeak.cc
    $ g++ -c speak.cc
    $ g++ hellospeak.o speak.o -o hellospeak

    $ g++ -c hellospeak.cc -o hspk1.o
    $ g++ -c speak.cc -o hspk2.o
    $ g++ hspk1.o hspk2.o -o hellospeak

## 预处理

使用选项`-E`，将源代码传递给预处理程序而不采取其他操作。

    $ g++ -E helloworld.cc
    $ g++ -E helloworld.cc -o helloworld.ii

## 生成汇编语言

选项`-S`指示编译程序将程序编译成汇编语言，输出汇编语言源码，然后停止。

    $ g++ -S helloworld.cc

## 创建静态库
静态库是文档文件(archive file)，其中包含编译程序产生的目标文件集合。
库成员可包括常规函数，类的定义和所定义类的实例。
所有可保存在`.o`目标文件中的类容都可以保存在库中。



