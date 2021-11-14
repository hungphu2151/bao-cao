#include <iostream>
#include <string.h>
using namespace std;

class Xuat
{
public:
    void xuat(int i) 
    {
        cout << "Xuat so nguyen: " << i << endl;
    }

    void xuat(double  f) 
    {
        cout << "Xuat so thuc: " << f << endl;
    }

    void xuat(string s) 
    {
        cout << "Xuat chuoi: " << s << endl;
    }
};

int main(void)
{
    Xuat dulieu;
    dulieu.xuat(1234);
    dulieu.xuat(10.01);
    dulieu.xuat("Hello");
    return 0;
}