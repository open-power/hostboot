/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/io_cleanup.H $                  */
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
//$Id: io_cleanup.H,v 1.1 2013/07/30 12:00:50 varkeykv Exp $
#ifndef IO_CLEANUP_H_
#define IO_CLEANUP_H_

#include <fapi.H>
#include "io_clear_firs.H"

using namespace fapi;

/**
 * io_cleanup func pointer Typedef for hostboot 
 *
 */
typedef fapi::ReturnCode (*io_cleanup_FP_t)(const fapi::Target &,const fapi::Target &);

extern "C"
{

/**
 * io_cleanup 
 *
 * master_target is the master side of a bus ..p8.mcs in a DMI .. or a p8.abus/p8.xbus in fabric 
 * slave_target - slave side of the bus .. Centaur in DMI , p8.xbus or p8.abus for fabric
 * while these are called master or slave... I actually do a check in the code to see 
 * whether these are actually master chips by reading a GCR master_mode bit
 * and accordingly will perform a target swap if required 
 * @return ReturnCode
 */
fapi::ReturnCode io_cleanup(const fapi::Target &master_target,const fapi::Target & slave_target);

} // extern "C"

#endif // IO_cleanup_H
