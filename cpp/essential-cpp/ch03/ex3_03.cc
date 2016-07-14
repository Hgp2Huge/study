/*
 *Exercise 3.3
 *Define a map for which the index is the family surname and the key is a vector of the children's
 *names. Populate the map with at least six entries. Test it by supporting user queries based on a
 *surname and printing all the map entries.
 */


#include <iostream>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

void PrintFamily(const string family_name, const vector<string>& children)
{
    cout << "The family " << family_name << " has " << children.size() << " children.\n";
    cout << "They are ";

    for (const auto s : children)
        cout << s << " ";
    cout << endl;
}

void QueryFamily(const map<string, vector<string>> &families, const string &surname)
{
    auto it = families.find(surname);
    if (it != families.end())
        PrintFamily(it->first, it->second);
    else
        cout << "family " << surname << "not found." << endl;
}


int main()
{
    // populate map
    map<string, vector<string>> families;

    ifstream in_file("data/families.txt");
    if (!in_file) {
        cerr << "Error in open file.\n";
        return -1;
    }

    string line;
    while (getline(in_file, line)) {
        string family_name;
        vector<string> children;
        string::size_type pos = 0, prev_pos = 0,
            line_size = line.size();

        while ((pos = line.find_first_of(' ', pos)) != string::npos) {
            string::size_type word_len = pos - prev_pos;
            if (!prev_pos)
                family_name = line.substr(prev_pos, word_len);
            else
                children.push_back(line.substr(prev_pos, word_len));
            prev_pos = pos++;
        }

        // handle last child or only family name
        if (prev_pos < line.size()) {
            if (!prev_pos)
                family_name = line.substr(prev_pos, pos - prev_pos);
            else
                children.push_back(line.substr(prev_pos, pos - prev_pos));
        }

        if (!families.count(family_name))
            families[family_name] = children;
        else cerr << "Oops! We already have a " << family_name << " family in our map!" << endl;
    }


    cout << "Please enter surname to query: ";
    string surname;
    cin >> surname;
    QueryFamily(families, surname);

    // Print all families
    cout << "\nNow, print all families." << endl;
    for (const auto &f : families)
        PrintFamily(f.first, f.second);

    return 0;
}
