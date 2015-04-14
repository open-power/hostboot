/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/plat/fapiPlatHwpInvoker.C $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2015                        */
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
 *  @file fapiPlatHwpInvoker.C
 *
 *  @brief Implements the fapiRcToErrl function.
 */

#include <fapiTarget.H>
#include <fapiReturnCode.H>
#include <fapiSystemConfig.H>
#include <fapiPlatTrace.H>
#include <fapiErrorInfo.H>
#include <hwpf/hwpf_reasoncodes.H>
#include <errl/errlentry.H>
#include <targeting/common/utilFilter.H>

namespace fapi
{

/**
 * @brief Translates a FAPI callout priority to an HWAS callout priority
 *
 * @param[i] i_fapiPri FAPI callout priority
 *
 * @return HWAS callout priority
 */
HWAS::callOutPriority xlateCalloutPriority(
    const fapi::CalloutPriorities::CalloutPriority i_fapiPri)
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
        FAPI_ERR("fapi::xlateCalloutPriority: Unknown priority 0x%x, assuming HIGH",
            i_fapiPri);
    }

    return l_priority;
}

/**
 * @brief Translates a FAPI Clock HW callout to an HWAS clock callout
 *
 * @param[i] i_fapiClock FAPI Clock HW callout
 *
 * @return HWAS Clock HW callout
 */
HWAS::clockTypeEnum xlateClockHwCallout(
    const fapi::HwCallouts::HwCallout i_fapiClock)
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

/**
 * @brief Translates a FAPI Part HW callout to an HWAS part callout
 *
 * @param[i] i_fapiPart FAPI part HW callout
 *
 * @return HWAS part HW callout
 */
HWAS::partTypeEnum xlatePartHwCallout(
    const fapi::HwCallouts::HwCallout i_fapiPart)
{
    // Use the HwCallout enum value as an index
    HWAS::partTypeEnum l_part;

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

         default:
               FAPI_ERR("fapi::xlatePartHwCallout: Unknown part",
                 i_fapiPart);
               l_part = HWAS::NO_PART_TYPE;
    }

    return l_part;
}
/**
 * @brief Translates a FAPI procedure callout to an HWAS procedure callout
 *
 * @param[i] i_fapiProc FAPI procedure callout
 *
 * @return HWAS procedure callout
 */
HWAS::epubProcedureID xlateProcedureCallout(
    const fapi::ProcedureCallouts::ProcedureCallout i_fapiProc)
{
    // Use the ProcedureCallout enum value as an index
    HWAS::epubProcedureID l_proc = HWAS::EPUB_PRC_HB_CODE;
    size_t l_index = i_fapiProc;

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
        FAPI_ERR("fapi::xlateProcedureCallout: Unknown proc 0x%x, assuming CODE",
            i_fapiProc);
    }

    return l_proc;
}

/**
 * @brief Translates a FAPI target type to a Targeting target type
 *
 * @param[i] i_targetType FAPI target type
 * @param[o] o_class      Targeting class
 * @param[o] o_type       Targeting type
 */
void xlateTargetType(const fapi::TargetType i_targetType,
                     TARGETING::CLASS & o_class,
                     TARGETING::TYPE & o_type)
{
    switch (i_targetType)
    {
    case fapi::TARGET_TYPE_SYSTEM:
        o_class = TARGETING::CLASS_SYS;
        o_type = TARGETING::TYPE_SYS;
        break;
    case fapi::TARGET_TYPE_DIMM:
        o_class = TARGETING::CLASS_LOGICAL_CARD;
        o_type = TARGETING::TYPE_DIMM;
        break;
    case fapi::TARGET_TYPE_PROC_CHIP:
        o_class = TARGETING::CLASS_CHIP;
        o_type = TARGETING::TYPE_PROC;
        break;
    case fapi::TARGET_TYPE_MEMBUF_CHIP:
        o_class = TARGETING::CLASS_CHIP;
        o_type = TARGETING::TYPE_MEMBUF;
        break;
    case fapi::TARGET_TYPE_EX_CHIPLET:
        o_class = TARGETING::CLASS_UNIT;
        o_type = TARGETING::TYPE_EX;
        break;
    case fapi::TARGET_TYPE_MBA_CHIPLET:
        o_class = TARGETING::CLASS_UNIT;
        o_type = TARGETING::TYPE_MBA;
        break;
    case fapi::TARGET_TYPE_MCS_CHIPLET:
        o_class = TARGETING::CLASS_UNIT;
        o_type = TARGETING::TYPE_MCS;
        break;
    case fapi::TARGET_TYPE_XBUS_ENDPOINT:
        o_class = TARGETING::CLASS_UNIT;
        o_type = TARGETING::TYPE_XBUS;
        break;
    case fapi::TARGET_TYPE_ABUS_ENDPOINT:
        o_class = TARGETING::CLASS_UNIT;
        o_type = TARGETING::TYPE_ABUS;
        break;
    case fapi::TARGET_TYPE_L4:
        o_class = TARGETING::CLASS_UNIT;
        o_type = TARGETING::TYPE_L4;
        break;
    default:
        o_class = TARGETING::CLASS_NA;
        o_type = TARGETING::TYPE_NA;
    }
}

