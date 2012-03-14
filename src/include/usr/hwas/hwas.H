//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/hwas/hwas.H $
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
#ifndef  __HWAS_HWAS_H
#define __HWAS_HWAS_H
/**
 *  @file hwas.H
 *
 *  HardWare Availability Service prototypes.
 *  In trying to keep with C++ tradition, doxygen documentation for functions
 *  are here in the .H file.
 *
 *  All of the following routines are "named isteps" - they are invoked as
 *  tasks by the @ref IStepDispatcher.
 *
 */


/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>
#include <errl/errlentry.H>

namespace HWAS
{

/**
 * @brief   initHardware   Common HWAS function to setup the hardware
 *
 *  It will call into the hwas platform-specific platInitHardware()
 *  function to init the FSI hardware.
 *
 * @param  none
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error
 *                          NULL if no errors;
 */
errlHndl_t initHardware();

/**
 * @brief   discoverTagets   Common HWAS function to build targeting
 *
 *  This routine will walk through all the targets and initialize HWAS STATE
 *  to a known default value (powered off, etc.)
 *
 *  Then call into the hwas platform-specific platPresenceDetect() function
 *  to read the hardware information, and apply it to the target states,
 *  and call into the hwas platform-specifiction platReadIDEC() function
 *  to get and set the ChipID and EC values.
 *
 * @param  none
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error
 *                          NULL if no errors;
 */
errlHndl_t discoverTargets();

};   // end namespace

#endif
