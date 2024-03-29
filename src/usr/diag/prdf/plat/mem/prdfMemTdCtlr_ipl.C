/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemTdCtlr_ipl.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2024                        */
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
#include <prdfMemExtraSig.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
uint32_t MemTdCtlr<T>::initialize()
{
    #define PRDF_FUNC "[MemTdCtlr::initialize] "

    uint32_t o_rc = SUCCESS;

    do
    {
        if ( iv_initialized ) break; // nothing to do

        // Check if broadcast mode is capable on this chip.
        iv_broadcastModeCapable = isBroadcastModeCapable<T>( iv_chip );

        // At this point, the TD controller is initialized.
        iv_initialized = true;

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
uint32_t MemTdCtlr<T>::defaultStep( STEP_CODE_DATA_STRUCT & io_sc,
                                    const MemAddr & i_addr )
{
    #define PRDF_FUNC "[MemTdCtlr::defaultStep] "

    uint32_t o_rc = SUCCESS;

    TdRankListEntry nextRank = iv_rankList.getNext( iv_stoppedRank,
                                                    iv_broadcastModeCapable );

    do
    {
        if ( nextRank <= iv_stoppedRank ) // The command made it to the end.
        {
            PRDF_TRAC( PRDF_FUNC "The TD command made it to the end of "
                       "memory on chip: 0x%08x", iv_chip->getHuid() );

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
            PRDF_TRAC( PRDF_FUNC "There is still memory left to test. "
                       "Calling startSfRead<T>(0x%08x, m%ds%d, %x)",
                       nextRank.getChip()->getHuid(),
                       nextRank.getRank().getMaster(),
                       nextRank.getRank().getSlave(),
                       nextRank.getPort() );

            // Start a super fast command to the end of memory.
            o_rc = startSfRead<T>( nextRank.getChip(), nextRank.getRank(),
                                   nextRank.getPort() );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "startSfRead<T>(0x%08x,m%ds%d,%x) failed",
                          nextRank.getChip()->getHuid(),
                          nextRank.getRank().getMaster(),
                          nextRank.getRank().getSlave(),
                          nextRank.getPort() );
                break;
            }
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
bool __mnfgCeCheck( uint32_t i_eccAttns );

template<> inline
bool __mnfgCeCheck<TYPE_OCMB_CHIP>( uint32_t i_eccAttns )
{
    return ( (  0 != (i_eccAttns & MAINT_HARD_NCE_ETE) ) &&
             ( (0 != (i_eccAttns & MAINT_NCE)) ||
               (0 != (i_eccAttns & MAINT_TCE))         ) );
}

template <TARGETING::TYPE T>
uint32_t MemTdCtlr<T>::checkEcc( ExtensibleChip * i_chip,
                                 const MemAddr & i_addr, bool & o_errorsFound,
                                 STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemTdCtlr::checkEcc] "

    uint32_t o_rc = SUCCESS;

    o_errorsFound = true; // Assume true for unless nothing found.

    TargetHandle_t trgt = i_chip->getTrgt();
    HUID           huid = i_chip->getHuid();

    MemRank rank = i_addr.getRank();

    do
    {
        // Check for ECC errors.
        uint32_t eccAttns = 0;
        o_rc = checkEccFirs<T>( i_chip, i_addr.getPort(), eccAttns );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "checkEccFirs<T>(0x%08x, %x) failed", huid,
                      i_addr.getPort() );
            break;
        }

        if ( 0 != (eccAttns & MAINT_UE) )
        {
            // Add the signature to the multi-signature list. Also, since
            // this will be a predictive callout, change the primary
            // signature as well.
            io_sc.service_data->AddSignatureList( trgt, PRDFSIG_MaintUE );
            io_sc.service_data->setSignature(     huid, PRDFSIG_MaintUE );

            // Do memory UE handling.
            o_rc = MemEcc::handleMemUe<T>( i_chip, i_addr, UE_TABLE::SCRUB_UE,
                                           io_sc );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "handleMemUe<T>(0x%08x) failed",
                          i_chip->getHuid() );
                break;
            }
        }
        // For Odyssey, AUEs found during IPL/memdiags will be handled during
        // command complete analysis. Pause on AUE will be set in the superfast
        // reads for memdiags.
        else if ( 0 != (eccAttns & MAINT_AUE) )
        {
            // Add the signature to the multi-signature list. Also, since
            // this will be a predictive callout, change the primary
            // signature as well.
            io_sc.service_data->AddSignatureList( trgt, PRDFSIG_MaintAUE );
            io_sc.service_data->setSignature(     huid, PRDFSIG_MaintAUE );

            // Do memory UE handling.
            MemEcc::handleOdyMaintAue(i_chip, i_addr, io_sc);
        }
        else if ( 0 != (eccAttns & MAINT_MPE) )
        {
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
        else if ( isMfgCeCheckingEnabled() && __mnfgCeCheck<T>(eccAttns) )
        {
            io_sc.service_data->AddSignatureList( trgt, PRDFSIG_MaintHARD_CTE );

            // Add a TPS procedure to the queue.
            TdEntry * e = new TpsEvent<T>{ i_chip, rank, i_addr.getPort() };
            MemDbUtils::pushToQueue<T>( i_chip, e );
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

// Avoid linker errors with the template.
template class MemTdCtlr<TYPE_OCMB_CHIP>;

//------------------------------------------------------------------------------

} // end namespace PRDF

