/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_ddr4_pda.H $ */
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
/// @file mss_ddr4_pda.H
/// @brief Tools for DDR4 DIMMs centaur procedures
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Steve Glancy <sglancy@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
///

#ifndef _MSS_DDR4_PDA_H
#define _MSS_DDR4_PDA_H
#include <fapi2.H>
#include <vector>
#include <dimmConsts.H>
using namespace std;

extern "C"
{
///
/// @brief PDA MRS storage structure
///
    class PDA_MRS_Storage
    {
        private:
            char pda_string[fapi2::MAX_ECMD_STRING_LEN + 14];
        public:
            uint8_t attribute_data;
            uint32_t attribute_name;
            uint8_t MRS;
            uint8_t dimm;
            uint8_t dram;
            uint8_t rank;
            uint8_t port;
            uint8_t odt_wr[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM];

            ///
            /// @brief PDA MRS storage constructor
            /// @param[in] ad attribute data
            /// @param[in] ad attribute name/ID
            /// @param[in] dr dram number
            /// @param[in] di DIMM position
            /// @param[in] r rank
            /// @param[in] p port
            /// @param[in] i_odt_wr nominal write ODT settings
            ///
            PDA_MRS_Storage(const uint8_t ad, const uint32_t an, const uint8_t dr, const uint8_t di, const uint8_t r,
                            const uint8_t p, const uint8_t (&i_odt_wr)[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT][MAX_RANKS_PER_DIMM]);

            ///
            /// @brief Destructor
            ///
            ~PDA_MRS_Storage();

            ///
            /// @brief Greater than operator
            /// @param[in] PDA2 object to compare to
            /// @return bool true iff this object is greater than the one we're comparing against
            ///
            bool operator> (const PDA_MRS_Storage& PDA2) const;

            ///
            /// @brief Greater than operator
            /// @param[in] PDA2 object to compare to
            /// @return bool true iff this object is greater than the one we're comparing against
            ///
            bool operator< (const PDA_MRS_Storage& PDA2) const;

            ///
            /// @brief copies one PDA_MRS_Storage to this one
            /// @param[in] temp MRS storage data structure
            ///
            void copy(PDA_MRS_Storage& temp);

            ///
            /// @brief sets the MRS variable based upon the inputted attribute name
            /// @param[in] i_target Centaur MBA target
            /// @return FAPI2_RC_SUCCESS
            ///
            fapi2::ReturnCode setMRSbyAttr(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);

            ///
            /// @brief Checks to make sure that
            /// @param[in] i_target MBA target
            /// @return FAPI2_RC_SUCCESS iff successful
            ///
            fapi2::ReturnCode checkPDAValid(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);

            ///
            /// @brief sends out the string
            /// @return pda string
            ///
            char* c_str();
            void generatePDAString();
    };

///
/// @brief PDA scom storage structure
///
    class PDA_Scom_Storage
    {
        public:
            uint64_t scom_addr;
            uint32_t start_bit;
            uint32_t num_bits;
            ///
            /// @brief PDA_Scom_Storage constructor
            /// @param[in] sa  Scom Address
            /// @param[in] sb  Start Bit
            /// @param[in] nb  Num Bits
            ///
            PDA_Scom_Storage(const uint64_t sa, const uint32_t sb, const uint32_t nb);

            ///
            /// @brief Default destructor
            ///
            ~PDA_Scom_Storage() = default;
    };

    typedef fapi2::ReturnCode (*mss_ddr4_pda_FP_t)(fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            vector<PDA_MRS_Storage> pda);

    ///
    /// @brief runs through the vector of given PDA values and issues the PDA commands to the requested DRAMs
    /// @param[in]  i_target:  Reference to centaur.mba target,
    /// @param[in]  i_pda:  Vector of PDA_MRS_Storage class elements - initialized by the user and contains DRAM information and attribute override information
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode mss_ddr4_run_pda(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                       vector<PDA_MRS_Storage> i_pda);

    ///
    /// @brief Puts the DRAM in per-DRAM addressability mode (PDA mode)
    /// @param[in]  target:  Reference to centaur.mba target,
    /// @param[in/out]  io_ccs_inst_cnt: starting point of CCS array - needed to properly setup CCS
    /// @param[in] i_dimm Centaur dimm to run
    /// @param[in] i_rank Centaur rank to run
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode mss_ddr4_setup_pda(
        const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
        uint32_t& io_ccs_inst_cnt,
        const uint8_t i_dimm,
        const uint8_t i_rank);

    ///
    /// @brief Takes the DRAM out of per-DRAM addressability mode (PDA mode)
    /// @param[in]  target:  Reference to centaur.mba target,
    /// @param[in/out]  io_ccs_inst_cnt: starting point of CCS array - needed to properly setup CCS
    /// @param[in]  i_dimm: which DIMM to run PDA commands on
    /// @param[in]  i_rank: which rank on which DIMM to run PDA commands on
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode mss_ddr4_disable_pda(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target, uint32_t& io_ccs_inst_cnt,
                                           const uint8_t i_dimm, const uint8_t i_rank);

    ///
    /// @brief called by wrapper - sets up a PDA vector if it's not already configured
    /// @param[in]  i_target:  Reference to centaur.mba target,
    /// @param[in]  i_pda:  Vector of PDA_MRS_Storage class elements - initialized by the user and contains DRAM information and attribute override information
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode mss_ddr4_pda(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target, vector<PDA_MRS_Storage> i_pda);

    ///
    /// @brief Checks the passed in PDA vector to ensure that all entries are good. then sorts the vector to ensure more efficient command stream
    /// @param[in]  i_target:  Reference to centaur.mba target,
    /// @param[in/out]  io_pda:  Vector of PDA_MRS_Storage class elements - initialized by the user and contains DRAM information and attribute override information
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode mss_ddr4_checksort_pda(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            vector<PDA_MRS_Storage>& io_pda);

    ///
    /// @brief Adds a given DRAM into the scom_storage vector
    /// @param[in]  i_target:  Reference to centaur.mba target,
    /// @param[in]  i_port:  identifies which port the given DRAM is on
    /// @param[in]  i_dram:  identifies which DRAM identifier is to be added
    /// @param[in/out]  io_scom_storage:  list of all DRAMs being modified by PDA. contains address, bit, and length
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode mss_ddr4_add_dram_pda(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target, const uint8_t i_port,
                                            const uint8_t i_dram,
                                            vector<PDA_Scom_Storage>& io_scom_storage);

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
            uint8_t& o_odt_hold_time, uint8_t& o_post_odt_nop_idle);

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
        const uint8_t i_rank
    );

    ///
    /// @brief returns a 1 if the PDA is empty for the given DIMM rank - returns 0 if not empty
    /// @param[in] i_pda
    /// @param[in] i_dimm
    /// @param[in] i_rank
    /// @return returns a 1 if the PDA is empty for the given DIMM rank - returns 0 if not empty
    ///
    uint32_t mss_ddr4_check_pda_empty_for_rank(
        vector<PDA_MRS_Storage> i_pda,
        const uint8_t i_dimm,
        const uint8_t i_rank
    );

} // extern "C"

#endif /* _MSS_DDR4_PDA_H */


