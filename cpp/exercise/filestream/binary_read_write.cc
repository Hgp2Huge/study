#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main()
{
    char buf[50];
    fstream file;
    file.open("text.data", ios::binary | ios::out);
    for (int i = 0; i < 2; i++) {
        memset(buf, 0, 50);
        cin >> buf;
        file.write(buf, 50);
        file << endl;
    }
    file.close();

    file.open("test.data", ios::binary | ios::in);
    while (!file.eof()) {
        memset(buf, 0, 50);
        file.read(buf, 50);
        if (file.tellg() > 0)
            cout << buf;
    }
    cout << endl;
    file.close();
    return 0;
}
