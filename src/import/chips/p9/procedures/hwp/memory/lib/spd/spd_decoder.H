/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/spd/spd_decoder.H $        */
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
#include <map>
#include <memory>

namespace mss
{
namespace spd
{


enum BYTE_EXTRACT : uint64_t
{
    // Byte 0
    BYTES_USED_START = 4,
    BYTES_USED_LEN = 4,

    BYTES_TOTAL_START = 1,
    BYTES_TOTAL_LEN = 3,

    BYTES_RESERVED_START = 0,
    BYTES_RESERVED_LEN = 1,

    // Byte 1
    ENCODING_LEVEL_START = 0,
    ENCODING_LEVEL_LEN = 4,

    ADDITIONS_LEVEL_START = 4,
    ADDITIONS_LEVEL_LEN = 4,

    // Byte 2 - Entire byte used

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
    PRIM_SIGNAL_LOAD_START = 6,
    PRIM_SIGNAL_LOAD_LEN = 2,

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
    BUS_WIDTH_START = 5,
    BUS_WIDTH_LEN = 3,

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

    // Byte 18 -  Entire byte used
    // Byte 19 -  Entire byte used

    // Byte 20-23
    CAS_BYTE_1_START = 56,
    CAS_BYTE_1_LEN = 8,
    CAS_BYTE_2_START = 48,
    CAS_BYTE_2_LEN = 8,
    CAS_BYTE_3_START = 40,
    CAS_BYTE_3_LEN = 8,
    CAS_BYTE_4_START = 32,
    CAS_BYTE_4_LEN = 8,

    // Byte 24 -  Entire byte used
    // Byte 25 -  Entire byte used
    // Byte 26 -  Entire byte used

    // Byte 27
    TRASMIN_MSN_START = 4, // MSN = most significant nibble
    TRASMIN_MSN_LEN = 4,

    TRCMIN_MSN_START = 0, // MSN = most significant nibble
    TRCMIN_MSN_LEN = 4,

    // Byte 28
    TRASMIN_LSB_START = 0, // LSB = least significant byte
    TRASMIN_LSB_LEN = 8,

    // Byte 29
    TRCMIN_LSB_START = 0, // LSB = least significant byte
    TRCMIN_LSB_LEN = 8,

    // Byte 30
    TRFC1MIN_LSB_START = 0,
    TRFC1MIN_LSB_LEN = 8,

    // Byte 31
    TRFC1MIN_MSB_START = 0,
    TRFC1MIN_MSB_LEN = 8,

    // Byte 32
    TRFC2MIN_LSB_START = 0,
    TRFC2MIN_LSB_LEN = 8,

    // Byte 33
    TRFC2MIN_MSB_START = 0,
    TRFC2MIN_MSB_LEN = 8,

    // Byte 34 & Byte 35
    TRFC4MIN_LSB_START = 0,
    TRFC4MIN_LSB_LEN = 8,

    TRFC4MIN_MSB_START = 0,
    TRFC4MIN_MSB_LEN = 8,

    // Byte 36
    TFAWMIN_MSN_START = 4,
    TFAWMIN_MSN_LEN = 4,

    // Byte 37
    TFAWMIN_LSB_START = 0,
    TFAWMIN_LSB_LEN = 8,

    // Byte 38 - Entire byte used
    // Byte 39 - Entire byte used
    // Byte 40 - Entire byte used

    // Byte 41
    TWRMIN_MSN_START = 4, // MSN = most significant nibble
    TWRMIN_MSN_LEN = 4,

    // Byte 42
    TWRMIN_LSB_START = 0, // LSB = least significant nibble
    TWRMIN_LSB_LEN = 8,

    // Byte 43
    TWTRMIN_L_MSN_START = 0, // MSN = most significant nibble
    TWTRMIN_L_MSN_LEN = 4,

    TWTRMIN_S_MSN_START = 4, // MSN = most significant nibble
    TWTRMIN_S_MSN_LEN = 4,

    // Byte 44
    TWTRMIN_S_LSB_START = 0, // LSB = least significant byte
    TWTRMIN_S_LSB_LEN = 8,

