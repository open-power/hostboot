/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/fapi/fapiPlatHwAccess.H $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2016                        */
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
// $Id: fapiPlatHwAccess.H,v 1.11 2015/10/06 19:19:45 kahnevan Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/hwpf/working/fapi/fapiPlatHwAccess.H,v $

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
 *                          mjjones     07/12/2012  Add Pulse mode option to
 *                                                  Ring funcs
 *          F876964         jknight     Apr, 02,2013  fapi get/setSpyImage
 *          F873646         srimeesa    Mar 10,2013 64Bit SPYID and 
 *                                                  ClockDomain ID support  
 *          F883863         atendolk    May 16,2013 fapi MultiScom support
 */

#ifndef FAPIPLATHWACCESS_H_
#define FAPIPLATHWACCESS_H_

#include <stdint.h>
#include <ecmdDataBufferBase.H>
#include <fapiReturnCode.H>
#include <fapiTarget.H>
#ifdef FAPI_SUPPORT_MULTI_SCOM
#include <fapiMultiScom.H>
#endif

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

#ifdef FAPI_SUPPORT_MULTI_SCOM
/**
 * @brief Platform-level implementation called by fapiMultiScom()
 * Hardware procedures writers will not call this function.
 *
 * @param[in]     i_target         Target to operate on
 * @param[in,out] io_multiScomList MultiScom object pre-populated with SCOMs to
 *                                 be performed on i_target
 * @return        ReturnCode       Zero on success, else platform specified error
 */
fapi::ReturnCode platMultiScom (const fapi::Target&    i_target,
                                      fapi::MultiScom& io_multiScomList);
#endif

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
                             const scanRingId_t i_address,
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
                             const scanRingId_t i_address,
                             ecmdDataBufferBase & i_data,
                             const uint32_t i_ringMode);


/**
 * @brief Platform-level implementation called by fapiModifyRing()
 * Hardware procedures writers will not call this function.
 *
 * @param[in] i_target     Target to operate on
 * @param[in] i_address    Ring address to modify
 * @param[in] i_data       ecmdDataBufferBase object that holds data to write into
 *                         address
 * @param[in] i_modifyMode The modify mode (or/and/xor)
 * @param[in] i_ringMode   Any number of mode options from fapi::RingMode ORed
 * @return ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode platModifyRing(const fapi::Target& i_target,
                                const scanRingId_t i_address,
                                ecmdDataBufferBase & i_data,
                                const fapi::ChipOpModifyMode i_modifyMode,
                                const uint32_t i_ringMode);

// --------------------------------------------------------------------------
// NOTE:
// These spy access interfaces are only used in FSP.
// HB does not allow spy access

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
#ifdef FAPI_SUPPORT_SPY_AS_ENUM
fapi::ReturnCode platGetSpy(const fapi::Target& i_target,
                            const spyId_t i_spyId,
                            ecmdDataBufferBase & o_data);
#endif

#ifdef FAPI_SUPPORT_SPY_AS_STRING
/**
 * @brief Reads a Spy from a target
 * @param[in] i_target              Target to read spy from
 * @param[in] i_spyId               The spy's id
 * @param[out] o_data               Storage for output data
 *
 * @return ReturnCode. Zero on success, else platform specified error
 *
 * @note:  This is only supported in the cronus environment
 *         it will not compile in FSP code 
 */
fapi::ReturnCode platGetSpy(const fapi::Target& i_target,
                             const char * const i_spyId,
                             ecmdDataBufferBase & o_data);
#endif

#ifdef FAPI_SUPPORT_SPY_AS_ENUM
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
                            const spyId_t i_spyId,
                            ecmdDataBufferBase & i_data);
#endif

#ifdef FAPI_SUPPORT_SPY_AS_STRING
fapi::ReturnCode platPutSpy(const fapi::Target& i_target,
                             const char * const i_spyId,
                             ecmdDataBufferBase & i_data);
#endif
#ifdef FAPI_SUPPORT_SPY_AS_ENUM
/**
 * @brief Platform-level implementation called by fapiGetSpyImage()
 * Hardware procedures writers will not call this function.
 *
 * @param[in] i_target              Target to read spy from
 * @param[in] i_spyId               The spy's id
 * @param[out] o_data               Storage for output data
 * @param[in] i_imageData           Input ring data
 *
 * @return ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode platGetSpyImage(const fapi::Target& i_target,
                                 const spyId_t i_spyId,
                                 ecmdDataBufferBase & o_data,
                                 const ecmdDataBufferBase & i_imageData);
#endif
#ifdef FAPI_SUPPORT_SPY_AS_STRING
/**
 * @brief Platform-level implementation called by fapiGetSpyImage()
 * Hardware procedures writers will not call this function.
 *
 * @param[in] i_target              Target to read spy from
 * @param[in] i_spyId               The spy's id
 * @param[out] o_data               Storage for output data
 * @param[in] i_imageData           Input ring data
 *
 * @return ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode platGetSpyImage(const fapi::Target& i_target,
                                 const char * const i_spyId,
                                 ecmdDataBufferBase & o_data,
                                 const ecmdDataBufferBase & i_imageData);
#endif
#ifdef FAPI_SUPPORT_SPY_AS_ENUM
/**
 * @brief Platform-level implementation called by fapiPutSpyImage()
 * Hardware procedures writers will not call this function.
 *
 * @param[in]  i_target             Target to read spy from
 * @param[in]  i_spyId              The spy's id
 * @param[in]  i_data               Data to be written into the image
 * @param[out] io_imageData         Holds ring image to write data into
 *
 * @return ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode platPutSpyImage(const fapi::Target& i_target,
                                 const spyId_t i_spyId,
                                 const ecmdDataBufferBase & i_data,
                                 ecmdDataBufferBase & io_imageData);
#endif
#ifdef FAPI_SUPPORT_SPY_AS_STRING
/**
 * @brief Platform-level implementation called by fapiPutSpyImage()
 * Hardware procedures writers will not call this function.
 *
 * @param[in]  i_target             Target to read spy from
 * @param[in]  i_spyId              The spy's id
 * @param[in]  i_data               Data to be written into the image
 * @param[out] io_imageData         Holds ring image to write data into
 *
 * @return ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode platPutSpyImage(const fapi::Target& i_target,
                                 const char* const i_spyId,
                                 const ecmdDataBufferBase & i_data,
                                 ecmdDataBufferBase & io_imageData);

#endif
} // extern "C"

#endif // FAPIPLATHWACCESS_H_
