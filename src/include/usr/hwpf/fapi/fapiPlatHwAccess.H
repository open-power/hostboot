/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/usr/hwpf/fapi/fapiPlatHwAccess.H $
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
 *  @file fapiPlatHwAccess.H
 *
 *  @brief Defines hardware-access functions for the platform layer.  
 *         Hardware procedure writers will not call these functions. 
 *       
 *         Implementors of platform code will provide worker routines
 *         for these functions in file hwpf/plat/fapiPlatHwAccess.C.
 *         fapi.H will not include this file, so platform implementors
 *         will have to include this file explicitly. 
 * 
 *         These platform entry points are called by fapi functions from 
 *         hwpf/fapi/fapiHwAccess.C which are wrapper functions that 
 *         output scand traces common to all platforms.  
 * 
 *         These functions have the same argument signatures as the
 *         fapi-level functions, but the function names her start with 
 *         "plat."
 *     
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          monte       8sep2011    new
 *                          mjjones     11/10/2011  Use ecmdDataBufferBase
 *          836579          thi         May 22,2012 Spy/Ring supports
 *                          mjjones     07/12/2012  Add Pulse mode option to Ring funcs
 */

#ifndef FAPIPLATHWACCESS_H_
#define FAPIPLATHWACCESS_H_

#include <stdint.h>
#include <ecmdDataBufferBase.H>
#include <fapiReturnCode.H>
#include <fapiTarget.H>


