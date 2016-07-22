#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vecotr<int> ivec;
    int ival;
    while (cin >> ival)
        ivec.push_back(ival);

    for (int sum = 0, i = 0; i < ivec.size(); ++i)
        sum += ivec[i];

    int average = sum / ivec.size();

    cout << "Sum of " << ivec.size()
        << "elemets: " << sum << "\n"
        << "Average: " << average << endl;
}
