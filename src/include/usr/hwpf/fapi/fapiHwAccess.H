/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/fapi/fapiHwAccess.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
// $Id: fapiHwAccess.H,v 1.13 2014/01/20 22:37:49 mklight Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/hwpf/working/fapi/fapiHwAccess.H,v $

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
 *                          rjknight    09/20/2012  Update fapiSpy interfaces to
 *          F876964         jknight     Apr, 02,2013  fapi get/setSpyImage
 *          F873646         srimeesa    Mar 10,2013 64Bit SPYID and 
 *                                                  ClockDomain ID support
 *          F883863         atendolk    05/06/2013  Add MultiScom support
 */

#ifndef FAPIHWACCESS_H_
#define FAPIHWACCESS_H_

#ifdef FAPI_SUPPORT_SPY_AS_ENUM
#include <fapiSpyIds.H>
#endif

#include <stdint.h>
#include <ecmdDataBufferBase.H>
#include <fapiReturnCode.H>
#include <fapiTarget.H>

#ifdef FAPI_SUPPORT_MULTI_SCOM
#include <fapiMultiScom.H>
#endif


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

typedef uint64_t spyId_t;
typedef uint64_t scanRingId_t;

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
                             const scanRingId_t i_address,
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
                             const scanRingId_t i_address,
                             ecmdDataBufferBase & i_data,
                             const uint32_t i_ringMode = 0);


/**
 * @brief Modifies a ring register on a target
 * @param[in] i_target  Target to operate on
 * @param[in] i_address Ring address to modify
 * @param[in] i_data    ecmdDataBufferBase object that holds data to write into
 *                      address
 * @param[in] i_modifyMode The modify mode (or/and/xor)
 * @param[in] i_ringMode Any number of mode options from fapi::RingMode ORed
 * @return ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiModifyRing(const fapi::Target& i_target,
                                const scanRingId_t i_address,
                                ecmdDataBufferBase & i_data,
                                const fapi::ChipOpModifyMode i_modifyMode,
                                const uint32_t i_ringMode = 0);

// --------------------------------------------------------------------------
// NOTE:
// These spy access interfaces are only used in FSP and cronus
// HB does not allow spy access

#if defined(FAPI_SUPPORT_SPY_AS_ENUM) || defined(FAPI_SUPPORT_SPY_AS_STRING)
/**
 * @brief Reads a Spy from a target
 * @param[in] i_target              Target to read spy from
 * @param[in] i_spyId               The spy's id
 * @param[out] o_data               Storage for output data
 *
 * @return ReturnCode. Zero on success, else platform specified error
 *
 * @note:  The string version is only supported for cronus.
 *
 *         The fapi design to support both FSP and cronus use of get and
 *         put spy functions is dependant on the SPY names being expanded
 *         to resemble a valid C identifier. This design places some
 *         restrictions on the SPY names which can be used.
 *
 *         1. if the spy name contains a # procedure writers should replace it
 *         with an __P__ for example -
 *
 *         ABUS.RX0.RXPACKS#0.RXPACK.RD.LC.LC.ACT_DIS
 *         becomes
 *         ABUS.RX0.RXPACKS__P__0.RXPACK.RD.LC.LC.ACT_DIS
 *
 *         2. if the spy name has a number following a "." it must have an
 *         underscore prepended to the number.
 *
 *         EH.TPCHIP.2KX100_ARY_CLK_EDGES_DLY
 *         becomes
 *         EH.TPCHIP._2KX100_ARY_CLK_EDGES_DLY
 *
 *         Example SPY name:
 *         The hardware procedure should call the function like:
 *
 *          ABUS.RX0.RXPACKS#0.RXPACK.RD.LC.LC.ACT_DIS
 *
 *          fapi::ReturnCode rc = fapiGetSpy( targ,
 *                  ABUS.RX0.RXPACKS__P__0.RXPACK.RD.LC.LC.ACT_DIS, data );
 *
 *         NOTE: the ID is not in quotes the fapi code will handle adding the
 *         quotes for the cronus environment
 *
*/
#endif

#ifdef FAPI_SUPPORT_SPY_AS_ENUM

#ifndef DOCUMENTATION
#define fapiGetSpy(TARGET, ID, DATA) _fapiGetSpy(TARGET, FAPI_SPY_NAMES::ID.value, DATA )
#endif
fapi::ReturnCode _fapiGetSpy(const fapi::Target& i_target,
                            const spyId_t i_spyId,
                            ecmdDataBufferBase & o_data);
#endif

#ifdef FAPI_SUPPORT_SPY_AS_STRING

