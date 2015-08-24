/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/plat/fapiPlatUtil.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2015                        */
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
 *  @file fapiPlatUtil.C
 *
 *  @brief Implements the fapiUtil.H utility functions.
 *
 *  Note that platform code must provide the implementation.
 */

#include <assert.h>
#include <fapi.H>
#include <trace/interface.H>
#include <sys/time.h>
#include <errl/errlmanager.H>
#include <fapiPlatHwpInvoker.H>
#include <vfs/vfs.H>
#include <initservice/initsvcbreakpoint.H>
#include <errl/errlentry.H>
#include <initservice/initserviceif.H>
#include <util/align.H>
#include <fapiPlatUtil.H>

#ifdef __HOSTBOOT_RUNTIME
#include <runtime/interface.h>
#include <targeting/common/targetservice.H>
#include <runtime/rt_targeting.H>
#include <hwpf/hwpf_reasoncodes.H>
#include "handleSpecialWakeup.H"
#endif

//******************************************************************************
// Trace descriptors
//******************************************************************************
trace_desc_t* g_fapiTd;
trace_desc_t* g_fapiImpTd;
trace_desc_t* g_fapiScanTd;
trace_desc_t* g_fapiMfgTd;

//******************************************************************************
// Global TracInit objects. Construction will initialize the trace buffer
//******************************************************************************
TRAC_INIT(&g_fapiTd, FAPI_TRACE_NAME, 2*KILOBYTE);
TRAC_INIT(&g_fapiImpTd, FAPI_IMP_TRACE_NAME, 2*KILOBYTE);
TRAC_INIT(&g_fapiScanTd, FAPI_SCAN_TRACE_NAME, 4*KILOBYTE);
TRAC_INIT(&g_fapiMfgTd, FAPI_MFG_TRACE_NAME, 4*KILOBYTE);

