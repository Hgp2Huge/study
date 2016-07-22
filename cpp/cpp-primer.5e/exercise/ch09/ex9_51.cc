#include <iostream>
#include <string>
using namespace std;

class MyDate {
private:
    unsigned year, month, day;
public:
    MyDate(const string& date_str);
    void print();
};

MyDate::MyDate(const string& date_str)
{
    string::size_type pos_day_begin = date_str.find_first_of("0123"); // find the pos of begin of day
    // 1/1/1900
    if (pos_day_begin == 0) {
        auto pos_day_end = date_str.find("/");
        auto pos_month_end = date_str.rfind("/");
        day = stoi(date_str.substr(pos_day_begin, pos_day_end));
        month = stoi(date_str.substr(pos_day_end + 1, pos_month_end));
        year = stoi(date_str.substr(pos_month_end + 1, date_str.size()));

    }
    // January 1, 1900 or Jan 1 1900
    else {
        if (date_str.find("Jan") < date_str.size()) month = 1;
        if (date_str.find("Feb") < date_str.size()) month = 2;
        if (date_str.find("Mar") < date_str.size()) month = 3;
        if (date_str.find("Apr") < date_str.size()) month = 4;
        if (date_str.find("May") < date_str.size()) month = 5;
        if (date_str.find("Jun") < date_str.size()) month = 6;
        if (date_str.find("Jul") < date_str.size()) month = 7;
        if (date_str.find("Aug") < date_str.size()) month = 8;
        if (date_str.find("Sep") < date_str.size()) month = 9;
        if (date_str.find("Oct") < date_str.size()) month = 10;
        if (date_str.find("Nov") < date_str.size()) month = 11;
        if (date_str.find("Dec") < date_str.size()) month = 12;

        auto pos_day_end = date_str.find_first_not_of("0123456789",pos_day_begin);
        day = stoi(date_str.substr(pos_day_begin, pos_day_end));
        year = stoi(date_str.substr(pos_day_end + 1, date_str.size()));
    }
}

void MyDate::print()
{
    std::cout << "year:" << year << " month:" << month << " day:" << day;
}


int main()
{
     MyDate date1("January 1, 1900");
     date1.print();
     std::cout << std::endl;
     MyDate date2("25/12/2016");
     date2.print();
     std::cout << std::endl;
     MyDate date3("Oct 10 1999");
     date3.print();
     std::cout << std::endl;

     return 0;
}
