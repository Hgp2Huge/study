/*
 *Exercise 10.14:
 *Write a lambda that takes two ints and returns their sum.
 */

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
    auto func = [](int value1, int value2) { return value1 + value2; };

    cout << func(5, 6) << endl;

    return 0;
}
