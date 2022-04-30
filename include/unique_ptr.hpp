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
