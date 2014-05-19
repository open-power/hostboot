/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/io_run_training.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: io_run_training.H,v 1.9 2014/03/05 11:56:29 varkeykv Exp $
#ifndef IO_RUN_TRAINING_H_
#define IO_RUN_TRAINING_H_


#include <fapi.H>

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
