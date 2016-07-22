/*
 *Exercise 15.16:
 *Rewrite the class representing a limited discount strategy,
 *which you wrote for the exercises in § 15.2.2 (p. 601), to inherit from Disc_quote.
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


class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const string&, double, std::size_t, double) :
        Quote(book, p), min_qty(qty), discount(disc) {}
    double net_price(std::size_t n) const override;
private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

class Bulk_quote2 : public Disc_quote {
publci:
    Bulk_quote2() = default;
    Bulk_quote2(std::string &book, double price, std::size_t qty, double disc) :
        Disc_quote(book, price, qty, disc) {}
    double net_price(std::size_t n) const override {
        if (cnt < min_qty)
            return cnt * (1 - discount) * price;
        else
            return (cnt - min_qty * discount) * price;
    }
};
