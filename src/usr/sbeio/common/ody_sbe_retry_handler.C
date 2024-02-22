/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/common/ody_sbe_retry_handler.C $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023,2024                        */
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
#include <arch/magic.H>

#include <ody_extract_sbe_rc.H>
#include <ody_sbe_hreset.H>
#include <ody_sppe_check_for_ready.H>

#ifdef CONFIG_PLDM
#include <pldm/extended/sbe_dump.H>
#endif

#include <cxxtest/TestInject.H>

#define SBE_TRACF(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"ody_sbe_retry_handler: " printf_string,##args)

extern trace_desc_t* g_trac_sbeio;

using namespace TARGETING;
using namespace ERRORLOG;

namespace SBEIO
{
#if defined(CONFIG_COMPILE_CXXTEST_HOOKS)

// This macro detects the inject, clears that inject, and creates an error log
#define CI_INJECT_HRESET_FAIL(_g_inject, _ocmb, _enum, _msg, _errl)             \
        if (_g_inject.isSet(_enum))                                             \
        {                                                                       \
            _g_inject.clear(_enum);                                             \
            TRACFCOMP(g_trac_sbeio, _msg                                        \
                      " OCMB 0x%08x", get_huid(_ocmb));                         \
            _errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,   \
                                            SBEIO_TEST_INJECT,                  \
                                            SBEIO_TEST_INJECT_HRESET);          \
        }

// This macro detects the first inject, clears that inject, sets the next inject,
//  and creates an error log
#define CI_INJECT_HRESET_TWO_FAILS(_g_inject, _ocmb, _enum, _e_set, _msg,_errl) \
        if (_g_inject.isSet(_enum))                                             \
        {                                                                       \
            _g_inject.clear(_enum);                                             \
            _g_inject.set(_e_set);                                              \
            TRACFCOMP(g_trac_sbeio, _msg                                        \
                      " OCMB 0x%08x", get_huid(_ocmb));                         \
            _errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,   \
                                            SBEIO_TEST_INJECT,                  \
                                            SBEIO_TEST_INJECT_HRESET);          \
        }

// This macro detects the inject, clears that inject, and sets _skip=true
#define CI_INJECT_HRESET_SKIP_DUMP(_g_inject, _ocmb, _enum, _msg, _skip)        \
        if (_g_inject.isSet(_enum))                                             \
        {                                                                       \
            _g_inject.clear(_enum);                                             \
            TRACFCOMP(g_trac_sbeio, _msg                                        \
                      " OCMB 0x%08x", get_huid(_ocmb));                         \
            _skip = true;                                                       \
        }
#else
#define CI_INJECT_HRESET_FAIL(_g_inject, _i_target, _enum, _msg, _errl)
#define CI_INJECT_HRESET_TWO_FAILS(_g_inject, _ocmb, _enum, _e_set, _msg,_errl)
#define CI_INJECT_HRESET_SKIP_DUMP(_g_inject, _ocmb, _enum, _msg, _skip)
#endif

GenericSbeRetryHandler::~GenericSbeRetryHandler()
{
}

OdySbeRetryHandler::OdySbeRetryHandler(Target* const i_ocmb)
    : iv_ocmb(i_ocmb)
{
}

