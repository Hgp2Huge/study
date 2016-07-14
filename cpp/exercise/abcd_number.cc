// 说明：abcd = (ab+cd)^2
// 题目：求所有这样的四位数

#include <iostream>

int main()
{
    int ab, cd;
    for (int i = 1000; i < 10000; i++) {
        ab = i / 100;
        cd = i % 100;
        if (i == (ab + cd) * (ab + cd)) std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
