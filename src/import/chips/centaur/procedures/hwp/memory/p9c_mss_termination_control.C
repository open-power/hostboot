/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_termination_control.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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

///
/// @file p9c_mss_termination_control.C
/// @brief Tools for DDR4 DIMMs centaur procedures
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: SARAVANAN SETHURAMAN  <saravanans@in.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
//


// Saravanan - Yet to update DRV_IMP new attribute enum change

// Not supported
// DDR4, DIMM Types
//----------------------------------------------------------------------
//  Includes - FAPI
//----------------------------------------------------------------------

#include <fapi2.H>
#include <dimmConsts.H>
#include <generic/memory/lib/utils/c_str.H>

//----------------------------------------------------------------------
//Centaur functions
//----------------------------------------------------------------------
#include <p9c_mss_termination_control.H>
#include <cen_gen_scom_addresses.H>
#include <p9c_mss_draminit_training_advanced.H>

///
/// @brief This function will configure the Driver impedance values to the registers
/// @param[in] i_target_mba  Centaur input mba
/// @param[in] i_port Centaur input port
/// @param[in] i_drv_imp_dq_dqs driver impedance (DQ/DQS) (OHM24,OHM30,OHM34,OHM40)
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode config_drv_imp(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba, const uint8_t i_port,
                                 const uint8_t i_drv_imp_dq_dqs)
{
    fapi2::buffer<uint64_t> data_buffer;
    uint8_t enslice_drv = 0xFF;
    uint8_t enslice_ffedrv = 0xF;
    uint8_t i = 0;

    FAPI_ASSERT(i_port < MAX_PORTS_PER_MBA,
                fapi2::CEN_CONFIG_DRV_IMP_INVALID_INPUT().
                set_PORT_PARAM(i_port),
                "Driver impedance port input(%u) out of bounds",
                i_port);

    for(i = 0; i < MAX_DRV_IMP; i++)
    {
        if (drv_imp_array[i] == i_drv_imp_dq_dqs)
        {
            switch (i)
            {
                case 0:   //40 ohms
                    enslice_drv = 0x3C;
                    enslice_ffedrv = 0xF;
                    break;

                case 1:   //34 ohms
                    enslice_drv = 0x7C;
                    enslice_ffedrv = 0xF;
                    break;

                case 2:  //30 ohms
                    enslice_drv = 0x7E;
                    enslice_ffedrv = 0xF;
                    break;

                case 3:   //24 ohms
                    enslice_drv = 0xFF;
                    enslice_ffedrv = 0xF;
                    break;
            }

            break;
        }
    }

    FAPI_TRY(fapi2::getScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_NFET_SLICE_P0_0,
                            data_buffer));
    FAPI_TRY(data_buffer.insertFromRight(enslice_drv, 48, 8), "config_drv_imp: Error in setting up buffer ");
    FAPI_TRY(data_buffer.insertFromRight(enslice_ffedrv, 56, 4), "config_drv_imp: Error in setting up buffer ");
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_NFET_SLICE_P0_0,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_NFET_SLICE_P0_1,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_NFET_SLICE_P0_2,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_NFET_SLICE_P0_3,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_NFET_SLICE_P0_4,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_PFET_SLICE_P0_0,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_PFET_SLICE_P0_1,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_PFET_SLICE_P0_2,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_PFET_SLICE_P0_3,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_PFET_SLICE_P0_4,
                            data_buffer));

    FAPI_TRY(fapi2::getScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_NFET_SLICE_P1_0,
                            data_buffer));
    FAPI_TRY(data_buffer.insertFromRight(enslice_drv, 48, 8), "config_drv_imp: Error in setting up buffer ");
    FAPI_TRY(data_buffer.insertFromRight(enslice_ffedrv, 56, 4), "config_drv_imp: Error in setting up buffer ");
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_NFET_SLICE_P1_0,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_NFET_SLICE_P1_1,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_NFET_SLICE_P1_2,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_NFET_SLICE_P1_3,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_NFET_SLICE_P1_4,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_PFET_SLICE_P1_0,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_PFET_SLICE_P1_1,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_PFET_SLICE_P1_2,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_PFET_SLICE_P1_3,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_PFET_SLICE_P1_4,
                            data_buffer));
fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief This function will configure the Receiver impedance values to the registers
/// @param[in] i_target_mba Centaur input mba
/// @param[in] i_port Centaur input port
/// @param[in] i_rcv_imp_dq_dqs : reciever impedance (OHM15,OHM20,OHM30,OHM40,OHM48,OHM60,OHM80,OHM120,OHM160,OHM240)
/// @return FAPI2_RC_SUCCESS iff successful
///

