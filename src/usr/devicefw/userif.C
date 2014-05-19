/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/devicefw/userif.C $                                   */
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
/** @file driverif.C
 *  Implement the functions from userif.H.
 */

#include <devicefw/userif.H>
#include <util/singleton.H>

#include "associator.H"

namespace DeviceFW
{
    errlHndl_t deviceRead(TARGETING::Target* i_target, 
                          void* o_buffer, size_t& io_buflen,
                          AccessType i_accessType, ...)
    {
        va_list args;
        errlHndl_t errl;

        va_start(args, i_accessType);

        errl = Singleton<Associator>::instance().performOp(
                READ, i_target, o_buffer, io_buflen,
                i_accessType, args);

        va_end(args);
        return errl;
    }

    errlHndl_t deviceWrite(TARGETING::Target* i_target, 
                           void* i_buffer, size_t& io_buflen,
                           AccessType i_accessType, ...)
    {
        va_list args;
        errlHndl_t errl;

        va_start(args, i_accessType);

        errl = Singleton<Associator>::instance().performOp(
                WRITE, i_target, i_buffer, io_buflen,
                i_accessType, args);

        va_end(args);
        return errl;
    }

};
