/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemTdCtlr_ipl.C $              */
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

/** @file  prdfMemTdCtlr_ipl.C
 *  @brief A state machine for memory Targeted Diagnostics (IPL only).
 */

#include <prdfMemTdCtlr.H>

// Platform includes
#include <prdfMemEccAnalysis.H>
#include <prdfMemMark.H>
#include <prdfMemoryMru.H>
#include <prdfMemScrubUtils.H>
#include <prdfMemUtils.H>
#include <prdfMemVcm.H>
#include <prdfP9McaExtraSig.H>
#include <UtilHash.H> // for Util::hashString

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
uint32_t MemTdCtlr<T>::handleTdEvent( STEP_CODE_DATA_STRUCT & io_sc,
                                      TdEntry * i_entry )
{
    #define PRDF_FUNC "[MemTdCtlr::handleTdEvent] "

    // Add this entry to the queue.
    iv_queue.push( i_entry );

    return SUCCESS;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
uint32_t MemTdCtlr<T>::defaultStep( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemTdCtlr::defaultStep] "

    uint32_t o_rc = SUCCESS;

    TdRankListEntry nextRank = iv_rankList.getNext( iv_stoppedRank,
                                                    iv_broadcastMode );

    do
    {
        if ( nextRank <= iv_stoppedRank ) // The command made it to the end.
        {
            // Clear all of the counters and maintenance ECC attentions. This
            // must be done before telling MDIA the command is done. Otherwise,
            // we may run into a race condition where MDIA may start the next
            // command and it completes before PRD clears the FIR bits for this
            // attention.
            o_rc = prepareNextCmd<T>( iv_chip );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "prepareNextCmd<T>(0x%08x) failed",
                          iv_chip->getHuid() );
                break;
            }

            // The command reached the end of memory. Send a message to MDIA.
            o_rc = mdiaSendEventMsg(iv_chip->getTrgt(), MDIA::COMMAND_COMPLETE);
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "mdiaSendEventMsg(0x%08x,COMMAND_COMPLETE) "
                          "failed", iv_chip->getHuid() );
                break;
            }
        }
        else // There is memory left to test.
        {
            // Start a super fast command to the end of memory.
            o_rc = startSfRead<T>( nextRank.getChip(), nextRank.getRank() );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "startSfRead<T>(0x%08x,%d) failed",
                          nextRank.getChip()->getHuid(),
                          nextRank.getRank().getMaster() );
                break;
            }
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
uint32_t __checkEcc( ExtensibleChip * i_chip, const MemRank & i_rank,
                     TdQueue & io_queue, bool & o_errorsFound,
                     STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[__checkEcc] "

    uint32_t o_rc = SUCCESS;

    o_errorsFound = true; // Assume true for unless nothing found.

    TargetHandle_t trgt = i_chip->getTrgt();
    HUID           huid = i_chip->getHuid();

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

        if ( 0 != (eccAttns & MAINT_UE) )
        {
            // Add the signature to the multi-signature list. Also, since
            // this will be a predictive callout, change the primary
            // signature as well.
            io_sc.service_data->AddSignatureList( trgt, PRDFSIG_MaintUE );
            io_sc.service_data->setSignature(     huid, PRDFSIG_MaintUE );

            // Add the rank to the callout list.
            MemEcc::calloutMemUe<T>( i_chip, i_rank, io_sc );

            // Make the error log predictive.
            io_sc.service_data->setServiceCall();
        }
        else if ( 0 != (eccAttns & MAINT_MPE) )
        {
            io_sc.service_data->AddSignatureList( trgt, PRDFSIG_MaintMPE );

            // Read the chip mark from markstore.
            MemMark chipMark;
            o_rc = MarkStore::readChipMark<T>( i_chip, i_rank, chipMark );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "readChipMark<T>(0x%08x,%d) failed",
                          huid, i_rank.getMaster() );
                break;
            }

            // If the chip mark is not valid, then somehow the chip mark was
            // placed on a rank other than the rank in which the command
            // stopped. This would most likely be a code bug.
            PRDF_ASSERT( chipMark.isValid() );

            // Add the mark to the callout list.
            MemoryMru mm { trgt, i_rank, chipMark.getSymbol() };
            io_sc.service_data->SetCallout( mm );

            // Add a new VCM procedure to the queue.
            TdEntry * e = new VcmEvent<T>{ i_chip, i_rank, chipMark };
            io_queue.push( e );
        }
        else if ( isMfgCeCheckingEnabled() &&
                  (0 != (eccAttns & MAINT_HARD_NCE_ETE)) )
        {
            io_sc.service_data->AddSignatureList( trgt, PRDFSIG_MaintHARD_CTE );

            // Query the per-symbol counters for the hard CE symbol.
            MemUtils::MaintSymbols symData; MemSymbol junk;
            o_rc = MemUtils::collectCeStats<T>( i_chip, i_rank, symData, junk );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "MemUtils::collectCeStats(0x%08x,m%ds%d) "
                          "failed", i_chip->GetId(), i_rank.getMaster(),
                          i_rank.getSlave() );
                break;
            }

            // The command will have finished at the end of the rank so there
            // may be more than one symbol. Add all to the callout list.
            for ( auto & s : symData )
            {
                MemoryMru memmru ( trgt, i_rank, s.symbol );
                io_sc.service_data->SetCallout( memmru );
            }

            // Add a TPS procedure to the queue.
            TdEntry * e = new TpsEvent<T>{ i_chip, i_rank };
            io_queue.push( e );
        }
        else // Nothing found.
        {
            o_errorsFound = false;
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <>
uint32_t MemTdCtlr<TYPE_MCBIST>::checkEcc( bool & o_errorsFound,
                                           STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemTdCtlr<TYPE_MCBIST>::checkEcc] "

    uint32_t o_rc = SUCCESS;

    o_errorsFound = false;

    MemRank rank = iv_stoppedRank.getRank();

    do
    {
        // Get all ports in which the command was run.
        std::vector<ExtensibleChip *> portList;
        o_rc = getMcbistMaintPort( iv_chip, portList );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMcbistMaintPort(0x%08x) failed",
                      iv_chip->getHuid() );
            break;
        }

        // Check each MCA for ECC errors.
        for ( auto & mcaChip : portList )
        {
            bool errorsFound;
            uint32_t l_rc = __checkEcc<TYPE_MCA>( mcaChip, rank, iv_queue,
                                                  errorsFound, io_sc );
            if ( SUCCESS != l_rc )
            {
                PRDF_ERR( PRDF_FUNC "__checkEcc<TYPE_MCA>(0x%08x,%d) failed",
                          mcaChip->getHuid(), rank.getMaster() );
                o_rc |= l_rc; continue; // Try the other MCAs.
            }

            if ( errorsFound ) o_errorsFound = true;
        }
        if ( SUCCESS != o_rc ) break;

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <>
uint32_t MemTdCtlr<TYPE_MBA>::checkEcc( bool & o_errorsFound,
                                        STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemTdCtlr<TYPE_MBA>::checkEcc] "

    uint32_t o_rc = SUCCESS;

    o_errorsFound = false;

    MemRank rank = iv_stoppedRank.getRank();

    o_rc = __checkEcc<TYPE_MBA>( iv_chip, rank, iv_queue, o_errorsFound, io_sc);
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "__checkEcc<TYPE_MBA>(0x%08x,%d) failed",
                  iv_chip->getHuid(), rank.getMaster() );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
