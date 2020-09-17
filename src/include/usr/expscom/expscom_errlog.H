/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/expscom/expscom_errlog.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
/*
 * @file expscom_errlog.H
 * @brief Explorer log gathering for hostboot side
 */
#ifndef __EXPSCOM_ERRLOG_H
#define __EXPSCOM_ERRLOG_H

//  targeting support
#include    <targeting/common/commontargeting.H>

// errl handle
#include <errl/errlentry.H>

namespace EXPSCOM
{
/**
 * @brief Enum for what kind of Explorer log
 */
enum exp_log_type : uint8_t
{
    ACTIVE_LOG  = 1, // RAM error section
    SAVED_LOG_A = 2, // SPI flash error section (image A)
    SAVED_LOG_B = 3, // SPI flash error section (image B)
    CURRENT_SAVED_LOG = 4, // SPI flash error section (current image running)
    NONCURRENT_SAVED_LOG = 5, // SPI flash error section (non-current image running)
};

/**
 * @brief Adds Explorer log data to platform log
 *        Grabs explorer error log based on type and then breaks that data
 *        into smaller user-data sections adding them to the platform log.
 *        Note: First section will be the smallest and contain the most recent
 *        trace data.
 * @param i_type - what kind of explorer error log to add
 * @param i_ocmb - Explorer target
 * @param io_errl - Platform error log to add logs into
 * @return true if explorer error data added, else false
 */
bool expAddLog( const exp_log_type i_type,
                TARGETING::Target * i_ocmb,
                errlHndl_t & io_errl );
}

#endif
