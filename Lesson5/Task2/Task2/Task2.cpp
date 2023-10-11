#include <iostream>
#include <exception>

template <typename T>
class Table 
{
private:
    class Row;

public:
    Table(int rows, int cols) : rows{rows}, cols{cols}
    {
        createTwoDimArray();
    }

    Table(const Table& other)
    {
        rows = other.getRows();
        cols = other.getCols();
        createTwoDimArray();
        copyTableValues(other);
    }

    ~Table() { deleteTwoDimArray(); }

    Table& operator=(const Table& other)
    {
        if (this == &other) return *this;

        rows = other.getRows();
        cols = other.getCols();
        deleteTwoDimArray();
        createTwoDimArray();
        copyTableValues(other);

        return *this;
    }

    Row operator[](const int index)
    {
        checkIndexInRowsRange(index);
        return Row(*this, array[index]);
    }

    const Row operator[](const int index) const
    {
        checkIndexInRowsRange(index);
        return Row(*this, array[index]);
    }

    int Size() const { return rows * cols; }

    int getRows() const { return rows; }

    int getCols() const { return cols; }

private:
    int rows;
    int cols;
    T** array = nullptr;

    class Row
    {
    public:
        Row(const Table<T>& parent_table, T* column) : parent_table{parent_table}, column {column} {}

        T& operator[](const int index)
        {
            parent_table.checkIndexInColsRange(index);
            return column[index];
        }

        const T& operator[](const int index) const
        {
            parent_table.checkIndexInColsRange(index);
            return column[index];
        }

    private:
        const Table<T>& parent_table;
        T* column = nullptr;
    };

    void checkIndexInRowsRange(const int index) const
    {
        if (index < 0 || index >= rows)
            throw std::out_of_range("Row index is out of range!");
    }

    void checkIndexInColsRange(const int index) const
    {
        if (index < 0 || index >= cols)
            throw std::out_of_range("Column index is out of range!");
    }

    void createTwoDimArray()
    {
        array = new T * [rows];
        for (int i = 0; i < rows; ++i)
        {
            array[i] = new T[cols]{};
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

    void copyTableValues(const Table& table)
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                array[i][j] = table[i][j];
            }
        }
    }
};


int main()
{
    try
    {
        auto table1 = Table<int>(2, 3);
        table1[0][0] = 4;
        table1[1][1] = 8;
        std::cout << table1[0][0] << " ";
        std::cout << table1[1][1] << std::endl;

        //std::cout << table1[3][0] << " "; // Row index out of range
        //std::cout << table1[1][4] << std::endl; // Column index out of range

        auto table2 = Table<int>(2, 3);
        table2 = table1;
        table2[1][1] = 555;
        std::cout << table2[0][0] << " ";
        std::cout << table2[1][1] << std::endl;

        table1[0][0] = 111;
        Table<int> table3(table1);
        std::cout << table3[0][0] << " ";
        std::cout << table3[1][1] << std::endl;

        const auto table4 = Table<int>(2, 3);
        //table4[0][0] = 11; // error because of const object
        std::cout << table4[0][0] << " ";
        std::cout << table4[1][1] << std::endl;
    }
    catch (const std::out_of_range& e)
    {
        std::cout << e.what();
    }
}