    // Byte 45
    TWTRMIN_L_LSB_START = 0,
    TWTRMIN_L_LSB_LEN = 8,

    // Bytes 46 - 59 - reserved

    // Bytes 60 - 77 - Connector to SDRAM Bit Mapping ??

    // Bytes 78 - 116 - reserved

    // Bytes 117 - 125 : Entire byte used

    // Byte 126
    CRC_MSB_START = 0,
    CRC_MSB_LEN = 8,

    // Byte 127
    CRC_LSB_START = 0,
    CRC_LSB_LEN = 8,

    // Bytes 128 ~ 191 Module-Specific Section ??

    // Bytes 192 ~ 255 Hybrid Memory Architecture Specific Parameters ??

    // Bytes 256 ~ 319 Extended Function Parameter Block ??

    // Bytes 320 ~ 383 Module Supplier’s Data ??
};

enum SDRAM_PACKAGE_TYPE : uint64_t
{
    // Signal loading
    MONOLITHIC = 0,
    NON_MONOLITHIC = 1,

    // Package Type
    UNSPECIFIED = 0,
    MULTI_LOAD_STACK = 1,
    SINGLE_LOAD_STACK = 2,
};

enum NOMINAL_VOLTAGE : uint64_t
{
    NOT_OPERABLE = 0,
    OPERABLE = 1,

    NOT_ENDURANT = 0,
    ENDURANT = 1
};


///
/// @class decoder
/// @brief Base SPD DRAM decoder
///
class decoder
{

    public:
        std::vector<uint8_t> iv_spd_data;

        // Constructor
        decoder() = default;

        // Deconstructor
        virtual ~decoder() = default;

        /////////////////////////
        // Member Methods
        /////////////////////////

        ///
        /// @brief      Decodes number of used SPD bytes
        /// @param[in]  i_target dimm target
        /// @param[out] o_value number of SPD bytes used
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       Decodes SPD Byte 0 (3~0)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 14
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode number_of_used_bytes(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint16_t& o_value);

        ///
        /// @brief      Decodes total number of SPD bytes
        /// @param[in]  i_target dimm target
        /// @param[out] o_value number of total SPD bytes
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       Decodes SPD Byte 0 (bits 6~4)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 14
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode number_of_total_bytes(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint16_t& o_value);

        ///
        /// @brief       Decodes DRAM Device Type
        /// @param[in]   i_target dimm target
        /// @param[out]  o_value dram device type enumeration
        /// @return      FAPI2_RC_SUCCESS if okay
        /// @note        Decodes SPD Byte 2
        /// @note        Item JC-45-2220.01x
        /// @note        Page 16
        /// @note        DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode dram_device_type(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);

        ///
        /// @brief      Decodes hybrid media field from SPD
        /// @param[in]  i_target
        /// @param[out] o_value
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       Decodes SPD Byte 3 (bits 6~4)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 17
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode hybrid_media(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                               uint8_t& o_value);
        ///
        /// @brief      Decodes hybrid field from SPD
        /// @param[in]  i_target
        /// @param[out] o_value
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       Decodes SPD Byte 3 (bit 7)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 17
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode hybrid(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                         uint8_t& o_value);
        ///
        /// @brief      Decodes SDRAM density from SPD
        /// @param[in]  i_target dimm target
        /// @param[out] o_value SDRAM density in GBs
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 4 (bits 3~0)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 18
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode sdram_density(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                                uint8_t& o_value);
        ///
        /// @brief      Decodes number of SDRAM banks from SPD
        /// @param[in]  i_target dimm target
        /// @param[out] o_value Number of SDRAM banks
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 4 (bits 5~4)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 18
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode banks(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                        uint8_t& o_value);

