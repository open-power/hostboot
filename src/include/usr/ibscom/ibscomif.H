/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/ibscom/ibscomif.H $                           */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
#ifndef __IBSCOM_IBSCOMIF_H
#define __IBSCOM_IBSCOMIF_H

#include <stdint.h>
#include <builtins.h>
#include <errl/errlentry.H>

namespace IBSCOM
{

#define IBSCOM_DISABLE true
#define IBSCOM_ENABLE false

/**
 * @brief Enable or disable Inband SCOMs on all capable chips
 *
 * @param i_disable  true: disable inband scoms
 */
void enableInbandScoms( bool i_disable = IBSCOM_ENABLE );

}

#endif
