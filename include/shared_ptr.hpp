template <typename T>
SharedPtr<T>::SharedPtr(T* arr)
{
    std::cout << "SharedPtr constructor" << std::endl;
    _p = arr;
}
template <typename T>
SharedPtr<T>::SharedPtr()
{
    std::cout << "default constructor" << std::endl;
    _p = nullptr;
}
template <typename T>
SharedPtr<T>::~SharedPtr()
{
    std::cout << "destructor" << std::endl;
    delete _p;
}
template <typename T>
T* SharedPtr<T>::get()
{
    return _p;
}