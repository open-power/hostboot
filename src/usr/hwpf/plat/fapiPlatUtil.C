/**
 *  @file platUtil.C
 *
 *  @brief Implements the fapiUtil.H utility functions.
 *
 *  Note that platform code must provide the implementation.
 */

#include <assert.h>
#include <trace/interface.H>
#include <fapiPlatTrace.H>

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

}
