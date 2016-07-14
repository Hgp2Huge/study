/* *Exercise 15.15:
 *Define your own versions of Disc_quote and Bulk_quote.
 */

#include <string>

class Quote {
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price):
        bookNo(book), price(sales_price) {}
    std::string isbn() const { return bookNo; }
    // 返回给定数量的书籍的销售总额
    // 派生类负责改写并使用不同的折扣计算算法
    virtual double net_price(std::size_t n) const { return n * price; }
    virtual ~Quote() = default;     // 对析构函数进行动态绑定
private:
    std::string bookNo;             // 书籍的ISBN编号
protected:
    double price = 0.0;             // 代表普通状态下不打折的价格
};

class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string &book, double price, std::size_t qty, double disc) :
        Quote(book, price), quantity(qty), discount(disc) {}
    double net_price(std::size_t) const = 0;
protected:
    std::size_t quantity = 0;       // 折扣使用的购买量
    double discount = 0.0;          // 表示折扣的小数值
};


// 当统一书籍的销售量超过某个值时启用折扣
// 折扣的值是一个小于1的正小数，一次来降低正常销售价格
class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double price, std::size_t qty, double disc) :
        Disc_quote(book, price, qty, disc) {}
    // 覆盖基类中的函数版本以实现一种新的折扣策略
    double net_price(std::size_t n) const override {
         if (n >= quantity)
             return n * (1 - discount) * price;
         else
             return n * price;
    }
};

