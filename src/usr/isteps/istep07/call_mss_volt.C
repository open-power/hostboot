/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep07/call_mss_volt.C $                      */
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
/**
 *  @file call_mss_volt.C
 *  Contains the wrapper for istep 7.2
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <initservice/initserviceif.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>
#include    <sbe/sbeif.H>
//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <attributetraits.H>

#include    <config.h>
#include    <util/align.H>
#include    <util/algorithm.H>

namespace   ISTEP_07
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;

// helper function to call multiple mss_volt_hwps
void  call_mss_volt_hwp (std::vector<TARGETING::ATTR_VMEM_ID_type>& i_VmemList,
                         TARGETING::TargetHandleList& i_membufTargetList,
                         IStepError& io_StepError,
                         fapi::ReturnCode(*mss_volt_hwp)(std::vector<fapi::Target>&))
{
    /* @TODO: RTC:133830 Add wrapper back when ready
    errlHndl_t l_err;
    //for each unique VmemId filter it out of the list of membuf targets
    //to create a subsetlist of membufs with just that vmemid
    std::vector<TARGETING::ATTR_VMEM_ID_type>::iterator l_vmem_iter;
    for (l_vmem_iter = i_VmemList.begin();
            l_vmem_iter != i_VmemList.end();
            ++l_vmem_iter)
    {
        //  declare a vector of fapi targets to pass to mss_volt procedures
        std::vector<fapi::Target> l_membufFapiTargets;

        for (TargetHandleList::const_iterator
                l_membuf_iter = i_membufTargetList.begin();
                l_membuf_iter != i_membufTargetList.end();
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

        FAPI_INVOKE_HWP(l_err, mss_volt_hwp, l_membufFapiTargets);

        //  process return code.
        if ( l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X:  mss_volt HWP( ) ",
                    l_err->reasonCode());

            // Create IStep error log and cross reference to error that occurred
            io_StepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );

        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS :  mss_volt_dimm_count HWP( )" );
        }
    }
    */
}

//
//  Wrapper function to call mss_volt
//
void* call_mss_volt( void *io_pArgs )
{

    IStepError l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_volt entry" );

    //@TODO RTC:133830 Add the wrapper back in when ready
/*    // Check that VPP, DDR3 VDDR, and DDR4 VDDR _EFF_CONFIG attributes are set
    errlHndl_t l_err = NULL;
    bool unused = false;
    set_eff_config_attrs_helper(DEFAULT, unused);

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

    //call mss_volt hwps
    call_mss_volt_hwp (l_VmemList, l_membufTargetList,l_StepError, mss_volt);
    call_mss_volt_hwp (l_VmemList, l_membufTargetList,l_StepError,
                       mss_volt_dimm_count);

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
*/
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_volt exit" );

    return l_StepError.getErrorHandle();
}


};