extern "C"
{

//******************************************************************************
// fapiAssert
//******************************************************************************
void fapiAssert(bool i_expression)
{
    assert(i_expression);
}

//******************************************************************************
// fapiDelay
//
// At the present time, VBU runs hostboot without a Simics
// front end. If a HW procedure wants to delay, we just make the
// syscall nanosleep().  In the syscall, the kernel will continue to consume
// clock cycles as it looks for a runnable task. When the sleep time expires,
// the calling task will resume running.
//
// In the future there could be a Simics front end to hostboot VBU. Then
// a possible implementation will be to use the Simics magic instruction
// to trigger a Simics hap. The Simics hap handler can call the simdispatcher
// client/server API to tell the Awan to advance some number of cycles.
//
// Monte  4 Aug 2011
//******************************************************************************

fapi::ReturnCode fapiDelay(uint64_t i_nanoSeconds, uint64_t i_simCycles)
{
    FAPI_DBG( INFO_MRK "delay %lld nanosec", i_nanoSeconds );
    nanosleep( 0, i_nanoSeconds );
    return fapi::FAPI_RC_SUCCESS;
}

//******************************************************************************
// fapiLogError
//******************************************************************************
void fapiLogError(fapi::ReturnCode & io_rc,
                  fapi::fapiErrlSeverity_t i_sev,
                  bool i_unitTestError)
{
    // ENUM CONVERSION FAPI to PLATFORM

    errlHndl_t l_pError = NULL;

    FAPI_INF("fapiLogError: logging error");

    // Convert a FAPI severity to a ERRORLOG severity
    ERRORLOG::errlSeverity_t l_sev = ERRORLOG::ERRL_SEV_UNRECOVERABLE;
    switch (i_sev)
    {
        case fapi::FAPI_ERRL_SEV_RECOVERED:
            l_sev = ERRORLOG::ERRL_SEV_RECOVERED;
            break;
        case fapi::FAPI_ERRL_SEV_PREDICTIVE:
            l_sev = ERRORLOG::ERRL_SEV_PREDICTIVE;
            break;
        case fapi::FAPI_ERRL_SEV_UNRECOVERABLE:
            // l_sev set above
            break;
        default:
            FAPI_ERR("severity (i_sev) of %d is unknown",i_sev);
    }

    // Convert the return code to an error log.
    // This will set the return code to FAPI_RC_SUCCESS and clear any PLAT Data,
    // HWP FFDC data, and Error Target associated with it.
    l_pError = fapiRcToErrl(io_rc, l_sev);

    // Commit the error log. This will delete the error log and set the handle
    // to NULL.
    if (i_unitTestError)
    {
        errlCommit(l_pError, CXXTEST_COMP_ID);
    }
    else
    {
        errlCommit(l_pError, HWPF_COMP_ID);
    }
}

//******************************************************************************
// platIsScanTraceEnabled
//******************************************************************************
bool platIsScanTraceEnabled()
{
  // SCAN trace can be dynamically turned on/off, always return true here
  return 1;
}

//******************************************************************************
// platSetScanTrace
// Implementation to be added if needed
//******************************************************************************
//void platSetScanTrace(bool i_enable)
//{
//
//}

//******************************************************************************
// fapiLoadInitFile
//******************************************************************************
fapi::ReturnCode fapiLoadInitFile(const fapi::Target & i_Target,
    const char * i_file, const char *& o_addr, size_t & o_size)
{
#ifndef __HOSTBOOT_RUNTIME
    fapi::ReturnCode l_rc = fapi::FAPI_RC_SUCCESS;
    errlHndl_t l_pError = NULL;
    o_size = 0;
    o_addr = NULL;

    FAPI_INF("fapiLoadInitFile: %s", i_file);

    l_pError = VFS::module_load(i_file);
    if(l_pError)
    {
        // Add the error log pointer as data to the ReturnCode
        FAPI_ERR("fapiLoadInitFile: module_load failed");
        l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
    }
    else
    {
        l_pError = VFS::module_address(i_file, o_addr, o_size);
        if(l_pError)
        {
            // Add the error log pointer as data to the ReturnCode
            FAPI_ERR("fapiLoadInitFile: module_address failed");
            l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
        }
        else
        {
            FAPI_DBG("fapiLoadInitFile: data module addr = %p, size = %ld",
                      o_addr, o_size);
            FAPI_DBG("fapiLoadInitFile: *addr = 0x%llX",
                      *(reinterpret_cast<const uint64_t*>(o_addr)));
        }
    }
#else
    fapi::ReturnCode l_rc = fapi::FAPI_RC_PLAT_NOT_SUPPORTED_AT_RUNTIME;
#endif

    return l_rc;
}

//******************************************************************************
// fapiUnloadInitFile
//******************************************************************************
fapi::ReturnCode fapiUnloadInitFile(const char * i_file, const char *& io_addr,
    size_t & io_size)
{
#ifndef __HOSTBOOT_RUNTIME
    fapi::ReturnCode l_rc = fapi::FAPI_RC_SUCCESS;
    errlHndl_t l_pError = NULL;

    FAPI_INF("fapiUnloadInitFile: %s", i_file);

    l_pError = VFS::module_unload(i_file);
    if(l_pError)
    {
        // Add the error log pointer as data to the ReturnCode
        FAPI_ERR("fapiUnloadInitFile: module_unload failed %s", i_file);
        l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
    }
    else
    {
        io_addr = NULL;
        io_size = 0;
    }
#else
    fapi::ReturnCode l_rc = fapi::FAPI_RC_PLAT_NOT_SUPPORTED_AT_RUNTIME;
#endif

    return l_rc;
}

//******************************************************************************
// fapiBreakPoint
//******************************************************************************
void fapiBreakPoint( uint32_t i_info)
{
#ifndef __HOSTBOOT_RUNTIME
    INITSERVICE::iStepBreakPoint( i_info );
#endif
}

//******************************************************************************
// fapiSpecialWakeup
//******************************************************************************
fapi::ReturnCode fapiSpecialWakeup(const fapi::Target & i_target,
                                   const bool i_enable)
{
    fapi::ReturnCode fapi_rc = fapi::FAPI_RC_SUCCESS;
    FAPI_INF("fapiSpecialWakeup");
#ifdef __HOSTBOOT_RUNTIME
    if(!INITSERVICE::spBaseServicesEnabled())
    {
        TARGETING::Target* l_EXtarget =
            reinterpret_cast<TARGETING::Target*>(i_target.get());

        errlHndl_t err_SW = handleSpecialWakeup(l_EXtarget,i_enable);
        if(err_SW)
        {
            fapi_rc.setPlatError(reinterpret_cast<void *>(err_SW));
        }

    }
    else if(g_hostInterfaces && g_hostInterfaces->wakeup)
    {
        TARGETING::Target* target =
            reinterpret_cast<TARGETING::Target*>(i_target.get());

        RT_TARG::rtChipId_t core_id = 0;
        errlHndl_t err = RT_TARG::getRtTarget(target, core_id);
        if(err)
        {
            fapi_rc.setPlatError(reinterpret_cast<void *>(err));
        }
        else
        {
            uint32_t mode = 0;   //Force awake
            if(!i_enable)
            {
                mode = 1;       // clear force
            }
            int rc = g_hostInterfaces->wakeup(core_id, mode);

            if(rc)
            {
                FAPI_ERR("CPU core wakeup call to hypervisor returned rc = %d",
                         rc);
                /*@
                 * @errortype
                 * @moduleid     fapi::MOD_PLAT_SPECIAL_WAKEUP
                 * @reasoncode   fapi::RC_RT_WAKEUP_FAILED
                 * @userdata1    Hypervisor return code
                 * @userdata2    Chiplet HUID
                 * @devdesc      Error code from hypervisor wakeup call
                 */
                const bool hbSwError = true;
                err = new ERRORLOG::ErrlEntry(
                                              ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                              fapi::MOD_PLAT_SPECIAL_WAKEUP,
                                              fapi::RC_RT_WAKEUP_FAILED,
                                              rc,
                                              TARGETING::get_huid(target),
                                              hbSwError);

                fapi_rc.setPlatError(reinterpret_cast<void*>(err));
            }
        }
    }
#endif
    // On Hostboot, processor cores cannot sleep so return success to the
    // fapiSpecialWakeup enable/disable calls
    return fapi_rc;
}

}

//******************************************************************************
// fapiPlatMalloc
//******************************************************************************
void* fapiPlatMalloc(size_t s)
{
    if (s > PAGE_SIZE)
    {
        s = PAGE_SIZE * ALIGN_POW2(ALIGN_PAGE(s) / PAGE_SIZE);
    }
    return malloc(s);
}
