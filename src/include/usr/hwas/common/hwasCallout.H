/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwas/common/hwasCallout.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
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
#if !defined(PARSER) && !defined(LOGPARSER)
#include <targeting/common/target.H>
#endif // not LOGPARSER

// The following enums are used in src/build/tools/ebmc/hwasCallout.py
// Any changes to these enums should also be reflected there.

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
    GARD_Reconfig               = 0xEB, //deconfig on reconfig loop
    GARD_Sticky_deconfig        = 0xEC, //Force deconfig on reconfig loop, not availible for resource recovery
                                        //set/created when ATTR_BLOCK_SPEC_DECONFIG is set
    GARD_Void                   = 0xFF
} GARD_ErrorType;

// Used in EPUB_PRC_INVALID_PART
// userdata 3 of the SRC
enum ErrorCategory {
    ERR_CATEGORY_INVALID_SERIAL = 0x01,
    ERR_CATEGORY_INVALID_PART = 0x02,
};

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
    ///< Look for other logs that include deconfigurations

    EPUB_PRC_SP_CODE                = 0x04,
    ///< Problem is in SP/BMC code, upgrade your firmware

    EPUB_PRC_PHYP_CODE              = 0x05,
    ///< Problem is in Hypervisor/Host code, upgrade your firmware

    EPUB_PRC_ALL_PROCS              = 0x08,
    ///< Any processor could be at fault, manual isolation is required

    EPUB_PRC_ALL_MEMCRDS            = 0x09,
    ///< Any memory card could be at fault, manual isolation is required

    EPUB_PRC_INVALID_PART           = 0x0A,
    ///< Unsupported part was installed

    EPUB_PRC_LVL_SUPP               = 0x10,
    ///< Isolation not possible, please contact your next level of support

    EPUB_PRC_SUE_PREVERROR          = 0x11,
    ///< Unrecoverable event occurred, look for previous errors for the cause

    EPUB_PRC_PROCPATH               = 0x16,
    ///< Problem is somewhere in the service control structure to the processor

    EPUB_PRC_NO_VPD_FOR_FRU         = 0x1C,
    ///< No VPD found for the specified FRU(s)

    EPUB_PRC_MEMORY_PLUGGING_ERROR  = 0x22,
    ///< Memory was installed incorrectly, look at callouts for clues on the
    ///<   parts that may be at fault

    EPUB_PRC_FSI_PATH               = 0x2D,
    ///< Problem is somewhere in the FSI bus path

    EPUB_PRC_PROC_AB_BUS            = 0x30,
    ///< Problem is on the SMP bus, could not be isolated to a specific part,
    ///<   Callouts will indicate the endpoints that are involved

    EPUB_PRC_PROC_XYZ_BUS           = 0x31,
    ///< Problem is on the SMP bus, could not be isolated to a specific part,
    ///<   Callouts will indicate the endpoints that are involved

    EPUB_PRC_MEMBUS_ERROR           = 0x34,
    ///< Problem is on the memory bus, could not be isolated to a specific part,
    ///<   Callouts will indicate the endpoints that are involved

    EPUB_PRC_EIBUS_ERROR            = 0x37,
    ///< Problem is on a bus, could not be isolated to a specific part,
    ///<   Callouts will indicate the endpoints that are involved

    EPUB_PRC_MULTINODE_CHECKSTOP    = 0x3D,
    ///< Possible checkstop caused communication problem between drawers.

    // Only used on FSP systems
#if defined(CONFIG_FSP_BUILD) || !defined(CONFIG_BUILD_FULL_PEL)
    EPUB_PRC_POWER_ERROR            = 0x3F,
    ///< Problem is related to the power subsystem
#endif

    // Only used on FSP systems
#if defined(CONFIG_FSP_BUILD) || !defined(CONFIG_BUILD_FULL_PEL)
    EPUB_PRC_PERFORMANCE_DEGRADED   = 0x4D,
    ///< System is running in a degraded performance mode,
    ///<   Look for previous errors for possible reasons
#endif

    EPUB_PRC_MEMORY_UE              = 0x4F,
    ///< Unrecoverable memory error occurred
    ///<  Look for previous errors for the cause

    EPUB_PRC_HB_CODE                = 0x55,
    ///< Problem is in Hostboot code, upgrade your firmware

    EPUB_PRC_TOD_CLOCK_ERR          = 0x56,
    ///< Problem is related to the TOD clock

    // Only used on FSP systems
