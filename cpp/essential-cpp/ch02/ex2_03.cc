/*
 *Exercise 2.3
 *Separate the function to calculate the Pentagonal numeric sequence implemented in Exercise 2.2
 *into two functions. One function should be inline; it checks the validity of the position. A valid
 *position not as yet calculated causes the function to invoke a second function that does the actual
 *calculation.
 */

extern void calcuPentalgonalNum(vector<int>& ivec, int pos);

inline bool CalcPentalgonalNum(vector<int>& ivec, int pos)
{
    if (pos < 1 || pos > 64) {
        cerr << "Sorry. Invalid position: " << pos << endl;
        return false;
    }

    if (ivec.size() < pos)
        calcuPentalgonalNum(ivec, pos);

    return true;
}


void calcuPentalgonalNum(vector<int>& ivec, int pos)
{
    for (int i = ivec.size()+1; i <= pos; ++i)
        ivec.push_back(i*(3*i-1)/2);
}


