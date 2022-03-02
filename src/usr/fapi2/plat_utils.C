/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/plat_utils.C $                                  */
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
///
/// @file plat_utils.C
///
/// @brief Implements the plat_utils.H utility functions.
///
/// Note that platform code must provide the implementation.
///

#include <sys/time.h>
#include <utils.H>
#include <plat_trace.H>
#include <return_code.H>
#include <error_info.H>
#include <assert.h>
#include <plat_utils.H>
#include <hw_access.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <hwpf_fapi2_reasoncodes.H>
#include <attributeenums.H>
#include <pnor/pnorif.H>
#include <p10_tor.H>
#include <p10_scan_compression.H>
#include <scom/wakeup.H>
#include <util/misc.H>

#include <fapi2.H>

//******************************************************************************
// Trace descriptors
//******************************************************************************
trace_desc_t* g_fapiTd;
trace_desc_t* g_fapiImpTd;
trace_desc_t* g_fapiScanTd;
trace_desc_t* g_fapiDbgTd;
trace_desc_t* g_fapiMfgTd;


//******************************************************************************
// Global TracInit objects. Construction will initialize the trace buffer
//******************************************************************************
TRAC_INIT(&g_fapiTd, FAPI_TRACE_NAME, 2*KILOBYTE);
TRAC_INIT(&g_fapiImpTd, FAPI_IMP_TRACE_NAME, 2*KILOBYTE);
TRAC_INIT(&g_fapiScanTd, FAPI_SCAN_TRACE_NAME, 4*KILOBYTE);
TRAC_INIT(&g_fapiDbgTd, FAPI_DBG_TRACE_NAME, 4*KILOBYTE);
TRAC_INIT(&g_fapiMfgTd, FAPI_MFG_TRACE_NAME, 4*KILOBYTE);
namespace fapi2
{

// Define globals
// g_platErrList stores error log pointers added to ReturnCodes via the
//   setPlatDataPtr function within the HWP_INVOKE scope.  These error logs
//   may or may not be deleted during HWP_INVOKE.  The remaining error logs
//   on the list are deleted in hwpResetGlobals() at the end of the HWP_INVOKE
//   sequence, thus avoiding a memory leak.
#ifndef PLAT_NO_THREAD_LOCAL_STORAGE
thread_local ReturnCode current_err;
thread_local std::list<errlHndl_t> g_platErrList;
#else
ReturnCode current_err;
std::list<errlHndl_t> g_platErrList;
#endif


///
/// @brief Add error log pointer as data to the ReturnCode and also add it
///        to the global error log list so we can delete it later
///
/// @param[in]  i_rc - ReturnCode reference
/// @param[in]  i_err - Error log pointer
///
void addErrlPtrToReturnCode( fapi2::ReturnCode& i_rc,
                             errlHndl_t i_err )
{
    assert(i_err != nullptr,
           "addErrlPtrToReturnCode() called with errHndl_t = nullptr");

    // Add the error log pointer as data to the ReturnCode
    i_rc.setPlatDataPtr(reinterpret_cast<void *> (i_err));

    // Add error to global list so we can delete it later
    g_platErrList.push_back(i_err);
}


///
/// @brief Translates a FAPI callout priority to an HWAS callout priority
///
/// @param[i] i_fapiPri FAPI callout priority
///
/// @return HWAS callout priority
///
HWAS::callOutPriority xlateCalloutPriority(
        const fapi2::CalloutPriorities::CalloutPriority i_fapiPri)
{
    // Use the CalloutPriority enum value as an index
    HWAS::callOutPriority l_priority = HWAS::SRCI_PRIORITY_HIGH;
    size_t l_index = i_fapiPri;

    const HWAS::callOutPriority HWAS_PRI[] = {HWAS::SRCI_PRIORITY_LOW,
        HWAS::SRCI_PRIORITY_MED,
        HWAS::SRCI_PRIORITY_HIGH,
        HWAS::SRCI_PRIORITY_NONE};

    if (l_index < (sizeof(HWAS_PRI)/sizeof(HWAS::callOutPriority)))
    {
        l_priority = HWAS_PRI[l_index];
    }
    else
    {
        FAPI_ERR("fapi2::xlateCalloutPriority: Unknown priority 0x%x, assuming HIGH",
                i_fapiPri);
    }

    return l_priority;
}

///
/// * @brief Translates a FAPI Clock HW callout to an HWAS clock callout
///
/// * @param[in] i_fapiClock FAPI Clock HW callout
/// * @param[in] i_clockPos  Clock position
///
/// * @return HWAS Clock HW callout
///
HWAS::clockTypeEnum xlateClockHwCallout(
        const fapi2::HwCallouts::HwCallout i_fapiClock,
        const uint8_t i_clockPos )
{
    // Use the HwCallout enum value as an index
    HWAS::clockTypeEnum l_clock = HWAS::TODCLK_TYPE;
    size_t l_index = i_fapiClock;

    const HWAS::clockTypeEnum HWAS_CLOCK[] = {
        HWAS::TODCLK_TYPE,
        HWAS::MEMCLK_TYPE,
        HWAS::OSCREFCLK_TYPE,
        HWAS::OSCPCICLK_TYPE};

    if (l_index < (sizeof(HWAS_CLOCK)/sizeof(HWAS::clockTypeEnum)))
    {
        l_clock = HWAS_CLOCK[l_index];
    }
    else
    {
        FAPI_ERR("fapi::xlateClockHwCallout: Unknown clock 0x%x, assuming TOD",
                i_fapiClock);
    }

    // Specify specific clock source for the case where which redundant source
    // can be determined as at fault
    FAPI_DBG("xlateClockHwCallout() - clockPos = %d", i_clockPos);
    if (l_clock == HWAS::OSCREFCLK_TYPE)
    {
        if ( 0 == i_clockPos )
        {
            l_clock = HWAS::OSCREFCLK0_TYPE;
        }
        else if ( 1 == i_clockPos )
        {
            l_clock = HWAS::OSCREFCLK1_TYPE;
        }
        //else can't determine which redundant source
    }
    else if (l_clock == HWAS::OSCPCICLK_TYPE)
    {
        if ( 0 == i_clockPos )
        {
            l_clock = HWAS::OSCPCICLK0_TYPE;
        }
        else if ( 1 == i_clockPos )
        {
            l_clock = HWAS::OSCPCICLK1_TYPE;
        }
        //else can't determine which redundant source
    }

    return l_clock;
}

///
/// * @brief Translates a FAPI Part HW callout to an HWAS part callout
///
/// * @param[i] i_fapiPart FAPI part HW callout
///
/// * @return HWAS part HW callout
///
HWAS::partTypeEnum xlatePartHwCallout(
        const fapi2::HwCallouts::HwCallout i_fapiPart)
{
    // Use the HwCallout enum value as an index
    HWAS::partTypeEnum l_part = HWAS::NO_PART_TYPE;

    // clock xlate function above assumes indexes match
    // between 2 enums.  seems better to do it explicitly

    switch (i_fapiPart)
    {
        case HwCallouts::FLASH_CONTROLLER_PART:
            l_part = HWAS::FLASH_CONTROLLER_PART_TYPE;
            break;
        case HwCallouts::PNOR_PART:
            l_part = HWAS::PNOR_PART_TYPE;
            break;
        case HwCallouts::SBE_SEEPROM_PART:
            l_part = HWAS::SBE_SEEPROM_PART_TYPE;
            break;
        case HwCallouts::VPD_PART:
            l_part = HWAS::VPD_PART_TYPE;
            break;
        case HwCallouts::LPC_SLAVE_PART:
            l_part = HWAS::LPC_SLAVE_PART_TYPE;
            break;
        case HwCallouts::GPIO_EXPANDER_PART:
            l_part = HWAS::GPIO_EXPANDER_PART_TYPE;
            break;
        case HwCallouts::SPIVID_SLAVE_PART:
            l_part = HWAS::SPIVID_SLAVE_PART_TYPE;
            break;
        case HwCallouts::TOD_CLOCK:
            l_part = HWAS::TOD_CLOCK;
            break;
        case HwCallouts::MEM_REF_CLOCK:
            l_part = HWAS::MEM_REF_CLOCK;
            break;
        case HwCallouts::PROC_REF_CLOCK:
            l_part = HWAS::PROC_REF_CLOCK;
            break;
        case HwCallouts::PCI_REF_CLOCK:
            l_part = HWAS::PCI_REF_CLOCK;
            break;

    }

    return l_part;
}

///
/// * @brief Translates a FAPI procedure callout to an HWAS procedure callout
///
/// * @param[i] i_fapiProc FAPI procedure callout
///
/// * @return HWAS procedure callout
///
HWAS::epubProcedureID xlateProcedureCallout(
        const fapi2::ProcedureCallouts::ProcedureCallout i_fapiProc)
{
    // Use the ProcedureCallout enum value as an index
    HWAS::epubProcedureID l_proc = HWAS::EPUB_PRC_HB_CODE;

    switch( i_fapiProc )
    {
        case(ProcedureCallouts::CODE):
            l_proc = HWAS::EPUB_PRC_HB_CODE;
            break;
        case(ProcedureCallouts::LVL_SUPPORT):
            l_proc = HWAS::EPUB_PRC_LVL_SUPP;
            break;
        case(ProcedureCallouts::MEMORY_PLUGGING_ERROR):
            l_proc = HWAS::EPUB_PRC_MEMORY_PLUGGING_ERROR;
            break;
        case(ProcedureCallouts::BUS_CALLOUT):
            l_proc = HWAS::EPUB_PRC_EIBUS_ERROR;
            break;
        case(ProcedureCallouts::FIND_DECONFIGURED_PART):
            l_proc = HWAS::EPUB_PRC_FIND_DECONFIGURED_PART;
            break;
    } //no default so that we catch changes at compile time

    return l_proc;
}

///
/// * @brief Translates a FAPI2 target type to a Targeting target type
///
/// * @param[i] i_targetType FAPI2 target type
/// * @param[o] o_class      Targeting class
/// * @param[o] o_type       Targeting type
///
void xlateTargetType(const fapi2::TargetType i_targetType,
        TARGETING::CLASS & o_class,
        TARGETING::TYPE & o_type)
{
    switch (i_targetType)
    {
        case fapi2::TARGET_TYPE_SYSTEM:
            o_class = TARGETING::CLASS_SYS;
            o_type = TARGETING::TYPE_SYS;
            break;
        case fapi2::TARGET_TYPE_DIMM:
            o_class = TARGETING::CLASS_LOGICAL_CARD;
            o_type = TARGETING::TYPE_DIMM;
            break;
        case fapi2::TARGET_TYPE_PROC_CHIP:
            o_class = TARGETING::CLASS_CHIP;
            o_type = TARGETING::TYPE_PROC;
            break;
        case fapi2::TARGET_TYPE_FC:
            o_class = TARGETING::CLASS_UNIT;
            o_type = TARGETING::TYPE_FC;
            break;
        case fapi2::TARGET_TYPE_CORE:
            o_class = TARGETING::CLASS_UNIT;
            o_type = TARGETING::TYPE_CORE;
            break;
        case fapi2::TARGET_TYPE_EQ:
            o_class = TARGETING::CLASS_UNIT;
            o_type = TARGETING::TYPE_EQ;
            break;
        case fapi2::TARGET_TYPE_MI:
            o_class = TARGETING::CLASS_UNIT;
            o_type = TARGETING::TYPE_MI;
            break;
        case fapi2::TARGET_TYPE_PERV:
            o_class = TARGETING::CLASS_UNIT;
            o_type = TARGETING::TYPE_PERV;
            break;
        case fapi2::TARGET_TYPE_PEC:
            o_class = TARGETING::CLASS_UNIT;
            o_type = TARGETING::TYPE_PEC;
            break;
        case fapi2::TARGET_TYPE_PHB:
            o_class = TARGETING::CLASS_UNIT;
            o_type = TARGETING::TYPE_PHB;
            break;
        case fapi2::TARGET_TYPE_MC:
            o_class = TARGETING::CLASS_UNIT;
            o_type = TARGETING::TYPE_MC;
            break;
        case fapi2::TARGET_TYPE_OMI:
            o_class = TARGETING::CLASS_UNIT;
            o_type = TARGETING::TYPE_OMI;
            break;
        case fapi2::TARGET_TYPE_OMIC:
            o_class = TARGETING::CLASS_UNIT;
            o_type = TARGETING::TYPE_OMIC;
            break;
        case fapi2::TARGET_TYPE_MCC:
            o_class = TARGETING::CLASS_UNIT;
            o_type = TARGETING::TYPE_MCC;
            break;
        case fapi2::TARGET_TYPE_OCMB_CHIP:
            o_class = TARGETING::CLASS_CHIP;
            o_type = TARGETING::TYPE_OCMB_CHIP;
            break;
        case fapi2::TARGET_TYPE_MEM_PORT:
            o_class = TARGETING::CLASS_UNIT;
            o_type = TARGETING::TYPE_MEM_PORT;
            break;
        default:
            o_class = TARGETING::CLASS_NA;
            o_type = TARGETING::TYPE_NA;
    }
}

///
/// @brief Is this target type pair a physical parent <-> child?
/// @return Return true if the types have physically parent <-> child
///         relationship; false otherwise.
///
bool isPhysParentChild(const TargetType i_parentType,
                       const TargetType i_childType)
{
    bool l_result = false;
    if (i_parentType == TARGET_TYPE_PROC_CHIP)
    {
        if ( (i_childType & (TARGET_TYPE_FC     |
                             TARGET_TYPE_CORE   |
                             TARGET_TYPE_EQ     |
                             TARGET_TYPE_MC     |
                             TARGET_TYPE_MCC    |
                             TARGET_TYPE_OMIC   |
                             TARGET_TYPE_OMI    |
                             TARGET_TYPE_MI     |
                             TARGET_TYPE_PERV   |
                             TARGET_TYPE_PEC    |
                             TARGET_TYPE_PHB    |
                             TARGET_TYPE_PAUC   |
                             TARGET_TYPE_IOHS   |
                             TARGET_TYPE_PAU)) != 0 )
        {
            l_result = true;
        }
    }
    else if (i_parentType == TARGET_TYPE_OCMB_CHIP)
    {
        if ( (i_childType & (TARGET_TYPE_MEM_PORT)) != 0 )
        {
            l_result = true;
        }
    }
    return l_result;
}

///
/// @brief Processes any FFDC in the ReturnCode Error Information and adds them
/// to the error log
///
/// @param[i] i_errInfo  Reference to ReturnCode Error Information
/// @param[io] io_pError Errorlog Handle
///
void processEIFfdcs(const ErrorInfo & i_errInfo,
                    errlHndl_t io_pError)
{
    // Iterate through the FFDC sections, adding each to the error log
    uint32_t l_size = 0;

    for (auto itr = i_errInfo.iv_ffdcs.begin();
         itr != i_errInfo.iv_ffdcs.end(); ++itr)
    {
        const void * l_pFfdc = (*itr)->getData(l_size);
        uint32_t l_ffdcId = (*itr)->getFfdcId();

        // Add the FFDC ID as the first word, then the FFDC data
        FAPI_DBG("processEIFfdcs: Adding %d bytes of FFDC (id:0x%08x)", l_size,
                 l_ffdcId);
        ERRORLOG::ErrlUD * l_pUD = io_pError->addFFDC(
            HWPF_COMP_ID, &l_ffdcId, sizeof(l_ffdcId), 1,
            HWPF_FAPI2_UDT_HWP_FFDC);

        if (l_pUD)
        {
            io_pError->appendToFFDC(l_pUD, l_pFfdc, l_size);
        }
    }
}

///
/// @brief Processes any HW callouts requests in the ReturnCode Error
///        Information and adds them to the error log
///
/// @param[i] i_errInfo  Reference to ReturnCode Error Information
/// @param[io] io_pError Errorlog Handle
///
void processEIHwCallouts(const ErrorInfo & i_errInfo,
                         errlHndl_t io_pError)
{
    // Iterate through the HW callout requests, adding each to the error log
    for (auto itr = i_errInfo.iv_hwCallouts.begin();
         itr != i_errInfo.iv_hwCallouts.end(); ++itr)
    {
        HWAS::callOutPriority l_priority =
            xlateCalloutPriority((*itr)->iv_calloutPriority);

        HwCallouts::HwCallout l_hw = ((*itr)->iv_hw);

        TARGETING::Target * l_pRefTarget = (*itr)->iv_refTarget.get();

        if ( ((l_hw == HwCallouts::TOD_CLOCK) ||
              (l_hw == HwCallouts::MEM_REF_CLOCK) ||
              (l_hw == HwCallouts::PROC_REF_CLOCK) ||
              (l_hw == HwCallouts::PCI_REF_CLOCK)) &&
             l_pRefTarget != NULL)
        {
            HWAS::clockTypeEnum l_clock =
                xlateClockHwCallout((*itr)->iv_hw, (*itr)->iv_clkPos);

            FAPI_ERR("processEIHwCallouts: Adding clock-callout"
                     " (clock:%d, pri:%d)",
                     l_clock, l_priority);

            //  Force PCI clocks to be deconfigured and garded
            if( l_hw == HwCallouts::PCI_REF_CLOCK )
            {
                io_pError->addClockCallout(l_pRefTarget,
                                           l_clock,
                                           l_priority,
                                           HWAS::DECONFIG,
                                           HWAS::GARD_Predictive);
            }
            else
            {
                // Base deconfig/gard records on priority
                switch (l_priority)
                {
                    // High Priority callout
                    // => FATAL gard, Deconfig
                    case HWAS::SRCI_PRIORITY_HIGH:
                        io_pError->addClockCallout(l_pRefTarget,
                                                   l_clock,
                                                   l_priority,
                                                   HWAS::DECONFIG,
                                                   HWAS::GARD_Fatal);

                        break;

                    // Medium Priority
                    // => Predictive, No deconfig (as per latest clock RAS behaviour).
                    case HWAS::SRCI_PRIORITY_MEDC:
                    case HWAS::SRCI_PRIORITY_MEDB:
                    case HWAS::SRCI_PRIORITY_MEDA:
                    case HWAS::SRCI_PRIORITY_MED:
                        io_pError->addClockCallout(l_pRefTarget,
                                                   l_clock,
                                                   l_priority,
                                                   HWAS::NO_DECONFIG,
                                                   HWAS::GARD_Predictive);
                        break;

                    // Low Priority
                    // => No Gard / Deconfig
                    case HWAS::SRCI_PRIORITY_LOW:
                    default:
                        io_pError->addClockCallout(l_pRefTarget,
                                                   l_clock,
                                                   l_priority);
                        break;
                }
            }
        }
        else if ( (l_hw == HwCallouts::FLASH_CONTROLLER_PART) ||
                  (l_hw == HwCallouts::PNOR_PART) ||
                  (l_hw == HwCallouts::SBE_SEEPROM_PART) ||
                  (l_hw == HwCallouts::VPD_PART) ||
                  (l_hw == HwCallouts::LPC_SLAVE_PART) ||
                  (l_hw == HwCallouts::GPIO_EXPANDER_PART) ||
                  (l_hw == HwCallouts::SPIVID_SLAVE_PART) )
        {
            HWAS::partTypeEnum l_part =
                xlatePartHwCallout((*itr)->iv_hw);

            FAPI_ERR("processEIHwCallouts: Adding part-callout"
                     " (part:%d, pri:%d)",
                     l_part, l_priority);
            io_pError->addPartCallout(l_pRefTarget, l_part, l_priority);
        }
        else
        {
            FAPI_ERR("processEIHwCallouts: Unsupported HW callout (%d)", l_hw);
            io_pError->addPartCallout(l_pRefTarget, HWAS::NO_PART_TYPE,
                     l_priority);
            io_pError->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE, l_priority);
        }
    }
}

