/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_mss_getecid.C $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>

#include    <hwas/common/deconfigGard.H>

//  targeting support.
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

//Fapi Support
#include    <config.h>
#include    <fapi2.H>
#include    <fapi2/plat_hwp_invoker.H>
#include    <util/utilmbox_scratch.H>

//HWP
#ifndef CONFIG_AXONE
    #include <p9c_mss_get_cen_ecid.H>
#else
    #include <chipids.H>
// @todo RTC 208512   #include  <exp_getecid.H>
    #include  <gem_getecid.H>
#endif


using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;


namespace ISTEP_12
{
void cumulus_mss_getecid(IStepError & io_istepError);
void axone_mss_getecid(IStepError & io_istepError);

void* call_mss_getecid (void *io_pArgs)
{
    IStepError l_StepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_getecid entry" );
    auto l_procModel = TARGETING::targetService().getProcessorModel();

    switch (l_procModel)
    {
        case TARGETING::MODEL_CUMULUS:
            cumulus_mss_getecid(l_StepError);
            break;
        case TARGETING::MODEL_AXONE:
            axone_mss_getecid(l_StepError);
            break;
        case TARGETING::MODEL_NIMBUS:
        default:
            break;
    }


    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_getecid exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

#ifndef CONFIG_AXONE
void cumulus_mss_getecid(IStepError & io_istepError)
{
    errlHndl_t l_err = NULL;
    uint8_t    l_ddr_port_status = 0;
    uint8_t    l_cache_enable = 0;
    uint8_t    l_centaur_sub_revision = 0;

    ecid_user_struct l_ecidUser;  // Do not need to be initalized by caller

    mss_get_cen_ecid_ddr_status l_mbaBadMask[2] =
       { MSS_GET_CEN_ECID_DDR_STATUS_MBA0_BAD,
         MSS_GET_CEN_ECID_DDR_STATUS_MBA1_BAD };

    // Get all Centaur targets
    TARGETING::TargetHandleList l_membufTargetList;
    getAllChips(l_membufTargetList, TYPE_MEMBUF);

    for ( const auto & l_membuf_target : l_membufTargetList )
    {
        // Dump current run on target
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "Running p9c_mss_get_cen_ecid HWP on "
                "target HUID %.8X", TARGETING::get_huid(l_membuf_target));

        //  call the HWP with each target
        fapi2::Target <fapi2::TARGET_TYPE_MEMBUF_CHIP> l_fapi_centaur
                (l_membuf_target);

        //  call the HWP with each fapi2::Target
        //  Note:  This HWP does not actually return the entire ECID data.  It
        //  updates the attribute ATTR_MSS_ECID and returns the DDR port status
        //  which is a portion of the ECID data.
        FAPI_INVOKE_HWP(l_err, p9c_mss_get_cen_ecid,
                        l_fapi_centaur, l_ddr_port_status,
                        l_cache_enable, l_centaur_sub_revision, l_ecidUser);
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X: p9c_mss_get_cen_ecid HWP returns error",
                      l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_membuf_target).addToLog( l_err );

            // Create IStep error log and cross reference error that occurred
            io_istepError.addErrorDetails( l_err );

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
                                 l_membuf_target,
                                 TYPE_MBA);

                for ( const auto & l_mba_target : l_mbaTargetList )
                {
                    // Get the MBA chip unit position
                    ATTR_CHIP_UNIT_type l_pos =
                        l_mba_target->getAttr<ATTR_CHIP_UNIT>();

                    // Check the DDR port status to see if this MBA should be
                    // set to nonfunctional.
                    if ( l_ddr_port_status & l_mbaBadMask[l_pos] )
                    {
                        // call HWAS to deconfigure this target
                        l_err = HWAS::theDeconfigGard().deconfigureTarget(
                                    *l_mba_target,
                                    HWAS::DeconfigGard::
                                    DECONFIGURED_BY_MEMORY_CONFIG);
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
                    io_istepError.addErrorDetails( l_err );

                    // Commit Error
                    errlCommit( l_err, HWPF_COMP_ID );
                }
            }

