/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/utils/stopreg/p9_stop_section_defines.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

///
/// @file   p9_stop_section_defines.H
/// @brief  defines all constants associated with STOP image layout.
///
// *HWP HW Owner    :  Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner    :  Prem Shanker Jha <premjha2@in.ibm.com>
// *HWP Team        :  PM
// *HWP Level       :  2
// *HWP Consumed by :  HB:HYP

#ifndef _STOP_SECTION_DEFINES_H
#define _STOP_SECTION_DEFINES_H

namespace stopImageSection
{

//basic constants
enum
{
    ONE_KB                  = 1024,
    ONE_MB                  = ONE_KB * ONE_KB,
    TWO_MB                  = 2 * ONE_MB,
    MAX_CORE_SCOM_ENTRIES = 15,
    MAX_NC_SCOM_ENTRIES   = 15,
    MAX_L2_SCOM_ENTRIES   = 16,
    MAX_L3_SCOM_ENTRIES   = 16,
    MAX_CORE_ID_SUPPORTED = 23,
    MAX_THREAD_ID_SUPPORTED = 3,
    MAX_CACHE_SECTN_SIZE_PER_CHIPLET =
        MAX_NC_SCOM_ENTRIES + MAX_L2_SCOM_ENTRIES + MAX_L3_SCOM_ENTRIES,

    // start offset for SPR register restore, core scom or cache scom register
    // restore regions in homer image.
    CORE_SCOM_SECTN_START   = ( TWO_MB + ( 256 * ONE_KB )), //offset from start of chip HOMER
    CACHE_SCOM_SECTN_START  = ( ONE_MB + ( 32 * ONE_KB )), // start of cache section

    //constants in HOMER's header area.
    REGULAR_MODE = 0xAA,
    FUSE_MODE = 0xBB,
    HOMER_MAGIC_WORD = 0x484F4D4552312E30ll,
    CACHE_CHIPLET_ID_MIN = 0x10,
    CACHE_CHIPLET_ID_MAX = 0x15,
    CORE_CHIPLET_ID_MIN  = 0x20,
    CORE_CHIPLET_ID_MAX  = 0x37,
    MAX_SPR_RESTORE_INST = 0x08,
    SIZE_PER_SPR_RESTORE_INST = ((4 * sizeof(uint8_t)) / sizeof(uint32_t)),
};

// all section sizes below are in bytes
enum
{
    SCOM_ENTRY_SIZE         = 16,
    INTERRUPT_HANDLER_SIZE  = 8 * ONE_KB,
    THREAD_LAUNCHER_SIZE    = 256,
    THREAD_RESTORE_SECTN    = 192,
    THREAD_COMPLETION       = 64,
    THREAD_AREA_SIZE        = ONE_KB,
    THREAD_SECTN_SIZE       = THREAD_RESTORE_SECTN + THREAD_COMPLETION,
    CORE_SPR_SECTN_SIZE     = ONE_KB,
    L2_AREA                 = (SCOM_ENTRY_SIZE * MAX_L2_SCOM_ENTRIES),
    L3_AREA                 = (SCOM_ENTRY_SIZE * MAX_L2_SCOM_ENTRIES ),
    NON_CACHE_AREA          = SCOM_ENTRY_SIZE * MAX_NC_SCOM_ENTRIES,
    MAX_SIZE_PER_CORE       = 8 * ONE_KB,
    SPR_RESTORE_PER_CHIP    = ( MAX_SIZE_PER_CORE *
                                ( MAX_CORE_ID_SUPPORTED + 1)) +
                              ( INTERRUPT_HANDLER_SIZE + THREAD_LAUNCHER_SIZE),
    SCOM_SIZE_PER_CORE      = ( MAX_CORE_SCOM_ENTRIES + 1 ) * SCOM_ENTRY_SIZE,
    SCOM_SIZE_PER_CHIP      = SCOM_SIZE_PER_CORE * ( MAX_CORE_ID_SUPPORTED + 1),
    SCOM_SIZE_PER_CACHE_CHIPLET = L2_AREA + L3_AREA + NON_CACHE_AREA
                                  + SCOM_ENTRY_SIZE,
//size in byte ends
};

}//stopImageSection ends

#endif

