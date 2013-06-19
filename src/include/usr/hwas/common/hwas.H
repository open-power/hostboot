/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwas/common/hwas.H $                          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
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
#include <targeting/common/commontargeting.H>
#include <hwas/common/hwasError.H>

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
 *  and call into the hwas platform-specific functions:
 *      platReadIDEC() to get and set the ChipID and EC values.
 *      platReadPartialGood() to get and set the partial good vector.
 *
 * @param  none
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error
 *                          NULL if no errors;
 */
errlHndl_t discoverTargets();

/**
 * @brief   restrictEXunits   Internal HWAS function to restrict the EXs
 *
 *  This routine will walk through the procs in the list, and turn EX
 *  units to not functional if the number of units is larger than the max
 *  given. This is used for PR keyword and Field Core Override (FCO)
 *  processing.
 *
 * @param[in] i_procRestrict   vector of procRestrict entries
 * @param[in] i_present    boolean for 'present' HWAS value for restricted
 *                          EX units
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error
 *                          NULL if no errors;
 */

// structure used to store proc information for EX restrict processing
typedef struct {
    TARGETING::TargetHandle_t target;      // proc target
    uint32_t group;             // uniq id for this group - ie: FRUID, node
    uint32_t maxEXs;            // max EX units for this group
    uint8_t procs;              // number of procs in the group
} procRestrict_t;

errlHndl_t restrictEXunits(
    std::vector <procRestrict_t> &i_procRestrict,
    bool i_present);

};   // end namespace

#endif
