#ifndef SPRIG_KRKR_MACRO_NATIVE_HPP
#define SPRIG_KRKR_MACRO_NATIVE_HPP

#include <sprig/config/config.hpp>

#ifdef SPRIG_USING_PRAGMA_ONCE
#	pragma once
#endif	// #ifdef SPRIG_USING_PRAGMA_ONCE

#include <exception>
#include <sprig/external/tp_stub.hpp>
#include <sprig/krkr/tjs/typedef.hpp>
#include <sprig/krkr/tjs/exception.hpp>
#include <sprig/krkr/tjs/instance.hpp>
#include <sprig/krkr/macro/text.hpp>
#include <sprig/krkr/macro/check.hpp>
#include <sprig/krkr/macro/result.hpp>
#include <sprig/krkr/macro/arg.hpp>

//
// COMMENT: 例外を吉里吉里に通知する為のブロックマクロ
//
//
// SPRIG_KRKR_TRY
// SPRIG_KRKR_CATCH[_RETURN[_VOID]]
//
#define SPRIG_KRKR_TRY() \
	try
#define SPRIG_KRKR_CATCH(E) \
	catch (std::exception const& E)
#define SPRIG_KRKR_RETHROW_TJS_EXCEPTION(E) \
	{ \
		sprig::krkr::tjs::rethrow_exception_to_tjs_exception((E)); \
	}
#define SPRIG_KRKR_CATCH_RETURN(RET_VALUE) \
	SPRIG_KRKR_CATCH(e) { \
		SPRIG_KRKR_RETHROW_TJS_EXCEPTION(e); \
		return (RET_VALUE); \
	}
#define SPRIG_KRKR_CATCH_RETURN_VOID() \
	SPRIG_KRKR_CATCH(e) { \
		SPRIG_KRKR_RETHROW_TJS_EXCEPTION(e); \
		return; \
	}

//
// COMMENT: ネイティブメソッド定義用のブロックマクロ
//
//
// SPRIG_KRKR_BEGIN_NATIVE
// SPRIG_KRKR_END_NATIVE
//
#define SPRIG_KRKR_BEGIN_NATIVE() \
	SPRIG_KRKR_TRY() {
#define SPRIG_KRKR_END_NATIVE() \
	} SPRIG_KRKR_CATCH_RETURN(TJS_S_OK)

//
// COMMENT: ネイティブクラス定義用のブロックマクロ
//
//
// SPRIG_KRKR_BEGIN_CREATE_NATIVE_CLASS
// SPRIG_KRKR_END_CREATE_NATIVE_CLASS
//
#define SPRIG_KRKR_BEGIN_CREATE_NATIVE_CLASS(FUNCTION_NAME, CLASS_NAME, ENTRY_NAME) \
	static tjs_int32 TJS_NATIVE_CLASSID_NAME = -1; \
	iTJSDispatch2* FUNCTION_NAME() { \
		tTJSNativeClassForPlugin* classobj = ::TJSCreateNativeClassForPlugin( \
			SPRIG_KRKR_TJS_STRINGIZE(ENTRY_NAME), \
			sprig::krkr::tjs::create_tjs_native_instance<CLASS_NAME> \
			); \
		TJS_BEGIN_NATIVE_MEMBERS(ENTRY_NAME) \
		TJS_DECL_EMPTY_FINALIZE_METHOD \
		TJS_BEGIN_NATIVE_CONSTRUCTOR_DECL(this_, CLASS_NAME, ENTRY_NAME) \
		{ \
			return TJS_S_OK; \
		} \
		TJS_END_NATIVE_CONSTRUCTOR_DECL(ENTRY_NAME)
#define SPRIG_KRKR_END_CREATE_NATIVE_CLASS() \
		TJS_END_NATIVE_MEMBERS \
		return classobj; \
	}

//
// COMMENT: ネイティブメソッドやネイティブプロパティ定義用のブロックマクロ
//
//
// SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL
// SPRIG_KRKR_END_NATIVE_METHOD_DECL
//
#define SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(NAME) \
	TJS_BEGIN_NATIVE_METHOD_DECL(NAME) \
	{ \
		SPRIG_KRKR_BEGIN_NATIVE();
#define SPRIG_KRKR_END_NATIVE_METHOD_DECL(NAME) \
		SPRIG_KRKR_END_NATIVE(); \
	} \
	TJS_END_NATIVE_METHOD_DECL(NAME)

//
// SPRIG_KRKR_BEGIN_NATIVE_PROP_GETTER
// SPRIG_KRKR_END_NATIVE_PROP_GETTER
//
#define SPRIG_KRKR_BEGIN_NATIVE_PROP_GETTER() \
	TJS_BEGIN_NATIVE_PROP_GETTER \
	{ \
		SPRIG_KRKR_BEGIN_NATIVE();
#define SPRIG_KRKR_END_NATIVE_PROP_GETTER() \
		SPRIG_KRKR_END_NATIVE(); \
	} \
	TJS_END_NATIVE_PROP_GETTER

