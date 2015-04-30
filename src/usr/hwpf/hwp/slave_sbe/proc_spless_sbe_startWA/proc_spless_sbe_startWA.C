/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_spless_sbe_startWA/proc_spless_sbe_startWA.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2015                        */
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
// $Id: proc_spless_sbe_startWA.C,v 1.2 2015/08/05 14:19:34 baiocchi Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_spless_sbe_startWA.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2013
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
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
//             i_sbeSeepromSelect  => SBE Seeprom Select Bit
// returns:    FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_spless_sbe_startWA(const fapi::Target & i_target,
                                         const bool  i_sbeSeepromSelect)
{

    uint32_t           rc_ecmd = 0;
    fapi::ReturnCode   rc;
    uint32_t           l_set_data;
    ecmdDataBufferBase  set_data(32);

    // mark start of function
    FAPI_INF("proc_spless_sbe_startWA: Enter: i_sbeSeepromSelect=%d", i_sbeSeepromSelect);

    do {

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
        // Enable output to ATTN pin to monitor for checkstops (3 commands)
        // - putcfam pu 0x081C 20000000
        FAPI_INF(   "Enable output to ATTN pin to monitor for checkstops");

        rc_ecmd |= set_data.setWord( 0, 0x20000000 );

        rc = fapiPutCfamRegister( i_target,
                                  CFAM_FSI_INTR_MASK_0x0000081C,
                                  set_data    );
        if (rc)
        {
            FAPI_ERR("ERROR: write CFAM_FSI_INTR_MASK_0x0000081C= 0x%08x",
                     static_cast<uint32_t>(rc) );
            break;
        }

        // - putcfam pu 0x100D 40000000
        rc_ecmd |= set_data.setWord( 0, 0x40000000 );

        rc = fapiPutCfamRegister( i_target,
                                  CFAM_FSI_TRUE_MASK_0x0000100D,
                                  set_data    );
        if (rc)
        {
            FAPI_ERR("ERROR: write CFAM_FSI_TRUE_MASK_0x0000100D= 0x%08x",
                     static_cast<uint32_t>(rc) );
            break;
        }


        // - putcfam pu  0x100B FFFFFFFF
        rc_ecmd |= set_data.setWord( 0, 0xFFFFFFFF );

        rc = fapiPutCfamRegister( i_target,
                                  CFAM_FSI_INTR_STATUS_0x0000100B,
                                  set_data    );
        if (rc)
        {
            FAPI_ERR("ERROR: write CFAM_FSI_INTR_STATUS_0x0000100B= 0x%08x",
                     static_cast<uint32_t>(rc) );
            break;
        }



        // -----------------------------------------------
        // Now toggle Warmstart bit to circumvent HW254584
        // -- set bit 8 to select SBE Image to boot from
        if (i_sbeSeepromSelect == true)
        {
            rc_ecmd |= set_data.setWord( 0, 0x30800000 );
        }
        else
        {
            rc_ecmd |= set_data.setWord( 0, 0x30000000 );
        }
        FAPI_INF(   "Write 0x%08x to SBE VITAL to toggle Warmstart bit",
                    set_data.getWord(0)   );

        rc = fapiPutCfamRegister( i_target,
                                  CFAM_FSI_SBE_VITAL_0x0000281C,
                                  set_data    );
        if (rc)
        {
            FAPI_ERR("ERROR: write CFAM_FSI_SBE_VITAL_0x0000281C= 0x%08x",
                     static_cast<uint32_t>(rc) );
            break;
        }

        // -----------------------------------------------
        // Now start SBE
        // -- set bit 8 to select SBE Image to boot from
        if (i_sbeSeepromSelect == true)
        {
            rc_ecmd |= set_data.setWord( 0, 0xB0800000 );
        }
        else
        {
            rc_ecmd |= set_data.setWord( 0, 0xB0000000 );
        }

        FAPI_INF(   "Write 0x%08x to SBE VITAL start SBE",
                    set_data.getWord(0)   );

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
