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
#include <stdint.h>

namespace ft {


template <class T> struct is_integral { static const bool value = false ;};

template <>          struct is_integral<bool>                { static const bool value = true; };
template <>          struct is_integral<char>                { static const bool value = true; };
template <>          struct is_integral<signed char>         { static const bool value = true; };
template <>          struct is_integral<unsigned char>       { static const bool value = true; };
template <>          struct is_integral<wchar_t>             { static const bool value = true; };
// template <>          struct is_integral<char16_t>            { static const bool value = true; };
// template <>          struct is_integral<char32_t>            { static const bool value = true; };
template <>          struct is_integral<short>               { static const bool value = true; };
template <>          struct is_integral<unsigned short>      { static const bool value = true; };
template <>          struct is_integral<int>                 { static const bool value = true; };
template <>          struct is_integral<unsigned int>        { static const bool value = true; };
template <>          struct is_integral<long>                { static const bool value = true; };
template <>          struct is_integral<unsigned long>       { static const bool value = true; };
template <>          struct is_integral<long long>           { static const bool value = true; };
template <>          struct is_integral<unsigned long long>  { static const bool value = true; };

template <bool Cond, class T = void> struct enable_if {};
template <class T> struct enable_if<true, T> {typedef T type;};

}
