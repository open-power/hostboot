/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/eff_config/eff_config.H $  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file eff_config.H
/// @brief Determine effective config for mss settings
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP FW Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_EFF_CONFIG_H_
#define _MSS_EFF_CONFIG_H_

#include <fapi2.H>
#include <cstdint>
#include "../spd/spd_decoder.H"

namespace mss
{

///
/// @class eff_config
/// @brief Determine effective config for mss settings
///
class eff_config
{
        // constructor
        eff_config() = default;

        // destructor
        ~eff_config() = default;

    public:
        ////////////////////////
        // Methods
        ///////////////////////

        ///
        /// @brief Determines & sets effective config for DRAM generation from SPD
        /// @param[in] i_target FAPI2 target
        /// @param[in] i_spd_data SPD blob
        /// @param[in] i_pDecoder shared pointer to decoder factory
        /// @return fapi2::ReturnCode
        ///
        fapi2::ReturnCode dram_gen(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                   const uint8_t* i_spd_data,
                                   std::shared_ptr<spd::decoder>& i_pDecoder);

        ///
        /// @brief Determines & sets effective config for DIMM type
        /// @param[in] i_target FAPI2 target
        /// @param[in] i_spd_data SPD blob
        /// @return fapi2::ReturnCode
        ///
        fapi2::ReturnCode dimm_type(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                    const uint8_t* i_spd_data);
        ///
        /// @brief Determines & sets effective config for Hybrid memory type from SPD
        /// @param[in] i_target FAPI2 target
        /// @param[in] i_spd_data SPD blob
        /// @param[in] i_pDecoder shared pointer to decoder factory
        /// @return fapi2::ReturnCode
        ///
        fapi2::ReturnCode hybrid_memory_type(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                             const uint8_t* i_spd_data,
                                             std::shared_ptr<spd::decoder>& i_pDecoder);
        ///
        /// @brief Sets effective config for temperature controlled refresh mode
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::ReturnCode
        /// @note Proposed DDR4 Full spec update(79-4A)
        /// @note  Committee: JC42.3C
        /// @note  Committee Item Number: 1716.78C
        /// @note  4.8.2  Extended temperature mode (pg. 44)
        fapi2::ReturnCode temp_ref_range(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for Refresh Mode
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::ReturnCode
        ///
        fapi2::ReturnCode fine_refresh_mode(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        /// @brief Determines & sets effective config for refresh interval time (tREFI)
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::ReturnCode
        ///
        fapi2::ReturnCode refresh_interval_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

};// eff_config

} // mss

#endif // _MSS_EFF_CONFIG_H_
