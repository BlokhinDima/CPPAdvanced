#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <string>


template <typename T>
void printContainer(T it_begin, T it_end)
{
    for (it_begin; it_begin != it_end; ++it_begin)
    {
        std::cout << *it_begin << " ";
    }
    std::cout << std::endl;
}


int main()
{
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    printContainer(test_set.begin(), test_set.end()); 

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    printContainer(test_list.begin(), test_list.end()); 

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    printContainer(test_vector.begin(), test_vector.end());
}
