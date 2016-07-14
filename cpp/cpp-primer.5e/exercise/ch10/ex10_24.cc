/*
 *Exercise 10.24:
 *Use bind and check_size to find the first element in a vector of ints
 *that has a value greater than the length of a specified string value.
 */

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <functional>
using std::bind; using std::placeholders::_1;

#include <algorithm>
using std::find_if;

#include <iostream>
using std::cout; using std::endl;

bool check_size(int value, string::size_type sz)
{
    return value > sz;
}

int main()
{

    vector<int> ivec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    string str = "testing";

    auto check_string_size = bind(check_size, _1, str.size());
    auto pos_first = find_if(ivec.cbegin(), ivec.cend(), check_string_size);

    cout << *pos_first << endl;

    return 0;
}
