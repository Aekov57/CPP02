/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:28:12 by misimon           #+#    #+#             */
/*   Updated: 2023/05/04 10:47:09 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _nbr(0) {}

Fixed::Fixed(const int value) {
	this->_nbr = (value << this->_bits);
}

Fixed::Fixed(const float value) {
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
	this->_nbr = other.getRawBits();
	return (*this);
}

bool Fixed::operator<(const Fixed& other) const {
	return(_nbr < other._nbr);
}

bool Fixed::operator>(const Fixed& other) const {
	return(_nbr > other._nbr);
}

bool Fixed::operator<=(const Fixed& other) const {
	return(_nbr <= other._nbr);
}

bool Fixed::operator>=(const Fixed& other) const {
	return(_nbr >= other._nbr);
}

bool Fixed::operator==(const Fixed& other) const{
	return(_nbr == other._nbr);
}

bool Fixed::operator!=(const Fixed& other) const{
	return(_nbr != other._nbr);
}

Fixed Fixed::operator+(const Fixed& other) const {
	Fixed tmp(*this);
	tmp.setRawBits(this->getRawBits() + other.getRawBits());
	return (tmp);
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed tmp(*this);
	tmp.setRawBits(this->getRawBits() - other.getRawBits());
	return (tmp);
}

Fixed Fixed::operator*(const Fixed& other) const {
	Fixed tmp(*this);
	tmp.setRawBits(this->getRawBits() * other.getRawBits() / (1 << this->_bits));
	return (tmp);
}

Fixed Fixed::operator/(const Fixed& other) const {
	Fixed tmp(*this);
	tmp.setRawBits((this->getRawBits() * (1 << this->_bits)) / other.getRawBits());
	return (tmp);
}

Fixed Fixed::operator++() {
	this->_nbr += 1;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	++(*this);
	return(temp);
}

Fixed Fixed::operator--() {
	this->_nbr -= 1;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	--(*this);
	return(temp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &value) {
	out << value.toFloat();
	return(out);
}

Fixed::Fixed(const Fixed& copy) {
	*this = copy;
}

void Fixed::setRawBits(int const raw) {
	this->_nbr = raw;
}

Fixed::~Fixed() {}