///
/// @brief Processes any Procedure callouts requests in the ReturnCode Error
///        Information and adds them to the error log
///
/// @param[i] i_errInfo  Reference to ReturnCode Error Information
/// @param[io] io_pError Errorlog Handle
///
void processEIProcCallouts(const ErrorInfo & i_errInfo,
                           errlHndl_t io_pError)
{
    // Iterate through the procedure callout requests, adding each to the error
    // log
    for (auto itr = i_errInfo.iv_procedureCallouts.begin();
         itr != i_errInfo.iv_procedureCallouts.end(); ++itr)
    {
        HWAS::epubProcedureID l_procedure =
            xlateProcedureCallout((*itr)->iv_procedure);

        HWAS::callOutPriority l_priority =
            xlateCalloutPriority((*itr)->iv_calloutPriority);

        FAPI_DBG("processEIProcCallouts: Adding proc-callout"
                 " (proc:0x%02x, pri:%d)",
                 l_procedure, l_priority);
        io_pError->addProcedureCallout(l_procedure, l_priority);
    }
}

///
/// @brief Processes any Bus callouts requests in the ReturnCode Error
///        Information and adds them to the error log
///
/// @param[i] i_errInfo  Reference to ReturnCode Error Information
/// @param[io] io_pError Errorlog Handle
///
void processEIBusCallouts(const ErrorInfo & i_errInfo,
                          errlHndl_t io_pError)
{
    // Iterate through the bus callout requests, adding each to the error log
    for (auto itr = i_errInfo.iv_busCallouts.begin();
         itr != i_errInfo.iv_busCallouts.end(); ++itr)
    {
        TARGETING::Target * l_pTarget1 = (*itr)->iv_target1.get();

        TARGETING::Target * l_pTarget2 = (*itr)->iv_target2.get();

        HWAS::callOutPriority l_priority =
            xlateCalloutPriority((*itr)->iv_calloutPriority);

        bool l_busTypeValid = true;
        HWAS::busTypeEnum l_busType = HWAS::FSI_BUS_TYPE;
        TARGETING::TYPE l_type1 = l_pTarget1->getAttr<TARGETING::ATTR_TYPE>();
        TARGETING::TYPE l_type2 = l_pTarget2->getAttr<TARGETING::ATTR_TYPE>();

        if ((l_type1 == TARGETING::TYPE_IOHS && l_type2 == TARGETING::TYPE_IOHS)
            || (l_type1 == TARGETING::TYPE_SMPGROUP && l_type2 == TARGETING::TYPE_SMPGROUP))
        {
            const auto l_iohsTarget1 = (l_type1 == TARGETING::TYPE_IOHS
                                        ? l_pTarget1
                                        : getImmediateParentByAffinity(l_pTarget1));
            const auto l_iohsTarget2 = (l_type2 == TARGETING::TYPE_IOHS
                                        ? l_pTarget2
                                        : getImmediateParentByAffinity(l_pTarget2));

            const auto l_configMode_pTarget1 = l_iohsTarget1->getAttr<TARGETING::ATTR_IOHS_CONFIG_MODE>();
            const auto l_configMode_pTarget2 = l_iohsTarget2->getAttr<TARGETING::ATTR_IOHS_CONFIG_MODE>();

            if ((l_configMode_pTarget1 == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPX) &&
                (l_configMode_pTarget2 == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPX))
            {
                l_busType = HWAS::X_BUS_TYPE;
            }
            else if ((l_configMode_pTarget1 == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPA) &&
                     (l_configMode_pTarget2 == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPA))
            {
                l_busType = HWAS::A_BUS_TYPE;
            }

        }
        else if ( ((l_type1 == TARGETING::TYPE_OMI) &&
                   (l_type2 == TARGETING::TYPE_OCMB_CHIP)) ||
                  ((l_type1 == TARGETING::TYPE_OCMB_CHIP) &&
                   (l_type2 == TARGETING::TYPE_OMI)) )
        {
            l_busType = HWAS::OMI_BUS_TYPE;
        }
        else
        {
            FAPI_ERR("processEIBusCallouts: Bus between target types not known (0x%08x:0x%08x)",
                     l_type1, l_type2);
            l_busTypeValid = false;
        }

        if (l_busTypeValid)
        {
            FAPI_INF("processEIBusCallouts: Adding bus-callout"
                     " (bus:%d, pri:%d)",
                     l_busType, l_priority);
            io_pError->addBusCallout(l_pTarget1, l_pTarget2, l_busType,
                                     l_priority);
        }
    }
}

