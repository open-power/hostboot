/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/occ/occ.H $                          */
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
#ifndef OCC_H_
#define OCC_H_

#include <limits.h>
#include <errl/errlentry.H>

namespace HBOCC {

    struct occHostConfigDataArea_t
    {
        uint32_t version;
        uint32_t nestFrequency;
    };

    enum
    {
        OccHostDataVersion = 1,
        OCC_LIDID = 0x81e00430,
        OCC_IBSCOM_RANGE_IN_MB = MEGABYTE,
    };

    enum occAction_t
    {
        OCC_START,
        OCC_STOP,
    };

    /**
     * @brief Starts OCCs on all Processors in the node
     *        This is intended to be used for AVP testing.
     *
     * @return errlHndl_t  Error log if OCC load failed
     */
    errlHndl_t loadnStartAllOccs();

} //end OCC namespace

#endif
