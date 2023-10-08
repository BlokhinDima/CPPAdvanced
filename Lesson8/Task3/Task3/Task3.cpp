#include <iostream>

template <typename T>
class UniquePtr
{
public:
    UniquePtr(T* ptr) : unique_ptr{ptr} {}

    UniquePtr(const UniquePtr&) = delete;

    ~UniquePtr() { delete unique_ptr; }

    UniquePtr& operator=(const UniquePtr&) = delete;

    T& operator*() const { return *unique_ptr; }

    T* release()
    {
        T* temp = this->unique_ptr;
        this->unique_ptr = nullptr;
        return temp;
    }

private:
    T* unique_ptr = nullptr;
};


int main()
{
    int* ptr = new int(10);
    std::cout << ptr << std::endl;

    UniquePtr<int> u_ptr(ptr);
    std::cout << *u_ptr << std::endl;

    int* ptr2 = u_ptr.release();
    std::cout << ptr2 << std::endl;
    UniquePtr<int> u_ptr2(ptr2);

    const int* ptr3 = new int(1000);
    UniquePtr<const int> u_ptr3(ptr3);
    std::cout << *u_ptr3 << std::endl;
    // *u_ptr3 = 10; // error
}
