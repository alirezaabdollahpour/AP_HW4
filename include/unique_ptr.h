#ifndef UNIQUE_PTR
#define UNIQUE_PTR

#include <compare>
#include <iostream>
#include <string>
#include <typeinfo>
#include <utility>
template <typename T>
class UniquePtr {
public:
    // UniquePtr<int> ptr { new int { 10 } };
    UniquePtr(T* arr);
    UniquePtr(); // default constructor
    ~UniquePtr();
    UniquePtr(const UniquePtr& t);
    T* get();
    UniquePtr<T>& operator=(UniquePtr& t) = delete;
    T& operator*();

private:
    T* _p;
};

#include "unique_ptr.hpp"
#endif // UNIQUE_PTR