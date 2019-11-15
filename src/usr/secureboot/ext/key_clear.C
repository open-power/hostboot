/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/ext/key_clear.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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
/**
 * @file key_clear.C
 *
 * @brief Implements Interfaces to Process Key Clear Requests
 */

#include <targeting/common/util.H>
#include <targeting/common/target.H>
#include <attributeenums.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <util/misc.H>
#include <secureboot/secure_reasoncodes.H>
#include <secureboot/key_clear_if.H>
#include "../common/securetrace.H"
#include <secureboot/service.H>    // for getSbeSecurityBackdoor();

using namespace TARGETING;

namespace SECUREBOOT
{

#ifdef CONFIG_BMC_IPMI

errlHndl_t clearKeyClearSensor(void)
{
    errlHndl_t err = nullptr;

    // TODO RTC 210301 - Add Support for this function
    SB_ENTER("clearKeyClearSensor");

    SB_EXIT("clearKeyClearSensor: err rc=0x%X",
            ERRL_GETRC_SAFE(err));

    return err;
}

errlHndl_t getKeyClearRequestSensor(
                    TARGETING::KEY_CLEAR_REQUEST & o_keyClearRequests)
{
    errlHndl_t err = nullptr;

    // TODO RTC 210301 - Add Support for this function
    SB_ENTER("getKeyClearRequestSensor");

    SB_EXIT("getKeyClearRequestSensor: err rc=0x%X, "
            "o_keyClearRequests = 0x%.04X",
            ERRL_GETRC_SAFE(err),
            o_keyClearRequests);

    return err;
}
#endif // (#ifdef CONFIG_BMC_IPMI)

#ifndef CONFIG_BMC_IPMI
static errlHndl_t getKeyClearRequestAttr(
                    TARGETING::KEY_CLEAR_REQUEST & o_keyClearRequests)
{
    errlHndl_t err = nullptr;

    SB_ENTER("getKeyClearRequestAttr");

    // Get the attributes associated with Key Clear Requests
    TargetService& tS = targetService();
    Target* sys = nullptr;
    (void) tS.getTopLevelTarget( sys );
    assert(sys, "getKeyClearRequestAttr: system target is nullptr");

    o_keyClearRequests = sys->getAttr<ATTR_KEY_CLEAR_REQUEST>();

    SB_EXIT("getKeyClearRequestAttr: err rc=0x%X, "
            "o_keyClearRequests = 0x%.04X",
            ERRL_GETRC_SAFE(err),
            o_keyClearRequests);

    return err;
}
#endif // (#ifndef CONFIG_BMC_IPMI)

errlHndl_t getKeyClearRequest(
                   bool & o_requestPhysPres,
                   TARGETING::KEY_CLEAR_REQUEST & o_keyClearRequests)
{
    errlHndl_t err = nullptr;

    SB_ENTER("getKeyClearRequest");

    o_requestPhysPres = false;
    o_keyClearRequests = KEY_CLEAR_REQUEST_NONE;
    TARGETING::KEY_CLEAR_REQUEST l_keyClearRequests = KEY_CLEAR_REQUEST_NONE;

    do
    {
    // Not supported in simics
    if (Util::isSimicsRunning())
    {
        SB_ERR("getKeyClearRequest: Skipping as not supported in simics");

        break;
    }

    // Get Key Clear Request information
#ifndef CONFIG_BMC_IPMI
    SB_DBG("getKeyClearRequest: calling getKeyClearRequestAttr");
    err = getKeyClearRequestAttr(l_keyClearRequests);
    if(err)
    {
        SB_ERR("getKeyClearRequest: call to getKeyClearRequestAttr failed. "
               "err_plid=0x%X, err_rc=0x%X",
               ERRL_GETPLID_SAFE(err),
               ERRL_GETRC_SAFE(err));

        err->collectTrace(SECURE_COMP_NAME);
        break;
    }
#else
    SB_DBG("getKeyClearRequest: calling getKeyClearRequestSensor");
    err = getKeyClearRequestSensor(l_keyClearRequests);
    if(err)
    {
        SB_ERR("getKeyClearRequest: call to getKeyClearRequestSensor failed. "
               "err_plid=0x%X, err_rc=0x%X",
               ERRL_GETPLID_SAFE(err),
               ERRL_GETRC_SAFE(err));

        err->collectTrace(SECURE_COMP_NAME);
        break;
    }
#endif

    // First check if the KEY_CLEAR_REQUEST_MFG bit is set and we have a
    // production driver; if so, clear this bit
    // Using the presence of a backdoor to assert we have an imprint/development
    // driver
    bool isImprintDriver = SECUREBOOT::getSbeSecurityBackdoor();

    if ((l_keyClearRequests & KEY_CLEAR_REQUEST_MFG) &&
        (isImprintDriver == false))
    {
        // create a temporary vairable and clear the bit
        uint16_t tmp = static_cast<uint16_t>(l_keyClearRequests);
        tmp &= ~(KEY_CLEAR_REQUEST_MFG);

        SB_INF("getKeyClearRequest: KEY_CLEAR_REQUEST_MFG (0x%.04X) is set "
               "on a production driver: 0x%.04X. Clearing this bit so new "
               "value is 0x%.04X",
                KEY_CLEAR_REQUEST_MFG,
                l_keyClearRequests, tmp);

        // set output parameter to updated temporary variable
        l_keyClearRequests = static_cast<TARGETING::KEY_CLEAR_REQUEST>(tmp);
    }

    // if we got here then we can set output variable
    o_keyClearRequests = l_keyClearRequests;

    // Check to see if the Key Clear Requests data requires a
    // physical presence assertion (defaulted to false above)
    if (l_keyClearRequests != KEY_CLEAR_REQUEST_NONE)
    {
        // If it's -ONLY- KEY_CLEAR_REQUEST_MFG and an imprint driver
        // then there's no need to request physical presence assertion
        if ((l_keyClearRequests == KEY_CLEAR_REQUEST_MFG) &&
            (isImprintDriver == true))
        {
            o_requestPhysPres = false;
            SB_INF("getKeyClearRequest: Only KEY_CLEAR_REQUEST_MFG (0x%.04X) is set "
                   "on a imprint driver: 0x%.04X. No need to request physical "
                   "presence assertion",
                    KEY_CLEAR_REQUEST_MFG, l_keyClearRequests);
            o_requestPhysPres = false;
        }
        // Some bit(s) are set and therefore require physical presence assertion
        else
        {
            o_requestPhysPres = true;

            SB_INF("getKeyClearRequest: KEY_CLEAR_REQUEST value 0x%.04X "
                   "requires physical presence assertion. "
                   "Setting o_requestPhysPres to %d",
                    l_keyClearRequests, o_requestPhysPres);
        }
    }

    } while (0);

    SB_EXIT("getKeyClearRequest: err rc=0x%X, "
            "o_requestPhysPres = %s, "
            "o_keyClearRequests = 0x%.04X",
            ERRL_GETRC_SAFE(err),
            o_requestPhysPres ? "TRUE" : "FALSE",
            o_keyClearRequests);

    return err;
}

} // namespace SECUREBOOT
