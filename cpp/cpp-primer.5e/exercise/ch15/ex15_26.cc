/*
 *Exercise 15.26:
 *Define the Quote and Bulk_quote copy-control members to do the same job as the synthesized versions.
 *Give them and the other constructors print statements that identify which function is running.
 *Write programs using these classes and predict what objects will be created and destroyed.
 *Compare your predictions with the output and continue experimenting until your predictions are reliably correct.
 */

#include <iostream>
#include <string>

// class Quote begin
class Quote {
public:
    Quote() { std::cout << "Quote default constructor" << std::endl; }
    Quote(const std::string &book, double sales_price) :
        bookNo(book), price(sales_price) { std::cout << "Quote two parameters constructor" << std::endl; }

    // copy constructor
    Quote(const Quote& q) : bookNo(q.bookNo), price(q.price) {
        std::cout << "Quote copy constructor" << std::endl;
    }

    // move constructor
    Quote(Quote&& q) noexcept : bookNo(std::move(q.bookNo)), price(std::move(q.price)) {
        std::cout << "Quote move constructor" << std::endl;
    }

    // copy =()
    Quote& operator=(const Quote& rhs) {
        bookNo = rhs.bookNo;
        price = rhs.price;

        std::cout << "Quote copy =()" << std::endl;
        return *this;
    }

    // move =()
    Quote& operator=(Quote&& q) noexcept {
        this->bookNo = std::move(q.bookNo);
        this->price = std::move(q.price);
        std::cout << "Quote move =()" << std::endl;
        return *this;
    }

    // members
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const { return n * price; }

    // default destructor
    virtual ~Quote() { std::cout << "Quote default destructor" << std::endl; }

private:
    std::string bookNo;
protected:
    double price = 0.0;

};
// class Quote end


// class Bulk_quote begin
class Bulk_quote : public Quote {
public:
    Bulk_quote() { std::cout << "Bulk_quote default constructor" << std::endl; }

    Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) :
                Quote(book, p), quantity(qty), discount(disc)
    {
        std::cout << "Bulk_quote four parameters constructor" << std::endl;
    }

    // copy constructor
    Bulk_quote(const Bulk_quote& bq) : Quote(bq), quantity(bq.quantity), discount(bq.discount)
    {
        std::cout << "Bulk_quote copy constructor" << std::endl;
    }

    // move constructor
    Bulk_quote(Bulk_quote&& rhs) noexcept :
                Quote(std::move(rhs)),
                quantity(std::move(rhs.quantity)),
                discount(std::move(rhs.discount))
    {
        std::cout << "Bulk_quote move constructor" << std::endl;
    }

    // copy =()
    Quote& operator=(const Bulk_quote& rhs)
    {
        Quote::operator=(rhs);
        this->quantity = rhs.quantity;
        this->discount = rhs.discount;

        std::cout << "Bulk_quote copy=()" << std::endl;
        return *this;
    }

    // move =()
    Quote& operator=(Bulk_quote&& rhs) noexcept
    {
        Quote::operator=(std::move(rhs));
        this->quantity = std::move(rhs.quantity);
        this->discount = std::move(rhs.discount);

        std::cout << "Bulk_quote move()" << std::endl;
        return *this;
    }

    // members
    double net_price(std::size_t cnt) const override
    {
        if (cnt >= quantity)
            return cnt * (1 - discount) * price;
        else
            return cnt * price;
    }

    ~Bulk_quote() { std::cout << "Bulk_quote default destructor" << std::endl; }

protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};
// class Bulk_quote end

int main()
{
    Quote q1; // Quote default constructor
    Quote* q2p = new Quote("ox100sbn", 25.5); // Quote two parameters constructor
    q1 = *q2p; // Quote copy =()
    Quote q3(q1); // Quote copy constructor
    delete q2p; // Quote default destructor
                // Quote default destructor

    Bulk_quote bq1; // Quote default constructor
                    // Bulk_quote default constructor
    Bulk_quote* bq2p = new Bulk_quote("ox100sbc", 30.0, 50, 0.2); // Quote two parameters constructor
                                                                  // Bulk_quote four parameters constructor
    bq1 = *bq2p; // Quote copy =()
                 // Bulk_quote copy=()
    Bulk_quote bq3(bq1); // Quote copy constructor
                         // Bulk_quote copy constructor
    delete bq2p; // Bulk_quote default destructor
                 // Quote default destructor
                 // Bulk_quote default destructor
                 // Quote default destructor

    std::cout << "exit." << std::endl;

    // Bulk_quote default destructor
    // Quote default destructor

    // Quote default destructor
    // Quote default destructor

    return 0;
}


