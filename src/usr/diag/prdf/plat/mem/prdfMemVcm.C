/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemVcm.C $                     */
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

/** @file prdfMemVcm.C */

#include <prdfMemVcm.H>

// Platform includes
#include <prdfCenMbaExtraSig.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//##############################################################################
//
//                          Specializations for MCA
//
//##############################################################################

template<>
uint32_t VcmEvent<TYPE_MCA>::handlePhaseComplete( const uint32_t & i_eccAttns,
                                                  STEP_CODE_DATA_STRUCT & io_sc,
                                                  bool & o_done )
{
    #define PRDF_FUNC "[VcmEvent<TYPE_MCA>::handlePhaseComplete] "

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

//##############################################################################
//
//                          Specializations for MBA
//
//##############################################################################

template<>
uint32_t VcmEvent<TYPE_MBA>::startNextPhase( STEP_CODE_DATA_STRUCT & io_sc )
{
    uint32_t signature = 0;

    if ( iv_canResumeScrub )
    {
        signature = PRDFSIG_VcmResume;

        PRDF_TRAC( "[VcmEvent] Resuming VCM Phase %d: 0x%08x,0x%02x",
                   iv_phase, iv_chip->getHuid(), getKey() );
    }
    else
    {
        switch ( iv_phase )
        {
            case TD_PHASE_0:
                iv_phase  = TD_PHASE_1;
                signature = PRDFSIG_StartVcmPhase1;
                break;

            case TD_PHASE_1:
                iv_phase  = TD_PHASE_2;
                signature = PRDFSIG_StartVcmPhase2;
                break;

            default: PRDF_ASSERT( false ); // invalid phase
        }

        PRDF_TRAC( "[VcmEvent] Starting VCM Phase %d: 0x%08x,0x%02x",
                   iv_phase, iv_chip->getHuid(), getKey() );
    }

    io_sc.service_data->AddSignatureList( iv_chip->getTrgt(), signature );

    return startCmd();
}

//------------------------------------------------------------------------------

template<>
uint32_t VcmEvent<TYPE_MBA>::handlePhaseComplete( const uint32_t & i_eccAttns,
                                                  STEP_CODE_DATA_STRUCT & io_sc,
                                                  bool & o_done )
{
    #define PRDF_FUNC "[VcmEvent<TYPE_MBA>::handlePhaseComplete] "

    uint32_t o_rc = SUCCESS;

    do
    {
        // Determine if the command stopped on the last address.
        bool lastAddr = false;
        o_rc = didCmdStopOnLastAddr<TYPE_MBA>( iv_chip, MASTER_RANK, lastAddr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "didCmdStopOnLastAddr(0x%08x) failed",
                      iv_chip->getHuid() );
            break;
        }

        // It is important to initialize iv_canResumeScrub here, so that we will
        // know to resume the current phase in startNextPhase() instead of
        // starting phase.
        iv_canResumeScrub = !lastAddr;

        if ( TD_PHASE_2 == iv_phase )
        {
            if ( i_eccAttns & MAINT_MCE )
            {
                // The chip mark has been verified.
                o_rc = verified( io_sc );
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC "verified() failed on 0x%08x",
                              iv_chip->getHuid() );
                    break;
                }

                o_done = true; // Procedure is complete.
            }
            else if ( !iv_canResumeScrub )
            {
                // The chip mark is not verified and the command has reached the
                // end of the rank. So this is a false alarm.
                o_rc = falseAlarm( io_sc );
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC "falseAlarm() failed on 0x%08x",
                              iv_chip->getHuid() );
                    break;
                }

                o_done = true; // Procedure is complete.
            }
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

} // end namespace PRDF