fapi2::ReturnCode config_rcv_imp(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba, const uint8_t i_port,
                                 const uint8_t i_rcv_imp_dq_dqs)
{
    fapi2::buffer<uint64_t> data_buffer;
    uint8_t enslicepterm = 0xFF;
    uint8_t enslicepffeterm = 0;
    uint8_t i = 0;

    FAPI_ASSERT(i_port < MAX_PORTS_PER_MBA,
                fapi2::CEN_CONFIG_RCV_IMP_INVALID_INPUT().
                set_PORT_PARAM(i_port),
                "Receiver impedance port input(%u) out of bounds",
                i_port);

    for(i = 0; i < MAX_RCV_IMP; i++)
    {
        if (rcv_imp_array[i] == i_rcv_imp_dq_dqs)
        {
            switch (i)
            {
                case 0:  //120 OHMS
                    enslicepterm = 0x10;
                    enslicepffeterm = 0x0;
                    break;

                case 1:   //80 OHMS
                    enslicepterm = 0x10;
                    enslicepffeterm = 0x2;
                    break;

                case 2:   //60 OHMS
                    enslicepterm = 0x18;
                    enslicepffeterm = 0x0;
                    break;

                case 3:   //48 OHMS
                    enslicepterm = 0x18;
                    enslicepffeterm = 0x2;
                    break;

                case 4:   //40 OHMS
                    enslicepterm = 0x18;
                    enslicepffeterm = 0x6;
                    break;

                case 5:   //34 OHMS
                    enslicepterm = 0x38;
                    enslicepffeterm = 0x2;
                    break;

                case 6:   //30 OHMS
                    enslicepterm = 0x3C;
                    enslicepffeterm = 0x0;
                    break;

                case 7:   //20 OHMS
                    enslicepterm = 0x7E;
                    enslicepffeterm = 0x0;
                    break;

                case 8:    //15 OHMS
                    enslicepterm = 0xFF;
                    enslicepffeterm = 0x0;
                    break;
            }

            break;
        }
    }

    FAPI_TRY(fapi2::getScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_NFET_TERM_P0_0,
                            data_buffer));
    FAPI_TRY(data_buffer.insertFromRight(enslicepterm, 48, 8), "config_rcv_imp: Error in setting up buffer ");
    FAPI_TRY(data_buffer.insertFromRight(enslicepffeterm, 56, 4), "config_rcv_imp: Error in setting up buffer ");
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_NFET_TERM_P0_0,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_NFET_TERM_P0_1,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_NFET_TERM_P0_2,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_NFET_TERM_P0_3,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_NFET_TERM_P0_4,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_PFET_TERM_P0_0,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_PFET_TERM_P0_1,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_PFET_TERM_P0_2,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_PFET_TERM_P0_3,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_PFET_TERM_P0_4,
                            data_buffer));

    FAPI_TRY(fapi2::getScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_NFET_TERM_P1_0,
                            data_buffer));
    FAPI_TRY(data_buffer.insertFromRight(enslicepterm, 48, 8), "config_rcv_imp: Error in setting up buffer ");
    FAPI_TRY(data_buffer.insertFromRight(enslicepffeterm, 56, 4), "config_rcv_imp: Error in setting up buffer ");
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_NFET_TERM_P1_0,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_NFET_TERM_P1_1,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_NFET_TERM_P1_2,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_NFET_TERM_P1_3,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_NFET_TERM_P1_4,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_PFET_TERM_P1_0,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_PFET_TERM_P1_1,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_PFET_TERM_P1_2,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_PFET_TERM_P1_3,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_IO_TX_PFET_TERM_P1_4,
                            data_buffer));
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief This function will configure the Slew rate values to the registers
/// @param[in] i_target_mba Centaur input mba
/// @param[in] i_port Centaur input port
/// @param[in] i_slew_type SLEW_TYPE_DATA=0, SLEW_TYPE_ADR_ADDR=1, SLEW_TYPE_ADR_CNTL=2
/// @param[in] i_slew_imp OHM15=15, OHM20=20, OHM24=24, OHM30=30, OHM34=34, OHM40=40
/// @note: 15, 20, 30, 40 valid for ADR; 24, 30, 34, 40 valid for DATA
/// @param[in] i_slew_rate SLEW_3V_NS=3, SLEW_4V_NS=4, SLEW_5V_NS=5, SLEW_6V_NS=6, SLEW_MAXV_NS=7
/// @note SLEW_MAXV_NS bypasses slew calibration
/// @return FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode config_slew_rate(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                   const uint8_t i_port, const uint8_t i_slew_type, const uint8_t i_slew_imp,
                                   const uint8_t i_slew_rate)
{
    fapi2::buffer<uint64_t> data_buffer;
    uint8_t slew_cal_value = 0;
    uint8_t imp_idx = 255;
    uint8_t slew_idx = 255;
    // array for ATTR_CEN_MSS_SLEW_RATE_DATA/ADR [2][4][4]
    // port,imp,slew_rat    cal'd slew settings
    uint8_t calibrated_slew_rate_table
    [MAX_PORTS_PER_MBA][MAX_NUM_IMP][MAX_NUM_CAL_SLEW_RATES] = {{{0}}};

    // FFDC for bad parameters
    FAPI_ASSERT(i_port < MAX_PORTS_PER_MBA,
                fapi2::CEN_CONFIG_SLEW_RATE_INVALID_INPUT().
                set_PORT_PARAM(i_port).
                set_SLEW_TYPE_PARAM(i_slew_type).
                set_SLEW_IMP_PARAM(i_slew_imp).
                set_SLEW_RATE_PARAM(i_slew_rate),
                "Slew port input(%u) out of bounds", i_port);

    FAPI_ASSERT(i_slew_type < MAX_NUM_SLEW_TYPES,
                fapi2::CEN_CONFIG_SLEW_RATE_INVALID_INPUT().
                set_PORT_PARAM(i_port).
                set_SLEW_TYPE_PARAM(i_slew_type).
                set_SLEW_IMP_PARAM(i_slew_imp).
                set_SLEW_RATE_PARAM(i_slew_rate),
                "Slew type input(%u) out of bounds, (>= %u)",
                i_slew_type, MAX_NUM_SLEW_TYPES);

    switch (i_slew_rate)        // get slew index
    {
        case SLEW_MAXV_NS:          // max slew
            FAPI_INF("Slew rate is set to MAX, using bypass mode");
            slew_cal_value = 0;     // slew cal value for bypass mode
            break;

        case SLEW_6V_NS:
            slew_idx = 3;
            break;

        case SLEW_5V_NS:
            slew_idx = 2;
            break;

        case SLEW_4V_NS:
            slew_idx = 1;
            break;

        case SLEW_3V_NS:
            slew_idx = 0;
            break;

        default:
            FAPI_ASSERT(false,
                        fapi2::CEN_CONFIG_SLEW_RATE_INVALID_INPUT(),
                        "Slew rate input(%u) out of bounds",
                        i_slew_rate);
    }

    if (i_slew_type == SLEW_TYPE_DATA)
    {
        switch (i_slew_imp)     // get impedance index for data
        {
            case OHM40:
                imp_idx = 3;
                break;

            case OHM34:
                imp_idx = 2;
                break;

            case OHM30:
                imp_idx = 1;
                break;

            case OHM24:
                imp_idx = 0;
                break;

            default:            // OHM15 || OHM20 not valid for data
                FAPI_ASSERT(false,
                            fapi2::CEN_CONFIG_SLEW_RATE_INVALID_INPUT(),
                            "Slew impedance input(%u) invalid "
                            "or out of bounds, index=%u",
                            i_slew_imp, imp_idx);
        }

        if (i_slew_rate != SLEW_MAXV_NS)
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_SLEW_RATE_DATA, i_target_mba,
                                   calibrated_slew_rate_table));

            slew_cal_value =
                calibrated_slew_rate_table[i_port][imp_idx][slew_idx];
        }

        if (slew_cal_value > MAX_SLEW_VALUE)
        {
            FAPI_INF("WARNING:  Slew rate(0x%02x) unsupported, "
                     "but continuing... !!", slew_cal_value);
            slew_cal_value = slew_cal_value & 0x0F;
        }

        FAPI_INF("Setting DATA (dq/dqs) slew register, imped=%i, slewrate=%i, "
                 "reg_val=0x%X", i_slew_imp, i_slew_rate, slew_cal_value);

        FAPI_DBG("port%u type=%u imp_idx=%u slew_idx=%u cal_slew=%u",
                 i_port, i_slew_type, imp_idx, slew_idx, slew_cal_value);

        if (i_port == 0)     // port 0 dq/dqs slew
        {
            FAPI_TRY(fapi2::getScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_IO_TX_CONFIG0_P0_0,
                                    data_buffer));

            FAPI_TRY(data_buffer.insertFromRight(slew_cal_value, 56, 4), "Error in setting up DATA slew buffer");
            // switch this later to use broadcast address, 0x80003C750301143F P0_[0:4]
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_IO_TX_CONFIG0_P0_0,
                                    data_buffer));
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_IO_TX_CONFIG0_P0_1,
                                    data_buffer));
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_IO_TX_CONFIG0_P0_2,
                                    data_buffer));
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_IO_TX_CONFIG0_P0_3,
                                    data_buffer));
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_IO_TX_CONFIG0_P0_4,
                                    data_buffer));
        }
        else     // port 1 dq/dqs slew
        {
            FAPI_TRY(fapi2::getScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_IO_TX_CONFIG0_P1_0,
                                    data_buffer));

            FAPI_TRY(data_buffer.insertFromRight(slew_cal_value, 56, 4), "Error in setting up DATA slew buffer");
            // switch this later to use broadcast address, 0x80013C750301143F P1_[0:4]
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_IO_TX_CONFIG0_P1_0,
                                    data_buffer));
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_IO_TX_CONFIG0_P1_1,
                                    data_buffer));
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_IO_TX_CONFIG0_P1_2,
                                    data_buffer));
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_IO_TX_CONFIG0_P1_3,
                                    data_buffer));
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_DP18_IO_TX_CONFIG0_P1_4,
                                    data_buffer));
        }
    } // end DATA
    else    // Slew type = ADR
    {
        uint8_t adr_pos = 48;   // SLEW_CTL0(48:51) of reg for ADR command slew

        for(uint8_t i = 0; i < MAX_NUM_IMP; i++) // find ADR imp index
        {
            if (adr_imp_array[i] == i_slew_imp)
            {
                imp_idx = i;
                break;
            }
        }

        if ((i_slew_imp == OHM24) || (i_slew_imp == OHM34) ||
            (imp_idx >= MAX_NUM_IMP))
        {
            FAPI_ASSERT(false,
                        fapi2::CEN_CONFIG_SLEW_RATE_INVALID_INPUT(),
                        "Slew impedance input(%u) out of bounds",
                        i_slew_imp);
        }

        if (i_slew_rate == SLEW_MAXV_NS)
        {
            slew_cal_value = 0;
        }
        else
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_SLEW_RATE_ADR, i_target_mba,
                                   calibrated_slew_rate_table));

            slew_cal_value =
                calibrated_slew_rate_table[i_port][imp_idx][slew_idx];
        }

        if (slew_cal_value > MAX_SLEW_VALUE)
        {
            FAPI_INF("!! Slew rate(0x%02x) unsupported, but continuing... !!",
                     slew_cal_value);
            slew_cal_value = slew_cal_value & 0x0F;
        }

        switch (i_slew_type)        // get impedance index for data
        {
            case SLEW_TYPE_ADR_ADDR:
                // CTL0 for command slew (A0:15, BA0:3, ACT, PAR, CAS, RAS, WE)
                FAPI_INF("Setting ADR command/address slew in CTL0 register "
                         "imped=%i, slewrate=%i, reg_val=0x%X", i_slew_imp,
                         i_slew_rate, slew_cal_value);
                adr_pos = 48;
                break;

            case SLEW_TYPE_ADR_CNTL:
                // CTL1 for control slew (CKE0:1, CKE4:5, ODT0:3, CSN0:3)
                FAPI_INF("Setting ADR control slew in CTL1 register "
                         "imped=%i, slewrate=%i, reg_val=0x%X", i_slew_imp,
                         i_slew_rate, slew_cal_value);
                adr_pos = 52;
                break;

            case SLEW_TYPE_ADR_CLK:
                // CTL2 for clock slew (CLK0:3)
                FAPI_INF("Setting ADR clock slew in CTL2 register "
                         "imped=%i, slewrate=%i, reg_val=0x%X", i_slew_imp,
                         i_slew_rate, slew_cal_value);
                adr_pos = 56;
                break;

            case SLEW_TYPE_ADR_SPCKE:
                // CTL3 for spare clock  slew (CKE2:3)
                FAPI_INF("Setting ADR Spare clock in CTL3 register "
                         "imped=%i, slewrate=%i, reg_val=0x%X", i_slew_imp,
                         i_slew_rate, slew_cal_value);
                adr_pos = 60;
                break;
        }

        FAPI_DBG("port%u type=%u slew_idx=%u imp_idx=%u cal_slew=%u",
                 i_port, i_slew_type, slew_idx, imp_idx, slew_cal_value);

        if (i_port == 0)     // port 0 adr slew
        {
            FAPI_TRY(fapi2::getScom(i_target_mba,
                                    CEN_MBA_DDRPHY_ADR_IO_SLEW_CTL_VALUE_P0_ADR0,
                                    data_buffer));

            FAPI_TRY(data_buffer.insertFromRight(slew_cal_value, adr_pos, 4), "Error in setting up ADR slew buffer");
            // switch this later to use broadcast address, 0x80007C1A0301143f ADR[0:3]
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_ADR_IO_SLEW_CTL_VALUE_P0_ADR0,
                                    data_buffer));
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_ADR_IO_SLEW_CTL_VALUE_P0_ADR1,
                                    data_buffer));
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_ADR_IO_SLEW_CTL_VALUE_P0_ADR2,
                                    data_buffer));
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_ADR_IO_SLEW_CTL_VALUE_P0_ADR3,
                                    data_buffer));
        }
        else                 // port 1 adr slew
        {
            FAPI_TRY(fapi2::getScom(i_target_mba,
                                    CEN_MBA_DDRPHY_ADR_IO_SLEW_CTL_VALUE_P1_ADR0,
                                    data_buffer));
            FAPI_TRY(data_buffer.insertFromRight(slew_cal_value, adr_pos, 4), "Error in setting up ADR slew buffer");
            // switch this later to use broadcast address, 0x80017C1A0301143f ADR[0:3]
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_ADR_IO_SLEW_CTL_VALUE_P1_ADR0,
                                    data_buffer));
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_ADR_IO_SLEW_CTL_VALUE_P1_ADR1,
                                    data_buffer));
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_ADR_IO_SLEW_CTL_VALUE_P1_ADR2,
                                    data_buffer));
            FAPI_TRY(fapi2::putScom(i_target_mba,
                                    CEN_MBA_DDRPHY_ADR_IO_SLEW_CTL_VALUE_P1_ADR3,
                                    data_buffer));
        }
    } // end ADR

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief This function configures PC_VREF_DRV_CONTROL registers to vary the DIMM VREF
/// @param[in] i_target_mba Centaur input mba
/// @param[in] i_port Centaur input port
/// @param[in] i_wr_dram_vref dram write reference voltage
/// @return FAPI2_RC_SUCCESS  iff successful
///
fapi2::ReturnCode config_wr_dram_vref(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba, const uint8_t i_port,
                                      const uint32_t i_wr_dram_vref)
{

    fapi2::buffer<uint64_t> data_buffer;
    uint32_t pcvref = 0;
    uint32_t sign = 0;

    // For DDR3 vary from VDD*0.42 to VDD*575
    // For DDR4 internal voltage is there this function is not required
    FAPI_ASSERT(i_port < MAX_PORTS_PER_MBA,
                fapi2::CEN_CONFIG_WR_DRAM_VREF_INVALID_INPUT().
                set_PORT_PARAM(i_port),
                "Write Vref port input(%u) out of bounds",
                i_port);

    if(i_wr_dram_vref < 500)
    {
        sign = 1;
    }
    else
    {
        sign = 0;
    }

    if((i_wr_dram_vref == 420) || (i_wr_dram_vref == 575))
    {
        pcvref = 0xF;
    }
    else if((i_wr_dram_vref == 425) || (i_wr_dram_vref == 570))
    {
        pcvref = 0x7;
    }
    else if((i_wr_dram_vref == 430) || (i_wr_dram_vref == 565))
    {
        pcvref = 0xB;
    }
    else if((i_wr_dram_vref == 435) || (i_wr_dram_vref == 560))
    {
        pcvref = 0x3;
    }
    else if((i_wr_dram_vref == 440) || (i_wr_dram_vref == 555))
    {
        pcvref = 0xD;
    }
    else if((i_wr_dram_vref == 445) || (i_wr_dram_vref == 550))
    {
        pcvref = 0x5;
    }
    else if((i_wr_dram_vref == 450) || (i_wr_dram_vref == 545))
    {
        pcvref = 0x9;
    }
    else if((i_wr_dram_vref == 455) || (i_wr_dram_vref == 540))
    {
        pcvref = 0x1;
    }
    else if((i_wr_dram_vref == 460) || (i_wr_dram_vref == 535))
    {
        pcvref = 0xE;
    }
    else if((i_wr_dram_vref == 465) || (i_wr_dram_vref == 530))
    {
        pcvref = 0x6;
    }
    else if((i_wr_dram_vref == 470) || (i_wr_dram_vref == 525))
    {
        pcvref = 0xA;
    }
    else if((i_wr_dram_vref == 475) || (i_wr_dram_vref == 520))
    {
        pcvref = 0x2;
    }
    else if((i_wr_dram_vref == 480) || (i_wr_dram_vref == 515))
    {
        pcvref = 0xC;
    }
    else if((i_wr_dram_vref == 485) || (i_wr_dram_vref == 510))
    {
        pcvref = 0x4;
    }
    else if((i_wr_dram_vref == 490) || (i_wr_dram_vref == 505))
    {
        pcvref = 0x8;
    }
    else if((i_wr_dram_vref == 495) || (i_wr_dram_vref == 500))
    {
        pcvref = 0x0;
    }

    FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_DDRPHY_PC_VREF_DRV_CONTROL_P0, data_buffer));
    FAPI_TRY(data_buffer.insertFromRight(sign, 48, 1), "config_wr_vref: Error in setting up buffer ");
    FAPI_TRY(data_buffer.insertFromRight(sign, 53, 1), "config_wr_vref: Error in setting up buffer ");
    FAPI_TRY(data_buffer.insertFromRight(pcvref, 49, 4), "config_wr_vref: Error in setting up buffer ");
    FAPI_TRY(data_buffer.insertFromRight(pcvref, 54, 4), "config_wr_vref: Error in setting up buffer ");
    FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_DDRPHY_PC_VREF_DRV_CONTROL_P0, data_buffer));
    FAPI_TRY(data_buffer.insertFromRight(sign, 48, 1), "config_wr_vref: Error in setting up buffer ");
    FAPI_TRY(data_buffer.insertFromRight(sign, 53, 1), "config_wr_vref: Error in setting up buffer ");
    FAPI_TRY(data_buffer.insertFromRight(pcvref, 49, 4), "config_wr_vref: Error in setting up buffer ");
    FAPI_TRY(data_buffer.insertFromRight(pcvref, 54, 4), "config_wr_vref: Error in setting up buffer ");
    FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_DDRPHY_PC_VREF_DRV_CONTROL_P1, data_buffer));
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief This function configures read vref registers to vary the CEN VREF
/// @param[in] i_target_mba centaur input mba
/// @param[in] i_rd_cen_vref Read vref (centaur side)
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode config_rd_cen_vref (const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba, const uint8_t i_port,
                                      const uint32_t i_rd_cen_vref)
{
// VDD40375 = 40375, VDD41750 = 41750, VDD43125 = 43125, VDD44500 = 44500,
// VDD45875 = 45875, VDD47250 = 47250, VDD48625 = 48625, VDD50000 = 50000, VDD51375 = 51375,
// VDD52750 = 52750, VDD54125 = 54125, VDD55500 = 55500, VDD56875 = 56875, VDD58250 = 58250,
// VDD59625 = 59625, VDD61000 = 61000, VDD60375 = 60375, VDD61750 = 61750, VDD63125 = 63125,
// VDD64500 = 64500, VDD65875 = 65875, VDD67250 = 67250, VDD68625 = 68625, VDD70000 = 70000,
// VDD71375 = 71375, VDD72750 = 72750, VDD74125 = 74125, VDD75500 = 75500, VDD76875 = 76875,
// VDD78250 = 78250, VDD79625 = 79625, VDD81000 = 81000
// DDR3 supports upto 61000, DDR4 - full range

    fapi2::buffer<uint64_t> data_buffer;
    uint32_t rd_vref = 0;

    FAPI_ASSERT(i_port < MAX_PORTS_PER_MBA,
                fapi2::CEN_CONFIG_RD_CEN_VREF_INVALID_INPUT().
                set_PORT_PARAM(i_port),
                "Read vref port input(%u) out of bounds",
                i_port);

    //if (rd_cen_vref == DDR3 rd_vref ) || (rd_cen_vref == DDR4)

    if((i_rd_cen_vref == 61000) || (i_rd_cen_vref == 81000))
    {
        rd_vref = 0xF;
    }
    else if((i_rd_cen_vref == 59625) || (i_rd_cen_vref == 79625))
    {
        rd_vref = 0xE;
    }
    else if((i_rd_cen_vref == 58250) || (i_rd_cen_vref == 78250))
    {
        rd_vref = 0xD;
    }
    else if((i_rd_cen_vref == 56875) || (i_rd_cen_vref == 76875))
    {
        rd_vref = 0xC;
    }
    else if((i_rd_cen_vref == 55500) || (i_rd_cen_vref == 75500))
    {
        rd_vref = 0xB;
    }
    else if((i_rd_cen_vref == 54125) || (i_rd_cen_vref == 74125))
    {
        rd_vref = 0xA;
    }
    else if((i_rd_cen_vref == 52750) || (i_rd_cen_vref == 72750))
    {
        rd_vref = 0x9;
    }
    else if((i_rd_cen_vref == 51375) || (i_rd_cen_vref == 71375))
    {
        rd_vref = 0x8;
    }
    else if((i_rd_cen_vref == 50000) || (i_rd_cen_vref == 70000))
    {
        rd_vref = 0x0;
    }
    else if((i_rd_cen_vref == 48625) || (i_rd_cen_vref == 68625))
    {
        rd_vref = 0x1;
    }
    else if((i_rd_cen_vref == 47250) || (i_rd_cen_vref == 67250))
    {
        rd_vref = 0x2;
    }
    else if((i_rd_cen_vref == 45875) || (i_rd_cen_vref == 65875))
    {
        rd_vref = 0x3;
    }
    else if((i_rd_cen_vref == 44500) || (i_rd_cen_vref == 64500))
    {
        rd_vref = 0x4;
    }
    else if((i_rd_cen_vref == 43125) || (i_rd_cen_vref == 63125))
    {
        rd_vref = 0x5;
    }
    else if((i_rd_cen_vref == 41750) || (i_rd_cen_vref == 61750))
    {
        rd_vref = 0x6;
    }
    else if((i_rd_cen_vref == 40375) || (i_rd_cen_vref == 60375))
    {
        rd_vref = 0x7;
    }
    else
    {
        rd_vref = 0x0;
    }

    FAPI_TRY(fapi2::getScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P0_0,
                            data_buffer));
    FAPI_TRY(data_buffer.insertFromRight(rd_vref, 56, 4), "config_rd_vref: Error in setting up buffer ");
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P0_0,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P0_1,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P0_2,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P0_3,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P0_4,
                            data_buffer));
    FAPI_TRY(fapi2::getScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P1_0,
                            data_buffer));
    FAPI_TRY(data_buffer.insertFromRight(rd_vref, 56, 4), "config_rd_vref: Error in setting up buffer ");
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P1_0,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P1_1,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P1_2,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P1_3,
                            data_buffer));
    FAPI_TRY(fapi2::putScom(i_target_mba,
                            CEN_MBA_DDRPHY_DP18_RX_PEAK_AMP_P1_4,
                            data_buffer));