        ///
        /// @brief      Decodes number of SDRAM bank groups from SPD
        /// @param[in]  i_target dimm target
        /// @param[out] o_value Number of SDRAM bank groups
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 4 (bits 7~6)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 18
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode bank_groups(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                              uint8_t& o_value);
        ///
        /// @brief      Decodes number of SDRAM column address bits
        /// @param[in]  i_target dimm target
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 5 (bits 2~0)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 18
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode column_address_bits(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);
        ///
        /// @brief      Decodes number of SDRAM row address bits
        /// @param[in]  i_target dimm target
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 5 (bits 5~3)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 18
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode row_address_bits(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);
        ///
        /// @brief      Decodes Primary SDRAM signal loading
        /// @param[in]  i_target dimm target
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 6 (bits 1~0)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 19
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode prim_sdram_signal_loading(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);
        ///
        /// @brief      Decodes Primary SDRAM die count
        /// @param[in]  i_target dimm target
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 6 (bits 6~4)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 19
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual  fapi2::ReturnCode prim_sdram_die_count(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);
        ///
        /// @brief      Decodes Primary SDRAM package type
        /// @param[in]  i_target dimm target
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 6 (bit 7)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 19
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode prim_sdram_package_type(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);
        ///
        /// @brief      Decode SDRAM Maximum activate count
        /// @param[in]  i_target dimm target
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 7 (bits 3~0)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 20
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode maximum_activate_count(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint32_t& o_value);
        ///
        /// @brief      Decode SDRAM Maximum activate window (multiplier), tREFI uknown at this point
        /// @param[in]  i_target
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 7 (bits 3~0)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 20
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode maximum_activate_window_multiplier(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint32_t& o_value);
        ///
        /// @brief      Decode Soft post package repair (soft PPR)
        /// @param[in]  i_target dimm target
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 9 (bit 5)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 21
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode soft_post_package_repair(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);
        ///
        /// @brief      Decode Post package repair (PPR)
        /// @param[in]  i_target dimm target
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 9 (bits 7~6)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 21
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode post_package_repair(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);
        ///
        /// @brief      Decodes Secondary SDRAM signal loading
        /// @param[in]  i_target dimm target
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 10 (bits 1~0)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 22
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode sec_sdram_signal_loading(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);
        ///
        /// @brief      Decodes Secondary DRAM Density Ratio
        /// @param[in]  i_target dimm target
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 10 (bits 3~2)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 22
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode sec_dram_density_ratio(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);
        ///
        /// @brief      Decodes Secondary SDRAM die count
        /// @param[in]  i_target dimm target
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 10 (bits 6~4)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 22
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode sec_sdram_die_count(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);
        ///
        /// @brief      Decodes Secondary SDRAM package type
        /// @param[in]  i_target dimm target
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 10 (bit 7)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 22
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode sec_sdram_package_type(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);
        ///
        /// @brief      Decode Module Nominal Voltage, VDD
        /// @param[in]  i_target dimm target
        /// @param[out] o_value enum representing if 1.2V is operable
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 11 (bit 0)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 23
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode operable_nominal_voltage(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);
        ///
        /// @brief      Decode Module Nominal Voltage, VDD
        /// @param[in]  i_target dimm target
        /// @param[out] o_value enum representing if 1.2V is endurant
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 11 (bit 1)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 23
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode endurant_nominal_voltage(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);
        ///
        /// @brief      Decodes SDRAM device width
        /// @param[in]  i_target dimm target
        /// @param[out] o_value device width in bits
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 12 (bits 2~0)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 23
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode device_width(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                               uint8_t& o_value);
        ///
        /// @brief      Decodes number of package ranks per DIMM
        /// @param[in]  i_target dimm target
        /// @param[out] o_value number of package ranks per DIMM
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 12 (bits 5~3)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 23
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode num_package_ranks_per_dimm(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);
        ///
        /// @brief      Decodes Rank Mix
        /// @param[in]  i_target dimm target
        /// @param[out] o_value rank mix value from SPD
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 12 (bit 6)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 23
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode rank_mix(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                           uint8_t& o_value);
        ///
        /// @brief      Decodes primary bus width
        /// @param[in]  i_target dimm target
        /// @param[out] o_value primary bus width in bits
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 13 (bits 2~0)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 27
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode prim_bus_width(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);
        ///
        /// @brief      Decodes bus width extension
        /// @param[in]  i_target dimm target
        /// @param[out] o_value bus width extension in bits
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 13 (bits 4~3)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 27
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode bus_width_extension(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);
        ///
        /// @brief      Decode Module Thermal Sensor
        /// @param[in]  i_target dimm target
        /// @param[out] o_value thermal sensor value from SPD
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 14 (bit 7)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 28
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode thermal_sensor(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);
        ///
        /// @brief      Decode Extended Base Module Type
        /// @param[in]  i_target dimm target
        /// @param[out] o_value extended base module type value from SPD
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 15 (bits 3~0)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 28
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode extended_base_module_type(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);
        ///
        /// @brief      Decode Fine Timebase
        /// @param[in]  i_target dimm target
        /// @param[out] o_value fine_timebase from SPD in picoseconds
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 17 (bits 1~0)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 29
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode fine_timebase(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                                int64_t& o_value);
        ///
        /// @brief      Decode Medium Timebase
        /// @param[in]  i_target dimm target
        /// @param[out] o_value fine_timebase from SPD in picoseconds
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 17 (bits 3~2)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 29
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode medium_timebase(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);
        ///
        ///
        /// @brief      Decodes SDRAM Minimum Cycle Time in MTB
        /// @param[in]  i_target dimm target
        /// @param[out] o_value tCKmin in MTB units
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 18
        /// @note       Item JC-45-2220.01x
        /// @note       Page 31-32
        /// @note       DDR4 SPD Document Release 3
        /// @warning    If tCKmin cannot be divided evenly by the MTB,
        ///             this byte must be rounded up to the next larger
        ///             integer and the Fine Offset for tCKmin (SPD byte 125)
        ///             used for correction to get the actual value.
        ///
        virtual fapi2::ReturnCode min_cycle_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);

