/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/plat_utils.C $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <hwpf_fapi2_reasoncodes.H>

//******************************************************************************
// Trace descriptors
//******************************************************************************
trace_desc_t* g_fapiTd;
trace_desc_t* g_fapiImpTd;
trace_desc_t* g_fapiScanTd;
trace_desc_t* g_fapiMfgTd;


//******************************************************************************
// Global TracInit objects. Construction will initialize the trace buffer
//******************************************************************************
TRAC_INIT(&g_fapiTd, FAPI_TRACE_NAME, 2*KILOBYTE);
TRAC_INIT(&g_fapiImpTd, FAPI_IMP_TRACE_NAME, 2*KILOBYTE);
TRAC_INIT(&g_fapiScanTd, FAPI_SCAN_TRACE_NAME, 4*KILOBYTE);
TRAC_INIT(&g_fapiMfgTd, FAPI_MFG_TRACE_NAME, 4*KILOBYTE);
namespace fapi2
{

// Define global current_err
//thread_local ReturnCode current_err;
ReturnCode current_err;
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
                                              HWAS::SRCI_PRIORITY_HIGH};

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
/// * @param[i] i_fapiClock FAPI Clock HW callout
///
/// * @return HWAS Clock HW callout
///
HWAS::clockTypeEnum xlateClockHwCallout(
    const fapi2::HwCallouts::HwCallout i_fapiClock)
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
    size_t l_index = i_fapiProc;

    //@TODO RTC:124673 - need to verify the order still matches
    const HWAS::epubProcedureID HWAS_PROC[] = {
        HWAS::EPUB_PRC_HB_CODE,
        HWAS::EPUB_PRC_LVL_SUPP,
        HWAS::EPUB_PRC_MEMORY_PLUGGING_ERROR,
        HWAS::EPUB_PRC_EIBUS_ERROR};

    if (l_index < (sizeof(HWAS_PROC)/sizeof(HWAS::epubProcedureID)))
    {
        l_proc = HWAS_PROC[l_index];
    }
    else
    {
        FAPI_ERR("fapi2::xlateProcedureCallout: Unknown proc 0x%x, assuming CODE",
            i_fapiProc);
    }

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
    case fapi2::TARGET_TYPE_MEMBUF_CHIP:
        o_class = TARGETING::CLASS_CHIP;
        o_type = TARGETING::TYPE_MEMBUF;
        break;
    case fapi2::TARGET_TYPE_EX:
        o_class = TARGETING::CLASS_UNIT;
        o_type = TARGETING::TYPE_EX;
        break;
    case fapi2::TARGET_TYPE_MBA:
        o_class = TARGETING::CLASS_UNIT;
        o_type = TARGETING::TYPE_MBA;
        break;
    case fapi2::TARGET_TYPE_MCS:
        o_class = TARGETING::CLASS_UNIT;
        o_type = TARGETING::TYPE_MCS;
        break;
    case fapi2::TARGET_TYPE_XBUS:
        o_class = TARGETING::CLASS_UNIT;
        o_type = TARGETING::TYPE_XBUS;
        break;
    case fapi2::TARGET_TYPE_L4:
        o_class = TARGETING::CLASS_UNIT;
        o_type = TARGETING::TYPE_L4;
        break;
    case fapi2::TARGET_TYPE_CORE:
        o_class = TARGETING::CLASS_UNIT;
        o_type = TARGETING::TYPE_CORE;
        break;
    case fapi2::TARGET_TYPE_EQ:
        o_class = TARGETING::CLASS_UNIT;
        o_type = TARGETING::TYPE_EQ;
        break;
    case fapi2::TARGET_TYPE_MCA:
        o_class = TARGETING::CLASS_UNIT;
        o_type = TARGETING::TYPE_MCA;
        break;
    case fapi2::TARGET_TYPE_MCBIST:
        o_class = TARGETING::CLASS_UNIT;
        o_type = TARGETING::TYPE_MCBIST;
        break;
    case fapi2::TARGET_TYPE_MI:
        o_class = TARGETING::CLASS_UNIT;
        o_type = TARGETING::TYPE_MI;
        break;
    case fapi2::TARGET_TYPE_CAPP:
        o_class = TARGETING::CLASS_UNIT;
        o_type = TARGETING::TYPE_CAPP;
        break;
    case fapi2::TARGET_TYPE_DMI:
        o_class = TARGETING::CLASS_UNIT;
        o_type = TARGETING::TYPE_DMI;
        break;
    case fapi2::TARGET_TYPE_OBUS:
        o_class = TARGETING::CLASS_UNIT;
        o_type = TARGETING::TYPE_OBUS;
        break;
    case fapi2::TARGET_TYPE_NV:
        o_class = TARGETING::CLASS_UNIT;
        o_type = TARGETING::TYPE_NVBUS;
        break;
    case fapi2::TARGET_TYPE_SBE:
        o_class = TARGETING::CLASS_UNIT;
        o_type = TARGETING::TYPE_SBE;
        break;
    case fapi2::TARGET_TYPE_PPE:
        o_class = TARGETING::CLASS_UNIT;
        o_type = TARGETING::TYPE_PPE;
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
        if ( (i_childType & (TARGET_TYPE_EX     |
                             TARGET_TYPE_MCS    |
                             TARGET_TYPE_XBUS   |
                             TARGET_TYPE_ABUS   |
                             TARGET_TYPE_CORE   |
                             TARGET_TYPE_EQ     |
                             TARGET_TYPE_MCA    |
                             TARGET_TYPE_MCBIST |
                             TARGET_TYPE_MI     |
                             TARGET_TYPE_CAPP   |
                             TARGET_TYPE_DMI    |
                             TARGET_TYPE_OBUS   |
                             TARGET_TYPE_NV     |
                             TARGET_TYPE_SBE    |
                             TARGET_TYPE_PPE    |
                             TARGET_TYPE_PERV   |
                             TARGET_TYPE_PEC)) != 0 )
        {
            l_result = true;
        }
    }
    else if (i_parentType == TARGET_TYPE_MEMBUF_CHIP)
    {
        if ( (i_childType & (TARGET_TYPE_MBA | TARGET_TYPE_L4)) != 0 )
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

        TARGETING::Target * l_pRefTarget =
            reinterpret_cast<TARGETING::Target*>((*itr)->iv_refTarget.get());

        if ( ((l_hw == HwCallouts::TOD_CLOCK) ||
              (l_hw == HwCallouts::MEM_REF_CLOCK) ||
              (l_hw == HwCallouts::PROC_REF_CLOCK) ||
              (l_hw == HwCallouts::PCI_REF_CLOCK)) &&
             l_pRefTarget != NULL)
        {
            HWAS::clockTypeEnum l_clock =
                xlateClockHwCallout((*itr)->iv_hw);

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
                io_pError->addClockCallout(l_pRefTarget, l_clock, l_priority);
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
        TARGETING::Target * l_pTarget1 =
            reinterpret_cast<TARGETING::Target*>((*itr)->iv_target1.get());

        TARGETING::Target * l_pTarget2 =
            reinterpret_cast<TARGETING::Target*>((*itr)->iv_target2.get());

        HWAS::callOutPriority l_priority =
            xlateCalloutPriority((*itr)->iv_calloutPriority);

        bool l_busTypeValid = true;
        HWAS::busTypeEnum l_busType = HWAS::FSI_BUS_TYPE;
        TARGETING::TYPE l_type1 = l_pTarget1->getAttr<TARGETING::ATTR_TYPE>();
        TARGETING::TYPE l_type2 = l_pTarget2->getAttr<TARGETING::ATTR_TYPE>();

        if ( ((l_type1 == TARGETING::TYPE_MCS) &&
              (l_type2 == TARGETING::TYPE_MEMBUF)) ||
             ((l_type1 == TARGETING::TYPE_MEMBUF) &&
              (l_type2 == TARGETING::TYPE_MCS)) )
        {
            l_busType = HWAS::DMI_BUS_TYPE;
        }
        else if ((l_type1 == TARGETING::TYPE_ABUS) &&
                 (l_type2 == TARGETING::TYPE_ABUS))
        {
            l_busType = HWAS::A_BUS_TYPE;
        }
        else if ((l_type1 == TARGETING::TYPE_XBUS) &&
                 (l_type2 == TARGETING::TYPE_XBUS))
        {
            l_busType = HWAS::X_BUS_TYPE;
        }
        else
        {
            FAPI_ERR("processEIBusCallouts: Bus between target types not known (0x%08x:0x%08x)",
                     l_type1, l_type2);
            l_busTypeValid = false;
        }

        if (l_busTypeValid)
        {
            FAPI_DBG("processEIBusCallouts: Adding bus-callout"
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
        TARGETING::Target * l_pTarget =
            reinterpret_cast<TARGETING::Target*>((*itr)->iv_target.get());

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
///                            For DIMMs: MBA Port Number
///                            Else unused
/// @param[i] i_childNum     Child Number
///                            For DIMMs: DIMM Socket Number
///                            For Chips: Chip Position
///                            For Chiplets: Chiplet Position
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
        TARGETING::Target * l_pTargParent =
            reinterpret_cast<TARGETING::Target *>(i_parentTarget.get());

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
                if ( ((i_childPort == ErrorInfoChildrenCDG::ALL_CHILD_PORTS) ||
                      (i_childPort ==
                           (*l_itr)->getAttr<TARGETING::ATTR_MBA_PORT>()))
                &&
                     ((i_childNum == ErrorInfoChildrenCDG::ALL_CHILD_NUMBERS) ||
                      (i_childNum ==
                           (*l_itr)->getAttr<TARGETING::ATTR_MBA_DIMM>())) )
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
        uint64_t l_rcValue = io_rc;

        // ReturnCode contains an error. Find out which component of the HWPF
        // created the error
        ReturnCode::returnCodeCreator l_creator = io_rc.getCreator();
        if (l_creator == ReturnCode::CREATOR_PLAT)
        {
            // PLAT error, get the platform data from the return code
            FAPI_ERR("rcToErrl: PLAT error: 0x%08x", l_rcValue);
            l_pError = reinterpret_cast<errlHndl_t>(io_rc.getPlatDataPtr());
        }
        else if (l_creator == ReturnCode::CREATOR_HWP)
        {
            // HWP Error. Create an error log
            FAPI_ERR("rcToErrl: HWP error: 0x%08x", l_rcValue);

            /*@
             * @errortype
             * @moduleid     MOD_FAPI2_RC_TO_ERRL
             * @reasoncode   RC_HWP_GENERATED_ERROR
             * @userdata1    RC value from HWP
             * @userdata2    <unused>
             * @devdesc      HW Procedure generated error. See User Data.
             * @custdesc     Error initializing processor/memory subsystem
             *               during boot. See FRU list for repair actions
             */
            l_pError = new ERRORLOG::ErrlEntry(i_sev,
                                               MOD_FAPI2_RC_TO_ERRL,
                                               RC_HWP_GENERATED_ERROR,
                                               l_rcValue);

            // Add the rcValue as FFDC. This will explain what the error was
            l_pError->addFFDC(HWPF_COMP_ID, &l_rcValue, sizeof(l_rcValue), 1,
                    HWPF_FAPI2_UDT_HWP_RCVALUE);

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

        // add the fapi traces to the elog
        l_pError->collectTrace(FAPI_TRACE_NAME, 256 );
        l_pError->collectTrace(FAPI_IMP_TRACE_NAME, 384 );
        l_pError->collectTrace(FAPI_SCAN_TRACE_NAME, 256 );
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

    io_rc.setPlatDataPtr(reinterpret_cast<void *>(l_pError));

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
    FAPI_DBG("Entering logError" );

    createPlatLog( io_rc, i_sev );

    errlHndl_t l_pError = reinterpret_cast<errlHndl_t>(io_rc.getPlatDataPtr());

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

    return;
}

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
    nanosleep( 0, i_nanoSeconds );
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

} //end namespace
