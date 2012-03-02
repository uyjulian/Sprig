#ifndef SPRIG_LENGTH_OF_HPP
#define SPRIG_LENGTH_OF_HPP

#include <sprig/config/config.hpp>

#ifdef SPRIG_USING_PRAGMA_ONCE
#	pragma once
#endif	// #ifdef SPRIG_USING_PRAGMA_ONCE

#include <cstddef>

namespace sprig {
	//
	// length_of
	//
	template<typename T, std::size_t N>
	SPRIG_INLINE std::size_t length_of(T (&)[N]) {
		return N;
	}
}	// namespace sprig

#endif	// #ifndef SPRIG_LENGTH_OF_HPP