            // mss_get_cen_ecid returns if the L4 cache is enabled. This can be
            // - fapi2::ENUM_ATTR_CEN_MSS_CACHE_ENABLE_OFF
            // - fapi2::ENUM_ATTR_CEN_MSS_CACHE_ENABLE_ON
            // - fapi2::ENUM_ATTR_CEN_MSS_CACHE_ENABLE_HALF_A
            // - fapi2::ENUM_ATTR_CEN_MSS_CACHE_ENABLE_HALF_B
            // - fapi2::ENUM_ATTR_CEN_MSS_CACHE_ENABLE_UNK_OFF
            // - fapi2::ENUM_ATTR_CEN_MSS_CACHE_ENABLE_UNK_ON
            // - fapi2::ENUM_ATTR_CEN_MSS_CACHE_ENABLE_UNK_HALF_A
            // - fapi2::ENUM_ATTR_CEN_MSS_CACHE_ENABLE_UNK_HALF_B
            // The UNK values are for DD1.* Centaur chips where the fuses were
            // not blown correctly so the cache may not be in the correct state.
            //
            // Firmware does not normally support HALF enabled
            // If ON then ATTR_CEN_MSS_CACHE_ENABLE is set to ON
            // Else ATTR_CEN_MSS_CACHE_ENABLE is set to OFF and the L4 Target is
            //   deconfigured
            //
            // However, an engineer can override ATTR_CEN_MSS_CACHE_ENABLE. If they
            // override it to HALF_A or HALF_B then
            // - ATTR_CEN_MSS_CACHE_ENABLE is set to HALF_X
            // - The L4 Target is not deconfigured
            if (l_cache_enable != fapi2::ENUM_ATTR_CEN_MSS_CACHE_ENABLE_ON)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "call_mss_getecid: mss_get_cen_ecid returned L4 not-on (0x%02x)",
                    l_cache_enable);
                l_cache_enable = fapi2::ENUM_ATTR_CEN_MSS_CACHE_ENABLE_OFF;
            }

            // ATTR_CEN_MSS_CACHE_ENABLE is not set as writeable in src/import/chips/centaur/procedures/xml/attribute_info/memory_attributes.xml
            // Should we remove below code?
            // Set the ATTR_CEN_MSS_CACHE_ENABLE attribute
            //l_membuf_target->setAttr<TARGETING::ATTR_CEN_MSS_CACHE_ENABLE>(
            //    l_cache_enable);

            // Read the ATTR_CEN_MSS_CACHE_ENABLE back to pick up any override
            uint8_t l_cache_enable_attr =
                l_membuf_target->getAttr<TARGETING::ATTR_CEN_MSS_CACHE_ENABLE>();

            if (l_cache_enable != l_cache_enable_attr)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "call_mss_getecid: ATTR_CEN_MSS_CACHE_ENABLE override (0x%02x)",
                    l_cache_enable_attr);
            }


            // At this point HALF_A/HALF_B are only possible due to override
            if ((l_cache_enable_attr !=
                 fapi2::ENUM_ATTR_CEN_MSS_CACHE_ENABLE_ON) &&
                (l_cache_enable_attr !=
                 fapi2::ENUM_ATTR_CEN_MSS_CACHE_ENABLE_HALF_A) &&
                (l_cache_enable_attr !=
                 fapi2::ENUM_ATTR_CEN_MSS_CACHE_ENABLE_HALF_B))
            {
                // Deconfigure the L4 Cache Targets (there should be 1)
                TargetHandleList l_list;
                getChildChiplets(l_list, l_membuf_target, TYPE_L4, false);

                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "call_mss_getecid: deconfiguring %d L4s (Centaur huid: 0x%.8X)",
                    l_list.size(), get_huid(l_membuf_target));

                for ( const auto & l_l4_target : l_list )
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "call_mss_getecid: deconfiguring L4 (huid: 0x%.8X)",
                        get_huid(l_l4_target));

                    l_err = HWAS::theDeconfigGard().
                        deconfigureTarget( *l_l4_target,
                            HWAS::DeconfigGard::DECONFIGURED_BY_MEMORY_CONFIG);

                    if (l_err)
                    {
                        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                                  "ERROR: error deconfiguring Centaur L4");

                        // Create IStep error log
                        //   and cross reference error that occurred
                        io_istepError.addErrorDetails( l_err);

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
}
#else
void cumulus_mss_getecid(IStepError & io_istepError)
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
              "Error: Trying to call 'p9c_mss_get_cen_ecid' but Cumulus code is not compiled in");
    assert(0, "Calling wrong Model's HWPs");
}
#endif

#ifdef CONFIG_AXONE
void axone_mss_getecid(IStepError & io_istepError)
{
    errlHndl_t l_err = NULL;

    // Get all OCMB targets
    TARGETING::TargetHandleList l_ocmbTargetList;
    getAllChips(l_ocmbTargetList, TYPE_OCMB_CHIP);

    bool isGeminiChip = false;
    for (const auto & l_ocmb_target : l_ocmbTargetList)
    {
        fapi2::Target <fapi2::TARGET_TYPE_OCMB_CHIP>
            l_fapi_ocmb_target(l_ocmb_target);

        // check EXPLORER first as this is most likely the configuration
        uint32_t chipId = l_ocmb_target->getAttr< TARGETING::ATTR_CHIP_ID>();
        if (chipId == POWER_CHIPID::EXPLORER_16)
        {
            isGeminiChip = false;
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running exp_getecid HWP on target HUID 0x%.8X",
                TARGETING::get_huid(l_ocmb_target) );
            //@todo RTC 208512: FAPI_INVOKE_HWP(l_err, exp_getecid, l_fapi_ocmb_target);
        }
        else
        {
            isGeminiChip = true;
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running gem_getecid HWP on target HUID 0x%.8X, chipId 0x%.4X",
                TARGETING::get_huid(l_ocmb_target), chipId );
            FAPI_INVOKE_HWP(l_err, gem_getecid, l_fapi_ocmb_target);
        }

        //  process return code.
        if ( l_err )
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR 0x%.8X : %s_getecid HWP returned error",
                l_err->reasonCode(), isGeminiChip?"gem":"exp");

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_ocmb_target).addToLog(l_err);

            // Create IStep error log and cross reference to error that occurred
            io_istepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );

            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS running %s_getecid HWP on target HUID 0x%.8X",
                isGeminiChip?"gem":"exp", TARGETING::get_huid(l_ocmb_target) );
        }
    }
}
#else
void axone_mss_getecid(IStepError & io_istepError)
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
              "Error: Trying to call 'gem_getecid' or 'exp_getecid' but Axone code is not compiled in");
    assert(0, "Calling wrong Model's HWPs");
}
#endif
};
