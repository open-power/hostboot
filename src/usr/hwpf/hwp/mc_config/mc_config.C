/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mc_config.C $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
/* [+] Google Inc.                                                        */
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
 *  @file mc_config.C
 *
 *  Support file for IStep: mc_config
 *   Step 12 MC Config
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-03-01:1032
 *  *****************************************************************
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>
#include    <fapiAttributeIds.H>
#include    <fapiAttributeService.H>

#include    "mc_config.H"

#include    "mss_volt/mss_volt.H"
#include    "mss_freq/mss_freq.H"
#include    "mss_eff_config/mss_eff_config.H"
#include    "mss_eff_config/mss_eff_config_thermal.H"
#include    "mss_eff_config/mss_eff_grouping.H"
#include    "mss_eff_config/opt_memmap.H"
#include    "mss_attr_cleanup/mss_attr_cleanup.H"
#include    "mss_eff_mb_interleave/mss_eff_mb_interleave.H"
#include    "mss_volt/mss_volt_avdd_offset.H"
#include    "mss_volt/mss_volt_vcs_offset.H"
#include    "mss_volt/mss_volt_vdd_offset.H"
#include    "mss_volt/mss_volt_vddr_offset.H"
#include    "mss_volt/mss_volt_vpp_offset.H"

#include <config.h>

namespace   MC_CONFIG
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   fapi;

//
//  Wrapper function to call host_collect_dimm_spd
//
void*    call_host_collect_dimm_spd( void *io_pArgs )
{
    errlHndl_t l_err = NULL;
    IStepError l_stepError;
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                      "call_host_collect_dimm_spd entry" );

    // Get a list of all present Centaurs
    TargetHandleList l_presCentaurs;
    getChipResources(l_presCentaurs, TYPE_MEMBUF, UTIL_FILTER_PRESENT);
    // Associated MBA targets
    TARGETING::TargetHandleList l_mbaList;

    // Define predicate for associated MBAs
    PredicateCTM predMba(CLASS_UNIT, TYPE_MBA);
    PredicatePostfixExpr presMba;
    PredicateHwas predPres;
    predPres.present(true);
    presMba.push(&predMba).push(&predPres).And();

    for (TargetHandleList::const_iterator
            l_cenIter = l_presCentaurs.begin();
            l_cenIter != l_presCentaurs.end();
            ++l_cenIter)
    {
        //  make a local copy of the target for ease of use
        TARGETING::Target * l_pCentaur = *l_cenIter;
        // Retrieve HUID of current Centaur
        TARGETING::ATTR_HUID_type l_currCentaurHuid =
            TARGETING::get_huid(l_pCentaur);

        // Dump current run on target
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "Running mss_attr_cleanup HWP on "
                "target HUID %.8X", l_currCentaurHuid);

        // find all present MBAs associated with this Centaur
        TARGETING::TargetHandleList l_presMbas;
        targetService().getAssociated(l_presMbas,
                                      l_pCentaur,
                                      TargetService::CHILD,
                                      TargetService::IMMEDIATE,
                                      &presMba);

        // If not at least two MBAs found
        if (l_presMbas.size() < 2)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "Not enough MBAs found for Centaur target HUID %.8X, "
              "skipping this Centaur.",
              l_currCentaurHuid);
            continue;
        }

        // Create FAPI Targets.
        const fapi::Target l_fapiCentaurTarget(TARGET_TYPE_MEMBUF_CHIP,
                (const_cast<TARGETING::Target*>(l_pCentaur)));
        const fapi::Target l_fapiMba0Target(TARGET_TYPE_MBA_CHIPLET,
                (const_cast<TARGETING::Target*>(l_presMbas[0])));
        const fapi::Target l_fapiMba1Target(TARGET_TYPE_MBA_CHIPLET,
                (const_cast<TARGETING::Target*>(l_presMbas[1])));
        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP(l_err, mss_attr_cleanup, l_fapiCentaurTarget,
                        l_fapiMba0Target, l_fapiMba1Target);
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X: mss_attr_cleanup HWP returns error",
                      l_err->reasonCode());
            // capture the target data in the elog
            ErrlUserDetailsTarget(l_pCentaur).addToLog(l_err);
            // Create IStep error log and cross reference error that occurred
            l_stepError.addErrorDetails(l_err);
            // Commit Error
            errlCommit(l_err, HWPF_COMP_ID);
        }
        else
        {
            // Success
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "Successfully ran mss_attr_cleanup HWP on "
                    "CENTAUR target HUID %.8X "
                    "and associated MBAs",
                    l_currCentaurHuid);
        }
    }


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                      "call_host_collect_dimm_spd exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}

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
    assert(pSysTarget != NULL,"System target was NULL.");

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

