// 介绍：
//      最大公约数（Greatest Common Divisor)，常用算法Euclid
//      最小公倍数（Lowest Common Muliple)

//      Euclid算法：gcd(a, b) = gcd(b, a mod b),a > b
//      两数相乘的积除以其最大公约数就是最小公倍数

// 题目：求输入的两个正整数的最大公约数与最小公倍数

#include <iostream>

// Recursion 递归
int Gcd(int a, int b)
{
    if (b == 0) return a;
    return Gcd(b, a % b);
}

// Common
//int Gcd(int a, int b)
//{
//    int tmp;
//    while (b != 0) {
//        tmp = b;
//        b = a % b;
//        a = tmp;
//    }
//}

void Swap(int& a, int& b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int a, b;
    int gcd, lcm;
    std::cout << "Please input two numbers: ";
    std::cin >> a >> b;
    if (a < b) Swap(a,b); // keep a > b before using Gcd(a, b)
    gcd = Gcd(a, b);
    lcm = a * b / gcd;
    std::cout << "The greatest common divisor is: " << gcd << std::endl;
    std::cout << "The lowest common mutiple is: " << lcm << std::endl;
    return 0;
}