#if defined(CONFIG_FSP_BUILD) || !defined(CONFIG_BUILD_FULL_PEL)
    EPUB_PRC_COOLING_SYSTEM_ERR     = 0x5C,
    ///< Problem is related to the cooling subsystem
#endif

    EPUB_PRC_FW_VERIFICATION_ERR    = 0x5D,
    ///< Verification of one or more firmware images failed,
    ///<   Reinstall your firmware

    EPUB_PRC_SBE_CODE               = 0x62,
    ///< Problem is in SBE code, upgrade your firmware
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
    A_BUS_TYPE      = 3,
    X_BUS_TYPE      = 4,
    I2C_BUS_TYPE    = 5,
    PSI_BUS_TYPE    = 6,
    O_BUS_TYPE      = 7,
    OMI_BUS_TYPE    = 8,
};

// Used by Hostboot code where real clock targets do not exist
enum clockTypeEnum
{
    // Specify a generic clock source in the event that the calling code is
    //  unable to determine which of the redundant sources are currently
    //  configured as active
    TODCLK_TYPE     = 1,
    MEMCLK_TYPE     = 2,
    OSCREFCLK_TYPE  = 3,
    OSCPCICLK_TYPE  = 4,

    // Specify a specific clock source for the case where the code can determine
    //  which of the redundant sources is actually at fault
    OSCREFCLK0_TYPE =  8, //Specifically clock 0
    OSCREFCLK1_TYPE =  9, //Specifically clock 1
    OSCPCICLK0_TYPE = 10, //Specifically clock 0
    OSCPCICLK1_TYPE = 11, //Specifically clock 1

    LPCREFCLK_TYPE  = 12, // LPC clock
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
    TOD_CLOCK                       = 8,
    MEM_REF_CLOCK                   = 9,
    PROC_REF_CLOCK                  = 10,
    PCI_REF_CLOCK                   = 11,
    // @TODO 195920 Remove SMP_CABLE once HWSV code no longer references it
    SMP_CABLE                       = 12, //Target is SMPGROUP
    BPM_CABLE_PART_TYPE             = 13, //Backup Power Module Cable for NVDIMM
    NV_CONTROLLER_PART_TYPE         = 14, //Controller for NVDIMM
    BPM_PART_TYPE                   = 15, //Backup Power Module for NVDIMM
    SPI_DUMP_PART_TYPE              = 16, // Dump SPI Engine
};

enum sensorTypeEnum
{
    UNKNOWN_SENSOR                  = 0,
    GPU_FUNC_SENSOR                 = 1,
    GPU_TEMPERATURE_SENSOR          = 2,
    GPU_MEMORY_TEMP_SENSOR          = 3,
};

//-- Flags
typedef uint8_t CalloutFlag_t;
// No extra flags are present
const uint8_t FLAG_NONE             = 0;
// SMP link is down, therefore its pair cannot be repaired
const uint8_t FLAG_LINK_DOWN        = 1;

//-- Callout types
enum calloutType : uint8_t
{
    HW_CALLOUT         = 0x01,
    PROCEDURE_CALLOUT  = 0x02,
    BUS_CALLOUT        = 0x03,
    CLOCK_CALLOUT      = 0x04,
    PART_CALLOUT       = 0x05,
    SENSOR_CALLOUT     = 0x06,
    I2C_DEVICE_CALLOUT = 0x07,
    LAST_CALLOUT = I2C_DEVICE_CALLOUT,
};
typedef calloutType CalloutType_t;

const uint8_t TARGET_IS_SENTINEL = 0xF0;

/**
 * @brief  Defines the data layout that is passed around the code as part
 *         of en error log to specify a callout.  Note that this structure
 *         is used in messages between Hostboot and FSP, and it is saved
 *         to persistent storage inside error logs.  This means that the
 *         size cannot change and the fields cannot be reordered.
 *
 * NOTE:   Keep check in ErrlUserDetailsParserCallout function in
 *         src/usr/errl/plugins/ebmc/b0100.py in sync with this struct
 */
