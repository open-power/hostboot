/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep16/call_host_ipl_complete.C $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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

/** @file call_host_ipl_complete.C
 *  @brief Host IPL Complete function
 */

#include <errl/errlentry.H>
#include <initservice/isteps_trace.H>
#include <isteps/hwpisteperror.H>
#include <errl/errludtarget.H>
#include <errl/errlmanager.H>

#include <initservice/initserviceif.H>
#include <initservice/istepdispatcherif.H>

//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/mfgFlagAccessors.H>
#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>

#include <targeting/attrrp.H>
#include <sys/internode.h>
#include <runtime/runtime.H>
#include <util/utiltce.H>

#include <util/utilsemipersist.H>
#include <hwas/common/deconfigGard.H>

#ifdef CONFIG_DEVTREE
#include <devtree/devtree.H>
#endif
#ifdef CONFIG_PLDM
#include <pldm/extended/pdr_manager.H>
#endif

#include <vmmconst.h>
#include <targeting/targplatutil.H>
#include <secureboot/service.H>

#include <algorithm>

using namespace ERRORLOG;
using namespace TARGETING;
using namespace ISTEP;
using namespace ISTEP_ERROR;

using namespace fapi2;

namespace ISTEP_16
{

void sw511706_convert_to_checkstop(IStepError& stepError);
void sw511706_mask(IStepError& stepError);

void* call_host_ipl_complete(void* const io_pArgs)
{
    errlHndl_t l_err = nullptr;

    IStepError l_stepError;

    TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "call_host_ipl_complete entry");
    do
    {
        // only run on non-FSP systems
        if (!INITSERVICE::spBaseServicesEnabled())
        {
            //No more reconfig loops are supported from this point
            //forward. Clean up the semi persistent area
            //   1) clear magic number (so next boot thinks it is cold)
            //      a) DON'T clear mfg term setting (so read-modify)
            //   2) clear any reconfig specific gard records
            Util::semiPersistData_t l_semiData;  //inits to 0s
            Util::readSemiPersistData(l_semiData);
            l_semiData.magic = 0x0;
            Util::writeSemiPersistData(l_semiData);

            l_err = HWAS::clearGardByType(HWAS::GARD_Reconfig);
            if (l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR 0x%.8X: clearGardByType(GARD_Reconfig)",
                          l_err->reasonCode() );
                // Create IStep error log and cross ref error that occurred
                l_stepError.addErrorDetails( l_err );
                errlCommit( l_err, ISTEP_COMP_ID );
            }

            l_err = HWAS::clearGardByType(HWAS::GARD_Sticky_deconfig);
            if (l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR 0x%.8X: clearGardByType(GARD_Sticky_deconfig)",
                          l_err->reasonCode() );
                // Create IStep error log and cross ref error that occurred
                l_stepError.addErrorDetails( l_err );
                errlCommit( l_err, ISTEP_COMP_ID );
            }
        }

        if (TCE::utilUseTcesForDmas())
        {
            l_err = TCE::utilSetupPayloadTces();

            if (l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          ERR_MRK"TCE::utilSetupPayloadTces failed");
                // Don't continue with the rest of this istep
                break;
            }
        }

        // Initialize the RUNTIME DATA attributes
        // that HDAT needs to allocate memory for us.
        // -----------------------------------------
        TARGETING::Target* sys = nullptr;
        TARGETING::targetService().getTopLevelTarget(sys);
        assert(sys != nullptr);

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "Initialize the runtime data attributes for HDAT consumption");

        // Set number of pointer pairs for HDAT HB RESERVED MEM
        uint32_t l_numRsvMemSections = HB_RSV_MEM_NUM_PTRS;
        sys->setAttr<ATTR_HDAT_RSV_MEM_NUM_SECTIONS>(l_numRsvMemSections);

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "number of HB Reserved mem sections = %d",
                  l_numRsvMemSections);

        // Set number of pointer pairs for HDAT HBRT
        uint32_t l_numHbrtSections = HBRT_NUM_PTRS;
        sys->setAttr<ATTR_HDAT_HBRT_NUM_SECTIONS>(l_numHbrtSections);

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "number of HBRT sections = %d",
                  l_numHbrtSections);

        // Set max size of a HBRT section for HDAT
        TARGETING::ATTR_HDAT_HBRT_SECTION_SIZE_type l_secSize = {0};

        uint64_t* const l_p_secSize = reinterpret_cast<uint64_t *>(&l_secSize);

        const uint32_t l_attrArraySize = std::size(l_secSize);

        assert(l_numHbrtSections <= l_attrArraySize);

        const uint64_t l_attrSize = AttrRP::maxSize();

        const uint64_t l_maxSecSize = std::max(l_attrSize, VMM_RT_VPD_SIZE);

        for (uint32_t l_sect = 0; l_sect < l_numHbrtSections; l_sect++)
        {
            l_p_secSize[l_sect] = l_maxSecSize;
        }

        sys->setAttr<ATTR_HDAT_HBRT_SECTION_SIZE>(l_secSize);

        // populate PHYP ATTN Area Attributes with values
        const auto l_nodeTgt = TARGETING::UTIL::getCurrentNodeTarget();
        if (INITSERVICE::spBaseServicesEnabled() && is_phyp_load())
        {
            // calculate absolute address for PHYP SP ATTN areas
            const auto l_abs = RUNTIME::calcSpAttnAreaStart();

            const auto spAttnArea1Addr = l_abs;
            const auto spAttnArea2Addr = l_abs + PHYP_ATTN_AREA_1_SIZE;

            l_nodeTgt->setAttr<ATTR_ATTN_AREA_1_ADDR>(spAttnArea1Addr);
            l_nodeTgt->setAttr<ATTR_ATTN_AREA_2_ADDR>(spAttnArea2Addr);
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, INFO_MRK"Set attributes "
                      "for PHYP ATTN areas. ATTN Area 1: 0x%.16llX ATTN Area 2: "
                      "0x%.16llX",
                      spAttnArea1Addr,
                      spAttnArea2Addr);
        }

        // Clear ATTR_KEY_CLEAR_REQUEST before sync.
        // - Any Key Clear Request should have already been saved in ATTR_KEY_CLEAR_REQUEST_HB
        // - Clear attribute at System and Node Level for now.  HWSV will handle
        //   any discrepancies of the attribute between the nodes
        auto keyClearRequests = KEY_CLEAR_REQUEST_NONE;
        sys->setAttr<ATTR_KEY_CLEAR_REQUEST>(keyClearRequests);
        l_nodeTgt->setAttr<ATTR_KEY_CLEAR_REQUEST>(keyClearRequests);

