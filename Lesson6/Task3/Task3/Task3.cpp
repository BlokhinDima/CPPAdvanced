#include <iostream>

template<typename T>
class Vector
{
public:
    Vector() { container = createContainer(_capacity); }

    Vector(int initial_capacity) : Vector()
    { 
        _capacity = initial_capacity;
        container = createContainer(_capacity);
    }

    Vector(const Vector& other)
    {
        _capacity = other.capacity();
        container_tail = other.size();
        container = createContainer(_capacity);

        for (int i = 0; i < container_tail; ++i)
            container[i] = other.at(i);
    }

    ~Vector() { deleteContainer(); }

    Vector& operator=(const Vector& other)
    {
        if (this == &other)
            return *this;

        _capacity = other.capacity();
        container_tail = other.size();
        deleteContainer();
        container = createContainer(_capacity);

        for (int i = 0; i < container_tail; ++i)
            container[i] = other.at(i);

        return *this;
    }

    T& operator[](const int index)
    {
        checkIndexInSize(index);
        return container[index];
    }

    const T& operator[](const int index) const
    {
        checkIndexInSize(index);
        return container[index];
    }

    T at(const int index) const
    {
        checkIndexInSize(index);
        return container[index];
    }

    void pushBack(T value)
    {
        if (container_tail == _capacity)
        {
            const int new_capacity = _capacity * 2;
            T* new_container = createContainer(new_capacity);

            for (int i = 0; i < container_tail; ++i)
            {
                new_container[i] = container[i];
            }

            deleteContainer();
            container = new_container;
            _capacity = new_capacity;
        }

        container[container_tail] = value;
        container_tail++;
    }

    int size() const { return container_tail; }

    int capacity() const { return _capacity; };

private:
    int container_tail = 0;
    int _capacity = 1;
    T* container = nullptr;

    T* createContainer(const int size)
    {
        return new T[size]{};
    }

    void deleteContainer()
    {
        delete[] container;
        container = nullptr;
    }

    void checkIndexInSize(const int index) const
    {
        if (index < 0 || index >= container_tail)
        {
            throw std::out_of_range("Index is out of range!");
        }
    }
};


template<typename T>
void printVector(const Vector<T>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v.at(i) << " ";
    }
    std::cout << std::endl << std::endl;
}


template<typename T>
void printVectorCapacityAndSize(const Vector<T>& v)
{
    std::cout << "Capacity: " << v.capacity() << " " 
        << "Size: " << v.size() << std::endl;
}

int main()
{
    Vector<int> v1;
    printVectorCapacityAndSize(v1);

    for (int i = 0; i < 10; i++)
    {
        v1.pushBack(i);
        printVectorCapacityAndSize(v1);
    }
    printVector(v1);
    v1[2] = 55;
    v1[6] = 66;
    //v1[13] = 66; // error

    Vector<int> v2(v1);
    printVectorCapacityAndSize(v2);
    printVector(v2);
    for (int i = 10; i < 20; i++)
    {
        v2.pushBack(i);
        printVectorCapacityAndSize(v2);
    }
    printVector(v2);
    
    Vector<int> v3 = v2;
    printVectorCapacityAndSize(v3);
    printVector(v3);

    const Vector<int> v4(v1);
    printVector(v4);
    // v4[1] = 0; // error
    // v4 = v3; // error
}
