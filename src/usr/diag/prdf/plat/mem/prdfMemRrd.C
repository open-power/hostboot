/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemRrd.C $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2023                        */
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

/** @file prdfMemRrd.C */

// Platform includes
#include <prdfMemRrd.H>
#include <UtilHash.H>

#include <exp_rank.H>
#include <kind.H>
#include <hwp_wrappers.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

template<TARGETING::TYPE T>
uint32_t RrdEvent<T>::nextStep( STEP_CODE_DATA_STRUCT & io_sc, bool & o_done )
{
    #define PRDF_FUNC "[RrdEvent::nextStep] "

    uint32_t o_rc = SUCCESS;

    // NOTE: Row repairs should already be supported if we get this far,
    //       so just continue without checking for the support here

    o_done = false;

    do
    {
        // First, do analysis.
        o_rc = analyzePhase( io_sc, o_done );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "analyzePhase() failed on 0x%08x,0x%2x",
                      iv_chip->getHuid(), getKey() );
            break;
        }

        if ( o_done ) break; // Nothing more to do.

        // Then, start the next phase of the procedure.
        o_rc = startNextPhase( io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "startNextPhase() failed on 0x%08x,0x%2x",
                      iv_chip->getHuid(), getKey() );
            break;
        }

    } while (0);

    // Add the chip mark to the callout list if no callouts in the list.
    if ( 0 == io_sc.service_data->getMruListSize() )
    {
        MemoryMru mm { iv_chip->getTrgt(), iv_rank, iv_port,
                       iv_mark.getSymbol() };
        io_sc.service_data->SetCallout( mm );
    }

    // Add any FFDC for the deployed row and uninitialized rows found so far.
    addFfdc(io_sc);

    return o_rc;

    #undef PRDF_FUNC
}

