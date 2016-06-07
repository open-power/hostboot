/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/runtime/interface.h $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2016                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef __RUNTIME__INTERFACE_H
#define __RUNTIME__INTERFACE_H

/** @file interface.h
 *  @brief Interfaces between Hostboot Runtime and Sapphire.
 *
 *  This file has two structures of function pointers: hostInterfaces_t and
 *  runtimeInterfaces_t.  hostInterfaces are provided by Sapphire (or a
 *  similar environment, such as Hostboot IPL's CxxTest execution).
 *  runtimeInterfaces are provided by Hostboot Runtime to Sapphire.
 *
 *  @note This file must be in C rather than C++.
 */

/** Current interface version.
 *  0x9001:  9=P9, 001=Version 1
 */
#define HOSTBOOT_RUNTIME_INTERFACE_VERSION 0x9001

#ifndef __HOSTBOOT_RUNTIME_INTERFACE_VERSION_ONLY

#include <stdint.h>
#include <time.h>

/** Memory error types defined for memory_error() interface. */
enum MemoryError_t
{
    /** Hardware has reported a solid memory CE that is correctable, but
     *  continues to report errors on subsequent reads. A second CE on that
     *  cache line will result in memory UE. Therefore, it is advised to
     *  migrate off of the address range as soon as possible. */
    MEMORY_ERROR_CE,

    /** Hardware has reported an uncorrectable error in memory (memory UE,
     *  channel failure, etc). The hypervisor should migrate any partitions
     *  off this address range as soon as possible. Note that these kind of
     *  errors will most likely result in persistent partition failures. It
     *  is advised that the hypervisor gives firmware some time after
     *  partition failures to handle the hardware attentions so that the
     *  hypervisor will know all areas of memory that are impacted by the
     *  failure. */
    MEMORY_ERROR_UE,

    /** Firmware has predictively requested service on a part in the memory
     *  subsystem. The partitions may not have been affected, but it is
     *  advised to migrate off of the address range as soon as possible to
     *  avoid potential partition outages. */
    MEMORY_ERROR_PREDICTIVE,
};

/**
 * I2C Master Description: chip, engine and port packed into
 * a single 64-bit argument
 *
 * ---------------------------------------------------
 * |         chip         |  reserved  |  eng | port |
 * |         (32)         |    (16)    |  (8) | (8)  |
 * ---------------------------------------------------
 */
#define HBRT_I2C_MASTER_CHIP_SHIFT        32
#define HBRT_I2C_MASTER_CHIP_MASK         (0xfffffffful << 32)
#define HBRT_I2C_MASTER_ENGINE_SHIFT      8
#define HBRT_I2C_MASTER_ENGINE_MASK       (0xfful << 8)
#define HBRT_I2C_MASTER_PORT_SHIFT        0
#define HBRT_I2C_MASTER_PORT_MASK         (0xfful)


/**
 *  Load types for the load_pm_complex() interface
 *      HBRT_PM_LOAD: initial load of all lids/sections from scratch,
 *                    preserve nothing
 *      HBRT_PM_RELOAD: concurrent reload of all lids/sections,
 *                      but preserve runtime updates
 */
#define HBRT_PM_LOAD    0
#define HBRT_PM_RELOAD  1

/** @typedef hostInterfaces_t
 *  @brief Interfaces provided by the underlying environment (ex. Sapphire).
 *
 *  @note Some of these functions are not required (marked optional) and
 *        may be NULL.
 */
