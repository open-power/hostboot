/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep06/host_discover_targets.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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

#include <stdint.h>
#include <map>
#include <vector>
#include <trace/interface.H>
#include <sys/misc.h>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <targeting/attrsync.H>
#include <targeting/namedtarget.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/mfgFlagAccessors.H>
#include <targeting/common/entitypath.H>
#include <targeting/common/targetservice.H>
#include <targeting/targplatutil.H>
#include <initservice/taskargs.H>
#include <initservice/isteps_trace.H>
#include <initservice/initserviceif.H>
#include <initservice/istepdispatcherif.H>
#include <isteps/hwpisteperror.H>
#include <istepHelperFuncs.H>
#include <initservice/isteps_trace.H>
#include <hwas/common/hwas.H>
#include <hwas/common/hwasCommon.H>
#include <hwas/common/hwas_reasoncodes.H>
#include <hwas/hwasPlat.H>
#include <vpd/vpd_if.H>
#include <console/consoleif.H>
#include <attributetraits.H>
#ifdef CONFIG_PLDM
#include <pldm/extended/pdr_manager.H>
#include <pldm/extended/hb_fru.H>
#include <pldm/extended/pldm_entity_ids.H>
#include <pldm/extended/sbe_dump.H>
#include <pldm/requests/pldm_pdr_requests.H>
#include <pldm/pldm_errl.H>
#endif
#include <fapi2/plat_hwp_invoker.H>
#include <fapi2/target.H>
#include <eeprom/eepromCache.H>
#include <runtime/customize_attrs_for_payload.H>
#include <devtree/devtree.H>


//SBE interfacing
#include <sbeio/sbeioif.H>
#include <sys/misc.h>
#include <sbe/sbeif.H>

// FIXME RTC: 208841 MPIPL support
//#include <p9_query_core_access_state.H>
#include <p10_setup_sbe_config.H>
//#include <p9_query_cache_access_state.H>
//#include <p9_hcd_core_stopclocks.H>
//#include <p9_hcd_cache_stopclocks.H>
//#include <p9_hcd_common.H>
//#include <p9_quad_power_off.H>
//#include <p9_perv_scom_addresses.H>

#ifdef CONFIG_PRINT_SYSTEM_INFO
#include <stdio.h>
#endif

//  HWP call support
#include <nest/nestHwpHelperFuncs.H>   // fapiHWPCallWrapperHandler


namespace ISTEP_06
{

#ifdef CONFIG_PRINT_SYSTEM_INFO

//Loop through list of targets and print out HUID and other key attributes if
//the target has it
void print_target_list(TARGETING::TargetHandleList i_targetList)
{

    for(auto & l_targ : i_targetList)
    {
        char * l_targetString =
        l_targ->getAttr<TARGETING::ATTR_PHYS_PATH>().toString();

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "%s", l_targetString);

        free(l_targetString);

        //Every target has a HUID so it is safe to assume this will return okay
        //from getAttr
        uint32_t l_huid =  get_huid(l_targ );

        //if output says DEAD then the attribute is not defined
        uint32_t l_isFunc = 0xDEAD;
        uint32_t l_isPres = 0xDEAD;
        uint32_t l_pos = 0xDEAD;
        uint32_t l_fapi_pos = 0xDEAD;
        uint32_t l_chip_unit = 0xDEAD;

        //The rest of these attributes may or may not exist on the target, so
        //only add them to the string if the attribute exists
        TARGETING::AttributeTraits<TARGETING::ATTR_HWAS_STATE>::Type hwasState;
        if(l_targ->tryGetAttr<TARGETING::ATTR_HWAS_STATE>(hwasState))
        {
            l_isFunc = hwasState.functional;
            l_isPres = hwasState.present;
        }

        TARGETING::AttributeTraits<TARGETING::ATTR_POSITION>::Type position;
        if(l_targ->tryGetAttr<TARGETING::ATTR_POSITION>(position))
        {
            l_pos = position;
        }

        TARGETING::AttributeTraits<TARGETING::ATTR_FAPI_POS>::Type fapi_position;
        if(l_targ->tryGetAttr<TARGETING::ATTR_FAPI_POS>(fapi_position))
        {
            l_fapi_pos = fapi_position;
        }

        TARGETING::AttributeTraits<TARGETING::ATTR_CHIP_UNIT>::Type chip_unit;
        if(l_targ->tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(chip_unit))
        {
            l_chip_unit = chip_unit;
        }

        //Trace out the string
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,"HUID:0x%x   Functional: 0x%x   Present: 0x%x      Position: 0x%x     FAPI_POS: 0x%x     Chip Unit: 0x%x",
                                                     l_huid,      l_isFunc,          l_isPres,          l_pos,             l_fapi_pos,        l_chip_unit);

    }
}

