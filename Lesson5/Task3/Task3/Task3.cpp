#include <iostream>
#include <vector>


class Counter
{
public:
    void operator()(std::vector<int>& v)
    {
        reset();

        for (auto number : v)
        {
            if (number % 3 == 0)
            {
                counter++;
                sum += number;
            }
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

    Counter int_counter;
    int_counter(v);

    std::cout << "[OUT]: get_sum() = " << int_counter.get_sum() << std::endl;
    std::cout << "[OUT]: get_sum() = " << int_counter.get_count() << std::endl;
    std::cout << std::endl;
}

