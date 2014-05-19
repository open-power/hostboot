/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pmc_init.C $           */
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
// $Id: p8_pmc_init.C,v 1.42 2014/04/10 21:12:22 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pmc_init.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Pradeep CN         Email: pradeepcn@in.ibm.com
// *! OWNER NAME: Greg Still         Email: stillgs@us.ibm.com
// *!
/// \verbatim
/// High-level procedure flow:
///
///     T
///
///  \endverbatim
///  buildfapiprcd -e "../../xml/error_info/p8_pmc_errors.xml,../../xml/error_info/p8_pstate_registers.xml" p8_pmc_init.C
//------------------------------------------------------------------------------


// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include "p8_pm.H"
#include "p8_pmc_init.H"

#define INTERCHIP_HALT_POLL_COUNT 256
#define VOLTAGE_CHANGE_POLL_COUNT 100
#define O2S_POLL_COUNT 256
#define O2P_POLL_COUNT 8
#define PSTATE_HALT_POLL_COUNT 256
#define PORE_REQ_POLL_COUNT 256

#define MASTER_SIDE 0
#define SLAVE_SIDE  1

extern "C" {

using namespace fapi;

// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------

fapi::ReturnCode
p8_pmc_poll_pstate_halt(    const fapi::Target &    i_target,
                            const uint8_t           i_side);

fapi::ReturnCode
p8_pmc_poll_idle_halt(      const fapi::Target &    i_target,
                            const uint8_t           i_side);

fapi::ReturnCode
p8_pmc_poll_interchip_halt( const fapi::Target&  i_target,
                            const uint8_t        i_side,
                            bool                 i_is_MasterPMC,
                            const fapi::Target&  i_dcm_target);

fapi::ReturnCode
p8_pmc_poll_spivid_halt(    const fapi::Target& i_target,
                            const uint8_t       i_side);

fapi::ReturnCode
p8_pmc_poll_o2p_halt(       const fapi::Target& i_target,
                            const uint8_t       i_side);

// ----------------------------------------------------------------------
/**
 * pmc_config_spivid_settings
 *
 * @param[in] i_target Chip target
 *
 * @retval ECMD_SUCCESS
 * @retval ERROR defined in xml
 */
fapi::ReturnCode
pmc_config_spivid_settings(const Target& l_pTarget)
{
    fapi::ReturnCode rc;

    // SPIVID Defaults

    const uint32_t  default_spivid_frequency = 1;  // MHz
    // Units: nanoseconds;  Value 15 microseconds
    const uint32_t  default_spivid_interframe_delay_write_status = 15000;
    // Units: nanoseconds;  Value 40 microsecond
    const uint32_t  default_spivid_inter_retry_delay = 40000;


    uint32_t attr_pm_spivid_frequency = 1;
    uint32_t attr_proc_nest_frequency = 2000;

    uint32_t attr_pm_spivid_clock_divider;
    uint32_t attr_pm_spivid_interframe_delay_write_status;
    uint32_t attr_pm_spivid_interframe_delay_write_status_value;
    uint32_t attr_pm_spivid_inter_retry_delay_value;
    uint32_t attr_pm_spivid_inter_retry_delay;

    FAPI_INF("pmc_config_spivid start...");
    do
    {

        //----------------------------------------------------------
        GETATTR(            rc,
                            ATTR_FREQ_PB,
                            "ATTR_FREQ_PB",
                            NULL,
                            attr_proc_nest_frequency);

        //----------------------------------------------------------
        GETATTR_DEFAULT(    rc,
                            ATTR_PM_SPIVID_FREQUENCY,
                            "ATTR_PM_SPIVID_FREQUENCY",
                            NULL,
                            attr_pm_spivid_frequency,
                            default_spivid_frequency);

        // calculation of clock divider
        attr_pm_spivid_clock_divider =  (attr_proc_nest_frequency /
                                            (attr_pm_spivid_frequency*8)-1 );


        SETATTR(            rc,
                            ATTR_PM_SPIVID_CLOCK_DIVIDER,
                            "ATTR_PM_SPIVID_CLOCK_DIVIDER",
                            &l_pTarget,
                            attr_pm_spivid_clock_divider);

        //----------------------------------------------------------
        // Delay between command and status frames of a SPIVID WRITE operation
        // (binary in nanoseconds)

        GETATTR_DEFAULT(    rc,
                            ATTR_PM_SPIVID_INTERFRAME_DELAY_WRITE_STATUS,
                            "ATTR_PM_SPIVID_INTERFRAME_DELAY_WRITE_STATUS",
                            &l_pTarget,
                            attr_pm_spivid_interframe_delay_write_status,
                            default_spivid_interframe_delay_write_status);

        // Delay is computed as: (value * ~100ns_hang_pulse)
        // +0/-~100ns_hang_pulse time
        // Thus, value = delay / 100
        attr_pm_spivid_interframe_delay_write_status_value =
                attr_pm_spivid_interframe_delay_write_status / 100;

        SETATTR(            rc,
                            ATTR_PM_SPIVID_INTERFRAME_DELAY_WRITE_STATUS_VALUE,
                            "ATTR_PM_SPIVID_INTERFRAME_DELAY_WRITE_STATUS_VALUE",
                            &l_pTarget,
                            attr_pm_spivid_interframe_delay_write_status_value);

        //----------------------------------------------------------

        // Delay between SPIVID reture attempts when WRITE command status
        // indicates an error (binary in nanoseconds)

        GETATTR_DEFAULT(    rc,
                            ATTR_PM_SPIVID_INTER_RETRY_DELAY,
                            "ATTR_PM_SPIVID_INTER_RETRY_DELAY",
                            &l_pTarget,
                            attr_pm_spivid_inter_retry_delay,
                            default_spivid_inter_retry_delay);

        FAPI_DBG (" attr_pm_spivid_inter_retry_delay value in config function = 0x%x",
                            attr_pm_spivid_inter_retry_delay );

        // Delay is computed as: (value * ~100ns_hang_pulse)
        // +0/-~100ns_hang_pulse time
        // Thus, value = delay / 100
        attr_pm_spivid_inter_retry_delay_value =
                attr_pm_spivid_inter_retry_delay / 100;

        SETATTR(            rc,
                            ATTR_PM_SPIVID_INTER_RETRY_DELAY_VALUE,
                            "ATTR_PM_SPIVID_INTER_RETRY_DELAY_VALUE",
                            &l_pTarget,
                            attr_pm_spivid_inter_retry_delay_value);


    } while(0);

    FAPI_INF("pmc_config_spivid end...");

    return rc ;
}


// ----------------------------------------------------------------------
/**
 * pmc_reset_function
 *
 * @param[in] i_target1 Primary Chip target:   Murano - chip0; Venice - chip
 * @param[in] i_target2 Secondary Chip target: Murano - chip1; Venice - NULL
 *
 * @retval ECMD_SUCCESS
 * @retval ERROR defined in xml
 */
fapi::ReturnCode
pmc_reset_function( const fapi::Target& i_target1 ,
                    const fapi::Target& i_target2,
                    uint32_t i_mode)
{

    fapi::ReturnCode rc;
    ecmdDataBufferBase data(64);
    ecmdDataBufferBase pmcstatus(64);
    ecmdDataBufferBase porr(64);
    ecmdDataBufferBase pmcmode_master(64);
    ecmdDataBufferBase pmcmode_slave(64);

    uint32_t e_rc = 0;
//    uint32_t count = 0 ;
//    bool is_stopped = false ;
//    bool is_pstate_error_stopped = false ;
//    bool is_spivid_stopped = false ;
//    bool is_intchp_error_stopped= false ;
    bool master_enable_pstate_voltage_changes = false ;
    bool master_is_MasterPMC= false ;
//    bool master_enable_fw_pstate_mode= false ;
    bool master_is_enable_interchip_interface= false ;


//    bool slave_enable_pstate_voltage_changes = false ;
    bool slave_is_MasterPMC= false ;
//    bool slave_enable_fw_pstate_mode= false ;
    bool slave_is_enable_interchip_interface= false ;


    fapi::Target master_target;
    fapi::Target slave_target;
    uint8_t attr_pm_spivid_port_enable1 = 0;
    uint8_t attr_dcm_installed_1 = 0;
    uint8_t attr_dcm_installed_2 = 0;
    uint64_t any_error = 0;

    FAPI_INF("pmc_reset start...");

    do
    {
        // Check for validity of passed parms
        bool dcm = false;

        FAPI_INF("Performing STEP 1");
        rc = FAPI_ATTR_GET(ATTR_PROC_DCM_INSTALLED, &i_target1, attr_dcm_installed_1);
        if (rc)
        {
            FAPI_ERR("fapiGetAttribute of ATTR_DCM_INSTALLED with rc = 0x%x", (uint32_t)rc);
            break;
        }

        FAPI_INF (" ATTR_DCM_INSTALLED value in reset function = 0x%x", attr_dcm_installed_1 );

        if (attr_dcm_installed_1 == 0)
        {

            // target2 should be NULL
            // if not NULL, exit with config error
            if (i_target2.getType() != TARGET_TYPE_NONE  )
            {
                FAPI_ERR ("Config error : target2 is not null for target1 SCM case");
                const fapi::Target& MASTER_TARGET = i_target1;
                const fapi::Target& SLAVE_TARGET = i_target2;
                const uint8_t & DCM_INSTALLED_1 =  attr_dcm_installed_1;
                const uint8_t & DCM_INSTALLED_2 =  attr_dcm_installed_2;
                FAPI_SET_HWP_ERROR(rc, RC_PROCPM_PMCRESET_SCM_INSTALL_ERROR);
                break;
            }
        }
        else
        {
            // GSS: test removed as this can be the case for a deconfigured DCM
            //         if target2 is NULL, exit with config error
            //         if target2 dcm attr not 1, exit with config error
            //if (i_target2.getType() == TARGET_TYPE_NONE )
            //{
            //    FAPI_ERR ("config error : target2 is null for target1 dcm installed case");
            //    FAPI_SET_HWP_ERROR(rc, RC_PROCPM_PMCRESET_DCM_INSTALL_ERROR);
            //    break;
            //}

            if (i_target2.getType() != TARGET_TYPE_NONE  )
            {
                rc = FAPI_ATTR_GET(ATTR_PROC_DCM_INSTALLED, &i_target2, attr_dcm_installed_2);
                if (rc)
                {
                    FAPI_ERR("fapiGetAttribute of ATTR_DCM_INSTALLED with rc = 0x%x", (uint32_t)rc);
                    break;
                }
                FAPI_INF (" ATTR_DCM_INSTALLED value in reset function = 0x%x", attr_dcm_installed_2 );

                if (attr_dcm_installed_2 != 1)
                {
                    FAPI_ERR ("Config error:  DCM_INSTALLED target2 does not match target1\n" \
                              "   target1: %08x attr:%02x, target2:%08x attr:%02x",
                              i_target1.getType(), attr_dcm_installed_1,
                              i_target2.getType(), attr_dcm_installed_2);
                    const fapi::Target& MASTER_TARGET = i_target1;
                    const fapi::Target& SLAVE_TARGET = i_target2;
                    const uint8_t & DCM_INSTALLED_1 =  attr_dcm_installed_1;
                    const uint8_t & DCM_INSTALLED_2 =  attr_dcm_installed_2;
                    FAPI_SET_HWP_ERROR(rc, RC_PROCPM_PMCRESET_DCM_INSTALL_ERROR);
                    break;
                }

                dcm = true;

            }
        }

        ////////////////////////////////////////////////////////////////////////////
        // 1) Determine master chip and slave chip. By reading the SPIVID_EN attribute
        //    If SPIVID_EN is != 0 then that target is master
        //    If SPIVID_EN is == 0 then that target is slave
        //    If both SPIVID_EN are != 0 then its an error
        ////////////////////////////////////////////////////////////////////////////


        FAPI_INF("Determine master chip and slave targets");
        rc = FAPI_ATTR_GET( ATTR_PM_SPIVID_PORT_ENABLE,
                            &i_target1,
                            attr_pm_spivid_port_enable1);
        if (rc)
        {
            FAPI_ERR("fapiGetAttribute of ATTR_PM_SPIVID_PORT_ENABLE with rc = 0x%x", (uint32_t)rc);
            break;
        }
        FAPI_INF (" value read from the attribute attr_pm_spivid_port_enable in reset function = 0x%x",
                    attr_pm_spivid_port_enable1);


        if (attr_pm_spivid_port_enable1 != 0 )
        {
            master_target = i_target1;
            slave_target = i_target2;
        }
        else
        {
            FAPI_ERR("Master target does not have SPIVID ports enabled: ATTR_PM_SPIVID_PORT_ENABLE must be non-zero.");
            const fapi::Target& MASTER_TARGET = i_target1;
            const uint64_t& ATTR_SPIVID_PORT_ENABLE = (uint64_t)attr_pm_spivid_port_enable1;
            FAPI_SET_HWP_ERROR(rc, RC_PROCPM_PMCRESET_SPIVID_CONFIG_ERROR);
            break;
        }

        ////////////////////////////////////////////////////////////////////////////
        // 2.0 cRQ_TD_IntMaskRQ: Mask OCC interrupts in OIMR1
        //     PMC_PSTATE_REQUEST, PMC_PROTOCOL_ONGOING, PMC_VOLTAGE_CHANGE_ONGOING,
        //     PMC_INTERCHIP_MSG_SEND_ONGOING, PMC_IDLE_ENTER, PMC_IDLE_EXIT, PMC_SYNC
        //       12
        //       13
        //       14
        //       15
        //       18
        //       20
        //       22  of OCB_OCI_OIMR1_0x0006a014
        //
        // 2.1 cRQ_TD_IntMaskER: Mask OCC interrupts in OIMR0
        //     PMC_ERROR, PMC_MALF_ALERT, PMC_INTERCHIP_MSG_RECVD
        //         9
        //        13
        //        21  of OCB_OCI_OIMR0_0x0006a004
        ////////////////////////////////////////////////////////////////////////////

        // ******************************************************
        // Master
        // ******************************************************

        FAPI_INF("Mask OCC interrupts in OIMR0 and OIMR1 on Master");

        // CHECKING PMC_FIRS

        e_rc = data.flushTo0();
        if (e_rc)
        {
            rc.setEcmdError(e_rc);
            break;
        }
        rc = fapiGetScom(master_target, PMC_LFIR_0x01010840 , data );
        if (rc)
        {
           FAPI_ERR("fapiGetScom(PMC_LFIR_0x01010840) failed.");
           break;
        }

        any_error = data.getDoubleWord(0);

        if (any_error)
        {
           FAPI_INF(" PMC_FIR has error(s) active.  Continuing though  0x%16llX ", data.getDoubleWord(0));
        }

        e_rc = data.flushTo0();
        if (e_rc)
        {
            rc.setEcmdError(e_rc);
            break;
        }

        rc = fapiGetScom(master_target, OCB_OCI_OIMR1_0x0006a014 , data );
        if (rc)
        {
             FAPI_ERR("fapiGetScom(OCB_OCI_OIMR1_0x0006a014) failed.");
             break;
        }

        e_rc |= data.setBit(12);
        e_rc |= data.setBit(13);
        e_rc |= data.setBit(14);
        e_rc |= data.setBit(15);
        e_rc |= data.setBit(18);
        e_rc |= data.setBit(20);
        e_rc |= data.setBit(22);
        if (e_rc)
        {
            FAPI_ERR("ecmdDataBufferBase error setting up OCB_OCI_OIMR1_0x0006a014 on Master");
            rc.setEcmdError(e_rc);
            break;
        }

        rc = fapiPutScom(master_target, OCB_OCI_OIMR1_0x0006a014 , data );
        if (rc)
        {
             FAPI_ERR("fapiPutScom(OCB_OCI_OIMR1_0x0006a014) failed.");
             break;
        }

        rc = fapiGetScom(master_target, OCB_OCI_OIMR0_0x0006a004 , data );
        if (rc)
        {
             FAPI_ERR("fapiGetScom(OCB_OCI_OIMR0_0x0006a004) failed.");
             break;
        }

        e_rc |= data.setBit(9);
        e_rc |= data.setBit(13);
        e_rc |= data.setBit(21);
        if (e_rc)
        {
            FAPI_ERR("ecmdDataBufferBase error setting up OCB_OCI_OIMR0_0x0006a004 on Master");
            rc.setEcmdError(e_rc);
            break;
        }

        rc = fapiPutScom(master_target, OCB_OCI_OIMR0_0x0006a004 , data );
        if (rc)
        {
             FAPI_ERR("fapiPutScom(OCB_OCI_OIMR0_0x0006a004) failed.");
             break;
        }

        // ******************************************************
        // Slave
        // ******************************************************

        if (dcm)
        {

            FAPI_INF("Mask OCC interrupts in OIMR0 and OIMR1 on Slave");

            // CHECKING PMC_FIRS

            e_rc = data.flushTo0();
            if (e_rc)
            {
                FAPI_ERR("ecmdDataBufferBase error flushing buffer");
                rc.setEcmdError(e_rc);
                break;
            }

            rc = fapiGetScom(slave_target, PMC_LFIR_0x01010840 , data );
            if (rc)
            {
                FAPI_ERR("fapiGetScom(PMC_LFIR_0x01010840) failed.");
                break;
            }

            any_error = data.getDoubleWord(0);

            if (any_error)
            {
                FAPI_DBG(" PMC_FIR has error(s) active.  Continuing though  0x%16llX ", data.getDoubleWord(0));
            }

            e_rc = data.flushTo0();
            if (e_rc)
            {
                FAPI_ERR("ecmdDataBufferBase error flushing buffer");
                rc.setEcmdError(e_rc);
                break;
            }

            rc = fapiGetScom(slave_target, OCB_OCI_OIMR1_0x0006a014 , data );
            if (rc)
            {
                FAPI_ERR("fapiGetScom(OCB_OCI_OIMR1_0x0006a014) failed."); break;
            }

            e_rc |= data.setBit(12);
            e_rc |= data.setBit(13);
            e_rc |= data.setBit(14);
            e_rc |= data.setBit(15);
            e_rc |= data.setBit(18);
            e_rc |= data.setBit(20);
            e_rc |= data.setBit(22);
            if (e_rc)
            {
                FAPI_ERR("ecmdDataBufferBase error setting up OIMR1");
                rc.setEcmdError(e_rc);
                break;
            }

            rc = fapiPutScom(slave_target, OCB_OCI_OIMR1_0x0006a014 , data );
            if (rc)
            {
                FAPI_ERR("fapiPutScom(OCB_OCI_OIMR1_0x0006a014) failed.");
                break;
            }

            rc = fapiGetScom(slave_target, OCB_OCI_OIMR0_0x0006a004 , data );
            if (rc)
            {
                 FAPI_ERR("fapiGetScom(OCB_OCI_OIMR0_0x0006a004) failed.");
                 break;
            }

            e_rc |= data.setBit(9);
            e_rc |= data.setBit(13);
            e_rc |= data.setBit(21);
            if (e_rc)
            {
                FAPI_ERR("ecmdDataBufferBase error setting up OIMR0");
                rc.setEcmdError(e_rc);
                break;
            }

            rc = fapiPutScom(slave_target, OCB_OCI_OIMR0_0x0006a004 , data );
            if (rc)
            {
                 FAPI_ERR("fapiPutScom(OCB_OCI_OIMR0_0x0006a004) failed."); break;
            }
        }

        ////////////////////////////////////////////////////////////////////////////
        // Issue halt to Pstate Master FSM on master_chiptarget
        // Issue halt to Pstate Master FSM on slave_chiptarget
        //
        // 3. cRQ_TD_DisableMPS: Write PMC_MODE_REG to halt things
        //    halt_pstate_master_fsm<-1          <-1 indicates to write the bit with the value 1
        //    halt_idle_state_master_fsm<-1      <-1 indicates to write the bit with the value 1
        //    Note: Other bits are left as setup so the configuration remains as things halt, and new
        //          requests are queued (just now processed now).
        ////////////////////////////////////////////////////////////////////////////


        // ******************************************************
        // Master
        // ******************************************************
        FAPI_INF("Halt Pstates and Idles on Master");

        rc = fapiGetScom(master_target, PMC_MODE_REG_0x00062000 , data );
        if (rc)
        {
             FAPI_ERR("fapiGetScom(PMC_MODE_REG_0x00062000) failed.");
             break;
        }

        e_rc |= data.setBit(05);
        e_rc |= data.setBit(14);
        if (e_rc)
        {
            FAPI_ERR("ecmdDataBufferBase error setting up PMC_MODE_REG_0x00062000 on Master during reset");
            rc.setEcmdError(e_rc);
            break;
        }

        rc = fapiPutScom(master_target, PMC_MODE_REG_0x00062000 , data );
        if (rc)
        {
             FAPI_ERR("fapiPutScom(PMC_MODE_REG_0x00062000) failed.");
             break;
        }

        master_is_MasterPMC = pmcmode_master.isBitSet(6) && pmcmode_master.isBitSet(7) ;
        master_enable_pstate_voltage_changes = pmcmode_master.isBitSet(3) ;
//        master_enable_fw_pstate_mode = pmcmode_master.isBitSet(2) ;
        master_is_enable_interchip_interface = pmcmode_master.isBitSet(6) ;

        // Resave the updated PMC Mode reg
        pmcmode_master = data;

        // ******************************************************
        // Slave
        // ******************************************************

        if (dcm)
        {
            FAPI_INF("Halt Pstates and Idles on Slave");
            rc = fapiGetScom(slave_target, PMC_MODE_REG_0x00062000 , pmcmode_master );
            if (rc)
            {
              FAPI_ERR("fapiGetScom(PMC_MODE_REG_0x00062000) failed.");
              break;
            }

            e_rc |= data.setBit(05);
            e_rc |= data.setBit(14);
            if (e_rc)
            {
                FAPI_ERR("ecmdDataBufferBase error setting up PMC_MODE_REG_0x00062000 on Slave during reset");
                rc.setEcmdError(e_rc);
                break;
            }

            rc = fapiPutScom(slave_target, PMC_MODE_REG_0x00062000 , data );
            if (rc)
            {
                 FAPI_ERR("fapiPutScom(PMC_MODE_REG_0x00062000) failed.");
                 break;
            }

            slave_is_MasterPMC = pmcmode_slave.isBitSet(6) && pmcmode_slave.isBitSet(7) ;
//            slave_enable_pstate_voltage_changes = pmcmode_slave.isBitSet(3) ;
//            slave_enable_fw_pstate_mode = pmcmode_slave.isBitSet(2) ;
            slave_is_enable_interchip_interface = pmcmode_slave.isBitSet(6) ;

            // Resave the updated PMC Mode reg
            pmcmode_slave = data;

        }



        ////////////////////////////////////////////////////////////////////////////
        // Issue halt to interchip FSM on master_chiptarget
        // Poll for interchip interface to stop on master_chiptarget
        // If poll not complete, flag "reset_suspicious" and save the poll point; continue

        // Issue halt to interchip FSM on slave_chiptarget
        // Poll for interchip interface to stop on slave_chiptarget
        // If poll not complete, flag "reset_suspicious" and save the poll point; continue

        // Poll for Pstate Master FSM being stopped on slave_chiptarget
        // If poll not complete, flag "reset_suspicious" and save the poll point; continue
        // Poll for Pstate Master FSM being stopped on slave_chiptarget
        // If poll not complete, flag "reset_suspicious" and save the poll point; continue
        //
        // 4. if enable_interchip_interface==1
        //       cRQ_TD_HaltInterchip_On: Write PMC_INTCHP_COMMAND_REG.interchip_halt_msg_fsm<-1 Should we write the command register here ? That's why I specified the command register, PMC_INTCHP_COMMAND_REG.
        //    cRQ_TD_HaltInterchip_Wait1: Read PMC_STATUS_REG
        //    cRQ_TD_HaltInterchip_Wait2: Read PMC_INTCHP_STATUS_REG
        //       is_pstate_error_stopped = pstate_processing_is_suspended || gpsa_bdcst_error || gpsa_vchg_error || gpsa_timeout_error || pstate_interchip_error
        //       is_intchp_error_stopped = interchip_ecc_ue_err || interchip_fsm_err || (is_MasterPMC && interchip_slave_error_code != 0) is_MasterPMC where is this bit ?
        //       is_stopped = (interchip_ga_ongoing == 0) || is_pstate_error_stopped || is_intchp_error_stopped
        //       If !is_stopped Then -->cRQ_TD_HaltInterchip_Wait1  (Wait limit is parm TD_Interchip_HaltWait_max=260)
        //    cRQ_TD_HaltInterchipIf: PMC_MODE_REG.interchip_halt_if<-1 interchip_halt_if where is this bit ? PMC_MODE_REG bit 15 as documented.


        ////////////////////////////////////////////////////////////////////////////

        // ******************************************************
        // Master
        // ******************************************************
        if (dcm)
        {
            FAPI_INF("Halt interchip interface on Master");
            if (master_is_enable_interchip_interface == 1)
            {
                rc = p8_pmc_poll_interchip_halt(master_target, MASTER_SIDE, master_is_MasterPMC, slave_target );
                if (rc)
                {
                    FAPI_ERR("p8_pmc_poll_interchip_halt detected a failure.");
                    break;
                }
            }

            // ******************************************************
            // Slave
            // ******************************************************
            FAPI_INF("Halt interchip interface on Slave");
            if (slave_is_enable_interchip_interface ==1)
            {
                rc = p8_pmc_poll_interchip_halt(slave_target, SLAVE_SIDE, slave_is_MasterPMC, master_target);
                if (rc)
                {
                    FAPI_ERR("p8_pmc_poll_interchip_halt detected a failure.");
                    break;
                }
            }
        } // end dcm

        ////////////////////////////////////////////////////////////////////////////
        // If voltage changes are enabled, issue halt to SPIVID controller on FSM on master_chiptarget
        // Poll for SPIVID FSM to halt on master_chiptarget
        // If poll not complete, flag "reset_suspicious" and save the poll point; continue
        //
        // 5. if enable_pstate_voltage_changes==1
        //         HaltSpivid: PMC_SPIV_COMMAND_REG.spivid_halt_fsm<-1
        //    Spivid_HaltWait: Read PMC_SPIV_STATUS_REG
        //       is_spivid_error = spivid_retry_timeout || spivid_fsm_err
        //       if spivid_ongoing && !is_spivid_error Then -->Spivid_HaltWait
        //       else -->MPS_HaltWait
        ////////////////////////////////////////////////////////////////////////////

        if (master_enable_pstate_voltage_changes==1)
        {
            FAPI_INF("Halt SPIVID controller on Master");
            rc = p8_pmc_poll_spivid_halt(master_target, MASTER_SIDE);
            if (rc)
            {
                FAPI_ERR("p8_pmc_poll_spivid_halt detected a failure.");
                break;
            }
        }

        ////////////////////////////////////////////////////////////////////////////
        // Poll for Pstate Master FSM being stopped on master_chiptarget
        //   If poll not complete, flag "reset_suspicious" and save the poll point; continue
        // Poll for Pstate Master FSM being stopped on slave_chiptarget
        //   If poll not complete, flag "reset_suspicious" and save the poll point; continue
        //
        // 6. MPS_HaltWait: Read PMC_STATUS_REG
        //
        //       if (fw_pstate_mode)
        //          is_not_ongoing = (enable_pstate_voltage_changes==0 || volt_chg_ongoing==0) && (brd_cst_ongoing == 0)
        //       else
        //          is_not_ongoing = (enable_pstate_voltage_changes==0 || gpsa_chg_ongoing==0)
        //
        //       is_pstate_error = (pstate_interchip_error || pstate_processing_is_suspended || gpsa_bdcst_error || gpsa_vchg_error || gpsa_timeout_error)
        //            is_stopped = is_not_ongoing || is_pstate_error
        //
        //       if (!is_stopped) then -->MPS_HaltWait   (Wait limit)
        ////////////////////////////////////////////////////////////////////////////

         FAPI_INF("Check for Pstate FSM being stopped on Master");

         rc = p8_pmc_poll_pstate_halt(master_target, MASTER_SIDE);
         if (rc)
         {
             FAPI_ERR("p8_pmc_poll_pstate_halt error detected for PMC Master");
             break;
         }

        // ******************************************************
        // Slave
        // ******************************************************
        if (dcm)
        {
            FAPI_INF("Check for Pstate FSM being stopped on Slave");

            rc = p8_pmc_poll_pstate_halt(master_target, SLAVE_SIDE);
            if (rc)
            {
                FAPI_ERR("p8_pmc_poll_pstate_halt error detected for PMC Slave");
                break;
            }

        } // dcm


        ///////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Poll for O2P bridge being complete on master_chiptarget
        // As the OCC (PPC405) has been halt prior to entry of this procedure,
        //      this poll will be immediate if there are no PIB related errors present
        // Poll for O2P bridge being complete on slave_chiptarget
        // As the OCC (PPC405) has been halt prior to entry of this procedure,
        //      this poll will be immediate if there are no PIB related errors present
        //
        // Poll for O2S bridge being complete on master_chiptarget
        // As the OCC (PPC405) has been halt prior to entry of this procedure,
        //      this poll will be immediate if there are no SPIVID related errors present
        //
        // 7. Wait
        //      - If an O2P or O2S Op is pending and did not hit an error
        //      - Queisce after traffic generation or last FW GA_Step
        //    The O2P and O2S bridges are treated separately.  The firmware should handle these
        //    recognizing they are still busy, hit an error, or hit a firmware timeout.  The
        //    firmware can then choose a halt sequence for them.
        //    O2S: Write PMC_O2S_COMMAND_REG.o2s_halt_retries<-1
        //         Read PMC_O2S_STATUS_REG
        //         Wait for o2s_ongoing==0 or error (o2s_retry_timeout | o2s_write_while_bridge_busy_err | o2s_fsm_err)
        //    O2P: No halt command in PMC - wait for PIB timeout.
        //         Read PMC_O2P_CTRL_STATUS_REG
        //         Wait for o2p_ongoing==0 or error (o2p_write_while_bridge_busy_err | o2p_fsm_err | o2p_abort | o2p_parity_error)
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////

        // ******************************************************
        // Master
        // ******************************************************

        FAPI_INF("Poll for O2P bridge being complete on Master");

        rc = p8_pmc_poll_o2p_halt(master_target, MASTER_SIDE);
        if (rc)
        {
            FAPI_ERR("p8_pmc_poll_o2p_halt error detected for PMC Master");
            break;
        }

        // ******************************************************
        // Slave
        // ******************************************************

        if (dcm)
        {
            FAPI_INF("Poll for O2P bridge being complete on Slave");

            rc = p8_pmc_poll_o2p_halt(slave_target, SLAVE_SIDE);
            if (rc)
            {
                FAPI_ERR("p8_pmc_poll_o2p_halt error detected for PMC Slave");
                break;
            }
        }


        ///////////////////////////////////////////////////////////////////////////////////////////////////////////
        // 8) Poll for Idle FSM being quiesced (timeout: 500ms to cover the case of having all 4 types of Deep Idle
        // transitions in flight)
        // Note: Previously issued special wake-ups could have triggered PORE activity through the Idle FSM (and
        // the related pending queues). if poll timeout, FAIL THE OCC RESET AS SLW RECOVER IS COMPROMISED
        //
        // Note on Idle/PORE-SLW state (prior to reset)
        // Given that special wake-up occurred before this point, any errors that resulted from that special wake-up
        // (eg PORE-SLW fatal or timeout indicated in PMC LFIR) will have fired a malfunction alert to PHYP whereby
        // the execution of p8_poreslw_recovery.C will have taken place.
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////

        // ******************************************************
        // Master
        // ******************************************************

        FAPI_INF("Poll for Idle FSM being quiesced on Master");

        rc = p8_pmc_poll_idle_halt(master_target, MASTER_SIDE);
        if (rc)
        {
            FAPI_ERR("p8_pmc_poll_idle_halt error detected for PMC Master");
            break;
        }


        // ******************************************************
        // Slave
        // ******************************************************

        if (dcm)
        {
            FAPI_INF("Poll for Idle FSM being quiesced on Slave");
            rc = p8_pmc_poll_idle_halt(slave_target, SLAVE_SIDE);
            if (rc)
            {
                FAPI_ERR("p8_pmc_poll_idle_halt error detected for PMC Slave");
                break;
            }
        }

        ///////////////////////////////////////////////////////////////////////////////
        // Issue interchip interface reset (if enabled) on master_chiptarget
        // PMC_INTCHP_COMMAND_REG.reset (0) = 1
        // PMC_INTCHP_COMMAND_REG.reset (0) = 0
        // Issue interchip interface reset (if enabled) on slave_chiptarget
        // PMC_INTCHP_COMMAND_REG.reset (0) = 1
        // PMC_INTCHP_COMMAND_REG.reset (0) = 0
        ///////////////////////////////////////////////////////////////////////////////

        // ******************************************************
        // Master
        // ******************************************************


        FAPI_INF("Reset interchip interface on Master");

        if ( master_is_enable_interchip_interface == 1)
        {

            rc = fapiGetScom(master_target, PMC_INTCHP_COMMAND_REG_0x00062014 , data );
            if (rc)
            {
                FAPI_ERR("fapiGetScom(PMC_INTCHP_COMMAND_REG_0x00062014) failed.");
                break;
            }

            e_rc = data.setBit(0);
            if (e_rc)
            {
                FAPI_ERR("ecmdDataBufferBase error setting up PMC_INTCHP_COMMAND_REG_0x00062014 on Master reset");
                rc.setEcmdError(e_rc);
                break;
            }

            rc = fapiPutScom(master_target, PMC_INTCHP_COMMAND_REG_0x00062014 , data );
            if (rc)
            {
                FAPI_ERR("fapiPutScom(PMC_INTCHP_COMMAND_REG_0x00062014) failed.");
                break;
            }

            e_rc = data.clearBit(0);
            if (e_rc)
            {
                FAPI_ERR("ecmdDataBufferBase error clearing up PMC_INTCHP_COMMAND_REG_0x00062014 on Master reset");
                rc.setEcmdError(e_rc);
                break;
            }

            rc = fapiPutScom(master_target, PMC_INTCHP_COMMAND_REG_0x00062014 , data );
            if (rc)
            {
                FAPI_ERR("fapiPutScom(PMC_INTCHP_COMMAND_REG_0x00062014) failed.");
                break;
            }
        }

        // ******************************************************
        // Slave
        // ******************************************************

         if (dcm)
         {
             FAPI_INF("Reset interchip interface on Slave");

             if ( slave_is_enable_interchip_interface == 1)
             {

                rc = fapiGetScom(slave_target, PMC_INTCHP_COMMAND_REG_0x00062014 , data );
                if (rc)
                {
                    FAPI_ERR("fapiGetScom(PMC_INTCHP_COMMAND_REG_0x00062014) failed.");
                    break;
                }

                e_rc = data.setBit(0);
                if (e_rc)
                {
                    FAPI_ERR("ecmdDataBufferBase error setting up PMC_INTCHP_COMMAND_REG_0x00062014 on Slave reset");
                    rc.setEcmdError(e_rc);
                    break;
                }

                rc = fapiPutScom(slave_target, PMC_INTCHP_COMMAND_REG_0x00062014 , data );
                if (rc)
                {
                    FAPI_ERR("fapiPutScom(PMC_INTCHP_COMMAND_REG_0x00062014) failed.");
                    break;
                }

                e_rc = data.clearBit(0);
                if (e_rc)
                {
                    FAPI_ERR("ecmdDataBufferBase error clearing up PMC_INTCHP_COMMAND_REG_0x00062014 on Slave reset");
                    rc.setEcmdError(e_rc);
                    break;
                }

                rc = fapiPutScom(slave_target, PMC_INTCHP_COMMAND_REG_0x00062014 , data );
                if (rc)
                {
                    FAPI_ERR("fapiPutScom(PMC_INTCHP_COMMAND_REG_0x00062014) failed.");
                    break;
                }
            }
        }

        ////////////////////////////////////////////////////////////////////////
        // Issue reset to the PMC
        // Note:  this action will wipe out the Idle Pending queue so that
        // requests for idle transitions (entry and exit) will be lost which
        // means that PHYP notification needs to happen.
        //
        // Write PMC_MODE_REG.pmc_reset_all_voltage_registers = 1.
        // Clearing LFIRs will have  been done by PRD
        // Note:  this will remove CONFIG settings
        // This puts the PMC into firmware mode which halts any future Global Actual operations
        ////////////////////////////////////////////////////////////////////////

        // ******************************************************
        // Master
        // ******************************************************
        // RESET_ALL_PMC_REGISTERS

        if (i_mode == PM_RESET)
        {
            FAPI_INF("Hard reset detected");
            FAPI_INF("Reset PMC on Master");
            rc = fapiGetScom(master_target, PMC_MODE_REG_0x00062000 , data );
            if (rc)
            {
                FAPI_ERR("fapiGetScom(PMC_MODE_REG_0x00062000) failed.");
                break;
            }

            e_rc = data.setBit(12);
                if (e_rc)
                {
                    FAPI_ERR("ecmdDataBufferBase error setting up PMC_INTCHP_COMMAND_REG_0x00062014 on Master reset");
                    rc.setEcmdError(e_rc);
                    break;
                }
            if (rc)
            {
                FAPI_ERR("fapiPutScom(PMC_INTCHP_COMMAND_REG_0x00062014) failed.");
                break;
            }

            rc = fapiPutScom(master_target, PMC_MODE_REG_0x00062000 , data );
            if (rc)
            {
                 FAPI_ERR("fapiPutScom(PMC_MODE_REG_0x00062000) failed.");
                 break;
            }

            // ******************************************************
            // Slave
            // ******************************************************
            if (dcm)
            {
                FAPI_INF("Reset PMC on Slave");

                rc = fapiGetScom(slave_target, PMC_MODE_REG_0x00062000 , data );
                if (rc)
                {
                     FAPI_ERR("fapiGetScom(PMC_MODE_REG_0x00062000) failed.");
                     break;
                }

                e_rc = data.setBit(12);
                if (e_rc)
                {
                    FAPI_ERR("ecmdDataBufferBase error setting up PMC_MODE_REG_0x00062000 on Slave reset");
                    rc.setEcmdError(e_rc);
                    break;
                }

                rc = fapiPutScom(slave_target, PMC_MODE_REG_0x00062000 , data );
                if (rc)
                {
                    FAPI_ERR("fapiPutScom(PMC_MODE_REG_0x00062000) failed.");
                    break;
                }
            }
        }
        else
        {
            FAPI_INF("Soft reset detected. PMC register reset skipped.");
        }
    } while(0);

    FAPI_INF("pmc_reset end...");

    return rc;
}

// ----------------------------------------------------------------------
/**
 * pmc_init_function
 *
 * @param[in] i_target Primary Chip target:   Murano - chip0; Venice - chip
 * @param[in] i_dcm     Boolean to run in DCM or SCM mode
 *
 * @retval ECMD_SUCCESS
 * @retval ERROR defined in xml
 */
fapi::ReturnCode pmc_init_function(const fapi::Target& i_target, bool i_dcm )
{
    fapi::ReturnCode rc;
    uint32_t        e_rc;
    ecmdDataBufferBase data(64);
    uint8_t         attr_pm_spivid_frame_size;
    uint8_t         attr_pm_spivid_in_delay_frame1;
    uint8_t         attr_pm_spivid_in_delay_frame2;
    uint8_t         attr_pm_spivid_clock_polarity;
    uint8_t         attr_pm_spivid_clock_phase;
    uint32_t        attr_pm_spivid_clock_divider;
    uint8_t         attr_pm_spivid_port_enable = 7;
    uint32_t        attr_pm_spivid_interframe_delay_write_status_value;
    uint32_t        attr_pm_spivid_inter_retry_delay_value;
    uint8_t         attr_pm_spivid_crc_gen_enable;
    uint8_t         attr_pm_spivid_crc_check_enable;
    uint8_t         attr_pm_spivid_majority_vote_enable;
    uint8_t         attr_pm_spivid_max_retries;
    uint8_t         attr_pm_spivid_crc_polynomial_enables;


    const uint8_t   default_spivid_frame_size = 32;
    const uint8_t   default_spivid_in_delay_frame1 = 0;
    const uint8_t   default_spivid_in_delay_frame2 = 0;
    const uint8_t   default_spivid_clock_polarity = 0;
    const uint8_t   default_spivid_clock_phase = 0;
    const uint32_t  default_spivid_port_enable = 0x0;
    const uint8_t   default_spivid_crc_gen_enable = 1;
    const uint8_t   default_spivid_crc_check_enable = 0;
    const uint8_t   default_spivid_majority_vote_enable = 1;
    const uint8_t   default_spivid_max_retries = 5;
    const uint8_t   default_spivid_crc_polynomial_enables = 0xD5;

    uint32_t        var_100ns_div_value = 0;
    uint32_t        proc_nest_frequency = 2400;
    uint32_t        attr_pm_interchip_frequency = 10;
    uint32_t        interchip_clock_divider = 0 ;

    do
    {

        rc = FAPI_ATTR_GET(ATTR_FREQ_PB, NULL, proc_nest_frequency);
        if (rc)
        {
            FAPI_ERR("fapiGetAttribute of ATTR_FREQ_PB with rc = 0x%x", (uint32_t)rc);
            break;
        }

        //    var_100ns_div_value = (( attr_proc_pss_init_nest_frequency * 1000000 * 100) /4000000000);
        var_100ns_div_value =    (( proc_nest_frequency ) /40);
        interchip_clock_divider = ( proc_nest_frequency /(attr_pm_interchip_frequency*8)-1 );

            //----------------------------------------------------------
        GETATTR_DEFAULT(rc,
                        ATTR_PM_SPIVID_FRAME_SIZE,
                        "ATTR_PM_SPIVID_FRAME_SIZE",
                        &i_target,
                        attr_pm_spivid_frame_size,
                        default_spivid_frame_size );

            //----------------------------------------------------------
        GETATTR_DEFAULT(rc,
                        ATTR_PM_SPIVID_IN_DELAY_FRAME1,
                        "ATTR_PM_SPIVID_IN_DELAY_FRAME1",
                        &i_target,
                        attr_pm_spivid_in_delay_frame1,
                        default_spivid_in_delay_frame1 );

            //----------------------------------------------------------
        GETATTR_DEFAULT(rc,
                        ATTR_PM_SPIVID_IN_DELAY_FRAME1,
                        "ATTR_PM_SPIVID_IN_DELAY_FRAME1",
                        &i_target,
                        attr_pm_spivid_in_delay_frame2,
                        default_spivid_in_delay_frame2 );

            //----------------------------------------------------------
        GETATTR_DEFAULT(rc,
                        ATTR_PM_SPIVID_CLOCK_POLARITY,
                        "ATTR_PM_SPIVID_CLOCK_POLARITY",
                        &i_target,
                        attr_pm_spivid_clock_polarity,
                        default_spivid_clock_polarity );

            //----------------------------------------------------------
        GETATTR_DEFAULT(rc,
                        ATTR_PM_SPIVID_CLOCK_PHASE,
                        "ATTR_PM_SPIVID_CLOCK_PHASE",
                        &i_target,
                        attr_pm_spivid_clock_phase,
                        default_spivid_clock_phase );

            //----------------------------------------------------------
        GETATTR_DEFAULT(rc,
                        ATTR_PM_SPIVID_CRC_GEN_ENABLE,
                        "ATTR_PM_SPIVID_CRC_GEN_ENABLE",
                        &i_target,
                        attr_pm_spivid_crc_gen_enable,
                        default_spivid_crc_gen_enable );

            //----------------------------------------------------------
        GETATTR_DEFAULT(rc,
                        ATTR_PM_SPIVID_CRC_CHECK_ENABLE,
                        "ATTR_PM_SPIVID_CRC_CHECK_ENABLE",
                        &i_target,
                        attr_pm_spivid_crc_check_enable,
                        default_spivid_crc_check_enable );

            //----------------------------------------------------------
        GETATTR_DEFAULT(rc,
                        ATTR_PM_SPIVID_MAJORITY_VOTE_ENABLE,
                        "ATTR_PM_SPIVID_CRC_CHECK_ENABLE",
                        &i_target,
                        attr_pm_spivid_majority_vote_enable,
                        default_spivid_majority_vote_enable );

            //----------------------------------------------------------
        GETATTR_DEFAULT(rc,
                        ATTR_PM_SPIVID_MAX_RETRIES,
                        "ATTR_PM_SPIVID_MAX_RETRIES",
                        &i_target,
                        attr_pm_spivid_max_retries,
                        default_spivid_max_retries );

            //----------------------------------------------------------
        GETATTR_DEFAULT(rc,
                        ATTR_PM_SPIVID_CRC_POLYNOMIAL_ENABLES,
                        "ATTR_PM_SPIVID_CRC_POLYNOMIAL_ENABLES",
                        &i_target,
                        attr_pm_spivid_crc_polynomial_enables,
                        default_spivid_crc_polynomial_enables );

            //----------------------------------------------------------
        GETATTR_DEFAULT(rc,
                        ATTR_PM_SPIVID_PORT_ENABLE,
                        "ATTR_PM_SPIVID_PORT_ENABLE",
                        &i_target,
                        attr_pm_spivid_port_enable,
                        default_spivid_port_enable );

           //----------------------------------------------------------
        GETATTR(        rc,
                        ATTR_PM_SPIVID_CLOCK_DIVIDER,
                        "ATTR_PM_SPIVID_CLOCK_DIVIDER",
                        &i_target,
                        attr_pm_spivid_clock_divider);

            //----------------------------------------------------------
        GETATTR(        rc,
                        ATTR_PM_SPIVID_INTERFRAME_DELAY_WRITE_STATUS_VALUE,
                        "ATTR_PM_SPIVID_INTERFRAME_DELAY_WRITE_STATUS_VALUE",
                        &i_target,
                        attr_pm_spivid_interframe_delay_write_status_value);

            //----------------------------------------------------------
        GETATTR(        rc,
                        ATTR_PM_SPIVID_INTER_RETRY_DELAY_VALUE,
                        "ATTR_PM_SPIVID_INTER_RETRY_DELAY_VALUE",
                        &i_target,
                        attr_pm_spivid_inter_retry_delay_value);

        FAPI_INF("PMC initialization as %s ...", i_dcm ? "DCM" : "SCM");

        uint8_t     o2s_frame_size = attr_pm_spivid_frame_size;
        uint8_t     o2s_in_delay1  = attr_pm_spivid_in_delay_frame1;
        uint8_t     o2s_in_delay2  = attr_pm_spivid_in_delay_frame2;
        uint8_t     o2s_clk_pol    = attr_pm_spivid_clock_polarity;
        uint8_t     o2s_clk_pha    = attr_pm_spivid_clock_phase;
        uint8_t     o2s_port_enable = attr_pm_spivid_port_enable;
        uint32_t    o2s_inter_frame_delay = attr_pm_spivid_interframe_delay_write_status_value;
        uint8_t     o2s_crc_gen_en = attr_pm_spivid_crc_gen_enable;
        uint8_t     o2s_crc_check_en = attr_pm_spivid_crc_check_enable;
        uint8_t     o2s_majority_vote_en = attr_pm_spivid_majority_vote_enable;
        uint8_t     o2s_max_retries = attr_pm_spivid_max_retries;
        uint8_t     o2s_crc_polynomial_enables = attr_pm_spivid_crc_polynomial_enables;
        uint16_t    o2s_clk_divider = attr_pm_spivid_clock_divider;
        //spivid_freq =  attr_pm_spivid_frequency;
        uint8_t     o2s_in_count2        = o2s_frame_size ;
        uint8_t     o2s_out_count2          = 0 ;
        uint8_t     o2s_bridge_enable = 0x1 ;
        uint8_t     o2s_nr_of_frames        = 2 ;
        uint8_t     o2s_in_count1        = 0 ;
        uint8_t     o2s_out_count1        = o2s_frame_size ;
        uint8_t     hangpulse_predivider = 1;
        uint8_t     gpsa_timeout_value   = 100;
        uint8_t     one=1;
        uint8_t     zero=0;
        uint8_t     is_master=0;
        uint8_t     is_slave=1;

        uint8_t     is_simulation = 0;
        uint64_t    any_error = 0;

        rc = FAPI_ATTR_GET( ATTR_IS_SIMULATION, NULL, is_simulation);
        if (rc)
        {
            FAPI_ERR("Failed to get attribute: ATTR_IS_SIMULATION.");
            break ;
        }

        if (is_simulation)
        {
            // Simulation value
            gpsa_timeout_value   = 100;
        }
        else
        {
            // Hardware
            gpsa_timeout_value   = 255;
        }

        // Here to bypass feature attribute passing until these as moved into proc.pm.pmc.scom.initfile
        o2s_bridge_enable = 0x1 ;

        e_rc = data.flushTo0();
        if (e_rc)
        {
            FAPI_ERR("ecmdDataBufferBase error flushing buffer");
            rc.setEcmdError(e_rc);
            break;
        }

        rc = fapiGetScom(i_target, PMC_LFIR_0x01010840 , data );
        if (rc)
        {
            FAPI_ERR("fapiGetScom(PMC_LFIR_0x01010840) failed.");
            break;
        }

        any_error = data.getDoubleWord(0);

        if (any_error)
        {
            // Once clear FIRs are established, this will throw errors.
            FAPI_INF("WARNING: PMC_FIR has error(s) active.  0x%016llX ", data.getDoubleWord(0));
            //FAPI_ERR(" PMC_FIR has error(s) active.  0x%16llX ", data.getDoubleWord(0));
            //FAPI_SET_HWP_ERROR(rc, RC_PROCPM_FIR_ERROR);
            //break;
        }

        //  ******************************************************************
        //     - set PMC_o2s_CTRL_REG0A (24b)
        //  ******************************************************************

        rc = fapiGetScom(i_target, PMC_O2S_CTRL_REG0A_0x00062050, data );
        if (rc)
        {
             FAPI_ERR("fapiGetScom(PMC_O2S_CTRL_REG0A) failed.");
             break;
        }

        e_rc  = data.insertFromRight(o2s_frame_size , 0,6);
        e_rc |= data.insertFromRight(o2s_out_count1 , 6,6);
        e_rc |= data.insertFromRight(o2s_in_delay1  ,12,6);
        e_rc |= data.insertFromRight(o2s_in_count1  ,18,6);
        if (e_rc)
        {
            FAPI_ERR("ecmdDataBufferBase error setting up PMC_O2S_CTRL_REG0A on Master init");
            rc.setEcmdError(e_rc);
            break;
        }

        FAPI_INF("  PMC_O2S_CTRL_REG0A / PMC_SPIV_CTRL_REG0A  Configuration");
        FAPI_INF("    frame size                 => %d ",  o2s_frame_size);
        FAPI_INF("    o2s_out_count1             => %d ",  o2s_out_count1);
        FAPI_INF("    o2s_in_delay1              => %d ",  o2s_in_delay1);
        FAPI_INF("    o2s_in_count1              => %d ",  o2s_in_count1);

        rc = fapiPutScom(i_target, PMC_O2S_CTRL_REG0A_0x00062050, data );
        if (rc)
        {
            FAPI_ERR("fapiPutScom(PMC_O2S_CTRL_REG0A_0x00062050) failed.");
            break;
        }

        rc = fapiPutScom(i_target, PMC_SPIV_CTRL_REG0A_0x00062040, data );
        if (rc)
        {
            FAPI_ERR("fapiPutScom(PMC_SPIV_CTRL_REG0A_0x00062040) failed.");
            break;
        }

        //  ******************************************************************
        //     - set PMC_O2S_CTRL_REG0B (24b)
        //  ******************************************************************

        rc = fapiGetScom(i_target, PMC_O2S_CTRL_REG0B_0x00062051, data );
        if (rc)
        {
            FAPI_ERR("fapiGetScom(PMC_O2S_CTRL_REG0B) failed.");
            break;
        }

        e_rc  = data.insertFromRight(o2s_out_count2,00,6);
        e_rc |= data.insertFromRight(o2s_in_delay2 ,06,6);
        e_rc |= data.insertFromRight(o2s_in_count2 ,12,6);
        if (e_rc)
        {
            FAPI_ERR("ecmdDataBufferBase error setting up PMC_O2S_CTRL_REG0B_0x00062051 on Master init");
            rc.setEcmdError(e_rc);
            break;
        }

        FAPI_INF("  PMC_O2S_CTRL_REG0B_ / PMC_SPIV_CTRL_REG0B Configuration");
        FAPI_INF("    o2s_out_count2             => %d ",  o2s_out_count2);
        FAPI_INF("    o2s_in_delay2              => %d ",  o2s_in_delay2 );
        FAPI_INF("    o2s_in_count2              => %d ",  o2s_in_count2 );

        rc = fapiPutScom(i_target, PMC_O2S_CTRL_REG0B_0x00062051, data );
        if (rc)
        {
            FAPI_ERR("fapiPutScom(PMC_O2S_CTRL_REG0B_0x00062051) failed.");
            break;
        }

        rc = fapiPutScom(i_target, PMC_SPIV_CTRL_REG0B_0x00062041, data );
        if (rc)
        {
            FAPI_ERR("fapiPutScom(PMC_SPIV_CTRL_REG0B_0x00062041) failed.");
            break;
        }

        //  ******************************************************************
        //     - set PMC_O2S_CTRL_REG1
        //  ******************************************************************

        rc = fapiGetScom(i_target, PMC_O2S_CTRL_REG1_0x00062052, data );
        if (rc)
        {
            FAPI_ERR("fapiGetScom(PMC_O2S_CTRL_REG1) failed.");
            break;
        }

        o2s_nr_of_frames--;
        e_rc = data.insertFromRight(o2s_bridge_enable   ,0 ,1);
        e_rc |= data.insertFromRight(o2s_clk_pol         ,2 ,1);
        e_rc |= data.insertFromRight(o2s_clk_pha         ,3 ,1);
        e_rc |= data.insertFromRight(o2s_clk_divider     ,4 ,10);
        e_rc |= data.insertFromRight(o2s_nr_of_frames    ,17,1);
        e_rc |= data.insertFromRight(o2s_port_enable     ,18,3);
        if (e_rc)
        {
            FAPI_ERR("ecmdDataBufferBase error setting up PMC_O2S_CTRL_REG1 on Master init");
            rc.setEcmdError(e_rc);
            break;
        }

        o2s_nr_of_frames++ ;
        FAPI_INF("  PMC_O2S_CTRL_REG1 / PMC_SPIV_CTRL_REG1 ");
        FAPI_INF("    o2s_bridge_enable           => %d ",  o2s_bridge_enable );
        FAPI_INF("    o2s_clk_pol                 => %d ",  o2s_clk_pol    );
        FAPI_INF("    o2s_clk_pha                 => %d ",  o2s_clk_pha    );
        FAPI_INF("    o2s_clk_divider             => 0x%x", o2s_clk_divider);
        FAPI_INF("    o2s_nr_of_frames            => %d ",  o2s_nr_of_frames);
        FAPI_INF("    o2s_port_enable             => %d ",  o2s_port_enable);


        rc = fapiPutScom(i_target, PMC_O2S_CTRL_REG1_0x00062052, data );
        if (rc)
        {
            FAPI_ERR("fapiPutScom(PMC_O2S_CTRL_REG1_0x00062052) failed.");
             break;
        }

        rc = fapiPutScom(i_target, PMC_SPIV_CTRL_REG1_0x00062042, data );
        if (rc)
        {
            FAPI_ERR("fapiPutScom(PMC_SPIV_CTRL_REG1_0x00062042) failed.");
            break;
        }

        //  ******************************************************************
        //     - set PMC_O2S_CTRL_REG2
        //  ******************************************************************

        rc = fapiGetScom(i_target, PMC_O2S_CTRL_REG2_0x00062053, data );
        if (rc)
        {
            FAPI_ERR("fapiGetScom(PMC_O2S_CTRL_REG2) failed.");
            break;
        }

        e_rc = data.insertFromRight(  o2s_inter_frame_delay   ,0,17);
        if (e_rc)
        {
            FAPI_ERR("ecmdDataBufferBase error setting up PMC_O2S_CTRL_REG2 on Master init");
            rc.setEcmdError(e_rc);
            break;
        }


        FAPI_INF("  PMC_O2S_CTRL_REG2_ / PMC_SPIV_CTRL_REG2Configuration");
        FAPI_INF("    o2s_inter_frame_delay       => %d ",  o2s_inter_frame_delay );

        rc = fapiPutScom(i_target, PMC_O2S_CTRL_REG2_0x00062053, data );
        if (rc)
        {
            FAPI_ERR("fapiPutScom(PMC_O2S_CTRL_REG2_0x00062053) failed.");
            break;
        }

        rc = fapiPutScom(i_target, PMC_SPIV_CTRL_REG2_0x00062043, data );
        if (rc)
        {
            FAPI_ERR("fapiPutScom(PMC_SPIV_CTRL_REG2_0x00062043) failed.");
            break;
        }

        //  ******************************************************************
        //     - set PMC_SPIV_CTRL_REG3
        //  ******************************************************************

        rc = fapiGetScom(i_target, PMC_SPIV_CTRL_REG3_0x00062044, data );
        if (rc)
        {
            FAPI_ERR("fapiGetScom(PMC_SPIV_CTRL_REG3) failed.");
            break;
        }

        e_rc = data.insertFromRight(  attr_pm_spivid_inter_retry_delay_value   ,0,17);
        e_rc |= data.insertFromRight(  var_100ns_div_value , 17 , 6);
        if (e_rc)
        {
            FAPI_ERR("ecmdDataBufferBase error setting up PMC_SPIV_CTRL_REG3 on Master init");
            rc.setEcmdError(e_rc);
            break;
        }

        FAPI_INF("  PMC_SPIV_CTRL_REG3 Configuration                  ");
        FAPI_INF("    spivid_inter_retry_delay_value => %d ",  attr_pm_spivid_inter_retry_delay_value );
        FAPI_INF("    100ns_div_value                => %d ",  var_100ns_div_value);

        rc = fapiPutScom(i_target, PMC_SPIV_CTRL_REG3_0x00062044, data );
        if (rc)
        {
            FAPI_ERR("fapiPutScom(PMC_SPIV_CTRL_REG3_0x00062044) failed.");
            break;
        }

            //  ******************************************************************
        //     - set PMC_O2S_CTRL_REG4
        //  ******************************************************************

        rc = fapiGetScom(i_target, PMC_O2S_CTRL_REG4_0x00062055, data );
        if (rc)
        {
            FAPI_ERR("fapiGetScom(PMC_O2S_CTRL_REG4) failed.");
            break;
        }

        e_rc  = data.insertFromRight(  o2s_crc_gen_en         ,0,1);
        e_rc |= data.insertFromRight(  o2s_crc_check_en       ,1,1);
        e_rc |= data.insertFromRight(  o2s_majority_vote_en   ,2,1);
        e_rc |= data.insertFromRight(  o2s_max_retries        ,3,5);
        e_rc |= data.insertFromRight(  o2s_crc_polynomial_enables,8,8);
        if (e_rc)
        {
            FAPI_ERR("ecmdDataBufferBase error setting up PMC_O2S_CTRL_REG on Master init");
            rc.setEcmdError(e_rc);
            break;
        }

        FAPI_INF("  PMC_O2S_CTRL_REG4 Configuration");
        FAPI_INF("    o2s_crc_gen_en           => %d ",  o2s_crc_gen_en          );
        FAPI_INF("    o2s_crc_check_en         => %d ",  o2s_crc_check_en        );
        FAPI_INF("    o2s_majority_vote_en     => %d ",  o2s_majority_vote_en    );
        FAPI_INF("    o2s_max_retries          => %d ",  o2s_max_retries         );
        FAPI_INF("    o2s_crc_polynomial_enab  => 0x%x ",  o2s_crc_polynomial_enables );


        rc = fapiPutScom(i_target, PMC_O2S_CTRL_REG4_0x00062055, data );
        if (rc)
        {
            FAPI_ERR("fapiPutScom(PMC_O2S_CTRL_REG4_0x00062055) failed.");
            break;
        }

        //  ******************************************************************
        //   Program crc polynomials
        //  ******************************************************************

        rc = fapiGetScom(i_target, PMC_SPIV_CTRL_REG4_0x00062045, data );
        if (rc)
        {
            FAPI_ERR("fapiGetScom(PMC_SPIV_CTRL_REG4) failed.");
            break;
        }

        e_rc  = data.insertFromRight(  o2s_crc_gen_en         ,0,1);
        e_rc |= data.insertFromRight(  o2s_crc_check_en       ,1,1);
        e_rc |= data.insertFromRight(  o2s_majority_vote_en   ,2,1);
        e_rc |= data.insertFromRight(  o2s_max_retries        ,3,5);
        e_rc |= data.insertFromRight(  o2s_crc_polynomial_enables,8,8);
        if (e_rc)
        {
            FAPI_ERR("ecmdDataBufferBase error setting up PMC_SPIV_CTRL_REG4 on Master init");
            rc.setEcmdError(e_rc);
            break;
        }

        FAPI_INF("  PMC_SPIV_CTRL_REG4 Configuration");
        FAPI_INF("    spiv_crc_gen_en           => %d ",  o2s_crc_gen_en          );
        FAPI_INF("    spiv_crc_check_en         => %d ",  o2s_crc_check_en        );
        FAPI_INF("    spiv_majority_vote_en     => %d ",  o2s_majority_vote_en    );
        FAPI_INF("    spiv_max_retries          => %d ",  o2s_max_retries         );
        FAPI_INF("    spiv_crc_polynomial_enab  => 0x%x ",  o2s_crc_polynomial_enables );

        rc = fapiPutScom(i_target, PMC_SPIV_CTRL_REG4_0x00062045, data );
        if (rc)
        {
            FAPI_ERR("fapiPutScom(PMC_SPIV_CTRL_REG4_0x00062045) failed.");
            break;
        }

        //  ******************************************************************
        //     - write PMC_PARAMETER_REG0
        //  ******************************************************************
        rc = fapiGetScom(i_target, PMC_PARAMETER_REG0_0x00062005, data );
        if (rc)
        {
            FAPI_ERR("fapiGetScom(PMC_PARAMETER_REG0_0x00062005) failed.");
            break;
        }

        e_rc = data.insertFromRight(hangpulse_predivider ,15,6);
        e_rc |= data.insertFromRight(gpsa_timeout_value   ,21,8);
        if (e_rc)
        {
            FAPI_ERR("ecmdDataBufferBase error setting up PMC_PARAMETER_REG0_0x00062005 on Master init");
            rc.setEcmdError(e_rc);
            break;
        }

        FAPI_INF("  PMC_PARAMETER_REG0 Configuration");
        FAPI_INF("    hangpulse_predivider       => 0x%x ",  hangpulse_predivider);
        FAPI_INF("    gpsa_timeout_value         => 0x%x ",  gpsa_timeout_value  );

        rc = fapiPutScom(i_target, PMC_PARAMETER_REG0_0x00062005, data );
        if (rc)
        {
            FAPI_ERR("fapiPutScom(PMC_PARAMETER_REG0_0x00062005) failed.");
            break;
        }

        //  ******************************************************************
        //     - write PMC_RAIL_BOUNDS_0x00062003 to place open defaults into
        //          the rail bounds as the hardware defaults to both being
        //          00 --- which may be a turbo frequency.
        //  ******************************************************************
        //  Added for SW207759
        rc = fapiGetScom(i_target, PMC_RAIL_BOUNDS_0x00062003, data );
        if (rc)
        {
            FAPI_ERR("fapiGetScom(PMC_RAIL_BOUNDS_0x00062003) failed.");
            break;
        }

        e_rc |= data.setByte(0, -128);  // Pmin
        e_rc |= data.setByte(1,  127);  // Pmax
        if (e_rc)
        {
            FAPI_ERR("ecmdDataBufferBase error setting up PMC_RAIL_BOUNDS_0x00062003 on Master init");
            rc.setEcmdError(e_rc);
            break;
        }

        FAPI_INF("  PMC_RAIL_BOUNDS_0x00062003 Configuration");
        FAPI_INF("    pmin_rail       => 0x%x ",  data.getByte(0));
        FAPI_INF("    pmax_rail       => 0x%x ",  data.getByte(1));

        rc = fapiPutScom(i_target, PMC_RAIL_BOUNDS_0x00062003, data );
        if (rc)
        {
            FAPI_ERR("fapiPutScom(PMC_RAIL_BOUNDS_0x00062003) failed.");
            break;
        }

        //  ******************************************************************
        //     - write PMC_MODE_REG
        //  ******************************************************************
        rc = fapiGetScom(i_target, PMC_MODE_REG_0x00062000, data );
        if (rc)
        {
            FAPI_ERR("fapiGetScom(PMC_MODE_REG_0x00062000) failed.");
            break;
        }

        e_rc  = data.insertFromRight(zero , 0  ,1); //HW_PSTATE_MODE
        e_rc |= data.insertFromRight(zero , 1  ,1); //FW_PSTATE_AUCTI
        e_rc |= data.insertFromRight(one  , 2  ,1); //FW_PSTATE_MODEON_MODE
        e_rc |= data.insertFromRight(one  , 9  ,1); //ENABLE_PSTATE_STEPPING (hack for PSS miss)
        e_rc |= data.insertFromRight(zero , 13 ,1); //SAFE_MODE_WITHOUT_SPIVID
        if (e_rc)
        {
            FAPI_ERR("ecmdDataBufferBase error setting up PMC_SPIV_CTRL_REG4 on Master init");
            rc.setEcmdError(e_rc);
            break;
        }

        FAPI_INF("  PMC_MODE_REG Configuration");
        FAPI_INF("    SAFE_MODE_WITHOUT_SPIVID       => %d ",  zero);

        rc = fapiPutScom(i_target, PMC_MODE_REG_0x00062000, data );
        if (rc)
        {
            FAPI_ERR("fapiPutScom(PMC_MODE_REG_0x00062000) failed.");
            break;
        }

        // *************************************************************
        // REGISTER WRITES FOR DCMS
        // *************************************************************

        if (i_dcm)
        {
            rc = fapiGetScom(i_target, DEVICE_ID_REG_0x000F000F, data );
            if (rc)
            {
                FAPI_ERR("fapiGetScom(DEVICE_ID_REG_0x000F000F) failed.");
                break;
            }

            is_master = data.isBitClear(39) ;
            is_slave = not is_master ;

            if (is_master)
            {
                FAPI_INF ("**** Setting up DCM Master ****");
            }
            else
            {
                FAPI_INF ("**** Setting up DCM Slave ****");
            }
            //  ****************************************************************
            //     - write PMC_MODE_REG
            //  ****************************************************************
            rc = fapiGetScom(i_target, PMC_MODE_REG_0x00062000, data );
            if (rc)
            {
                FAPI_ERR("fapiGetScom(PMC_MODE_REG_0x00062000) failed.");
                break;
            }

            e_rc  = data.insertFromRight( one      , 6 ,1); //ENABLE_INTERCHIP_INTERFACE
            e_rc |= data.insertFromRight( is_master, 7 ,1); //INTERCHIP_MODE
            e_rc |= data.insertFromRight( is_master, 8 ,1); //ENABLE_INTERCHIP_PSTATE_IN_HAPS
            e_rc |= data.insertFromRight( is_slave ,13 ,1); //SAFEMODE_WITHOUT_SPIVID
            if (e_rc)
            {
                FAPI_ERR("ecmdDataBufferBase error setting up PMC_MODE_REG_0x00062000 on Master DCM init");
                rc.setEcmdError(e_rc);
                break;
            }

            FAPI_INF("  PMC_MODE_REG Configuration");
            FAPI_DBG("    ENABLE_INTERCHIP_INTERFACE             => %d ", one       );
            FAPI_DBG("    INTERCHIP_MODE                         => %d ", is_master );
            FAPI_DBG("    ENABLE_INTERCHIP_PSTATE_IN_HAPS        => %d ", is_master );
            FAPI_DBG("    SAFE_MODE_WITHOUT_SPIVID               => %d ", is_slave  );

            rc = fapiPutScom(i_target, PMC_MODE_REG_0x00062000, data );
            if (rc)
            {
                FAPI_ERR("fapiPutScom(PMC_MODE_REG_0x00062000) failed.");
                break;
            }
            FAPI_DBG(" before exiting pmc_init PMC_MODE_REG_0x00062000  =>0x%16llx", data.getDoubleWord(0));

            //  ******************************************************************
            //     - set PMC_O2S_CTRL_REG1
            //  ******************************************************************

            rc = fapiGetScom(i_target, PMC_O2S_CTRL_REG1_0x00062052, data );
            if (rc)
            {
                FAPI_ERR("fapiGetScom(PMC_O2S_CTRL_REG1) failed.");
                break;
            }

            // Force the port enables on the slave or else the SPIVID on the slave
            // chip will hang
            if (is_slave)
            {
                 o2s_port_enable = 4 ;
                 e_rc = data.insertFromRight(o2s_port_enable     ,18,3);
                 if (e_rc)
                 {
                     FAPI_ERR("ecmdDataBufferBase error setting up forced slave port enable on Slave DCM init");
                     rc.setEcmdError(e_rc);
                     break;
                 }
                 FAPI_INF("Forcing port enable on slave to avoid SPIVID controller hang");
                 FAPI_INF("  PMC O2S CTRL_REG_1 / PMC_SPIV_CTRL_REG1 Configuration");
                 FAPI_INF("    spiv/o2s_port_enable       => %d ",  o2s_port_enable  );
            }

            // \todo this should be looked at for removal to avoid future problems
            rc = fapiPutScom(i_target, PMC_O2S_CTRL_REG1_0x00062052, data );
            if (rc)
            {
                FAPI_ERR("fapiPutScom(PMC_O2S_CTRL_REG1_0x00062052) failed.");
                break;
            }

            rc = fapiPutScom(i_target, PMC_SPIV_CTRL_REG1_0x00062042, data );
            if (rc)
            {
                FAPI_ERR("fapiPutScom(PMC_SPIV_CTRL_REG1_0x00062042) failed.");
                break;
            }

            //  ******************************************************************
            //     - write PMC_INTCHP_CTRL_REG1
            //  ******************************************************************
            rc = fapiGetScom(i_target, PMC_INTCHP_CTRL_REG1_0x00062010, data );
            if (rc)
            {
                FAPI_ERR("fapiGetScom(PMC_INTCHP_CTRL_REG1_0x00062010) failed.");
                break;
            }

            e_rc  = data.insertFromRight(one , 0 ,1);                      //INTERCHIP_GA_FSM_ENABLE
            e_rc |= data.insertFromRight(zero, 7 ,1);                      //INTERCHIP_CPHA
            e_rc |= data.insertFromRight( interchip_clock_divider, 4 ,10); //INTERCHIP_CLOCK_DIVIDER
            if (e_rc)
            {
                FAPI_ERR("ecmdDataBufferBase error setting up PMC_INTCHP_CTRL_REG1_0x00062010 on Master DCM init");
                rc.setEcmdError(e_rc);
                break;
            }

            FAPI_INF("  PMC_INTCHP_CTRL_REG1 Configuration                  ");
            FAPI_DBG("    INTERCHIP_GA_FSM_ENABLE        =>   %d ",  one          );
            FAPI_DBG("    INTERCHIP_CPHA                 =>   %d ", zero     );
            FAPI_DBG("    INTERCHIP_CLOCK_DIVIDER        => 0x%x ", interchip_clock_divider     );

            rc = fapiPutScom(i_target, PMC_INTCHP_CTRL_REG1_0x00062010, data );
            if (rc)
            {
                FAPI_ERR("fapiPutScom(PMC_INTCHP_CTRL_REG1_0x00062010) failed.");
                break;
            }
            FAPI_DBG(" before exiting pmc_init PMC_INTCHP_CTRL_REG1_0x00062010  =>0x%16llx", data.getDoubleWord(0));

            //  ******************************************************************
            //     - write PMC_INTCHP_CTRL_REG4
            //  ******************************************************************
            rc = fapiGetScom(i_target, PMC_INTCHP_CTRL_REG4_0x00062012, data );
            if (rc)
            {
                FAPI_ERR("fapiGetScom(PMC_INTCHP_CTRL_REG4_0x00062012) failed.");
                break;
            }
            e_rc  = data.insertFromRight(one , 0 ,1); //INTERCHIP_ECC_GEN_EN
            e_rc |= data.insertFromRight(one , 1 ,1); //INTERCHIP_ECC_CHECK_EN
            e_rc |= data.insertFromRight(one , 2 ,1); //INTERCHIP_MSG_RCV_OVERFLOW_CHECK_EN
            e_rc |= data.insertFromRight(one , 3 ,1); //INTERCHIP_ECC_UE_BLOCK_EN
            if (e_rc)
            {
                FAPI_ERR("ecmdDataBufferBase error setting up PMC_INTCHP_CTRL_REG1_0x00062010 on Master DCM init");
                rc.setEcmdError(e_rc);
                break;
            }

            FAPI_INF("  PMC_INTCHP_CTRL_REG4 Configuration                  ");
            FAPI_DBG("    INTERCHIP_ECC_GEN_EN                       =>   %d ",  one          );
            FAPI_DBG("    INTERCHIP_ECC_CHECK_EN                     =>   %d ",  one          );
            FAPI_DBG("    INTERCHIP_MSG_RCV_OVERFLOW_CHECK_EN        =>   %d ",  one          );
            FAPI_DBG("    INTERCHIP_ECC_UE_BLOCK_EN                  =>   %d ",  one          );

            rc = fapiPutScom(i_target, PMC_INTCHP_CTRL_REG4_0x00062012, data );
            if (rc)
            {
                FAPI_ERR("fapiPutScom(PMC_INTCHP_CTRL_REG4_0x00062012) failed.");
                break;
            }
            FAPI_DBG(" before exiting pmc_init PMC_INTCHP_CTRL_REG4_0x00062012  =>0x%16llx", data.getDoubleWord(0));
        } // dcm

    } while(0);


    FAPI_INF ("Done with the init");
    return rc;

}


// ----------------------------------------------------------------------
/**
 * p8_pmc_init
 *
 * @param[in] i_target1 Primary Chip target:   Murano - chip0; Venice - chip
 * @param[in] i_target2 Secondary Chip target: Murano - chip1; Venice - NULL
 * @param[in] mode (PM_INIT , PM_CONFIG, PM_RESET, PM_RESET_SOFT)
 *
 * @retval ECMD_SUCCESS
 * @retval ERROR defined in xml
 */
fapi::ReturnCode
p8_pmc_init(const fapi::Target& i_target1, const fapi::Target& i_target2, uint32_t mode)
{
    fapi::ReturnCode    rc;

    uint8_t         attr_dcm_installed_1 = 0;
    uint8_t         attr_dcm_installed_2 = 0;
    bool            dcm = false;

    do
    {

        // ------------------------------------------------
        // CONFIG mode
        // ------------------------------------------------
        if (mode == PM_CONFIG)
        {
            rc = pmc_config_spivid_settings(i_target1);
            if (rc)
            {
                FAPI_ERR("Error from pmc_config_spivid_settings for target1");
                break;
            }

            if ( i_target2.getType() != TARGET_TYPE_NONE )
            {
                rc = pmc_config_spivid_settings(i_target2);
                if (rc)
                {
                    FAPI_ERR("Error from pmc_config_spivid_settings for target2");
                    break;
                }
            }
        }

        // ------------------------------------------------
        // INIT mode
        // ------------------------------------------------
        else if (mode == PM_INIT)
        {

            // Per SW250226, determine if initialization should be as a real DCM
            // or as a garded SCM
            rc = FAPI_ATTR_GET(ATTR_PROC_DCM_INSTALLED, &i_target1, attr_dcm_installed_1);
            if (rc)
            {
                FAPI_ERR("fapiGetAttribute of ATTR_DCM_INSTALLED with rc = 0x%x", (uint32_t)rc);
                break;
            }

            FAPI_INF (" ATTR_DCM_INSTALLED value in init function = 0x%x", attr_dcm_installed_1 );

            // Default is dcm = false
            if (attr_dcm_installed_1 == 0)
            {

                // target2 should be NULL
                // if not NULL, exit with config error
                if (i_target2.getType() != TARGET_TYPE_NONE  )
                {
                    FAPI_ERR ("Config error : target2 is not null for target1 SCM case");
                    const fapi::Target& MASTER_TARGET = i_target1;
                    const fapi::Target& SLAVE_TARGET = i_target2;
                    const uint8_t & DCM_INSTALLED_1 =  attr_dcm_installed_1;
                    const uint8_t & DCM_INSTALLED_2 =  attr_dcm_installed_2;
                    FAPI_SET_HWP_ERROR(rc, RC_PROCPM_PMCINIT_SCM_INSTALL_ERROR);
                    break;
                }
            }
            // Target 1 indicates a physical DCM
            else
            {
                // Check if Target 2 indicates a real DCM.  If not, gard defaults to SCM
                if (i_target2.getType() != TARGET_TYPE_NONE  )
                {
                    rc = FAPI_ATTR_GET(ATTR_PROC_DCM_INSTALLED, &i_target2, attr_dcm_installed_2);
                    if (rc)
                    {
                        FAPI_ERR("fapiGetAttribute of ATTR_DCM_INSTALLED with rc = 0x%x", (uint32_t)rc);
                        break;
                    }
                    FAPI_INF (" ATTR_DCM_INSTALLED value in INIT function = 0x%x", attr_dcm_installed_2 );

                    if (attr_dcm_installed_2 != 1)
                    {
                        FAPI_ERR ("Config error:  DCM_INSTALLED target2 does not match target1\n" \
                                  "   target1: %08x attr:%02x, target2:%08x attr:%02x",
                                  i_target1.getType(), attr_dcm_installed_1,
                                  i_target2.getType(), attr_dcm_installed_2);
                        const fapi::Target& MASTER_TARGET = i_target1;
                        const fapi::Target& SLAVE_TARGET = i_target2;
                        const uint8_t & DCM_INSTALLED_1 =  attr_dcm_installed_1;
                        const uint8_t & DCM_INSTALLED_2 =  attr_dcm_installed_2;
                        FAPI_SET_HWP_ERROR(rc, RC_PROCPM_PMCINIT_DCM_INSTALL_ERROR);
                        break;
                    }
                    dcm = true;
                }
            }


            FAPI_INF("Executing p8_pmc_init for as %s for Target %s ...",
                            dcm ? "DCM" : "SCM",
                            i_target1.toEcmdString());
            rc = pmc_init_function(i_target1, dcm);
            if (rc)
            {
                FAPI_ERR("Error from pmc_init_function for target1");
                break;
            }

            if ( i_target2.getType() != TARGET_TYPE_NONE )
            {
                FAPI_INF("Executing p8_pmc_init for Target %s ...", i_target2.toEcmdString());
                rc = pmc_init_function(i_target2, dcm);
                if (rc)
                {
                  FAPI_ERR("Error from pmc_init_function for target2");
                  break;
                }
            }
        }

        /// -------------------------------
        /// Reset:  perform hard reset of PMC
        /// -------------------------------
        else if (mode == PM_RESET)
        {
            FAPI_INF("Hard reset detected.  Calling pmc_reset_function");
            rc = pmc_reset_function(i_target1 , i_target2, mode);
            if (rc)
            {
                FAPI_ERR("Error from pmc_reset_function");
                break;
            }
        }

        // -------------------------------
        /// Reset:  perform soft reset of PMC
        /// -------------------------------
        else if (mode == PM_RESET_SOFT)
        {
            FAPI_INF("Soft reset detected.  Calling pmc_reset_function");
            rc = pmc_reset_function(i_target1 , i_target2, mode);
            if (rc)
            {
                FAPI_ERR("Error from pmc_reset_function");
                break;
            }
        }


        /// -------------------------------
        /// Unsupported Mode
        /// -------------------------------
        else
        {
            FAPI_ERR("Unknown mode passed to p8_pmc_init. Mode %x ", mode);
            const uint64_t & MODE = (uint64_t)mode;
            FAPI_SET_HWP_ERROR(rc, RC_PROCPM_PMC_CODE_BAD_MODE);
        }

    } while(0);
    //    FAPI_INF("im here ");
    return rc;

} // end p8_pmc_init


// ----------------------------------------------------------------------
/**
 * p8_pmc_poll_pstate_halt
 *
 * @param[in] i_target  Chip target
 * @param[in] i_side    Master - 0; Slave - 1
 *
 * @retval ECMD_SUCCESS
 * @retval ERROR defined in xml
 */
fapi::ReturnCode
p8_pmc_poll_pstate_halt(const fapi::Target& i_target, uint8_t const i_side)
{
    fapi::ReturnCode    rc;
    ecmdDataBufferBase  pmcstatus(64);
    ecmdDataBufferBase  porr(64);

    bool is_pstate_error_stopped = false ;
    bool is_error_stopped = false;

    uint32_t count = 0 ;
    bool is_stopped = false ;

    do
    {

        // Confirm that Pstate hardware is quiesced before changing modes
        rc = fapiGetScom(i_target, PMC_STATUS_REG_0x00062009 , pmcstatus );
        if (rc)
        {
             FAPI_ERR("fapiGetScom(PMC_STATUS_REG_0x00062009) failed.");
             break;
        }

        //  Poll for local Pstates being stopped
        for (count = 0 , is_stopped = 0 ; count <= PSTATE_HALT_POLL_COUNT && is_stopped == 0;  count++)
        {

            //  is_stopped = (GPSA_CHG_ONGOING == 0 ||
            //                VOLT_CHG_ONGOING == 0 ||
            //                BRD_CST_ONGOING  == 0) ;
            is_stopped = pmcstatus.isBitClear(7)  || pmcstatus.isBitClear(8) || pmcstatus.isBitClear(9);

            // Leave if stopped
            if (is_stopped)
                continue;

            // wait for 1 millisecond/loop in hardware
            rc = fapiDelay(1000*1000, 20000000);
            if (rc)
            {
                FAPI_ERR("FAPI delay ends up with error");
                break;
            }

            // Re-read
            rc = fapiGetScom(i_target, PMC_STATUS_REG_0x00062009 , pmcstatus );
            if (rc)
            {
                 FAPI_ERR("fapiGetScom(PMC_STATUS_REG_0x00062009) failed.");
                 break;
            }

        } // end_for
        // Error check
        if (!rc.ok())
        {
            break;
        }

        // check for Pstate errors
        is_pstate_error_stopped =   pmcstatus.isBitSet(0) ||
                                    pmcstatus.isBitSet(1) ||
                                    pmcstatus.isBitSet(5) ||
                                    pmcstatus.isBitSet(6) ||
                                    pmcstatus.isBitSet(11);

        if (is_pstate_error_stopped)
        {
            FAPI_ERR("Pstate errors exist. Reset may be suspicious but NOT failing as it could be cleared ... ");
        }

        if (count > PSTATE_HALT_POLL_COUNT)
        {
            FAPI_ERR("Timed out in polling for Local Pstates to quiesce. Reset may be suspicious but NOT failing as it could be cleared ... ");
        }


        rc = fapiGetScom(i_target, PMC_PORRR0_REG_0x0006208E , porr );
        if (rc)
        {
             FAPI_ERR("fapiGetScom(PMC_PORRR0_REG_0x0006208E) failed.");
             break;
        }

        // Poll for local Idle being stopped.  As specical wake-up was to have
        // occured prior to this, execution should be quick.  If this times out,
        // there is a significant problem.
        for (count = 0 , is_stopped = 0 ; count <= PORE_REQ_POLL_COUNT && is_stopped == 0;  count++)
        {
            //  is_stopped = (PORRR_PORE_BUSY == 0) ;
            is_stopped = porr.isBitClear(20);

            // Leave if stopped
            if (is_stopped)
                continue;

            // wait for 1 millisecond/loop in hardware
            rc = fapiDelay(1000*1000, 20000000);
            if (rc)
            {
                FAPI_ERR("FAPI delay ends up with error");
                break;
            }

            // Re-read
            rc = fapiGetScom(i_target, PMC_PORRR0_REG_0x0006208E , porr );
            if (rc)
            {
                 FAPI_ERR("fapiGetScom(PMC_PORRR0_REG_0x0006208E) failed.");
                 break;
            }

        } // end_for
        // Error check
        if (!rc.ok())
        {
            break;
        }

        // check for Idle errors
        is_error_stopped =   porr.isBitSet(21) || pmcstatus.isBitSet(12);

        if (is_error_stopped)
        {
            FAPI_ERR("PMC Idle halt errors exist.  OCC recovery cannot proceed ... ");
            const fapi::Target& TARGET = i_target;
            const uint64_t & PORR = porr.getDoubleWord(0);
            const uint64_t & PMCSTATUS = pmcstatus.getDoubleWord(0);
            FAPI_SET_HWP_ERROR(rc, RC_PROCPM_PMCRESET_IDLE_ERROR);
            break;
        }

        if (count > PORE_REQ_POLL_COUNT)
        {
            FAPI_ERR("PMC Timed out in polling for Idle to Halt. OCC recovery cannot proceed ... ");
            const fapi::Target& TARGET = i_target;
            const uint64_t & PORR = porr.getDoubleWord(0);
            const uint64_t & PMCSTATUS = pmcstatus.getDoubleWord(0);
            FAPI_SET_HWP_ERROR(rc, RC_PROCPM_PMCRESET_IDLE_TIMEOUT_ERROR);
            break;
        }

    }
    while (0);
    return rc;
}

// ----------------------------------------------------------------------
/**
 * p8_pmc_poll_idle_halt
 *
 * @param[in] i_target  Chip target
 * @param[in] i_side    Master - 0; Slave - 1
 *
 * @retval ECMD_SUCCESS
 * @retval ERROR defined in xml
 */
fapi::ReturnCode
p8_pmc_poll_idle_halt(const fapi::Target& i_target, const uint8_t i_side)
{
    fapi::ReturnCode    rc;
    ecmdDataBufferBase  pmcstatus(64);
    ecmdDataBufferBase  porr(64);

    bool is_error_stopped = false;

    uint32_t count = 0 ;
    bool is_stopped = false ;

    do
    {

        // Poll for local Idle being stopped.  As special wake-up was to have
        // occured prior to this, execution should be quick.  If this times out,
        // there is a significant problem.
        for (count = 0 , is_stopped = 0 ; count <= PORE_REQ_POLL_COUNT && is_stopped == 0;  count++)
        {
            //  is_stopped = (PORRR_PORE_BUSY == 0) ;
            is_stopped = porr.isBitClear(20);

            // Leave if stopped
            if (is_stopped)
                continue;

            // wait for 1 millisecond/loop in hardware
            rc = fapiDelay(1000*1000, 20000000);
            if (rc)
            {
                FAPI_ERR("FAPI delay ends up with error");
                break;
            }

            // Re-read
            rc = fapiGetScom(i_target, PMC_PORRR0_REG_0x0006208E , porr );
            if (rc)
            {
                 FAPI_ERR("fapiGetScom(PMC_PORRR0_REG_0x0006208E) failed.");
                 break;
            }

        } // end_for
        // Error check
        if (!rc.ok())
        {
            break;
        }

        // check for Idle errors
        is_error_stopped =   porr.isBitSet(21) || pmcstatus.isBitSet(12);

        if (is_error_stopped)
        {
            FAPI_ERR("PMC Idle halt errors exist.  OCC recovery cannot proceed ... ");
            const fapi::Target& TARGET = i_target;
            const uint64_t & PORR = porr.getDoubleWord(0);
            const uint64_t & PMCSTATUS = pmcstatus.getDoubleWord(0);
            FAPI_SET_HWP_ERROR(rc, RC_PROCPM_PMCRESET_IDLE_ERROR);
            break;
        }

        if (count > PORE_REQ_POLL_COUNT)
        {
            FAPI_ERR("PMC Timed out in polling for Idle to Halt. OCC recovery cannot proceed ... ");
            const fapi::Target& TARGET = i_target;
            const uint64_t & PORR = porr.getDoubleWord(0);
            const uint64_t & PMCSTATUS = pmcstatus.getDoubleWord(0);
            FAPI_SET_HWP_ERROR(rc, RC_PROCPM_PMCRESET_IDLE_TIMEOUT_ERROR);
            break;
        }

    }
    while (0);
    return rc;
}

// ----------------------------------------------------------------------
/**
 * p8_pmc_poll_interchip_halt
 *
 * @param[in] i_target  Chip target
 * @param[in] i_side    Master - 0; Slave - 1
 *
 * @retval ECMD_SUCCESS
 * @retval ERROR defined in xml
 */
fapi::ReturnCode
p8_pmc_poll_interchip_halt( const fapi::Target& i_target,
                            const uint8_t       i_side,
                            bool                i_MasterPMC,
                            const fapi::Target& i_dcm_target)
{
    fapi::ReturnCode    rc;
    uint32_t            e_rc;
    ecmdDataBufferBase  data(64);

    bool is_stopped = false ;
    bool is_pstate_error_stopped = false;
    bool is_intchp_error_stopped = false;

    uint32_t count = 0 ;


    do
    {
        rc = fapiGetScom(i_target, PMC_INTCHP_COMMAND_REG_0x00062014 , data );
        if (rc)
        {
            FAPI_ERR("fapiGetScom(PMC_INTCHP_COMMAND_REG_0x00062014) failed.");
            break;
        }

        e_rc = data.setBit(01);
        if (e_rc)
        {
            FAPI_ERR("ecmdDataBufferBase error setting up PMC_INTCHP_COMMAND_REG_0x00062014 on Master during reset");
            rc.setEcmdError(e_rc);
            break;
        }

        rc = fapiPutScom(i_target, PMC_INTCHP_COMMAND_REG_0x00062014 , data );
        if (rc)
        {
            FAPI_ERR("fapiPutScom(PMC_INTCHP_COMMAND_REG_0x00062014) failed.");
            break;
        }

        //  Poll for interchip interface to stop
        for (count = 0 , is_stopped = 0 ; count <= INTERCHIP_HALT_POLL_COUNT && is_stopped == 0;  count++)
        {

            rc = fapiGetScom(i_target, PMC_STATUS_REG_0x00062009 , data );
            if (rc)
            {
                FAPI_ERR("fapiGetScom(PMC_STATUS_REG_0x00062009) failed.");
                break;
            }

            //    Interchip_Wait1: Read PMC_STATUS_REG
            //       is_pstate_error_stopped =  pstate_processing_is_suspended ||
            //                                  gpsa_bdcst_error ||
            //                                  gpsa_vchg_error ||
            //                                  gpsa_timeout_error ||
            //                                  pstate_interchip_error;
            is_pstate_error_stopped =   data.isBitSet(0) ||
                                        data.isBitSet(1) ||
                                        data.isBitSet(5) ||
                                        data.isBitSet(6) ||
                                        data.isBitSet(11);

            //    Interchip_Wait2: Read PMC_INTCHP_STATUS_REG
            //       is_intchp_error_stopped =  interchip_ecc_ue_err ||
            //                                  interchip_fsm_err ||
            //                                  (is_MasterPMC && interchip_slave_error_code != 0) is_MasterPMC
            rc = fapiGetScom(i_target, PMC_INTCHP_STATUS_REG_0x00062013 , data );
            if (rc)
            {
                FAPI_ERR("fapiGetScom(PMC_INTCHP_STATUS_REG_0x00062013) failed.");
                break;
            }
            is_intchp_error_stopped =   data.isBitSet(1) ||
                                        data.isBitSet(7) ||
                                        (~( data.isBitClear(16,4) &&  i_MasterPMC)) ;

            //    is_stopped = (interchip_ga_ongoing == 0) ||
            //                  is_pstate_error_stopped ||
            //                  is_intchp_error_stopped ;
            is_stopped = data.isBitClear(0)  || is_pstate_error_stopped || is_intchp_error_stopped;

            if (is_stopped)
                continue;

            FAPI_DBG("polling interchip ongoing :  ... ");

            //       If !is_stopped Then -->Interchip_Wait1  (Wait limit is parm TD_Interchip_HaltWait_max=260)

            // wait for 1 millisecond/loop in hardware
            rc = fapiDelay(1000*1000, 20000000);
            if (rc)
            {
                FAPI_ERR("fapi delay ends up with error");
                break;
            }

        } // end_for
        // Error check
        if (!rc.ok())
        {
            break;
        }

        if (count > INTERCHIP_HALT_POLL_COUNT)
        {
            FAPI_INF("Timed out in polling interchip ongoing : Reset may be suspicious but NOT failing as it could be cleared ... ");
            const fapi::Target& THISTARGET = i_target;
            const fapi::Target& DCMTARGET = i_dcm_target;
            FAPI_SET_HWP_ERROR(rc, RC_PROCPM_PMCRESET_INTCHP_TIMEOUT_ERROR);
            fapiLogError(rc, fapi::FAPI_ERRL_SEV_RECOVERED);
        }

        // InterchipIf: PMC_MODE_REG.interchip_halt_if<-1 interchip_halt_if

        rc = fapiGetScom(i_target, PMC_MODE_REG_0x00062000 , data );
        if (rc)
        {
            FAPI_ERR("fapiGetScom(PMC_MODE_REG_0x00062000) failed.");
            break;
        }

        e_rc = data.setBit(15);
        if (e_rc)
        {
            FAPI_ERR("ecmdDataBufferBase error setting up PMC_MODE_REG_0x00062000 on Master during reset");
            rc.setEcmdError(e_rc);
            break;
        }

        rc = fapiPutScom(i_target, PMC_MODE_REG_0x00062000 , data );
        if (rc)
        {
            FAPI_ERR("fapiPutScom(PMC_MODE_REG_0x00062000) failed.");
            break;
        }

    }
    while (0);
    return rc;
}

// ----------------------------------------------------------------------
/**
 * p8_pmc_poll_spivid_halt
 *
 * @param[in] i_target  Chip target
 * @param[in] i_side    Master - 0; Slave - 1
 *
 * @retval ECMD_SUCCESS
 * @retval ERROR defined in xml
 */
fapi::ReturnCode
p8_pmc_poll_spivid_halt(const fapi::Target& i_target,
                        const uint8_t       i_side)
{
    fapi::ReturnCode    rc;
    uint32_t            e_rc;
    ecmdDataBufferBase  data(64);

    bool is_spivid_stopped = false ;

    uint32_t count = 0 ;


    do
    {
        //  HaltSpivid: PMC_SPIV_COMMAND_REG.spivid_halt_fsm<-1
        rc = fapiGetScom(i_target, PMC_SPIV_COMMAND_REG_0x00062047 , data );
        if (rc)
        {
            FAPI_ERR("fapiGetScom(PMC_SPIV_COMMAND_REG_0x00062047) failed.");
            break;
        }

        e_rc = data.setBit(0);
        if (e_rc)
        {
            FAPI_ERR("ecmdDataBufferBase error setting up PMC_SPIV_COMMAND_REG_0x00062047 on Side %d during reset",
                                    i_side);
            rc.setEcmdError(e_rc);
            break;
        }

        rc = fapiPutScom(i_target, PMC_SPIV_COMMAND_REG_0x00062047 , data );
        if (rc)
        {
            FAPI_ERR("fapiPutScom(PMC_SPIV_COMMAND_REG_0x00062047) failed.");
            break;
        }

        //    Spivid_HaltWait: Read PMC_SPIV_STATUS_REG
        for (count = 0 , is_spivid_stopped=0; count <= VOLTAGE_CHANGE_POLL_COUNT  && is_spivid_stopped==0  ; count++)
        {

            rc = fapiGetScom(i_target, PMC_SPIV_STATUS_REG_0x00062046 , data );
            if (rc)
            {
              FAPI_ERR("fapiGetScom(PMC_SPIV_STATUS_REG_0x00062046) failed.");
              break;
            }
            is_spivid_stopped =   data.isBitClear(0) ||
                                  data.isBitSet(1)   ||
                                  data.isBitSet(2)   ||
                                  data.isBitSet(3)   ||
                                  data.isBitSet(4) ;

            if (is_spivid_stopped)
                continue;

            FAPI_DBG("Polling spivid ongoing on Side %d", i_side);

            // wait for 1 millisecond/loop in hardware
            rc = fapiDelay(1000*1000, 20000000);
            if (rc)
            {
                FAPI_ERR("fapi delay ends up with error");
                break;
            }

        } // end for

        // Error check
        if (!rc.ok())
        {
            break;
        }

        // Timeout check
        if (count > VOLTAGE_CHANGE_POLL_COUNT)
        {
            FAPI_ERR("Timed out in polling SPIVID ongoing  : Reset_suspicious    ... ");
            const fapi::Target& TARGET = i_target;
            FAPI_SET_HWP_ERROR(rc, RC_PROCPM_PMCRESET_SPIVID_TIMEOUT_ERROR);
            fapiLogError(rc, fapi::FAPI_ERRL_SEV_RECOVERED);
        }

    }
    while (0);
    return rc;
}

// ----------------------------------------------------------------------
/**
 * p8_pmc_poll_o2p_halt
 *
 * @param[in] i_target  Chip target
 * @param[in] i_side    Master - 0; Slave - 1
 *
 * @retval ECMD_SUCCESS
 * @retval ERROR defined in xml
 */
fapi::ReturnCode
p8_pmc_poll_o2p_halt(const fapi::Target& i_target,
                     const uint8_t       i_side)
{
    fapi::ReturnCode    rc;
    uint32_t            e_rc;
    ecmdDataBufferBase  data(64);

    bool is_stopped = false ;

    uint32_t count = 0 ;


    do
    {
        rc = fapiGetScom(i_target, PMC_O2S_COMMAND_REG_0x00062057 , data );
        if (rc)
        {
            FAPI_ERR("fapiGetScom(PMC_O2S_COMMAND_REG__0x00062057) failed.");
            break;
        }

        e_rc = data.setBit(00);
        if(e_rc)
        {
            rc.setEcmdError(e_rc);
            break;
        }

        rc = fapiPutScom(i_target, PMC_O2S_COMMAND_REG_0x00062057 , data );
        if (rc)
        {
            FAPI_ERR("fapiPutScom(PMC_O2S_COMMAND_REG__0x00062057) failed.");
            break;
        }

        // Poll for O2S to be stopped
        for (count = 0 , is_stopped = 0 ; count <= O2S_POLL_COUNT && is_stopped == 0 ; count++)
        {
            // wait for 1 millisecond/loop in hardware
            rc = fapiDelay(1000*1000, 20000000);
            if (rc)
            {
                FAPI_ERR("fapi delay ends up with error");
                break;
            }
            rc = fapiGetScom(i_target, PMC_O2S_STATUS_REG_0x00062056 , data );
            if (rc)
            {
                FAPI_ERR("fapiGetScom(PMC_O2S_STATUS_REG__0x00062056) failed.");
                break;
            }

            is_stopped = (  data.isBitClear(0) ||
                            data.isBitSet(4)   ||
                            data.isBitSet(5)   ||
                            data.isBitSet(7));
            FAPI_DBG("Polling O2S ongoing . :   .. ");
        }

        // Error check
        if (!rc.ok())
        {
            break;
        }

        // Timeout check
        if (count > O2P_POLL_COUNT)
        {
            FAPI_ERR("Timed out in polling O2P ongoing . : Reset_suspicious .. ");
            const fapi::Target& TARGET = i_target;
            const uint64_t & O2PSTATUS = data.getDoubleWord(0);
            FAPI_SET_HWP_ERROR(rc, RC_PROCPM_PMCRESET_O2P_TIMEOUT_ERROR);
            fapiLogError(rc, fapi::FAPI_ERRL_SEV_RECOVERED);
        }

    }
    while (0);
    return rc;
}

} //end extern C

