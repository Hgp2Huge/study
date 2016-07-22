#include "basket.h"

double Basket::total_receipt(std::ostream &os) const
{
    double sum = 0.0;       // 保存总价格
    // iter 指向ISBN相同的一批元素中的第一个
    // upper_bound返回一个迭代器，指向这批元素的尾后位置
    for (auto iter = items.cbegin();
              iter != items.cend();
              iter = items.upper_bound(*iter)) {
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << "Total sale: " << sum << std::endl;
    return sum;
}
