#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>

using std::vector; using std::string;
using std::list; using std::deque;

template <typename T>
void PrintVector(const std::vector<T>& vec)
{
    for (const auto &elem : vec)
        std::cout << elem << " ";
    std::cout << std::endl;
}

int main()
{
    list<string> test1{"aaa", "bbb", "ccc"};

    vector<string> s0;
    vector<string> s1{"Henry", "Peter", "John"};
    vector<string> s2(s1);
    vector<string> s3(test1.begin(), test1.end());
    vector<string> s4(10, "Henry");             // 10个Henry

    std::cout << "s0:";
    PrintVector(s0);
    std::cout << "s1:";
    PrintVector(s1);
    std::cout << "s2:";
    PrintVector(s2);
    std::cout << "s3:";
    PrintVector(s3);
    std::cout << "s4:";
    PrintVector(s4);

    deque<int> test2{6, 5, 4, 3, 2, 1};

    vector<int> i0;
    vector<int> i1{1, 2, 3, 4, 5, 6};
    vector<int> i2(i1);
    vector<int> i3(test2.begin(), test2.end());
    vector<int> i4(10);                         // 10个0
    vector<int> i5(10, 2);                      // 10个2

    std::cout << "i0:";
    PrintVector(i0);
    std::cout << "i1:";
    PrintVector(i1);
    std::cout << "i2:";
    PrintVector(i2);
    std::cout << "i3:";
    PrintVector(i3);
    std::cout << "i4:";
    PrintVector(i4);
    std::cout << "i5:";
    PrintVector(i5);

    return 0;
}


/*
 *s0:
 *s1:Henry Peter John
 *s2:Henry Peter John
 *s3:aaa bbb ccc
 *s4:Henry Henry Henry Henry Henry Henry Henry Henry Henry Henry
 *i0:
 *i1:1 2 3 4 5 6
 *i2:1 2 3 4 5 6
 *i3:6 5 4 3 2 1
 *i4:0 0 0 0 0 0 0 0 0 0
 *i5:2 2 2 2 2 2 2 2 2 2
 */
