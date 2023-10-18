#include <iostream>
#include "big_integer.h"

int main()
{
    
    auto number1 = BigInteger("18446744073709551616");
    std::cout << "Number 1 = 2^64 = " << number1 << std::endl;

    auto number2 = BigInteger("18446744073709551616");
    std::cout << "Number 2 = 2^64 = " << number2 << std::endl;

    BigInteger number3 = number1;
    std::cout << "Number 3 = Number 1 = " << number3 << std::endl;

    auto number4 = number1 + number2;
    std::cout << "Number 4 = Number 1 + Number 2 = " << number4 << std::endl;

    auto number5 = number1 + 455555555;
    std::cout << "Number 5 = Number 1 + 455555555 = " << number5 << std::endl;
    
    auto number6 = BigInteger("9223372036854775808");
    std::cout << "Number 6 = 2^63 = " << number6 << std::endl;

    auto number7 = BigInteger("111111");
    std::cout << "Number 7 = " << number7 << std::endl;

    auto number8 = number6 * number7;
    std::cout << "Number 8 = Number 7 * Number 6 = " << number8 << std::endl;

    auto number9 = number8 * 123456789;
    std::cout << "Number 9 = Number 8 * 123456789 = " << number9 << std::endl;

    auto number10 = std::move(number9);
    std::cout << "Number 10 = std::move(Number 9) = " << number10 << std::endl;
    std::cout << "Number 9 = " << number9 << std::endl;

    auto number11(std::move(number10));
    std::cout << "Number 11 (std::move(Number 9) = " << number11 << std::endl;
    std::cout << "Number 10 = " << number10 << std::endl;
}
