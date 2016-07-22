#include "quote.h"

void Quote::debug() const
{
    std::cout << "bookNO: " << this->bookNo << " "
                << "price: " << this->price << " \n";
}