//
// SPRIG_KRKR_BEGIN_NATIVE_PROP_SETTER
// SPRIG_KRKR_END_NATIVE_PROP_SETTER
//
#define SPRIG_KRKR_BEGIN_NATIVE_PROP_SETTER() \
	TJS_BEGIN_NATIVE_PROP_SETTER \
	{ \
		SPRIG_KRKR_BEGIN_NATIVE();
#define SPRIG_KRKR_END_NATIVE_PROP_SETTER() \
		SPRIG_KRKR_END_NATIVE(); \
	} \
	TJS_END_NATIVE_PROP_SETTER

//
// COMMENT: 単純なネイティブメソッド定義のユーティリティ
//
//
// SPRIG_KRKR_NATIVE_METHOD_DECL_PARAM_VOID_RES_VOID
//	MANUAL: (VOID) VOID
//
#define SPRIG_KRKR_NATIVE_METHOD_DECL_PARAM_VOID_RES_VOID(CLASS_NAME, METHOD_NAME) \
	SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(METHOD_NAME) \
	{ \
		TJS_GET_NATIVE_INSTANCE(this_, CLASS_NAME); \
		this_->METHOD_NAME(); \
		return TJS_S_OK; \
	} \
	SPRIG_KRKR_END_NATIVE_METHOD_DECL(METHOD_NAME)

//
// SPRIG_KRKR_NATIVE_METHOD_DECL_[INVOKE]_PARAM_VOID_RES_VARIANT
//	MANUAL: (VOID) VARIANT
//
#define SPRIG_KRKR_NATIVE_METHOD_DECL_PARAM_VOID_RES_VARIANT(CLASS_NAME, METHOD_NAME) \
	SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(METHOD_NAME) \
	{ \
		TJS_GET_NATIVE_INSTANCE(this_, CLASS_NAME); \
		SPRIG_KRKR_RESULT_SET(this_->METHOD_NAME()); \
		return TJS_S_OK; \
	} \
	SPRIG_KRKR_END_NATIVE_METHOD_DECL(METHOD_NAME)
#define SPRIG_KRKR_NATIVE_METHOD_DECL_INVOKE_PARAM_VOID_RES_VARIANT(CLASS_NAME, METHOD_NAME) \
	SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(METHOD_NAME) \
	{ \
		TJS_GET_NATIVE_INSTANCE(this_, CLASS_NAME); \
		SPRIG_KRKR_INVOKE_RESULT_SET(this_->METHOD_NAME()); \
		return TJS_S_OK; \
	} \
	SPRIG_KRKR_END_NATIVE_METHOD_DECL(METHOD_NAME)

//
// SPRIG_KRKR_NATIVE_METHOD_DECL_PARAM_VARIANT_RES_VOID
//	MANUAL: (VARIANT) VOID
//
#define SPRIG_KRKR_NATIVE_METHOD_DECL_PARAM_VARIANT_RES_VOID(CLASS_NAME, METHOD_NAME) \
	SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(METHOD_NAME) \
	{ \
		TJS_GET_NATIVE_INSTANCE(this_, CLASS_NAME); \
		SPRIG_KRKR_NUMPARAMS_CHECK(1); \
		this_->METHOD_NAME(SPRIG_KRKR_ARG_VARIANT(0)); \
		return TJS_S_OK; \
	} \
	SPRIG_KRKR_END_NATIVE_METHOD_DECL(METHOD_NAME)

//
// SPRIG_KRKR_NATIVE_METHOD_DECL_PARAM_VARIANT_BOOL_RES_VOID
//	MANUAL: (VARIANT) VOID
//
#define SPRIG_KRKR_NATIVE_METHOD_DECL_PARAM_VARIANT_BOOL_RES_VOID(CLASS_NAME, METHOD_NAME) \
	SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(METHOD_NAME) \
	{ \
		TJS_GET_NATIVE_INSTANCE(this_, CLASS_NAME); \
		SPRIG_KRKR_NUMPARAMS_CHECK(1); \
		this_->METHOD_NAME(SPRIG_KRKR_ARG_BOOL(0)); \
		return TJS_S_OK; \
	} \
	SPRIG_KRKR_END_NATIVE_METHOD_DECL(METHOD_NAME)

//
// SPRIG_KRKR_NATIVE_METHOD_DECL_[INVOKE]_PARAM_VOID_RES_INTERMEDIATE
//	MANUAL: (VOID) INTERMEDIATE
//
#define SPRIG_KRKR_NATIVE_METHOD_DECL_PARAM_VOID_RES_INTERMEDIATE(CLASS_NAME, METHOD_NAME, VARIANT_TYPE, INTERMEDIATE_TYPE) \
	SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(METHOD_NAME) \
	{ \
		TJS_GET_NATIVE_INSTANCE(this_, CLASS_NAME); \
		SPRIG_KRKR_RESULT_SET(static_cast<VARIANT_TYPE>(static_cast<INTERMEDIATE_TYPE>(this_->METHOD_NAME()))); \
		return TJS_S_OK; \
	} \
	SPRIG_KRKR_END_NATIVE_METHOD_DECL(METHOD_NAME)
