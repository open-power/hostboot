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
 * @brief Finds if a P7 EM0 chiplet clock is on
 *
 * @param[in]  i_chip            Target chip
 * @param[out] o_clocksOn        True if clocks are on, else false
 *
 * @return ReturnCode
 */
fapi::ReturnCode hwpIsP7EM0ChipletClockOn(const fapi::Target & i_chip,
                                          bool & o_clocksOn);

} // extern "C"

#endif // FAPITESTHWPROC_H_
