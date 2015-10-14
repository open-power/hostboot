/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istepHelperFuncs.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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

#ifndef _ISTEP_HELPER_FUNCS_H
#define _ISTEP_HELPER_FUNCS_H

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <attributetraits.H>
#include    <attributeenums.H>
/**
 *  @brief Enum specifying what attributes should be used to set the
 *         memory _EFF_CONFIG attributes
 *
 */
enum EFF_CONFIG_ATTRIBUTES_BASE
{
    DEFAULT         = 0x00, ///< Use System Defaults
    POST_DRAM_INIT  = 0x01, ///< Use POST_DRAM_INIT attributes if non-zero
};


//
//  Helper function to set _EFF_CONFIG attributes for HWPs
//
void set_eff_config_attrs_helper( const EFF_CONFIG_ATTRIBUTES_BASE i_base,
                                  bool & o_post_dram_inits_found);


/**
 *  @brief Compares two memory buffer targets based on the voltage domain ID for
 *      the voltage domain given by the template parameter.  Used for sorting
 *      memory buffer targets within containers.  API should be called in well
 *      controlled conditions where the input restrictions can be guaranteed.
 *
 *  @param[in] i_pMembufLhs
 *      Left hand side memory buffer target.  Must be a memory buffer target,
 *      and must not be NULL.  These conditions are not enforced internally.
 *
 *  @param[in] i_pMembufRhs
 *      Right hand side memory buffer target.  Must be a memory buffer target,
 *      and must not be NULL.  These conditions are not enforced internally.
 *
 *  @tparam VOLTAGE_DOMAIN_ID_ATTR
 *      Attribute corresponding to voltage domain to compare
 *
 *  @return Bool indicating whether LHS memory buffer target's voltage domain ID
 *      for the specified domain logically precedes the RHS memory buffer
 *      target's voltage domain ID for the same domain
 */
template < const TARGETING::ATTRIBUTE_ID VOLTAGE_DOMAIN_ID_ATTR>
bool _compareMembufWrtVoltageDomain(
    TARGETING::Target* i_pMembufLhs,
    TARGETING::Target* i_pMembufRhs)
{
    typename TARGETING::AttributeTraits< VOLTAGE_DOMAIN_ID_ATTR >::Type
        lhsDomain = i_pMembufLhs->getAttr<VOLTAGE_DOMAIN_ID_ATTR>();
    typename TARGETING::AttributeTraits< VOLTAGE_DOMAIN_ID_ATTR >::Type
        rhsDomain = i_pMembufRhs->getAttr<VOLTAGE_DOMAIN_ID_ATTR>();

    return lhsDomain < rhsDomain;
}
//******************************************************************************
// setMemoryVoltageDomainOffsetVoltage
//******************************************************************************

