#include <iostream>
using namespace std;

class vatnuoi
{
public:
    virtual void keu() = 0;
    /*virtual void keu()
    {
        cout << "chua biet" << endl;
    }*/
};
class cho : public vatnuoi
{
public:
    void keu()
    {
        cout << "gau gau" << endl;
    }
};


int main()
{
    /*cho c;
    vatnuoi* v = &c;*/
    vatnuoi* v = new cho;

    v->keu();
    return 0;
}