///
/// @brief Processes any Callout/Deconfigure/GARD requests in the
///        ReturnCode Error Information and adds them to the error log
///
/// @param[i] i_errInfo  Reference to ReturnCode Error Information
/// @param[io] io_pError Errorlog Handle
///
void processEICDGs(const ErrorInfo & i_errInfo,
                   errlHndl_t io_pError)
{
    // Iterate through the CGD requests, adding each to the error log
    for (auto itr = i_errInfo.iv_CDGs.begin();
         itr != i_errInfo.iv_CDGs.end(); ++itr)
    {
        TARGETING::Target * l_pTarget = (*itr)->iv_target.get();

        HWAS::callOutPriority l_priority =
            xlateCalloutPriority((*itr)->iv_calloutPriority);

        HWAS::DeconfigEnum l_deconfig = HWAS::NO_DECONFIG;
        if ((*itr)->iv_deconfigure)
        {
            l_deconfig = HWAS::DELAYED_DECONFIG;
        }

        HWAS::GARD_ErrorType l_gard = HWAS::GARD_NULL;
        if ((*itr)->iv_gard)
        {
            l_gard = HWAS::GARD_Unrecoverable;
        }

        FAPI_DBG("processEICDGs: Calling out target"
                 " (huid:%.8x, pri:%d, deconf:%d, gard:%d)",
                 TARGETING::get_huid(l_pTarget), l_priority, l_deconfig,
                 l_gard);
        io_pError->addHwCallout(l_pTarget, l_priority, l_deconfig, l_gard);
    }

}

