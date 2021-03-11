/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatutil.H $                                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
 * @file hdatutil.H
 *
 * @brief This file contains various utility functions used internally by the
 *        hypervisor data area component.
 */

#ifndef HDATUTIL_H
#define HDATUTIL_H

/*----------------------------------------------------------------------------*/
/* Includes                                                                   */
/*----------------------------------------------------------------------------*/
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <hdat/hdat_reasoncodes.H>
#include <trace/interface.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <hdat/hdat.H>
#include "hdatvpd.H"
#include "hdatbldda.H"
#include <vpd/mvpdenums.H>
#include <vpd/pvpdenums.H>
#include <vpd/spdenums.H>
#include <devicefw/driverif.H>
#include <targeting/common/predicates/predicatectm.H>
#include "../vpd/mvpd.H"
#include "../vpd/ipvpd.H"
#include "../vpd/pvpd.H"
#include <i2c/i2cif.H>
#include <targeting/common/hbrt_target.H>
#include <spi/spi.H>

using namespace MVPD;
using namespace PVPD;
using namespace IPVPD;
using namespace I2C;
using namespace SPI;


/*----------------------------------------------------------------------------*/
/* Constants                                                                  */
/*----------------------------------------------------------------------------*/
const uint16_t HDAT_VERSION1 = 1;
const uint16_t HDAT_VERSION2 = 2;
const uint16_t HDAT_VERSION3 = 3;
#define DBG_MRK "D>"

//initialize the trac buffers
#define HDAT_ENTER()  \
        TRACFCOMP(g_trac_hdat,ENTER_MRK"[%s]",__FUNCTION__);

#define HDAT_EXIT()   \
    TRACFCOMP(g_trac_hdat,EXIT_MRK"[%s]",__FUNCTION__);

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#define AT " [ " __FILE__ " ]:[ " TOSTRING(__LINE__) " ]: "

