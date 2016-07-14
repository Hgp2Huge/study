// 求一个整数任意次方后的最后三位数

#include <iostream>

int main()
{
    int i, x, y;
    int z = 1;

    std::cout << "输入两个整数 x, y (x^y): ";
    std::cin >> x >> y;

    for(i=1; i<=y; i++)
        z = z * x % 1000; // 截取低三位

    if(z>=100)
        std::cout << x << "^" << y << "的最后三位数是: " << z << std::endl;
    else
        std::cout << x << "^" << y << "的最后三位数是: 0" << z << std::endl;

    return 0;
}