#define SPRIG_KRKR_NATIVE_METHOD_DECL_INVOKE_PARAM_VOID_RES_INTERMEDIATE(CLASS_NAME, METHOD_NAME, VARIANT_TYPE, INTERMEDIATE_TYPE) \
	SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(METHOD_NAME) \
	{ \
		TJS_GET_NATIVE_INSTANCE(this_, CLASS_NAME); \
		SPRIG_KRKR_INVOKE_RESULT_SET(static_cast<VARIANT_TYPE>(static_cast<INTERMEDIATE_TYPE>(this_->METHOD_NAME()))); \
		return TJS_S_OK; \
	} \
	SPRIG_KRKR_END_NATIVE_METHOD_DECL(METHOD_NAME)

//
// SPRIG_KRKR_NATIVE_METHOD_DECL_PARAM_INTERMEDIATE_RES_VOID
//	MANUAL: (INTERMEDIATE) VOID
//
#define SPRIG_KRKR_NATIVE_METHOD_DECL_PARAM_INTERMEDIATE_RES_VOID(CLASS_NAME, METHOD_NAME, VARIANT_TYPE, INTERMEDIATE_TYPE) \
	SPRIG_KRKR_BEGIN_NATIVE_METHOD_DECL(METHOD_NAME) \
	{ \
		TJS_GET_NATIVE_INSTANCE(this_, CLASS_NAME); \
		SPRIG_KRKR_NUMPARAMS_CHECK(1); \
		this_->METHOD_NAME(SPRIG_KRKR_ARG_INTERMEDIATE(0, VARIANT_TYPE, INTERMEDIATE_TYPE)); \
		return TJS_S_OK; \
	} \
	SPRIG_KRKR_END_NATIVE_METHOD_DECL(METHOD_NAME)

//
// SPRIG_KRKR_BEGIN_NATIVE_PROP_DECL
// SPRIG_KRKR_END_NATIVE_PROP_DECL
//
#define SPRIG_KRKR_BEGIN_NATIVE_PROP_DECL(PROP_NAME) \
	TJS_BEGIN_NATIVE_PROP_DECL(PROP_NAME)
#define SPRIG_KRKR_END_NATIVE_PROP_DECL(PROP_NAME) \
	TJS_END_NATIVE_PROP_DECL(PROP_NAME)

//
// COMMENT: ネイティブプロパティ定義用の基本マクロ（ACCESS指定可能）
// NOTE: ACCESSは例えば this_-> のようにgetter/setterの呼出方法を指定する。
//
//
// SPRIG_KRKR_NATIVE_PROP_BASIC_[GETTER|SETTER]_DECL_VARIANT
//
#define SPRIG_KRKR_NATIVE_PROP_BASIC_GETTER_VARIANT(CLASS_NAME, GETTER_NAME, ACCESS) \
	SPRIG_KRKR_BEGIN_NATIVE_PROP_GETTER() \
	{ \
		TJS_GET_NATIVE_INSTANCE(this_, CLASS_NAME); \
		SPRIG_KRKR_RESULT_SET(ACCESS GETTER_NAME()); \
		return TJS_S_OK; \
	} \
	SPRIG_KRKR_END_NATIVE_PROP_GETTER()
#define SPRIG_KRKR_NATIVE_PROP_BASIC_SETTER_VARIANT(CLASS_NAME, SETTER_NAME, ACCESS) \
	SPRIG_KRKR_BEGIN_NATIVE_PROP_SETTER() \
	{ \
		TJS_GET_NATIVE_INSTANCE(this_, CLASS_NAME); \
		ACCESS SETTER_NAME(*param); \
		return TJS_S_OK; \
	} \
	SPRIG_KRKR_END_NATIVE_PROP_SETTER()
//
// SPRIG_KRKR_NATIVE_PROP_BASIC_DECL_VARIANT_[GETONLY|SETONLY]
//
#define SPRIG_KRKR_NATIVE_PROP_BASIC_DECL_VARIANT(CLASS_NAME, PROP_NAME, GETTER_NAME, SETTER_NAME, ACCESS) \
	SPRIG_KRKR_BEGIN_NATIVE_PROP_DECL(PROP_NAME) \
	{ \
		SPRIG_KRKR_NATIVE_PROP_BASIC_GETTER_VARIANT(CLASS_NAME, GETTER_NAME, ACCESS); \
		SPRIG_KRKR_NATIVE_PROP_BASIC_SETTER_VARIANT(CLASS_NAME, SETTER_NAME, ACCESS); \
	} \
	SPRIG_KRKR_END_NATIVE_PROP_DECL(PROP_NAME)
