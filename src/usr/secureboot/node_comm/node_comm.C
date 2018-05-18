/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/node_comm/node_comm.C $                    */
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
/**
 * @file node_comm.C
 *
 * @brief Implementation of the Secure Node Communications Functions
 *
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <string.h>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <errl/errludlogregister.H>
#include <targeting/common/targetservice.H>
#include <devicefw/userif.H>
#include <devicefw/driverif.H>
#include <secureboot/secure_reasoncodes.H>
#include <secureboot/nodecommif.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>

#include "node_comm.H"

using   namespace   TARGETING;

namespace SECUREBOOT
{

namespace NODECOMM
{

/**
 *  @brief Map Attention Bits in FIR Register to specific Link Mailbox
 */
errlHndl_t nodeCommMapAttn(TARGETING::Target* i_pProc,
                           const node_comm_modes_t i_mode,
                           bool & o_attn_found,
                           uint64_t & o_linkId,
                           uint64_t & o_mboxId)
{
    errlHndl_t err = nullptr;
    uint64_t fir_data = 0x0;
    uint64_t fir_data_with_mask = 0x0;
    o_attn_found = false;

    assert(i_mode < NCDD_MODE_INVALID,"nodeCommMapAttn: Invalid mode: %d",
           i_mode);

    const uint64_t fir_mask = (i_mode == NCDD_MODE_ABUS)
                              ? NCDD_ABUS_FIR_ATTN_MASK
                              : NCDD_XBUS_FIR_ATTN_MASK;

    const uint64_t fir_addr = (i_mode == NCDD_MODE_ABUS)
                              ? NCDD_REG_FIR + NCDD_ABUS_REG_OFFSET
                              : NCDD_REG_FIR;

    const size_t expSize = sizeof(fir_data);

    TRACFCOMP(g_trac_nc,ENTER_MRK
              "nodeCommMapAttn: tgt=0x%X, mode=%s, fir_addr=0x%.16llX",
              get_huid(i_pProc),
              (i_mode == NCDD_MODE_ABUS)
                ? NCDD_ABUS_STRING : NCDD_XBUS_STRING,
              fir_addr);


    do
    {
    // Read the FIR reg
    auto reqSize = expSize;
    err = DeviceFW::deviceRead(i_pProc,
                               &fir_data,
                               reqSize,
                               DEVICE_SCOM_ADDRESS(fir_addr));

    if(err)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommMapAttn Read Fail! (%s): "
                  " tgt=0x%X, reg_addr=0x%.16llX, data=0x%.16llX "
                  TRACE_ERR_FMT,
                  (i_mode == NCDD_MODE_ABUS)
                    ? NCDD_ABUS_STRING : NCDD_XBUS_STRING,
                  TARGETING::get_huid(i_pProc),
                  fir_addr, fir_data,
                  TRACE_ERR_ARGS(err));
        break;
    }
    assert(reqSize==expSize,"nodeCommMapAttn: SCOM deviceRead didn't return expected data size of %d (it was %d)",
           expSize,reqSize);

    // Map Attention bits in the FIR
    fir_data_with_mask = fir_data & fir_mask;
    const int bit_count = __builtin_popcount(fir_data_with_mask);
    TRACUCOMP(g_trac_nc,"nodeCommMapAttn: FIR data = 0x%.16llX, "
              "mask=0x%.16llX, data+mask=0x%.16llX, count=%d",
              fir_data, fir_mask, fir_data_with_mask, bit_count);

    if (bit_count == 0)
    {
        TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommMapAttn: no attentions found");
        break;
    }
    else if (bit_count > 1)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommMapAttn: "
                  "Too many attentions found (%d) in fir: data=0x%.16llX, "
                  "data+mask=0x%.16llX, fir_addr=0x%.16llX",
                  bit_count, fir_data, fir_data_with_mask, fir_addr);

        /*@
         * @errortype
         * @reasoncode       RC_NC_TOO_MANY_ATTNS_FOUND
         * @moduleid         MOD_NC_MAP_ATTN
         * @userdata1        Raw FIR Data
         * @userdata2[0:31]  Number of Attentions found
         * @userdata2[32:63] Target HUID FIR was read from
         * @devdesc          Too many attentions were found in
         *                   the Node Comm FIR Register
         * @custdesc         Secure Boot failure
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       MOD_NC_MAP_ATTN,
                                       RC_NC_TOO_MANY_ATTNS_FOUND,
                                       fir_data,
                                       TWO_UINT32_TO_UINT64(
                                         bit_count,
                                         get_huid(i_pProc)));

        // Likely HB code failed to do the procedure correctly
        err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                 HWAS::SRCI_PRIORITY_HIGH);

        // Or unlikely an issue with Processor or its bus
        err->addHwCallout( i_pProc,
                           HWAS::SRCI_PRIORITY_LOW,
                           HWAS::NO_DECONFIG,
                           HWAS::GARD_NULL );

        // Collect FFDC
        getNodeCommFFDC(i_mode, i_pProc, err);

        err->collectTrace(SECURE_COMP_NAME);
        err->collectTrace(NODECOMM_TRACE_NAME);

        break;
    }

    int bit = 0;
    const int possible_attn_bits = __builtin_popcount(fir_mask);
    for ( ; bit < possible_attn_bits ; ++bit)
    {
        // Start at first bit and shift right to find an attention
        if ( fir_data & (NCDD_START_OF_ATTN_BITS >> bit))
        {
            o_attn_found = true;
            o_linkId = (bit / 2);
            o_mboxId = (bit % 2);
            break;
        }
    }

    } while( 0 );

    TRACFCOMP(g_trac_nc,EXIT_MRK"nodeCommMapAttn: tgt=0x%X: "
              "o_attn_found=%d, o_linkId=%d, mboxId=%d, "
              TRACE_ERR_FMT,
              get_huid(i_pProc), o_attn_found, o_linkId, o_mboxId,
              TRACE_ERR_ARGS(err));

    return err;

} // end of nodeCommMapAttn


/**
 * @brief Add FFDC for the target to an error log
 */
