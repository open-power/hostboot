/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hdat/hdat.H $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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


/**
 *  @file hdat.H
 *
 *  @brief This file contains constants and typedefs needed by both the hdat
 *      component as well as other components.  They are placed here to avoid
 *      header file circular dependencies.
 *
 *      MAINTENANCE NOTE:  Do not put any functions or methods in this file.
 *      Various components include the header file to get typedefs but do
 *      not want to get bound to the HDAT shared library.
 */

#ifndef HDAT_H
#define HDAT_H

/*----------------------------------------------------------------------------*/
/* Includes                                                                   */
/*----------------------------------------------------------------------------*/
#include <stdint.h>

namespace HDAT
{
/*----------------------------------------------------------------------------*/
/* Type definitions                                                           */
/*----------------------------------------------------------------------------*/

/** @brief Type definition for a 64 bit host memory address.  */
struct hdatMsAddr_t
{
    uint32_t hi;
    uint32_t lo;
}__attribute__ ((packed));

/** @brief Type definition for the common hypervisor Data Interface Format
 * (HDIF) header.    */
struct hdatHDIF_t
{
    uint16_t hdatStructId;      // 0x0000 Structure format ID
    char     hdatStructName[6]; // 0x0002 Structure eye catcher
    uint16_t hdatInstance;      // 0x0008 Instance number
    uint16_t hdatVersion;       // 0x000A Structure version
    uint32_t hdatSize;          // 0x000C Total structure size in bytes
    uint32_t hdatHdrSize;       // 0x0010 Header size in bytes
    uint32_t hdatDataPtrOffset; // 0x0014 Offset to hdatHDIFDataHdr_t
    uint16_t hdatDataPtrCnt;    // 0x0018 Count of hdatHDIFDataHdr_t structures
    uint16_t hdatChildStrCnt;   // 0x001A Count of hdatDIFChildPtr_t structures
    uint32_t hdatChildStrOffset;// 0x001C Offset to child structures array
}__attribute__ ((packed));


/** @brief Type definition for the "pointer" header to the internal data.*/
struct hdatHDIFDataHdr_t
{
    uint32_t hdatOffset;    // 0x0000 Offset from top of structure
    uint32_t hdatSize;      // 0x0004 Data structure size in bytes
}__attribute__ ((packed));


/** @brief Type definition for the data array header.
 * Used when internal data is an array.*/
struct hdatHDIFDataArray_t
{
    uint32_t hdatOffset;    // 0x0000 Offset to array from this structure
    uint32_t hdatArrayCnt;  // 0x0004 Number of array entries
    uint32_t hdatAllocSize; // 0x0008 Size of allocated space for array entry
    uint32_t hdatActSize;   // 0x000C Actual size of an array entry
                            //      (<= hdatAllocSize)
} __attribute__ ((packed));

/** @brief Type definition for a versioned data array header. Used when internal
 *         data is an array and the array data must be versioned
 */
struct hdatHDIFVersionedDataArray_t
{
  uint32_t hdatOffset;     // 0x0000 Offset to array from this structure
  uint32_t hdatArrayCnt;   // 0x0004 Number of array entries
  uint32_t hdatAllocSize;  // 0x0008 Size of allocated space for array entry
  uint32_t hdatActSize;    // 0x000C Actual size of an array entry
  uint32_t hdatVersion;    // 0x0010 Version of the array instance format
} __attribute__ ((packed));

/** @brief Type definition for the 5-tuples that the SPIRA uses to address other
 *         data structures.
 */
struct hdat5Tuple_t
{
    hdatMsAddr_t hdatAbsAddr;       // 0x0000  Absolute address to a structure
    uint16_t     hdatAllocCnt;      // 0x0008  Allocated count
    uint16_t     hdatActualCnt;     // 0x000A  Actual count
    uint32_t     hdatAllocSize;     // 0x000C  Allocated size in bytes
    uint32_t     hdatActualSize;    // 0x0010  Actual size in bytes
    uint32_t     hdatTceOffset;     // 0x0014  Offset to add to TCE for use at
                                    //runtime
    uint8_t      hdatReserved1[8];  // 0x0018  Reserved for future use
} __attribute__ ((packed));


/** @brief Type definition for the "pointer" header to a child data structure**/
struct hdatHDIFChildHdr_t
{
    uint32_t hdatOffset;    // 0x0000 Offset from top of structure
    uint32_t hdatSize;      // 0x0004 Child data structure size in bytes
    uint32_t hdatCnt;       // 0x0008 Count of child data structures
} __attribute__ ((packed));


/** @brief FRU Identification */
struct hdatFruId_t
{
    uint16_t hdatSlcaIdx;       // 0x0000 SLCA index of this FRU
    uint16_t hdatResourceId;    // 0x0002 VPD resource id of this FRU
} __attribute__ ((packed));

/*----------------------------------------------------------------------------*/
/* Constants                                                                  */
/*----------------------------------------------------------------------------*/
extern const int32_t HDAT_SUCCESS;
extern const int32_t HDAT_FAILURE;

/** @brief No children for a data structure*/
extern const uint32_t HDAT_NO_CHILD;

/** @brief Structure id for an HDIF structure*/
extern const uint16_t HDAT_HDIF_STRUCT_ID;

/** @brief FFDC Version to classify data in error log */
extern const uint8_t HDAT_VERSION1;

/** @brief FFDC Sub Version to classify data in error log */
extern const uint8_t HDAT_PCIA_FFDC_SUBSEC;
extern const uint8_t HDAT_NACA_FFDC_SUBSEC1;
extern const uint8_t HDAT_NACA_FFDC_SUBSEC2;

extern const uint32_t HDAT_REAL_ADDRESS_MASK;
extern const uint64_t HDAT_REAL_ADDRESS_MASK64;

/** @brief Align value for HDAT instances */
extern const uint8_t HDAT_HDIF_ALIGN;

// (this goes up to 8 threads on P8)
#define HDAT_MAX_THREADS_SUPPORTED           8
#define HDAT_MAX_EIGHT_THREADS_SUPPORTED     8
#define HDAT_MAX_FOUR_THREADS_SUPPORTED      4

/* @enum hdatProcStatus
 *       Status of a processor FRU.
 */
enum hdatProcStatus
{
  HDAT_PROC_USABLE        = 0x00000000,  // Usable, no failures
  HDAT_PROC_FAILURES      = 0x40000000,  // Usable, failures encountered
  HDAT_PROC_NOT_INSTALLED = 0x80000000,  // Not installed
  HDAT_PROC_NOT_USABLE    = 0xC0000000,  // Unusable
  HDAT_PROC_STAT_BITS     = 0xC0000000,  // constant to and off all bits
                                         //  but 2 status bits
  HDAT_RESERVE_FOR_CCM    = 0x10000000   // reserved for future use
};

/* @enum hdatThreadIndicator
 *       Indicator of primary or secondary thread
 */
enum hdatThreadIndicator
{
    HDAT_PRIM_THREAD    = 0x00000000,  // Primary thread
    HDAT_SEC_THREAD     = 0x20000000,  // Secondary thread
    HDAT_THREAD_IND_BIT = 0x20000000   // For mask operations
};

/* @enum hdatThreadCnt
 *       Number of threads per processor
 */
enum hdatThreadCnt
{
    HDAT_ONE_THREAD     = 0x00000000, // One thread per processor
    HDAT_TWO_THREAD     = 0x00010000, // Two threads per processor
    HDAT_FOUR_THREAD    = 0x00030000, // Four threads per processor
    HDAT_EIGHT_THREAD   = 0x00070000  // Eight  threads per processor
};

struct hdatSpira_t
{
    hdatHDIF_t           hdatHDIF;
    hdatHDIFDataHdr_t    hdatDataHdr;
    uint8_t              hdatReserved1[8];
    hdatHDIFDataArray_t  hdatArrayInfo;
    hdat5Tuple_t         hdatDataArea[24];
}__attribute__ ((packed));

/** @enum List of possible Range Types for Reserved Hostboot Memory (RHB)
 */
enum hdatMsVpdRhbAddrRangeType : uint8_t
{
    RHB_TYPE_PRIMARY         = 0,
    RHB_TYPE_HBRT            = 1,
    RHB_TYPE_VERIFIED_LIDS   = 2,
    RHB_TYPE_SECUREBOOT      = 3,
    RHB_TYPE_HOMER_OCC       = 4,

    RHB_TYPE_INVALID         = 0xFF
};

/* vpd constants
 *      Defining vpd constants
 */
#define FRU_SV 0x1C

} //namespace HDAT
#endif // HDAT_H