#define SPRIG_KRKR_NATIVE_PROP_BASIC_DECL_VARIANT_GETONLY(CLASS_NAME, PROP_NAME, GETTER_NAME, ACCESS) \
	SPRIG_KRKR_BEGIN_NATIVE_PROP_DECL(PROP_NAME) \
	{ \
		SPRIG_KRKR_NATIVE_PROP_BASIC_GETTER_VARIANT(CLASS_NAME, GETTER_NAME, ACCESS); \
		TJS_DENY_NATIVE_PROP_SETTER; \
	} \
	SPRIG_KRKR_END_NATIVE_PROP_DECL(PROP_NAME)
#define SPRIG_KRKR_NATIVE_PROP_BASIC_DECL_VARIANT_SETONLY(CLASS_NAME, PROP_NAME, SETTER_NAME, ACCESS) \
	SPRIG_KRKR_BEGIN_NATIVE_PROP_DECL(PROP_NAME) \
	{ \
		TJS_DENY_NATIVE_PROP_GETTER; \
		SPRIG_KRKR_NATIVE_PROP_BASIC_SETTER_VARIANT(CLASS_NAME, SETTER_NAME, ACCESS); \
	} \
	SPRIG_KRKR_END_NATIVE_PROP_DECL(PROP_NAME)

//
// SPRIG_KRKR_NATIVE_PROP_BASIC_[GETTER|SETTER]_DECL_INTERMEDIATE
//
#define SPRIG_KRKR_NATIVE_PROP_BASIC_GETTER_INTERMEDIATE(CLASS_NAME, GETTER_NAME, VARIANT_TYPE, INTERMEDIATE_TYPE, ACCESS) \
	SPRIG_KRKR_BEGIN_NATIVE_PROP_GETTER() \
	{ \
		TJS_GET_NATIVE_INSTANCE(this_, CLASS_NAME); \
		SPRIG_KRKR_RESULT_SET(static_cast<VARIANT_TYPE>(static_cast<INTERMEDIATE_TYPE>(ACCESS GETTER_NAME()))); \
		return TJS_S_OK; \
	} \
	SPRIG_KRKR_END_NATIVE_PROP_GETTER()
#define SPRIG_KRKR_NATIVE_PROP_BASIC_SETTER_INTERMEDIATE(CLASS_NAME, SETTER_NAME, VARIANT_TYPE, INTERMEDIATE_TYPE, ACCESS) \
	SPRIG_KRKR_BEGIN_NATIVE_PROP_SETTER() \
	{ \
		TJS_GET_NATIVE_INSTANCE(this_, CLASS_NAME); \
		ACCESS SETTER_NAME(static_cast<INTERMEDIATE_TYPE>(static_cast<VARIANT_TYPE>(*param))); \
		return TJS_S_OK; \
	} \
	SPRIG_KRKR_END_NATIVE_PROP_SETTER()
//
// SPRIG_KRKR_NATIVE_PROP_BASIC_DECL_INTERMEDIATE_[GETONLY|SETONLY]
//
#define SPRIG_KRKR_NATIVE_PROP_BASIC_DECL_INTERMEDIATE(CLASS_NAME, PROP_NAME, GETTER_NAME, SETTER_NAME, VARIANT_TYPE, INTERMEDIATE_TYPE, ACCESS) \
	SPRIG_KRKR_BEGIN_NATIVE_PROP_DECL(PROP_NAME) \
	{ \
		SPRIG_KRKR_NATIVE_PROP_BASIC_GETTER_INTERMEDIATE(CLASS_NAME, GETTER_NAME, VARIANT_TYPE, INTERMEDIATE_TYPE, ACCESS); \
		SPRIG_KRKR_NATIVE_PROP_BASIC_SETTER_INTERMEDIATE(CLASS_NAME, SETTER_NAME, VARIANT_TYPE, INTERMEDIATE_TYPE, ACCESS); \
	} \
	SPRIG_KRKR_END_NATIVE_PROP_DECL(PROP_NAME)
#define SPRIG_KRKR_NATIVE_PROP_BASIC_DECL_INTERMEDIATE_GETONLY(CLASS_NAME, PROP_NAME, GETTER_NAME, VARIANT_TYPE, INTERMEDIATE_TYPE, ACCESS) \
	SPRIG_KRKR_BEGIN_NATIVE_PROP_DECL(PROP_NAME) \
	{ \
		SPRIG_KRKR_NATIVE_PROP_BASIC_GETTER_INTERMEDIATE(CLASS_NAME, GETTER_NAME, VARIANT_TYPE, INTERMEDIATE_TYPE, ACCESS); \
		TJS_DENY_NATIVE_PROP_SETTER; \
	} \
	SPRIG_KRKR_END_NATIVE_PROP_DECL(PROP_NAME)
