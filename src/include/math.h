#include <stdint.h>
#include <builtins.h>

#ifndef _MATH_H
#define _MATH_H

#ifdef __cplusplus
extern "C"
{
#endif

ALWAYS_INLINE
static inline int64_t log2(uint64_t s)
{
    int64_t n = cntlzd(s);
    return 63-n;
}

#ifdef __cplusplus
};
#endif

#endif
