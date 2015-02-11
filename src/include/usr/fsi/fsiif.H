/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fsi/fsiif.H $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2015                        */
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

#ifndef __FSI_FSIIF_H
#define __FSI_FSIIF_H

#include <stdint.h>
#include <builtins.h>
#include <errl/errlentry.H>

namespace FSI
{

/**
 * @brief Initialize the FSI hardware
 *
 * @return errlHndl_t  NULL on success
 */
errlHndl_t initializeHardware();


/**
 * @brief Retrieves the status of a given port
 *
 * @param[in] i_fsiMaster  FSI Master chip
 * @param[in] i_type  FSI Master Type (MFSI or cMFSI)
 * @param[in] i_port  Slave port number
 * 
 * @return bool  true if port sensed as active during FSI initialization
 */
bool isSlavePresent( TARGETING::Target* i_fsiMaster,
                     TARGETING::FSI_MASTER_TYPE i_type,
                     uint8_t i_port );

/**
 * @brief Retrieves the FSI status of a given chip
 *
 * @param[in] i_target
 * 
 * @return bool  true if port sensed as active during FSI initialization
 */
bool isSlavePresent( TARGETING::Target* i_target );


/**
 *  Enum defining type of FFDC to collect
 */
enum fsiFFDCType_t
{
    FFDC_PRESENCE_FAIL   = 0,
    FFDC_READWRITE_FAIL  = 1,
    FFDC_PIB_FAIL        = 2,
    FFDC_OPB0_FAIL       = 3,
    FFDC_OPB1_FAIL       = 4,
    FFDC_OPB_FAIL_SLAVE  = 5,
};

/**
 * @brief Add FFDC for the target to an error log
 *
 * @param[in] i_ffdc_type   Type of FFDC to add
 * @param[in/out] i_log     Error Log to add FFDC to
 * @param[in] i_target     Chip Target, for OPB_FAIL this should
 *    be the FSI Master, otherwise it should be the target of
 *    the FSI operation (i.e. the FSI Slave)
 *
 * @return void
 */
void getFsiFFDC( fsiFFDCType_t       i_ffdc_type,
                 errlHndl_t          &io_log,
                 TARGETING::Target*  i_target );

/**
 * @brief Cleanup the FSI PIB2OPB logic on the procs
 *
 * @param[in] i_target  Proc Chip Target to reset
 *
 * @return errlHndl_t  NULL on success
 */
errlHndl_t resetPib2Opb( TARGETING::Target* i_target );

/**
 * @brief Structure which defines info necessary to access a chip via FSI
 */
struct FsiLinkInfo_t
{
    TARGETING::Target* master; ///< FSI Master
    TARGETING::FSI_MASTER_TYPE type; ///< Master or Cascaded Master
    uint8_t link; ///< Which link is this chip hanging off of
    uint8_t cascade; ///< Slave cascade position
    uint8_t mPort; ///< FSI Master port (0=A,1=B)
    uint32_t baseAddr; ///< Base FSI Address for this chip

    FsiLinkInfo_t() :
      master(NULL), type(TARGETING::FSI_MASTER_TYPE_NO_MASTER),
    link(0xFF), cascade(0), mPort(0), baseAddr(UINT32_MAX)
    {};
};

/**
 * @brief Retrieve some FSI attribute information
 *
 * @param[in] i_slave  Slave Chip Target to query
 * @param[out] o_info  FSI Link Information
 */
void getFsiLinkInfo( TARGETING::Target* i_slave,
                     FsiLinkInfo_t& o_info );


/**
 * FSI Slave Registers for P8
 *   These registers are repeated for every master+port+cascade combo 
 */
enum SlaveRegistersP8
{
    // Local FSI Space
    SLAVE_CFG_TABLE  = 0x000000, /**< Configuration Table of CFAM */
    SLAVE_PEEK_TABLE = 0x000400, /**< Peek Table */

    SLAVE_REGS       = 0x000800, /**< FSI Slave Register */
    SMODE_00         = SLAVE_REGS|0x00,
    SLBUS_30         = SLAVE_REGS|0x30,
    SLRES_34         = SLAVE_REGS|0x34,

    FSI_SHIFT_ENGINE = 0x000C00, /**< FSI Shift Engine (SCAN) */

    FSI2PIB_ENGINE   = 0x001000, /**< FSI2PIB Engine (SCOM) */
    FSI2PIB_RESET    = FSI2PIB_ENGINE|0x18, /**< see 1006 */
    FSI2PIB_STATUS   = FSI2PIB_ENGINE|0x1C, /**< see 1007 */
    FSI2PIB_COMPMASK = FSI2PIB_ENGINE|0x30, /**< see 100C */
    FSI2PIB_TRUEMASK = FSI2PIB_ENGINE|0x34, /**< see 100D */

    FSI_SCRATCHPAD   = 0x001400, /**< FSI Scratchpad */

    FSI_I2C_MASTER   = 0x001800, /**< FSI I2C-Master */

    FSI_GEMINI_MBOX  = 0x002800, /**< FSI Gemini Mailbox with FSI GPx Registers */
};


// Trace buffer for FSI Register read/writes
#define FSIR_TRACE_BUF "FSIR"

}

#endif 
