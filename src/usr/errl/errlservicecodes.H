#ifndef __ERRL_SERVICE_CODE_H
#define __ERRL_SERVICE_CODE_H

/**
 *  @file errlservicecodes.H
 *
 *  @brief  Reason code and Module ID definitions for ERRL component.
 *
 */

#include <hbotcompid.H>

// Module IDs for ERRL component
enum
{
    ERRL_FIRST_MODULE_ID        = 0x00,
    //........
    ERRL_LAST_MODULE_ID         = 0xFF
};

// Reason codes for ERRL component
enum errlReasonCode
{
    ERRL_FIRST_ERR          = ERRL_COMP_ID | 0x01,
    //........
    ERRL_LAST_ERR           = ERRL_COMP_ID | 0xFF
};


#endif
