#ifndef SPRIG_WAVE_COMPILER_VISUALC_HPP
#define SPRIG_WAVE_COMPILER_VISUALC_HPP

#include <sprig/config/config.hpp>

#ifdef SPRIG_USING_PRAGMA_ONCE
#	pragma once
#endif	// #ifdef SPRIG_USING_PRAGMA_ONCE

#include <sprig/wave/config.hpp>

#ifdef SPRIG_WAVE_VISUALC

	//
	// SPRIG_WAVE_MACROS_[N]
	//
#	define SPRIG_WAVE_MACROS_0(OPT) SPRIG_WAVE_MACROS_SEP(OPT, "-")

#	ifdef NDEBUG
#		define SPRIG_WAVE_MACROS_1(OPT) SPRIG_WAVE_MACROS_DEF(OPT, NDEBUG)
#	else
#		define SPRIG_WAVE_MACROS_1(OPT) SPRIG_WAVE_MACROS_NDEF(OPT, NDEBUG)
#	endif
#	ifdef _DEBUG
#		define SPRIG_WAVE_MACROS_2(OPT) SPRIG_WAVE_MACROS_DEF(OPT, _DEBUG)
#	else
#		define SPRIG_WAVE_MACROS_2(OPT) SPRIG_WAVE_MACROS_NDEF(OPT, _DEBUG)
#	endif
#	define SPRIG_WAVE_MACROS_3(OPT) SPRIG_WAVE_MACROS_REM(OPT, "デバッグ版かリリース版か")

#	define SPRIG_WAVE_MACROS_4(OPT) SPRIG_WAVE_MACROS_SEP(OPT, "-")

#	ifdef WIN32
#		define SPRIG_WAVE_MACROS_5(OPT) SPRIG_WAVE_MACROS_DEF(OPT, WIN32)
#	else
#		define SPRIG_WAVE_MACROS_5(OPT) SPRIG_WAVE_MACROS_NDEF(OPT, WIN32)
#	endif
#	ifdef _WIN32
#		define SPRIG_WAVE_MACROS_6(OPT) SPRIG_WAVE_MACROS_DEF(OPT, _WIN32)
#	else
#		define SPRIG_WAVE_MACROS_6(OPT) SPRIG_WAVE_MACROS_NDEF(OPT, _WIN32)
#	endif
#	ifdef __WIN32__
#		define SPRIG_WAVE_MACROS_7(OPT) SPRIG_WAVE_MACROS_DEF(OPT, __WIN32__)
#	else
#		define SPRIG_WAVE_MACROS_7(OPT) SPRIG_WAVE_MACROS_NDEF(OPT, __WIN32__)
#	endif
#	define SPRIG_WAVE_MACROS_8(OPT) SPRIG_WAVE_MACROS_REM(OPT, "Win32")

#	define SPRIG_WAVE_MACROS_9(OPT) SPRIG_WAVE_MACROS_SEP(OPT, "-")

#	ifdef WIN64
#		define SPRIG_WAVE_MACROS_10(OPT) SPRIG_WAVE_MACROS_DEF(OPT, WIN64)
#	else
#		define SPRIG_WAVE_MACROS_10(OPT) SPRIG_WAVE_MACROS_NDEF(OPT, WIN64)
#	endif
#	ifdef _WIN64
#		define SPRIG_WAVE_MACROS_11(OPT) SPRIG_WAVE_MACROS_DEF(OPT, _WIN64)
#	else
#		define SPRIG_WAVE_MACROS_11(OPT) SPRIG_WAVE_MACROS_NDEF(OPT, _WIN64)
#	endif
#	ifdef __WIN64__
#		define SPRIG_WAVE_MACROS_12(OPT) SPRIG_WAVE_MACROS_DEF(OPT, __WIN64__)
#	else
#		define SPRIG_WAVE_MACROS_12(OPT) SPRIG_WAVE_MACROS_NDEF(OPT, __WIN64__)
#	endif
#	define SPRIG_WAVE_MACROS_13(OPT) SPRIG_WAVE_MACROS_REM(OPT, "Win64")

