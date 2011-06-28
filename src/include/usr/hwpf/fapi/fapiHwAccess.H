/**
 *  @file fapiHwAccess.H
 *
 *  @brief Defines the hardware access functions that platform code must
 *         implement. It is a HWP requirement that these be "C" functions.
 */

#ifndef FAPIHWACCESS_H_
#define FAPIHWACCESS_H_

#include <stdint.h>
#include <fapiReturnCode.H>
#include <fapiTarget.H>
#include <ecmdDataBuffer.H>

namespace fapi
{
    /**
     * @brief Enumeration of modify modes used in modify operations
     */
    enum ChipOpModifyMode
    {
        CHIP_OP_MODIFY_MODE_OR = 1,
        CHIP_OP_MODIFY_MODE_AND = 2,
        CHIP_OP_MODIFY_MODE_XOR = 3,
    };
}

extern "C"
{

//------------------------------------------------------------------------------
// HW Communication Functions
//------------------------------------------------------------------------------

/**
 * @brief Reads a SCOM register from a Chip
 * @param[in] i_target Target to operate on
 * @param[in] i_address Scom address to read from
 * @param[out] o_data ecmdDataBufferBase object that holds data read from
 *                    address
 * @return ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode GetScom(const fapi::Target& i_target,
                         const uint64_t i_address,
                         ecmdDataBufferBase & o_data);

/**
 * @brief Writes a SCOM register on a Chip
 * @param[in] i_target Target to operate on
 * @param[in] i_address Scom address to write to
 * @param[in] i_data ecmdDataBufferBase object that holds data to write into
 *                   address
 * @return ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode PutScom(const fapi::Target& i_target,
                         const uint64_t i_address,
                         ecmdDataBufferBase & i_data);

/**
 * @brief Writes a SCOM register under mask to a chip
 * @param[in] i_target Target to operate on
 * @param[in] i_address Scom address to write to
 * @param[in] i_data ecmdDataBufferBase object that holds the data
 * @param[in] i_mask ecmdDataBufferBase object that holds the mask (i_data to
 *                   write)
 * @return ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode PutScomUnderMask(const fapi::Target& i_target,
                                  const uint64_t i_address,
                                  ecmdDataBufferBase & i_data,
                                  ecmdDataBufferBase & i_mask);


/**
 * @brief Reads a CFAM register from a chip
 * @param[in] i_target Target to operate on
 * @param[in] i_address CFAM address to read from
 * @param[out] o_data ecmdDataBufferBase object that holds data read from
 *                    address
 * @return ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode GetCfamRegister(const fapi::Target& i_target,
                                 const uint32_t i_address,
                                 ecmdDataBufferBase & o_data);

/**
 * @brief Writes a CFAM register to a chip
 * @param[in] i_target Target to operate on
 * @param[in] i_address CFAM address to write to
 * @param[in] i_data ecmdDataBufferBase object that holds data to write into
 *                   address
 * @return ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode PutCfamRegister(const fapi::Target& i_target,
                                 const uint32_t i_address,
                                 ecmdDataBufferBase & i_data);

/**
 * @brief Read-modify-write a CFAM register on a chip
 * @param[in] i_target Target to operate on
 * @param[in] i_address CFAM address to write to
 * @param[in] i_data ecmdDataBufferBase object that holds the modifying data
 * @param[in] i_modifyMode The modify mode (or/and/xor)
 * @return ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode ModifyCfamRegister(const fapi::Target& i_target,
                                    const uint32_t i_address,
                                    ecmdDataBufferBase & i_data,
                                    const fapi::ChipOpModifyMode i_modifyMode);


} // extern "C"

#endif // FAPIHWACCESS_H_