fapi_try_exit:
    return fapi2::current_err;
}

///
/// Function: mss_slew_cal()
/// @brief Runs the slew calibration engine to configure MSS_SLEW_DATA/ADR attrs and calls config_slew_rate to set the slew rate
/// @param[in] i_target_mba centaur mba
///
fapi2::ReturnCode mss_slew_cal(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba)
{
    fapi2::ReturnCode array_rcs[MAX_PORTS_PER_MBA]; // capture rc per port loop
    uint32_t poll_count = 0;
    uint8_t ports_valid = 0;
    uint8_t is_sim = 0;
    fapi2::ReturnCode rc;
    uint8_t freq_idx = 0;       // freq index into lookup table
    uint32_t ddr_freq = 0;      // current ddr freq
    uint8_t ddr_idx = 0;        // ddr type index into lookup table
    uint8_t ddr_type = 0;       // ATTR_CEN_EFF_DRAM_GEN{0=invalid, 1=ddr3, 2=ddr4}

    uint8_t cal_status = 0;
    // bypass slew (MAX slew rate) not included since it is not calibrated.
    // for output ATTR_CEN_MSS_SLEW_RATE_DATA(0),
    //            ATTR_CEN_MSS_SLEW_RATE_ADR(1), [port=2][imp=4][slew=4]
    uint8_t calibrated_slew[2][MAX_PORTS_PER_MBA][MAX_NUM_IMP]
    [MAX_NUM_CAL_SLEW_RATES] = {{{{ 0 }}}};

    fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> l_target_centaur; // temporary target for parent

    fapi2::buffer<uint64_t> ctl_reg;
    fapi2::buffer<uint64_t> stat_reg;

    // DD level 1.0-1.1, Version 1.0
    // [ddr3/4][dq/adr][speed][impedance][slew_rate]
    // note: Assumes standard voltage for DDR3(1.35V), DDR4(1.2V),
    // little endian, if >=128, lab only debug.
    //
    // ddr_type(2)  ddr3=0, ddr4=1
    // data/adr(2)  data(dq/dqs)=0, adr(cmd/cntl)=1
    // speed(4)     1066=0, 1333=1, 1600=2, 1866=3
    // imped(4)     24ohms=0, 30ohms=1, 34ohms=2, 40ohms=3 for DQ/DQS
    // imped(4)     15ohms=0, 20ohms=1, 30ohms=2, 40ohms=3 for ADR driver
    // slew(3)      3V/ns=0, 4V/ns=1, 5V/ns=2, 6V/ns=3
    const uint8_t slew_table[2][2][4][4][4] =
    {
//  NOTE: bit 7 = unsupported slew, and actual value is in bits 4:0

        /*  DDR3(0) */
        { {
                // dq/dqs(0)
                /* Imp. ________24ohms______..________30ohms______..________34ohms______..________40ohms______
                   Slew    3    4    5    6      3    4    5    6      3    4    5    6      3    4    5    6  (V/ns) */
                /*1066*/{{ 12,   9,   7, 134}, { 13,   9,   7, 133}, { 13,  10,   7, 134}, { 14,  10,   7, 132}},
                /*1333*/{{ 15,  11,   8, 135}, { 16,  12,   9, 135}, { 17,  12,   9, 135}, { 17,  12,   8, 133}},
                /*1600*/{{ 18,  13,  10, 136}, { 19,  14,  10, 136}, { 20,  15,  11, 136}, { 21,  14,  10, 134}},
                /*1866*/{{149, 143, 140, 138}, {151, 144, 140, 137}, {151, 145, 141, 138}, {152, 145, 139, 135}}
            }, {
                // adr(1),
                /* Imp. ________15ohms______..________20ohms______..________30ohms______..________40ohms______
                   Slew    3    4    5    6      3    4    5    6      3    4    5    6      3    4    5    6  (V/ns) */
// 1066 {{ 17,  13,  10,   8}, { 13,  11,   7,   6}, { 12,   8,   5, 131}, {  7,   4, 131, 131}}, // old before May 2013
                /*1066*/{{ 17,  13,  10,   8}, { 13,  10,   7,   6}, { 12,   8,   5, 131}, {  7,   4, 131, 131}},
                /*1333*/{{ 21,  16,  12,  10}, { 17,  12,   9,   7}, { 15,  10,   6, 132}, {  6,   5, 132, 132}},
                /*1600*/{{ 25,  19,  15,  12}, { 20,  14,  13,   8}, { 19,  12,   7, 133}, {  7,   6, 133, 133}},
                /*1866*/{{157, 150, 145, 142}, {151, 145, 141, 138}, {150, 142, 136, 134}, {141, 134, 134, 134}}
            }
        },
        /* DDR4(1) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
        { {
                // dq/dqs(0)
                /* Imp. ________24ohms______..________30ohms______..________34ohms______..________40ohms______
                   Slew    3    4    5    6      3    4    5    6      3    4    5    6      3    4    5    6  (V/ns) */
                /*1066*/{{138, 135, 134, 133}, {139, 136, 134, 132}, {140, 136, 134, 132}, {140, 136, 132, 132}},
                /*1333*/{{139, 137, 135, 134}, {142, 138, 135, 133}, {143, 138, 135, 133}, {143, 138, 133, 132}},
                /*1600*/{{ 15,  11,   9, 135}, { 17,  11,   9, 135}, { 18,  13,   9, 134}, { 18,  11,   6, 133}},
                /*1866*/{{ 18,  13,  10, 137}, { 19,  13,  10, 136}, { 21,  15,  10, 135}, { 21,  13,   8, 134}}
            }, {
                // adr(1)
                /* Imp. ________15ohms______..________20ohms______..________30ohms______..________40ohms______
                   Slew    3    4    5    6      3    4    5    6      3    4    5    6      3    4    5    6  (V/ns) */
                /*1066*/{{142, 139, 136, 134}, {140, 136, 134, 133}, {138, 134, 131, 131}, {133, 131, 131, 131}},
                /*1333*/{{145, 142, 139, 136}, {143, 138, 135, 134}, {140, 135, 132, 132}, {134, 132, 132, 132}},
                /*1600*/{{ 21,  16,  13,  10}, { 18,  12,   9, 135}, { 15,   8, 133, 133}, {  7, 133, 133, 133}},
                /*1866*/{{ 24,  19,  15,  11}, { 21,  14,  10, 136}, { 17,  10, 134, 134}, {  9, 134, 134, 134}}
            }
        }
    };

    // slew calibration control register
    const uint64_t slew_cal_cntl[] =
    {
        CEN_MBA_DDRPHY_ADR_SLEW_CAL_CNTL_P0_ADR32S0, // port 0
        CEN_MBA_DDRPHY_ADR_SLEW_CAL_CNTL_P1_ADR32S0  // port 1
    };
    // slew calibration status registers
    const uint64_t slew_cal_stat[] =
    {
        CEN_MBA_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P0_ADR32S0_RO,
        CEN_MBA_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P1_ADR32S0_RO
    };
    const uint8_t ENABLE_BIT = 48;
    const uint8_t START_BIT = 49;
    const uint8_t BB_LOCK_BIT = 56;
    // general purpose 100 ns delay for HW mode  (2000 sim cycles if simclk = 20ghz)
    const uint16_t  DELAY_100NS     = 100;
    const uint16_t  DELAY_2000NCLKS = 4000;     // roughly 2000 nclks if DDR freq >= 1066
    // normally 2000, but since cal doesn't work in SIM, setting to 1
    const uint16_t  DELAY_SIMCYCLES = 1;
    const uint8_t   MAX_POLL_LOOPS  = 20;

    uint8_t cal_slew;
    uint8_t slew_imp_val [MAX_NUM_SLEW_TYPES][2][MAX_PORTS_PER_MBA] = {{{0}}};
    enum
    {
        SLEW = 0,
        IMP = 1,
    };
    // verify which ports are functional
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_EFF_DIMM_FUNCTIONAL_VECTOR,
                           i_target_mba, ports_valid), "Failed to get attribute:ATTR_CEN_MSS_EFF_DIMM_FUNCTIONAL_VECTOR");

    // Check if in SIM
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), is_sim),
             "Failed to get attribute: ATTR_IS_SIMULATION");
    // Get DDR type (DDR3 or DDR4)
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_GEN, i_target_mba, ddr_type),
             "Failed to get attribute: ATTR_CEN_EFF_DRAM_GEN");

    // ddr_type(2)  ddr3=0, ddr4=1
    if (ddr_type == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4)     //type=2
    {
        ddr_idx = 1;
    }
    else if (ddr_type == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR3)     //type=1
    {
        ddr_idx = 0;
    }
    else
    {
        FAPI_ASSERT(false,
                    fapi2::CEN_MSS_SLEW_CAL_INVALID_DRAM_GEN().
                    set_DRAM_GEN(ddr_type),
                    "Invalid ATTR_CEN_DRAM_DRAM_GEN = %d, %s!",
                    ddr_type,
                    mss::c_str(i_target_mba));
    }

    // get freq from parent
    l_target_centaur = i_target_mba.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_FREQ, l_target_centaur, ddr_freq));

    if (ddr_freq == 0)
    {
        FAPI_ASSERT(false,
                    fapi2::CEN_MSS_SLEW_CAL_INVALID_FREQ(),
                    "Invalid ATTR_CEN_MSS_FREQ = %d on %s!",
                    ddr_freq,
                    mss::c_str(i_target_mba));
    }

    // speed(4)     1066=0, 1333=1, 1600=2, 1866=3
    if (ddr_freq > 1732)
    {
        freq_idx = 3;       // for 1866+
    }
    else if ((ddr_freq > 1460) && (ddr_freq <= 1732))
    {
        freq_idx = 2;       // for 1600
    }
    else if ((ddr_freq > 1200) && (ddr_freq <= 1460))
    {
        freq_idx = 1;       // for 1333
    }
    else            // (ddr_freq <= 1200)
    {
        freq_idx = 0;       // for 1066-
    }

    for (uint8_t l_port = 0; l_port < MAX_PORTS_PER_MBA; l_port++)
    {
        uint8_t port_val = (ports_valid & (0xF0 >> (4 * l_port)));

        if (port_val == 0)
        {
            FAPI_INF("WARNING:  port %u is invalid from "
                     "ATTR_CEN_MSS_EFF_DIMM_FUNCTIONAL_VECTOR (0x%02x), skipping.",
                     l_port, ports_valid);
            continue;
        }

        //  Step A: Configure ADR registers and MCLK detect (done in ddr_phy_reset)
        // CEN_MBA_DDRPHY_ADR_SLEW_CAL_CNTL_P0_ADR32S0 + port
        FAPI_TRY(fapi2::getScom(i_target_mba, slew_cal_cntl[l_port], ctl_reg),
                 "Error reading DDRPHY_ADR_SLEW_CAL_CNTL register.");
        ctl_reg.flush<0>();
        FAPI_TRY(ctl_reg.setBit(ENABLE_BIT), "Error setting enable bit in ADR Slew calibration "
                 "control register.");       // set enable (bit49) to 1

        FAPI_INF("Enabling slew calibration engine on port %i: DDR%i(%u) "
                 "%u(%u) in %s", l_port, (ddr_type + 2), ddr_idx, ddr_freq,
                 freq_idx, mss::c_str(i_target_mba));

        // CEN_MBA_DDRPHY_ADR_SLEW_CAL_CNTL_P0_ADR32S0 + port
        FAPI_TRY(fapi2::putScom(i_target_mba, slew_cal_cntl[l_port], ctl_reg), "Error enabling slew calibration engine in "
                 "DDRPHY_ADR_SLEW_CAL_CNTL register.");
        // Note: must be 2000 nclks+ after setting enable bit
        FAPI_TRY(fapi2::delay(DELAY_2000NCLKS, 1), "Error executing fapi2::delay of 2000 nclks or 1 simcycle");

        //---------------------------------------------------------------------/
        //  Step 1. Check for BB lock.
        FAPI_DBG("Wait for BB lock in status register, bit %u", BB_LOCK_BIT);

        for (poll_count = 0; poll_count < MAX_POLL_LOOPS; poll_count++)
        {
            FAPI_TRY(fapi2::delay(DELAY_100NS, DELAY_SIMCYCLES), "Error executing fapi2::delay of 100ns or 2000simcycles");
            // CEN_MBA_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P0_ADR32S0_RO + port
            FAPI_TRY(fapi2::getScom(i_target_mba, slew_cal_stat[l_port], stat_reg),
                     "Error reading DDRPHY_ADR_SYSCLK_PR_VALUE_RO register "
                     "for BB_Lock.");
//          FAPI_DBG("stat_reg = 0x%04x, count=%i",stat_reg.getHalfWord(3),
//                  poll_count);

            if (stat_reg.getBit(BB_LOCK_BIT))
            {
                break;
            }
        }

        if (poll_count == MAX_POLL_LOOPS)
        {
            FAPI_INF("WARNING: Timeout on polling BB_Lock, continuing...");
        }
        else
        {
            FAPI_DBG("polling finished in %i loops (%u ns)\n",
                     poll_count, (100 * poll_count));
        }

        //---------------------------------------------------------------------/
        // Create calibrated slew settings
        // dq/adr(2)    dq/dqs=0, adr=1
        // slew(4)      3V/ns=0, 4V/ns=1, 5V/ns=2, 6V/ns=3
        for (uint8_t data_adr = 0; data_adr < 2; data_adr++)
        {
            FAPI_INF("Starting %s(%i) slew calibration...",
                     (data_adr ? "ADR" : "DATA"), data_adr);

            for (uint8_t imp = 0; imp < MAX_NUM_IMP; imp++)
            {

                for (uint8_t slew = 0; slew < MAX_NUM_CAL_SLEW_RATES; slew++)
                {
                    cal_slew =
                        slew_table[ddr_idx][data_adr][freq_idx][imp][slew];

                    // set slew phase rotator from slew_table
                    // slew_table[ddr3/4][dq/adr][freq][impedance][slew_rate]
                    FAPI_TRY(ctl_reg.insertFromRight(cal_slew, 59, 5), "Error setting start bit or cal input value.");

                    FAPI_TRY(ctl_reg.setBit(START_BIT), "Error setting start bit or cal input value."); // set start bit(48)

                    /*              FAPI_DBG("Slew data_adr=%i, imp_idx=%i, slewrate=%i, "
                                        "i_slew=%i,0x%02X (59:63) cntl_reg(48:63)=0x%04X",
                                        data_adr, imp, (slew+3), cal_slew, cal_slew,
                                        ctl_reg.getHalfWord(3)); */

                    // CEN_MBA_DDRPHY_ADR_SLEW_CAL_CNTL_P0_ADR32S0 + port
                    FAPI_TRY(fapi2::putScom(i_target_mba, slew_cal_cntl[l_port], ctl_reg), "Error starting slew calibration.");

                    // poll for calibration status done or timeout...
                    for (poll_count = 0; poll_count < MAX_POLL_LOOPS;
                         poll_count++)
                    {
                        // CEN_MBA_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P0_ADR32S0_RO + port
                        FAPI_TRY(fapi2::getScom(i_target_mba, slew_cal_stat[l_port],
                                                stat_reg), "Error reading "
                                 "DDRPHY_ADR_SYSCLK_PR_VALUE_RO "
                                 "register for calibration status.");
                        FAPI_TRY(stat_reg.extractToRight(cal_status, 58, 2), "Error getting calibration status bits");

                        if (cal_status != 0)
                        {
                            break;
                        }

                        // wait (1020 mclks / MAX_POLL_LOOPS)
                        FAPI_TRY(fapi2::delay(DELAY_100NS, DELAY_SIMCYCLES));
                    }

                    if (cal_status > 1)
                    {
                        if (cal_status == 3)
                        {
                            FAPI_DBG("slew calibration completed successfully,"
                                     " loop=%i input=0x%02x",    poll_count,
                                     (cal_slew & 0x1F));
                        }
                        else if (cal_status == 2)
                        {
                            /*    FAPI_INF("WARNING: occurred during slew calibration"
                                         ", imped=%i, slewrate=%i %s ddr_idx[%i]",
                                         data_adr ? adr_imp_array[imp] :
                                           drv_imp_array[(4-imp)], (slew+3),
                                         i_target_mba.toEcmdString(), ddr_idx);
                                FAPI_INF("data_adr[%i], freq_idx[%i], imp[%i], slew[%i]",
                                         data_adr, freq_idx, imp, slew);
                                FAPI_INF("input=0x%02X, ctrl=0x%04X, status=0x%04X",
                                         (cal_slew & 0x1F), ctl_reg.getHalfWord(3),
                                         stat_reg.getHalfWord(3)); */
                        }

                        cal_slew = cal_slew & 0x80; // clear bits 6:0
                        stat_reg.extract<60, 4, 4>(cal_slew);
                        FAPI_DBG("MSS_SLEW_RATE_%s port[%i]imp[%i]slew[%i] = "
                                 "0x%02x\n", (data_adr ? "ADR" : "DATA"), l_port,
                                 imp, slew, (cal_slew & 0xF));
                        calibrated_slew[data_adr][l_port][imp][slew] = cal_slew;
                    }
                    else
                    {
                        if (is_sim)
                        {
                            // Calibration fails in sim since bb_lock not
                            // possible in cycle simulator, putting initial
                            // to be cal'd value in output table
                            FAPI_INF("In SIM setting input slew value in array"
                                     ", status(%i) NOT clean.", cal_status);
                            calibrated_slew[data_adr][l_port][imp][slew] =
                                cal_slew;
                        }
                        else
                        {
                            FAPI_ERR("Slew calibration failed on %s slew: "
                                     "imp_idx=%d(%i ohms)",
                                     (data_adr ? "ADR" : "DATA"), imp,
                                     (data_adr ? adr_imp_array[imp] :
                                      drv_imp_array[(4 - imp)]));
                            //    FAPI_ERR("slew_idx=%d(%i V/ns), slew_table=0x%02X",
                            //       slew, (slew+3), cal_slew);
                            //FAPI_ERR("ctl_reg=0x%04X, status=0x%04X on %s!",
                            //     stat_reg.getHalfWord(3),
                            //     ctl_reg.getHalfWord(3),
                            //     i_target_mba.toEcmdString());

                            if (cal_status == 1)
                            {
                                if (l_port == 0)
                                {
                                    FAPI_ASSERT(false,
                                                fapi2::CEN_MSS_SLEW_CAL_ERROR_PORT0().
                                                set_DATA_ADR(data_adr).
                                                set_IMP(imp).
                                                set_SLEW(slew).
                                                set_MBA_IN_ERROR(i_target_mba).
                                                set_STAT_REG(stat_reg),
                                                "Error occurred during slew calibration on port 0");
                                }
                                else
                                {
                                    FAPI_ASSERT(false,
                                                fapi2::CEN_MSS_SLEW_CAL_ERROR_PORT1().
                                                set_DATA_ADR(data_adr).
                                                set_IMP(imp).
                                                set_SLEW(slew).
                                                set_MBA_IN_ERROR(i_target_mba).
                                                set_STAT_REG(stat_reg),
                                                "Error occurred during slew calibration on port 1");
                                }
                            }
                            else
                            {
                                if (l_port == 0)
                                {
                                    FAPI_ASSERT(false,
                                                fapi2::CEN_MSS_SLEW_CAL_TIMEOUT_PORT0().
                                                set_DATA_ADR(data_adr).
                                                set_IMP(imp).
                                                set_SLEW(slew).
                                                set_MBA_IN_ERROR(i_target_mba).
                                                set_STAT_REG(stat_reg),
                                                "Slew calibration timed out on port 0, loop=%i", poll_count);
                                }
                                else
                                {
                                    FAPI_ASSERT(false,
                                                fapi2::CEN_MSS_SLEW_CAL_TIMEOUT_PORT1().
                                                set_DATA_ADR(data_adr).
                                                set_IMP(imp).
                                                set_SLEW(slew).
                                                set_MBA_IN_ERROR(i_target_mba).
                                                set_STAT_REG(stat_reg),
                                                "Slew calibration timed out on port 1, loop=%i",
                                                poll_count);
                                }
                            }

                            array_rcs[l_port] = rc;
                            continue;
                        }
                    } // end error check
                } // end slew
            } // end imp
        } // end data_adr

        // disable calibration engine for port
        ctl_reg.clearBit(ENABLE_BIT);
        FAPI_TRY(fapi2::putScom(i_target_mba, slew_cal_cntl[l_port], ctl_reg), "Error disabling slew calibration engine in "
                 "DDRPHY_ADR_SLEW_CAL_CNTL register.");
        FAPI_INF("Finished slew calibration on port %i: "
                 "disabling cal engine\n", l_port);
    } // end port loop

    for (uint8_t rn = 0; rn < MAX_PORTS_PER_MBA; rn++)
    {
        if (array_rcs[rn] != fapi2::FAPI2_RC_SUCCESS)
        {
            FAPI_ERR("Returning ERROR RC for port %u", rn);
            return array_rcs[rn];
        }
    }

    FAPI_INF("Setting output slew tables ATTR_CEN_MSS_SLEW_RATE_DATA/ADR\n");
    // ATTR_CEN_MSS_SLEW_RATE_DATA [2][4][4]    port, imped, slew_rate
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_SLEW_RATE_DATA, i_target_mba, calibrated_slew[0]),
             "Failed to set attribute: ATTR_CEN_MSS_SLEW_RATE_DATA");
    // ATTR_CEN_MSS_SLEW_RATE_ADR [2][4][4]     port, imped, slew_rate
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_SLEW_RATE_ADR, i_target_mba, calibrated_slew[1]),
             "Failed to set attribute: ATTR_CEN_MSS_SLEW_RATE_ADR");

    /******************************************************************************/

    // Get desired dq/dqs slew rate & impedance from attribute
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CEN_SLEW_RATE_DQ_DQS, i_target_mba,
                           slew_imp_val[SLEW_TYPE_DATA][SLEW]), "Failed to get attribute: ATTR_CEN_EFF_CEN_SLEW_RATE_DQ_DQS");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS, i_target_mba,
                           slew_imp_val[SLEW_TYPE_DATA][IMP]), "Failed to get attribute: ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS");

    // convert enum value to actual ohms.
    for (uint8_t j = 0; j < MAX_PORTS_PER_MBA; j++)
    {
//      FAPI_INF("DQ_DQS IMP Attribute[%i] = %u", j,
//              slew_imp_val[SLEW_TYPE_DATA][IMP][j]);

        switch (slew_imp_val[SLEW_TYPE_DATA][IMP][j])
        {
            case fapi2::ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM24_FFE0:
                slew_imp_val[SLEW_TYPE_DATA][IMP][j] = 24;
                break;

            case fapi2::ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM30_FFE0:
            case fapi2::ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM30_FFE480:
            case fapi2::ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM30_FFE240:
            case fapi2::ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM30_FFE160:
            case fapi2::ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM30_FFE120:
                slew_imp_val[SLEW_TYPE_DATA][IMP][j] = 30;
                break;

            case fapi2::ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE0:
            case fapi2::ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE480:
            case fapi2::ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE240:
            case fapi2::ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE160:
            case fapi2::ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM34_FFE120:
                slew_imp_val[SLEW_TYPE_DATA][IMP][j] = 34;
                break;

            case fapi2::ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE0:
            case fapi2::ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE480:
            case fapi2::ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE240:
            case fapi2::ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE160:
            case fapi2::ENUM_ATTR_CEN_EFF_CEN_DRV_IMP_DQ_DQS_OHM40_FFE120:
                slew_imp_val[SLEW_TYPE_DATA][IMP][j] = 40;
                break;

            default:
                FAPI_INF("WARNING: EFF_CEN_DRV_IMP_DQ_DQS attribute "
                         "invalid, using value of 0");
        }

//      FAPI_DBG("switched imp to value of %u",
//              slew_imp_val[SLEW_TYPE_DATA][IMP][j]);
    }

    // Get desired ADR control slew rate & impedance from attribute
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_SLEW_RATE_CNTL, i_target_mba,
                           slew_imp_val[SLEW_TYPE_ADR_CNTL][SLEW]), "Failed to get attribute: ATTR_CEN_VPD_SLEW_RATE_CNTL");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DRV_IMP_CNTL, i_target_mba,
                           slew_imp_val[SLEW_TYPE_ADR_CNTL][IMP]), "Failed to get attribute: ATTR_CEN_VPD_DRV_IMP_CNTL");
    // Get desired ADR command slew rate & impedance from attribute
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_SLEW_RATE_ADDR, i_target_mba,
                           slew_imp_val[SLEW_TYPE_ADR_ADDR][SLEW]), "Failed to get attribute: ATTR_CEN_VPD_SLEW_RATE_ADDR");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DRV_IMP_ADDR, i_target_mba,
                           slew_imp_val[SLEW_TYPE_ADR_ADDR][IMP]), "Failed to get attribute: ATTR_CEN_VPD_DRV_IMP_ADDR");
    // Get desired ADR clock slew rate & impedance from attribute
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_SLEW_RATE_CLK, i_target_mba,
                           slew_imp_val[SLEW_TYPE_ADR_CLK][SLEW]), "Failed to get attribute: ATTR_CEN_VPD_SLEW_RATE_CLK");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DRV_IMP_CLK, i_target_mba,
                           slew_imp_val[SLEW_TYPE_ADR_CLK][IMP]), "Failed to get attribute: ATTR_CEN_VPD_DRV_IMP_CLK");
    // Get desired ADR Spare clock slew rate & impedance from attribute
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_SLEW_RATE_SPCKE, i_target_mba,
                           slew_imp_val[SLEW_TYPE_ADR_SPCKE][SLEW]), "Failed to get attribute: ATTR_CEN_VPD_SLEW_RATE_SPCKE");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DRV_IMP_SPCKE, i_target_mba,
                           slew_imp_val[SLEW_TYPE_ADR_SPCKE][IMP]), "Failed to get attribute: ATTR_CEN_VPD_DRV_IMP_SPCKE");

    for (uint8_t l_port = 0; l_port < MAX_PORTS_PER_MBA; l_port++)
    {
        //uint8_t ports_mask = 0xF0;  // bits 0:3 = port0, bits 4:7 = port1
        uint8_t port_val = (ports_valid & (0xF0 >> (4 * l_port)));

        if (port_val == 0)
        {
            FAPI_INF("WARNING:  port %u is invalid from "
                     "ATTR_CEN_MSS_EFF_DIMM_FUNCTIONAL_VECTOR, 0x%02x "
                     "skipping configuration of slew rate on this port",
                     l_port, ports_valid);
            continue;
        }

        FAPI_INF("Setting slew registers for port %i", l_port);

        for (uint8_t slew_type = 0; slew_type < MAX_NUM_SLEW_TYPES; slew_type++)
        {
            fapi2::ReturnCode config_rc =
                config_slew_rate(i_target_mba, l_port, slew_type,
                                 slew_imp_val[slew_type][IMP][l_port],
                                 slew_imp_val[slew_type][SLEW][l_port]);

            if (config_rc)
            {
                array_rcs[l_port] = config_rc;
            }
        }
    }

    for (uint8_t rn = 0; rn < MAX_PORTS_PER_MBA; rn++)
    {
        if (array_rcs[rn] != fapi2::FAPI2_RC_SUCCESS)
        {
            FAPI_ERR("Returning ERROR RC for port %u", rn);
            return array_rcs[rn];
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}
