/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/ibscom/ibscomreasoncodes.H $                  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
    };
};

#endif
