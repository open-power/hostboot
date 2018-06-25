/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/node_comm/node_comm.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
#ifndef __NODE_COMM_H
#define __NODE_COMM_H

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <config.h>
#include <devicefw/userif.H>
#include <trace/interface.H>
#include <scom/centaurScomCache.H> // for TRACE_ERR_FMT, TRACE_ERR_ARGS
#include <secureboot/nodecommif.H>
// ----------------------------------------------
// Defines
// ----------------------------------------------
#define NODECOMM_TRACE_NAME "NODECOMM"
extern trace_desc_t* g_trac_nc;

// Easy macro replace for unit testing - TRACD vs TRACF
#define TRACUCOMP(args...) TRACDCOMP(args)

namespace SECUREBOOT
{

namespace NODECOMM
{

/*****************************************************************************/
/* Node Comm Registers Decription
 *
 * There is a set offset between the equivalent XBUS and ABUS registers such
 * that in all cases ABUS Register Address = XBUS Register Address + 0x400.
 * The offset of 0x400 will be applied if the operation is in ABUS mode.
 */
/*****************************************************************************/
#define NCDD_ABUS_REG_OFFSET 0x400
#define NCDD_ABUS_STRING "ABUS"
#define NCDD_XBUS_STRING "XBUS"


/*
 * @brief Node Comm Registers - see above for description
 */
enum node_comm_registers_t : uint64_t
{
                             // XBUS values are default values
                             // NCDD_ABUS_REG_OFFSET added if in ABUS mode
    NCDD_REG_FIR          =  0x5013400,
    NCDD_REG_FIR_WOX_AND  =  0x5013401,
    NCDD_REG_FIR_WOX_OR   =  0x5013402,

    NCDD_REG_CTRL         =  0x501342E,
    NCDD_REG_DATA         =  0x501342F,

    //MailBox Registers:
    NCDD_REG_LINK_MBOX_00  =  0x5013430, //(secure)

/* These registers are calculated by getLinkMboxReg() below
   NCDD_REG_LINK_MBOX_01  =  0x5013431,
   NCDD_REG_LINK_MBOX_10  =  0x5013432,
   NCDD_REG_LINK_MBOX_11  =  0x5013433,
   NCDD_REG_LINK_MBOX_20  =  0x5013434, //(secure)
   NCDD_REG_LINK_MBOX_21  =  0x5013435,
   NCDD_REG_LINK_MBOX_30  =  0x5013436,
   NCDD_REG_LINK_MBOX_31  =  0x5013437,
   NCDD_REG_LINK_MBOX_40  =  0x5013438, //(secure)
   NCDD_REG_LINK_MBOX_41  =  0x5013439,
   NCDD_REG_LINK_MBOX_50  =  0x501343A,
   NCDD_REG_LINK_MBOX_51  =  0x501343B,

   ABUS-Only: (but still use theoretical XBUS value and in NCDD_ABUS_REG_OFFSET)
   NCDD_REG_LINK_MBOX_60  =  0x501343A, //(secure)
   NCDD_REG_LINK_MBOX_61  =  0x501343B,
   NCDD_REG_LINK_MBOX_70  =  0x501343A,
   NCDD_REG_LINK_MBOX_71  =  0x501343B,
*/
};

/**
 *  @brief Convert Link Mailbox Register Address based on mode (XBUS or ABUS)
 *
 *  @param[in] i_reg  - Register Base Address - see node_comm_registers_t
 *  @param[in] i_mode - Indicates if the address is for a ABUS or XBUS operation
 *
 *  @return uint64_t - Calculated Link Mailbox Register Address
 */
inline uint64_t getLinkMboxRegAddr(uint64_t i_reg,
                                   node_comm_modes_t i_mode)
{
    return (i_mode == NCDD_MODE_ABUS)
              ? (i_reg + NCDD_ABUS_REG_OFFSET)
              : i_reg;
}

/**
 *  @brief Calculate Link Mailbox Base Register based on linkId and mboxId
 *
 *  @param[in] i_linkId - Link Id of the operation
 *  @param[in] i_mboxId - Mailbox Id of the operation
 *
 *  @return uint64_t - Calculated Link Mailbox Register Base Address
 *  @note   Returned value is Base/XBUS Address - see node_comm_registers_t
 */
inline uint64_t getLinkMboxReg(uint8_t i_linkId, uint8_t i_mboxId)
{
    return NCDD_REG_LINK_MBOX_00 + (2*i_linkId) + i_mboxId;
}

/**
 *  @brief Calculate Secure LinkId and MailboxId based on OBUS Instance
 *
 *  @param[out] i_obusInstance - OBUS Instance of the operation
 *  @param[out] o_linkId       - Link Id of the OBUS instance
 *  @param[out] o_mboxId       - Mailbox Id of the OBUS instance
 *
 *  @return void
 */
inline void getSecureLinkMboxFromObus(uint8_t i_obusInstance,
                                      uint8_t & o_linkId,
                                      uint8_t & o_mboxId)
{
    // For each OBUS instance there are 2 links and 2 mailboxes
    // and the Secure Link and Mailbox is always the relative 'L0M0'
    // of these 4 possibilities
    o_linkId = (2*i_obusInstance);
    o_mboxId = 0;

    return;
}


enum node_comm_fir_reg_helpers_t : uint64_t
{
    NCDD_ABUS_FIR_ATTN_MASK = 0x000000000FFFF000,
    NCDD_XBUS_FIR_ATTN_MASK = 0x000000000FFF0000,
    NCDD_START_OF_ATTN_BITS = 0x0000000008000000,
};


/**
 *  @brief Calculate Link Mailbox FIR Register Attention Bit Mask
 *         based on linkId and mboxId
 *
 *  @param[in] i_linkId - Link Id of the operation
 *  @param[in] i_mboxId - Mailbox Id of the operation
 *
 *  @return uint64_t - Calculated FIR Register Attention Bit Mask
 */
inline uint64_t getLinkMboxFirAttnBit(uint8_t i_linkId, uint8_t i_mboxId)
{
    return (NCDD_START_OF_ATTN_BITS >> ((2*i_linkId) + i_mboxId));
}


/**
 *  @brief Map Attention Bits in XBUS/ABUS FIR Register to specific Link Mailbox
 *
 *  @param[in] i_pProc      Processor target to look for attentions on
 *                          Can't be nullptr
 *  @param[in] i_mode       Indicates to look for ABUS or XBUS attentions
 *  @param[in] o_attn_found Returns true if attention was found; otherwise false
 *  @param[in] o_linkId     Link Id attention was found on
 *  @param[in] o_mboxId     Mbox Id attention was found on
 *  @note - o_linkId and o_mboxId are only set/valid if o_attn_found is true
 *
 *  @return errlHndl_t Error log handle
 *  @retval nullptr Operation was successful
 *  @retval !nullptr Operation failed with valid error log
 */
errlHndl_t nodeCommMapAttn(TARGETING::Target* i_pProc,
                           node_comm_modes_t i_mode,
                           bool & o_attn_found,
                           uint64_t & o_linkId,
                           uint64_t & o_mboxId);

/**
 * @brief Add FFDC for the target to an error log
 *
 * @param[in] i_mode       Specifies XBUS or ABUS mode
 * @param[in] i_pProc      Proc Chip Target used to collect info from
 * @param[in,out] io_log   Error Log to add FFDC to
 *
 * @return void
 */
void getNodeCommFFDC(node_comm_modes_t i_mode,
                     TARGETING::Target*  i_pProc,
                     errlHndl_t & io_log);

} // end NODECOMM namespace

} // end SECUREBOOT namespace

#endif // End __NODE_COMM_H

