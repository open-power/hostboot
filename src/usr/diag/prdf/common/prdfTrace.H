/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/prdfTrace.H $                        */
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

#ifndef PRDF_TRACE_H
#define PRDF_TRACE_H

#include <tracinterface.H>
#include <prdf_service_codes.H>

namespace PRDF
{
    #ifdef __HOSTBOOT_MODULE
    typedef trace_desc_t* tracDesc_t;
    #endif

    extern tracDesc_t traceDesc;

} // end namespace PRDF

// field traces -------------------

#define PRDF_TRAC(args...)  TRACFCOMP(PRDF::traceDesc, args)
#define PRDF_ENTER(args...) TRACFCOMP(PRDF::traceDesc, ENTER_MRK"" args)
#define PRDF_EXIT(args...)  TRACFCOMP(PRDF::traceDesc, EXIT_MRK"" args)
#define PRDF_ERR(args...)   TRACFCOMP(PRDF::traceDesc, ERR_MRK"" args)
#define PRDF_INF(args...)   TRACFCOMP(PRDF::traceDesc, INFO_MRK"" args)

// debug traces -------------------

#define PRDF_DTRAC(args...)  TRACDCOMP(PRDF::traceDesc, args)
#define PRDF_DENTER(args...) TRACDCOMP(PRDF::traceDesc, ENTER_MRK"" args)
#define PRDF_DEXIT(args...)  TRACDCOMP(PRDF::traceDesc, EXIT_MRK"" args)

#endif // PRDF_TRACE_H

