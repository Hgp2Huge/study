# Chapter 15 Object-Oriented Programming
任何构造函数之外的非静态函数都可以是虚函数。

## Exercise 15.1: 
> What is a virtual member?
基类声明的虚函数。基类希望派生类覆盖(override)的函数。

## Exercise 15.2: 
> How does the protected access specifier differ from private?
protected声明的成员允许派生类访问，禁止其他用户访问。
private声明的成员仅允许类内访问。


## Exercise 15.4: 
> Which of the following declarations, if any, are incorrect? Explain why.
    class Base { ... };
(a) class Derived : public Derived { ... }; // 类不能派生它本身。
(b) class Derived : private Base { ... };
(c) class Derived : public Base; // incorrect, 派生类申明不需要派生列表。


## Exercise 15.8: 
> Define static type and dynamic type.
静态类型(static type): 变量声明时的类型或表达式生成的类型；
动态类型(dynamic type): 变量或表达式表示的内存中的对象的类型。动态类型直到运行时才可知。

## Exercise 15.9: 
> When is it possible for an expression’s static type to differ from its dynamic type? Give three examples in which the static and dynamic type differ.
只有当表达式是基类的指针或引用时，其动态类型才可能与静态类型不一致。
    Bulk_quote bulk;
    Quote *p = &bulk; p->net_price(5);
    Quote &r = bulk; r.net_price(5);


## Exercise 15.10: 
> Recalling the discussion from §8.1 (p. 311), explain how the program on page 317 that passed an ifstream to the Sales_data read function works.
ifstream 继承自istream.
read的第一个参数是istream类型的引用。执行read函数发生了派生类到基类的转换


## Exercise 15.12: 
> Is it ever useful to declare a member function as both override and final? Why or why not?
有用。override覆盖基类的同名虚函数，final阻止派生类覆盖该类的虚函数。

## Exercise 15.13: 
> Given the following classes, explain each print function:
    class base {
    public:
       string name() { return basename; }
       virtual void print(ostream &os) { os << basename; }
    private:
       string basename;
    };
    class derived : public base {
    public:
       void print(ostream &os) { print(os); os << " " << i; }
    private:
       int i;
    };
> If there is a problem in this code, how would you fix it?
无限递归。派生类虚函数需要调用基类版本时，如果没有使用作用域运算符，则在运行时该调用将被解析为对派生类版本自身的调用，导致无限递归。
print(os) 改为 base::print(os)

## Exercise 15.14: 
> Given the classes from the previous exercise and the following objects, determine which function is called at run time:
    base bobj;     base *bp1 = &bobj;   base &br1 = bobj;
    derived dobj;  base *bp2 = &dobj;   base &br2 = dobj;
 
(a) bobj.print();   // base::print();
(b) dobj.print();   // derived::print()
(c) bp1->name();    // base::name()
(d) bp2->name();    // base::name()
(e) br1.print();    // base::print()
(f) br2.print();    // derived::print()

## Exercise 15.17: 
> Try to define an object of type Disc_quote and see what errors you get from the compiler.
    Disc_quote discq;

错误提示：
error: cannot declare variable ‘discq’ to be of abstract type ‘Disc_quote’
note:   because the following virtual functions are pure within ‘Disc_quote’:
提示不能申明抽象类型的对象，因为其虚函数是纯虚函数。

## Exercise 15.18: 
> Given the classes from page 612 and page 613, and assuming each object has the type specified in the comments, determine which of these assignments are legal. Explain why those that are illegal aren’t allowed:
    Base *p = &d1;  //  d1 has type Pub_Derv
    p = &d2;        //  d2 has type Priv_Derv
    p = &d3;        //  d3 has type Prot_Derv
    p = &dd1;       //  dd1 has type Derived_from_Public
    p = &dd2;       //  dd2 has type Derived_from_Private
    p = &dd3;       //  dd3 has type Derived_from_Protected

    Base *p = &d1;  // legal.
    p = &d2;        // illegal.
    p = &d3;        // illegal.
    p = &dd1;       // legal.
    p = &dd2;       // illegal.
    p = &dd3;       // illegal.

只有当D公有地继承B时，用户代码才能使用派生类向基类的转换；如果D继承B的方式是受保护的或者私有的，则用户代码不能使用该转换。

Tips: 对于代码中的某个给定的节点，如果基类的公有成员是可访问的，则派生类向基类的转换也是可访问的；反之则不行。
 
