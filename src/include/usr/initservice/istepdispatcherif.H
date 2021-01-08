/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/initservice/istepdispatcherif.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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
#ifndef __INITSERVICE_ISTEPDISPATCHERIF_H
#define __INITSERVICE_ISTEPDISPATCHERIF_H

#include <vector>

namespace INITSERVICE
{


/**
 * @brief This function will hold off callers until a sync point message is
 *      received from an outside source.
 *
 * @return NONE.
 */
void waitForSyncPoint ( void );


/**
 * @brief This function is to be used by external code to initiate a sync
 *      point reached message to be sent to the Fsp.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the error
 *      log.
 */
errlHndl_t sendSyncPoint ( void );


/**
* @brief This function is used by external code to send a progress message
*      from Hostboot to Fsp.
*
* param[in] i_needsLock flag to acquire mutex or not
*
*/
void sendProgressCode(bool i_needsLock = true);


/**
 * @brief This function is to be used by external code to initiate a Istep
 *      complete message to be sent to the Fsp.
 *
 *      NOTE: This function should ONLY be called by the start_payload istep.
 *      Any other use is unsupported and could cause unknown side effects.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the error
 *      log.
 */
errlHndl_t sendIstepCompleteMsg ( void );


/**
 * @brief This function is to be used by external code to tell ATTN code on
 *        the FSP to start monitoring these chips
 *
 * param[in] i_huid_list - HUID list of chips for ATTN to watch
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the error
 *      log.
 */
errlHndl_t sendAttnMonitorChipIdMsg(
                    const std::vector<TARGETING::ATTR_HUID_type> & i_huid_list);


/**
 * @brief This function is to be used by external code to check whether
 *      a shutdown has been requested
 *
 * @return bool - true if shutdown requested, false if not
 */
bool isShutdownRequested ( void );


/**
 *  @brief This function is to be used by external code to
 *    initiate a system reboot. The function will figure out which reboot
 *    mechanism it needs to use to reboot the system (IPMI message, PLDM
 *    message, or shutdown() call)
 *
 * @param[in] i_reason the reason for reboot (printed to the console)
 */
void requestReboot(const char* i_reason = nullptr);

#ifdef CONFIG_BMC_IPMI
/**
 *  @brief This function is to be used by external code to
 *    initiate a system power off via IPMI commands
 */
void requestPowerOff( void );

/**
 *  @brief This function is to be used by external code to
 *    initiate a soft system power off via IPMI commands
 */
void requestSoftPowerOff( void );
#endif

/**
 * @brief This function is to be used by external code to tell
 *      this instance of istepdispatcher whether it should
 *      accept istep messages or not
 *
 * @param[in] i_accept - true if istep messages are to be accepted, false if not
 *
 * @return Nothing
 */
void setAcceptIstepMessages ( bool i_accept );

/**
 * @brief This function will set a member class variable to state new gard
 * records have been committed on this boot attempt.
 *
 * Gard records being created are an indication of forward progress.  Therefore
 * if a gard record has been created we can issue a reboot that does not count
 * towards the reboot count limit.
 *
 * @return None.
 */
void setNewGardRecord ( void );

}

#endif
