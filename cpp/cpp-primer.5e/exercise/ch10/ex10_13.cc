/*
 *Exercise 10.13:
 *The library defines an algorithm named partition that takes a predicate and partitions the container
 *so that values for which the predicate is true appear in the first part
 *and those for which the predicate is false appear in the second part.
 *The algorithm returns an iterator just past the last element for which the predicate returned true.
 *Write a function that takes a string and returns a bool indicating whether the string has five characters or more.
 *Use that function to partition words. Print the elements that have five or more characters.
 *
 */

#include <vector>
using std::vector;

#include <algorithm>
using std::partition;

#include <string>
using std::string;

#include <iostream>
using std::cin; using std::cout; using std::endl;

bool isLongerThan5(const string &str)
{
    return str.size() >= 5 ? true : false;
}

int main()
{
    vector<string> svec;
    string s;
    while (cin >> s)
        svec.push_back(s);

    auto after_end = partition(svec.begin(), svec.end(), isLongerThan5);
    for (auto iter = svec.begin(); iter != after_end; ++iter)
        cout << *iter << " ";

    return 0;

}