/**
 * @brief Processes any FFDC in the ReturnCode Error Information and adds them
 *        to the error log
 *
 * @param[i] i_errInfo  Reference to ReturnCode Error Information
 * @param[io] io_pError Errorlog Handle
 */
void processEIFfdcs(const ErrorInfo & i_errInfo,
                    errlHndl_t io_pError)
{
    // Iterate through the FFDC sections, adding each to the error log
    uint32_t l_size = 0;

    for (ErrorInfo::ErrorInfoFfdcCItr_t l_itr = i_errInfo.iv_ffdcs.begin();
         l_itr != i_errInfo.iv_ffdcs.end(); ++l_itr)
    {
        const void * l_pFfdc = (*l_itr)->getData(l_size);
        uint32_t l_ffdcId = (*l_itr)->getFfdcId();

        // Add the FFDC ID as the first word, then the FFDC data
        FAPI_DBG("processEIFfdcs: Adding %d bytes of FFDC (id:0x%08x)", l_size,
                 l_ffdcId);
        ERRORLOG::ErrlUD * l_pUD = io_pError->addFFDC(
            HWPF_COMP_ID, &l_ffdcId, sizeof(l_ffdcId), 1, HWPF_UDT_HWP_FFDC);

        if (l_pUD)
        {
            io_pError->appendToFFDC(l_pUD, l_pFfdc, l_size);
        }
    }
}

/**
 * @brief Processes any HW callouts requests in the ReturnCode Error
 *        Information and adds them to the error log
 *
 * @param[i] i_errInfo  Reference to ReturnCode Error Information
 * @param[io] io_pError Errorlog Handle
 */