        ///
        /// @brief      Decodes SDRAM Maximum Cycle Time in MTB
        /// @param[in]  i_target dimm target
        /// @param[out] o_value tCKmax in MTB units
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 19
        /// @note       Item JC-45-2220.01x
        /// @note       Page 32
        /// @note       DDR4 SPD Document Release 3
        /// @warning    If tCKmax cannot be divided evenly by the MTB,
        ///             this byte must be rounded up to the next larger
        ///             integer and the Fine Offset for tCKmax (SPD byte 124)
        ///             used for correction to get the actual value.
        ///
        virtual fapi2::ReturnCode max_cycle_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);
        ///
        /// @brief      Decode CAS Latencies Supported
        /// @param[in]  i_target dimm target
        /// @param[out] o_value bitmap of supported CAS latencies
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Bytes 20-23
        /// @note       Item JC-45-2220.01x
        /// @note       Page 33-34
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode supported_cas_latencies(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint64_t& o_value);
        ///
        /// @brief      Decodes SDRAM Minimum CAS Latency Time in MTB
        /// @param[in]  i_target dimm target
        /// @param[out] o_value tAAmin in MTB units
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 24
        /// @note       Item JC-45-2220.01x
        /// @note       Page 34
        /// @note       DDR4 SPD Document Release 3
        /// @warning    If tAAmin cannot be divided evenly by the MTB,
        ///             this byte must be rounded up to the next larger
        ///             integer and the Fine Offset for tAAmin (SPD byte 123)
        ///             used for correction to get the actual value.
        ///
        virtual fapi2::ReturnCode min_cas_latency_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);
        ///
        /// @brief      Decodes SDRAM Minimum RAS to CAS Delay Time in MTB
        /// @param[in]  i_target dimm target
        /// @param[out] o_value tRCDmin in MTB units
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 25
        /// @note       Item JC-45-2220.01x
        /// @note       Page 35
        /// @note       DDR4 SPD Document Release 3
        /// @warning    If tRCDmin cannot be divided evenly by the MTB,
        //              this byte must be rounded up to the next larger
        ///             integer and the Fine Offset for tRCDmin (SPD byte 122)
        ///             used for correction to get the actual value
        ///
        virtual fapi2::ReturnCode min_ras_to_cas_delay_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);
        ///
        /// @brief      Decodes SDRAM Minimum Row Precharge Delay Time in MTB
        /// @param[in]  i_target dimm target
        /// @param[out] o_value tRPmin in MTB units
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 26
        /// @note       Item JC-45-2220.01x
        /// @note       Page 36-37
        /// @note       DDR4 SPD Document Release 3
        /// @warning    If tRPmin cannot be divided evenly by the MTB,
        //              this byte must be rounded up to the next larger
        ///             integer and the Fine Offset for tRPmin (SPD byte 121)
        ///             used for correction to get the actual value
        ///
        virtual fapi2::ReturnCode min_row_precharge_delay_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);
        ///
        /// @brief      Decodes SDRAM Minimum Active to Precharge Delay Time in MTB
        /// @param[in]  i_target dimm target
        /// @param[out] o_value tRASmin in MTB units
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 28 (bits 7~4) & SPD Byte 27 (bits 3~0)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 38
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode min_active_to_precharge_delay_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);
        ///
        /// @brief      Decodes SDRAM Minimum Active to Active/Refresh Delay Time in MTB
        /// @param[in]  i_target dimm target
        /// @param[out] o_value tRCmin in MTB units
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 27 (bits 7~4) & SPD Byte 29 (bits 7~0)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 38
        /// @note       DDR4 SPD Document Release 3
        /// @warning    If tRCmin cannot be divided evenly by the MTB,
        ///             this byte must be rounded up to the next larger
        ///             integer and the Fine Offset for tRCmin (SPD byte 120)
        ///             used for correction to get the actual value.
        ///
        virtual
        fapi2::ReturnCode min_active_to_active_refresh_delay_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);
        ///
        /// @brief      Decodes SDRAM Minimum Refresh Recovery Delay Time 1
        /// @param[in]  i_target dimm target
        /// @param[out] o_value tRFC1min in MTB units
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 30 & Byte 31
        /// @note       Item JC-45-2220.01x
        /// @note       Page 39-40
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode min_refresh_recovery_delay_time_1(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);
        ///
        /// @brief      Decodes SDRAM Minimum Refresh Recovery Delay Time 2
        /// @param[in]  i_target dimm target
        /// @param[out] o_value tRFC2min in MTB units
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 32 & Byte 33
        /// @note       Item JC-45-2220.01x
        /// @note       Page 40
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode min_refresh_recovery_delay_time_2(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);
        ///
        /// @brief      Decodes SDRAM Minimum Refresh Recovery Delay Time 4
        /// @param[in]  i_target dimm target
        /// @param[out] o_value tRFC4min in MTB units
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 34 & Byte 35
        /// @note       Item JC-45-2220.01x
        /// @note       Page 40
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode min_refresh_recovery_delay_time_4(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);
        ///
        /// @brief      Decodes SDRAM Minimum Four Activate Window Delay Time
        /// @param[in]  i_target dimm target
        /// @param[out] o_value tFAWmin in MTB units
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 36 (bits 3~0) & Byte 37 (bits 7~0)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 42
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode min_tfaw(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                           int64_t& o_value);
        ///
        /// @brief      Decodes Minimum Activate to Activate Delay Time - Different Bank Group
        /// @param[in]  i_target dimm target
        /// @param[out] o_value tRRD_Smin MTB units
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 38
        /// @note       Item JC-45-2220.01x
        /// @note       Page 43
        /// @note       DDR4 SPD Document Release 3
        /// @warning    If tRRD_Smin cannot be divided evenly by the MTB,
        ///             this byte must be rounded up to the next larger
        ///             integer and the Fine Offset for tRRD_Smin (SPD byte 119)
        ///             used for correction to get the actual value.
        ///
        virtual fapi2::ReturnCode min_trrd_s(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                             int64_t& o_value);
        ///
        /// @brief      Decodes Minimum Activate to Activate Delay Time - Same Bank Group
        /// @param[in]  i_target dimm target
        /// @param[out] o_value tRRD_Lmin MTB units
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 39
        /// @note       Item JC-45-2220.01x
        /// @note       Page 43-44
        /// @note       DDR4 SPD Document Release 3
        /// @warning    If tRRD_Lmin cannot be divided evenly by the MTB,
        ///             this byte must be rounded up to the next larger
        ///             integer and the Fine Offset for tRRD_Lmin (SPD byte 118)
        ///             used for correction to get the actual value.
        ///
        virtual fapi2::ReturnCode min_trrd_l(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                             int64_t& o_value);
        ///
        /// @brief      Decodes Minimum CAS to CAS Delay Time - Same Bank Group
        /// @param[in]  i_target dimm target
        /// @param[out] o_value tCCD_Lmin MTB units
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 40
        /// @note       Item JC-45-2220.01x
        /// @note       Page 44-45
        /// @note       DDR4 SPD Document Release 3
        /// @warning    If tCCD_Lmin cannot be divided evenly by the MTB,
        ///             this byte must be rounded up to the next larger
        ///             integer and the Fine Offset for tCCD_Lmin (SPD byte 117)
        ///             used for correction to get the actual value.
        ///
        virtual fapi2::ReturnCode min_tccd_l(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                             int64_t& o_value);
        ///
        /// @brief      Decodes Minimum Write Recovery Time
        /// @param[in]  i_target dimm target
        /// @param[out] o_value tWRmin in MTB units
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 41 (bits 3~0) & Byte 42 (bits 7~0)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 40
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode min_write_recovery_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);
        ///
        /// @brief      Decodes Minimum Write to Read Time - Different Bank Group
        /// @param[in]  i_target dimm target
        /// @param[out] o_value tWRT_Smin in MTB units
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 43 (bits 3~0) & Byte 44 (bits 7~0)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 40
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode min_twtr_s(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                             int64_t& o_value);

        ///
        /// @brief      Decodes Minimum Write to Read Time - Same Bank Group
        /// @param[in]  i_target dimm target
        /// @param[out] o_value tWRT_Lmin in MTB units
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 43 (bits 7~4) & Byte 45 (bits 7~0)
        /// @note       Item JC-45-2220.01x
        /// @note       Page 46
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode min_twtr_l(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                             int64_t& o_value);
        ///
        /// @brief      Decodes Fine Offset for Minimum CAS to CAS Delay Time - Same Bank Group
        /// @param[in]  i_target dimm target
        /// @param[out] o_value tCCD_Lmin offset in FTB units
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 117
        /// @note       Item JC-45-2220.01x
        /// @note       Page 52
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode fine_offset_min_tccd_l(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);
        ///
        /// @brief      Decodes Fine Offset for Minimum Activate to Activate Delay Time - Same Bank Group
        /// @param[in]  i_target dimm target
        /// @param[out] o_value tRRD_Lmin offset in FTB units
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 118
        /// @note       Item JC-45-2220.01x
        /// @note       Page 52
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode fine_offset_min_trrd_l(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);
        ///
        /// @brief      Decodes Fine Offset for Minimum Activate to Activate Delay Time - Different Bank Group
        /// @param[in]  i_target dimm target
        /// @param[out] o_value tRRD_Smin offset in FTB units
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 119
        /// @note       Item JC-45-2220.01x
        /// @note       Page 52
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode fine_offset_min_trrd_s(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);
        ///
        /// @brief      Decodes Fine Offset for Minimum Active to Active/Refresh Delay Time
        /// @param[in]  i_target dimm target
        /// @param[out] o_value tRCmin offset in FTB units
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 120
        /// @note       Item JC-45-2220.01x
        /// @note       Page 52
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode fine_offset_min_trc(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);
        ///
        /// @brief      Decodes Fine Offset for Minimum Row Precharge Delay Time
        /// @param[in]  i_target dimm target
        /// @param[out] o_value tRPmin offset in FTB units
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 121
        /// @note       Item JC-45-2220.01x
        /// @note       Page 52
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode fine_offset_min_trp(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);
        ///
        /// @brief      Decodes Fine Offset for SDRAM Minimum RAS to CAS Delay Time
        /// @param[in]  i_target dimm target
        /// @param[out] o_value tRCDmin offset in FTB units
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 122
        /// @note       Item JC-45-2220.01x
        /// @note       Page 52
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode fine_offset_min_trcd(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);
        ///
        /// @brief      Decodes Fine Offset for SDRAM Minimum CAS Latency Time
        /// @param[in]  i_target dimm target
        /// @param[out] o_value tAAmin offset in FTB units
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 123
        /// @note       Item JC-45-2220.01x
        /// @note       Page 52
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode fine_offset_min_taa(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);
        ///
        /// @brief      Decodes Fine Offset for SDRAM Maximum Cycle Time
        /// @param[in]  i_target dimm target
        /// @param[out] o_value tCKmax offset in FTB units
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 124
        /// @note       Item JC-45-2220.01x
        /// @note       Page 52
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode fine_offset_max_tck(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);
        ///
        /// @brief      Decodes Fine Offset for SDRAM Minimum Cycle Time
        /// @param[in]  i_target dimm target
        /// @param[out] o_value tCKmin offset in FTB units
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 125
        /// @note       Item JC-45-2220.01x
        /// @note       Page 52
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode fine_offset_min_tck(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);

        ///
        /// @brief      Decodes Cyclical Redundancy Code (CRC) for Base Configuration Section
        /// @param[in]  i_target dimm target
        /// @param[out] o_value crc value from SPD
        /// @return     FAPI2_RC_SUCCESS if okay
        /// @note       SPD Byte 127 & Byte 126
        /// @note       Item JC-45-2220.01x
        /// @note       Page 53
        /// @note       DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode cyclical_redundancy_code(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint16_t& o_value);
};// decoder