#ifdef CONFIG_PLDM
        PLDM::thePdrManager().sendAllFruFunctionalStates();
#endif

        // Sync attributes to Fsp/Bmc
        l_err = TARGETING::AttrRP::syncAllAttributesToSP();

        if (l_err)
        {
            break;
        }

        // Send Sync Point to Fsp
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  INFO_MRK"Send SYNC_POINT_REACHED msg to Fsp");
        l_err = INITSERVICE::sendSyncPoint();

        switch (sys->getAttr<TARGETING::ATTR_SW511706_CHECKSTOP_ON_GTE_LV1_HANG>())
        {
        case 1:
            sw511706_convert_to_checkstop(l_stepError);
            break;
        case 2:
            sw511706_mask(l_stepError);
            break;
        default:
            break;
        }
    } while(0);

    // Collect and log any remaining errors
    if (l_err)
    {
        // Create IStep error log and cross reference error that occurred
        l_stepError.addErrorDetails(l_err);

        // Commit Error
        errlCommit(l_err, HWPF_COMP_ID);
    }

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "call_host_ipl_complete exit");

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
} // end call_host_ipl_complete

using namespace TARGETING;

void sw511706_convert_to_checkstop(IStepError& stepError)
{
    errlHndl_t l_err = nullptr;

    // SW511706: Convert "hang recovery level gte1" errors into checkstops from recoverables

    const auto zero_ninth_bit = [](TARGETING::Target* proc, const uint64_t address)
        {
            uint64_t value = 0;
            uint64_t size = 8;

            errlHndl_t l_err = deviceRead(proc, &value, size, DEVICE_SCOM_ADDRESS(address));

            if (l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          ERR_MRK"SW511706: SCOM read of 0x%016x on 0x%08x failed: " TRACE_ERR_FMT,
                          address, get_huid(proc), TRACE_ERR_ARGS(l_err));
                return l_err;
            }

            const uint64_t ninth_bit_mask = 0x1ull << (63 - 9);

            value &= ~ninth_bit_mask;
            size = 8;

            l_err = deviceWrite(proc, &value, size, DEVICE_SCOM_ADDRESS(address));

            if (l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          ERR_MRK"SW511706: SCOM write of 0x%016x on 0x%08x failed: " TRACE_ERR_FMT,
                          address, get_huid(proc), TRACE_ERR_ARGS(l_err));
                return l_err;
            }

            return l_err;
        };

    TargetHandleList procs;
    getAllChips(procs, TYPE_PROC);

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              ERR_MRK"SW511706: found %d processors",
              procs.size());

    for (const auto proc : procs)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  ERR_MRK"SW511706: Setting PowerBus PB RaceTrack Station nest domain FIR Action 0/1 Register[9] to 0 on processor %08x",
                  get_huid(proc));

        /* Perform SCOM operations to make "hang recovery level gte1" FIRs into
         * checkstops rather than recoverable errors. */

        // PowerBus PB RaceTrack Station nest domain FIR Action 0 Register
        // PB.PB_COM.PB_SCOM_ES3.PB_STATION_FIR_ACTION0_REG
        const uint64_t address1 = 0x03011386;
        // PowerBus PB RaceTrack Station nest domain FIR Action 1 Register
        // PB.PB_COM.PB_SCOM_ES3.PB_STATION_FIR_ACTION1_REG
        const uint64_t address2 = 0x03011387;

        l_err = zero_ninth_bit(proc, address1);
        l_err || (l_err = zero_ninth_bit(proc, address2));

        if (l_err)
        {
            stepError.addErrorDetails(l_err);
            errlCommit(l_err, HWPF_COMP_ID);
            break;
        }
    }
}

