/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dmi_training/proc_cen_set_inband_addr/proc_cen_set_inband_addr.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// -*- mode: C++; c-file-style: "linux";  -*-
// $Id: proc_cen_set_inband_addr.C,v 1.8 2014/02/05 17:34:30 mfred Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_cen_set_inband_addr.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_cen_set_inband_addr.C
// *! DESCRIPTION : Set the inband base address in the MCS MDFGPR register
// *!
// *! OWNER NAME  : Mark Fredrickson     Email: mfred@us.ibm.com
// *!
// *! The purpose of this procedure is to set the inband base address in the MCS MDFGPR register
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p8_scom_addresses.H>
#include <proc_cen_set_inband_addr.H>


using namespace fapi;


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------




//------------------------------------------------------------------------------
// Function definition
//------------------------------------------------------------------------------

extern "C"
{

    //------------------------------------------------------------------------------
    // function:  Set the inband base address in the MCS MDFGPR register
    //
    // parameters: i_target       =>   MCS chiplet of processor chip
    // returns: FAPI_RC_SUCCESS if operation was successful, else error
    //------------------------------------------------------------------------------
    fapi::ReturnCode proc_cen_set_inband_addr(const fapi::Target & i_target)
    {
        // data buffer to hold register values
        ecmdDataBufferBase scom_data(64);
        ecmdDataBufferBase attr_data(64);

        // return codes
        uint32_t rc_ecmd = 0;
        fapi::ReturnCode rc;

        // locals
        uint64_t        inband_base_addr = 0;


        // mark function entry
        FAPI_INF("********* Starting proc_cen_set_inband_addr *********");
        do
        {

            // Read the ATTR_MCS_INBAND_BASE_ADDRESS attribute
            rc = FAPI_ATTR_GET( ATTR_MCS_INBAND_BASE_ADDRESS, &i_target, inband_base_addr);
            if (rc)
            {
                FAPI_ERR("Failed to get attribute: ATTR_MCS_INBAND_BASE_ADDRESS.");
                break;
            }
            FAPI_DBG("The inband base address is specified to be set to: %#llX.", inband_base_addr);



            // Munge the bits:
            // Extract bits 14:27 from the attribute value, pass them into bits 6:19 of the register
            // In the target register:
            // Bit 0 is MCFGPRQ_VALID.   Needs to be set to '1'.
            // Bits 6:19 are MCFGPRQ_BASE_ADDRESS.  Needs to be set to base address for inband SCOM operations.
            rc_ecmd |= attr_data.setDoubleWord(0, inband_base_addr);
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x filling ecmd data buffer with value from an attribute.",  rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            rc_ecmd |= scom_data.flushTo0();
            // Insert bits 17:27 from the attribute data into the scom data buffer bits 6:19
            rc_ecmd |= scom_data.insert( attr_data, 6, 14, 14);
            // Set bit 0 to be a '1'
            rc_ecmd |= scom_data.setBit(0);
            if (rc_ecmd)
            {
                FAPI_ERR("Error 0x%x setting up ecmd data buffer to write MCS MCFGPR Register.",  rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }



            // Write the MCS MCFGPR register.
            // Write SCOM  address=MCS_MCFGPR_0x02011802 using data from attibute.
            FAPI_DBG("Writing MCS MCFGPR Register to set base address for inband SCOM operations.");
            rc = fapiPutScom( i_target, MCS_MCFGPR_0x02011802, scom_data);
            if (rc)
            {
                FAPI_ERR("Error writing MCS MCFGPR Register to set base address for inband SCOM operations.");
                break;
            }



        } while (0); // end do

        // mark function exit
        FAPI_INF("********* proc_cen_set_inband_addr complete *********");
        return rc;
    }  // end FAPI procedure proc_cen_set_inband_addr

} // extern "C"

/*
*************** Do not edit this area ***************
This section is automatically updated by CVS when you check in this file.
Be sure to create CVS comments when you commit so that they can be included here.
$Log: proc_cen_set_inband_addr.C,v $
Revision 1.8  2014/02/05 17:34:30  mfred
Changed include statements to use <> instead of double-quotes.

Revision 1.7  2012/11/30 15:33:50  mfred
Several updates suggested by gerrit code review.  Get rid of unused attribute reference.  Change name of inband bar attribute.

Revision 1.6  2012/11/15 20:15:01  mfred
Update the hwp to take real address from attribute and modify value for BAR register.

Revision 1.5  2012/11/06 17:11:36  mfred
Procedure now gets the BAR value from the attribute.

Revision 1.4  2012/10/24 15:32:27  mfred
Temporarilly hardcode the BAR value until the attribute is ready.

Revision 1.3  2012/10/11 14:36:24  mfred
Updated code to write to MCS MCFGPR Regsiter.

Revision 1.2  2012/10/10 21:11:15  mfred
Check in some updates to two new procedures.


*/

