/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemTdCtlr_rt.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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

// Framework includes
#include <prdfRegisterCache.H>
#include <UtilHash.H>

// Platform includes
#include <prdfMemEccAnalysis.H>
#include <prdfMemScrubUtils.H>
#include <prdfMemTps.H>
#include <prdfMemUtils.H>
#include <prdfMemVcm.H>
#include <prdfP9McaDataBundle.H>
#include <prdfP9McaExtraSig.H>
#include <prdfPlatServices.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
void __recaptureRegs( STEP_CODE_DATA_STRUCT & io_sc, ExtensibleChip * i_chip );

template<>
void __recaptureRegs<TYPE_MCBIST>( STEP_CODE_DATA_STRUCT & io_sc,
                                   ExtensibleChip * i_chip )
{
    #define PRDF_FUNC "[__recaptureRegs<TYPE_MCBIST>] "

    RegDataCache & cache = RegDataCache::getCachedRegisters();
    CaptureData & cd = io_sc.service_data->GetCaptureData();

    // refresh and recapture the mcb registers
    const char * mcbRegs[] =
    {
        "MCBISTFIR", "MBSEC0", "MBSEC1", "MCB_MBSSYMEC0",
        "MCB_MBSSYMEC1", "MCB_MBSSYMEC2", "MCB_MBSSYMEC3",
        "MCB_MBSSYMEC4", "MCB_MBSSYMEC5", "MCB_MBSSYMEC6",
        "MCB_MBSSYMEC7", "MCB_MBSSYMEC8", "MBSMSEC", "MCBMCAT",
    };

    for ( uint32_t i = 0; i < sizeof(mcbRegs)/sizeof(char*); i++ )
    {
        SCAN_COMM_REGISTER_CLASS * reg =
            i_chip->getRegister( mcbRegs[i] );
        cache.flush( i_chip, reg );
    }

    i_chip->CaptureErrorData( cd, Util::hashString("MaintCmdRegs_mcb") );

    // refresh and recapture the mca registers
    const char * mcaRegs[] =
    {
        "MCAECCFIR",
    };

    ExtensibleChipList mcaList = getConnected( i_chip, TYPE_MCA );

    for ( auto & mca : mcaList )
    {
        for ( uint32_t i = 0; i < sizeof(mcaRegs)/sizeof(char*); i++ )
        {
            SCAN_COMM_REGISTER_CLASS * reg = mca->getRegister( mcaRegs[i] );
            cache.flush( mca, reg );
        }
        mca->CaptureErrorData( cd, Util::hashString("MaintCmdRegs_mca") );
    }

    #undef PRDF_FUNC
}

