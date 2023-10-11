#include <iostream>
#include <vector>
#include <algorithm>

class Counter
{
public:
    void operator()(int value)
    {
        if (value % 3 == 0)
        {
            counter++;
            sum += value;
        }
    }

    void reset()
    {
        sum = 0;
        counter = 0;
    }

    int get_sum()
    {
        return sum;
    }

    int get_count()
    {
        return counter;
    }

private:
    int sum = 0;
    int counter = 0;
};


int main()
{
    std::vector<int> v{ 4, 1, 3, 6, 25, 54 };
    std::cout << "[IN]: ";
    for (auto num : v)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    Counter counter;
    counter = std::for_each(v.begin(), v.end(), counter);

    std::cout << "[OUT]: get_sum() = " << counter.get_sum() << std::endl;
    std::cout << "[OUT]: get_sum() = " << counter.get_count() << std::endl;
    std::cout << std::endl;
}

