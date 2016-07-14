#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream ofile;
    cout << "Create file1" << endl;
    ofile.open("test.txt",ios::out);
    if (!ofile.fail()) {
        ofile << "name1" << " ";
        ofile << "sex1" << " ";
        ofile << "age1";
        ofile.close();
        cout << "Create file2" << endl;
        ofile.open("test2.txt");
        if (!ofile.fail()) {
            ofile << "name2" << " ";
            ofile << "sex2" << " ";
            ofile << "age2";
            ofile.close();
        }
    }
    return 0;
}
