/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemVcm.C $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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

/** @file prdfMemVcm.C */

#include <prdfMemVcm.H>

// Platform includes

#include <exp_defaults.H>
#include <exp_rank.H>
#include <kind.H>
#include <hwp_wrappers.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//##############################################################################
//
//                           Generic Specializations
//
//##############################################################################

template<TARGETING::TYPE T>
uint32_t VcmEvent<T>::handlePhaseComplete( const uint32_t & i_eccAttns,
                                           STEP_CODE_DATA_STRUCT & io_sc,
                                           bool & o_done )
{
    #define PRDF_FUNC "[VcmEvent<T>::handlePhaseComplete] "

    uint32_t o_rc = SUCCESS;

    do
    {
        if ( TD_PHASE_2 == iv_phase )
        {
            // Determine if the chip mark has been verified.
            o_rc = (i_eccAttns & MAINT_MCE) ? verified(io_sc)
                                            : falseAlarm(io_sc);
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "verified()/falseAlarm() failed" );
                break;
            }

            o_done = true; // Procedure is complete.
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

template
uint32_t VcmEvent<TYPE_OCMB_CHIP>::handlePhaseComplete(
                                                  const uint32_t & i_eccAttns,
                                                  STEP_CODE_DATA_STRUCT & io_sc,
                                                  bool & o_done );

//##############################################################################
//
//                           Specializations for OCMB
//
//##############################################################################

template<>
uint32_t VcmEvent<TYPE_OCMB_CHIP>::startCmd()
{
    #define PRDF_FUNC "[VcmEvent::startCmd] "

    uint32_t o_rc = SUCCESS;

    // No stop conditions.
    mss::mcbist::stop_conditions<mss::mc_type::EXPLORER> stopCond;

    // Start the time based scrub procedure on this master rank.
    o_rc = startTdScrub<TYPE_OCMB_CHIP>( iv_chip, iv_rank, MASTER_RANK,
                                         stopCond );
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