///
/// @brief Returns child targets to Callout/Deconfigure/GARD
///
/// @param[i] i_parentTarget FAPI2 Parent Target
/// @param[i] i_childType    FAPI2 Child Type
/// @param[i] i_childPort    Child Port Number
///                            For DIMMs: Port Number
///                            Else unused
/// @param[i] i_childNum     Child Number
///                            For DIMMs: DIMM Socket Number
///                            For Chips: Chip Position
///                            For Chiplets: Chiplet Position
/// @param[o] o_childTargets List of child targets matching input
///                            criteria.
///
void getChildTargetsForCDG(
             const fapi2::Target<fapi2::TARGET_TYPE_ALL>& i_parentTarget,
             const fapi2::TargetType i_childType,
             const uint8_t i_childPort,
             const uint8_t i_childNum,
             TARGETING::TargetHandleList & o_childTargets)
{
    o_childTargets.clear();

    do
    {
        // Get the parent TARGETING::Target
        TARGETING::Target * l_pTargParent = i_parentTarget.get();

        if (l_pTargParent == NULL)
        {
            FAPI_ERR("getChildTargetsForCDG: NULL Target pointer");
            break;
        }

        // Find if the child target type is a dimm, chip or chiplet
        bool l_childIsDimm = false;
        bool l_childIsChip = false;
        bool l_childIsChiplet = false;

        if (i_childType == fapi2::TARGET_TYPE_DIMM)
        {
            l_childIsDimm = true;
        }
        else
        {
            l_childIsChip = fapi2::Target<TARGET_TYPE_ALL>::isChip(i_childType);
            if (!l_childIsChip)
            {
                l_childIsChiplet = fapi2::Target<TARGET_TYPE_ALL>::
                                               isChiplet(i_childType);
            }
        }

        // Translate the FAPI child target type into TARGETING Class/Type
        TARGETING::CLASS l_targChildClass = TARGETING::CLASS_NA;
        TARGETING::TYPE l_targChildType = TARGETING::TYPE_NA;
        xlateTargetType(i_childType, l_targChildClass, l_targChildType);

        if (l_targChildType == TARGETING::TYPE_NA)
        {
            FAPI_ERR("getChildTargetsForCDG: Could not xlate child type (0x%08x)",
                     i_childType);
            break;
        }

        // Get the child targets
        TARGETING::TargetHandleList l_targChildList;

        if ( isPhysParentChild(i_parentTarget.getType(), i_childType) )
        {
            // Child by containment
            TARGETING::getChildChiplets(l_targChildList, l_pTargParent,
                                        l_targChildType);
            FAPI_ERR("getChildTargetsForCDG: Got %d candidate children by containment",
                     l_targChildList.size());
        }
        else
        {
            // Assumption is child by affinity
            TARGETING::getChildAffinityTargets(l_targChildList, l_pTargParent,
                                               l_targChildClass,
                                               l_targChildType);
            FAPI_ERR("getChildTargetsForCDG: Got %d candidate children by affinity",
                     l_targChildList.size());
        }

        // Filter out child targets based on type and input port/number
        for (TARGETING::TargetHandleList::const_iterator
                l_itr = l_targChildList.begin();
             l_itr != l_targChildList.end(); ++l_itr)
        {
            if (l_childIsDimm)
            {
                // Match i_childPort and i_childNum
                if ( (i_childPort == ErrorInfoChildrenCDG::ALL_CHILD_PORTS)
                &&   (i_childNum == ErrorInfoChildrenCDG::ALL_CHILD_NUMBERS))
                {
                    o_childTargets.push_back(*l_itr);
                }
            }
            else if (l_childIsChip)
            {
                // Match i_childNum
                if ((i_childNum == ErrorInfoChildrenCDG::ALL_CHILD_NUMBERS) ||
                    (i_childNum ==
                         (*l_itr)->getAttr<TARGETING::ATTR_POSITION>()))
                {
                    o_childTargets.push_back(*l_itr);
                }
            }
            else if (l_childIsChiplet)
            {
                // Match i_childNum
                if ((i_childNum == ErrorInfoChildrenCDG::ALL_CHILD_NUMBERS) ||
                    (i_childNum ==
                         (*l_itr)->getAttr<TARGETING::ATTR_CHIP_UNIT>()))
                {
                    o_childTargets.push_back(*l_itr);
                }
            }
            else
            {
                // Do not match on anything
                o_childTargets.push_back(*l_itr);
            }
        }
    } while(0);
}