/////////////////////////
// Non-members functions
/////////////////////////

///
/// @brief       Decodes SPD Revision encoding level
/// @param[in]   i_target dimm target
/// @param[in]   i_spd_data SPD data
/// @param[out]  o_value encoding revision num
/// @return      FAPI2_RC_SUCCESS if okay
/// @note        Decodes SPD Byte 1 (3~0).
/// @note        Item JC-45-2220.01x
/// @note        Page 14-15
/// @note        DDR4 SPD Document Release 3
///
fapi2::ReturnCode rev_encoding_level(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                     const std::vector<uint8_t>& i_spd_data,
                                     uint8_t& o_value);
///
/// @brief       Decodes SPD Revision additions level
/// @param[in]   i_target dimm target
/// @param[in]   i_spd_data SPD blob
/// @param[out]  o_value additions revision num
/// @return      FAPI2_RC_SUCCESS if okay
/// @note        Decodes SPD Byte 1 (bits 7~4).
/// @note        Item JC-45-2220.01x
/// @note        Page 14-15
/// @note        DDR4 SPD Document Release 3
///
fapi2::ReturnCode rev_additions_level(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                      const std::vector<uint8_t>& i_spd_data,
                                      uint8_t& o_value);

///
/// @brief      Decodes base module type (DIMM type) from SPD
/// @param[in]  i_target dimm target
/// @param[in]  i_spd_data SPD data
/// @param[out] o_value base module type
/// @return     FAPI2_RC_SUCCESS if okay
/// @note       Decodes SPD Byte 3 (bits 3~0)
/// @note       Item JC-45-2220.01x
/// @note       Page 17
/// @note       DDR4 SPD Document Release 3
///
fapi2::ReturnCode base_module_type(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                   const std::vector<uint8_t>& i_spd_data,
                                   uint8_t& o_value);

///
/// @brief       Object factory to select correct decoder
/// @param[in]   i_target dimm target
/// @param[in]   i_spd_data SPD data
/// @param[out]  o_fact_obj shared pointer to the factory object
/// @return      FAPI2_RC_SUCCESS if okay
/// @note        Factory dependent on SPD revision & dimm type
///
fapi2::ReturnCode factory(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                          const std::vector<uint8_t>& i_spd_data,
                          std::shared_ptr<decoder>& o_fact_obj);

///
/// @brief       Creates factory object & SPD data caches
/// @param[in]   i_target the fapi2 target
/// @param[out]  o_factory_caches map of factory objects with a dimm position key
/// @return      FAPI2_RC_SUCCESS if okay
///
template<fapi2::TargetType T>
fapi2::ReturnCode populate_decoder_caches(const fapi2::Target<T>& i_target,
        std::map<uint32_t, std::shared_ptr<decoder> >& o_factory_caches,
        const std::shared_ptr<decoder>& i_pDecoder = nullptr);


}// spd
}// mss

#endif //_MSS_SPD_DECODER_H_
