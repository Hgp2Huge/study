/*
 *Exercise 15.6:
 *Test your print_total function from the exercises in §15.2.1 (p. 595) by passing both Quote and Bulk_quote objects o that function.
 */


#include <string>
using std::string;
#include <iostream>
using std::cout; using std::endl; using std::ostream;

class Quote {
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price):
        bookNo(book), price(sales_price) {}
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const { return n * price; }
    virtual ~Quote() = default;

private:
    std::string bookNo;
protected:
    double price = 0.0;

};



double print_total(ostream &os, const Quote &item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
        << " # sold: " << n << " total due: " << ret << endl;
    return ret;
};


class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string&, double, std::size_t, double);
    double net_price(std::size_t) const override;
private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};


Bulk_quote::Bulk_quote(const std::string &book, double p, std::size_t qty, double disc)
    : Quote(book, p), min_qty(qty), discount(disc) {}

double Bulk_quote::net_price(std::size_t cnt) const {
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}


int main()
{
     Quote quote("0x100151", 25);
     Bulk_quote bulk("0x100161",25, 5, 0.5);

     print_total(cout, quote, 10);
     print_total(cout, bulk, 10);
     return 0;
}
