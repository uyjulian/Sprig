#ifndef SPRIG_CONFIG_LIBINFO_BZIP2_HPP
#define SPRIG_CONFIG_LIBINFO_BZIP2_HPP

#include <sprig/config/pragma_once.hpp>

#ifdef SPRIG_USING_PRAGMA_ONCE
#	pragma once
#endif	// #ifdef SPRIG_USING_PRAGMA_ONCE

#if defined(SPRIG_CONFIG_LIBINFO_MESSAGE) || defined(SPRIG_CONFIG_LIBINFO_MESSAGE_BZIP2)

#	include <sprig/config/pragma_message.hpp>
#	ifdef SPRIG_HAS_PRAGMA_MESSAGE

#		include <boost/preprocessor/stringize.hpp>
#		include <bzlib_private.h>

#		pragma message("sprig/config/libinfo/bzip2.hpp")
#		pragma message("    BZ_VERSION  = " BOOST_PP_STRINGIZE(BZ_VERSION))

#	endif	// #ifdef SPRIG_HAS_PRAGMA_MESSAGE

#endif	// #if defined(SPRIG_CONFIG_LIBINFO_MESSAGE) || defined(SPRIG_CONFIG_LIBINFO_MESSAGE_BZIP2)

#endif	// #ifndef SPRIG_CONFIG_LIBINFO_BZIP2_HPP