//
//  Wrapper function to call mss_volt
//
void* call_mss_volt( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    IStepError l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_volt entry" );

    TARGETING::TargetHandleList l_membufTargetList;
    getAllChips(l_membufTargetList, TYPE_MEMBUF);

    //get a list of unique VmemIds
    std::vector<TARGETING::ATTR_VMEM_ID_type> l_VmemList;

    //fapi Return Code
    fapi::ReturnCode l_fapirc;

    for (TargetHandleList::const_iterator
            l_membuf_iter = l_membufTargetList.begin();
            l_membuf_iter != l_membufTargetList.end();
            ++l_membuf_iter)
    {
        TARGETING::ATTR_VMEM_ID_type l_VmemID =
                            (*l_membuf_iter)->getAttr<ATTR_VMEM_ID>();
        l_VmemList.push_back(l_VmemID);

    }

#ifdef CONFIG_ALLOW_NON_COMPLIANT_DIMM
        // Set ATTR_MSS_VOLT_COMPLIANT_DIMMS to ALL
        // Value of ALL value in attribute enum
        uint8_t l_allowNonCompliantDimms =
                        ENUM_ATTR_MSS_VOLT_COMPLIANT_DIMMS_ALL_VOLTAGES;

        TARGETING::Target* l_sys = NULL;
        targetService().getTopLevelTarget(l_sys);
        l_sys->setAttr<TARGETING::ATTR_MSS_VOLT_COMPLIANT_DIMMS>
                                                    (l_allowNonCompliantDimms);

#endif



    std::sort(l_VmemList.begin(), l_VmemList.end());

    std::vector<TARGETING::ATTR_VMEM_ID_type>::iterator objItr;
    objItr=std::unique(l_VmemList.begin(), l_VmemList.end());
    l_VmemList.erase(objItr,l_VmemList.end());

    //for each unique VmemId filter it out of the list of membuf targets
    //to create a subsetlist of membufs with just that vmemid
    std::vector<TARGETING::ATTR_VMEM_ID_type>::iterator l_vmem_iter;
    for (l_vmem_iter = l_VmemList.begin();
            l_vmem_iter != l_VmemList.end();
            ++l_vmem_iter)
    {
        //  declare a vector of fapi targets to pass to mss_volt
        std::vector<fapi::Target> l_membufFapiTargets;

        for (TargetHandleList::const_iterator
                l_membuf_iter = l_membufTargetList.begin();
                l_membuf_iter != l_membufTargetList.end();
                ++l_membuf_iter)
        {
            //  make a local copy of the target for ease of use
            const TARGETING::Target*  l_membuf_target = *l_membuf_iter;
            if (l_membuf_target->getAttr<ATTR_VMEM_ID>()==*l_vmem_iter)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "=====  add to fapi::Target vector vmem_id=0x%08X "
                    "target HUID %.8X",
                    l_membuf_target->getAttr<ATTR_VMEM_ID>(),
                    TARGETING::get_huid(l_membuf_target));

                fapi::Target l_membuf_fapi_target(fapi::TARGET_TYPE_MEMBUF_CHIP,
                        (const_cast<TARGETING::Target*>(l_membuf_target)) );

                l_membufFapiTargets.push_back( l_membuf_fapi_target );
            }
        }

        //now have the a list of fapi membufs with just the one VmemId
        //call the HWP on the list of fapi targets
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                            "=====  mss_volt HWP( vector )" );
        FAPI_INVOKE_HWP(l_err, mss_volt, l_membufFapiTargets);

        //  process return code.
        if ( l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X:  mss_volt HWP( ) ", l_err->reasonCode());

            // Create IStep error log and cross reference to error that occurred
            l_StepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );

        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS :  mss_volt HWP( )" );
        }

    }   // endfor

    l_err = setMemoryVoltageDomainOffsetVoltage<
        TARGETING::ATTR_MSS_CENT_VDD_OFFSET_DISABLE,
        TARGETING::ATTR_MEM_VDD_OFFSET_MILLIVOLTS,
        TARGETING::ATTR_VDD_ID>();
    if(l_err)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "ERROR 0x%08X: setMemoryVoltageDomainOffsetVoltage for VDD domain",
            l_err->reasonCode());
        l_StepError.addErrorDetails(l_err);
        errlCommit(l_err,HWPF_COMP_ID);
    }

    l_err = setMemoryVoltageDomainOffsetVoltage<
        TARGETING::ATTR_MSS_CENT_AVDD_OFFSET_DISABLE,
        TARGETING::ATTR_MEM_AVDD_OFFSET_MILLIVOLTS,
        TARGETING::ATTR_AVDD_ID>();
    if(l_err)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "ERROR 0x%08X: setMemoryVoltageDomainOffsetVoltage for AVDD domain",
            l_err->reasonCode());
        l_StepError.addErrorDetails(l_err);
        errlCommit(l_err,HWPF_COMP_ID);
    }

    l_err = setMemoryVoltageDomainOffsetVoltage<
        TARGETING::ATTR_MSS_CENT_VCS_OFFSET_DISABLE,
        TARGETING::ATTR_MEM_VCS_OFFSET_MILLIVOLTS,
        TARGETING::ATTR_VCS_ID>();
    if(l_err)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "ERROR 0x%08X: setMemoryVoltageDomainOffsetVoltage for VCS domain",
            l_err->reasonCode());
        l_StepError.addErrorDetails(l_err);
        errlCommit(l_err,HWPF_COMP_ID);
    }

    l_err = setMemoryVoltageDomainOffsetVoltage<
        TARGETING::ATTR_MSS_VOLT_VPP_OFFSET_DISABLE,
        TARGETING::ATTR_MEM_VPP_OFFSET_MILLIVOLTS,
        TARGETING::ATTR_VPP_ID>();
    if(l_err)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "ERROR 0x%08X: setMemoryVoltageDomainOffsetVoltage for VPP domain",
            l_err->reasonCode());
        l_StepError.addErrorDetails(l_err);
        errlCommit(l_err,HWPF_COMP_ID);
    }

    l_err = setMemoryVoltageDomainOffsetVoltage<
        TARGETING::ATTR_MSS_VOLT_VDDR_OFFSET_DISABLE,
        TARGETING::ATTR_MEM_VDDR_OFFSET_MILLIVOLTS,
        TARGETING::ATTR_VMEM_ID>();
    if(l_err)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "ERROR 0x%08X: setMemoryVoltageDomainOffsetVoltage for VDDR domain",
            l_err->reasonCode());
        l_StepError.addErrorDetails(l_err);
        errlCommit(l_err,HWPF_COMP_ID);
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_volt exit" );

    return l_StepError.getErrorHandle();
}

