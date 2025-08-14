#include "../includes/Fixed.hpp"

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->_fixedPointValue + other._fixedPointValue);
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->_fixedPointValue - other._fixedPointValue);
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	result.setRawBits((this->_fixedPointValue * other._fixedPointValue) >> this->_fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	result.setRawBits((this->_fixedPointValue << this->_fractionalBits) / other._fixedPointValue);
	return result;
}
