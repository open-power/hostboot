/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/ext/key_clear.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
#include <targeting/targplatutil.H>
#include <attributeenums.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <util/misc.H>
#include <secureboot/secure_reasoncodes.H>
#include <secureboot/key_clear_if.H>
#include "../common/securetrace.H"
#include <secureboot/service.H>    // for getSbeSecurityBackdoor();

#ifdef CONFIG_BMC_IPMI
#include <ipmi/ipmisensor.H>
#endif

using namespace TARGETING;
using namespace ERRORLOG;

namespace SECUREBOOT
{

#ifdef CONFIG_BMC_IPMI

void getKeyClearRequestSensor(TARGETING::KEY_CLEAR_REQUEST & o_keyClearRequests)
{
    errlHndl_t err = nullptr;
    o_keyClearRequests = KEY_CLEAR_REQUEST_NONE;

    SB_ENTER("getKeyClearRequestSensor");

    // The sensor has a size of one byte that maps to the MSB of the
    // TARGETING::KEY_CLEAR_REQUEST struct (aka attribute)
    uint8_t value = 0;
    SENSOR::KeyClearRequestSensor sensor;

    err = sensor.getKeyClearRequest( value );
    if ( err )
    {
        err->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
        SB_ERR("getKeyClearRequestSensor: FAIL Getting Key Clear Request Sensor"
               ". Setting to ERRL_SEV_INFORMATIONAL and commiting it here: "
               TRACE_ERR_FMT,
               TRACE_ERR_ARGS(err));
        err->collectTrace( SECURE_COMP_NAME );
        errlCommit(err, SECURE_COMP_ID);

    }
    else
    {
        // Need to shift the value 8 bits to the left to make it the MSBits of
        // the o_keyClearRequests struct (aka attribute)
        o_keyClearRequests = static_cast<TARGETING::KEY_CLEAR_REQUEST>(value << 8);
    }

    SB_EXIT("getKeyClearRequestSensor: err rc=0x%X, "
            "o_keyClearRequests = 0x%.04X",
            ERRL_GETRC_SAFE(err),
            o_keyClearRequests);

    return;
}

errlHndl_t clearKeyClearSensor(void)
{
    errlHndl_t err = nullptr;
    TARGETING::KEY_CLEAR_REQUEST keyClearRequests = KEY_CLEAR_REQUEST_NONE;

    SB_ENTER("clearKeyClearSensor");

    do
    {

    // First Get Current Key Clear Request Sensor Value
    getKeyClearRequestSensor(keyClearRequests);

    // Check if it needs to be cleared
    if (keyClearRequests == KEY_CLEAR_REQUEST_NONE)
    {
        SB_INF("clearKeyClearSensor: no need to clear sensor as it is "
               "already 0x%.4X",
               keyClearRequests);
        break;
    }

    // Need to write zero back to sensor value
    // NOTE: the sensor value is only a uint8_t whereas
    // keyClearRequests is a uint16_t
    uint8_t clear_value = 0;
    SENSOR::KeyClearRequestSensor sensor;

    err = sensor.setKeyClearRequest( clear_value );
    if ( err )
    {
        SB_ERR("clearKeyClearSensor: "
               "FAIL Setting Key Clear Request Sensor: "
               TRACE_ERR_FMT,
               TRACE_ERR_ARGS(err));
        break;
    }

    // Read back to make sure it's cleared
    getKeyClearRequestSensor(keyClearRequests);

    // Check if it needs to be cleared
    if (keyClearRequests == KEY_CLEAR_REQUEST_NONE)
    {
        SB_INF("clearKeyClearSensor: Key Clear Requests Sensor has been cleared");
    }
    else
    {
        SB_ERR("clearKeyClearSensor: Failed to clear KeyClearRequestSensor: "
               "Expected 0x%.4X, Actual 0x%.4X",
               KEY_CLEAR_REQUEST_NONE, keyClearRequests);

        /*@
         * @errortype
         * @reasoncode       RC_CLEARING_KEY_CLEAR_SENSOR_FAILED
         * @severity         ERRL_SEV_UNRECOVERABLE
         * @moduleid         MOD_CLEAR_KEY_CLEAR_SENSOR
         * @userdata1        Expected Key Clear Request Sensor Value
         * @userdata2        Actual Key Clear Request Sensor Value
         * @devdesc          Attempt to clear the Key Clear Request Sensor
         *                   failed as it still requests some keys to be cleared
         * @custdesc         A problem occurred during the IPL
         *                   of the system.
         */
        err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                            MOD_CLEAR_KEY_CLEAR_SENSOR,
                            RC_CLEARING_KEY_CLEAR_SENSOR_FAILED,
                            KEY_CLEAR_REQUEST_NONE,
                            keyClearRequests,
                            ErrlEntry::ADD_SW_CALLOUT);

        break;

    }

    } while(0);

