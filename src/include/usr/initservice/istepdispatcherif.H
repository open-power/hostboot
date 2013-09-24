/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/initservice/istepdispatcherif.H $             */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
#ifndef __INITSERVICE_ISTEPDISPATCHERIF_H
#define __INITSERVICE_ISTEPDISPATCHERIF_H

namespace INITSERVICE
{


/**
 * @brief This function will hold off callers until a sync point message is
 *      recieved from an outside source.
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

}

#endif
