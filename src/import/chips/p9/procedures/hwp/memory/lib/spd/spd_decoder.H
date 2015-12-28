/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/spd/spd_decoder.H $        */
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

///
/// @file spd_decoder.H
/// @brief SPD decoder declarations
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_SPD_DECODER_H_
#define _MSS_SPD_DECODER_H_

#include <fapi2.H>
#include <cstdint>

namespace mss
{
namespace spd
{


enum constants : uint64_t
{
    // Byte 0
    BYTES_USED_START = 4,
    BYTES_USED_LEN = 4,

    BYTES_TOTAL_START = 1,
    BYTES_TOTAL_LEN = 3,

    BYTES_RESERVED_START = 0,
    BYTES_RESERVED_LEN = 1,

    // Byte 1 & 2 not used now

    // Byte 3
    BASE_MODULE_START = 4,
    BASE_MODULE_LEN = 4,

    HYBRID_MEDIA_START = 1,
    HYBRID_MEDIA_LEN = 3,

    HYBRID_START = 0,
    HYBRID_LEN = 1,

    // Byte 4
    SDRAM_CAPACITY_START = 4,
    SDRAM_CAPACITY_LEN = 4,

    SDRAM_BANKS_START = 2,
    SDRAM_BANKS_LEN = 2,

    BANK_GROUP_START = 0,
    BANK_GROUP_LEN = 2,

    // Byte 5
    COL_ADDRESS_START = 5,
    COL_ADDRESS_LEN = 3,

    ROW_ADDRESS_START = 2,
    ROW_ADDRESS_LEN = 3,

    ADDRESS_RESERVED_START = 0,
    ADDRESS_RESERVED_LEN = 2,

    // Byte 6
    PRIM_PRIM_SIGNAL_LOAD_START = 5,
    PRIM_PRIM_SIGNAL_LOAD_LEN = 2,

    PACKAGE_RESERVE_START = 4,
    PACKAGE_RESERVE_LEN = 2,

    PRIM_DIE_COUNT_START = 1,
    PRIM_DIE_COUNT_LEN = 3,

    PRIM_PACKAGE_TYPE_START = 0,
    PRIM_PACKAGE_TYPE_LEN = 1,

    // Byte 7
    MAC_START = 4,
    MAC_LEN = 4,

    TMAW_START = 2,
    TMAW_LEN = 2,

    OPT_FEAT_RESERVED_START = 0,
    OPT_FEAT_RESERVED_LEN = 2,

    // Byte 8 reserved

    // Byte 9
    PPR_RESERVED_START = 3,
    PPR_RESERVED_LEN = 5,

    SOFT_PPR_START = 2,
    SOFT_PPR_LEN = 1,

    PPR_START = 0,
    PPR_LEN = 2,

    // Byte 10
    SEC_SIGNAL_LOAD_START = 5,
    SEC_SIGNAL_LOAD_LEN = 2,

    DENSITY_RATIO_START = 4,
    DENSITY_RATIO_LEN = 2,

    SEC_DIE_COUNT_START = 1,
    SEC_DIE_COUNT_LEN = 3,

    SEC_PACKAGE_TYPE_START = 0,
    SEC_PACKAGE_TYPE_LEN = 1,

    // Byte 11
    OPERABLE_START = 7,
    OPERABLE_LEN = 1,

    ENDURANT_START = 6,
    ENDURANT_LEN = 1,

    NOM_VOLT_START = 0,
    NOM_VOLT_LEN = 6,

    // Byte 12
    SDRAM_WIDTH_START = 5,
    SDRAM_WIDTH_LEN = 3,

    PACKAGE_RANKS_START = 2,
    PACKAGE_RANKS_LEN = 3,

    RANK_MIX_START = 1,
    RANK_MIX_LEN = 1,

    MODULE_ORG_RESERVED_START = 0,
    MODULE_ORG_RESERVED_LEN = 1,

    // Byte 13
    BUS_WIDTH_START = 6,
    BUS_WIDTH_LEN = 2,

    BUS_EXT_WIDTH_START = 3,
    BUS_EXT_WIDTH_LEN = 2,

    BUS_WIDTH_RESERVED_START = 0,
    BUS_WIDTH_RESERVED_LEN = 3,

    // Byte 14
    THERM_SENSOR_RESERV_START = 1,
    THERM_SENSOR_RESERV_LEN = 7,

    THERM_SENSOR_START = 0,
    THERM_SENSOR_LEN = 1,

    // Byte 15
    EXT_MOD_TYPE_START = 5,
    EXT_MOD_TYPE_LEN = 3,

    EXT_MOD_TYPE_RESERV_START = 0,
    EXT_MOD_TYPE_RESERV_LEN = 4,

    // Byte 16 - reserved

    // Byte 17
    FINE_TIMEBASE_START = 6,
    FINE_TIMEBASE_LEN = 2,

