/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/xscom/xscomreasoncodes.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
#ifndef __XSCOM_REASONCODES_H
#define __XSCOM_REASONCODES_H

#include <hbotcompid.H>

namespace XSCOM
{
    enum xscomModuleId
    {
        XSCOM_PERFORM_OP            = 0x00,
        XSCOM_SANITY_CHECK          = 0x01,
        XSCOM_TEST_XSCOM1           = 0x02,
        XSCOM_GET_TARGET_VIRT_ADDR  = 0x03,
        XSCOM_TEST_XSCOM2           = 0x04,
        XSCOM_COLLECT_FFDC          = 0x05,
        XSCOM_RESET                 = 0x06,
        XSCOM_DO_OP                 = 0x07,
        XSCOM_RT_DO_OP              = 0x08,
        XSCOM_RT_SANITY_CHECK       = 0x09,
    };

    enum xscomReasonCode
    {
        XSCOM_STATUS_ERR           = XSCOM_COMP_ID | 0x01,
        XSCOM_INVALID_DATA_BUFFER  = XSCOM_COMP_ID | 0x02,
        XSCOM_INVALID_OP_TYPE      = XSCOM_COMP_ID | 0x03,
        XSCOM_DATA_UNMATCHED       = XSCOM_COMP_ID | 0x04,
        XSCOM_MMIO_UNMAP_ERR       = XSCOM_COMP_ID | 0x05,
        XSCOM_RUNTIME_ERR          = XSCOM_COMP_ID | 0x06,
        XSCOM_RUNTIME_INTERFACE_ERR = XSCOM_COMP_ID | 0x07,
    };
};

#endif
