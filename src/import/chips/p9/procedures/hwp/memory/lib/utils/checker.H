/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/utils/checker.H $          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

///
/// @file checker.H
/// @brief Contains common functions that perform checks
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP FW Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _CHECKER_H_
#define _CHECKER_H_

#include <fapi2.H>
#include "../shared/mss_const.H"
#include <mss_attribute_accessors.H>

namespace mss
{
namespace check
{
///
/// @brief      Checks homogenous DDR4 dimm configuration (e.g. DDR4)
/// @param[in]  const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target_mcs
/// @return     FAPI2_RC_SUCCESS iff ok
///
inline fapi2::ReturnCode dram_type(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target_mcs)
{
    uint8_t l_dram_gen[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Retrieve DDR4 dimm attributes
    FAPI_TRY(spd_dram_device_type(i_target_mcs, &(l_dram_gen[0][0])));

    // Make sure all DRAMs are DDR4 or throw an error
    // Iterate through MCA's/ports
    for (auto p : i_target_mcs.getChildren<fapi2::TARGET_TYPE_MCA>())
    {
        auto port_num = mss::index(p);

        // Iterate through DIMM targets
        for (auto d : p.getChildren<fapi2::TARGET_TYPE_DIMM>())
        {
            auto dimm_num = mss::index(d);

            FAPI_INF("%s DRAM device type is %llX",
                     mss::c_str(d),
                     l_dram_gen[port_num][dimm_num]);

            // Nimbus supports only DDR4
            FAPI_ASSERT(l_dram_gen[port_num][dimm_num] == fapi2::ENUM_ATTR_SPD_DRAM_DEVICE_TYPE_DDR4,
                        fapi2::MSS_UNSUPPORTED_DEV_TYPE().
                        set_DEV_TYPE(l_dram_gen[port_num][dimm_num]),
                        "%s Incorrect DRAM device generation, DRAM generation is %llx",
                        mss::c_str(d),
                        l_dram_gen[port_num][dimm_num]);
        }

    }

fapi_try_exit:
    return fapi2::current_err;
}// dram_type


///
/// @brief Check if there is DIMM mixing (and deconfigures unsupported mixing <shrug> ?? - AAM)
/// @param[in]  const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target_mcs
/// @param[out] uint64_t& o_module_type (returns something ?? - AAM )
/// @return FAPI2_RC_SUCCESS iff ok
/// @note Functionality currently unknown
///
inline fapi2::ReturnCode dimm_mixing(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target_mcs,
                                     uint64_t& o_module_type)
{
    //TODO
    //Need to complete - AAM

    // Anuwat pushed Warren to say IBM systems will not support DIMM mixing
    // Now DIMM deconfig rules? - AAM
#if 0

    std::vector<uint8_t> l_module_type_vector;
    uint8_t l_module_type[mss::PORTS_PER_MCS][mss::MAX_DIMM_PER_PORT] = {0};
    uint8_t lr_dimm_count;
    uint8_t r_dimm_count;
    uint8_t u_dimm_count;

    FAPI_TRY(mss::spd_module_type(i_target_mcs, &l_module_type[0][0]),
             "Unable to read the SPD module type.");

    for(size_t l_port = 0; l_port < mss::PORTS_PER_MCS; l_port++)
    {
        for (size_t l_dimm = 0; l_dimm < mss::MAX_DIMM_PER_PORT; l_dimm++)
        {
            l_module_type_vector.push_back(l_module_type[l_port][l_dimm]);
        }
    }

    lr_dimm_count = std::count(l_module_type_vector.begin(),
                               l_module_type_vector.end(),
                               fapi2::ENUM_ATTR_SPD_MODULE_TYPE_LRDIMM);
    r_dimm_count = std::count(l_module_type_vector.begin(),
                              l_module_type_vector.end(),
                              fapi2::ENUM_ATTR_SPD_MODULE_TYPE_RDIMM);
    u_dimm_count = std::count(l_module_type_vector.begin(),
                              l_module_type_vector.end(),
                              fapi2::ENUM_ATTR_SPD_MODULE_TYPE_UDIMM); // Not supported? - AAM

    count(l_module_type_vector.begin(), l_module_type_vector.end(), fapi2::SO_DIMM); // Not supported? - AAM

    uint8_t temp = std::max({lr_dimm_count, r_dimm_count, u_dimm_count});

    return (temp == r_dimm_count) ? fapi2::RDIMM : fapi2::LRDIMM

#endif

           return fapi2::FAPI2_RC_SUCCESS;
}// dimm_mixing

///
/// @brief Checks what type of system is configured (i.e., single drop, dual drop)
/// @param[in] Unknown
/// @param[out] Unknown
/// @return FAPI2_RC_SUCCESS iff ok
/// @note Functionality currently unknown
///
inline fapi2::ReturnCode system_drop_type(void)
{
    //TODO
    //Update for P9, how will we check if a system is single/dual drop?? - AAM

#if 0
    //Determining the cnfg for imposing any cnfg speed limitations
    if ( (cur_dimm_spd_valid_u8array[0][0][0] == MSS_FREQ_VALID)
         && (cur_dimm_spd_valid_u8array[0][0][1] == MSS_FREQ_EMPTY) )
    {
        plug_config = MSS_FREQ_SINGLE_DROP;
        num_ranks_total = num_ranks[0][0][0] + 1;
    }
    else if (((cur_dimm_spd_valid_u8array[1][0][0] == MSS_FREQ_VALID)
              && (cur_dimm_spd_valid_u8array[1][0][1] == MSS_FREQ_EMPTY)) ||
             ((cur_dimm_spd_valid_u8array[1][0][1] == MSS_FREQ_VALID) && (cur_dimm_spd_valid_u8array[1][0][0] == MSS_FREQ_EMPTY)))
    {
        plug_config = MSS_FREQ_SINGLE_DROP;
        num_ranks_total = num_ranks[1][0][0] + 1;
    }
    else if ((cur_dimm_spd_valid_u8array[0][0][0] == MSS_FREQ_VALID)
             && (cur_dimm_spd_valid_u8array[0][0][1] == MSS_FREQ_VALID))
    {
        plug_config = MSS_FREQ_DUAL_DROP;
        num_ranks_total = (num_ranks[0][0][0] + 1) + (num_ranks[0][0][1] + 1);
    }
    else if ((cur_dimm_spd_valid_u8array[1][0][0] == MSS_FREQ_VALID)
             && (cur_dimm_spd_valid_u8array[1][0][1] == MSS_FREQ_VALID))
    {
        plug_config = MSS_FREQ_DUAL_DROP;
        num_ranks_total = (num_ranks[1][0][0] + 1) + (num_ranks[1][0][1] + 1);
    }
    else
    {
        plug_config = MSS_FREQ_EMPTY;
    }


    FAPI_INF( "PLUG CONFIG(from SPD): %d, Type of Dimm(from SPD): 0x%02X, Num Ranks(from SPD): %d",
              plug_config, module_type, num_ranks_total);
fapi_try_exit:
    return fapi2::current_err;

#endif

    return fapi2::FAPI2_RC_SUCCESS;
}// system_drop_type

///
/// @brief      Checks nominal voltage is correct for all DIMMs
/// @param[in]  const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target_mcs,
///             fapi2::TargetState dimm_state
/// @return ReturnCode
///
inline fapi2::ReturnCode module_nominal_voltage(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target_mcs,
        fapi2::TargetState dimm_state)
{

    uint64_t l_module_nom_voltage[mss::PORTS_PER_MCS][mss::MAX_DIMM_PER_PORT] = {0};

    FAPI_TRY(mss::spd_module_nominal_voltage(i_target_mcs, &l_module_nom_voltage[0][0]));

    for (auto p : i_target_mcs.getChildren<fapi2::TARGET_TYPE_MCA>())
    {
        auto port_num = mss::index(p);

        // Iterate through DIMM targets
        for (auto d : p.getChildren<fapi2::TARGET_TYPE_DIMM>(dimm_state))
        {
            auto dimm_num = mss::index(d);

            FAPI_INF("%s DRAM nominal voltage (in milliseconds) is %d",
                     mss::c_str(d),
                     l_module_nom_voltage[port_num][dimm_num]);

            // All DIMMs have to be operable at 1.2 V, else don't IPL (according to Warren)
            FAPI_ASSERT( l_module_nom_voltage[port_num][dimm_num] == fapi2::ENUM_ATTR_SPD_MODULE_NOMINAL_VOLTAGE_OPERABLE,
                         fapi2::MSS_VOLT_DDR_TYPE_REQUIRED_VOLTAGE().
                         set_DIMM_VOLTAGE(l_module_nom_voltage[port_num][dimm_num]),
                         "%s.Failed conditional, data returned:o %d.",
                         mss::c_str(d),
                         l_module_nom_voltage[port_num][dimm_num] );
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}// module_nominal_voltage

namespace spd
{
///
/// @brief      Checks conditional passes and implements traces & exits if it fails
/// @tparam     T spd_data, of any size
/// @param[in]  const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
///             bool conditional
///             size_t spd_byte_index
///             const char* err_str
/// @return     ReturnCode
///
template< typename T >
inline fapi2::ReturnCode valid_value_fail(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        bool conditional,
        size_t spd_byte_index,
        T spd_data,
        const char* err_str)
{
    FAPI_ASSERT(conditional,
                fapi2::MSS_SPD_DECODE_INVALID_VALUE().
                set_VALUE(spd_data).
                set_BYTE(spd_byte_index).
                set_DIMM_TARGET(i_target),
                "%s %s Byte %d, Data returned: %d.",
                c_str(i_target),
                err_str,
                spd_byte_index,
                spd_data);

fapi_try_exit:
    return fapi2::current_err;

} // invalid_value_fail()

///
/// @brief      Checks conditional passes and implements traces if it fails
/// @tparam     T spd_data, of any size
/// @param[in]  const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
///             bool conditional
///             size_t spd_byte_index
///             const char* err_str
/// @return     void
///
template< typename T >
inline void valid_value_warn(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                             bool conditional,
                             size_t spd_byte_index,
                             T spd_data,
                             const char* err_str)
{
    // Don't print warning conditional is true
    if(!conditional)
    {
        FAPI_IMP("%s. %s. Byte %d, Data returned: %d.",
                 c_str(i_target),
                 err_str,
                 spd_byte_index,
                 spd_data );
    }
}// valid_value_warn

}// spd
}// check
}// mss

#endif
