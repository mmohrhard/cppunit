#ifndef _INCLUDE_CPPUNIT_CONFIG_EVC4_H
#define _INCLUDE_CPPUNIT_CONFIG_EVC4_H 1

#if _MSC_VER > 1000     // VC++
#pragma warning( disable : 4786 )   // disable warning debug symbol > 255...
#endif // _MSC_VER > 1000

#define CPPUNIT_NO_STREAM 1
#define CPPUNIT_NO_ASSERT 1

// Compiler error location format for CompilerOutputter
// See class CompilerOutputter for format.
#undef CPPUNIT_COMPILER_LOCATION_FORMAT
#if _MSC_VER >= 1300    // VS 7.0
# define CPPUNIT_COMPILER_LOCATION_FORMAT "%p(%l) : error : "
#else
# define CPPUNIT_COMPILER_LOCATION_FORMAT "%p(%l):"
#endif

/* _INCLUDE_CPPUNIT_CONFIG_EVC4_H */
#endif