//Debugging tool used to print out target information early on in IPL
void print_system_info(void)
{
    //Vector of target types you want to print out
    std::vector<TARGETING::AttributeTraits<TARGETING::ATTR_TYPE>::Type> types_to_print;

    //Add all the target types that you want to see in the output to this vector
    types_to_print.push_back(TARGETING::TYPE_PROC);
    types_to_print.push_back(TARGETING::TYPE_DIMM);
    types_to_print.push_back(TARGETING::TYPE_CORE);
    types_to_print.push_back(TARGETING::TYPE_MC);
    types_to_print.push_back(TARGETING::TYPE_MI);
    types_to_print.push_back(TARGETING::TYPE_MCC);
    types_to_print.push_back(TARGETING::TYPE_OCMB_CHIP);

    //Loop through each type to get a list of targets then print it out
    for(auto l_type : types_to_print)
    {
        TARGETING::PredicateCTM l_CtmFilter(TARGETING::CLASS_NA,
                                            l_type,
                                            TARGETING::MODEL_NA);

        // Apply the filter through all targets
        TARGETING::TargetRangeFilter l_targetList(TARGETING::targetService().begin(),
                                                  TARGETING::targetService().end(),
                                                  &l_CtmFilter);

        TARGETING::TargetHandleList l_allTargets;

        for ( ; l_targetList; ++l_targetList)
        {
            l_allTargets.push_back(*l_targetList);
        }

        print_target_list(l_allTargets);
    }

}
#endif


/**
*  @brief  Walk through list of PROC chip targets and send a continueMPIPL
*          FIFO chip-op to all of the secondary PROC chips
*
*  @return     errlHndl_t
*/
errlHndl_t sendContinueMpiplChipOp()
{
    errlHndl_t l_err = nullptr;

    TARGETING::TargetHandleList l_procChips;
    TARGETING::getAllChips(l_procChips, TARGETING::TYPE_PROC, true);
    TARGETING::PROC_SBE_MASTER_CHIP_ATTR l_is_master_chip = 1;

    for(const auto & l_chip : l_procChips)
    {
        l_is_master_chip = l_chip->getAttr<TARGETING::ATTR_PROC_SBE_MASTER_CHIP>();
        if(!l_is_master_chip)
        {
            l_err = SBEIO::sendContinueMpiplRequest(l_chip);

            if(l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "Failed sending continueMPIPL request on this proc = %x",
                          l_chip->getAttr<TARGETING::ATTR_HUID>());
                break;
            }
        }
    }
    return l_err;
}

