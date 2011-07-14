#ifndef __XSCOM_REASONCODES_H
#define __XSCOM_REASONCODES_H

#include <hbotcompid.H>

namespace XSCOM
{
    enum xscomModuleId
    {
        XSCOM_PERFORM_OP      = 0x00,
        XSCOM_SANITY_CHECK    = 0x01,
        XSCOM_TEST_XSCOM1     = 0x02,
    };

    enum xscomReasonCode
    {
        XSCOM_STATUS_ERR           = XSCOM_COMP_ID | 0x01,
        XSCOM_INVALID_DATA_BUFFER  = XSCOM_COMP_ID | 0x02,
        XSCOM_INVALID_OP_TYPE      = XSCOM_COMP_ID | 0x03,
        XSCOM_DATA_UNMATCHED       = XSCOM_COMP_ID | 0x04,
    };
};

#endif