bool OdySbeRetryHandler::odyssey_recovery_handler()
{
    SBE_TRACF(ENTER_MRK"OdySbeRetryhandler::odyssey_recovery_handler HUID=0x%X", get_huid(iv_ocmb));
    bool l_recovered = false;
    bool isRuntimeOrMpIpl = TARGETING::UTIL::assertGetToplevelTarget()->getAttr<TARGETING::ATTR_IS_MPIPL_HB>();
    bool hreset_already_run = false;
#if defined (__HOSTBOOT_RUNTIME)
    isRuntimeOrMpIpl = true;
#endif
    if (!isRuntimeOrMpIpl)
    {
        SBE_TRACF("OdySbeRetryhandler::odyssey_recovery_handler unsupported at IPL time HUID=0x%X", get_huid(iv_ocmb));
        return l_recovered; // We only support Odyssey odyssey_recovery_handler at runtime or MPIPL
    }

    auto l_ody_recovery_state = iv_ocmb->getAttr<TARGETING::ATTR_ODY_RECOVERY_STATE>();
    if (l_ody_recovery_state != ODY_RECOVERY_STATUS_DEAD)
    {
        // If timeouts occur during checkOdyFFDC, the main_sbe_handler will
        // be invoked within the checkOdyFFDC scope to perform an hreset
        hreset_already_run = SBEIO::checkOdyFFDC(iv_ocmb);
        l_ody_recovery_state = iv_ocmb->getAttr<TARGETING::ATTR_ODY_RECOVERY_STATE>();
    }
    // Let main_sbe_handler own the ODY_RECOVERY_STATUS_IN_PROGRESS

    if ((!hreset_already_run) && (l_ody_recovery_state != ODY_RECOVERY_STATUS_DEAD))
    {
        main_sbe_handler();
    }
    l_ody_recovery_state = iv_ocmb->getAttr<TARGETING::ATTR_ODY_RECOVERY_STATE>();

    if (l_ody_recovery_state == ODY_RECOVERY_STATUS_VIABLE)
    {
        SBE_TRACF("OdySbeRetryhandler::odyssey_recovery_handler VIABLE set l_recovered=true HUID=0x%X", get_huid(iv_ocmb));
        l_recovered = true;
    }
    return l_recovered;
}

void OdySbeRetryHandler::main_sbe_handler(errlHndl_t& io_errl, const bool i_sbeHalted)
{
    errlHndl_t l_errl           = nullptr;
    errlHndl_t l_errl_extractRC = nullptr;
    bool       isRuntimeOrMpIpl{};

    SBE_TRACF(ENTER_MRK"OdySbeRetryHandler::main_sbe_handler HUID=0x%X", get_huid(iv_ocmb));

    // Use the ODY_RECOVERY_STATE (a per-target attribute) to prevent any re-entrant callers.
    // If an OCMB target has already entered this function, then we are prohibiting any recursive
    // callers.  During HBRT we are single threaded, so not an issue, however during IPL, in theory,
    // multi-threaded callers *could*  attempt.
    // @TODO - need a lock??
    if ((iv_ocmb->getAttr<ATTR_ODY_RECOVERY_STATE>()) == ODY_RECOVERY_STATUS_VIABLE)
    {
        iv_ocmb->setAttr<ATTR_ODY_RECOVERY_STATE>(ODY_RECOVERY_STATUS_IN_PROGRESS);
        SBE_TRACF("OdySbeRetryHandler::main_sbe_handler SET RECOVERY IN PROGRESS HUID=0x%X",
                  get_huid(iv_ocmb));
    }
    else // either ODY_RECOVERY_IN_PROGRESS or DEAD
    {
        /*@
         * @errortype  ERRL_SEV_INFORMATIONAL
         * @moduleid   SBEIO_ODY_RECOVERY
         * @reasoncode SBEIO_ODY_RECOVERY_NOT_AVAILABLE
         * @userdata1  HUID of Odyssey OCMB
         * @userdata2  Unused
         * @devdesc    There is no recovery action on the SBE.
         * @custdesc   OCMB Error
         */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                         SBEIO_ODY_RECOVERY,
                                         SBEIO_ODY_RECOVERY_NOT_AVAILABLE,
                                         get_huid(iv_ocmb),
                                         0,
                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(SBEIO_COMP_NAME);
        SBE_TRACF("OdySbeRetryHandler::main_sbe_handler recovery not available "
                  "HUID=0x%X ERRL=0x%X (committing)",
                  get_huid(iv_ocmb), ERRL_GETEID_SAFE(l_errl));
        goto EXIT;
    }

    // First determine if any errors are resident in the Odyssey SBE, see ExtractRC
    //  for its filtering mechanisms.
    // Only valid errors should be bubbled back to this layer
    l_errl_extractRC = ExtractRC();
    if (l_errl_extractRC)
    {
        SBE_TRACF("OdySbeRetryHandler::main_sbe_handler ody_extract_sbe_rc "
                  "returned an error 0x%8X", ERRL_GETEID_SAFE(l_errl));
    }

    isRuntimeOrMpIpl = UTIL::assertGetToplevelTarget()->getAttr<ATTR_IS_MPIPL_HB>();
#if defined (__HOSTBOOT_RUNTIME)
    isRuntimeOrMpIpl = true;
#endif

    if (isRuntimeOrMpIpl)
    {
        // During runtime or MPIPL we perform an HRESET, because
        // the SBE can't be restarted after it's dumped, and we
        // don't want to reboot the entire system here.
        l_errl = hreset();
        if (l_errl)
        {
            SBE_TRACF("OdySbeRetryHandler:main_sbe_handler: hreset error 0x%8X",
                      ERRL_GETEID_SAFE(l_errl));
            if (l_errl_extractRC)
            {
                l_errl->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE);
                errlCommit(l_errl_extractRC, SBEIO_COMP_ID);
            }
        }
    }
    else
    {
        // IPL, only action is dump
        l_errl = dump(ERRL_GETEID_SAFE(io_errl));
        if (l_errl)
        {
            SBE_TRACF("OdySbeRetryHandler:main_sbe_handler: dump error 0x%8X",
                      ERRL_GETEID_SAFE(l_errl));
        }
    }

    if (l_errl_extractRC) // cleanup
    {
        delete l_errl_extractRC;
        l_errl_extractRC = nullptr;
    }

    // Note: if ODY_RECOVERY_STATE == DEAD, leave ODY_RECOVERY_STATE as DEAD
    //
    //       *check the reentrant state used to block other threads
    //         if IN_PROGRESS, set VIABLE
    if (iv_ocmb->getAttr<ATTR_ODY_RECOVERY_STATE>() == ODY_RECOVERY_STATUS_IN_PROGRESS)
    {
        iv_ocmb->setAttr<ATTR_ODY_RECOVERY_STATE>(ODY_RECOVERY_STATUS_VIABLE);
    }

 EXIT:
    aggregate(io_errl, l_errl, true /* update plid */);

    SBE_TRACF(EXIT_MRK"OdySbeRetryHandler::main_sbe_handler HUID=0x%X "
                      "ODY_RECOVERY_STATE=0x%X ERRL=0x%X",
                      get_huid(iv_ocmb), iv_ocmb->getAttr<ATTR_ODY_RECOVERY_STATE>(), ERRL_GETEID_SAFE(io_errl));
    return;
}

