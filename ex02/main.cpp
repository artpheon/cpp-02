#include "Fixed.hpp"
#include <iostream>
#include <string>
#include <iomanip>


int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << std::setw(5) << "a:\t" << std::setw(5) << a << std::endl;
    std::cout << std::setw(5) << "++a:\t" << std::setw(5) << ++a << std::endl;
    std::cout << std::setw(5) << "a:\t" << std::setw(5) << a << std::endl;
    std::cout << std::setw(5) <<"a++:\t" << std::setw(5) << a++ << std::endl;
    std::cout << std::setw(5) <<"a:\t" << std::setw(5) << a << std::endl;
    std::cout << std::setw(5) << "b:\t" << std::setw(5) << b << std::endl;
    std::cout << std::setw(5) << "max(a, b):" << std::setw(5) << Fixed::max( a, b ) << std::endl;
return 0; }