## Exercise 15.19: 
> Assume that each of the classes from page 612 and page 613 has a member function of the form:
    void memfcn(Base &b) { b = *this; }
> For each class, determine whether this function would be legal.

不论D以什么方式继承B，D的成员函数和友元都能使用派生类向基类的转换；派生类向其直接基类的类型转换对于派生类的成员和友元来说永远可访问。
因此，Pub_Derv,Prot_Derv, Priv_Derv都合法。

如果D继承B的方式是公有的或者受保护的，则D的派生类的成员和友元可以使用D向B的类型转换；反之，如果D继承B的方式是私有的，则不能使用。
因此，Derived_from_Public, Derived_from_Protected合法；Derived_from_Private不合法。

 
## Exercise 15.20: 
> Write code to test your answers to the previous two exercises.

编译错误代码：

    ex15_20.cc:6:12: error: ‘class Base Base::Base’ is inaccessible
     class Base {
                ^
    ex15_20.cc:29:17: error: within this context
         void memfcn(Base &b) { b = *this; }
                     ^
    ex15_20.cc: In member function ‘void Derived_from_Private::memfcn(Base&)’:
    ex15_20.cc:29:30: error: ‘Base’ is an inaccessible base of ‘Derived_from_Private’
         void memfcn(Base &b) { b = *this; }
                                  ^
    ex15_20.cc: In function ‘int main()’:
    ex15_20.cc:45:7: error: ‘Base’ is an inaccessible base of ‘Priv_Derv’
         p = &d2;        //  d2 has type Priv_Derv
           ^
    ex15_20.cc:46:7: error: ‘Base’ is an inaccessible base of ‘Prot_Derv’
         p = &d3;        //  d3 has type Prot_Derv
           ^
    ex15_20.cc:48:7: error: ‘Base’ is an inaccessible base of ‘Derived_from_Private’
         p = &dd2;       //  dd2 has type Derived_from_Private
           ^
    ex15_20.cc:49:7: error: ‘Base’ is an inaccessible base of ‘Derived_from_Protected’
         p = &dd3;       //  dd3 has type Derived_from_Protected
           ^


## Exercise 15.23: 
> Assuming class D1 on page 620 had intended to override its inherited fcn function, how would you fix that class? 
Assuming you fixed the class so that fcn matched the definition in Base, how would the calls in that section be resolved?

删除参数int即可。  详细查看 ex15_23.cc 

## Exercise 15.24: 
> What kinds of classes need a virtual destructor? What operations must a virtual destructor perform?

继承体系中的基类应该定义虚析构函数。当delete基类指针时将确保执行正确的析构函数版本。

## Exercise 15.25: 
> Why did we define a default constructor for Disc_quote?
What effect, if any, would removing that constructor have on the behavior of Bulk_quote?

如果基类的默认构造函数、拷贝构造函数、拷贝赋值运算符或析构函数是被删除的函数或不可访问，则派生类中对应的成员将是被删除的，
原因是编译器不能使用基类成员来执行派生类对象基类部分的构造、赋值或销毁操作。

因此，如果删除Disc_quote中的默认构造函数，Bulk_quote中将删除Disc_quote对应的成员。


## Exercise 15.26:
> Define the Quote and Bulk_quote copy-control members to do the same job as the synthesized versions.
Give them and the other constructors print statements that identify which function is running.
Write programs using these classes and predict what objects will be created and destroyed.
Compare your predictions with the output and continue experimenting until your predictions are reliably correct.

详情看`ex15_26.cc`.


## Exercise 15.27: 
> Redefine your Bulk_quote class to inherit its constructors.

    class Bulk_quote : public Disc_quote {
    public:
        using Disc_quote::Disc_quote; // 继承Disc_quote的构造函数
        double net_price(std::size_t) const;
    }


## Exercise 15.28: 
> Define a vector to hold Quote objects but put Bulk_quote objects into that vector. 
Compute the total net_price of all the elements in the vector.

计算的是Quote部分。

## Exercise 15.29: 
> Repeat your program, but this time store shared_ptrs to objects of type Quote. 
Explain any discrepancy in the sum generated by the this version and the previous program. 
If there is no discrepancy, explain why there isn’t one.

结果不一致。  
 - ex15.28: 存在vector里的是Bulk_quote对象的Quote部分。调用时执行Quote的net_price，不打折  
 - ex15.29: 存Quote的智能指针。通过智能指针调用net_price发生动态绑定，运行时根据指针的对象执行相应版本net_price。


## Exercise 15.30: 
> Write your own version of the Basket class and use it to
compute prices for the same transactions as you used in the previous exercises.

查看文件夹ch15.30

## Exercise 15.31: 
> Given that s1, s2, s3, and s4 are all strings, determine what objects are created in the following expressions:
(a) Query(s1) | Query(s2) & ~ Query(s3);
(b) Query(s1) | (Query(s2) & ~ Query(s3));
(c) (Query(s1) & (Query(s2)) | (Query(s3) & Query(s4)));

 - (a) OrQuery, AndQuery, NotQuery, WordQuery
 - (b) 同上
 - (c) AndQuery, OrQuery, WordQuery


## Exercise 15.32: 
> What happens when an object of type Query is copied, moved, assigned, and destroyed?

 - **copy:** 调用合成的拷贝构造函数，复制数据成员到新对象。对于共享指针成员，指针指向同一个地址，共享指针的使用计数+1。
 - **move:** 调用合成的移动构造函数，移动数据成员到新对象。新对象的共享指针指向旧对象的共享指针指向的地址。共享指针的使用计数不变。旧对象指针变成空指针(nullptr)。
 - **assigned:** 调用拷贝复制或者移动赋值，与相应的构造函数一样。
 - **destroy:** 调用合成的析构函数。将调用共享指针的析构函数，自减使用计数，如果使用计数值为0，共享指针的析构函数删除其指向的资源。

## Exercise 15.33: 
> What about objects of type Query_base?

Query_base是抽象类，不能创建抽象类的对象。类对象存在于派生类中。由合成的版本控制。

## Exercise 15.34: 
> For the expression built in Figure 15.3 (p. 638):
(a) List the constructors executed in processing that expression.
(b) List the calls to rep that are made from cout << q.
(c) List the calls to eval made from q.eval().

Query q = Query("fiery") & Query("bird") | Query("wind");
 - (a):
 1. Query::Query(const std::string& s);
 2. WordQuery::WordQuery(const std::string& s);
 3. AndQuery::AndQuery(cosnt Query& left, const Query& right), 在"+"运算符位置
 4. BinaryQuery(const Query& l, const Query& r, std::string s), AndQuery调用基类初始化
 5. Query::Query(std::shared_ptr<Query_base> query)
 6. OrQuery::OrQuery(const Query& left, const Query& right);
 7. BinaryQuery(const Query& l, const Query& r, std::string s);
 8. Query::Query(std::shared_ptr<Query_base> query);
 
 - (b):
 1. 

 - (c):
 1. 

## Exercise 15.35: 
> Implement the Query and Query_base classes, including a definition of rep but omitting the definition of eval.

待完成...

## Exercise 15.36: 
> Put print statements in the constructors and rep members and run your code to check your answers to (a) and (b) from the first exercise.

待完成...

## Exercise 15.37: 
> What changes would your classes need if the derived classes had members of type shared_ptr<Query_base> rather than of type Query?


## Exercise 15.38: 
> Are the following declarations legal? If not, why not? If so, explain what the declarations mean.

BinaryQuery a = Query("fiery") & Query("bird");     // illegal, BinaryQuery是抽象类。
AndQuery b = Query("fiery") & Query("bird");        // illegal, 表达式返回Query, 不能从Query转成AndQuery。
OrQuery c = Query("fiery") & Query("bird");         // illegal, 表达式返回Query, 不能从Query转成OrQuery。

## Exercise 15.39: 
> Implement the Query and Query_base classes. Test your application by evaluating and printing a query such as the one in Figure 15.3
(p. 638).


## Exercise 15.40: 
> In the OrQuery eval function what would happen if its rhs member returned an empty set? What if its lhs member did so? What if both rhs and lhs returned empty sets?

## Exercise 15.41: 
> Reimplement your classes to use built-in pointers to Query_base rather than shared_ptrs. Remember that your classes will no longer be able to use the synthesized copy-control members.


## Exercise 15.42: 
> Design and implement one of the following enhancements:
(a) Print words only once per sentence rather than once per line.
(b) Introduce a history system in which the user can refer to a previous query by number, possibly adding to it or combining it with another.
(c) Allow the user to limit the results so that only matches in a given range of lines are displayed.

待完成...