uint32_t OdySbeRetryHandler::getSbeRegister()
{
    uint32_t l_data = 0;
    uint64_t l_dataSize = sizeof(l_data);
    auto l_errl = deviceRead(iv_ocmb,
                             &l_data,
                             l_dataSize,
                             DEVICE_CFAM_ADDRESS(0x2809));

    if (l_errl)
    {
        SBE_TRACF(ERR_MRK"OdySbeRetryHandler::getSbeRegister: deviceRead "
                  " failed: " TRACE_ERR_FMT,
                  TRACE_ERR_ARGS(l_errl));
        errlCommit(l_errl, SBEIO_COMP_ID);
        l_data = 0;
    }

    return l_data;
}

/*******************************************************************************
 * @brief Execute ody_extract_sbe_rc
 ******************************************************************************/
errlHndl_t OdySbeRetryHandler::ExtractRC()
{
    SBE_TRACF(ENTER_MRK"OdySbeRetryHandler::ExtractRC HUID=0x%X", get_huid(iv_ocmb));

#ifdef __HOSTBOOT_RUNTIME
    const bool isIplTime = false;
#else
    const bool isIplTime = !UTIL::assertGetToplevelTarget()->getAttr<ATTR_IS_MPIPL_HB>();
#endif

    errlHndl_t l_errl = nullptr;

    FAPI_INVOKE_HWP(l_errl,
                    ody_extract_sbe_rc,
                    { iv_ocmb },
                    isIplTime /* set SDB at IPL time so we can do
                                 scoms over I2CR with security on
                                 (this will halt the SPPE but we're
                                 going to reboot anyway) */,
                    false /* prefer CFAM accesses */);

    if (l_errl && l_errl->getUserData1() == fapi2::RC_SPPE_RUNNING)
    {
        // if the SPPE is running, the error log doesn't contain anything useful.
        SBE_TRACF("OdySbeRetryHandler::ExtractRC HUID=0x%X RC_SPPE_RUNNING "
                  "ERRL=0x%X (deleting)",
                  get_huid(iv_ocmb), ERRL_GETEID_SAFE(l_errl));
        delete l_errl;
        l_errl = nullptr;
    }

    SBE_TRACF(EXIT_MRK"OdySbeRetryHandler::ExtractRC HUID=0x%X", get_huid(iv_ocmb));
    return l_errl;
}

