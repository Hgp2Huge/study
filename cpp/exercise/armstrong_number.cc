// 介绍：阿姆斯特朗数俗称水仙花数，是指一个三位数，其各位数字的立方和等于其本身。
// 题目：编程求出所有水仙花数.

#include <iostream>

int main()
{
    int j, k, l;
    for (int i = 100; i < 1000; i++) {
        j = i % 10;
        k = i / 10 % 10;
        l = i / 100;
        if(i == j*j*j + k*k*k + l*l*l) std::cout << i << " ";
    }

    std::cout << std::endl;
    return 0;
}
