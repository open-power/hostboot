/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_draminit_trainadv/mss_mcbist_address.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
// *!***************************************************************************
// *! (C) Copyright International Business Machines Corp. 1997, 1998
// *!           All Rights Reserved -- Property of IBM
// *!                   *** IBM Confidential ***
// *!***************************************************************************
// *! FILENAME             :  mss_mcbist_address.H
// *! TITLE                : 
// *! DESCRIPTION          : MCBIST procedures
// *! CONTEXT              : 
// *!
// *! OWNER  NAME          : 
// *! BACKUP               : 
// *!***************************************************************************
// CHANGE HISTORY:
//-------------------------------------------------------------------------------
// Version:|Author: | Date:   | Comment:
// --------|--------|---------|--------------------------------------------------
//------------------------------------------------------------------------------
#ifndef MSS_MCBIST_ADDRESS_H
#define MSS_MCBIST_ADDRESS_H

/****************************************************************************************/
/* mss_mcbist_address.H                                                                           */
/****************************************************************************************/
#include <fapi.H>
#include <cen_scom_addresses.H>
#include <mss_access_delay_reg.H>
#include <mss_shmoo_common.H>
#include <mss_mcbist.H>
#include<string.h>
extern "C"
{
using namespace fapi;

/*enum address_mode
{
    SF,
    SR,
    RF,
    RR
};*/
enum interleave_type
{

BANK_RANK, 
RANK_BANK,
BANK_ONLY,
RANK_ONLY,
RANKS_DIMM0,
RANKS_DIMM1,
USER_PATTERN
};

fapi::ReturnCode address_generation(const fapi:: Target & i_target_mba,uint8_t i_port,mcbist_addr_mode i_addr_type,interleave_type i_add_inter_type,uint8_t i_rank,uint64_t &io_start_address, uint64_t &io_end_address);
fapi::ReturnCode parse_addr(const fapi:: Target & i_target_mba, char addr_string[],uint8_t mr3_valid,uint8_t mr2_valid,uint8_t mr1_valid,uint8_t l_dram_rows,uint8_t l_dram_cols,uint8_t l_addr_inter); 

}
#endif
