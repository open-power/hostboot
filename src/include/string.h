#ifndef __STRING_H
#define __STRING_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" 
{
#endif

    void* memset(void* s, int c, size_t n);
    int strcmp(const char* s1, const char* s2);

#ifdef __cplusplus
};
#endif

#endif
