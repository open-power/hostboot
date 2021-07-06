/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/fapi2/src/error_info.C $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2021                        */
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
 *  @file error_info.C
 *  @brief Implements the error information classes
 */

#include <stdint.h>
#include <string.h>
#include <plat_trace.H>
#include <error_info.H>
#include <buffer.H>

//explicitly declare for space as these templates are used everywhere
template class std::shared_ptr<fapi2::ErrorInfo>;
template class std::shared_ptr<fapi2::ErrorInfoFfdc>;

namespace fapi2
{
///
/// @brief Constructor
///
/// @param[in] i_ffdcId FFDC Identifier (used to decode FFDC)
/// @param[in] i_pFfdc  Pointer to the FFDC to copy
/// @param[in] i_size   Size of the FFDC to copy
///
ErrorInfoFfdc::ErrorInfoFfdc(const uint32_t i_ffdcId,
                             const void*    i_pFfdc,
                             const uint32_t i_size):
    iv_ffdcId(i_ffdcId),
    iv_size(i_size)
{
    iv_pFfdc = std::shared_ptr<uint8_t>(new uint8_t[i_size]());

    // If they passed us a NULL pointer they want to fill
    // in the data themselves later.
    if (i_pFfdc != nullptr)
    {
        memcpy(iv_pFfdc.get(), i_pFfdc, i_size);
    }
}

///
/// @brief Constructor.
///
/// @param[in] i_hw              Hardware to callout
/// @param[in] i_calloutPriority Priority of callout
/// @param[in] i_refTarget       Reference to reference target
/// @param[in[ i_clkPos          Clock position
///
ErrorInfoHwCallout::ErrorInfoHwCallout(
    const HwCallouts::HwCallout i_hw,
    const CalloutPriorities::CalloutPriority i_calloutPriority,
    const Target<TARGET_TYPE_ALL>& i_refTarget,
    const uint8_t i_clkPos):
    iv_hw(i_hw),
    iv_calloutPriority(i_calloutPriority),
    iv_refTarget(i_refTarget),
    iv_clkPos(i_clkPos)
{}

///
/// @brief Constructor.
///
/// @param[in] i_procedure        Procedure to callout
/// @param[in] i_calloutPriority  Priority of callout
///
ErrorInfoProcedureCallout::ErrorInfoProcedureCallout(
    const ProcedureCallouts::ProcedureCallout i_procedure,
    const CalloutPriorities::CalloutPriority i_calloutPriority):
    iv_procedure(i_procedure),
    iv_calloutPriority(i_calloutPriority)
{}

///
/// @brief Constructor.
///
/// @param[in] i_target1          Reference to target on one end of the bus
/// @param[in] i_target2          Reference to target on other end of the bus
/// @param[in] i_calloutPriority  Priority of callout
///
ErrorInfoBusCallout::ErrorInfoBusCallout(
    const Target<TARGET_TYPE_ALL>& i_target1,
    const Target<TARGET_TYPE_ALL>& i_target2,
    const CalloutPriorities::CalloutPriority i_calloutPriority):
    iv_target1(i_target1),
    iv_target2(i_target2),
    iv_calloutPriority(i_calloutPriority)
{}

///
/// @brief Constructor.
///
/// @param[in] i_target      Reference to the target to c/d/g
/// @param[in] i_callout     True if Target should be called out
/// @param[in] i_deconfigure True if Target should be deconfigured
/// @param[in] i_gard        True if Target should be GARDed
/// @param[in] i_priority    The priority of any callout
/// @param[in] i_gardType    Type of GARD
///
ErrorInfoCDG::ErrorInfoCDG(
    const Target<TARGET_TYPE_ALL>& i_target,
    const bool i_callout,
    const bool i_deconfigure,
    const bool i_gard,
    const CalloutPriorities::CalloutPriority i_priority,
    const GardTypes::GardType i_gardType):
    iv_target(i_target),
    iv_callout(i_callout),
    iv_calloutPriority(i_priority),
    iv_deconfigure(i_deconfigure),
    iv_gard(i_gard),
    iv_gardType(i_gardType)
{}

///
/// @brief Constructor.
///
/// @param[in] i_parent      Reference to the parent target
/// @oaram[in] i_childType   Child target type to c/d/g
/// @param[in] i_callout     True if Target should be called out
/// @param[in] i_deconfigure True if Target should be deconfigured
/// @param[in] i_gard        True if Target should be GARDed
/// @param[in] i_priority    The priority of any callout
/// @param[in] i_childPort   Child Port
///                            For DIMM children, the MBA port number
/// @param[in] i_childNum    Child Number
///                            For DIMM children, the dimm socket number
///                            For Chip children, the chip position
///                            For Chiplet children, the chiplet unit pos
///
ErrorInfoChildrenCDG::ErrorInfoChildrenCDG(
    const Target<TARGET_TYPE_ALL>& i_parentChip,
    const TargetType i_childType,
    const bool i_callout,
    const bool i_deconfigure,
    const bool i_gard,
    const CalloutPriorities::CalloutPriority i_priority,
    const uint8_t i_childPort, const uint8_t i_childNum):
    iv_parent(i_parentChip),
    iv_childType(i_childType),
    iv_callout(i_callout),
    iv_calloutPriority(i_priority),
    iv_deconfigure(i_deconfigure),
    iv_gard(i_gard),
    iv_childPort(i_childPort),
    iv_childNumber(i_childNum)
{}

///
/// @brief Constructor.
///
/// @param[in] i_trace
///
ErrorInfoCollectTrace::ErrorInfoCollectTrace(
    CollectTraces::CollectTrace i_traceId):
    iv_eiTraceId(i_traceId)
{}

static void handleNullObjectPointer(const char* const i_function_name,
                                    const int i_object_index)
{
    FAPI_ERR("%s: NULL FFDC object pointer at index %d! This is indicative of a code bug in a HWP.",
             i_function_name,
             i_object_index);
}

///
/// @brief Collect target, buffer or generic FFDC information to this ffdc
/// object
/// @param[in] A pointer to the error info we're collecting
/// @param[in] A pointer to the objects
/// @return void
///
void ErrorInfoEntryFfdc::addErrorInfo(std::shared_ptr<ErrorInfo> i_info,
                                      const void* const* i_objects) const
{
    if (!i_objects[iv_ffdcObjIndex])
    {
        handleNullObjectPointer("ErrorInfoEntryFfdc::addErrorInfo", iv_ffdcObjIndex);
        return;
    }

    switch(iv_ffdcSize)
    {

        case EI_FFDC_SIZE_TARGET:
            {
                Target<TARGET_TYPE_ALL> object =
                    *(static_cast<const Target<TARGET_TYPE_ALL>*>
                      (i_objects[iv_ffdcObjIndex]));

                // Allocate an ErrorInfoFfdc but don't copy anything in to it.
                // We can copy the target string once if we copy directly into
                // the error info
                ErrorInfoFfdc* e =
                    new ErrorInfoFfdc(iv_ffdcId, nullptr, MAX_ECMD_STRING_LEN);

                toString(object, static_cast<char*>(e->getData()),
                         MAX_ECMD_STRING_LEN);
                i_info->iv_ffdcs.push_back(std::shared_ptr<ErrorInfoFfdc>(e));

                FAPI_DBG("addErrorInfo: Adding target ffdc id: 0x%x %s",
                         iv_ffdcId, static_cast<char*>(e->getData()));
            }
            break;

        default:
            i_info->iv_ffdcs.push_back(std::shared_ptr<ErrorInfoFfdc>(
                                           new ErrorInfoFfdc(
                                               iv_ffdcId,
                                               i_objects[iv_ffdcObjIndex],
                                               iv_ffdcSize)));
            FAPI_DBG("addErrorInfo: Adding ffdc id 0x%x size: %d",
                     iv_ffdcId, iv_ffdcSize);
            break;

    };

    return;
}

///
/// @brief Collect h/w callout FFDC information to this ffdc
/// object
/// @param[in] A pointer to the error info we're collecting
/// @param[in] A pointer to the objects
/// @return void
///
void ErrorInfoEntryHwCallout::addErrorInfo(std::shared_ptr<ErrorInfo> i_info,
        const void* const* i_object) const
{
    // If the index is 0xFF, we use an empty target. Otherwise the
    // target is taken from the object arrary with the given index.
    if (iv_refObjIndex != 0xFF && !i_object[iv_refObjIndex])
    {
        handleNullObjectPointer("ErrorInfoEntryHwCallout::addErrorInfo", iv_refObjIndex);
        return;
    }

    const fapi2::Target<TARGET_TYPE_ALL> target =
        iv_refObjIndex == 0xFF ?
        fapi2::Target<TARGET_TYPE_ALL>() :
        *(static_cast<const fapi2::Target<TARGET_TYPE_ALL>*>
          (i_object[iv_refObjIndex]));

    ErrorInfoHwCallout* ei = new ErrorInfoHwCallout(
        static_cast<HwCallouts::HwCallout>(iv_hw),
        static_cast<CalloutPriorities::CalloutPriority>(iv_calloutPriority),
        target,
        iv_clkPos);

    FAPI_DBG("addErrorInfo: Adding hw callout target: 0x%lx hw: %d, pri: %d, pos: %d",
             ei->iv_refTarget.get(), ei->iv_hw, ei->iv_calloutPriority, ei->iv_clkPos);

    i_info->iv_hwCallouts.push_back(std::shared_ptr<ErrorInfoHwCallout>(ei));
}

///
/// @brief Collect proc callout FFDC information to this ffdc
/// object
/// @param[in] A pointer to the error info we're collecting
/// @param[in] A pointer to the objects
/// @return void
///
void ErrorInfoEntryProcCallout::addErrorInfo(
    std::shared_ptr<ErrorInfo> i_info,
    const void* const* ) const
{
    ErrorInfoProcedureCallout* ei = new ErrorInfoProcedureCallout(
        static_cast<ProcedureCallouts::ProcedureCallout>(iv_procedure),
        static_cast<CalloutPriorities::CalloutPriority>(iv_calloutPriority));

    // Add the ErrorInfo
    FAPI_DBG("addErrorInfo: Adding proc callout, proc: %d, pri: %d",
             ei->iv_procedure, ei->iv_calloutPriority);

    i_info->iv_procedureCallouts.push_back(
        std::shared_ptr<ErrorInfoProcedureCallout>(ei));
}

///
/// @brief Collect bus callout FFDC information to this ffdc
/// object
/// @param[in] A pointer to the error info we're collecting
/// @param[in] A pointer to the objects
/// @return void
///
void ErrorInfoEntryBusCallout::addErrorInfo(
    std::shared_ptr<ErrorInfo> i_info,
    const void* const* i_object) const
{
    if (!i_object[iv_endpoint1ObjIndex])
    {
        handleNullObjectPointer("ErrorInfoEntryBusCallout::addErrorInfo", iv_endpoint1ObjIndex);
        return;
    }

    if (!i_object[iv_endpoint2ObjIndex])
    {
        handleNullObjectPointer("ErrorInfoEntryBusCallout::addErrorInfo", iv_endpoint2ObjIndex);
        return;
    }

    // We need to add a procedure callout as well as a bus callout
    ErrorInfoEntryProcCallout(ProcedureCallouts::BUS_CALLOUT,
                              iv_calloutPriority).addErrorInfo(i_info,
                                      i_object);

    // Now add our bus callout, but drop the priority by one.
    ErrorInfoBusCallout* ei = new ErrorInfoBusCallout(
        // First target
        * (static_cast<const fapi2::Target<TARGET_TYPE_ALL>*>
           (i_object[iv_endpoint1ObjIndex])),

        // Second target
        * (static_cast<const fapi2::Target<TARGET_TYPE_ALL>*>
           (i_object[iv_endpoint2ObjIndex])),

        // Priority, one lower.
        (iv_calloutPriority == CalloutPriorities::HIGH) ?
        CalloutPriorities::MEDIUM : CalloutPriorities::LOW);

    FAPI_DBG("addErrorInfo: Adding bus callout pri: %d", ei->iv_calloutPriority);

    i_info->iv_busCallouts.push_back(
        std::shared_ptr<ErrorInfoBusCallout>(ei));
}

///
/// @brief Collect h/w target cdg FFDC information to this ffdc
/// object
/// @param[in] A pointer to the error info we're collecting
/// @param[in] A pointer to the objects
/// @return void
///
void ErrorInfoEntryTargetCDG::addErrorInfo(
    std::shared_ptr<ErrorInfo> i_info,
    const void* const* i_object) const
{
    if (!i_object[iv_targetObjIndex])
    {
        handleNullObjectPointer("ErrorInfoEntryTargetCDG::addErrorInfo", iv_targetObjIndex);
        return;
    }

    ErrorInfoCDG* ei = new
    ErrorInfoCDG(
        *(static_cast<const fapi2::Target<TARGET_TYPE_ALL>*>
          (i_object[iv_targetObjIndex])),
        iv_callout,
        iv_deconfigure,
        iv_gard,
        static_cast<CalloutPriorities::CalloutPriority>
        (iv_calloutPriority),
        static_cast<GardTypes::GardType>(iv_gardType)
    );

    FAPI_INF("addErrorInfo: Adding cdg (%d:%d:%d), pri: %d, gtyp: %d",
             ei->iv_callout, ei->iv_deconfigure,
             ei->iv_gard, ei->iv_calloutPriority,
             ei->iv_gardType);

    // Add the ErrorInfo
    i_info->iv_CDGs.push_back(std::shared_ptr<ErrorInfoCDG>(ei));
}

///
/// @brief Collect h/w children cdg FFDC information to this ffdc
/// object
/// @param[in] A pointer to the error info we're collecting
/// @param[in] A pointer to the objects
/// @return void
///
void ErrorInfoEntryChildrenCDG::addErrorInfo(
    std::shared_ptr<ErrorInfo> i_info,
    const void* const* i_object) const
{
    if (!i_object[iv_parentObjIndex])
    {
        handleNullObjectPointer("ErrorInfoEntryChildrenCDG::addErrorInfo", iv_parentObjIndex);
        return;
    }

    ErrorInfoChildrenCDG* ei = new ErrorInfoChildrenCDG(
        *(static_cast<const fapi2::Target<TARGET_TYPE_ALL>*>
          (i_object[iv_parentObjIndex])),
        static_cast<fapi2::TargetType>(iv_childType),
        iv_callout,
        iv_deconfigure,
        iv_gard,
        static_cast<CalloutPriorities::CalloutPriority>
        (iv_calloutPriority),
        iv_childPort,
        iv_childNumber);

    FAPI_DBG("addErrorInfo: Adding children cdg (%d:%d:%d), type:"
             " 0x%.16lX, pri: %d",
             ei->iv_callout, ei->iv_deconfigure, ei->iv_gard,
             ei->iv_childType, ei->iv_calloutPriority);

    // Add the ErrorInfo
    i_info->iv_childrenCDGs.push_back(
        std::shared_ptr<ErrorInfoChildrenCDG>(ei));
}

///
/// @brief Collect trace information to this ffdc
/// object
/// @param[in] A pointer to the error info we're collecting
/// @param[in] A pointer to the objects
/// @return void
///
void ErrorInfoEntryCollectTrace::addErrorInfo(
    std::shared_ptr<ErrorInfo> i_info,
    const void* const* ) const
{
    ErrorInfoCollectTrace* ei = new ErrorInfoCollectTrace(
        static_cast<CollectTraces::CollectTrace>(iv_eieTraceId));

    FAPI_DBG("addErrorInfo: Adding trace: 0x%x", ei->iv_eiTraceId);

    // Add the ErrorInfo
    i_info->iv_traces.push_back(std::shared_ptr<ErrorInfoCollectTrace>(ei));
}

};
