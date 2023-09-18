#include <iostream>
/*
Linker error. We have definition of myFunction(){} inside "header.h"
and "other.cpp" file also uses "header.h". After preprocessing we will
have two funtion definitions. One inside this file and other inside 
"other.cpp" file. To solve this problem we must leave in "header.h"
only function declaration and write function definition in separate
.cpp file, e.g. "header.cpp".
*/
#include"header.h"

int main()
{
    // Syntax errors: Wrong operator "<" and undefined variable "my_var"
    std::cout < myFunction() + my_var << std::endl;

    // Semantic error: division by zero
    int my_var = 5;
    std::cout << my_var / 0 << std::endl;
}
