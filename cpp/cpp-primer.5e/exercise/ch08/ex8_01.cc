#include <iostream>

using std::istream;

istream& func(istream& is) {
    std::string tmp;
    while(is >> tmp)
        std::cout << tmp << std::endl;
    is.clear();
    return is;
}


int main()
{
    istream& is = func(std::cin);
    std::cout << is.rdstate() << std::endl;  // return current state of istream, type is strm::iostate

    // show value of flags
    is.clear();
    std::cout << is.rdstate() << std::endl;
    // badbit  value:1
    is.setstate(std::ios::badbit);
    std::cout << is.rdstate() << std::endl;
    is.clear();
    // failbit value:4
    is.setstate(std::ios::failbit);
    std::cout << is.rdstate() << std::endl;
    is.clear();
    // eofbit value:2
    is.setstate(std::ios::eofbit);
    std::cout << is.rdstate() << std::endl;
    is.clear();
    // goodbit value:0
    is.setstate(std::ios::goodbit);
    std::cout << is.rdstate() << std::endl;
    is.clear();


    return 0;
}

// while (cin >> i)
// putting cin in an error state cause to terminate.
// such as eofbit,failbit and badbit.whose flags is not zero
