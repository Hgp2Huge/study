/*
 *Exercise 2.5
 *Implement an overloaded set of max() functions to accept (a) two integers, (b) two floats, (c) two
 *strings, (d) a vector of integers, (e) a vector of floats, (f) a vector of strings, (g) an array of integers
 *and an integer indicating the size of the array, (h) an array of floats and an integer indicating the
 *size of the array, and (i) an array of strings and an integer indicating the size of the array. Again,
 *write a main() function to exercise these functions.
 */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>     // output max
using namespace std;

inline int max(int a, int b)
{
    return a > b ? a : b;
}

inline float max(float a, float b)
{
    return a > b ? a : b;
}

inline std::string max(const std::string &s1, const std::string &s2)
{
    return s1 > s2 ? s1 : s2;
}

inline int max(const std::vector<int> &ivec)
{
    return *std::max_element(ivec.cbegin(), ivec.cend());
}

inline float max(const std::vector<float> &fvec)
{
    return *std::max_element(fvec.cbegin(), fvec.cend());
}

inline std::string max(const std::vector<std::string> &svec)
{
     return *std::max_element(svec.cbegin(), svec.cend());
}

inline int max(const int *arr, int size)
{
    return *std::max_element(arr, arr + size);
}

inline float max(const float *arr, int size)
{
     return *std::max_element(arr, arr + size);
}

inline std::string max(const std::string *arr, int size)
{
    return *std::max_element(arr, arr + size);
}

int main()
{
    string str_arr[] = {"we", "were", "her", "pride", "of", "ten"};
    vector<string> svec(str_arr, str_arr + 6);

    int int_arr[] = {12, 70, 2, 169, 1, 5, 29};
    vector<int> ivec(int_arr, int_arr + 7);

    float float_arr[] = {2.5, 24.8, 18.7, 4.1, 23.9};
    vector<float> fvec(float_arr, float_arr + 5);

    int imax = max(max(ivec), max(int_arr, 7));
    float fmax = max(max(fvec), max(float_arr, 5));
    string smax = max(max(svec), max(str_arr, 6));
    cout << "imax should be 169 -- found: " << imax << '\n'
        << "fmax should be 24.8 -- found: " << fmax << '\n'
        << "smax should be were -- found: " << smax << '\n';

    return 0;
}
