/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/errno.h $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2023                        */
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

/**
 * @file errno.h
 * @brief Defines error number for standard errors
 */

#define ENOENT           2      // No such file or directory
#define EIO              5      // I/O error
#define ENXIO            6      // No such device or address
#define ENOEXEC          8      // Exec format error
#define EBADF            9      // Bad file descriptor
#define EAGAIN          11      // Try again
#define ENOMEM          12      // Not enough space
#define EACCES          13      // Permission denied
#define EFAULT          14      // Bad address
#define EBUSY           16      // Device or resource busy
#define EINVAL          22      // Invalid argument
#define ENFILE          23      // Too many open files in system
#define EDEADLK         35      // Operation would cause deadlock.
#define ETIME           62      // Time expired.
#define EMSGSIZE        90      // Message too long
#define EHOSTDOWN       112     // Host is down
#define EALREADY        114     // Operation already in progress

#define EWOULDBLOCK     EAGAIN  // operation would block

/**
  * @brief Returns string representation of an errno.
  *
  * @param[in] i_errno     errno to get string for.
  *
  * @return  const char*  - If found, String associated with errno
  *                         else, "UNKNOWN" string
  *
*/
const char * ErrnoToString( int i_errno );


#endif
