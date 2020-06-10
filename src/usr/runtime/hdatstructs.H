/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/runtime/hdatstructs.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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
#ifndef __RUNTIME_HDATSTRUCTS_H
#define __RUNTIME_HDATSTRUCTS_H

#include <stdint.h>
#include <vmmconst.h>
#include <string.h>
#include <hdat/hdat.H>

// Copied from FipS:src/hdat/fsp/hdatnaca.H
// offset in mainstore where NACA starts
const uint64_t HDAT_NACA_OFFSET = 0x00004000;

/* NOTE: Most of these structures were copied and adapted from the HDAT
 component in FipS.  They do not need to be kept exactly in sync so long
 as this code follows the HDAT specification. */

// Copied from FipS:src/hdat/fsp/hdatnaca.H
/** @brief
 *  This type definition defines the Node Address Communication Area (NACA).
 *  The NACA is a data structure used primarily by the host operating
 *  system.  The NACA is prebuilt as part of the primary host LID.  FipS
 *  uses several fields in the NACA to determine where the LID table
 *  and the Service Processor Interace Root Array reside.
 *  Fields which are not used by FipS are just defined as reserved so
 *  that we don't have to chase uninteresting changes the host OS may
 *  make to things FipS does not care about.
 */
struct hdatNaca_t
{
    uint64_t  spiraH;             // 0x0000 Spira-H offset (if non-zero)
    uint8_t  reserved1[40];       // 0x0008 Reserved space
    uint64_t spiraOld;            // 0x0030 Legacy SPIRA offset
    uint8_t  reserved2[104];      // 0x0038 Reserved space
    uint32_t spiraSizeOld;        // 0x00A0 Actual Legacy SPIRA size in bytes
    uint8_t  nacaReserved4[28];   // 0x00A4 reserved space
    uint64_t nacaHypLoadMap;      // 0x00C0 Hyp resident module load map
    uint8_t  nacaReserved5[228];  // 0x00C8 reserved space
    uint8_t  nacaFlags[4];        // 0x01AC Flags to control FSP function.
    uint8_t  nacaReserved6[5];    // 0x01B0 reserved space
    uint8_t  nacaSftAttn;         // 0x01B5 Software attentions enabled
    uint8_t  nacaReserved7[1];    // 0x01B6 Reserved area not for FSP usage
    uint8_t  nacaPhypPciaSupport; // 0x01B7 PHYP supports PCIA format

} __attribute__ ((packed));


// Initially copied from FipS:src/hdat/fsp/hdatspira.H
/** @enum hdatSpiraDataAreas
 *        This enumeration defines the list of N-Tuples within
 *        the LegacySPIRA structure
 */
enum hdatSpiraLegacyDataAreas
{
    SPIRAL_INVALID          = -1,
    SPIRAL_FIRST            = 0,
    SPIRAL_SP_SUBSYS        = 0,    // service processor subsystem
    SPIRAL_IPL_PARMS        = 1,    // IPL parameters
    SPIRAL_ENCLOSURE_VPD    = 2,    // enclosure vital product data
    SPIRAL_SLCA             = 3,    // slot location code array
    SPIRAL_BACKPLANE_VPD    = 4,    // backplane vital product data
    SPIRAL_SYS_VPD          = 5,    // system vital product data
    SPIRAL_CHIP_TOD         = 6,    // chip time-of-day
    SPIRAL_PROC_INIT        = 7,    // phyp-supplied processor init data
    SPIRAL_CLOCK_VPD        = 8,    // clock vital product data
    SPIRAL_ANCHOR_VPD       = 9,    // anchor card vital product data
    SPIRAL_OP_PNL_VPD       = 10,   // operator panel vital product data
    SPIRAL_L3_VPD           = 11,   // level 3 cache vital product data
    SPIRAL_MISC_CEC_VPD     = 12,   // miscellaneous FRU vital product data
    SPIRAL_RSV_1            = 13,   // (old PACA)
    SPIRAL_MDT              = 14,   // memory description tree
    SPIRAL_IO_HUB           = 15,   // I/O hub FRU array
    SPIRAL_CPU_CTRL         = 16,   // CPU controls
    SPIRAL_MS_DUMP_SRC_TBL  = 17,   // mainstore dump source table
    SPIRAL_MS_DUMP_DST_TBL  = 18,   // mainstore dump destination table
    SPIRAL_MS_DUMP_RSLT_TBL = 19,   // mainstore dump results table
    SPIRAL_HEAP             = 20,   // Phyp allocated storage location
    SPIRAL_PCIA             = 21,   // PCIA (Core information area)
    SPIRAL_PCRD             = 22,   // PCRD (Chip related data area)
    SPIRAL_HSVC_DATA        = 23,   // Host Services Data
    SPIRAL_HBRT_DATA        = 24,   // Hostboot Runtime Data
    SPIRAL_IPMI_DATA        = 25,   // IPMI Data
    SPIRAL_TPM_DATA         = 26,   // TPM Node Related Data
    SPIRAL_LAST             = 26
};

