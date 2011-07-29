#ifndef __PNOR_REASONCODES_H
#define __PNOR_REASONCODES_H

#include <hbotcompid.H>

namespace PNOR
{
    enum PNORModuleId
    {
        MOD_PNORRP_WAITFORMESSAGE      = 0x01, /**< pnorrp.C : PnorRP::waitForMessage */
        MOD_PNORRP_COMPUTEDEVICEADDR   = 0x02, /**< pnorrp.C : PnorRP::computeDeviceAddr */
        MOD_PNORRP_GETSECTIONINFO      = 0x03, /**< pnorrp.C : PnorRP::getSectionInfo */
        MOD_PNORRP_COMPUTESECTION      = 0x04, /**< pnorrp.C : PnorRP::computeSection */
    };

    enum PNORReasonCode
    {
        RC_INVALID_MESSAGE           = PNOR_COMP_ID | 0x01, 
        RC_INVALID_ADDRESS           = PNOR_COMP_ID | 0x02,
        RC_INVALID_SECTION           = PNOR_COMP_ID | 0x03,
    };
};

#endif
