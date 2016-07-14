/*
 *Exercise 4.1
 *Create a Stack.h and a Stack.suffix, where suffix is whatever convention your compiler
 *or project follows. Write a main() function to exercise the full public interface, and compile and
 *execute it. Both the program text file and main() must include Stack.h:
 *#include "Stack.h"
 */

#include "Stack.h"

#include <string>
using std::string;
#include <iostream>
using std::cin; using std::cout;
using std::istream;

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

    return 0;
}
