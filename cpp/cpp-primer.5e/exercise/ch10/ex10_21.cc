/*
 *Exercise 10.21:
 *Write a lambda that captures a local int variable and decrements that variable until it reaches 0.
 *Once the variable is 0 additional calls should no longer decrement the variable.
 *The lambda should return a bool that indicates whether the captured variable is 0.
 */

#include <iostream>
using std::cout; using std::endl;

int main()
{
    int value = 15;
    auto func = [&value]() -> bool {
        while (value > 0) --value;
        return true;
    };

    if (func()) cout << "true" << endl;
    cout << value << endl;
    return 0;
}
