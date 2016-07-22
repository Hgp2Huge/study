#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;

int main()
{
    vector<const char*> cstr = {"Henry", "Peter", "Jhon", "David"};
    vector<const char*> cstr2 = {"Henry", "Peter", "Jhon", "David"};

    if (equal(cstr.cbegin(), cstr.cend(), cstr2.cbegin()))
        std::cout << "cstr is equal to cstr2" << std::endl;
    else
        std::cout << "cstr is not equal to cstr2" << std::endl;
    return 0;
}
