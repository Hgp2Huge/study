/*
 *Exercise 2.4
 *Introduce a static local vector to hold the elements of your Pentagonal series. This function returns
 *a const pointer to the vector. It accepts a position by which to grow the vector if the vector is not
 *as yet that size. Implement a second function that, given a position, returns the element at that
 *position. Write a main() function to exercise these functions.
 */

#include <vector>
#include <iostream>
using namespace std;

inline bool check_pos(int pos)
{
    return (pos < 1 || pos > 64) ? false : true;
}

const vector<int>* get_pentagonal_sequence(int pos)
{
    static vector<int> _sequence;
    if (check_pos(pos) && (pos > _sequence.size()))
        for (int i = _sequence.size()+1; i <= pos; ++i)
            _sequence.push_back(i*(3*i-1)/2);
    return &_sequence;
}

bool get_pentagonal_elem(int pos, int &elem)
{
    if (!check_pos(pos)) {
        cout << "Sorry. Invalid position: " << pos << endl;
        return false;
    }
    const vector<int> *seq = get_pentagonal_sequence(pos);
    elem = (*seq)[pos-1];
    return true;
}


int main()
{
    int elem;
    if (get_pentagonal_elem(8, elem))
        cout << "element at position 8 is :" << elem << '\n';

    if (get_pentagonal_elem(88, elem))
        cout << "element at position 88 is :" << elem << '\n';

    if (get_pentagonal_elem(12, elem))
        cout << "element at position 12 is :" << elem << '\n';

    if (get_pentagonal_elem(64, elem))
        cout << "element at position 64 is :" << elem << '\n';

    return 0;
}
