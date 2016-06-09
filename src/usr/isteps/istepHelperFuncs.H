/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istepHelperFuncs.H $                           */
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

#ifndef _ISTEP_HELPER_FUNCS_H
#define _ISTEP_HELPER_FUNCS_H

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <attributetraits.H>
#include    <attributeenums.H>
#include    <initservice/isteps_trace.H>
#include    <fapi2.H>

// fapi2 HWP invoker
#include  <fapi2/plat_hwp_invoker.H>

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

/**
 *  @brief Enum for per-domain control of different voltages
 */
enum MSS_PROGRAM_TYPE
{
    POWERON = 0, // domain is programmed as part of regular power on sequence
    STATIC  = 1, // domain needs to be programmed, no special computation needed
    DYNAMIC = 2, // domain needs to be programmed, uses dynamic vid logic
};

//
//  Helper function to set _EFF_CONFIG attributes for HWPs
//
void set_eff_config_attrs_helper( const EFF_CONFIG_ATTRIBUTES_BASE i_base,
                                  bool & o_post_dram_inits_found);


/**
 *  @brief Compares two mcbist targets based on the voltage domain ID for
 *      the voltage domain given by the template parameter.  Used for sorting
 *      mcbist targets within containers.  API should be called in well
 *      controlled conditions where the input restrictions can be guaranteed.
 *
 *  @param[in] i_pMcbistLhs
 *      Left hand side mcbist target.  Must be a mcbist target,
 *      and must not be NULL.  These conditions are not enforced internally.
 *
 *  @param[in] i_pMcbistRhs
 *      Right hand side mcbist target.  Must be a mcbist target,
 *      and must not be NULL.  These conditions are not enforced internally.
 *
 *  @tparam VOLTAGE_DOMAIN_ID_ATTR
 *      Attribute corresponding to voltage domain to compare
 *
 *  @return Bool indicating whether LHS mcbist target's voltage domain ID
 *      for the specified domain logically precedes the RHS mcbist
 *      target's voltage domain ID for the same domain
 */
template < const TARGETING::ATTRIBUTE_ID VOLTAGE_DOMAIN_ID_ATTR>
bool _compareMcbistWrtVoltageDomain(
    TARGETING::Target* i_pMcbistLhs,
    TARGETING::Target* i_pMcbistRhs)
{
    typename TARGETING::AttributeTraits< VOLTAGE_DOMAIN_ID_ATTR >::Type
        lhsDomain = i_pMcbistLhs->getAttr<VOLTAGE_DOMAIN_ID_ATTR>();
    typename TARGETING::AttributeTraits< VOLTAGE_DOMAIN_ID_ATTR >::Type
        rhsDomain = i_pMcbistRhs->getAttr<VOLTAGE_DOMAIN_ID_ATTR>();

    return lhsDomain < rhsDomain;
}


//******************************************************************************
// computeDynamicMemoryVoltage
//******************************************************************************

// TODO via RTC: 110777
// Optimize computeDynamicMemoryVoltage into templated and non-templated
// pieces to reduce code size
template< const TARGETING::ATTRIBUTE_ID OFFSET_DISABLEMENT_ATTR,
          const TARGETING::ATTRIBUTE_ID VOLTAGE_DOMAIN_ID_ATTR >