typedef struct hostInterfaces
{
    /** Interface version. */
    uint64_t interfaceVersion;

    /**
     *  @brief Put a string to the console
     *         Host must add newline to end of the string
     *  @param[in] i_str string to print
     *  @platform FSP, OpenPOWER
     */
    void (*puts)(const char* i_str);

    /**
     *  @brief Critical failure in runtime executeion
     *  @platform FSP, OpenPOWER
     */
    void (*assert)();

    /**
     *  @brief Hint to environment that the page may be executed
     *         OPTIONAL - may be implemented as a NO-OP
     *  @param[in] i_pageAddr aligned address of page that may be executed
     *  @return 0 on success else return code
     *  @platform FSP, OpenPOWER
     */
    int (*set_page_execute)(void* i_pageAddr);

    /**
     *  @brief Allocate a block of memory
     *  @param[in] i_blockSize size of the block to be allocated
     *  @return pointer to beginning of the block or NULL if allocation failed
     *  @platform FSP, OpenPOWER
     */
    void* (*malloc)(size_t i_blockSize);

    /**
     *  @brief Deallocate a block of memory
     *  @param[in] i_blockAddr address pointing to block of memory to deallocate
     *  @platform FSP, OpenPOWER
     */
    void (*free)(void* i_blockAddr);

    /**
     *  @brief Resize a block of memory
     *  @param[in] i_blockAddr address pointing to block of memory to resize
     *  @param[in] i_blockSize new size of the allocated block
     *  @return pointer to beginning of the block or NULL if resize failed
     *  @platform FSP, OpenPOWER
     */
    void* (*realloc)(void* i_blockAddr, size_t blockSize);

    /**
     *  @brief Send an error log to the FSP
     *  @param[in] i_plid     platform log identifier
     *  @param[in] i_errlSize data size in bytes
     *  @param[in] i_errlData pointer to data
     *  @return 0 on success else error code
     *  @platform FSP
     */
    int (*sendErrorLog)(uint32_t i_plid, uint32_t i_errlSize,
                        void* i_errlData);

    /**
     *  @brief Scan communication read
     *  @param[in]  i_chipId   from devtree defn
     *  @param[in]  i_scomAddr scom address to read
     *  @param[out] o_scomData pointer to 8-byte data buffer
     *  @return 0 on success else return code
     *  @platform FSP, OpenPOWER
     */
    int (*scom_read)(uint64_t i_chipId, uint64_t i_scomAddr,
                     void* o_scomData);

    /**
     *  @brief Scan communication write
     *  @param[in] i_chipId   from devtree defn
     *  @param[in] i_scomAddr scom address to write
     *  @param[in] i_scomData pointer to 8-byte data buffer
     *  @return 0 on success else return code
     *  @platform FSP, OpenPOWER
     */
    int (*scom_write)(uint64_t i_chipId, uint64_t i_scomAddr,
                      void* i_scomData);

    /**
     *  @brief Load a LID from PNOR, FSP, etc.
     *  @param[in]  i_lidId     LID number
     *  @param[out] o_lidBuffer allocated buffer for LID
     *  @param[out] o_lidSize   size of LID (in bytes)
     *  @return 0 on success, else RC.
     *  @platform FSP
     */
    int (*lid_load)(uint32_t i_lidId, void** o_lidBuffer,
                    size_t* o_lidSize);

    /**
     *  @brief Release memory from previously loaded LID.
     *  @param[in] i_lidBuffer allocated buffer for LID to release
     *  @return 0 on success, else return code
     *  @platform FSP
     */
    int (*lid_unload)(void* i_lidBuffer);

    /**
     *  @brief Get the address of a reserved memory region by its name
     *  @param[in] i_name     memory region name (ex. "ibm,hbrt-vpd-image")
     *  @param[in] i_instance instance number
     *  @return physical address of region or NULL
     *  @platform FSP, OpenPOWER
     **/
    uint64_t (*get_reserved_mem)(const char* i_name, uint32_t i_instance);

    /**
     *  @brief Force a core to be awake, or clear the force
     *  @param[in] i_core  Core to wake (based on devtree defn)
     *  @param[in] i_mode  0=force awake
     *                     1=clear force
     *  @return non-zero return code on error
     *  @platform FSP, OpenPOWER
     */
    int (*wakeup)(uint32_t i_core, uint32_t i_mode );

    /**
     *  @brief Delay/sleep for at least the time given
     *  @param[in] i_seconds     seconds to sleep
     *  @param[in] i_nanoSeconds nano seconds to sleep
     *  @platform FSP, OpenPOWER
     */
    void (*nanosleep)(uint64_t i_seconds, uint64_t i_nanoSeconds);

    /**
     * DEPRECATED - remove when PHYP support new pm_complex functions
     * @brief Report an OCC error to the host
     * @param[in] Failing    status that identifies the nature of the fail
     * @param[in] Identifier that specifies the failing part
     * @platform FSP
     */
    void (*report_failure)( uint64_t i_status, uint64_t i_partId );

    /**
     *  @brief Reads the clock value from a POSIX clock
     *  @param[in]  i_clkId the clock ID to read
     *  @param[out] o_tp    the timespec struct to store the clock value in
     *  @return 0 or -(errno)
     *  @retval     0       SUCCESS
     *  @retval     -EINVAL invalid clock requested
     *  @retval     -EFAULT NULL ptr given for timespec struct
     *  @platform FSP, OpenPOWER
     */
    int (*clock_gettime)(clockid_t i_clkId, timespec_t* o_tp);

    /**
     *  @brief Read Pnor
     *  @param[in]  i_proc          processor Id
     *  @param[in]  i_partitionName name of the partition to read
     *  @param[in]  i_offset        offset within the partition
     *  @param[out] o_data          pointer to the data read
     *  @param[in]  i_sizeBytes     size of o_data buffer, maximum number
     *                              of bytes to read
     *  @retval     rc              negative on error, else number of
     *                              bytes actually read
     *  @platform OpenPOWER
     */
    int (*pnor_read) (uint32_t i_proc, const char* i_partitionName,
                      uint64_t i_offset, void* o_data, size_t i_sizeBytes);

    /**
     *  @brief Write Pnor
     *  @param[in] i_proc          processor Id
     *  @param[in] i_partitionName name of the partition to write
     *  @param[in] i_offset        offset withing the partition
     *  @param[in] i_data          pointer to the data to write
     *  @param[in] i_sizeBytes     size of i_data buffer, maximum number
     *                             of bytes to read
     *  @retval    rc              negative on error, else number of
     *                             bytes actually written
     */
    int (*pnor_write) (uint32_t i_proc, const char* i_partitionName,
                       uint64_t i_offset, void* i_data, size_t i_sizeBytes);

    /**
     *  @brief Read data from an i2c device
     *  @param[in] i_master     chip, engine and port packed into
     *                          a single 64-bit argument
     *     ---------------------------------------------------
     *     |         chip         |  reserved  |  eng | port |
     *     |         (32)         |    (16)    |  (8) | (8)  |
     *     ---------------------------------------------------
     *  @param[in] i_devAddr    I2C address of device
     *  @param[in] i_offsetSize length of offset (in bytes)
     *  @param[in] i_offset     offset within device to read
     *  @param[in] i_length     number of bytes to read
     *  @param[out] o_data      data that was read
     *  @return 0 on success else return code
     *  @platform OpenPOWER
     */
    int (*i2c_read)( uint64_t i_master, uint16_t i_devAddr,
                     uint32_t i_offsetSize, uint32_t i_offset,
                     uint32_t i_length, void* o_data );

    /**
     *  @brief Write data to an i2c device
     *  @param[in] i_master     chip, engine and port packed into
     *                          a single 64-bit argument
     *    ---------------------------------------------------
     *    |         chip         |  reserved  |  eng | port |
     *    |         (32)         |    (16)    |  (8) | (8)  |
     *    ---------------------------------------------------
     *  @param[in] i_devAddr    I2C address of device
     *  @param[in] i_offsetSize length of offset (in bytes)
     *  @param[in] i_offset     offset within device to write
     *  @param[in] i_length     number of bytes to write
     *  @param[in] i_data       data to write
     *  @return 0 on success else return code
     *  @platform OpenPOWER
     */
    int (*i2c_write)( uint64_t i_master, uint16_t i_devAddr,
                      uint32_t i_offsetSize, uint32_t i_offset,
                      uint32_t i_length, void* i_data );

    /**
     *  @brief Perform an IPMI transaction
     *  @param[in] netfn      the IPMI netfn byte
     *  @param[in] cmd        the IPMI cmd byte
     *  @param[in] tx_buf     the IPMI packet to send to the host
     *  @param[in] tx_size    the number of bytes to send
     *  @param[in] rx_buf     a buffer to be populated with the IPMI
     *                        response. First bytes will be the
     *                        IPMI completion code.
     *  @param[inout] rx_size The allocated size of the rx buffer on input
     *                        updated to the size of the response on output.
     *  @retval rc            non-zero on error
     *  @platform OpenPOWER
     */
    int (*ipmi_msg)(uint8_t netfn, uint8_t cmd,
                    void *tx_buf, size_t tx_size,
                    void *rx_buf, size_t *rx_size);

    /**
     * @brief Hardware has reported a memory error. This function requests the
     *        hypervisor to dynamically remove all pages within the address
     *        range given (including endpoints) from the available memory space.
     *
     * It is understood that the hypervisor may not be able to immediately
     * deallocate the memory because it is in use by a partition. Therefore, the
     * hypervisor should cache all requests and deallocate the memory once it
     * has been freed.
     *
     * Firmware does not know page boundaries so the addresses given could be
     * any address within a page. In some cases, the start and end address may
     * be the same address, indicating that only one page needs to be
     * deallocated.
     *
     * @param  i_startAddr The beginning address of the range.
     * @param  i_endAddr   The end address of the range.
     * @param  i_errorType See enum MemoryError_t.
     *
     * @return 0 if the request is successfully received. Any value other than 0
     *         on failure. The hypervisor should cache the request and return
     *         immediately. It should not wait for the request to be applied.
     *         See note above.
     * @platform FSP, OpenPOWER
     */
    int (*memory_error)( uint64_t i_startAddr, uint64_t i_endAddr,
                         enum MemoryError_t i_errorType );

    /**
     *  @brief Modify the SCOM restore section of the HCODE image with the
     *         given register data
     *
     *  @note The Hypervisor should perform the following actions:
     *        - insert the data into the HCODE image (p9_stop_api)
     *
     *  @pre HBRT is responsible for enabling special wakeup on the
     *       associated core(s) before calling this interface
     *
     *  @param  i_homer     start address of the homer image
     *  @param  i_section   runtime section to update
     *                      (passthru to pore_gen_scom)
     *  @param  i_operation type of operation to perform
     *                      (passthru to pore_gen_scom)
     *  @param  i_scomAddr  fully qualified scom address
     *  @param  i_scomData  data for operation
     *
     *  @return 0 if the request is successfully received.
     *          Any value other than 0 on failure.
     *  @platform FSP, OpenPOWER
     */
    int (*hcode_scom_update)( uint64_t i_homer,
                              uint32_t i_section,
                              uint32_t i_operation,
                              uint64_t i_scomAddr,
                              uint64_t i_scomData );

    /**
     *  @brief Map a physical address space into usable memory
     *  @note Repeated calls to map the same memory should not return an error
     *  @param[in]  i_physMem  Physical address
     *  @param[in]  i_bytes    Number of bytes to map in
     *  @return NULL on error, else pointer to usable memory
     *  @platform FSP, OpenPOWER
     */
    void* (*map_phys_mem)(uint64_t i_physMem, size_t i_bytes);

    /**
     *  @brief Unmap a physical address space from usable memory
     *  @param[in]  i_ptr  Previously mapped pointer
     *  @return 0 on success, else RC
     *  @platform FSP, OpenPOWER
     */
    int (*unmap_phys_mem)(void* i_ptr);

    // Reserve some space for future growth.
    // do NOT ever change this number, even if you add functions.
    //
    // The value of 32 was somewhat arbitrarily chosen.
    //
    // If either side modifies the interface.h file we're suppose to be able to
    // tolerate the other side not supporting the function yet.  The function
    // pointer can be NULL.  So if we require a new interface from OPAL, like
    // "read_iic", we need to be able to tolerate that function pointer being
    // NULL and do something sane (and erroring out is not consider sane).
    //
    // The purpose of this is to give us the ability to update Hostboot and
    // OPAL independently.  It is pretty rare that we both have function ready
    // at the same time.  The "reserve" is there so that the structures are
    // allocated with sufficient space and populated with NULL function
    // pointers.  32 is big enough that we should not likely add that many
    // functions from either direction in between any two levels of support.
    void (*reserved[32])(void);

} hostInterfaces_t;


