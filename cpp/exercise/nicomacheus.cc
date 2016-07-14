// 尼科彻斯定理内容是：任何一个整数的立方都可以写成一串连续奇数的和。编程验证该定理。
// 根据等差数列求和公式可以得到数列第一项是a1=m*m-m+1,数列共m项
// am = a1 + (m-1)d

#include <iostream>
#include <vector>

void GetNumbers(int m, std::vector<int> &result)
{
    int cube = m * m * m;
    int last = cube / 2;               // last is largest in the sequence
    if (last % 2 == 0) last += 1;   // last is odd number

    bool flag = true;
    int sum, k;
    while (flag && last >= 1) {
        sum = 0;
        k = 0;
        while (1) {
            sum += last - 2 * k;
            k++;
            if (sum == cube) {
                for (k--; k >= 0; k--)
                    result.push_back(last - 2 * k);
                flag = false;           // switch flag to false to stop the loop
            }
            if (sum > cube)
                break;
        }
        last -= 2;
    }
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
        GetNumbers(m, result);

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
    return 0;
}
