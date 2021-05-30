#include "Fixed.hpp"

Fixed::Fixed() : _val(0) {}

Fixed::Fixed(const int val) {
    this->_val = val * (1 << this->_frac);
}

Fixed::Fixed(const float val) {
    this->_val = (int)roundf(val * (float)(1 << this->_frac));
}

Fixed::Fixed(const Fixed& src) {
   *this = src;
}

Fixed::~Fixed() {
}

Fixed& Fixed::operator=(const Fixed& right) {
    this->_val = right.getRawBits();
    return *this;
}

bool Fixed::operator>(const Fixed& right) const {
    if (this->_val > right.getRawBits())
        return true;
    else
        return false;
}

bool Fixed::operator<(const Fixed& right) const {
    if (this->_val < right.getRawBits())
        return true;
    else
        return false;
}

bool Fixed::operator>=(const Fixed& right) const {
    if (this->_val >= right.getRawBits())
        return true;
    else
        return false;
}

bool Fixed::operator<=(const Fixed& right) const {
    if (this->_val <= right.getRawBits())
        return true;
    else
        return false;
}

bool Fixed::operator==(const Fixed& right) const {
    if (this->_val == right.getRawBits())
        return true;
    else
        return false;
}

bool Fixed::operator!=(const Fixed& right) const {
    if (this->_val != right.getRawBits())
        return true;
    else
        return false;
}

Fixed   Fixed::operator+(const Fixed& right) const {
    int bits = this->_val + right.getRawBits();
    return Fixed(bits / (1 << Fixed::_frac));
}

Fixed   Fixed::operator-(const Fixed& right) const {
    int bits = this->_val - right.getRawBits();
    return Fixed(bits / (1 << Fixed::_frac));
}

Fixed   Fixed::operator*(const Fixed& right) const {
    return this->toFloat() * right.toFloat();
}

Fixed   Fixed::operator/(const Fixed& right) const {
    float num = (right.toFloat() != 0) ? this->toFloat() / right.toFloat() : 0;
    return Fixed(num);
}

// Fixed&   Fixed::operator++() {
//     this->_val += 1 << this->_frac;
//     return *this;
// }

// Fixed   Fixed::operator++(int num) {
//     (void)num;
//     Fixed tmp = *this;
//     this->_val += 1 << this->_frac;
//     return (tmp);
// }

// Fixed&   Fixed::operator--() {
//     this->_val -= 1 << this->_frac;
//     return *this;
// }

// Fixed   Fixed::operator--(int num) {
//     (void)num;
//     Fixed tmp = *this;
//     this->_val -= 1 << this->_frac;
//     return (tmp);
// }

Fixed&   Fixed::operator++() {
    this->_val += 1;
    return *this;
}

Fixed   Fixed::operator++(int num) {
    (void)num;
    Fixed tmp = *this;
    this->_val += 1;
    return (tmp);
}

Fixed&   Fixed::operator--() {
    this->_val -= 1;
    return *this;
}

Fixed   Fixed::operator--(int num) {
    (void)num;
    Fixed tmp = *this;
    this->_val -= 1;
    return (tmp);
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

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}

const int Fixed::_frac = 8;

Fixed&	Fixed::max(Fixed &a, Fixed &b) {
    if (a > b)
        return a;
    else
        return b;
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b) {
    if (a > b)
        return a;
    else
        return b;
}