/** @enum hdatSpiraHDataAreas
 *        This enumeration defines the list of N-Tuples within
 *        the SPIRA-H structure
 */
enum hdatSpiraHDataAreas
{
    SPIRAH_INVALID          = -1,
    SPIRAH_FIRST            = 0,
    SPIRAH_HOST_DATA_AREAS  = 0,    // Reserved memory for FSP-filled data
    SPIRAH_PROC_INIT        = 1,    // phyp-supplied processor init data
    SPIRAH_CPU_CTRL         = 2,    // CPU controls
    SPIRAH_MS_DUMP_SRC_TBL  = 3,    // mainstore dump source table
    SPIRAH_MS_DUMP_DST_TBL  = 4,    // mainstore dump destination table
    SPIRAH_MS_DUMP_RSLT_TBL = 5,    // mainstore dump results table
    SPIRAH_LAST             = 5
};

/** @enum hdatSpiraSDataAreas
 *        This enumeration defines the list of N-Tuples within
 *        the SPIRA-S structure
 */
enum hdatSpiraSDataAreas
{
    SPIRAS_INVALID          = -1,
    SPIRAS_FIRST            = 0,
    SPIRAS_SP_SUBSYS        = 0,    // service processor subsystem
    SPIRAS_IPL_PARMS        = 1,    // IPL parameters
    SPIRAS_SLCA             = 2,    // slot location code array
    SPIRAS_BACKPLANE_VPD    = 3,    // backplane vital product data
    SPIRAS_SYS_VPD          = 4,    // system vital product data
    SPIRAS_CLOCK_VPD        = 5,    // clock vital product data
    SPIRAS_ANCHOR_VPD       = 6,    // anchor card vital product data
    SPIRAS_OP_PNL_VPD       = 7,    // operator panel vital product data
    SPIRAS_MISC_CEC_VPD     = 9,    // miscellaneous FRU vital product data
    SPIRAS_MDT              = 10,   // memory description tree
    SPIRAS_IO_HUB           = 11,   // I/O hub FRU array
    SPIRAS_PCIA             = 12,   // PCIA (Core information area)
    SPIRAS_PCRD             = 13,   // PCRD (Chip related data area)
    SPIRAS_HSVC_DATA        = 14,   // Host Services Data
    SPIRAS_HBRT_DATA        = 15,   // Hostboot Runtime Data
    SPIRAS_IPMI_DATA        = 16,   // IPMI Data
    SPIRAS_TPM_DATA         = 17,   // Node TPM Related Data
    SPIRAS_LAST             = 17
};


// Copied from FipS:src/hdat/fsp/hdatspira.H
/** @brief Type definition for the 5-tuples that the SPIRA uses to address other
 *         data structures.
 */
