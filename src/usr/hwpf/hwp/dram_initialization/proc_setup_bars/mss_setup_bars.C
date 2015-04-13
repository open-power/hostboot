/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_initialization/proc_setup_bars/mss_setup_bars.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
// $Id: mss_setup_bars.C,v 1.44 2015/03/19 15:30:38 gpaulraj Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *!
// *! TITLE       : mss_setup_bars.C
// *! DESCRIPTION : Program MCS base address registers (BARs) (FAPI)
// *!
// *! OWNER NAME  : Girisankar Paulraj      Email: gpaulraj@in.ibm.com
// *! OWNER NAME  : Mark Bellows            Email: bellows@us.ibm.com
// *!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//  1.43   | gpaulraj | 03/19/15| fix SW296125 - modified k as k = 0
//  1.42   | gpaulraj | 05/21/14| fixed on 1 MCS mirror BAR EN  issue -SW261358
//  1.40   | gpaulraj | 05/06/14| fixed on mirror configuration issue
//  1.39   | gpaulraj | 04/08/14| 5/5 FW review feedback - gerrit process - SW251227
//  1.33   |          | 03/09/14| RAS review
//  1.32   | gpaulraj | 08/16/13| fixed code
//  1.31   | gpaulraj | 08/13/13| fix HW259884 Mirror BAR Scom Parity Error
//  1.30   | gpaulraj | 08/13/13| added fix HW259884 Mirror BAR Scom Parity Error
//  1.29   | gpaulraj | 08/12/13| fixed mirror BAR issues
//  1.27   | jmcgill  | 05/21/13| address FW review issues
//  1.26   | jmcgill  | 04/22/13| rewrite to line up with attribute changes
//  1.23   | bellows  | 12/04/12| more updates
//  1.22   | gpaulraj | 10/03/12| review updates
//  1.21   | gpaulraj | 10/02/12| review updates
//  1.19   | bellows  | 09/25/12| review updates
//  1.18   | bellows  | 09/06/12| updates suggested by Van
//  1.17   | bellows  | 08/31/12| use the final 32bit attribute
//  1.16   | bellows  | 08/29/12| remove compile error, use 32bit group info
//         |          |         | as a temporary fix
//  1.10   | bellows  | 07/16/12| added in Id tag
//  1.4    | bellows  | 06-05-12| Updates to Match First Configuration, work for
//         |          |         | P8 and Murano
//  1.3    | gpaulraj | 05-22-12| 2MCS/group supported for 128GB CDIMM
//  1.2    | gpaulraj | 05-07-12| 256 group configuration in
//  1.1    | gpaulraj | 03-19-12| First drop for centaur
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------

#include <mss_setup_bars.H>


//------------------------------------------------------------------------------
//  Function definitions
//------------------------------------------------------------------------------

