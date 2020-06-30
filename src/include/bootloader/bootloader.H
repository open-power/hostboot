/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/bootloader/bootloader.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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

#ifndef __BOOT_LOADER_H
#define __BOOT_LOADER_H

/**
 * @file    bootloader.H
 *
 *  TaskInfo structs for each task that will run.
 */

#include <builtins.h>
#include <pnor_const.H>
#include <pnor_utils.H>
#include <common/ffs_hb.H>
#include <kernel/terminate.H>
#include <kernel/hbterminatetypes.H>
#include <bootloader/bootloaderif.H>
#include <bootloader/bootloader_trace.H>
#include <bootloader/bootloader_data.H>
#include <bootloader/hbblreasoncodes.H>

extern "C" void task_end_stub();
extern "C" void enterHBB(uint64_t i_hbb_hrmor, uint64_t i_hbb_offset);

#define printk(format...)

 /**
  * @brief Handle setting up to terminate Bootloader
  *
  * @param[in] i_moduleID    ID for module where terminate is occurring
  * @param[in] i_reasoncode  Reason code for why terminating
  * @param[in] i_word7       Data for SRC word 7 / @userdata2[0:31]
  *                             (optional, default is 0)
  * @param[in] i_word8       Data for SRC word 8 / @userdata2[32:63]
  *                             (optional, default is 0)
  * @param[in] i_executeTI   Flag for calling terminateExecuteTI
  *                             (optional, default is true)
  * @param[in] i_failAddr    Address associated with termination
  *                             (SRC word 6 / @userdata1[32:63],
  *                              optional, default is 0)
  * @param[in] i_error_info  Optional error data to go in the TI
  *                             data area
  * */
void bl_terminate(uint8_t  i_moduleID,
                  uint16_t i_reasoncode,
                  uint32_t i_word7 = 0,
                  uint32_t i_word8 = 0,
                  bool     i_executeTI = true,
                  uint64_t i_failAddr = 0,
                  uint32_t i_error_info = 0);


/**
 * @brief Macro to assert using bl_terminate
 *
 * Calls bl_terminate with default module id and reason code for assert
 */
#define __ASSERT() \
{\
    bl_terminate(Bootloader::MOD_BOOTLOADER_ASSERT,Bootloader::RC_ASSERT);\
}

/**
 * @brief Macro to assert with custom trace
 *
 * Calls Bootloader trace and assert macro
 */
#define __ASSERT_W_TRACE(trace) \
{ \
    BOOTLOADER_TRACE(trace);\
    __ASSERT();\
}

/**
 * @brief Macro to assert using bl_terminate with custom trace and reason code.
 *
 * Calls Bootloader trace and provides a custom reason code to bl_terminate
 */
#define __ASSERT_W_TRACE_RC(trace,rc) \
{ \
    BOOTLOADER_TRACE(trace);\
    bl_terminate(Bootloader::MOD_BOOTLOADER_ASSERT, rc);\
}


// Macro tricks to determine which assert macro to call
#define GET_MACRO(_1,_2,_3,FUNC,...) FUNC

/**
 * @brief Standard assert macro.
 *
 * Verifies condition, uses GET_MACRO to determine which assert macro to call.
 * Supports asserting via bl_terminate with custom trace and/or reason code
 */
