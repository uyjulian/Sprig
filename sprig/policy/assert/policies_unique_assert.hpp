#ifndef SPRIG_POLICY_ASSERT_POLICIES_UNIQUE_ASSERT_HPP
#define SPRIG_POLICY_ASSERT_POLICIES_UNIQUE_ASSERT_HPP

#include <sprig/config/config.hpp>

#ifdef SPRIG_USING_PRAGMA_ONCE
#	pragma once
#endif	// #ifdef SPRIG_USING_PRAGMA_ONCE

#include <sprig/policy/assert/assert.hpp>
#include <sprig/policy/detail/policies_unique_check_impl.hpp>

//
// SPRIG_POLICYIES_UNIQUE_ASSERT
//
#define SPRIG_POLICYIES_UNIQUE_ASSERT(TAGS, TYPES) \
	SPRIG_POLICYIES_UNIQUE_CHECK_IMPL(TAGS, TYPES, SPRIG_POLICY_ASSERT)

#endif	// #ifndef SPRIG_POLICY_ASSERT_POLICIES_UNIQUE_ASSERT_HPP
