/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemDsd_rt.C $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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

/** @file prdfMemDsd_rt.C */

// Platform includes
#include <prdfMemDsd.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//##############################################################################
//
//                          Generic template functions
//
//##############################################################################

template<TARGETING::TYPE T>
uint32_t DsdEvent<T>::analyzePhase( STEP_CODE_DATA_STRUCT & io_sc,
                                    bool & o_done )
{
    #define PRDF_FUNC "[DsdEvent::analyzePhase] "

    uint32_t o_rc = SUCCESS;

    // TODO: RTC 189221 remove once function is supported
    PRDF_ERR( PRDF_FUNC "not supported yet" );

    do
    {
        if ( TD_PHASE_0 == iv_phase )
        {
            // Before starting the next command, set iv_mark in the steer mux.
            /* TODO: RTC 189221
            o_rc = setSteerMux<T>( iv_chip, iv_rank, iv_mark );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "setSteerMux(0x%08x,0x%2x) failed",
                          iv_chip->getHuid(), getKey() );
                break;
            }
            */

            break; // Nothing to analyze yet.
        }

        // TODO: RTC 189221 finish supporting this function.

        // At this point, we are done with the procedure.
        o_done = true;

    } while (0);

    if ( (SUCCESS == o_rc) && o_done )
    {
        // Clear the ECC FFDC for this master rank.
        MemDbUtils::resetEccFfdc<T>( iv_chip, iv_rank, MASTER_RANK );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//##############################################################################
//
//                          Specializations for MBA
//
//##############################################################################

template<>
uint32_t DsdEvent<TYPE_MBA>::startCmd()
{
    #define PRDF_FUNC "[DsdEvent::startCmd] "

    uint32_t o_rc = SUCCESS;

    uint32_t stopCond = mss_MaintCmd::NO_STOP_CONDITIONS;

    // Due to a hardware bug in the Centaur, we must execute runtime maintenance
    // commands at a very slow rate. Because of this, we decided that we should
    // stop the command immediately on error if there is a UE so that we can
    // respond quicker and send a DMD message to the hypervisor as soon as
    // possible.

    stopCond |= mss_MaintCmd::STOP_ON_UE;
    stopCond |= mss_MaintCmd::STOP_IMMEDIATE;

    // Start the time based scrub procedure on this master rank.
    o_rc = startTdScrub<TYPE_MBA>( iv_chip, iv_rank, MASTER_RANK, stopCond );
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "startTdScrub(0x%08x,0x%2x) failed",
                  iv_chip->getHuid(), getKey() );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

} // end namespace PRDF

