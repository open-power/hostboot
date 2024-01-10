/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep07/host_mss_attr_cleanup.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2024                        */
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
 *  @file host_mss_attr_cleanup.C
 *  Place holder for cleaning up memory related attributes.
 *  Currently used for misc functions.
 */

/******************************************************************************/
// Includes
/******************************************************************************/

#include    <attribute_service.H>
#include    <errl/errlentry.H>
#include    <errl/errlmanager.H>
#include    <isteps/hwpisteperror.H>
#include    <initservice/isteps_trace.H>
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/util.H>
#include    <devicefw/userif.H>
#include    <vpd/spdenums.H>
#include    <util/misc.H>
#include    <chipids.H>
#include    <hwas/common/hwasCallout.H>


namespace   ISTEP_07
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ISTEPS_TRACE;
using   namespace   ERRORLOG;
using   namespace   TARGETING;


/*******************************************************************************
 * @brief if mix of exp/ody ocmb is found, deconfigure the ocmbs of lesser number
 *
 * @return   true if mixed ocmbs are found and require deconfig, else false
 ******************************************************************************/
int enforce_ocmb_mixing_rules(void)
{
    TRACFCOMP(g_trac_isteps_trace, ">>enforce_ocmb_mixing_rules");

    int              l_rc = 0; // exit rc
    TargetHandleList l_exp{};  // list of exp in system
    TargetHandleList l_ody{};  // list of ody in system

    //--------------------------------------------------------------------------
    // loop through the exp/ody in the system
    // *save vectors of each exp/ody
    //--------------------------------------------------------------------------
    for (const auto ocmb : composable(getChipResources)(TYPE_OCMB_CHIP,
                                                        UTIL_FILTER_FUNCTIONAL))
    {
        ATTR_CHIP_ID_type chipId = ocmb->getAttr<ATTR_CHIP_ID>();

        if      (chipId == POWER_CHIPID::EXPLORER_16) {l_exp.push_back(ocmb);}
        else if (chipId == POWER_CHIPID::ODYSSEY_16)  {l_ody.push_back(ocmb);}
    }

    //--------------------------------------------------------------------------
    // check for a mix of exp/ody
    //--------------------------------------------------------------------------
    if (l_exp.size() && l_ody.size())
    {
        // ERROR, mix of exp/ody
        TRACFCOMP(g_trac_isteps_trace,
                  "enforce_ocmb_mixing_rules: ERROR: mix of exp:%d ody:%d found",
                  l_exp.size(), l_ody.size());

        TargetHandleList *l_deconfigs = nullptr; // ptr to ocmbs to deconfig

        if (l_exp.size() > l_ody.size())
        {
            l_deconfigs = &l_ody; // more exp, deconfig odysseys
        }
        else
        {
            l_deconfigs = &l_exp; // equal or more ody, deconfig explorers
        }

        errlHndl_t l_errl = nullptr;  // error log, if there is a deconfig

        // deconfig the type of ocmbs with a smaller count
        for (const auto ocmb : *l_deconfigs)
        {
            if (!l_errl)    // allocate only one error log for all deconfigs
            {
                /*@
                * @errortype
                * @severity   ERRL_SEV_UNRECOVERABLE
                * @moduleid   MOD_MSS_ATTR_CLEANUP
                * @reasoncode RC_OCMB_MIXING_RULES_ERROR
                * @userdata1  number of explorer ocmbs
                * @userdata2  number of odyssey ocmbs
                * @devdesc    Cannot mix explorer and odyssey ocmbs
                * @custdesc   Firmware detected an invalid mix of DIMMs
                */
                l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                       MOD_MSS_ATTR_CLEANUP,
                                       RC_OCMB_MIXING_RULES_ERROR,
                                       l_exp.size(),
                                       l_ody.size());
                l_errl->addProcedureCallout(HWAS::EPUB_PRC_MEMORY_PLUGGING_ERROR,
                                            HWAS::SRCI_PRIORITY_MED);
            }

            l_errl->addHwCallout(ocmb, HWAS::SRCI_PRIORITY_MED,
                                       HWAS::DELAYED_DECONFIG,
                                       HWAS::GARD_NULL);
        }
        l_rc = -1;
        errlCommit(l_errl, ISTEP_COMP_ID);
    }

    TRACFCOMP(g_trac_isteps_trace, "<<enforce_ocmb_mixing_rules: rc:%d", l_rc);
    return l_rc;
}

/*******************************************************************************
 * @brief Clear out any memory repairs from the DIMMS
 *        -get all the functional Dimms
 *        -clear DDIM repairs
 ******************************************************************************/