void getNodeCommFFDC( node_comm_modes_t   i_mode,
                      TARGETING::Target*  i_pProc,
                      errlHndl_t          &io_log)
{
    TRACFCOMP(g_trac_nc,ENTER_MRK
              "getNodeCommFFDC: tgt=0x%X, mode=%s, err_plid=0x%X",
              get_huid(i_pProc),
              (i_mode == NCDD_MODE_ABUS)
                ? NCDD_ABUS_STRING : NCDD_XBUS_STRING,
              ERRL_GETPLID_SAFE(io_log));

    do
    {
    if (io_log == nullptr)
    {
        TRACFCOMP(g_trac_nc,INFO_MRK"getNodeCommFFDC: io_log==nullptr, so "
                  "no FFDC has been collected for tgt=0x%X, mode=%s",
                  get_huid(i_pProc),
                  (i_mode == NCDD_MODE_ABUS)
                    ? NCDD_ABUS_STRING : NCDD_XBUS_STRING);
        break;
    }

    // Add Target to log
    ERRORLOG::ErrlUserDetailsTarget(i_pProc,"Proc Target").addToLog(io_log);

    // Add HW regs
    ERRORLOG::ErrlUserDetailsLogRegister ffdc(i_pProc);

    // FIR/Control/Status/Data Registers
    ffdc.addData(DEVICE_SCOM_ADDRESS(getLinkMboxRegAddr(NCDD_REG_FIR,i_mode)));
    ffdc.addData(DEVICE_SCOM_ADDRESS(getLinkMboxRegAddr(NCDD_REG_CTRL,i_mode)));
    ffdc.addData(DEVICE_SCOM_ADDRESS(getLinkMboxRegAddr(NCDD_REG_DATA,i_mode)));

    // Loop Through All of the Mailbox Registers Where the Data Could End Up
    uint64_t l_reg = 0;
    const auto max_linkId = (i_mode==NCDD_MODE_ABUS)
                              ? NCDD_MAX_ABUS_LINK_ID
                              : NCDD_MAX_XBUS_LINK_ID;

    for (size_t linkId=0;  linkId <= max_linkId ; ++linkId)
    {
        for (size_t mboxId=0; mboxId <= NCDD_MAX_MBOX_ID; ++mboxId)
        {
            l_reg = getLinkMboxReg(linkId, mboxId);
            ffdc.addData(DEVICE_SCOM_ADDRESS(getLinkMboxRegAddr(l_reg,i_mode)));
        }
    }

    ffdc.addToLog(io_log);


    } while( 0 );

    TRACFCOMP(g_trac_nc,EXIT_MRK"getNodeCommFFDC");

    return;

} // end of getNodeCommFFDC


} // End NODECOMM namespace

} // End SECUREBOOT namespace