struct hdat5Tuple_t
{
  uint64_t     hdatAbsAddr;       // 0x0000  Absolute address to a structure
  uint16_t     hdatAllocCnt;      // 0x0008  Allocated count
  uint16_t     hdatActualCnt;     // 0x000A  Actual count
  uint32_t     hdatAllocSize;     // 0x000C  Allocated size in bytes
  uint32_t     hdatActualSize;    // 0x0010  Actual size in bytes
  uint32_t     hdatTceOffset;     // 0x0014  Offset to add to TCE at runtime
  uint8_t      hdatReserved1[8];  // 0x0018  Reserved for future use
} __attribute__ ((packed));


// Copied from FipS:src/hdat/fsp/hdat.H
/** @brief Type definition for the common hypervisor Data Interface
 *         Format (HDIF) header.
 */
struct hdatHDIF_t
{
  uint16_t hdatStructId;        // 0x0000 Structure format ID
  char     hdatStructName[6];   // 0x0002 Structure eye catcher
  uint16_t hdatInstance;        // 0x0008 Instance number
  uint16_t hdatVersion;         // 0x000A Structure version
  uint32_t hdatSize;            // 0x000C Total structure size in bytes
  uint32_t hdatHdrSize;         // 0x0010 Header size in bytes
  uint32_t hdatDataPtrOffset;   // 0x0014 Offset to hdatHDIFDataHdr_t
  uint16_t hdatDataPtrCnt;      // 0x0018 Count of hdatHDIFDataHdr_t structures
  uint16_t hdatChildStrCnt;     // 0x001A Count of hdatHDIFChildPtr_t structs
  uint32_t hdatChildStrOffset;  // 0x001C Offset to child structures array
} __attribute__ ((packed));


// Copied from FipS:src/hdat/fsp/hdat.H
/** @brief Type definition for the "pointer" header to a child data structure.
 */
struct hdatHDIFChildHdr_t
{
  uint32_t hdatOffset;          // 0x0000 Offset from top of structure
  uint32_t hdatSize;            // 0x0004 Child data structure size in bytes
  uint32_t hdatCnt;             // 0x0008 Count of child data structures
} __attribute__ ((packed));


// Copied from FipS:src/hdat/fsp/hdat.H
/** @brief Type definition for the "pointer" header to the internal data.
 */
struct hdatHDIFDataHdr_t
{
  uint32_t hdatOffset;          // 0x0000 Offset from top of structure
  uint32_t hdatSize;            // 0x0004 Data structure size in bytes
} __attribute__ ((packed));


// Copied from FipS:src/hdat/fsp/hdat.H
/** @brief Type definition for the data array header.  Used when internal
 *         data is an array.
 */
