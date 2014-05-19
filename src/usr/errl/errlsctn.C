/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/errlsctn.C $                                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
 *  @file errlsctn.C
 *
 *  @brief Implementation of ErrlSctn class.
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <trace/interface.H>
#include <errl/errlentry.H>


namespace ERRORLOG
{

extern trace_desc_t* g_trac_errl;


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

ErrlSctn::ErrlSctn(  const uint16_t    i_sid,
                     const uint16_t    i_slen,
                     const uint8_t     i_ver,
                     const uint8_t     i_sst,
                     const compId_t    i_compId ) :
    iv_header( i_sid, i_slen, i_ver, i_sst, i_compId )
{

}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ErrlSctn::~ErrlSctn()
{

}


} // end namespace
