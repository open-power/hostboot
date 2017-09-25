/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_attn.C $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
/*
  Contains the logic that is needed to handle and recover from SBE vital
  attentions that occur when the SBE crashes.
*/

#include <errl/errlentry.H>

extern trace_desc_t* g_trac_sbeio;

namespace SBEIO
{

    /**
     * @brief Gathers FFDC and recovers from SBE errors
     */
    errlHndl_t handleVitalAttn( TARGETING::Target* i_procTarg )
    {
        TRACFCOMP( g_trac_sbeio,
                   ENTER_MRK "handleVitalAttn> i_procTarg=",
                   TARGETING::get_huid(i_procTarg) );
        errlHndl_t l_errhdl = nullptr;

        TRACFCOMP( g_trac_sbeio, "NOOP for now" );
        // @todo - RTC:180241 - Implement basic error handling
        // @todo - RTC:180242 - Restart SBE
        // @todo - RTC:180243 - Advanced error handling
        // @todo - RTC:180244 - Disable the OCC
        // @todo - RTC:180245 - Inform OPAL

        TRACFCOMP( g_trac_sbeio,
                   EXIT_MRK "handleVitalAttn> ");
        return l_errhdl;
    }

};