/**
*  @brief  Walk through list of PROC chip targets and run p10_setup_sbe_config
*          HWP on all of the secondary PROC chips to ensure scratch regs are updated
*
*  @return     errlHndl_t
*/
errlHndl_t updateSecondarySbeScratchRegs()
{
    errlHndl_t l_err = nullptr;
    TARGETING::TargetHandleList l_procChips;
    TARGETING::getAllChips(l_procChips, TARGETING::TYPE_PROC, true);
    TARGETING::PROC_SBE_MASTER_CHIP_ATTR l_is_master_chip = 1;

    for(const auto & l_chip : l_procChips)
    {
        l_is_master_chip = l_chip->getAttr<TARGETING::ATTR_PROC_SBE_MASTER_CHIP>();
        if(!l_is_master_chip)
        {
            fapi2::Target <fapi2::TARGET_TYPE_PROC_CHIP> l_fapi_proc_target (l_chip);
            // Run the setup_sbe_config hwp on all of the secondary procs to make sure
            // the scratch registers are up to date prior to sending the continueMPIPL
            // operation
            FAPI_INVOKE_HWP(l_err,
                            p10_setup_sbe_config,
                            l_fapi_proc_target);

            if(l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "Failed during updateSecondarySbeScratchRegs request on this proc = %x",
                          l_chip->getAttr<TARGETING::ATTR_HUID>());
                break;
            }
        }
    }
    return l_err;
}

#ifdef CONFIG_PLDM

/* @brief Add local PDRs and finish the first half of the PDR exchange with the
 *        BMC (until and including Hostboot notifying the BMC that it has added
 *        its own PDRs to its repository). Presence detection should have already
 *        been done.
 *
 * @return errlHndl_t Error if any, otherwise nullptr.
 */
static errlHndl_t exchange_pdrs()
{
    /* Perform part of the PDR exchange sequence with the BMC. We will get their
     * PDRs first, then allow them to request our PDRs after we send them a PDR
     * Repository Changed event. */

    errlHndl_t l_err = nullptr;

    do
    {
        /* Save a list of the BMC's PDR handles. */

        const auto bmc_pdr_handles = PLDM::thePdrManager().getAllPdrHandles();

        /* Add our own PDRs to our repository. */

        l_err = addHostbootPdrs(PLDM::thePdrManager());

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      ERR_MRK"Failed to add local PDR to pdr repository");
            break;
        }

        auto hb_pdr_handles = PLDM::thePdrManager().getAllPdrHandles();

        /*  Remove the BMC handles from the HB PDR handle list */

        const auto bmc_pdrs
            = std::remove_if(begin(hb_pdr_handles), end(hb_pdr_handles),
                             [&bmc_pdr_handles](const uint32_t handle)
                             {
                                 return (std::find(cbegin(bmc_pdr_handles), cend(bmc_pdr_handles), handle)
                                         != cend(bmc_pdr_handles));
                             });

        hb_pdr_handles.erase(bmc_pdrs, end(hb_pdr_handles));

        /* Notify the BMC that our PDR repository has changed. */

        // The BMC will request the handle we tell them changed, and each
        // subsequent handle in the PDR repository.
        const auto lowest_handle = std::accumulate(begin(hb_pdr_handles), end(hb_pdr_handles),
                                                   hb_pdr_handles.front(),
                                                   std::min<PLDM::pdr_handle_t>);

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "Sending PDR notification to the BMC for %llu new Hostboot PDRs (lowest handle = 0x%08x)",
                  hb_pdr_handles.size(),
                  lowest_handle);

        TARGETING::UTIL::assertGetToplevelTarget()->setAttr<TARGETING::ATTR_PLDM_HB_PDR_COUNT>(hb_pdr_handles.size());

        l_err = PLDM::thePdrManager().sendPdrRepositoryChangeEvent({ lowest_handle });

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      ERR_MRK"Failed to send repository update event to BMC");
            break;
        }
    } while (false);

    return l_err;
}

/* @brief Finish the PDR exchange by waiting on the BMC to send a "PDR
 *        Repository Changed" notification to us, and then refetching their PDR
 *        repository.
 * @return errlHndl_t  Error if any, otherwise nullptr.
 */
