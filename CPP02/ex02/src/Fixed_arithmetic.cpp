#include "../includes/Fixed.hpp"

bool Fixed::operator!=(const Fixed& other) const
{
	return this->_fixedPointValue != other._fixedPointValue;
}

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