typedef struct runtimeInterfaces
{
    /** Interface version. */
    uint64_t interfaceVersion;

    /**
     *  @brief Execute CxxTests that may be contained in the image.
     *  @param[in] i_stats pointer to CxxTestStats structure for
     *                     results reporting.
     *  @platform FSP, OpenPOWER
     */
    void (*cxxtestExecute)(void* i_stats);

    /**
     *  @brief Get a list of lid numbers for the lids known to HostBoot
     *  @param[out] o_num the number of lids in the list
     *  @return a pointer to the lid list
     *  @platform FSP
     */
    const uint32_t * (*get_lid_list)(size_t * o_num);

    /**
     *  @brief Load OCC/HCODE images into mainstore
     *
     *  @param[in] i_chip            the HW chip id (XSCOM chip ID)
     *  @param[in] i_homer_addr      the physical mainstore address of the
     *                               start of the HOMER image,
     *  @param[in] i_occ_common_addr the physical mainstore address of the
     *                               OCC common area, 8MB, used for
     *                               OCC-OCC communication (1 per node)
     *  @param[in] i_mode            selects initial load vs concurrent reloads
     *                               HBRT_PM_LOAD:
     *                                  load all lids/sections from scratch,
     *                                  preserve nothing
     *                               HBRT_PM_RELOAD:
     *                                  reload all lids/sections,
     *                                  but preserve runtime updates
     *  @return 0 on success else return code
     *  @platform FSP, OpenPOWER
     */
    int (*load_pm_complex)( uint64_t i_chip,
                            uint64_t i_homer_addr,
                            uint64_t i_occ_common_addr,
                            uint32_t i_mode );

    /**
     *  @brief Start OCC/HCODE on the specified chip
     *  @param[in] i_chip the HW chip id
     *  @return 0 on success else return code
     *  @platform FSP, OpenPOWER
     */
    int (*start_pm_complex)( uint64_t i_chip );

    /**
     *  @brief Reset OCC/HCODE on the specified chip
     *  @param[in] i_chip the HW chip id
     *  @return 0 on success else return code
     *  @platform FSP, OpenPOWER
     */
    int (*reset_pm_complex)( uint64_t i_chip );

    /**
     *  @brief Notify HTMGT that an OCC has an error to report
     *
     *  @details  When an OCC has encountered an error that it wants to
     *            be reported, this interface will be called to trigger
     *            HTMGT to collect and commit the error.
     *
     *  @param[in] i_chipId ChipID which identifies the OCC reporting an error
     *  @platform FSP, OpenPOWER
     */
    void (*process_occ_error)(uint64_t i_chipId);

    /**
     *  @brief Enable chip attentions
     *  @return 0 on success else return code
     *  @platform FSP, OpenPOWER
     */
    int (*enable_attns)(void);

    /**
     *  @brief Disable chip attentions
     *  @return 0 on success else return code
     *  @platform FSP, OpenPOWER
     */
    int (*disable_attns)(void);

    /**
     *  @brief handle chip attentions
     *  @param[in] i_proc        processor chip id at attention
     *                           XSCOM chip id based on devtree defn
     *  @param[in] i_ipollStatus processor chip Ipoll status
     *  @param[in] i_ipollMask   processor chip Ipoll mask
     *  @return 0 on success else return code
     *  @platform FSP, OpenPOWER
     */
    int (*handle_attns)( uint64_t i_proc,
                         uint64_t i_ipollStatus,
                         uint64_t i_ipollMask );

    /**
     *  @brief Notify HTMGT that an OCC has failed and needs to be reset
     *
     *  @details  When BMC detects an OCC failure that requires a reset,
     *            this interface will be called to trigger the OCC reset.
     *            HTMGT maintains a reset count and if there are additional
     *            resets available, the OCCs get reset/reloaded.
     *            If the recovery attempts have been exhauseted or the OCC
     *            fails to go active, an unrecoverable error will be logged
     *            and the system will remain in safe mode.
     *
     *  @param[in]  i_chipId  ChipID which identifies the failing OCC
     *  @platform OpenPOWER
     */
    void (*process_occ_reset)(uint64_t  i_chipId);

    /**
     *  @brief Change the OCC state
     *
     *  @details  This is a blocking call that will change the OCC state.
     *            The OCCs will only actuate (update processor frequency/
     *            voltages) when in Active state.  The OCC will only be
     *            monitoring/observing when in Observation state.
     *
     *  @note     When the OCCs are initially started, the state will default
     *            to Active.  If the state is changed to Observation, that
     *            state will be retained until the next IPL. (If the OCC would
     *            get reset, it would return to the last requested state)
     *
     *  @param[in]  i_occ_activation  set to 0 to move OCC to Observation state
     *                           or any other value to move OCC to Active state
     *  @returns  0 on success, or return code if the state did not change
     *  @platform OpenPOWER
     */
    int (*enable_occ_actuation)(int i_occ_activation);

    /**
     * @brief Apply a set of attribute overrides
     * @param[in] i_data pointer to binary override data
     * @param[in] i_size length of override data (bytes)
     * @returns  0 on success, or return code if the command failed
     * @platform FSP, OpenPOWER
     */
    int (*apply_attr_override)(uint8_t* i_data,
                               size_t i_size );

    /**
     *  @brief Send a pass-through command to HTMGT
     *
     *  @details  This is a blocking call that will send a command
     *            to HTMGT.
     *  @note     If o_rspLength is returned with a non-zero value,
     *            the data at the o_rspData should be dumped to
     *            stdout in a hex dump format.
     *  @note     The maximum response data returned will be 4096 bytes
     *
     *  @param[in]      i_cmdLength  number of bytes in pass-thru command data
     *  @param[in]     *i_cmdData    pointer to pass-thru command data
     *  @param[out]    *o_rspLength  pointer to number of bytes returned
     *                               in o_rspData
     *  @param[out]    *o_rspData    pointer to a 4096 byte buffer that will
     *                               contain the response data from the command
     *  @returns  0 on success, or return code if the command failed
     *  @platform OpenPOWER
     */
    int (*mfg_htmgt_pass_thru)( uint16_t   i_cmdLength,
                                uint8_t *  i_cmdData,
                                uint16_t * o_rspLength,
                                uint8_t *  o_rspData );

    /**
     *  @brief Execute an arbitrary command inside Hostboot Runtime
     *  @param[in]  argc        number of arguments (standard C args)
     *  @param[in]  argv        array of argument values (standard C args)
     *  @param[out] o_outString response message (NULL terminated), memory
     *                          allocated by hbrt, if o_outString is NULL
     *                          then no response will be sent
     *  @return 0 on success, else error code
     *  @platform FSP, OpenPOWER
     */
    int run_command( int argc,
                     const char** argv,
                     char** o_outString );

    // Reserve some space for future growth.
    void (*reserved[32])(void);

} runtimeInterfaces_t;


// For internal use. These routines are to be called after all other set up
// is complete.
// This approach is taken due to complication with linking to rt_main, the
// order of static global initializers, constructors, and vfs_module_init.

#ifdef __HOSTBOOT_RUNTIME
struct postInitCalls_t
{
    /**
     * @brief Apply ATTR_TMP overrides
     *
     */
    void (*callApplyTempOverrides)();

};

extern hostInterfaces_t* g_hostInterfaces;
runtimeInterfaces_t* getRuntimeInterfaces();
postInitCalls_t* getPostInitCalls();
#endif

#endif //__HOSTBOOT_RUNTIME_INTERFACE_VERSION_ONLY
#endif //__RUNTIME__INTERFACE_H
