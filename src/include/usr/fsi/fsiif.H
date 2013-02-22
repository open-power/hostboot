/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fsi/fsiif.H $                                 */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
 * FSI Slave Registers for P8
 *   These registers are repeated for every master+port+cascade combo 
 */
enum SlaveRegistersP8
{
    // Local FSI Space
    SLAVE_CFG_TABLE  = 0x000000, /**< Configuration Table of CFAM */
    SLAVE_PEEK_TABLE = 0x000400, /**< Peek Table */

    SLAVE_REGS       = 0x000800, /**< FSI Slave Register */
    SLAVE_MODE_00    = SLAVE_REGS|0x00,

    FSI_SHIFT_ENGINE = 0x000C00, /**< FSI Shift Engine (SCAN) */
    FSI2PIB_ENGINE   = 0x001000, /**< FSI2PIB Engine (SCOM) */
    FSI_SCRATCHPAD   = 0x001400, /**< FSI Scratchpad */
    FSI_I2C_MASTER   = 0x001800, /**< FSI I2C-Master */
    FSI_GEMINI_MBOX  = 0x002800, /**< FSI Gemini Mailbox with FSI GPx Registers */
};



}

#endif 
