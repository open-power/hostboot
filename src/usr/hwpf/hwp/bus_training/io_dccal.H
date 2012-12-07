/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/io_dccal.H $                    */
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
// $Id: io_dccal.H,v 1.7 2012/11/27 08:43:45 varkeykv Exp $
#ifndef IO_DCCAL_H_
#define IO_DCCAL_H_

#include <fapi.H>

using namespace fapi;

/**
 * io_dccal HWP func pointer typedef
 *
 */
typedef fapi::ReturnCode (*io_dccal_FP_t)(const fapi::Target &target);

extern "C"
{

/**
 * io_dccal HWP 
 *
 * master_target is any IO target P8 MCS,XBUS,Abus or centaur
 * 
 * 
 *
 * 
 */

fapi::ReturnCode io_dccal(const fapi::Target &target);
    
} // extern "C"
#endif // IO_DCCAL_H_

