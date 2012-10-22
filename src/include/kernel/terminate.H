/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/terminate.H $                              */
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
/** @file terminate.H
 *  @brief Defines kernel information about the TI data area
 */
#ifndef __KERNEL_TERMINATE_H
#define __KERNEL_TERMINATE_H

#include <kernel/types.h>

/** @fn terminateAndUpdateSaveArea
 *  Update TI data area with src or PLID and force a TI
 *  @param[in] i_type :   indicates if an src or plid is stored
 *  @param[in] i_source:  indicates what type of fail forced the TI
 *  @param[in] *i_src:    SRC to be stored
 *  @param[in] i_plid:    plid to be stored
 *  @param[out] NONE:
 */
void terminateAndUpdateSaveArea(uint16_t i_type,
                                    uint16_t i_source,
                                    uint64_t *i_src,
                                    uint64_t plid = 0);
  

#endif