#	define SPRIG_WAVE_MACROS_14(OPT) SPRIG_WAVE_MACROS_SEP(OPT, "-")

#	ifdef _MBCS
#		define SPRIG_WAVE_MACROS_15(OPT) SPRIG_WAVE_MACROS_DEF(OPT, _MBCS)
#	else
#		define SPRIG_WAVE_MACROS_15(OPT) SPRIG_WAVE_MACROS_NDEF(OPT, _MBCS)
#	endif
#	ifdef _UNICODE
#		define SPRIG_WAVE_MACROS_16(OPT) SPRIG_WAVE_MACROS_DEF(OPT, _UNICODE)
#	else
#		define SPRIG_WAVE_MACROS_16(OPT) SPRIG_WAVE_MACROS_NDEF(OPT, _UNICODE)
#	endif
#	ifdef UNICODE
#		define SPRIG_WAVE_MACROS_17(OPT) SPRIG_WAVE_MACROS_DEF(OPT, UNICODE)
#	else
#		define SPRIG_WAVE_MACROS_17(OPT) SPRIG_WAVE_MACROS_NDEF(OPT, UNICODE)
#	endif
#	define SPRIG_WAVE_MACROS_18(OPT) SPRIG_WAVE_MACROS_REM(OPT, "ジェネリックテキストマッピング")

#	define SPRIG_WAVE_MACROS_19(OPT) SPRIG_WAVE_MACROS_SEP(OPT, "-")

#	ifdef _WINDOWS
#		define SPRIG_WAVE_MACROS_20(OPT) SPRIG_WAVE_MACROS_DEF(OPT, _WINDOWS)
#	else
#		define SPRIG_WAVE_MACROS_20(OPT) SPRIG_WAVE_MACROS_NDEF(OPT, _WINDOWS)
#	endif
#	ifdef _CONSOLE
#		define SPRIG_WAVE_MACROS_21(OPT) SPRIG_WAVE_MACROS_DEF(OPT, _CONSOLE)
#	else
#		define SPRIG_WAVE_MACROS_21(OPT) SPRIG_WAVE_MACROS_NDEF(OPT, _CONSOLE)
#	endif
#	ifdef _USRDLL
#		define SPRIG_WAVE_MACROS_22(OPT) SPRIG_WAVE_MACROS_DEF(OPT, _USRDLL)
#	else
#		define SPRIG_WAVE_MACROS_22(OPT) SPRIG_WAVE_MACROS_NDEF(OPT, _USRDLL)
#	endif
#	ifdef _LIB
#		define SPRIG_WAVE_MACROS_23(OPT) SPRIG_WAVE_MACROS_DEF(OPT, _LIB)
#	else
#		define SPRIG_WAVE_MACROS_23(OPT) SPRIG_WAVE_MACROS_NDEF(OPT, _LIB)
#	endif
#	define SPRIG_WAVE_MACROS_24(OPT) SPRIG_WAVE_MACROS_REM(OPT, "ビルド対象")

#	define SPRIG_WAVE_MACROS_25(OPT) SPRIG_WAVE_MACROS_SEP(OPT, "-")

#	ifdef _NATIVE_WCHAR_T_DEFINED
#		define SPRIG_WAVE_MACROS_26(OPT) SPRIG_WAVE_MACROS_DEF(OPT, _NATIVE_WCHAR_T_DEFINED)
#	else
#		define SPRIG_WAVE_MACROS_26(OPT) SPRIG_WAVE_MACROS_NDEF(OPT, _NATIVE_WCHAR_T_DEFINED)
#	endif
#	ifdef _WCHAR_T_DEFINED
#		define SPRIG_WAVE_MACROS_27(OPT) SPRIG_WAVE_MACROS_DEF(OPT, _WCHAR_T_DEFINED)
#	else
#		define SPRIG_WAVE_MACROS_27(OPT) SPRIG_WAVE_MACROS_NDEF(OPT, _WCHAR_T_DEFINED)
#	endif
#	define SPRIG_WAVE_MACROS_28(OPT) SPRIG_WAVE_MACROS_REM(OPT, "wchar_t が組み込み型であるか")

