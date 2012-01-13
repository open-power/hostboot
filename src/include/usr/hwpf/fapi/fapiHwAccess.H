//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/hwpf/fapi/fapiHwAccess.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
/**
 *  @file fapiHwAccess.H
 *
 *  @brief Defines the hardware access functions that platform code must
 *         implement. It is a HWP requirement that these be "C" functions
 *         because it simplifies language bindings for non-C languages,
 *         such as perl
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     04/13/2011  Created. Copied from Hlava's code.
 *                          mjjones     06/02/2011  Scom addresses should be uint64_t
 *                                                  use ecmdDataBufferBase
 *                          mjjones     06/30/2011  Updated comment
 *                          mjjones     09/14/2011  Prepended fapi to functions
 *                          mjjones     11/10/2011  Use ecmdDataBufferBase
 */

#ifndef FAPIHWACCESS_H_
#define FAPIHWACCESS_H_

#include <stdint.h>
#include <ecmdDataBufferBase.H>
#include <fapiReturnCode.H>
#include <fapiTarget.H>

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
fapi::ReturnCode fapiGetScom(const fapi::Target& i_target,
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
fapi::ReturnCode fapiPutScom(const fapi::Target& i_target,
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
fapi::ReturnCode fapiPutScomUnderMask(const fapi::Target& i_target,
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
fapi::ReturnCode fapiGetCfamRegister(const fapi::Target& i_target,
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
fapi::ReturnCode fapiPutCfamRegister(const fapi::Target& i_target,
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
fapi::ReturnCode fapiModifyCfamRegister(const fapi::Target& i_target,
                                        const uint32_t i_address,
                                        ecmdDataBufferBase & i_data,
                                        const fapi::ChipOpModifyMode i_modifyMode);

} // extern "C"

#endif // FAPIHWACCESS_H_
