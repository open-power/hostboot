/**
 *  @file fapiTestHwpAttr.H
 *
 *  @brief Defines a test Hardware Procedure that exercises the test attributes
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     06/30/2011  Created.
 */

#ifndef FAPITESTHWPATTR_H_
#define FAPITESTHWPATTR_H_

#include <fapi.H>

// HWPs are defined as C functions because platforms may wish to package them
// in linux shared libraries which are DL-Opened
extern "C"
{

/**
 * @brief HWP that exercises attributes
 *
 * @return ReturnCode
 */
fapi::ReturnCode hwpTestAttributes();

} // extern "C"

#endif // FAPITESTHWPATTR_H_
