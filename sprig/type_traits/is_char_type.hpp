#ifndef SPRIG_TYPE_TRAITS_IS_CHAR_TYPE_HPP
#define SPRIG_TYPE_TRAITS_IS_CHAR_TYPE_HPP

#include <sprig/config/config.hpp>

#ifdef SPRIG_USING_PRAGMA_ONCE
#	pragma once
#endif	// #ifdef SPRIG_USING_PRAGMA_ONCE

#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_cv.hpp>
#include <boost/mpl/or.hpp>

namespace sprig {
	//
	// is_char_type
	//
	template<typename T>
	struct is_char_type
		: public boost::mpl::or_<
			boost::is_same<typename boost::remove_cv<T>::type, char>,
			boost::is_same<typename boost::remove_cv<T>::type, signed char>,
			boost::is_same<typename boost::remove_cv<T>::type, unsigned char>
		>
	{};
}	// namespace sprig

#endif	// #ifndef SPRIG_TYPE_TRAITS_IS_CHAR_TYPE_HPP
