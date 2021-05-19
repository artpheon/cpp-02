#include "Fixed.hpp"


int main() {
    Fixed num;
    num.setRawBits(5);
    std::cout << "Now number contains value " << num.getRawBits() << "." << std::endl;

    {
        Fixed a;
        Fixed b( a );
        Fixed c;
        c = b;
       /* std::cout << a.getRawBits() << std::endl;
        std::cout << b.getRawBits() << std::endl;
        std::cout << c.getRawBits() << std::endl;*/
        std::cout << c;
    }
    return (0);
}