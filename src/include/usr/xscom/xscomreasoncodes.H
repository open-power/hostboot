/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/xscom/xscomreasoncodes.H $                    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
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
    };

    enum xscomReasonCode
    {
        XSCOM_STATUS_ERR           = XSCOM_COMP_ID | 0x01,
        XSCOM_INVALID_DATA_BUFFER  = XSCOM_COMP_ID | 0x02,
        XSCOM_INVALID_OP_TYPE      = XSCOM_COMP_ID | 0x03,
        XSCOM_DATA_UNMATCHED       = XSCOM_COMP_ID | 0x04,
        XSCOM_MMIO_UNMAP_ERR       = XSCOM_COMP_ID | 0x05,
    };
};

#endif
