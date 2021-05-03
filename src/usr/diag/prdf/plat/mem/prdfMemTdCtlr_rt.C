/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemTdCtlr_rt.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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

/** @file  prdfMemTdCtlr_rt.C
 *  @brief A state machine for memory Targeted Diagnostics (runtime only).
 */

#include <prdfMemTdCtlr.H>

// Platform includes
#include <prdfMemCaptureData.H>
#include <prdfMemEccAnalysis.H>
#include <prdfMemScrubUtils.H>
#include <prdfMemTps.H>
#include <prdfMemUtils.H>
#include <prdfMemVcm.H>
#include <prdfMemExtraSig.H>
#include <prdfPlatServices.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
uint32_t MemTdCtlr<T>::handleTdEvent( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemTdCtlr::handleTdEvent] "

    uint32_t o_rc = SUCCESS;

    do
    {
        // Make sure the TD controller is initialized.
        o_rc = initialize();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "initialize() failed on 0x%08x",
                      iv_chip->getHuid() );
            break;
        }

        // Don't interrupt a TD procedure if one is already in progress.
        if ( nullptr != iv_curProcedure ) break;

        // If the queue is empty, there is nothing to do. So there is no point
        // to stopping background scrub. This could have happen if TPS was
        // banned on a rank and the TPS request was never added to the queue. In
        // that case, mask fetch attentions temporarily to prevent flooding.
        if ( iv_queue.empty() )
        {
            o_rc = maskEccAttns();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "maskEccAttns() failed" );
                break;
            }

            break; // Don't stop background scrub.
        }

        // Stop background scrubbing.
        o_rc = stopBgScrub<T>( iv_chip );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "stopBgScrub<T>(0x%08x) failed",
                      iv_chip->getHuid() );
            break;
        }

        // Since we had to manually stop the maintenance command, refresh all
        // relevant registers that may have changed since the initial capture.
        recaptureRegs( io_sc );

        collectStateCaptureData( io_sc, TD_CTLR_DATA::START );

        // It is possible that background scrub could have found an ECC error
        // before we had a chance to stop the command. Therefore, we need to
        // call analyzeCmdComplete() first so that any ECC errors found can be
        // handled. Also, analyzeCmdComplete() will initialize the variables
        // needed so we know where to restart background scrubbing.
        bool junk = false;
        o_rc = analyzeCmdComplete( junk, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "analyzeCmdComplete(0x%08x) failed",
                      iv_chip->getHuid() );
            break;
        }

        // Move onto the next step in the state machine.
        o_rc = nextStep( io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "nextStep() failed on 0x%08x",
                      iv_chip->getHuid() );
            break;
        }

    } while (0);

    // Gather capture data even if something failed above.
    collectStateCaptureData( io_sc, TD_CTLR_DATA::END );

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Failed on 0x%08x", iv_chip->getHuid() );

        // Change signature indicating there was an error in analysis.
        io_sc.service_data->setSignature( iv_chip->getHuid(),
                                          PRDFSIG_CmdComplete_ERROR );

        // Something definitely failed, so callout 2nd level support.
        io_sc.service_data->SetCallout( LEVEL2_SUPPORT, MRU_HIGH );
        io_sc.service_data->setServiceCall();
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
uint32_t MemTdCtlr<T>::defaultStep( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemTdCtlr::defaultStep] "

    uint32_t o_rc = SUCCESS;

    if ( iv_resumeBgScrub )
    {
        // Background scrubbing paused for FFDC collection only. Resume the
        // current command.

        iv_resumeBgScrub = false;

        PRDF_TRAC( PRDF_FUNC "Calling resumeBgScrub<T>(0x%08x)",
                   iv_chip->getHuid() );

        o_rc = resumeBgScrub<T>( iv_chip, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "resumeBgScrub<T>(0x%08x) failed",
                      iv_chip->getHuid() );
        }
    }
    else
    {

        // Unmask the ECC attentions that were explicitly masked during the
        // TD procedure.
        o_rc = unmaskEccAttns();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "unmaskEccAttns() failed" );
        }

        // A TD procedure has completed. Restart background scrubbing on the
        // next rank.

        TdRankListEntry nextRank = iv_rankList.getNext( iv_stoppedRank );

        PRDF_TRAC( PRDF_FUNC "Calling startBgScrub<T>(0x%08x, m%ds%d)",
                   nextRank.getChip()->getHuid(),
                   nextRank.getRank().getMaster(),
                   nextRank.getRank().getSlave() );

        o_rc = startBgScrub<T>( nextRank.getChip(), nextRank.getRank() );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "startBgScrub<T>(0x%08x,m%ds%d) failed",
                      nextRank.getChip()->getHuid(),
                      nextRank.getRank().getMaster(),
                      nextRank.getRank().getSlave() );
        }
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t __handleNceEte( ExtensibleChip * i_chip,
                         const MemAddr & i_addr, STEP_CODE_DATA_STRUCT & io_sc,
                         bool i_isHard = false )
{
    #define PRDF_FUNC "[__handleNceEte] "

    uint32_t o_rc = SUCCESS;

    MemRank rank = i_addr.getRank();

    do
    {
        // Query the per-symbol counters for the CE symbol(s).
        MemUtils::MaintSymbols symData; MemSymbol junk;
        o_rc = MemUtils::collectCeStats<T>( i_chip, rank, symData, junk );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "MemUtils::collectCeStats(0x%08x,m%ds%d) "
                      "failed", i_chip->getHuid(), rank.getMaster(),
                      rank.getSlave() );
            break;
        }

        // Make sure the list size is correct. Note that OCMBs have two symbol
        // correction. So it is possible to have two symbols in the counters
        // even though the threshold is set to 1.
        uint32_t count = symData.size();
        switch ( T )
        {
            case TYPE_OCMB_CHIP:
            {
                PRDF_ASSERT( 1 <= count && count <= 2 );
                // Increment the UE counter and store the rank we're on,
                // reset the UE and CE counts if we have stopped on a new rank.
                OcmbDataBundle * ocmbdb = getOcmbDataBundle(i_chip);
                if ( ocmbdb->iv_ceUeRank != i_addr.getRank() )
                {
                    ocmbdb->iv_ceStopCounter.reset();
                    ocmbdb->iv_ueStopCounter.reset();
                }
                ocmbdb->iv_ceStopCounter.inc( io_sc );
                ocmbdb->iv_ceUeRank = i_addr.getRank();

                break;
            }
            default:
            {
                PRDF_ASSERT( false );
            }
        }

        for ( auto & d : symData )
        {
            // Add the symbol(s) to the callout list and CE table.
            bool doTps;
            o_rc = MemEcc::handleMemCe<T>( i_chip, i_addr, d.symbol, doTps,
                                           io_sc, i_isHard );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleMemCe(0x%08x) failed",
                          i_chip->getHuid() );
                break;
            }

            // Add a TPS procedure to the queue, if needed.
            if ( doTps )
            {
                TdEntry * e = new TpsEvent<T>{ i_chip, rank };
                MemDbUtils::pushToQueue<T>( i_chip, e );
            }
        }
        if ( SUCCESS != o_rc ) break;

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t __handleSoftInterCeEte( ExtensibleChip * i_chip,
                                 const MemAddr & i_addr,
                                 STEP_CODE_DATA_STRUCT & io_sc );

