#include <iostream>
#include <vector>
#include <string>
#include <utility>

template <typename T>
void printVector(std::vector<T> v)
{
    for (const auto value : v)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}


template <typename T>
void moveVectors(std::vector<T>& v1, std::vector<T>& v2)
{
    auto temp = std::move(v1);
    v1 = std::move(v2);
    v2 = std::move(temp);
}


int main()
{
    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two;

    std::cout << "Before move:\n";
    std::cout << "V1: ";
    printVector(one);
    std::cout << "V2: ";
    printVector(two);

    moveVectors(one, two);

    std::cout << "After move:\n";
    std::cout << "V1: ";
    printVector(one);
    std::cout << "V2: ";
    printVector(two);
}
