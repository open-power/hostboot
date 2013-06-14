/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwas/common/hwasCallout.H $                   */
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
#ifndef PARSER
#include <targeting/common/target.H>
#endif // not PARSER

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

typedef enum {
    GARD_NULL                   = 0x00,
    GARD_User_Manual            = 0xD2, //Manual Guard.
    GARD_Unrecoverable          = 0xE2, //TODO:RTC-76814
    GARD_Fatal                  = 0xE3, //IPL Failures, and others.
    GARD_Predictive             = 0xE6, //Policy flag to disable.
    GARD_Func                   = 0xE7, //Policy flag to disable.
    GARD_Power                  = 0xE9, //Needed since PLID is NOT passed in.
    GARD_PHYP                   = 0xEA, //Needed since PLID is NOT passed in.
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
    EPUB_PRC_SP_CODE                = 0x04,
    EPUB_PRC_PHYP_CODE              = 0x05,
    EPUB_PRC_ALL_PROCS              = 0x08,
    EPUB_PRC_ALL_MEMCRDS            = 0x09,
    EPUB_PRC_INVALID_PART           = 0x0A,
    EPUB_PRC_LVL_SUPP               = 0x10,
    EPUB_PRC_PROCPATH               = 0x16,
    EPUB_PRC_NO_VPD_FOR_FRU         = 0x1C,
    EPUB_PRC_MEMORY_PLUGGING_ERROR  = 0x22,
    EPUB_PRC_FSI_PATH               = 0x2D,
    EPUB_PRC_PROC_AB_BUS            = 0x30,
    EPUB_PRC_PROC_XYZ_BUS           = 0x31,
    EPUB_PRC_MEMBUS_ERROR           = 0x34,
    EPUB_PRC_EIBUS_ERROR            = 0x37,
    EPUB_PRC_POWER_ERROR            = 0x3F,
    EPUB_PRC_PERFORMANCE_DEGRADED   = 0x4D,
    EPUB_PRC_HB_CODE                = 0x51
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

enum busTypeEnum
{
    FSI_BUS_TYPE    = 1,
    DMI_BUS_TYPE    = 2,
    A_BUS_TYPE      = 3,
    X_BUS_TYPE      = 4,
    I2C_BUS_TYPE    = 5,
    PSI_BUS_TYPE    = 6
};

//
const uint8_t HW_CALLOUT        = 0x01;
const uint8_t PROCEDURE_CALLOUT = 0x02;
const uint8_t BUS_CALLOUT       = 0x03;

const uint8_t TARGET_IS_SENTINEL = 0xF0;

typedef struct callout_ud
{
    uint8_t             type;
    uint8_t             pad[3];
    callOutPriority     priority; // uint32_t
    union {
        struct {    // deconfigure / gard
            DeconfigEnum    deconfigState; // uint32_t
            GARD_ErrorType  gardErrorType; // uint32_t
            uint32_t        cpuid;
        };
        struct {    // callout
            epubProcedureID procedure;  // uint32_t
        };
        struct {
            busTypeEnum     busType;
        };
    };
} callout_ud_t;

#ifndef PARSER

/**
 *  @brief processCallout process the userdetail for a callout, calling
 *              the deconfigure and/or GARD funcationality as appropriate
 *
 *  @param[in]  i_errl Error log handle
 *  @param[in]  i_pData  Pointer to the callout bundle
 *  @param[in]  i_Size  size of the data in the callout bundle
 *  @param[in]  i_DeferredOnly  bool - true if ONLY check for defered deconfig
 *
 */
void processCallout(errlHndl_t i_errl,
        uint8_t *i_pData,
        uint64_t i_Size,
        bool i_DeferredOnly = false);

// typedef for function pointer that the errlog class will use.
typedef bool (*processCalloutFn)(errlHndl_t, uint8_t *, uint64_t, bool);

/**
 * @brief platform specific code to handle a procedure callout that has been
 *  found in an errlog
 *
 * @param[in]  i_errl       errlHndl for this errlog.
 * @param[in]  i_procedure  Enum indicating which procedure to add to the
 *                          error log
 * @param[in]  i_priority   Enum indicating the priority of the callout
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error,
 *                          NULL if no errors;
 */
errlHndl_t platHandleProcedureCallout(errlHndl_t i_errl,
        epubProcedureID i_procedure,
        callOutPriority i_priority);

/**
 * @brief platform specific code to handle a hardware callout that has been
 *  found in an errlog
 *
 * @param[in]  i_pTarget        target
 * @param[in]  i_priority       Enum indicating the priority of the callout
 * @param[in]  i_deconfigState  Enum indicating whether to deconfig or not
 * @param[in]  i_errl           errlHnld for this errlog
 * @param[in]  i_gardErrType    Enum indicating the type of failure
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error,
 *                          NULL if no errors;
 */
errlHndl_t platHandleHWCallout(
        TARGETING::Target *i_pTarget,
        callOutPriority i_priority,
        DeconfigEnum    i_deconfigState,
        errlHndl_t i_errl,
        GARD_ErrorType  i_gardErrorType);

/**
 * @brief platform specific code to handle a bus callout that has been
 *  found in an errlog
 *
 * @param[in]  i_pTarget1       target endpoint1
 * @param[in]  i_pTarget2       target endpoint2
 * @param[in]  i_busType        bus type Enum
 * @param[in]  i_priority       Enum indicating the priority of the callout
 * @param[in]  i_errl           errlHnld for this errlog
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error,
 *                          NULL if no errors;
 */
errlHndl_t platHandleBusCallout(
        TARGETING::Target *i_pTarget1,
        TARGETING::Target *i_pTarget2,
        busTypeEnum i_busType,
        callOutPriority i_priority,
        errlHndl_t i_errl);

#endif // not PARSER

};   // end namespace

#endif
