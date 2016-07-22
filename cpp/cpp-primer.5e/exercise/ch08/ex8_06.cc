#include <fstream>

#include "../book_source_code/7/Sales_data.h"

using std::ifstream;

// main ../book_source_code/1/data/book_sales
int main(int argc, char** argv)
{
    ifstream ifs(argv[1]);
    Sales_data total;
    if (read(ifs, total))
    {
        Sales_data trans;
        while (read(ifs, trans))
        {
            if (total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                print(std::cout, total) << std::endl;
                total = trans;
            }
        }
        print(std::cout, total) << std::endl;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
    }
    ifs.close();
    return 0;
}
