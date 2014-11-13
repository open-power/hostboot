/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/sfc_fake.C $                                     */
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
#include "sfc_fake.H"
#include "norflash.H"


/*****************************************************************************/
// C o n s t a n t s
/*****************************************************************************/

// By default we well use the top of the cache 4MB-8MB
#define FAKE_PNOR_START (4*MEGABYTE)
#define FAKE_PNOR_END   (8*MEGABYTE)
#define FAKE_PNOR_SIZE  (FAKE_PNOR_END-FAKE_PNOR_START)




/*****************************************************************************/
// G l o b a l s
/*****************************************************************************/

// Initialized in pnorrp.C
extern trace_desc_t* g_trac_pnor;

/*****************************************************************************/
// M e t h o d s
/*****************************************************************************/

namespace PNOR {
/**
 * @brief Wrapper for device driver constructor
 */
errlHndl_t create_SfcDD( SfcDD*& o_sfc,
                         TARGETING::Target* i_proc )
{
    errlHndl_t l_err = NULL;
    TRACFCOMP( g_trac_pnor, "Creating SfcFake object" );
    o_sfc = new SfcFake( l_err, i_proc );
    return l_err;
}

};

/**
 * @brief Constructor
 */
SfcFake::SfcFake( errlHndl_t& o_err,
                  TARGETING::Target* i_proc )
: SfcDD(o_err,i_proc)
, iv_fakePnor(reinterpret_cast<uint8_t*>(FAKE_PNOR_START))
, iv_sizeBytes(FAKE_PNOR_SIZE)
{
    TRACFCOMP( g_trac_pnor, "Instantiating SfcFake" );
}


/**
 * @brief Read data from the flash
 */
errlHndl_t SfcFake::readFlash( uint32_t i_addr,
                               size_t i_size,
                               void* o_data )
{
    TRACDCOMP( g_trac_pnor, "SfcFake::readFlash> i_addr=0x%.8x, i_size=0x%.8x",
               i_addr, i_size );
    errlHndl_t errhdl = NULL;

    //create a pointer to the offset start.
    uint8_t* srcPtr = reinterpret_cast<uint8_t*>(iv_fakePnor+i_addr);

    if( (srcPtr+i_size) > (iv_fakePnor+iv_sizeBytes) )
    {
        TRACFCOMP(g_trac_pnor, "SfcFake::readFlash> Read goes past end of fake-PNOR : i_addr=0x%X, i_size=0x%X", i_addr, i_size );
        /*@
         * @errortype
         * @moduleid     PNOR::MOD_SFCFAKE_READFLASH
         * @reasoncode   PNOR::RC_INVALID_ADDRESS
         * @userdata1[0:31]  PNOR Address
         * @userdata1[32:63] Bytes to read
         * @userdata2[0:31]  <unused>
         * @userdata2[32:63] Size of allocated PNOR space
         * @devdesc      SfcFake::readFlash> Requested access exceeded the
         *               bounds of the allocated PNOR space
         * @custdesc     Firmware error accessing flash during IPL
         */
        errhdl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         PNOR::MOD_SFCFAKE_READFLASH,
                                         PNOR::RC_INVALID_ADDRESS,
                                         TWO_UINT32_TO_UINT64(i_addr,
                                                              i_size),
                                         TWO_UINT32_TO_UINT64(0,
                                                              iv_sizeBytes),
                                         true /*Software error*/);
    }
    else
    {
        //Read directly from memory
        memcpy( o_data, srcPtr, i_size );
    }

    return errhdl;
}


/**
 * @brief Write data into flash
 */
errlHndl_t SfcFake::writeFlash( uint32_t i_addr,
                                size_t i_size,
                                void* i_data )
{
    TRACDCOMP( g_trac_pnor, "SfcFake::writeFlash> i_addr=0x%.8x, i_size=0x%.8x",
               i_addr, i_size );
    errlHndl_t errhdl = NULL;

    //create a pointer to the offset start.
    uint8_t* destPtr = reinterpret_cast<uint8_t*>(iv_fakePnor+i_addr);

    if( (destPtr+i_size) > (iv_fakePnor+iv_sizeBytes) )
    {
        TRACFCOMP(g_trac_pnor, "SfcFake::writeFlash> Write goes past end of fake-PNOR : i_addr=0x%X, i_size=0x%X", i_addr, i_size );
        /*@
         * @errortype
         * @moduleid     PNOR::MOD_SFCFAKE_WRITEFLASH
         * @reasoncode   PNOR::RC_INVALID_ADDRESS
         * @userdata1[0:31]  PNOR Address
         * @userdata1[32:63] Bytes to write
         * @userdata2[0:31]  <unused>
         * @userdata2[32:63] Size of allocated PNOR space
         * @devdesc      SfcFake::writeFlash> Requested access exceeded the
         *               bounds of the allocated PNOR space
         * @custdesc     Firmware error accessing flash during IPL
         */
        errhdl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         PNOR::MOD_SFCFAKE_WRITEFLASH,
                                         PNOR::RC_INVALID_ADDRESS,
                                         TWO_UINT32_TO_UINT64(i_addr,
                                                              i_size),
                                         TWO_UINT32_TO_UINT64(0,
                                                              iv_sizeBytes),
                                         true /*Software error*/);
    }
    else
    {
        //Write directly to memory
        memcpy( destPtr, i_data, i_size );
    }

    return errhdl;
}