template<>
uint32_t __handleSoftInterCeEte<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                                 const MemAddr & i_addr,
                                                 STEP_CODE_DATA_STRUCT & io_sc )
{
    return __handleNceEte<TYPE_OCMB_CHIP>( i_chip, i_addr, io_sc );
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t __handleRceEte( ExtensibleChip * i_chip,
                         const MemRank & i_rank, bool & o_errorsFound,
                         STEP_CODE_DATA_STRUCT & io_sc );

template<>
uint32_t __handleRceEte<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                         const MemRank & i_rank,
                                         bool & o_errorsFound,
                                         STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[__handleRceEte] "

    uint32_t o_rc = SUCCESS;

    // Should only get this attention in MNFG mode.
    PRDF_ASSERT( mfgMode() );

    do
    {
        // The RCE ETE attention could be from IUE, IMPE, or IRCD. Need to check
        // RDFFIR[37] to determine if there was at least one IUE.
        SCAN_COMM_REGISTER_CLASS * fir = i_chip->getRegister( "RDFFIR" );
        o_rc = fir->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on RDFFIR: i_chip=0x%08x",
                      i_chip->getHuid() );
            break;
        }
        if ( !fir->IsBitSet(37) ) break; // nothing else to do

        // Handle the IUE.
        o_errorsFound = true;
        io_sc.service_data->AddSignatureList( i_chip->getTrgt(),
                                              PRDFSIG_MaintIUE );
        o_rc = MemEcc::handleMemIue<TYPE_OCMB_CHIP>( i_chip, i_rank, io_sc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "analyzeMaintIue(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
uint32_t __checkEcc( ExtensibleChip * i_chip,
                     const MemAddr & i_addr, bool & o_errorsFound,
                     STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[__checkEcc] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( T == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    o_errorsFound = false;

    TargetHandle_t trgt = i_chip->getTrgt();
    HUID           huid = i_chip->getHuid();

    MemRank rank = i_addr.getRank();

    do
    {
        // Check for ECC errors.
        uint32_t eccAttns = 0;
        o_rc = checkEccFirs<T>( i_chip, eccAttns );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "checkEccFirs<T>(0x%08x) failed", huid );
            break;
        }

        if ( 0 != (eccAttns & MAINT_INT_NCE_ETE) )
        {
            o_errorsFound = true;
            io_sc.service_data->AddSignatureList( trgt, PRDFSIG_MaintINTER_CTE);

            o_rc = __handleSoftInterCeEte<T>( i_chip, i_addr, io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "__handleSoftInterCeEte<T>(0x%08x) failed",
                          huid );
                break;
            }
        }

        if ( 0 != (eccAttns & MAINT_SOFT_NCE_ETE) )
        {
            o_errorsFound = true;
            io_sc.service_data->AddSignatureList( trgt, PRDFSIG_MaintSOFT_CTE );

            o_rc = __handleSoftInterCeEte<T>( i_chip, i_addr, io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "__handleSoftInterCeEte<T>(0x%08x) failed",
                          huid );
                break;
            }
        }

        if ( 0 != (eccAttns & MAINT_HARD_NCE_ETE) )
        {
            o_errorsFound = true;
            io_sc.service_data->AddSignatureList( trgt, PRDFSIG_MaintHARD_CTE );

            o_rc = __handleNceEte<T>( i_chip, i_addr, io_sc, true );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "__handleNceEte<T>(0x%08x) failed",
                          huid );
                break;
            }

            // Any hard CEs in MNFG should be immediately reported.
            // NOTE: We will only use the MNFG thresholds if DRAM repairs is
            //       disabled.
            if ( areDramRepairsDisabled() )
            {
                io_sc.service_data->setSignature( huid, PRDFSIG_MaintHARD_CTE );
                io_sc.service_data->setServiceCall();
            }
        }

        if ( 0 != (eccAttns & MAINT_MPE) )
        {
            o_errorsFound = true;
            io_sc.service_data->AddSignatureList( trgt, PRDFSIG_MaintMPE );

            o_rc = MemEcc::handleMpe<T>( i_chip, i_addr, UE_TABLE::SCRUB_MPE,
                                         io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleMpe<T>(0x%08x, 0x%02x) failed",
                          i_chip->getHuid(), rank.getKey() );
                break;
            }
        }

        if ( 0 != (eccAttns & MAINT_RCE_ETE) )
        {
            o_rc = __handleRceEte<T>( i_chip, rank, o_errorsFound,
                                      io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "__handleRceEte<T>(0x%08x) failed", huid );
                break;
            }
        }

        if ( 0 != (eccAttns & MAINT_UE) )
        {
            o_errorsFound = true;
            io_sc.service_data->AddSignatureList( trgt, PRDFSIG_MaintUE );

            // Since this will be a predictive callout, change the primary
            // signature as well.
            io_sc.service_data->setSignature( huid, PRDFSIG_MaintUE );

            // Add the rank to the callout list.
            o_rc = MemEcc::handleMemUe<T>( i_chip, i_addr, UE_TABLE::SCRUB_UE,
                                           io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleMemUe<T>(0x%08x) failed",
                          i_chip->getHuid() );
                break;
            }

            // Add a TPS request to the TD queue for additional analysis. It is
            // unlikely the procedure will result in a repair because of the UE.
            // However, we want to run TPS once just to see how bad the rank is.
            TdEntry * e = new TpsEvent<T>{ i_chip, rank };
            MemDbUtils::pushToQueue<T>( i_chip, e );

            // Because of the UE, any further TPS requests will likely have no
            // effect. So ban all subsequent requests.
            MemDbUtils::banTps<T>( i_chip, rank );
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

