/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/runtime/hdatstructs.H $                               */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
#ifndef __RUNTIME_HDATSTRUCTS_H
#define __RUNTIME_HDATSTRUCTS_H

#include <stdint.h>
#include <vmmconst.h>
#include <string.h>

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
    SPIRAL_LAST             = 24
};

/** @enum hdatSpiraHDataAreas
 *        This enumeration defines the list of N-Tuples within
 *        the SPIRA-H structure
 */
enum hdatSpiraHDataAreas
{
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
    SPIRAS_LAST             = 14
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
#endif