void MemTdCtlr<T>::collectStateCaptureData( STEP_CODE_DATA_STRUCT & io_sc,
                                            const char * i_startEnd )
{
    #define PRDF_FUNC "[MemTdCtlr<T>::collectStateCaptureData] "

    // Get the number of entries in the TD queue (limit 15)
    TdQueue::Queue queue = iv_queue.getQueue();
    uint8_t queueCount = queue.size();
    if ( 15 < queueCount ) queueCount = 15;

    // Get the buffer
    uint32_t bitLen = 22 + queueCount*10; // Header + TD queue
    BitStringBuffer bsb( bitLen );
    uint32_t curPos = 0;

    //######################################################################
    // Header data (18 bits)
    //######################################################################

    // Specifies running at IPL. Also ensures our data is non-zero. 4-bit
    bsb.setFieldJustify( curPos, 4, TD_CTLR_DATA::Version::IPL ); curPos+=4;

    uint8_t mrnk  = 0;
    uint8_t srnk  = 0;
    uint8_t phase = TdEntry::Phase::TD_PHASE_0;
    uint8_t type  = TdEntry::TdType::INVALID_EVENT;

    if ( nullptr != iv_curProcedure )
    {
        mrnk  = iv_curProcedure->getRank().getMaster(); // 3-bit
        srnk  = iv_curProcedure->getRank().getSlave();  // 3-bit
        phase = iv_curProcedure->getPhase();            // 4-bit
        type  = iv_curProcedure->getType();             // 4-bit
    }

    bsb.setFieldJustify( curPos, 3, mrnk  ); curPos+=3;
    bsb.setFieldJustify( curPos, 3, srnk  ); curPos+=3;
    bsb.setFieldJustify( curPos, 4, phase ); curPos+=4;
    bsb.setFieldJustify( curPos, 4, type  ); curPos+=4;

    //######################################################################
    // TD Request Queue (min 4 bits, max 164 bits)
    //######################################################################

    bsb.setFieldJustify( curPos, 4, queueCount ); curPos+=4; // 4-bit

    for ( uint32_t n = 0; n < queueCount; n++ )
    {
        uint8_t itMrnk = queue[n]->getRank().getMaster(); // 3-bit
        uint8_t itSrnk = queue[n]->getRank().getSlave();  // 3-bit
        uint8_t itType = queue[n]->getType();             // 4-bit

        bsb.setFieldJustify( curPos, 3, itMrnk ); curPos+=3;
        bsb.setFieldJustify( curPos, 3, itSrnk ); curPos+=3;
        bsb.setFieldJustify( curPos, 4, itType ); curPos+=4;
    }

    //######################################################################
    // Add the capture data
    //######################################################################
    CaptureData & cd = io_sc.service_data->GetCaptureData();
    cd.Add( iv_chip->getTrgt(), Util::hashString(i_startEnd), bsb );


    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

// Avoid linker errors with the template.
template class MemTdCtlr<TYPE_MCBIST>;
template class MemTdCtlr<TYPE_MBA>;

//------------------------------------------------------------------------------

} // end namespace PRDF