extern "C" {


const int SETUP_BARS_MBA_SIZE_MCS=8;
const int SETUP_BARS_MBA_SIZE_PORT=2;
struct MssSetupBarsSizeInfo{
   uint8_t MBA_size[SETUP_BARS_MBA_SIZE_MCS][SETUP_BARS_MBA_SIZE_PORT]; // mcs, mba pairs, port, dimm
   uint32_t MCS_size[SETUP_BARS_MBA_SIZE_MCS];
};

//------------------------------------------------------------------------------
// function: write non-mirrored BAR registers (MCFGP/MCFGPA) for a single MCS
// parameters: i_mcs_target      => MCS chiplet target
//             i_pri_valid       => true if MCS primary non-mirrored BAR
//                                  should be marked valid
//             i_group_member_id => group member ID (only valid if
//                                  i_pri_valid=true)
//             i_group_data      => MSS_MCS_GROUP_32 attribute data
//                                  for member group (only valid if
//                                  i_pri_valid=true)
// returns: FAPI_RC_SUCCESS if all register writes are successful,
//          else failing return code
//------------------------------------------------------------------------------
fapi::ReturnCode mss_setup_bars_init_nm_bars(
    const fapi::Target& i_mcs_target,
    bool i_pri_valid,
    uint32_t i_group_member_id,
    uint32_t i_group_data[])
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;

    ecmdDataBufferBase MCFGP(64);
    ecmdDataBufferBase MCFGPA(64);

    // Defect HW259884 (AddNote by retter) P8 Lab Brazos: Mirror BAR Scom Parity Error - workaround
    ecmdDataBufferBase MCIFIR(64);
    ecmdDataBufferBase MCIFIRMASK(64);
    ecmdDataBufferBase MCSMODE4(64);

    do
    {
        rc = fapiGetScom(i_mcs_target, MCS_MCIFIRMASK_0x02011843, MCIFIRMASK);
        if (!rc.ok())
        {
             FAPI_ERR("mss_setup_bars_init_nm_bars: Error from fapiGetScom (MCS_MCIFIRMASK_0x02011843");
             break;
        }
        // Mask MCIFIR bit 25
        rc_ecmd |= MCIFIRMASK.setBit(25);
        if (rc_ecmd)
        {
             FAPI_ERR("mss_setup_bars_init_nm_bars: Error 0x%X setting up MCIFIRMASK data buffer",
                         rc_ecmd);
             rc.setEcmdError(rc_ecmd);
             break;
        }
        rc = fapiPutScom(i_mcs_target, MCS_MCIFIRMASK_0x02011843, MCIFIRMASK);
        if (!rc.ok())
        {
             FAPI_ERR("mss_setup_bars_init_nm_bars: Error from fapiPutScom (MCS_MCIFIRMASK_0x02011843");
             break;
        }

        // establish base content for MCFGP register
        rc_ecmd |= MCFGP.setBit(MCFGP_ENABLE_RCMD0_BIT);
        rc_ecmd |= MCFGP.setBit(MCFGP_ENABLE_RCMD1_BIT);
        rc_ecmd |= MCFGP.setBit(MCFGP_RSVD_1_BIT);
        rc_ecmd |= MCFGP.setBit(MCFGP_ENABLE_FASTPATH_BIT);

        // check buffer manipulation return codes
        if (rc_ecmd)
        {
            FAPI_ERR("mss_setup_bars_init_nm_bars: Error 0x%X setting up MCFGP base data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        if (i_pri_valid)
        {
            // MCFGPQ_VALID
            rc_ecmd |= MCFGP.setBit(MCFGP_VALID_BIT);
            // MCFGPQ_MCS_UNITS_PER_GROUP
            rc_ecmd |= MCFGP.insertFromRight(
                i_group_data[MSS_MCS_GROUP_32_MCS_IN_GROUP_INDEX] / 2,
                MCFGP_MCS_UNITS_PER_GROUP_START_BIT,
                (MCFGP_MCS_UNITS_PER_GROUP_END_BIT-
                 MCFGP_MCS_UNITS_PER_GROUP_START_BIT)+1);
            // MCFGPQ_GROUP_MEMBER_IDENTIFICATION
            rc_ecmd |= MCFGP.insertFromRight(
                i_group_member_id,
                MCFGP_GROUP_MEMBER_ID_START_BIT,
                (MCFGP_GROUP_MEMBER_ID_END_BIT-
                 MCFGP_GROUP_MEMBER_ID_START_BIT)+1);
            // MCFGPQ_GROUP_SIZE
            rc_ecmd |= MCFGP.insertFromRight(
                (i_group_data[MSS_MCS_GROUP_32_SIZE_INDEX]/4)-1,
                MCFGP_GROUP_SIZE_START_BIT,
                (MCFGP_GROUP_SIZE_END_BIT-
                 MCFGP_GROUP_SIZE_START_BIT)+1);

            // MCFGPQ_BASE_ADDRESS_OF_GROUP
            rc_ecmd |= MCFGP.insertFromRight(
                i_group_data[MSS_MCS_GROUP_32_BASE_INDEX] >> 2,
                MCFGP_BASE_ADDRESS_START_BIT,
                (MCFGP_BASE_ADDRESS_END_BIT-
                 MCFGP_BASE_ADDRESS_START_BIT)+1);

            // check buffer manipulation return codes
            if (rc_ecmd)
            {
                FAPI_ERR("mss_setup_bars_init_nm_bars: Error 0x%X setting up MCFGP data buffer",
                         rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }

            bool alt_valid = i_group_data[MSS_MCS_GROUP_32_ALT_VALID_INDEX];
            if (alt_valid)
            {
                if (i_group_data[MSS_MCS_GROUP_32_ALT_BASE_INDEX] !=
                    (i_group_data[MSS_MCS_GROUP_32_BASE_INDEX] +
                     (i_group_data[MSS_MCS_GROUP_32_SIZE_INDEX]/2)))
                {
                    FAPI_ERR("mss_setup_bars_init_nm_bars: Invalid non-mirrored alternate BAR configuration");
                    const uint32_t & ALT_BASE_INDEX = i_group_data[MSS_MCS_GROUP_32_ALT_BASE_INDEX];
                    const uint32_t & BASE_INDEX = i_group_data[MSS_MCS_GROUP_32_BASE_INDEX];
	            const uint32_t & SIZE_INDEX= i_group_data[MSS_MCS_GROUP_32_SIZE_INDEX];
                    FAPI_SET_HWP_ERROR(rc,
                                       RC_MSS_SETUP_BARS_NM_ALT_BAR_ERR);
                    break;
                }

                // MCFGPAQ_VALID
                rc_ecmd |= MCFGPA.setBit(MCFGPA_VALID_BIT);

                // MCFGPAQ_GROUP_SIZE
                rc_ecmd |= MCFGPA.insertFromRight(
                    (i_group_data[MSS_MCS_GROUP_32_ALT_SIZE_INDEX]/4)-1,
                    MCFGPA_GROUP_SIZE_START_BIT,
                    (MCFGPA_GROUP_SIZE_END_BIT-
                     MCFGPA_GROUP_SIZE_START_BIT)+1);

                // MCFGPAQ_BASE_ADDRESS_OF_GROUP
                rc_ecmd |= MCFGPA.insertFromRight(
                    i_group_data[MSS_MCS_GROUP_32_ALT_BASE_INDEX] >> 2,
                    MCFGPA_BASE_ADDRESS_START_BIT,
                    (MCFGPA_BASE_ADDRESS_END_BIT-
                     MCFGPA_BASE_ADDRESS_START_BIT)+1);

                // check buffer manipulation return codes
                if (rc_ecmd)
                {
                    FAPI_ERR("mss_setup_bars_init_nm_bars: Error 0x%X setting up MCFGPA data buffer",
                             rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
            }
        }

        // write registers
        rc = fapiPutScom(i_mcs_target, MCS_MCFGP_0x02011800, MCFGP);
        if (!rc.ok())
        {
            FAPI_ERR("mss_setup_bars_init_nm_bars: Error from fapiPutScom (MCS_MCFGP_0x02011800)");
            break;
        }

        rc = fapiPutScom(i_mcs_target, MCS_MCFGPA_0x02011814, MCFGPA);
        if (!rc.ok())
        {
            FAPI_ERR("mss_setup_bars_init_nm_bars: Error from fapiPutScom (MCS_MCFGPA_0x02011814)");
            break;
        }

        rc = fapiGetScom(i_mcs_target, MCS_MCSMODE4_0x0201181A, MCSMODE4);
        if (!rc.ok())
        {
             FAPI_ERR("mss_setup_bars_init_nm_bars: Error from fapiGetScom (MCS_MCSMODE4_0x0201181A");
             break;
        }
        // set MCSMODE4 bit 0
        rc_ecmd |= MCSMODE4.setBit(0);
        rc = fapiPutScom(i_mcs_target, MCS_MCSMODE4_0x0201181A, MCSMODE4);
        if (!rc.ok())
        {
             FAPI_ERR("mss_setup_bars_init_nm_bars: Error from fapiPutScom (MCS_MCSMODE4_0x0201181A");
             break;
        }
        // Clear MCSMODE4 bit 0
        rc_ecmd |= MCSMODE4.clearBit(0);
        rc = fapiPutScom(i_mcs_target, MCS_MCSMODE4_0x0201181A, MCSMODE4);
        if (!rc.ok())
        {
             FAPI_ERR("mss_setup_bars_init_nm_bars: Error from fapiPutScom (MCS_MCSMODE4_0x0201181A");
             break;
        }

        rc = fapiGetScom(i_mcs_target, MCS_MCIFIR_0x02011840, MCIFIR);
        if (!rc.ok())
        {
             FAPI_ERR("mss_setup_bars_init_nm_bars: Error from fapiGetScom (MCS_MCIFIR_0x02011840");
             break;
        }
        // Reset MCIFIR bit 25
        rc_ecmd |= MCIFIR.clearBit(25);
        rc = fapiPutScom(i_mcs_target, MCS_MCIFIR_0x02011840, MCIFIR);
        if (!rc.ok())
        {
             FAPI_ERR("mss_setup_bars_init_nm_bars: Error from fapiPutScom (MCS_MCIFIR_0x02011840");
             break;
        }

        rc = fapiGetScom(i_mcs_target, MCS_MCIFIRMASK_0x02011843, MCIFIRMASK);
        if (!rc.ok())
        {
             FAPI_ERR("mss_setup_bars_init_nm_bars: Error from fapiGetScom (MCS_MCIFIRMASK_0x02011843");
             break;
        }
        // Unmask MCIFIR bit 25
        rc_ecmd |= MCIFIRMASK.clearBit(25);
        rc = fapiPutScom(i_mcs_target, MCS_MCIFIRMASK_0x02011843, MCIFIRMASK);
        if (!rc.ok())
        {
             FAPI_ERR("mss_setup_bars_init_nm_bars: Error from fapiPutScom (MCS_MCIFIRMASK_0x02011843");
             break;
        }
    } while(0);

    return rc;
}


//------------------------------------------------------------------------------
// function: write mirrored BAR registers (MCFGPM/MCFGPMA) for a single MCS
// parameters: i_mcs_target => MCS chiplet target
//             i_pri_valid  => true if MCS primary mirrored BAR
//                             should be marked valid
//             i_group_data => MSS_MCS_GROUP_32 attribute data
//                             for member group (only valid if
//                             i_pri_valid=true)
// returns: FAPI_RC_SUCCESS if all register writes are successful,
//          else failing return code
//------------------------------------------------------------------------------
fapi::ReturnCode mss_setup_bars_init_m_bars(
    const fapi::Target& i_mcs_target,
    bool i_pri_valid,
    uint32_t i_group_data[])
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;

    ecmdDataBufferBase MCFGPM(64);
    ecmdDataBufferBase MCFGPMA(64);

    // Defect HW259884 (AddNote by retter) P8 Lab Brazos: Mirror BAR Scom Parity Error - workaround
    ecmdDataBufferBase MCIFIR(64);
    ecmdDataBufferBase MCIFIRMASK(64);
    ecmdDataBufferBase MCSMODE4(64);
    do
    {

        rc = fapiGetScom(i_mcs_target, MCS_MCIFIRMASK_0x02011843, MCIFIRMASK);
        if (!rc.ok())
        {
             FAPI_ERR("mss_setup_bars_init_m_bars: Error from fapiGetScom (MCS_MCIFIRMASK_0x02011843");
             break;
        }
        // Mask MCIFIR bit 25
        rc_ecmd |= MCIFIRMASK.setBit(25);
        if (rc_ecmd)
        {
             FAPI_ERR("mss_setup_bars_init_m_bars: Error 0x%X setting up MCIFIRMASK data buffer",
                         rc_ecmd);
             rc.setEcmdError(rc_ecmd);
             break;
        }
        rc = fapiPutScom(i_mcs_target, MCS_MCIFIRMASK_0x02011843, MCIFIRMASK);
        if (!rc.ok())
        {
             FAPI_ERR("mss_setup_bars_init_m_bars: Error from fapiPutScom (MCS_MCIFIRMASK_0x02011843");
             break;
        }
        if (i_pri_valid)
        {

            // MCFGPMQ_VALID
            rc_ecmd |= MCFGPM.setBit(MCFGPM_VALID_BIT);
            // MCFGPMQ_GROUP_SIZE
            rc_ecmd |= MCFGPM.insertFromRight(
                (i_group_data[MSS_MCS_GROUP_32_SIZE_INDEX]/4)-1,
                MCFGPM_GROUP_SIZE_START_BIT,
                (MCFGPM_GROUP_SIZE_END_BIT-
                 MCFGPM_GROUP_SIZE_START_BIT)+1);

            // MCFGPMQ_BASE_ADDRESS_OF_GROUP
            rc_ecmd |= MCFGPM.insertFromRight(
                i_group_data[MSS_MCS_GROUP_32_BASE_INDEX] >> 2,
                MCFGPM_BASE_ADDRESS_START_BIT,
                (MCFGPM_BASE_ADDRESS_END_BIT-
                 MCFGPM_BASE_ADDRESS_START_BIT)+1);

            // check buffer manipulation return codes
            if (rc_ecmd)
            {
                FAPI_ERR("mss_setup_bars_init_m_bars: Error 0x%X setting up MCFGPM data buffer",
                         rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }

            bool alt_valid = i_group_data[MSS_MCS_GROUP_32_ALT_VALID_INDEX];
            if (alt_valid)
            {
                // MCFGPMAQ_VALID
                rc_ecmd |= MCFGPMA.setBit(MCFGPMA_VALID_BIT);

                // MCFGPMAQ_GROUP_SIZE
                rc_ecmd |= MCFGPMA.insertFromRight(
                    (i_group_data[MSS_MCS_GROUP_32_ALT_SIZE_INDEX]/4)-1,
                    MCFGPMA_GROUP_SIZE_START_BIT,
                    (MCFGPMA_GROUP_SIZE_END_BIT-
                     MCFGPMA_GROUP_SIZE_START_BIT)+1);

                // MCFGPMAQ_BASE_ADDRESS_OF_GROUP
                rc_ecmd |= MCFGPMA.insertFromRight(
                    i_group_data[MSS_MCS_GROUP_32_ALT_BASE_INDEX] >> 2,
                    MCFGPMA_BASE_ADDRESS_START_BIT,
                    (MCFGPMA_BASE_ADDRESS_END_BIT-
                     MCFGPMA_BASE_ADDRESS_START_BIT)+1);

                if (i_group_data[MSS_MCS_GROUP_32_ALT_BASE_INDEX] !=
                    (i_group_data[MSS_MCS_GROUP_32_BASE_INDEX] +
                     (i_group_data[MSS_MCS_GROUP_32_SIZE_INDEX]/2)))
                {
                    FAPI_ERR("mss_setup_bars_init_m_bars: Invalid mirrored alternate BAR configuration");
                    const uint32_t & ALT_BASE_INDEX = i_group_data[MSS_MCS_GROUP_32_ALT_BASE_INDEX];
		    const uint32_t & BASE_INDEX = i_group_data[MSS_MCS_GROUP_32_BASE_INDEX];
		    const uint32_t & SIZE_INDEX= i_group_data[MSS_MCS_GROUP_32_SIZE_INDEX];
                    FAPI_SET_HWP_ERROR(rc,
                                       RC_MSS_SETUP_BARS_M_ALT_BAR_ERR);
                    break;
                }
            }

            // check buffer manipulation return codes
            if (rc_ecmd)
            {
                FAPI_ERR("mss_setup_bars_init_m_bars: Error 0x%X setting up MCFGPMA data buffer",
                         rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
        }

        // write registers
        rc = fapiPutScom(i_mcs_target, MCS_MCFGPM_0x02011801, MCFGPM);
        if (!rc.ok())
        {
            FAPI_ERR("mss_setup_bars_init_m_bars: Error from fapiPutScom (MCS_MCFGPM_0x02011801)");
            break;
        }
        rc = fapiPutScom(i_mcs_target, MCS_MCFGPMA_0x02011815, MCFGPMA);
        if (!rc.ok())
        {
            FAPI_ERR("mss_setup_bars_init_m_bars: Error from fapiPutScom (MCS_MCFGPMA_0x02011815");
            break;
        }

        rc = fapiGetScom(i_mcs_target, MCS_MCSMODE4_0x0201181A, MCSMODE4);
        if (!rc.ok())
        {
             FAPI_ERR("mss_setup_bars_init_m_bars: Error from fapiGetScom (MCS_MCSMODE4_0x0201181A");
             break;
        }
        // set MCSMODE4 bit 0
        rc_ecmd |= MCSMODE4.setBit(0);
        rc = fapiPutScom(i_mcs_target, MCS_MCSMODE4_0x0201181A, MCSMODE4);
        if (!rc.ok())
        {
             FAPI_ERR("mss_setup_bars_init_m_bars: Error from fapiPutScom (MCS_MCSMODE4_0x0201181A");
             break;
        }
        // Clear MCSMODE4 bit 0
        rc_ecmd |= MCSMODE4.clearBit(0);
        rc = fapiPutScom(i_mcs_target, MCS_MCSMODE4_0x0201181A, MCSMODE4);
        if (!rc.ok())
        {
             FAPI_ERR("mss_setup_bars_init_m_bars: Error from fapiPutScom (MCS_MCSMODE4_0x0201181A");
             break;
        }

        rc = fapiGetScom(i_mcs_target, MCS_MCIFIR_0x02011840, MCIFIR);
        if (!rc.ok())
        {
             FAPI_ERR("mss_setup_bars_init_m_bars: Error from fapiGetScom (MCS_MCIFIR_0x02011840");
             break;
        }
        // Reset MCIFIR bit 25
        rc_ecmd |= MCIFIR.clearBit(25);
        rc = fapiPutScom(i_mcs_target, MCS_MCIFIR_0x02011840, MCIFIR);
        if (!rc.ok())
        {
             FAPI_ERR("mss_setup_bars_init_m_bars: Error from fapiPutScom (MCS_MCIFIR_0x02011840");
             break;
        }

        rc = fapiGetScom(i_mcs_target, MCS_MCIFIRMASK_0x02011843, MCIFIRMASK);
        if (!rc.ok())
        {
             FAPI_ERR("mss_setup_bars_init_m_bars: Error from fapiGetScom (MCS_MCIFIRMASK_0x02011843");
             break;
        }
        // Unmask MCIFIR bit 25
        rc_ecmd |= MCIFIRMASK.clearBit(25);
        rc = fapiPutScom(i_mcs_target, MCS_MCIFIRMASK_0x02011843, MCIFIRMASK);
        if (!rc.ok())
        {
             FAPI_ERR("mss_setup_bars_init_m_bars: Error from fapiPutScom (MCS_MCIFIRMASK_0x02011843");
             break;
        }
    } while(0);

    return rc;
}


//------------------------------------------------------------------------------
// function: mss_setup_bars_mcs_size
//------------------------------------------------------------------------------
fapi::ReturnCode mss_setup_bars_mcs_size(  const fapi::Target & i_target,std::vector<fapi::Target> & i_associated_centaurs, MssSetupBarsSizeInfo & io_sizeInfo)
{
      fapi::ReturnCode rc;
      uint8_t centaur;
      uint8_t mba_i;
      uint8_t mba=0;
      uint8_t dimm=0;
      uint32_t cenpos;
      uint32_t procpos;
      uint8_t port;
       uint32_t l_unit_pos =0;
       uint8_t min_group = 1;
      uint8_t mba_pos[2][2] = { {0, 0},{0,0}};
      std::vector<fapi::Target> l_mba_chiplets;
      uint8_t cen_count=0;
      rc = FAPI_ATTR_GET(ATTR_POS,&i_target, procpos);
      if(rc) return rc;
      for(centaur= 0; centaur < i_associated_centaurs.size(); centaur++) {
        mba=0;port=0;dimm=0;
        fapi::Target & centaur_t = i_associated_centaurs[centaur];
        rc = FAPI_ATTR_GET(ATTR_POS,&centaur_t, cenpos);
        if(rc) return rc;
        if(cenpos>=procpos*8 && cenpos<(procpos*8+8)){
                FAPI_INF("... working on centaur %d", cenpos);
                io_sizeInfo.MCS_size[cenpos - procpos * 8]=0;
                rc = fapiGetChildChiplets(i_associated_centaurs[centaur], fapi::TARGET_TYPE_MBA_CHIPLET, l_mba_chiplets);
                if(rc) return rc;
                for(mba_i=0; mba_i<l_mba_chiplets.size(); mba_i++) {

                  rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &l_mba_chiplets[mba_i], mba);
                  if(rc) return rc;
                  FAPI_INF("... working on mba %d", mba);
                  rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_SIZE, &l_mba_chiplets[mba_i],mba_pos);
                  if(rc) return rc;
                  for(port = 0; port<2; port++)
                  {	
                    for(dimm=0; dimm<2; dimm++) {
                       io_sizeInfo.MCS_size[cenpos - procpos * 8]+=mba_pos[port][dimm];
                       io_sizeInfo.MBA_size[cenpos - procpos * 8][mba] += mba_pos[port][dimm];
                    }
                  }

                  FAPI_INF(" Cen Pos %d mba %d DIMM SIZE %d \n",cenpos,mba, io_sizeInfo.MBA_size[cenpos - procpos * 8][mba]);
                  FAPI_INF(" Cen Pos %d MBA SIZE %d %d  %d %d \n",cenpos, mba_pos[0][0],mba_pos[0][1],mba_pos[1][0],mba_pos[1][1]);
                  FAPI_INF(" MCS SIZE %d\n",io_sizeInfo.MCS_size[cenpos - procpos * 8]);
            }
            cen_count++;l_unit_pos++;
        }
      }
      FAPI_INF("attr_mss_setting %d and  no  of MBAs   %d \n",min_group,l_unit_pos);
     return rc;
}

//------------------------------------------------------------------------------
// function: mss_setup_bars HWP entry point
//           NOTE: see comments above function prototype in header
//------------------------------------------------------------------------------
fapi::ReturnCode mss_setup_bars(const fapi::Target& i_pu_target,   std::vector<fapi::Target> & i_associated_centaurs)
{
    fapi::ReturnCode rc;
    std::vector<fapi::Target> l_mcs_chiplets;
    uint32_t group_data[16][16];
    uint8_t M_valid;
    MssSetupBarsSizeInfo sizeInfo;
    do
    {

        rc= mss_setup_bars_mcs_size(i_pu_target,i_associated_centaurs, sizeInfo);
        // obtain group configuration attribute for this chip
        rc = FAPI_ATTR_GET(ATTR_MSS_MCS_GROUP_32, &i_pu_target, group_data);
        if (!rc.ok())
        {
            FAPI_ERR("mss_setup_bars: Error reading ATTR_MSS_MCS_GROUP_32");
            break;
        }
        rc = FAPI_ATTR_GET(ATTR_MRW_ENHANCED_GROUPING_NO_MIRRORING, NULL, M_valid);
        if (!rc.ok())
        {
            FAPI_ERR("mss_setup_bars: Error reading ATTR_MRW_ENHANCED_GROUPING_NO_MIRRORING");
            break;
        }


         //check if all the grouped mcs are valid
         for (size_t i = MSS_MCS_GROUP_32_NM_START_INDEX;
                (i <= MSS_MCS_GROUP_32_NM_END_INDEX);
                i++)
           {
               // only process valid groups
               if (group_data[i][MSS_MCS_GROUP_32_SIZE_INDEX] == 0)
               {
                   continue;
               }

               uint32_t mcs_in_group = group_data[i][MSS_MCS_GROUP_32_MCS_IN_GROUP_INDEX];

               uint32_t mcs_sz = group_data[i][0];
               for (size_t j = MSS_MCS_GROUP_32_MEMBERS_START_INDEX;
                    (j < MSS_MCS_GROUP_32_MEMBERS_START_INDEX+mcs_in_group);
                    j++)
               {
                    if(mcs_sz !=  sizeInfo.MCS_size[group_data[i][j]])
                    {
                          FAPI_INF(" Group %zd will not be configured as MCS %d is not valid grouped size is %d , present MCS size is %d \n",i,group_data[i][j],mcs_sz, sizeInfo.MCS_size[group_data[i][j]]);
                          for(uint8_t k = 0; k<32;k++) { group_data[i][k]=0; }
                     }
               }
           }
        // get child MCS chiplets
        rc = fapiGetChildChiplets(i_pu_target,
                                  fapi::TARGET_TYPE_MCS_CHIPLET,
                                  l_mcs_chiplets,
                                  fapi::TARGET_STATE_FUNCTIONAL);
        if (!rc.ok())
        {
            FAPI_ERR("mss_setup_bars: Error from fapiGetChildChiplets");
            break;
        }

        // loop through & set configuration of each MCS chiplet
        for (std::vector<fapi::Target>::iterator iter = l_mcs_chiplets.begin();
             iter != l_mcs_chiplets.end();
             iter++)
        {
            // obtain MCS chip unit number
            uint8_t mcs_pos = 0x0;
            rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &(*iter), mcs_pos);
            if (!rc.ok())
            {
                FAPI_ERR("mss_setup_bars: Error reading ATTR_CHIP_UNIT_POS");
                break;
            }

            // determine non-mirrored member group
            bool nm_bar_valid = false;
            uint8_t nm_bar_group_index = 0x0;
            uint8_t nm_bar_group_member_id = 0x0;
            for (size_t i = MSS_MCS_GROUP_32_NM_START_INDEX;
                 (i <= MSS_MCS_GROUP_32_NM_END_INDEX);
                 i++)
            {
                // only process valid groups
                if (group_data[i][MSS_MCS_GROUP_32_SIZE_INDEX] == 0)
                {
                    continue;
                }

                uint32_t mcs_in_group = group_data[i][MSS_MCS_GROUP_32_MCS_IN_GROUP_INDEX];


                for (size_t j = MSS_MCS_GROUP_32_MEMBERS_START_INDEX;
                     (j < MSS_MCS_GROUP_32_MEMBERS_START_INDEX+mcs_in_group);
                     j++)
                {
                    if (mcs_pos == group_data[i][j])
                    {
                        if (nm_bar_valid)
                        {
                            const uint8_t& MCS_POS = mcs_pos;
                            const uint8_t& GROUP_INDEX_A = nm_bar_group_index;
                            const uint8_t& GROUP_INDEX_B = i;
                            FAPI_ERR("mss_setup_bars: MCS %d is listed as a member in multiple non-mirrored groups",
                                     mcs_pos);
                            FAPI_SET_HWP_ERROR(
                                rc,
                                RC_MSS_SETUP_BARS_MULTIPLE_GROUP_ERR);
                            break;
                        }
                        nm_bar_valid = true;
                        nm_bar_group_index = i;
                        nm_bar_group_member_id =
                            j-MSS_MCS_GROUP_32_MEMBERS_START_INDEX;
                    }
                }
                if (!rc.ok())
                {
                    break;
                }
            }
            if (!rc.ok())
            {
                break;
            }

            // write non-mirrored BARs based on group configuration
            rc = mss_setup_bars_init_nm_bars(
                *iter,
                nm_bar_valid,
                nm_bar_group_member_id,
                group_data[nm_bar_group_index]);
            if (!rc.ok())
            {
                FAPI_ERR("mss_setup_bars: Error from mss_setup_bars_init_nm_bars");
                break;
            }

            // determine mirrored member group
            if(!M_valid)
	    {
            	bool m_bar_valid = false;
            	uint8_t m_bar_group_index = 0x0;
            	for (size_t i = MSS_MCS_GROUP_32_M_START_INDEX;
                 (i <= MSS_MCS_GROUP_32_M_END_INDEX);
                 i++)
            	{
                	// only process valid groups
                 if (group_data[i-8][MSS_MCS_GROUP_32_SIZE_INDEX] == 0)
                    {
                    	continue;
                    }

                 uint32_t mcs_in_group = group_data[i-8][MSS_MCS_GROUP_32_MCS_IN_GROUP_INDEX];
                 if( mcs_in_group > 1)
                 {
                	for (size_t j = MSS_MCS_GROUP_32_MEMBERS_START_INDEX;
                    	 (j < MSS_MCS_GROUP_32_MEMBERS_START_INDEX+mcs_in_group);
                    	 j++)
                	{
                    	   if (mcs_pos == group_data[i-8][j])
                    	   {
                        	if (m_bar_valid)
                        	{
                            	const uint8_t& MCS_POS = mcs_pos;
                            	const uint8_t& GROUP_INDEX_A = m_bar_group_index;
                            	const uint8_t& GROUP_INDEX_B = i;
                            	FAPI_ERR("mss_setup_bars: MCS %d is listed as a member in multiple mirrored groups",
                                     mcs_pos);
                            	FAPI_SET_HWP_ERROR(
                                	rc,
                                 RC_MSS_SETUP_BARS_MULTIPLE_GROUP_ERR);
                            	break;
                       	        }
                        	m_bar_valid = true;
                        	m_bar_group_index = i;
                           }
                	}
            	    if (!rc.ok())
            	    {
                	    break;
            	    }
                  }
            	}
            	if (!rc.ok())
            	{
                	break;
            	}
            	// write mirrored BARs based on group configuration
            	rc = mss_setup_bars_init_m_bars(
                	*iter,
                	m_bar_valid,
                	group_data[m_bar_group_index]);
            	if (!rc.ok())
            	{
                	FAPI_ERR("mss_setup_bars: Error from mss_setup_bars_init_m_bars");
               		 break;
            	}
            }
            // write attribute signifying BARs are valid & MSS inits are finished
            uint8_t final = 1;
            rc = FAPI_ATTR_SET(ATTR_MSS_MEM_IPL_COMPLETE, &i_pu_target, final);
            if (!rc.ok())
            {
               	FAPI_ERR("mss_setup_bars: Error from FAPI_ATTR_SET (ATTR_MSS_MEM_IPL_COMPLETE)");
               	break;
            }

        }
    } while(0);

    return rc;
}


} // extern "C"
