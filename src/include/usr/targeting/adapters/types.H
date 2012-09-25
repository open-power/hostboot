/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/adapters/types.H $                  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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

#ifndef __TARGETING_TYPES_H
#define __TARGETING_TYPES_H

/**
 *  @file targeting/adapters/types.H
 *
 *  @brief Platform specific type translation support
 */

//******************************************************************************
// Includes
//******************************************************************************

#include <hbotcompid.H>

#ifndef PARSER

#include <sys/sync.h>
#include <util/singleton.H>
#include <vmmconst.h>

/**
 *  @brief Adapt common singleton declaration to specific platform
 *
 *  @param[in] __T__
 *      Type of singleton, fully namespaced
 *
 *  @param[in] __NAME__
 *      Symbol name for singleton
 */
#define TARG_DECLARE_SINGLETON(__T__,__NAME__) \
    typedef Singleton<__T__> __NAME__;

/**
 *  @brief Adapt common singleton "getter" to the specific platform
 *
 *  @param[in] __TYPE__
 *      Typedef for singleton, as created above
 *
 *  @return Singleton reference for the given singleton
 */
#define TARG_GET_SINGLETON(__TYPE__) \
    __TYPE__::instance()

#endif // PARSER
#endif // __TARGETING_TYPES_H
