// 黑纸与白纸

// 黑-0，白-1

#include <iostream>

int main()
{

    std::cout << "Black - 0, White - 1" << std::endl;
    for (int a = 0; a < 2; a++)
        for (int b = 0; b < 2; b++)
            for (int c = 0; c < 2; c++)
                for (int d = 0; d < 2; d++)
                    for (int e = 0; e < 2; e++) {
                        if ((a && b + c + d + e == 3 || !a && b + c + d + e != 3)
                                && (b && a + c + d + e == 0 || !b && a + c + d + e != 0)
                                && (c && a + b + d + e == 1 || !c && a + b + d + e != 1)
                                && (d && a + b + c + e == 4 || !d && a + b + c + e != 4 )) {
                            std::cout << "A is: " << a << std::endl;
                            std::cout << "B is: " << b << std::endl;
                            std::cout << "C is: " << c << std::endl;
                            std::cout << "D is: " << d << std::endl;
                            std::cout << "E is: " << e << std::endl;
                            std::cout << std::endl;
                        }

                    }

}