void clearMemRepairs()
{
    errlHndl_t       l_err = nullptr;
    TargetHandleList l_funcDimmList;

    // Get all the functional Dimms
    getAllLogicalCards(l_funcDimmList, TYPE_DIMM, true);

    // DIMM_BAD_DQ_DATA
    for (const auto & l_Dimm: l_funcDimmList)
    {
        // Read ATTR_CLEAR_DIMM_SPD_ENABLE attribute
        Target* l_sys = NULL;
        targetService().getTopLevelTarget(l_sys);

        ATTR_CLEAR_DIMM_SPD_ENABLE_type l_clearSPD =
            l_sys->getAttr<TARGETING::ATTR_CLEAR_DIMM_SPD_ENABLE>();

        // If SPD clear is enabled then write 0's into magic word for
        // DIMM_BAD_DQ_DATA keyword
        // Note: If there's an error from performing the clearing,
        // just log the error and continue.
        if (l_clearSPD)
        {
            size_t l_size = 0;

            // Do a read to get the DIMM_BAD_DQ_DATA keyword size
            uint64_t spdKey = fapi2::platAttrSvc::getDimmRepairSpdKey(l_Dimm);
            l_err = deviceRead(l_Dimm, NULL, l_size,
                               DEVICE_SPD_ADDRESS(spdKey));
            if (l_err)
            {
                TRACFCOMP( g_trac_isteps_trace,
                           ERR_MRK"host_mss_attr_cleanup() "
                           "Error reading DIMM_BAD_DQ_DATA keyword size");
                errlCommit( l_err, HWPF_COMP_ID );
            }
            else
            {
                // Clear the data
                TRACFCOMP( g_trac_isteps_trace,
                           "Clearing out BAD_DQ_DATA SPD on DIMM HUID 0x%X",
                           get_huid(l_Dimm));

                uint8_t * l_data = static_cast<uint8_t*>(malloc( l_size ));
                memset(l_data, 0, l_size);

                l_err = deviceWrite(l_Dimm, l_data, l_size,
                                    DEVICE_SPD_ADDRESS(spdKey));
                if (l_err)
                {
                    TRACFCOMP( g_trac_isteps_trace,
                               ERR_MRK"host_mss_attr_cleanup() "
                               "Error trying to clear SPD on DIMM HUID 0x%X",
                               get_huid(l_Dimm));
                    errlCommit( l_err, HWPF_COMP_ID );
                }

                // Free the memory
                if (NULL != l_data)
                {
                    free(l_data);
                }
            }
        }
    }
    return;
}

/*******************************************************************************
 * @brief Replicate HB memory mirroring policy into HWP policy
 ******************************************************************************/
void setupDynamicAttrs()
{
    Target* l_pTopLevel = UTIL::assertGetToplevelTarget();
    auto l_mirror = l_pTopLevel->getAttr<TARGETING::ATTR_PAYLOAD_IN_MIRROR_MEM>();

    if(l_mirror)
    {
        l_pTopLevel->setAttr<TARGETING::ATTR_MRW_HW_MIRRORING_ENABLE>
          (TARGETING::MRW_HW_MIRRORING_ENABLE_REQUIRED);
    }
    else
    {
        l_pTopLevel->setAttr<TARGETING::ATTR_MRW_HW_MIRRORING_ENABLE>
          (TARGETING::MRW_HW_MIRRORING_ENABLE_OFF);
    }
    return;
}

/*******************************************************************************
 * @brief   Wrapper function to call mss_attr_update
 *          mss_attr_update no longer used
 *          will use this for other misc functions
 ******************************************************************************/
void* host_mss_attr_cleanup(void *io_pArgs)
{
    TRACFCOMP(g_trac_isteps_trace, "host_mss_attr_cleanup entry");

    IStepError l_StepError;

    //--------------------------------------------------------------------------
    // Enforce mixing rules between Explorer and Odyssey
    //--------------------------------------------------------------------------
    if (enforce_ocmb_mixing_rules())
    {
        // a delayed deconfig of ocmb is pending, so just exit
        goto EXIT;
    }

    //--------------------------------------------------------------------------
    //  Clear out any memory repairs from the DIMMS
    //--------------------------------------------------------------------------
    clearMemRepairs();

    //--------------------------------------------------------------------------
    // Setup any dynamic attributes
    //--------------------------------------------------------------------------
    setupDynamicAttrs();

    //--------------------------------------------------------------------------
    //  Setup any SPPE state attributes before sync to OCMB (like Odyssey)
    //--------------------------------------------------------------------------
    TARGETING::update_sppe_target_state();

EXIT:
    TRACFCOMP( g_trac_isteps_trace, "host_mss_attr_cleanup exit");

    return l_StepError.getErrorHandle();
}

};   // end namespace
