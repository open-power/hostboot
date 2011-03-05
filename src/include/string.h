#ifndef __STRING_H
#define __STRING_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" 
{
#endif

    void *memset(void* s, int64_t c, size_t n);
    void bzero(void *vdest, size_t len);
    void *memcpy(void *dest, const void *src, size_t num);
    void *memmove(void *vdest, const void *vsrc, size_t len);
    int64_t memcmp(const void *p1, const void *p2, size_t len);

    char* strcpy(char* d, const char* s);
    int strcmp(const char* s1, const char* s2);
    size_t strlen(const char* s1);

#ifdef __cplusplus
};
#endif

#endif
