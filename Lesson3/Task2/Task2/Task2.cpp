#include <iostream>
#include <exception>

class SmartArray
{
public:
    SmartArray(int size)
    {
        this->size = size;
        container = createContainer(size);
    }

    ~SmartArray() { deleteContainer(); }

    SmartArray& operator=(const SmartArray& smart_array)
    {
        if (this == &smart_array) return *this;

        deleteContainer();
        container = createContainer(size);

        for (container_tail = 0; container_tail < smart_array.size; ++container_tail)
        {
            container[container_tail] = smart_array.getElement(container_tail);
        }

        return *this;
    }

    int* createContainer(int size) { return new int[size]; }

    void deleteContainer() { delete[] container; }

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
    try 
    {
        SmartArray arr(5);
        arr.addElement(1);
        arr.addElement(4);
        arr.addElement(155);

        std::cout << arr.getElement(0) << " " << arr.getElement(1) << " " << arr.getElement(2) << std::endl;
        
        SmartArray new_arr(2);
        new_arr.addElement(44);
        new_arr.addElement(34);

        arr = new_arr;
        arr.addElement(155);

        std::cout << arr.getElement(0) << " " << arr.getElement(1) << " " << arr.getElement(2) << std::endl;
        std::cout << new_arr.getElement(0) << " " << new_arr.getElement(1) << std::endl;
    }
    catch (const std::exception& ex) 
    {
        std::cout << ex.what() << std::endl;
    }
}
