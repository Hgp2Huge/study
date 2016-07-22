/*
 *Exercise 15.7:
 *Define a class that implements a limited discount strategy, which applies a discount to books purchased up to a given limit.
 *If the number of copies exceeds that limit, the normal price applies to those purchased beyond the limit.
 */


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


class Disc_Quote : public Quote {
public:
    Disc_Quote() = default;
    Disc_Quote(const string&, double, std::size_t, double);
    double net_price(std::size_t n) const override;
private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

Disc_Quote::Disc_Quote(const string &book, double p, std::size_t qty, double disc)
    : Quote(book, p), min_qty(qty), discount(disc) {}

double Disc_Quote::net_price(std::size_t cnt) const {
    if (cnt < min_qty)
        return cnt * (1 - discount) * price;
    else
        return (cnt - min_qty * discount) * price;
}
