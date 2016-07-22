#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    // C-style character string
    char user_name[128];
    cout << "Please enter your name: ";
    cin.getline(user_name, 128);

    if (1 < strlen(user_name))
        cout << "Hello, " << user_name << ", saved in C-style.\n";
    else
        cout << "Error: the input must be at least two characters in length.\n";


    return 0;
}