#define SPRIG_KRKR_NATIVE_PROP_BASIC_DECL_INTERMEDIATE_SETONLY(CLASS_NAME, PROP_NAME, SETTER_NAME, VARIANT_TYPE, INTERMEDIATE_TYPE, ACCESS) \
	SPRIG_KRKR_BEGIN_NATIVE_PROP_DECL(PROP_NAME) \
	{ \
		TJS_DENY_NATIVE_PROP_GETTER; \
		SPRIG_KRKR_NATIVE_PROP_BASIC_SETTER_INTERMEDIATE(CLASS_NAME, SETTER_NAME, VARIANT_TYPE, INTERMEDIATE_TYPE, ACCESS); \
	} \
	SPRIG_KRKR_END_NATIVE_PROP_DECL(PROP_NAME)

//
// SPRIG_KRKR_NATIVE_PROP_BASIC_[GETTER|SETTER]_DECL_BOOL
//
#define SPRIG_KRKR_NATIVE_PROP_BASIC_GETTER_BOOL(CLASS_NAME, GETTER_NAME, ACCESS) \
	SPRIG_KRKR_BEGIN_NATIVE_PROP_GETTER() \
	{ \
		TJS_GET_NATIVE_INSTANCE(this_, CLASS_NAME); \
		SPRIG_KRKR_RESULT_SET(static_cast<tjs_int>(ACCESS GETTER_NAME())); \
		return TJS_S_OK; \
	} \
	SPRIG_KRKR_END_NATIVE_PROP_GETTER()
#define SPRIG_KRKR_NATIVE_PROP_BASIC_SETTER_BOOL(CLASS_NAME, SETTER_NAME, ACCESS) \
	SPRIG_KRKR_BEGIN_NATIVE_PROP_SETTER() \
	{ \
		TJS_GET_NATIVE_INSTANCE(this_, CLASS_NAME); \
		ACCESS SETTER_NAME(static_cast<tjs_int>(*param) != 0); \
		return TJS_S_OK; \
	} \
	SPRIG_KRKR_END_NATIVE_PROP_SETTER()
//
// SPRIG_KRKR_NATIVE_PROP_BASIC_DECL_BOOL_[GETONLY|SETONLY]
//
#define SPRIG_KRKR_NATIVE_PROP_BASIC_DECL_BOOL(CLASS_NAME, PROP_NAME, GETTER_NAME, SETTER_NAME, ACCESS) \
	SPRIG_KRKR_BEGIN_NATIVE_PROP_DECL(PROP_NAME) \
	{ \
		SPRIG_KRKR_NATIVE_PROP_BASIC_GETTER_BOOL(CLASS_NAME, GETTER_NAME, ACCESS); \
		SPRIG_KRKR_NATIVE_PROP_BASIC_SETTER_BOOL(CLASS_NAME, SETTER_NAME, ACCESS); \
	} \
	SPRIG_KRKR_END_NATIVE_PROP_DECL(PROP_NAME)
#define SPRIG_KRKR_NATIVE_PROP_BASIC_DECL_BOOL_GETONLY(CLASS_NAME, PROP_NAME, GETTER_NAME, ACCESS) \
	SPRIG_KRKR_BEGIN_NATIVE_PROP_DECL(PROP_NAME) \
	{ \
		SPRIG_KRKR_NATIVE_PROP_BASIC_GETTER_BOOL(CLASS_NAME, GETTER_NAME, ACCESS); \
		TJS_DENY_NATIVE_PROP_SETTER; \
	} \
	SPRIG_KRKR_END_NATIVE_PROP_DECL(PROP_NAME)
#define SPRIG_KRKR_NATIVE_PROP_BASIC_DECL_BOOL_SETONLY(CLASS_NAME, PROP_NAME, SETTER_NAME, ACCESS) \
	SPRIG_KRKR_BEGIN_NATIVE_PROP_DECL(PROP_NAME) \
	{ \
		TJS_DENY_NATIVE_PROP_GETTER; \
		SPRIG_KRKR_NATIVE_PROP_BASIC_SETTER_BOOL(CLASS_NAME, SETTER_NAME, ACCESS); \
	} \
	SPRIG_KRKR_END_NATIVE_PROP_DECL(PROP_NAME)

//
// SPRIG_KRKR_NATIVE_PROP_BASIC_[GETTER|SETTER]_DECL_TJSCLASS
//
#define SPRIG_KRKR_NATIVE_PROP_BASIC_GETTER_TJSCLASS(CLASS_NAME, GETTER_NAME, ACCESS) \
	SPRIG_KRKR_BEGIN_NATIVE_PROP_GETTER() \
	{ \
		TJS_GET_NATIVE_INSTANCE(this_, CLASS_NAME); \
		sprig::krkr::tjs::object_type obj = ACCESS GETTER_NAME(); \
		*result = tTJSVariant(obj.get(), obj.get()); \
		return TJS_S_OK; \
	} \
	SPRIG_KRKR_END_NATIVE_PROP_GETTER()
