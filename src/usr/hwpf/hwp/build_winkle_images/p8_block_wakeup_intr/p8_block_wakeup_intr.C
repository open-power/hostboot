/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_block_wakeup_intr/p8_block_wakeup_intr.C $ */
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
// $Id: p8_block_wakeup_intr.C,v 1.1 2013/08/27 16:13:05 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_block_wakeup_intr.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
/**
  * OWNER NAME:   Greg Still         Email: stillgs@us.ibm.com
  * BACKUP NAME : Michael Olsen      Email: cmolsen@us.ibm.com
  *
  * @file p8_block_wakeup_intr.C
  * @brief Set/reset the BLOCK_REG_WKUP_SOURCES bit in the PCBS-PM associated 
  *         with an EX chiplet
  *
  * @verbatim
  * High-level procedure flow:
  *
  *  With set/reset enum parameter, either set or clear PMGP0(53)
  *
  *  Procedure Prereq:
  *     - System clocks are running
  * @endverbatim
  */
//------------------------------------------------------------------------------


// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------

#include "p8_block_wakeup_intr.H"

extern "C" {

using namespace fapi;


/**
 * p8_block_wakeup_intr
 *
 * @param[in] i_ex_target EX target
 * @param[in] i_operation  SET, RESET
 *
 * @retval ECMD_SUCCESS
 * @retval ERROR only those from called functions or MACROs
 */
fapi::ReturnCode
p8_block_wakeup_intr(  const fapi::Target& i_ex_target,
                        PROC_BLKWKUP_OPS i_operation )

{
    fapi::ReturnCode    rc;
    uint32_t            e_rc = 0;
    uint64_t            address;
    uint64_t            offset;
    ecmdDataBufferBase  data(64);

    fapi::Target        l_parentTarget;
    uint8_t             attr_chip_unit_pos = 0;
    
    // PMGP0 Bit definitions
    const uint32_t      BLOCK_REG_WKUP_SOURCES = 53;

    // This must stay in sync with enum defined the .H file
    const char* PROC_BLKWKUP_OPS_NAMES[] =
    {
        "SET",
        "RESET"
    };

    do
    {

        FAPI_INF("Executing p8_block_wakeup_intr with operation %s to EX %s...",
                    PROC_BLKWKUP_OPS_NAMES[i_operation],
                    i_ex_target.toEcmdString());
      

        // Get the parent chip to target the registers
        rc = fapiGetParentChip(i_ex_target, l_parentTarget);
        if (rc)
        {
            FAPI_ERR("fapiGetParentChip with rc = 0x%x", (uint32_t)rc);
            break;
        }

        // Get the core number
        rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_ex_target, attr_chip_unit_pos);
        if (rc)
        {
            FAPI_ERR("fapiGetAttribute of ATTR_CHIP_UNIT_POS with rc = 0x%x", (uint32_t)rc);
            break;
        }

        FAPI_DBG("Core number = %d", attr_chip_unit_pos);
        offset = attr_chip_unit_pos * 0x01000000;

        if (i_operation == BLKWKUP_SET)
        {
            FAPI_INF("Setting Block Interrupt Sources...");
            
            address =  EX_PMGP0_OR_0x100F0102 + offset;                                        
            
            e_rc |= data.flushTo0();
            e_rc |= data.setBit(BLOCK_REG_WKUP_SOURCES);
            E_RC_CHECK(e_rc, rc);

            PUTSCOM(rc, l_parentTarget, address, data);

            
        }
        else if (i_operation == BLKWKUP_RESET)
        {

            FAPI_INF("Clearing Block Interrupt Sources...");
            
            address =  EX_PMGP0_AND_0x100F0101 + offset;                                        
            
            e_rc |= data.flushTo1();
            e_rc |= data.clearBit(BLOCK_REG_WKUP_SOURCES);
            E_RC_CHECK(e_rc, rc);

            PUTSCOM(rc, l_parentTarget, address, data);

        }
        else
        {
            FAPI_ERR("Invalid parameter specified. Operation %x", i_operation );
            const fapi::Target & EX_TARGET = i_ex_target;
            PROC_BLKWKUP_OPS & OPERATION = i_operation ;
            FAPI_SET_HWP_ERROR(rc, RC_PROCPM_BLKWKUP_CODE_BAD_OP);
            break;
        }
        
    } while (0);
    
    return rc;   
}

} //end extern C