#define assert(expr, ...) \
{\
    if(unlikely(!(expr))) \
    {\
        GET_MACRO(0, ##__VA_ARGS__, __ASSERT_W_TRACE_RC, __ASSERT_W_TRACE, __ASSERT)(__VA_ARGS__) \
    }\
}

namespace Bootloader{
    /**
     * @brief Get the current HBBL HRMOR
     *
     * Used to know where the bootloader is running
     */
    ALWAYS_INLINE
      inline uint64_t getHRMOR()
    {
        register uint64_t hrmor = 0;
        asm volatile("mfspr %0, 313" : "=r" (hrmor));
        return hrmor;
    }


     /**Core Scratch Register 3 which tells the state of hostboot.
        This is passed into writeScratchReg to select which scratch
        reg you are writing */
#define MMIO_SCRATCH_HOSTBOOT_ACTIVE          0x18

    /**
     * @brief Pointer to bootloader scratch space
     *
     * Pointer to location in main storage which bootloader uses as
     * scratch space
     */
    extern uint8_t *g_blScratchSpace;

    /** @enum MMIOLoadStoreSizes
     *  @brief List of MMIO Load and Store Sizes.
     *
     *  These are the sizes (in bytes) for the load and store commands used
     *  to read and write data when handling an MMIO.
     */
    enum MMIOLoadStoreSizes
    {
        /** BYTESIZE */
        BYTESIZE = 1,
        /** WORDSIZE */
        WORDSIZE = 4,
        /** DBLWORDSIZE */
        DBLWORDSIZE = 8
    };

    /**
     * @brief Handle MMIO to copy code/data from one location to another
     *
     * @param[in] i_srcAddr     MMIO address to copy from
     * @param[in] i_destAddr    address to copy to
     * @param[in] i_size        number of bytes to copy
     * @param[in] i_ld_st_size  size of data in ld and st instructions
     *        BYTESIZE     => copy 1 byte at a time
     *        WORDSIZE     => copy 4 bytes at a time
     *        DBLWORDSIZE  => copy 8 bytes at a time
     */
    extern void handleMMIO(uint64_t i_srcAddr,
                           uint64_t i_destAddr,
                           uint32_t i_size,
                           MMIOLoadStoreSizes i_ld_st_size);

    /** @enum HbbLengths
     *  @brief List of HBB lengths.
     *
     *  These are the lengths of the Hostboot Base data or instructions
     *  with and without ECC.
     */
    enum HbbLengths
    {
        /** LENGTH_WO_ECC */
        LENGTH_WO_ECC = 8,
        /** LENGTH_W_ECC */
        LENGTH_W_ECC = 9
    };

    /**
     *  @brief List of addresses where HBB and HBBL code is stored.
     *
     *  These specify locations where the Hostboot Bootloader code is
     *  stored and where it stores the Hostboot Base code.  The HBB code
     *  is copied to various locations as the HBBL works with it.  Then
     *  HBB is copied to its running location and its execution is started.
     */

    /** HW Keys hash is placed in the last 64 bytes of the HBBL */
#define HW_KEYS_HASH_ADDR (getHRMOR() + HBBL_EXCEPTION_VECTOR_SIZE \
                           + MAX_HBBL_SIZE - 64)

    /** FW Secure Version is placed in byte before HW_KEYS_HASH_ADDR */
#define SECURE_VERSION_ADDR (HW_KEYS_HASH_ADDR-1)

    /** Location of working copy of HBB with ECC */
#define HBB_ECC_WORKING_ADDR    (getHRMOR() - ( 1*MEGABYTE))

    /** Location of working copy of HBB without ECC */
#define HBB_WORKING_ADDR        (getHRMOR() + ( 1*MEGABYTE))

    /** Location of HBBL data */
#define HBBL_DATA_ADDR          (getHRMOR() + HBBL_EXCEPTION_VECTOR_SIZE \
                                 + MAX_HBBL_SIZE)

    /** Location of HBBL scratch space */
#define HBBL_SCRATCH_SPACE_ADDR (getHRMOR() + (64*KILOBYTE))

    /** Location of SBE HB communication area
        Defined in SBE code and bootloader.ld */
#define SBE_HB_COMM_ADDR        (getHRMOR() + 0x4)

    enum
    {
        /** Offset for starting running copy of HBB */
        HBB_RUNNING_OFFSET = 0,
        /** Mask to indicate HRMOR should be ignored for the address */
        IGNORE_HRMOR_MASK = 0x8000000000000000ul
    };
} // end namespace Bootloader

#endif
