#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed {
private:
	int _val;
	static const int _frac;
	int getRawBits() const;
	void	setRawBits(const int raw);

public:
	Fixed();
	Fixed(const int val);
	Fixed(const float val);
	Fixed(const Fixed& src);
	~Fixed();

	Fixed& operator=(const Fixed& right);
	bool operator>(const Fixed& right) const;
	bool operator<(const Fixed& right) const;
	bool operator>=(const Fixed& right) const;
	bool operator<=(const Fixed& right) const;
	bool operator==(const Fixed& right) const;
	bool operator!=(const Fixed& right) const;

	Fixed   operator+(const Fixed& right) const;
	Fixed   operator-(const Fixed& right) const;
	Fixed   operator*(const Fixed& right) const;
	Fixed   operator/(const Fixed& right) const;
	Fixed&  operator++();
	Fixed	operator++(int);
	Fixed&  operator--();
	Fixed   operator--(int num);
	static Fixed&	max(Fixed &, Fixed &);
	static const Fixed&	max(const Fixed &, const Fixed &);


	float	toFloat() const;
	int	toInt() const;

};
std::ostream&	operator<<(std::ostream& o, const Fixed& src);

#endif