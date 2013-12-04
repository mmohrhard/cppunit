#ifndef _INCLUDE_CPPUNIT_CONFIG_MSVC6_H
#define _INCLUDE_CPPUNIT_CONFIG_MSVC6_H 1

#if _MSC_VER > 1000     // VC++
#pragma warning( disable : 4786 )   // disable warning debug symbol > 255...
#endif // _MSC_VER > 1000

// Compiler error location format for CompilerOutputter
// See class CompilerOutputter for format.
#undef CPPUNIT_COMPILER_LOCATION_FORMAT
#if _MSC_VER >= 1300    // VS 7.0
# define CPPUNIT_COMPILER_LOCATION_FORMAT "%p(%l) : error : "
#else
# define CPPUNIT_COMPILER_LOCATION_FORMAT "%p(%l):"
#endif

#if _MSC_VER >= 1300    // VS 7.0
#define CPPUNIT_UNIQUE_COUNTER __COUNTER__
#endif // if _MSC_VER >= 1300    // VS 7.0

/* _INCLUDE_CPPUNIT_CONFIG_MSVC6_H */
#endif
