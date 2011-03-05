#include <builtins.h>

#ifndef _ASSERT_H
#define _ASSERT_H

#ifdef __cplusplus
extern "C"
{
#endif

NO_RETURN
void __assert(bool expr, const char *exprStr, const char *file, int line);

#define assert(expr) \
{\
    if (!(expr))\
    {\
        __assert((expr), #expr, __FILE__, __LINE__);\
    }\
}\

#ifdef NDEBUG 
#undef assert
#define assert(expr) { }
#endif

#ifdef __cplusplus
};
#endif

#endif
