/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:27:29 by misimon           #+#    #+#             */
/*   Updated: 2023/05/04 10:02:06 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	static const int _bits = 8;
	int _nbr;
public:
	Fixed();
	Fixed(const Fixed& copy);
	~Fixed();
	
	Fixed& operator=(const Fixed& other);
	
	int getRawBits(void) const;
	void setRawBits(int const raw);	
};

#endif