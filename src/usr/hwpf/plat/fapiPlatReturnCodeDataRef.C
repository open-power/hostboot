/**
 *  @file platReturnCodeDataRef.C
 *
 *  @brief Implements the platform part of the ReturnCodeDataRef class.
 *
 *  Note that platform code must provide the implementation. FAPI has provided
 *  an example for platforms that do not attach ReturnCodeData to a ReturnCode.
 */

#include <fapiReturnCodeDataRef.H>
#include <fapiPlatTrace.H>
#include <errl/errlentry.H>

namespace fapi
{

//******************************************************************************
// deleteData function
//******************************************************************************
void ReturnCodeDataRef::deleteData()
{
	FAPI_DBG("ReturnCodeDataRef::deleteData");

    // FSP platform uses iv_pData to point at a FipS error log.
    delete (reinterpret_cast<errlHndl_t>(const_cast<void *>(iv_pData)));
}

}