static errlHndl_t finish_pdr_exchange()
{
    /* Wait on the BMC to notify us that it is ready for us to request its
     * new PDRs. */

    errlHndl_t l_err = nullptr;

    do
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "Awaiting PDR Repository Changed notification from the BMC");

        l_err = PLDM::thePdrManager().awaitBmcPdrRepoChanged(PLDM::PdrManager::TIMEOUT_MAX_MS);
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      ERR_MRK"Failed while waiting for PDR repository update event from BMC");
            break;
        }

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "Received PDR Repository Changed notification from the BMC");

        /* Re-fetch the normalized PDRs from the BMC. */

        PLDM::thePdrManager().resetPdrs();

        l_err = PLDM::thePdrManager().addRemotePdrs();
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      ERR_MRK"Failed to re-add remote PDRs to PDR manager");
            break;
        }

        const auto sys = TARGETING::UTIL::assertGetToplevelTarget();

        // Verify BMC returned at least previous BMC count + HB count
        if ( (sys->getAttr<TARGETING::ATTR_PLDM_HB_PDR_COUNT>() +
             sys->getAttr<TARGETING::ATTR_PLDM_BMC_PDR_COUNT>()) >
             PLDM::thePdrManager().pdrCount() )
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  ERR_MRK"Current BMC pdr count %d is less than previous BMC count %d + HB count %d",
                  PLDM::thePdrManager().pdrCount(),
                  sys->getAttr<TARGETING::ATTR_PLDM_BMC_PDR_COUNT>(),
                  sys->getAttr<TARGETING::ATTR_PLDM_HB_PDR_COUNT>());
            /*@
             * @errortype
             * @moduleid   ISTEP::MOD_FINISH_PDR_EXCHANGE
             * @reasoncode ISTEP::RC_TOO_SMALL_BMC_PDR_COUNT
             * @userdata1  Current BMC PDR count (should includes HB PDRs)
             * @userdata2[0:31]  BMC PDR count before HB pdr exchange
             * @userdata2[32:63] Hostboot PDR count sent to BMC
             * @devdesc    BMC returned less PDRs than previous BMC + HB PDRs
             * @custdesc   A software error occurred during system boot
             */
            l_err = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                  ISTEP::MOD_FINISH_PDR_EXCHANGE,
                                  ISTEP::RC_TOO_SMALL_BMC_PDR_COUNT,
                                  PLDM::thePdrManager().pdrCount(),
                                  TWO_UINT32_TO_UINT64(
                                  sys->getAttr<TARGETING::ATTR_PLDM_BMC_PDR_COUNT>(),
                                  sys->getAttr<TARGETING::ATTR_PLDM_HB_PDR_COUNT>()),
                                  ErrlEntry::NO_SW_CALLOUT);
            PLDM::addBmcErrorCallouts(l_err);
            l_err->collectTrace(ISTEP_COMP_NAME);
            errlCommit(l_err, ISTEP_COMP_ID);

            // The reboot message is for the benefit of the customer's understanding of what's going on. However,
            // there may be situations where this reboot is triggered that isn't caused by a hotplug issue, e.g. a code
            // bug.
            INITSERVICE::requestReboot("Rebooting due to a FRU hot-remove");
        }
        // now update BMC PDR count to latest count which includes HB PDRs
        sys->setAttr<TARGETING::ATTR_PLDM_BMC_PDR_COUNT>(PLDM::thePdrManager().pdrCount());

        // Verify HB Terminus Locator PDR exists in repo
        l_err = PLDM::thePdrManager().checkForHbTerminusLocator();
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                ERR_MRK"Failed to find HB Terminus Locator in PDR repo");
            break;
        }

        /* Assign the PLDM-aware targets their entity IDs */

        l_err = PLDM::assignTargetEntityIds();

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      ERR_MRK"Failed to set PLDM entity IDs for targets");
            break;
        }
    } while (false);


    return l_err;
}

#endif // CONFIG_PLDM

/**
 * @brief host_discover_targets istep
 */
