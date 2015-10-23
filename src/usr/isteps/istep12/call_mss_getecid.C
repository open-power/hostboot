/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_mss_getecid.C $                   */
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
#include    <errl/errlentry.H>

#include    <initservice/isteps_trace.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

//  targeting support.
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;


namespace ISTEP_12
{
void* call_mss_getecid (void *io_pArgs)
{
    IStepError l_StepError;
    /*
    //@TODO RTC:133831
    errlHndl_t l_err = NULL;
    uint8_t    l_ddr_port_status = 0;
    uint8_t    l_cache_enable = 0;
    uint8_t    l_centaur_sub_revision = 0;

    ecid_user_struct l_ecidUser;  // Do not need to be initalized by caller

    mss_get_cen_ecid_ddr_status l_mbaBadMask[2] =
       { MSS_GET_CEN_ECID_DDR_STATUS_MBA0_BAD,
         MSS_GET_CEN_ECID_DDR_STATUS_MBA1_BAD };

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_getecid entry" );

    // Get all Centaur targets
    TARGETING::TargetHandleList l_membufTargetList;
    getAllChips(l_membufTargetList, TYPE_MEMBUF);

    for (TargetHandleList::const_iterator
            l_membuf_iter = l_membufTargetList.begin();
            l_membuf_iter != l_membufTargetList.end();
            ++l_membuf_iter)
    {
        //  make a local copy of the target for ease of use
        TARGETING::Target* l_pCentaur = *l_membuf_iter;

        // Dump current run on target
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "Running mss_get_cen_ecid HWP on "
                "target HUID %.8X", TARGETING::get_huid(l_pCentaur));

        // Cast to a FAPI type of target.
        const fapi::Target l_fapi_centaur( TARGET_TYPE_MEMBUF_CHIP,
                (const_cast<TARGETING::Target*>(l_pCentaur)) );

        //  call the HWP with each fapi::Target
        //  Note:  This HWP does not actually return the entire ECID data.  It
        //  updates the attribute ATTR_MSS_ECID and returns the DDR port status
        //  which is a portion of the ECID data.
        FAPI_INVOKE_HWP(l_err, mss_get_cen_ecid,
                        l_fapi_centaur, l_ddr_port_status,
                        l_cache_enable, l_centaur_sub_revision, l_ecidUser);
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X: mss_get_cen_ecid HWP returns error",
                      l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_pCentaur).addToLog( l_err );

            // Create IStep error log and cross reference error that occurred
            l_StepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );
        }
        else
        {
            if (MSS_GET_CEN_ECID_DDR_STATUS_ALL_GOOD != l_ddr_port_status)
            {
                // Check the DDR port status returned by mss_get_cen_ecid to
                // see which MBA is bad.  If the MBA's state is
                // functional and the DDR port status indicates that it's bad,
                // then set the MBA to nonfunctional.  If the MBA's state is
                // nonfunctional, then do nothing since we don't want to
                // override previous settings.

                // Find the functional MBAs associated with this Centaur
                PredicateCTM l_mba_pred(CLASS_UNIT,TYPE_MBA);
                TARGETING::TargetHandleList l_mbaTargetList;
                getChildChiplets(l_mbaTargetList,
                                 l_pCentaur,
                                 TYPE_MBA);

                uint8_t l_num_func_mbas = l_mbaTargetList.size();

                for (TargetHandleList::const_iterator
                        l_mba_iter = l_mbaTargetList.begin();
                        l_mba_iter != l_mbaTargetList.end();
                        ++l_mba_iter)
                {
                    //  Make a local copy of the target for ease of use
                    TARGETING::Target*  l_pMBA = *l_mba_iter;

                    // Get the MBA chip unit position
                    ATTR_CHIP_UNIT_type l_pos =
                        l_pMBA->getAttr<ATTR_CHIP_UNIT>();

                    // Check the DDR port status to see if this MBA should be
                    // set to nonfunctional.
                    if ( l_ddr_port_status & l_mbaBadMask[l_pos] )
                    {
                        // call HWAS to deconfigure this target
                        l_err = HWAS::theDeconfigGard().deconfigureTarget(
                                    *l_pMBA, HWAS::DeconfigGard::
                                                DECONFIGURED_BY_MEMORY_CONFIG);
                        l_num_func_mbas--;

                        if (l_err)
                        {
                            // shouldn't happen, but if it does, stop trying to
                            //  deconfigure targets..
                            break;
                        }
                    }
                } // for

                if (l_err)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              "ERROR: error deconfiguring MBA or Centaur");

                    // Create IStep error log and cross ref error that occurred
                    l_StepError.addErrorDetails( l_err );

                    // Commit Error
                    errlCommit( l_err, HWPF_COMP_ID );
                }
            }

            // mss_get_cen_ecid returns if the L4 cache is enabled. This can be
            // - fapi::ENUM_ATTR_MSS_CACHE_ENABLE_OFF
            // - fapi::ENUM_ATTR_MSS_CACHE_ENABLE_ON
            // - fapi::ENUM_ATTR_MSS_CACHE_ENABLE_HALF_A
            // - fapi::ENUM_ATTR_MSS_CACHE_ENABLE_HALF_B
            // - fapi::ENUM_ATTR_MSS_CACHE_ENABLE_UNK_OFF
            // - fapi::ENUM_ATTR_MSS_CACHE_ENABLE_UNK_ON
            // - fapi::ENUM_ATTR_MSS_CACHE_ENABLE_UNK_HALF_A
            // - fapi::ENUM_ATTR_MSS_CACHE_ENABLE_UNK_HALF_B
            // The UNK values are for DD1.* Centaur chips where the fuses were
            // not blown correctly so the cache may not be in the correct state.
            //
            // Firmware does not normally support HALF enabled
            // If ON then ATTR_MSS_CACHE_ENABLE is set to ON
            // Else ATTR_MSS_CACHE_ENABLE is set to OFF and the L4 Target is
            //   deconfigured
            //
            // However, an engineer can override ATTR_MSS_CACHE_ENABLE. If they
            // override it to HALF_A or HALF_B then
            // - ATTR_MSS_CACHE_ENABLE is set to HALF_X
            // - The L4 Target is not deconfigured
            if (l_cache_enable != fapi::ENUM_ATTR_MSS_CACHE_ENABLE_ON)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "call_mss_getecid: mss_get_cen_ecid returned L4 not-on (0x%02x)",
                    l_cache_enable);
                l_cache_enable = fapi::ENUM_ATTR_MSS_CACHE_ENABLE_OFF;
            }

            // Set the ATTR_MSS_CACHE_ENABLE attribute
            l_pCentaur->setAttr<TARGETING::ATTR_MSS_CACHE_ENABLE>(
                l_cache_enable);

            // Read the ATTR_MSS_CACHE_ENABLE back to pick up any override
            uint8_t l_cache_enable_attr =
                l_pCentaur->getAttr<TARGETING::ATTR_MSS_CACHE_ENABLE>();

            if (l_cache_enable != l_cache_enable_attr)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "call_mss_getecid: ATTR_MSS_CACHE_ENABLE override (0x%02x)",
                    l_cache_enable_attr);
            }

            // At this point HALF_A/HALF_B are only possible due to override
            if ((l_cache_enable_attr !=
                 fapi::ENUM_ATTR_MSS_CACHE_ENABLE_ON) &&
                (l_cache_enable_attr !=
                 fapi::ENUM_ATTR_MSS_CACHE_ENABLE_HALF_A) &&
                (l_cache_enable_attr !=
                 fapi::ENUM_ATTR_MSS_CACHE_ENABLE_HALF_B))
            {
                // Deconfigure the L4 Cache Targets (there should be 1)
                TargetHandleList l_list;
                getChildChiplets(l_list, l_pCentaur, TYPE_L4, false);

                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "call_mss_getecid: deconfiguring %d L4s (Centaur huid: 0x%.8X)",
                    l_list.size(), get_huid(l_pCentaur));

                for (TargetHandleList::const_iterator
                        l_l4_iter = l_list.begin();
                        l_l4_iter != l_list.end();
                        ++l_l4_iter)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "call_mss_getecid: deconfiguring L4 (huid: 0x%.8X)",
                        get_huid( *l_l4_iter));

                    l_err = HWAS::theDeconfigGard().
                        deconfigureTarget(**l_l4_iter ,
                                    HWAS::DeconfigGard::
                                                DECONFIGURED_BY_MEMORY_CONFIG);

                    if (l_err)
                    {
                        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                                  "ERROR: error deconfiguring Centaur L4");

                        // Create IStep error log
                        //   and cross reference error that occurred
                        l_StepError.addErrorDetails( l_err);

                        // Commit Error
                        errlCommit(l_err, HWPF_COMP_ID);
                    }
                }
            }
            else
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "call_mss_getecid: Centaur L4 good, not deconfiguring");
            }
        }

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "SUCCESS :  mss_get_cen_ecid HWP( )" );
    }

    #ifdef CONFIG_BMC_IPMI
        // Gather + Send the IPMI Fru Inventory data to the BMC
        IPMIFRUINV::setData(true);
    #endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_getecid exit" );
*/
    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