//
//  Wrapper function to call mss_freq
//
void*    call_mss_freq( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    IStepError l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_freq entry" );

    TARGETING::TargetHandleList l_membufTargetList;
    getAllChips(l_membufTargetList, TYPE_MEMBUF);

    for (TargetHandleList::const_iterator
            l_membuf_iter = l_membufTargetList.begin();
            l_membuf_iter != l_membufTargetList.end();
            ++l_membuf_iter)
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target* l_membuf_target = *l_membuf_iter;

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "=====  mss_freq HWP "
                "target HUID %.8X",
                TARGETING::get_huid(l_membuf_target));

        //  call the HWP with each target   ( if parallel, spin off a task )
        // $$const fapi::Target l_fapi_membuf_target(
        fapi::Target l_fapi_membuf_target(fapi::TARGET_TYPE_MEMBUF_CHIP,
                    (const_cast<TARGETING::Target*>(l_membuf_target)) );

        FAPI_INVOKE_HWP(l_err, mss_freq, l_fapi_membuf_target);

        //  process return code.
        if ( l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                     "ERROR 0x%.8X:  mss_freq HWP ",
                     l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_membuf_target).addToLog( l_err );

            // Create IStep error log and cross reference to error that occurred
            l_StepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );

         }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                     "SUCCESS :  mss_freq HWP");
        }
    } // End memBuf loop

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_freq exit" );

    return l_StepError.getErrorHandle();
}

