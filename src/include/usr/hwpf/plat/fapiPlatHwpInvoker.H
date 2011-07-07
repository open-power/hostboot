/**
 *  @file fapiPlatHwpInvoker.H
 *
 *  @brief Defines the platform specific HW Procedure invoker functions.
 *
 *  Note that each platform needs to provide an invoker function for each HW
 *  procedure. Prototypes cannot be provided because each platform will have
 *  functions that take platform specific targets and return platform specific
 *  return codes.
 */

#ifndef FAPIPLATHWPINVOKER_H_
#define FAPIPLATHWPINVOKER_H_

#include <targeting/targetservice.H>
#include <errl/errlentry.H>

namespace fapi
{

/**
 * @brief Invokes hwpIsP7EM0ChipletClockOn procedure
 *
 * @param[in]  i_target   Pointer to Chip
 * @param[out] o_clocksOn True if EM0 clocks are on, else false
 */
errlHndl_t invokeHwpIsP7EM0ChipletClockOn(TARGETING::Target* i_target,
                                          bool & o_clocksOn);

/**
 * @brief Invokes hwpInitialTest procedure
 *
 * @param[in]  i_target   Pointer to Chip
 */
errlHndl_t invokeHwpInitialTest(TARGETING::Target* i_target);


}

#endif // FAPIPLATHWPINVOKER_H_