#ifndef DOCUMENTATION
#define fapiGetSpy(TARGET, ID, DATA) _fapiGetSpy(TARGET, #ID, DATA)
#endif
fapi::ReturnCode _fapiGetSpy(const fapi::Target& i_target,
                             const char * const i_spyId,
                             ecmdDataBufferBase & o_data);
#endif

#if defined(FAPI_SUPPORT_SPY_AS_ENUM) || defined(FAPI_SUPPORT_SPY_AS_STRING)
/**
 * @brief Writes a spy on a target
 * @param[in] i_target  Target to operate on
 * @param[in] i_spyId   The spy's id
 * @param[in] i_data    ecmdDataBufferBase object that holds data to write into
 *                      address
 *
 * @return ReturnCode. Zero on success, else platform specified error
 *
 * @note:  The string version is only supported for cronus.
 *
 *         The fapi design to support both FSP and cronus use of get and
 *         put spy functions is dependent on the SPY names being expanded
 *         to resemble a valid C identifier. This design places some
 *         restrictions on the SPY names which can be used.
 *
 *         1. if the spy name contains a # procedure writers should replace it
 *         with an __P__ for example -
 *
 *         ABUS.RX0.RXPACKS#0.RXPACK.RD.LC.LC.ACT_DIS
 *         becomes
 *         ABUS.RX0.RXPACKS__P__0.RXPACK.RD.LC.LC.ACT_DIS
 *
 *         2. if the spy name has a number following a "." it must have an
 *         underscore prepended to the number.
 *
 *         EH.TPCHIP.2KX100_ARY_CLK_EDGES_DLY
 *         becomes
 *         EH.TPCHIP._2KX100_ARY_CLK_EDGES_DLY
 *
 *         Example SPY name:
 *         The hardware procedure should call the function like:
 *
 *          ABUS.RX0.RXPACKS#0.RXPACK.RD.LC.LC.ACT_DIS
 *
 *          fapi::ReturnCode rc = fapiPutSpy( targ,
 *                  ABUS.RX0.RXPACKS__P__0.RXPACK.RD.LC.LC.ACT_DIS, data );
 *
 *         NOTE: the ID is not in quotes the fapi code will handle adding the
 *         quotes for the cronus environment
 *
*/
#endif

#ifdef FAPI_SUPPORT_SPY_AS_ENUM
#ifndef DOCUMENTATION
#define fapiPutSpy(TARGET, ID, DATA) _fapiPutSpy(TARGET, FAPI_SPY_NAMES::ID.value, DATA)
#endif
fapi::ReturnCode _fapiPutSpy(const fapi::Target& i_target,
                            const spyId_t i_spyId,
                            ecmdDataBufferBase & i_data);
#endif

#ifdef FAPI_SUPPORT_SPY_AS_STRING
#ifndef DOCUMENTATION
#define fapiPutSpy(TARGET, ID, DATA) _fapiPutSpy(TARGET, #ID, DATA)
#endif
fapi::ReturnCode _fapiPutSpy(const fapi::Target& i_target,
                            const char* const i_spyId,
                            ecmdDataBufferBase & i_data);

#endif

#if defined(FAPI_SUPPORT_SPY_AS_ENUM) || defined(FAPI_SUPPORT_SPY_AS_STRING)
/**
 * @brief Writes data into a ring image
 * @param[in]   i_target      Target to operate on
 * @param[in]   i_spyId       The spy's id
 * @param[in]   i_data        ecmdDataBufferBase object that holds data to
 *                            be written
 * @param[out]  o_imageData   ecmdDataBufferBase object that holds data to
 *                            write into
 * @return ReturnCode. Zero on success, else platform specified error
 *
 * @note:  The string version is only supported for cronus.
 *
 *         The fapi design to support both FSP and cronus use of get and
 *         put spy functions is dependent on the SPY names being expanded
 *         to resemble a valid C identifier. This design places some
 *         restrictions on the SPY names which can be used.
 *
 *         See fapiPutSpy for details on spy id specifics.
 */
#endif

#ifdef FAPI_SUPPORT_SPY_AS_ENUM
#ifndef DOCUMENTATION
#define fapiPutSpyImage(TARGET, ID, DATA1, DATA2) _fapiPutSpyImage(TARGET, \
                                                    FAPI_SPY_NAMES::ID.value, \
                                                    DATA1, DATA2)
#endif
fapi::ReturnCode _fapiPutSpyImage(const fapi::Target& i_target,
                                  const spyId_t i_spyId,
                                  const ecmdDataBufferBase & i_data,
                                  ecmdDataBufferBase & o_imageData);
#endif

#ifdef FAPI_SUPPORT_SPY_AS_STRING
// fapiPutSpyImage function Cronus version
#ifndef DOCUMENTATION
#define fapiPutSpyImage(TARGET, ID, DATA1, DATA2) _fapiPutSpyImage(TARGET, #ID,\
                                                             DATA1,DATA2)
