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
#include <prdfMemRrd.H>

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
        // Determine if the command stopped on the last address.
        bool lastAddr = false;
        o_rc = didCmdStopOnLastAddr<TYPE_OCMB_CHIP>( iv_chip, MASTER_RANK,
                                                     lastAddr );
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
                    // If row repair is not supported, call verified
                    if ( !iv_rowRepairEnabled )
                    {
                        o_rc = verified( io_sc );
                        if ( SUCCESS != o_rc )
                        {
                            PRDF_ERR( PRDF_FUNC "verified() failed on 0x%08x",
                                      iv_chip->getHuid() );
                            break;
                        }
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

                    o_rc = didCmdStopOnLastAddr<TYPE_OCMB_CHIP>( iv_chip,
                        MASTER_RANK, lastAddr, true );
                    if ( SUCCESS != o_rc )
                    {
                        PRDF_ERR( PRDF_FUNC "didCmdStopOnLastAddr(0x%08x) "
                                  "failed", iv_chip->getHuid() );
                        break;
                    }
                    iv_canResumeScrub = !lastAddr;
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

    // If at phase 2, set to stop on MCEs
    if ( TD_PHASE_2 == iv_phase )
    {
        stopCond.set_pause_on_mce_hard(mss::ON)
                .set_pause_on_mce_soft(mss::ON)
                .set_pause_on_mce_int(mss::ON);
    }

    if ( iv_canResumeScrub )
    {
        PRDF_TRAC( PRDF_FUNC "Scrub stopped before end of rank, resuming "
                   "scrub from the next addr of this rank: "
                   "resumeTdScrub(0x%08x)", iv_chip->getHuid() );

        if ( iv_rowRepairEnabled )
        {
            // If row repair is enabled and we hit an MCE, start a new TD scrub
            // on the next row instead of the next address. This is so scrub
            // avoids just immediately hitting another MCE on the next address
            // of the bad row. The address we stopped on should be stored in
            // iv_rowRepairFailAddr by this point.
            o_rc = startTdScrubOnNextRow<TYPE_OCMB_CHIP>( iv_chip, iv_rank,
                    iv_rowRepairFailAddr, MASTER_RANK, stopCond,
                    mss::mcbist::STOP_AFTER_ADDRESS );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "startTdScrubOnNextRow(0x%08x,0x%02x) "
                          "failed", iv_chip->getHuid() );
            }
        }
        else
        {
            // Resume the command from the next addr to the end of this master
            // rank.
            o_rc = resumeTdScrub<TYPE_OCMB_CHIP>( iv_chip, stopCond );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "resumeTdScrub(0x%08x) failed",
                          iv_chip->getHuid() );
            }
        }
    }
    else
    {
        // Start the time based scrub procedure on this master rank.
        o_rc = startTdScrub<TYPE_OCMB_CHIP>( iv_chip, iv_rank, MASTER_RANK,
                                             stopCond,
                                             mss::mcbist::STOP_AFTER_ADDRESS );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "startTdScrub(0x%08x,0x%02x) failed",
                      iv_chip->getHuid(), getKey() );
        }
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t VcmEvent<TYPE_OCMB_CHIP>::rowRepair( STEP_CODE_DATA_STRUCT & io_sc,
                                              bool & o_done )
{
    #define PRDF_FUNC "[VcmEvent::rowRepair] "

    PRDF_ASSERT( iv_rowRepairEnabled )

    uint32_t o_rc = SUCCESS;

    do
    {
        // get port select
        uint8_t l_ps = iv_mark.getSymbol().getPortSlct();

        // get dimm
        TARGETING::TargetHandle_t l_dimm =
            PlatServices::getConnectedDimm( iv_chip->getTrgt(), iv_rank,
                                            l_ps );

        // If scrub stops on first MCE and row repair supported
        if ( 1 == iv_mceCount )
        {
            PRDF_TRAC( PRDF_FUNC "Scrub stopped on first MCE" );
            MemRowRepair l_rowRepair;
            o_rc = getRowRepairData<TYPE_OCMB_CHIP>( l_dimm, iv_rank,
                                                     l_rowRepair );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "getRowRepairData(0x%08x, 0x%02x)",
                          getHuid(l_dimm), iv_rank.getKey() );
                break;
            }

            // If the port, dimm, master rank has previous row repair in VPD
            if ( l_rowRepair.isValid() )
            {
                // No need to continue scrubbing, VCM verified, VCM done
                o_done = true;

                o_rc = verified( io_sc );
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC "verified() failed on 0x%08x",
                              iv_chip->getHuid() );
                    break;
                }

                // If previous repair for same DRAM
                if ( l_rowRepair.getRowRepairDram() ==
                     iv_mark.getSymbol().getDramSpareAdjusted() )
                {
                    PRDF_TRAC( PRDF_FUNC "Previous row repair on same dram %d. "
                               "clearRowRepairData(0x%08x,0x%02x)",
                               iv_mark.getSymbol().getDramSpareAdjusted(),
                               getHuid(l_dimm), iv_rank.getKey() );
                    // Clear previous row repair from VPD
                    o_rc = clearRowRepairData<TYPE_OCMB_CHIP>(l_dimm, iv_rank);
                    if ( SUCCESS != o_rc )
                    {
                        PRDF_ERR( PRDF_FUNC "clearRowRepairData"
                                  "(0x%08x, 0x%02x) failed",
                                  getHuid(l_dimm), iv_rank.getKey() );
                        break;
                    }

                    // Record bad DQs in VPD - done when verified()
                    // Signature: "VCM: verified: previous PPR on same DRAM"
                    io_sc.service_data->setSignature( iv_chip->getHuid(),
                        PRDFSIG_VcmVerSameDram );
                }
                // Else if previous repair for different DRAM
                else
                {
                    PRDF_TRAC( PRDF_FUNC "Previous row repair on different "
                               "dram. Previous dram: %d, New dram: %d",
                               l_rowRepair.getRowRepairDram(),
                               iv_mark.getSymbol().getDramSpareAdjusted() );
                    // Leave previous row repair in VPD
                    // Record bad DQs in VPD - done when verified()
                    // Signature:"VCM: verified: previous PPR on
                    // different DRAM"
                    io_sc.service_data->setSignature( iv_chip->getHuid(),
                        PRDFSIG_VcmVerDiffDram );
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
                o_rc = getMemMaintAddr<TYPE_OCMB_CHIP>( iv_chip,
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

            o_rc = verified( io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "verified() failed on 0x%08x",
                          iv_chip->getHuid() );
                break;
            }

            // Signature: "VCM: verified: second MCE"
            io_sc.service_data->setSignature( iv_chip->getHuid(),
                PRDFSIG_VcmVerSecMce );
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t VcmEvent<TYPE_OCMB_CHIP>::rowRepairEndRank(
    STEP_CODE_DATA_STRUCT & io_sc )
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

        PRDF_TRAC( PRDF_FUNC "Common row fail, deploying row repair: "
                   "setRowRepairData(0x%08x,0x%02x,%d)", getHuid(l_dimm),
                   iv_rank.getKey(),
                   iv_mark.getSymbol().getDramSpareAdjusted() );

        // If scrub gets to the end of the master rank with an MCE
        // Update VPD with row repair
        o_rc = setRowRepairData<TYPE_OCMB_CHIP>( l_dimm, iv_rank,
            iv_rowRepairFailAddr, iv_mark.getSymbol().getDramSpareAdjusted() );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "setRowRepairData(0x%08x, 0x%02x) "
                      "failed", getHuid(l_dimm), iv_rank.getKey() );
            break;
        }

        // Add a row repair deploy event to the targeted diagnostics queue
        TdEntry * rrd = new RrdEvent<TYPE_OCMB_CHIP>{iv_chip, iv_rank, iv_mark};
        MemDbUtils::pushToQueue<TYPE_OCMB_CHIP>( iv_chip, rrd );

        // Signature: "VCM: verified: common row fail"
        io_sc.service_data->setSignature( iv_chip->getHuid(),
                                          PRDFSIG_VcmVerRowFail );

        // VCM verified, VCM done

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

} // end namespace PRDF

