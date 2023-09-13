#include <iostream>
#include <functional>
#include <vector>
#include <cmath>


double degreesToRad(double degrees)
{
    return degrees * 3.1415926 / 180;
}

int main()
{
    double angles[] = {degreesToRad(30), degreesToRad(60), degreesToRad(90)};

    std::cout << "Input angles (radians):\n";
    for (const auto& angle : angles)
    {
        std::cout << angle << std::endl;
    }
    std::cout << std::endl;
    
    std::function<void(double)> printSin = 
        [](double angle) { std::cout << "sin: " << std::sin(angle) << " "; };

    std::function<void(double)> printCos = 
        [](double angle) { std::cout << "cos: " << std::cos(angle) << " "; };

    std::vector<std::function<void(double)>> functions = { printSin, printCos };

    std::cout << "Output:\n";
    for (const auto& angle : angles) {
        std::cout << angle << ": ";
        for (const auto& function : functions)
            function(angle);
        std::cout << std::endl;
    }
}