    if (err)
    {
        err->collectTrace( SECURE_COMP_NAME );
    }

    SB_EXIT("clearKeyClearSensor: err rc=0x%X",
            ERRL_GETRC_SAFE(err));

    return err;
}

#endif // (#ifdef CONFIG_BMC_IPMI)

#ifndef CONFIG_BMC_IPMI
void getKeyClearRequestAttr(TARGETING::KEY_CLEAR_REQUEST & o_keyClearRequests)
{
    SB_ENTER("getKeyClearRequestAttr");

    // Get the attributes associated with Key Clear Requests
    Target* sys = UTIL::assertGetToplevelTarget();

    o_keyClearRequests = sys->getAttr<ATTR_KEY_CLEAR_REQUEST>();

    SB_EXIT("getKeyClearRequestAttr: o_keyClearRequests = 0x%.04X",
            o_keyClearRequests);

    return;
}
#endif // (#ifndef CONFIG_BMC_IPMI)

void getKeyClearRequest(bool & o_requestPhysPres,
                        TARGETING::KEY_CLEAR_REQUEST & o_keyClearRequests)
{
    SB_ENTER("getKeyClearRequest");

    o_requestPhysPres = false;
    o_keyClearRequests = KEY_CLEAR_REQUEST_NONE;
    TARGETING::KEY_CLEAR_REQUEST l_keyClearRequests = KEY_CLEAR_REQUEST_NONE;

    do
    {

    // Get Key Clear Request information
#ifndef CONFIG_BMC_IPMI
    SB_DBG("getKeyClearRequest: calling getKeyClearRequestAttr");
    getKeyClearRequestAttr(l_keyClearRequests);
#else
    SB_DBG("getKeyClearRequest: calling getKeyClearRequestSensor");
    getKeyClearRequestSensor(l_keyClearRequests);
#endif

    // First check if either the KEY_CLEAR_REQUEST_MFG bit or the
    // KEY_CLEAR_REQUEST_MFG_ALL bit are set.
    // If we have a production driver and security is set, we must clear these bits
    // Using the presence of a backdoor to assert we have an imprint/development
    // driver
    bool isImprintDriver = SECUREBOOT::getSbeSecurityBackdoor();

    if (((l_keyClearRequests & KEY_CLEAR_REQUEST_MFG) ||
         (l_keyClearRequests & KEY_CLEAR_REQUEST_MFG_ALL)) &&
        ((isImprintDriver == false) &&
          SECUREBOOT::enabled()))
    {
        // create a temporary variable and clear the bit
        uint16_t tmp = static_cast<uint16_t>(l_keyClearRequests);
        tmp &= ~(KEY_CLEAR_REQUEST_MFG | KEY_CLEAR_REQUEST_MFG_ALL);

        SB_INF("getKeyClearRequest: Either/both KEY_CLEAR_REQUEST_MFG (0x%.04X)"
               " or KEY_CLEAR_REQUEST_MFG_ALL (0x%.04X) is set on a production "
               "driver with security enabled: 0x%.04X. Clearing these bits so "
               "new value is 0x%.04X",
               KEY_CLEAR_REQUEST_MFG, KEY_CLEAR_REQUEST_MFG_ALL,
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
        // If it's -ONLY- KEY_CLEAR_REQUEST_MFG --OR-- KEY_CLEAR_REQUEST_MFG_ALL
        // then there's no need to request physical presence assertion
        if ((l_keyClearRequests == KEY_CLEAR_REQUEST_MFG) ||
            (l_keyClearRequests == KEY_CLEAR_REQUEST_MFG_ALL))
        {
            o_requestPhysPres = false;
            SB_INF("getKeyClearRequest: Only KEY_CLEAR_REQUEST_MFG (0x%.04X) "
                   "or KEY_CLEAR_REQUEST_MFG_ALL (0x%.04X) is set: 0x%.04X. "
                   "No need to request physical presence assertion",
                   KEY_CLEAR_REQUEST_MFG, KEY_CLEAR_REQUEST_MFG_ALL,
                   l_keyClearRequests);
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

    // Set (potentially updated) Key Clear Requests attribute
    Target* sys = UTIL::assertGetToplevelTarget();
    sys->setAttr<ATTR_KEY_CLEAR_REQUEST>(l_keyClearRequests);

    } while (0);

    SB_EXIT("getKeyClearRequest: o_requestPhysPres = %s, "
            "o_keyClearRequests = 0x%.04X",
            o_requestPhysPres ? "TRUE" : "FALSE",
            o_keyClearRequests);

    return;
}

} // namespace SECUREBOOT