#	define SPRIG_WAVE_MACROS_29(OPT) SPRIG_WAVE_MACROS_SEP(OPT, "-")

#	ifdef _CHAR_UNSIGNED
#		define SPRIG_WAVE_MACROS_30(OPT) SPRIG_WAVE_MACROS_DEF(OPT, _CHAR_UNSIGNED)
#	else
#		define SPRIG_WAVE_MACROS_30(OPT) SPRIG_WAVE_MACROS_NDEF(OPT, _CHAR_UNSIGNED)
#	endif
#	define SPRIG_WAVE_MACROS_31(OPT) SPRIG_WAVE_MACROS_REM(OPT, "char が符号無し型であるか")

#	define SPRIG_WAVE_MACROS_32(OPT) SPRIG_WAVE_MACROS_SEP(OPT, "-")

#	ifdef _CPPRTTI
#		define SPRIG_WAVE_MACROS_33(OPT) SPRIG_WAVE_MACROS_DEF(OPT, _CPPRTTI)
#	else
#		define SPRIG_WAVE_MACROS_33(OPT) SPRIG_WAVE_MACROS_NDEF(OPT, _CPPRTTI)
#	endif
#	ifdef _CPPUNWIND
#		define SPRIG_WAVE_MACROS_34(OPT) SPRIG_WAVE_MACROS_DEF(OPT, _CPPUNWIND)
#	else
#		define SPRIG_WAVE_MACROS_34(OPT) SPRIG_WAVE_MACROS_NDEF(OPT, _CPPUNWIND)
#	endif
#	define SPRIG_WAVE_MACROS_35(OPT) SPRIG_WAVE_MACROS_REM(OPT, "C++ 言語機能オプション")

#	define SPRIG_WAVE_MACROS_36(OPT) SPRIG_WAVE_MACROS_SEP(OPT, "-")

#	ifdef _DLL
#		define SPRIG_WAVE_MACROS_37(OPT) SPRIG_WAVE_MACROS_DEF(OPT, _DLL)
#	else
#		define SPRIG_WAVE_MACROS_37(OPT) SPRIG_WAVE_MACROS_NDEF(OPT, _DLL)
#	endif
#	ifdef _MT
#		define SPRIG_WAVE_MACROS_38(OPT) SPRIG_WAVE_MACROS_DEF(OPT, _MT)
#	else
#		define SPRIG_WAVE_MACROS_38(OPT) SPRIG_WAVE_MACROS_NDEF(OPT, _MT)
#	endif
#	define SPRIG_WAVE_MACROS_39(OPT) SPRIG_WAVE_MACROS_REM(OPT, "使用する CRT")

#	define SPRIG_WAVE_MACROS_40(OPT) SPRIG_WAVE_MACROS_SEP(OPT, "-")

#	ifdef _INTEGRAL_MAX_BITS
#		define SPRIG_WAVE_MACROS_41(OPT) SPRIG_WAVE_MACROS_DEFV(OPT, _INTEGRAL_MAX_BITS)
#	else
#		define SPRIG_WAVE_MACROS_41(OPT) SPRIG_WAVE_MACROS_NDEFV(OPT, _INTEGRAL_MAX_BITS)
#	endif
#	define SPRIG_WAVE_MACROS_42(OPT) SPRIG_WAVE_MACROS_REM(OPT, "最大の組み込み整数型のビット数")

#	define SPRIG_WAVE_MACROS_43(OPT) SPRIG_WAVE_MACROS_SEP(OPT, "-")

#	ifdef _MSC_VER
#		define SPRIG_WAVE_MACROS_44(OPT) SPRIG_WAVE_MACROS_DEFV(OPT, _MSC_VER)
#	else
#		define SPRIG_WAVE_MACROS_44(OPT) SPRIG_WAVE_MACROS_NDEFV(OPT, _MSC_VER)
#	endif
#	ifdef _MSC_FULL_VER
#		define SPRIG_WAVE_MACROS_45(OPT) SPRIG_WAVE_MACROS_DEFV(OPT, _MSC_FULL_VER)
#	else
#		define SPRIG_WAVE_MACROS_45(OPT) SPRIG_WAVE_MACROS_NDEFV(OPT, _MSC_FULL_VER)
#	endif
#	define SPRIG_WAVE_MACROS_46(OPT) SPRIG_WAVE_MACROS_REM(OPT, "コンパイラバージョン")

