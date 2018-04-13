/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemDsd_ipl.C $                 */
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

/** @file prdfMemDsd_ipl.C */

// Platform includes
#include <prdfMemDqBitmap.H>
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

    } while (0);

    // TODO: RTC 189221 remove once function is supported
    PRDF_ERR( PRDF_FUNC "not supported yet" );
    o_done = true; // to ensure nothing else gets executed

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

    switch ( iv_phase )
    {
        case TD_PHASE_1:
            // Start the steer cleanup procedure on this master rank.
            o_rc = startTdSteerCleanup<TYPE_MBA>( iv_chip, iv_rank, MASTER_RANK,
                                                  stopCond );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "startTdSteerCleanup(0x%08x,0x%2x) failed",
                          iv_chip->getHuid(), getKey() );
            }
            break;

        case TD_PHASE_2:
            // Start the superfast read procedure on this master rank.
            o_rc = startTdSfRead<TYPE_MBA>( iv_chip, iv_rank, MASTER_RANK,
                                            stopCond );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "startTdSfRead(0x%08x,0x%2x) failed",
                          iv_chip->getHuid(), getKey() );
            }
            break;

        default: PRDF_ASSERT( false ); // invalid phase
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

} // end namespace PRDF

