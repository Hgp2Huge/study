/*
 *Exercise 15.23:
 *Assuming class D1 on page 620 had intended to override its inherited fcn function, how would you fix that class?
 *Assuming you fixed the class so that fcn matched the definition in Base, how would the calls in that section be resolved?
 *
 */

#include <iostream>

class Base {
public:
    virtual int fcn() { std::cout << "virtual Base::func()" << std::endl; return 0;}
};

class D1 : public Base {
public:
    int fcn() override { std::cout << "virtual D1::func()" << std::endl; return 0; }
    //  ^^^ fixed
    virtual void f2() { std::cout << "virtual D1::f2()" << std::endl; }
};

class D2 : public D1 {
public:
    int fcn(int i) { std::cout << "D2::fcn(int)" << std::endl; return i; }
    int fcn() override { std::cout << "virtual D2::fcn()" << std::endl; return 0; }
    void f2() override { std::cout << "virtual D2::f2()" << std::endl; }
};

int main()
{
    Base bobj; D1 d1obj; D2 d2obj;

    Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
    bp1->fcn();     // virtual Base::func()
    bp2->fcn();     // virtual D1::func()
    bp3->fcn();     // virtual D2::fcn()

    D1 *d1p = &d1obj; D2 *d2p = &d2obj;
    //bp2->f2();
    d1p->f2();      // virtual D1::f2()
    d2p->f2();      // virtual D2::f2()

    Base *p1 = &d2obj; D1 *p2 = &d2obj; D2 *p3 = &d2obj;
    //p1->fcn(42);
    //p2->fcn(42);  // Base, D1 has no member fcn(int)
    p3->fcn(42);    // D2::fcn(int)

}




