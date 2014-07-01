/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mem_pll_setup/cen_mem_pll_setup.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
// $Id: cen_mem_pll_setup.C,v 1.26 2014/03/19 13:58:05 mfred Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/cen_mem_pll_setup.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE       : cen_mem_pll_setup
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Mark Fredrickson  Email: mfred@us.ibm.com
// *! BACKUP NAME : Mark Bellows      Email: bellows@us.ibm.com
// *! SCREEN      : pervasive_screen
// #! ADDITIONAL COMMENTS :
//
// The purpose of this procedure is to make sure the Centaur MEM PLL locks.
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------

#include <fapi.H>
#include <cen_scom_addresses.H>
#include <cen_mem_pll_setup.H>

//  Constants
const uint64_t  DELAY_100NS             = 100;     // General purpose 100 ns delay for HW mode   (2000 sim cycles if simclk - 20ghz)
const uint64_t  DELAY_2000SIMCYCLES     = 2000;    // General purpose 2000 sim cycle delay for sim mode     (100 ns if simclk = 20Ghz)
const uint16_t  POLL_COUNT_MAX          = 50;      // Number of times to poll for PLL lock before timing out.

// CFAM FSI STATUS register bit/field definitions
const uint8_t FSI_STATUS_MEM_PLL_LOCK_BIT = 25;

// TP LFIR  bit/field definitions
const uint8_t TP_LFIR_ERRORS_FROM_NEST_PLL_LOCK_BIT = 19;
const uint8_t TP_LFIR_ERRORS_FROM_MEM_PLL_LOCK_BIT  = 20;