#endif

fapi::ReturnCode _fapiPutSpyImage(const fapi::Target& i_target,
                                  const char* const i_spyId,
                                  const ecmdDataBufferBase & i_data,
                                  ecmdDataBufferBase & o_imageData);
#endif

#if defined(FAPI_SUPPORT_SPY_AS_ENUM) || defined(FAPI_SUPPORT_SPY_AS_STRING)
/**
 * @brief Reads data from a ring image
 * @param[in]   i_target      Target to operate on
 * @param[in]   i_spyId       The spy's id
 * @param[out]  o_data        ecmdDataBufferBase object where data is
 *                            returned
 * @param[in]   i_imageData   ecmdDataBufferBase object that holds ring image
 *                            to read data from
 * @return ReturnCode. Zero on success, else platform specified error
 *
 * @note:  The string version is only supported for cronus.
 *
 *         The fapi design to support both FSP and cronus use of get and
 *         put spy functions is dependent on the SPY names being expanded
 *         to resemble a valid C identifier. This design places some
 *         restrictions on the SPY names which can be used.
 *
 *         See fapiPutSpy for details on spy id specifics.
 */
#endif

#ifdef FAPI_SUPPORT_SPY_AS_ENUM
#ifndef DOCUMENTATION
#define fapiGetSpyImage(TARGET, ID, DATA1, DATA2) _fapiGetSpyImage(TARGET, \
                                            FAPI_SPY_NAMES::ID.value, \
                                            DATA1, DATA2)
#endif
fapi::ReturnCode _fapiGetSpyImage(const fapi::Target& i_target,
                                  const spyId_t i_spyId,
                                  ecmdDataBufferBase & o_data,
                                  const ecmdDataBufferBase & i_imageData);
#endif

#ifdef FAPI_SUPPORT_SPY_AS_STRING
// fapiGetSpyImage function Cronus version
#ifndef DOCUMENTATION
#define fapiGetSpyImage(TARGET, ID, DATA1, DATA2) _fapiGetSpyImage(TARGET,\
                                                    #ID, DATA1,DATA2)
#endif

fapi::ReturnCode _fapiGetSpyImage(const fapi::Target& i_target,
                                  const char* const i_spyId,
                                  ecmdDataBufferBase & o_data,
                                  const ecmdDataBufferBase & i_imageData);
#endif

#ifdef FAPI_SUPPORT_MULTI_SCOM
/**
 *  @brief Performs a multiple SCOM operation
 *
 *  @par Description:
 *    This interface performs multiple SCOM operations on a chip or chiplet,
 *    in the order specified by the input MultiScom object. See fapiMultiScom.H
 *    for details of how to populate the MultiScom object with SCOM operations
 *
 *  @param[in]      i_target        Chip/Chiplet target to do MultiScom on
 *  @param[in,out]  io_multiScomObj Reference to a MultiScom object,
 *                                  pre-populated with SingleScomInfo entries
 *                                  to perform multiple SCOMs on input target
 *  @return ReturnCode              Zero on success, else platform specified
 *                                  error
 *
 *  @note   This is a synchronous interface and would return after all the SCOM
 *          operations are completed or on the first failed SCOM operation
 *
 *  @note   SCOMs will be performed in the order they were added to the input
 *          MultiScom object
 *
 *  @note   In case of errors, the platform code is responsible to collect and
 *          add all the required error info and FFDC into the error data for
 *          debugging
 *
 *  @note   If the SCOM operations added are specific to a processor chip,
 *          then the FSI Shift Engine configured in scatter-gather DMA mode
 *          extension would be used to execute the SCOM operations in a
 *          performance optimize mode. In this mode, the special
 *          SCOM_BULK_READ_MODE and SCOM_BULK_WRITE_MODE operations are
 *          supported that allow a large bulk of SCOM access (in multiple of 64
 *          bits) for targets that support auto-increment. The
 *          SCOM_WRITE_UNDER_MASK operation is not supported in this mode
 *
 *  @note   If the SCOM operations added are specific to a memory buffer chip,
 *          then the regular SCOM engine is used to execute the SCOM operations.
 *          SCOM_WRITE_UNDER_MASK operation is supported in this mode, but the
 *          special SCOM_BULK_READ_MODE and SCOM_BULK_WRITE_MODE operations are
 *          not supported due to hardware limitations.
 */
fapi::ReturnCode fapiMultiScom (
                    const   fapi::Target&       i_target,
                            fapi::MultiScom&    io_multiScomObj);
#endif  // FAPI_SUPPORT_MULTI_SCOM


} // extern "C"

#endif // FAPIHWACCESS_H_