/*
*************** Do not edit this area ***************
This section is automatically updated by CVS when you check in this file.
Be sure to create CVS comments when you commit so that they can be included here.

$Log: p8_pmc_init.C,v $
Revision 1.42  2014/04/10 21:12:22  stillgs
Per SW256701, hardcode the enablement of Pstate Stepping in PMC Mode reg for GA1

Revision 1.41  2014/04/03 20:29:13  cmolsen
Removed three bool variables that were set only but not used.

Revision 1.40  2014/03/12 21:03:15  stillgs
Per SW251617, updates for HostCompiler tool flagged logical errors (bitwise operators were scalar was intended

Revision 1.39  2014/03/06 16:26:54  stillgs
SW250226 (deconfigured chip on DCM)

Revision 1.38  2014/03/05 22:13:13  stillgs

- Updates per RAS/callout reviews.  In dealing with these comments, did some
restructuring of common code into subroutines.  Runs through the Cronus
OCC reset shift cleanly.

Revision 1.37  2013/11/07 14:00:09  stillgs

Per SW232699, updated SPIVID parameters
/!/ Units: nanoseconds;  Value 15 microseconds
const uint32_t  default_spivid_interframe_delay_write_status = 15000;
/!/ Units: nanoseconds;  Value 40 microseconds
 const uint32_t  default_spivid_inter_retry_delay = 40000;

Revision 1.36  2013/08/02 19:09:07  stillgs

- Support for p8_pm.H.
- Temporarily changed the detection of set FIR bit from FAPI_ERR to FAPI_INF until fully complete with testing.
This keeps "FAPI ERR" from showing up in log for things that do not give non-zero RCs.
- Added plumbing support for "soft" rest.  FUNCTION IS NOT YET SUPPORTED

Revision 1.35  2013/06/07 19:17:24  stillgs

Fix swap of Pmin and PMax rail settings

Revision 1.34  2013/06/05 21:09:03  stillgs

Fix for SW207759:  Added setting of PMC Rail Bounds register to +127/-127
to deal with hardware reset values being 0s --- the turbo value for P8 machines

Revision 1.33  2013/05/24 10:53:38  pchatnah
Assigning boolean variables to false by default

Revision 1.32  2013/05/16 11:41:16  pchatnah
fixing gerrit comments

Revision 1.31  2013/05/09 10:26:33  pchatnah
fixing gerrot comments

Revision 1.30  2013/04/30 11:20:22  pchatnah
fixing memory fault issue for scm

Revision 1.29  2013/04/17 13:11:28  pchatnah
fixing some more SCM issues

Revision 1.28  2013/04/16 12:00:26  pchatnah
fixing Daniels failures on hardware

Revision 1.27  2013/04/12 01:25:02  stillgs

Update for DCM initialization and reset function per hardware testing

Revision 1.25  2013/04/06 02:14:03  pchatnah
 restructuring

Revision 1.24  2013/04/04 12:43:49  pchatnah
fixing sm_without_spivid

Revision 1.23  2013/04/02 14:17:55  pchatnah
fixing spivid_enable for slave

Revision 1.22  2013/04/01 04:11:54  stillgs

Output formating changes only to remove extraneous log content

Revision 1.21  2013/03/28 14:42:02  pchatnah
adding FIR check

Revision 1.20  2013/03/28 14:29:04  pchatnah
adding FIR check

Revision 1.19  2013/03/15 12:25:57  pchatnah
fixing no_of_ports

Revision 1.18  2013/03/04 16:15:35  pchatnah
fising more issues for prep_for_reset

Revision 1.17  2013/02/25 19:27:01  pchatnah
fising compilation issues

Revision 1.16  2013/02/21 08:58:37  pchatnah
fixing 100ns calculation

Revision 1.15  2013/02/11 15:44:16  pchatnah
fixing pstate

Revision 1.14  2013/02/07 18:44:49  pchatnah
adding PM_LFIR reset also into it

Revision 1.13  2013/01/24 11:58:12  pchatnah
adding log inside the file

*/
