/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_initialization/proc_setup_bars/mss_setup_bars.C $ */
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
// $Id: mss_setup_bars.C,v 1.33 2013/09/20 14:07:42 jmcgill Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
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
// function: mss_setup_bars HWP entry point
//           NOTE: see comments above function prototype in header
//------------------------------------------------------------------------------
fapi::ReturnCode mss_setup_bars(const fapi::Target& i_pu_target)
{
    fapi::ReturnCode rc;
    std::vector<fapi::Target> l_mcs_chiplets;
    uint32_t group_data[16][16];

    do
    {
        // obtain group configuration attribute for this chip
        rc = FAPI_ATTR_GET(ATTR_MSS_MCS_GROUP_32, &i_pu_target, group_data);
        if (!rc.ok())
        {
            FAPI_ERR("mss_setup_bars: Error reading ATTR_MSS_MCS_GROUP_32");
            break;
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
             iter != l_mcs_chiplets.end() && rc.ok();
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
                 (i <= MSS_MCS_GROUP_32_NM_END_INDEX) && rc.ok();
                 i++)
            {
                // only process valid groups
                if (group_data[i][MSS_MCS_GROUP_32_SIZE_INDEX] == 0)
                {
                    continue;
                }

                uint32_t mcs_in_group = group_data[i][MSS_MCS_GROUP_32_MCS_IN_GROUP_INDEX];
                for (size_t j = MSS_MCS_GROUP_32_MEMBERS_START_INDEX;
                     (j < MSS_MCS_GROUP_32_MEMBERS_START_INDEX+mcs_in_group) &&
                     (rc.ok());
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
            bool m_bar_valid = false;
            uint8_t m_bar_group_index = 0x0;
            for (size_t i = MSS_MCS_GROUP_32_M_START_INDEX;
                 (i <= MSS_MCS_GROUP_32_M_END_INDEX) && rc.ok();
                 i++)
            {
                // only process valid groups
                if (group_data[i-8][MSS_MCS_GROUP_32_SIZE_INDEX] == 0)
                {
                    continue;
                }

                uint32_t mcs_in_group = group_data[i-8][MSS_MCS_GROUP_32_MCS_IN_GROUP_INDEX];
                for (size_t j = MSS_MCS_GROUP_32_MEMBERS_START_INDEX;
                     (j < MSS_MCS_GROUP_32_MEMBERS_START_INDEX+mcs_in_group) &&
                     (rc.ok());
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
