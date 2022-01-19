/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pair.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 15:47:26 by tmullan       #+#    #+#                 */
/*   Updated: 2022/01/19 16:20:12 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template < class T1, class T2 >
struct pair
{
	typedef	T1	first_type;
	typedef	T2	second_type;

	


	first_type	first;
	second_type	second;
};
