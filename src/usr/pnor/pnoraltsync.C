/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/pnoraltsync.C $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
 *  @file pnoraltsync.C
 *
 *  @brief Implements PNOR::copyPnorPartitionToAlt() to synchronize
 *         partitions between the active and alternate PNORs
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <trace/interface.H>
#include <devicefw/driverif.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <attributeenums.H>
#include "ffs.h"
#include "common/ffs_hb.H"
#include "pnorrp.H"
#include <pnor/pnorif.H>
#include <pnor/pnor_reasoncodes.H>
#include <lpc/lpcif.H>

#if defined(CONFIG_PNORDD_IS_SFC)
#include "pnor_sfcdd.H"
using PnorDD = PnorSfcDD;
#elif (defined(CONFIG_PNORDD_IS_BMCMBOX) || defined(CONFIG_PNORDD_IS_IPMI))
#include "pnor_hiomapdd.H"
using PnorDD = PnorHiomapDD;
#else
#error "No PNOR DD configured"
#endif

extern trace_desc_t* g_trac_pnor;

namespace PNOR
{

/**
 * @brief Copy a given PNOR partition from the active PNOR into the
 *        alternate copy
 */
errlHndl_t copyPnorPartitionToAlt( PNOR::SectionId i_section )
{
    errlHndl_t l_errhdl = nullptr;
    const char* l_sectionName = PNOR::SectionIdToString(i_section);
    TRACFCOMP( g_trac_pnor, ENTER_MRK"PNOR::copyPnorPartitionToAlt(%d=%s)> ",
               i_section, l_sectionName );

    // Algorithm is:
    // 0. Check if there is an alt-pnor to update, exit if not
    // 1. Instantiate an alt-pnordd to access the alternate PNOR.
    // 2. Find the flash offset and full size (including ECC) of the
    //    target section on the active PNOR.
    // 3. Find the flash offset and full size (including ECC) of the
    //    target section on the alternate PNOR.
    // 4. If size+offset match, bulk copy the complete section from
    //    the active PNOR to the alternate.

    PnorDD* altpnordd = nullptr;

    // When reading PNOR TOC assume a single page and no ECC
    uint8_t* tocBuffer = new uint8_t[PAGESIZE];
    const uint64_t toc0_offset = PnorRP::getInstance().getTocOffset(TOC_0);

    do{
        //--------------------------------
        // 0. Check if there is an alt-pnor to update, exit if not

        // Get list of all processors
        TARGETING::TargetHandleList procList;
        TARGETING::getAllChips(procList,
                               TARGETING::TYPE_PROC,
                               true); // true: return functional targets

        if( ( 0 == procList.size() ) ||
            ( nullptr == procList[0] ) )
        {
            TRACFCOMP( g_trac_pnor, INFO_MRK"PNOR::copyPnorPartitionToAlt()> No functional processors Found! Validation skipped" );
            break;
        }

        // Loop through all processors to find the alt-proc
        TARGETING::Target* l_altProc = nullptr;
        for(uint32_t i=0; i<procList.size(); i++)
        {
            // Check if processor is MASTER_CANDIDATE
            TARGETING::ATTR_PROC_MASTER_TYPE_type type_enum =
              procList[i]->getAttr<TARGETING::ATTR_PROC_MASTER_TYPE>();

            if ( type_enum != TARGETING::PROC_MASTER_TYPE_MASTER_CANDIDATE )
            {
                TRACDCOMP( g_trac_pnor, INFO_MRK"PNOR::copyPnorPartitionToAlt> Skipping Processor 0x%X (PROC_MASTER_TYPE=%d)",
                           TARGETING::get_huid(procList[i]), type_enum);
                continue;
            }

            TRACFCOMP( g_trac_pnor, INFO_MRK"PNOR::copyPnorPartitionToAlt> Validating Processor 0x%X (PROC_MASTER_TYPE=%d)",
                       TARGETING::get_huid(procList[i]), type_enum);
            l_altProc = procList[i];
            break;
        }
        if( !l_altProc )
        {
            TRACFCOMP( g_trac_pnor, INFO_MRK"PNOR::copyPnorPartitionToAlt> There are no alternate PNORs to update" );
            break;
        }


        //--------------------------------
        // 1. Instantiate an alt-pnordd to access the alternate PNOR.

        // Create the LPC objects we're going to use
        l_errhdl = LPC::create_altmaster_objects( true, l_altProc );
        if ( l_errhdl )
        {
            // Commit Error Log, but continue the test
            TRACFCOMP( g_trac_pnor, INFO_MRK"PNOR::copyPnorPartitionToAlt> Could not create LPC objects for %.8X.", TARGETING::get_huid(l_altProc) );
            break;
        }

        // Create and initialize custom PNOR DD class for this target
        altpnordd = new PnorDD(l_altProc);


        //--------------------------------
        // 2. Find the flash offset and full size (including ECC) of the
        //    target section on the active PNOR.

        PNOR::SectionInfo_t l_activePnor;
        l_errhdl = PNOR::getSectionInfo(i_section, l_activePnor);
        if( l_errhdl )
        {
            TRACFCOMP( g_trac_pnor, INFO_MRK"PNOR::copyPnorPartitionToAlt> Error getting data for section %d(%s)", i_section, l_sectionName );
            break;
        }
        TRACFCOMP( g_trac_pnor, INFO_MRK"PNOR::copyPnorPartitionToAlt> Section %d(%s) located at 0x%.X for 0x%X bytes", i_section, l_sectionName, l_activePnor.flashAddr, l_activePnor.sizeActual );


        //--------------------------------
        // 3. Find the flash offset and full size (including ECC) of the
        //    target section on the alternate PNOR.

        size_t read_size = PAGESIZE;
        l_errhdl = altpnordd->readFlash(tocBuffer, read_size, toc0_offset);
        if ( l_errhdl )
        {
            TRACFCOMP( g_trac_pnor, INFO_MRK"PNOR::copyPnorPartitionToAlt> readFlash fail for 0x%X.",
                       TARGETING::get_huid(l_altProc) );
            break;
        }

        PNOR::SectionData_t l_altTOC[PNOR::NUM_SECTIONS+1];
        l_errhdl = parseTOC( tocBuffer, l_altTOC );
        if( l_errhdl )
        {
            TRACFCOMP( g_trac_pnor, INFO_MRK"PNOR::copyPnorPartitionToAlt> parseTOC fail for 0x%X.",
                       TARGETING::get_huid(l_altProc) );
            // This can be caused by a genesis boot where the alt side has never been IPLed.
            // Need to just ignore this error and move on.
            l_errhdl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
            errlCommit(l_errhdl,PNOR_COMP_ID);
            break;
        }


        //--------------------------------
        // 4. If size+offset match, bulk copy the complete section from
        //    the active PNOR to the alternate.
        if( l_activePnor.sizeActual != l_altTOC[i_section].size )
        {
            TRACFCOMP( g_trac_pnor, INFO_MRK"PNOR::copyPnorPartitionToAlt> Size mismatch between active (0x%X) and alt (0x%X) sections",
                       l_activePnor.sizeActual,
                       l_altTOC[i_section].size );
            break;
        }

        TRACFCOMP( g_trac_pnor, INFO_MRK"PNOR::copyPnorPartitionToAlt> About to copy 0x%X bytes", l_altTOC[i_section].size );
        // loop through to write a few KB at a time so we don't
        //  need to allocate a giant chunk of memory
        constexpr size_t TRANSFER_SIZE = 4*PAGESIZE;
        uint8_t l_buffer[TRANSFER_SIZE] = {0};
        for( size_t loop = 0; loop < l_altTOC[i_section].size; loop += TRANSFER_SIZE )
        {
            size_t l_readSize = std::min( TRANSFER_SIZE, l_altTOC[i_section].size-loop );

            // read the data off the active pnor
            l_errhdl = DeviceFW::deviceRead(
                  TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                  l_buffer,
                  l_readSize,
                  DEVICE_PNOR_ADDRESS(0,l_activePnor.flashAddr+loop) );
            if( l_errhdl )
            {
                TRACFCOMP( g_trac_pnor, INFO_MRK"PNOR::copyPnorPartitionToAlt> Failed to read 0x%X from active PNOR", loop+l_activePnor.flashAddr );
                break;
            }

            // write the data into the alternate pnor
            l_errhdl = altpnordd->writeFlash(l_buffer,
                                          l_readSize,
                                          l_altTOC[i_section].flashAddr+loop);
            if( l_errhdl )
            {
                TRACFCOMP( g_trac_pnor, INFO_MRK"PNOR::copyPnorPartitionToAlt> Failed to write 0x%X into alternate PNOR", l_altTOC[i_section].flashAddr+loop );
                break;
            }
        }
        if( l_errhdl ) { break; }

    }while(0);

    if( l_errhdl )
    {
        l_errhdl->collectTrace(PNOR_COMP_NAME);
    }

    // Delete PNOR DD class and memory buffer
    if ( altpnordd )
    {
        delete altpnordd;
        altpnordd = nullptr;

        // Delete the LPC objects we used
        errlHndl_t l_errhdl2 = LPC::create_altmaster_objects( false, nullptr );
        if ( l_errhdl2 )
        {
            // Commit Error Log, but don't kill the istep because we can recover from being
            //   out of sync on a later IPL
            TRACFCOMP( g_trac_pnor, INFO_MRK"PNOR::copyPnorPartitionToAlt> Could not delete LPC objects. eid=0x%X, rc=0x%X. Committing log as info", l_errhdl2->eid(), l_errhdl2->reasonCode());

            l_errhdl->collectTrace(PNOR_COMP_NAME);
            l_errhdl2->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
            errlCommit(l_errhdl2,PNOR_COMP_ID);
        }
    }

    if(tocBuffer != nullptr)
    {
        delete[] tocBuffer;
        tocBuffer = nullptr;
    }

    TRACFCOMP( g_trac_pnor, EXIT_MRK"PNOR::copyPnorPartitionToAlt(%d=%s)> ",
               i_section, l_sectionName );
    return l_errhdl;
}



}; //namespace PNOR

