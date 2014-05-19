/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/mdia/mdiatrace.H $                               */
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
#ifndef __MDIA_MDIATRACE_H
#define __MDIA_MDIATRACE_H

/**
 * @file mdiatrace.H
 * @brief mdia trace macros
 */

#include <trace/interface.H>

namespace MDIA
{

extern trace_desc_t * fastTd;
extern trace_desc_t * slowTd;

}

#define MDIA_DBG( _fmt_, _args_...) TRACDCOMP( MDIA::fastTd, INFO_MRK""_fmt_, ##_args_)
#define MDIA_FAST( _fmt_, _args_...) TRACFCOMP( MDIA::fastTd, INFO_MRK""_fmt_, ##_args_)
#define MDIA_SLOW( _fmt_, _args_...) TRACFCOMP( MDIA::slowTd, INFO_MRK""_fmt_, ##_args_)
#define MDIA_ERR( _fmt_, _args_...) TRACFCOMP( MDIA::slowTd, ERR_MRK""_fmt_, ##_args_)

#endif
