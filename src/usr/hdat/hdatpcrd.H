/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatpcrd.H $                                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
 *  @file hdatpcrd.H
 *
 *  @brief This file contains the definition of the Processor Chip Related
 *      Data structure.
 *
 *      A C++ class is defined that is used to update the copy of the PCRD.
 *      The PCRD is written to main memory.
 */

#ifndef HDATPCRD_H
#define HDATPCRD_H

/*----------------------------------------------------------------------------*/
/* Includes                                                                   */
/*----------------------------------------------------------------------------*/
#include <hdat/hdat.H>
#include <errl/errlentry.H>
#include <hdat/hdat_reasoncodes.H>
#include "hdatutil.H"

namespace HDAT
{

/*----------------------------------------------------------------------------*/
/* Constants                                                                  */
/*----------------------------------------------------------------------------*/

#define HDAT_NUM_P7_PCRD_ENTRIES    32
#define HDAT_FULL_MVPD_SIZE 0x10000
const uint16_t HDAT_PCRD_VERSION    = 0x26;
const char HDAT_PCRD_STRUCT_NAME[7] = "SPPCRD";
#define HDAT_SW_CHKSTP_FIR_SCOM         0x03040100
#define HDAT_SW_CHKSTP_FIR_SCOM_BIT_POS 0x3C

//Max number of I2c devices for any given proc
#define HDAT_PCRD_MAX_I2C_DEV  128
#define HDAT_PCRD_MAX_SMP_LINK 12
#define HDAT_PCRD_MAX_SPI_DEV  8
#define HDAT_PCRD_MAX_EEPROM_PART 24

const uint32_t HOST_SPI_DEV_INFO_VERSION = 0x00000001;
const uint32_t HOST_EEPROM_PART_VERSION = 0x00000001;
const uint32_t HOST_SPI_EEPROM_OFFSET_TO_ARRAY = 0x0014;

/** @enum hdatDataPtrs
 * Enumeration which defines the data sections of the PCRD
 */
enum hdatPcrdDataPtrs
{
    // Values used for PCRD
    HDAT_PCRD_DA_CHIP_INFO      = 0,
    HDAT_PCRD_DA_CHIP_TIMEOFDAY = 1,
    HDAT_PCRD_DA_FRU_ID         = 2,
    HDAT_PCRD_DA_ASCII_KWD      = 3,
    HDAT_PCRD_DA_CHIP_VPD       = 4,
    HDAT_PCRD_DA_HOST_I2C       = 5,
    HDAT_PCRD_DA_PNOR           = 6,
    HDAT_PCRD_DA_SMP            = 7,
    HDAT_PCRD_CHIP_EC_LVL       = 8,
    HDAT_PCRD_DA_HOST_SPI       = 9,
    HDAT_PCRD_DA_EEPROM_PART    = 10,
    HDAT_PCRD_DA_CNT            = 11,
    HDAT_PCRD_DA_LAST           = 12,
};

/*----------------------------------------------------------------------------*/
/* Type definitions                                                           */
/*----------------------------------------------------------------------------*/

/*
 * @brief This defines the Chip Info structure in the PCRD.
 */
struct hdatPcrdChipInfo_t
{
    uint32_t  hdatPcrdProcChipId;       // 0x0000 Processor Chip ID
    uint32_t  hdatPcrdStatusFlags;      // 0x0004 verify/exist flags
    uint32_t  hdatPcrdNxFunctional;     // 0x0008 NX functional
    uint32_t  hdatPcrdPoreFunctional;   // 0x000C Pore functional
    uint32_t  hdatPcrdRealFabricGrpId;  // 0x0010 Real Fabric Group ID
    uint32_t  hdatPcrdEffFabricGrpId;   // 0x0014 Effective Fabric Group ID
    uint32_t  hdatPcrdDbobId;           // 0x0018 Drawer/Book/Octant/Blade ID
                                        //          (DBOB)
    uint32_t  hdatPcrdOccFuncState;     // 0x001C OCC Functional State
    uint32_t  hdatPcrdProcessorFruId;   // 0x0020 Processor FRU ID
    uint32_t  hdatPcrdChipECLevel;      // 0x0024 Chip EC Level
    uint32_t  hdatPcrdHwModuleId;       // 0x0028 Hardware module ID
    uint32_t  hdatPcrdHwCardID;         // 0x002C HW Card ID
    uint32_t  hdatPcrdFabricId;         // 0x0030 Internal Drawer Node ID
                                        //         (Fabric Id)
    uint32_t  hdatPcrdCcmNodeID;        // 0x0034 CCM Node ID
    uint32_t  hdatPcrdCappFunc_unit0;   // 0x0038 Capp functional state unit0
    uint32_t  hdatPcrdCappFunc_unit1;   // 0x003C Capp functional state unit1
    uint32_t  hdatPcrdStopLevelSupport; // 0x0040 Supported Stop Level
    uint32_t  hdatPcrdCheckstopAddr;    // 0x0044 SW Checkstop FIR SCom address
    uint8_t   hdatPcrdSpareBitNum;      // 0x0048 Bit position to set for FIR scom
    uint8_t   hdatPcrdTopologyIdTab
              [sizeof(TARGETING::ATTR_PROC_FABRIC_TOPOLOGY_ID_TABLE_type)];
                                        // 0x0049 Topology ID table
    uint8_t   hdatPcrdTopologyIdIndex;  // 0x0069 index in the topology id array
                                        //        to indicate the primary
                                        //        topology id
    uint32_t  hdatPcrdABCBusSpeed;      // 0x006A A-bus speed
    uint32_t  hdatPcrdXYZBusSpeed;      // 0x007E X-bus speed
    uint8_t   hdatPcrdFabTopologyId;    // 0x0072 Fabric topology id
} __attribute__ ((packed));

/* @brief Defines 'chip time-of-day structure in the PCRD */
struct hdatPcrdChipTod_t
{
    uint32_t  hdatPcrdTodFlags;           // 0x0000 Flags
    uint32_t  hdatPcrdTodControls;        // 0x0004 Time-of-day controls
    uint32_t  hdatPcrdTodControlRegister; // 0x0008 Chip Time-of-day
                                          //        control register
} __attribute__ ((packed));

/* @brief defines PNOR structure in PCRD */
struct hdatPcrdPnor_t
{
    uint8_t hdatPcrdPnorBusType;         //0x0000 bus on which pnor placed
    uint8_t hdatPcrdPnorReserved1[7];    //0x0001 Reserved

