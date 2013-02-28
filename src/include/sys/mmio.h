/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/sys/mmio.h $                                      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2010,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef __SYS_MMIO_H
#define __SYS_MMIO_H

#include <stdint.h>
#include <sys/sync.h>
#include <limits.h>

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
    THIRTYTWO_MB = (32*MEGABYTE),
    THIRTYTWO_GB = (32*GIGABYTE),
};

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

/** @enum MMIO_Scratch_Register
 *  @brief Enumeration of the available scratch registers and their assigned
 *         purpose.
 *
 *  These enumeration values should be used as the 'which' parameter of
 *  mmio_scratch_read / mmio_scratch_write.
 *
 *  These values come from the Chip Pervasive Spec.
 */
enum MMIO_Scratch_Register
{
        /** Thread0 Scratch Register - Progress Code / Status. */
    MMIO_SCRATCH_PROGRESS_CODE = 0x0,
        /** Thread1 Scratch Register - PNOR mode control*/
    MMIO_SCRATCH_PNOR_MODE = 0x8,
        /** Thread2 Scratch Register - Unused */
    MMIO_SCRATCH_ISTEP_MODE = 0x10,
        /** Thread3 Scratch Register - Unused */
    MMIO_SCRATCH_RSVD_T3 = 0x18,
        /** Thread4 Scratch Register - Unused */
    MMIO_SCRATCH_RSVD_T4 = 0x20,
        /** Thread5 Scratch Register - Unused */
    MMIO_SCRATCH_RSVD_T5 = 0x28,
        /** Thread6 Scratch Register - Identifies where hostboot currently
                                       resides and how large the space is */
    MMIO_SCRATCH_MEMORY_STATE = 0x30,
        /** Thread7 Scratch Register - Identifies if Hostboot is active after
         *                             host_start_payload. */
    MMIO_SCRATCH_HOSTBOOT_ACTIVE = 0x38,
        /** Thread7 Scratch Register - Set be SBE for reduced-threads support
         *                             for AVPs.  */
    MMIO_SCRATCH_AVP_THREADS = 0x38,
};

/** @fn mmio_scratch_read()
 *  @brief Reads and returns protected SCRATCH register.
 *
 *  @param[in] which - Which SCRATCH register to read (MMIO_Scratch_Register).
 *  @return Requested SCRATCH register value
 *
 *  @note SCRATCH registers can only be modified from the master processor,
 *        so this call may have the side effect of migrating your task to
 *        another core or hardware thread.  Beware that any affinity settings
 *        for the task are ignored by this call.
 */
uint64_t mmio_scratch_read(uint64_t which);

/** @fn mmio_scratch_write()
 *  @brief Writes the protected SCRATCH register.
 *
 *  @param[in] which - Which SCRATCH register to write (MMIO_Scratch_Register).
 *  @param[in] value - The value to write into the SCRATCH.
 *
 *  @note SCRATCH registers can only be modified from the master processor,
 *        so this call may have the side effect of migrating your task to
 *        another core or hardware thread.  Beware that any affinity settings
 *        for the task are ignored by this call.
 */
void mmio_scratch_write(uint64_t which, uint64_t value);


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
