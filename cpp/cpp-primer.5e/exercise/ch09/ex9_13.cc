 /*
  *Exercise 9.13:
  *How would you initialize a vector<double> from a list<int>? From a vector<int>? Write code to check your answers.
  */

#include <iostream>
#include <vector>
#include <list>

using std::vector; using std::list;

int main()
{
    list<int> list_i{1, 2, 3, 4, 5};
    vector<double> vec_d(list_i.begin(), list_i.end());

    for (const auto &d : vec_d)
        std::cout << d << " ";
    std::cout << std::endl;
}