errlHndl_t computeDynamicMemoryVoltage()
{
  TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            "computeDynamicMemoryVoltage enter");

  errlHndl_t pError = NULL;

  do
  {
    TARGETING::Target* pSysTarget = NULL;
    TARGETING::targetService().getTopLevelTarget(pSysTarget);
    assert(pSysTarget != NULL,
           "computeDynamicMemoryVoltage: System target was NULL.");

    typename TARGETING::AttributeTraits< OFFSET_DISABLEMENT_ATTR >::Type
        domainProgram =
            pSysTarget->getAttr< OFFSET_DISABLEMENT_ATTR >();


    if(domainProgram != MSS_PROGRAM_TYPE::DYNAMIC)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "INFO: Dynamic offset voltage processing disabled for domain type 0x%08X.",
            OFFSET_DISABLEMENT_ATTR);
        break;
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
        "INFO: Offset voltage processing enabled for domain type 0x%08X.",
        OFFSET_DISABLEMENT_ATTR);

    typedef fapi2::ReturnCode (*pOffsetFn_t)(std::vector<fapi2::Target<fapi2::TARGET_TYPE_MCS>>&);

    struct {

        TARGETING::ATTRIBUTE_ID domain;
        pOffsetFn_t             fn;
        const char*             fnName;
        bool                    callIfAllNonFunc;

    } fnMap[] = {
/* TODO: RTC 157349 -- These HWPs don't exist yet
        {TARGETING::ATTR_AVDD_ID,
            p9_mss_dynamic_vid_avdd,"p9_mss_dynamic_vid_avdd", true},
        {TARGETING::ATTR_VDD_ID ,
            p9_mss_dynamic_vid_vdd ,"p9_mss_dynamic_vid_vdd", true},
        {TARGETING::ATTR_VCS_ID ,
            p9_mss_dynamic_vcs_avdd ,"p9_mss_dynamic_vcs_avdd", true},
        {TARGETING::ATTR_VDDR_ID,
            p9_mss_dynamic_vid_vddr,"p9_mss_dynamic_vid_vddr", false},
        {TARGETING::ATTR_VPP_ID ,
            p9_mss_dynamic_vid_vpp ,"p9_mss_dynamic_vid_vpp", false}
*/
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

    assert(recordIndex < records,
        "Code bug! Called computeDynamicMemoryVoltage "
        "using unsupported voltage offset attribute type of 0x%08X.",
        VOLTAGE_DOMAIN_ID_ATTR);

    TARGETING::TargetHandleList l_mcbistTargetList;

    // Must pull ALL present mcbist (not just functional) for these
    // computations
    getAllChiplets(l_mcbistTargetList, TARGETING::TYPE_MCBIST, false);

    // sort the mcbist targets based on domain id
    std::sort(l_mcbistTargetList.begin(), l_mcbistTargetList.end(),
        _compareMcbistWrtVoltageDomain< VOLTAGE_DOMAIN_ID_ATTR >);

    std::vector<fapi2::Target<fapi2::TARGET_TYPE_MCS>> l_mcsFapiTargetsList;
    typename TARGETING::AttributeTraits< VOLTAGE_DOMAIN_ID_ATTR >::Type lastDomainId
        = 0;

    if(!l_mcbistTargetList.empty())
    {
        lastDomainId =
            (*l_mcbistTargetList.begin())->getAttr<VOLTAGE_DOMAIN_ID_ATTR>();
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
    bool last = l_mcbistTargetList.empty();
    for (TARGETING::TargetHandleList::const_iterator
            ppPresentMcbist = l_mcbistTargetList.begin();
         ((ppPresentMcbist != l_mcbistTargetList.end()) || (last == false));
         ++ppPresentMcbist)
    {
        // If no valid target to process, this is our last time through the loop
        last = (ppPresentMcbist == l_mcbistTargetList.end());

        typename TARGETING::AttributeTraits< VOLTAGE_DOMAIN_ID_ATTR >::Type
            currentDomainId = last ? lastDomainId :
                (*ppPresentMcbist)->getAttr<VOLTAGE_DOMAIN_ID_ATTR>();

        // Invoke the HWP if the domain ID in the sorted list change relative to
        // prior entry or this is our final time through the loop (and there is
        // a list entry to process)
        if(   ( (currentDomainId != lastDomainId)
               || (last))
           && (!l_mcsFapiTargetsList.empty()) )
        {
            // Skip HWP if this domain has all deconfigured mcs and the
            // domain rule specifies not running the HWP for that case
            bool invokeHwp = true;
            if(fnMap[recordIndex].callIfAllNonFunc == false)
            {
                invokeHwp = false;
                TARGETING::PredicateIsFunctional funcPred;
                std::vector<fapi2::Target<fapi2::TARGET_TYPE_MCS>>::const_iterator
                    pFapiTarget = l_mcsFapiTargetsList.begin();

                for(;pFapiTarget != l_mcsFapiTargetsList.end();++pFapiTarget)
                {
                    // Is there a functional mcs target?
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

                // HWP should set up ATTR_MSS_VOLT_<domain>_OFFSET_MILLIVOLTS
                // for MCBIST targets associated with the mcs list
                FAPI_INVOKE_HWP(
                    pError,
                    fnMap[recordIndex].fn,
                    l_mcsFapiTargetsList);

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
                    "since domain has no functional mcbist.",
                    fnMap[recordIndex].fnName,
                    VOLTAGE_DOMAIN_ID_ATTR, lastDomainId);
            }

            l_mcsFapiTargetsList.clear();

            lastDomainId = currentDomainId;
        }

        // If not the last time through loop, there is a new target
        // to accumulate
        if(!last)
        {
            const TARGETING::Target* pPresentMcbist = *ppPresentMcbist;

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "=====  add to fapi::Target vector attr type=0x%08X, "
                "id=0x%08X, target HUID=0x%08X",
                VOLTAGE_DOMAIN_ID_ATTR,
                pPresentMcbist->getAttr<VOLTAGE_DOMAIN_ID_ATTR>(),
                TARGETING::get_huid(pPresentMcbist));

            fapi2::Target<fapi2::TARGET_TYPE_MCBIST> mcbistFapiTarget(
                (const_cast<TARGETING::Target*>(pPresentMcbist)) );

            // Get the mcs targets under this current mcbist target
            std::vector<fapi2::Target<fapi2::TARGET_TYPE_MCS>> l_childMCSs =
                mcbistFapiTarget.getChildren<fapi2::TARGET_TYPE_MCS>(fapi2::TARGET_STATE_PRESENT);

            // append this mcs target list to the overall mcs target list
            // for that particular domain
            l_mcsFapiTargetsList.insert( l_mcsFapiTargetsList.end(),
                                         l_childMCSs.begin(),
                                         l_childMCSs.end() );
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
        "computeDynamicMemoryVoltage exit");

  return pError;
}


#endif
