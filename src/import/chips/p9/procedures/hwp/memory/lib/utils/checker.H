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
#include <mss_attribute_accessors.H>
#include <lib/shared/mss_const.H>

namespace mss
{
namespace check
{

///
/// @brief      Checks homogenous DDR4 dimm configuration (e.g. DDR4)
/// @param[in]  i_target the controller target
/// @return     FAPI2_RC_SUCCESS iff ok
///
inline fapi2::ReturnCode dram_type(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target)
{
    uint8_t l_dram_gen[PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {0};

    // Retrieve DDR4 dimm attributes
    FAPI_TRY(eff_dram_gen(i_target, &(l_dram_gen[0][0])));

    // Make sure all DRAMs are DDR4 or throw an error
    for (const auto& l_mca : i_target.getChildren<fapi2::TARGET_TYPE_MCA>())
    {
        const auto l_port_num = mss::index(l_mca);

        for (const auto& l_dimm : l_mca.getChildren<fapi2::TARGET_TYPE_DIMM>())
        {
            const auto l_dimm_num = mss::index(l_dimm);

            FAPI_INF("%s DRAM device type is %llX",
                     mss::c_str(l_dimm),
                     l_dram_gen[l_port_num][l_dimm_num]);

            // Nimbus supports only DDR4
            FAPI_ASSERT(l_dram_gen[l_port_num][l_dimm_num] == fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
                        fapi2::MSS_UNSUPPORTED_DEV_TYPE().
                        set_DEV_TYPE(l_dram_gen[l_port_num][l_dimm_num]),
                        "%s Incorrect DRAM device generation, DRAM generation is %llx",
                        mss::c_str(l_dimm),
                        l_dram_gen[l_port_num][l_dimm_num]);
        }// dimm
    }// mca

fapi_try_exit:
    return fapi2::current_err;

}// dram_type


///
/// @brief      Checks nominal voltage is correct for all DIMMs
/// @param[in]  i_target the fapi2 target
/// @param[in]  i_dimm_state (i.e. functional or non-functional)
/// @return     ReturnCode
///
inline fapi2::ReturnCode module_nominal_voltage(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        fapi2::TargetState i_dimm_state)
{

    uint64_t l_module_nom_voltage[mss::PORTS_PER_MCS][mss::MAX_DIMM_PER_PORT] = {0};

    FAPI_TRY(mss::spd_module_nominal_voltage(i_target, &l_module_nom_voltage[0][0]));

    for (const auto& l_mca : i_target.getChildren<fapi2::TARGET_TYPE_MCA>())
    {
        const auto l_port_num = mss::index(l_mca);

        for (const auto& l_dimm : l_mca.getChildren<fapi2::TARGET_TYPE_DIMM>(i_dimm_state))
        {
            const auto l_dimm_num = mss::index(l_dimm);

            FAPI_INF("%s DRAM nominal voltage (in milliseconds) is %d",
                     mss::c_str(l_dimm),
                     l_module_nom_voltage[l_port_num][l_dimm_num]);

            // All DIMMs have to be operable at 1.2 V, else don't IPL (according to Warren)
            FAPI_ASSERT( l_module_nom_voltage[l_port_num][l_dimm_num] == fapi2::ENUM_ATTR_SPD_MODULE_NOMINAL_VOLTAGE_OPERABLE,
                         fapi2::MSS_VOLT_DDR_TYPE_REQUIRED_VOLTAGE().
                         set_DIMM_VOLTAGE(l_module_nom_voltage[l_port_num][l_dimm_num]),
                         "%s.Failed conditional, data returned:o %d.",
                         mss::c_str(l_dimm),
                         l_module_nom_voltage[l_port_num][l_dimm_num] );
        }
    }

fapi_try_exit:
    return fapi2::current_err;

}// module_nominal_voltage


///
/// @brief      Checks conditional and implements traces & exits if it fails
/// @param[in]  i_target the dimm target
/// @param[in]  i_conditional conditional that we are testing against
/// @param[in]  i_key map key
/// @param[in]  i_data additional returned data
/// @param[in]  i_err_str error string to print out when conditional fails
/// @return     ReturnCode
///
inline fapi2::ReturnCode fail_for_invalid_map(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const bool i_conditional,
        const uint64_t i_key,
        const uint64_t i_data = 0,
        const char* i_err_str = "")
{
    // Invalid keys won't return useful or valid data so we allow optional data
    FAPI_ASSERT(i_conditional,
                fapi2::MSS_INVALID_KEY().
                set_KEY(i_key).
                set_DATA(i_data).
                set_DIMM_TARGET(i_target),
                "%s. %s Could not find value from key %d. Returned data: %d.",
                c_str(i_target),
                i_err_str,
                i_key,
                i_data);

fapi_try_exit:
    return fapi2::current_err;
}

namespace spd
{

///
/// @brief      Checks conditional passes and implements traces & exits if it fails
/// @tparam     T input data of any size
/// @param[in]  i_target fapi2 dimm target
/// @param[in]  i_conditional conditional that we are testing against
/// @param[in]  i_spd_byte_index current SPD byte
/// @param[in]  i_spd_data debug data
/// @param[in]  i_err_str error string to print out when conditional fails
/// @return     ReturnCode
///
template< typename T >
inline fapi2::ReturnCode fail_for_invalid_value(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const bool i_conditional,
        const size_t i_spd_byte_index,
        const T i_spd_data,
        const char* i_err_str)
{
    FAPI_ASSERT(i_conditional,
                fapi2::MSS_BAD_SPD().
                set_VALUE(i_spd_data).
                set_BYTE(i_spd_byte_index).
                set_DIMM_TARGET(i_target),
                "%s %s Byte %d, Data returned: %d.",
                c_str(i_target),
                i_err_str,
                i_spd_byte_index,
                i_spd_data);

fapi_try_exit:
    return fapi2::current_err;

} // fail_for_invalid_value()

///
/// @brief      Checks conditional passes and implements traces if it fails. No FFDC collected.
/// @tparam     T input data of any size
/// @param[in]  i_target fapi2 dimm target
/// @param[in]  i_conditional that we are testing against
/// @param[in]  i_spd_byte_index
/// @param[in]  i_spd_data debug data
/// @param[in]  i_err_str string to print out when conditional fails
/// @return     void
///
template< typename T >
inline void warn_for_invalid_value(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                   const bool i_conditional,
                                   const size_t i_spd_byte_index,
                                   const T i_spd_data,
                                   const char* i_err_str)
{
    // Don't print warning conditional is true
    if(!i_conditional)
    {
        FAPI_IMP("%s. %s. Byte %d, Data returned: %d.",
                 c_str(i_target),
                 i_err_str,
                 i_spd_byte_index,
                 i_spd_data );
    }
}// warn_for_invalid_value

///
/// @brief      Checks if valid factory parameters are given
/// @param[in]  i_target fapi2 dimm target
/// @param[in]  i_dimm_type DIMM type enumeration
/// @param[in]  i_encoding_rev SPD encoding level rev number
/// @param[in]  i_additions_rev SPD additions level rev number
/// @param[in]  i_err_str string to print out when conditional fails
/// @return     fapi2::ReturnCode
///
inline fapi2::ReturnCode invalid_factory_sel(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint8_t i_dimm_type,
        const uint8_t i_encoding_rev,
        const uint8_t i_additions_rev,
        const char* i_err_str)
{
    FAPI_ASSERT(false,
                fapi2::MSS_INVALID_DIMM_REV_COMBO().
                set_DIMM_TYPE(i_dimm_type).
                set_ENCODING_REV(i_encoding_rev).
                set_ADDITIONS_REV(i_additions_rev).
                set_DIMM_TARGET(i_target),
                "%s. %s. Invalid combination for dimm type: %d, rev: %d.%d",
                c_str(i_target),
                i_err_str,
                i_dimm_type,
                i_encoding_rev,
                i_additions_rev);
fapi_try_exit:
    return fapi2::current_err;
}// invalid_factory_sel

///
/// @brief      Checks if valid factory parameters are given
/// @param[in]  i_target fapi2 dimm target
/// @param[in]  i_dimm_type DIMM type enumeration
/// @param[in]  i_encoding_rev SPD encoding level rev number
/// @param[in]  i_additions_rev SPD additions level rev number
/// @param[in]  i_err_str string to print out when conditional fails
/// @return     fapi2::ReturnCode
///
inline fapi2::ReturnCode invalid_cache(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                       const bool i_conditional,
                                       const uint8_t i_dimm_pos)
{
    FAPI_ASSERT(i_conditional,
                fapi2::MSS_INVALID_CACHE().
                set_DIMM_POS(i_dimm_pos).
                set_DIMM_TARGET(i_target),
                "%s. Could not find SPD decoder cache for dimm pos: %d",
                c_str(i_target),
                i_dimm_pos);

fapi_try_exit:
    return fapi2::current_err;
}// invalid_factory_sel

}// spd
}// check
}// mss

#endif
