/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatpcia.H $                                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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
 *  @file hdatpcia.H
 *
 *  @brief This file contains the definition of the Processor Core Information
 *      Area (PCIA) data structure.
 *
 *      A C++ class is defined that is used to update the copy of the PCIA.
 *      The PCIA is written to main memory.
 */

#ifndef HDATPCIA_H
#define HDATPCIA_H

/*----------------------------------------------------------------------------*/
/* Includes                                                                   */
/*----------------------------------------------------------------------------*/
#include <hdat/hdat.H>
#include <errl/errlentry.H>
#include <hdat/hdat_reasoncodes.H>
#include "hdatutil.H"
#include <math.h>

namespace HDAT
{

/*----------------------------------------------------------------------------*/
/* Constants                                                                  */
/*----------------------------------------------------------------------------*/
#define HDAT_NUM_P8_PCIA_ENTRIES        32 * 8

const uint16_t HDAT_PCIA_VERSION    = 0x01;
const char HDAT_PCIA_STRUCT_NAME[7] = "SPPCIA";
const uint32_t HDAT_PROC_STAT_MASK  = 0xC0000000;
const uint8_t  HDAT_DEAD_CORE_MODE_ENABLED = 1;

// Bits in the proc/exist flags for PCIA data
 #define HDAT_EXIST_FLAGS_MASK_FOR_PCIA  0xD0FF0000

/** @enum hdatDataPtrs
 * Enumeration which defines the data sections of the PCIA
 */
enum hdatDataPtrs
{
    HDAT_PCIA_DA_COREDATA       = 0,
    HDAT_PCIA_DA_CPU_TIME_BASE  = 1,
    HDAT_PCIA_DA_CACHE_SIZE     = 2,
    HDAT_PCIA_DA_THREADDATA     = 3,
    HDAT_PCIA_DA_CPU_ATTRIBUTES = 4,
    HDAT_PCIA_DA_CNT            = 5,
    HDAT_PCIA_DA_LAST           = 8
};

/*----------------------------------------------------------------------------*/
/* Type definitions                                                           */
/*----------------------------------------------------------------------------*/

/** @brief This defines the Core unique data section of the PCIA.
 *         Data here is related to processor cores
 */
struct hdatPciaCoreUniqueData_t
{
    uint32_t     reserved_01;          // 0x0000 Reserved.
    uint32_t     pciaFruId;            // 0x0004 FRU ID
    uint32_t     pciaHdwProcId;        // 0x0008 hardware processor ID
    uint32_t     pciaProcStatus;       // 0x000C processor status flags
    uint32_t     pciaChipEcLvl;        // 0x0010 chip EC level
    uint32_t     pciaChipId;           // 0x0014 processor chip ID
    uint32_t     reserved_02;          // 0x0018 Deprecated
    uint32_t     reserved_03;          // 0x001C Deprecated
    uint32_t     reserved_04;          // 0x0020 Reserved
    uint32_t     pciaModuleId;         // 0x0024 module id for the DCM,
                                       //        MCM, QCM, etc.
    hdatMsAddr_t reserved_05;          // 0x0028 Reserved.
    uint32_t     reserved_06;          // 0x0030 Reserved.
    uint32_t     reserved_07;          // 0x0034 Deprecated
    uint32_t     reserved_08;          // 0x0038 Reserved.
    uint32_t     pciaCCMNodeID;        // 0x003C CCM Node ID
    uint32_t     pciaHWCardID;         // 0x0040 HW Card ID
    uint32_t     pciaDrawerNodeID;     // 0x0044 Internal Drawer Node ID
    uint32_t     pciaDBOBID;           // 0x0048 Drawer/Book/Octant/Blade ID
    uint32_t     reserved_09;          // 0x004C Reserved.
    uint32_t     pciaLCOTarget;        // 0x0050 LCO Target.
    uint32_t     reserved_10;          // 0x0054 Reserved.
} __attribute__ ((packed));


/** @brief CPU Time Base portion of the FipS PCIA section
 */
struct hdatPciaCpuTimeBase_t
{
    uint32_t    pciaCycleTime;     // 0x0000 cycle time
    uint32_t    pciaTimeBase;      // 0x0004 time base
    uint32_t    pciaClockSpeed;    // 0x0008 actual clock speed
    uint32_t    pciaMemBusFreq;    // 0x000C memory bus frequency
} __attribute__ ((packed));


/** @brief Cache Size portion of the FipS PCIA section
 */
struct hdatPciaCacheSize_t
{
    uint32_t    pciaICacheSize;         // 0x0000 instruction cache size (in KB)
    uint32_t    pciaICacheLineSize;     // 0x0004 instruction cache line size
                                        //        (in bytes)
    uint32_t    pciaL1DCacheSize;       // 0x0008 L1 data cache size (in KB)
    uint32_t    pciaL1DCacheLineSize;   // 0x000C L1 data cache line size
                                        //        (in bytes)
    uint32_t    pciaL2DCacheSize;       // 0x0010 L2 data cache size (in KB)
    uint32_t    pciaL2DCacheLineSize;   // 0x0014 L2 cache line size (in bytes)
    uint32_t    pciaL3DCacheSize;       // 0x0018 L3 data cache size (in KB)
    uint32_t    pciaL3DCacheLineSize;   // 0x001C L3 cache line size (in bytes)
    uint32_t    pciaDCacheBlkSize;      // 0x0020 data cache block size
                                        //        (in bytes)
    uint32_t    pciaICacheBlkSize;      // 0x0024 instruction cache block size
                                        //        (in bytes)
    uint32_t    pciaDCacheAssocSets;    // 0x0028 number of associativity sets
                                        //        in data cache
    uint32_t    pciaICacheAssocSets;    // 0x002C number of associativity sets
                                        //        in instruction cache
    uint32_t    pciaDTlbEntries;        // 0x0030 number of data TLB entries
    uint32_t    pciaDTlbAssocSets;      // 0x0034 number of associativity sets
                                        //        in data TLB
    uint32_t    pciaITlbEntries;        // 0x0038 number of instruction TLB
                                        //        entries
    uint32_t    pciaITlbAssocSets;      // 0x003C number of associativity sets
                                        //        in instruction TLB
    uint32_t    pciaReserveSize;        // 0x0040 reservation size
    uint32_t    pciaL2AssocSets;        // 0x0044 number of associativity sets
                                        //        in L2
    uint32_t    pciaL3Pt5DCacheSize;    // 0x0048 L3.5 data cache size (in KB)
    uint32_t    pciaL3Pt5DCacheLineSize; // 0x004C L3.5 cache line size
                                        //         (in bytes)
} __attribute__ ((packed));


/** @brief This defines the thread array for each processor core area.
 */
struct hdatPciaThreadArray_t
{
    uint32_t     pciaInterruptLine;    // 0x0000 processor interrupt line.
    uint32_t     pciaPhysThreadId;     // 0x0004 processor thread ID (0,1,...)
    hdatMsAddr_t pciaIbaseAddr;        // 0x0008 IBASE register address.
    uint32_t     pciaProcIdReg;        // 0x0010 processor ID register
} __attribute__ ((packed));


/** @brief This defines the thread specific data section for each
 * processor core.
 */
struct hdatPciaThreadUniqueData_t
{
    uint32_t     pciaThreadOffsetToData;    // 0x0000 Should be fixed at size
                                            //     of this 16 byte header
    uint32_t     pciaThreadNumEntries;      // 0x0004 Number of entries in the
                                            //     thread data array past header
    uint32_t     pciaThreadSizeAllocated;   // 0x0008 Allocated size of array
                                            //     entry in bytes  (will be
                                            //      16 bytes for now)
    uint32_t     pciaThreadSizeActual;      // 0x000C Actual size of each
                                            //      entry in bytes
    hdatPciaThreadArray_t  pciaThreadData[HDAT_MAX_THREADS_SUPPORTED];
                                            // 0x0010 Actual array thread data

} __attribute__ ((packed));


/** @brief CPU Attributes portion of the FipS PCIA section
 */
struct hdatPciaCpuAttributes_t
{
    uint32_t    pciaAttributes;     // 0x0000 bit map of attributes
} __attribute__ ((packed));



/** @brief This defines the PCIA.  FipS updates this
 *         portion and DMAs the entire PCIA back to main memory.
 */
struct hdatSpPcia_t
{
    hdatHDIF_t                  hdatHdr;
    hdatHDIFDataHdr_t           hdatPciaIntData[HDAT_PCIA_DA_LAST];
    hdatPciaCoreUniqueData_t    hdatCoreData;
    hdatPciaCpuTimeBase_t       hdatTime;
    hdatPciaCacheSize_t         hdatCache;
    hdatPciaThreadUniqueData_t  hdatThreadData;
    hdatPciaCpuAttributes_t     hdatAttr;
} __attribute__ ((packed));

/*----------------------------------------------------------------------------*/
/* C++ class definition                                                       */
/*----------------------------------------------------------------------------*/

/** Begin Class Description
 *
 * @brief  The HdatPcia class is used to construct the PCIA object.
 *
 * Description: This class defines a specialized object.  It is not intended
 *      that any component can create an object of this type.
 *      In particular, the object is built only in the
 *      CEC Server process when requested by the hdat component.
 *
 *      The real purpose of the object is to create the PCIA array
 *      structure as defined by the PHYP Initialization architecture.
 *
 * Signal handler usage: This class is not intended to be used in a signal
 *      handler
 *
 * End Class Description
 */
class HdatPcia
{
    public:
    /**
    * @brief Construct an HdatPcia object
    *
    * This is the constructor for the HdatPcia object.
    *
    * @pre None
    *
    * @post An HdatPcia object pointer would be pointing to the host memory
    *       where the data would be directly written on to the memory.
    *       Each PCIA entry is initialized to indicate the processor is not
    *       installed. If the processor is installed, set the status and
    *       supply other information.
    *
    * @param[out] o_errlHndl
    *       If any errors occur, the HdatPcia object is NOT constructed
    *       and errors are returned in this parameter

    * @param[in] i_msAddr
    *       The main memory address that the PCIA structure will be DMA'd to.
    *
    * @return A null error log handle if successful, else the return code
    *       pointed to by o_errlHndl.
    *
    */

