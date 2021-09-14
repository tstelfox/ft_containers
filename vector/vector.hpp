/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/14 17:07:27 by tmullan       #+#    #+#                 */
/*   Updated: 2021/09/14 17:08:11 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class vector
{
private:
	/* data */
public:
	vector(/* args */);
	~vector();
};

vector::vector(/* args */)
{
	std::cout << "The vector is here" << std::endl;
}

vector::~vector()
{
}