struct hdatHDIFDataArray_t
{
  uint32_t hdatOffset;     // 0x0000 Offset to array from this structure
  uint32_t hdatArrayCnt;   // 0x0004 Number of array entries
  uint32_t hdatAllocSize;  // 0x0008 Size of allocated space for array entry
  uint32_t hdatActSize;    // 0x000C Actual size of an array entry
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

// Originally copied from FipS:src/hdat/fsp/hdatspira.H
/** @brief The SPIRA is composed of an HDIF header and an array.  Each array
 *         entry is an n-tuple.  That is, it is a structure with a particular
 *         number of fields
 */
struct hdatSpira_t
{
  hdatHDIF_t           hdatHDIF;            // 0x0000 Common HDIF header
  hdatHDIFDataHdr_t    hdatDataHdr;         // 0x0020 Data "pointers"
  uint8_t              hdatReserved1[8];    // 0x0028 Padding/future growth
  hdatHDIFDataArray_t  hdatArrayInfo;       // 0x0030 Info on 5-tuple array
  hdat5Tuple_t         hdatDataArea[SPIRAL_LAST]; // 0x0040 5-tuple array
  // At this point, the host OS may have reserved extra space for future growth
  // but FipS does not need to be concerned with the reserved space nor DMA it
  // back from main memory.
} __attribute__ ((packed));


// Copied from FipS:src/hdat/fsp/hdatiplparms.H
/** @brief Structure definition for system model and feature code
 */
struct hdatSysParms_t
{
    uint32_t hdatSysModel;
    uint32_t hdatProcFeatCode;
    uint32_t hdatEffectivePvr;
    uint32_t hdatSysType;
    uint8_t  hdatNumLPARsPerOctant[8];
    uint32_t hdatABCBusSpeed;
    uint32_t hdatWXYZBusSpeed;
    uint32_t hdatSystemECOMode;
    uint32_t hdatSystemAttributes;
    uint32_t hdatMemoryScrubbing;
    uint16_t hdatCurrentSPPLValue;
    uint8_t  hdatPumpMode;
    uint8_t  usePoreSleep;
    uint32_t poreImageSize;
    uint8_t  vTpmEnabled;
    uint8_t  hdatReserved;
    uint16_t hdatDispWheel;
    uint32_t hdatNestFreq;             // Nest Clock Frequency in MHz
    uint8_t  hdatSplitCoreMode;        // Split Core Mode
    uint8_t  hdatFwSecureVersion;      // FW Secure Version
    uint16_t hdatReserved5;            // Reserved
    uint8_t  hdatSystemVendorName[64]; // System Vendor Name
    uint16_t hdatSysSecuritySetting;   // System Security Settings
    uint16_t hdatTpmConfBits;          // TPM Configuration Bits
    uint16_t hdatTpmDrawer;            // TPMs/Drawer
    uint16_t hdatHwKeyHashSize;        // Size of HW Keys' Hash
    uint8_t  hdatHwKeyHashValue[64];   // Hardware Keys Hash Value
    char     hdatSystemFamily[64];     // System Family/Vendor Name
    char     hdatSystemType[64];       // System Type/Vendor Type
} __attribute__ ((packed));


/**
 * @brief Structure used to verify header data
 */
struct hdatHeaderExp_t
{
    uint16_t id;        //<* compare to hdatStructId
    const char* name;   //<* compare to hdatStructName
    uint16_t version;   //<* compare to hdatVersion

    /**
     * @brief Flatten data into a uint64_t
     * @return  [id:16][version:16][name:32]
     */
    const uint64_t flatten( void ) const
    {
        uint64_t retval = id;
        retval <<= 16;
        retval |= version;
        retval <<= 32;
        char* tmp = reinterpret_cast<char*>(&retval);
        memcpy( tmp+4, name, 6 );
        return retval;
     };
};


/**
 * @brief Structure for HBRT Data -- PHYP adjunct partition
 */
struct hdatHBRT_t
{
    char                 hdatStringName[24];    // offset 0x0000
    uint32_t             hdatInstance;          // offset 0x0018
    hdatHDIFDataHdr_t    hdatDataBlob;          // offset 0x001C
    uint8_t              hdatReservedHbrt[12];  // offset 0x0024
} __attribute__ ((packed));


/** @brief Header to array of reserved Hostboot memory address
*/
struct hdatMsReservedMemArrayHeader_t
{
    uint32_t offsetToArray;     //offSet to Address Range Array
    uint32_t arrayEntryCount;   //total number of entries (reserved memSections)
    uint32_t entrySize;         // allotted size of each array entry
    uint32_t actualContentSize; //actual size of array entries
}  __attribute__ ((packed));

/** @brief In Reserved Hostboot Memory address range
*    array element information -
*/
struct hdatMsVpdRhbAddrRange_t
{
    hdatMsVpdRhbAddrRange_t(): hdatRhbRngType(HDAT::RHB_TYPE_INVALID),
                               hdatRhbRngId(0), hdatRhbAddrRngStrAddr(0),
                               hdatRhbAddrRngEndAddr(0), hdatRhbLabelSize(1),
                               hdatRhbLabelString{},
                               hdatRhbPermission(HDAT::RHB_READ_WRITE),
                               reserved{} {}

    /**
     * Set all member variables of class
     * @param[in] i_type, Range type
     * @param[in] i_rangeId, Range ID
     * @param[in] i_startAddr, Range Starting Address
     * @param[in] i_size, Size of memory region
     * @param[in] i_label, Label String Ptr
     * @param[in] i_permission, R/W permissions for RHB.
     * @note size of i_label is calculated in function versus a input parameter.
     */
    void set(const HDAT::hdatMsVpdRhbAddrRangeType i_type,
             const uint16_t i_rangeId, const uint64_t i_startAddr,
             const uint64_t i_endAddr, const char* i_label,
             const HDAT::hdatRhbPermType i_permission = HDAT::RHB_READ_WRITE);

