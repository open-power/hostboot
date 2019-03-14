/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemVcm.C $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
uint32_t VcmEvent<TYPE_MCA>::startCmd()
{
    #define PRDF_FUNC "[VcmEvent::startCmd] "

    uint32_t o_rc = SUCCESS;

    // No stop conditions.
    mss::mcbist::stop_conditions<> stopCond;

    // Start the time based scrub procedure on this master rank.
    o_rc = startTdScrub<TYPE_MCA>( iv_chip, iv_rank, MASTER_RANK, stopCond );
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "startTdScrub(0x%08x,0x%2x) failed",
                  iv_chip->getHuid(), getKey() );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

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
uint32_t VcmEvent<TYPE_MBA>::rowRepair( STEP_CODE_DATA_STRUCT & io_sc,
                                        bool & o_done )
{
    #define PRDF_FUNC "[VcmEvent::rowRepair] "

    PRDF_ASSERT( iv_rowRepairEnabled )

    uint32_t o_rc = SUCCESS;

    do
    {
        // get port select
        uint8_t l_ps = iv_mark.getSymbol().getPortSlct();

        // get if the spares are available
        bool l_spAvail, l_eccAvail;
        o_rc = PlatServices::isSpareAvailable<TYPE_MBA>( iv_chip->getTrgt(),
            iv_rank, l_ps, l_spAvail, l_eccAvail );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "isChipMarkOnSpare(0x%08x) failed",
                      iv_chip->getHuid() );
            break;
        }

        // get dimm
        TARGETING::TargetHandle_t l_dimm =
            PlatServices::getConnectedDimm( iv_chip->getTrgt(), iv_rank,
                                            l_ps );

        // If scrub stops on first MCE, and static row repair
        // not supported or both spare and chip mark used
        if ( 1 == iv_mceCount && ( !l_spAvail && !l_eccAvail ) )
        {
            // Record bad DQs in VPD - done when verified()
            // No need to continue scrubbing, VCM verified, VCM done.
            o_done = true;
        }
        // Else if scrub stops on first MCE and static row repair
        // supported
        else if ( 1 == iv_mceCount )
        {
            MemRowRepair l_rowRepair;
            o_rc = getRowRepairData<TYPE_MBA>( l_dimm, iv_rank, l_rowRepair );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "getRowRepairData(0x%08x, 0x%02x)",
                          PlatServices::getHuid(l_dimm), iv_rank.getKey() );
                break;
            }

            // If the port, dimm, master rank has previous row repair in VPD
            if ( l_rowRepair.isValid() )
            {
                // If previous repair for same DRAM
                if ( l_rowRepair.getRowRepairDram() ==
                     iv_mark.getSymbol().getDramRelCenDqs() )
                {
                    // Clear previous row repair from VPD
                    o_rc = clearRowRepairData<TYPE_MBA>( l_dimm, iv_rank );
                    if ( SUCCESS != o_rc )
                    {
                        PRDF_ERR( PRDF_FUNC "clearRowRepairData"
                                  "(0x%08x, 0x%02x) failed",
                                  PlatServices::getHuid(l_dimm),
                                  iv_rank.getKey() );
                        break;
                    }

                    // Record bad DQs in VPD - done when verified()
                    // Signature: "VCM: verified: previous PPR on same DRAM"
                    io_sc.service_data->setSignature( iv_chip->getHuid(),
                        PRDFSIG_VcmVerSameDram );

                    // No need to continue scrubbing, VCM verified, VCM done
                    o_done = true;
                }
                // Else if previous repair for different DRAM
                else
                {
                    // Leave previous row repair in VPD
                    // Record bad DQs in VPD - done when verified()
                    // Signature:"VCM: verified: previous PPR on
                    // different DRAM"
                    io_sc.service_data->setSignature( iv_chip->getHuid(),
                        PRDFSIG_VcmVerDiffDram );

                    // No need to continue scrubbing, VCM verified, VCM done
                    o_done = true;
                }
            }
            // Else if no previous row repair
            else
            {
                // Signature: "VCM: verified: first MCE"
                io_sc.service_data->setSignature( iv_chip->getHuid(),
                    PRDFSIG_VcmVerFirstMce );

                // Record bad DQs in VPD - done when verified()
                // Remember address
                MemAddr l_addr;
                o_rc = getMemMaintAddr<TYPE_MBA>( iv_chip,
                                                  iv_rowRepairFailAddr );
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC "getMemMaintAddr(0x%08x) failed",
                              iv_chip->getHuid() );
                    break;
                }

                // Continue scrub, don't set procedure to done
            }
        }
        // Else if scrub stops on second MCE
        else if ( iv_mceCount > 1 )
        {
            // Since at least 2 bad rows, don't bother with row repair
            // No need to continue scrubbing, VCM verified, VCM done
            o_done = true;

            // Signature: "VCM: verified: second MCE"
            io_sc.service_data->setSignature( iv_chip->getHuid(),
                PRDFSIG_VcmVerSecMce );
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

template<>
uint32_t VcmEvent<TYPE_MBA>::rowRepairEndRank( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[VcmEvent::rowRepairEndRank] "

    PRDF_ASSERT( !iv_canResumeScrub );
    PRDF_ASSERT( iv_rowRepairEnabled );
    PRDF_ASSERT( 0 != iv_mceCount );

    uint32_t o_rc = SUCCESS;

    do
    {
        // get dimm
        uint8_t l_ps = iv_mark.getSymbol().getPortSlct();
        TARGETING::TargetHandle_t l_dimm =
            PlatServices::getConnectedDimm( iv_chip->getTrgt(), iv_rank,
                                            l_ps );

        // If scrub gets to the end of the master rank with an MCE
        // Update VPD with row repair
        // Note: inputted DRAM position needs to be relative to the Centaur DQs
        o_rc = setRowRepairData<TYPE_MBA>( l_dimm, iv_rank,
            iv_rowRepairFailAddr, iv_mark.getSymbol().getDramRelCenDqs() );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "setRowRepairData(0x%08x, 0x%02x) "
                      "failed", PlatServices::getHuid(l_dimm),
                      iv_rank.getKey() );
            break;
        }

        // Signature: "VCM: verified: common row fail"
        io_sc.service_data->setSignature( iv_chip->getHuid(),
                                          PRDFSIG_VcmVerRowFail );

        // VCM verified, VCM done

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

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
                iv_mceCount++;

                // Only need to call verified on the first mce we hit
                if ( 1 == iv_mceCount )
                {
                    o_rc = verified( io_sc );
                    if ( SUCCESS != o_rc )
                    {
                        PRDF_ERR( PRDF_FUNC "verified() failed on 0x%08x",
                                  iv_chip->getHuid() );
                        break;
                    }
                }

                if ( iv_rowRepairEnabled )
                {
                    o_rc = rowRepair( io_sc, o_done );
                    if ( SUCCESS != o_rc )
                    {
                        PRDF_ERR( PRDF_FUNC "rowRepair() failed on 0x%08x",
                                  iv_chip->getHuid() );
                        break;
                    }
                    if ( o_done ) break;

                    // Row repair is enabled, we found an MCE, and we did not
                    // need to exit the procedure. This means we will resume the
                    // command on the next row, but first we need to make sure
                    // the command did not stop on the last row of the address
                    // range. So reinitialize iv_canResumeScrub if necessary.

                    o_rc = didCmdStopOnLastAddr<TYPE_MBA>( iv_chip, MASTER_RANK,
                                                           lastAddr, true );
                    if ( SUCCESS != o_rc )
                    {
                        PRDF_ERR( PRDF_FUNC "didCmdStopOnLastAddr(0x%08x) "
                                  "failed", iv_chip->getHuid() );
                        break;
                    }
                    iv_canResumeScrub = !lastAddr;

                    if ( iv_canResumeScrub )
                    {
                        // Indicate that we need to resume the command on the
                        // next row instead of the next address.
                        iv_resumeNextRow = true;
                    }
                }
                else
                {
                    o_done = true; // Procedure is complete.
                    break;
                }
            }

            if ( !iv_canResumeScrub )
            {
                // If row repair is enabled, we reached the end of the rank, and
                // we got an MCE, we need to apply the row repair.
                if ( iv_rowRepairEnabled && 0 != iv_mceCount )
                {
                    o_rc = rowRepairEndRank( io_sc );
                    if ( SUCCESS != o_rc )
                    {
                        PRDF_ERR( PRDF_FUNC "rowRepairEndRank() failed on "
                                  "0x%08x", iv_chip->getHuid() );
                        break;
                    }
                }
                else
                {
                    // The chip mark is not verified and the command has reached
                    // the end of the rank. So this is a false alarm.
                    o_rc = falseAlarm( io_sc );
                    if ( SUCCESS != o_rc )
                    {
                        PRDF_ERR( PRDF_FUNC "falseAlarm() failed on 0x%08x",
                                  iv_chip->getHuid() );
                        break;
                    }
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

