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
    SharedPtr(const SharedPtr& t);
    T& operator*();
    T* get();
    int use_count();
    T* operator->();
    void reset();
    void reset(T* t);
    operator bool();
    SharedPtr<T>& operator=(const SharedPtr& ptr);
    // T& operator=(const T& ptr);

private:
    T* _p;
    int* counter;
};

template <typename T>
T* make_shared(T t)
{
    return new T { t };
}

#include "shared_ptr.hpp"
#endif // SHARED_PTR