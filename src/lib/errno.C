/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/lib/errno.C $                                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2021                        */
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
#include <errno.h>
#include <map>

const char * ErrnoToString( int i_errno )
{
    //  Map of errnos to string.
    //  Kept within function for deferred malloc and more error handling
    //      Otherwise the map is malloc'd before memory is initialized
    //  Note: All keys and values are preceded with a '-', this is because the
    //        the errno's will be set to 2's complement when there's an error.
    static const std::map<int, const char*> ErrnoToStringMap =
    {
        { -ENOENT     , "-ENOENT"},
        { -EIO        , "-EIO"},
        { -ENXIO      , "-ENXIO"},
        { -ENOEXEC    , "-ENOEXEC"},
        { -EBADF      , "-EBADF"},
        { -EAGAIN     , "-EAGAIN"},
        { -EACCES     , "-EACCES"},
        { -EFAULT     , "-EFAULT"},
        { -EINVAL     , "-EINVAL"},
        { -ENFILE     , "-ENFILE"},
        { -EDEADLK    , "-EDEADLK"},
        { -ETIME      , "-ETIME"},
        { -EALREADY   , "-EALREADY"},
        { -EWOULDBLOCK, "-EWOULDBLOCK"},
    };

    if (ErrnoToStringMap.count(i_errno) > 0)
    {
        return ErrnoToStringMap.at(i_errno);
    }
    else
    {
        return "UNKNOWN";
    }
}