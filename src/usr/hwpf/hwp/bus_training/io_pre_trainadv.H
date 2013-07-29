/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/io_pre_trainadv.H $             */
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
// $Id: io_pre_trainadv.H,v 1.1 2013/05/10 20:05:59 thomsen Exp $
#ifndef IO_PRE_TRAINADV_H_
#define IO_PRE_TRAINADV_H_

#include <fapi.H>

using namespace fapi;

/**
 * io_pre_trainadv HWP func pointer typedef
 *
 */
typedef fapi::ReturnCode (*io_pre_trainadv_FP_t)(const fapi::Target &target);

extern "C"
{

/**
 * io_pre_trainadv HWP
 *
 * master_target is any IO target P8 MCS,XBUS,Abus or centaur
 *
 *
 *
 *
 */

fapi::ReturnCode io_pre_trainadv(const fapi::Target &target);

} // extern "C"
#endif // io_pre_trainadv_H_

