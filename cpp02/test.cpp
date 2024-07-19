#include <iostream>
#include <math.h>

int main()
{
    double   a = 1.5f;
    double   b = 3.7f;

    int fixed = (int )roundf( 28.2f * 256 ) ;
    int fixed1 = (int )roundf( 3.7f * 256 ) ;
    // int fixed = (int )roundf( 2.2f * 256 ) ;
    std::cout << fixed << std::endl;
    std::cout << fixed1 << std::endl;

    // std::cout << ((fixed * fixed1) >> 8) << std::endl;
    // std::cout << (((float)((fixed / fixed1) << 8)) / 256) << std::endl;
    // std::cout << (((float)(((fixed << 8) / fixed1))) / 256) << std::endl;
    return (0);
}
