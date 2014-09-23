/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/occ/occ.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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
     * @param[out] o_failedOccTarget: Pointer to the target failing
     *                       loadnStartAllOccs
     * @return errlHndl_t  Error log if OCC load failed
     */
    errlHndl_t loadnStartAllOccs(TARGETING::Target *& o_failedOccTarget);

    /**
     * @brief Starts OCCs on all Processors in the node
     *        This is intended to be used for Open Power.
     *
     * @return errlHndl_t  Error log if OCC load failed
     */
    errlHndl_t activateOCC ();
} //end OCC namespace

#endif
