/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_mcbist_address.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
/// @file mss_mcbist_address.C
/// @brief MCBIST address generation procedures
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Steve Glancy <sglancy@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
///


#include <p9c_mss_mcbist_address.H>
#include <generic/memory/lib/utils/c_str.H>
extern "C"
{
#define DELIMITERS ","
    constexpr uint8_t MAX_ADDR_BITS = 37;

    ///
    /// @brief  Setup MCBIST address string
    /// @param[in] i_target_mba Centaur input MBA
    /// @param[in] l_str_cust_addr Optional custom address string
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode address_generation(const fapi2:: Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                         const char* l_str_cust_addr)
    {
        uint8_t l_num_ranks_per_dimm[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t l_num_master_ranks[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t l_dram_rows = 0;
        uint8_t l_dram_cols = 0;
        uint8_t l_addr_inter = 0;
        uint8_t l_num_ranks_p0_dim0, l_num_ranks_p0_dim1, l_num_ranks_p1_dim0, l_num_ranks_p1_dim1 = 0;
        uint8_t l_master_ranks_p0_dim0, l_master_ranks_p0_dim1, l_master_ranks_p1_dim0 = 0;
        uint8_t mr3_valid, mr2_valid, mr1_valid, sl0_valid, sl1_valid, sl2_valid = 0;

        char S0[] = "b";
        //Choose a default buffer for the below
        //0         1   2       3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35  36
        //MR0(MSB)  MR1 MR2     MR3 BA0 BA1 BA2 BA3 C3  C4  C5  C6  C7  C8  C9  C10 C11 R0  R1  R2  R3  R4  R5  R6  R7  R8  R9  R10 R11 R12 R13 R14 R15 R16 SL0(MSB)    SL1 SL2

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_RANKS_PER_DIMM, i_target_mba,  l_num_ranks_per_dimm));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_MASTER_RANKS_PER_DIMM, i_target_mba,  l_num_master_ranks));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_ROWS, i_target_mba,  l_dram_rows));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_COLS, i_target_mba,  l_dram_cols));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MCBIST_ADDR_INTER, i_target_mba,  l_addr_inter));

        l_num_ranks_p0_dim0 = l_num_ranks_per_dimm[0][0];
        l_num_ranks_p0_dim1 = l_num_ranks_per_dimm[0][1];
        l_num_ranks_p1_dim0 = l_num_ranks_per_dimm[1][0];
        l_num_ranks_p1_dim1 = l_num_ranks_per_dimm[1][1];
        l_master_ranks_p0_dim0 = l_num_master_ranks[0][0];
        l_master_ranks_p0_dim1 = l_num_master_ranks[0][1];
        l_master_ranks_p1_dim0 = l_num_master_ranks[1][0];

        //Initial all ranks are invalid
        mr3_valid = 0;
        mr2_valid = 0;
        mr1_valid = 0;
        sl2_valid = 0;
        sl1_valid = 0;
        sl0_valid = 0;

        if( (l_num_ranks_p0_dim0 == 1 && l_num_ranks_p0_dim1 == 0) || (l_num_ranks_p1_dim0 == 1
                && l_num_ranks_p1_dim1 == 0) )   //Single Rank case   -- default0
        {
            //do rank-only stuff for this
            FAPI_DBG("%s:--- INSIDE 1R", mss::c_str(i_target_mba));
            l_addr_inter = 3;
        }

        else if ( (l_num_ranks_p0_dim0 == 1 && l_num_ranks_p0_dim1 == 1) || (l_num_ranks_p1_dim0 == 1
                  && l_num_ranks_p1_dim1 == 1) )
        {
            FAPI_DBG("%s:--- INSIDE p0d0 valid and p0d1 valid --- 0 4----  2R", mss::c_str(i_target_mba));
            mr1_valid = 1;
        }

        else if ( (l_num_ranks_p0_dim0 == 2 && l_num_ranks_p0_dim1 == 0) || (l_num_ranks_p1_dim0 == 2
                  && l_num_ranks_p1_dim1 == 0) )
        {
            FAPI_DBG("%s:--- INSIDE p0d0 valid and p0d1 valid --- 0 1----  2R", mss::c_str(i_target_mba));
            mr3_valid = 1;
        }
        else if (((l_num_ranks_p0_dim0 == 2 && l_num_ranks_p0_dim1 == 2) || (l_num_ranks_p1_dim0 == 2
                  && l_num_ranks_p1_dim1 == 2)) && (l_master_ranks_p0_dim0 != 1 && l_master_ranks_p0_dim1 != 1))   //Rank 01 and 45 case
        {
            FAPI_DBG("%s:--- INSIDE  --- 2R   0145", mss::c_str(i_target_mba));
            mr3_valid = 1;
            mr1_valid = 1;
        }

        else if((l_num_ranks_p0_dim0 == 4 && l_num_ranks_p0_dim1 == 0 ) || (l_num_ranks_p1_dim0 == 4
                && l_num_ranks_p1_dim1 == 0 ))  //Rank 0123 on single dimm case
        {
            mr3_valid = 1;
            mr2_valid = 1;
        }
        else if (((l_num_ranks_p0_dim0 == 4 && l_num_ranks_p0_dim1 == 4) || (l_num_ranks_p1_dim0 == 4
                  && l_num_ranks_p1_dim1 == 4)) && l_master_ranks_p0_dim0 == 1) //1r 4h stack
        {
            mr1_valid = 0; //DDC
            sl1_valid = 1;
            sl2_valid = 1;
        }

        else if (((l_num_ranks_p0_dim0 == 8 && l_num_ranks_p0_dim1 == 0) || (l_num_ranks_p1_dim0 == 8
                  && l_num_ranks_p1_dim1 == 0)) && ((l_master_ranks_p0_dim0 == 2) || (l_master_ranks_p0_dim1 == 0
                          && l_master_ranks_p1_dim0 == 2))) //2rx4 4h ddr4 3ds
        {
            l_addr_inter = 4;
            mr3_valid = 1; //DDC
            sl1_valid = 1;
            sl2_valid = 1;
        }
        else if ((l_num_ranks_p0_dim0 == 4 && l_num_ranks_p0_dim1 == 4) || (l_num_ranks_p1_dim0 == 4
                 && l_num_ranks_p1_dim1 == 4)) //Rank 0123 and 4567 case
        {
            mr3_valid = 1;
            mr2_valid = 1;
            mr1_valid = 1;
        }
        else if (((l_num_ranks_p0_dim0 == 2 && l_num_ranks_p0_dim1 == 2) ||
                  (l_num_ranks_p1_dim0 == 2 && l_num_ranks_p1_dim1 == 2)) &&
                 (l_master_ranks_p0_dim0 == 1 && l_master_ranks_p0_dim1 == 1)) //1rx4 2h ddr4 3ds 2 dimm, CDIMM
        {
            sl1_valid = 0;
            sl2_valid = 1;
            mr1_valid = 1;
        }
        else
        {
            FAPI_INF("-- Error ---- mcbist_addr_Check dimm_Config ----- ");
        }

        //custom addressing string is not to be used
        if(l_addr_inter != 4)
        {
            FAPI_TRY(parse_addr(i_target_mba, S0, mr3_valid, mr2_valid, mr1_valid,
                                l_dram_rows, l_dram_cols, l_addr_inter, sl2_valid, sl1_valid, sl0_valid));
        }
        else
        {
            FAPI_DBG("Custom addressing flag was selected");
            FAPI_TRY(parse_addr(i_target_mba, l_str_cust_addr, mr3_valid, mr2_valid, mr1_valid,
                                l_dram_rows, l_dram_cols, l_addr_inter, sl2_valid, sl1_valid, sl0_valid));
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief Parse MCBIST address string and set corresponding registers
    /// @param[in] i_target_mba Centaur input MBA
    /// @param[in] addr_string MCBIST address string
    /// @param[in] mr3_valid Master rank 3 valid bit
    /// @param[in] mr2_valid Master rank 2 valid bit
    /// @param[in] mr1_valid Master rank 1 valid bit
    /// @param[in] l_dram_rows Num dram rows
    /// @param[in] l_dram_cols Num dram columns
    /// @param[in] l_addr_inter Address interleave bit
    /// @param[in] sl2_valid Slave rank 2 valid bit
    /// @param[in] sl1_valid Slave rank 1 valid bit
    /// @param[in] sl0_valid Slave rank 0 valid bit
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode parse_addr(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                 const char addr_string[],
                                 const uint8_t mr3_valid,
                                 const uint8_t mr2_valid,
                                 const uint8_t mr1_valid,
                                 const uint8_t l_dram_rows,
                                 const uint8_t l_dram_cols,
                                 const uint8_t l_addr_inter,
                                 const uint8_t sl2_valid,
                                 const uint8_t sl1_valid,
                                 const uint8_t sl0_valid)
    {
        uint8_t i = MAX_ADDR_BITS;
        uint8_t l_value = 0;
        uint32_t l_value32 = 0;
        uint32_t l_sbit = 0;
        uint32_t l_start = 0;
        uint32_t l_len = 0;
        uint64_t l_readscom_value = 0;
        uint64_t l_end = 0;
        uint64_t l_start_addr = 0;
        uint8_t l_value_zero = 0;
        uint8_t l_user_end_addr = 0;
        fapi2::buffer<uint64_t> l_data_buffer_64;
        fapi2::buffer<uint64_t> l_data_buffer_rd64;
        uint8_t l_attr_addr_mode = 0;
        uint8_t l_num_cols = 0;
        uint8_t l_num_rows = 0;
        uint8_t l_dram_gen = 0;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_SCHMOO_ADDR_MODE, i_target_mba,  l_attr_addr_mode));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MCBIST_ADDR_NUM_COLS, i_target_mba,  l_num_cols));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MCBIST_ADDR_NUM_ROWS, i_target_mba,  l_num_rows));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_GEN, i_target_mba,  l_dram_gen));

        if (l_num_cols == 0)
        {
            l_num_cols = l_dram_cols;
        }

        if (l_num_rows == 0)
        {
            l_num_rows = l_dram_rows;
        }

        //Set all the addr reg to 0
        //Define Custom String
        //Set all Params based on the string.
        l_data_buffer_64.flush<0>();
        l_sbit = 0;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR1A0Q, l_data_buffer_64));
        FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit, 6));
        FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR1A0Q, l_data_buffer_64));
        i--;

        l_sbit = 54;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR0A0Q, l_data_buffer_64));
        FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit, 6));
        FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR0A0Q, l_data_buffer_64));
        i--;

        l_sbit = 18;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR0A0Q, l_data_buffer_64));

        if (mr3_valid == 1)
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR0A0Q, l_data_buffer_64));
            i--;
        }
        else
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR0A0Q, l_data_buffer_64));
        }

        l_sbit = 12;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR0A0Q, l_data_buffer_64));

        if (mr2_valid == 1)
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR0A0Q, l_data_buffer_64));
            i--;
        }
        else
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR0A0Q, l_data_buffer_64));
        }

        l_sbit = 6;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR0A0Q, l_data_buffer_64));

        if (mr1_valid == 1)
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR0A0Q, l_data_buffer_64));

            i--;
        }
        else
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR0A0Q, l_data_buffer_64));
        }

        l_sbit = 48;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR0A0Q, l_data_buffer_64));
        FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit, 6));
        FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR0A0Q, l_data_buffer_64));
        i--;

        l_sbit = 42;
        l_value = i;
        //------- Enable these for DDR4 --- for now constant map to zero
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR0A0Q, l_data_buffer_64));

        if (l_dram_gen == 2)
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR0A0Q, l_data_buffer_64));
            i--;
        }
        else
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR0A0Q, l_data_buffer_64));
        }

        l_sbit = 0;
        l_value = i;
        //------- Enable these for DDR4 --- for now constant map to zero
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR0A0Q, l_data_buffer_64));
        FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6));
        FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR0A0Q, l_data_buffer_64));

        l_sbit = 42;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR3A0Q, l_data_buffer_64));
        FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6));
        FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR3A0Q, l_data_buffer_64));

        l_sbit = 36;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR3A0Q, l_data_buffer_64));

        if (l_num_cols >= 1)
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR3A0Q, l_data_buffer_64));
            i--;
        }
        else
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR3A0Q, l_data_buffer_64));
        }

        l_sbit = 30;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR3A0Q, l_data_buffer_64));

        if (l_num_cols >= 2)
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR3A0Q, l_data_buffer_64));
            i--;
        }
        else
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR3A0Q, l_data_buffer_64));
        }

        l_sbit = 24;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR3A0Q, l_data_buffer_64));

        if (l_num_cols >= 3)
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR3A0Q, l_data_buffer_64));
            i--;
        }
        else
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR3A0Q, l_data_buffer_64));
        }

        l_sbit = 18;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR3A0Q, l_data_buffer_64));

        if (l_num_cols >= 4)
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR3A0Q, l_data_buffer_64));

            i--;
        }
        else
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR3A0Q, l_data_buffer_64));
        }

        l_sbit = 12;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR3A0Q, l_data_buffer_64));

        if (l_num_cols >= 5)
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR3A0Q, l_data_buffer_64));
            i--;
        }
        else
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR3A0Q, l_data_buffer_64));

        }

        l_sbit = 6;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR3A0Q, l_data_buffer_64));

        if (l_num_cols >= 6)
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR3A0Q, l_data_buffer_64));
            i--;
        }
        else
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR3A0Q, l_data_buffer_64));

        }

        l_sbit = 0;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR3A0Q, l_data_buffer_64));

        if (l_num_cols >= 7)
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR3A0Q, l_data_buffer_64));
            i--;
        }

        else
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR3A0Q, l_data_buffer_64));

        }

        l_sbit = 54;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR2A0Q, l_data_buffer_64));

        if (l_num_cols >= 11)
        {
            if (l_dram_cols >= 11)
            {
                FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit, 6));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR2A0Q, l_data_buffer_64));
                i--;
            }
            else
            {
                FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR2A0Q, l_data_buffer_64));
                FAPI_DBG("%s:Col 11 -- Invalid", mss::c_str(i_target_mba));

            }
        }
        else
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR2A0Q, l_data_buffer_64));

        }

        l_sbit = 48;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR2A0Q, l_data_buffer_64));

        if (l_num_cols >= 12)
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR2A0Q, l_data_buffer_64));
            i--;
        }
        else
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR2A0Q, l_data_buffer_64));

        }

        l_sbit = 42;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR2A0Q, l_data_buffer_64));

        if (l_num_rows > 0)
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR2A0Q, l_data_buffer_64));
            i--;
        }
        else
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR2A0Q, l_data_buffer_64));

        }

        l_sbit = 36;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR2A0Q, l_data_buffer_64));

        if (l_num_rows > 1)
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR2A0Q, l_data_buffer_64));
            i--;
        }
        else
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR2A0Q, l_data_buffer_64));

        }

        l_sbit = 30;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR2A0Q, l_data_buffer_64));

        if (l_num_rows > 2)
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR2A0Q, l_data_buffer_64));
            i--;
        }
        else
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR2A0Q, l_data_buffer_64));

        }

        l_sbit = 24;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR2A0Q, l_data_buffer_64));

        if (l_num_rows > 3)
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR2A0Q, l_data_buffer_64));
            i--;
        }
        else
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR2A0Q, l_data_buffer_64));

        }

        l_sbit = 18;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR2A0Q, l_data_buffer_64));

        if (l_num_rows > 4)
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR2A0Q, l_data_buffer_64));
            i--;
        }
        else
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR2A0Q, l_data_buffer_64));

        }

        l_sbit = 12;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR2A0Q, l_data_buffer_64));

        if (l_num_rows > 5)
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR2A0Q, l_data_buffer_64));
            i--;
        }
        else
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR2A0Q, l_data_buffer_64));

        }

        l_sbit = 6;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR2A0Q, l_data_buffer_64));

        if (l_num_rows > 6)
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR2A0Q, l_data_buffer_64));
            i--;
        }
        else
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR2A0Q, l_data_buffer_64));

        }

        l_sbit = 0;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR2A0Q, l_data_buffer_64));

        if (l_num_rows > 7)
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR2A0Q, l_data_buffer_64));
            i--;
        }
        else
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR2A0Q, l_data_buffer_64));

        }

        l_sbit = 54;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR1A0Q, l_data_buffer_64));

        if (l_num_rows > 8)
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR1A0Q, l_data_buffer_64));
            i--;
        }
        else
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR1A0Q, l_data_buffer_64));

        }

        l_sbit = 48;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR1A0Q, l_data_buffer_64));

        if (l_num_rows > 9)
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR1A0Q, l_data_buffer_64));
            i--;
        }
        else
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR1A0Q, l_data_buffer_64));

        }

        l_sbit = 42;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR1A0Q, l_data_buffer_64));

        if (l_num_rows > 10)
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR1A0Q, l_data_buffer_64));
            i--;
        }
        else
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR1A0Q, l_data_buffer_64));

        }

        l_sbit = 36;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR1A0Q, l_data_buffer_64));

        if (l_num_rows > 11)
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR1A0Q, l_data_buffer_64));
            i--;
        }
        else
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR1A0Q, l_data_buffer_64));

        }

        l_sbit = 30;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR1A0Q, l_data_buffer_64));

        if (l_num_rows > 12)
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR1A0Q, l_data_buffer_64));
            i--;
        }
        else
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR1A0Q, l_data_buffer_64));

        }

        l_sbit = 24;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR1A0Q, l_data_buffer_64));

        if (l_num_rows > 13)
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR1A0Q, l_data_buffer_64));
            i--;
        }
        else
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR1A0Q, l_data_buffer_64));

        }

        l_sbit = 18;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR1A0Q, l_data_buffer_64));

        if (l_num_rows > 14)
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR1A0Q, l_data_buffer_64));
            i--;
        }
        else
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR1A0Q, l_data_buffer_64));

        }

        l_sbit = 12;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR1A0Q, l_data_buffer_64));

        if (l_num_rows > 15)
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR1A0Q, l_data_buffer_64));
            i--;
        }
        else
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR1A0Q, l_data_buffer_64));

        }

        l_sbit = 6;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR1A0Q, l_data_buffer_64));

        if (l_dram_rows >= 17)
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR1A0Q, l_data_buffer_64));
            i--;
        }
        else
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit, 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR1A0Q, l_data_buffer_64));
        }

        l_sbit = 36;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR0A0Q, l_data_buffer_64));

        if(sl2_valid == 1)
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit , 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR0A0Q, l_data_buffer_64));
            i--;
        }
        else
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit , 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR0A0Q, l_data_buffer_64));
            FAPI_DBG("%s:sl2 Invalid", mss::c_str(i_target_mba));

        }

        l_sbit = 30;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR0A0Q, l_data_buffer_64));

        //------- Enable these for later --- for now constant map to zero
        if(sl1_valid == 1)
        {

            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit , 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR0A0Q, l_data_buffer_64));
            i--;
        }
        else
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit , 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR0A0Q, l_data_buffer_64));
            FAPI_DBG("%s:sl1 Invalid", mss::c_str(i_target_mba));

        }

        FAPI_INF("Inside strcmp sl0");
        l_sbit = 24;
        l_value = i;
        FAPI_TRY(fapi2::getScom(i_target_mba, CEN_MBA_MCBAMR0A0Q, l_data_buffer_64));

        //------- Enable these for later --- for now constant map to zero
        if(sl0_valid == 1)
        {

            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value, l_sbit , 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR0A0Q, l_data_buffer_64));
            i--;
        }
        else
        {
            FAPI_TRY(l_data_buffer_64.insertFromRight(l_value_zero, l_sbit , 6));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBAMR0A0Q, l_data_buffer_64));
            FAPI_DBG("%s:sl0 Invalid", mss::c_str(i_target_mba));

        }

        //------ Setting Start and end addr counters
        FAPI_INF("Debug - --------------- Setting Start and End Counters -----------\n");
        l_data_buffer_rd64.flush<0>();
        FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBSSARA0Q, l_data_buffer_rd64));
        l_value = i + 1;
        FAPI_INF("Setting end_addr Value of i = %d", i);
        l_data_buffer_rd64.flush<0>();

        //Calculate and set Valid bits for end_addr
        for (i = l_value; i <= 37; i++)
        {
            FAPI_TRY(l_data_buffer_rd64.clearBit(i));
            FAPI_TRY(l_data_buffer_rd64.setBit(i));
        }

        l_readscom_value = uint64_t(l_data_buffer_rd64);

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_SCHMOO_ADDR_MODE, i_target_mba,  l_attr_addr_mode));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MCBIST_START_ADDR, i_target_mba,  l_start_addr));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MCBIST_END_ADDR, i_target_mba,  l_end));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MCBIST_RANK, i_target_mba,  l_user_end_addr));

        if (l_user_end_addr == 1)
        {
            //Setting start and end Temp
            l_data_buffer_rd64 = l_start_addr;
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBSSARA0Q, l_data_buffer_rd64));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBSSARA1Q, l_data_buffer_rd64));
            l_data_buffer_rd64 = l_end;
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBSEARA0Q, l_data_buffer_rd64));
            FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBSEARA1Q, l_data_buffer_rd64));
        }

        else
        {
            if (l_attr_addr_mode == 0)
            {
                FAPI_INF("ATTR_EFF_SCHMOO_ADDR_MODE - %d ---- Few Address Mode --------", l_attr_addr_mode);
                l_sbit = 32;
                l_data_buffer_rd64.flush<0>();
                l_start = 24;
                l_len = 8;
                l_value32 = 28;
                FAPI_TRY(l_data_buffer_rd64.insert(l_value32, l_sbit, l_len,  l_start));
                l_readscom_value = 0x000003FFF8000000ull;
                l_data_buffer_rd64 = l_readscom_value;
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBSEARA0Q, l_data_buffer_rd64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBSEARA1Q, l_data_buffer_rd64));
                l_readscom_value = uint64_t(l_data_buffer_rd64);
            }
            else if (l_attr_addr_mode == 1)
            {
                FAPI_INF("ATTR_EFF_SCHMOO_ADDR_MODE - %d ---- QUARTER ADDRESSING Mode --------", l_attr_addr_mode);
                l_readscom_value = l_readscom_value >> 2;
                FAPI_INF("Debug - Final End addr for CEN_MBA_MCBSEARA0Q = %016llX", l_readscom_value);
                l_data_buffer_rd64 = l_readscom_value;
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBSEARA0Q, l_data_buffer_rd64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBSEARA1Q, l_data_buffer_rd64));

            }
            else if (l_attr_addr_mode == 2)
            {
                FAPI_INF("ATTR_EFF_SCHMOO_ADDR_MODE - %d ---- HALF ADDRESSING Mode --------", l_attr_addr_mode);
                l_readscom_value = l_readscom_value >> 1;
                FAPI_INF("Debug - Final End addr for CEN_MBA_MCBSEARA0Q = %016llX", l_readscom_value);
                l_data_buffer_rd64 = l_readscom_value;
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBSEARA0Q, l_data_buffer_rd64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBSEARA1Q, l_data_buffer_rd64));

            }
            else
            {
                FAPI_INF("ATTR_EFF_SCHMOO_ADDR_MODE - %d ---- FULL Address Mode --------", l_attr_addr_mode);
                FAPI_INF("Debug - Final End addr for CEN_MBA_MCBSEARA0Q = %016llX", l_readscom_value);
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBSEARA0Q, l_data_buffer_rd64));
                FAPI_TRY(fapi2::putScom(i_target_mba, CEN_MBA_MCBSEARA1Q, l_data_buffer_rd64));

            }
        }

    fapi_try_exit:
        return fapi2::current_err;
    }
}
