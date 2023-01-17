/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/perv/poz_ring_ids.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
#pragma once

namespace ring_id
{

#define RING_ID_MAXLEN 32
#define RING_ID(id) const char id[] = #id; static_assert(sizeof(id) <= RING_ID_MAXLEN, "Ring ID " #id " exceeds maximum length")

// Regenerate using:
// cat composite_ring_sorting.txt | sed 's/#.*$//;/^[ \t]*$/ d;' | cut -d' ' -f1 | grep -v FAIL | sed 's/.*/    RING_ID(\0);/'

RING_ID(perv_rtg);
RING_ID(perv_initf);
RING_ID(chiplet_rtg);
RING_ID(chiplet_initf);

}
