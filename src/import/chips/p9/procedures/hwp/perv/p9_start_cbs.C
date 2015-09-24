/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/perv/p9_start_cbs.C $                 */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
//------------------------------------------------------------------------------
/// @file  p9_start_cbs.C
///
/// @brief Start CBS : Trigger CBS
//------------------------------------------------------------------------------
// *HWP HW Owner        : Abhishek Agarwal <abagarw8@in.ibm.com>
// *HWP HW Backup Owner : Srinivas V Naga <srinivan@in.ibm.com>
// *HWP FW Owner        : sunil kumar <skumar8j@in.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 2
// *HWP Consumed by     : SE
//------------------------------------------------------------------------------


//## auto_generated
#include "p9_start_cbs.H"

#include "p9_perv_scom_addresses.H"


enum P9_START_CBS_Private_Constants
{
    P9_CFAM_CBS_POLL_COUNT = 600, // Observed Number of times CBS read for CBS_INTERNAL_STATE_VECTOR
    CBS_IDLE_VALUE = 0x002, // Read the value of CBS_CS_INTERNAL_STATE_VECTOR
    P9_CBS_IDLE_HW_NS_DELAY = 100000, // unit is nano seconds
    P9_CBS_IDLE_SIM_CYCLE_DELAY = 5000 // unit is sim cycles
};

fapi2::ReturnCode p9_start_cbs(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                               & i_target_chip)
{
    fapi2::buffer<uint32_t> l_read_reg ;
    bool l_read_fsi2pib_status = false;
    fapi2::buffer<uint32_t> l_data32;
    fapi2::buffer<uint32_t> l_data32_cbs_cs;
    int l_timeout = 0;
    FAPI_DBG("Entering ...");

    FAPI_INF("check for OSC ok");
    //Getting SNS1LTH register value
    FAPI_TRY(fapi2::getCfamRegister(i_target_chip, PERV_SNS1LTH_FSI,
                                    l_read_reg)); //l_read_reg = CFAM.SNS1LTH

    FAPI_ASSERT(l_read_reg.getBit<10>() || l_read_reg.getBit<11>(),
                fapi2::OSC_BIT_ERR()
                .set_READ_SNS1LTH(l_read_reg),
                "FATAL ERROR:BIT 10 OR 11 NOT SET FOR MAILBOX SNS1LTH");

    FAPI_INF("check for VDD");
    //Getting FSI2PIB_STATUS register value
    FAPI_TRY(fapi2::getCfamRegister(i_target_chip, PERV_FSI2PIB_STATUS_FSI,
                                    l_data32));
    //l_read_fsi2pib_status = CFAM.FSI2PIB_STATUS.VDD_NEST_OBSERVE
    l_read_fsi2pib_status = l_data32.getBit<16>();

    FAPI_ASSERT(l_read_fsi2pib_status,
                fapi2::VDD_NEST_OBSERVE()
                .set_READ_FSI2PIB_STATUS(l_read_fsi2pib_status),
                "ERROR:VDD OFF , FSI2BIB STATUS BIT 16 NOT SET");

    FAPI_INF("Resetting CFAM Boot Sequencer (CBS) to flush value");
    //Setting CBS_CS register value
    FAPI_TRY(fapi2::getCfamRegister(i_target_chip, PERV_CBS_CS_FSI,
                                    l_data32_cbs_cs));
    l_data32_cbs_cs.clearBit<0>();  //CFAM.CBS_CS.CBS_CS_START_BOOT_SEQUENCER = 0
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_CBS_CS_FSI,
                                    l_data32_cbs_cs));

    // HW319150 - pervSoA:  cbs_start is implemented as pulse 0 -> 1
    FAPI_INF("Triggering CFAM Boot Sequencer (CBS) to start");
    //Setting CBS_CS register value
    l_data32_cbs_cs.setBit<0>();  //CFAM.CBS_CS.CBS_CS_START_BOOT_SEQUENCER = 1
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip, PERV_CBS_CS_FSI,
                                    l_data32_cbs_cs));

    FAPI_INF("Check cbs_cs_internal_state_vector");
    l_timeout = P9_CFAM_CBS_POLL_COUNT;

    //UNTIL CBS_CS.CBS_CS_INTERNAL_STATE_VECTOR == CBS_IDLE_VALUE
    while (l_timeout != 0)
    {
        //Getting CBS_CS register value
        FAPI_TRY(fapi2::getCfamRegister(i_target_chip, PERV_CBS_CS_FSI,
                                        l_data32_cbs_cs));
        uint32_t l_poll_data = 0;    //uint32_t l_poll_data = CFAM.CBS_CS.CBS_CS_INTERNAL_STATE_VECTOR
        l_data32_cbs_cs.extractToRight<16, 16>(l_poll_data);

        if (l_poll_data == CBS_IDLE_VALUE)
        {
            break;
        }

        fapi2::delay(P9_CBS_IDLE_HW_NS_DELAY, P9_CBS_IDLE_SIM_CYCLE_DELAY);
        --l_timeout;
    }

    FAPI_INF("Loop Count :%d", l_timeout);

    FAPI_ASSERT(l_timeout > 0,
                fapi2::CBS_CS_INTERNAL_STATE(),
                "ERROR:STATE NOT SET , CBS_CS BIT 30 NOT SET");

    FAPI_DBG("Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}
