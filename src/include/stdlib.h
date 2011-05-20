#ifndef __STDLIB_H
#define __STDLIB_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

void* malloc(size_t);
void free(void*);
void* realloc(void*, size_t);

#ifdef __cplusplus
};
#endif

#endif