/*******************************************************************************
 * @brief Execute the Odyssey hreset
 *
 * run_hreset_flow() to current SIDE
 * if success, then exit
 *
 * run_hreset_flow() to alternate SIDE
 * if success, then exit
 *
 * else, hresets failed, so dump()
 ******************************************************************************/
errlHndl_t OdySbeRetryHandler::hreset()
{
    errlHndl_t l_errl = nullptr;

    do
    {

    SBE_TRACF(ENTER_MRK"OdySbeRetryHandler::hreset HUID=0x%X", get_huid(iv_ocmb));

    /*--------------------------------------------------------------------------
     * CURRENT-SIDE - hreset
     *------------------------------------------------------------------------*/
    l_errl = run_hreset_flow();
    if (!l_errl)
    {
        // SUCCESS
        SBE_TRACF("OdySbeRetryHandler::hreset success (current side) HUID=0x%X",
                  get_huid(iv_ocmb));
        break;
    }

    /*--------------------------------------------------------------------------
     * CURRENT-SIDE - FAIL
     *------------------------------------------------------------------------*/
    SBE_TRACF("OdySbeRetryHandler::hreset: run_hreset_flow failed"
              "(current side) HUID=0x%X ERRL=0x%X (committing)",
              get_huid(iv_ocmb), ERRL_GETEID_SAFE(l_errl));
    l_errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL); // keep some history
    errlCommit(l_errl, SBEIO_COMP_ID);

    // switch from CURRENT to ALTERNATE SIDE
    side_switch();

    /*--------------------------------------------------------------------------
     * ALTERNATE-SIDE - hreset
     *------------------------------------------------------------------------*/
    l_errl = run_hreset_flow();
    if (!l_errl)
    {
        // SUCCESS
        SBE_TRACF("OdySbeRetryHandler::hreset success (alternate side) HUID=0x%X",
                  get_huid(iv_ocmb));
        break;
    }

    /*--------------------------------------------------------------------------
     * ALTERNATE-SIDE - FAIL
     *   We have now failed on side-x and side-y, no more recovery to try
     *------------------------------------------------------------------------*/
    SBE_TRACF("OdySbeRetryHandler::hreset: run_hreset_flow failed "
              "(alternate side) HUID=0x%X ERRL=0x%X (committing), will gather FFDC",
              get_huid(iv_ocmb), ERRL_GETEID_SAFE(l_errl));
    l_errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);

    const uint32_t l_dump_eid = ERRL_GETEID_SAFE(l_errl);

    errlCommit(l_errl, SBEIO_COMP_ID);

    SBE_TRACF("OdySbeRetryHandler::hreset: ODY_RECOVERY_STATE=0x%X",
              iv_ocmb->getAttr<ATTR_ODY_RECOVERY_STATE>());

    // @TODO -  need some kind of SEV_PREDICTIVE log if we aren't able to recover

    /*--------------------------------------------------------------------------
     * ALTERNATE-SIDE - DUMP
     *  All we can do now is grab a dump, which leaves the SBE as DEAD
     *------------------------------------------------------------------------*/
    SBE_TRACF("OdySbeRetryHandler::hreset: collect dump (alternate side) HUID=0x%X",
              get_huid(iv_ocmb));
    l_errl = dump(l_dump_eid);
    if (l_errl)
    {
        l_errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
        errlCommit(l_errl, SBEIO_COMP_ID);
    }

    } while (false);

    SBE_TRACF(EXIT_MRK"OdySbeRetryHandler::hreset: HUID=0x%X ERRL=0x%X "
                      "ODY_RECOVERY_STATE=0x%X",
                      get_huid(iv_ocmb), ERRL_GETEID_SAFE(l_errl),
                      iv_ocmb->getAttr<ATTR_ODY_RECOVERY_STATE>());
    return l_errl;
}

