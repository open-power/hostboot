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


//******************************************************************************
// Trace descriptors
//******************************************************************************
trace_desc_t* g_fapiInfTd;
trace_desc_t* g_fapiImpTd;
trace_desc_t* g_fapiErrTd;
trace_desc_t* g_fapiDbgTd;

//******************************************************************************
// Global TracInit objects. Construction will initialize the trace buffer
//******************************************************************************
TRAC_INIT(&g_fapiInfTd, FAPI_INF_TRACE_NAME, 4096);
TRAC_INIT(&g_fapiImpTd, FAPI_IMP_TRACE_NAME, 4096);
TRAC_INIT(&g_fapiErrTd, FAPI_ERR_TRACE_NAME, 4096);
TRAC_INIT(&g_fapiDbgTd, FAPI_DBG_TRACE_NAME, 4096);

namespace fapi
{

//******************************************************************************
// fapiAssert
//******************************************************************************
void fapiAssert(bool i_expression)
{
    assert(i_expression);
}

//******************************************************************************
// delay
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

fapi::ReturnCode delay( uint64_t i_nanoSeconds, uint64_t i_simCycles )
{
    FAPI_DBG( INFO_MRK "delay %lld nanosec", i_nanoSeconds );
    nanosleep( 0, i_nanoSeconds );
    return fapi::FAPI_RC_SUCCESS;
}





}
