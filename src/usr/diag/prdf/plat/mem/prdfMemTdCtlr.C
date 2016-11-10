/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemTdCtlr.C $                  */
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

#include <prdfMemTdCtlr.H>

#include <prdfMemAddress.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//------------------------------------------------------------------------------

template<>
uint32_t MemTdCtlr<TYPE_MCBIST>::initStoppedRank()
{
    #define PRDF_FUNC "[initStoppedRank] "

    uint32_t o_rc = SUCCESS;

    do
    {
        // Get all ports in which the command was run. In broadcast mode, the
        // rank configuration for all ports will be the same. In non-broadcast
        // mode, there will only be one MCA in the list. Therefore, we can
        // simply use the first MCA in the list for all configs.
        std::vector<ExtensibleChip *> portList;
        o_rc = getMcbistMaintPort( iv_chip, portList );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMcbistMaintPort(0x%08x) failed",
                      iv_chip->getHuid() );
            break;
        }

        // Get the rank in which the command stopped.
        MemAddr addr;
        o_rc = getMemMaintAddr<TYPE_MCBIST>( iv_chip, addr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemMaintAddr<TYPE_MCBIST>(0x%08x) failed",
                      iv_chip->getHuid() );
            break;
        }

        // Update iv_stoppedRank.
        iv_stoppedRank = TdRankListEntry ( portList.front(), addr.getRank() );
        #ifndef __HOSTBOOT_RUNTIME
        // Update iv_broadcastMode.
        iv_broadcastMode = ( 1 < portList.size() );
        #endif

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t MemTdCtlr<TYPE_MBA>::initStoppedRank()
{
    #define PRDF_FUNC "[initStoppedRank] "

    uint32_t o_rc = SUCCESS;

    do
    {
        // Get the rank in which the command stopped.
        MemAddr addr;
        o_rc = getMemMaintAddr<TYPE_MBA>( iv_chip, addr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemMaintAddr<TYPE_MBA>(0x%08x) failed",
                      iv_chip->getHuid() );
            break;
        }

        // Update iv_stoppedRank.
        iv_stoppedRank = TdRankListEntry( iv_chip, addr.getRank() );

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

} // end namespace PRDF