///
/// @brief Processes any Children Callout/Deconfigure/GARD requests in the
///        ReturnCode Error Information and adds them to the error log
///
/// @param[i] i_errInfo  Reference to ReturnCode Error Information
/// @param[io] io_pError Errorlog Handle
///
void processEIChildrenCDGs(const ErrorInfo & i_errInfo,
                           errlHndl_t io_pError)
{
    // Iterate through the Child CGD requests, adding each to the error log
    for (auto itr = i_errInfo.iv_childrenCDGs.begin();
         itr != i_errInfo.iv_childrenCDGs.end(); ++itr)
    {
        HWAS::callOutPriority l_priority =
            xlateCalloutPriority((*itr)->iv_calloutPriority);

        HWAS::DeconfigEnum l_deconfig = HWAS::NO_DECONFIG;
        if ((*itr)->iv_deconfigure)
        {
            l_deconfig = HWAS::DELAYED_DECONFIG;
        }

        HWAS::GARD_ErrorType l_gard = HWAS::GARD_NULL;
        if ((*itr)->iv_gard)
        {
            l_gard = HWAS::GARD_Unrecoverable;
        }

        // Get a list of children to callout
        TARGETING::TargetHandleList l_children;
        getChildTargetsForCDG((*itr)->iv_parent,
                              (*itr)->iv_childType,
                              (*itr)->iv_childPort,
                              (*itr)->iv_childNumber,
                              l_children);

        // Callout/Deconfigure/GARD each child as appropriate
        for (TARGETING::TargetHandleList::const_iterator
                itr = l_children.begin();
                itr != l_children.end(); ++itr)
        {
            FAPI_DBG("processEIChildrenCDGs: Calling out target"
                     " (huid:%.8x, pri:%d, deconf:%d, gard:%d)",
                     TARGETING::get_huid(*itr), l_priority, l_deconfig,
                     l_gard);
            io_pError->addHwCallout(*itr, l_priority, l_deconfig, l_gard);
        }
    }
}

