/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_set_pore_bar/p8_poreslw_init.C $ */
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
// $Id: p8_poreslw_init.C,v 1.15 2013/08/02 19:09:56 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_poreslw_init.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Greg Still         Email: stillgs@us.ibm.com
// *!
/// \file p8_poreslw_init.C
/// \brief Configure or reset the SLW PORE and related functions to enable idle
///         operations
///
/// High-level procedure flow:
/// \verbatim
///
///     Check for valid parameters
///     if PM_CONFIG {
///         None (see p8_set_pore_bars.C)
///     else if PM_INIT {
///         Synchronize the PMC Deconfiguration Register
///         Activate the PMC Idle seequencer
///         For each functional EX chiplet
///             Activate the PCBS-PM macro to enable idle operations
///             Clear the OCC Special Wake-up bit that is blocking idles until
///                 the SLW image is installed
///     } else if PM_RESET {
///         Set and then reset bit 0 in the SLW_RESET_REGISTER
///
///     }
///
///  Procedure Prereq:
///     - System clocks are running
/// \endverbatim
///
//------------------------------------------------------------------------------


// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include "p8_pm.H"
#include "p8_poreslw_init.H"
#include "p8_pfet_init.H"
#include "p8_pmc_deconfig_setup.H"
#include "p8_cpu_special_wakeup.H"
#include "p8_pcb_scom_errors.H"


