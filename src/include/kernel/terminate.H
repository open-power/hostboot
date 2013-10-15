/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/terminate.H $                              */
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
/** @file terminate.H
 *  @brief Defines kernel information about the TI data area
 */
#ifndef __KERNEL_TERMINATE_H
#define __KERNEL_TERMINATE_H

#include <kernel/types.h>


/** @fn terminateExecuteTI
 *  @brief Sequence to execute a TI attn
 */
void terminateExecuteTI();

/** @fn termWritePlid
 *  Update TI data area with a PLID.
 *  @param[in] i_source:  indicates what type of fail forced the TI
 *  @param[in] i_plid:    plid to be stored
 *  @param[out] NONE:
 */
void termWritePlid(uint16_t i_source, uint32_t plid);

/** @fn termWriteSRC
 *  Create an SRC and Update the TI data area with the src created
 *  @param[in] i_source:  indicates what type of fail forced the TI
 *  @param[in] i_reasoncode: reasoncode for the failure(assert or shutdown)
 *  @param[in] i_failAddr: i_linkRegister() value (address of failure)
 *  @param[out] NONE:
 */
void termWriteSRC(uint16_t i_source,
                    uint16_t i_reasoncode,
                    uint64_t i_failAddr = 0);


#endif