    hdatMsAddr_t hdatPcrdPnorBaseAddr;   //0x0008 base addr of pnor device
    uint32_t hdatPcrdPnorSize;           //0x0010 size of pnor addr space
    uint32_t hdatPcrdPnorReserved2;      //0x0014 Reserved

    hdatMsAddr_t hdatPcrdPnorGoldenTOC;  //0x0018 start addr of golden image TOC
    uint32_t hdatPcrdPnorGoldenTOCsize;  //0x0020 KB size of golden image TOC
    uint32_t hdatPcrdPnorReserved3;     //0x0024 Reserved

    hdatMsAddr_t hdatPcrdPnorWorkingTOC; //0x0028 working TOC start addr
    uint32_t hdatPcrdPnorWorkTOCsize;    //0x0030 KB size of working TOC
    uint32_t hdatPcrdPnorReserved4;      //0x0034 Reserved

    hdatMsAddr_t hdatPcrdPnorPsideTOC;   //0x0038 P-side image TOC start addr
    uint32_t hdatPcrdPnorPsideTOCsize;   //0x0040 KB size of P-side TOC
    uint32_t hdatPcrdPnorReserved5;      //0x0044 Reserved

    hdatMsAddr_t hdatPcrdPnorTsideTOC;   //0x0048 T-side TOC start addr
    uint32_t hdatPcrdPnorTsideTOCsize;   //0x0050 T-side TOC size
};


/** @brief Defines the PCRD.
 * FipS updates this portion and DMAs the entire PCRD back to main memory.
 */
struct hdatSpPcrd_t
{
    hdatHDIF_t         hdatHdr;
    hdatHDIFDataHdr_t  hdatPcrdIntData[HDAT_PCRD_DA_LAST];
    hdatPcrdChipInfo_t hdatChipData;
    hdatPcrdChipTod_t  hdatChipTodData;
    hdatFruId_t        hdatFruId;
    char               *hdatKwd;
    uint8_t            *vpd_data;
    hdatPcrdPnor_t     hdatPnorData;
    //add in padding here. uint32_t whatever it is.
} __attribute__ ((packed));

/*----------------------------------------------------------------------------*/
/* C++ class definition                                                       */
/*----------------------------------------------------------------------------*/

/** Begin Class Description
 *
 * @brief  The HdatPcrd class is used to construct the PCRD object.
 *
 * Description: This class defines a specialized object.  It is not intended
 *      that any component can create an object of this type.
 *      In particular, the object is built only in the
 *      CEC Server process when requested by the hdat component.
 *
 *      The real purpose of the object is to create the PCRD array
 *      structure as defined by the PHYP Initialization architecture.
 *
 * Signal handler usage: This class is not intended to be used in a signal
 *      handler
 *
 * End Class Description
 */
class HdatPcrd
{
    public:
    /**
    * @brief Construct an HdatPcrd object
    *
    * This is the constructor for the HdatPcrd object.
    *
    * @pre None
    *
    * @post An HdatPcrd object pointer would be pointing to the host memory
    *       where the data would be directly written on to the memory.
    *       Each PCRD entry is initialized to indicate the processor is not
    *       installed. If the processor is installed, set the status and
    *       supply other information.
    *
    * @param[out] o_errlHndl
    *       If any errors occur, the HdatPcrd object is NOT constructed
    *       and errors are returned in this parameter

    * @param[in] i_msAddr
    *       The main memory address that the PCRD structure will be DMA'd to.
    *
    * @return A null error log handle if successful, else the return code
    *       pointed to by o_errlHndl.
    *
    */

