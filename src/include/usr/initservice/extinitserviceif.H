//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/initservice/extinitserviceif.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
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
#ifndef __INITSERVICE_EXTINITSERVICEIF_H
#define __INITSERVICE_EXTINITSERVICEIF_H

namespace INITSERVICE
{

/**
 * @brief This function will execute the Cxx Unit tests for Hostboot.  It is
 *      to be done here, instead of in Initservice, because when this istep
 *      completes the Payload will be started.
 *
 * @return errlHndl_t - NULL if successfule, otherwise a pointer to the error
 *      log.
 */
errlHndl_t executeUnitTests ( void );

}

#endif