errlHndl_t call_mss_eff_grouping()
{
    errlHndl_t l_err = NULL;

    TARGETING::TargetHandleList l_procsList;
    getAllChips(l_procsList, TYPE_PROC);

    for (TargetHandleList::const_iterator
            l_proc_iter = l_procsList.begin();
            l_proc_iter != l_procsList.end();
            ++l_proc_iter)
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target* l_cpu_target = *l_proc_iter;

        //  print call to hwp and write HUID of the target(s)
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "=====  mss_eff_grouping HWP cpu "
                "target HUID %.8X",
                TARGETING::get_huid(l_cpu_target));

        // cast OUR type of target to a FAPI type of target.
        const fapi::Target l_fapi_cpu_target(fapi::TARGET_TYPE_PROC_CHIP,
                    (const_cast<TARGETING::Target*>(l_cpu_target)) );

        TARGETING::TargetHandleList l_membufsList;
        getChildAffinityTargets(l_membufsList, l_cpu_target,
                   CLASS_CHIP, TYPE_MEMBUF);
        std::vector<fapi::Target> l_associated_centaurs;

        for (TargetHandleList::const_iterator
                l_membuf_iter = l_membufsList.begin();
                l_membuf_iter != l_membufsList.end();
                ++l_membuf_iter)
        {
            //  make a local copy of the target for ease of use
            const TARGETING::Target* l_pTarget = *l_membuf_iter;

            // cast OUR type of target to a FAPI type of target.
            const fapi::Target l_fapi_centaur_target(fapi::TARGET_TYPE_MEMBUF_CHIP,
                   (const_cast<TARGETING::Target*>(l_pTarget)) );

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "target HUID %.8X", TARGETING::get_huid(l_pTarget));

            l_associated_centaurs.push_back(l_fapi_centaur_target);
        }

        FAPI_INVOKE_HWP(l_err, mss_eff_grouping,
                        l_fapi_cpu_target, l_associated_centaurs);

        //  process return code.
        if ( l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "ERROR 0x%.8X:  mss_eff_grouping HWP",
                        l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_cpu_target).addToLog(l_err);

            break; // break out mba loop
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "SUCCESS :  mss_eff_grouping HWP");
        }
    }   // endfor

    return l_err;
}

errlHndl_t call_opt_memmap( bool i_initBase )
{
    errlHndl_t l_err = NULL;

    TARGETING::TargetHandleList l_procs;
    getAllChips(l_procs, TYPE_PROC);

    std::vector<fapi::Target> l_fapi_procs;

    for ( TARGETING::TargetHandleList::const_iterator
          l_iter = l_procs.begin();
          l_iter != l_procs.end();
          ++l_iter )
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target*  l_target = *l_iter;

        // cast OUR type of target to a FAPI type of target.
        const fapi::Target l_fapi_target(fapi::TARGET_TYPE_PROC_CHIP,
                    (const_cast<TARGETING::Target*>(l_target)) );

        l_fapi_procs.push_back(l_fapi_target);
    }

    FAPI_INVOKE_HWP(l_err, opt_memmap, l_fapi_procs, i_initBase);

    if ( l_err )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "ERROR 0x%.8X:  opt_memmap HWP", l_err->reasonCode());
    }
    else
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "SUCCESS :  opt_memmap HWP");
    }

    return l_err;
}

