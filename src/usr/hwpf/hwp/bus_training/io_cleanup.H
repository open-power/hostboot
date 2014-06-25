/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/io_cleanup.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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

//$Id: io_cleanup.H,v 1.3 2014/06/06 19:43:49 steffen Exp $
#ifndef IO_CLEANUP_H_
#define IO_CLEANUP_H_

#include <fapi.H>
#include <p8_scom_addresses.H>
#include "io_clear_firs.H"

using namespace fapi;

	CONST_UINT64_T( CENTAUR_MBI_CFG_0x0201080A                     , ULL(0x0201080A) );
	CONST_UINT64_T( CENTAUR_MBI_FIR_0x02010800                     , ULL(0x02010800) );
	CONST_UINT64_T( CENTAUR_MBI_CRCSYN_0x0201080C                  , ULL(0x0201080C) );
	CONST_UINT64_T( CENTAUR_CEN_DMIFIR_0x02010400                  , ULL(0x02010400) );

/**
 * io_cleanup func pointer Typedef for hostboot
 *
 */
typedef fapi::ReturnCode (*io_cleanup_FP_t)(const fapi::Target &);

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
fapi::ReturnCode io_cleanup(const fapi::Target &master_target);

} // extern "C"

#endif // IO_cleanup_H
