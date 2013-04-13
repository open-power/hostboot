/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/core_activate/switch_rec_attn/cen_switch_rec_attn.C $ */
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
// $Id: cen_switch_rec_attn.C,v 1.4 2013/03/04 17:56:36 mfred Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/cen_switch_rec_attn.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : cen_switch_rec_attn
// *! DESCRIPTION : The purpose of this procedure is to route Centaur recoverable attns and special attns to the FSP.
// *! OWNER NAME  : Mark Fredrickson  Email: mfred@us.ibm.com
// *! BACKUP NAME : Mark Bellows      Email: bellows@us.ibm.com
// *! SCREEN      : pervasive_screen
// #! ADDITIONAL COMMENTS : See inline comments below.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------

#include <fapi.H>
#include <cen_scom_addresses.H>
#include <cen_switch_rec_attn.H>

//  Constants
const uint8_t RECOV_ERR_IPOLL_MASK_BIT = 5;
const uint8_t SPEC_ATTN_IPOLL_MASK_BIT = 6;

extern "C" {

using namespace fapi;

fapi::ReturnCode cen_switch_rec_attn(const fapi::Target & i_target)
{
    // Target is centaur

    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;
    ecmdDataBufferBase scom_data(64);


    FAPI_INF("********* cen_switch_rec_attn start *********");
    do
    {

        // Clear bit 5 in the IPOLL Mask Register 0x01020013 to unmask the recoverable errors going to FSI and DMI.
        // Clear bit 6 in the IPOLL Mask Register 0x01020013 to unmask the special attn interrupts going to FSI and DMI.
        // Note: In Centaur the outputs of the ITR Macro go to both the FSI and to the DMI.
        //       The "HostBridge" mentioned in the P8 Pervasive Workbook is NOT the DMI path.
        //       In Centaur the IPOLL Mask bits 0-3 to not do anything.
        //       In Centaur the IPOLL Mask bits 4-7 controll signals going to BOTH FSI and DMI.
        FAPI_DBG("Writing IPOLL Mask Register 0x01020013 to clear bit 5 and 6 (to unmask recov errs and spc attns) ...");
        rc = fapiGetScom( i_target, TP_IPOLL_MSK_0x01020013, scom_data);
        if ( rc )
        {
            FAPI_ERR("Error reading Interrupt IPOLL Mask Reg 0x01020013.");
            break;
        }
        rc_ecmd |= scom_data.clearBit(RECOV_ERR_IPOLL_MASK_BIT);
        rc_ecmd |= scom_data.clearBit(SPEC_ATTN_IPOLL_MASK_BIT);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up ecmd data buffer to write Interrupt IPOLL Mask Register.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom( i_target, TP_IPOLL_MSK_0x01020013, scom_data);
        if (rc)
        {
            FAPI_ERR("Error writing Interrupt IPOLL Mask Reg 0x01020013.");
            break;
        }


    } while(0);


    FAPI_INF("********* cen_switch_rec_attn complete *********");
    return rc;
}

} //end extern C



/*
*************** Do not edit this area ***************
This section is automatically updated by CVS when you check in this file.
Be sure to create CVS comments when you commit so that they can be included here.
$Log: cen_switch_rec_attn.C,v $
Revision 1.4  2013/03/04 17:56:36  mfred
Add some header comments for BACKUP and SCREEN.

Revision 1.3  2013/01/18 17:18:31  mfred
Clear mask to allow special attentions to go to FSP, along with recoverables.

Revision 1.2  2012/12/13 22:54:32  mfred
Update to remove unneeded commands and unmask recoverable path to FSI.

Revision 1.1  2012/12/10 22:39:02  mfred
Adding new procedure cen_switch_rec_attn.


*/
