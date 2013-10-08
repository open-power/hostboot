/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/core_activate/proc_prep_master_winkle/proc_prep_master_winkle.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
// -*- mode: C++; c-file-style: "linux";  -*-
// $Id: proc_prep_master_winkle.C,v 1.13 2013/07/30 15:23:25 jeshua Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_prep_master_winkle.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_prep_master_winkle.C
// *! DESCRIPTION : Prepares for the master core to winkle
// *!
// *! OWNER NAME  : Jeshua Smith            Email: jeshua@us.ibm.com
// *!
// *! Overview:
// *!    Wait for SBE ready
// *!    Start SBE deadman timer
// *!    *Enter winkle*
// *!
// *!    Note: Hostboot should always run with i_useRealSBE = true
// *!
// *!    Here's the flow of SBE_VITAL substeps:
// *!    SBE (automatic on procedure entry): substep_proc_entry
// *!    SBE                               : substep_sbe_ready
// *!    HB (proc_prep_master_winkle)      : substep_deadman_start
// *!    SBE                               : substep_deadman_waiting_for_winkle
// *!    SBE                               : substep_deadman_waiting_for_wakeup
// *!    HB (proc_stop_deadman_timer)      : substep_hostboot_alive_again
// *!    SBE                   : (stops with error code 0xF to indicate success)
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "proc_prep_master_winkle.H"
#include "p8_scom_addresses.H"
#include "p8_istep_num.H"
#include "proc_sbe_trigger_winkle.H"

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

extern "C"
{



//------------------------------------------------------------------------------
// function: proc_prep_master_winkle
//     Wait for SBE ready
//     Start SBE deadman timer
//     *Enter winkle*
//
// parameters: i_ex_target     => Reference to master chiplet target
//             i_useRealSBE => True if proc_sbe_trigger_winkle is supposed to be
//                             running on the real SBE (default is true), else
//                             false if proc_sbe_trigger_winkle is running on
//                             the FSP (via poreve).
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
    fapi::ReturnCode proc_prep_master_winkle(const fapi::Target & i_ex_target, 
                                             const bool & i_useRealSBE = true)
    {
        // data buffer to hold register values
        ecmdDataBufferBase data(64);
        ecmdDataBufferBase pmgp1(64);

        // return codes
        uint32_t                    rc_ecmd = 0;
        fapi::ReturnCode            rc;
        
        // istep/substep umbers
        uint32_t                    istep_num = 0;
        uint8_t                     substep_num = 0;
        
        // addressing variables
        uint64_t                    address;
        uint8_t                     l_ex_number = 0;
        fapi::Target                l_parentTarget;

        // mark function entry
        FAPI_INF("Entry, useRealSBE is %s\n", i_useRealSBE? "true":"false");

        do
        {
            
            // Get the parent chip to target the PCBS registers
            rc = fapiGetParentChip(i_ex_target, l_parentTarget);
            if (rc)
            {
                FAPI_ERR("fapiGetParentChip access");
                break;
            }
                                  
            // Wait for SBE ready
            // ie. SBE running, and istep num and substep num correct
            if( i_useRealSBE )
            {            
                rc = fapiGetScom(l_parentTarget, PORE_SBE_CONTROL_0x000E0001, data);
                if(!rc.ok())
                {
                    FAPI_ERR("Scom error reading SBE STATUS\n");
                    break;
                }
                if( data.isBitSet( 0 ) )
                {
                    FAPI_ERR("SBE isn't running when it should be\n");
                    const fapi::Target & CHIP_IN_ERROR = l_parentTarget;
                    ecmdDataBufferBase & SBE_STATUS = data;
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_PREP_MASTER_WINKLE_SBE_NOT_RUNNING);
                    break;
                }
            }

            rc = fapiGetScom(l_parentTarget, MBOX_SBEVITAL_0x0005001C, data);
            if(!rc.ok())
            {
                FAPI_ERR("Scom error reading SBE VITAL\n");
                break;
            }

            rc_ecmd |= data.extractToRight(&istep_num,
                                           ISTEP_NUM_BIT_POSITION,
                                           ISTEP_NUM_BIT_LENGTH);
            rc_ecmd |= data.extractToRight(&substep_num,
                                           SUBSTEP_NUM_BIT_POSITION,
                                           SUBSTEP_NUM_BIT_LENGTH);
            if(rc_ecmd)
            {
                FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", rc_ecmd);

                rc.setEcmdError(rc_ecmd);
                break;
            }
            if( istep_num != PROC_SBE_TRIGGER_WINKLE_ISTEP_NUM )
            {
                FAPI_ERR("Expected istep num %llX but found %X\n",
                         PROC_SBE_TRIGGER_WINKLE_ISTEP_NUM,
                         istep_num );
                const fapi::Target & CHIP_IN_ERROR = l_parentTarget;
                ecmdDataBufferBase & SBE_VITAL = data;
                FAPI_SET_HWP_ERROR(rc, RC_PROC_PREP_MASTER_WINKLE_BAD_ISTEP_NUM);
                break;
            }
            if( substep_num != SUBSTEP_SBE_READY )
            {
                FAPI_ERR("Expected substep num %X but found %X\n",
                         SUBSTEP_SBE_READY,
                         substep_num );
                const fapi::Target & CHIP_IN_ERROR = l_parentTarget;
                ecmdDataBufferBase & SBE_VITAL = data;
                FAPI_SET_HWP_ERROR(rc, RC_PROC_PREP_MASTER_WINKLE_BAD_SUBSTEP_NUM);
                break;
            }
            FAPI_INF("SBE is ready for master to enter winkle\n");

            // Get the core number
            rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_ex_target, l_ex_number);
            if (rc)
            {
                FAPI_ERR("fapiGetAttribute of ATTR_CHIP_UNIT_POS with rc = 0x%x", (uint32_t)rc);
                break;
            }

            FAPI_INF("Processing core %d on %s", l_ex_number, l_parentTarget.toEcmdString());           
                
            // Disable movement to Fast Winkle if errors are present
            rc_ecmd |= pmgp1.flushTo0();
            rc_ecmd |= pmgp1.setBit(20);
            if(rc_ecmd)
            {
                FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", rc_ecmd);

                rc.setEcmdError(rc_ecmd);
                break;
            }

            address = EX_PMGP1_OR_0x100F0105 + (l_ex_number*0x01000000);
            rc = fapiPutScom(l_parentTarget, address, pmgp1);
            if(!rc.ok())
            {
                FAPI_ERR("Scom error updating PMGP1\n");
                break;
            }
            FAPI_INF("Disabled the ability to have Deep Winkle turned to Fast Winkle if errors are present\n");  
          

            //Start the deadman timer
            substep_num = SUBSTEP_DEADMAN_START;
            rc_ecmd |= data.insertFromRight(&substep_num,
                                            SUBSTEP_NUM_BIT_POSITION,
                                            SUBSTEP_NUM_BIT_LENGTH);
            if(rc_ecmd)
            {
                FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom(l_parentTarget, MBOX_SBEVITAL_0x0005001C, data);
            if(!rc.ok())
            {
                FAPI_ERR("Scom error updating SBE VITAL\n");
                break;
            }
            
            //Enter winkle
            FAPI_INF("HB should enter winkle now, FSP should execute proc_force_winkle now\n");

        } while (0);

        // mark function exit
        FAPI_INF("Exit");
        return rc;
    }

} // extern "C"
/* Local Variables: */
/* c-basic-offset: 4 */
/* End: */
