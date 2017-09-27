/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/common/attnbits.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2017                        */
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
#ifndef ATTN_ATTNBITS_H
#define ATTN_ATTNBITS_H

/**
 * @file attnbits.H
 *
 * @brief Utility functions and types provided by the attnbits module.
 */

namespace ATTN
{
namespace IPOLL
{

/**
 * @brief address IPOLL mask register SCOM address.
 */
extern const uint64_t address;

/**
 * @brief getCheckbits Obtain the associated mask bit(s) in the ipoll
 *                     mask register.
 *
 * @param[in] i_type The attention type for which to obtain the mask bit(s).
 * @param[out] o_bits The mask bits associated with the attention type.
 *
 * @retval[true] Bits found for supplied attention type.
 * @retval[false] No bits found for supplied attention type.
 */
bool getCheckbits(
        uint64_t i_type,
        uint64_t & o_bits);

/**
 * @brief forEach Call a function for each masked attention type
 *                 in the ipoll mask register.
 *
 * @param[in] i_scomData The register content to decode.
 * @param[in] i_data User pointer.
 * @param[in] i_func User function.
 */
void forEach(
        uint64_t i_scomData,
        void * i_data,
        void (*i_func)(uint64_t, void *));
}

namespace GFIR
{

/**
 * @brief getAddress Get the GFir address for the given attention type.
 *
 * @param[in] i_type The type for which to obtain the address.
 * @param[out] o_address The address associated with the attention type.
 *
 * @retval[false] No address found for the supplied attention type.
 * @retval[true] Address found for the supplied attention type.
 */
bool getAddress(
        uint64_t i_type,
        uint64_t & o_address);

/**
 * @brief getCheckbits Obtain the associated bits for the given
 *                               attention type.
 *
 * @param[in] i_type The attention type for which to obtain the bits.
 * @param[out] o_bits The bits associated with the attention type.
 *
 * @retval[false] No bits found for the supplied attention type.
 * @retval[true] Bits found for the supplied attention type.
 */
bool getCheckbits(
        uint64_t i_type,
        uint64_t & o_bits);
}

namespace MC
{
/**
 * @brief First MC chiplet bits in broadcast read
 */
extern const uint64_t firstChiplet;

/**
 * @brief Total Number of MC chiplets
 */
extern const uint64_t numChiplets;
}



// @TODO RTC: 180469
// Remove MCI address space and then update all the CXX testing
namespace MCI
{

/**
 * @brief address MCI FIR register SCOM address.
 */
extern const uint64_t address;

/**
 * @brief getCheckbits Obtain the associated mask bit(s) in the MCI Fir.
 *
 * @param[in] i_type The attention type for which to obtain the mask bit(s).
 * @param[out] o_bits The mask bits associated with the attention type.
 *
 * @retval[true] Bits found for supplied attention type.
 * @retval[false] No bits found for supplied attention type.
 */
bool getCheckbits(
        uint64_t i_type,
        uint64_t & o_bits);

/**
 * @brief forEach Call a function for each membuf attention
 *          type reported by the MCI FIR.
 *
 * @param[in] i_scomData The register content to decode.
 * @param[in] i_data User pointer.
 * @param[in] i_func User function.
 */
void forEach(
        uint64_t i_scomData,
        void * i_data,
        void (*i_func)(uint64_t, void *));
}


// @TODO RTC: 180469
// Remove GP1  address space and then update all the CXX testing
namespace GP1
{

/**
 * @brief address GP1 nest register SCOM address.
 */
extern const uint64_t address;

/**
 * @brief forEach Call a function for each MCS position reporting
 *                  an attention.
 *
 * @param[in] i_scomData The register content to decode.
 * @param[in] i_data User pointer.
 * @param[in] i_func User function.
 */
void forEach(
        uint64_t i_scomData,
        void * i_data,
        void (*i_func)(uint64_t, void *));

/**
 * @brief getCheckbits Obtain the associated mask bit(s) in the GP1 nest
 *        register.
 *
 * @param[in] i_pos The MCS position for which to obtain the mask bit(s).
 * @param[out] o_bits The mask bits associated with the MCS position.
 *
 * @retval[true] Bits found for supplied MCS position.
 * @retval[false] No bits found for supplied MCS position.
 */
bool getCheckbits(
        uint64_t i_pos,
        uint64_t & o_bits);
}


/**
 * @brief Interrupt config related constants
 */
enum
{
    // PIB interrupt register (spec/recov/chkstop)
    PIB_INTR_TYPE_REG                = 0x000F001A,

    // IPOLL MASK register
    IPOLL_MASK_REG                   = 0x000F0033,
    // (IPOLL) Error status reg
    IPOLL_STATUS_REG                 = 0x000F0034,
};


/**
 * @brief Values used to indicate the bits used in
 *        the IPOLL mask and status registers.
 */
enum
{
    IPOLL_CHECK_STOP     = 0x8000000000000000ull,
    IPOLL_RECOVERABLE    = 0x4000000000000000ull,
    IPOLL_SPECIAL        = 0x2000000000000000ull,
    IPOLL_UNIT_CS        = 0x1000000000000000ull,
    IPOLL_HOST_ATTN      = 0x0800000000000000ull,

    IPOLL_ROUTE_TO_HOST  = 0x0400000000000000ull,

    IPOLL_SP_CHECK_STOP  = 0x0200000000000000ull,
    IPOLL_SP_RECOVERABLE = 0x0100000000000000ull,
    IPOLL_SP_SPECIAL     = 0x0080000000000000ull,
    IPOLL_SP_UNIT_CS     = 0x0040000000000000ull,
    IPOLL_SP_HOST_ATTN   = 0x0020000000000000ull,

    IPOLL_ROUTE_TO_SP    = 0x0010000000000000ull
};


}
#endif
