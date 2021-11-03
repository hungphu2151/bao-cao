#include <iostream>
using namespace std;

class A
{
private:
    int privateA;
protected:
    int protectedA;
public:
    A(int t1 = 0, int t2 = 0) : protectedA(t1), privateA(t2) {};
    void showValue();
};
void A::showValue() 
{
    cout << protectedA + privateA << endl;
}

class B : public A
{
private:
    int privateB;
protected:
    int protectedB;
public:
    B(){};
    void show();
};
void B::show()
{
    showValue();        // public of A --> public of B
    protectedA = 1;     // protected of A --> protected of B
}

class C : private A
{
private:
    int privateC;
protected:
    int protectedC;
public:
    C(){};
    void show();
};

void C::show()
{
    showValue();        // public of A --> private of C
    protectedA = 3;     // protected of A --> private of C
}

class D : protected A
{
private:
    int privateD;
protected:
    int protectedD;
public:
    D() {};
    void show();
};

void D::show()
{
    showValue();        // public of A --> protected of C
    protectedA = 3;     // protected of A --> protected of C

}
int main()
{
    A a(8, 10);
    cout << "a:" << endl;
    a.showValue();
    cout << endl;

    B b;
    cout << "b:" << endl;
    b.show();
    b.showValue();     // public of B
    cout << endl;

    C c;
    cout << "c:" << endl;
    c.show();
    c.show();
    //c.showValue();   // private of C --> error
    cout << endl;

    D d;
    cout << "d:" << endl;
    d.show();
    d.show();
    //d.showValue()     // protected of D --> error
    return 0;
}