template<TARGETING::TYPE T>
uint32_t RrdEvent<T>::checkEcc( const uint32_t & i_eccAttns,
                                STEP_CODE_DATA_STRUCT & io_sc,
                                bool & o_done )
{
    #define PRDF_FUNC "[RrdEvent<T>::checkEcc] "

    uint32_t o_rc = SUCCESS;

    do
    {
        if ( i_eccAttns & MAINT_UE )
        {
            PRDF_TRAC( "[RrdEvent] UE Detected: 0x%08x,0x%02x",
                       iv_chip->getHuid(), getKey() );

            io_sc.service_data->setSignature( iv_chip->getHuid(),
                                              PRDFSIG_MaintUE );

            // At this point we don't actually have an address for the UE. The
            // best we can do is get the address in which the command stopped.
            MemAddr addr;
            o_rc = getMemMaintAddr<T>( iv_chip, addr );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "getMemMaintAddr(0x%08x) failed",
                          iv_chip->getHuid() );
                break;
            }

            o_rc = MemEcc::handleMemUe<T>( iv_chip, addr,
                                           UE_TABLE::SCRUB_UE, io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleMemUe(0x%08x,0x%02x) failed",
                          iv_chip->getHuid(), getKey() );
                break;
            }

            #ifdef __HOSTBOOT_RUNTIME
            // Because of the UE, any further TPS requests will likely have no
            // effect. So ban all subsequent requests.
            MemDbUtils::banTps<T>( iv_chip, addr.getRank(), iv_port );
            #endif

            // Leave the mark in place and abort this procedure.
            o_done = true; break;
        }

        #ifndef __HOSTBOOT_RUNTIME
        // For Odyssey, AUEs found during IPL/memdiags will be handled the same
        // as UEs. Pause on AUE will be set in the superfast reads for memdiags.
        if ( 0 != (i_eccAttns & MAINT_AUE) )
        {
            // At this point we don't actually have an address for the UE. The
            // best we can do is get the address in which the command stopped.
            MemAddr addr;
            o_rc = getMemMaintAddr<T>( iv_chip, addr );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "getMemMaintAddr(0x%08x) failed",
                          iv_chip->getHuid() );
                break;
            }

            // Add the signature to the multi-signature list. Also, since
            // this will be a predictive callout, change the primary
            // signature as well.
            io_sc.service_data->AddSignatureList( iv_chip->getTrgt(),
                                                  PRDFSIG_MaintAUE );
            io_sc.service_data->setSignature( iv_chip->getHuid(),
                                              PRDFSIG_MaintAUE );

            // Do memory UE handling.
            o_rc = MemEcc::handleMemUe<T>( iv_chip, addr, UE_TABLE::SCRUB_AUE,
                                           io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "MAINT_AUE: handleMemUe<T>(0x%08x) failed",
                          iv_chip->getHuid() );
                break;
            }

            // Leave the mark in place and abort this procedure.
            o_done = true; break;
        }
        #endif

        if ( i_eccAttns & MAINT_RCE_ETE )
        {
            io_sc.service_data->setSignature( iv_chip->getHuid(),
                                              PRDFSIG_MaintRETRY_CTE );

            // Add the rank to the callout list.
            MemoryMru mm { iv_chip->getTrgt(), iv_rank, iv_port,
                           MemoryMruData::CALLOUT_RANK };
            io_sc.service_data->SetCallout( mm );

            // Make the error log predictive.
            io_sc.service_data->setServiceCall();

            // Don't abort continue the procedure.
        }

        if ( TD_PHASE_1 == iv_phase && i_eccAttns & MAINT_MCE )
        {
            // An MCE in this case will indicate an uninitialized address/row
            // that scrub stopped on. All the uninitialized row information
            // should be collected so the row that the row repair was deployed
            // on can be compared to that list. The original bad row
            // should match one of the uninitialized rows as an indicator that
            // it was correctly deployed.
            MemAddr addr;
            o_rc = getMemMaintAddr<T>( iv_chip, addr );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "getMemMaintAddr(0x%08x) failed",
                          iv_chip->getHuid() );
                break;
            }
            PRDF_TRAC( PRDF_FUNC "RRD: Stopped on MCE addr=0x%016llx",
                       addr.toMaintAddr<T>(iv_chip->getTrgt()) );

            FfdcRrData ffdc = getRrdFfdc(iv_chip->getTrgt(), addr);

            iv_uninitRows.push_back(ffdc);
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t RrdEvent<T>::verifyRowRepair( STEP_CODE_DATA_STRUCT & io_sc,
                                       bool & o_done )
{
    #define PRDF_FUNC "[RrdEvent<T>::verifyRowRepair] "

    uint32_t o_rc = SUCCESS;

    do
    {
        if ( TD_PHASE_2 != iv_phase ) break; // nothing to do

        o_done = true;

        // If it is safe to remove the chip mark, do so. Then the row repair
        // has been successfully deployed.
        if ( MarkStore::isSafeToRemoveChipMark<T>( iv_chip, iv_rank, iv_port ) )
        {
            PRDF_TRAC( PRDF_FUNC "Row repair deployed successfully: "
                       "0x%08x,0x%02x,%x", iv_chip->getHuid(), getKey(),
                       iv_port );

            io_sc.service_data->setSignature( iv_chip->getHuid(),
                                              PRDFSIG_RrdRowDeployed );

            o_rc = MarkStore::clearChipMark<T>( iv_chip, iv_rank, iv_port );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "clearChipMark(0x%08x,0x%02x,%x) failed",
                          iv_chip->getHuid(), getKey(), iv_port );
                break;
            }

            // Add an FFDC signature depending on data in iv_uninitRows
            if (iv_uninitRows.empty())
            {
                io_sc.service_data->AddSignatureList(iv_chip->getTrgt(),
                                                     PRDFSIG_RrdNoUninitRows);
            }
            else
            {
                // Look for if their is an uninitialized row that matches the
                // deployed row repair
                if (std::find(iv_uninitRows.begin(), iv_uninitRows.end(),
                    iv_deployedRr) != iv_uninitRows.end())
                {
                    // Matching row found
                    io_sc.service_data->AddSignatureList(iv_chip->getTrgt(),
                                                         PRDFSIG_RrdMatching);
                }
                else
                {
                    // No matching row found
                    io_sc.service_data->AddSignatureList(iv_chip->getTrgt(),
                                                         PRDFSIG_RrdNoMatching);
                }
            }
        }
        // Else if it is not safe to remove the chip mark, the spare row is bad
        else
        {
            PRDF_TRAC( PRDF_FUNC "Spare row is bad: 0x%08x,0x%02x",
                       iv_chip->getHuid(), getKey() );

            io_sc.service_data->setSignature( iv_chip->getHuid(),
                                              PRDFSIG_RrdBadRow );

            // Take actions to cleanup the chip mark
            bool junk = false;
            o_rc = MarkStore::chipMarkCleanup<T>(iv_chip, iv_rank, iv_port,
                                                 io_sc, junk);
            if ( SUCCESS != o_rc )
            {
                PRDF_TRAC( PRDF_FUNC "chipMarkCleanup(0x%08x, 0x%02x) failed",
                           iv_chip->getHuid(), getKey() );
                break;
            }
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t RrdEvent<T>::analyzePhase(STEP_CODE_DATA_STRUCT & io_sc, bool & o_done)
{
    #define PRDF_FUNC "[RrdEvent::analyzePhase] "

    uint32_t o_rc = SUCCESS;

    do
    {
        if ( TD_PHASE_0 == iv_phase )
        {
            // Clear the EICR register before deploying the row repair, has
            // no effect in the field, but helps with lab verification.
            char mbeicr[64];

            // Odyssey OCMB
            if (isOdysseyOcmb(iv_chip->getTrgt()))
            {
                sprintf( mbeicr, "MBEICR_%x", iv_port );
            }
            // Explorer OCMB
            else
            {
                sprintf( mbeicr, "MBEICR" );
            }
            SCAN_COMM_REGISTER_CLASS * reg = iv_chip->getRegister( mbeicr );
            reg->clearAllBits();
            o_rc = reg->Write();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "Write() failed on %s", mbeicr );
            }

            // Before starting the first command, deploy the row repair
            o_rc = PlatServices::deployRowRepair<T>( iv_chip, iv_rank );
            break; // Nothing to analyze yet.
        }

        bool lastAddr = false;
        o_rc = didCmdStopOnLastAddr<TARGETING::TYPE_OCMB_CHIP>( iv_chip,
            MASTER_RANK, lastAddr, true );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "didCmdStopOnLastAddr(0x%08x) failed",
                      iv_chip->getHuid() );
            break;
        }
        iv_canResumeScrub = !lastAddr;

        // Look for any ECC errors that occurred during the command.
        uint32_t eccAttns;
        o_rc = checkEccFirs<T>( iv_chip, iv_port, eccAttns );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "checkEccFirs(0x%08x, %x) failed",
                      iv_chip->getHuid(), iv_port );
            break;
        }

        // Analyze the ECC errors, if needed.
        o_rc = checkEcc( eccAttns, io_sc, o_done );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "checkEcc() failed on 0x%08x",
                      iv_chip->getHuid() );
            break;
        }

        if ( o_done ) break; // abort the procedure.

        // Determine if the row repair was deployed successfully.
        if (lastAddr)
        {
            o_rc = verifyRowRepair( io_sc, o_done );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "verifyRowRepair() failed on 0x%08x",
                          iv_chip->getHuid() );
                break;
            }
        }

    } while (0);

    #ifdef __HOSTBOOT_RUNTIME
    if ( (SUCCESS == o_rc) && o_done )
    {
        // Clear the ECC FFDC for this master rank.
        MemDbUtils::resetEccFfdc<T>( iv_chip, iv_rank, MASTER_RANK );
    }
    #endif

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
template<mss::mc_type MC>
uint32_t RrdEvent<TYPE_OCMB_CHIP>::startCmd()
{
    #define PRDF_FUNC "[RrdEvent<TYPE_OCMB_CHIP>::startCmd] "

    uint32_t o_rc = SUCCESS;

    mss::mcbist::stop_conditions<MC> stopCond;

    if ( TD_PHASE_1 == iv_phase )
    {
        // Set pause on all MCE types, so that uninitialized rows that exist
        // during the scrub can be recorded for FFDC.
        stopCond.set_pause_on_mce_hard(mss::ON)
                .set_pause_on_mce_soft(mss::ON)
                .set_pause_on_mce_int(mss::ON);
    }
    if ( TD_PHASE_2 == iv_phase )
    {
        // Set the per-symbol counters to count all 3 CE types: hard, soft, int
        stopCond.set_nce_soft_symbol_count_enable( mss::ON);
        stopCond.set_nce_inter_symbol_count_enable(mss::ON);
        stopCond.set_nce_hard_symbol_count_enable( mss::ON);

        // Set the per-symbol MCE counters to count only hard MCEs
        stopCond.set_mce_hard_symbol_count_enable(mss::ON);
    }

    if ( iv_canResumeScrub )
    {
        MemAddr addr;
        o_rc = getMemMaintAddr<TYPE_OCMB_CHIP>( iv_chip, addr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemMaintAddr(0x%08x) failed",
                      iv_chip->getHuid() );
        }
        else
        {
            o_rc = startTdScrubOnNextRow<TYPE_OCMB_CHIP>( iv_chip, iv_rank,
                addr, MASTER_RANK, stopCond, mss::mcbist::STOP_AFTER_ADDRESS );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "startTdScrubOnNextRow(0x%08x,0x%02x) "
                          "failed", iv_chip->getHuid(), getKey() );
            }
        }
    }
    else
    {
        // Start the time based scrub procedure on this master rank.
        o_rc = startTdScrub<TYPE_OCMB_CHIP>( iv_chip, iv_rank, iv_port,
                                            MASTER_RANK, stopCond,
                                            mss::mcbist::STOP_AFTER_ADDRESS );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "startTdScrub(0x%08x,0x%2x,%x) failed",
                    iv_chip->getHuid(), getKey(), iv_port );
        }
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t RrdEvent<T>::startNextPhase( STEP_CODE_DATA_STRUCT & io_sc )
{
    uint32_t signature = 0;

    if ( iv_canResumeScrub )
    {
        signature = PRDFSIG_RrdResume;
        PRDF_TRAC( "[RrdEvent] Resuming RRD Phase %d: 0x%08x,0x%02x",
                   iv_phase, iv_chip->getHuid(), getKey() );
    }
    else
    {
        switch ( iv_phase )
        {
            case TD_PHASE_0:
                iv_phase  = TD_PHASE_1;
                signature = PRDFSIG_StartRrdPhase1;
                break;

            case TD_PHASE_1:
                iv_phase  = TD_PHASE_2;
                signature = PRDFSIG_StartRrdPhase2;
                break;

            default: PRDF_ASSERT( false ); // invalid phase
        }

        PRDF_TRAC( "[RrdEvent] Starting RRD Phase %d: 0x%08x,0x%02x",
                   iv_phase, iv_chip->getHuid(), getKey() );
    }

    io_sc.service_data->AddSignatureList( iv_chip->getTrgt(), signature );

    // Odyssey OCMBs
    if (isOdysseyOcmb(iv_chip->getTrgt()))
    {
        return startCmd<mss::mc_type::ODYSSEY>();
    }
    // Explorer OCMBs
    else
    {
        return startCmd<mss::mc_type::EXPLORER>();
    }
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
void RrdEvent<T>::addFfdc(STEP_CODE_DATA_STRUCT & io_sc)
{
    // RrdFfdc Format:
    // 1 byte: Dram Position
    // 8 bytes: FfdcRrData entry for the deployed row repair
    // 1 byte: Number of uninitialized row entries
    // 8 bytes per entry: One FfdcRrData entry per uninitialized row found


    // Get the total size of the data.
    size_t sz_data = sizeof(uint8_t) + sizeof(FfdcRrData) + sizeof(uint8_t) +
                     (sizeof(FfdcRrData)*iv_uninitRows.size());

    auto buf = std::make_shared<FfdcBuffer>(ErrlRrdFfdc, ErrlVer1, sz_data);

    // Add in the dram position.
    (*buf) << iv_mark.getSymbol().getDramSpareAdjusted(); // 1 byte

    // Add in the deployed row repair.
    (*buf) << iv_deployedRr.prank  // 1 byte
           << iv_deployedRr.srank  // 1 byte
           << iv_deployedRr.bnkGrp // 1 byte
           << iv_deployedRr.bnk    // 1 byte
           << iv_deployedRr.row;   // 4 bytes

    // Add the number of uninitialized row entries
    uint8_t entries = iv_uninitRows.size();
    (*buf) << entries; // 1 byte

    // Loop through and add all uninitialized rows that have been found so far.
    for (const auto & row : iv_uninitRows)
    {
        (*buf) << row.prank  // 1 byte
               << row.srank  // 1 byte
               << row.bnkGrp // 1 byte
               << row.bnk    // 1 byte
               << row.row;   // 4 bytes
    }

    if (!buf->good())
    {
        PRDF_ERR("RrdEvent::addFfdc: Buffer state bad. Data may be "
                 "incomplete.");
    }

    io_sc.service_data->getFfdc().push_back(buf);
}

//##############################################################################
//                              Utility Functions
//##############################################################################

FfdcRrData getRrdFfdc(TargetHandle_t i_ocmb, const MemAddr & i_addr)
{
    // Get the information of the row repair to be deployed for FFDC.
    // The address information will be stored in a format consistent with
    // the row repair format stored in VPD.
    uint8_t prank = i_addr.getRank().getRankSlct();
    uint8_t srank = i_addr.getRank().getSlave();

    uint8_t bnkGrp;
    uint8_t bnk;
    // Odyssey OCMBs
    if (isOdysseyOcmb(i_ocmb))
    {
        // MemAddr Bank format - OCMB (Odyssey) : b0-b1,bg0-bg2 (5-bit)
        bnkGrp = i_addr.getBank() & 0x07;
        bnkGrp = MemUtils::reverseBits(bnkGrp, 3); // bg2-bg0

        bnk = (i_addr.getBank() & 0x18) >> 3;
        bnk = MemUtils::reverseBits(bnk, 2); // b1-b0
    }
    // Explorer OCMBs
    else
    {
        // MemAddr Bank format - OCMB (Explorer): b0-b2,bg0-bg1 (5-bit)
        bnkGrp = i_addr.getBank() & 0x03;
        bnkGrp = MemUtils::reverseBits(bnkGrp, 2); // bg1-bg0

        bnk = (i_addr.getBank() & 0x1C) >> 2;
        bnk = MemUtils::reverseBits(bnk, 3); // b2-b0
    }

    uint32_t row = i_addr.getRow();
    row = MemUtils::reverseBits(row, 18); // r17-r0

    FfdcRrData rrdFfdc = {prank, srank, bnkGrp, bnk, row};

    return rrdFfdc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

// Avoid linker errors with the template.
template class RrdEvent<TYPE_OCMB_CHIP>;

} // end namespace PRDF

