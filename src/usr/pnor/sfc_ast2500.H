/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/sfc_ast2500.H $                                  */
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
#ifndef __PNOR_SFCAST2500_H
#define __PNOR_SFCAST2500_H

#include <limits.h>
#include <targeting/common/targetservice.H>
#include <errl/errlentry.H>
#include "sfcdd.H"
#include "sfc_ast2X00.H"
#include <config.h>

/** @file sfc_ast2500.H
 *  @brief Provides the logic to access and configure the
 *         AST2500 BMC in order to access the PNOR
 */

/**
 *  @brief  AST2500 SFC Device Driver Class
 *    Provides the logic to access and configure the
 *    AST2500 BMC in order to access the PNOR
 */
class SfcAST2500 : public SfcAST2X00
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
    SfcAST2500( errlHndl_t& o_err,
                TARGETING::Target* i_proc
                = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL );

  protected:
    /**
     * @brief List of registers in the SPI Controller logic
     */
    enum SpicReg_t
    {
        CONFREG_00           = 0x00, //SPIR00
        CE_CTLREG_04         = 0x04, //SPIR04
        INTRPCTLSTATUSREG_08 = 0x08, //SPIR08
        COMMANDCTRLREG_0C    = 0x0C, //SPIR0C
        CE0_CTRLREG_10       = 0x10, //SPIR10
        CE1_CTRLREG_14       = 0x14, //SPIR14
        READTIMEREG_94       = 0x94, //SPIR94
    };

    /**
     * @brief SPI0 Configuration Register
     */
    union SpiConfigReg00_t
    {
        uint32_t data32;
        struct
        {                             //Little-endian bit positions
            uint32_t rsvd            : 14; //31:18
            uint32_t enableCE1Write  : 1;  //17
            uint32_t enableCE0Write  : 1;  //16
            uint32_t rsvd2           : 16; //15:0
        };
        SpiConfigReg00_t() : data32(0) {};
    };

    /**
     * @brief SPI04 CE Control Register
     */
    union SpiCEControlReg04_t
    {
        uint32_t data32;
        struct
        {                             //Little-endian bit positions
            uint32_t ceSwapControl   : 1;  //31
            uint32_t rsvd            : 21; //30:10
            uint32_t enableCE1Div2   : 1;  //9
            uint32_t enableCE0Div2   : 1;  //8
            uint32_t rsvd2           : 6;  //7:2
            uint32_t fourByteModeCE1 : 1;  //1
            uint32_t fourByteModeCE0 : 1;  //0
        };
        SpiCEControlReg04_t() : data32(0) {};
    };

    /**
     * @brief SPI10 CE0 Control Register
     */
    union SpiCE0ControlReg10_t
    {
        uint32_t data32;
        struct
        {                              //Little-endian bit positions
            uint32_t rsvd              : 2; //31:30
            uint32_t ioMode            : 2; //29:28
            uint32_t pulseWidth        : 4; //27:24
            uint32_t cmdData           : 8; //23:16
            uint32_t dummyCycleCmd     : 1; //15
            uint32_t dummyCycleRead1   : 1; //14
            uint32_t spiClkDivide4Mode : 1; //13
            uint32_t disableCmdMerge   : 1; //12
            uint32_t spiClkFreq        : 4; //11:8
            uint32_t dummyCycleRead2   : 2; //7:6
            uint32_t lsbFirst          : 1; //5
            uint32_t useClkMode3       : 1; //4
            uint32_t dualInputMode     : 1; //3
            uint32_t stopActiveCtl     : 1; //2
            uint32_t cmdMode           : 2; //1:0
        };
        SpiCE0ControlReg10_t() : data32(0) {};
    };

    /**
     * @brief Default value of SPI10 (saves a read)
     */
    SpiCE0ControlReg10_t iv_ctlRegCE0Default;

    /**
     * @brief SPI14 CE1 Control Register
     */
    union SpiCE1ControlReg14_t
    {
        uint32_t data32;
        struct
        {                              //Little-endian bit positions
            uint32_t rsvd              : 2; //31:30
            uint32_t ioMode            : 2; //29:28
            uint32_t pulseWidth        : 4; //27:24
            uint32_t cmdData           : 8; //23:16
            uint32_t dummyCycleCmd     : 1; //15
            uint32_t dummyCycleRead1   : 1; //14
            uint32_t spiClkDivide4Mode : 1; //13
            uint32_t disableCmdMerge   : 1; //12
            uint32_t spiClkFreq        : 4; //11:8
            uint32_t dummyCycleRead2   : 2; //7:6
            uint32_t lsbFirst          : 1; //5
            uint32_t useClkMode3       : 1; //4
            uint32_t dualInputMode     : 1; //3
            uint32_t stopActiveCtl     : 1; //2
            uint32_t cmdMode           : 2; //1:0
        };
        SpiCE1ControlReg14_t() : data32(0) {};
    };

    /**
     * @brief Default value of SPI14 (saves a read)
     */
    SpiCE1ControlReg14_t iv_ctlRegCE1Default;

    friend class SfcAST2500Test;
};

#endif
