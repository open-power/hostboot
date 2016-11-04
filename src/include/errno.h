/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/errno.h $                                         */
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
#ifndef _ERRNO_H
#define _ERRNO_H

#include <map>

// Map to to store strings of errorno codes
typedef std::map<int, const char*> ErrorNoNames;

#define ENOENT           2      // No such file or directory
#define	EIO              5      // I/O error
#define ENXIO            6      // No such device or address
#define ENOEXEC          8      // Exec format error
#define EBADF            9      // Bad file descriptor
#define EAGAIN          11      // Try again
#define EACCES          13      // Permission denied
#define	EFAULT          14      // Bad address
#define EINVAL          22      // Invalid argument
#define ENFILE          23      // Too many open files in system
#define EDEADLK         35      // Operation would cause deadlock.
#define ETIME           62      // Time expired.
#define EALREADY        114     // Operation already in progress

#define EWOULDBLOCK     EAGAIN  // operation would block

// @Brief Initialize an ErrorNoNames map
//  Note: All keys and values are preceded with a '-', this is because the
//  the errno's will be set to 2's complement when there's an error.
inline ErrorNoNames init_map()
{
    ErrorNoNames l_map;
    l_map[-ENOENT]      = "-ENOENT";
    l_map[-EIO]         = "-EIO";
    l_map[-ENXIO]       = "-ENXIO";
    l_map[-ENOEXEC]     = "-ENOEXEC";
    l_map[-EBADF]       = "-EBADF";
    l_map[-EAGAIN]      = "-EAGAIN";
    l_map[-EACCES]      = "-EACCES";
    l_map[-EFAULT]      = "-EFAULT";
    l_map[-EINVAL]      = "-EINVAL";
    l_map[-ENFILE]      = "-ENFILE";
    l_map[-EDEADLK]     = "-EDEADLK";
    l_map[-ETIME]       = "-ETIME";
    l_map[-EALREADY]    = "-EALREADY";
    l_map[-EWOULDBLOCK] = "-EWOULDBLOCK";
    return l_map;
};

#endif
