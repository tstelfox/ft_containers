/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   equal_lexographical_compare.h                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/25 11:23:53 by tmullan       #+#    #+#                 */
/*   Updated: 2021/10/25 11:36:40 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft {

template < class InputIterator1, class InputIterator2 >
bool	equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {

	while (first1 != last1) {
		if (!(*first1 == *first2))
			return false;
		++first1;
		++first2;
	}
	return true;
}

template < class InputIterator1, class InputIterator2 >
bool	lexographical_compare (InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2) {
	
	while (first1 != last1) {
		if (first2 == last2 || *first2 < *first1)
			return false;
		else if (*first1 < *first2)
			return true;
		++first1;
		++first2;
	}
	return (first2 != last2);
}

}