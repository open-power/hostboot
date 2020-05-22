/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_ddr4_pda.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
/// @file mss_ddr4_pda.C
/// @brief Tools for DDR4 DIMMs centaur procedures
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Steve Glancy <sglancy@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
///

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <fapi2.H>
#include <generic/memory/lib/utils/c_str.H>
#include <p9c_mss_ddr4_pda.H>
#include <p9c_mss_funcs.H>
#include <p9c_mss_ddr4_funcs.H>
#include <cen_gen_scom_addresses.H>
#include <dimmConsts.H>
#include <p9c_mss_access_delay_reg.H>
#include <algorithm>
using namespace std;
extern "C" {
    ///
    /// @brief PDA_Scom_Storage constructor
    /// @param[in] sa  Scom Address
    /// @param[in] sb  Start Bit
    /// @param[in] nb  Num Bits
    ///
    PDA_Scom_Storage::PDA_Scom_Storage(const uint64_t sa, const uint32_t sb, const uint32_t nb)
    {
        scom_addr = sa;
        start_bit = sb;
        num_bits = nb;
    }

    ///
    /// @brief PDA_MRS_Storage class constructor
    /// @param[in] ad  Attribute Data
    /// @param[in] an  Attribute Name
    /// @param[in] dr  DRAM
    /// @param[in] di  DIMM
    /// @param[in] r   Rank
    /// @param[in] p   Port
    /// @param[in] i_odt_wr nominal write ODT settings
    ///
    PDA_MRS_Storage::PDA_MRS_Storage(const uint8_t ad, const uint32_t an, const uint8_t dr, const uint8_t di,
                                     const uint8_t r, const uint8_t p,
                                     const uint8_t (&i_odt_wr)[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM])
    {
        attribute_data = ad;
        attribute_name = an;
        dram = dr;
        dimm = di;
        rank = r;
        port = p;
        MRS = 0xFF;
        pda_string[0] = '\0';

        std::copy(&i_odt_wr[0][0][0],
                  &i_odt_wr[0][0][0] + (MAX_PORTS_PER_MBA * MAX_DIMM_PER_PORT * MAX_RANKS_PER_DIMM),
                  &odt_wr[0][0][0]);
    }

    ///
    /// @brief Generates the string
    ///
    void PDA_MRS_Storage::generatePDAString()
    {
        snprintf(pda_string, sizeof(pda_string),
                 "NAME 0x%08x DATA 0x%02x MRS %d P %d DI %d R %d DR %d", attribute_name, attribute_data, MRS, port,
                 dimm, rank, dram);
    }

    ///
    /// @brief sends out the string
    /// @return pda string
    ///
    char* PDA_MRS_Storage::c_str()
    {
        //generate new string
        generatePDAString(); //note using a separate function here in case some other function would need to call the generation of the string
        return pda_string;
    }

    ///
    /// @brief Checks to make sure that
    /// @param[in] i_target MBA target
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode PDA_MRS_Storage::checkPDAValid(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        uint8_t num_ranks[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t dram_stack[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t num_spares[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM] = {0};
        uint8_t dram_width = 0;
        uint8_t num_spare = 0;
        uint8_t num_dram = 0;

        //checks constants first
        //ports out of range
        FAPI_ASSERT(port < MAX_PORTS_PER_MBA,
                    fapi2::CEN_MSS_PDA_DRAM_DNE().
                    set_MBA_TARGET(i_target).
                    set_PORT_VALUE(port).
                    set_DIMM_VALUE(dimm).
                    set_RANK_VALUE(rank).
                    set_DRAM_VALUE(dram),
                    "ERROR!! Port out of valid range! Exiting...");

        //DIMMs out of range
        FAPI_ASSERT(dimm < MAX_DIMM_PER_PORT,
                    fapi2::CEN_MSS_PDA_DRAM_DNE().
                    set_MBA_TARGET(i_target).
                    set_PORT_VALUE(port).
                    set_DIMM_VALUE(dimm).
                    set_RANK_VALUE(rank).
                    set_DRAM_VALUE(dram),
                    "ERROR!! DIMM out of valid range! Exiting...");

        //now checks based upon attributes
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_STACK_TYPE, i_target, dram_stack));

        //get num master ranks per dimm for 3DS
        if(dram_stack[0][0] == fapi2::ENUM_ATTR_CEN_EFF_STACK_TYPE_STACK_3DS)
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM, i_target, num_ranks));
        }
        //get num ranks per dimm for non-3DS
        else
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_RANKS_PER_DIMM, i_target, num_ranks));
        }

        //no ranks on the selected dimm
        FAPI_ASSERT(num_ranks[port][dimm] != 0,
                    fapi2::CEN_MSS_PDA_DRAM_DNE().
                    set_MBA_TARGET(i_target).
                    set_PORT_VALUE(port).
                    set_DIMM_VALUE(dimm).
                    set_RANK_VALUE(rank).
                    set_DRAM_VALUE(dram),
                    "ERROR!! DIMM has no valid ranks! Exiting...");

        //rank is out of range
        FAPI_ASSERT(num_ranks[port][dimm] > rank,
                    fapi2::CEN_MSS_PDA_DRAM_DNE().
                    set_MBA_TARGET(i_target).
                    set_PORT_VALUE(port).
                    set_DIMM_VALUE(dimm).
                    set_RANK_VALUE(rank).
                    set_DRAM_VALUE(dram),
                    "ERROR!! Rank is out of bounds! Exiting...");

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DIMM_SPARE, i_target, num_spares));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_target, dram_width));

        if(num_spares[port][dimm][rank] == fapi2::ENUM_ATTR_CEN_VPD_DIMM_SPARE_LOW_NIBBLE)
        {
            num_spare = 1;
        }

        if(num_spares[port][dimm][rank] == fapi2::ENUM_ATTR_CEN_VPD_DIMM_SPARE_HIGH_NIBBLE)
        {
            num_spare = 1;
        }

        if(num_spares[port][dimm][rank] == fapi2::ENUM_ATTR_CEN_VPD_DIMM_SPARE_FULL_BYTE
           && dram_width == fapi2::ENUM_ATTR_CEN_EFF_DRAM_WIDTH_X4)
        {
            num_spare = 2;
        }

        if(num_spares[port][dimm][rank] == fapi2::ENUM_ATTR_CEN_VPD_DIMM_SPARE_FULL_BYTE
           && dram_width == fapi2::ENUM_ATTR_CEN_EFF_DRAM_WIDTH_X8)
        {
            num_spare = 1;
        }

        num_dram = ISDIMM_MAX_DQ_72 / dram_width + num_spare;

        FAPI_ASSERT(num_dram > dram,
                    fapi2::CEN_MSS_PDA_DRAM_DNE().
                    set_MBA_TARGET(i_target).
                    set_PORT_VALUE(port).
                    set_DIMM_VALUE(dimm).
                    set_RANK_VALUE(rank).
                    set_DRAM_VALUE(dram),
                    "ERROR!! DRAM is out of bounds! Exiting...");

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief sets the MRS variable based upon the inputted attribute name
    /// @param[in] i_target Centaur MBA target
    /// @return FAPI2_RC_SUCCESS
    ///
    fapi2::ReturnCode PDA_MRS_Storage::setMRSbyAttr(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
    {
        switch(attribute_name)
        {
            //MRS0
            case fapi2::ATTR_CEN_EFF_DRAM_BL:
                MRS = MRS0_BA;
                break;

            case fapi2::ATTR_CEN_EFF_DRAM_RBT:
                MRS = MRS0_BA;
                break;

            case fapi2::ATTR_CEN_EFF_DRAM_CL:
                MRS = MRS0_BA;
                break;

            case fapi2::ATTR_CEN_EFF_DRAM_TM:
                MRS = MRS0_BA;
                break;

            case fapi2::ATTR_CEN_EFF_DRAM_DLL_RESET:
                MRS = MRS0_BA;
                break;

            case fapi2::ATTR_CEN_EFF_DRAM_WR:
                MRS = MRS0_BA;
                break;

            case fapi2::ATTR_CEN_EFF_DRAM_TRTP:
                MRS = MRS0_BA;
                break;

            case fapi2::ATTR_CEN_EFF_DRAM_DLL_PPD:
                MRS = MRS0_BA;
                break;

            //MRS1
            case fapi2::ATTR_CEN_EFF_DRAM_DLL_ENABLE:
                MRS = MRS1_BA;
                break;

            case fapi2::ATTR_CEN_VPD_DRAM_RON:
                MRS = MRS1_BA;
                break;

            case fapi2::ATTR_CEN_VPD_DRAM_RTT_NOM:
                MRS = MRS1_BA;
                break;

            case fapi2::ATTR_CEN_EFF_DRAM_AL:
                MRS = MRS1_BA;
                break;

            case fapi2::ATTR_CEN_EFF_DRAM_WR_LVL_ENABLE:
                MRS = MRS1_BA;
                break;

            case fapi2::ATTR_CEN_EFF_DRAM_TDQS:
                MRS = MRS1_BA;
                break;

            case fapi2::ATTR_CEN_EFF_DRAM_OUTPUT_BUFFER:
                MRS = MRS1_BA;
                break;

            //MRS2
            case fapi2::ATTR_CEN_EFF_DRAM_LPASR:
                MRS = MRS2_BA;
                break;

            case fapi2::ATTR_CEN_EFF_DRAM_CWL:
                MRS = MRS2_BA;
                break;

            case fapi2::ATTR_CEN_VPD_DRAM_RTT_WR:
                MRS = MRS2_BA;
                break;

            case fapi2::ATTR_CEN_EFF_WRITE_CRC:
                MRS = MRS2_BA;
                break;

            //MRS3
            case fapi2::ATTR_CEN_EFF_MPR_MODE:
                MRS = MRS3_BA;
                break;

            case fapi2::ATTR_CEN_EFF_MPR_PAGE:
                MRS = MRS3_BA;
                break;

            case fapi2::ATTR_CEN_EFF_GEARDOWN_MODE:
                MRS = MRS3_BA;
                break;

            case fapi2::ATTR_CEN_EFF_PER_DRAM_ACCESS:
                MRS = MRS3_BA;
                break;

            case fapi2::ATTR_CEN_EFF_TEMP_READOUT:
                MRS = MRS3_BA;
                break;

            case fapi2::ATTR_CEN_EFF_FINE_REFRESH_MODE:
                MRS = MRS3_BA;
                break;

            case fapi2::ATTR_CEN_EFF_CRC_WR_LATENCY:
                MRS = MRS3_BA;
                break;

            case fapi2::ATTR_CEN_EFF_MPR_RD_FORMAT:
                MRS = MRS3_BA;
                break;

            //MRS4
            case fapi2::ATTR_CEN_EFF_MAX_POWERDOWN_MODE:
                MRS = MRS4_BA;
                break;

            case fapi2::ATTR_CEN_EFF_TEMP_REF_RANGE:
                MRS = MRS4_BA;
                break;

            case fapi2::ATTR_CEN_EFF_TEMP_REF_MODE:
                MRS = MRS4_BA;
                break;

            case fapi2::ATTR_CEN_EFF_INT_VREF_MON:
                MRS = MRS4_BA;
                break;

            case fapi2::ATTR_CEN_EFF_CS_CMD_LATENCY:
                MRS = MRS4_BA;
                break;

            case fapi2::ATTR_CEN_EFF_SELF_REF_ABORT:
                MRS = MRS4_BA;
                break;

            case fapi2::ATTR_CEN_EFF_RD_PREAMBLE_TRAIN:
                MRS = MRS4_BA;
                break;

            case fapi2::ATTR_CEN_EFF_RD_PREAMBLE:
                MRS = MRS4_BA;
                break;

            case fapi2::ATTR_CEN_EFF_WR_PREAMBLE:
                MRS = MRS4_BA;
                break;


            //MRS5
            case fapi2::ATTR_CEN_EFF_CA_PARITY_LATENCY :
                MRS = MRS5_BA;
                break;

            case fapi2::ATTR_CEN_EFF_CRC_ERROR_CLEAR :
                MRS = MRS5_BA;
                break;

            case fapi2::ATTR_CEN_EFF_CA_PARITY_ERROR_STATUS :
                MRS = MRS5_BA;
                break;

            case fapi2::ATTR_CEN_EFF_ODT_INPUT_BUFF :
                MRS = MRS5_BA;
                break;

            case fapi2::ATTR_CEN_VPD_DRAM_RTT_PARK :
                MRS = MRS5_BA;
                break;

            case fapi2::ATTR_CEN_EFF_CA_PARITY :
                MRS = MRS5_BA;
                break;

            case fapi2::ATTR_CEN_EFF_DATA_MASK :
                MRS = MRS5_BA;
                break;

            case fapi2::ATTR_CEN_EFF_WRITE_DBI :
                MRS = MRS5_BA;
                break;

            case fapi2::ATTR_CEN_EFF_READ_DBI :
                MRS = MRS5_BA;
                break;

            //MRS6
            case fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_VALUE:
                MRS = MRS6_BA;
                break;

            case fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_RANGE:
                MRS = MRS6_BA;
                break;

            case fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE:
                MRS = MRS6_BA;
                break;

            case fapi2::ATTR_CEN_TCCD_L:
                MRS = MRS6_BA;
                break;

            //MRS attribute not found, error out
            default:
                FAPI_ASSERT(false,
                            fapi2::CEN_MSS_PDA_NONMRS_ATTR_NAME().
                            set_NONMRS_ATTR_NAME(attribute_name).
                            set_MBA_TARGET(i_target),
                            "ERROR!! Found attribute name not associated with an MRS! Exiting...");
        }

    fapi_try_exit:
        return fapi2::current_err;
    }//end setMRSbyAttr

    ///
    /// @brief PDA_MRS_Storage class destructor
    ///
    PDA_MRS_Storage::~PDA_MRS_Storage() {}

    ///
    /// @brief PDA_MRS_Storage greater than operator
    /// @param[in] PDA2 - PDA instance
    /// @return DRAM/port/dimm/rank/mrs/attribute name for A is greater than B return true else false
    ///
    bool PDA_MRS_Storage::operator> (const PDA_MRS_Storage& PDA2) const
    {
        //check on the DRAM first
        //DRAM for A is greater than B return true
        if(dram > PDA2.dram)
        {
            return true;
        }
        //B > A -> false
        else if(dram < PDA2.dram)
        {
            return false;
        }
        //B == A, so go to port
        //A > B -> true
        else if(port > PDA2.port)
        {
            return true;
        }
        //A < B -> false
        else if(port < PDA2.port)
        {
            return false;
        }
        //ports are equal, so start comparing dimms
        //A > B -> true
        else if(dimm > PDA2.dimm)
        {
            return true;
        }
        //A < B -> false
        else if(dimm < PDA2.dimm)
        {
            return false;
        }
        //dimms are equal, so start comparing ranks
        //A > B -> true
        else if(rank > PDA2.rank)
        {
            return true;
        }
        //A < B -> false
        else if(rank < PDA2.rank)
        {
            return false;
        }
        //ports are equal, so start comparing the MRS number
        //A > B -> true
        else if(MRS > PDA2.MRS)
        {
            return true;
        }
        //A < B -> false
        else if(MRS < PDA2.MRS)
        {
            return false;
        }
        //ports are equal, so start comparing the attribute_name
        //A > B -> true
        else if(attribute_name > PDA2.attribute_name)
        {
            return true;
        }
        //A < B -> false
        else if(attribute_name < PDA2.attribute_name)
        {
            return false;
        }
        //ports are equal, so start comparing the attribute_data
        //A > B -> true
        else if(attribute_data > PDA2.attribute_data)
        {
            return true;
        }

        //equal or less than
        return false;
    }//end operator>

    ///
    /// @brief PDA_MRS_Storage less than operator
    /// @param[in] PDA2 - PDA instance
    /// @return DRAM/port/dimm/rank/mrs/attribute name for A is less than B return true else false
    ///
    bool PDA_MRS_Storage::operator< (const PDA_MRS_Storage& PDA2) const
    {
        //check on the DRAM first
        //DRAM for A is less than B return true
        if(dram < PDA2.dram)
        {
            return true;
        }
        //B < A -> false
        else if(dram > PDA2.dram)
        {
            return false;
        }
        //B == A, so go to port
        //A < B -> true
        else if(port < PDA2.port)
        {
            return true;
        }
        //A > B -> false
        else if(port > PDA2.port)
        {
            return false;
        }
        //ports are equal, so start comparing dimms
        //A < B -> true
        else if(dimm < PDA2.dimm)
        {
            return true;
        }
        //A > B -> false
        else if(dimm > PDA2.dimm)
        {
            return false;
        }
        //dimms are equal, so start comparing ranks
        //A < B -> true
        else if(rank < PDA2.rank)
        {
            return true;
        }
        //A > B -> false
        else if(rank > PDA2.rank)
        {
            return false;
        }
        //ports are equal, so start comparing the MRS number
        //A < B -> true
        else if(MRS < PDA2.MRS)
        {
            return true;
        }
        //A > B -> false
        else if(MRS > PDA2.MRS)
        {
            return false;
        }
        //ports are equal, so start comparing the attribute_name
        //A < B -> true
        else if(attribute_name < PDA2.attribute_name)
        {
            return true;
        }
        //A > B -> false
        else if(attribute_name > PDA2.attribute_name)
        {
            return false;
        }
        //ports are equal, so start comparing the attribute_data
        //A < B -> true
        else if(attribute_data < PDA2.attribute_data)
        {
            return true;
        }

        //equal or greater than
        return false;
    }//end operator<

    ///
    /// @brief copies one PDA_MRS_Storage to this one
    /// @param[in] temp MRS storage data structure
    ///
    void PDA_MRS_Storage::copy(PDA_MRS_Storage& temp)
    {
        attribute_data = temp.attribute_data;
        attribute_name = temp.attribute_name;
        MRS            = temp.MRS           ;
        dram           = temp.dram          ;
        dimm           = temp.dimm          ;
        rank           = temp.rank          ;
        port           = temp.port          ;
        std::copy(&odt_wr[0][0][0],
                  &odt_wr[0][0][0] + (MAX_PORTS_PER_MBA * MAX_DIMM_PER_PORT * MAX_RANKS_PER_DIMM),
                  &temp.odt_wr[0][0][0]);
    }

    ///
    /// @brief Checks the passed in PDA vector to ensure that all entries are good. then sorts the vector to ensure more efficient command stream
    /// @param[in]  i_target:  Reference to centaur.mba target,
    /// @param[in/out]  io_pda:  Vector of PDA_MRS_Storage class elements - initialized by the user and contains DRAM information and attribute override information
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode mss_ddr4_checksort_pda(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            vector<PDA_MRS_Storage>& io_pda)
    {
        //does the check to make sure all given attributes are associated with an MRS
        for(auto& pda : io_pda)
        {
            FAPI_TRY(pda.setMRSbyAttr(i_target));
            FAPI_TRY(pda.checkPDAValid(i_target));
        }

        //does the sort, sorting by the class comparator (should be DRAM first)
        sort(io_pda.begin(), io_pda.end());

    fapi_try_exit:
        return fapi2::current_err;
    }


    ///
    /// @brief sets up per-DRAM addressability funcitonality on both ports on the passed MBA
    /// @param[in] i_target Centaur input mba
    /// @param[in/out] io_ccs_inst_cnt CCS instance number
    /// @param[in] i_dimm Centaur dimm to run
    /// @param[in] i_rank Centaur rank to run
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode mss_ddr4_setup_pda(
        const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
        uint32_t& io_ccs_inst_cnt,
        const uint8_t i_dimm,
        const uint8_t i_rank)
    {
        uint32_t l_port_number = 0;
        uint32_t dimm_number = i_dimm;
        uint32_t rank_number = i_rank;
        // Increased polling parameters to avoid CCS hung errors in HB
        const uint32_t NUM_POLL = 10000;
        const uint32_t WAIT_TIMER = 1500;
        uint64_t reg_address = 0;
        fapi2::buffer<uint64_t> data_buffer;
        fapi2::variable_buffer address_16(16);
        fapi2::variable_buffer bank_3(3);
        fapi2::variable_buffer activate_1(1);
        fapi2::variable_buffer rasn_1(1);
        fapi2::variable_buffer casn_1(1);
        fapi2::variable_buffer wen_1(1);
        fapi2::variable_buffer cke_4(4);
        fapi2::variable_buffer csn_8(8);
        fapi2::variable_buffer odt_4(4);
        fapi2::variable_buffer ddr_cal_type_4(4);
        fapi2::variable_buffer num_idles_16(16);
        fapi2::variable_buffer num_repeat_16(16);
        fapi2::variable_buffer data_20(20);
        fapi2::variable_buffer read_compare_1(1);
        fapi2::variable_buffer rank_cal_4(4);
        fapi2::variable_buffer ddr_cal_enable_1(1);
        fapi2::variable_buffer ccs_end_1(1);
        fapi2::variable_buffer mrs3(16);
        uint16_t MRS3 = 0;
        uint8_t num_ranks_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0}; //[port][dimm]
        uint8_t dram_stack[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t dimm_type = 0;
        uint8_t dram_gen = 0;
        uint8_t is_sim = 0;
        uint8_t address_mirror_map[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0}; //address_mirror_map[port][dimm]
        uint8_t mpr_op = 0; // MPR Op
        uint8_t mpr_page = 0; // MPR Page Selection  - NEW
        uint8_t geardown_mode = 0; // Gear Down Mode  - NEW
        uint8_t temp_readout = 0; // Temperature sensor readout  - NEW
        uint8_t fine_refresh = 0; // fine refresh mode  - NEW
        uint8_t wr_latency = 0; // write latency for CRC and DM  - NEW
        uint8_t read_format = 0; // MPR READ FORMAT  - NEW
        uint8_t wl_launch_time = 0;
        uint8_t odt_hold_time = 0;
        uint8_t post_odt_nop_idle = 0;

        FAPI_TRY(activate_1.setBit(0));
        FAPI_TRY(cke_4.setBit(0, 4));
        FAPI_TRY(csn_8.setBit(0, 8));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_STACK_TYPE, i_target, dram_stack));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_TYPE, i_target, dimm_type));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_GEN, i_target, dram_gen));

        //get num master ranks per dimm for 3DS
        if(dram_stack[i_dimm][i_rank] == fapi2::ENUM_ATTR_CEN_EFF_STACK_TYPE_STACK_3DS)
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM, i_target, num_ranks_array));
        }
        //get num ranks per dimm for non-3DS
        else
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_RANKS_PER_DIMM, i_target, num_ranks_array));
        }

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), is_sim));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_ADDRESS_MIRRORING, i_target, address_mirror_map));
        // WORKAROUNDS
        FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_CCS_MODEQ, data_buffer));
        //Setting up CCS mode
        data_buffer.setBit<51>();

        //if in DDR4 mode, count the parity bit and set it
        if((dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4) && (dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_LRDIMM
                || dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_RDIMM) )
        {
            FAPI_TRY(data_buffer.insertFromRight( static_cast<uint8_t>(0xff), 61, 1),
                     "mss_ddr4_setup_pda: Error setting up buffers");
        }

        FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_CCS_MODEQ, data_buffer));

        //loops through port 0 and port 1 on the given MBA
        for(l_port_number = 0; l_port_number < MAX_PORTS_PER_MBA; l_port_number++)
        {
            // Raise CKE high with NOPS, waiting min Reset CKE exit time (tXPR) - 400 cycles
            FAPI_TRY(cke_4.setBit(0, 4));
            FAPI_TRY(csn_8.setBit(0, 8));

            FAPI_TRY(mss_disable_cid(i_target, csn_8, cke_4));

            FAPI_TRY(address_16.clearBit(0, 16), "mss_ddr4_setup_pda: Error setting up buffers");
            FAPI_TRY(odt_4.clearBit(0, 4), "mss_ddr4_setup_pda: Error setting up buffers");
            FAPI_TRY(num_idles_16.insertFromRight(static_cast<uint32_t>(400), 0, 16),
                     "mss_ddr4_setup_pda: Error setting up buffers");

            FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                          io_ccs_inst_cnt,
                                          address_16,
                                          bank_3,
                                          activate_1,
                                          rasn_1,
                                          casn_1,
                                          wen_1,
                                          cke_4,
                                          csn_8,
                                          odt_4,
                                          ddr_cal_type_4,
                                          l_port_number));

            FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                          io_ccs_inst_cnt,
                                          num_idles_16,
                                          num_repeat_16,
                                          data_20,
                                          read_compare_1,
                                          rank_cal_4,
                                          ddr_cal_enable_1,
                                          ccs_end_1));
            io_ccs_inst_cnt ++;
        }

        //Does the RTT_WR to RTT_NOM swapping
        //loops through all ports
        for(l_port_number = 0; l_port_number < MAX_PORTS_PER_MBA; l_port_number++)
        {
            uint8_t io_dram_rtt_nom_original = 0xff;
            FAPI_TRY(mss_ddr4_rtt_nom_rtt_wr_swap(i_target, 0, l_port_number, i_rank + i_dimm * 4, 0xFF, io_ccs_inst_cnt,
                                                  io_dram_rtt_nom_original));
            io_ccs_inst_cnt = 0;
        }


        //Sets up MRS3 -> the MRS that has PDA
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_MPR_MODE, i_target, mpr_op));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_MPR_PAGE, i_target, mpr_page));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_GEARDOWN_MODE, i_target, geardown_mode));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_TEMP_READOUT, i_target, temp_readout));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_FINE_REFRESH_MODE, i_target, fine_refresh));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CRC_WR_LATENCY, i_target, wr_latency));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_MPR_RD_FORMAT, i_target, read_format));

        //enables PDA mode
        //loops through all ports
        for(l_port_number = 0; l_port_number < MAX_PORTS_PER_MBA; l_port_number++)
        {
            // Only corresponding CS to rank
            FAPI_TRY(csn_8.setBit(0, 8));

            FAPI_TRY(mss_disable_cid(i_target, csn_8, cke_4));

            FAPI_TRY(csn_8.clearBit(rank_number + 4 * dimm_number));

            FAPI_TRY(bank_3.insert((uint8_t) MRS3_BA, 0, 1, 7));
            FAPI_TRY(bank_3.insert((uint8_t) MRS3_BA, 1, 1, 6));
            FAPI_TRY(bank_3.insert((uint8_t) MRS3_BA, 2, 1, 5));

            //sets up MRS3 ecmd buffer
            FAPI_TRY(mrs3.insert((uint8_t) mpr_page, 0, 2));
            FAPI_TRY(mrs3.insert((uint8_t) mpr_op, 2, 1));
            FAPI_TRY(mrs3.insert((uint8_t) geardown_mode, 3, 1));
            FAPI_TRY(mrs3.insert((uint8_t) 0xff, 4, 1)); //enables PDA mode!!!!
            FAPI_TRY(mrs3.insert((uint8_t) temp_readout, 5, 1));
            FAPI_TRY(mrs3.insert((uint8_t) fine_refresh, 6, 3));
            FAPI_TRY(mrs3.insert((uint8_t) wr_latency, 9, 2));
            FAPI_TRY(mrs3.insert((uint8_t) read_format, 11, 2));
            FAPI_TRY(mrs3.insert((uint8_t) 0x00, 13, 2));
            FAPI_TRY(mrs3.extract(MRS3, 0, 16));
            FAPI_TRY(num_idles_16.insertFromRight((uint32_t) 24, 0, 16));
            FAPI_TRY(address_16.insert(mrs3, 0, 16, 0));

            if (( address_mirror_map[l_port_number][dimm_number] & (0x08 >> rank_number) ) && (is_sim == 0))
            {
                FAPI_TRY(mss_address_mirror_swizzle(i_target, address_16, bank_3));
            }

            // Send out to the CCS array
            FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                          io_ccs_inst_cnt,
                                          address_16,
                                          bank_3,
                                          activate_1,
                                          rasn_1,
                                          casn_1,
                                          wen_1,
                                          cke_4,
                                          csn_8,
                                          odt_4,
                                          ddr_cal_type_4,
                                          l_port_number));

            FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                          io_ccs_inst_cnt,
                                          num_idles_16,
                                          num_repeat_16,
                                          data_20,
                                          read_compare_1,
                                          rank_cal_4,
                                          ddr_cal_enable_1,
                                          ccs_end_1));
            io_ccs_inst_cnt ++;

            //if the DIMM is an R or LR DIMM, then run inverted for the B-Side DRAM
            if ( (dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_RDIMM)
                 || (dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_LRDIMM) )
            {
                //reload all MRS values (removes address swizzling)
                // Only corresponding CS to rank
                FAPI_TRY(csn_8.setBit(0, 8));

                FAPI_TRY(mss_disable_cid(i_target, csn_8, cke_4));

                FAPI_TRY(csn_8.clearBit(rank_number + 4 * dimm_number));

                FAPI_TRY(bank_3.insert((uint8_t) MRS3_BA, 0, 1, 7), "mss_ddr4_setup_pda: Error setting up buffers");
                FAPI_TRY(bank_3.insert((uint8_t) MRS3_BA, 1, 1, 6), "mss_ddr4_setup_pda: Error setting up buffers");
                FAPI_TRY(bank_3.insert((uint8_t) MRS3_BA, 2, 1, 5), "mss_ddr4_setup_pda: Error setting up buffers");

                //sets up MRS3 ecmd buffer
                FAPI_TRY(address_16.insert(mrs3, 0, 16, 0), "mss_ddr4_setup_pda: Error setting up buffers");

                //FLIPS all necessary bits
                // Indicate B-Side DRAMS BG1=1
                FAPI_TRY(address_16.setBit(15), "mss_ddr4_setup_pda: Error setting up buffers");  // Set BG1 = 1
                FAPI_TRY(address_16.flipBit(3, 7)); // Invert A3:A9
                FAPI_TRY(address_16.flipBit(11));  // Invert A11
                FAPI_TRY(address_16.flipBit(13));  // Invert A13
                FAPI_TRY(address_16.flipBit(14));  // Invert A17
                FAPI_TRY(bank_3.flipBit(0, 3));    // Invert BA0,BA1,BG0

                if (( address_mirror_map[l_port_number][dimm_number] & (0x08 >> rank_number) ) && (is_sim == 0))
                {
                    FAPI_TRY(mss_address_mirror_swizzle(i_target, address_16, bank_3));
                }

                // Send out to the CCS array
                FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                              io_ccs_inst_cnt,
                                              address_16,
                                              bank_3,
                                              activate_1,
                                              rasn_1,
                                              casn_1,
                                              wen_1,
                                              cke_4,
                                              csn_8,
                                              odt_4,
                                              ddr_cal_type_4,
                                              l_port_number));
                FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                              io_ccs_inst_cnt,
                                              num_idles_16,
                                              num_repeat_16,
                                              data_20,
                                              read_compare_1,
                                              rank_cal_4,
                                              ddr_cal_enable_1,
                                              ccs_end_1));
                io_ccs_inst_cnt ++;
            } //if RDIMM or LRDIMM
        } // for each port

        //runs a NOP command for 24 cycle
        FAPI_TRY(num_idles_16.insertFromRight((uint32_t) 24, 0, 16), "mss_ddr4_setup_pda: Error setting up buffers");
        // Raise CKE high with NOPS, waiting min Reset CKE exit time (tXPR) - 400 cycles
        FAPI_TRY(cke_4.setBit(0, 4), "mss_ddr4_setup_pda: Error setting up buffers");
        FAPI_TRY(csn_8.setBit(0, 8), "mss_ddr4_setup_pda: Error setting up buffers");
        FAPI_TRY(address_16.clearBit(0, 16), "mss_ddr4_setup_pda: Error setting up buffers");
        FAPI_TRY(odt_4.clearBit(0, 4), "mss_ddr4_setup_pda: Error setting up buffers");
        FAPI_TRY(num_idles_16.clearBit(0, 16), "mss_ddr4_setup_pda: Error setting up buffers");
        FAPI_TRY(num_idles_16.insertFromRight((uint32_t) 24, 0, 16), "mss_ddr4_setup_pda: Error setting up buffers");
        FAPI_TRY(rasn_1.setBit(0, 1), "mss_ddr4_setup_pda: Error setting up buffers");
        FAPI_TRY(casn_1.setBit(0, 1), "mss_ddr4_setup_pda: Error setting up buffers");
        FAPI_TRY(wen_1.setBit(0, 1), "mss_ddr4_setup_pda: Error setting up buffers");

        FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                      io_ccs_inst_cnt,
                                      address_16,
                                      bank_3,
                                      activate_1,
                                      rasn_1,
                                      casn_1,
                                      wen_1,
                                      cke_4,
                                      csn_8,
                                      odt_4,
                                      ddr_cal_type_4,
                                      l_port_number));

        FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                      io_ccs_inst_cnt,
                                      num_idles_16,
                                      num_repeat_16,
                                      data_20,
                                      read_compare_1,
                                      rank_cal_4,
                                      ddr_cal_enable_1,
                                      ccs_end_1));

        //Setup end bit for CCS
        FAPI_TRY(mss_ccs_set_end_bit (i_target, io_ccs_inst_cnt));

        //Enable CCS and set RAS/CAS/WE high during idles
        FAPI_INF("Enabling CCS\n");
        reg_address = CEN_MBA_CCS_MODEQ;
        FAPI_TRY(fapi2::getScom(i_target, reg_address, data_buffer));

        data_buffer.setBit<29>();    //Enable CCS
        data_buffer.setBit<52>();    //RAS high
        data_buffer.setBit<53>();    //CAS high
        data_buffer.setBit<54>();    //WE high

        //if in DDR4 mode, count the parity bit and set it
        if((dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4) && (dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_LRDIMM
                || dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_RDIMM) )
        {
            FAPI_TRY(data_buffer.insertFromRight( (uint8_t)0xff, 61, 1), "enable ccs setup: Error setting up buffers");
        }

        FAPI_TRY(fapi2::putScom(i_target, reg_address, data_buffer));

        //Execute the CCS array
        FAPI_INF("Executing the CCS array\n");
        FAPI_TRY(mss_execute_ccs_inst_array (i_target, NUM_POLL, WAIT_TIMER));
        io_ccs_inst_cnt = 0;

        //exits PDA
        //loops through the DP18's and sets everything to 1's - no PDA
        for(l_port_number = 0; l_port_number < MAX_PORTS_PER_MBA; l_port_number++)
        {
            for(uint8_t dp18 = 0; dp18 < MAX_BLOCKS_PER_RANK; dp18++)
            {
                reg_address = 0x800000010301143full + 0x0001000000000000ull * l_port_number + 0x0000040000000000ull * (dp18);
                FAPI_TRY(fapi2::getScom(i_target, reg_address, data_buffer));

                FAPI_TRY(data_buffer.setBit(60, 4), "enable ccs setup: Error setting up buffers"); //Enable CCS
                FAPI_TRY(fapi2::putScom(i_target, reg_address, data_buffer));
            }
        }

        //sets up the DRAM DQ drive time
        FAPI_TRY(mss_get_pda_odt_timings(i_target, wl_launch_time, odt_hold_time, post_odt_nop_idle));
        wl_launch_time -= 7;

        FAPI_TRY(fapi2::getScom(i_target,  CEN_MBA_DDRPHY_WC_CONFIG3_P0, data_buffer));
        //Setting up CCS mode
        FAPI_TRY(data_buffer.setBit(48), "mss_ddr4_setup_pda: Error setting up buffers");
        FAPI_TRY(data_buffer.insertFromRight(static_cast<uint8_t>(0x00), 49, 6),
                 "mss_ddr4_setup_pda: Error setting up buffers");
        FAPI_TRY(data_buffer.insertFromRight(static_cast<uint8_t>(0xFF), 55, 6),
                 "mss_ddr4_setup_pda: Error setting up buffers");
        FAPI_TRY(fapi2::putScom(i_target,  CEN_MBA_DDRPHY_WC_CONFIG3_P0, data_buffer));

        FAPI_TRY(fapi2::getScom(i_target,  CEN_MBA_DDRPHY_WC_CONFIG3_P1, data_buffer));
        //Setting up CCS mode
        FAPI_TRY(data_buffer.setBit(48), "mss_ddr4_setup_pda: Error setting up buffers");
        FAPI_TRY(data_buffer.insertFromRight(static_cast<uint8_t>(0x00), 49, 6),
                 "mss_ddr4_setup_pda: Error setting up buffers");
        FAPI_TRY(data_buffer.insertFromRight(static_cast<uint8_t>(0xFF), 55, 6),
                 "mss_ddr4_setup_pda: Error setting up buffers");
        FAPI_TRY(fapi2::putScom(i_target,  CEN_MBA_DDRPHY_WC_CONFIG3_P1, data_buffer));

    fapi_try_exit:
        return fapi2::current_err;
    }// end mss_ddr4_setup_pda


    ///
    /// @brief called by wrapper - sets up a PDA vector if it's not already configured
    /// @param[in]  i_target:  Reference to centaur.mba target,
    /// @param[in]  i_pda:  Vector of PDA_MRS_Storage class elements - initialized by the user and contains DRAM information and attribute override information
    /// @return ReturnCode
    ///
    fapi2::ReturnCode mss_ddr4_pda(
        const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
        vector<PDA_MRS_Storage> i_pda)
    {
        uint8_t dram_loop_end = 0;
        uint8_t dram_loop_end_with_spare = 0;
        FAPI_INF("Commonly used PDA attributes: fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE=0x%08x fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_VALUE=0x%08x",
                 fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_ENABLE, fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_VALUE);
        //gets the rank information
        uint8_t num_ranks_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t dram_stack[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t num_spare[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM] = {0};
        uint8_t wr_vref[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM] = {0};
        uint8_t odt_wr[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM] = {0};
        uint8_t dram_width = 0;
        uint8_t array[][2][19] = {{{0x18, 0x18, 0x1c, 0x1c, 0x18, 0x18, 0x1c, 0x1c, 0x18, 0x1c, 0x18, 0x18, 0x1c, 0x1c, 0x1c, 0x18, 0x1c, 0x18, 0x18}, {0x18, 0x1c, 0x20, 0x1c, 0x20, 0x1c, 0x20, 0x20, 0x1c, 0x1c, 0x20, 0x1c, 0x18, 0x1c, 0x1c, 0x1c, 0x1c, 0x18, 0x18}}, {{0x18, 0x1c, 0x1c, 0x1c, 0x20, 0x1c, 0x20, 0x18, 0x18, 0x18, 0x1c, 0x1c, 0x1c, 0x18, 0x18, 0x1c, 0x18, 0x18, 0x1c}, {0x18, 0x1c, 0x18, 0x1c, 0x20, 0x1c, 0x18, 0x1c, 0x20, 0x1c, 0x1c, 0x1c, 0x1c, 0x24, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c}}};
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_STACK_TYPE, i_target, dram_stack));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_ODT_WR, i_target, odt_wr));

        //get num master ranks per dimm for 3DS
        if(dram_stack[0][0] == fapi2::ENUM_ATTR_CEN_EFF_STACK_TYPE_STACK_3DS)
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM, i_target, num_ranks_array));
        }
        //get num ranks per dimm for non-3DS
        else
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_RANKS_PER_DIMM, i_target, num_ranks_array));
        }

        //gets the spare information
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DIMM_SPARE, i_target, num_spare));

        //gets the WR VREF information
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_VALUE, i_target, wr_vref));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_target, dram_width));

        //sets the loop_end value, to ensure that the proper number of loops are conducted
        if(dram_width == 0x08)
        {
            dram_loop_end = 9;
        }
        //must be a x4 DRAM
        else
        {
            dram_loop_end = 18;
        }

        //if pda is empty then, sets up the vector for the MRS storage
        if(i_pda.size() == 0)
        {
            //loops through each port each dimm each rank each dram and sets everything
            for(uint8_t port = 0; port < MAX_PORTS_PER_MBA; port++)
            {
                for(uint8_t dimm = 0; dimm < MAX_DIMM_PER_PORT; dimm++)
                {
                    for(uint8_t rank = 0; rank < num_ranks_array[port][dimm]; rank++)
                    {
                        //DIMM has a spare, add one DRAM to the loop
                        if(num_spare[port][dimm][rank])
                        {
                            dram_loop_end_with_spare = dram_loop_end + 1;
                        }
                        else
                        {
                            dram_loop_end_with_spare = dram_loop_end;
                        }

                        //loops through all dram
                        for(uint8_t dram = 0; dram < dram_loop_end_with_spare; dram++)
                        {
                            //uint8_t ad,uint32_t an,uint8_t d,uint8_t r,uint8_t
                            if(port == 0)
                            {
                                wr_vref[port][dimm][rank] = dram * 3;
                            }
                            else
                            {
                                wr_vref[port][dimm][rank] = 57 - dram * 3;
                            }

                            if(wr_vref[port][dimm][rank]  > 50)
                            {
                                wr_vref[port][dimm][rank] = 50;
                            }

                            i_pda.push_back(PDA_MRS_Storage(array[port][dimm][dram], fapi2::ATTR_CEN_EFF_VREF_DQ_TRAIN_VALUE, dram, dimm, rank,
                                                            port, odt_wr));
                            FAPI_INF("PDA STRING: %d %s", i_pda.size() - 1, i_pda[i_pda.size() - 1].c_str());
                        }//for each dram
                    }//for each rank
                }//for each dimm
            }//for each port
        }//if pda.size == 0

        FAPI_TRY(mss_ddr4_run_pda(i_target, i_pda));
    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief runs through the vector of given PDA values and issues the PDA commands to the requested DRAMs
    /// @param[in]  i_target:  Reference to centaur.mba target,
    /// @param[in]  i_pda:  Vector of PDA_MRS_Storage class elements - initialized by the user and contains DRAM information and attribute override information
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode mss_ddr4_run_pda(
        const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
        vector<PDA_MRS_Storage> i_pda)
    {
        if(i_pda.size() == 0)
        {
            return fapi2::FAPI2_RC_FALSE;
        }

        uint8_t num_ranks_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0}; //[port][dimm]
        FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM, i_target, num_ranks_array);

        //loops through all DIMMs all Ranks
        for(uint8_t l_dimm = 0; l_dimm < MAX_DIMM_PER_PORT; l_dimm++)
        {
            uint8_t largest_num_ranks = num_ranks_array[0][l_dimm];

            if(largest_num_ranks < num_ranks_array[1][l_dimm])
            {
                largest_num_ranks = num_ranks_array[1][l_dimm];
            }

            for(uint8_t l_rank = 0; l_rank < largest_num_ranks; l_rank++)
            {
                FAPI_INF("Running PDA on DIMM %d Rank %d!!", l_dimm, l_rank);
                FAPI_TRY(mss_ddr4_run_pda_by_dimm_rank(i_target, i_pda, l_dimm, l_rank));
            }
        }

    fapi_try_exit:
        return fapi2::current_err;
    }


    ///
    /// @brief runs per-DRAM addressability funcitonality on both ports on the passed MBA by dimm and rank
    /// @param[in] i_target Centaur input mba
    /// @param[in] i_pda Vector of PDA_MRS_Storage class elements - initialized by the user and contains DRAM information and attribute override information
    /// @param[in] i_dimm Centaur dimm to run
    /// @param[in] i_rank Centaur rank to run
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode mss_ddr4_run_pda_by_dimm_rank(
        const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
        vector<PDA_MRS_Storage> i_pda,
        const uint8_t i_dimm,
        const uint8_t i_rank)
    {
        //no PDA was entered, just exit
        if(i_pda.size() == 0)
        {
            return fapi2::FAPI2_RC_FALSE;
        }

        //DIMM/rank not found - exit
        if(mss_ddr4_check_pda_empty_for_rank(i_pda, i_dimm, i_rank))
        {
            return fapi2::FAPI2_RC_FALSE;
        }

        uint32_t io_ccs_inst_cnt = 0;
        // Increased polling parameters to avoid CCS hung errors in HB
        const uint32_t NUM_POLL = 10000;
        const uint32_t WAIT_TIMER = 1500;
        fapi2::buffer<uint64_t> data_buffer_64;
        fapi2::variable_buffer address_16(16);
        fapi2::variable_buffer address_16_backup(16);
        fapi2::variable_buffer bank_3(3);
        fapi2::variable_buffer bank_3_backup(3);
        fapi2::variable_buffer activate_1(1);
        fapi2::variable_buffer rasn_1(1);
        fapi2::variable_buffer casn_1(1);
        fapi2::variable_buffer wen_1(1);
        fapi2::variable_buffer rasn_1_odt(1);
        fapi2::variable_buffer casn_1_odt(1);
        fapi2::variable_buffer wen_1_odt(1);
        fapi2::variable_buffer num_repeat_16_odt(16);
        fapi2::variable_buffer num_idles_16_odt(16);
        fapi2::variable_buffer csn_8_odt(8);
        fapi2::variable_buffer cke_4(4);
        fapi2::variable_buffer csn_8(8);
        fapi2::variable_buffer odt_4(4);
        fapi2::variable_buffer ddr_cal_type_4(4);
        fapi2::variable_buffer num_idles_16(16);
        fapi2::variable_buffer num_repeat_16(16);
        fapi2::variable_buffer data_20(20);
        fapi2::variable_buffer read_compare_1(1);
        fapi2::variable_buffer rank_cal_4(4);
        fapi2::variable_buffer ddr_cal_enable_1(1);
        fapi2::variable_buffer ccs_end_1(1);
        uint8_t dimm_type = 0;
        uint8_t dram_width = 0;
        uint8_t dram_stack[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        fapi2::buffer<uint64_t> data_buffer;
        uint8_t is_sim = 0;
        uint8_t address_mirror_map[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0}; //address_mirror_map[port][dimm]
        uint8_t wl_launch_time = 0;
        uint8_t odt_hold_time = 0;
        uint8_t post_odt_nop_idle = 0;
        bool prev_dram_set = false;
        vector<PDA_Scom_Storage> scom_storage;
        uint8_t prev_dram = 0;
        uint8_t prev_port = 0;
        uint8_t prev_rank = 0;
        uint8_t prev_dimm = 0;
        uint8_t prev_mrs  = 0;

        FAPI_TRY(activate_1.setBit(0));
        FAPI_TRY(rasn_1_odt.clearBit(0, 1));
        FAPI_TRY(casn_1_odt.clearBit(0, 1));
        FAPI_TRY(wen_1_odt.clearBit(0, 1));
        FAPI_TRY(csn_8_odt.setBit(0, 8));
        FAPI_TRY(csn_8_odt.clearBit(7, 1));
        FAPI_TRY(cke_4.setBit(0, 4));
        FAPI_TRY(csn_8.setBit(0, 8));
        //checks each MRS and saves each
        FAPI_TRY(mss_ddr4_checksort_pda(i_target, i_pda));
        //loads in dram type
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_TYPE, i_target, dimm_type));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_target, dram_width));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_STACK_TYPE, i_target, dram_stack));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), is_sim));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_ADDRESS_MIRRORING, i_target, address_mirror_map));

        FAPI_TRY(mss_ddr4_setup_pda(i_target, io_ccs_inst_cnt, i_dimm, i_rank ));
        FAPI_TRY(mss_get_pda_odt_timings(i_target, wl_launch_time, odt_hold_time, post_odt_nop_idle));
        FAPI_TRY(num_idles_16.insertFromRight((uint32_t) 0, 0, 16));
        FAPI_TRY(num_repeat_16.insertFromRight((uint32_t) 0, 0, 16));
        FAPI_TRY(num_idles_16_odt.insertFromRight( post_odt_nop_idle, 0, 8));
        FAPI_TRY(num_repeat_16_odt.insertFromRight( odt_hold_time, 0, 8));

        FAPI_TRY(cke_4.setBit(0, 4));
        FAPI_TRY(csn_8.setBit(0, 8));
        FAPI_TRY(address_16.clearBit(0, 16));
        FAPI_TRY(odt_4.clearBit(0, 4));
        FAPI_TRY(rasn_1.clearBit(0, 1));
        FAPI_TRY(casn_1.clearBit(0, 1));
        FAPI_TRY(wen_1.clearBit(0, 1));

        //runs through each PDA command
        for(uint32_t i = 0; i < i_pda.size(); i++)
        {
            //did not find a PDA with the same DIMM and rank as requested
            if(i_pda[i].rank != i_rank || i_pda[i].dimm != i_dimm)
            {
                continue;
            }

            //found a PDA of the same dimm and rank, but storage not set
            if(!prev_dram_set)
            {
                //gets the start PDA values
                prev_dram = i_pda[i].dram;
                prev_port = i_pda[i].port;
                prev_rank = i_pda[i].rank;
                prev_dimm = i_pda[i].dimm;
                prev_mrs  = i_pda[i].MRS;
                prev_dram_set = true;

                FAPI_TRY(mss_ddr4_load_nominal_mrs_pda(i_target, bank_3, address_16, prev_mrs, prev_port, prev_dimm, prev_rank));

                scom_storage.clear();
                FAPI_TRY(mss_ddr4_add_dram_pda(i_target, prev_port, prev_dram, scom_storage));
            }

            FAPI_INF("Target %s On PDA %d is %s", mss::c_str(i_target), i, i_pda[i].c_str());

            //dram, port, rank, dimm, and mrs are the same
            if(prev_dram == i_pda[i].dram && prev_port == i_pda[i].port && prev_rank == i_pda[i].rank && prev_dimm == i_pda[i].dimm
               && prev_mrs == i_pda[i].MRS)
            {
                //modifies this attribute
                FAPI_TRY(mss_ddr4_modify_mrs_pda(i_target, address_16, i_pda[i].attribute_name, i_pda[i].attribute_data));
            }
            //another MRS, so set this MRS.  do additional checks to later in the code
            else
            {
                //adds values to a backup address_16 before doing the mirroring
                FAPI_TRY(address_16_backup.clearBit(0, 16));
                FAPI_TRY(address_16_backup.insert(address_16, 0, 16, 0));
                FAPI_TRY(bank_3_backup.clearBit(0, 3));
                FAPI_TRY(bank_3_backup.insert(bank_3, 0, 3, 0));

                //loads the previous DRAM
                if (( address_mirror_map[prev_port][prev_dimm] & (0x08 >> prev_rank) ) && (is_sim == 0))
                {
                    FAPI_TRY(mss_address_mirror_swizzle(i_target, address_16, bank_3));
                }

                // Only corresponding CS to rank
                FAPI_TRY(csn_8.setBit(0, 8));
                FAPI_TRY(csn_8.clearBit(prev_rank + 4 * prev_dimm));

                FAPI_TRY(mss_disable_cid(i_target, csn_8, cke_4));

                FAPI_TRY(odt_4.insert(i_pda[i].odt_wr[prev_port][prev_dimm][prev_rank], 0, 4, 0));
                // Send out to the CCS array
                FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                              io_ccs_inst_cnt,
                                              address_16,
                                              bank_3,
                                              activate_1,
                                              rasn_1,
                                              casn_1,
                                              wen_1,
                                              cke_4,
                                              csn_8,
                                              odt_4,
                                              ddr_cal_type_4,
                                              prev_port));
                FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                              io_ccs_inst_cnt,
                                              num_idles_16,
                                              num_repeat_16,
                                              data_20,
                                              read_compare_1,
                                              rank_cal_4,
                                              ddr_cal_enable_1,
                                              ccs_end_1));
                io_ccs_inst_cnt ++;

                // Send out to the CCS array
                FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                              io_ccs_inst_cnt,
                                              address_16,
                                              bank_3,
                                              activate_1,
                                              rasn_1_odt,
                                              casn_1_odt,
                                              wen_1_odt,
                                              cke_4,
                                              csn_8_odt,
                                              odt_4,
                                              ddr_cal_type_4,
                                              prev_port));
                FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                              io_ccs_inst_cnt,
                                              num_idles_16_odt,
                                              num_repeat_16_odt,
                                              data_20,
                                              read_compare_1,
                                              rank_cal_4,
                                              ddr_cal_enable_1,
                                              ccs_end_1));
                io_ccs_inst_cnt ++;

                //is an R or LR DIMM -> do a B side MRS write
                if ( (dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_RDIMM)
                     || (dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_LRDIMM) )
                {
                    //takes values from the backup
                    FAPI_TRY(address_16.clearBit(0, 16));
                    FAPI_TRY(address_16.insert(address_16_backup, 0, 16, 0));
                    FAPI_TRY(bank_3.clearBit(0, 3));
                    FAPI_TRY(bank_3.insert(bank_3_backup, 0, 3, 0));

                    //FLIPS all necessary bits
                    // Indicate B-Side DRAMS BG1=1
                    FAPI_TRY(address_16.setBit(15));  // Set BG1 = 1

                    FAPI_TRY(address_16.flipBit(3, 7)); // Invert A3:A9
                    FAPI_TRY(address_16.flipBit(11));  // Invert A11
                    FAPI_TRY(address_16.flipBit(13));  // Invert A13
                    FAPI_TRY(address_16.flipBit(14));  // Invert A17
                    FAPI_TRY(bank_3.flipBit(0, 3));    // Invert BA0,BA1,BG0

                    //loads the previous DRAM
                    if (( address_mirror_map[prev_port][prev_dimm] & (0x08 >> prev_rank) ) && (is_sim == 0))
                    {
                        FAPI_TRY(mss_address_mirror_swizzle(i_target, address_16, bank_3));
                    }

                    // Only corresponding CS to rank
                    FAPI_TRY(csn_8.setBit(0, 8));
                    FAPI_TRY(csn_8.clearBit(prev_rank + 4 * prev_dimm));

                    FAPI_TRY(mss_disable_cid(i_target, csn_8, cke_4));

                    FAPI_TRY(odt_4.insert(i_pda[i].odt_wr[prev_port][prev_dimm][prev_rank], 0, 4, 0));

                    // Send out to the CCS array
                    FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                                  io_ccs_inst_cnt,
                                                  address_16,
                                                  bank_3,
                                                  activate_1,
                                                  rasn_1,
                                                  casn_1,
                                                  wen_1,
                                                  cke_4,
                                                  csn_8,
                                                  odt_4,
                                                  ddr_cal_type_4,
                                                  prev_port));
                    FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                                  io_ccs_inst_cnt,
                                                  num_idles_16,
                                                  num_repeat_16,
                                                  data_20,
                                                  read_compare_1,
                                                  rank_cal_4,
                                                  ddr_cal_enable_1,
                                                  ccs_end_1));
                    io_ccs_inst_cnt ++;

                    // Send out to the CCS array
                    FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                                  io_ccs_inst_cnt,
                                                  address_16,
                                                  bank_3,
                                                  activate_1,
                                                  rasn_1_odt,
                                                  casn_1_odt,
                                                  wen_1_odt,
                                                  cke_4,
                                                  csn_8_odt,
                                                  odt_4,
                                                  ddr_cal_type_4,
                                                  prev_port));
                    FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                                  io_ccs_inst_cnt,
                                                  num_idles_16_odt,
                                                  num_repeat_16_odt,
                                                  data_20,
                                                  read_compare_1,
                                                  rank_cal_4,
                                                  ddr_cal_enable_1,
                                                  ccs_end_1));
                    io_ccs_inst_cnt ++;
                }

                //the DRAM are different, so kick off CCS, and clear out the MRS DRAMs and set up a new DRAM
                if(prev_dram != i_pda[i].dram)
                {
                    //sets a NOP as the last command
                    FAPI_TRY(cke_4.setBit(0, 4));
                    FAPI_TRY(csn_8.setBit(0, 8));
                    FAPI_TRY(address_16.clearBit(0, 16));
                    FAPI_TRY(rasn_1.setBit(0, 1));
                    FAPI_TRY(casn_1.setBit(0, 1));
                    FAPI_TRY(wen_1.setBit(0, 1));
                    FAPI_TRY(odt_4.insert((uint8_t) 0, 0, 4, 0));


                    // Send out to the CCS array
                    FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                                  io_ccs_inst_cnt,
                                                  address_16,
                                                  bank_3,
                                                  activate_1,
                                                  rasn_1,
                                                  casn_1,
                                                  wen_1,
                                                  cke_4,
                                                  csn_8,
                                                  odt_4,
                                                  ddr_cal_type_4,
                                                  prev_port));
                    FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                                  io_ccs_inst_cnt,
                                                  num_idles_16,
                                                  num_repeat_16,
                                                  data_20,
                                                  read_compare_1,
                                                  rank_cal_4,
                                                  ddr_cal_enable_1,
                                                  ccs_end_1));
                    io_ccs_inst_cnt ++;

                    //Setup end bit for CCS
                    FAPI_TRY(mss_ccs_set_end_bit (i_target, io_ccs_inst_cnt - 1));

                    //Execute the CCS array
                    FAPI_INF("Executing the CCS array\n");
                    FAPI_TRY(mss_execute_ccs_inst_array (i_target, NUM_POLL, WAIT_TIMER));
                    io_ccs_inst_cnt = 0;

                    // Sets NOP as the first command
                    FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                                  io_ccs_inst_cnt,
                                                  address_16,
                                                  bank_3,
                                                  activate_1,
                                                  rasn_1,
                                                  casn_1,
                                                  wen_1,
                                                  cke_4,
                                                  csn_8,
                                                  odt_4,
                                                  ddr_cal_type_4,
                                                  prev_port));
                    FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                                  io_ccs_inst_cnt,
                                                  num_idles_16,
                                                  num_repeat_16,
                                                  data_20,
                                                  read_compare_1,
                                                  rank_cal_4,
                                                  ddr_cal_enable_1,
                                                  ccs_end_1));
                    io_ccs_inst_cnt ++;

                    FAPI_TRY(cke_4.setBit(0, 4));
                    FAPI_TRY(csn_8.setBit(0, 8));
                    FAPI_TRY(address_16.clearBit(0, 16));
                    FAPI_TRY(rasn_1.clearBit(0, 1));
                    FAPI_TRY(casn_1.clearBit(0, 1));
                    FAPI_TRY(wen_1.clearBit(0, 1));

                    //loops through and clears out the storage class
                    for(const auto& scom : scom_storage)
                    {
                        FAPI_TRY(fapi2::getScom(i_target, scom.scom_addr, data_buffer));

                        FAPI_TRY(data_buffer.setBit(scom.start_bit, scom.num_bits),
                                 "enable ccs setup: Error setting up buffers");  //Enable CCS
                        FAPI_TRY(fapi2::putScom(i_target, scom.scom_addr, data_buffer));
                    }

                    scom_storage.clear();
                    //enables the next dram scom
                    FAPI_TRY(mss_ddr4_add_dram_pda(i_target, i_pda[i].port, i_pda[i].dram, scom_storage));
                }
                //different port but same DRAM, enable the next scom
                else if(prev_port != i_pda[i].port)
                {
                    //enables the next dram scom
                    FAPI_TRY(mss_ddr4_add_dram_pda(i_target, i_pda[i].port, i_pda[i].dram, scom_storage));
                }

                //loads in the nominal MRS for this target
                prev_dram = i_pda[i].dram;
                prev_port = i_pda[i].port;
                prev_rank = i_pda[i].rank;
                prev_dimm = i_pda[i].dimm;
                prev_mrs  = i_pda[i].MRS;

                FAPI_TRY( mss_ddr4_load_nominal_mrs_pda(i_target, bank_3, address_16, prev_mrs, prev_port, prev_dimm, prev_rank));
                //modifies the MRS
                FAPI_TRY(mss_ddr4_modify_mrs_pda(i_target, address_16, i_pda[i].attribute_name, i_pda[i].attribute_data));
            }
        }

        //runs the last PDA command, if and only if a PDA of the desired rank and dimm was run
        if(prev_dram_set)
        {
            //adds values to a backup address_16 before doing the mirroring
            FAPI_TRY(address_16_backup.clearBit(0, 16));
            FAPI_TRY(address_16_backup.insert(address_16, 0, 16, 0));
            FAPI_TRY(bank_3_backup.clearBit(0, 3));
            FAPI_TRY(bank_3_backup.insert(bank_3, 0, 3, 0));
            FAPI_TRY(odt_4.insert(i_pda[0].odt_wr[prev_port][prev_dimm][prev_rank], 0, 4, 0));

            //loads the previous DRAM
            if (( address_mirror_map[prev_port][prev_dimm] & (0x08 >> prev_rank) ) && (is_sim == 0))
            {
                FAPI_TRY(mss_address_mirror_swizzle(i_target, address_16, bank_3));
            }

            // Only corresponding CS to rank
            FAPI_TRY(csn_8.setBit(0, 8));

            FAPI_TRY(mss_disable_cid(i_target, csn_8, cke_4));

            FAPI_TRY(csn_8.clearBit(prev_rank + 4 * prev_dimm));

            // Send out to the CCS array
            FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                          io_ccs_inst_cnt,
                                          address_16,
                                          bank_3,
                                          activate_1,
                                          rasn_1,
                                          casn_1,
                                          wen_1,
                                          cke_4,
                                          csn_8,
                                          odt_4,
                                          ddr_cal_type_4,
                                          prev_port));
            FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                          io_ccs_inst_cnt,
                                          num_idles_16,
                                          num_repeat_16,
                                          data_20,
                                          read_compare_1,
                                          rank_cal_4,
                                          ddr_cal_enable_1,
                                          ccs_end_1));
            io_ccs_inst_cnt ++;

            // Send out to the CCS array
            FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                          io_ccs_inst_cnt,
                                          address_16,
                                          bank_3,
                                          activate_1,
                                          rasn_1_odt,
                                          casn_1_odt,
                                          wen_1_odt,
                                          cke_4,
                                          csn_8_odt,
                                          odt_4,
                                          ddr_cal_type_4,
                                          prev_port));
            FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                          io_ccs_inst_cnt,
                                          num_idles_16_odt,
                                          num_repeat_16_odt,
                                          data_20,
                                          read_compare_1,
                                          rank_cal_4,
                                          ddr_cal_enable_1,
                                          ccs_end_1));
            io_ccs_inst_cnt ++;

            //is an R or LR DIMM -> do a B side MRS write
            if ( (dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_RDIMM)
                 || (dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_LRDIMM) )
            {
                //takes values from the backup
                FAPI_TRY(address_16.clearBit(0, 16));
                FAPI_TRY(address_16.insert(address_16_backup, 0, 16, 0));
                FAPI_TRY(bank_3.clearBit(0, 3));
                FAPI_TRY(bank_3.insert(bank_3_backup, 0, 3, 0));

                //FLIPS all necessary bits
                // Indicate B-Side DRAMS BG1=1
                FAPI_TRY(address_16.setBit(15));  // Set BG1 = 1
                FAPI_TRY(address_16.flipBit(3, 7)); // Invert A3:A9
                FAPI_TRY(address_16.flipBit(11));  // Invert A11
                FAPI_TRY(address_16.flipBit(13));  // Invert A13
                FAPI_TRY(address_16.flipBit(14));  // Invert A17
                FAPI_TRY(bank_3.flipBit(0, 3));    // Invert BA0,BA1,BG0

                //loads the previous DRAM
                if (( address_mirror_map[prev_port][prev_dimm] & (0x08 >> prev_rank) ) && (is_sim == 0))
                {
                    FAPI_TRY(mss_address_mirror_swizzle(i_target, address_16, bank_3));
                }

                // Only corresponding CS to rank
                FAPI_TRY(csn_8.setBit(0, 8));

                FAPI_TRY(mss_disable_cid(i_target, csn_8, cke_4));

                FAPI_TRY(csn_8.clearBit(prev_rank + 4 * prev_dimm));


                // Send out to the CCS array
                FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                              io_ccs_inst_cnt,
                                              address_16,
                                              bank_3,
                                              activate_1,
                                              rasn_1,
                                              casn_1,
                                              wen_1,
                                              cke_4,
                                              csn_8,
                                              odt_4,
                                              ddr_cal_type_4,
                                              prev_port));
                FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                              io_ccs_inst_cnt,
                                              num_idles_16,
                                              num_repeat_16,
                                              data_20,
                                              read_compare_1,
                                              rank_cal_4,
                                              ddr_cal_enable_1,
                                              ccs_end_1));
                io_ccs_inst_cnt ++;

                // Send out to the CCS array
                FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                              io_ccs_inst_cnt,
                                              address_16,
                                              bank_3,
                                              activate_1,
                                              rasn_1_odt,
                                              casn_1_odt,
                                              wen_1_odt,
                                              cke_4,
                                              csn_8_odt,
                                              odt_4,
                                              ddr_cal_type_4,
                                              prev_port));
                FAPI_TRY( mss_ccs_inst_arry_1( i_target,
                                               io_ccs_inst_cnt,
                                               num_idles_16_odt,
                                               num_repeat_16_odt,
                                               data_20,
                                               read_compare_1,
                                               rank_cal_4,
                                               ddr_cal_enable_1,
                                               ccs_end_1));
                io_ccs_inst_cnt ++;
            }
        }

        //sets a NOP as the last command
        FAPI_TRY(cke_4.setBit(0, 4));
        FAPI_TRY(csn_8.setBit(0, 8));
        FAPI_TRY(address_16.clearBit(0, 16));
        FAPI_TRY(rasn_1.setBit(0, 1));
        FAPI_TRY(casn_1.setBit(0, 1));
        FAPI_TRY(wen_1.setBit(0, 1));

        // Send out to the CCS array
        FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                      io_ccs_inst_cnt,
                                      address_16,
                                      bank_3,
                                      activate_1,
                                      rasn_1,
                                      casn_1,
                                      wen_1,
                                      cke_4,
                                      csn_8_odt,
                                      odt_4,
                                      ddr_cal_type_4,
                                      prev_port));
        FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                      io_ccs_inst_cnt,
                                      num_idles_16,
                                      num_repeat_16,
                                      data_20,
                                      read_compare_1,
                                      rank_cal_4,
                                      ddr_cal_enable_1,
                                      ccs_end_1));
        io_ccs_inst_cnt ++;

        //Setup end bit for CCS
        FAPI_TRY(mss_ccs_set_end_bit (i_target, io_ccs_inst_cnt - 1));

        //Execute the CCS array
        FAPI_INF("Executing the CCS array\n");
        FAPI_TRY(mss_execute_ccs_inst_array (i_target, NUM_POLL, WAIT_TIMER));

        //loops through and clears out the storage class
        for(uint32_t scoms = 0; scoms < scom_storage.size(); scoms++)
            for(const auto& scom : scom_storage)
            {
                FAPI_TRY(fapi2::getScom(i_target, scom.scom_addr, data_buffer));

                FAPI_TRY(data_buffer.setBit(scom.start_bit, scom.num_bits),
                         "enable ccs setup: Error setting up buffers");  //Enable CCS
                FAPI_TRY(fapi2::putScom(i_target, scom.scom_addr, data_buffer));
            }

        io_ccs_inst_cnt = 0;
        FAPI_TRY(mss_ddr4_disable_pda(i_target, io_ccs_inst_cnt, i_dimm, i_rank));
    fapi_try_exit:
        return fapi2::current_err;
    }


    ///
    /// @brief Adds a given DRAM into the scom_storage vector
    /// @param[in]  i_target:  Reference to centaur.mba target,
    /// @param[in]  i_port:  identifies which port the given DRAM is on
    /// @param[in]  i_dram:  identifies which DRAM identifier is to be added
    /// @param[in/out]  io_scom_storage:  list of all DRAMs being modified by PDA. contains address, bit, and length
    /// @return ReturnCode
    ///
    fapi2::ReturnCode mss_ddr4_add_dram_pda(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target, const uint8_t i_port,
                                            const uint8_t i_dram,
                                            vector<PDA_Scom_Storage>& io_scom_storage)
    {
        fapi2::buffer<uint64_t> data_buffer;
        //access delay regs function
        uint8_t i_rank_pair = 0;
        input_type_t i_input_type_e = WR_DQ;
        uint8_t i_input_index = 75;
        uint8_t i_verbose = 1;
        uint8_t phy_lane = 6;
        uint8_t phy_block = 6;
        uint8_t flag = 0;
        uint32_t scom_len = 0;
        uint32_t scom_start = 0;
        uint64_t reg_address = 0;
        uint8_t dram_width = 0;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, i_target, dram_width));

        // C4 DQ to lane/block (flag = 0) in PHY or lane/block to C4 DQ (flag = 1)
        // In this case moving from lane/block to C4 DQ to use access_delay_reg
        i_input_index = 4 * i_dram;
        FAPI_TRY( mss_c4_phy(i_target, i_port, i_rank_pair, i_input_type_e, i_input_index, i_verbose, phy_lane, phy_block,
                             flag));

        reg_address = 0x800000010301143full + (0x0001000000000000ull * i_port) + (0x0000040000000000ull * phy_block);

        //gets the lane and number of bits to set to 0's
        if(dram_width == 0x04)
        {
            scom_start = 60 + (uint32_t)(phy_lane / 4);
            scom_len = 1;
        }
        //x8 DIMM
        else
        {
            scom_start = 60 + (uint32_t)((phy_lane / 8) * 2);
            scom_len = 2;
        }

        FAPI_INF("Enabling %016llx start at %d for %d bits for port %d dram %d", reg_address, scom_start, scom_len, i_port,
                 i_dram);

        FAPI_TRY(fapi2::getScom(i_target, reg_address, data_buffer));
        FAPI_TRY(data_buffer.clearBit(scom_start, scom_len));   //Enable CCS
        FAPI_TRY(fapi2::putScom(i_target, reg_address, data_buffer));

        io_scom_storage.push_back(PDA_Scom_Storage(reg_address, scom_start, scom_len));
    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Takes the DRAM out of per-DRAM addressability mode (PDA mode)
    /// @param[in]  target:  Reference to centaur.mba target,
    /// @param[in/out]  io_ccs_inst_cnt: starting point of CCS array - needed to properly setup CCS
    /// @param[in]  i_dimm: which DIMM to run PDA commands on
    /// @param[in]  i_rank: which rank on which DIMM to run PDA commands on
    /// @return ReturnCode
    ///
    fapi2::ReturnCode mss_ddr4_disable_pda(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target, uint32_t& io_ccs_inst_cnt,
                                           const uint8_t i_dimm, const uint8_t i_rank)
    {
        uint32_t l_port_number = 0;
        uint32_t dimm_number = i_dimm;
        uint32_t rank_number = i_rank;
        // Increased polling parameters to avoid CCS hung errors in HB
        const uint32_t NUM_POLL = 10000;
        const uint32_t WAIT_TIMER = 1500;
        uint64_t reg_address = 0;
        fapi2::buffer<uint64_t> data_buffer;
        fapi2::buffer<uint64_t> data_buffer_64;
        fapi2::variable_buffer address_16(16);
        fapi2::variable_buffer bank_3(3);
        fapi2::variable_buffer activate_1(1);
        fapi2::variable_buffer rasn_1(1);
        fapi2::variable_buffer casn_1(1);
        fapi2::variable_buffer wen_1(1);
        fapi2::variable_buffer cke_4(4);
        fapi2::variable_buffer csn_8(8);
        fapi2::variable_buffer odt_4(4);
        fapi2::variable_buffer ddr_cal_type_4(4);

        fapi2::variable_buffer num_idles_16(16);
        fapi2::variable_buffer num_repeat_16(16);
        fapi2::variable_buffer data_20(20);
        fapi2::variable_buffer read_compare_1(1);
        fapi2::variable_buffer rank_cal_4(4);
        fapi2::variable_buffer ddr_cal_enable_1(1);
        fapi2::variable_buffer ccs_end_1(1);

        fapi2::variable_buffer rasn_1_odt(1);
        fapi2::variable_buffer casn_1_odt(1);
        fapi2::variable_buffer wen_1_odt(1);
        fapi2::variable_buffer num_repeat_16_odt(16);
        fapi2::variable_buffer num_idles_16_odt(16);
        fapi2::variable_buffer csn_8_odt(8);
        uint8_t dram_gen = 0;
        fapi2::variable_buffer mrs3(16);
        uint8_t dram_stack[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t dimm_type = 0;
        uint8_t is_sim = 0;
        uint8_t address_mirror_map[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0}; //address_mirror_map[port][dimm]
        uint8_t odt_wr[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM] = {0};
        uint8_t mpr_op = 0; // MPR Op
        uint8_t mpr_page = 0; // MPR Page Selection
        uint8_t geardown_mode = 0; // Gear Down Mode
        uint8_t temp_readout = 0; // Temperature sensor readout
        uint8_t fine_refresh = 0; // fine refresh mode
        uint8_t wr_latency = 0; // write latency for CRC and DM
        uint8_t read_format = 0; // MPR READ FORMAT
        uint8_t wl_launch_time = 0;
        uint8_t odt_hold_time = 0;
        uint8_t post_odt_nop_idle = 0;
        uint8_t io_dram_rtt_nom_original = 0;
        uint16_t MRS3 = 0;

        FAPI_TRY(activate_1.setBit(0));
        FAPI_TRY(cke_4.setBit(0, 4));
        FAPI_TRY(csn_8.setBit(0, 8));
        FAPI_TRY(rasn_1_odt.clearBit(0, 1));
        FAPI_TRY(casn_1_odt.clearBit(0, 1));
        FAPI_TRY(wen_1_odt.clearBit(0, 1));
        FAPI_TRY(csn_8_odt.setBit(0, 8));
        FAPI_TRY(csn_8_odt.clearBit(7, 1));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_GEN, i_target, dram_gen));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_STACK_TYPE, i_target, dram_stack));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_TYPE, i_target, dimm_type));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), is_sim));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_ADDRESS_MIRRORING, i_target, address_mirror_map));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_ODT_WR, i_target, odt_wr));

        // WORKAROUNDS
        FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_CCS_MODEQ, data_buffer));
        //Setting up CCS mode
        data_buffer.setBit<51>();

        //if in DDR4 mode, count the parity bit and set it
        if((dram_gen == fapi2::ENUM_ATTR_CEN_EFF_DRAM_GEN_DDR4) && (dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_LRDIMM
                || dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_RDIMM) )
        {
            FAPI_TRY(data_buffer.insertFromRight( (uint8_t)0xff, 61, 1), "disable ccs setup: Error disabling up buffers");
        }

        FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_CCS_MODEQ, data_buffer));

        //loops through port 0 and port 1 on the given MBA
        for(l_port_number = 0; l_port_number < MAX_PORTS_PER_MBA; l_port_number++)
        {
            // Raise CKE high with NOPS, waiting min Reset CKE exit time (tXPR) - 400 cycles
            FAPI_TRY(cke_4.setBit(0, 4), "disable ccs setup: Error disabling up buffers");
            FAPI_TRY(csn_8.setBit(0, 8), "disable ccs setup: Error disabling up buffers");
            FAPI_TRY(address_16.clearBit(0, 16), "disable ccs setup: Error disabling up buffers");
            FAPI_TRY(odt_4.clearBit(0, 4), "disable ccs setup: Error disabling up buffers");
            FAPI_TRY(num_idles_16.insertFromRight((uint32_t) 400, 0, 16), "disable ccs setup: Error disabling up buffers");
            FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                          io_ccs_inst_cnt,
                                          address_16,
                                          bank_3,
                                          activate_1,
                                          rasn_1,
                                          casn_1,
                                          wen_1,
                                          cke_4,
                                          csn_8,
                                          odt_4,
                                          ddr_cal_type_4,
                                          l_port_number));
            FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                          io_ccs_inst_cnt,
                                          num_idles_16,
                                          num_repeat_16,
                                          data_20,
                                          read_compare_1,
                                          rank_cal_4,
                                          ddr_cal_enable_1,
                                          ccs_end_1));
            io_ccs_inst_cnt ++;
        }


        //Sets up MRS3 -> the MRS that has PDA
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_MPR_MODE, i_target, mpr_op));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_MPR_PAGE, i_target, mpr_page));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_GEARDOWN_MODE, i_target, geardown_mode));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_TEMP_READOUT, i_target, temp_readout));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_FINE_REFRESH_MODE, i_target, fine_refresh));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CRC_WR_LATENCY, i_target, wr_latency));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_MPR_RD_FORMAT, i_target, read_format));


        //sets up the DRAM DQ drive time
        FAPI_TRY(mss_get_pda_odt_timings(i_target, wl_launch_time, odt_hold_time, post_odt_nop_idle));

        FAPI_TRY(num_idles_16.insertFromRight((uint32_t) 0, 0, 16));
        FAPI_TRY(num_repeat_16.insertFromRight((uint32_t) 0, 0, 16));
        FAPI_TRY(num_idles_16_odt.insertFromRight( post_odt_nop_idle, 0, 8));
        FAPI_TRY(num_repeat_16_odt.insertFromRight( odt_hold_time, 0, 8));

        //exits PDA
        for(l_port_number = 0; l_port_number < MAX_PORTS_PER_MBA; l_port_number++)
        {
            //loops through the DP18's and sets everything to 0's
            for(uint8_t dp18 = 0; dp18 < MAX_BLOCKS_PER_RANK; dp18++)
            {
                reg_address = 0x800000010301143full + 0x0001000000000000ull * l_port_number + 0x0000040000000000ull * (dp18);
                FAPI_TRY(fapi2::getScom(i_target, reg_address, data_buffer));
                FAPI_TRY(data_buffer.clearBit(60, 4), "enable ccs setup: Error setting up buffers");  //Enable CCS
                FAPI_TRY(fapi2::putScom(i_target, reg_address, data_buffer));
            }
        }

        //exits PDA
        for(l_port_number = 0; l_port_number < 2; l_port_number++)
        {
            // Only corresponding CS to rank
            FAPI_TRY(csn_8.setBit(0, 8), "mss_mrs_load: Error setting up buffers");

            FAPI_TRY(mss_disable_cid(i_target, csn_8, cke_4));

            FAPI_TRY(csn_8.clearBit(rank_number + 4 * dimm_number));
            FAPI_TRY(bank_3.insert((uint8_t) MRS3_BA, 0, 1, 7), "mss_mrs_load: Error setting up buffers");
            FAPI_TRY(bank_3.insert((uint8_t) MRS3_BA, 1, 1, 6), "mss_mrs_load: Error setting up buffers");
            FAPI_TRY(bank_3.insert((uint8_t) MRS3_BA, 2, 1, 5), "mss_mrs_load: Error setting up buffers");

            //enables PDA
            FAPI_TRY(mrs3.insert((uint8_t) mpr_page, 0, 2), "mss_mrs_load: Error setting up buffers");
            FAPI_TRY(mrs3.insert((uint8_t) mpr_op, 2, 1), "mss_mrs_load: Error setting up buffers");
            FAPI_TRY(mrs3.insert((uint8_t) geardown_mode, 3, 1), "mss_mrs_load: Error setting up buffers");
            FAPI_TRY(mrs3.insert((uint8_t) 0x00, 4, 1), "mss_mrs_load: Error setting up buffers");
            FAPI_TRY(mrs3.insert((uint8_t) temp_readout, 5, 1), "mss_mrs_load: Error setting up buffers");
            FAPI_TRY(mrs3.insert((uint8_t) fine_refresh, 6, 3), "mss_mrs_load: Error setting up buffers");
            FAPI_TRY(mrs3.insert((uint8_t) wr_latency, 9, 2), "mss_mrs_load: Error setting up buffers");
            FAPI_TRY(mrs3.insert((uint8_t) read_format, 11, 2), "mss_mrs_load: Error setting up buffers");
            FAPI_TRY(mrs3.insert((uint8_t) 0x00, 13, 2), "mss_mrs_load: Error setting up buffers");
            FAPI_TRY(mrs3.extract(MRS3, 0, 16), "mss_mrs_load: Error setting up buffers");
            FAPI_TRY(num_idles_16.insertFromRight((uint32_t) 100, 0, 16), "mss_mrs_load: Error setting up buffers");
            FAPI_TRY(odt_4.insert(odt_wr[l_port_number][dimm_number][rank_number], 0, 4, 0),
                     "mss_mrs_load: Error setting up buffers");

            //copies over values
            FAPI_TRY(address_16.insert(mrs3, 0, 16, 0), "mss_mrs_load: Error setting up buffers");

            if (( address_mirror_map[l_port_number][dimm_number] & (0x08 >> rank_number) ) && (is_sim == 0))
            {
                FAPI_TRY(mss_address_mirror_swizzle(i_target, address_16, bank_3));
            }

            // Send out to the CCS array
            FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                          io_ccs_inst_cnt,
                                          address_16,
                                          bank_3,
                                          activate_1,
                                          rasn_1,
                                          casn_1,
                                          wen_1,
                                          cke_4,
                                          csn_8,
                                          odt_4,
                                          ddr_cal_type_4,
                                          l_port_number));
            FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                          io_ccs_inst_cnt,
                                          num_idles_16,
                                          num_repeat_16,
                                          data_20,
                                          read_compare_1,
                                          rank_cal_4,
                                          ddr_cal_enable_1,
                                          ccs_end_1));
            io_ccs_inst_cnt ++;

            // Send out to the CCS array
            FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                          io_ccs_inst_cnt,
                                          address_16,
                                          bank_3,
                                          activate_1,
                                          rasn_1_odt,
                                          casn_1_odt,
                                          wen_1_odt,
                                          cke_4,
                                          csn_8_odt,
                                          odt_4,
                                          ddr_cal_type_4,
                                          l_port_number));
            FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                          io_ccs_inst_cnt,
                                          num_idles_16_odt,
                                          num_repeat_16_odt,
                                          data_20,
                                          read_compare_1,
                                          rank_cal_4,
                                          ddr_cal_enable_1,
                                          ccs_end_1));
            io_ccs_inst_cnt ++;

            //if the DIMM is an R or LR DIMM, then run inverted for the B-Side DRAM
            if ( (dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_RDIMM)
                 || (dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_LRDIMM) )
            {

                //reload all MRS values (removes address swizzling)
                // Only corresponding CS to rank
                FAPI_TRY(csn_8.setBit(0, 8), "mss_ddr4_setup_pda: Error setting up buffers");

                FAPI_TRY(mss_disable_cid(i_target, csn_8, cke_4));

                FAPI_TRY(csn_8.clearBit(rank_number + 4 * dimm_number));

                FAPI_TRY(bank_3.insert((uint8_t) MRS3_BA, 0, 1, 7), "mss_ddr4_setup_pda: Error setting up buffers");
                FAPI_TRY(bank_3.insert((uint8_t) MRS3_BA, 1, 1, 6), "mss_ddr4_setup_pda: Error setting up buffers");
                FAPI_TRY(bank_3.insert((uint8_t) MRS3_BA, 2, 1, 5), "mss_ddr4_setup_pda: Error setting up buffers");

                //enables PDA
                FAPI_TRY(mrs3.insert((uint8_t) mpr_page, 0, 2), "mss_ddr4_setup_pda: Error setting up buffers");
                FAPI_TRY(mrs3.insert((uint8_t) mpr_op, 2, 1), "mss_ddr4_setup_pda: Error setting up buffers");
                FAPI_TRY(mrs3.insert((uint8_t) geardown_mode, 3, 1), "mss_ddr4_setup_pda: Error setting up buffers");
                FAPI_TRY(mrs3.insert((uint8_t) 0x00, 4, 1), "mss_ddr4_setup_pda: Error setting up buffers");
                FAPI_TRY(mrs3.insert((uint8_t) temp_readout, 5, 1), "mss_ddr4_setup_pda: Error setting up buffers");
                FAPI_TRY(mrs3.insert((uint8_t) fine_refresh, 6, 3), "mss_ddr4_setup_pda: Error setting up buffers");
                FAPI_TRY(mrs3.insert((uint8_t) wr_latency, 9, 2), "mss_ddr4_setup_pda: Error setting up buffers");
                FAPI_TRY(mrs3.insert((uint8_t) read_format, 11, 2), "mss_ddr4_setup_pda: Error setting up buffers");
                FAPI_TRY(mrs3.insert((uint8_t) 0x00, 13, 2), "mss_ddr4_setup_pda: Error setting up buffers");
                FAPI_TRY(mrs3.extract(MRS3, 0, 16), "mss_ddr4_setup_pda: Error setting up buffers");
                FAPI_TRY(num_idles_16.insertFromRight((uint32_t) 100, 0, 16), "mss_ddr4_setup_pda: Error setting up buffers");
                //copies over values
                FAPI_TRY(address_16.insert(mrs3, 0, 16, 0), "mss_ddr4_setup_pda: Error setting up buffers");

                //FLIPS all necessary bits
                // Indicate B-Side DRAMS BG1=1
                FAPI_TRY(address_16.setBit(15), "mss_ddr4_setup_pda: Error setting up buffers"); // Set BG1 = 1

                FAPI_TRY(address_16.flipBit(3, 7)); // Invert A3:A9
                FAPI_TRY(address_16.flipBit(11)); // Invert A11
                FAPI_TRY(address_16.flipBit(13)); // Invert A13
                FAPI_TRY(address_16.flipBit(14)); // Invert A17
                FAPI_TRY(bank_3.flipBit(0, 3));   // Invert BA0,BA1,BG0

                if (( address_mirror_map[l_port_number][dimm_number] & (0x08 >> rank_number) ) && (is_sim == 0))
                {
                    FAPI_TRY(mss_address_mirror_swizzle(i_target, address_16, bank_3));
                }

                // Send out to the CCS array
                FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                              io_ccs_inst_cnt,
                                              address_16,
                                              bank_3,
                                              activate_1,
                                              rasn_1,
                                              casn_1,
                                              wen_1,
                                              cke_4,
                                              csn_8,
                                              odt_4,
                                              ddr_cal_type_4,
                                              l_port_number));
                FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                              io_ccs_inst_cnt,
                                              num_idles_16,
                                              num_repeat_16,
                                              data_20,
                                              read_compare_1,
                                              rank_cal_4,
                                              ddr_cal_enable_1,
                                              ccs_end_1));
                io_ccs_inst_cnt ++;

                // Send out to the CCS array
                FAPI_TRY(mss_ccs_inst_arry_0( i_target,
                                              io_ccs_inst_cnt,
                                              address_16,
                                              bank_3,
                                              activate_1,
                                              rasn_1_odt,
                                              casn_1_odt,
                                              wen_1_odt,
                                              cke_4,
                                              csn_8_odt,
                                              odt_4,
                                              ddr_cal_type_4,
                                              l_port_number));
                FAPI_TRY(mss_ccs_inst_arry_1( i_target,
                                              io_ccs_inst_cnt,
                                              num_idles_16_odt,
                                              num_repeat_16_odt,
                                              data_20,
                                              read_compare_1,
                                              rank_cal_4,
                                              ddr_cal_enable_1,
                                              ccs_end_1));
                io_ccs_inst_cnt ++;
            }
        }

        //Setup end bit for CCS
        FAPI_TRY(mss_ccs_set_end_bit (i_target, io_ccs_inst_cnt - 1));

        //Execute the CCS array
        FAPI_INF("Executing the CCS array\n");
        FAPI_TRY(mss_execute_ccs_inst_array (i_target, NUM_POLL, WAIT_TIMER));

        //Disable CCS
        FAPI_INF("Disabling CCS\n");
        reg_address = CEN_MBA_CCS_MODEQ;
        FAPI_TRY(fapi2::getScom(i_target, reg_address, data_buffer));
        FAPI_TRY(data_buffer.clearBit(29), "disable ccs setup: Error disabling up buffers");
        FAPI_TRY(fapi2::putScom(i_target, reg_address, data_buffer));

        //disables the DDR4 PDA mode writes
        FAPI_TRY(fapi2::getScom(i_target,  CEN_MBA_DDRPHY_WC_CONFIG3_P0, data_buffer));
        //Setting up CCS mode
        FAPI_TRY(data_buffer.clearBit(48), "mss_ddr4_setup_pda: Error setting up buffers");
        FAPI_TRY(fapi2::putScom(i_target,  CEN_MBA_DDRPHY_WC_CONFIG3_P0, data_buffer));

        FAPI_TRY(fapi2::getScom(i_target,  CEN_MBA_DDRPHY_WC_CONFIG3_P1, data_buffer));
        //Setting up CCS mode
        FAPI_TRY(data_buffer.clearBit(48), "mss_ddr4_setup_pda: Error setting up buffers");
        FAPI_TRY(fapi2::putScom(i_target,  CEN_MBA_DDRPHY_WC_CONFIG3_P1, data_buffer));

        FAPI_INF("Successfully exited out of PDA mode.");
        io_ccs_inst_cnt = 0;

        //Does the RTT_WR to RTT_NOM swapping
        //loops through all ports
        for(l_port_number = 0; l_port_number < MAX_PORTS_PER_MBA; l_port_number++)
        {
            FAPI_TRY(mss_ddr4_rtt_nom_rtt_wr_swap(i_target, 0, l_port_number, rank_number + dimm_number * 4, 0xFF, io_ccs_inst_cnt,
                                                  io_dram_rtt_nom_original));
            io_ccs_inst_cnt = 0;
        }

    fapi_try_exit:
        return fapi2::current_err;
    }


    ///
    /// @brief sets up the ODT holdtime and number of idles to be issued after
    /// @param[in]  i_target:  Reference to centaur.mba target,
    /// @param[out]  o_wl_launch_time:  holds the number of cycles that the data must be launched after the PDA command is issued
    /// @param[out]  o_odt_hold_time:  holds the number of cycles that the ODT must be held for PDA
    /// @param[out]  o_post_odt_nop_idle:  holds the number of cycles that
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode mss_get_pda_odt_timings(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            uint8_t& o_wl_launch_time,
            uint8_t& o_odt_hold_time,
            uint8_t& o_post_odt_nop_idle)
    {
        fapi2::buffer<uint64_t> data_buffer;
        //reads out the register values
        //gets the hold time
        uint8_t launch_delay = 0;
        uint8_t dram_al = 0;
        uint8_t dram_cl = 0;
        FAPI_TRY(data_buffer.extractToRight(launch_delay, 12, 6));
        FAPI_TRY(data_buffer.extractToRight(o_odt_hold_time, 18, 6));
        FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBA_DSM0Q, data_buffer));
        o_odt_hold_time = o_odt_hold_time + launch_delay;

        //gets write latency
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_CWL, i_target, o_wl_launch_time));

        o_wl_launch_time += launch_delay;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_AL, i_target, dram_al));

        //Addative latency enabled - need to add CL-AL
        if(dram_al != fapi2::ENUM_ATTR_CEN_EFF_DRAM_AL_DISABLE)
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_CL, i_target, dram_cl));
            o_wl_launch_time += (dram_cl - dram_al);
        }

        o_post_odt_nop_idle = o_wl_launch_time + o_odt_hold_time + 50;
    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief returns a 1 if the PDA is empty for the given DIMM rank - returns 0 if not empty
    /// @param[in] i_pda Vector of PDA_MRS_Storage class elements
    /// @param[in] i_dimm Centaur input dimm
    /// @param[in] i_rank Centaur input rank
    /// @return returns a 1 if the PDA is empty for the given DIMM rank - returns 0 if not empty
    ///
    uint32_t mss_ddr4_check_pda_empty_for_rank(
        vector<PDA_MRS_Storage> i_pda,
        const uint8_t i_dimm,
        const uint8_t i_rank)
    {
        for(auto& pda : i_pda)
        {
            //found, return 0
            if((pda.dimm == i_dimm) && (pda.rank == i_rank))
            {
                return 0;
            }
        }

        //not found, return 1
        return 1;
    }
}