    MED_TIMEBASE_START = 4,
    MED_TIMEBASE_LEN = 2,

    TIMEBASE_RESERV_START = 0,
    TIMEBASE_RESERV_LEN = 4,

    // Byte 18 -  bits not decoded
    // Byte 19 -  bits not decoded

    // Byte 20-23
    CAS_BYTE_1_START = 55,
    CAS_BYTE_1_LEN = 8,
    CAS_BYTE_2_START = 47,
    CAS_BYTE_2_LEN = 8,
    CAS_BYTE_3_START = 39,
    CAS_BYTE_3_LEN = 8,
    CAS_BYTE_4_START = 31,
    CAS_BYTE_4_LEN = 8,

    // Byte 24 -  bits not decoded
    // Byte 25 -  bits not decoded
    // Byte 26 -  bits not decoded

    // Byte 27
    TRCMIN_MSN_START = 0, // MSN = most significant nibble
    TRCMIN_MSN_LEN = 4,

    TRASMIN_MSN_START = 4, // MSN = most significant nibble
    TRASMIN_MSN_LEN = 4,

    // Byte 28
    TRASMIN_LSB_START = 4, // LSB = least significant byte
    TRASMIN_LSB_LEN = 8,

    // Byte 29
    TRCMIN_LSB_START = 4, // LSB = least significant byte
    TRCMIN_LSB_LEN = 8,

    // Byte 30
    //  TRFC1MIN_LSB_START
    //  TRFC1MIN_LSB_LEN

    // Byte 31
//   TRFC1MIN_MSB_START
//   TRFC1MIN_MSB_LEN

    // Bytes 46 - 59 - reserved

    // Bytes 60 - 77 - Connector to SDRAM Bit Mapping ??

    // Bytes 78 - 116 - reserved

    // Bytes 117 - 125 : bits not decoded

    // Bytes 128 ~ 191 Module-Specific Section ??

    // Bytes 192 ~ 255 Hybrid Memory Architecture Specific Parameters ??

    // Bytes 256 ~ 319 Extended Function Parameter Block ??

    // Bytes 320 ~ 383 Module Supplier’s Data ??
};


class decoder
{

    public:
        // Constructor
        decoder() = default;
        // Deconstructor
        virtual ~decoder() = default;

        // Methods
        virtual fapi2::ReturnCode number_of_bytes(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                const uint8_t* i_spd_data,
                const size_t i_read_spd_size);

        virtual fapi2::ReturnCode revision(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                                           const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode dram_device_type(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode module_type(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                                              const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode sdram_density(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                                                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode sdram_addressing(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode primary_package_type(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode sdram_optional_features(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode thermal_and_refresh_options(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode other_optional_features(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode secondary_package_type(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode module_nominal_voltage(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode module_organization(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode module_memory_bus_width(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode module_thermal_sensor(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode extended_module_type(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode timebases(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                                            const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode min_cycle_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode max_cycle_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode min_cas_latency_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                const uint8_t* i_spd_data);

        // Note: Yet to be implemented methods
#if 0

        virtual fapi2::ReturnCode supported_cas_latencies(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                const uint8_t* i_spd_data);


        virtual fapi2::ReturnCode min_ras_to_cas_delay_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode min_row_precharge_delay_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode upper_nibble_tRAS_tRC(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode min_activate_to_activate_refresh_delay_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>&
                i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode min_activate_to_precharge_delay_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>&
                i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode min_refresh_recovery_delay_time_1(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode min_refresh_recovery_delay_time_2(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode min_refresh_recovery_delay_time_4(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode min_four_activate_window_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode min_act_to_act_delay_time_diff_bank_group(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>&
                i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode min_act_to_act_delay_time_same_bank_group(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>&
                i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode min_cas_to_cas_delay_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode min_write_recovery_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode min_write_to_read_time_diff_bank_group(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>&
                i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode min_write_recovery_time_same_bank_group(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>&
                i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode connector_to_sdram_bit_mapping(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode offset_for_min_cas_to_cas_delay_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>&
                i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode offset_min_act_to_act_delay_time_diff_bank_gp(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>&
                i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode offset_min_act_to_act_delay_time_same_bank_gp(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>&
                i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode offset_for_min_act_to_act_refresh_delay_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>&
                i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode offset_for_min_row_precharge_delay_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>&
                i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode offset_for_min_ras_to_cas_delay_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>&
                i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode offset_for_min_cas_latency_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode offset_for_min_cycle_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode offset_for_max_cycle_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                const uint8_t* i_spd_data);

        virtual fapi2::ReturnCode crc_for_base_config_section(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target_dimm,
                const uint8_t* i_spd_data);
#endif
};

}// spd
}// mss

#endif //_MSS_SPD_DECODER_H_
