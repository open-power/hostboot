#ifndef __SYS_MISC_H
#define __SYS_MISC_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

/** @fn shutdown()
 *  @brief Shutdown all CPUs (hardware threads)
 *  @param[in] i_status The status code to post
 */
void shutdown(uint64_t i_status);

#ifdef __cplusplus
}
#endif

#endif
