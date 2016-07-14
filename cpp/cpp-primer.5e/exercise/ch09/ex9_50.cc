#include <iostream>
#include <vector>
#include <string>

using std::vector; using std::string;

int int_sum_from_string(const vector<string> &str)
{
    int sum = 0;
    for (auto s : str)
        sum += stoi(s);
    return sum;
}

double double_sum_from_string(const vector<string> &str)
{
    double sum = 0;
    for (auto s : str)
        sum += stof(s);
    return sum;
}

int main()
{
     vector<string> str_i = {"1", "2", "3", "4", "5"};
     vector<string> str_f = {"0.1", "0.2", "0.3", "0.4", "0.5"};

     std::cout << int_sum_from_string(str_i) << std::endl;
     std::cout << double_sum_from_string(str_f) << std::endl;

     return 0;
}
