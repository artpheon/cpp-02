#include "Fixed.hpp"

Fixed::Fixed() : _val(0) {
    std::cout << "Fixed number " << this->_val << " created." << std::endl;
}

Fixed::Fixed(const Fixed& src) {
   *this = src;
    std::cout << "Fixed number " << this->_val << " copy created." << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destroyed " << this->_val << " number!" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& right) {
    std::cout << "Assigning a fixed to another fixed." << std::endl;
    this->_val = right.getRawBits();
    return *this;
}

int Fixed::getRawBits() const {
    return (this->_val);
}

void	Fixed::setRawBits(const int raw) {
    this->_val = raw;
}

std::ostream&	operator<<(std::ostream& o, const Fixed& src) {
    o << src.getRawBits();
    return (o);
}

const int Fixed::_frac = 8;