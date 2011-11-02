//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/plat/fapiPlatUtil.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
/**
 *  @file platUtil.C
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


//******************************************************************************
// Trace descriptors
//******************************************************************************
trace_desc_t* g_fapiInfTd;
trace_desc_t* g_fapiImpTd;
trace_desc_t* g_fapiErrTd;
trace_desc_t* g_fapiDbgTd;
trace_desc_t* g_fapiScanTd;

//******************************************************************************
// Global TracInit objects. Construction will initialize the trace buffer
//******************************************************************************
TRAC_INIT(&g_fapiInfTd, FAPI_INF_TRACE_NAME, 4096);
TRAC_INIT(&g_fapiImpTd, FAPI_IMP_TRACE_NAME, 4096);
TRAC_INIT(&g_fapiErrTd, FAPI_ERR_TRACE_NAME, 4096);
TRAC_INIT(&g_fapiDbgTd, FAPI_DBG_TRACE_NAME, 4096);
TRAC_INIT(&g_fapiScanTd, FAPI_SCAN_TRACE_NAME, 4096);

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
void fapiLogError(fapi::ReturnCode & io_rc)
{
    errlHndl_t l_pError = NULL;

    FAPI_ERR("fapiLogError: logging error");

    // Convert the return code to an error log.
    // This will set the return code to FAPI_RC_SUCCESS and clear any PLAT Data,
    // HWP FFDC data, and Error Target associated with it.
    l_pError = fapiRcToErrl(io_rc);

    // Commit the error log. This will delete the error log and set the handle
    // to NULL.
    errlCommit(l_pError,HWPF_COMP_ID);
}

//****************************************************************************
// platform-level implementation 

bool platIsScanTraceEnabled()
{
  // TODO: Get the answer from g_fapiScanTd conditional trace buffer. Camvan
  // has not pushed the code yet.
  return 1;
}

//****************************************************************************
// platform-level implementation 

void platSetScanTrace(bool i_enable)
{
  // TODO: enable or disable scan trace via the SCAN trace buffer.  Camvan
  // has not pushed the code yet.
  return;
}

//******************************************************************************
// fapiLoadInitFile
//******************************************************************************
fapi::ReturnCode fapiLoadInitFile(const char * i_file, const char *& o_addr, 
    size_t & o_size)
{
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
        l_rc = fapi::FAPI_RC_PLAT_ERR_SEE_DATA;
        l_rc.setPlatData(reinterpret_cast<void *> (l_pError));
    }
    else
    {
        l_pError = VFS::module_address(i_file, o_addr, o_size);
        if(l_pError)
        {
            // Add the error log pointer as data to the ReturnCode
            FAPI_ERR("fapiLoadInitFile: module_address failed");
            l_rc = fapi::FAPI_RC_PLAT_ERR_SEE_DATA;
            l_rc.setPlatData(reinterpret_cast<void *> (l_pError));
        }
        else
        {
            FAPI_DBG("fapiLoadInitFile: data module addr = %p, size = %ld",
                      o_addr, o_size);
            FAPI_DBG("fapiLoadInitFile: *addr = 0x%llX",
                      *(reinterpret_cast<const uint64_t*>(o_addr)));
        }
    }

    return l_rc;
}

//******************************************************************************
// fapiUnloadInitFile
//******************************************************************************
fapi::ReturnCode fapiUnloadInitFile(const char * i_file, const char *& io_addr, 
    size_t & io_size)
{
    fapi::ReturnCode l_rc = fapi::FAPI_RC_SUCCESS;
    errlHndl_t l_pError = NULL;

    FAPI_INF("fapiUnloadInitFile: %s", i_file);

    l_pError = VFS::module_unload(i_file);
    if(l_pError)
    {
        // Add the error log pointer as data to the ReturnCode
        FAPI_ERR("fapiUnloadInitFile: module_unload failed %s", i_file);
        l_rc = fapi::FAPI_RC_PLAT_ERR_SEE_DATA;
        l_rc.setPlatData(reinterpret_cast<void *> (l_pError));
    }
    else
    {
        io_addr = NULL;
        io_size = 0;
    }

    return l_rc;
}

}