///
/// @brief Converts a fapi2::ReturnCode to a HostBoot PLAT error log
/// See doxygen in plat_utils.H
///
errlHndl_t rcToErrl(ReturnCode & io_rc,
                    ERRORLOG::errlSeverity_t i_sev)
{
    errlHndl_t l_pError = NULL;

    FAPI_DBG("Entering rcToErrl");

    if (io_rc)
    {
        uint32_t l_rcValue = io_rc;

        // ReturnCode contains an error. Find out which component of the HWPF
        // created the error
        ReturnCode::returnCodeCreator l_creator = io_rc.getCreator();
        l_pError = reinterpret_cast<errlHndl_t>(io_rc.getPlatDataPtr());

        if (l_creator == ReturnCode::CREATOR_PLAT)
        {
            // PLAT error, get the platform data from the return code
            FAPI_ERR("rcToErrl: PLAT error: 0x%08x", l_rcValue);

            // Remove from the global error list
            g_platErrList.remove(l_pError);
        }
        else if (nullptr == l_pError)
        {
            if (l_creator == ReturnCode::CREATOR_HWP)
            {
                // HWP Error. Create an error log
                FAPI_ERR("rcToErrl: HWP error: 0x%08x", l_rcValue);

                /*@
                 * @errortype
                 * @moduleid     MOD_FAPI2_RC_TO_ERRL
                 * @reasoncode   RC_HWP_GENERATED_ERROR
                 * @userdata1    RC value from HWP
                 * @userdata2    <unused>
                 * @devdesc      HW Procedure generated error. Check User Data.
                 * @custdesc     Error initializing processor/memory subsystem
                 *               during boot. Check FRU list for repair actions
                 */
                l_pError = new ERRORLOG::ErrlEntry(i_sev,
                                                   MOD_FAPI2_RC_TO_ERRL,
                                                   RC_HWP_GENERATED_ERROR,
                                                   l_rcValue);
                // Note - If location of RC value changes, must update
                //   ErrlEntry::getFapiRC accordingly

                // Add the rcValue as FFDC. This will explain what the error was
                l_pError->addFFDC(HWPF_COMP_ID, &l_rcValue, sizeof(l_rcValue),
                                                1, HWPF_FAPI2_UDT_HWP_RCVALUE);

                // Get the Error Information Pointer
                const ErrorInfo* l_pErrorInfo =  io_rc.getErrorInfo();
                if (l_pErrorInfo)
                {
                    // There is error information associated with the ReturnCode
                    processEIFfdcs(*l_pErrorInfo, l_pError);
                    processEIProcCallouts(*l_pErrorInfo, l_pError);
                    processEIBusCallouts(*l_pErrorInfo, l_pError);
                    processEICDGs(*l_pErrorInfo, l_pError);
                    processEIChildrenCDGs(*l_pErrorInfo, l_pError);
                    processEIHwCallouts(*l_pErrorInfo, l_pError);
                }
                else
                {
                    FAPI_ERR("rcToErrl: No Error Information");
                }
            }
            else
            {
                // FAPI error. Create an error log
                FAPI_ERR("rcToErrl: FAPI error: 0x%08x", l_rcValue);

                // The errlog reason code is the HWPF compID and the rcValue LSB
                uint16_t l_reasonCode = l_rcValue;
                l_reasonCode &= 0xff;
                l_reasonCode |= HWPF_COMP_ID;

                // HostBoot errlog tags for FAPI errors are in hwpfReasonCodes.H
                l_pError = new ERRORLOG::ErrlEntry(i_sev,
                                                   MOD_FAPI2_RC_TO_ERRL,
                                                   l_reasonCode);

                // FAPI may have added Error Information.
                // Get the Error Information Pointer
                const ErrorInfo* l_pErrorInfo =  io_rc.getErrorInfo();
                if (l_pErrorInfo)
                {
                    processEIFfdcs(*l_pErrorInfo, l_pError);
                    processEIProcCallouts(*l_pErrorInfo, l_pError);
                    processEIBusCallouts(*l_pErrorInfo, l_pError);
                    processEICDGs(*l_pErrorInfo, l_pError);
                    processEIChildrenCDGs(*l_pErrorInfo, l_pError);
                    processEIHwCallouts(*l_pErrorInfo, l_pError);
                }
            }
        } // else if no elog yet

        // add the fapi traces to the elog
        l_pError->collectTrace(FAPI_TRACE_NAME, 256 );
        l_pError->collectTrace(FAPI_IMP_TRACE_NAME, 384 );
        l_pError->collectTrace(FAPI_SCAN_TRACE_NAME, 256 );
        l_pError->collectTrace(FAPI_DBG_TRACE_NAME, 256 );

        // Make sure the severity is set correctly for all errors.
        // The severity of PLAT errors is not set above, so set it here.
        l_pError->setSev(i_sev);
    }

    FAPI_DBG("Exiting rcToErrl");
    return l_pError;
}

