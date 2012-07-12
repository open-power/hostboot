/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/usr/hwpf/fapi/fapiHwAccess.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2011-2012
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
 *          836579          thi         May 22,2012 Spy/Ring supports
 *                          mjjones     07/12/2012  Add mode options to Ring funcs
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

    /**
     * @brief Enumeration of Ring operation modes
     *
     * This is a bitmap to allow the user to specify multiple modes
     */
    enum RingMode
    {
        RING_MODE_SET_PULSE       = 0x00000001,
        RING_MODE_NO_HEADER_CHECK = 0x00000002,
        // FUTURE_MODE            = 0x00000004,
        // FUTURE_MODE            = 0x00000008,
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

/**
 * @brief Reads a ring from a target
 * @param[in] i_target Target to operate on
 * @param[in] i_address Ring address to read from
 * @param[out] o_data ecmdDataBufferBase object that holds data read from
 *                    address
 * @param[in] i_ringMode Any number of mode options from fapi::RingMode ORed
 * @return ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiGetRing(const fapi::Target& i_target,
                             const uint32_t i_address,
                             ecmdDataBufferBase & o_data,
                             const uint32_t i_ringMode = 0);

/**
 * @brief Writes a ring register on a target
 * @param[in] i_target  Target to operate on
 * @param[in] i_address Ring address to write to
 * @param[in] i_data    ecmdDataBufferBase object that holds data to write into
 *                      address
 * @param[in] i_ringMode Any number of mode options from fapi::RingMode ORed
 * @return ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPutRing(const fapi::Target& i_target,
                             const uint32_t i_address,
                             ecmdDataBufferBase & i_data,
                             const uint32_t i_ringMode = 0);


/**
 * @brief Modifies a ring register on a target
 * @param[in] i_target  Target to operate on
 * @param[in] i_address Ring address to modify
 * @param[in] i_data    ecmdDataBufferBase object that holds data to write into
 *                      address
 * @param[in] i_ringMode Any number of mode options from fapi::RingMode ORed
 * @return ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiModifyRing(const fapi::Target& i_target,
                                const uint32_t i_address,
                                ecmdDataBufferBase & i_data,
                                const fapi::ChipOpModifyMode i_modifyMode,
                                const uint32_t i_ringMode = 0);

// --------------------------------------------------------------------------
// NOTE:
// These spy access interfaces are only used in FSP.
// HB does not allow spy access

#ifndef _NO_SPY_ACCESS

/**
 * @brief Reads a Spy from a target
 * @param[in] i_target              Target to read spy from
 * @param[in] i_spyId               The spy's id
 * @param[out] o_data               Storage for output data
 *
 * @return ReturnCode. Zero on success, else platform specified error
 
 */
fapi::ReturnCode fapiGetSpy(const fapi::Target& i_target,
                            const uint32_t i_spyId,
                            ecmdDataBufferBase & o_data);

/**
 * @brief Writes a spy on a target
 * @param[in] i_target  Target to operate on
 * @param[in] i_spyId   The spy's id
 * @param[in] i_data    ecmdDataBufferBase object that holds data to write into
 *                      address
 *
 * @return ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPutSpy(const fapi::Target& i_target,
                            const uint32_t i_spyId,
                            ecmdDataBufferBase & i_data);

/**
 * @brief Read spy Enum data from a target
 * @param[in] i_target         Target to read spy enum from
 * @param[in] i_spyId          The spy's id
 * @param[out] o_enumVal       Spy enum value
 *
 * @return ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiGetSpyEnum(const fapi::Target& i_target,
                                const uint32_t i_spyId,
                                uint32_t& o_enumVal);

/**
 * @brief Write spy enum data to a target
 * @param[in] i_target             The chip or logical unit target
 * @param[in] i_spyId              The spy's id
 * @param[in] i_enumVal            Spy enum value to write
 */
fapi::ReturnCode fapiPutSpyEnum(const fapi::Target& i_target,
                                const uint32_t i_spyId,
                                const uint32_t i_enumVal);

#endif

} // extern "C"

#endif // FAPIHWACCESS_H_