    HDAT::hdatMsVpdRhbAddrRangeType hdatRhbRngType; // 0x0000 Range type
    uint8_t  hdatRhbRngRes;            // 0x0001 Reserved
    uint16_t hdatRhbRngId;             // 0x0002 Range ID
    uint64_t hdatRhbAddrRngStrAddr;    // 0x0004 Range starting
    uint64_t hdatRhbAddrRngEndAddr;    // 0x000C Range ending
    uint32_t hdatRhbLabelSize;         // 0x0014 Label size
    uint8_t  hdatRhbLabelString[64];   // 0x0018 Label string Ptr
    HDAT::hdatRhbPermType hdatRhbPermission; // 0x0058 R/W Permissions
    uint8_t  reserved[7];              // 0x0059 Reserved
}  __attribute__ ((packed));

// Supported versions
enum hbHypCommAreaVersionInfo {
    STRUCT_VERSION_FIRST  = 0x1,
    STRUCT_VERSION_LATEST = 0x1,
};

// Size of supported versions - must be 8-byte aligned
const size_t  HB_HYP_COMM_STRUCT_SIZES[STRUCT_VERSION_LATEST+1]
{
    0,
    32,  // ver1: size of struct is 32 bytes
};

// Magic number for hbHypCommArea (ASCII = "HYPECOMM")
const uint64_t HYPECOMM_MAGIC_NUM = 0x48595045434f4d4d;

// Number of bytes into struct for HRMOR address
// (offset to start of data in hbHypCommArea_t struct)
const uint8_t  HYPCOMM_STRUCT_HRMOR_OFFSET = 24;


//Note when adding data to this make sure to add at the bottom
//and keep this struct 8 byte aligned
// We never want to change the format of the first 24 bytes of this struct
struct hbHypCommArea_t
{
    uint64_t magicNum;          // 8 bytes 0x48595045434f4d4d = HYPECOMM
    size_t   size;              // 8 bytes
    uint32_t version;           // 4 bytes keep track of version so we can set the size correctly
    uint8_t padding[4];         // 4 bytes put padding in so hrmor is 8 byte aligned
    //Start Data                // 0x18 or 24 byte offset to data
    //
    //The space allocated for HRMOR address can be written to by the hypervisor
    //in the event that the hypervisor changes its hrmor. This will allow
    //hostboot to know where to load the payload on MPIPL.
    uint64_t hrmorAddress;      // 8 bytes

    //Total = 32 bytes
    hbHypCommArea_t(): magicNum(HYPECOMM_MAGIC_NUM), size(HB_HYP_COMM_STRUCT_SIZES[STRUCT_VERSION_LATEST]),
                       version(STRUCT_VERSION_LATEST), padding{0,0,0,0}, hrmorAddress(0)
    {
    }
} PACKED;

/** @brief The fields in the CPU Controls Legacy structure are a set of
 *         address / length pairs as shown below
 */
struct hdatCpuCtrlPair_t
{
    uint64_t address;    // 0x0000 Absolute main store adress relative to HRMOR
    uint64_t size;       // 0x0008 Data structure size in bytes
}__attribute__ ((packed));

/** @brief CPU Controls Legacy Structure pointed to by the CPU Controls Header
 *         Area pointer in the CPU Controls
 */
struct hdatCpuCtrlInfo_t
{
    hdatCpuCtrlPair_t spAddrTable;       // SP Address Table (SPAT)
    hdatCpuCtrlPair_t spAttnArea1;       // SP Attention Area 1
    hdatCpuCtrlPair_t spAttnArea2;       // SP Attention Area 2
    hdatCpuCtrlPair_t servRoutineData;   // Service Routines Data Area
}  __attribute__ ((packed));

#endif
