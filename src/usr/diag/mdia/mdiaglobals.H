/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/mdia/mdiaglobals.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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
#ifndef __MDIA__MDIAGLOBALS_H
#define __MDIA__MDIAGLOBALS_H

/**
 * @file mdiaglobals.H
 * @brief memory diagnostics global variables
 */

#include "mdiafwd.H"
#include <stdint.h>
#include <mfgFlagAccessors.H>

namespace MDIA
{

/**
 * @brief memory diagnostics step global variables
 */
class Globals
{
  private:

    /** The number of diagnostic patterns to run. */
    DiagMode iv_diagMode = ONE_PATTERN;

    /** True, if special pattern testing is explicitly enabled. */
    bool iv_specialPatternTesting = true; // will be cleared in constructor

    /** True, if MNFG IPL CE checking is enabled. */
    bool iv_mnfgIplCeChecking = false;

  public:

    /** @brief Default constructor. */
    Globals()
    {
        TARGETING::TargetHandle_t sysTrgt = nullptr;
        TARGETING::targetService().getTopLevelTarget(sysTrgt);
        assert( nullptr != sysTrgt );

        // Get the list of manufacturing flags to check against
        TARGETING::ATTR_MFG_FLAGS_typeStdArr mfg = {0};
        TARGETING::getAllMfgFlags(mfg);

        // Set the diagnostics pattern mode.
        if ( TARGETING::isExhaustivePatternTestEnabled(mfg) )
        {
            iv_diagMode = NINE_PATTERNS;
        }
        else if ( TARGETING::isStandardPatternTestEnabled(mfg) )
        {
            iv_diagMode = FOUR_PATTERNS;
        }
        else if ( TARGETING::isMinimumPatternTestEnabled(mfg) )
        {
            iv_diagMode = ONE_PATTERN;
        }
        else
        {
            iv_specialPatternTesting = false; // Normal pattern testing
        }

        // Check if MNFG IPL CE checking is enabled.
        if ( TARGETING::isMfgCeCheckingEnabled(mfg) )
        {
            iv_mnfgIplCeChecking = true;
        }
    }

    /** @return The default diagnostics mode. */
    DiagMode getDiagMode() const { return iv_diagMode; }

    /** @return True, if MNFG IPL pattern testing is enabled. */
    bool querySpecialPatternTesting() const { return iv_specialPatternTesting; }

    /** @return True, if MNFG IPL CE checking is enabled. */
    bool queryMnfgIplCeChecking() const { return iv_mnfgIplCeChecking; }
};

} // namespace MDIA

#endif
