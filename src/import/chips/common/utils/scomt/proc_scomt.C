/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/common/utils/scomt/proc_scomt.C $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
#include "proc_scomt.H"

namespace scomt
{

#ifdef SCOM_CHECKING

    #ifndef PLAT_NO_THREAD_LOCAL_STORAGE
        thread_local uint64_t       last_scom;
        thread_local uint8_t        chip;
        thread_local uint8_t        ec;
        thread_local bool           no_regchk = false;
        thread_local uint64_t       spare0 = 0;
        thread_local uint64_t       spare1 = 0;
    #else
        uint64_t       last_scom;
        uint8_t        chip;
        uint8_t        ec;
        bool           no_regchk = false;
        uint64_t       spare0 = 0;
        uint64_t       spare1 = 0;
    #endif

#endif

}
