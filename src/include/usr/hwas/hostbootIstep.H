/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwas/hostbootIstep.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/**
 *  @file hostbootIstep.H
 *
 *  @brief Defines hostboot functions that get called by the istep dispatcher
 *         and call into the HWAS common interface
 */

#ifndef HOSTBOOTISTEP_H_
#define HOSTBOOTISTEP_H_

namespace HWAS
{
/**
 * @brief   host_stub empty function  returning success
 *
 *  stub function to be called for un-implemented host steps
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any error logs to istep
 */
void* host_stub( void *io_pArgs );



// hostboot only functions that are called by the istep dispatcher
//  and then call the HWAS common functions

/**
 * @brief   host_init_fsi   Setup the FSI links to slave chips
 *
 *  Call into the hwas platform-specific initHardware() function
 *  to init the FSI hardware.
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any error logs to istep
 */
void* host_init_fsi( void *io_pArgs );

/**
 * @brief   host_set_ipl_parms  Build ipl parameters
 *
 *  TBD
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any error logs to istep
 */
void* host_set_ipl_parms( void *io_pArgs );

/**
 * @brief   host_discover_targets   Builds targeting
 *
 *  This routine will walk through all the targets and initialize HWAS STATE
 *  to a known default value.
 *
 *  Currently everything is initialized to powered off, etc.
 *
 *  Call into the hwas platform-specific presenceDetect() function to
 *  read the hardware information, and apply it to the target states.
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any error logs to istep
 */
void* host_discover_targets( void *io_pArgs );

/**
 * @brief   host_gard   Do Gard
 *
 * Collect GARD information and apply it to the target states.
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any error logs to istep
 */
void* host_gard( void *io_pArgs );

/**
 *  @brief p9_revert_sbe_mcs_setup
 *
 *  Clean up MCS Extent regs
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return any error logs to istep
 */
void* call_p9_revert_sbe_mcs_setup(void *io_pArgs);

/**
 * @brief   host_cancontinue_clear  Clear deconfigured status
 *
 *  TBD
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any error logs to istep
 */
void* host_cancontinue_clear( void *io_pArgs );

/**
 * @brief   host_prd_hwreconfig  Hook for PRD to handle reconfigure
 *
 *  TBD
 *
 *  param[in,out] io_pArgs  -   (normally) a pointer to a TaskArgs struct,
 *                              or NULL.
 *  return  any error logs to istep
 */
void* host_prd_hwreconfig( void *io_pArgs );

} // namespace HWAS
#endif // HOSTBOOTISTEP_H_
