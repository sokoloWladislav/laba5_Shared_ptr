#include <iostream>
#include <exception>
#include <list>
#include "contact.h"

using namespace std;

template <class T>
class SharedPointer
{
private:
    T* ptr;
    int* count;
    void del()
    {
        if (--*count == 0)
        {
            delete count;
            delete ptr;
        }
    }
public:
    SharedPointer():ptr(0), count(new int(0)){}
    explicit SharedPointer(T* p=0)
        : ptr(p), count(new int(1)) {}
    SharedPointer(const SharedPointer<T>& p) throw()
        : ptr(p.ptr), count(p.count){++*count;}
    ~SharedPointer()
    {
        del();
    }
    SharedPointer<T>& operator= (const SharedPointer<T>& p) throw()
    {
        if(this!=&p)
        {
            del();
            ptr=p.ptr;
            count=p.count;
            ++*count;
        }
        return *this;
    }

    T& operator*(){return *ptr;}
    T* operator->(){return ptr;}
};

int main()
{
    Contact *a;
    Contact *b;
    ContactOnline c;
    c.show();
    return 0;
}