    HdatPcia(errlHndl_t &o_errlHndl,
            const hdatMsAddr_t &i_msAddr);
    /**
    * @brief HdatPcia object destructor
    *
    *       This is the destructor for an HdatPcia object.
    *
    * @pre No preconditions exist
    *
    * @post The HdatPcia object has been destroyed and can no longer be used.
    *
    */
    ~HdatPcia();

    /**
    * @brief Load the HdatPcia object
    *
    *       This function is used to the load the HdatPcia object with all the
    *       hdatSpPcia_t structure data. HdatPcia object would be having all
    *       the core data with partial good data which are present and all
    *       the present which are not functional also
    *
    * @param[out] o_size
    *       Size of PCIA object which are written onto Host memory.
    *
    * @param[out] o_count
    *       Count of PCIA objects which are written onto Host memory.
    *
    * @pre HdatPcia Object should be constructed with the main memory address
    *
    * @post The HdatPcia object with all the PCIA entry populated.
    *
    * @return A null error log handle if successful, else the return code
    *       pointed to by o_errlHndl.
    */
    errlHndl_t hdatLoadPcia(uint32_t &o_size, uint32_t &o_count);

    private:

    /** Object instance Data
    *
    * Only one copy of this data exists in a process.
    *
    */

    /* @li iv_msAddr - main memory address the final data structure written */
    hdatMsAddr_t    iv_msAddr;

