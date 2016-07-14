/*
 *Exercise 10.17:
 *Rewrite exercise 10.12 from § 10.3.1 (p. 387) to use a lambda in the call to sort instead of the compareIsbn function.
 */

#include <vector>
using std::vector;

#include <algorithm>

#include <fstream>
using std::ifstream;

#include <iostream>
using std::cin; using std::cout; using std::endl;

#include "../include/Sales_item.h"

int main()
{
    ifstream input("data/book_sales");
    vector<Sales_item> data_vec;
    Sales_item tmp;
    while (cin >> tmp) {
        data_vec.push_back(tmp);
    }

    for (const auto &d : data_vec)
        cout << d << endl;

    // compareIsbn define in class Sales_item
    sort(data_vec.begin(), data_vec.end(),
            [](const Sales_item &data1, const Sales_item &data2)
              { return data1.isbn() < data2.isbn();});

    cout << endl;

    for (const auto &d : data_vec)
        cout << d << endl;

    return 0;
}