template
uint32_t __checkEcc<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                     const MemAddr & i_addr,
                                     bool & o_errorsFound,
                                     STEP_CODE_DATA_STRUCT & io_sc );

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t MemTdCtlr<T>::maskEccAttns()
{
    #define PRDF_FUNC "[MemTdCtlr<T>::maskEccAttns] "

    uint32_t o_rc = SUCCESS;

    SCAN_COMM_REGISTER_CLASS * mask = iv_chip->getRegister( "RDFFIR_MASK_OR" );

    mask->clearAllBits();
    mask->SetBit(8); // Mainline read NCE
    mask->SetBit(9); // Mainline read TCE

    o_rc = mask->Write();
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Write() failed on RDFFIR_MASK_OR" );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t MemTdCtlr<TYPE_OCMB_CHIP>::unmaskEccAttns()
{
    #define PRDF_FUNC "[MemTdCtlr<TYPE_OCMB_CHIP>::unmaskEccAttns] "

    uint32_t o_rc = SUCCESS;

    // Memory CEs were masked at the beginning of the TD procedure, so
    // clear and unmask them. Also, it is possible that memory UEs have
    // thresholded so clear and unmask them as well.

    SCAN_COMM_REGISTER_CLASS * fir  = iv_chip->getRegister( "RDFFIR_AND" );
    SCAN_COMM_REGISTER_CLASS * mask = iv_chip->getRegister( "RDFFIR_MASK_AND" );

    fir->setAllBits(); mask->setAllBits();

    // Do not unmask NCE and TCE attentions if they have been permanently
    // masked due to certain TPS conditions.
    if ( !(getOcmbDataBundle(iv_chip)->iv_maskMainlineNceTce) )
    {
        fir->ClearBit(8);  mask->ClearBit(8);  // Mainline read NCE
        fir->ClearBit(9);  mask->ClearBit(9);  // Mainline read TCE
    }
    fir->ClearBit(14); mask->ClearBit(14); // Mainline read UE

    o_rc = fir->Write();
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Write() failed on RDFFIR_AND" );
    }

    o_rc = mask->Write();
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Write() failed on RDFFIR_MASK_AND" );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
SCAN_COMM_REGISTER_CLASS * __getEccFirAnd( ExtensibleChip * i_chip );

template<>
SCAN_COMM_REGISTER_CLASS * __getEccFirAnd<TYPE_OCMB_CHIP>(
                                                ExtensibleChip * i_chip )
{
    return i_chip->getRegister( "RDFFIR_AND" );
}

template <TARGETING::TYPE TP, TARGETING::TYPE TC>
uint32_t __findChipMarks( TdRankList<TC> & i_rankList )
{
    #define PRDF_FUNC "[__findChipMarks] "

    uint32_t o_rc = SUCCESS;

    for ( auto & entry : i_rankList.getList() )
    {
        ExtensibleChip * chip = entry.getChip();
        MemRank          rank = entry.getRank();

        // Call readChipMark to get MemMark.
        MemMark chipMark;
        o_rc = MarkStore::readChipMark<TP>( chip, rank, chipMark );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "readChipMark(0x%08x,0x%02x) failed",
                      chip->getHuid(), rank.getKey() );
            break;
        }

        if ( !chipMark.isValid() ) continue; // no chip mark present

        // Get the DQ Bitmap data.
        MemDqBitmap dqBitmap;
        o_rc = getBadDqBitmap( chip->getTrgt(), rank, dqBitmap );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getBadDqBitmap(0x%08x,0x%02x)",
                      chip->getHuid(), rank.getKey() );
            break;
        }

        // Check if the chip mark is verified or not.
        bool cmVerified = false;
        o_rc = dqBitmap.isChipMark( chipMark.getSymbol(), cmVerified );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "dqBitmap.isChipMark() failed on 0x%08x "
                      "0x%02x", chip->getHuid(), rank.getKey() );
            break;
        }

        // If the chip mark is unverified, add a VcmEvent to the TD queue.
        if ( !cmVerified )
        {
            // Chip mark is not present in VPD. Add it to queue.
            TdEntry * e = new VcmEvent<TP>{ chip, rank, chipMark };
            MemDbUtils::pushToQueue<TP>( chip, e );

            // We will want to clear the MPE attention for the unverified chip
            // mark so we don't get any redundant attentions for chip marks that
            // are already in the queue. This is reset/reload safe because
            // initialize() will be called again and we can redetect the
            // unverified chip marks.
            SCAN_COMM_REGISTER_CLASS * reg = __getEccFirAnd<TP>( chip );
            reg->setAllBits();
            reg->ClearBit(  0 + rank.getMaster() ); // fetch
            reg->ClearBit( 20 + rank.getMaster() ); // scrub
            o_rc = reg->Write();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "Write() failed on ECC FIR AND: 0x%08x",
                          chip->getHuid() );
                break;
            }
        }
    }

    return o_rc;

    #undef PRDF_FUNC
}

