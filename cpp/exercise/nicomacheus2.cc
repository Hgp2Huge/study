// 尼科彻斯定理内容是：任何一个整数的立方都可以写成一串连续奇数的和。编程验证该定理。
// 根据等差数列求和公式可以得到数列第一项是a1=m*m-m+1,数列共m项
// am = a1 + (m-1)d



#include <iostream>
#include <vector>

bool GetNumbers(int m, std::vector<int> &result)
{
    int cube = m * m * m;
    int a1 = m * m - m + 1;
    int i = 0, sum = 0;
    while (i < m) {
        result.push_back(a1 + 2 * i);
        sum += a1 + 2 * i;
        i++;
    }
    if (sum == cube)
        return true;
    else
        return false;
}

int main()
{
    std::cout << "Input the number: " << std::endl;
    int m;
    while(std::cin >> m) {
        if (m <= 0) {
            std::cout << "Error number: " << m << std::endl;
            continue;
        }
        std::vector<int> result;

        if (GetNumbers(m, result)) {
            // Print reslut
            std::cout << m << "^3 = ";
            std::vector<int>::iterator iter = result.begin();
            std::vector<int>::iterator end = result.end();
            while (iter < end - 1) {
                std::cout << *iter << "+";
                iter++;
            }
            std::cout << *iter << std::endl;  // print the last number
        }
    }
    return 0;
}
