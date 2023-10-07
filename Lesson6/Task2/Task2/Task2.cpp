#include <iostream>
#include <set>

int main()
{
    int values_number;
    std::cout << "Enter number of values: ";
    std::cin >> values_number;

    std::set<int> s;
    for (int i = 0; i < values_number; ++i)
    {
        int value;
        std::cout << "Enter value: ";
        std::cin >> value;
        s.insert(value);
    }

    std::cout << "Out:\n";
    for (auto it = s.rbegin(); it != s.rend(); ++it)
        std::cout << *it << std::endl;
}
