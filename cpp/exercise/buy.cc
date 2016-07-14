// 百钱买百鸡
// cock 5, hen 3, 3chick 1

#include <iostream>

int main()
{
    int cock, hen, chick;
    for (cock = 0; cock <= 20; cock++)
        for (hen = 0; hen <= 33; hen++)
            for (chick = 0; chick <= 300; chick++)
                if (100 == 5 * cock + 3 * hen + chick / 3)
                    if (100 == cock + hen + chick)
                        if (chick % 3 == 0) {
                            std::cout << "Cock: " << cock;
                            std::cout << "Hen: " << hen;
                            std::cout << "Chick: " << chick << std::endl;
                        }
}
