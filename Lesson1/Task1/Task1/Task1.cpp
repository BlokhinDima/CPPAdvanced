#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    std::cout << "Input data: ";
    for (const auto& value : v)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::for_each(v.begin(), v.end(),
        [](int& n) { if (n % 2 != 0) n *= 3; }
    );

    std::cout << "Output data: ";
    for (const auto& value : v)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}