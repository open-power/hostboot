/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/plat/fapiPlatHwpInvoker.C $                      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
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
        HWAS::EPUB_PRC_MEMORY_PLUGGING_ERROR};

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
void getChildTargetsForCDG(
        TARGETING::Target * i_pParent, TARGETING::TYPE i_childType,
        TARGETING::TargetHandleList & o_childTargets, uint8_t i_childPort,
        uint8_t i_childNumber);

/**
 * @brief Translates a FAPI target type to a Targeting target type
 *
 * @param[i] i_targetType FAPI target type
 *
 * @return TARGETING type
 */
TARGETING::TYPE xlateTargetType(
    const fapi::TargetType i_targetType)
{
    TARGETING::TYPE l_type = TARGETING::TYPE_NA;

    switch (i_targetType)
    {
    case fapi::TARGET_TYPE_SYSTEM:
        l_type = TARGETING::TYPE_SYS;
        break;
    case fapi::TARGET_TYPE_DIMM:
        l_type = TARGETING::TYPE_DIMM;
        break;
    case fapi::TARGET_TYPE_PROC_CHIP:
        l_type = TARGETING::TYPE_PROC;
        break;
    case fapi::TARGET_TYPE_MEMBUF_CHIP:
        l_type = TARGETING::TYPE_MEMBUF;
        break;
    case fapi::TARGET_TYPE_EX_CHIPLET:
        l_type = TARGETING::TYPE_EX;
        break;
    case fapi::TARGET_TYPE_MBA_CHIPLET:
        l_type = TARGETING::TYPE_MBA;
        break;
    case fapi::TARGET_TYPE_MCS_CHIPLET:
        l_type = TARGETING::TYPE_MCS;
        break;
    case fapi::TARGET_TYPE_XBUS_ENDPOINT:
        l_type = TARGETING::TYPE_XBUS;
        break;
    case fapi::TARGET_TYPE_ABUS_ENDPOINT:
        l_type = TARGETING::TYPE_ABUS;
        break;
    case fapi::TARGET_TYPE_L4:
        l_type = TARGETING::TYPE_L4;
        break;
    default:
        l_type = TARGETING::TYPE_NA;
        break;
    }

    return l_type;
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
        FAPI_ERR("processEIFfdcs: Adding %d bytes of FFDC (id:0x%08x)", l_size,
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

            FAPI_ERR("processEIHwCallouts: Adding clock-callout (clock:%d, pri:%d)",
                     l_clock, l_priority);
            io_pError->addClockCallout(l_pRefTarget, l_clock, l_priority);
        }
        else
        {
            FAPI_ERR("processEIHwCallouts: Unsupported HW callout (%d)", l_hw);
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

        FAPI_ERR("processEIProcCallouts: Adding proc-callout (proc:0x%02x, pri:%d)",
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
            FAPI_ERR("processEIBusCallouts: Adding bus-callout (bus:%d, pri:%d)",
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

        FAPI_ERR("processEICDGs: Calling out target (pri:%d, deconf:%d, gard:%d)",
                 l_priority, l_deconfig, l_gard);
        io_pError->addHwCallout(l_pTarget, l_priority, l_deconfig, l_gard);
    }
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

        uint8_t l_childNumber = (*l_itr)->iv_childNumber;
        uint8_t l_childPort = (*l_itr)->iv_childPort;

        TARGETING::TYPE l_childType =
            xlateTargetType((*l_itr)->iv_childType);

        if (l_childType == TARGETING::TYPE_NA)
        {
            FAPI_ERR("processEIChildrenCDGs: Could not xlate child type (0x%08x)",
                     (*l_itr)->iv_childType);
        }
        else
        {
            TARGETING::Target * l_pParent =
                reinterpret_cast<TARGETING::Target *>
                ((*l_itr)->iv_parent.get());

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

            // Get a list of functional children
            TARGETING::TargetHandleList l_children;

            getChildTargetsForCDG( l_pParent, l_childType, l_children,
                                   l_childPort, l_childNumber );

            // Callout/Deconfigure/GARD each child as appropriate
            for (TARGETING::TargetHandleList::const_iterator
                    l_itr = l_children.begin();
                    l_itr != l_children.end(); ++l_itr)
            {

                FAPI_ERR("processEIChildrenCDGs: Calling out target"
                         " (type: 0x%02x, pri:%d, deconf:%d, gard:%d)",
                         l_childType, l_priority, l_deconfig, l_gard);
                io_pError->addHwCallout(*l_itr, l_priority, l_deconfig, l_gard);
            }
        }
    }
}

void getChildTargetsForCDG(
        TARGETING::Target * i_pParent, TARGETING::TYPE i_childType,
        TARGETING::TargetHandleList & o_childTargets, uint8_t i_childPort,
        uint8_t i_childNumber )
{
    o_childTargets.clear();
    bool l_functional = true;

    // dimms are not considered as a chiplet but
    // a logical card so we need special processing here
    if( i_childType == TARGETING::TYPE_DIMM )
    {
        TARGETING::TargetHandleList l_dimmList;

        TARGETING:: getChildAffinityTargets( l_dimmList, i_pParent,
                TARGETING::CLASS_LOGICAL_CARD,
                TARGETING::TYPE_DIMM, l_functional);

        for (TARGETING::TargetHandleList::const_iterator
                l_itr = l_dimmList.begin();
                l_itr != l_dimmList.end();
                ++l_itr)
        {

            uint8_t l_mbaPort =
                (*l_itr)->getAttr<TARGETING::ATTR_MBA_PORT>();

            uint8_t l_mbaDimm =
                (*l_itr)->getAttr<TARGETING::ATTR_MBA_DIMM>();

            // if childPort was not set in the callout
            // the caller is trying to callout either all dimms
            // connected to this MBA or a specific dimm number on both
            // ports
            if( i_childPort == FAPI_ALL_MBA_PORTS )
            {
                // if the caller reqested all children on all ports
                // or if this dimm matches the requested dimm on
                // either port then add it
                if( ( i_childNumber == FAPI_ALL_MBA_DIMMS ) ||
                        ( i_childNumber == l_mbaDimm ))
                {
                    FAPI_DBG("adding callout for i_childNumber=%d "
                            "and i_childPort %d ",
                            i_childNumber, i_childPort );

                    o_childTargets.push_back( *l_itr );
                }
            }
            else
            {
                // if caller requested all dimms on a specific port or if this
                // child is the one requested then add it
                if((( i_childNumber == FAPI_ALL_MBA_DIMMS ) ||
                            ( i_childNumber == l_mbaDimm )) &&
                            ( i_childPort == l_mbaPort ))
                {
                    FAPI_DBG("adding callout for i_childNumber=%d "
                            " and i_childPort %d",
                            i_childNumber, i_childPort );

                    o_childTargets.push_back( *l_itr );
                }
            }
        }
    }
    else
    {
        TARGETING::getChildChiplets(o_childTargets, i_pParent, i_childType);
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
        l_pError->collectTrace(FAPI_IMP_TRACE_NAME, 256 );
        l_pError->collectTrace(FAPI_SCAN_TRACE_NAME, 256 );
    }

    return l_pError;
}

} // End namespace
