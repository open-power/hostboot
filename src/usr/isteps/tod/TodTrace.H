/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/tod/TodTrace.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
#ifndef TODTRACE_H
#define TODTRACE_H

#include <tracinterface.H>
#include <initservice/isteps_trace.H>

namespace TOD
{

// field traces -------------------

#define TOD_TRAC(args...)  TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,\
                                " TOD:: " args)
#define TOD_ENTER(args...) TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,\
                                ENTER_MRK" TOD:: " args)
#define TOD_EXIT(args...)  TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,\
                                EXIT_MRK" TOD:: " args)
#define TOD_ERR(args...)   TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,\
                                ERR_MRK" TOD:: " args)
#define TOD_INF(args...)   TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,\
                                INFO_MRK" TOD:: " args)
#define TOD_IMP(args...)   TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,\
                                INFO_MRK" TOD:: " args)

// debug traces -------------------

#define TOD_DTRAC(args...)  TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,\
                                " TOD:: " args)
#define TOD_DENTER(args...) TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,\
                                ENTER_MRK" TOD:: " args)
#define TOD_DEXIT(args...)  TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,\
                                EXIT_MRK" TOD:: " args)

}

#endif