extern "C"
{

//------------------------------------------------------------------------------
// HW Communication Functions to be implemented at the platform layer.
//------------------------------------------------------------------------------


/**
 * @brief Platform-level implementation called by GetScom()
 * Hardware procedures writers will not call this function.
 * 
 * 
 * @param[in] i_target Target to operate on
 * @param[in] i_address Scom address to read from
 * @param[out] o_data ecmdDataBufferBase object that holds data read from
 *                    address
 * @return ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode platGetScom(const fapi::Target& i_target,
                             const uint64_t i_address,
                             ecmdDataBufferBase & o_data);


/**
 * @brief Platform-level implementation called by PutScom().
 * Hardware procedures writers will not call this function.
 * 
 * @param[in] i_target Target to operate on
 * @param[in] i_address Scom address to write to
 * @param[in] i_data ecmdDataBufferBase object that holds data to write into
 *                   address
 * @return ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode platPutScom(const fapi::Target& i_target,
                             const uint64_t i_address,
                             ecmdDataBufferBase & i_data);


/**
 * @brief Platform-level implementation called by PutScomUnderMask()
 * Hardware procedures writers will not call this function.
 * 
 * @param[in] i_target Target to operate on
 * @param[in] i_address Scom address to write to
 * @param[in] i_data ecmdDataBufferBase object that holds the data
 * @param[in] i_mask ecmdDataBufferBase object that holds the mask (i_data to
 *                   write)
 * @return ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode platPutScomUnderMask(const fapi::Target& i_target,
                                      const uint64_t i_address,
                                      ecmdDataBufferBase & i_data,
                                      ecmdDataBufferBase & i_mask);


/**
 * @brief Platorm-level implementation called by GetCfamRegister()
 * Hardware procedures writers will not call this function.
 * 
 * @param[in] i_target Target to operate on
 * @param[in] i_address CFAM address to read from
 * @param[out] o_data ecmdDataBufferBase object that holds data read from
 *                    address
 * @return ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode platGetCfamRegister(const fapi::Target& i_target,
                                     const uint32_t i_address,
                                     ecmdDataBufferBase & o_data);


/**
 * @brief Platform-level implementation called by PutCfamRegister()
 * Hardware procedures writers will not call this function.
 * 
 * @param[in] i_target Target to operate on
 * @param[in] i_address CFAM address to write to
 * @param[in] i_data ecmdDataBufferBase object that holds data to write into
 *                   address
 * @return ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode platPutCfamRegister(const fapi::Target& i_target,
                                     const uint32_t i_address,
                                     ecmdDataBufferBase & i_data);


/**
 * @brief Platform-level implementation of ModifyCfamRegister()
 * Hardware procedures writers will not call this function.
 * 
 * @param[in] i_target Target to operate on
 * @param[in] i_address CFAM address to write to
 * @param[in] i_data ecmdDataBufferBase object that holds the modifying data
 * @param[in] i_modifyMode The modify mode (or/and/xor)
 * @return ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode platModifyCfamRegister(const fapi::Target& i_target,
                                  const uint32_t i_address,
                                  ecmdDataBufferBase & i_data,
                                  const fapi::ChipOpModifyMode i_modifyMode);


/**
 * @brief Platform-level implementation called by fapiGetRing()
 * Hardware procedures writers will not call this function.
 * 
 * @param[in] i_target  Target to operate on
 * @param[in] i_address Ring address to read from
 * @param[out] o_data   ecmdDataBufferBase object that holds data read from
 *                      address
 * @param[in] i_ringMode Any number of mode options from fapi::RingMode ORed
 * @return ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode platGetRing(const fapi::Target& i_target,
                             const uint32_t i_address,
                             ecmdDataBufferBase & o_data,
                             const uint32_t i_ringMode);


/**
 * @brief Platform-level implementation called by fapiPutRing()
 * Hardware procedures writers will not call this function.
 *
 * @param[in] i_target  Target to operate on
 * @param[in] i_address Ring address to write to
 * @param[in] i_data    ecmdDataBufferBase object that holds data to write into
 *                      address
 * @param[in] i_ringMode Any number of mode options from fapi::RingMode ORed
 * @return ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode platPutRing(const fapi::Target& i_target,
                             const uint32_t i_address,
                             ecmdDataBufferBase & i_data,
                             const uint32_t i_ringMode);


/**
 * @brief Platform-level implementation called by fapiModifyRing()
 * Hardware procedures writers will not call this function.
 *
 * @param[in] i_target  Target to operate on
 * @param[in] i_address Ring address to modify
 * @param[in] i_data    ecmdDataBufferBase object that holds data to write into
 *                      address
 * @param[in] i_ringMode Any number of mode options from fapi::RingMode ORed
 * @return ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode platModifyRing(const fapi::Target& i_target,
                                const uint32_t i_address,
                                ecmdDataBufferBase & i_data,
                                const fapi::ChipOpModifyMode i_modifyMode,
                                const uint32_t i_ringMode);

// --------------------------------------------------------------------------
// NOTE:
// These spy access interfaces are only used in FSP.
// HB does not allow spy access

#ifndef _NO_SPY_ACCESS
/**
 * @brief Platform-level implementation called by fapiGetSpy()
 * Hardware procedures writers will not call this function.
 *
 * @param[in] i_target              Target to read spy from
 * @param[in] i_spyId               The spy's id
 * @param[out] o_data               Storage for output data
 *
 * @return ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode platGetSpy(const fapi::Target& i_target,
                            const uint32_t i_spyId,
                            ecmdDataBufferBase & o_data);

/**
 * @brief Platform-level implementation called by fapiPutSpy()
 * Hardware procedures writers will not call this function.
 *
 * @param[in] i_target  Target to operate on
 * @param[in] i_spyId   The spy's id
 * @param[in] i_data    ecmdDataBufferBase object that holds data to write into
 *                      address
 *
 * @return ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode platPutSpy(const fapi::Target& i_target,
                            const uint32_t i_spyId,
                            ecmdDataBufferBase & i_data);

/**
 * @brief Platform-level implementation called by fapiGetSpyEnum()
 * Hardware procedures writers will not call this function.
 *
 * @param[in] i_target         Target to read spy enum from
 * @param[in] i_spyId          The spy's id
 * @param[out] o_enumVal       Spy enum value
 *
 * @return ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode platGetSpyEnum(const fapi::Target& i_target,
                                const uint32_t i_spyId,
                                uint32_t& o_enumVal);

/**
 * @brief Platform-level implementation called by fapiPutSpyEnum()
 * Hardware procedures writers will not call this function.
 *
 * @param[in] i_target             The chip or logical unit target
 * @param[in] i_spyId              The spy's id
 * @param[in] i_enumVal            Spy enum value to write
 */
fapi::ReturnCode platPutSpyEnum(const fapi::Target& i_target,
                                const uint32_t i_spyId,
                                const uint32_t i_enumVal);

#endif

} // extern "C"

#endif // FAPIPLATHWACCESS_H_