template<>
void __recaptureRegs<TYPE_MBA>( STEP_CODE_DATA_STRUCT & io_sc,
                                ExtensibleChip * i_chip )
{
    #define PRDF_FUNC "[__recaptureRegs<TYPE_MBA>] "

    RegDataCache & cache = RegDataCache::getCachedRegisters();
    ExtensibleChip * membChip = getConnectedParent( i_chip, TYPE_MEMBUF );
    TargetHandle_t mbaTrgt = i_chip->GetChipHandle();
    uint32_t mbaPos = getTargetPosition( mbaTrgt );

    const char * membRegs[2][15] =
    {
        { "MBA0_MBSECCFIR", "MBA0_MBSECCERRPT_0","MBA0_MBSECCERRPT_1",
          "MBA0_MBSEC0", "MBA0_MBSEC1", "MBA0_MBSTR",
          "MBA0_MBSSYMEC0", "MBA0_MBSSYMEC1", "MBA0_MBSSYMEC2",
          "MBA0_MBSSYMEC3", "MBA0_MBSSYMEC4", "MBA0_MBSSYMEC5",
          "MBA0_MBSSYMEC6", "MBA0_MBSSYMEC7", "MBA0_MBSSYMEC8", },
        { "MBA1_MBSECCFIR", "MBA1_MBSECCERRPT_0","MBA1_MBSECCERRPT_1",
          "MBA1_MBSEC0", "MBA1_MBSEC1", "MBA1_MBSTR",
          "MBA1_MBSSYMEC0", "MBA1_MBSSYMEC1", "MBA1_MBSSYMEC2",
          "MBA1_MBSSYMEC3", "MBA1_MBSSYMEC4", "MBA1_MBSSYMEC5",
          "MBA1_MBSSYMEC6", "MBA1_MBSSYMEC7", "MBA1_MBSSYMEC8", },
    };
    for ( uint32_t i = 0; i < 15; i++ )
    {
        SCAN_COMM_REGISTER_CLASS * reg
            = membChip->getRegister( membRegs[mbaPos][i] );
        cache.flush( membChip, reg );
    }

    const char * mbaRegs[] =
    {
        "MBASPA", "MBMCT", "MBMSR", "MBMACA", "MBMEA", "MBASCTL", "MBAECTL",
    };
    for ( uint32_t i = 0; i < sizeof(mbaRegs)/sizeof(char*); i++ )
    {
        SCAN_COMM_REGISTER_CLASS * reg = i_chip->getRegister( mbaRegs[i] );
        cache.flush( i_chip, reg );
    }

    // Now recapture those registers.

    CaptureData & cd = io_sc.service_data->GetCaptureData();

    if ( 0 == mbaPos )
    {
        membChip->CaptureErrorData(cd, Util::hashString("MaintCmdRegs_mba0") );
    }
    else
    {
        membChip->CaptureErrorData(cd, Util::hashString("MaintCmdRegs_mba1") );
    }
    i_chip->CaptureErrorData(cd, Util::hashString("MaintCmdRegs"));

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
uint32_t MemTdCtlr<T>::handleTdEvent( STEP_CODE_DATA_STRUCT & io_sc,
                                      TdEntry * i_entry )
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

        // Add this entry to the queue.
        iv_queue.push( i_entry );

        // Don't interrupt a TD procedure if one is already in progress.
        if ( nullptr != iv_curProcedure ) break;

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
        __recaptureRegs<T>( io_sc, iv_chip );

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

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <>
uint32_t MemTdCtlr<TYPE_MBA>::initialize()
{
    #define PRDF_FUNC "[MemTdCtlr<TYPE_MBA>::initialize] "

    uint32_t o_rc = SUCCESS;

    do
    {
        if ( iv_initialized ) break; // nothing to do

        // Add any unverified chip marks to the TD queue.

        std::vector<TdRankListEntry> vectorList = iv_rankList.getList();

        for ( auto & entry : vectorList )
        {
            ExtensibleChip * mbaChip = entry.getChip();
            MemRank rank = entry.getRank();

            // Call readChipMark to get MemMark.
            MemMark chipMark;
            o_rc = MarkStore::readChipMark<TYPE_MBA>( mbaChip, rank, chipMark );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "readChipMark<TYPE_MBA>(0x%08x,%d) "
                        "failed", mbaChip->getHuid(), rank.getMaster() );
                break;
            }

            if ( !chipMark.isValid() ) continue; // no chip mark present

            // Get the DQ Bitmap data.
            TargetHandle_t mbaTrgt = mbaChip->GetChipHandle();
            MemDqBitmap<DIMMS_PER_RANK::MBA> dqBitmap;

            o_rc = getBadDqBitmap<DIMMS_PER_RANK::MBA>(mbaTrgt, rank, dqBitmap);
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "getBadDqBitmap<DIMMS_PER_RANK::MBA>"
                        "(0x%08x, %d)", getHuid(mbaTrgt), rank.getMaster() );
                break;
            }

            // Check if the chip mark is verified or not.
            bool cmVerified = false;
            o_rc = dqBitmap.isChipMark( chipMark.getSymbol(), cmVerified );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "dqBitmap.isChipMark() failed." );
                break;
            }

            // If the chip mark is unverified, add a VcmEvent to the TD queue
            if ( !cmVerified )
            {
                TdEntry * vcmEntry = new VcmEvent<TYPE_MBA>( mbaChip, rank,
                        chipMark );
                iv_queue.push( vcmEntry );
            }
        }

        // At this point, the TD controller is initialized.
        iv_initialized = true;
    }while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <>