#	define SPRIG_WAVE_MACROS_47(OPT) SPRIG_WAVE_MACROS_SEP(OPT, "-")

#	ifdef _CPPLIB_VER
#		define SPRIG_WAVE_MACROS_48(OPT) SPRIG_WAVE_MACROS_DEFV(OPT, _CPPLIB_VER)
#	else
#		define SPRIG_WAVE_MACROS_48(OPT) SPRIG_WAVE_MACROS_NDEFV(OPT, _CPPLIB_VER)
#	endif
#	define SPRIG_WAVE_MACROS_49(OPT) SPRIG_WAVE_MACROS_REM(OPT, "C++ 標準ライブラリバージョン")

#	define SPRIG_WAVE_MACROS_50(OPT) SPRIG_WAVE_MACROS_SEP(OPT, "-")

#	ifdef _MFC_VER
#		define SPRIG_WAVE_MACROS_51(OPT) SPRIG_WAVE_MACROS_DEFV(OPT, _MFC_VER)
#	else
#		define SPRIG_WAVE_MACROS_51(OPT) SPRIG_WAVE_MACROS_NDEFV(OPT, _MFC_VER)
#	endif
#	ifdef _ATL_VER
#		define SPRIG_WAVE_MACROS_52(OPT) SPRIG_WAVE_MACROS_DEFV(OPT, _ATL_VER)
#	else
#		define SPRIG_WAVE_MACROS_52(OPT) SPRIG_WAVE_MACROS_NDEFV(OPT, _ATL_VER)
#	endif
#	define SPRIG_WAVE_MACROS_53(OPT) SPRIG_WAVE_MACROS_REM(OPT, "MFC, ATL バージョン")

#	define SPRIG_WAVE_MACROS_54(OPT) SPRIG_WAVE_MACROS_SEP(OPT, "-")

#	ifdef __CLR_VER
#		define SPRIG_WAVE_MACROS_55(OPT) SPRIG_WAVE_MACROS_DEFV(OPT, __CLR_VER)
#	else
#		define SPRIG_WAVE_MACROS_55(OPT) SPRIG_WAVE_MACROS_NDEFV(OPT, __CLR_VER)
#	endif
#	define SPRIG_WAVE_MACROS_56(OPT) SPRIG_WAVE_MACROS_REM(OPT, "CLR バージョン")

#	define SPRIG_WAVE_MACROS_57(OPT) SPRIG_WAVE_MACROS_SEP(OPT, "-")

