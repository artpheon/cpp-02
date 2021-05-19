#include "Fixed.hpp"
#include <iostream>

std::ostream&	operator<<(std::ostream& stream, const Fixed& src) {
    stream << src.toFloat();
    return stream;
}
int main() {
    {
        float i = 5.5;
        Fixed number(i);
        std::cout << number << " is " << number.getRawBits() << std::endl;
    }

    {
        float i = 0.0555;
        Fixed number(i);
        std::cout << "number " << number << " is " << number.getRawBits() << std::endl;
    }
    {
        int i = -10;
        Fixed number(i);
        std::cout << "number " << number.toFloat() << " is " << number.getRawBits() << std::endl;
    }
    {
        Fixed a;
        Fixed const b( 10 );
        Fixed const c( 42.42f );
        Fixed const d( b );
        a = Fixed( 1234.4321f );
        std::cout << "a is " << a << std::endl;
        std::cout << "b is " << b << std::endl;
        std::cout << "c is " << c << std::endl;
        std::cout << "d is " << d << std::endl;
        std::cout << "a is " << a.toInt() << " as integer" << std::endl;
        std::cout << "b is " << b.toInt() << " as integer" << std::endl;
        std::cout << "c is " << c.toInt() << " as integer" << std::endl;
        std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    }
    return (0);
}