    HdatPcrd(errlHndl_t &o_errlHndl,
            const hdatMsAddr_t &i_msAddr);

    /**
    * @brief HdatPcrd object destructor
    *
    *       This is the destructor for an HdatPcrd object.
    *
    * @pre No preconditions exist
    *
    * @post The HdatPcrd object has been destroyed and can no longer be used.
    *
    */

   ~HdatPcrd();

   /**
    * @brief Load the HdatPcrd object
    *
    *       This function is used to the load the HdatPcrd object with all the
    *       hdatSpPcrd_t structure data. HdatPcrd object would be having all
    *       the processor data which are present and all the present which
    *       are not functional also
    *
    * @param[out] o_size
    *       Size of PCRD object which are written onto Host memory.
    *
    * @param[out] o_count
    *       Count of PCRD objects which are written onto Host memory.
    *
    * @pre HdatPcrd Object should be constructed with the main memory address
    *
    * @post The HdatPcrd object with all the PCRD entry populated.
    *
    * @return A null error log handle if successful, else the return code
    *       pointed to by o_errlHndl.
    */
    errlHndl_t hdatLoadPcrd(uint32_t &o_size, uint32_t &o_count);

    private:

    /** Object instance Data
    *
    * Only one copy of this data exists in a process.
    *
    */

    /* @li iv_msAddr - main memory address the final data structure written */
    hdatMsAddr_t    iv_msAddr;

    /* @li iv_numPcrdEntries  - number of PCRD entries*/
    uint32_t        iv_numPcrdEntries;  // Number of PCRD entries

    /* @li iv_spPcrdEntrySize - size of one entry in PCRD*/
    uint32_t        iv_spPcrdEntrySize;  // Size of a PCRD entry

    /* @li iv_spPcrd          - pointer to the first PCRD Entry */
    hdatSpPcrd_t   *iv_spPcrd;

    /**
    * @brief Set the Processor Chip Related Info
    *
    *       This function is an helper function used to set the processor chip
    *       specific info into the HdatPcrd object with for all the
    *       hdatHDIF_t, hdatHDIFDataHdr_t, hdatPcrdChipInfo_t,
    *       hdatPcrdChipTod_t and module VPD related data into structure data.
    *
    * @pre HdatPcrd Object should be constructed with the main memory address
    *      Target pointer to the present procs in the system
    *
    * @post The HdatPcrd object with all the processor chipd related data
    *      populated.
    *
    * @param[in] i_pTarget
    *      Proc target pointer. Must not be NULL (otherwise call will return an
    *      error log).  Must be a valid target from the system blueprint.
    *
    * @param[in] i_procstatus
    *      Processor status place holder
    *
    * @return A null error log handle if successful, else the return code
    *       pointed to by o_errlHndl.
    */

    errlHndl_t hdatSetProcessorInfo(const TARGETING::Target* i_pProcTarget,
                                        uint32_t i_procstatus);

    /**
     * @brief fetches the pnor data according to the hdat spec
     *
     * @pre HdatPcrd Object should be constructed with the main memory address
     *      Target pointer to the present procs in the system
     *
     * @post the pnor data is populated
     *
     * @param[out] o_pnorData  the pnor data structure
     *
     * @return A null error log handle if successful, else the return code
     *    pointed to by o_errlHndl
     */     
    errlHndl_t fetch_pnor_data( hdatPcrdPnor_t& o_pnorData);
};


} //namespace HDAT
#endif // HDATPCRD_H
