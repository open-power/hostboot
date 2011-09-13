//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/plat/fapiPlatHwAccess.C $
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
 *  @file fapiPlatHwAccess.C
 *
 *  @brief Implements the fapiHwAccess.H functions.
 *
 *  Note that platform code must provide the implementation.
 */

#include <fapiHwAccess.H>
#include <fapiPlatTrace.H>
#include <fapiPlatHwAccess.H>
#include <errl/errlentry.H>
#include <targeting/targetservice.H>
#include <devicefw/userif.H>

extern "C"
{

//******************************************************************************
// platGetScom function, the platform implementation
//******************************************************************************
fapi::ReturnCode platGetScom(const fapi::Target& i_target,
                             const uint64_t i_address,
                             ecmdDataBufferBase & o_data)
{
    FAPI_DBG(ENTER_MRK "platGetScom");

    fapi::ReturnCode l_rc;
    errlHndl_t l_err = NULL;

    // Extract the component pointer
    TARGETING::Target* l_target = reinterpret_cast<TARGETING::Target*>(i_target.get());

    // Perform SCOM read
    uint64_t l_data = 0;
    size_t l_size = sizeof(uint64_t);
    l_err = deviceRead(l_target,
                       &l_data,
                       l_size,
                       DEVICE_SCOM_ADDRESS(i_address));
    if (l_err)
    {
        // Add the error log pointer as data to the ReturnCode
        FAPI_ERR("GetScom: HostBoot GetScom returns error");
        l_rc = fapi::FAPI_RC_PLAT_ERR_SEE_DATA;
        l_rc.setPlatData(reinterpret_cast<void *> (l_err));
    }
    else
    {
        o_data.setDoubleWord(0, l_data);
    }

    FAPI_DBG(EXIT_MRK "platGetScom");
    return l_rc;
}

//******************************************************************************
// platPutScom function
//******************************************************************************
fapi::ReturnCode platPutScom(const fapi::Target& i_target,
                             const uint64_t i_address,
                             ecmdDataBufferBase & i_data)
{
    FAPI_DBG(ENTER_MRK "platPutScom");
    fapi::ReturnCode l_rc;
    errlHndl_t l_err = NULL;

    // Extract the component pointer
    TARGETING::Target* l_target = reinterpret_cast<TARGETING::Target*>(i_target.get());

    // Perform SCOM read
    uint64_t l_data = i_data.getDoubleWord(0);
    size_t l_size = sizeof(uint64_t);
    l_err = deviceWrite(l_target,
                        &l_data,
                        l_size,
                        DEVICE_SCOM_ADDRESS(i_address));
    if (l_err)
    {
        // Add the error log pointer as data to the ReturnCode
        FAPI_ERR("Putscom: HostBoot Putscom returns error");
        l_rc = fapi::FAPI_RC_PLAT_ERR_SEE_DATA;
        l_rc.setPlatData(reinterpret_cast<void *> (l_err));
    }

    FAPI_DBG(EXIT_MRK "platPutScom");
    return l_rc;
}

//@todo - Implement these functions later
#if 0
//******************************************************************************
// platPutScomUnderMask function
//******************************************************************************
fapi::ReturnCode platPutScomUnderMask(const fapi::Target& i_target,
                                      const uint64_t i_address,
                                      ecmdDataBufferBase & i_data,
                                      ecmdDataBufferBase & i_mask)
{
	FAPI_DBG(ENTER_MRK "platPutScomUnderMask");

	FAPI_DBG(EXIT_MRK "platPutScomUnderMask");
}

//******************************************************************************
// platGetCfamRegister function
//******************************************************************************
fapi::ReturnCode platGetCfamRegister(const fapi::Target& i_target,
                                     const uint32_t i_address,
                                     ecmdDataBufferBase & o_data)
{
	FAPI_DBG(ENTER_MRK "platGetCfamRegister");

	FAPI_DBG(EXIT_MRK "platGetCfamRegister");
}

//******************************************************************************
// platPutCfamRegister function
//******************************************************************************
fapi::ReturnCode platPutCfamRegister(const fapi::Target& i_target,
                                     const uint32_t i_address,
                                     ecmdDataBufferBase & i_data)
{
	FAPI_DBG(ENTER_MRK "platPutCfamRegister");

	FAPI_DBG(EXIT_MRK "platPutCfamRegister");
}

//******************************************************************************
// platModifyCfamRegister function
//******************************************************************************
fapi::ReturnCode platModifyCfamRegister(const fapi::Target& i_target,
                                        const uint32_t i_address,
                                        ecmdDataBufferBase & i_data,
                                        const fapi::ChipOpModifyMode i_modifyMode)
{
	FAPI_DBG(ENTER_MRK "platModifyCfamRegister");

	FAPI_DBG(EXIT_MRK "platModifyCfamRegister");
}
#endif

} // extern "C"
