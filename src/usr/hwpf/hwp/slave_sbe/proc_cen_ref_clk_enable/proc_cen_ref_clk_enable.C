/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_cen_ref_clk_enable/proc_cen_ref_clk_enable.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: proc_cen_ref_clk_enable.C,v 1.4 2014/04/14 18:57:01 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_cen_ref_clk_enable.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_cen_ref_clk_enable.C
// *! DESCRIPTION : Enable Centaur reference clocks (FAPI)
// *!
// *! OWNER  NAME  : Benedikt Geukes         Email: benedikt.geukes@de.ibm.com
// *! BACKUP NAME  : Ralph Koester           Email: rkoester@de.ibm.com
// *!
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "proc_check_master_sbe_seeprom.H"
#include "proc_cen_ref_clk_enable.H"

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

extern "C"
{


//------------------------------------------------------------------------------
// Hardware Procedure
//------------------------------------------------------------------------------
// parameters: i_target            => chip target
//             i_attached_centaurs => bitmask representing attached Centaur
//                                    positions
// returns:    FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_cen_ref_clk_enable(const fapi::Target & i_target,
                                         const uint8_t i_attached_centaurs)
{

    ecmdDataBufferBase reg_data(32);
    uint32_t           rc_ecmd = 0;
    fapi::ReturnCode   rc;
    bool               is_master = false;
    uint8_t            configured_centaurs = 0x00;
    std::vector<fapi::Target> mcs_targets;


    do
    {
        // determine chip status (master/slave) to differentiate access path to FSI GP8 register
        //   master: SCOM
        //   slave:  CFAM
        rc = proc_check_master_sbe_seeprom(i_target, is_master);
        if (!rc.ok())
        {
            FAPI_ERR("proc_cen_ref_clk_enable: Error from proc_check_master_sbe_seeprom");
            break;
        }

        FAPI_INF("proc_cen_ref_clk_enable: Target %s is %s, attached Centaurs: 0x%02X",
                 i_target.toEcmdString(), (is_master)?("master"):("slave"), i_attached_centaurs);

        // obtain set of functional MCS chiplets
        rc = fapiGetChildChiplets(i_target,
                                  fapi::TARGET_TYPE_MCS_CHIPLET,
                                  mcs_targets,
                                  fapi::TARGET_STATE_FUNCTIONAL);
        if (!rc.ok())
        {
            FAPI_ERR("proc_cen_ref_clk_enable: Error from fapiGetChildChiplets");
            break;
        }

        // loop through MCS chiplets, match with attached Centaurs
        for (std::vector<fapi::Target>::iterator i = mcs_targets.begin();
             (i != mcs_targets.end()) && !rc && !rc_ecmd;
             i++)
        {
            uint8_t mcs_unit_id = 0x00;
            uint8_t refclock_bit = 0x00;

            rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS,
                               &(*i),
                               mcs_unit_id);
            if (rc)
            {
                FAPI_ERR("proc_cen_ref_clk_enable: Error querying ATTR_CHIP_UNIT_POS");
                break;
            }

            // continue to next iteration if this MCS is not connected to a Centaur
            if (!(i_attached_centaurs & (1 << ((NUM_CENTAUR_POS-1)-mcs_unit_id))))
            {
                FAPI_DBG("proc_cen_ref_clk_enable: MCS %d is not connected to a Centaur, skipping...\n", mcs_unit_id);
            }
            else
            {
                // mark that we have configured this MCS/Centaur pair
                configured_centaurs |= (1 << ((NUM_CENTAUR_POS-1)-mcs_unit_id));
                FAPI_DBG("proc_cen_ref_clk_enable: MCS %d is connected to a Centaur, configured_centaurs: %02X\n", mcs_unit_id,configured_centaurs);

                // query attribute which defines reflock bit associated with this Centaur
                rc = FAPI_ATTR_GET(ATTR_DMI_REFCLOCK_SWIZZLE,
                                   &(*i),
                                   refclock_bit);
                if (rc)
                {
                    FAPI_ERR("proc_cen_ref_clk_enable: Error querying ATTR_DMI_REFCLOCK_SWIZZLE");
                    break;
                }
                FAPI_DBG("proc_cen_ref_clk_enable: refclock_bit: %02X\n", refclock_bit);

                if ((FSI_GP8_CENTAUR_REFCLOCK_START_BIT + refclock_bit) > FSI_GP8_CENTAUR_REFCLOCK_END_BIT)
                {
                    // bit offset exceeds field range
                    FAPI_ERR("proc_cen_ref_clk_enable: Translated Centaur refclock enable bit position is out of range!");
                    const fapi::Target& PROC_TARGET = i_target;
                    const uint8_t& CENTAUR_POSITION = mcs_unit_id;
                    const uint8_t& REFCLOCK_BIT = refclock_bit;
                    FAPI_SET_HWP_ERROR(rc,
                                       RC_PROC_CEN_REF_CLK_ENABLE_SWIZZLE_ERR);
                    break;
                }

                rc_ecmd |= reg_data.setBit(FSI_GP8_CENTAUR_REFCLOCK_START_BIT+
                                           refclock_bit);
            }
        }
        if (rc)
        {
            break;
        }
        if (rc_ecmd)
        {
            FAPI_ERR("proc_cen_ref_clk_enable: Error (0x%x) setting up refclock enable OR data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        if (configured_centaurs != i_attached_centaurs)
        {
            FAPI_ERR("proc_cen_ref_clk_enable: Not all Centaurs marked as attached were configured");
            const fapi::Target& PROC_TARGET = i_target;
            const uint8_t& CONFIGURED_CENTAUR_POSITIONS = configured_centaurs;
            const uint8_t& ATTACHED_CENTAUR_POSITIONS = i_attached_centaurs;
            FAPI_SET_HWP_ERROR(rc,
                               RC_PROC_CEN_REF_CLK_ENABLE_CONFIG_ERR);
            break;
        }

        FAPI_INF("proc_cen_ref_clk_enable: Enable refclk for functional Centaur chips...");
        if (is_master)
        {
            ecmdDataBufferBase scom_data(64);
            rc = fapiGetScom(i_target, MBOX_FSIGP8_0x00050017, scom_data);
            if (rc)
            {
                FAPI_ERR("proc_cen_ref_clk_enable: fapiGetScom error (MBOX_FSIGP8_0x00050017)");
                break;
            }
            
            rc_ecmd |= scom_data.setOr(reg_data.getWord(0), 0, 32);
            if (rc_ecmd)
            {
                FAPI_ERR("proc_cen_ref_clk_enable: Error (0x%x) setting up FSI GP8 write data buffer (SCOM)",
                         rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }

            rc = fapiPutScom(i_target, MBOX_FSIGP8_0x00050017, scom_data);
            if (rc)
            {
                FAPI_ERR("proc_cen_ref_clk_enable: fapiPutScom error (MBOX_FSIGP8_0x00050017)");
                break;
            }
        }
        else
        {
            ecmdDataBufferBase cfam_data(32);
            rc = fapiGetCfamRegister(i_target, CFAM_FSI_GP8_0x00002817, cfam_data);
            if (rc)
            {
                FAPI_ERR("proc_cen_ref_clk_enable: fapiGetCfamRegister error (CFAM_FSI_GP8_0x00001017)");
                break;
            }
            
            rc_ecmd |= cfam_data.setOr(reg_data.getWord(0), 0, 32);
            if (rc_ecmd)
            {
                FAPI_ERR("proc_cen_ref_clk_enable: Error (0x%x) setting up FSI GP8 write data buffer (CFAM)",
                         rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }

            rc = fapiPutCfamRegister(i_target, CFAM_FSI_GP8_0x00002817, cfam_data);
            if (rc)
            {
                FAPI_ERR("proc_cen_ref_clk_enable: fapiPutCfamRegister error (CFAM_FSI_GP8_0x00001017)");
                break;
            }
        }
    } while(0);  // end do

    // mark function exit
    FAPI_INF("proc_cen_ref_clk_enable: Exit");
    return rc;
}  // end FAPI procedure proc_cen_ref_clk_enable


} // extern "C"
