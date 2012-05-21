/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/bus_training/io_run_training.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
#ifndef IO_RUN_TRAINING_H_
#define IO_RUN_TRAINING_H_

#include <fapi.H>
#include "io_funcs.H"

using namespace fapi;

/**
 * io_run_training func pointer Typedef for hostboot 
 *
 */
typedef fapi::ReturnCode (*io_run_training_FP_t)(const fapi::Target &,const fapi::Target &);

extern "C"
{

/**
 * io_run_training 
 *
 * master_target is the master side of a bus ..p8.mcs in a DMI .. or a p8.abus/p8.xbus in fabric 
 * slave_target - slave side of the bus .. Centaur in DMI , p8.xbus or p8.abus for fabric
 * while these are called master or slave... I actually do a check in the code to see 
 * whether these are actually master chips by reading a GCR master_mode bit
 * and accordingly will perform a target swap if required 
 * @return ReturnCode
 */
fapi::ReturnCode io_run_training(const fapi::Target &master_target,const fapi::Target & slave_target);

} // extern "C"

#endif // IO_RUN_TRAINING_H
