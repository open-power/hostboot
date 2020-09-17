/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/expaccess/errlud_expscom.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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

#ifndef __ERRLUD_EXPSCOM_H
#define __ERRLUD_EXPSCOM_H

/**
 *  @file errlud_expscom.H
 *  @brief Utility functions to add Explorer logs to your hostboot error
 */
#include <stdint.h>
#include <errl/errluserdetails.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

namespace EXPSCOM
{

/**
 *  @brief Distinguish image location of the saved log
 */
enum saved_exp_image : uint8_t
{
    SAVED_IMAGE_A = 0,
    SAVED_IMAGE_B = 1,
};


/**
 * @brief Header data of every explorer error log user-data section
 */
struct explog_section_header_t
{
    uint16_t packet_num;      // ordering byte (0 = first packet)
    uint32_t offset_exp_log;  // offset where data portion started in full explorer log
    uint16_t error_data_size; // size of data portion following header

    explog_section_header_t()
      : packet_num(0),
        offset_exp_log(0),
        error_data_size(0)
    {}
} __attribute__((__packed__));

// Break large explorer log data into smaller error sections
// to avoid dropping important debug data.
// Make most important first section smaller so this won't get dropped
const uint16_t FIRST_EXPLORER_DATA_SECTION_SIZE     = 0x0150;
const uint16_t FOLLOWING_EXPLORER_DATA_SECTION_SIZE = 0x0200;


/**
 * @class ExpscomActiveLogUD
 *
 * Adds Explorer Active log information to an error log as user detail
 * Data is from Explorer RAM
 *
 */
class ExpscomActiveLogUD : public ERRORLOG::ErrlUserDetails
{
  public:
    /**
     *  @brief Constructor
     *
     *  @param i_header_info  Meta information added to beginning of section
     *  @param i_data_portion Pointer to portion of Active log data
     *
     */
    ExpscomActiveLogUD( const explog_section_header_t & i_header_info,
                          const uint8_t * i_data_portion );

    /**
     *  @brief Destructor
     */
    virtual ~ExpscomActiveLogUD();

    // Disabled
    ExpscomActiveLogUD() = delete;
    ExpscomActiveLogUD(ExpscomActiveLogUD &) = delete;
    ExpscomActiveLogUD & operator=(ExpscomActiveLogUD &) = delete;
};




/**
 * @class ExpscomSavedLogUD
 *
 * Adds Explorer Saved log information to an error log as user detail
 * Data is from Explorer SPI flash
 *
 */
class ExpscomSavedLogUD : public ERRORLOG::ErrlUserDetails
{
  public:
    /**
     *  @brief Constructor
     *
     *  @param i_header_info  Meta information added to beginning of section
     *  @param i_data_portion Pointer to portion of Saved error data
     *
     */
    ExpscomSavedLogUD( const saved_exp_image i_image,
                       const explog_section_header_t & i_header_info,
                       const uint8_t * i_data_portion );

    /**
     *  @brief Destructor
     */
    virtual ~ExpscomSavedLogUD();

    // Disabled
    ExpscomSavedLogUD() = delete;
    ExpscomSavedLogUD(ExpscomSavedLogUD &) = delete;
    ExpscomSavedLogUD & operator=(ExpscomSavedLogUD &) = delete;
};

}

#endif
