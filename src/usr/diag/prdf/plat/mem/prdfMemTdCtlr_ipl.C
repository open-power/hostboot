/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemTdCtlr_ipl.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
#include <prdfMemScrubUtils.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

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

// Avoid linker errors with the template.
template class MemTdCtlr<TYPE_MCBIST>;
template class MemTdCtlr<TYPE_MBA>;

//------------------------------------------------------------------------------

} // end namespace PRDF

