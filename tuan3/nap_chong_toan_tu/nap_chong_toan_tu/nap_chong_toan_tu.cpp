#include <iostream>
using namespace std;

class SoPhuc
{
private:
    int thuc, ao;
public:
    SoPhuc(int Thuc, int Ao )
    {
        this->thuc = Thuc;
        this->ao = Ao;
    }
    SoPhuc()
    {
        this->thuc = 0;
        this->ao = 0;
    }
    SoPhuc operator+(SoPhuc const &a)
    {
        SoPhuc result;
        result.thuc = this->thuc + a.thuc;
        result.ao = this->ao + a.ao;
        return result;
    }
    void print() 
    { 
        cout << this->thuc << " + " << this->ao << "i" << endl; 
    }
};

int main()
{
    SoPhuc c1(10, 5), c2(5, 4);
    SoPhuc c3 = c1 + c2;
    c3.print();
    return 0;
}
