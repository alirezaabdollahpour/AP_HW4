#ifndef SHARED_PTR
#define SHARED_PTR
#include <compare>
#include <iostream>
#include <memory>
#include <string>
#include <typeinfo>
#include <utility>

template <typename T>
class SharedPtr {
public:
    SharedPtr(T* arr);
    SharedPtr();
    ~SharedPtr();
    T* get();

private:
    T* _p;
};

template <typename T>
T* make_shared(T t)
{
    return new T { t };
}

#include "shared_ptr.hpp"
#endif // SHARED_PTR