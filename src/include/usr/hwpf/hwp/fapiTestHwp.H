/**
 *  @file fapiTestHwp.H
 *
 *  @brief Defines a simple test Hardware Procedure
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     04/21/2011  Created.
 *                          mjjones     06/28/2011  Updated comment
 *                          mjjones     08/11/2011  Removed Clock HWP
 *
 */

#ifndef FAPITESTHWPROC_H_
#define FAPITESTHWPROC_H_

#include <fapi.H>

// HWPs are defined as C functions because platforms may wish to package them
// in linux shared libraries which are DL-Opened
extern "C"
{

/**
 * @brief A simple HWP. Can easily be modified by HW dev team for test
 *
 * @param[in] i_chip Reference to target chip
 *
 * @return ReturnCode
 */
fapi::ReturnCode hwpInitialTest(const fapi::Target & i_chip);



} // extern "C"

#endif // FAPITESTHWPROC_H_
