/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/sfc_memboot_ast2400.C $                          */
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
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <sys/time.h>
#include <lpc/lpcif.H>
#include "sfc_ast2400.H"
#include "sfc_memboot_ast2400.H"
#include <util/align.H>
#include <devicefw/driverif.H>
#include "pnor_common.H"

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
SfcMembootAST2400::SfcMembootAST2400( errlHndl_t& o_err,
                        TARGETING::Target* i_proc )
: SfcAST2400(o_err,i_proc)
{
}

/**
 * @brief Write data into flash
 */
errlHndl_t SfcMembootAST2400::writeFlash( uint32_t i_addr,
                                   size_t i_size,
                                   void* i_data )
{
    errlHndl_t l_err = NULL;
    TRACDCOMP( g_trac_pnor, ENTER_MRK"SfcMembootAST2400::writeFlash> i_addr=0x%.8x, i_size=0x%.8x", i_addr, i_size );

    do{
        uint32_t* word_ptr = static_cast<uint32_t*>(i_data);
        uint32_t word_size = (ALIGN_4(i_size))/4;
        for( uint32_t words_write = 0;
             words_write < word_size;
             words_write ++ )
        {
            //Write directly to the MMIO space
            uint32_t lpc_addr = PNOR::LPC_SFC_MMIO_OFFSET |
                                (i_addr + words_write*4);
            size_t reg_size = sizeof(uint32_t);

            l_err = deviceOp( DeviceFW::WRITE,
                              iv_proc,
                              &(word_ptr[words_write]),
                              reg_size,
                              DEVICE_LPC_ADDRESS(LPC::TRANS_FW,
                                                 lpc_addr) );
            if( l_err ) {  break; }
        }
        if( l_err ) {  break; }
    }while(0);

    TRACDCOMP( g_trac_pnor, EXIT_MRK"SfcMembootAST2400::writeFlash> err=%.8X", ERRL_GETEID_SAFE(l_err) );
    return l_err;
}


/**
 * @brief Erase a block of flash
 */
errlHndl_t SfcMembootAST2400::eraseFlash( uint32_t i_addr )
{
    errlHndl_t l_err = NULL;
    TRACDCOMP( g_trac_pnor, ENTER_MRK"SfcMembootAST2400::eraseFlash> Block 0x%.8X", i_addr );

    do{
        uint32_t zero = 0;
        uint32_t word_size = (ALIGN_4(iv_eraseSizeBytes))/4;
        for( uint32_t words_write = 0;
             words_write < word_size;
             words_write ++ )
        {
            //Write directly to MMIO space
            uint32_t lpc_addr = PNOR::LPC_SFC_MMIO_OFFSET |
                                (i_addr + words_write*4);
            size_t reg_size = sizeof(uint32_t);

            l_err = deviceOp( DeviceFW::WRITE,
                              iv_proc,
                              &zero,
                              reg_size,
                              DEVICE_LPC_ADDRESS(LPC::TRANS_FW,
                                                 lpc_addr) );
            if( l_err ) {  break; }
        }
        if( l_err ) {  break; }
    }while(0);

    TRACDCOMP( g_trac_pnor, EXIT_MRK"SfcMembootAST2400::eraseFlash> err=%.8X", ERRL_GETEID_SAFE(l_err) );
    return l_err;
}

/**
 * @brief Send a SPI command
 */
errlHndl_t SfcMembootAST2400::sendSpiCmd( uint8_t i_opCode,
                                   uint32_t i_address,
                                   size_t i_writeCnt,
                                   const uint8_t* i_writeData,
                                   size_t i_readCnt,
                                   uint8_t* o_readData )
{
    errlHndl_t l_err = NULL;
    TRACDCOMP( g_trac_pnor, EXIT_MRK"SfcMembootAST2400::sendSpiCmd> o_readData=%.2X, err=%.8X", o_readData == NULL ? 0 : o_readData[0], ERRL_GETEID_SAFE(l_err) );
    return l_err;
}
