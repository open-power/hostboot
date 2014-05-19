/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/ibscom/ibscomreasoncodes.H $                  */
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
#ifndef __IBSCOM_REASONCODES_H
#define __IBSCOM_REASONCODES_H

#include <hbotcompid.H>

namespace IBSCOM
{
    enum ibscomModuleId
    {
        IBSCOM_INVALID               = 0x00,
        IBSCOM_PERFORM_OP            = 0x01,
        IBSCOM_SANITY_CHECK          = 0x02,
        IBSCOM_GET_TARG_VIRT_ADDR    = 0x03,
        IBSCOM_DO_IBSCOM             = 0x04,
    };

    enum ibscomReasonCode
    {
        IBSCOM_INVALID_DATA_BUFFER  = IBSCOM_COMP_ID | 0x01,
        IBSCOM_INVALID_OP_TYPE      = IBSCOM_COMP_ID | 0x02,
        IBSCOM_INVALID_CONFIG       = IBSCOM_COMP_ID | 0x03,
        IBSCOM_SUE_OCCURRED         = IBSCOM_COMP_ID | 0x04,
        IBSCOM_SUE_IN_ERR_PATH      = IBSCOM_COMP_ID | 0x05,
        IBSCOM_BUS_FAILURE          = IBSCOM_COMP_ID | 0x06,
        IBSCOM_INVALID_ADDRESS      = IBSCOM_COMP_ID | 0x07,
        IBSCOM_PIB_FAILURE          = IBSCOM_COMP_ID | 0x08,
        IBSCOM_WRONG_ERROR          = IBSCOM_COMP_ID | 0x09,
        IBSCOM_RETRY_DUE_TO_ERROR   = IBSCOM_COMP_ID | 0x0A,
    };
};

#endif
