//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/fsi/fsiif.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END

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
