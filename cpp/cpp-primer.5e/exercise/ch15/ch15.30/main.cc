/*
 *Exercise 15.30:
 *Write your own version of the Basket class and use it to
 *compute prices for the same transactions as you used in the previous exercises.
 */

#include <iostream>
#include <string>

#include "quote.h"
#include "bulk_quote.h"
#include "basket.h"

int main()
{

    Basket basket;

    // 存50个ISBN号相同的销售记录
    for (unsigned i = 0; i != 50; ++i)
        basket.add_item(Bulk_quote("0-201-82470-1", 50.0, 20, 0.1));

    for (unsigned i = 0; i != 50; ++i)
        basket.add_item(Bulk_quote("0-201-82470-2", 51.0, 20, 0.1));

    for (unsigned i = 0; i != 50; ++i)
        basket.add_item(Quote("0-201-82470-3", 53.0));

    basket.total_receipt(std::cout);

    return 0;
}