/*******************************************************************************
 * @brief Perform the hreset flow
 *  -ody_sbe_hreset
 *  -ody_sppe_check_for_ready
 *  -sendAttrUpdateRequest
 *  -sendExecHWPRequestForThermalSensorPolling
 ******************************************************************************/
errlHndl_t OdySbeRetryHandler::run_hreset_flow()
{
    errlHndl_t l_errl = nullptr;
    uint32_t   l_odySensorPollingPeriod{};
    uint8_t    l_odyDqsTrackingPeriod{};
    fapi2::Target <fapi2::TARGET_TYPE_OCMB_CHIP>l_fapi_ocmb_target(iv_ocmb);

    SBE_TRACF(ENTER_MRK"OdySbeRetryHandler::run_hreset_flow: HUID=0x%X side=0x%X "
                       "ODY_RECOVERY_STATE=0x%X",
                        get_huid(iv_ocmb), iv_ocmb->getAttr<ATTR_SPPE_BOOT_SIDE>(),
                        iv_ocmb->getAttr<ATTR_ODY_RECOVERY_STATE>());

    /*--------------------------------------------------------------------------
     * ody_sbe_hreset - boot up SBE
     *------------------------------------------------------------------------*/
    FAPI_INVOKE_HWP(l_errl, ody_sbe_hreset, { iv_ocmb }, /*i_use_scom=*/false);

    CI_INJECT_HRESET_FAIL(CxxTest::g_cxxTestInject,
                          iv_ocmb,
                          CxxTest::SBEIO_INJECT_HRESET_ody_sbe_hreset,
                          "OdySbeRetryHandler::run_hreset_flow: "
                          "INJECT_ERROR ody_sbe_hreset",
                          l_errl);
    if (l_errl)
    {
        SBE_TRACF("OdySbeRetryHandler::run_hreset_flow: ody_sbe_hreset failed "
                  "HUID=0x%X ERRL=0x%X",
                  get_huid(iv_ocmb), ERRL_GETEID_SAFE(l_errl));
        goto ERROR_EXIT;
    }
    SBE_TRACF("OdySbeRetryHandler::run_hreset_flow: ody_sbe_hreset success HUID=0x%X",
              get_huid(iv_ocmb));

    /*--------------------------------------------------------------------------
     * ody_sppe_check_for_ready
     *------------------------------------------------------------------------*/
    FAPI_INVOKE_HWP(l_errl, ody_sppe_check_for_ready, l_fapi_ocmb_target);

    CI_INJECT_HRESET_FAIL(CxxTest::g_cxxTestInject,
                          iv_ocmb,
                          CxxTest::SBEIO_INJECT_HRESET_ody_sppe_check_for_ready,
                          "OdySbeRetryHandler::run_hreset_flow: "
                          "INJECT_ERROR ody_sppe_check_for_ready",
                          l_errl);

    CI_INJECT_HRESET_TWO_FAILS(CxxTest::g_cxxTestInject,
                               iv_ocmb,
                               CxxTest::SBEIO_INJECT_HRESET_TWO_FAILS,
                               CxxTest::SBEIO_INJECT_HRESET_ody_sppe_check_for_ready,
                               "OdySbeRetryHandler::run_hreset_flow: "
                               "INJECT_HRESET_TWO_FAILS ody_sppe_check_for_ready",
                               l_errl);
    if (l_errl)
    {
        // pull the SBE traces, since checkOdyFFDC wont run for this case
        MAGIC_INST_GET_SBE_TRACES(iv_ocmb->getAttr<TARGETING::ATTR_ORDINAL_ID>(),
                                  SBEIO_HRESET_CHECK_FOR_READY_FAIL,
                                  MAGIC_GET_ODY_SBE_TRACES);
        SBE_TRACF("OdySbeRetryHandler::run_hreset_flow: ody_sppe_check_for_ready failed "
                  "HUID=0x%X ERRL=0x%X",
                  get_huid(iv_ocmb), ERRL_GETEID_SAFE(l_errl));
        goto ERROR_EXIT;
    }

    // If FFDC is available, grab it, parse it, and commit the resulting error logs
    SBEIO::checkOdyFFDC(iv_ocmb);

    SBE_TRACF("OdySbeRetryHandler::run_hreset_flow: ody_sppe_check_for_ready success "
              "HUID=0x%X",
              get_huid(iv_ocmb));

    /*--------------------------------------------------------------------------
     * sendAttrUpdateRequest
     *   send ALL attributes via chip-ops to restore the settings in Odyssey
     *------------------------------------------------------------------------*/
    l_errl = SBEIO::sendAttrUpdateRequest(iv_ocmb);

    CI_INJECT_HRESET_FAIL(CxxTest::g_cxxTestInject,
                          iv_ocmb,
                          CxxTest::SBEIO_INJECT_HRESET_sendAttrUpdateRequest,
                          "OdySbeRetryHandler::run_hreset_flow: "
                          "INJECT_ERROR sendAttrUpdateRequest",
                          l_errl);
    if (l_errl)
    {
        // ODY_RECOVERY_STATUS_DEAD
        iv_ocmb->setAttr<ATTR_ODY_RECOVERY_STATE>(ODY_RECOVERY_STATUS_DEAD);
        SBE_TRACF(ERR_MRK"OdySbeRetryHandler::run_hreset_flow: sendAttrUpdateRequest "
                         "failed ODY_RECOVERY_STATUS_DEAD "
                         "HUID=0x%X ERRL=0x%X",
                  get_huid(iv_ocmb), ERRL_GETEID_SAFE(l_errl));
        goto ERROR_EXIT;
    }
    SBE_TRACF("OdySbeRetryHandler::run_hreset_flow: sendAttrUpdateRequest success "
              "HUID=0x%X ODY_RECOVERY_STATE=0x%X",
              get_huid(iv_ocmb), iv_ocmb->getAttr<ATTR_ODY_RECOVERY_STATE>());

    // update what could be a stale DEAD from the original side boot
    iv_ocmb->setAttr<ATTR_ODY_RECOVERY_STATE>(ODY_RECOVERY_STATUS_IN_PROGRESS);

    /*--------------------------------------------------------------------------
     * enable thermal sensor polling and DQS tracking, chipop AC-02
     *------------------------------------------------------------------------*/
    l_odySensorPollingPeriod = iv_ocmb->getAttr<ATTR_ODY_SENSOR_POLLING_PERIOD_MS_INIT>();
    l_odyDqsTrackingPeriod   = iv_ocmb->getAttr<ATTR_ODY_DQS_TRACKING_PERIOD_INIT>();
    l_errl = SBEIO::sendExecHWPRequestForThermalSensorPolling(iv_ocmb,
                                                              l_odySensorPollingPeriod,
                                                              l_odyDqsTrackingPeriod);
    CI_INJECT_HRESET_FAIL(CxxTest::g_cxxTestInject,
                          iv_ocmb,
                          CxxTest::SBEIO_INJECT_HRESET_ThermalSensorPolling,
                          "OdySbeRetryHandler::run_hreset_flow: "
                          "INJECT_ERROR ThermalSensorPolling",
                          l_errl);
    if (l_errl)
    {
        SBE_TRACF("OdySbeRetryHandler::run_hreset_flow: ThermalSensorPolling failed "
                  "HUID=0x%X ERRL=0x%X (committing)",
                  get_huid(iv_ocmb), ERRL_GETEID_SAFE(l_errl));
        // Just commit as INFO, let OCC decide how important later if they desire
        //  -do not return the log and fail because of Thermal
        l_errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
        errlCommit(l_errl, SBEIO_COMP_ID);
        goto ERROR_EXIT;
    }

    SBE_TRACF("OdySbeRetryHandler::run_hreset_flow: ThermalSensorPolling success "
              "l_odySensorPollingPeriod=0x%X l_odyDqsTrackingPeriod=0x%X HUID=0x%X",
               l_odySensorPollingPeriod, l_odyDqsTrackingPeriod, get_huid(iv_ocmb));

ERROR_EXIT:
    SBE_TRACF(EXIT_MRK"OdySbeRetryHandler::run_hreset_flow: HUID=0x%X ERRL=0x%X "
                      "ODY_RECOVERY_STATE=0x%X side=0x%X",
                      get_huid(iv_ocmb), ERRL_GETEID_SAFE(l_errl),
                      iv_ocmb->getAttr<ATTR_ODY_RECOVERY_STATE>(),
                      iv_ocmb->getAttr<ATTR_SPPE_BOOT_SIDE>());
    return l_errl;
}

