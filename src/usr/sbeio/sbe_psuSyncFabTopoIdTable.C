/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_psuSyncFabTopoIdTable.C $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2022                        */
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
/**
* @file sbe_psuSyncFabTopoIdTable.C
* @brief Send the system-wide topology id table to each SBE
*/

#include <errl/errlmanager.H>                  // errlHndl_t
#include <sbeio/sbe_psudd.H>                   // SbePsu::psuCommand
#include <targeting/common/commontargeting.H>  // get_huid
#include <targeting/common/utilFilter.H>       // getAllChips
#include <sbeio/sbeioreasoncodes.H>            // SBEIO_PSU, SBEIO_PSU_SEND
#include <sbeio/sbeioif.H>

extern trace_desc_t* g_trac_sbeio;

namespace SBEIO
{
using namespace TARGETING;

 /** @brief Send Topology ID Table to the SBE
 *
 *  @param[in] i_pProc - The PROC target associated with this SBE
 *  @param[in] i_cmd - Fully formed PSU command to send topology id table
 *  @return nullptr if no error else an error log
 */
errlHndl_t psuSendTopologyIdTable(const TargetHandle_t i_pProc,
                                  SbePsu::psuCommand i_cmd)
{
    errlHndl_t l_err(nullptr);

    // Validate and verify that the target passed in is indeed a PROC
    assert( TYPE_PROC == i_pProc->getAttr<ATTR_TYPE>(),
            "Expected a target of type PROC but received a target of type 0x%.4X",
            i_pProc->getAttr<ATTR_TYPE>() );

    TRACFCOMP(g_trac_sbeio, ENTER_MRK"psuSendTopologyIdTable: PROC target HUID 0x%.8X",
                            get_huid(i_pProc) );

    do
    {
        // Create a PSU response message
        SbePsu::psuResponse l_psuResponse;

        bool command_unsupported = false;

        // Make the call to perform the PSU Chip Operation
        l_err = SbePsu::getTheInstance().performPsuChipOp(
                        i_pProc,
                        &i_cmd,
                        &l_psuResponse,
                        SbePsu::MAX_PSU_SHORT_TIMEOUT_NS,
                        SbePsu::SBE_TOPOLOGY_TABLE_REQ_USED_REGS,
                        SbePsu::SBE_TOPOLOGY_TABLE_RSP_USED_REGS,
                        SbePsu::COMMAND_SUPPORT_OPTIONAL,
                        &command_unsupported);

        if (l_err)
        {
            TRACFCOMP( g_trac_sbeio, ERR_MRK"psuSendTopologyIdTable: ERROR: "
                       "Call to performPsuChipOp failed, error returned" );

            break;
        }
        else if ( command_unsupported )
        {
            TRACFCOMP( g_trac_sbeio, WARN_MRK"psuSendTopologyIdTable: WARNING: SBE firmware "
                       "does not support PSU sending Topology ID Table" );
            break;
        }
        else if (SBE_PRI_OPERATION_SUCCESSFUL != l_psuResponse.primaryStatus)
        {
            TRACFCOMP( g_trac_sbeio, ERR_MRK"psuSendTopologyIdTable: ERROR: Call to performPsuChipOp failed on Proc %.8X. Returned primary status (0x%.4X) and secondary status (0x%.4X)",
                       TARGETING::get_huid(i_pProc),
                       l_psuResponse.primaryStatus,
                       l_psuResponse.secondaryStatus);

            /*@
             * @errortype        ERRL_SEV_PREDICTIVE
             * @moduleid         SBEIO_PSUSYNCFABTOPOIDTABLE
             * @reasoncode       SBEIO_PSU_SEND
             * @userdata1        The PROC Target HUID
             * @userdata2[00:31] PSU response, primary status
             * @userdata2[32:63] PSU response, secondary status
             * @devdesc          Software problem, call to performPsuChipOp failed
             *                   when sending Topology Id Table
             * @custdesc         A software error occurred during system boot
             */
            l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                             SBEIO_PSUSYNCFABTOPOIDTABLE,
                                             SBEIO_PSU_SEND,
                                             get_huid(i_pProc),
                                             TWO_UINT32_TO_UINT64(
                                                         l_psuResponse.primaryStatus,
                                                         l_psuResponse.secondaryStatus ),
                                             ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

            // Collect the entire command and response buffers
            TRACFBIN(g_trac_sbeio,
                     "Topology Id Table full command:",
                     &i_cmd, sizeof(i_cmd));
            TRACFBIN(g_trac_sbeio,
                     "Topology Id Table full response:",
                     &l_psuResponse, sizeof(l_psuResponse));

            break;
        }


    } while (0);


    TRACFCOMP(g_trac_sbeio, EXIT_MRK "psuSendTopologyIdTable");

    return l_err;
}; // psuSendTopologyIdTable


errlHndl_t psuSendTopologyIdTable( void )
{
    errlHndl_t l_errl = nullptr;

    do {
        // Use the same table for all procs
        auto l_topoTable = UTIL::assertGetToplevelTarget()
          ->getAttrAsStdArr<ATTR_PROC_FABRIC_TOPOLOGY_ID_TABLE>();
        TRACFBIN(g_trac_sbeio,
                 "psuSendTopologyIdTable> ATTR_PROC_FABRIC_TOPOLOGY_ID_TABLE",
                 l_topoTable.data(),
                 l_topoTable.size());

        // Create a PSU command message to be used for each proc
        SbePsu::psuCommand l_psuCommand(
                    SbePsu::SBE_REQUIRE_RESPONSE |
                    SbePsu::SBE_REQUIRE_ACK,          // control flags
                    SbePsu::SBE_PSU_GENERIC_MESSAGE,  // command class (0xD7)
                    SbePsu::SBE_PSU_TOPOLOGY_ID_TABLE); // command (0x0A)

        // Allocate and align memory due to SBE requirements
        SBEIO::sbeAllocationHandle_t l_topoTableBuffer = sbeMalloc
          (l_topoTable.size());

        // Copy data from attribute into aligned memory
        memcpy( l_topoTableBuffer.dataPtr,
                l_topoTable.data(),
                l_topoTable.size() );

        // Fill in all of the required fields
        l_psuCommand.cd7_syncFabTopoIdTable_Address
          = l_topoTableBuffer.physAddr;
        l_psuCommand.cd7_syncFabTopoIdTable_Length
          = l_topoTable.size();

        // Make sure we don't exceed the data size that the SBE expects
        constexpr size_t TABLE_LENGTH = 32;
        static_assert( l_topoTable.size() == TABLE_LENGTH );

        // Loop through all functional procs to send to each SBE
        TargetHandleList l_procList;
        TARGETING::getAllChips(l_procList,
                               TARGETING::TYPE_PROC);
        for( auto l_proc : l_procList )
        {
            l_errl = psuSendTopologyIdTable( l_proc,
                                             l_psuCommand );
            if( l_errl )
            {
                break;
            }
        }
        sbeFree( l_topoTableBuffer );
        if( l_errl ) { break; }

    } while(0);

    return l_errl;
}

} // namespace SBEIO