#define SPRIG_KRKR_NATIVE_PROP_BASIC_SETTER_TJSCLASS(CLASS_NAME, SETTER_NAME, ACCESS) \
	SPRIG_KRKR_BEGIN_NATIVE_PROP_SETTER() \
	{ \
		TJS_GET_NATIVE_INSTANCE(this_, CLASS_NAME); \
		ACCESS SETTER_NAME(param); \
		return TJS_S_OK; \
	} \
	SPRIG_KRKR_END_NATIVE_PROP_SETTER()
//
// SPRIG_KRKR_NATIVE_PROP_BASIC_DECL_TJSCLASS_[GETONLY|SETONLY]
//
#define SPRIG_KRKR_NATIVE_PROP_BASIC_DECL_TJSCLASS(CLASS_NAME, PROP_NAME, GETTER_NAME, SETTER_NAME, ACCESS) \
	SPRIG_KRKR_BEGIN_NATIVE_PROP_DECL(PROP_NAME) \
	{ \
		SPRIG_KRKR_NATIVE_PROP_BASIC_GETTER_TJSCLASS(CLASS_NAME, GETTER_NAME, ACCESS); \
		SPRIG_KRKR_NATIVE_PROP_BASIC_SETTER_TJSCLASS(CLASS_NAME, SETTER_NAME, ACCESS); \
	} \
	SPRIG_KRKR_END_NATIVE_PROP_DECL(PROP_NAME)
#define SPRIG_KRKR_NATIVE_PROP_BASIC_DECL_TJSCLASS_GETONLY(CLASS_NAME, PROP_NAME, GETTER_NAME, ACCESS) \
	SPRIG_KRKR_BEGIN_NATIVE_PROP_DECL(PROP_NAME) \
	{ \
		SPRIG_KRKR_NATIVE_PROP_BASIC_GETTER_TJSCLASS(CLASS_NAME, GETTER_NAME, ACCESS); \
		TJS_DENY_NATIVE_PROP_SETTER; \
	} \
	SPRIG_KRKR_END_NATIVE_PROP_DECL(PROP_NAME)
#define SPRIG_KRKR_NATIVE_PROP_BASIC_DECL_TJSCLASS_SETONLY(CLASS_NAME, PROP_NAME, SETTER_NAME, ACCESS) \
	SPRIG_KRKR_BEGIN_NATIVE_PROP_DECL(PROP_NAME) \
	{ \
		TJS_DENY_NATIVE_PROP_GETTER; \
		SPRIG_KRKR_NATIVE_PROP_BASIC_SETTER_TJSCLASS(CLASS_NAME, SETTER_NAME, ACCESS); \
	} \
	SPRIG_KRKR_END_NATIVE_PROP_DECL(PROP_NAME)

//
// COMMENT: ネイティブプロパティ定義用マクロ（ネイティブインスタンスのメンバに直接アクセスする）
//
//
// SPRIG_KRKR_NATIVE_PROP_DECL_VARIANT
//
#define SPRIG_KRKR_NATIVE_PROP_GETTER_VARIANT(CLASS_NAME, GETTER_NAME) \
	SPRIG_KRKR_NATIVE_PROP_BASIC_GETTER_VARIANT(CLASS_NAME, GETTER_NAME, this_->)
#define SPRIG_KRKR_NATIVE_PROP_SETTER_VARIANT(CLASS_NAME, SETTER_NAME) \
	SPRIG_KRKR_NATIVE_PROP_BASIC_SETTER_VARIANT(CLASS_NAME, SETTER_NAME, this_->)
#define SPRIG_KRKR_NATIVE_PROP_DECL_VARIANT(CLASS_NAME, PROP_NAME, GETTER_NAME, SETTER_NAME) \
	SPRIG_KRKR_NATIVE_PROP_BASIC_DECL_VARIANT(CLASS_NAME, PROP_NAME, GETTER_NAME, SETTER_NAME, this_->)
#define SPRIG_KRKR_NATIVE_PROP_DECL_VARIANT_GETONLY(CLASS_NAME, PROP_NAME, GETTER_NAME) \
	SPRIG_KRKR_NATIVE_PROP_BASIC_DECL_VARIANT_GETONLY(CLASS_NAME, PROP_NAME, GETTER_NAME, this_->)
#define SPRIG_KRKR_NATIVE_PROP_DECL_VARIANT_SETONLY(CLASS_NAME, PROP_NAME, SETTER_NAME) \
	SPRIG_KRKR_NATIVE_PROP_BASIC_DECL_VARIANT_SETONLY(CLASS_NAME, PROP_NAME, SETTER_NAME, this_->)
