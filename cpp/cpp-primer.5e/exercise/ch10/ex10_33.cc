/*
 *Exercise 10.33:
 *Write a program that takes the names of an input file and two output files.
 *The input file should hold integers. Using an istream_iterator read the input file.
 *Using ostream_iterators, write the odd numbers into the first output file. Each value should be followed by a space.
 *Write the even numbers into the second file. Each of these values should be placed on a separate line.
 */

// Usage:ex10_33 <in_file> <odd_out_file> <even_out_file>

#include <fstream>
using std::ifstream; using std::ofstream;

#include <vector>
using std::vector;

#include <iterator>
using std::istream_iterator; using std::ostream_iterator;

int main(int argc, char* argv[])
{
    ifstream in_file_nums(argv[1]);
    ofstream out_file_odd_nums(argv[2]);
    ofstream out_file_even_nums(argv[3]);

    istream_iterator<int> in_nums_iter(in_file_nums), eof;
    ostream_iterator<int> out_odd_nums_iter(out_file_odd_nums, " ");
    ostream_iterator<int> out_even_nums_iter(out_file_even_nums, "\n");

    while (in_nums_iter != eof) {
        *in_nums_iter % 2 ? out_odd_nums_iter = *in_nums_iter : out_even_nums_iter = *in_nums_iter;
        in_nums_iter++;
    }

    return 0;
}
