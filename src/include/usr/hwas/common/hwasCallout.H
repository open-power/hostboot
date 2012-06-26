/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/usr/hwas/common/hwasCallout.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
#ifndef  __HWAS_HWASCALLOUT_H
#define __HWAS_HWASCALLOUT_H
/**
 *  @file hwasCallout.H
 *
 *  HardWare Availability Service Callout prototypes.
 */


/******************************************************************************/
// Includes
/******************************************************************************/
#include <targeting/common/target.H>
#include <errl/errlud.H>

namespace HWAS
{
// from hwsv/server/hwsvTypes.H:
// Legacy HOM deconfig enum
enum DeconfigEnum
{
    NO_DECONFIG,
    DECONFIG,
    DELAYED_DECONFIG,
};

// from gard/fsp/GardExtIntData.H
typedef enum {
    GARD_NULL                   = 0x00,
    GARD_Pending                = 0xE1,
    GARD_PendingCmplt           = 0xEE,
    GARD_Unrecoverable          = 0xE2,
    GARD_Fatal                  = 0xE3,
    GARD_Fabric                 = 0xE4,
    GARD_Computation            = 0xE5,
    GARD_ComputationCmplt       = 0xEC,
    GARD_Predictive             = 0xE6,
    GARD_PredictiveCmplt        = 0xE9,
    GARD_ByAssociation          = 0xE8,
    GARD_ResourceRecovery       = 0xEA,
    GARD_Cmplt                  = 0xEF,
    GARD_Func                   = 0xE7,
    GARD_FuncCmplt              = 0xEB,
    GARD_DmaRecoverable         = 0xE0,
    GARD_DmaUnrecoverable       = 0xED,
    GARD_Tod                    = 0xD0,
    GARD_TodCmplt               = 0xD1,
    GARD_Slb                    = 0xD2,
    GARD_SlbCmplt               = 0xD3,
    GARD_ProcRecoverable        = 0xD4,
    GARD_ProcRecoverableCmplt   = 0xD5,
    GARD_TimeFac                = 0xD6,
    GARD_TimeFacCmplt           = 0xD7,
    GARD_GxBusError             = 0xD8,
    GARD_PowerBusError          = 0xDA,
    GARD_Withheld               = 0xD9,
    GARD_PoreError              = 0xDC,
    GARD_NxError                = 0xDB,
    GARD_Void                   = 0xFF
} GARD_ErrorType;

// from src/epub/fsp/epub_service_codes.H
// nuVersionSID  1.24.14.36                  versionSID    1.24.14.36
    /** @enum epubProcedureID
     *  This enumeration contains all the Procedures to be used with a callout
     *  in an SRC.
     */
enum epubProcedureID
{
    EPUB_PRC_NONE                   = 0x00,
    EPUB_PRC_FIND_DECONFIGURED_PART = 0x01,
    EPUB_PRC_EARLY_TERM             = 0x02,
    EPUB_PRC_USER_ERR               = 0x03,
    EPUB_PRC_SP_CODE                = 0x04,
    EPUB_PRC_PHYP_CODE              = 0x05,
    EPUB_PRC_INT_PROB               = 0x06,
    EPUB_PRC_TOD_PROB               = 0x07,
    EPUB_PRC_ALL_PROCS              = 0x08,
    EPUB_PRC_ALL_MEMCRDS            = 0x09,
    EPUB_PRC_INVALID_PART           = 0x0A,
    EPUB_PRC_RIO_PORTX              = 0x0B,
    EPUB_PRC_DIMM_CONNECTOR         = 0x0C,
    EPUB_PRC_FNM_CODE               = 0x0D,
    EPUB_PRC_WAIT_FOR_PHYP          = 0x0E,
    EPUB_PRC_SMA_CODE               = 0x0F,
    EPUB_PRC_LVL_SUPP               = 0x10,
    EPUB_PRC_SUE_PREVERROR          = 0x11,
    EPUB_PRC_CODE_UPDATE            = 0x12,
    EPUB_PRC_PLUG_COUNT_EXCEED      = 0x13,
    EPUB_PRC_SYSUNIT                = 0x14,
    EPUB_PRC_IOPATH                 = 0x15,
    EPUB_PRC_PROCPATH               = 0x16,
    EPUB_PRC_FIPS_DUMP              = 0x17,
    EPUB_PRC_REBOOT                 = 0x18,
    EPUB_PRC_THERMAL_FAULT          = 0x19,
    EPUB_PRC_BACKPLANE              = 0x1A,
    EPUB_PRC_ATTN_LINE              = 0x1B,
    EPUB_PRC_NO_VPD_FOR_FRU         = 0x1C,
    EPUB_PRC_IOBRIDGE               = 0x1D,
    EPUB_PRC_ANCHOR                 = 0x1E,
    EPUB_PRC_SYSTEM_VPD             = 0x1F,
    EPUB_PRC_ENCLOSURE_VPD          = 0x20,
    EPUB_PRC_SURV_HMC_ERROR         = 0x21,
    EPUB_PRC_MEMORY_PLUGGING_ERROR  = 0x22,
    EPUB_PRC_MEM_SCRUB_REBOOT       = 0x23,
    EPUB_PRC_SMP_CABLE              = 0x24,
    EPUB_PRC_MS_PROC_TIMEOUT        = 0x25,
    EPUB_PRC_JTAG_PATH              = 0x26,
    EPUB_PRC_MNFG_DIMM_ISOLATION    = 0x27,
    EPUB_PRC_LOGAUTH_WARN           = 0x28,
    EPUB_PRC_IIC_BUS_ISOLATION      = 0x29,
    EPUB_PRC_FABRIC_ISOLATION       = 0x2A,
    EPUB_PRC_STATIC_IP              = 0x2B,
    EPUB_PRC_MUX_CARD               = 0x2C,
    EPUB_PRC_FSI_PATH               = 0x2D,
    EPUB_PRC_SERV_PROC              = 0x2E,
    EPUB_PRC_PSI_LINK               = 0x2F,
    EPUB_PRC_PROC_AB_BUS            = 0x30,
    EPUB_PRC_PROC_XYZ_BUS           = 0x31,
    EPUB_PRC_GX_SLOT                = 0x32,
    EPUB_PRC_MEMBUS_REPAIR          = 0x33,
    EPUB_PRC_MEMBUS_ERROR           = 0x34,
    EPUB_PRC_NET_SWITCH             = 0x35,
    EPUB_PRC_OVER_TEMP              = 0x36,
    EPUB_PRC_EIBUS_ERROR            = 0x37,
    EPUB_PRC_CCM_VPD_CARD           = 0x38,
    EPUB_PRC_HOST_ONE_NETWORK       = 0x39,
    EPUB_PRC_NET_CABLE_MISPLUG      = 0x3A,
    EPUB_PRC_NET_DATA_NOT_AVAILABLE = 0x3B,
    EPUB_PRC_MAC_ADDRESS_DUP        = 0x3C,
    EPUB_PRC_INVALID_HUB_CONNECTION = 0x3D,
    EPUB_PRC_MISSING_NODE           = 0x3E,
    EPUB_PRC_POWER_ERROR            = 0x3F,
    EPUB_PRC_NO_LINKS               = 0x40,
    EPUB_PRC_BAD_IP_SUBNET          = 0x41,
    EPUB_PRC_RFSP                   = 0x42,
    EPUB_PRC_STANDBY_POWR           = 0x43,
    EPUB_PRC_FSP_LVL_SUPP           = 0x44,
    EPUB_PRC_BALANCED_MEMORY        = 0x45,
    EPUB_PRC_CHECK_POWR_SRCS        = 0x46,
    EPUB_PRC_BPC_PROC               = 0x47,
    EPUB_PRC_BLADE_LNK_DWN          = 0x48,
    EPUB_PRC_WRAP_PRBS              = 0x49,
    EPUB_PRC_PRBS_SWRAP             = 0x4A,
    EPUB_PRC_INVALID_IP             = 0x4B,
    EPUB_PRC_CCIN_NOT_FOUND         = 0x4C,
    EPUB_PRC_PERFORMANCE_DEGRADED   = 0x4D,
    EPUB_PRC_WKP_FAIL               = 0x4E,
    EPUB_PRC_MEMORY_UE              = 0x4F,
    EPUB_PRC_PLATFORM_CODE          = 0x50,
    EPUB_PRC_MAX
};

// from srci/fsp/srci.H
enum callOutPriority
{
    SRCI_PRIORITY_LOW   = 1,
    SRCI_PRIORITY_MEDC  = 2,
    SRCI_PRIORITY_MEDB  = 3,
    SRCI_PRIORITY_MEDA  = 4,
    SRCI_PRIORITY_MED   = 5,
    SRCI_PRIORITY_HIGH  = 6
};


/**
 *  @brief processCallout process the userdetail for a callout, calling
 *              the deconfigure and/or GARD funcationality as appropriate
 *
 *  @param[in]  i_errlPlid Error log PLID to store in GARD Record.
 *  @param[in]  i_pData  Pointer to the callout bundle
 *  @param[in]  i_Size  size of the data in the callout bundle
 *
 *  @return void
 */
void processCallout(const uint32_t i_errlPlid,
        uint8_t *i_pData,
        uint64_t i_Size);

// typedef for function pointer that the errlog class will use.
typedef void (*processCalloutFn)(const uint32_t, uint8_t *, uint64_t);

//
const uint8_t HW_CALLOUT        = 0x01;
const uint8_t PROCEDURE_CALLOUT = 0x02;

const uint8_t TARGET_IS_SENTINEL = 0xF0;

typedef struct callout_ud
{
    uint8_t             type;
    callOutPriority     priority; // uint8_t
    union {
        struct {    // deconfigure / gard
            DeconfigEnum    deconfigState; // uint8_t
            GARD_ErrorType  gardErrorType; // uint8_t
            uint32_t        cpuid;
        } __attribute__((packed));
        struct {    // callout
            epubProcedureID procedure;  // uint8_t
        } __attribute__((packed));
    };
} __attribute__((packed)) callout_ud_t;


};   // end namespace

#endif
