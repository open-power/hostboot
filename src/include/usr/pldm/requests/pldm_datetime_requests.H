/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/requests/pldm_datetime_requests.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2022                        */
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
#ifndef PLDM_DATETIME_REQUESTS_H
#define PLDM_DATETIME_REQUESTS_H

#include <time.h>
#include <errl/errlentry.H>

/* @file pldm_datetime_requests.H
 *
 * This file contains the declarations of the functions involved in getting
 * the timestamp (date/time) from the BMC.
 */

namespace PLDM
{

/*
 * @brief This function requests the current date/time from BMC.
 *
 * @param[out] o_dateTime the date/time that BMC returned (0 on error)
 * @return nullptr on success; non-nullptr on error
 */
errlHndl_t getDateTime(date_time_t& o_dateTime);

} // namespace PLDM

#endif
