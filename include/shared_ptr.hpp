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