// TODO via RTC: 110777
// Optimize setMemoryVoltageDomainOffsetVoltage into templated and non-templated
// pieces to reduce code size
/*
 * TODO: RTC:133830 Re-enable this function, the following ATTRs don't seem to
 * exist currently.
template< const ATTRIBUTE_ID OFFSET_DISABLEMENT_ATTR,
          const ATTRIBUTE_ID OFFSET_VOLTAGE_ATTR,
          const ATTRIBUTE_ID VOLTAGE_DOMAIN_ID_ATTR >
errlHndl_t setMemoryVoltageDomainOffsetVoltage()
{
    TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
        "setMemoryVoltageDomainOffsetVoltage enter");

    errlHndl_t pError = NULL;

    do {

    TARGETING::Target* pSysTarget = NULL;
    TARGETING::targetService().getTopLevelTarget(pSysTarget);
    assert(pSysTarget != NULL,"setMemoryVoltageDomainOffsetVoltage: "
                                        "System target was NULL.");

    typename AttributeTraits< OFFSET_DISABLEMENT_ATTR >::Type
        disableOffsetVoltage =
            pSysTarget->getAttr< OFFSET_DISABLEMENT_ATTR >();

    if(disableOffsetVoltage)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "INFO: Offset voltage processing disabled for domain type 0x%08X.",
            OFFSET_DISABLEMENT_ATTR);
        break;
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
        "INFO: Offset voltage processing enabled for domain type 0x%08X.",
        OFFSET_DISABLEMENT_ATTR);

    typedef fapi::ReturnCode (*pOffsetFn_t)(std::vector<fapi::Target>&);

    struct {

        TARGETING::ATTRIBUTE_ID domain;
        pOffsetFn_t             fn;
        const char*             fnName;
        bool                    callIfAllNonFunc;

    } fnMap[] = {

        {TARGETING::ATTR_AVDD_ID,
            mss_volt_avdd_offset,"mss_volt_avdd_offset", true},
        {TARGETING::ATTR_VDD_ID ,
            mss_volt_vdd_offset ,"mss_volt_vdd_offset", true},
        {TARGETING::ATTR_VCS_ID ,
            mss_volt_vcs_offset ,"mss_volt_vcs_offset", true},
        {TARGETING::ATTR_VMEM_ID,
            mss_volt_vddr_offset,"mss_volt_vddr_offset", false},
        {TARGETING::ATTR_VPP_ID ,
            mss_volt_vpp_offset ,"mss_volt_vpp_offset", false}
    };

    size_t recordIndex = 0;
    const size_t records = sizeof(fnMap)/sizeof(fnMap[0]);
    for(; recordIndex<records; ++recordIndex)
    {
        if(VOLTAGE_DOMAIN_ID_ATTR == fnMap[recordIndex].domain)
        {
            break;
        }
    }

    if(recordIndex >= records)
    {
        assert(recordIndex < records,
            "Code bug! Called setMemoryVoltageDomainOffsetVoltage "
            "using unsupported voltage offset attribute type of 0x%08X.",
            VOLTAGE_DOMAIN_ID_ATTR);
        break;
    }

    TARGETING::TargetHandleList membufTargetList;

    // Must pull ALL present memory buffers (not just functional) for these
    // computations
    getChipResources(membufTargetList, TYPE_MEMBUF,
        TARGETING::UTIL_FILTER_PRESENT);

    std::sort(membufTargetList.begin(), membufTargetList.end(),
        _compareMembufWrtVoltageDomain< VOLTAGE_DOMAIN_ID_ATTR >);

    std::vector<fapi::Target> membufFapiTargetsList;
    typename AttributeTraits< VOLTAGE_DOMAIN_ID_ATTR >::Type lastDomainId
        = 0;

    if(!membufTargetList.empty())
    {
        lastDomainId =
            (*membufTargetList.begin())->getAttr<VOLTAGE_DOMAIN_ID_ATTR>();
    }

    // O(n) algorithm to execute HWPs on groups of memory buffers.  As the
    // memory buffers are sorted in order of domain ID (several records in a row
    // might have same domain ID), walk down the list accumulating targets for
    // the HWP until the domain ID changes.  The first record is not considered
    // a change.  At the time the change is detected, run the HWP on the set of
    // accumulated targets, clear the list, and accumulate the target with a new
    // domain ID as the start of the new list.  When we hit end of list, we
    // might add this last target to a new accumulation, so we have to go back
    // through the loop one more time to process it (being careful not to do
    // unholy things to the iterator, etc.)

    // Prevent running the HWP on the first target.  Var is used to push us
    // through the loop after we exhausted all the targets
    bool last = membufTargetList.empty();
    for (TargetHandleList::const_iterator
            ppPresentMembuf = membufTargetList.begin();
         ((ppPresentMembuf != membufTargetList.end()) || (last == false));
         ++ppPresentMembuf)
    {
        // If no valid target to process, this is our last time through the loop
        last = (ppPresentMembuf == membufTargetList.end());

        typename AttributeTraits< VOLTAGE_DOMAIN_ID_ATTR >::Type
            currentDomainId = last ? lastDomainId :
                (*ppPresentMembuf)->getAttr<VOLTAGE_DOMAIN_ID_ATTR>();

        // Invoke the HWP if the domain ID in the sorted list change relative to
        // prior entry or this is our final time through the loop (and there is
        // a list entry to process)
        if(   (   (currentDomainId != lastDomainId)
               || (last))
           && (!membufFapiTargetsList.empty()) )
        {
            // Skip HWP if this domain has all deconfigured membufs and the
            // domain rule specifies not running the HWP for that case
            bool invokeHwp = true;
            if(fnMap[recordIndex].callIfAllNonFunc == false)
            {
                invokeHwp = false;
                TARGETING::PredicateIsFunctional funcPred;
                std::vector<fapi::Target>::const_iterator pFapiTarget =
                    membufFapiTargetsList.begin();
                for(;pFapiTarget != membufFapiTargetsList.end();++pFapiTarget)
                {
                    if(funcPred(
                           reinterpret_cast<const TARGETING::Target*>(
                               pFapiTarget->get())))
                    {
                        invokeHwp = true;
                        break;
                    }
                }
            }

            if(invokeHwp)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "INFO invoking %s on domain type 0x%08X, ID 0x%08X",
                    fnMap[recordIndex].fnName,
                    VOLTAGE_DOMAIN_ID_ATTR, lastDomainId);

                FAPI_INVOKE_HWP(
                    pError,
                    fnMap[recordIndex].fn,
                    membufFapiTargetsList);

                if (pError)
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "ERROR 0x%.8X: %s",
                        pError->reasonCode(),fnMap[recordIndex].fnName);
                    break;
                }
                else
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "SUCCESS : %s",fnMap[recordIndex].fnName );
                }
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "INFO not invoking %s on domain type 0x%08X, ID 0x%08X "
                    "since domain has no functional memory buffers.",
                    fnMap[recordIndex].fnName,
                    VOLTAGE_DOMAIN_ID_ATTR, lastDomainId);
            }

            membufFapiTargetsList.clear();

            lastDomainId = currentDomainId;
        }

        // If not the last time through loop, there is a new target to
        // accumulate
        if(!last)
        {
            const TARGETING::Target* pPresentMembuf = *ppPresentMembuf;

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "=====  add to fapi::Target vector attr type=0x%08X, "
                "id=0x%08X, target HUID=0x%08X",
                VOLTAGE_DOMAIN_ID_ATTR,
                pPresentMembuf->getAttr<VOLTAGE_DOMAIN_ID_ATTR>(),
                TARGETING::get_huid(pPresentMembuf));

            fapi::Target membufFapiTarget(fapi::TARGET_TYPE_MEMBUF_CHIP,
                (const_cast<TARGETING::Target*>(pPresentMembuf)) );

            membufFapiTargetsList.push_back(membufFapiTarget);
        }
        // Otherwise need to bail, lest we increment the iterator again, which
        // is undefined
        else
        {
            break;
        }
    }

    if(pError)
    {
        break;
    }

    } while(0);

    TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
        "setMemoryVoltageDomainOffsetVoltage exit");

    return pError;
}
*/
#endif
