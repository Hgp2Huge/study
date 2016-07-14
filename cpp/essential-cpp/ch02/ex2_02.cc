/*
 *Exercise 2.2
 *The formula for the Pentagonal numeric sequence is Pn=n*(3n-1)/2. This yields the sequence
 *1, 5, 12, 22, 35, and so on. Define a function to fill a vector of elements passed in to the function
 *calculated to some user-specified position. Be sure to verify that the position specified is valid.
 *Write a second function that, given a vector, displays its elements. It should take a second
 *parameter identifying the type of numeric series the vector represents. Write a main() function to
 *exercise these functions.
 */

#include <iostream>
#include <vector>
#include <limits>
using namespace std;


int main()
{
    // test numeric limit for int
    int max_int = numeric_limits<int>::max();
    std::cout << "The max int number in current system: " << max_int << endl;

    // ex2_02 begin
    bool CalcPentalgonalNum(vector<int>& ivec, int pos);
    void PrintSequence(const vector<int>& ivec, const string &title, ostream &os=cout);

    vector<int> seq;
    const string title("Pentagonal Numeric Sequence");

    if (CalcPentalgonalNum(seq, 0))
        PrintSequence(seq, title);

    if (CalcPentalgonalNum(seq, 8))
        PrintSequence(seq, title);

    if (CalcPentalgonalNum(seq, 14))
        PrintSequence(seq, title);

    if (CalcPentalgonalNum(seq, 9))
        PrintSequence(seq, title);

    if (CalcPentalgonalNum(seq, 138))
        PrintSequence(seq, title);

    return 0;
}


bool CalcPentalgonalNum(vector<int>& ivec, int pos)
{
    if (pos < 1 || pos > 64) {
        cerr << "Sorry. Invalid position: " << pos << endl;
        return false;
    }

    for (int i = ivec.size()+1; i <= pos; ++i)
        ivec.push_back(i*(3*i-1)/2);

    return true;
}

void PrintSequence(const vector<int>& ivec, const string &title, ostream &os=cout)
{

    os << '\n' << title << "\t Position: " << ivec.size() << endl;
    for (int i = 0; i < ivec.size(); ++i )
        os << ivec[i] << ' ';
    os << endl;
}