/**
 * @brief Erase a block of flash
 */
errlHndl_t SfcFake::eraseFlash( uint32_t i_addr )
{
    TRACDCOMP( g_trac_pnor, "SfcFake::eraseFlash> i_addr=0x%.8x, i_size=0x%.8x",
               i_addr );
    errlHndl_t errhdl = NULL;

    //create a pointer to the offset start.
    uint8_t* destPtr = reinterpret_cast<uint8_t*>(iv_fakePnor+i_addr);

    if( (destPtr+iv_eraseSizeBytes) > (iv_fakePnor+iv_sizeBytes) )
    {
        TRACFCOMP(g_trac_pnor, "SfcFake::writeFlash> Write goes past end of fake-PNOR : i_addr=0x%X, i_size=0x%X", i_addr );
        /*@
         * @errortype
         * @moduleid     PNOR::MOD_SFCFAKE_ERASEFLASH
         * @reasoncode   PNOR::RC_INVALID_ADDRESS
         * @userdata1[0:31]  PNOR Address
         * @userdata1[32:63] <unused>
         * @userdata2[0:31]  Bytes in erase block
         * @userdata2[32:63] Size of allocated PNOR space
         * @devdesc      SfcFake::writeFlash> Requested access exceeded the
         *               bounds of the allocated PNOR space
         * @custdesc     Firmware error accessing flash during IPL
         */
        errhdl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      PNOR::MOD_SFCFAKE_ERASEFLASH,
                                      PNOR::RC_INVALID_ADDRESS,
                                      TWO_UINT32_TO_UINT64(i_addr,
                                                           0),
                                      TWO_UINT32_TO_UINT64(iv_eraseSizeBytes,
                                                           iv_sizeBytes),
                                      true /*Software error*/);
    }
    else
    {
        //A real erase sets every bit so emulate that with a memset
        memset( destPtr, 0xFF, iv_eraseSizeBytes );
    }

    return errhdl;
}

/**
 * @brief Initialize and configure the SFC hardware
 */
errlHndl_t SfcFake::hwInit( )
{
    TRACFCOMP( g_trac_pnor, "SfcFake::hwInit> Nothing to do here" );
    return NULL;
}

/**
 * @brief Informs caller if PNORDD is using
 *        L3 Cache for fake PNOR or not.
 */
bool SfcFake::usingL3Cache( void )
{
    return true;
}

/**
 * @brief Send a user-defined SPI command
 */
errlHndl_t SfcFake::sendSpiCmd( uint8_t i_opCode,
                                uint32_t i_address,
                                size_t i_writeCnt,
                                const uint8_t* i_writeData,
                                size_t i_readCnt,
                                uint8_t* o_readData )
{
    TRACFCOMP( g_trac_pnor, "SfcFake::sendSpiCmd> Nothing to do here : opcode=%.2X", i_opCode );
    /*@
     * @errortype
     * @moduleid     PNOR::MOD_SFCFAKE_SENDSPICMD
     * @reasoncode   PNOR::RC_UNSUPPORTED_OPERATION
     * @userdata1[0:31]  Op Code
     * @userdata1[32:63] Address
     * @userdata2    <unused>
     * @devdesc      SfcFake::sendSpiCmd> Function is not supported
     * @custdesc     Firmware error accessing flash during IPL
     */
    return new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                   PNOR::MOD_SFCFAKE_SENDSPICMD,
                                   PNOR::RC_UNSUPPORTED_OPERATION,
                                   TWO_UINT32_TO_UINT64(i_opCode,
                                                        i_address),
                                   0,
                                   true /*Software error*/);
}

/**
 * @brief Return first 3 bytes of NOR chip id
 */
errlHndl_t SfcFake::getNORChipId( uint32_t& o_chipId )
{
    o_chipId = PNOR::FAKE_NOR_ID;
    iv_norChipId = PNOR::FAKE_NOR_ID;
    return NULL;
}

