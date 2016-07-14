/*
 *Exercise 10.31:
 *Update the program from the previous exercise so that it prints only the unique elements.
 *Your program should use unqiue_copy (§ 10.4.1, p. 403).
 */

#include <vector>
using std::vector;

#include <algorithm>
using std::sort; using std::find;

#include <numeric>
using std::accumulate;

#include <iterator>
using std::istream_iterator; using std::ostream_iterator;

#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <fstream>
using std::ifstream;

#include "../include/Sales_item.h"

int main()
{
    ifstream ifs("data/book_sales");
    istream_iterator<Sales_item> item_iter(ifs), eof;
    vector<Sales_item> sales_vec(item_iter, eof);
    sort(sales_vec.begin(), sales_vec.end(), compareIsbn);

    for (auto beg = sales_vec.cbegin(), end = beg; end != sales_vec.cend(); beg = end) {
        end = find_if(beg, sales_vec.cend(), [beg](const Sales_item &item) { return item.isbn() != beg->isbn(); });
        cout << accumulate(beg, end, Sales_item(beg->isbn())) << endl;
    }

    return 0;
}