//
// SPRIG_KRKR_NATIVE_PROP_DECL_INTERMEDIATE
//
#define SPRIG_KRKR_NATIVE_PROP_GETTER_INTERMEDIATE(CLASS_NAME, GETTER_NAME, VARIANT_TYPE, INTERMEDIATE_TYPE) \
	SPRIG_KRKR_NATIVE_PROP_BASIC_GETTER_INTERMEDIATE(CLASS_NAME, GETTER_NAME, VARIANT_TYPE, INTERMEDIATE_TYPE, this_->)
#define SPRIG_KRKR_NATIVE_PROP_SETTER_INTERMEDIATE(CLASS_NAME, SETTER_NAME, VARIANT_TYPE, INTERMEDIATE_TYPE) \
	SPRIG_KRKR_NATIVE_PROP_BASIC_SETTER_INTERMEDIATE(CLASS_NAME, SETTER_NAME, VARIANT_TYPE, INTERMEDIATE_TYPE, this_->)
#define SPRIG_KRKR_NATIVE_PROP_DECL_INTERMEDIATE(CLASS_NAME, PROP_NAME, GETTER_NAME, SETTER_NAME, VARIANT_TYPE, INTERMEDIATE_TYPE) \
	SPRIG_KRKR_NATIVE_PROP_BASIC_DECL_INTERMEDIATE(CLASS_NAME, PROP_NAME, GETTER_NAME, SETTER_NAME, VARIANT_TYPE, INTERMEDIATE_TYPE, this_->)
#define SPRIG_KRKR_NATIVE_PROP_DECL_INTERMEDIATE_GETONLY(CLASS_NAME, PROP_NAME, GETTER_NAME, VARIANT_TYPE, INTERMEDIATE_TYPE) \
	SPRIG_KRKR_NATIVE_PROP_BASIC_DECL_INTERMEDIATE_GETONLY(CLASS_NAME, PROP_NAME, GETTER_NAME, VARIANT_TYPE, INTERMEDIATE_TYPE, this_->)
#define SPRIG_KRKR_NATIVE_PROP_DECL_INTERMEDIATE_SETONLY(CLASS_NAME, PROP_NAME, SETTER_NAME, VARIANT_TYPE, INTERMEDIATE_TYPE) \
	SPRIG_KRKR_NATIVE_PROP_BASIC_DECL_INTERMEDIATE_SETONLY(CLASS_NAME, PROP_NAME, SETTER_NAME, VARIANT_TYPE, INTERMEDIATE_TYPE, this_->)
//
// SPRIG_KRKR_NATIVE_PROP_DECL_BOOL
//
#define SPRIG_KRKR_NATIVE_PROP_GETTER_BOOL(CLASS_NAME, GETTER_NAME) \
	SPRIG_KRKR_NATIVE_PROP_BASIC_GETTER_BOOL(CLASS_NAME, GETTER_NAME, this_->)
#define SPRIG_KRKR_NATIVE_PROP_SETTER_BOOL(CLASS_NAME, SETTER_NAME) \
	SPRIG_KRKR_NATIVE_PROP_BASIC_SETTER_BOOL(CLASS_NAME, SETTER_NAME, this_->)
#define SPRIG_KRKR_NATIVE_PROP_DECL_BOOL(CLASS_NAME, PROP_NAME, GETTER_NAME, SETTER_NAME) \
	SPRIG_KRKR_NATIVE_PROP_BASIC_DECL_BOOL(CLASS_NAME, PROP_NAME, GETTER_NAME, SETTER_NAME, this_->)
#define SPRIG_KRKR_NATIVE_PROP_DECL_BOOL_GETONLY(CLASS_NAME, PROP_NAME, GETTER_NAME) \
	SPRIG_KRKR_NATIVE_PROP_BASIC_DECL_BOOL_GETONLY(CLASS_NAME, PROP_NAME, GETTER_NAME, this_->)
#define SPRIG_KRKR_NATIVE_PROP_DECL_BOOL_SETONLY(CLASS_NAME, PROP_NAME, SETTER_NAME) \
	SPRIG_KRKR_NATIVE_PROP_BASIC_DECL_BOOL_SETONLY(CLASS_NAME, PROP_NAME, SETTER_NAME, this_->)
//
// SPRIG_KRKR_NATIVE_PROP_DECL_TJSCLASS
//
#define SPRIG_KRKR_NATIVE_PROP_GETTER_TJSCLASS(CLASS_NAME, GETTER_NAME) \
	SPRIG_KRKR_NATIVE_PROP_BASIC_GETTER_TJSCLASS(CLASS_NAME, GETTER_NAME, this_->)
#define SPRIG_KRKR_NATIVE_PROP_SETTER_TJSCLASS(CLASS_NAME, SETTER_NAME) \
	SPRIG_KRKR_NATIVE_PROP_BASIC_SETTER_TJSCLASS(CLASS_NAME, SETTER_NAME, this_->)
