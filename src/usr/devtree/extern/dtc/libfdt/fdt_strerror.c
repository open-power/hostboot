/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/devtree/extern/dtc/libfdt/fdt_strerror.c $            */
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
*     EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#include "libfdt_env.h"

#include <fdt.h>
#include <libfdt.h>

#include "libfdt_internal.h"

struct fdt_errtabent {
    const char *str;
};

/*
#define FDT_ERRTABENT(val) \
    [(val)] = { .str = #val, }
*/

static struct fdt_errtabent fdt_errtable[] = {
    "FDT_ERR_NOTFOUND",
    "FDT_ERR_EXISTS",
    "FDT_ERR_NOSPACE",

    "FDT_ERR_BADOFFSET",
    "FDT_ERR_BADPATH",
    "FDT_ERR_BADPHANDLE",
    "FDT_ERR_BADSTATE",

    "FDT_ERR_TRUNCATED",
    "FDT_ERR_BADMAGIC",
    "FDT_ERR_BADVERSION",
    "FDT_ERR_BADSTRUCTURE",
    "FDT_ERR_BADLAYOUT",
    "FDT_ERR_INTERNAL",
    "FDT_ERR_BADNCELLS",
    "FDT_ERR_BADVALUE",
    "FDT_ERR_BADOVERLAY",
    "FDT_ERR_NOPHANDLES",
    "FDT_ERR_BADFLAGS",
};
#define FDT_ERRTABSIZE  (sizeof(fdt_errtable) / sizeof(fdt_errtable[0]))

const char *fdt_strerror(int errval)
{
    if (errval > 0)
        return "<valid offset/length>";
    else if (errval == 0)
        return "<no error>";
    else if (errval < (int)FDT_ERRTABSIZE) {
        const char *s = (const char *)(&(fdt_errtable[-errval]));

        if (s)
            return s;
    }

    return "<unknown error>";
}
