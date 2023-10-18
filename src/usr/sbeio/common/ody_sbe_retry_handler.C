/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/common/ody_sbe_retry_handler.C $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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

#include <fapi2.H>
#include <fapi2/plat_hwp_invoker.H>
#include <trace/interface.H>
#include <sbeio/sbe_retry_handler.H>
#include <targeting/targplatutil.H>
#include <targeting/odyutil.H>
#include <sbeio/sbeioreasoncodes.H>
#include <errl/errlreasoncodes.H>
#include "sbe_fifodd.H"
#include <sbeio/sbeioif.H>


#include <ody_extract_sbe_rc.H>
#include <ody_sbe_hreset.H>
#include <ody_sppe_check_for_ready.H>

#define SBE_TRACF(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"ody_sbe_retry_handler: " printf_string,##args)

extern trace_desc_t* g_trac_sbeio;

namespace SBEIO
{

GenericSbeRetryHandler::~GenericSbeRetryHandler()
{
}

/**
 * OdysseySbeRetryHandler implementation
 */

OdysseySbeRetryHandler::OdysseySbeRetryHandler(TARGETING::Target* const i_ocmb)
    : iv_ocmb(i_ocmb)
{
}

void OdysseySbeRetryHandler::main_sbe_handler(const bool i_sbeHalted)
{
    SBE_TRACF(ENTER_MRK"OdysseySbeRetryhandler::main_sbe_handler HUID=0x%X", get_huid(iv_ocmb));
    errlHndl_t l_errl = nullptr;
    // Use the SBE_RECOVERY_IN_PROGRESS (a per-target attribute) to prevent any re-entrant callers.
    // If an OCMB target has already entered this function, then we are prohibiting any recursive
    // callers.  During HBRT we are single threaded, so not an issue, however during IPL, in theory,
    // multi-threaded callers *could*  attempt.
    auto l_sbe_recovery_in_progress = iv_ocmb->getAttr<TARGETING::ATTR_SBE_RECOVERY_IN_PROGRESS>();
    if (!l_sbe_recovery_in_progress)
    {
        iv_ocmb->setAttr<TARGETING::ATTR_SBE_RECOVERY_IN_PROGRESS>(1);
        SBE_TRACF("OdysseySbeRetryHandler::main_sbe_handler SET RECOVERY IN PROGRESS HUID=0x%X", get_huid(iv_ocmb));
    }
    else
    {
        /*@ There is no action possible. Gard and Callout the OCMB
         * @errortype  ERRL_SEV_INFORMATIONAL
         * @moduleid   SBEIO_ODY_RECOVERY
         * @reasoncode SBEIO_ODY_RECOVERY_IN_PROGRESS
         * @userdata1  HUID of Odyssey OCMB
         * @userdata2  Unused
         * @devdesc    There is no recovery action on the SBE.
         * @custdesc   OCMB Error
         */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                         SBEIO_ODY_RECOVERY,
                                         SBEIO_ODY_RECOVERY_IN_PROGRESS,
                                         TARGETING::get_huid(iv_ocmb),
                                         0,
                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        SBE_TRACF("OdysseySbeRetryHandler::main_sbe_handler recovery in progress HUID=0x%X ERRL=0x%X (committing)",
                  get_huid(iv_ocmb), ERRL_GETEID_SAFE(l_errl));
        errlCommit(l_errl, SBEIO_COMP_ID); // Commit since the caller gets void return
        goto ERROR_EXIT;
    }

    // First determine if any errors are resident in the Odyssey SBE, see ExtractRC for its filtering mechanisms
    // Only valid errors should be bubbled back to this layer
    l_errl = ExtractRC();
    if (l_errl)
    {
        SBE_TRACF("OdysseySbeRetryHandler:main_sbe_handler ody_extract_sbe_rc returned an error 0x%X (committing)", ERRL_GETEID_SAFE(l_errl));
        errlCommit(l_errl, SBEIO_COMP_ID);
    }
    else
    {
        SBE_TRACF("OdysseySbeRetryHandler:main_sbe_handler ody_extract_sbe_rc did not find any error");
    }

    {
        bool isRuntimeOrMpIpl = false;
        if(TARGETING::UTIL::assertGetToplevelTarget()->getAttr<TARGETING::ATTR_IS_MPIPL_HB>())
        {
            isRuntimeOrMpIpl = true;
        }
#if defined (__HOSTBOOT_RUNTIME)
        isRuntimeOrMpIpl = true;
#endif
        if (isRuntimeOrMpIpl)
        {
            // At runtime or MPIPL, the caller enters main_sbe_handler to properly hreset the Odyssey SBE.
            // During runtime or MPIPL, the only valid option is for the hreset recovery
            l_errl = hreset();
            if (l_errl)
            {
                SBE_TRACF("OdysseySbeRetryHandler:main_sbe_handler hreset returned an error 0x%X", ERRL_GETEID_SAFE(l_errl));
                // @TODO PFHB-542 BAD PATH will refine
                errlCommit(l_errl, SBEIO_COMP_ID);
            }
        }
        else
        {
            l_errl = dump();
            if (l_errl)
            {
                SBE_TRACF("OdysseySbeRetryHandler:main_sbe_handler dump returned an error 0x%X", ERRL_GETEID_SAFE(l_errl));
                // @TODO JIRA: PFHB-290 Dump the Odyssey (work will be addressed during story work)
                errlCommit(l_errl, SBEIO_COMP_ID);
            }
        }
    }

    iv_ocmb->setAttr<TARGETING::ATTR_SBE_RECOVERY_IN_PROGRESS>(0);
ERROR_EXIT: // Skip the decrement since we were already in progress
    SBE_TRACF(EXIT_MRK"OdysseySbeRetryHandler::main_sbe_handler HUID=0x%X l_sbe_recovery_in_progress=0x%X",
              get_huid(iv_ocmb), l_sbe_recovery_in_progress);
}

errlHndl_t OdysseySbeRetryHandler::ExtractRC()
{
    SBE_TRACF(ENTER_MRK"OdysseySbeRetryhandler::ExtractRC HUID=0x%X", get_huid(iv_ocmb));
    errlHndl_t l_errl = nullptr;
    FAPI_INVOKE_HWP(l_errl, ody_extract_sbe_rc, { iv_ocmb });

    if (l_errl && l_errl->getUserData1() == fapi2::RC_SPPE_RUNNING)
    { // if the SPPE is running, the error log doesn't contain anything useful.
        SBE_TRACF("OdysseySbeRetryhandler::ExtractRC HUID=0x%X DELETE RC_SPPE_RUNNING ERRL=0x%X",
                  get_huid(iv_ocmb), ERRL_GETEID_SAFE(l_errl));
        delete l_errl;
        l_errl = nullptr;
    }

    SBE_TRACF(EXIT_MRK"OdysseySbeRetryhandler::ExtractRC HUID=0x%X", get_huid(iv_ocmb));
    return l_errl;
}

errlHndl_t OdysseySbeRetryHandler::hreset()
{
    SBE_TRACF(ENTER_MRK"OdysseySbeRetryhandler::hreset HUID=0x%X", get_huid(iv_ocmb));
    errlHndl_t l_errl = nullptr;
    fapi2::Target <fapi2::TARGET_TYPE_OCMB_CHIP>l_fapi_ocmb_target(iv_ocmb);

    FAPI_INVOKE_HWP(l_errl, ody_sbe_hreset, { iv_ocmb });
    if (l_errl)
    {
        SBE_TRACF("OdysseySbeRetryHandler::hreset failed ody_sbe_hreset HUID=0x%X",
                  get_huid(iv_ocmb));
        goto HRESET_ERROR_EXIT;
    }
    SBE_TRACF("OdysseySbeRetryHandler::hreset passed ody_sbe_hreset HUID=0x%X",
              get_huid(iv_ocmb));

    FAPI_INVOKE_HWP(l_errl, ody_sppe_check_for_ready, l_fapi_ocmb_target);
    if (l_errl)
    {
        SBE_TRACF("OdysseySbeRetryHandler::hreset failed ody_sppe_check_for_ready HUID=0x%X",
                  get_huid(iv_ocmb));
        goto HRESET_ERROR_EXIT;
    }
    SBE_TRACF("OdysseySbeRetryHandler::hreset passed ody_sppe_check_for_ready HUID=0x%X",
              get_huid(iv_ocmb));

    // Reset the FIFO to sync HB and the SBE, @TODO JIRA: PFHB-542 confirm performFifoReset does the proper handshaking
    l_errl = SbeFifo::getTheInstance().performFifoReset(iv_ocmb);
    if (l_errl)
    {
        SBE_TRACF("OdysseySbeRetryHandler::hreset failed performFifoReset HUID=0x%X",
                  get_huid(iv_ocmb));
        goto HRESET_ERROR_EXIT;
    }
    SBE_TRACF("OdysseySbeRetryHandler::hreset passed performFifoReset HUID=0x%X",
              get_huid(iv_ocmb));

    // Need to send ALL attributes via chip-ops to restore the settings in Odyssey
    l_errl = SBEIO::sendAttrUpdateRequest(iv_ocmb); // push pull ody_generate_sbe_attributes
    if (l_errl)
    {
        SBE_TRACF("OdysseySbeRetryHandler::hreset failed ody_generate_sbe_attributes HUID=0x%X",
                  get_huid(iv_ocmb));
        goto HRESET_ERROR_EXIT;
    }
    SBE_TRACF("OdysseySbeRetryHandler::hreset passed ody_generate_sbe_attributes HUID=0x%X",
              get_huid(iv_ocmb));

    {
        uint32_t l_odySensorPollingPeriod = iv_ocmb->getAttr<TARGETING::ATTR_ODY_SENSOR_POLLING_PERIOD_MS_INIT>();
        uint8_t  l_odyDqsTrackingPeriod = iv_ocmb->getAttr<TARGETING::ATTR_ODY_DQS_TRACKING_PERIOD_INIT>();
        // enable thermal sensor polling and DQA tracking, chipop AC-02
        l_errl = SBEIO::sendExecHWPRequestForThermalSensorPolling(iv_ocmb,
                                                                  l_odySensorPollingPeriod,
                                                                  l_odyDqsTrackingPeriod);
        if (l_errl)
        {
            SBE_TRACF("OdysseySbeRetryHandler::hreset failed ThermalSensorPolling HUID=0x%X",
                      get_huid(iv_ocmb));
            goto HRESET_ERROR_EXIT;
        }
        SBE_TRACF("OdysseySbeRetryHandler::hreset passed ThermalSensorPolling "
                  "l_odySensorPollingPeriod=0x%X l_odyDqsTrackingPeriod=0x%X HUID=0x%X",
                   l_odySensorPollingPeriod, l_odyDqsTrackingPeriod, get_huid(iv_ocmb));
    }

HRESET_ERROR_EXIT:
    // @TODO JIRA: PFHB-542 HRESET Bad Path, covers any FFDC gathering, etc
    SBE_TRACF(EXIT_MRK"OdysseySbeRetryhandler::hreset HUID=0x%X", get_huid(iv_ocmb));
    return l_errl;
}

errlHndl_t OdysseySbeRetryHandler::dump()
{
    // @TODO JIRA: PFHB-290 Dump the Odyssey SBE HERE
    SBE_TRACF(ENTER_MRK"OdysseySbeRetryhandler::dump HUID=0x%X", get_huid(iv_ocmb));
    errlHndl_t l_errl = nullptr;
    SBE_TRACF(EXIT_MRK"OdysseySbeRetryhandler::dump HUID=x%X", get_huid(iv_ocmb));
    return l_errl;
}


OdysseySbeRetryHandler::~OdysseySbeRetryHandler()
{
}

}
