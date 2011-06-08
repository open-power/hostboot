#ifndef __SYS_MMIO_H
#define __SYS_MMIO_H

#include <stdint.h>
#include <sys/mutex.h>

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

/** @fn mmio_xscom_mutex()
 *  @brief Returns the per-CPU mutex for the XSCOM hardware logic.
 *
 *  @pre Task must be pinned to a CPU by task_affinity_pin.  Function will
 *       assert if not met.
 *
 *  @returns The existing mutex for the CPU or creates a new one.
 *
 *  @note The task should only interact with the mutex while protected by an
 *        affinity pin.  If the pin is moved the mutex is no longer
 *        guarenteed for the CPU the task is executing on.
 */
mutex_t mmio_xscom_mutex();

#ifdef __cplusplus
}
#endif

#endif