void* host_discover_targets( void *io_pArgs )
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "host_discover_targets entry" );

    errlHndl_t l_err(nullptr);
    ISTEP_ERROR::IStepError l_stepError;

    do
    {

    // Check whether we're in MPIPL mode
    TARGETING::Target* l_pTopLevel = TARGETING::UTIL::assertGetToplevelTarget();
    if (l_pTopLevel->getAttr<TARGETING::ATTR_IS_MPIPL_HB>())
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "host_discover_targets: MPIPL mode, targeting "
                  "information has already been loaded from memory "
                  "when the targeting service started");
        do
        {
            // We will not perform presence detection and there should be a
            // populated EECACHE from the previous IPL. This being said
            // we must walk the EECACHE partition and populate the map
            // we use in code to do EECACHE lookups.
            l_err = EEPROM::cacheEECACHEPartition();
            if (l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          ERR_MRK"host_discover_targets: BREAK Failed to cacheEECACHEPartition");
                break;
            }

            // if cores/fused cores were deconfigured due to Field Core
            // Override (FCO), set target 'functional' to re-enable
            // for use or for FCO selection again
            // get all present Non ECO cores on the system
            TARGETING::TargetHandleList l_cores;
            getNonEcoCores(l_cores, nullptr, false);
            for (auto l_core : l_cores)
            {
                HWAS::applyCoreFunctionalOverride(l_core);
            }
            // get all present Non ECO fused cores on the system
            getNonEcoFcs(l_cores, nullptr, false);
            for (auto l_fc : l_cores)
            {
                HWAS::applyCoreFunctionalOverride(l_fc);
            }

            // Need to ensure secondary SBE's scratch registers are
            // up to date prior to sending continueMPIPL op
            l_err = updateSecondarySbeScratchRegs();
            if (l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          ERR_MRK"host_discover_targets: BREAK Failed to updateSecondarySbeScratchRegs");
                break;
            }

            // Send continue mpipl op to secondary procs
            l_err = sendContinueMpiplChipOp();
            if (l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          ERR_MRK"host_discover_targets: BREAK Failed to sendContinueMpiplChipOp");
                break;
            }

            // Mask off the IOHS/PAUC FIRs (normally part of
            // p10_proc_chiplet_scominit. Make the FAPI call to
            // p10_io_iohs_firmask_save_restore
            const bool l_success = ISTEP::fapiHWPCallWrapperHandler(
                                 ISTEP::P10_IO_IOHS_FIRMASK_SAVE_RESTORE,
                                 l_stepError,
                                 ISTEP_COMP_ID,
                                 TARGETING::TYPE_PROC);
            if( !l_success )
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          ERR_MRK"host_discover_targets: Error calling p10_io_iohs_firmask_save_restore");
            }

        }while(0);

    }
    else
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "host_discover_targets: Normal IPL mode");

#if( defined(CONFIG_SUPPORT_EEPROM_CACHING) && !defined(CONFIG_SUPPORT_EEPROM_HWACCESS) )
        l_err = EEPROM::cacheEECACHEPartition();
#endif

        if(nullptr == l_err)
        {
            HWAS::HWASDiscovery l_HWASDiscovery;
            l_err = l_HWASDiscovery.discoverTargets();
        }
    }

#ifdef CONFIG_PLDM
    /* Second step of the PDR exchange is to add local PDRs and notify the
     * BMC that we have done so. This will cause them to fetch the new PDRs
     * from us. This has to be done after presence detection. */

    if (!l_err)
    {
        l_err = exchange_pdrs();

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      ERR_MRK"host_discover_targets: Failed to exchange PDRs with the BMC");

            captureError(l_err, l_stepError, ISTEP_COMP_ID);
            break;
        }
    }
#endif


#if (defined(CONFIG_MEMVPD_READ_FROM_HW)&&defined(CONFIG_MEMVPD_READ_FROM_PNOR))
    // Now that all targets have completed presence detect and vpd access,
    // invalidate PNOR::CENTAUR_VPD sections where all the targets sharing a
    // VPD_REC_NUM are invalid.
    if (nullptr == l_err) //discoverTargets worked
    {
        l_err = VPD::validateSharedPnorCache();
    }