    /* @li iv_numPciaEntries  - number of PCIA entries*/
    uint32_t        iv_numPciaEntries;  // Number of core entries

    /* @li iv_spPciaEntrySize - size of one entry in PCIA*/
    uint32_t        iv_spPciaEntrySize;  // Size of a PCIA entry

    /* @li iv_spPcia          - pointer to the first PCIA Entry */
    hdatSpPcia_t   *iv_spPcia;

    /**
    * @brief Set the core specific info
    *
    *       This function is an helper function used to the set the core
    *       specific info into the HdatPcia object with for all the
    *       hdatPciaCoreUniqueData_t, hdatPciaCacheSize_t,
    *       hdatPciaCpuAttributes_t structure data.
    *
    * @pre HdatPcia Object should be constructed with the main memory address
    *      Target pointer to the core which is present on the system
    *      Target pointer to the present procs in the system
    *
    * @post The HdatPcia object with all the core related data populated.
    *
    * @param[in] i_index
    *      Index value
    *
    * @param[in] i_pTarget
    *      Core target pointer. Must not be NULL (otherwise call will return an
    *      error log).  Must be a valid target from the system blueprint.
    *
    * @param[in] i_pTarget
    *      Proc target pointer. Must not be NULL (otherwise call will return an
    *      error log).  Must be a valid target from the system blueprint.
    *
    * @param[in] i_dcmNum
    *      DCM Number
    *
    * @return A null error log handle if successful, else the return code
    *       pointed to by o_errlHndl.
    */

    errlHndl_t hdatSetCoreInfo(const uint32_t i_index,
                               const TARGETING::Target* i_pCoreTarget,
                               const TARGETING::Target* i_pProcTarget,
                               const uint8_t i_dcmNum);
};

} //namespace HDAT
#endif // HDATPCIA_H
