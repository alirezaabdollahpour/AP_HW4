template <typename T>
SharedPtr<T>::SharedPtr(T* arr)
{
    std::cout << "SharedPtr constructor" << std::endl;
    _p = arr;
    counter = new int { 1 };
}
template <typename T>
SharedPtr<T>::SharedPtr()
{
    std::cout << "default constructor" << std::endl;
    _p = nullptr;
    counter = new int { 1 };
}
template <typename T>
SharedPtr<T>::~SharedPtr()
{
    std::cout << "destructor" << std::endl;
    _p = nullptr;
    delete _p;
    --(*counter);
    if (*counter == 0) {
        delete counter;
        counter = new int {};
    }
}
template <typename T>
T* SharedPtr<T>::get()
{
    return _p;
}
template <typename T>
SharedPtr<T>::SharedPtr(const SharedPtr& t)
{
    std::cout << "copy constructor" << std::endl;
    counter = t.counter;
    _p = t._p;
    ++(*counter);
}
template <typename T>
int SharedPtr<T>::use_count()
{
    return *counter;
}
template <typename T>
T& SharedPtr<T>::operator*()
{
    return *_p;
}
template <typename T>
T* SharedPtr<T>::operator->()
{
    return _p;
}
template <typename T>
void SharedPtr<T>::reset()
{
    _p = nullptr;
    delete _p;
    --(*counter);
}
template <typename T>
void SharedPtr<T>::reset(T* t)
{
    delete _p;
    _p = t;
    // return *_p;
}
template <typename T>
SharedPtr<T>::operator bool()
{
    if (_p == nullptr)
        return false;
    else
        return true;
}
template <typename T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr& ptr)
{
    if (this == &ptr)
        return *this;
    _p = ptr._p;
    counter = ptr.counter;
    ++(*counter);
    return *this;
}
// T& SharedPtr<T>::operator=(const T& ptr)
// {
//     if (this == &ptr)
//         return *this;
//     _p = ptr._p;
//     counter = ptr.counter;
//     ++(*counter);
//     return *this;
// }