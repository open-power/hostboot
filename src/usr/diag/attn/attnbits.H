/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/attnbits.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
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
}
#endif