// Convert the RC passed in to a platform error log and
// assign it to the platform data pointer of the RC
void createPlatLog(
        fapi2::ReturnCode & io_rc,
        fapi2::errlSeverity_t i_sev
        )
{

    FAPI_DBG("Entering createLog");

    errlHndl_t l_pError = NULL;

    // Convert a FAPI severity to a ERRORLOG severity
    ERRORLOG::errlSeverity_t l_sev = ERRORLOG::ERRL_SEV_UNRECOVERABLE;
    switch (i_sev)
    {
        case fapi2::FAPI2_ERRL_SEV_RECOVERED:
            l_sev = ERRORLOG::ERRL_SEV_RECOVERED;
            break;
        case fapi2::FAPI2_ERRL_SEV_PREDICTIVE:
            l_sev = ERRORLOG::ERRL_SEV_PREDICTIVE;
            break;
        case fapi2::FAPI2_ERRL_SEV_UNRECOVERABLE:
            // l_sev set above
            break;
        default:
            FAPI_ERR("severity (i_sev) of %d is unknown",i_sev);
            break;
    }

    // Convert the return code to an error log.
    // This will set the return code to FAPI2_RC_SUCCESS and clear any
    // PLAT Data, HWP FFDC data, and Error Target associated with it.
    l_pError = rcToErrl(io_rc, l_sev);

    // Add the error log pointer as data to the ReturnCode
    addErrlPtrToReturnCode(io_rc, l_pError);

}

///
/// @brief Log an error - Create a platform error from the passed
//                        RC passed in and commit it.
///
void logError(
    fapi2::ReturnCode & io_rc,
    fapi2::errlSeverity_t i_sev,
    bool i_unitTestError )
{
    FAPI_INF("logError(rc=%x, sev=%d)", (uint32_t)io_rc, i_sev );

    createPlatLog( io_rc, i_sev );

    errlHndl_t l_pError = reinterpret_cast<errlHndl_t>(io_rc.getPlatDataPtr());

    // Remove from the global error list
    g_platErrList.remove(l_pError);

    // Commit the error log. This will delete the error log and set the handle
    // to NULL.
    if (i_unitTestError)
    {
        errlCommit(l_pError, CXXTEST_COMP_ID);
    }
    else
    {
        errlCommit(l_pError, HWPF_COMP_ID);
    }

    // error log is deleted so need to make sure nobody uses it again
    io_rc.forgetData();

    //error is committed, no current error
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    return;
}
///
/// @brief Free platform log ptr - free a platform error from the
///                                 passed in RC.
///
void deletePlatformDataPointer(fapi2::ReturnCode & io_rc)
{
    errlHndl_t l_pError = reinterpret_cast<errlHndl_t>(io_rc.getPlatDataPtr());

    // Remove from the global error list
    g_platErrList.remove(l_pError);

    delete(l_pError);
}

