#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main()
{
    char buf[128];
    ofstream ofile("text.txt");
    for (int i = 0; i < 5; i++) {
        memset(buf, 0, 128);
        cin >> buf;
        ofile << buf;
    }
    ofile.close();
    ifstream ifile("text.txt");
    while (!ifile.eof()) {
        char ch;
        ifile.get(ch);
        if (!ifile.eof())
            cout << ch;
    }
    cout << endl;
    ifile.close();
    return 0;
}
