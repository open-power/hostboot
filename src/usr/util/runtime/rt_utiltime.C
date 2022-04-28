/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/runtime/rt_utiltime.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
/**
 *  @file rt_utiltime.C
 *
 *  @brief Time related functions for Runtime code
 */

#include "../utilbase.H"
#include <util/utiltime.H>
#include <util/runtime/rt_fwreq_helper.H>  // firmware_request_helper
#include <runtime/interface.h>   // g_hostInterfaces

namespace Util
{

date_time_t getCurrentDateTime()
{
    date_time_t l_result{};

    errlHndl_t l_errl = nullptr;

    do {
    if((nullptr == g_hostInterfaces) ||
       (nullptr == g_hostInterfaces->firmware_request))
    {
        UTIL_FT(ERR_MRK"getCurrentDateTime: firmware_request interface not found");
        break;
    }

    hostInterfaces::hbrt_fw_msg l_request{};
    size_t l_requestSize = sizeof(l_request);
    l_request.io_type = hostInterfaces::HBRT_FW_MSG_TYPE_GET_ELOG_TIME;

    hostInterfaces::hbrt_fw_msg l_response{};
    size_t l_responseSize = sizeof(l_response);

    l_errl = firmware_request_helper(l_requestSize,
                                     &l_request,
                                     &l_responseSize,
                                     &l_response);
    if(l_errl)
    {
        UTIL_FT(ERR_MRK"getCurrentDateTime: firmware_request_helper returned an error; deleting the error and continuing");
        delete l_errl;
        l_errl = nullptr;
        break;
    }

    hostInterfaces::dateTime* l_bcdTime = reinterpret_cast<hostInterfaces::dateTime*>(&l_response);

    l_result.format.year = bcd2dec16(l_bcdTime->year);
    l_result.format.month = bcd2dec8(l_bcdTime->month);
    l_result.format.day = bcd2dec8(l_bcdTime->day);
    l_result.format.hour = bcd2dec8(l_bcdTime->hour);
    l_result.format.minute = bcd2dec8(l_bcdTime->minute);
    l_result.format.second = bcd2dec8(l_bcdTime->second);

    } while(0);

    return l_result;
}

};

// Be sure to log the time when the modules get loaded in
struct logTime
{
    logTime()
    {
        auto l_time = Util::getCurrentDateTime();
        UTIL_FT("Current time (Y/M/D H:M:S) : %.04d/%.02d/%.02d %.02d:%.02d:%.02d",
                l_time.format.year, l_time.format.month, l_time.format.day,
                l_time.format.hour, l_time.format.minute, l_time.format.second);
    }
};

logTime g_logTime;

