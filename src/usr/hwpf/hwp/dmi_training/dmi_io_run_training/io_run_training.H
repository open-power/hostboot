//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/HWPs/dmi_training/dmi_io_run_training/io_run_training.H $
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
#ifndef IO_RUN_TRAINING_H_
#define IO_RUN_TRAINING_H_

#include <fapi.H>
#include "io_funcs.H"

using namespace fapi;

/**
 * io_run_training func pointer Typedef for hostboot 
 *
 */
typedef fapi::ReturnCode (*io_run_training_FP_t)(const fapi::Target &,io_interface_t ,uint32_t ,const fapi::Target &,io_interface_t ,uint32_t );

extern "C"
{

/**
 * io_run_training 
 *
 * master_target is the master side of a bus ..p8 in a DMI .. or a p8 master on fabric 
 * master_interface - since this code is generic across bus types master interface tells the code which bus interface is selected. This maps to a BUS GCR SCOM address base
 * master_group - clock group on master side ..since fAPI code runs only on a single clock group 
 * slave_target - slave side of the bus .. Centaur in DMI .. or p8 slaves
 * slave_interface - same as the master interface defn
 * slave_group - clock group on the slave side since fAPI code runs only on a single clock group 
 * 
 * @return ReturnCode
 */
fapi::ReturnCode io_run_training(const fapi::Target &master_target,io_interface_t master_interface,uint32_t master_group,const fapi::Target & slave_target,io_interface_t slave_interface,uint32_t slave_group);




} // extern "C"

#endif // IO_RUN_TRAINING_H
