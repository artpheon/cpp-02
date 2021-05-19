#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed {
private:
    int _val;
    static const int _frac = 8;

public:
    Fixed();
    Fixed(const Fixed& src);
    ~Fixed();

    Fixed& operator=(const Fixed& right);
	int	getValue() const;
    int getRawBits() const;
	void	setRawBits(const int raw);
};

std::ostream&	operator<<(const std::ostream& o, Fixed const& src);

#endif