#	ifdef _M_IX86
#		define SPRIG_WAVE_MACROS_58(OPT) SPRIG_WAVE_MACROS_DEFV(OPT, _M_IX86)
#	else
#		define SPRIG_WAVE_MACROS_58(OPT) SPRIG_WAVE_MACROS_NDEFV(OPT, _M_IX86)
#	endif
#	ifdef _M_IX86_FP
#		define SPRIG_WAVE_MACROS_59(OPT) SPRIG_WAVE_MACROS_DEFV(OPT, _M_IX86_FP)
#	else
#		define SPRIG_WAVE_MACROS_59(OPT) SPRIG_WAVE_MACROS_NDEFV(OPT, _M_IX86_FP)
#	endif
#	ifdef _M_X64
#		define SPRIG_WAVE_MACROS_60(OPT) SPRIG_WAVE_MACROS_DEFV(OPT, _M_X64)
#	else
#		define SPRIG_WAVE_MACROS_60(OPT) SPRIG_WAVE_MACROS_NDEFV(OPT, _M_X64)
#	endif
#	ifdef _M_IA64
#		define SPRIG_WAVE_MACROS_61(OPT) SPRIG_WAVE_MACROS_DEFV(OPT, _M_IA64)
#	else
#		define SPRIG_WAVE_MACROS_61(OPT) SPRIG_WAVE_MACROS_NDEFV(OPT, _M_IA64)
#	endif
#	ifdef _M_MPPC
#		define SPRIG_WAVE_MACROS_62(OPT) SPRIG_WAVE_MACROS_DEFV(OPT, _M_MPPC)
#	else
#		define SPRIG_WAVE_MACROS_62(OPT) SPRIG_WAVE_MACROS_NDEFV(OPT, _M_MPPC)
#	endif
#	ifdef _M_MRX000
#		define SPRIG_WAVE_MACROS_63(OPT) SPRIG_WAVE_MACROS_DEFV(OPT, _M_MRX000)
#	else
#		define SPRIG_WAVE_MACROS_63(OPT) SPRIG_WAVE_MACROS_NDEFV(OPT, _M_MRX000)
#	endif
#	ifdef _M_ALPHA
#		define SPRIG_WAVE_MACROS_64(OPT) SPRIG_WAVE_MACROS_DEFV(OPT, _M_ALPHA)
#	else
#		define SPRIG_WAVE_MACROS_64(OPT) SPRIG_WAVE_MACROS_NDEFV(OPT, _M_ALPHA)
#	endif
#	define SPRIG_WAVE_MACROS_65(OPT) SPRIG_WAVE_MACROS_REM(OPT, "プラットフォーム")

#	define SPRIG_WAVE_MACROS_66(OPT) SPRIG_WAVE_MACROS_SEP(OPT, "-")

#	ifdef _MSC_EXTENSIONS
#		define SPRIG_WAVE_MACROS_67(OPT) SPRIG_WAVE_MACROS_DEF(OPT, _MSC_EXTENSIONS)
#	else
#		define SPRIG_WAVE_MACROS_67(OPT) SPRIG_WAVE_MACROS_NDEF(OPT, _MSC_EXTENSIONS)
#	endif
#	ifdef __MSVC_RUNTIME_CHECKS
#		define SPRIG_WAVE_MACROS_68(OPT) SPRIG_WAVE_MACROS_DEF(OPT, __MSVC_RUNTIME_CHECKS)
#	else
#		define SPRIG_WAVE_MACROS_68(OPT) SPRIG_WAVE_MACROS_NDEF(OPT, __MSVC_RUNTIME_CHECKS)
#	endif
#	ifdef _VC_NODEFAULTLIB
#		define SPRIG_WAVE_MACROS_69(OPT) SPRIG_WAVE_MACROS_DEF(OPT, _VC_NODEFAULTLIB)
#	else
#		define SPRIG_WAVE_MACROS_69(OPT) SPRIG_WAVE_MACROS_NDEF(OPT, _VC_NODEFAULTLIB)
#	endif
#	ifdef _OPENMP
#		define SPRIG_WAVE_MACROS_70(OPT) SPRIG_WAVE_MACROS_DEF(OPT, _OPENMP)
#	else
#		define SPRIG_WAVE_MACROS_70(OPT) SPRIG_WAVE_MACROS_NDEF(OPT, _OPENMP)
#	endif
#	ifdef _Wp64
#		define SPRIG_WAVE_MACROS_71(OPT) SPRIG_WAVE_MACROS_DEF(OPT, _Wp64)
#	else
#		define SPRIG_WAVE_MACROS_71(OPT) SPRIG_WAVE_MACROS_NDEF(OPT, _Wp64)
#	endif
#	define SPRIG_WAVE_MACROS_72(OPT) SPRIG_WAVE_MACROS_REM(OPT, "各種コンパイラオプション")

#	define SPRIG_WAVE_MACROS_73(OPT) SPRIG_WAVE_MACROS_SEP(OPT, "-")

#	ifdef __cplusplus_cli
#		define SPRIG_WAVE_MACROS_74(OPT) SPRIG_WAVE_MACROS_DEFV(OPT, __cplusplus_cli)
#	else
#		define SPRIG_WAVE_MACROS_74(OPT) SPRIG_WAVE_MACROS_NDEFV(OPT, __cplusplus_cli)
#	endif
#	define SPRIG_WAVE_MACROS_75(OPT) SPRIG_WAVE_MACROS_REM(OPT, "C++/CLI 言語を使用するか")

