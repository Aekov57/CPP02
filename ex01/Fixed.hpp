/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:27:29 by misimon           #+#    #+#             */
/*   Updated: 2023/05/03 16:35:01 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	static const int _bits = 8;
	int _nbr;
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& copy);
	~Fixed();

	Fixed& operator=(const Fixed& other);
	
	float	toFloat(void) const;
	int		toInt(void) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);	
};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif