/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/sfcdd.C $                                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <sys/mmio.h>
#include <sys/task.h>
#include <sys/sync.h>
#include <string.h>
#include <devicefw/driverif.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludlogregister.H>
#include <targeting/common/targetservice.H>
#include <pnor/pnor_reasoncodes.H>
#include <sys/time.h>
#include <lpc/lpcif.H>
#include "sfcdd.H"
#include "norflash.H"


/*****************************************************************************/
// C o n s t a n t s
/*****************************************************************************/




/*****************************************************************************/
// G l o b a l s
/*****************************************************************************/

// Initialized in pnorrp.C
extern trace_desc_t* g_trac_pnor;


/*****************************************************************************/
// M e t h o d s
/*****************************************************************************/

/**
 * @brief Constructor
 */
SfcDD::SfcDD( errlHndl_t& o_err,
              TARGETING::Target* i_proc )
: iv_proc(i_proc)
, iv_flashWorkarounds(PNOR::HWWK_NO_WORKAROUNDS)
, iv_norChipId(PNOR::UNKNOWN_NOR_ID)
, iv_eraseSizeBytes(4*KILOBYTE) //default to 4KB blocks
{
    o_err = NULL;
}

/**
 * @brief Destructor
 */
SfcDD::~SfcDD()
{
    // Nothing to do by default
}

/**
 * @brief Read the NOR FLash ChipID
 */
errlHndl_t SfcDD::getNORChipId(uint32_t& o_chipId)
{
    errlHndl_t l_err = NULL;

    if( iv_norChipId == PNOR::UNKNOWN_NOR_ID )
    {
        o_chipId = 0;
        l_err = sendSpiCmd( PNOR::SPI_JEDEC_CHIPID,
                            SfcDD::NO_ADDRESS,
                            0, NULL,
                            4, reinterpret_cast<uint8_t*>(&o_chipId) );
        if( !l_err )
        {
            // Only look at first 3 bytes of chipid
            iv_norChipId = o_chipId & PNOR::ID_MASK;
        }
    }

    o_chipId = iv_norChipId;
    TRACFCOMP( g_trac_pnor, "SfcDD::getNORChipId> chipid=%.8X", o_chipId );
    return l_err;
}

/**
 * @brief Informs caller if PNORDD is using
 *        L3 Cache for fake PNOR or not.
 */
bool SfcDD::usingL3Cache( void )
{
    // by default we are not using the L3
    return false;
}
