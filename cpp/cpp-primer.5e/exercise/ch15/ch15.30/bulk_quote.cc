#include "bulk_quote.h"

double Bulk_quote::net_price(std::size_t n) const
{
    if (n >= quantity)
        return n * (1 - discount) * price;
    else
        return n * price;
}


void Bulk_quote::debug() const
{
    std::cout << "quantity= " << quantity << " "
            << "discount= " << this->discount << " \n";
}