uint32_t MemTdCtlr<TYPE_MCBIST>::initialize()
{
    #define PRDF_FUNC "[MemTdCtlr<TYPE_MCBIST>::initialize] "

    uint32_t o_rc = SUCCESS;

    do
    {
        if ( iv_initialized ) break; // nothing to do

        // Add any unverified chip marks to the TD queue.

        std::vector<TdRankListEntry> vectorList = iv_rankList.getList();

        for ( auto & entry : vectorList )
        {
            ExtensibleChip * mcaChip = entry.getChip();
            MemRank rank = entry.getRank();

            // Call readChipMark to get MemMark.
            MemMark chipMark;
            o_rc = MarkStore::readChipMark<TYPE_MCA>( mcaChip, rank, chipMark );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "readChipMark<TYPE_MCA>(0x%08x,%d) "
                        "failed", mcaChip->getHuid(), rank.getMaster() );
                break;
            }

            if ( !chipMark.isValid() ) continue; // no chip mark present

            // Get the DQ Bitmap data.
            TargetHandle_t mcaTrgt = mcaChip->GetChipHandle();
            MemDqBitmap<DIMMS_PER_RANK::MCA> dqBitmap;

            o_rc = getBadDqBitmap<DIMMS_PER_RANK::MCA>(mcaTrgt, rank, dqBitmap);
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "getBadDqBitmap<DIMMS_PER_RANK::MCA>"
                        "(0x%08x, %d)", getHuid(mcaTrgt), rank.getMaster() );
                break;
            }

            // Check if the chip mark is verified or not.
            bool cmVerified = false;
            o_rc = dqBitmap.isChipMark( chipMark.getSymbol(), cmVerified );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "dqBitmap.isChipMark() failed." );
                break;
            }

            // If the chip mark is unverified, add a VcmEvent to the TD queue
            if ( !cmVerified )
            {
                TdEntry * vcmEntry = new VcmEvent<TYPE_MCA>( mcaChip, rank,
                        chipMark );
                iv_queue.push( vcmEntry );
            }
        }

        // At this point, the TD controller is initialized.
        iv_initialized = true;
    }while(0);


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

        o_rc = resumeBgScrub<T>( iv_chip );
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

template<TARGETING::TYPE T, typename D>
uint32_t __handleNceEte( ExtensibleChip * i_chip, TdQueue & io_queue,
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

        // Make sure the list size is correct. Note that Nimbus has two symbol
        // correction. So it is possible to have two symbols in the counters
        // even though the threshold is set to 1.
        uint32_t count = symData.size();
        switch ( T )
        {
            case TYPE_MCA: PRDF_ASSERT( 1 <= count && count <= 2 ); break;
            case TYPE_MBA: PRDF_ASSERT( 1 == count               ); break;
            default: PRDF_ASSERT( false );
        }

        for ( auto & d : symData )
        {
            // Add the symbol(s) to the callout list and CE table.
            bool doTps;
            o_rc = MemEcc::handleMemCe<T,D>( i_chip, i_addr, d.symbol, doTps,
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
                io_queue.push( e );
            }
        }
        if ( SUCCESS != o_rc ) break;

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t __handleRceEte( ExtensibleChip * i_chip, bool & o_errorsFound,
                         STEP_CODE_DATA_STRUCT & io_sc );

template<>
uint32_t __handleRceEte<TYPE_MCA>( ExtensibleChip * i_chip,
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
        // MCAECCFIR[37] to determine if there was at least one IUE.
        SCAN_COMM_REGISTER_CLASS * fir = i_chip->getRegister( "MCAECCFIR" );
        o_rc = fir->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on MCAECCFIR: i_chip=0x%08x",
                      i_chip->getHuid() );
            break;
        }
        if ( !fir->IsBitSet(37) ) break; // nothing else to do

        // Handle the IUE.
        o_errorsFound = true;
        io_sc.service_data->AddSignatureList( i_chip->getTrgt(),
                                              PRDFSIG_MaintIUE );
        o_rc = MemEcc::analyzeMaintIue<TYPE_MCA,McaDataBundle *>(i_chip, io_sc);
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

/* TODO RTC 157888
template<>
uint32_t __handleRceEte<TYPE_MBA>( ExtensibleChip * i_chip,
                                   bool & o_errorsFound,
                                   STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[__handleRceEte] "

    uint32_t o_rc = SUCCESS;

    do
    {

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}
*/

//------------------------------------------------------------------------------

