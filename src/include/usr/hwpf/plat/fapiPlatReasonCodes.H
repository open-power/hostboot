#ifndef FAPIPLATREASONCODES_H_
#define FAPIPLATREASONCODES_H_

#include <hbotcompid.H>

namespace fapi
{
    enum hwpfModuleId
    {
        MOD_RC_TO_ERRL  = 0x01,
    };

    enum hwpfReasonCode
    {
        RC_HWP_ERROR  = HWPF_COMP_ID | 0x01,
        RC_FAPI_ERROR = HWPF_COMP_ID | 0x02,
    };
};

#endif
