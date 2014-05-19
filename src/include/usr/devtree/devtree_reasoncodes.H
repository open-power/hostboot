/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/devtree/devtree_reasoncodes.H $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
#ifndef __DEVTREE_REASONCODES_H
#define __DEVTREE_REASONCODES_H

#include <hbotcompid.H>

namespace DEVTREE
{
    enum DevtreeModuleId
    {
        MOD_DEVTREE_INVALID           = 0x00, /**< Zero is invalid module id */
        MOD_DEVTREE_BLD_MEM           = 0x01,
        MOD_BLD_VPD_IMAGE             = 0x02,
    };

    enum DevtreeReasonCode
    {
        RC_ATTR_MEMSIZE_GET_FAIL            = DEVTREE_COMP_ID | 0x01,
        RC_ATTR_MEMBASE_GET_FAIL            = DEVTREE_COMP_ID | 0x02,
        RC_INSUFFICIENT_SPACE_FOR_RT_VPD    = DEVTREE_COMP_ID | 0x03,
    };
};

#endif
