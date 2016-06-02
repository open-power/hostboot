/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep07/call_mss_volt.C $                      */
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

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <attributetraits.H>

#include    <config.h>
#include    <util/align.H>
#include    <util/algorithm.H>

//Fapi Support
#include    <fapi2.H>
#include    <target_types.H>
#include    <plat_hwp_invoker.H>
#include    <attributeenums.H>
#include    <istepHelperFuncs.H>

// HWP
#include    <p9_mss_volt.H>

namespace   ISTEP_07
{
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;


// helper function to call  mss_volt_hwp
void  call_mss_volt_hwp (std::vector<TARGETING::ATTR_VMEM_ID_type>& i_VmemList,
                         TARGETING::TargetHandleList& i_mcsTargetList,
                         IStepError& io_StepError)
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "call_mss_volt_hwp function entry" );
    errlHndl_t l_err;

    //for each unique VmemId filter it out of the list of mcs targets
    //to create a subsetlist of MCSs with just that vmemid
    for (auto & l_vmem : i_VmemList)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "Create list of MCS targets for vmem:0x%08X",l_vmem );

        //  declare a vector of fapi targets to pass to mss_volt procedures
        std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCS> >
            l_mcsFapiTargets;

        for(auto & l_mcs_target : i_mcsTargetList)
        {
            //  make a local copy of the target for ease of use
            if (l_mcs_target->getAttr<ATTR_VMEM_ID>() == l_vmem)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "add to fapi2::Target vector vmem_id=0x%08X "
                    "target HUID %.8X",
                    l_mcs_target->getAttr<ATTR_VMEM_ID>(),
                    TARGETING::get_huid(l_mcs_target));

                fapi2::Target <fapi2::TARGET_TYPE_MCS>
                    l_mcs_fapi_target (l_mcs_target);

                l_mcsFapiTargets.push_back( l_mcs_fapi_target );
            }
        }

        //now have the a list of fapi MCSs with just the one VmemId
        //call the HWP on the list of fapi targets
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "Calling p9_mss_volt on list of mcs targets");

        FAPI_INVOKE_HWP(l_err, p9_mss_volt, l_mcsFapiTargets);

        //  process return code.
        if ( l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X:  p9_mss_volt HWP() failed",
                    l_err->reasonCode());

            // Create IStep error log and cross reference
            // to error that occurred
            io_StepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS :  mss_volt HWP( )" );
        }
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "call_mss_volt_hwp function exit" );
}


//
//  Wrapper function to call mss_volt
//
void* call_mss_volt( void *io_pArgs )
{

    IStepError l_StepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_volt entry" );

    // Check that VPP, DDR3 VDDR, and DDR4 VDDR _EFF_CONFIG attributes are set
    bool unused = false;
    set_eff_config_attrs_helper(DEFAULT, unused);

    TARGETING::TargetHandleList l_mcsTargetList;
    getAllChiplets(l_mcsTargetList, TYPE_MCS);

    //get a list of unique VmemIds
    std::vector<TARGETING::ATTR_VMEM_ID_type> l_VmemList;

    //fapi Return Code
    fapi2::ReturnCode l_fapirc;

    for (auto & l_mcs : l_mcsTargetList)
    {
        TARGETING::ATTR_VMEM_ID_type l_VmemID =
                            l_mcs->getAttr<ATTR_VMEM_ID>();
        l_VmemList.push_back(l_VmemID);

    }

    std::sort(l_VmemList.begin(), l_VmemList.end());
    auto objItr = std::unique(l_VmemList.begin(), l_VmemList.end());
    l_VmemList.erase(objItr,l_VmemList.end());

    //call mss_volt hwps
    call_mss_volt_hwp (l_VmemList, l_mcsTargetList, l_StepError);

/* TODO RTC: 152294 Enable VDDR Functions
    errlHndl_t l_err = NULL;
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

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_volt exit" );

    return l_StepError.getErrorHandle();
}


};
