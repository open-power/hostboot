#ifndef __PNOR_REASONCODES_H
#define __PNOR_REASONCODES_H

#include <hbotcompid.H>

namespace PNOR
{
    enum PNORModuleId
    {
        PNORRP_WAITFORMESSAGE      = 0x01,
    };

    enum PNORReasonCode
    {
        INVALID_MESSAGE           = PNOR_COMP_ID | 0x01,
    };
};

#endif
