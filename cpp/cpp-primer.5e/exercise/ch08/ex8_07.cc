
/*
 *Input:" ../book_source_code/1/data/book_sales"
 *Output:"total.txt"
 */

#include <fstream>

#include "../book_source_code/7/Sales_data.h"

using std::ifstream; using std::ofstream;

int main(int argc, char** argv)
{
    ifstream ifs(argv[1]);
    ofstream ofs(argv[2], ofstream::app);
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
                print(ofs, total) << std::endl;
                total = trans;
            }
        }
        print(ofs, total) << std::endl;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
    }
    ifs.close();
    ofs.close();
}
