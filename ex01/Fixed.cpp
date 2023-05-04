/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:28:12 by misimon           #+#    #+#             */
/*   Updated: 2023/05/04 10:06:50 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _nbr(0) {
	std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->_nbr = (value << this->_bits);
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->_nbr = roundf(value * (1 << this->_bits));
}

float	Fixed::toFloat(void) const {
	return ((float)this->_nbr / (float)(1 << this->_bits));
}

int		Fixed::toInt(void) const {
	return (this->_nbr >> this->_bits);
}

int Fixed::getRawBits(void) const {
	return(this->_nbr);
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_nbr = other.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &value) {
	out << value.toFloat();
	return(out);
}

Fixed::Fixed(const Fixed& copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

void Fixed::setRawBits(int const raw) {
	this->_nbr = raw;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}