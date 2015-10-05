/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwas/common/hwasCallout.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
    GARD_Power                  = 0xE9, //Needed since EID is NOT passed in.
    GARD_PHYP                   = 0xEA, //Needed since EID is NOT passed in.
    GARD_Void                   = 0xFF
} GARD_ErrorType;

// from src/epub/fsp/epub_service_codes.H v1.24.24.4
// - Any additions should be added to FipS code first

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
    EPUB_PRC_MEMORY_UE              = 0x4F,
    EPUB_PRC_HB_CODE                = 0x55,
    EPUB_PRC_TOD_CLOCK_ERR          = 0x56,
    EPUB_PRC_COOLING_SYSTEM_ERR     = 0x5C,
};

// from srci/fsp/srci.H
enum callOutPriority
{
    SRCI_PRIORITY_NONE  = 0, //< Invalid externally, but used internally
    SRCI_PRIORITY_LOW   = 1, //< Replace items one at a time in listed order
    SRCI_PRIORITY_MEDC  = 2, //< Replace all items together as a group
    SRCI_PRIORITY_MEDB  = 3, //< Replace all items together as a group
    SRCI_PRIORITY_MEDA  = 4, //< Replace all items together as a group
    SRCI_PRIORITY_MED   = 5, //< Replace items one at a time in listed order
    SRCI_PRIORITY_HIGH  = 6  //< Replace all items together as a group
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

enum clockTypeEnum
{
    TODCLK_TYPE     = 1,
    MEMCLK_TYPE     = 2,
    OSCREFCLK_TYPE  = 3,
    OSCPCICLK_TYPE  = 4,
};


enum partTypeEnum
{
    NO_PART_TYPE                    = 0,
    FLASH_CONTROLLER_PART_TYPE      = 1,
    PNOR_PART_TYPE                  = 2,
    SBE_SEEPROM_PART_TYPE           = 3,
    VPD_PART_TYPE                   = 4,
    LPC_SLAVE_PART_TYPE             = 5,
    GPIO_EXPANDER_PART_TYPE         = 6,
    SPIVID_SLAVE_PART_TYPE          = 7,
};

//
const uint8_t HW_CALLOUT        = 0x01;
const uint8_t PROCEDURE_CALLOUT = 0x02;
const uint8_t BUS_CALLOUT       = 0x03;
const uint8_t CLOCK_CALLOUT     = 0x04;
const uint8_t PART_CALLOUT      = 0x05;

const uint8_t TARGET_IS_SENTINEL = 0xF0;

typedef struct callout_ud
{
    uint8_t             type;
    uint8_t             pad[3];
    callOutPriority     priority;           // uint32_t
    union {
        struct {    // type == HW_CALLOUT
            DeconfigEnum    deconfigState;  // uint32_t
            GARD_ErrorType  gardErrorType;  // uint32_t
            uint32_t        cpuid;
            // one Target will follow
        };
        struct {    // type == PROCEDURE_CALLOUT
            epubProcedureID procedure;      // uint32_t
        };
        struct {    // type == BUS_CALLOUT
            busTypeEnum     busType;        // uint32_t
            // two Targets will follow
        };
        struct {    // type == CLOCK_CALLOUT
            clockTypeEnum   clockType;          // uint32_t
            DeconfigEnum    clkDeconfigState;   // uint32_t
            GARD_ErrorType  clkGardErrorType;   // uint32_t
            // one Target will follow
        };
        struct {    // type == PART_CALLOUT
            partTypeEnum    partType;           // uint32_t
            DeconfigEnum    partDeconfigState;  // uint32_t
            GARD_ErrorType  partGardErrorType;  // uint32_t
            // one Target will follow
        };
    }; // union
} callout_ud_t;

#ifndef PARSER

/**
 *  @brief retrieveTarget will convert the EntityPath to a Target
 *
 *  @param[in]  io_uData pointer to the userdetail data
 *  @param[in]  o_pTarget target that is found
 *  @param[in]  io_errl Error log handle reference
 *
 *  @return     true if error and o_pTarget data not valid,
 *              false no error, o_pTarget data valid
 */
bool retrieveTarget(uint8_t * & io_uData,
                    TARGETING::Target * & o_pTarget,
                    errlHndl_t i_errl);

/**
 *  @brief processCallout process the userdetail for a callout, calling
 *              the deconfigure and/or GARD funcationality as appropriate
 *
 *  @param[in]  io_errl Error log handle reference
 *  @param[in]  i_pData  Pointer to the callout bundle
 *  @param[in]  i_Size  size of the data in the callout bundle
 *  @param[in]  i_DeferredOnly  bool - true if ONLY check for defered deconfig
 *
 */
void processCallout(errlHndl_t &io_errl,
        uint8_t *i_pData,
        uint64_t i_Size,
        bool i_DeferredOnly = false);

// typedef for function pointer that the errlog class will use.
typedef bool (*processCalloutFn)(errlHndl_t &, uint8_t *, uint64_t, bool);

/**
 * @brief platform specific code to handle a procedure callout that has been
 *  found in an errlog
 *
 * @param[in]  io_errl      reference to errlHndl for this errlog.
 * @param[in]  i_procedure  Enum indicating which procedure to add to the
 *                          error log
 * @param[in]  i_priority   Enum indicating the priority of the callout
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error,
 *                          NULL if no errors;
 */
errlHndl_t platHandleProcedureCallout(errlHndl_t &io_errl,
        epubProcedureID i_procedure,
        callOutPriority i_priority);

/**
 * @brief platform specific code to handle a hardware callout that has been
 *  found in an errlog
 *
 * @param[in]  i_pTarget        target
 * @param[in]  i_priority       Enum indicating the priority of the callout
 * @param[in]  i_deconfigState  Enum indicating whether to deconfig or not
 * @param[in]  io_errl          reference to errlHnld for this errlog
 * @param[in]  i_gardErrType    Enum indicating the type of failure
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error,
 *                          NULL if no errors;
 */
errlHndl_t platHandleHWCallout(
        TARGETING::Target *i_pTarget,
        callOutPriority i_priority,
        DeconfigEnum    i_deconfigState,
        errlHndl_t &io_errl,
        GARD_ErrorType  i_gardErrorType);

/**
 * @brief platform specific code to handle a bus callout that has been
 *  found in an errlog
 *
 * @param[in]  i_pTarget1       target endpoint1
 * @param[in]  i_pTarget2       target endpoint2
 * @param[in]  i_busType        bus type Enum
 * @param[in]  i_priority       Enum indicating the priority of the callout
 * @param[in]  io_errl          reference to errlHnld for this errlog
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error,
 *                          NULL if no errors;
 */
errlHndl_t platHandleBusCallout(
        TARGETING::Target *i_pTarget1,
        TARGETING::Target *i_pTarget2,
        busTypeEnum i_busType,
        callOutPriority i_priority,
        errlHndl_t &io_errl);

/**
 * @brief platform specific code to handle a clock callout that has been
 *  found in an errlog
 *
 * @param[in]  i_pTarget        target
 * @param[in]  i_clockType      Enum indicating which type of clock
 * @param[in]  i_priority       Enum indicating the priority of the callout
 * @param[in]  io_errl          reference to errlHnld for this errlog
 * @param[in]  i_deconfigState  Enum indicating whether to deconfig or not
 * @param[in]  i_gardErrType    Enum indicating the type of failure
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error,
 *                          NULL if no errors;
 */
errlHndl_t platHandleClockCallout(
        TARGETING::Target *i_pTarget,
        clockTypeEnum i_clockType,
        callOutPriority i_priority,
        errlHndl_t &io_errl,
        DeconfigEnum    i_deconfigState = DECONFIG,
        GARD_ErrorType  i_gardErrorType = GARD_Fatal);

/**
 * @brief platform specific code to handle a part callout that has been
 *  found in an errlog
 *
 * @param[in]  i_pTarget        associated target
 * @param[in]  i_partType       Enum indicating which type of part
 * @param[in]  i_priority       Enum indicating the priority of the callout
 * @param[in]  io_errl          reference to errlHnld for this errlog
 * @param[in]  i_deconfigState  Enum indicating whether to deconfig or not
 * @param[in]  i_gardErrType    Enum indicating the type of failure
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error,
 *                          NULL if no errors;
 */
errlHndl_t platHandlePartCallout(
        TARGETING::Target *i_pTarget,
        partTypeEnum i_partType,
        callOutPriority i_priority,
        errlHndl_t &io_errl,
        DeconfigEnum    i_deconfigState = DECONFIG,
        GARD_ErrorType  i_gardErrorType = GARD_Fatal);

#endif // not PARSER

};   // end namespace
#endif
