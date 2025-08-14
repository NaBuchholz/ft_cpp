#include "../includes/Fixed.hpp"

bool Fixed::operator>(const Fixed& other) const
{
	return this->_fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed& other) const
{
	return this->_fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return this->_fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return this->_fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed& other) const
{
	return this->_fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return this->_fixedPointValue != other._fixedPointValue;
}
