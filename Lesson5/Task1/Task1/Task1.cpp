#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
T square(T value)
{
    return value * value;
}

template <typename T>
std::vector<T> square(std::vector<T>& v)
{
    std::vector<T> out_v = v;
    std::for_each(out_v.begin(), out_v.end(), [](T& x) { x *= x; });
    return out_v;
}

int main()
{
    int x = 4;
    std::vector<int> v {-1, 4, 8};

    std::cout << "In: " << x << std::endl;
    std::cout << "Out: " << square(4) << std::endl;

    std::cout << "In: ";
    for (auto const x : v)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    auto v2 = square(v);
    std::cout << "Out: ";
    for (auto const x : v2)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

