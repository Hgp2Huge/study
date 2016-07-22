#include "quote.h"

void Quote::debug() const
{
    std::cout << "bookNO: " << this->bookNo << " "
                << "price: " << this->price << " \n";
}

// non-member
double print_total(std::ostream &os, const Quote &item, std::size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
        << " # sold: " << n << "total due: " << ret << std::endl;
    return ret;
}