//
//  Wrapper function to call mss_eff_config
//
void*    call_mss_eff_config( void *io_pArgs )
{
    errlHndl_t l_err = NULL;
    IStepError l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_eff_config entry" );

    TARGETING::Target* l_sys = NULL;
    targetService().getTopLevelTarget(l_sys);
    assert( l_sys != NULL );

    // The attribute ATTR_MEM_MIRROR_PLACEMENT_POLICY should already be
    // correctly set by default for all platforms except for sapphire.
    // Don't allow mirroring on sapphire yet @todo-RTC:108314
    //
    //ATTR_PAYLOAD_IN_MIRROR_MEM_type l_mirrored =
    //    l_sys->getAttr<ATTR_PAYLOAD_IN_MIRROR_MEM>();
    //
    //if(l_mirrored && is_sapphire_load())
    //{
    //    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "Mirroring is enabled");

    //    uint8_t l_mmPolicy =
    //        fapi::ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_FLIPPED;
    //    l_sys->
    //        setAttr<TARGETING::ATTR_MEM_MIRROR_PLACEMENT_POLICY>(l_mmPolicy);
    //}

    // Get all functional MBA chiplets
    TARGETING::TargetHandleList l_mbaTargetList;
    getAllChiplets(l_mbaTargetList, TYPE_MBA);

    // Iterate over all MBAs, calling mss_eff_config and mss_eff_config_thermal
    for (TargetHandleList::const_iterator l_mba_iter = l_mbaTargetList.begin();
            l_mba_iter != l_mbaTargetList.end(); ++l_mba_iter)
    {
        // Get the TARGETING::Target pointer and its HUID
        const TARGETING::Target* l_mba_target = *l_mba_iter;
        uint32_t l_huid = TARGETING::get_huid(l_mba_target);

        // Create a FAPI target representing the MBA
        const fapi::Target l_fapi_mba_target(fapi::TARGET_TYPE_MBA_CHIPLET,
            (const_cast<TARGETING::Target*>(l_mba_target)));

        // Call the mss_eff_config HWP
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "=====  mss_eff_config HWP. MBA HUID %.8X", l_huid);
        FAPI_INVOKE_HWP(l_err, mss_eff_config, l_fapi_mba_target);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR 0x%.8X:  mss_eff_config HWP ", l_err->reasonCode());

            // Ensure istep error created and has same plid as this error
            ErrlUserDetailsTarget(l_mba_target).addToLog(l_err);
            l_StepError.addErrorDetails(l_err);
            errlCommit(l_err, HWPF_COMP_ID);
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS :  mss_eff_config HWP");

            // Call the mss_eff_config_thermal HWP
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "=====  mss_eff_config_thermal HWP. MBA HUID %.8X", l_huid);
            FAPI_INVOKE_HWP(l_err, mss_eff_config_thermal, l_fapi_mba_target);

            if (l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X:  mss_eff_config_thermal HWP ", l_err->reasonCode());

                // Ensure istep error created and has same plid as this error
                ErrlUserDetailsTarget(l_mba_target).addToLog(l_err);
                l_StepError.addErrorDetails(l_err);
                errlCommit(l_err, HWPF_COMP_ID);
            }
            else
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS :  mss_eff_config_thermal HWP");
            }
        }
    }

    if (l_StepError.isNull())
    {
        // Flush out BASE attributes to starting values
        l_err = call_opt_memmap(true);

        if (!l_err)
        {
            // Stack the memory on each chip
            l_err = call_mss_eff_grouping();

            if (!l_err)
            {
                // Move the BASES around to the real final values
                l_err = call_opt_memmap(false);

                if (!l_err)
                {
                    // Stack the memory again based on system-wide positions
                    l_err = call_mss_eff_grouping();
                }
            }
        }

        if (l_err)
        {
            // Ensure istep error created and has same plid as this error
            l_StepError.addErrorDetails( l_err );
            errlCommit( l_err, HWPF_COMP_ID );
        }
    }

    // Calling mss_eff_mb_interleave
    if (l_StepError.isNull())
    {
        TARGETING::TargetHandleList l_membufTargetList;
        getAllChips(l_membufTargetList, TYPE_MEMBUF);
        for (TargetHandleList::const_iterator
                l_membuf_iter = l_membufTargetList.begin();
                l_membuf_iter != l_membufTargetList.end();
                ++l_membuf_iter)
        {
            const TARGETING::Target* l_membuf_target = *l_membuf_iter;
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "=====  Running mss_eff_mb_interleave HWP on HUID %.8X",
                    TARGETING::get_huid(l_membuf_target));
            fapi::Target l_membuf_fapi_target(fapi::TARGET_TYPE_MEMBUF_CHIP,
                        (const_cast<TARGETING::Target*>(l_membuf_target)) );
            FAPI_INVOKE_HWP(l_err, mss_eff_mb_interleave, l_membuf_fapi_target);
            if (l_err)
            {
               TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                         "ERROR 0x%.8X: mss_eff_mb_interleave HWP returns error",
                         l_err->reasonCode());
               ErrlUserDetailsTarget(l_membuf_target).addToLog(l_err);
               l_StepError.addErrorDetails(l_err);
               errlCommit(l_err, HWPF_COMP_ID);
            }
            else
            {
               TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "Successfully ran mss_eff_mb_interleave HWP on HUID %.8X",
                    TARGETING::get_huid(l_membuf_target));
            }
        }
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_eff_config exit" );

    return l_StepError.getErrorHandle();
}
//
//  Wrapper function to call mss_attr_update
//
void*    call_mss_attr_update( void *io_pArgs )
{

    IStepError l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_attr_update entry");
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_attr_update exit" );

    return l_StepError.getErrorHandle();
}



};   // end namespace
