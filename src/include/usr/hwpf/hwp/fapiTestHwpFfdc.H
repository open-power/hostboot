/**
 *  @file fapiTestHwpFfdc.H
 *
 *  @brief Defines a simple test Hardware Procedure that collects FFDC data 
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     08/08/2011  Created.
 *
 */

#ifndef FAPITESTHWPFFDC_H_
#define FAPITESTHWPFFDC_H_

#include <fapi.H>
#include <fapiFfdcHwpData.H>

// HWPs are defined as C functions because platforms may wish to package them
// in linux shared libraries which are DL-Opened
extern "C"
{

/**
 * @brief Simple FFDC HWP that collects TestFfdc1 data
 *
 * @param[in]  i_target Reference to target (unused by HWP)
 * @param[out] o_ffdc   Reference to TestFfdc1 that is filled in with FFDC
 *
 * @return ReturnCode
 */
fapi::ReturnCode hwpTestFfdc1(const fapi::Target & i_target,
                              fapi::TestFfdc1 & o_ffdc);

} // extern "C"

#endif // FAPITESTHWPFFDC_H_
