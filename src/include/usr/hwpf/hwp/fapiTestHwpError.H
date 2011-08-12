/**
 *  @file fapiTestHwpError.H
 *
 *  @brief Defines a simple test Hardware Procedure that returns an error
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     08/08/2011  Created.
 *
 */

#ifndef FAPITESTHWPERROR_H_
#define FAPITESTHWPERROR_H_

#include <fapi.H>

// HWPs are defined as C functions because platforms may wish to package them
// in linux shared libraries which are DL-Opened
extern "C"
{

/**
 * @brief Simple HWP that returns an error (RC_TEST_ERROR_A)
 *
 * @param[in] i_target Reference to target (unused by HWP)
 *
 * @return ReturnCode
 */
fapi::ReturnCode hwpTestError(const fapi::Target & i_target);

} // extern "C"

#endif // FAPITESTHWPERROR_H_
