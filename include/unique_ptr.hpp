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