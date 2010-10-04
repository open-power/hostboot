#ifndef __SYS_TIME_H
#define __SYS_TIME_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

int nanosleep(uint64_t sec, uint64_t nsec);

#ifdef __cplusplus
}
#endif

#endif