#	define SPRIG_WAVE_MACROS_76(OPT) SPRIG_WAVE_MACROS_SEP(OPT, "-")

#	ifdef _MANAGED
#		define SPRIG_WAVE_MACROS_77(OPT) SPRIG_WAVE_MACROS_DEF(OPT, _MANAGED)
#	else
#		define SPRIG_WAVE_MACROS_77(OPT) SPRIG_WAVE_MACROS_NDEF(OPT, _MANAGED)
#	endif
#	ifdef _M_CEE
#		define SPRIG_WAVE_MACROS_78(OPT) SPRIG_WAVE_MACROS_DEF(OPT, _M_CEE)
#	else
#		define SPRIG_WAVE_MACROS_78(OPT) SPRIG_WAVE_MACROS_NDEF(OPT, _M_CEE)
#	endif
#	ifdef _M_CEE_PURE
#		define SPRIG_WAVE_MACROS_79(OPT) SPRIG_WAVE_MACROS_DEF(OPT, _M_CEE_PURE)
#	else
#		define SPRIG_WAVE_MACROS_79(OPT) SPRIG_WAVE_MACROS_NDEF(OPT, _M_CEE_PURE)
#	endif
#	ifdef _M_CEE_SAFE
#		define SPRIG_WAVE_MACROS_80(OPT) SPRIG_WAVE_MACROS_DEF(OPT, _M_CEE_SAFE)
#	else
#		define SPRIG_WAVE_MACROS_80(OPT) SPRIG_WAVE_MACROS_NDEF(OPT, _M_CEE_SAFE)
#	endif
#	define SPRIG_WAVE_MACROS_81(OPT) SPRIG_WAVE_MACROS_REM(OPT, "CLR オプション")

#	define SPRIG_WAVE_MACROS_82(OPT) SPRIG_WAVE_MACROS_SEP(OPT, "-")

#	ifdef __COUNTER__
#		define SPRIG_WAVE_MACROS_83(OPT) SPRIG_WAVE_MACROS_DEFP(OPT, __COUNTER__)
#	else
#		define SPRIG_WAVE_MACROS_83(OPT) SPRIG_WAVE_MACROS_NDEFP(OPT, __COUNTER__)
#	endif
#	ifdef __FUNCDNAME__
#		define SPRIG_WAVE_MACROS_84(OPT) SPRIG_WAVE_MACROS_DEFP(OPT, __FUNCDNAME__)
#	else
#		define SPRIG_WAVE_MACROS_84(OPT) SPRIG_WAVE_MACROS_NDEFP(OPT, __FUNCDNAME__)
#	endif
#	ifdef __FUNCSIG__
#		define SPRIG_WAVE_MACROS_85(OPT) SPRIG_WAVE_MACROS_DEFP(OPT, __FUNCSIG__)
#	else
#		define SPRIG_WAVE_MACROS_85(OPT) SPRIG_WAVE_MACROS_NDEFP(OPT, __FUNCSIG__)
#	endif
#	ifdef __FUNCTION__
#		define SPRIG_WAVE_MACROS_86(OPT) SPRIG_WAVE_MACROS_DEFP(OPT, __FUNCTION__)
#	else
#		define SPRIG_WAVE_MACROS_86(OPT) SPRIG_WAVE_MACROS_NDEFP(OPT, __FUNCTION__)
#	endif
#	define SPRIG_WAVE_MACROS_87(OPT) SPRIG_WAVE_MACROS_REM(OPT, "特殊な展開が行われるマクロ（これらは正常に展開されません）")

#	define SPRIG_WAVE_MACROS_88(OPT) SPRIG_WAVE_MACROS_SEP(OPT, "-")
	//
	// SPRIG_WAVE_MACROS_NUM
	//
#	define SPRIG_WAVE_MACROS_NUM 89

#endif	// #ifdef SPRIG_WAVE_VISUALC

#endif	// #ifndef SPRIG_WAVE_COMPILER_VISUALC_HPP
