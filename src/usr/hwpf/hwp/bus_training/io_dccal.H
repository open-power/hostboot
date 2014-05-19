/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/io_dccal.H $                    */
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
// $Id: io_dccal.H,v 1.9 2013/12/04 10:35:50 jaswamin Exp $
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

