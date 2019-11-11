/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mctp/libmctp-astlpc.h $                               */
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

#ifndef _LIBMCTP_ASTLPCL_H
#define _LIBMCTP_ASTLPCL_H

#ifdef __cplusplus
extern "C" {
#endif


#include "libmctp.h"

#include <unistd.h>

struct mctp_binding_astlpc;

enum mctp_binding_astlpc_kcs_reg {
	MCTP_ASTLPC_KCS_REG_DATA = 0,
	MCTP_ASTLPC_KCS_REG_STATUS = 1,
};

struct mctp_binding_astlpc_ops {
	int	(*kcs_read)(void *data, enum mctp_binding_astlpc_kcs_reg reg,
			uint8_t *val);
	int	(*kcs_write)(void *data, enum mctp_binding_astlpc_kcs_reg reg,
			uint8_t val);
	int	(*lpc_read)(void *data, void *buf, off_t offset, size_t len);
	int	(*lpc_write)(void *data, void *buf, off_t offset, size_t len);
};

struct mctp_binding_astlpc *mctp_astlpc_init_ops(
		struct mctp_binding_astlpc_ops *ops,
		void *ops_data, void *lpc_map);

struct mctp_binding *mctp_binding_astlpc_core(struct mctp_binding_astlpc *b);

int mctp_astlpc_poll(struct mctp_binding_astlpc *astlpc);

/* fileio-based interface */
struct mctp_binding_astlpc *mctp_astlpc_init_fileio(void);
int mctp_astlpc_get_fd(struct mctp_binding_astlpc *astlpc);

#ifdef __cplusplus
}
#endif

#endif /* _LIBMCTP_ASTLPCL_H */
