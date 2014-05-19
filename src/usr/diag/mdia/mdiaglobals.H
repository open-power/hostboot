/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/mdia/mdiaglobals.H $                             */
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
#ifndef __MDIA__MDIAGLOBALS_H
#define __MDIA__MDIAGLOBALS_H

/**
 * @file mdiaglobals.H
 * @brief memory diagnostics global variables
 */

#include "mdiafwd.H"
#include <stdint.h>

namespace MDIA
{

/**
 * @brief memory diagnostics step global variables
 */
struct Globals
{
    /**
     * @brief policy flags
     */
    uint64_t mfgPolicy;

    /**
     * @brief user interface policy
     */
    uint64_t userPolicy;

    /**
     * @brief flag to indicate running in simics env
     */
    bool simicsRunning;

    /**
     * @brief flag to disable scrubs after pattern test
     */
    bool disableScrubs;


    Globals(): mfgPolicy(0), userPolicy(0),
       simicsRunning(false), disableScrubs(false) {}

};
}
#endif
