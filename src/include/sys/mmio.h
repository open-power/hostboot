#ifndef __SYS_MMIO_H
#define __SYS_MMIO_H

#include <stdint.h>
#include <sys/sync.h>

#ifdef __cplusplus
extern "C"
{
#endif

/** @fn mmio_map()
 *  @brief Map a region into virtual address space.
 *  
 *  @param[in] ra - address of page
 *  @param[in] pages - count of pages to map
 *
 *  @returns The virtual address where mapped.
 */
void* mmio_map(void* ra, size_t pages);


/** @fn mmio_unmap()
 *  @brief Unmap a region previously mapped into virtual address space.
 *
 *  Appears not to be implemented. See _mmioUnmap in src/kernel/vmmmgr.C
 *  
 *  @param[in] ea - virtual address as returned from mmio_map()
 *  @param[in] pages - count of pages to unmap
 *
 *  @returns -1 from _mmioUnmap in src/kernel/vmmmgr.C 
 */
int mmio_unmap(void* ea, size_t pages);


/** @fn mmio_hmer_read()
 *  @brief Reads and returns protected HMER register.
 *  @return HMER register value
 */
uint64_t mmio_hmer_read();


/** @fn mmio_hmer_write()
 *  @brief Writes the protected HMER register.
 *
 *  @param[in] value - The value to write into the HMER.
 */
void mmio_hmer_write(uint64_t value);


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
 *        guaranteed for the CPU the task is executing on.
 */
mutex_t * mmio_xscom_mutex();

#ifdef __cplusplus
}
#endif

#endif