#define HDAT_ERR( _fmt_, _args_...) \
        TRACFCOMP( g_trac_hdat,ERR_MRK AT _fmt_, ##_args_ );

#define HDAT_DBG( _fmt_, _args_...)  \
        TRACFCOMP( g_trac_hdat,DBG_MRK _fmt_, ##_args_ );

#define HDAT_INF( _fmt_, _args_...)  \
        TRACFCOMP( g_trac_hdat,DBG_MRK _fmt_, ##_args_ );

#define UINT64_HIGH(u) ((u & 0xFFFFFFFF00000000) >> 32)

#define UINT64_LOW(u) (u & 0x00000000FFFFFFFF)

#define HDAT_ADD_PAD(x) x += (16 - ((uint64_t)x % 16))

#define HDAT_NV_KWD_MAGIC_WRD  0x4E563030    // "NV00"
#define NUM_BRICKS_PER_OBUS 3

/**
 * Retrieve the CLASS of the target, or return NA if the target is NULL
 */
#define GETCLASS(pTarget) (((pTarget) == NULL) ? (TARGETING::CLASS_NA) : \
        ((pTarget)->getAttr<TARGETING::ATTR_CLASS>()))

/**
 *  * Retrieve the TYPE of the target, or return NA if the target is NULL
 *   */
#define GETTYPE(pTarget) (((pTarget) == NULL) ? (TARGETING::TYPE_NA) : \
        ((pTarget)->getAttr<TARGETING::ATTR_TYPE>()))


namespace HDAT
{

extern trace_desc_t* g_trac_hdat;

#define HDAT_8BYTE_ACCESS_SUPPORT 0x8000000000000000
#define HDAT_4BYTE_ACCESS_SUPPORT 0x4000000000000000

enum HOST_I2C_DEV_INFO_VERSION : uint32_t
{
    V2 = 0x00000002,
};

/** @brief Defines the Host I2C device info
 */
struct hdatI2cData_t
{
    uint8_t  hdatI2cEngine;
    uint8_t  hdatI2cMasterPort;
    uint16_t hdatI2cBusSpeed;
    uint8_t  hdatI2cSlaveDevType;
    uint8_t  hdatI2cSlaveDevAddr;
    uint8_t  hdatI2cSlavePort;
    uint8_t  hdatReserved1;
    uint32_t hdatI2cSlaveDevPurp;
    uint32_t hdatI2cLinkId;
    uint16_t hdatI2cSlcaIndex;
    char     hdatI2cLabel[64];

}__attribute__ ((packed));

/* @brief Defines the SMP Link info */
struct hdatSMPLinkInfo_t
{
    uint32_t hdatSMPLinkID;
    uint32_t hdatSMPLinkUsage;
    uint32_t hdatSMPLinkBrickID;
    uint32_t hdatSMPLinkLaneMask;
    uint16_t hdatSMPLinkPCISlotIndex;
    uint16_t hdatSMPLinkPCISlotSideBand;
    uint16_t hdatSMPLinkSLCAIndex;
    uint16_t hdatReserved1;
    uint32_t hdatSMPLinkI2cLinkId;
    uint32_t hdatSMPLinkI2cLinkIdPres;
    uint32_t hdatSMPLinkI2cLinkIdMicro;
    uint8_t  hdatSMPLinkSpeed;
    uint8_t  hdatSMPOccRegBitPos;
    uint16_t hdatSMPGPUSlcaIdx;

}__attribute__ ((packed));

enum hdatSMPLinkUsage
{
    HDAT_SMP_LINK_USAGE_SMP         = 0,
    HDAT_SMP_LINK_USAGE_NATIVE_GPU  = 1,
    HDAT_SMP_LINK_USAGE_EXT_IODRW   = 2,
    HDAT_SMP_LINK_USAGE_GPU_TO_GPU  = 3,
    HDAT_SMP_LINK_USAGE_UNKNOWN     = 0xFFFF,
};
enum hdatWitherspoonNVCnfg
{
    HDAT_REDBUD_NV_CNFG             = 1,
    HDAT_SEQUOIA_NV_CNFG            = 2,
};

/** @enum NV Link speeds
  */
enum hdatNVLinkSpeed
{
    HDAT_OBUS_FREQ_20GBPS       = 0,
    HDAT_OBUS_FREQ_25GBPS       = 1,
    HDAT_OBUS_FREQ_25_78125GBPS = 2,
};

/** @brief Structure definition for an entry in the chip's engineering change
 *         level array
 */
struct hdatEcLvl_t
{
    uint32_t hdatChipManfId;  // 0x0000 Chip manufacturing id
    uint32_t hdatChipEcLvl;   // 0x0004 Chip EC level
}  __attribute__ ((packed));

/** @brief Structure defination for an entry in Proc Chip ec level array */
struct hdatProcEcLvlElement_t
{
    hdatEcLvl_t hdatEcLvl;  
    uint64_t    hdatEcid[2]; // Proc ECID
} __attribute__ ((packed));

/** @brief Address range array element information of MMIO regions for OCMB
 *         access by HBRT
 */
struct hdatMsAreaMmioAddrRange_t
{
    hdatMsAddr_t hdatMmioAddrRngStrAddr;    // 0x0000 Range starting address
    hdatMsAddr_t hdatMmioAddrRngEndAddr;    // 0x0008 Range ending address
    uint32_t hdatMmioMemCtlId;              // 0x0010 Memory Controller ID
    uint32_t hdatMmioProcPhyChipId;         // 0x0014 Processor Physical Chip ID
    uint64_t hdatMmioHbrtChipId;            // 0x0018 HBRT Chip ID
    uint64_t hdatMmioFlags;                 // 0x0020 Flags
}  __attribute__ ((packed));

/** @brief Defines the Host SPI device info
 */
struct hdatSpiDevData_t
{
    uint32_t hdatSpiDevId;
    uint8_t  hdatSpiMasterEngine;
    uint8_t  hdatSpiMasterPort;
    uint16_t hdatReserved1;
    uint32_t hdatSpiBusSpeed;
    uint8_t  hdatSpiSlaveDevType;
    uint16_t hdatReserved2;
    uint8_t  hdatReserved3;
    uint32_t hdatSpiDevPurp;
    uint16_t hdatSpiSlcaIndex;
    char     hdatSpiDevStr[64];
}__attribute__ ((packed));

/** @brief Structure for uart interrupt info
*/
struct lockData_t
{
    hdatMsAddr_t hdatScomAddr;
    uint8_t  hdatBitPol;
    uint8_t  hdatIsSticky;
    uint8_t  hdatBitControl;
    uint8_t  hdatReserved1;
}__attribute__ ((packed));

/** @brief Defines the EEPROM partition info
 */
struct hdatEepromPartData_t
{
    uint32_t hdatSpiDevId;
    uint32_t hdatEepmPartDevPurp;
    uint32_t hdatEepmStartOffset;
    uint32_t hdatEepmSize;
    lockData_t hdatWriteLockInfo;
    lockData_t hdatReadLockInfo;

}__attribute__ ((packed));

enum HDAT_FRUType_t
{
     HDAT_SLCA_FRU_TYPE_BP      = 0x00,
     HDAT_SLCA_FRU_TYPE_EV      = 0x01,
     HDAT_SLCA_FRU_TYPE_SV      = 0x02,
     HDAT_SLCA_FRU_TYPE_PROC    = 0x03,
     HDAT_SLCA_FRU_TYPE_MEM     = 0x04,
     HDAT_SLCA_FRU_TYPE_IOP     = 0x05,
     HDAT_SLCA_FRU_TYPE_SP      = 0x06,
     HDAT_SLCA_FRU_TYPE_PS      = 0x07,
     HDAT_SLCA_FRU_TYPE_AM      = 0x08,
     HDAT_SLCA_FRU_TYPE_CU      = 0x09,
     HDAT_SLCA_FRU_TYPE_CE      = 0x0A,
     HDAT_SLCA_FRU_TYPE_OP      = 0x0B,
     HDAT_SLCA_FRU_TYPE_RG      = 0x0C,
     HDAT_SLCA_FRU_TYPE_SA      = 0x0D,
     HDAT_SLCA_FRU_TYPE_EI      = 0x0E,
     HDAT_SLCA_FRU_TYPE_EF      = 0x0F,
     HDAT_SLCA_FRU_TYPE_CS      = 0x10,
     HDAT_SLCA_FRU_TYPE_DIMM    = 0x11,
     HDAT_SLCA_FRU_TYPE_VV      = 0x12,
     HDAT_SLCA_FRU_TYPE_RI      = 0x13,
     HDAT_SLCA_FRU_TYPE_UNKNOWN = 0xFF,
};

/**
 * @brief Create/Build an Error log and add HADT component trace
 * if the log exists then FFDC will be added to the existing log and
 * trace will be collected
 *
 * @param[in,out] io_err    Error handle to use or NULL to create new handle
 * @param[in]     i_modid   Module ID
 * @param[in]     i_rc      Return Code
 * @param[in]     i_data1   User data word 1
 * @param[in]     i_data2   User data word 2
 * @param[in]     i_data3   User data word 3
 * @param[in]     i_data4   User data word 4
 * @param[in]     i_sev     Error severity
 * @param[in]     i_version Data Version identifier for errorlog user details
 * @param[in]     i_commit  true if the log should be committed inside
 *                          the function
 * @param[in]     i_callout Default is true to add software callout info
 */
void hdatBldErrLog(errlHndl_t &   io_err,
                   const uint8_t  i_modid,
                   const uint16_t i_rc,
                   const uint32_t i_data1 = 0,
                   const uint32_t i_data2 = 0,
                   const uint32_t i_data3 = 0,
                   const uint32_t i_data4 = 0,
                   const ERRORLOG::errlSeverity_t i_sev =
                   ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                   const uint16_t i_version =
                   HDAT_VERSION1,
                   const bool i_commit = false,
                   bool i_callout = true);

/**
 * @brief Check whether the supplied Target is functional
 *
 * @param[in] i_pTarget - Target pointer
 *
 * @return bool - Functional state of Target.
 *                functional(TRUE) or not(FALSE).  If an invalid target is
 *                supplied then the interface will commit and will return false.
 *
 */
bool isFunctional( const TARGETING::Target* i_Target);

/**
 * @brief  Get the EC Id and Chip Level for the target
 *
 * @param[in] i_pTarget
 *      Input target pointer. Must not be NULL (otherwise call will return an
 *      error log).  Must be a valid target from the system blueprint.
 *
 * @param[out] o_ecLevel - value of EC level for the target
 * @param[out] o_chipId  - value of Chip id for the target
 *
 * @return errlHndl_t Error log handle indicating the status of the operation
 *      @retval NULL for Success, non NULL for Failure
 *
 */
errlHndl_t hdatGetIdEc(const TARGETING::Target *i_pTarget, uint32_t &o_ecLevel,
                           uint32_t &o_chipId);

/**
 * @brief Get the Hardware Card ID
 *
 * @param[in] i_pTarget
 *      Input target pointer. Must not be NULL (otherwise call will return an
 *      error log).  Must be a valid target from the system blueprint.
 *
 * @param[out] o_cardId - Hardware Card ID
 *
 * @return errlHndl_t Error log handle indicating the status of the operation
 *      @retval NULL for Success, non NULL for Failure
 *
 */
errlHndl_t hdatGetHwCardId(const TARGETING::Target *i_pTarget,
                                                        uint32_t &o_cardId);

/**
 * @brief This routine populates the MTM and Serial number attributes
                           of system Target
 *
 * @pre None
 *
 * @post None
 *
 * @param None
 *
 * @return None
 */
void hdatPopulateMTMAndSerialNumber();

/**
 * @brief This routine gets suffix of location code
 *
 * @pre None
 *
 * @post None
 *
 * @param i_pFruTarget    - input parameter - fru target
 *        i_frutype - fru type
 *        o_locCode - output location code
 *
 * @return None
 */
void hdatGetLocationCode(TARGETING::Target *i_pFruTarget,
                                             HDAT_FRUType_t i_frutype,
                                             char *o_locCode);

/**
 * @brief  Get the ascii keyword for a TARGET
 *
 * @param[in] i_Target input target pointer
 *
 * @param[out]o_kwdSize: keyword size
 * @param[out]o_kwd: key word array
 *
 * @param[in] i_vpdtype: enum vpdType to select the appropriate device address
 * @param[in] i_fetchVpd: relevant structure to be read to fetch the VPD
 * @param[in] i_num: number of elements in the structure
 * @param[in/out] theSize : array containing the size for each keyword
 * @param[in]: i_Keywords : keyword enum to name mapping
 *
 * @return errlHndl_t NULL on success
 */
errlHndl_t hdatGetAsciiKwd(
                           TARGETING::Target * i_target,
                           uint32_t &o_kwdSize,
                           char* &o_kwd,
                           vpdType i_vpdtype,
                           struct vpdData i_fetchVpd[],
                           uint32_t i_num,size_t theSize[],
                           const HdatKeywordInfo i_Keywords[]);

/**
 * @brief  Get the ascii keyword for proc
 *
 * @param[in] i_target input target pointer
 * @param[out]o_kwdSize: keyword size
 * @param[out]o_kwd: key word array
 * @param[in] i_fetchVpd: relevant structure to be read to fetch the VPD
 * @param[in] i_num: number of elements in the structure
 *
 * @return errlHndl_t NULL on success
 *
 */
errlHndl_t hdatGetAsciiKwdForMvpd(
                       TARGETING::Target * i_target,
                       uint32_t &o_kwdSize,
                       char* &o_kwd,
                       struct vpdData i_fetchVpd[],
                       uint32_t i_num,size_t theSize[]);

/**
 * @brief  Get the Full records of passed in vpd type
 *
 * @param[in] i_target input target pointer
 * @param[out]o_kwdSize: keyword size
 * @param[out]o_kwd: key word array
 * @param[in] i_fetchVpd: relevant structure to be read to fetch the VPD
 * @param[in] i_num: number of elements in the structure
 *
 * @return errlHndl_t NULL on success
 *
 */
errlHndl_t hdatGetFullRecords( TARGETING::Target * i_target,uint32_t &o_kwdSize,
           char* &o_kwd,vpdType i_vpdtype,const IpVpdFacade::recordInfo i_fetchVpd[],
                      uint32_t i_num, size_t theSize[]);

/**
 * @brief  Get the ascii keyword for backplane
 *
 * @param[out]o_kwdSize: keyword size
 * @param[out]o_kwd: key word array
 * @param[in] i_fetchVpd: relevant structure to be read to fetch the VPD
 * @param[in] i_num: number of elements in the structure
 * @param[in/out] theSize : array containing the size for each keyword
 * @param[in]: i_Keywords : keyword enum to name mapping
 *
 * @return errlHndl_t NULL on success
 *
 */
errlHndl_t hdatGetAsciiKwdForPvpd(
                       TARGETING::Target * i_target,
                       uint32_t &o_kwdSize,
                       char* &o_kwd,
                       struct vpdData i_fetchVpd[],
                       size_t i_num,size_t theSize[],
                       const HdatKeywordInfo i_Keywords[]);


/**
 * @brief  Get the Full MVPD records post adding start/end tag.
 *         We need to add the tag back, since HB is stripping them off before
 *         storing the vpd records in pnor cache.
 *
 * @param[in] i_target input target pointer
 * @param[out]o_kwdSize: keyword size
 * @param[out]o_kwd: key word array
 * @param[in] i_fetchVpd: relevant structure to be read to fetch the VPD
 * @param[in] i_num: number of elements in the structure
 *
 * @return errlHndl_t NULL on success
 *
 */
errlHndl_t hdatGetMvpdFullRecord(
                       TARGETING::Target * i_target,
                       uint32_t &o_kwdSize,
                       char* &o_kwd,
                       const IpVpdFacade::recordInfo i_fetchVpd[],
                       uint32_t i_num,size_t theSize[]);

/**
 * @brief  Get the Full PVPD records post adding start/end tag.
 *         We need to add the tag back, since HB is stripping them off before
 *         storing the vpd records in pnor cache.
 * @param[out]o_kwdSize: keyword size
 * @param[out]o_kwd: key word array
 * @param[in] i_fetchVpd: relevant structure to be read to fetch the VPD
 * @param[in] i_num: number of elements in the structure
 *
 * @return errlHndl_t NULL on success
 *
 */
errlHndl_t hdatGetPvpdFullRecord(
                       TARGETING::Target * i_target,
                       uint32_t &o_kwdSize,
                       char* &o_kwd,
                       const IpVpdFacade::recordInfo i_fetchVpd[],
                       size_t i_num,size_t theSize[]);

/**
 * @brief  Get the ascii keyword for  dimm
 *
 * @param[in] i_pTarget input target pointer
 *
 * @param[out]o_kwdSize: keyword size
 * @param[out]o_kwd: key word array
 * @return errlHndl_t NULL on success
 *
 */
errlHndl_t hdatGetAsciiKwdForSpd(
                           TARGETING::Target * i_target,
                           size_t&o_kwdSize,
                           char* &o_kwd);
/**
 * @brief Get the Max Cec nde count
 *
 *
 * @return - Number of nodes present
 *
 */
uint32_t hdatGetMaxCecNodes();


/**
 * @brief This routine is a debug routine that prints out the headers associated
 *        with an HDIF data structure.
 *
 * @pre None
 *
 * @post Output is directed to standard out
 *
 * @param[in] i_hdif   - Pointer to data of type hdatHDIF_t
 * @param[in] i_data   - Pointer to data of type hdatHDIFDataHdr_t
 * @param[in] i_dataArray - Pointer to data of type hdatHDIFDataArray_t
 * @param[in] i_child     - Pointer to data of type hdatHDIFChildHdr_t
 *
 */

void hdatPrintHdrs(const hdatHDIF_t *i_hdif,
                     const hdatHDIFDataHdr_t *i_data,
                     const hdatHDIFDataArray_t *i_dataArray,
                     const hdatHDIFChildHdr_t *i_child);

/**
 * @brief This routine is a debug routine that prints out the ASCII keyword VPD
 *
 * @pre None
 *
 * @post Output is directed to standard out
 *
 * @param[in] i_kwd    - Pointer to the ASCII keyword VPD
 * @param[in] i_kwdLen - Length of the ASCII keyword VPD
 *
 */

void hdatPrintKwd(const char *i_kwd,
                     int32_t i_kwdLen);

/**
 * @brief This routine return the target list for the given data area.
 *
 * @pre None
 *
 * @post Output is directed to standard out
 *
 * @param[in] i_dataArea - area that indicates different VPD type
 * @param[out] o_targList - target list
 *
 */
void hdatGetTarget (const hdatSpiraDataAreas i_dataArea,
                        TARGETING::TargetHandleList &o_targList);
/**
 * @brief  Format the ascii keyword based on the HDAT specifiction format
 *
 * @param[in] i_fetchVpd: relevant structure to be read to fetch the VPD
 * @param[in] i_num: number of elements in the structure
 * @param[in] theSize: Size of the each keyword data value
 * @param[in] i_kwd: keyword data array
 * @param[in] i_kwdSize: keyword data size
 * @param[out] o_kwd: format keyword data array
 * @param[out] o_kwdSize: format keyword data size
 * @param[in] i_Keywords : keyword string array
 *
 * @return errlHndl_t NULL on success
 *
 */

errlHndl_t hdatformatAsciiKwd(const struct vpdData i_fetchVpd[],
        const size_t &i_num, const size_t theSize[], char* &i_kwd,
        const uint32_t &i_kwdSize, char* &o_fmtKwd, uint32_t &o_fmtkwdSize,
        const HdatKeywordInfo i_Keywords[]) ;


/**
 * @brief  Get the Full vpd of the target from eeprom
 *
 * @param[in]    i_pTarget    input target pointer
 * @param[in/out]io_dataSize: VPD data size
 * @param[out]   o_data:      VPD data
 * @return errlHndl_t NULL on success
 *
 */
errlHndl_t hdatGetFullEepromVpd ( TARGETING::Target * i_target,
                           size_t &io_dataSize,
                           char* &o_data);

/*******************************************************************************
 * hdatGetI2cDeviceInfo
 *
 * @brief Routine returns the Host I2C device entries
 *
 * @pre None
 *
 * @post None
 *
 * @param[in] i_pTarget
 *       The i2c master target handle
 * @param[in] i_model Target model
 * @param[out] o_i2cDevEntries
 *       The host i2c dev entries
 *
 * @return void
 *
*******************************************************************************/
void hdatGetI2cDeviceInfo(TARGETING::Target* i_pTarget,
    TARGETING::ATTR_MODEL_type  i_model,
    std::vector<hdatI2cData_t>&o_i2cDevEntries);

/*******************************************************************************
 * hdatGetSMPLinkInfo
 *
 * @brief Routine returns the Host SMP Link info entries
 *
 * @pre None
 *
 * @post None
 *
 * @param[in] i_pTarget
 *       The SMP Link  master target handle
 * @param[out] o_SMPLinkEntries
 *       The host SMP Link entries
 *
 * @return void
 *
*******************************************************************************/
void hdatGetSMPLinkInfo(TARGETING::Target* i_pTarget,
    std::vector<hdatSMPLinkInfo_t>&o_SMPLinkEntries);

/******************************************************************************
 * @brief         Updated the smp link info data got from hdat pnor partition
 * @param[in]     i_SMPinfoFullPcrdHdrPtr : SMP info header pointer
 * @param[in/out] io_SMPInfoFullPcrdDataPtr : SMP info data pointer
 * @param[in]     i_pProcTarget : Proc target
 * @return        A null error log handle if successfull, else the return code
 * pointed by o_errlHndl
*******************************************************************************/
errlHndl_t hdatUpdateSMPLinkInfoData(hdatHDIFDataArray_t * i_SMPInfoFullPcrdHdrPtr ,
                                        hdatSMPLinkInfo_t * io_SMPInfoFullPcrdDataPtr,
                                        TARGETING::Target* i_pProcTarget);


/******************************************************************************
 * @brief         get Memory bus frequency of given proc target.
 * @param[in]     i_pTarget     : input Proc target handle
 * @return        Memory bus frequency. upon any error conditions it returns 0.
*******************************************************************************/
uint32_t getMemBusFreq(const TARGETING::Target* i_pTarget);

/******************************************************************************
 * @brief         get Memory bus frequency of given target.
 * @param[in]     i_pTarget     : input target handle
 * @return        Memory bus frequency. upon any error conditions it returns 0.
*******************************************************************************/
uint32_t getMemBusFreqP10(const TARGETING::Target* i_pTarget);

/*******************************************************************************
 * hdatGetMemTargetMmioInfo
 *
 * @brief Routine returns the MMIO entries
 *
 * @pre None
 *
 * @post None
 *
 * @param[in] i_pTarget
 *       The MMIO target handle
 * @param[out] o_mmioEntries
 *       The MMIO entries
 *
 * @return void
 *
*******************************************************************************/
void hdatGetMemTargetMmioInfo(TARGETING::Target* i_pTarget,
     std::vector<hdatMsAreaMmioAddrRange_t>&o_mmioEntries);

/*******************************************************************************
 * hdatGetHostSpiDevInfo
 *
 * @brief Routine returns the host SPI device entries
 *
 * @pre None
 *
 * @post None
 *
 * @param[out] o_spiDevEntries
 *       The SPI device entries
 * @param[out] o_eepromPartEntries
 *       The EEPROM partition entries
 * @param[in]  i_pProcTarget
 *       The Proc target
 *
 * @return void
 *
*******************************************************************************/
void hdatGetHostSpiDevInfo(std::vector<hdatSpiDevData_t>&o_spiDevEntries,
    std::vector<hdatEepromPartData_t>&o_eepromPartEntries,
    TARGETING::Target* i_pProcTarget);

/*******************************************************************************
 * hdatGetPrimaryTopIdIndex
 *
 * @brief Routine returns the five bit primary topology index
 *
 * @pre None
 *
 * @post None
 *
 * @param[in] i_procEffFabricTopoId
 *       Four bit effective topology id
 * @param[in] i_topMod
 *       The topology mode
 *
 * @return uint8_t Five bit primary topology id index
 *
*******************************************************************************/
uint8_t hdatGetPrimaryTopIdIndex(const uint32_t i_procEffFabricTopoId,
   const uint32_t i_topMod);

};// end namespace

#endif // HDATUTILITY_H
