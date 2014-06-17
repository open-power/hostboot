/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/sfc_fake.H $                                     */
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
#ifndef __PNOR_SFCFAKE_H
#define __PNOR_SFCFAKE_H

#include <limits.h>
#include <targeting/common/targetservice.H>
#include <errl/errlentry.H>
#include "sfcdd.H"

/** @file sfc_fake.H
 *  @brief Provides the logic to access an emulated PNOR
 *     model using mainstore as a proxy for flash
 */

/**
 *  @brief  Fake SFC Device Driver Class
 *    Provides the logic to access an emulated PNOR
 *    model using mainstore as a proxy for flash
 */
class SfcFake : public SfcDD
{

  public: //SfcDD methods
    /**
     * @brief Initialize the SFC Hardware
     *
     * @return void
     */
    virtual errlHndl_t hwInit();

    /**
     * @brief Read data from the PNOR flash
     *
     * @parm i_addr  PNOR flash Address to read
     * @parm i_size  Amount of data to read, in bytes.
     * @parm o_data  Buffer to read data into
     *
     * @return Error from operation
     */
    virtual errlHndl_t readFlash(uint32_t i_addr,
                                 size_t i_size,
                                 void* o_data);

    /**
     * @brief Write data to the PNOR flash
     *
     * @parm i_addr  PNOR flash Address to write
     * @parm i_size  Amount of data to write, in bytes.
     * @parm i_data  Buffer containing data to write
     *
     * @return Error from operation
     */
    virtual errlHndl_t writeFlash(uint32_t i_addr,
                                  size_t i_size,
                                  void* i_data);

    /**
     * @brief Erase a block of flash
     *
     * @parm i_address  Offset into flash to erase, aligned to erase block
     *
     * @return Error from operation
     */
    virtual errlHndl_t eraseFlash(uint32_t i_address);

    /**
     * @brief Send a user-defined SPI command
     *
     * @parm[in] i_opCode: command to send into controller first
     * @parm[in] i_address: address for those commands that need it
     * @parm[in] i_writeCnt: number of bytes to write to device
     * @parm[in] i_writeData: write data buffer
     * @parm[in] i_readCnt: number of bytes to read from device
     * @parm[out] o_readData: read data buffer
     *
     * @return Error from operation
     */
    virtual errlHndl_t sendSpiCmd( uint8_t i_opCode,
                                   uint32_t i_address,
                                   size_t i_writeCnt,
                                   const uint8_t* i_writeData,
                                   size_t i_readCnt,
                                   uint8_t* o_readData );

    /**
     * @brief Informs caller if PNORDD is using
     *        L3 Cache for fake PNOR or not.
     *
     * @return Indicate state of fake PNOR
     *         true = using L3 Cache for fake PNOR
     *         false = not using L3 Cache for fake PNOR
     */
    virtual bool usingL3Cache( void );

    /**
     * @brief Return first 3 bytes of NOR chip id
     *
     * @parm[out]  NOR chip id
     *
     * @return Error from operation
     */
    virtual errlHndl_t getNORChipId( uint32_t& o_chipId );

  public:
    /**
     * @brief Constructor
     * @param[out]  Return any error in constructor
     * @param[in]  Processor target associated with the LPC master
     */
    SfcFake( errlHndl_t& o_err,
             TARGETING::Target* i_proc
             = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL );


  protected:
    /**
     * @brief Pointer to fake memory location
     */
    uint8_t* iv_fakePnor;

    /**
     * @brief Size of allocated PNOR space in bytes
     */
    size_t iv_sizeBytes;
};

#endif
