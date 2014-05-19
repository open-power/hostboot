/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/io_post_trainadv.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: io_post_trainadv.H,v 1.2 2013/11/08 14:22:27 mjjones Exp $
#ifndef IO_POST_TRAINADV_H_
#define IO_POST_TRAINADV_H_

#include <fapi.H>

/**
 * io_post_trainadv HWP func pointer typedef
 */
typedef fapi::ReturnCode (*io_post_trainadv_FP_t)(const fapi::Target &);

extern "C"
{

/**
 * @brief Debug routine for IO Characterization
 *
 * @param[in]  i_target  Reference to bus endpoint target. Type is one of:
 *                       XBUS_ENDPOINT, ABUS_ENDPOINT,
 *                       MCS_CHIPLET, MEMBUF_CHIP
 * @return ReturnCode
 */
fapi::ReturnCode io_post_trainadv(const fapi::Target & i_target);

} // extern "C"

#endif
