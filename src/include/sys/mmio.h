#ifndef __SYS_MMIO_H
#define __SYS_MMIO_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

void* mmio_map(void* ra, size_t pages);
int mmio_unmap(void* ea, size_t pages);

/** @fn mmio_hmer_read()
 *  @brief Reads the protected HMER register.
 */
uint64_t mmio_hmer_read();

/** @fn mmio_hmer_write()
 *  @brief Writes the protected HMER register.
 *
 *  @param[in] value - The value to write into the HMER.
 *
 *  @returns 0.
 */
int mmio_hmer_write(uint64_t value);

#ifdef __cplusplus
}
#endif

#endif