#define SPRIG_KRKR_NATIVE_PROP_DECL_TJSCLASS(CLASS_NAME, PROP_NAME, GETTER_NAME, SETTER_NAME) \
	SPRIG_KRKR_NATIVE_PROP_BASIC_DECL_TJSCLASS(CLASS_NAME, PROP_NAME, GETTER_NAME, SETTER_NAME, this_->)
#define SPRIG_KRKR_NATIVE_PROP_DECL_TJSCLASS_GETONLY(CLASS_NAME, PROP_NAME, GETTER_NAME) \
	SPRIG_KRKR_NATIVE_PROP_BASIC_DECL_TJSCLASS_GETONLY(CLASS_NAME, PROP_NAME, GETTER_NAME, this_->)
#define SPRIG_KRKR_NATIVE_PROP_DECL_TJSCLASS_SETONLY(CLASS_NAME, PROP_NAME, SETTER_NAME) \
	SPRIG_KRKR_NATIVE_PROP_BASIC_DECL_TJSCLASS_SETONLY(CLASS_NAME, PROP_NAME, SETTER_NAME, this_->)

//
// COMMENT: ネイティブプロパティ定義用マクロ（静的メソッド用）
//
//
// SPRIG_KRKR_NATIVE_STATIC_PROP_BASIC_[GETTER|SETTER]_DECL_VARIANT
//
#define SPRIG_KRKR_NATIVE_STATIC_PROP_BASIC_GETTER_DECL_VARIANT(CLASS_NAME, PROP_NAME, GETTER_NAME) \
	SPRIG_KRKR_BEGIN_NATIVE_PROP_GETTER() \
	{ \
		SPRIG_KRKR_RESULT_SET(CLASS_NAME::GETTER_NAME()); \
		return TJS_S_OK; \
	} \
	SPRIG_KRKR_END_NATIVE_PROP_GETTER()
#define SPRIG_KRKR_NATIVE_STATIC_PROP_BASIC_SETTER_DECL_VARIANT(CLASS_NAME, PROP_NAME, SETTER_NAME) \
	SPRIG_KRKR_BEGIN_NATIVE_PROP_SETTER() \
	{ \
		CLASS_NAME::SETTER_NAME(*param); \
		return TJS_S_OK; \
	} \
	SPRIG_KRKR_END_NATIVE_PROP_SETTER()
//
// SPRIG_KRKR_NATIVE_STATIC_PROP_DECL_VARIANT_[GETONLY]
//
#define SPRIG_KRKR_NATIVE_STATIC_PROP_DECL_VARIANT(CLASS_NAME, PROP_NAME, GETTER_NAME, SETTER_NAME) \
	SPRIG_KRKR_BEGIN_NATIVE_PROP_DECL(PROP_NAME) \
	{ \
		SPRIG_KRKR_NATIVE_STATIC_PROP_BASIC_GETTER_DECL_VARIANT(CLASS_NAME, PROP_NAME, GETTER_NAME); \
		SPRIG_KRKR_NATIVE_STATIC_PROP_BASIC_SETTER_DECL_VARIANT(CLASS_NAME, PROP_NAME, SETTER_NAME); \
	} \
	SPRIG_KRKR_END_NATIVE_PROP_DECL(PROP_NAME)
#define SPRIG_KRKR_NATIVE_STATIC_PROP_DECL_VARIANT_GETONLY(CLASS_NAME, PROP_NAME, GETTER_NAME) \
	SPRIG_KRKR_BEGIN_NATIVE_PROP_DECL(PROP_NAME) \
	{ \
		SPRIG_KRKR_NATIVE_STATIC_PROP_BASIC_GETTER_DECL_VARIANT(CLASS_NAME, PROP_NAME, GETTER_NAME); \
		TJS_DENY_NATIVE_PROP_SETTER; \
	} \
	SPRIG_KRKR_END_NATIVE_PROP_DECL(PROP_NAME)

//
// COMMENT: ネイティブプロパティ定義用マクロ（定数用）
//
//
// SPRIG_KRKR_NATIVE_CONSTANT_PROP_DECL
//
#define SPRIG_KRKR_NATIVE_CONSTANT_PROP_DECL(CONSTANT_NAME, CONSTANT_VALUE) \
	SPRIG_KRKR_BEGIN_NATIVE_PROP_DECL(CONSTANT_NAME) \
	{ \
		SPRIG_KRKR_BEGIN_NATIVE_PROP_GETTER() \
		{ \
			SPRIG_KRKR_RESULT_SET(CONSTANT_VALUE); \
			return TJS_S_OK; \
		} \
		SPRIG_KRKR_END_NATIVE_PROP_GETTER(); \
		TJS_DENY_NATIVE_PROP_SETTER; \
	} \
	SPRIG_KRKR_END_NATIVE_PROP_DECL(CONSTANT_NAME)

#endif	// #ifndef SPRIG_KRKR_MACRO_NATIVE_HPP
