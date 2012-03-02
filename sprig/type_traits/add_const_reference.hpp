#ifndef SPRIG_TYPE_TRAITS_ADD_CONST_REFERENCE_HPP
#define SPRIG_TYPE_TRAITS_ADD_CONST_REFERENCE_HPP

#include <sprig/config/config.hpp>

#ifdef SPRIG_USING_PRAGMA_ONCE
#	pragma once
#endif	// #ifdef SPRIG_USING_PRAGMA_ONCE

#include <boost/type_traits/add_const.hpp>
#include <boost/type_traits/add_reference.hpp>
#include <boost/type_traits/remove_reference.hpp>

namespace sprig {
	//
	// add_const_reference
	//
	template<typename T>
	struct add_const_reference
		: public boost::add_reference<
			typename boost::add_const<
				typename boost::remove_reference<T>::type
			>::type
		>
	{};
}	// namespace sprig

#endif	// #ifndef SPRIG_TYPE_TRAITS_ADD_CONST_REFERENCE_HPP
