#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::string str = "Heeello Woooorld!!!";
    std::map<char, int> symbols_count;

    for (const auto& symbol : str)
    {
        if (symbols_count.find(symbol) != symbols_count.end())
        {
            symbols_count[symbol] += 1;
        }
        else
        {
            symbols_count[symbol] = 1;
        }
    }

    std::vector<std::pair<char, int>> pairs;
    for (auto itr = symbols_count.begin(); itr != symbols_count.end(); ++itr)
        pairs.push_back(*itr);

    std::sort(pairs.begin(), pairs.end(), 
        [=](std::pair<char, int>& a, std::pair<char, int>& b) { return a.second > b.second;}
    );

    for (const auto& elem : pairs)
        std::cout << elem.first << ": " << elem.second << std::endl;
}
