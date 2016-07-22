#include <iostream>
#include <vector>

using std::vector;

int main()
{
    vector<int> v;
    int val1, val2, val3, val4;
    val1 = v.at(0);
    val2 = v[0];
    val3 = v.front();
    val4 = *(v.begin());

    std::cout << "val1: " << val1 <<std::endl;
    std::cout << "val2: " << val2 <<std::endl;
    std::cout << "val3: " << val3 <<std::endl;
    std::cout << "val4: " << val4 <<std::endl;

    return 0;
}
