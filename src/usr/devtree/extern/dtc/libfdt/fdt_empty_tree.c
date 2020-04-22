/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/devtree/extern/dtc/libfdt/fdt_empty_tree.c $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
// SPDX-License-Identifier: (GPL-2.0-or-later OR BSD-2-Clause)
/*
* libfdt - Flat Device Tree manipulation
* Copyright (C) 2012 David Gibson, IBM Corporation.
*/
#include "libfdt_env.h"

#include <fdt.h>
#include <libfdt.h>

#include "libfdt_internal.h"

int fdt_create_empty_tree(void *buf, int bufsize)
{
    int err;

    err = fdt_create(buf, bufsize);
    if (err)
        return err;

    err = fdt_finish_reservemap(buf);
    if (err)
        return err;

    err = fdt_begin_node(buf, "");
    if (err)
        return err;

    err =  fdt_end_node(buf);
    if (err)
        return err;

    err = fdt_finish(buf);
    if (err)
        return err;

    return fdt_open_into(buf, buf, bufsize);
}
