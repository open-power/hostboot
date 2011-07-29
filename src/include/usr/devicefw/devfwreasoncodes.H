#ifndef __DEVICEFW_DEVFWREASONCODES_H
#define __DEVICEFW_DEVFWREASONCODES_H

#include <hbotcompid.H>

namespace DeviceFW
{
    enum DevFwModuleId
    {
        DEVFW_MOD_ASSOCIATOR    = 0x01,
    };

    enum DevFwReasonCode
    {
        DEVFW_RC_INVALID_REGISTRATION   = DEVFW_COMP_ID | 0x01,
        DEVFW_RC_NO_ROUTE_FOUND         = DEVFW_COMP_ID | 0x02,
    };
};

#endif
