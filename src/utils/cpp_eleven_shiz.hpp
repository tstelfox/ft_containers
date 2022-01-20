/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cpp_eleven_shiz.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 17:23:34 by tmullan       #+#    #+#                 */
/*   Updated: 2022/01/19 17:27:07 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <type_traits>

template <class T>
struct is_integral : integral_constant
{
	// I REALLY don't get the point of this
};