/*******************************************************************************
 * @brief Update ATTR_SPPE_BOOT_SIDE to switch sides
 ******************************************************************************/
void OdySbeRetryHandler::side_switch()
{
    auto l_boot_side = iv_ocmb->getAttr<ATTR_SPPE_BOOT_SIDE>();

    SBE_TRACF(ENTER_MRK"OdySbeRetryHandler::side_switch HUID=0x%X "
                       "ODY_RECOVERY_STATE=0x%X "
                       "SPPE_BOOT_SIDE=0x%X",
                       get_huid(iv_ocmb),
                       iv_ocmb->getAttr<ATTR_ODY_RECOVERY_STATE>(),
                       l_boot_side);

    // flip sides
    if (l_boot_side == SPPE_BOOT_SIDE_SIDE0)
    {
        l_boot_side = SPPE_BOOT_SIDE_SIDE1;
    }
    else if (l_boot_side == SPPE_BOOT_SIDE_SIDE1)
    {
        l_boot_side = SPPE_BOOT_SIDE_SIDE0;
    }
    else
    {
        assert(false, "OdySbeRetryHandler::side_switch HUID=0x%X SPPE_BOOT_SIDE=%d"
                      "Unexpected value for ATTR_SPPE_BOOT_SIDE",
                      get_huid(iv_ocmb), l_boot_side);
    }

    iv_ocmb->setAttr<ATTR_SPPE_BOOT_SIDE>(l_boot_side);

    SBE_TRACF(EXIT_MRK"OdySbeRetryHandler::side_switch HUID=0x%X "
                      "ODY_RECOVERY_STATE=0x%X "
                      "SPPE_BOOT_SIDE=0x%X",
                       get_huid(iv_ocmb),
                       iv_ocmb->getAttr<ATTR_ODY_RECOVERY_STATE>(),
                       l_boot_side);
    return;
}

