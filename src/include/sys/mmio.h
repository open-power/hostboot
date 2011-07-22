#ifndef __SYS_MMIO_H
#define __SYS_MMIO_H

#include <stdint.h>
#include <sys/sync.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Sizes used to determine segment block size during map/unmap functions
 * within the kernel or user space
 */
enum SEG_DATA_SIZES
{
    THIRTYTWO_GB = 0x800000000,
};

/**
 * @brief DEPRECATED
 */
void* mmio_map(void* ra, size_t pages);
/**
 * @brief DEPRECATED
 */
int mmio_unmap(void* ea, size_t pages);

/**
 * @brief System call to map a device into the device segment(2TB)
 * @param ra[in] - Void pointer to real address to be mapped in
 * @param i_devDataSize[in] - Size of device segment block
 * @return void* - Pointer to beginning virtual address, NULL otherwise
 */
void* mmio_dev_map(void *ra, SEG_DATA_SIZES i_devDataSize);
/**
 * @brief System call to unmap a device from the device segment(2TB)
 * @param ea[in] - Void pointer to effective address
 * @return int - 0 for successful unmap, non-zero otherwise
 */
int mmio_dev_unmap(void *ea);

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
