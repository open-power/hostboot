#ifndef __SYS_MMIO_H
#define __SYS_MMIO_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

void* mmio_map(void* ra, size_t pages);
int mmio_unmap(void* ea, size_t pages);

#ifdef __cplusplus
}
#endif

#endif
