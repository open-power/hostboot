/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/common/attntrace.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2016                        */
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

#ifndef __ATTN_ATTNTRACE_H
#define __ATTN_ATTNTRACE_H

/**
 * @file attntrace.H
 *
 * @brief HBATTN trace macros.
 */

#include <trace/interface.H>

namespace ATTN
{

extern trace_desc_t * fastTd;
extern trace_desc_t * slowTd;

}

#define ATTN_DBG( _fmt_, _args_...) TRACDCOMP( ATTN::fastTd, INFO_MRK _fmt_, ##_args_)
#define ATTN_FAST( _fmt_, _args_...) TRACFCOMP( ATTN::fastTd, INFO_MRK _fmt_, ##_args_)
#define ATTN_SLOW( _fmt_, _args_...) TRACFCOMP( ATTN::slowTd, INFO_MRK _fmt_, ##_args_)
#define ATTN_ERR( _fmt_, _args_...) TRACFCOMP( ATTN::slowTd, ERR_MRK _fmt_, ##_args_)

// If you want to see what is going on, uncomment and rebuild
// #define ATTN_DEBUG

// The ATTN_TRACE can be used to provide lots of debug help if compiled in.
// However, normal compiles will have this completely out (so no affect).
#ifdef ATTN_DEBUG
  #define ATTN_TRACE( _fmt_, _args_...)  \
          TRACFCOMP( ATTN::fastTd, INFO_MRK _fmt_, ##_args_)
#else
  #define ATTN_TRACE( _fmt_, _args_...)
#endif

#endif
