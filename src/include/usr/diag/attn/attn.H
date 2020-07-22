/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/diag/attn/attn.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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
#ifndef __ATTN_ATTN_H
#define __ATTN_ATTN_H

/**
 * @file attn.H
 *
 * @brief HBATTN declarations.
 */

#include <errl/errlentry.H>
#include <targeting/common/targetservice.H>

// Custom compile configs

namespace ATTN
{

/**
 * @brief startService Start the HB attention handler service.
 *
 * Registers with Interrupt Service for callback for attention
 *          or host type interrupts.
 *
 * @retval[0] No error occurred.
 * @retval[1] Unexpected error occurred.
 */
errlHndl_t startService();

/**
 * @brief stopService Stop the HB attention handler service.
 *
 * Stop background threads and unregister from Interrupt Service
 * Attention or host type interrupt messages.  Waits for completion of
 * any in-progress attention analysis.
 *
 * @post All resources reclaimed, no outstanding attentions.
 *
 * @retval[0] No error occurred.
 * @retval[1] Unexpected error occurred.
 */
errlHndl_t stopService();

/**
 * @brief checkForIplAttentions
 *
 * Check each proc target for any attentions
 * and invoke PRD for analysis.  Will loop indefinitely
 * until all chips stop reporting attentions.
 *
 * @retval[0] No errors.
 * @retval[!0] Unexpected error occurred.
 */
errlHndl_t checkForIplAttentions();

/**
 * @brief setTrueMask_otherProcs
 *
 * This will init the trueMASK (cfam reg) on processors
 * other than the primary proc.  It should be called
 * during IPL when the secondary procs are ready to
 * become part of the system.
 *
 * NOTE: Does nothing on FSP systems.
 *
 * @retval  none
 */
void  setTrueMask_otherProcs( const TARGETING::TargetHandleList &i_allProcs );

}

#endif
