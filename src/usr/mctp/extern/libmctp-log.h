/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mctp/extern/libmctp-log.h $                           */
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
/* SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later */

#ifndef _LIBMCTP_LOG_H
#define _LIBMCTP_LOG_H

/* libmctp-internal logging */

void mctp_prlog(int level, const char *fmt, ...)
	__attribute__((format(printf, 2, 3)));

#define mctp_prerr(fmt, ...)  mctp_prlog(MCTP_LOG_ERR, fmt, ##__VA_ARGS__)
#define mctp_prwarn(fmt, ...) mctp_prlog(MCTP_LOG_WARNING, fmt, ##__VA_ARGS__)
#define mctp_prinfo(fmt, ...) mctp_prlog(MCTP_LOG_INFO, fmt, ##__VA_ARGS__)
#define mctp_prdebug(fmt, ...)  mctp_prlog(MCTP_LOG_DEBUG, fmt, ##__VA_ARGS__)


#endif /* _LIBMCTP_LOG_H */
