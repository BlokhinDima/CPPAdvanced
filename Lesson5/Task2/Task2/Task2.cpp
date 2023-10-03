#include <iostream>

template <class T>
class Table 
{
public:
    Table(int rows, int cols)
    {
        this->rows = rows;
        this->cols = cols;
        createTwoDimArray();
    }

    ~Table() { deleteTwoDimArray(); }

    void createTwoDimArray()
    {
        array = new T* [rows];
        for (int i = 0; i < rows; ++i)
        {
            array[i] = new T[cols];
        }
    }

    void deleteTwoDimArray()
    {
        for (int i = 0; i < rows; ++i)
        {
            delete[] array[i];
        }
        delete[] array;
    }

    T* operator[](const int index)
    {
        return array[index];
    }

    const T* operator[](const int index) const
    {
        return array[index];
    }

    int Size() const { return rows * cols; }

private:
    int rows;
    int cols;
    T** array = nullptr;
};

int main()
{
    auto test = Table<int>(2, 3);
    test[0][0] = 4;
    test[1][1] = 8;
    std::cout << test[0][0] << " ";
    std::cout << test[1][1] << std::endl;

    const auto test2 = Table<int>(2, 3);
    // test2[0][0] = 11; error because of const object
    std::cout << test2[0][0] << " ";
    std::cout << test2[1][1] << std::endl;
}
