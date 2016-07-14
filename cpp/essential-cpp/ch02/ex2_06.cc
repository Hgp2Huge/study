/*
 *Exercise 2.6
 *Reimplement the functions of Exercise 2.5 using templates. Modify the main() function
 *accordingly.
 */

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

template <typename T>
inline T max(const T& v1, const T& v2)
{
    return v1 < v2 ? v2 : v1;
}

template <typename T>
inline T max(const std::vector<T>& vec)
{
    return *max_element(vec.cbegin(), vec.cend());
}

template <typename T>
inline T max(const T *arr, int size)
{
    return *max_element(arr, arr + size);
}


int main()
{
    string str_arr[] = {"we", "were", "her", "pride", "of", "ten"};
    vector<string> svec(str_arr, str_arr + 6);

    int int_arr[] = {12, 70, 2, 169, 1, 5, 29};
    vector<int> ivec(int_arr, int_arr + 7);

    float float_arr[] = {2.5, 24.8, 18.7, 4.1, 23.9};
    vector<float> fvec(float_arr, float_arr + 5);

    // ::max申明使用本文件定义的max模板
    int imax = ::max(max(ivec), max(int_arr, 7));
    float fmax = ::max(max(fvec), max(float_arr, 5));
    string smax = ::max(max(svec), max(str_arr, 6));
    cout << "imax should be 169 -- found: " << imax << '\n'
        << "fmax should be 24.8 -- found: " << fmax << '\n'
        << "smax should be were -- found: " << smax << '\n';

    return 0;
}
