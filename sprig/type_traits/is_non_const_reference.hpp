#ifndef SPRIG_TYPE_TRAITS_IS_NON_CONST_REFERENCE_HPP
#define SPRIG_TYPE_TRAITS_IS_NON_CONST_REFERENCE_HPP

#include <sprig/config/config.hpp>

#ifdef SPRIG_USING_PRAGMA_ONCE
#	pragma once
#endif	// #ifdef SPRIG_USING_PRAGMA_ONCE

#include <boost/mpl/and.hpp>
#include <boost/mpl/not.hpp>
#include <boost/type_traits/is_const.hpp>
#include <boost/type_traits/is_reference.hpp>
#include <boost/type_traits/remove_reference.hpp>

namespace sprig {
	//
	// is_non_const_reference
	//
	template<typename T>
	struct is_non_const_reference
		: public boost::mpl::and_<
			boost::is_reference<T>,
			boost::mpl::not_<
				boost::is_const<
					typename boost::remove_reference<T>::type
				>
			>
		>
	{};
}	// namespace sprig

#endif	// #ifndef SPRIG_TYPE_TRAITS_IS_NON_CONST_REFERENCE_HPP
