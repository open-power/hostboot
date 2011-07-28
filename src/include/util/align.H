#ifndef __UTIL_ALIGN_H
#define __UTIL_ALIGN_H

#include <limits.h>

#define ALIGN_4(u) ((u + 0x3ull) & ~0x3ull)
#define ALIGN_PAGE(u) ((u + (PAGESIZE-1)) & ~(PAGESIZE-1))

#endif