/*******************************************************************************
 * @brief Execute the Odyssey dump
 ******************************************************************************/
errlHndl_t OdySbeRetryHandler::dump(const uint32_t i_eid)
{
    errlHndl_t l_errl      = nullptr;
    bool       l_skip_dump = false;

    SBE_TRACF(ENTER_MRK"OdySbeRetryHandler::dump HUID=0x%X", get_huid(iv_ocmb));

    // if SKIP_DUMP flag is set, then l_skip is set to true, and we exit the fcn
    CI_INJECT_HRESET_SKIP_DUMP(CxxTest::g_cxxTestInject,
                               iv_ocmb,
                               CxxTest::SBEIO_INJECT_HRESET_SKIP_DUMP,
                               "OdySbeRetryHandler::dump: INJECT_SKIP_DUMP",
                               l_skip_dump);

    if (!l_skip_dump)
    {
#if defined(CONFIG_PLDM) && !defined(__HOSTBOOT_RUNTIME)
        l_errl = PLDM::dumpSbe(iv_ocmb, i_eid);
#endif
    }

    iv_ocmb->setAttr<ATTR_ODY_RECOVERY_STATE>(ODY_RECOVERY_STATUS_DEAD);
    SBE_TRACF("OdySbeRetryHandler::dump: ODY_RECOVERY_STATUS_DEAD "
              "HUID=0x%X", get_huid(iv_ocmb));

    SBE_TRACF(EXIT_MRK"OdySbeRetryHandler::dump HUID=0x%X", get_huid(iv_ocmb));
    return l_errl;
}

OdySbeRetryHandler::~OdySbeRetryHandler()
{
}

}
