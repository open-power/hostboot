/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/nor_micron.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
/* [+] Google Inc.                                                        */
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
#include "norflash.H"
#include "sfcdd.H"
#include <pnor/pnor_reasoncodes.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errlreasoncodes.H>

// Initialized in pnorrp.C
extern trace_desc_t* g_trac_pnor;


namespace PNOR {

/**
 * @brief Check the version of the part to see if it has any
 *        known errors that require a workaround.
 */
errlHndl_t micronCheckForWorkarounds( SfcDD* i_sfc,
                                      uint32_t& o_workarounds )
{
    errlHndl_t l_err = NULL;

    do {
        // Assume all Micron chips have this bug
        o_workarounds |= HWWK_MICRON_EXT_READ;

        // HW workaround - run this command before reading out chipid
        l_err = micronFlagStatus( i_sfc );
        if(l_err) { delete l_err; }

        uint32_t outdata[4];

        //Read back full 6 bytes of chipid
        l_err = i_sfc->sendSpiCmd( PNOR::SPI_JEDEC_CHIPID,
                                   SfcDD::NO_ADDRESS,
                                   0, NULL,
                                   6, reinterpret_cast<uint8_t*>(outdata) );
        if(l_err) { break; }

        //If bit 1 (indicates 45nm new part) is set in 2nd word of cmd buffer
        //  data, then we do not need the workaround.
        //Ex: CCCCCCLL 40000000
        //    CCCCCC -> Industry Standard Chip ID
        //    LL -> Length of Micron extended data
        //    4 -> Bit to indicate we do not need the erase/write workaround
        TRACFCOMP( g_trac_pnor, "micronCheckForWorkarounds> ExtId = %.8X %.8X", outdata[0], outdata[1] );
        if((outdata[1] & 0x40000000) == 0x00000000)
        {
            TRACFCOMP( g_trac_pnor, "micronCheckForWorkarounds> Setting Micron workaround flag" );
            //Set Micron workaround flag
            o_workarounds |= HWWK_MICRON_WRT_ERASE;
        }

        //Prove this works
        l_err = micronFlagStatus( i_sfc );
        if(l_err) { delete l_err; }

    } while(0);

    return l_err;
}

/**
 * @brief Check flag status bit on Micron NOR chips
 *        Some versions of Micron parts require the Flag
 *        Status register be read after a write or erase operation,
 *        otherwise all future operations won't work..
 */
errlHndl_t micronFlagStatus( SfcDD* i_sfc )
{
    errlHndl_t l_err = NULL;
    TRACDCOMP( g_trac_pnor, "micronFlagStatus>" );

    do {
        //Read Micron 'flag status' register
        uint8_t flagstat = 0;
        l_err = i_sfc->sendSpiCmd( SPI_MICRON_FLAG_STAT,
                                   SfcDD::NO_ADDRESS,
                                   0, NULL,
                                   sizeof(flagstat), &flagstat );
        if(l_err) { break; }

        TRACDCOMP(g_trac_pnor,
                  "micronFlagStatus> (0x%.2X)",
                  flagstat);

        // check for ready and no errors
        // bit 0 = ready, bit 2=erase fail, bit 3=Program (Write) failure
        if( (flagstat & 0xB0) != 0x80)
        {
            TRACFCOMP(g_trac_pnor, "micronFlagStatus> Error or timeout from Micron Flag Status Register (0x%.2X)", flagstat);

            //Read back full 6 bytes of chipid
            uint32_t outdata[2];
            l_err = i_sfc->sendSpiCmd( PNOR::SPI_JEDEC_CHIPID,
                                       SfcDD::NO_ADDRESS,
                                       0, NULL,
                                       6, reinterpret_cast<uint8_t*>(outdata) );
            if( l_err ) { delete l_err; }

            /*@
             * @errortype
             * @moduleid     PNOR::MOD_NORMICRON_MICRONFLAGSTATUS
             * @reasoncode   PNOR::RC_MICRON_INCOMPLETE
             * @userdata1[0:31]   Micron Flag status register
             * @userdata2    NOR Flash Chip ID
             * @devdesc      micronFlagStatus> Error or timeout from
             *               Micron Flag Status Register
             * @custdesc     Hardware error accessing flash during IPL
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        PNOR::MOD_NORMICRON_MICRONFLAGSTATUS,
                                        PNOR::RC_MICRON_INCOMPLETE,
                                        TWO_UINT32_TO_UINT64(flagstat,0),
                                        TWO_UINT32_TO_UINT64(outdata[0],
                                                             outdata[1]) );

            // Limited in callout: no PNOR target, so calling out processor
            l_err->addHwCallout(
                           TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                           HWAS::SRCI_PRIORITY_HIGH,
                           HWAS::NO_DECONFIG,
                           HWAS::GARD_NULL );
            i_sfc->addFFDC(l_err);

            //Read out SFDP
            uint8_t sfdp[16];
            l_err = i_sfc->sendSpiCmd( PNOR::SPI_JEDEC_READ_SFDP,
                                       0,
                                       0, NULL,
                                       16, sfdp );
            if( l_err )
            {
                delete l_err;
            }
            else
            {
                //@fixme-RTC:115212 - Create userdetails class
                l_err->addFFDC( PNOR_COMP_ID,
                                sfdp,
                                sizeof(sfdp),
                                0, // Version
                                ERRORLOG::ERRL_UDT_NOFORMAT,
                                false );             // merge
            }

            //Erase & Program error bits are sticky,
            // so they need to be cleared.
            uint8_t flagstat = 0;
            errlHndl_t tmp_err = i_sfc->sendSpiCmd( SPI_MICRON_CLRFLAG_STAT,
                                                    SfcDD::NO_ADDRESS,
                                                    sizeof(flagstat),
                                                    &flagstat,
                                                    0,
                                                    NULL );
            if(tmp_err)
            {
                //commit this error and return the original
                tmp_err->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                tmp_err->plid(l_err->plid());
                ERRORLOG::errlCommit(tmp_err,PNOR_COMP_ID);
            }

            l_err->collectTrace(PNOR_COMP_NAME);

            break;
        }


    }while(0);

    return l_err;

}


};//namespace PNOR
