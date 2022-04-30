template <typename T>
UniquePtr<T>::UniquePtr(T* arr)
{
    std::cout << "constructor" << std::endl;
    _p = arr;
}

template <typename T>
UniquePtr<T>::UniquePtr()
{
    std::cout << "default constructor" << std::endl;
    _p = nullptr;
}
template <typename T>
UniquePtr<T>::~UniquePtr()
{
    std::cout << "destructor " << std::endl;
    delete _p;
}
template <typename T>
T* UniquePtr<T>::get()
{
    return _p;
}
template <typename T>
UniquePtr<T>::UniquePtr(const UniquePtr<T>& t)
{
    // if (t != nullptr)
    throw std::logic_error { std::string { "error" } };
}
template <typename T>
T& UniquePtr<T>::operator*()
{
    std::cout << "operator* called" << std::endl;
    return *_p;
}
template <typename T>
void UniquePtr<T>::reset()
{
    delete _p;
    _p = nullptr;
}
template <typename T>
T* UniquePtr<T>::operator->()
{
    return _p;
}
template <typename T>
void UniquePtr<T>::reset(T* t)
{
    delete _p;
    _p = t;
    // return *_p;
}
template <typename T>
UniquePtr<T>::operator bool()
{
    if (_p == nullptr)
        return false;
    else
        return true;
}