template <TARGETING::TYPE T, typename D>
uint32_t __checkEcc( ExtensibleChip * i_chip, TdQueue & io_queue,
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

            o_rc = __handleNceEte<T,D>( i_chip, io_queue, i_addr, io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "__handleNceEte<T,D>(0x%08x) failed",
                          huid );
                break;
            }
        }

        if ( 0 != (eccAttns & MAINT_SOFT_NCE_ETE) )
        {
            o_errorsFound = true;
            io_sc.service_data->AddSignatureList( trgt, PRDFSIG_MaintSOFT_CTE );

            o_rc = __handleNceEte<T,D>( i_chip, io_queue, i_addr, io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "__handleNceEte<T,D>(0x%08x) failed",
                          huid );
                break;
            }
        }

        if ( 0 != (eccAttns & MAINT_HARD_NCE_ETE) )
        {
            o_errorsFound = true;
            io_sc.service_data->AddSignatureList( trgt, PRDFSIG_MaintHARD_CTE );

            o_rc = __handleNceEte<T,D>( i_chip, io_queue, i_addr, io_sc, true );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "__handleNceEte<T,D>(0x%08x) failed",
                          huid );
                break;
            }

            // Any hard CEs in MNFG should be immediately reported.
            if ( mfgMode() )
            {
                io_sc.service_data->setSignature( huid, PRDFSIG_MaintHARD_CTE );
                io_sc.service_data->setServiceCall();
            }
        }

        if ( 0 != (eccAttns & MAINT_MPE) )
        {
            o_errorsFound = true;
            io_sc.service_data->AddSignatureList( trgt, PRDFSIG_MaintMPE );

            // Add entry to UE table.
            D db = static_cast<D>(i_chip->getDataBundle());
            db->iv_ueTable.addEntry( UE_TABLE::SCRUB_MPE, i_addr );

            o_rc = MemEcc::handleMpe<T,D>( i_chip, rank, io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleMpe<T>(0x%08x, 0x%02x) failed",
                          i_chip->getHuid(), rank.getKey() );
                break;
            }
        }

        if ( 0 != (eccAttns & MAINT_RCE_ETE) )
        {
            o_rc = __handleRceEte<T>( i_chip, o_errorsFound, io_sc );
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

            // Add a TPS procedure to the queue.
            TdEntry * e = new TpsEvent<T>{ i_chip, rank };
            io_queue.push( e );
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

template
uint32_t __checkEcc<TYPE_MCA, McaDataBundle *>( ExtensibleChip * i_chip,
                                                TdQueue & io_queue,
                                                const MemAddr & i_addr,
                                                bool & o_errorsFound,
                                                STEP_CODE_DATA_STRUCT & io_sc );

/* TODO RTC 157888
template
uint32_t __checkEcc<TYPE_MBA>( ExtensibleChip * i_chip, TdQueue & io_queue,
                               const MemAddr & i_addr, bool & o_errorsFound,
                               STEP_CODE_DATA_STRUCT & io_sc );
*/

//------------------------------------------------------------------------------

template<>
uint32_t MemTdCtlr<TYPE_MCBIST>::maskEccAttns()
{
    #define PRDF_FUNC "[MemTdCtlr<TYPE_MCBIST>::maskEccAttns] "

    uint32_t o_rc = SUCCESS;

    // Loop through all MCAs.
    for ( auto mcaChip : getConnected(iv_chip, TYPE_MCA) )
    {
        SCAN_COMM_REGISTER_CLASS * mask =
            mcaChip->getRegister( "MCAECCFIR_MASK_OR" );

        mask->clearAllBits();
        mask->SetBit(8); // Mainline read NCE
        mask->SetBit(9); // Mainline read TCE

        o_rc = mask->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Write() failed on MCAECCFIR_MASK_OR" );
            break;
        }
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t MemTdCtlr<TYPE_MCBIST>::unmaskEccAttns()
{
    #define PRDF_FUNC "[MemTdCtlr<TYPE_MCBIST>::unmaskEccAttns] "

    uint32_t o_rc = SUCCESS;

    // Memory CEs were masked at the beginning of the TD procedure, so
    // clear and unmask them. Also, it is possible that memory UEs have
    // thresholded so clear and unmask them as well.

    // Loop through all MCAs.
    for ( auto mcaChip : getConnected(iv_chip, TYPE_MCA) )
    {
        SCAN_COMM_REGISTER_CLASS * fir =
            mcaChip->getRegister( "MCAECCFIR_AND" );
        SCAN_COMM_REGISTER_CLASS * mask =
            mcaChip->getRegister( "MCAECCFIR_MASK_AND" );

        fir->setAllBits(); mask->setAllBits();

        // Do not unmask NCE and TCE attentions if they have been permanently
        // masked due to certain TPS conditions.
        if ( !(getMcaDataBundle(mcaChip)->iv_maskMainlineNceTce) )
        {
            fir->ClearBit(8);  mask->ClearBit(8);  // Mainline read NCE
            fir->ClearBit(9);  mask->ClearBit(9);  // Mainline read TCE
        }
        fir->ClearBit(14); mask->ClearBit(14); // Mainline read UE

        o_rc = fir->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Write() failed on MCAECCFIR_AND" );
            break;
        }

        o_rc = mask->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Write() failed on MCAECCFIR_MASK_AND" );
            break;
        }
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t MemTdCtlr<TYPE_MBA>::maskEccAttns()
{
    #define PRDF_FUNC "[MemTdCtlr<TYPE_MBA>::maskEccAttns] "

    uint32_t o_rc = SUCCESS;

    // TODO RTC 176901
    //do
    //{
    //    // Don't want to handle memory CEs during any TD procedures, so
    //    // mask them.

    //    const char * reg_str = (0 == iv_mbaPos) ? "MBA0_MBSECCFIR_MASK_OR"
    //                                            : "MBA1_MBSECCFIR_MASK_OR";
    //    SCAN_COMM_REGISTER_CLASS * reg = iv_membChip->getRegister(reg_str);

    //    reg->clearAllBits();
    //    reg->SetBit(16); // fetch NCE
    //    reg->SetBit(17); // fetch RCE
    //    reg->SetBit(43); // prefetch UE

    //    o_rc = reg->Write();
    //    if ( SUCCESS != o_rc )
    //    {
    //        PRDF_ERR( PRDF_FUNC "Write() failed on %s", reg_str );
    //        break;
    //    }

    //    iv_fetchAttnsMasked = true;

    //} while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t MemTdCtlr<TYPE_MBA>::unmaskEccAttns()
{
    #define PRDF_FUNC "[MemTdCtlr<TYPE_MBA>::unmaskEccAttns] "

    uint32_t o_rc = SUCCESS;

    // TODO RTC 176901
    //do
    //{
    //    // Memory CEs where masked at the beginning of the TD procedure, so
    //    // clear and unmask them. Also, it is possible that memory UEs have
    //    // thresholded so clear and unmask them as well.

    //    const char * fir_str = (0 == iv_mbaPos) ? "MBA0_MBSECCFIR_AND"
    //                                            : "MBA1_MBSECCFIR_AND";
    //    const char * msk_str = (0 == iv_mbaPos) ? "MBA0_MBSECCFIR_MASK_AND"
    //                                            : "MBA1_MBSECCFIR_MASK_AND";

    //    SCAN_COMM_REGISTER_CLASS * fir = iv_membChip->getRegister( fir_str );
    //    SCAN_COMM_REGISTER_CLASS * msk = iv_membChip->getRegister( msk_str );

    //    fir->setAllBits(); msk->setAllBits();
    //    fir->ClearBit(16); msk->ClearBit(16); // fetch NCE
    //    fir->ClearBit(17); msk->ClearBit(17); // fetch RCE
    //    fir->ClearBit(19); msk->ClearBit(19); // fetch UE
    //    fir->ClearBit(43); msk->ClearBit(43); // prefetch UE

    //    o_rc = fir->Write();
    //    if ( SUCCESS != o_rc )
    //    {
    //        PRDF_ERR( PRDF_FUNC "Write() failed on %s", fir_str );
    //        break;
    //    }

    //    o_rc = msk->Write();
    //    if ( SUCCESS != o_rc )
    //    {
    //        PRDF_ERR( PRDF_FUNC "Write() failed on %s", msk_str );
    //        break;
    //    }

    //    iv_fetchAttnsMasked = false;

    //} while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

// Avoid linker errors with the template.
template class MemTdCtlr<TYPE_MCBIST>;
template class MemTdCtlr<TYPE_MBA>;

//------------------------------------------------------------------------------

} // end namespace PRDF


