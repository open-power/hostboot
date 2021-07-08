/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mctp/hostboot_mctp.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
#ifndef _HOSTBOOT_MCTP_H
#define _HOSTBOOT_MCTP_H

// Headers from local directory
#include "libmctp-lpc.h"

// Provide functions that will perform a KCS register
// read/writes to fufill the binding requirements
extern "C"
int __mctp_hostlpc_hostboot_kcs_read(void *arg,
    enum mctp_binding_lpc_kcs_reg reg, uint8_t *val);
extern "C"
int __mctp_hostlpc_hostboot_kcs_write(void *arg,
    enum mctp_binding_lpc_kcs_reg reg, uint8_t val);

// Provide functions that will perform a LPC read/writes
// in the MCTP space to fufill the binding requirements
extern "C"
int __mctp_hostlpc_hostboot_lpc_read(void *arg,
    void * buf, uint64_t offset, size_t len);
extern "C"
int __mctp_hostlpc_hostboot_lpc_write(void *arg,
    void * buf, uint64_t offset, size_t len);

// Provide a function that will sleep for a given amount
// of seconds or nanoseconds
extern "C"
void __mctp_hostlpc_hostboot_nanosleep(uint64_t i_sec,
                                       uint64_t i_nsec);

// Perform a shutdown with the provided error code
extern "C"
void __mctp_hostlpc_hostboot_do_shutdown(uint64_t i_status);

// Print the provided string to the console
extern "C"
void __mctp_hostlpc_hostboot_console_print(const char* i_message);

#endif
