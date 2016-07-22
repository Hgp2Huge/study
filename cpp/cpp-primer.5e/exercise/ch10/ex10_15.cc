/*
 *Exercise 10.15:
 *Write a lambda that captures an int from its enclosing function and takes an int parameter.
 *The lambda should return the sum of the captured int and the int parameter.
 */

/*
 *Note:
 *1. A lambda may use a variable local to its surrounding function only if the lambda captures that variable in its capture list.
 *2. The capture list is used for local nonstatic variables only.
 *3. lambdas can use local statics and variables declared outside the function directly.
 */


#include <iostream>
using std::cout; using std::endl;

int i2 = 15;

int sumWithExternalValue()
{
    int i1 = 10;
    auto addExternalValue = [i1](const int value) { return i1 + value; };
    return addExternalValue(i2);
}

int main()
{
    cout << sumWithExternalValue() << endl;
    return 0;
}
