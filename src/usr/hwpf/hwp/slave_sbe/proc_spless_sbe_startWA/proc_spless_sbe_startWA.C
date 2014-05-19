/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_spless_sbe_startWA/proc_spless_sbe_startWA.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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

// $Id: proc_spless_sbe_startWA.C,v 1.2 2013/08/14 20:44:47 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_cen_ref_clk_enable.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2013
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_spless_sbe_startWA.C
// *! DESCRIPTION : Issue workaround for CFAM Reset SBE start (FAPI)
// *!
// *! OWNER  NAME  : Benedikt Geukes         Email: benedikt.geukes@de.ibm.com
// *! BACKUP NAME  : Ralph Koester           Email: rkoester@de.ibm.com
// *!
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "proc_spless_sbe_startWA.H"
#include "p8_scom_addresses.H"
#include "p8_mailbox_utils.H"


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

extern "C"
{


//------------------------------------------------------------------------------
// Hardware Procedure
//------------------------------------------------------------------------------
// parameters: i_target            => chip target (S1/P8)
// returns:    FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_spless_sbe_startWA(const fapi::Target & i_target)
{

    uint32_t           rc_ecmd = 0;
    fapi::ReturnCode   rc;
    uint32_t           l_set_data;
    ecmdDataBufferBase  set_data(32);
    uint8_t l_needSbeStartWA = 0;

    do {

        // ---- check if workaround is needed
        rc = FAPI_ATTR_GET(ATTR_CHIP_EC_FEATURE_CFAM_RESET_SBE_START_WA,
                           &i_target,
                           l_needSbeStartWA);
        if(rc)
        {
            FAPI_ERR("Error querying Chip EC feature: "
                     "ATTR_CHIP_EC_FEATURE_CFAM_RESET_SBE_START_WA");
            break;
        }

        if(!l_needSbeStartWA)
        {
            //Workaround not needed -- break
            break;
        }

        // -----------------------------------------------------------
        //Need to set the I2C speed based in the mailbox reg
        //Since not all 1.x part have the correctly programmed OTPROM
        rc = p8_mailbox_utils_get_mbox2( i_target, l_set_data );
        if (rc)
        {
            FAPI_ERR("ERROR: get_mbox2 = 0x%08x",
                     static_cast<uint32_t>(rc) );
            break;
        }

        rc_ecmd |= set_data.setWord( 0, l_set_data );

        FAPI_INF(   "Write 0x%08x to mbox scratch 2",
                    set_data.getWord(0)   );

        // write it to mbox scratch2
        rc = fapiPutCfamRegister( i_target,
                                  MBOX_SCRATCH_REG1_0x00002839,
                                  set_data    );
        if (rc)
        {
            FAPI_ERR("ERROR: write MBOX_SCRATCH_REG1_0x00002839= 0x%08x",
                     static_cast<uint32_t>(rc) );
            break;
        }

        // ------------------------------------------------
        // Now toggle Warmstart bit to circumvent HW254584
        // write it to mbox scratch2
        rc_ecmd |= set_data.setWord( 0, 0x10000000 );


        rc = fapiPutCfamRegister( i_target,
                                  CFAM_FSI_SBE_VITAL_0x0000281C,
                                  set_data    );
        if (rc)
        {
            FAPI_ERR("ERROR: write CFAM_FSI_SBE_VITAL_0x0000281C= 0x%08x",
                     static_cast<uint32_t>(rc) );
            break;
        }

        rc_ecmd |= set_data.setWord( 0, 0x90000000 );


        rc = fapiPutCfamRegister( i_target,
                                  CFAM_FSI_SBE_VITAL_0x0000281C,
                                  set_data    );
        if (rc)
        {
            FAPI_ERR("ERROR: write CFAM_FSI_SBE_VITAL_0x0000281C= 0x%08x",
                     static_cast<uint32_t>(rc) );
            break;
        }

        if(rc_ecmd)
        {
            FAPI_ERR( "Error (0x%08x) writing value to set_data",
                      rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
    } while(0);  // end do

    // mark function exit
    FAPI_INF("proc_spless_sbe_startWA: Exit");
    return rc;
}  // end FAPI procedure proc_spless_sbe_startWA


} // extern "C"
