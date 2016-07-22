/*
 *Exercise 15.20:
 *Write code to test your answers to the previous two exercises.
 */

class Base {
public:
    void pub_mem();
protected:
    int prot_mem();
private:
    char priv_mem();
};

struct Pub_Derv : public Base {
    void memfcn(Base &b) { b = *this; }
};
struct Priv_Derv : private Base {
    void memfcn(Base &b) { b = *this; }
};
struct Prot_Derv : protected Base {
    void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Public : public Pub_Derv {
    void memfcn(Base &b) { b = *this; }
};
struct Derived_from_Private :private Priv_Derv {
    void memfcn(Base &b) { b = *this; }
};
struct Derived_from_Protected : protected Prot_Derv {
    void memfcn(Base &b) { b = *this; }
};

int main()
{
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Derived_from_Public dd1;
    Derived_from_Private dd2;
    Derived_from_Protected dd3;

    Base *p = &d1;  //  d1 has type Pub_Derv
    p = &d2;        //  d2 has type Priv_Derv
    p = &d3;        //  d3 has type Prot_Derv
    p = &dd1;       //  dd1 has type Derived_from_Public
    p = &dd2;       //  dd2 has type Derived_from_Private
    p = &dd3;       //  dd3 has type Derived_from_Protected

    return 0;
}
