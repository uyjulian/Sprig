#ifndef SPRIG_POLICY_ASSERT_POLICY_EXIST_ASSERT_HPP
#define SPRIG_POLICY_ASSERT_POLICY_EXIST_ASSERT_HPP

#include <sprig/config/config.hpp>

#ifdef SPRIG_USING_PRAGMA_ONCE
#	pragma once
#endif	// #ifdef SPRIG_USING_PRAGMA_ONCE

#include <sprig/policy/assert/assert.hpp>
#include <sprig/policy/detail/policy_exist_check_impl.hpp>

//
// SPRIG_POLICY_EXIST_ASSERT
//
#define SPRIG_POLICY_EXIST_ASSERT(TAG, TYPES) \
	SPRIG_POLICY_EXIST_CHECK_IMPL(TAG, TYPES, SPRIG_POLICY_ASSERT)

#endif	// #ifndef SPRIG_POLICY_ASSERT_POLICY_EXIST_ASSERT_HPP
