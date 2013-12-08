/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/core_activate/switch_rec_attn/proc_switch_rec_attn.C $ */
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
// -*- mode: C++; c-file-style: "linux";  -*-
// $Id: proc_switch_rec_attn.C,v 1.3 2013/11/25 17:13:06 mfred Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_switch_rec_attn.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_switch_rec_attn.C
// *! DESCRIPTION : The purpose of this procedure is to mask Centaur recoverable attentions from the host
// *!               (At this point in the IPL process those attentions should be routed to the FSP.)
// *!
// *! OWNER NAME  : Mark Fredrickson     Email: mfred@us.ibm.com
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p8_scom_addresses.H>
#include <proc_switch_rec_attn.H>
#include <fapi.H>


using namespace fapi;


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// MCS MCI FIR bit/field definitions
const uint8_t MCI_CENTAUR_CHECKSTOP_BIT  = 12;
const uint8_t MCI_CENTAUR_RECOV_ERR_BIT  = 15;
const uint8_t MCI_CENTAUR_SPEC_ATTN_BIT  = 16;
const uint8_t MCI_CENTAUR_MAINT_COMP_BIT = 17;


//------------------------------------------------------------------------------
// Function definition
//------------------------------------------------------------------------------

extern "C"
{

    //------------------------------------------------------------------------------
    // function:  mask Centaur recoverable attentions from the host
    //
    // parameters: i_target       =>   MCS chiplet of processor chip
    // returns: FAPI_RC_SUCCESS if operation was successful, else error
    //------------------------------------------------------------------------------
    fapi::ReturnCode proc_switch_rec_attn(const fapi::Target & i_target)
    {
        // data buffer to hold register values
        ecmdDataBufferBase scom_data(64);

        // return codes
        uint32_t rc_ecmd = 0;
        fapi::ReturnCode rc;



        // mark function entry
        FAPI_INF("********* Starting proc_switch_rec_attn *********");
        do
        {

            // Mask the following FIR bits that came over from Centaur
            // MCS_MCIFIR(12,15,16,17)
            // The FIR bits are in the MCS MCIFIR register (02011840 is the first instance)
            // The FIR masks are in the MCS MCIFIRMASK reg (02011843 is the first instance)
            FAPI_INF("Mask OFF the MCI FIR bits 12,15,16,17 coming from Centaur.\n");
            rc = fapiGetScom(i_target, MCS_MCIFIRMASK_0x02011843, scom_data);
            if (rc)
            {
                FAPI_ERR("fapiGetScom error (MCS_MCIFIRMASK_0x02011843)");
                break;
            }
            rc_ecmd |= scom_data.setBit(MCI_CENTAUR_CHECKSTOP_BIT);
            rc_ecmd |= scom_data.setBit(MCI_CENTAUR_RECOV_ERR_BIT);
            rc_ecmd |= scom_data.setBit(MCI_CENTAUR_SPEC_ATTN_BIT);
            rc_ecmd |= scom_data.setBit(MCI_CENTAUR_MAINT_COMP_BIT);
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x setting up data buffer to mask the MCI FIR bits", rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom(i_target, MCS_MCIFIRMASK_0x02011843, scom_data);
            if (rc)
            {
                FAPI_ERR("fapiPutScom error (MCS_MCIFIRMASK_0x02011843)");
                break;
            }


            // Marc Gollub also suggested that the action bits for these signals should be set to recoverable attention (A0=0, A1=1)
            // The action0 bits are in the MCS MCIFIRACT0 reg (02011846 is the first instance)
            // The action1 bits are in the MCS MCIFIRACT1 reg (02011847 is the first instance)
            FAPI_INF("Set MCS MCI ACTION0 bits 12,15,16,17 to zero in MCS_MCIFIRACT0_0x02011846.\n");
            rc = fapiGetScom(i_target, MCS_MCIFIRACT0_0x02011846, scom_data);
            if (rc)
            {
                FAPI_ERR("fapiGetScom error (MCS_MCIFIRACT0_0x02011846)");
                break;
            }
            rc_ecmd |= scom_data.clearBit(MCI_CENTAUR_CHECKSTOP_BIT);
            rc_ecmd |= scom_data.clearBit(MCI_CENTAUR_RECOV_ERR_BIT);
            rc_ecmd |= scom_data.clearBit(MCI_CENTAUR_SPEC_ATTN_BIT);
            rc_ecmd |= scom_data.clearBit(MCI_CENTAUR_MAINT_COMP_BIT);
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x setting up data buffer to clear action bits in MCS_MCIFIRACT0_0x02011846", rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom(i_target, MCS_MCIFIRACT0_0x02011846, scom_data);
            if (rc)
            {
                FAPI_ERR("fapiPutScom error (MCS_MCIFIRACT0_0x02011846)");
                break;
            }

            FAPI_INF("Set MCS MCI ACTION1 bits 12,15,16,17 to one in MCS_MCIFIRACT1_0x02011847.\n");
            rc = fapiGetScom(i_target, MCS_MCIFIRACT1_0x02011847, scom_data);
            if (rc)
            {
                FAPI_ERR("fapiGetScom error (MCS_MCIFIRACT1_0x02011847)");
                break;
            }
            rc_ecmd |= scom_data.setBit(MCI_CENTAUR_CHECKSTOP_BIT);
            rc_ecmd |= scom_data.setBit(MCI_CENTAUR_RECOV_ERR_BIT);
            rc_ecmd |= scom_data.setBit(MCI_CENTAUR_SPEC_ATTN_BIT);
            rc_ecmd |= scom_data.setBit(MCI_CENTAUR_MAINT_COMP_BIT);
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x setting up data buffer to set action bits in MCS_MCIFIRACT1_0x02011847", rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc = fapiPutScom(i_target, MCS_MCIFIRACT1_0x02011847, scom_data);
            if (rc)
            {
                FAPI_ERR("fapiPutScom error (MCS_MCIFIRACT1_0x02011847)");
                break;
            }


        } while (0); // end do

        // mark function exit
        FAPI_INF("********* proc_switch_rec_attn complete *********");
        return rc;
    }  // end FAPI procedure proc_switch_rec_attn

} // extern "C"

/*
*************** Do not edit this area ***************
This section is automatically updated by CVS when you check in this file.
Be sure to create CVS comments when you commit so that they can be included here.
$Log: proc_switch_rec_attn.C,v $
Revision 1.3  2013/11/25 17:13:06  mfred
Change include statements to avoid problems.  (From Gerrit review.)

Revision 1.2  2013/04/12 19:23:36  mfred
Avoid clearing bit 18 of the MCIFIRMASK by reading the reg first. (Fix for SW197032).

Revision 1.1  2012/12/10 20:38:04  mfred
Committing new procedure proc_switch_rec_attn.



*/

