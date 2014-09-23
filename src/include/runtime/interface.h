/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/runtime/interface.h $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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
/** Current interface version. */
#define HOSTBOOT_RUNTIME_INTERFACE_VERSION 1
#ifndef __HOSTBOOT_RUNTIME_INTERFACE_VERSION_ONLY

#include <stdint.h>

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

    /** Put a string to the console. */
    void (*puts)(const char*);
    /** Critical failure in runtime execution. */
    void (*assert)();

    /** OPTIONAL. Hint to environment that the page may be executed. */
    int (*set_page_execute)(void*);

    /** malloc */
    void* (*malloc)(size_t);
    /** free */
    void (*free)(void*);
    /** realloc */
    void* (*realloc)(void*, size_t);

    /** sendErrorLog
     * @param[in] plid Platform Log identifier
     * @param[in] data size in bytes
     * @param[in] pointer to data
     * @return 0 on success else error code
     */
    int (*sendErrorLog)(uint32_t,uint32_t,void *);

    /** Scan communication read
     * @param[in] chip_id (based on devtree defn)
     * @param[in] address
     * @param[in] pointer to 8-byte data buffer
     * @return 0 on success else return code
     */
    int (*scom_read)(uint64_t, uint64_t, void*);

    /** Scan communication write
     * @param[in] chip_id (based on devtree defn)
     * @param[in] address
     * @param[in] pointer to 8-byte data buffer
     * @return 0 on success else return code
     */
    int (*scom_write)(uint64_t, uint64_t, void* );

    /** lid_load
     *  Load a LID from PNOR, FSP, etc.
     *
     *  @param[in] LID number.
     *  @param[out] Allocated buffer for LID.
     *  @param[out] Size of LID (in bytes).
     *
     *  @return 0 on success, else RC.
     */
    int (*lid_load)(uint32_t, void**, size_t*);

    /** lid_unload
     *  Release memory from previously loaded LID.
     *
     *  @param[in] Allocated buffer for LID to release.
     *
     *  @return 0 on success, else RC.
     */
    int (*lid_unload)(void*);

    /** Get the address of a reserved memory region by its devtree name.
     *
     *  @param[in] Devtree name (ex. "ibm,hbrt-vpd-image")
     *  @return physical address of region (or NULL).
     **/
    uint64_t (*get_reserved_mem)(const char*);

    /**
     * @brief  Force a core to be awake, or clear the force
     * @param[in] i_core  Core to wake (based on devtree defn)
     * @param[in] i_mode  0=force awake
     *                    1=clear force
     *                    2=clear all previous forces
     * @return rc non-zero on error
     */
    int (*wakeup)(uint32_t i_core, uint32_t i_mode );

    /**
     * @brief Delay/sleep for at least the time given
     * @param[in] seconds
     * @param[in] nano seconds
     */
    void (*nanosleep)(uint64_t i_seconds, uint64_t i_nano_seconds);

    /**
     * @brief Report an error to the host
     * @param[in] Failing status that identifies the nature of the fail
     * @param[in] Identifier that specifies the failing part
     */
    void (*report_failure)( uint64_t i_status, uint64_t i_partId );

    // Reserve some space for future growth.
    void (*reserved[32])(void);

} hostInterfaces_t;

typedef struct runtimeInterfaces
{
    /** Interface version. */
    uint64_t interfaceVersion;

    /** Execute CxxTests that may be contained in the image.
     *
     *  @param[in] - Pointer to CxxTestStats structure for results reporting.
     */
    void (*cxxtestExecute)(void*);

    /** Get a list of lids numbers of the lids known to HostBoot
     *
     * @param[out] o_num - the number of lids in the list
     * @return a pointer to the list
     */
    const uint32_t * (*get_lid_list)(size_t * o_num);

    /** Load OCC Image and common data into mainstore, also setup OCC BARSs
     *
     * @param[in] i_homer_addr_phys - The physical mainstore address of the
     *                                start of the HOMER image
     * @param[in] i_homer_addr_va - Virtual memory address of the HOMER image
     * @param[in] i_common_addr_phys - The physical mainstore address of the
     *                                 OCC common area.
     * @param[in] i_common_addr_va - Virtual memory address of the common area
     * @param[in] i_chip - XSCOM chip id of processor based on devtree defn
     * @return 0 on success else return code
     */
    int(*occ_load)(uint64_t i_homer_addr_phys,
                  uint64_t i_homer_addr_va,
                  uint64_t i_common_addr_phys,
                  uint64_t i_common_addr_va,
                  uint64_t i_chip);

    /** Start OCC on all chips, by module
     *
     *  @param[in] i_chip - Array of functional processor chip ids
     *                      XSCOM chip id based on devtree defn
     *  @Note The caller must include a complete modules worth of chips
     *  @param[in] i_num_chips - Number of chips in the array
     *  @return 0 on success else return code
     */
    int (*occ_start)(uint64_t* i_chip,
                     size_t i_num_chips);

    /** Stop OCC hold OCCs in reset
     *
     *  @param[in] i_chip - Array of functional processor chip ids
     *                      XSCOM chip id based on devtree defn
     *  @Note The caller must include a complete modules worth of chips
     *  @param[in] i_num_chips - Number of chips in the array
     *  @return 0 on success else return code
     */
    int (*occ_stop)(uint64_t* i_chip,
                    size_t i_num_chips);

    /** Reset OCC upon failure
     *  @param [in]: i_chipId: Id of processor with failing OCC
     *  @return NONE
     */
    void (*occ_error) (uint64_t i_chipId);

    // Reserve some space for future growth.
    void (*reserved[32])(void);

} runtimeInterfaces_t;

#ifdef __HOSTBOOT_RUNTIME
extern hostInterfaces_t* g_hostInterfaces;
runtimeInterfaces_t* getRuntimeInterfaces();
#endif

#endif //__HOSTBOOT_RUNTIME_INTERFACE_VERSION_ONLY
#endif //__RUNTIME__INTERFACE_H
