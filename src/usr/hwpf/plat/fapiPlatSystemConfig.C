/**
 *  @file fapiPlatSystemConfig.C
 *
 *  @brief Implements the fapiSystemConfig.H functions.
 *
 *  Note that platform code must provide the implementation.
 */

#include <fapiSystemConfig.H>
#include <fapiPlatTrace.H>

extern "C"
{

//******************************************************************************
// GetFunctionalChiplets function
//******************************************************************************
fapi::ReturnCode GetFunctionalChiplets(const fapi::Target& i_target,
                                       const fapi::TargetType i_chipletType,
                                       std::vector<fapi::Target> & o_chiplets)
{
	FAPI_DBG(ENTER_MRK "GetFunctionalChiplets");

	FAPI_DBG(EXIT_MRK "GetFunctionalChiplets");

	return fapi::FAPI_RC_PLAT_NOT_IMPLEMENTED;
}

//******************************************************************************
// GetExistingChiplets function
//******************************************************************************
fapi::ReturnCode GetExistingChiplets(const fapi::Target& i_target,
                                     const fapi::TargetType i_chipletType,
                                     std::vector<fapi::Target> & o_chiplets)
{
	FAPI_DBG(ENTER_MRK "GetExistingChiplets");

	FAPI_DBG(EXIT_MRK "GetExistingChiplets");

	return fapi::FAPI_RC_PLAT_NOT_IMPLEMENTED;

}

//******************************************************************************
// GetFunctionalDimms function
//******************************************************************************
fapi::ReturnCode GetFunctionalDimms(const fapi::Target& i_target,
                                    std::vector<fapi::Target> & o_dimms)
{
	FAPI_DBG(ENTER_MRK "GetFunctionalDimms");

	FAPI_DBG(EXIT_MRK "GetFunctionalDimms");

	return fapi::FAPI_RC_PLAT_NOT_IMPLEMENTED;

}

//******************************************************************************
// GetExistingDimms function
//******************************************************************************
fapi::ReturnCode GetExistingDimms(const fapi::Target& i_target,
                                  std::vector<fapi::Target> & o_dimms)
{
	FAPI_DBG(ENTER_MRK "GetExistingDimms");

	FAPI_DBG(EXIT_MRK "GetExistingDimms");

	return fapi::FAPI_RC_PLAT_NOT_IMPLEMENTED;

}

} // extern "C"
