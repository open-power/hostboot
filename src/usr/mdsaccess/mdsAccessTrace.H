/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mdsaccess/mdsAccessTrace.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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

/**
 *  @file mdsAccessTrace.H
 *
 *  @brief Defines the extern mdsaccess trace
 */

#ifndef MDS_ACCESS_TRACE_H
#define MDS_ACCESS_TRACE_H

#include <trace/interface.H> // trace_desc_t, TRAC_INIT

//******************************************************************************
// Trace descriptor that is defined in matching C file
//******************************************************************************
extern trace_desc_t* g_trac_mdsaccess;

#endif // #ifndef MDS_ACCESS_TRACE_H
