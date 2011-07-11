#ifndef __SYS_TIME_H
#define __SYS_TIME_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif


/** @fn nanosleep()
 *  @brief Sleep for time duration given: seconds plus nanoseconds.
 *  @param[in] sec  - seconds
 *  @param[in] nsec - nanoseconds (billionths of a second)
 */
void nanosleep(uint64_t sec, uint64_t nsec);



#ifdef __cplusplus
}
#endif

#endif