void processEIHwCallouts(const ErrorInfo & i_errInfo,
                         errlHndl_t io_pError)
{
    // Iterate through the HW callout requests, adding each to the error log
    for (ErrorInfo::ErrorInfoHwCalloutCItr_t l_itr =
             i_errInfo.iv_hwCallouts.begin();
         l_itr != i_errInfo.iv_hwCallouts.end(); ++l_itr)
    {
        HWAS::callOutPriority l_priority =
            xlateCalloutPriority((*l_itr)->iv_calloutPriority);

        HwCallouts::HwCallout l_hw = ((*l_itr)->iv_hw);

        TARGETING::Target * l_pRefTarget =
            reinterpret_cast<TARGETING::Target*>((*l_itr)->iv_refTarget.get());

        if ( ((l_hw == HwCallouts::TOD_CLOCK) ||
              (l_hw == HwCallouts::MEM_REF_CLOCK) ||
              (l_hw == HwCallouts::PROC_REF_CLOCK) ||
              (l_hw == HwCallouts::PCI_REF_CLOCK)) &&
             l_pRefTarget != NULL)
        {
            HWAS::clockTypeEnum l_clock =
                xlateClockHwCallout((*l_itr)->iv_hw);

            FAPI_ERR("processEIHwCallouts: Adding clock-callout"
                     " (clock:%d, pri:%d)",
                     l_clock, l_priority);

            //@fixme-RTC:127069-add native support to deconfig/gard clocks
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
                xlatePartHwCallout((*l_itr)->iv_hw);

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

/**
 * @brief Processes any Procedure callouts requests in the ReturnCode Error
 *        Information and adds them to the error log
 *
 * @param[i] i_errInfo  Reference to ReturnCode Error Information
 * @param[io] io_pError Errorlog Handle
 */
void processEIProcCallouts(const ErrorInfo & i_errInfo,
                           errlHndl_t io_pError)
{
    // Iterate through the procedure callout requests, adding each to the error
    // log
    for (ErrorInfo::ErrorInfoProcedureCalloutCItr_t l_itr =
             i_errInfo.iv_procedureCallouts.begin();
         l_itr != i_errInfo.iv_procedureCallouts.end(); ++l_itr)
    {
        HWAS::epubProcedureID l_procedure =
            xlateProcedureCallout((*l_itr)->iv_procedure);

        HWAS::callOutPriority l_priority =
            xlateCalloutPriority((*l_itr)->iv_calloutPriority);

        FAPI_DBG("processEIProcCallouts: Adding proc-callout"
                 " (proc:0x%02x, pri:%d)",
                 l_procedure, l_priority);
        io_pError->addProcedureCallout(l_procedure, l_priority);
    }
}

/**
 * @brief Processes any Bus callouts requests in the ReturnCode Error
 *        Information and adds them to the error log
 *
 * @param[i] i_errInfo  Reference to ReturnCode Error Information
 * @param[io] io_pError Errorlog Handle
 */
void processEIBusCallouts(const ErrorInfo & i_errInfo,
                          errlHndl_t io_pError)
{
    // Iterate through the bus callout requests, adding each to the error log
    for (ErrorInfo::ErrorInfoBusCalloutCItr_t l_itr =
             i_errInfo.iv_busCallouts.begin();
         l_itr != i_errInfo.iv_busCallouts.end(); ++l_itr)
    {
        TARGETING::Target * l_pTarget1 =
            reinterpret_cast<TARGETING::Target*>((*l_itr)->iv_target1.get());

        TARGETING::Target * l_pTarget2 =
            reinterpret_cast<TARGETING::Target*>((*l_itr)->iv_target2.get());

        HWAS::callOutPriority l_priority =
            xlateCalloutPriority((*l_itr)->iv_calloutPriority);

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

/**
 * @brief Processes any Callout/Deconfigure/GARD requests in the ReturnCode Error
 *        Information and adds them to the error log
 *
 * @param[i] i_errInfo  Reference to ReturnCode Error Information
 * @param[io] io_pError Errorlog Handle
 */
void processEICDGs(const ErrorInfo & i_errInfo,
                   errlHndl_t io_pError)
{
    // Iterate through the CGD requests, adding each to the error log
    for (ErrorInfo::ErrorInfoCDGCItr_t l_itr = i_errInfo.iv_CDGs.begin();
         l_itr != i_errInfo.iv_CDGs.end(); ++l_itr)
    {
        TARGETING::Target * l_pTarget =
            reinterpret_cast<TARGETING::Target*>((*l_itr)->iv_target.get());

        HWAS::callOutPriority l_priority =
            xlateCalloutPriority((*l_itr)->iv_calloutPriority);

        HWAS::DeconfigEnum l_deconfig = HWAS::NO_DECONFIG;
        if ((*l_itr)->iv_deconfigure)
        {
            l_deconfig = HWAS::DELAYED_DECONFIG;
        }

        HWAS::GARD_ErrorType l_gard = HWAS::GARD_NULL;
        if ((*l_itr)->iv_gard)
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

/**
 * @brief Returns child targets to Callout/Deconfigure/GARD
 *
 * @param[i] i_parentTarget FAPI Parent Target
 * @param[i] i_childType    FAPI Child Type
 * @param[i] i_childPort    Child Port Number
 *                            For DIMMs: MBA Port Number
 *                            Else unused
 * @param[i] i_childNum     Child Number
 *                            For DIMMs: DIMM Socket Number
 *                            For Chips: Chip Position
 *                            For Chiplets: Chiplet Position
 */
void getChildTargetsForCDG(const fapi::Target & i_parentTarget,
                           const fapi::TargetType i_childType,
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

        if (i_childType == fapi::TARGET_TYPE_DIMM)
        {
            l_childIsDimm = true;
        }
        else
        {
            l_childIsChip = fapi::Target::isChip(i_childType);

            if (!l_childIsChip)
            {
                l_childIsChiplet = fapi::Target::isChiplet(i_childType);
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

        if (fapi::Target::isPhysParentChild(i_parentTarget.getType(),
                                            i_childType))
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

/**
 * @brief Processes any Children Callout/Deconfigure/GARD requests in the
 *        ReturnCode Error Information and adds them to the error log
 *
 * @param[i] i_errInfo  Reference to ReturnCode Error Information
 * @param[io] io_pError Errorlog Handle
 */
void processEIChildrenCDGs(const ErrorInfo & i_errInfo,
                           errlHndl_t io_pError)
{
    // Iterate through the Child CGD requests, adding each to the error log
    for (ErrorInfo::ErrorInfoChildrenCDGCItr_t l_itr =
             i_errInfo.iv_childrenCDGs.begin();
         l_itr != i_errInfo.iv_childrenCDGs.end(); ++l_itr)
    {
        HWAS::callOutPriority l_priority =
            xlateCalloutPriority((*l_itr)->iv_calloutPriority);

        HWAS::DeconfigEnum l_deconfig = HWAS::NO_DECONFIG;
        if ((*l_itr)->iv_deconfigure)
        {
            l_deconfig = HWAS::DELAYED_DECONFIG;
        }

        HWAS::GARD_ErrorType l_gard = HWAS::GARD_NULL;
        if ((*l_itr)->iv_gard)
        {
            l_gard = HWAS::GARD_Unrecoverable;
        }

        // Get a list of children to callout
        TARGETING::TargetHandleList l_children;
        getChildTargetsForCDG((*l_itr)->iv_parent,
                              (*l_itr)->iv_childType,
                              (*l_itr)->iv_childPort,
                              (*l_itr)->iv_childNumber,
                              l_children);

        // Callout/Deconfigure/GARD each child as appropriate
        for (TARGETING::TargetHandleList::const_iterator
                l_itr = l_children.begin();
                l_itr != l_children.end(); ++l_itr)
        {
            FAPI_DBG("processEIChildrenCDGs: Calling out target"
                     " (huid:%.8x, pri:%d, deconf:%d, gard:%d)",
                     TARGETING::get_huid(*l_itr), l_priority, l_deconfig,
                     l_gard);
            io_pError->addHwCallout(*l_itr, l_priority, l_deconfig, l_gard);
        }
    }
}

//******************************************************************************
// fapiRcToErrl function. Converts a fapi::ReturnCode to an error log
//******************************************************************************
errlHndl_t fapiRcToErrl(ReturnCode & io_rc,
                        ERRORLOG::errlSeverity_t i_sev)
{
    errlHndl_t l_pError = NULL;

    if (io_rc)
    {
        // ReturnCode contains an error. Find out which component of the HWPF
        // created the error
        ReturnCode::returnCodeCreator l_creator = io_rc.getCreator();

        if (l_creator == ReturnCode::CREATOR_PLAT)
        {
            // PLAT error. Release the errlHndl_t
            FAPI_ERR("fapiRcToErrl: PLAT error: 0x%08x",
                    static_cast<uint32_t>(io_rc));
            l_pError = reinterpret_cast<errlHndl_t> (io_rc.releasePlatData());
        }
        else if (l_creator == ReturnCode::CREATOR_HWP)
        {
            // HWP Error. Create an error log
            uint32_t l_rcValue = static_cast<uint32_t>(io_rc);
            FAPI_ERR("fapiRcToErrl: HWP error: 0x%08x", l_rcValue);

            /*@
             * @errortype
             * @moduleid     MOD_HWP_RC_TO_ERRL
             * @reasoncode   RC_HWP_GENERATED_ERROR
             * @userdata1    RC value from HWP
             * @userdata2    <unused>
             * @devdesc      HW Procedure generated error. See User Data.
             * @custdesc     Error initializing processor/memory subsystem
             *               during boot. See FRU list for repair actions
             */
            l_pError = new ERRORLOG::ErrlEntry(i_sev,
                                               MOD_HWP_RC_TO_ERRL,
                                               RC_HWP_GENERATED_ERROR,
                                               TO_UINT64(l_rcValue));

            // Add the rcValue as FFDC. This will explain what the error was
            l_pError->addFFDC(HWPF_COMP_ID, &l_rcValue, sizeof(l_rcValue), 1,
                    HWPF_UDT_HWP_RCVALUE);

            // Get the Error Information Pointer
            const ErrorInfo * l_pErrorInfo = io_rc.getErrorInfo();

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
                FAPI_ERR("fapiRcToErrl: No Error Information");
            }
        }
        else
        {
            // FAPI error. Create an error log
            FAPI_ERR("fapiRcToErrl: FAPI error: 0x%08x",
                     static_cast<uint32_t>(io_rc));

            // The errlog reason code is the HWPF compID and the rcValue LSB
            uint32_t l_rcValue = static_cast<uint32_t>(io_rc);
            uint16_t l_reasonCode = l_rcValue;
            l_reasonCode &= 0xff;
            l_reasonCode |= HWPF_COMP_ID;

            // HostBoot errlog tags for FAPI errors are in hwpfReasonCodes.H
            l_pError = new ERRORLOG::ErrlEntry(i_sev,
                                               MOD_FAPI_RC_TO_ERRL,
                                               l_reasonCode);

            // FAPI may have added Error Information.
            // Get the Error Information Pointer
            const ErrorInfo * l_pErrorInfo = io_rc.getErrorInfo();

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

        // Set the ReturnCode to success, this will delete any ErrorInfo or PLAT
        // DATA associated with the ReturnCode
        io_rc = FAPI_RC_SUCCESS;

        // add the fapi traces to the elog
        l_pError->collectTrace(FAPI_TRACE_NAME, 256 );
        l_pError->collectTrace(FAPI_IMP_TRACE_NAME, 384 );
        l_pError->collectTrace(FAPI_SCAN_TRACE_NAME, 256 );
    }

    return l_pError;
}

} // End namespace