extern "C" {

using namespace fapi;

fapi::ReturnCode cen_mem_pll_setup(const fapi::Target & i_target)
{
    // Target is centaur
    fapi::ReturnCode rc;
    ecmdDataBufferBase cfam_data(32);
    uint32_t            rc_ecmd = 0;
    ecmdDataBufferBase  scom_data(64);

    uint32_t  poll_count           = 0;
    uint32_t  done_polling         = 0;

    FAPI_INF("********* cen_mem_pll_setup start *********");
    do
    {
        //---------------------------------------
        // Poll for PLL lock bit
        //---------------------------------------
        // Check MEM PLL lock bit (25) in CFAM FSI status register to see if PLL is locked
        // Check bit 25 only.  Bit 25 is for the MEM PLL. (Bit 24 is the PLL lock for NEST PLL)
        FAPI_DBG("Polling on FSI STATUS register bit 25 to see if MEM PLL has locked....\n");
        done_polling = 0;
        poll_count = 0;
        do
        {
            rc = fapiDelay(DELAY_100NS, DELAY_2000SIMCYCLES); // wait 2000 simcycles (in sim mode) OR 100 nS (in hw mode)
            if (rc)
            {
                FAPI_ERR("Error executing fapiDelay of 100ns or 2000simcycles.");
                break;
            }

            rc = fapiGetCfamRegister( i_target, CFAM_FSI_STATUS_0x00001007, cfam_data);
            if (rc)
            {
                FAPI_ERR("Error reading FSI STATUS Regiter 0x00001007.");
                break;
            }
            if ( cfam_data.isBitSet(FSI_STATUS_MEM_PLL_LOCK_BIT) ) done_polling = 1;
            poll_count++;

        } while ((done_polling == 0) && (poll_count < POLL_COUNT_MAX)); // Poll until PLL is locked or max count is reached.
        if (rc) break;    // Go to end of proc if error found inside polling loop.

        if ( (poll_count == POLL_COUNT_MAX) && ( done_polling != 1 ) )
        {
            FAPI_ERR("Centaur MEM PLL failed to lock!  Polling timed out after %d loops.",POLL_COUNT_MAX);
            ecmdDataBufferBase & CFAM_FSI_STATUS = cfam_data;
            const fapi::Target & MEMBUF_CHIP_IN_ERROR = i_target;
            FAPI_SET_HWP_ERROR(rc, RC_CEN_MEM_PLL_SETUP_PLL_LOCK_TIMEOUT);
            break;
        }
        else
        {
            FAPI_INF("Centaur MEM PLL is now locked.");
        }


        FAPI_DBG("Clearing the FIR PLL lock error bits and unmasking TP LFIR PLL lock error bits ...");
        rc_ecmd |= scom_data.flushTo1();
        rc_ecmd |= scom_data.clearBit(TP_LFIR_ERRORS_FROM_NEST_PLL_LOCK_BIT);
        rc_ecmd |= scom_data.clearBit(TP_LFIR_ERRORS_FROM_MEM_PLL_LOCK_BIT);
        if (rc_ecmd)
        {
            FAPI_ERR("Error 0x%x setting up ecmd data buffer to clear TP LFIR PLL Lock bits.", rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom(i_target, TP_PERV_LFIR_AND_0x0104000B, scom_data);
        if (!rc.ok())
        {
            FAPI_ERR("Error writing Pervasive LFIR AND Register.");
            break;
        }
        rc = fapiPutScom(i_target, TP_PERV_LFIR_MASK_AND_0x0104000E, scom_data);
        if (!rc.ok())
        {
            FAPI_ERR("Error writing Pervasive LFIR Mask AND Register.");
            break;
        }


    } while(0);

    FAPI_INF("********* cen_mem_pll_setup complete *********");
    return rc;
}

} //end extern C



/*
*************** Do not edit this area ***************
This section is automatically updated by CVS when you check in this file.
Be sure to create CVS comments when you commit so that they can be included here.
$Log: cen_mem_pll_setup.C,v $
Revision 1.26  2014/03/19 13:58:05  mfred
Update to clear and unmask the PLL lock FIR bits after the PLL locks.  SW249390.

Revision 1.25  2013/11/15 16:30:00  mfred
Changes made by Mike Jones for gerrit review, mostly for improved error handling.

Revision 1.24  2013/03/04 17:56:26  mfred
Add some header comments for BACKUP and SCREEN.

Revision 1.23  2012/08/13 17:16:16  mfred
Adding new hwp cen_mem_pll_initf.

Revision 1.22  2012/07/12 21:16:53  mfred
Remove a lot of simulation-only code, use putspys to set the PLL control ring.

Revision 1.21  2012/07/10 14:30:59  mfred
Commented out some lines.

Revision 1.20  2012/07/05 20:06:43  mfred
But MEM PLL into bypass before scanning in new settings.

Revision 1.19  2012/07/02 16:33:31  mfred
Added MEM PLL settings for simulation.

Revision 1.18  2012/06/27 20:34:39  mfred
Updates to use real MEM PLL instead of var osc.

Revision 1.17  2012/06/25 23:37:54  jeshua
Attempt to fix up the mem pll variable oscillators

Revision 1.16  2012/06/14 19:25:13  mfred
Fixing spelling in comment.

Revision 1.15  2012/06/14 19:07:51  mfred
Added more code for setting real PLL control chain.  Values are still not final.

Revision 1.14  2012/06/13 20:59:58  mfred
Some updates for using real PLL.cen_mem_pll_setup.C

Revision 1.13  2012/06/07 13:52:23  jmcgill
use independent data buffers for cfam/scom accesses

Revision 1.12  2012/06/06 20:05:03  jmcgill
change FSI GP3/GP4/status register accesses from SCOM->CFAM

Revision 1.11  2012/05/31 18:29:17  mfred
Updates for RC checking and error messages, etc.

Revision 1.10  2012/04/26 20:52:57  mfred
add additional comment

Revision 1.9  2012/04/26 14:35:29  mfred
Some fixes.

Revision 1.8  2012/04/06 15:58:20  mfred
Plugged in real error msgs, removed some unneeded actions.

Revision 1.5  2012/04/03 21:35:57  mfred
Many updates for both sim and lab actions.

Revision 1.4  2012/04/02 15:30:43  mfred
removing prcdUtils.H from this dir.

Revision 1.3  2012/03/30 19:11:06  mfred
removing some obsolete files

Revision 1.1  2012/03/23 20:36:03  mfred
Checking in a shell prototype for cen_mem_pll_setup.



*/

