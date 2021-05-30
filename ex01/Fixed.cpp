#include "Fixed.hpp"

Fixed::Fixed() : _val(0) {
    std::cout << "Fixed number " << this->_val << " created." << std::endl;
}

Fixed::Fixed(const int val) {
    this->_val = val * (1 << this->_frac);
    std::cout << "Fixed number from " << val << " created." << std::endl;
}

Fixed::Fixed(const float val) {
    this->_val = (int)roundf(val * (float)(1 << this->_frac));
    std::cout << "Fixed number from " << val << " created." << std::endl;    
}

Fixed::Fixed(const Fixed& src) {
   *this = src;
    std::cout << "Fixed number copy created." << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destroyed a number!" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& right) {
    std::cout << "Assigning a fixed to another fixed." << std::endl;
    this->_val = right.getRawBits();
    return *this;
}

int Fixed::getRawBits() const {
    return this->_val;
}

void	Fixed::setRawBits(const int raw) {
    this->_val = raw;
}

float   Fixed::toFloat() const {
    return (float)((float)this->getRawBits() / (1 << this->_frac));
}

int Fixed::toInt() const {
    return (int)(this->getRawBits() / (1 << this->_frac));
}

std::ostream& operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}

const int Fixed::_frac = 8;