void sw511706_mask(IStepError& stepError)
{
    errlHndl_t l_err = nullptr;

    // SW511706: Mask "hang recovery level gte1" errors

    const auto set_ninth_bit = [](TARGETING::Target* proc, const uint64_t address)
        {
            uint64_t value = 0;
            uint64_t size = 8;

            errlHndl_t l_err = deviceRead(proc, &value, size, DEVICE_SCOM_ADDRESS(address));

            if (l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          ERR_MRK"SW511706: SCOM read of 0x%016x on 0x%08x failed: " TRACE_ERR_FMT,
                          address, get_huid(proc), TRACE_ERR_ARGS(l_err));
                return l_err;
            }

            const uint64_t ninth_bit_mask = 0x1ull << (63 - 9);

            value |= ninth_bit_mask;
            size = 8;

            l_err = deviceWrite(proc, &value, size, DEVICE_SCOM_ADDRESS(address));

            if (l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          ERR_MRK"SW511706: SCOM write of 0x%016x on 0x%08x failed: " TRACE_ERR_FMT,
                          address, get_huid(proc), TRACE_ERR_ARGS(l_err));
                return l_err;
            }

            return l_err;
        };

    TargetHandleList procs;
    getAllChips(procs, TYPE_PROC);

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              ERR_MRK"SW511706: found %d processors",
              procs.size());

    for (const auto proc : procs)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  ERR_MRK"SW511706: Setting PowerBus PB RaceTrack Station nest domain FIR MASK[9] to 1 on processor 0x%08x",
                  get_huid(proc));

        /* Perform SCOM operation to mask "hang recovery level gte1" FIRs */

        // PowerBus PB RaceTrack Station nest domain FIR MASK register
        // PB.PB_COM.PB_SCOM_ES3.PB_STATION_FIR_MASK_REG
        const uint64_t address = 0x3011383;

        l_err = set_ninth_bit(proc, address);

        if (l_err)
        {
            stepError.addErrorDetails(l_err);
            errlCommit(l_err, HWPF_COMP_ID);
            break;
        }
    }
}

} // end namespace ISTEP_16
