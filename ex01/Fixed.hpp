#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed {
private:
    int _val;
    static const int _frac = 8;
    bool    _checkMaxMin(int nbr);
    void    _throwErr();

public:
    Fixed();
    Fixed(const int val);
    Fixed(const float val);
    Fixed(const Fixed& src);
    ~Fixed();

    Fixed& operator=(const Fixed& right);
    int getRawBits() const;
	void	setRawBits(const int raw);
    float   toFloat() const;
    int toInt() const;
    
};

std::ostream&	operator<<(const std::ostream& o, const Fixed& src);

#endif