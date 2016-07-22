#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    ifstream in("data/words.txt");
    string word;
    vector<string> svec;

    if (!in.is_open()) {
        cout << "Error: file not found!" << endl;
        return 0;
    }

    while (in >> word) {
        svec.push_back(word);
    }

    in.close();

    for (auto s : svec)
        cout << s << " ";
    cout << endl;

    sort(svec.begin(), svec.end());

    ofstream out("data/words_sorted.txt");

    for (auto s : svec)
        out << s << " ";
    out << endl;
    out.close();

    return 0;
}
