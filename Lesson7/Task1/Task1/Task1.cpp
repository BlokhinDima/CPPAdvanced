#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

template <typename T>
void removeDuplicates(std::vector<T>& v)
{
    std::sort(v.begin(), v.end());
    auto it = std::unique(v.begin(), v.end());
    v.erase(it, v.end());
}


template <typename T>
void printVector(std::vector<T>& v)
{
    for (const auto& value : v)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}


int main()
{
    std::vector<int> v{ 1, 1, 2, 5, 6, 1, 2, 4 };
    printVector(v);
    removeDuplicates(v);
    printVector(v);

    std::vector<double> v2{ 1.2, 1.1, 2.2, 5, 6.7, 1.2, 2.2, 4.4 };
    printVector(v2);
    removeDuplicates(v2);
    printVector(v2);

    std::vector<std::string> v3{ "dog", "cat", "bird", "penguin", "dog", "elephant", "bird" };
    printVector(v3);
    removeDuplicates(v3);
    printVector(v3);
}
