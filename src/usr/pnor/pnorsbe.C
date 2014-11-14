/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/pnorsbe.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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
 *  @file pnorsbe.C
 *
 *  @brief Implements PNOR::getSbeBootSeeprom(), which Determines which
 *         Seeprom was used to boot the SB
 */

#include <pnor/pnorif.H>
#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <devicefw/userif.H>

extern trace_desc_t* g_trac_pnor;

namespace PNOR
{

//Used to read SBE Boot Side from processor
const uint64_t SBE_VITAL_REG_0x0005001C = 0x005001C;
const uint64_t SBE_BOOT_SELECT_MASK = 0x0080000000000000;

errlHndl_t getSbeBootSeeprom(TARGETING::Target* i_target,
                             sbeSeepromSide_t& o_bootSide)
{
    TRACFCOMP( g_trac_pnor, ENTER_MRK"PNOR::getSbeBootSeeprom()" );

    errlHndl_t err = NULL;
    uint64_t scomData = 0x0;

    o_bootSide = SBE_SEEPROM0;

    do{

        size_t op_size = sizeof(scomData);
        err = deviceRead( i_target,
                          &scomData,
                          op_size,
                          DEVICE_SCOM_ADDRESS(SBE_VITAL_REG_0x0005001C) );
        if( err )
        {
            TRACFCOMP( g_trac_pnor, ERR_MRK"PNOR::getSbeBootSeeprom() -Error "
                       "reading SBE VITAL REG (0x%.8X) from Target :"
                       "HUID=0x%.8X",
                       SBE_VITAL_REG_0x0005001C,
                       TARGETING::get_huid(i_target));
            break;
        }
        if(scomData & SBE_BOOT_SELECT_MASK)
        {
            o_bootSide = SBE_SEEPROM1;
        }

    }while(0);

    TRACFCOMP( g_trac_pnor,
               EXIT_MRK"PNOR::getSbeBootSeeprom(): o_bootSide=0x%X (reg=0x%X)",
               o_bootSide, scomData );

    return err;
}

} // end namespace