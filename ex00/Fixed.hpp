#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed {
private:
    int _val;
    static const int _frac;

public:
    Fixed();
    Fixed(const Fixed& src);
    ~Fixed();

    Fixed& operator=(const Fixed& right);
    int getRawBits() const;
	void	setRawBits(const int raw);
};

std::ostream&	operator<<(std::ostream& o, Fixed const& src);

#endif