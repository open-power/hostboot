/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/build/tools/calc-attribute-size-info/calc_attr_size.C $   */
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

/* This program iterates each hostboot attribute and prints its ID and size to
 * standard output. It is used by HostAttrDump.pm to dump HB attributes using
 * the debug framework. */

#define assert(X) (void)0

#include <targeting/common/attributes.H>

#include "mapattrmetadata.H"

#include <unistd.h>
#include <stdio.h>

int main() {
    printf("ATTR_HUID, %d\n", TARGETING::ATTR_HUID);

    for (auto& i : TARGETING::theMapAttrMetadata::instance().getMapMetadataForAllAttributes())
    {
        printf("%d, %d\n", i.first, i.second.size);
    }
}