typedef struct callout_ud
{
    CalloutType_t       type; //uint8_t
    CalloutFlag_t       flag; //uint8_t
    uint8_t             pad[2];
    callOutPriority     priority;           // uint32_t
    union { // 3 x uint32
        struct {    // type == HW_CALLOUT
            DeconfigEnum    deconfigState;  // uint32_t
            GARD_ErrorType  gardErrorType;  // uint32_t
            uint32_t        cpuid;
            // one Target will follow
        };
        struct {    // type == PROCEDURE_CALLOUT
            epubProcedureID procedure;      // uint32_t
            // uint32 - unused
            // uint32 - unused
        };
        struct {    // type == BUS_CALLOUT
            busTypeEnum     busType;        // uint32_t
            // uint32 - unused
            // uint32 - unused
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
        struct {  // type == SENSOR_CALLOUT
            uint32_t        sensorId;
            sensorTypeEnum  sensorType;
            // uint32 - unused
            // zero Targets will follow
        };
        struct {  // type == I2C_DEVICE_CALLOUT
            uint8_t        engine;
            uint8_t        port;
            uint8_t        address;
            // one Target will follow
        };
    }; // union

    // Default Ctor
    // The struct is made up of a union of structs, so instead of trying
    // to predict the default value for each, just setting all data to 0.
    callout_ud() { memset(this, 0, sizeof(callout_ud)); }
} __attribute__ ((packed)) callout_ud_t;


#if !defined(PARSER) && !defined(LOGPARSER)

/* BUS callout Structure: This structure contains all the parameters needed for callout
// in platHandleAddBusCallout, Fields are:
// TargetPart1: One End point of BUS
// TargetPart2: Second End point of BUS
// busType:     BUS Type
// priority:    priority of this callout
// flag:        This flag is specific for SMP cable only, for others it will be NONE
//              if FLAG_LINK_DOWN, CBLV link state will be set as ERROR STATE
*/
typedef struct
{
    TARGETING::Target* TargetPart1;
    TARGETING::Target* TargetPart2;
    HWAS::busTypeEnum  busType;
    HWAS::callOutPriority priority;
    HWAS::CalloutFlag_t flag;
}busCallout_t;

/**
 *  @brief retrieveTarget will convert the EntityPath to a Target
 *
 *         Special usage for bus callouts, calling retrieveTarget
 *         back to back will bump the io_uData and allow the
 *         secondary call to retrieve the destination side of the
 *         bus callout (so first invocation to retrieveTarget for
 *         a bus callout retrieves the source side, second call
 *         using the bumped io_uData pointer will access the
 *         destination side of the bus callout user details data).
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
 * @brief helper function to determine what the type of an Ephemeral Guard should
 *        be based off ATTR_BLOCK_SPEC_DECONFIG
 *
 * @return GARD_ErrorType   GARD_Sticky_deconfig if ATTR_BLOCK_SPEC_DECONFIG == 1,
 *                          GARD_Reconfig otherwise
 */
GARD_ErrorType getEphmeralGardRecordType();

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
 * @param[in]  io_busCallout a structure of all the fields data needed for
 *             bus callout
 *             TargetPart1: target endpoint1
 *             TargetPart2: target endpoint2
 *             busType:     bus type Enum
 *             priority:    Enum indicating the priority of the callout
 *             flag:        Flag for CBLV link state of SMP cables only
 *
 * @param[in] io_errl  reference to errlHnld for this errlog
 * @return errlHndl_t       valid errlHndl_t handle if there was an error,
 *                          NULL if no errors;
 */
errlHndl_t platHandleAddBusCallout(busCallout_t &io_busCallout,
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

/**
 * @brief platform specific code to handle a bus callout that has been
 *  found in an errlog
 *
 * @param[in]  i_i2cMaster      I2c master target for the i2c device
 * @param[in]  i_engine         I2c device engine
 * @param[in]  i_port           I2c device port
 * @param[in]  i_address        I2c device address
 * @param[in]  i_priority       Enum indicating the priority of the callout
 * @param[in]  io_errl          Reference to error log handle
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error,
 *                          nullptr if no errors;
 */
errlHndl_t platHandleI2cDeviceCallout(
        TARGETING::Target *i_i2cMaster,
        uint8_t i_engine,
        uint8_t i_port,
        uint8_t i_address,
        callOutPriority i_priority,
        errlHndl_t &io_errl);

#endif // not LOGPARSER

};   // end namespace
#endif
