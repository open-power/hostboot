/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep07/call_mss_volt.C $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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
#include    <map>
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
#include    <p9c_mss_volt.H>
#include    <p9c_mss_volt_vddr_offset.H>
#include    <p9c_mss_volt_dimm_count.H>

namespace   ISTEP_07
{
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;

typedef std::map<ATTR_VDDR_ID_type, std::vector<fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>>> MembufTargetMap_t;
typedef std::vector<ATTR_VDDR_ID_type> VDDR_ID_vect_t;

/**
 *  @brief
 *     A macro that wraps call_mss_volt_hwps used to stringify the FAPI HWP call
 *
 *  @see
 *      call_mss_volt_hwps below for parameter definitions
 */
#define FAPI_MSS_VOLT_CALL_MACRO(FUNC, MEMBUF_MAP, UNIQUE_VDDRS, STEP_ERROR)   \
    call_mss_volt_hwps(FUNC, #FUNC, MEMBUF_MAP, UNIQUE_VDDRS, STEP_ERROR)

void call_mss_volt_hwps (p9c_mss_volt_FP_t i_mss_volt_hwps,
                         const char* i_mss_volt_hwp_str,
                         MembufTargetMap_t & i_membufFapiTargetMap,
                         VDDR_ID_vect_t & i_unique_vddrs,
                         IStepError & io_err)
{
    errlHndl_t l_err = NULL;
    for (auto & l_vddr : i_unique_vddrs)
    {

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
              "Calling %s hwp with list of membuf targets"
              " with VDDR_ID=%d, list size=%d",
              i_mss_volt_hwp_str, l_vddr,
              i_membufFapiTargetMap[l_vddr].size());

        // p9c_mss_volt.C (vector of centaurs with same VDDR_ID)
        FAPI_INVOKE_HWP(l_err, i_mss_volt_hwps,
                i_membufFapiTargetMap[l_vddr]);

        // process return code
        if ( l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X:  %s HWP() failed",
                    i_mss_volt_hwp_str,
                    l_err->reasonCode());

            // Create IStep error log and cross reference to error
            // that occurred
            io_err.addErrorDetails(l_err);

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );

        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS : %s HWP", i_mss_volt_hwp_str);
        }
    }
}

void buildMembufLists(TargetHandleList & i_membufTargetList,
                      MembufTargetMap_t & o_membufFapiTargetMap,
                      VDDR_ID_vect_t & o_unique_vddr_ids)
{
    for (auto & l_membuf : i_membufTargetList)
    {
        //get VDDR_ID attribute
        auto l_vddr_id = l_membuf->getAttr<ATTR_VDDR_ID>();

        //convert membuf to fapi target
        fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>
            l_fapi_membuf (l_membuf);

        //Create a vector with the fapi target to insert in the map later.
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>> l_fapi_vect;
        l_fapi_vect.push_back(std::move(l_fapi_membuf));

        //insert {VDDR_ID, fapi2 membuf} in the map
        //l_ret is of format std::pair<MembufTargetMap_t iterator, bool>
        //where bool indicates whether the insertion was successful or not
        auto l_ret = o_membufFapiTargetMap.insert({l_vddr_id, l_fapi_vect});
        if (l_ret.second == false)
        {
            //This VDDR_ID already exists in the map, we need to push
            //l_fapi_membuf to the exisiting vector
            l_ret.first->second.push_back(std::move(l_fapi_membuf));
        }
        else
        {
            //insertion was successful meaning this is a new vddr id
            //save it off in a vector for faster retrieval later
            o_unique_vddr_ids.push_back(std::move(l_vddr_id));
        }
    }
}


