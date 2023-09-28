#include <iostream>
#include <exception>

class SmartArray
{
public:
    SmartArray(int size) 
    { 
        this->size = size;
        this->container = new int[size];
    }

    ~SmartArray() { delete[] container; }

    void addElement(int element)
    {
        if (container_tail > size - 1)
        {
            throw std::length_error("Can't add element. Array is full!");
        }

        container[container_tail] = element;
        container_tail++;
    }

    int getElement(int index) const
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Index is out of range!");
        }

        return container[index];
    }

private:
    int size = 0;
    int* container = nullptr;
    int container_tail = 0;
};


int main()
{
    try {
        SmartArray arr(5);
        arr.addElement(1);
        arr.addElement(4);
        arr.addElement(155);
        arr.addElement(14);
        arr.addElement(15);
        //arr.addElement(105);
        std::cout << arr.getElement(0) << std::endl;
        std::cout << arr.getElement(1) << std::endl;
        std::cout << arr.getElement(2) << std::endl;
        std::cout << arr.getElement(3) << std::endl;
        std::cout << arr.getElement(4) << std::endl;
        //std::cout << arr.getElement(5) << std::endl;
        //std::cout << arr.getElement(-1) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}

