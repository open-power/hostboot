/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/devtree/extern/dtc/libfdt/fdt_wip.c $                 */
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
* Copyright (C) 2006 David Gibson, IBM Corporation.
*/
#include "libfdt_env.h"

#include <fdt.h>
#include <libfdt.h>

#include "libfdt_internal.h"

int fdt_setprop_inplace_namelen_partial(void *fdt, int nodeoffset,
                    const char *name, int namelen,
                    uint32_t idx, const void *val,
                    int len)
{
    void *propval;
    int proplen;

    propval = fdt_getprop_namelen_w(fdt, nodeoffset, name, namelen,
                    &proplen);
    if (!propval)
        return proplen;

    if (proplen < (len + (int)idx))
        return -FDT_ERR_NOSPACE;

    memcpy((char *)propval + idx, val, len);
    return 0;
}

int fdt_setprop_inplace(void *fdt, int nodeoffset, const char *name,
            const void *val, int len)
{
    const void *propval;
    int proplen;

    propval = fdt_getprop(fdt, nodeoffset, name, &proplen);
    if (!propval)
        return proplen;

    if (proplen != len)
        return -FDT_ERR_NOSPACE;

    return fdt_setprop_inplace_namelen_partial(fdt, nodeoffset, name,
                        strlen(name), 0,
                        val, len);
}

static void fdt_nop_region_(void *start, int len)
{
    fdt32_t *p;

    for (p = (fdt32_t *)start; (char *)p < ((char *)start + len); p++)
        *p = cpu_to_fdt32(FDT_NOP);
}

int fdt_nop_property(void *fdt, int nodeoffset, const char *name)
{
    struct fdt_property *prop;
    int len;

    prop = fdt_get_property_w(fdt, nodeoffset, name, &len);
    if (!prop)
        return len;

    fdt_nop_region_(prop, len + sizeof(*prop));

    return 0;
}

int fdt_node_end_offset_(void *fdt, int offset)
{
    int depth = 0;

    while ((offset >= 0) && (depth >= 0))
        offset = fdt_next_node(fdt, offset, &depth);

    return offset;
}

int fdt_nop_node(void *fdt, int nodeoffset)
{
    int endoffset;

    endoffset = fdt_node_end_offset_(fdt, nodeoffset);
    if (endoffset < 0)
        return endoffset;

    fdt_nop_region_(fdt_offset_ptr_w(fdt, nodeoffset, 0),
            endoffset - nodeoffset);
    return 0;
}
