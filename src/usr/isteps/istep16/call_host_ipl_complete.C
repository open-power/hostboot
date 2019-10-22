/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep16/call_host_ipl_complete.C $             */
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
#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>

/* TODO RTC 245393: P10 implementation
#include <p10_switch_rec_attn.H>
*/

#include <targeting/attrrp.H>
#include <sys/internode.h>
#include <runtime/runtime.H>
#include <util/utiltce.H>

#include <util/utilsemipersist.H>
#include <hwas/common/deconfigGard.H>
#ifdef CONFIG_BMC_IPMI
#include <ipmi/ipmisensor.H>
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
            //forward.  Clean up the semi persistent area
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
                          "ERROR 0x%.8X: clearGardByType( )",
                          l_err->reasonCode() );
                // Create IStep error log and cross ref error that occurred
                l_stepError.addErrorDetails( l_err );
                errlCommit( l_err, ISTEP_COMP_ID );
            }
        }

#ifdef CONFIG_BMC_IPMI
        // Alert BMC to clear HB volatile memory
        SENSOR::HbVolatileSensor l_hbVolatileCtl;
        l_err = l_hbVolatileCtl.setHbVolatile(SENSOR::HbVolatileSensor::ENABLE_VOLATILE);
        if(l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "Failure in notifying BMC to clear hostboot volatile section,"
                      " RC=%X", ERRL_GETRC_SAFE(l_err));

            // This error could come from OpenPower system without
            // updated OpenBMC code so just delete the error
            delete l_err;
            l_err = nullptr;
        }
#endif

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

        TARGETING::TargetHandleList l_procChips;
        //Use targeting code to get a list of all processors
        getAllChips(l_procChips, TARGETING::TYPE_PROC);

        //Loop through all of the procs and call the HWP on each one
        for (const auto & l_procChip: l_procChips)
        {
            const fapi2::Target<TARGET_TYPE_PROC_CHIP> l_fapiProcTarget(l_procChip);

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "Running p10_switch_rec_attn HWP on target HUID %.8X",
                      TARGETING::get_huid(l_procChip));

            /* @TODO RTC 245393: Update for P10
#ifdef ISTEP16_ENABLE_HWPS
            //  call p10_switch_rec_attn
            FAPI_INVOKE_HWP(l_err, p10_switch_rec_attn, l_fapiProcTarget);
#endif
            */

            if (l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR 0x%.8X: p10_switch_rec_attn HWP returned error: "
                          TRACE_ERR_FMT,
                          l_err->reasonCode(),
                          TRACE_ERR_ARGS(l_err));

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_procChip).addToLog(l_err);

                //Create IStep error log and cross reference error that occurred
                l_stepError.addErrorDetails(l_err);

                //break to end because if p10_switch_rec_attn fails
                //recoverable/special attentions control didnt make it back
                // to the fsp, this is a fatal error
                break;
            }
            else
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "SUCCESS: p10_switch_rec_attn HWP( ) on target HUID %.8X",
                          TARGETING::get_huid(l_procChip));
            }
        }

        // if an error occurred during for loop, break to error handling
        if (l_err)
        {
            break;
        }

        // populate PHYP ATTN Area Attributes with values
        if (INITSERVICE::spBaseServicesEnabled() && is_phyp_load())
        {
            // calculate absolute address for PHYP SP ATTN areas
            const auto l_abs = RUNTIME::calcSpAttnAreaStart();

            const auto spAttnArea1Addr = l_abs;
            const auto spAttnArea2Addr = l_abs + PHYP_ATTN_AREA_1_SIZE;

            const auto l_nodeTgt = TARGETING::UTIL::getCurrentNodeTarget();

            l_nodeTgt->setAttr<ATTR_ATTN_AREA_1_ADDR>(spAttnArea1Addr);
            l_nodeTgt->setAttr<ATTR_ATTN_AREA_2_ADDR>(spAttnArea2Addr);
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, INFO_MRK"Set attributes "
                      "for PHYP ATTN areas. ATTN Area 1: 0x%.16llX ATTN Area 2: "
                      "0x%.16llX",
                      spAttnArea1Addr,
                      spAttnArea2Addr);
        }

        // Sync attributes to Fsp
        l_err = TARGETING::AttrRP::syncAllAttributesToFsp();

        if (l_err)
        {
            break;
        }

        // Send Sync Point to Fsp
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  INFO_MRK"Send SYNC_POINT_REACHED msg to Fsp");
        l_err = INITSERVICE::sendSyncPoint();
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

} // end namespace ISTEP_16