///
/// @brief Internal Function associates PRD and HW elogs
/// Used by log_related_error
///
void set_log_id( const Target<TARGET_TYPE_ALL>& i_fapiTrgt,
                 fapi2::ReturnCode& io_rc,
                 fapi2::errlSeverity_t i_sev )
{
    do
    {
        // Get TARGETING target.
        TARGETING::Target* attrTrgt = i_fapiTrgt.get();
        if ( nullptr == attrTrgt )
        {
            FAPI_ERR( "[set_log_id] attrTrgt is null" );
            break;
        }

        // Create an error log for this FAPI error.
        createPlatLog( io_rc, i_sev );

        // Get the PLID from this error log.
        errlHndl_t errl = reinterpret_cast<errlHndl_t>(io_rc.getPlatDataPtr());
        uint32_t plid = ERRL_GETPLID_SAFE(errl);

        // Add the error log pointer as data to the ReturnCode
        addErrlPtrToReturnCode(io_rc, errl);

        // Set the PLID in this attribute.
        if ( ! attrTrgt->trySetAttr<TARGETING::ATTR_PRD_HWP_PLID>(plid) )
        {
            FAPI_ERR( "[set_log_id] failed to set ATTR_PRD_HWP_PLID on 0x%08x",
                      TARGETING::get_huid(attrTrgt) );
            break;
        }

    } while (0);

} // end set_log_id

///
/// @brief Associate an error to PRD PLID.
/// Used to connect HW error log to the PRD log.
///
void log_related_error(
    const Target<TARGET_TYPE_ALL>& i_target,
    fapi2::ReturnCode& io_rc,
    const fapi2::errlSeverity_t i_sev,
    const bool i_unitTestError )
{
    // This call will associate the FAPI and PRD logs
    set_log_id( i_target, io_rc, i_sev );
    // Commit the log
    logError( io_rc, i_sev, i_unitTestError );
} // end log_related_error

///
/// @brief Delay this thread. Hostboot will use the nanoseconds parameter
/// and make a syscall to nanosleep. While in the syscall, the hostboot
/// kernel will continue to consume CPU cycles as it looks for a runnable
/// task.  When the delay time expires, the task becomes runnable and will soon
/// return from the syscall.  Callers of delay() in the hostboot environment
/// will likely have to know the mHz clock speed they are running on and
/// compute a non-zero value for i_nanoSeconds.
///
ReturnCode delay(uint64_t i_nanoSeconds,
                 uint64_t i_simCycles,
                 bool i_fixed)
{
    //Note: i_fixed is deliberately ignored

    // We don't need to waste time for hardware delays if we're running in Simics
    if( !Util::isSimicsRunning() )
    {
        nanosleep( 0, i_nanoSeconds );
    }
    return FAPI2_RC_SUCCESS;
}

///
/// @brief Assert a condition, and halt
///
/// @param[in] a boolean representing the assertion
///
void Assert(bool i_expression)
{
    assert(i_expression);
}

bool platIsScanTraceEnabled()
{
  // SCAN trace can be dynamically turned on/off, always return true here
  return 1;
}

//******************************************************************************
// platSpecialWakeup
//******************************************************************************
fapi2::ReturnCode platSpecialWakeup(const Target<TARGET_TYPE_ALL>& i_target,
                                    const bool i_enable)
{
    fapi2::ReturnCode fapi_rc = fapi2::FAPI2_RC_SUCCESS;

    TARGETING::Target* l_target = i_target.get();
    FAPI_INF("platSpecialWakeup : HUID=%.8X, enable=%d", TARGETING::get_huid(l_target), i_enable);

    WAKEUP::HandleOptions_t l_option = WAKEUP::DISABLE;
    if( i_enable )
    {
        l_option = WAKEUP::ENABLE;
    }

    errlHndl_t err_SW = WAKEUP::handleSpecialWakeup(l_target,l_option);
    if(err_SW)
    {
        // Add the error log pointer as data to the ReturnCode
        addErrlPtrToReturnCode(fapi_rc, err_SW);
    }

    // On Hostboot, processor cores cannot sleep so return success to the
    // fapiSpecialWakeup enable/disable calls
    return fapi_rc;
}

///
/// @brief Resets all HWP thread_local variables
///
void hwpResetGlobals(void)
{
    // Reset all HWP thread_local vars
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    fapi2::opMode = fapi2::NORMAL;
    fapi2::setPIBErrorMask(0);

    // Delete remaining error logs on global list
    for( const auto & l_errl : g_platErrList )
    {
        delete(l_errl);
    }

    // Clear out the list
    g_platErrList.clear();
}

///
/// @brief Wrapper for toString to handle dynamic memory
std::vector<char> _getFapiName( const fapi2::Target<fapi2::TARGET_TYPE_ALL>& i_target )
{
    TARGETING::ATTR_FAPI_NAME_type l_targName = {0};
    fapi2::toString(i_target, l_targName, sizeof(l_targName));
    std::vector<char> output(l_targName,l_targName+sizeof(l_targName));
    return output;
}

} //end namespace