#endif

    if (l_err)
    {
        captureError(l_err, l_stepError, ISTEP_COMP_ID);
    }

#if (!defined(CONFIG_CONSOLE_OUTPUT_TRACE) && defined(CONFIG_CONSOLE))
    CONSOLE::displayf(CONSOLE::DEFAULT, "HWAS", "---------------------------------");
    CONSOLE::displayf(CONSOLE::DEFAULT, "HWAS", "PRESENT>");
#endif
    TARGETING::PredicateHwas l_isPresent;
    l_isPresent.present(true);

    TARGETING::UTIL::displayProcChildrenBitmasks(&l_isPresent);
#if (!defined(CONFIG_CONSOLE_OUTPUT_TRACE) && defined(CONFIG_CONSOLE))
    CONSOLE::displayf(CONSOLE::DEFAULT, "HWAS", "---------------------------------");
#endif

    // Force a sync to the BMC if there were any new parts
    //  This will give the BMC a more accurate view of things in case
    //  anyone looks before we do the full sync at the end of step16
    DEVTREE::syncIfChanged();

    // Cross-check our list with what the SP saw
    //  Any errors will be committed inline
    HWAS::crosscheck_sp_presence();

    // Make the PSU call to get and apply the SBE Capabilities on the boot proc
    TARGETING::TargetHandle_t l_pMasterProcChip(nullptr);
    TARGETING::targetService().masterProcChipTargetHandle(l_pMasterProcChip);
    if (l_pMasterProcChip)
    {
#ifdef CONFIG_SBE_PRESENT
        l_err = SBEIO::getPsuSbeCapabilities(l_pMasterProcChip);
#endif
        if (l_err)
        {
            // Commit Error
            errlCommit (l_err, ISTEP_COMP_ID);
        }
    }  // end if (l_pMasterProcChip)


#ifdef CONFIG_PRINT_SYSTEM_INFO
    print_system_info();
#endif

    // Now that we have all of the targets set up we can assign HBRT ids
    // to all of the targets. These are the IDs the Hypervisors use to ID
    // a given target. We set them up now because we want to make sure the
    // attribute is set long before HDAT code consumes them.
    l_err = RUNTIME::configureHbrtHypIds(TARGETING::is_phyp_load());
    if(l_err)
    {
        captureError(l_err, l_stepError, ISTEP_COMP_ID);
    }

#if CONFIG_PLDM
    l_err = finish_pdr_exchange();

    if (l_err)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  ERR_MRK"host_discover_targets: PDR exchange failed");
        captureError(l_err, l_stepError, ISTEP_COMP_ID);
        break;
    }

    // Notify the BMC that we are not able to take SBE HRESET requests. (We
    // will be ready at runtime.)
    PLDM::notifySbeHresetsReady(false);

    // Set initial progress state
    PLDM::sendProgressStateChangeEvent(
        PLDM_STATE_SET_BOOT_PROG_STATE_PRIMARY_PROC_INITIALIZATION);
#endif // CONFIG_PLDM

    // Send AttrRP notification that we have completed host_discover_targets
    // (which completes presence detection).
    //
    // We can now OPEN the attribute sync window to allow RECONFIG loops to
    // sync attributes down to the SP.
    //
    // This prevents performing an attribute sync which may possibly have
    // CLEARED EECACHE.  This may inappropriately identify the primary PROC
    // as -NOT- functional which would inhibit forward progression.

    l_err = TARGETING::AttrRP::notifyResourceReady(
              TARGETING::AttrRP::RESOURCE::SYNC_WINDOW_OPEN);
    if (l_err)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK"host_discover_targets: PROBLEM with SYNC_WINDOW_OPEN");
        captureError(l_err, l_stepError, ISTEP_COMP_ID);
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "host_discover_targets exit" );

    } while (0); // main loop

    return l_stepError.getErrorHandle();
}

};
