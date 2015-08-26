/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/bootloader/bl_pnorAccess.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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

#ifndef __BL_PNORACCESS_H
#define __BL_PNORACCESS_H


#include <pnor_const.H>
#include <pnor_utils.H>
#include <ffs.h>

/** @file bl_pnorAccess.H
 *  @brief Provides interface to the PNOR flash for bootloader
 */

/**
 *  @brief  bootloader PNOR access class
 *  Provide interfaces for the bootloader to look through pnor and find toc
 */

class bl_pnorAccess
{

  friend class pnorutilsTest;
  public:

/**
 * @brief Get the hostboot base image
 *
 * @param[in] i_pnorStart       MMIO address to access the start of pnor flash
 *
 * @param[out] o_hbbSection     Struct that holds information about the
 *                              Hostboot Base Image Section
 *
 * @param[out] o_errCode        Anything besides PNOR:NO_ERROR is an error
 *
 * @param[out] o_tocUsed        Tells you which table of contents was used
 *
 * @return void
 */
static void getHBBSection(uint64_t i_pnorStart,
                          PNOR::SectionData_t& o_hbbSection,
                          uint32_t& o_errCode,
                          uint8_t& o_tocUsed);

  private:
/**
 * @brief Read in the toc and get information about each section
 *
 * @param[in] i_tocBuffer     Buffer containing a single TOC
 *
 * @param[out] o_errCode      Anything besides PNOR:NO_ERROR is an error
 *
 * @param[out] o_TOC          Array of section data describing contents of pnor
 *
 * @param[in] i_baseAddr      MMIO address to access the start of pnor flash
 *
 * @return void
 */
static void readTOC(uint8_t i_tocBuffer[PNOR::TOC_SIZE],  uint32_t & o_errCode,
                    PNOR::SectionData_t * o_TOC, uint64_t i_baseAddr);

/**
 * @brief Find a valid TOC within specified side of pnor flash
          side is determined by the base mmio address passed in
 *
 * @param[in] i_pnorBase     MMIO address to access the start of pnor flash
 *
 * @param[out] o_TOC         Array of section data describing contents of pnor
 *
 * @param[out] o_errCode     Anything besides PNOR:NO_ERROR is an error
 *
 * @param[out] o_tocUsed     Tells you which table of contents was used
 *
 * @return void
 */
static void findTOC(uint64_t i_pnorBase, PNOR::SectionData_t * o_TOC,
                    uint32_t& o_errCode, uint8_t& o_tocUsed);

};

#endif