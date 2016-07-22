/*
 *Exercise 10.28:
 *Copy a vector that holds the values from 1 to 9 inclusive, into three other containers.
 *Use an inserter, a back_inserter, and a front_inserter, respectivly to add elements to these containers.
 *Predict how the output sequence varies by the kind of inserter and verify your predictions by running your programs.
 */


// inserter:1 2 3 4 5 6 7 8 9
// back_inserter: 1 2 3 4 5 6 7 8 9
// front_inserter: 9 8 7 6 5 4 3 2 1


#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <iterator>
using std::inserter; using std::back_inserter; using std::front_inserter;

int main()
{
    vector<int> ivec = {1,2,3,4,5,6,7,8,9};
    list<int> ilst1, ilst2, ilst3;

    copy(ivec.cbegin(), ivec.cend(), inserter(ilst1, ilst1.begin()));
    copy(ivec.cbegin(), ivec.cend(), back_inserter(ilst2));
    copy(ivec.cbegin(), ivec.cend(), front_inserter(ilst3));

    cout << "inserter: ";
    for (auto i : ilst1)
        cout << i << " ";
    cout << endl;

    cout << "back_inserter: ";
    for (auto i : ilst2)
        cout << i << " ";
    cout << endl;

    cout << "front_inserter: ";
    for (auto i : ilst3)
        cout << i << " ";
    cout << endl;

    return 0;
}
