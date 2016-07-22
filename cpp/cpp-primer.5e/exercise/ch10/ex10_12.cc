/*
 *Exercise 10.12:
 *Write a function named compareIsbn that compares the isbn() members of two Sales_data objects.
 *Use that function to sort a vector that holds Sales_data objects.
 */

#include <vector>
using std::vector;

#include <algorithm>
using std::stable_sort;

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

    // compareIsbn define in class Sales_data
    sort(data_vec.begin(), data_vec.end(), compareIsbn);

    cout << endl;

    for (const auto &d : data_vec)
        cout << d << endl;
    return 0;
}

