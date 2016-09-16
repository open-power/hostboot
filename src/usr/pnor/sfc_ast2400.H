/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/sfc_ast2400.H $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2016                        */
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
#ifndef __PNOR_SFCAST2400_H
#define __PNOR_SFCAST2400_H

#include <limits.h>
#include <targeting/common/targetservice.H>
#include <errl/errlentry.H>
#include "sfcdd.H"
#include "sfc_ast2X00.H"
#include <config.h>

/** @file sfc_ast2400.H
 *  @brief Provides the logic to access and configure the
 *         AST2400 BMC in order to access the PNOR
 */

/**
 *  @brief  AST2400 SFC Device Driver Class
 *    Provides the logic to access and configure the
 *    AST2400 BMC in order to access the PNOR
 */
class SfcAST2400 : public SfcAST2X00
{

  public: //SfcDD methods

    /**
     * @brief Initialize the SFC Hardware
     *
     * @return void
     */
    virtual errlHndl_t hwInit();

    /**
     * @brief Enter/exit command mode
     *
     * @param[in] i_enter: true=enter cmd mode, false=exit cmd mode
     *
     * @return Error from operation
     */
    virtual errlHndl_t commandMode( bool i_enter );

  public:
    /**
     * @brief Constructor
     * @param[out]  Return any error in constructor
     * @param[in]  Processor target associated with the LPC master
     */
    SfcAST2400( errlHndl_t& o_err,
                TARGETING::Target* i_proc
                = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL );

  protected:
    /**
     * @brief List of registers in the SPI Controller logic
     */
    enum SpicReg_t
    {
        CONFREG_00     = 0x00,
        CTLREG_04      = 0x04,
        MISCCTLREG_10  = 0x10,
        READTIMEREG_14 = 0x14
    };

    /**
     * @brief SPI0 Configuration Register
     */
    union SpiConfigReg00_t
    {
        uint32_t data32;
        struct
        {                             //Little-endian bit positions
            uint32_t rsvd            : 30; //31:2
            uint32_t inactiveX2mode  : 1; //1
            uint32_t enableWrite     : 1; //0
        };
        SpiConfigReg00_t() : data32(0) {};
    };

    /**
     * @brief SPI04 Control Register
     */
    union SpiControlReg04_t
    {
        uint32_t data32;
        struct
        {                             //Little-endian bit positions
            uint32_t rsvd            : 2; //31:30
            uint32_t ioMode          : 2; //29:28
            uint32_t pulseWidth      : 4; //27:24
            uint32_t cmdData         : 8; //23:16
            uint32_t dummyCycleCmd   : 1; //15
            uint32_t dummyCycleRead1 : 1; //14
            uint32_t fourByteMode    : 1; //13
            uint32_t disableCmdMerge : 1; //12
            uint32_t spiClkFreq      : 4; //11:8
            uint32_t dummyCycleRead2 : 2; //7:6
            uint32_t lsbFirst        : 1; //5
            uint32_t useClkMode3     : 1; //4
            uint32_t dualInputMode   : 1; //3
            uint32_t stopActiveCtl   : 1; //2
            uint32_t cmdMode         : 2; //1:0
        };
        SpiControlReg04_t() : data32(0) {};
    };

    /**
     * @brief Default value of SPI04 (saves a read)
     */
    SpiControlReg04_t iv_ctlRegDefault;

    friend class SfcAST2400Test;
};

#endif
