/*
 *Exercise 4.2
 *Extend the Stack class to support both a find() and a count() operation. find() returns
 *true or false depending on whether the value is found. count() returns the number of
 *occurrences of the string. Reimplement the main() of Exercise 4.1 to invoke both functions.
 */

#include "Stack.h"

#include <iostream>
using std::cin; using std::cout;
using std::istream;
#include <string>
using std::string;

void fill_stack(Stack &stack, istream &is = cin)
{
    string str;
    while (is >> str && !stack.full())
        stack.push(str);

    cout << "Read in " << stack.size() << " elements.\n";
}

int main()
{
    Stack stack;
    fill_stack(stack);

    cout << "Query word: ";
    string str;
    cin >> str;

    if (stack.find(str))
        cout << str << " occurs " << stack.count(str) << " time(s).\n";
    else
        cout << str << " not found.\n";

    return 0;
}