template<>
uint32_t MemTdCtlr<TYPE_OCMB_CHIP>::initialize()
{
    #define PRDF_FUNC "[MemTdCtlr<TYPE_OCMB_CHIP>::initialize] "

    uint32_t o_rc = SUCCESS;

    do
    {
        if ( iv_initialized ) break; // nothing to do

        // Unmask the fetch attentions just in case there were masked during a
        // TD procedure prior to a reset/reload.
        o_rc = unmaskEccAttns();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "unmaskEccAttns() failed" );
            break;
        }

        // Find all unverified chip marks.
        o_rc = __findChipMarks<TYPE_OCMB_CHIP>( iv_rankList );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "__findChipMarks() failed on 0x%08x",
                      iv_chip->getHuid() );
            break;
        }

        // At this point, the TD controller is initialized.
        iv_initialized = true;

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t MemTdCtlr<TYPE_OCMB_CHIP>::handleRrFo()
{
    #define PRDF_FUNC "[MemTdCtlr<TYPE_OCMB_CHIP>::handleRrFo] "

    uint32_t o_rc = SUCCESS;

    do
    {
        // Check if maintenance command complete attention is set.
        SCAN_COMM_REGISTER_CLASS * mcbistfir =
                                iv_chip->getRegister("MCBISTFIR");
        o_rc = mcbistfir->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on MCBISTFIR");
            break;
        }

        // If there is a command complete attention, nothing to do, break out.
        if ( mcbistfir->IsBitSet(10) )
            break;


        // Check if a command is not running.
        // If bit 0 of MCB_CNTLSTAT is on, a mcbist run is in progress.
        SCAN_COMM_REGISTER_CLASS * mcb_cntlstat =
            iv_chip->getRegister("MCB_CNTLSTAT");
        o_rc = mcb_cntlstat->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on MCB_CNTLSTAT" );
            break;
        }

        // If a command is not running, set command complete attn, break.
        if ( !mcb_cntlstat->IsBitSet(0) )
        {
            SCAN_COMM_REGISTER_CLASS * mcbistfir_or =
                iv_chip->getRegister("MCBISTFIR_OR");
            mcbistfir_or->SetBit( 10 );

            mcbistfir_or->Write();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "Write() failed on MCBISTFIR_OR" );
            }
            break;
        }

        // Check if there are unverified chip marks.
        std::vector<TdRankListEntry> vectorList = iv_rankList.getList();

        for ( auto & entry : vectorList )
        {
            ExtensibleChip * ocmbChip = entry.getChip();
            MemRank rank = entry.getRank();

            // Get the chip mark
            MemMark chipMark;
            o_rc = MarkStore::readChipMark<TYPE_OCMB_CHIP>( ocmbChip, rank,
                                                            chipMark );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "readChipMark<TYPE_OCMB_CHIP>(0x%08x,%d) "
                          "failed", ocmbChip->getHuid(), rank.getMaster() );
                break;
            }

            if ( !chipMark.isValid() ) continue; // no chip mark present

            // Get the DQ Bitmap data.
            MemDqBitmap dqBitmap;

            o_rc = getBadDqBitmap( ocmbChip->getTrgt(), rank, dqBitmap );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "getBadDqBitmap(0x%08x, %d)",
                          ocmbChip->getHuid(), rank.getMaster() );
                break;
            }

            // Check if the chip mark is verified or not.
            bool cmVerified = false;
            o_rc = dqBitmap.isChipMark( chipMark.getSymbol(), cmVerified );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "dqBitmap.isChipMark failed." );
                break;
            }

            // If there are any unverified chip marks, stop the command, break.
            if ( !cmVerified )
            {
                o_rc = stopBgScrub<TYPE_OCMB_CHIP>( iv_chip );
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC "stopBgScrub<TYPE_OCMB_CHIP>(0x%08x) "
                              "failed", iv_chip->getHuid() );
                }
                break;
            }
        }

    } while (0);

    return o_rc;
    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t MemTdCtlr<TYPE_OCMB_CHIP>::canResumeBgScrub( bool & o_canResume,
        STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemTdCtlr<TYPE_OCMB_CHIP>::canResumeBgScrub] "

    uint32_t o_rc = SUCCESS;

    o_canResume = false;

    // It is possible that we were running a TD procedure and the PRD service
    // was reset. Therefore, we must check if background scrubbing was actually
    // configured. There really is not a good way of doing this. A scrub command
    // is a scrub command the only difference is the speed. Unfortunately, that
    // speed can change depending on how the hardware team tunes it. For now, we
    // can use the stop conditions, which should be unique for background scrub,
    // to determine if it has been configured.

    do
    {
        SCAN_COMM_REGISTER_CLASS * reg = iv_chip->getRegister( "MBSTR" );
        o_rc = reg->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on MBSTR: iv_chip=0x%08x",
                    iv_chip->getHuid() );
            break;
        }
        // Note: The stop conditions for background scrubbing can now be
        // variable depending on whether we have hit threshold for the number
        // of UEs or CEs that we have stopped on on a rank.

        // If we haven't hit CE or UE threshold, check the CE stop conditions
        if ( !getOcmbDataBundle(iv_chip)->iv_ceStopCounter.thReached(io_sc) &&
             !getOcmbDataBundle(iv_chip)->iv_ueStopCounter.thReached(io_sc) )
        {
            // If the stop conditions aren't set, just break out.
            if ( !(0xf != reg->GetBitFieldJustified(0,4) && // NCE int TH
                   0xf != reg->GetBitFieldJustified(4,4) && // NCE soft TH
                   0xf != reg->GetBitFieldJustified(8,4)) ) // NCE hard TH
            {
                break;
            }

        }

        // If we haven't hit UE threshold yet, check the UE stop condition
        if ( !getOcmbDataBundle(iv_chip)->iv_ueStopCounter.thReached(io_sc) )
        {
            // If the stop condition isn't set, just break out
            if ( !reg->IsBitSet(35) ) // pause on UE
            {
                break;
            }
        }

        // Need to check the stop on mpe stop condition regardless of whether
        // we hit the UE or CE threshold.
        if ( reg->IsBitSet(34) ) // pause on MPE
        {
            // If we reach here, all the stop conditions are set for background
            // scrub, so we can resume.
            o_canResume = true;
        }
    }while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

// Avoid linker errors with the template.
template class MemTdCtlr<TYPE_OCMB_CHIP>;

//------------------------------------------------------------------------------

} // end namespace PRDF


