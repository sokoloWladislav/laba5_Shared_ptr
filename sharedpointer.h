#ifndef SHAREDPOINTER_H
#define SHAREDPOINTER_H


template <class T>
class SharedPointer
{
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
    SharedPointer():
        ptr(new T()),count(new int(1)){}
    SharedPointer(T* p=0)
        : ptr(p), count(new int(1)) {}
    SharedPointer<T>(const SharedPointer<T>& p) throw()
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

#endif // SHAREDPOINTER_H