extern "C" {

using namespace fapi;

// ----------------------------------------------------------------------
// Constant definitions
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Global variables
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------

fapi::ReturnCode poreslw_init(const Target& i_target);
fapi::ReturnCode poreslw_reset(const Target& i_target);
fapi::ReturnCode poreslw_ex_setup(const Target& i_target);

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
/**
 * p8_pcbs_init calls the underlying routine based on mode parameter
 *
 * @param[in] i_target Chip target
 * @param[in] mode     Control mode for the procedure
 *                     PM_INIT, PM_CONFIG, PM_RESET
 *
 * @retval FAPI_RC_SUCCESS
 * @retval ERROR defined in xml
 */
fapi::ReturnCode
p8_poreslw_init(const Target& i_target, uint32_t mode)
{
    fapi::ReturnCode      rc;

    FAPI_INF("Executing p8_poreslw_init in mode %x ....", mode);

    /// -------------------------------
    /// Configuration:  perform translation of any Platform Attributes
    /// into Feature Attributes that are applied during Initalization
    if (mode == PM_CONFIG)
    {
      FAPI_INF("PORE-SLW configuration...");
      // None is defined
    }

    /// -------------------------------
    /// Initialization:  perform order or dynamic operations to initialize
    /// the SLW using necessary Platform or Feature attributes.
    else if (mode == PM_INIT)
    {
      rc = poreslw_init(i_target);
    }

    /// -------------------------------
    /// Reset:  perform reset of SLW engine so that it can reconfigured and
    /// reinitialized
    else if (mode == PM_RESET)
    {
      rc = poreslw_reset(i_target);
    }

    /// -------------------------------
    /// Unsupported Mode
    else {

      FAPI_ERR("Unknown mode passed to p8_poreslw_init. Mode %x ....", mode);
      FAPI_SET_HWP_ERROR(rc, RC_PROCPM_PORESLW_CODE_BAD_MODE);

    }

    return rc;
}

//------------------------------------------------------------------------------
// PORE SLW Initialization Function
//------------------------------------------------------------------------------
/**
 * poreslw_init Initializes the slw function on a chip
 *
 * @param[in] i_target Chip target
 *
 * @retval FAPI_RC_SUCCESS
 * @retval ERROR defined in xml
 */
fapi::ReturnCode
poreslw_init(const Target& i_target)
{
    fapi::ReturnCode      rc;
    uint32_t              e_rc = 0;
    ecmdDataBufferBase    data(64);

    FAPI_INF("PORE-SLW initialization...");

    do
    {

        // Synchronize the PMC Deconfiguration Register with the currently
        // enabled EX chiplets.
        FAPI_EXEC_HWP(rc,  p8_pmc_deconfig_setup, i_target);
        if(rc)
        {
            FAPI_ERR("PMC Deconfig Setup error");
            break;
        }

        FAPI_DBG("Activate the PMC Idle seequencer by making sure the Halt bit is clear");
        const uint32_t HALT_IDLE_STATE_MASTER_FSM = 14;
        rc = fapiGetScom(i_target, PMC_MODE_REG_0x00062000, data);
        if(!rc.ok())
        {
            FAPI_ERR("Scom error reading PMC_MODE");
            break;
        }

        e_rc |= data.clearBit(HALT_IDLE_STATE_MASTER_FSM);
        if (e_rc)
        {
            FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", e_rc);
            rc.setEcmdError(e_rc);
            break;
        }

        rc = fapiPutScom(i_target, PMC_MODE_REG_0x00062000, data);
        if(!rc.ok())
        {
            FAPI_ERR("Scom error writing PMC_MODE");
            break;
        }

        FAPI_DBG("Activate the PMC Idle seequencer by making sure the Halt bit is clear");

        // Setup up each of the EX chiplets
        rc = poreslw_ex_setup(i_target);
        if(!rc.ok())
        {
            FAPI_ERR("Error from poreslw_ex_setup n");
            break;
        }

    } while(0);

    return rc;
}

//------------------------------------------------------------------------------
// PORE SLW Reset Function
//------------------------------------------------------------------------------
/**
 * poreslw_reset Resets the slw function on a chip
 *
 * @param[in] i_target Chip target
 *
 * @retval FAPI_RC_SUCCESS
 * @retval ERROR defined in xml
 */
fapi::ReturnCode
poreslw_reset(const Target& i_target)
{
    fapi::ReturnCode      rc;
    uint32_t              e_rc = 0;
    ecmdDataBufferBase    data(64);
    ecmdDataBufferBase    polldata(64);
    const uint32_t        max_polls = 8;
    uint32_t              poll_count;
    bool                  wait_state_detected;
    bool                  poll_loop_error = false;

    FAPI_INF("PORE-SLW reset...");

    do
    {
        //  Reset the SLWs using the Reset Register bit 0.
        //  Note:  Resets ALL registers (including debug registers) with the
        //  exception of Error Maskbuild_node_slw

        // set PORE run bit to stop
        rc = fapiGetScom(i_target, PORE_SLW_CONTROL_0x00068001, data);
        if(!rc.ok())
        {
            FAPI_ERR("Scom error reading PORE_SLW_CONTROL");
            break;
        }

        e_rc |= data.setBit(0);
        if (e_rc)
        {
            FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", e_rc);
            rc.setEcmdError(e_rc);
            break;
        }

        rc = fapiPutScom(i_target, PORE_SLW_CONTROL_0x00068001, data);
        if(!rc.ok())
        {
            FAPI_ERR("Scom error writing PORE_SLW_CONTROL");
            break;
        }

        // Reset PORE (state machines and PIBMS_DBG registers) and PIB2OCI
        // interface write Reset_Register(0:1) with 0b11 to trigger the reset.
        e_rc |= data.flushTo0();
        e_rc |= data.setBit(0, 2);
        if (e_rc)
        {
            FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", e_rc);
            rc.setEcmdError(e_rc);
            break;
        }

        FAPI_DBG("PORE-SLW Reset value: 0x%16llX", data.getDoubleWord(0));

        rc = fapiPutScom(i_target, PORE_SLW_RESET_0x00068002, data);
        if(!rc.ok())
        {
            FAPI_ERR("Scom error writing PORE_SLW_RESET");
            break;
        }

        // poll until PORE has returned to WAIT state 3:6=0b0001
        wait_state_detected = false;
        for (poll_count=0; poll_count<max_polls; poll_count++)
        {
            rc = fapiGetScom(i_target, PORE_SLW_STATUS_0x00068000, polldata);
            if(!rc.ok())
            {
                FAPI_ERR("Scom error reading PORE_SLW_STATUS");
                poll_loop_error = true;
                break;
            }

            if(polldata.isBitClear(3, 3) && polldata.isBitSet(6))
            {
               wait_state_detected = true;
               break;
            }
            else
            {
              fapiDelay(1000, 10);
            }
        }

        // Break if a FAPI error occured in the polling loop
        if (poll_loop_error)
        {
             break;
        }

        if(!wait_state_detected)
        {
          FAPI_ERR("PORE SLW reset failed ");
          FAPI_SET_HWP_ERROR(rc, RC_PROCPM_SLW_RESET_TIMEOUT);
        }

    } while (0);

    return rc;
}

//------------------------------------------------------------------------------
// EX Idle Setup Function
//  Note:   PMGP0 and OCC Special Wakeup actions could be done with multicast in
//          the future.
//------------------------------------------------------------------------------
/**
 * poreslw_ex_setup Resets the slw function for each EX chiplet
 *
 * @param[in] i_target Chip target
 *
 * @retval FAPI_RC_SUCCESS
 * @retval ERROR defined in xml
 */
fapi::ReturnCode
poreslw_ex_setup(const Target& i_target)
{
    fapi::ReturnCode                rc;
    uint32_t                        e_rc = 0;
    ecmdDataBufferBase              data(64);
    ecmdDataBufferBase              config_data(64);
    ecmdDataBufferBase              set_data(64);
    ecmdDataBufferBase              clear_data(64);
    std::vector<fapi::Target>       l_exChiplets;
    uint8_t                         l_ex_number = 0;
    uint64_t                        address;

    uint8_t                         pm_sleep_type;
    uint8_t                         pm_sleep_entry ;
    uint8_t                         pm_sleep_exit ;
    uint8_t                         pm_winkle_type  ;
    uint8_t                         pm_winkle_entry ;
    uint8_t                         pm_winkle_exit ;


    // These enums must match the enum values in pm_hwp_attributes.xml
    enum IDLE_TYPE
    {
        FAST        = 0,
        DEEP        = 1
    };

    enum IDLE_TRANSITION_MODE
    {
        HARDWARE    = 0,
        ASSISTED    = 1
    };

    // Give relevant bits a name
    // PMGP1 bits
    const uint32_t                  PM_SLEEP_POWER_DOWN_EN_BIT  = 0;
    const uint32_t                  PM_SLEEP_POWER_UP_EN_BIT    = 1;
    const uint32_t                  PM_SLEEP_POWER_OFF_SEL_BIT  = 2;
    const uint32_t                  PM_WINKLE_POWER_DOWN_EN_BIT = 3;
    const uint32_t                  PM_WINKLE_POWER_UP_EN_BIT   = 4;
    const uint32_t                  PM_WINKLE_POWER_OFF_SEL_BIT = 5;

    const uint32_t                  PM_DISABLE = 0;

    do
    {

        FAPI_INF("Executing poreslw_ex_setup...");

        // --------------------------------------
        // Initialize the PFET controllers
        //   This HWP loops across the chiplet but uses chip level attributes so
        //   it is invoked prior to the chiplet loop below.
        FAPI_INF("\tInitialize the PFET controllers");

        FAPI_EXEC_HWP(rc,  p8_pfet_init, i_target, PM_INIT);
        if(rc)
        {
            FAPI_ERR("PFET Controller Setup error");
            break;
        }

        // Read the attributes

        // \todo Hardcoded values until platform control of attributes is in place.
        FAPI_INF("\tWARNING:  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
        FAPI_INF("\tWARNING:  Hardcoded idle config values set until platform support of attributes available");
        FAPI_INF("\tWARNING:  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");

        pm_sleep_entry      = 0;   // 0=assisted, 1=HW
        pm_sleep_exit       = 0;   // 0=assisted, 1=HW
        pm_sleep_type       = 1;   // 0=fast, 1=deep

        // Due to L3 High Availability Write Pointers that must be
        // saved upon a Deep Winkle Entry, this transition must be
        // assisted.
        pm_winkle_entry     = 0;   // 0=assisted, 1=HW
        pm_winkle_exit      = 0;   // 0=assisted, 1=HW
        pm_winkle_type      = 1;   // 0=fast, 1=deep

        // Sleep
        /*
        GETATTR(ATTR_PM_SLEEP_TYPE,
                "ATTR_PM_SLEEP_TYPE",
                &i_target,
                pm_sleep_type);

        GETATTR(ATTR_PM_SLEEP_ENTRY,
                "ATTR_PM_SLEEP_ENTRY",
                &i_target,
                pm_sleep_entry);

        GETATTR(ATTR_PM_SLEEP_EXIT,
                "ATTR_PM_SLEEP_EXIT",
                &i_target,
                pm_sleep_exit);

        // Winkle
        GETATTR(ATTR_PM_WINKLE_TYPE,
                "ATTR_PM_WINKLE_TYPE",
                &i_target,
                pm_winkle_type);

        GETATTR(ATTR_PM_WINKLE_ENTRY,
                "ATTR_PM_WINKLE_ENTRY",
                &i_target,
                pm_winkle_entry);

        GETATTR(ATTR_PM_WINKLE_EXIT,
                "ATTR_PM_WINKLE_EXIT",
                &i_target,
                pm_winkle_exit);

        */
        // Due to L3 High Availability Write Pointers that must be
        // saved upon a Deep Winkle Entry, this transition must be
        // assisted.
        // \todo  need Attribute for L3 HA enabled.  GA1 = NO
        if (pm_winkle_entry != ASSISTED)
        {
            FAPI_INF("Winkle Entry is not configured in ASSISTED mode.  L3 High Availability functions"
                        " are not supported");
            FAPI_INF("Continuing anyway....");
        }

        // --------------------------------------
        // Walk the configured chiplets
        rc = fapiGetChildChiplets (   i_target,
                                        TARGET_TYPE_EX_CHIPLET,
                                        l_exChiplets,
                                        TARGET_STATE_FUNCTIONAL);
        if (rc)
        {
            FAPI_ERR("Error from fapiGetChildChiplets!");
            break;
        }

        FAPI_DBG("\tChiplet vector size  => %u ", l_exChiplets.size());


        // Iterate through the returned chiplets
        for (uint8_t j=0; j < l_exChiplets.size(); j++)
        {

            // Get the core number
            rc = FAPI_ATTR_GET(  ATTR_CHIP_UNIT_POS,
                                   &l_exChiplets[j],
                                   l_ex_number);
            if(!rc.ok())
            {
                FAPI_ERR("fapiGetAttribute of ATTR_CHIP_UNIT_POS error");
                break;
            }

            address = EX_GP3_0x100F0012 + (l_ex_number * 0x01000000);
            rc=fapiGetScom(i_target, address, data);
            if(rc)
            {
                FAPI_ERR("GetScom error");
                break;
            }

            // Check if chiplet enable bit is set (configured).  If so, process
            if ( data.isBitSet(0) )
            {
                FAPI_INF("\tSetting up Core %X ", l_ex_number);

                //  ******************************************************************
                //  Set PMGP1_REG
                //  ******************************************************************

                FAPI_DBG("\t-----------------------------------------------------");
                FAPI_DBG("\tPMGP1_REG Configuration                  ");
                FAPI_DBG("\t-----------------------------------------------------");
                FAPI_DBG("\t  pm_sleep_entry          => %d ", pm_sleep_entry );
                FAPI_DBG("\t  pm_sleep_exit           => %d ", pm_sleep_exit  );
                FAPI_DBG("\t  pm_sleep_type           => %d ", pm_sleep_type  );
                FAPI_DBG("\t  pm_winkle_entry         => %d ", pm_winkle_entry  );
                FAPI_DBG("\t  pm_winkle_exit          => %d ", pm_winkle_exit  );
                FAPI_DBG("\t  pm_winkle_type          => %d ", pm_winkle_type  );
                FAPI_DBG("\t-----------------------------------------------------");


                FAPI_DBG("\t*************************************");
                FAPI_INF("\tSetup PMGP1_REG for EX %x", l_ex_number);
                FAPI_DBG("\t*************************************");

                // Initialize the set and clear vectors
                e_rc |= clear_data.flushTo1();  // Set to 1s to be used for WAND
                e_rc |= set_data.flushTo0();    // Set to 0s to be used for WOR

                // If   sleep entry = 1 (hardware), sleep power down enable = 1
                // else sleep entry = 0 (assisted), sleep power down enable = 0
                if (pm_sleep_entry)
                {
                    e_rc |= set_data.setBit(PM_SLEEP_POWER_DOWN_EN_BIT);
                }
                else
                {
                    e_rc |= clear_data.clearBit(PM_SLEEP_POWER_DOWN_EN_BIT);
                }

                // If   sleep exit  = 1 (hardware), sleep power up enable = 1
                // else sleep exit  = 0 (assisted), sleep power up enable = 0
                if (pm_sleep_exit)
                {
                    e_rc |= set_data.setBit(PM_SLEEP_POWER_UP_EN_BIT);
                }
                else
                {
                    e_rc |= clear_data.clearBit(PM_SLEEP_POWER_UP_EN_BIT);
                }

                // If   sleep type  = 1 (deep), sleep power up sel = 1
                // else sleep type  = 0 (fast), sleep power up sel = 0
                if (pm_sleep_type)
                {
                    e_rc |= set_data.setBit(PM_SLEEP_POWER_OFF_SEL_BIT);

                }
                else
                {
                    e_rc |= clear_data.clearBit(PM_SLEEP_POWER_OFF_SEL_BIT);
                }

                // If   winkle entry = 1 (hardware), winkle power down enable = 1
                // else winkle entry = 0 (assisted), winkle power down enable = 0
                if (pm_winkle_entry)
                {
                    e_rc |= set_data.setBit(PM_WINKLE_POWER_DOWN_EN_BIT);
                }
                else
                {
                    e_rc |= clear_data.clearBit(PM_WINKLE_POWER_DOWN_EN_BIT);
                }

                // If   winkle exit  = 1 (hardware), winkle power up enable = 1
                // else winkle exit  = 0 (assisted), winkle power up enable = 0
                if (pm_winkle_exit)
                {
                    e_rc |= set_data.setBit(PM_WINKLE_POWER_UP_EN_BIT);
                }
                else
                {
                    e_rc |= clear_data.clearBit(PM_WINKLE_POWER_UP_EN_BIT);
                }

                // If   winkle type  = 1 (deep), winkle power up sel = 1
                // else winkle type  = 0 (fast), winkle power up sel = 0
                if (pm_winkle_type)
                {
                    e_rc |= set_data.setBit(PM_WINKLE_POWER_OFF_SEL_BIT);

                }
                else
                {
                    e_rc |= clear_data.clearBit(PM_WINKLE_POWER_OFF_SEL_BIT);
                }

                // Check for any errors from set/clear ops into the buffers
                if (e_rc)
                {
                    FAPI_ERR("eCmdDataBuffer operation failed. rc = 0x%x", (uint32_t)e_rc);
                    rc.setEcmdError(e_rc);
                    break;
                }

                // The set and clear vectors are built.  Write them to
                // the respective addresses.
                FAPI_DBG("\tEX_PMGP1_WOR  0x%16llx" , set_data.getDoubleWord(0));
                address = EX_PMGP1_REG_0_WORx100F0105 + (l_ex_number * 0x01000000);
                rc=fapiPutScom(i_target, address, set_data);
                if (rc)
                {
                    FAPI_ERR("fapiPutScom(EX_PMGP1_REG_0_WORx100F0105) failed. rc = 0x%x", (uint32_t)rc);
                    break;
                }

                FAPI_DBG("\tEX_PMGP1_WAND 0x%16llx" , clear_data.getDoubleWord(0));
                address = EX_PMGP1_REG_0_WANDx100F0104 + (l_ex_number * 0x01000000);
                rc=fapiPutScom(i_target, address, clear_data);
                if (rc)
                {
                    FAPI_ERR("fapiPutScom(EX_PMGP1_REG_0_WORx100F0105) failed. rc = 0x%x", (uint32_t)rc);
                    break;
                }

                FAPI_INF("\tDisable the PCBS Heartbeat EX %x", l_ex_number);
                address = EX_SLAVE_CONFIG_0x100F001E + (l_ex_number * 0x01000000);
                rc = fapiGetScom(i_target, address, data);
                if(!rc.ok())
                {
                    FAPI_ERR("Scom error reading PCBS Slave Config");
                    break;
                }

                e_rc |= data.setBit(4);
                if (e_rc)
                {
                    FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", e_rc);
                    rc.setEcmdError(e_rc);
                    break;
                }

                rc=fapiPutScom(i_target, address, data);
                if(!rc.ok())
                {
                    FAPI_ERR("Scom error writing PCBS Slave Config");
                    break;
                }

                // --------------------------------------
                FAPI_INF("\tSet PMGP0(46) to deal with HW259509 - winkle Pstate stepping hang");
                // This is a spare bit in Murano and Venice DD1s but
                // is necessary to set in Murano and Venice DD2 to deal
                // the hang condition that is fixed.  As bit 46 is spare
                // in the previous levels, setting it on all levels is not
                // harmful.
                address = EX_PMGP0_OR_0x100F0102 + (l_ex_number * 0x01000000);
                e_rc |= data.flushTo0();
                e_rc |= data.setBit(46);
                if (e_rc)
                {
                    FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", e_rc);
                    rc.setEcmdError(e_rc);
                    break;
                }

                rc=fapiPutScom(i_target, address, data);
                if(!rc.ok())
                {
                    FAPI_ERR("Scom error setting PMGP0");
                    break;
                }

                // --------------------------------------
                // Check that PM function is enabled (eg not disabled).
                // If not, remove the disable

                address = EX_PMGP0_0x100F0100 + (l_ex_number * 0x01000000);
                rc=fapiGetScom(i_target, address, data);
                if(!rc.ok())
                {
                    FAPI_ERR("Scom error reading PMGP0");
                    break;
                }

                if (data.isBitSet(PM_DISABLE))
                {

                    // Activate the PCBS-PM macro by clearing the PM_DISABLE bit
                    FAPI_INF("\tActivate the PCBS-PM for EX %x", l_ex_number);

                    e_rc |= data.flushTo1();
                    e_rc |= data.clearBit(PM_DISABLE);
                    if (e_rc)
                    {
                        FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", e_rc);
                        rc.setEcmdError(e_rc);
                        break;
                    }

                    address = EX_PMGP0_AND_0x100F0101 + (l_ex_number * 0x01000000);
                    rc=fapiPutScom(i_target, address, data);
                    if(!rc.ok())
                    {
                        FAPI_ERR("Scom error writing EX_PMGP0_OR");
                        break;
                    }
                }

                // --------------------------------------
                // Clear OCC Special Wake-up bit - only 1 bit in the register
                address = EX_PMSpcWkupOCC_REG_0x100F010C + (l_ex_number * 0x01000000);
                rc=fapiGetScom(i_target, address, data);
                if(!rc.ok())
                {
                    FAPI_ERR("Scom error clearing EX_OCC_SPWKUP");
                    break;
                }

                if (data.isBitSet(0))
                {
                    FAPI_INF("\tClear OCC Special Wake-up for EX %x", l_ex_number);
                    e_rc |= data.flushTo0();
                    if (e_rc)
                    {
                        FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", e_rc);
                        rc.setEcmdError(e_rc);
                        break;
                    }

                    rc=fapiPutScom(i_target, address, data);
                    if(!rc.ok())
                    {
                        FAPI_ERR("Scom error clearing EX_OCC_SPWKUP");
                        break;
                    }
                }

                // --------------------------------------
                // Initialize the special wake-up tracking attributes
                FAPI_INF("\tInitialize the special wake-up tracking attributes");

                FAPI_EXEC_HWP(rc,  p8_cpu_special_wakeup,
                                    l_exChiplets[j],
                                    SPCWKUP_INIT,
                                    SPW_ALL);
                if(rc)
                {
                    FAPI_ERR("Special wake-up initialization error");
                    break;
                }

            }  // Chiplet Enabled
        }  // chiplet loop
    } while(0);

    return rc;
}

} //end extern

