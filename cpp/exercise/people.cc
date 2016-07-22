#include <iostream>
#include <string>

class People {
public:
    People(); // default constructor
    People(int number, std::string name, char sex,unsigned int age, std::string id_number);
    People(const People&); // copy constructor
    ~People() {}

private:
    unsigned int number_;
    std::string name_;
    char sex_;
    unsigned int age_;
    std::string id_number_;
};

People::People(int number, std::string name, char sex,unsigned int age, std::string id_number)
    :number_(number),name_(name),sex_(sex),age_(age),id_number_(id_number)
{

}

People::People(const People &p)
    :number_(p.number_),name_(p.name_),sex_(p.sex_),age_(p.age_),id_number_(p.id_number_)
{

}