void* call_mss_volt( void *io_pArgs )
{
    IStepError l_StepError;
    errlHndl_t l_err = NULL;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_volt entry" );

    // Check that VPP, DDR3 VDDR, and DDR4 VDDR _EFF_CONFIG attributes are set
    bool unused = false;
    set_eff_config_attrs_helper(DEFAULT, unused);


    do
    {
        TargetHandleList l_membufTargetList;
        getAllChips(l_membufTargetList, TYPE_MEMBUF);

       if (l_membufTargetList.size() > 0)
       {

           MembufTargetMap_t l_membufFapiTargetMap {};
           VDDR_ID_vect_t l_unique_vddrs {};
           buildMembufLists(l_membufTargetList, l_membufFapiTargetMap,
                   l_unique_vddrs);

           FAPI_MSS_VOLT_CALL_MACRO(p9c_mss_volt,
                                    l_membufFapiTargetMap,
                                    l_unique_vddrs,
                                    l_StepError);
           if (l_StepError.getErrorHandle())
           {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "ERROR: p9c_mss_volt HWP failed");
                break;
           }

           FAPI_MSS_VOLT_CALL_MACRO(p9c_mss_volt_vddr_offset,
                                    l_membufFapiTargetMap,
                                    l_unique_vddrs,
                                    l_StepError);
           if (l_StepError.getErrorHandle())
           {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "ERROR: p9c_mss_volt_vddr_offset HWP failed");
                break;
           }

           FAPI_MSS_VOLT_CALL_MACRO(p9c_mss_volt_dimm_count,
                                    l_membufFapiTargetMap,
                                    l_unique_vddrs,
                                    l_StepError);
           if (l_StepError.getErrorHandle())
           {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "ERROR: p9c_mss_volt_vddr_offset HWP failed");
                break;
           }
       }
       else
       {
           TargetHandleList l_mcsTargetList;
           getAllChiplets(l_mcsTargetList, TYPE_MCS);

           std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCS> >
               l_mcsFapiTargetsList;

           for(auto & l_mcs_target : l_mcsTargetList)
           {
               fapi2::Target <fapi2::TARGET_TYPE_MCS>
                   l_mcs_fapi_target (l_mcs_target);

               l_mcsFapiTargetsList.push_back( l_mcs_fapi_target );
           }

           TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Calling p9_mss_volt on list of mcs targets");

           FAPI_INVOKE_HWP(l_err, p9_mss_volt, l_mcsFapiTargetsList);

           // process return code
           if ( l_err )
           {
               TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "ERROR 0x%.8X:  p9_mss_volt HWP() failed",
                       l_err->reasonCode());

               // Create IStep error log and cross reference to error
               // that occurred
               l_StepError.addErrorDetails(l_err);

               // Commit Error
               errlCommit( l_err, HWPF_COMP_ID );
           }
           else
           {
               // No need to compute dynamic values if mss_volt failed

               // Calculate Dynamic Offset voltages for each domain
               Target* pSysTarget = NULL;
               targetService().getTopLevelTarget(pSysTarget);
               assert(
                       (pSysTarget != NULL),
                       "call_mss_volt: Code bug!  System target was NULL.");

               // only calculate if system supports dynamic voltage
               if (pSysTarget->getAttr<ATTR_SUPPORTS_DYNAMIC_MEM_VOLT >() == 1)
               {
                   l_err = computeDynamicMemoryVoltage<
                       ATTR_MSS_VDD_PROGRAM,
                       ATTR_VDD_ID>();
                   if(l_err)
                   {
                       TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "ERROR 0x%08X: computeDynamicMemoryVoltage for "
                               "VDD domain",
                               l_err->reasonCode());
                       l_StepError.addErrorDetails(l_err);
                       errlCommit(l_err,HWPF_COMP_ID);
                   }

                   l_err = computeDynamicMemoryVoltage<
                       ATTR_MSS_AVDD_PROGRAM,
                       ATTR_AVDD_ID>();
                   if(l_err)
                   {
                       TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "ERROR 0x%08X: computeDynamicMemoryVoltage for "
                               "AVDD domain",
                               l_err->reasonCode());
                       l_StepError.addErrorDetails(l_err);
                       errlCommit(l_err,HWPF_COMP_ID);
                   }

                   l_err = computeDynamicMemoryVoltage<
                       ATTR_MSS_VCS_PROGRAM,
                       ATTR_VCS_ID>();
                   if(l_err)
                   {
                       TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "ERROR 0x%08X: computeDynamicMemoryVoltage for "
                               "VCS domain",
                               l_err->reasonCode());
                       l_StepError.addErrorDetails(l_err);
                       errlCommit(l_err,HWPF_COMP_ID);
                   }

                   l_err = computeDynamicMemoryVoltage<
                       ATTR_MSS_VPP_PROGRAM,
                       ATTR_VPP_ID>();
                   if(l_err)
                   {
                       TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "ERROR 0x%08X: computeDynamicMemoryVoltage for "
                               "VPP domain",
                               l_err->reasonCode());
                       l_StepError.addErrorDetails(l_err);
                       errlCommit(l_err,HWPF_COMP_ID);
                   }

                   l_err = computeDynamicMemoryVoltage<
                       ATTR_MSS_VDDR_PROGRAM,
                       ATTR_VDDR_ID>();
                   if(l_err)
                   {
                       TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "ERROR 0x%08X: computeDynamicMemoryVoltage for "
                               "VDDR domain",
                               l_err->reasonCode());
                       l_StepError.addErrorDetails(l_err);
                       errlCommit(l_err,HWPF_COMP_ID);
                   }
               }
           }
       }
   }while(0);

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_volt exit" );

    return l_StepError.getErrorHandle();
}


};
