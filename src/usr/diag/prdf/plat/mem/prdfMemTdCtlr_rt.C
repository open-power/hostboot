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

// Platform includes
#include <prdfPlatServices.H>

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

template <TARGETING::TYPE T>
uint32_t MemTdCtlr<T>::initialize()
{
    #define PRDF_FUNC "[MemTdCtlr::initialize] "

    uint32_t o_rc = SUCCESS;

    do
    {
        if ( iv_initialized ) break; // nothing to do

        // Add any unverified chip marks to the TD queue
        // TODO: RTC 136126

        // At this point, the TD controller is initialized.
        iv_initialized = true;

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
uint32_t MemTdCtlr<T>::defaultStep( STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[MemTdCtlr::defaultStep] "

    uint32_t o_rc = SUCCESS;

    TdRankListEntry nextRank = iv_rankList.getNext( iv_stoppedRank );

    do
    {
        PRDF_TRAC( PRDF_FUNC "Resuming background scrub. "
                   "Calling startBgScrub<T>(0x%08x, m%ds%d)",
                   nextRank.getChip()->getHuid(),
                   nextRank.getRank().getMaster(),
                   nextRank.getRank().getSlave() );

        // Restart background scrubbing on the next rank.
        o_rc = startBgScrub<T>( nextRank.getChip(), nextRank.getRank() );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "startBgScrub<T>(0x%08x,m%ds%d) failed",
                      nextRank.getChip()->getHuid(),
                      nextRank.getRank().getMaster(),
                      nextRank.getRank().getSlave() );
            break;
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

    /* TODO: RTC 136126
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
                                                  io_sc, errorsFound );
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
    */

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

    /* TODO: RTC 136126
    MemRank rank = iv_stoppedRank.getRank();

    o_rc = __checkEcc<TYPE_MBA>( iv_chip, rank, iv_queue, io_sc,
                                 o_errorsFound );
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "__checkEcc<TYPE_MBA>(0x%08x,%d) failed",
                  iv_chip->getHuid(), rank.getMaster() );
    }
    */

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <TARGETING::TYPE T>
void MemTdCtlr<T>::collectStateCaptureData( STEP_CODE_DATA_STRUCT & io_sc,
                                            const char * i_startEnd )
{
    #define PRDF_FUNC "[MemTdCtlr<T>::collectStateCaptureData] "

    // TODO RTC 167827

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

// Avoid linker errors with the template.
template class MemTdCtlr<TYPE_MCBIST>;
template class MemTdCtlr<TYPE_MBA>;

//------------------------------------------------------------------------------

} // end namespace PRDF


