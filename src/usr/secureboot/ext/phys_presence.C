/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/ext/phys_presence.C $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
 * @file phys_presence.C
 *
 * @brief Implements Interfaces to Detect and Open Physical Presence Windows
 *
 */

#include <config.h>
#include <targeting/common/util.H>
#include <targeting/common/target.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <devicefw/driverif.H>
#include <console/consoleif.H>
#include <util/misc.H>
#include <initservice/initserviceif.H>
#include <initservice/istepdispatcherif.H>
#include <secureboot/secure_reasoncodes.H>
#include <secureboot/phys_presence_if.H>
#include "../common/securetrace.H"
#include <gpio/gpioif.H>

using namespace TARGETING;
using namespace GPIO;

namespace SECUREBOOT
{

errlHndl_t detectPhysPresence(void)
{
    errlHndl_t err = nullptr;

    SB_ENTER("detectPhysPresence");

    // Not supported in simics
    if (Util::isSimicsRunning())
    {
        SB_ERR("detectPhysPresence: Skipping as not supported in simics");

        // Normally don't have multiple return statements, but
        // this solves having 2 do-while loops
        return err;
    }

    // Declare local variables here as there might be an operation
    // after the do-while() loop
    Target * mproc = nullptr;
    uint8_t led_data = 0;
    ATTR_GPIO_INFO_PHYS_PRES_type gpioInfo = {};
    uint8_t led_window_open = 0;
    uint8_t led_phys_pres_asserted = 0;
    bool is_window_open = false;
    bool is_phys_pres_asserted = false;

    // Get the attributes associated with Physical Presence
    TargetService& tS = targetService();
    Target* sys = nullptr;
    (void) tS.getTopLevelTarget( sys );
    assert(sys, "detectPhysPresence: system target is nullptr");

    do
    {
    uint8_t attr_open_window =
        sys->getAttr<ATTR_PHYS_PRES_REQUEST_OPEN_WINDOW>();

    uint8_t attr_fake_assert = sys->getAttr<ATTR_PHYS_PRES_FAKE_ASSERT>();
    // NOTE: Using attributes to request opening the physical presence window
    // and/or fake the assertion of physical presence is only for testing
    // purposes.  Both attributes will default to 'no' and cannot be changed
    // when security is enabled in a production driver since attribute
    // overrides are not allowed in that scenario.
    SB_INF("detectPhysPresence: attr_open_window=%d (0x%X), "
           "attr_fake_assert=%d (0x%X)",
           attr_open_window, attr_open_window,
           attr_fake_assert, attr_fake_assert);

    // The PCA9551 device that controls the "window open" and
    // "physical presence asserted" logic is connected to the master processor
    err = targetService().queryMasterProcChipTargetHandle(mproc);
    if(err)
    {
        SB_ERR("detectPhysPresence: call to queryMasterProcChipTargetHandle "
               "failed.  err_plid=0x%X, err_rc=0x%X",
               ERRL_GETPLID_SAFE(err),
               ERRL_GETRC_SAFE(err));

        err->collectTrace(SECURE_COMP_NAME);
        break;
    }

    // Get the attribute with the needed GPIO information
    if (mproc->tryGetAttr<ATTR_GPIO_INFO_PHYS_PRES>(gpioInfo))
    {
        SB_INF("detectPhysPresence: gpioInfo: e%d/p%d/devAddr=0x%X, "
               "windowOpenPin=%d, physPresPin=%d",
               gpioInfo.engine, gpioInfo.port, gpioInfo.devAddr,
               gpioInfo.windowOpenPin, gpioInfo.physicalPresencePin);
    }
    else
    {
        SB_ERR("detectPhysPresence: couldn't find GPIO_INFO_PHYS_PRES "
               "on mproc 0x%.08X", get_huid(mproc));

        /*@
         * @errortype
         * @reasoncode       RC_PHYS_PRES_ATTR_NOT_FOUND
         * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid         MOD_PHYS_PRES_DETECT
         * @userdata1        HUID of Master Processor Target
         * @userdata2        ATTR_GPIO_INFO_PHYS_PRES hash value
         * @devdesc          Master processor target did not have
         *                   ATTR_GPIO_INFO_PHYS_PRES associated with it
         * @custdesc         A problem occurred during the IPL
         *                   of the system.
         */
        err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      MOD_PHYS_PRES_DETECT,
                                      RC_PHYS_PRES_ATTR_NOT_FOUND,
                                      get_huid(mproc),
                                      ATTR_GPIO_INFO_PHYS_PRES,
                                      ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

        err->collectTrace( SECURE_COMP_NAME );
        break;
    }

    // Get "window open" and "physical presence asserted" LEDs/Pins
    led_window_open = PCA9551_LED0 << gpioInfo.windowOpenPin;
    led_phys_pres_asserted = PCA9551_LED0 << gpioInfo.physicalPresencePin;

    // Read PCA9551 INPUT Register to get LED Values
    led_data = 0;
    err = gpioPca9551GetLeds(mproc, led_data);
    if(err)
    {
        SB_ERR("detectPhysPresence: Reading LEDs failed");
        break;
    }

    // Look for "window open" and "physical presence asserted"
    // LEDs/PINs represent "WINDOW_OPEN_N" and "PHYS_PRESENCE_N" so need
    // to invert their values to get their true meaning
    is_window_open = ! (led_window_open & led_data);

    // Only care if its asserted if the window is open
    // (technically it's not supposed to be asserted unless the window is open)
    is_phys_pres_asserted = is_window_open &&
                            (! (led_phys_pres_asserted & led_data));


    // Look for special case to fake assertion
    if ((is_window_open == true ) &&
        (is_phys_pres_asserted == false) &&
        (attr_fake_assert != 0 ))
    {
        is_phys_pres_asserted = true;
        SB_INF("detectPhysPresence: FAKING Physical Assertion: "
               "is_WO=%d, is_PPA=%d, attr_FA=0x%X",
               is_window_open, is_phys_pres_asserted,
               attr_fake_assert);

        // Write the attribute so faking the assert only happens once
        sys->setAttr<ATTR_PHYS_PRES_FAKE_ASSERT>(0x00);
    }

    SB_INF("detectPhysPresence: LEDs=0x%.2X, led_WO=0x%X, led_PPA=0x%X, "
           "attrWO=0x%X, attr_FA=0x%X, is_WO=%d, is_PPA=%d",
           led_data, led_window_open, led_phys_pres_asserted,
           attr_open_window, attr_fake_assert,
           is_window_open, is_phys_pres_asserted);

    } while(0);

    // Regardless of any previous error, attempt to close the window here
    // if it was already opened
    if (is_window_open == true)
    {
        errlHndl_t err_close = nullptr;
        err_close = gpioPca9551SetLed(mproc,
                                      static_cast<GPIO::PCA9551_LEDS_t>
                                        (led_window_open),
                                      PCA9551_OUTPUT_HIGH_IMPEDANCE,
                                      led_data);

        if (err_close == nullptr)
        {
            // Verify that window was closed
            // LEDs/PIN represents "WINDOW_OPEN_N" so looking for a "1" in
            // that position
            if (!(led_data & led_window_open))
            {
                SB_ERR("detectPhysPresence: Closed Window LEDs = 0x%.2X "
                       "indicated that LED %d is showing window is still open",
                        led_data, led_window_open);

                /*@
                 * @errortype
                 * @reasoncode       RC_PHYS_PRES_WINDOW_NOT_CLOSED
                 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid         MOD_PHYS_PRES_DETECT
                 * @userdata1        HUID of Master Processor Target
                 * @userdata2[0:31]  LED Data from PCA9551
                 * @userdata[32:63]  LED Windoow Open LED (aka PIN)
                 * @devdesc          Attempt to close physical presence window
                 *                   did not close the window
                 * @custdesc         A problem occurred during the IPL
                 *                   of the system.
                 */
                err_close = new ERRORLOG::ErrlEntry(
                                          ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          MOD_PHYS_PRES_DETECT,
                                          RC_PHYS_PRES_WINDOW_NOT_CLOSED,
                                          get_huid(mproc),
                                          TWO_UINT32_TO_UINT64(
                                            led_data,
                                            led_window_open),
                                          ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            }
            else
            {
                SB_INF("detectPhysPresence: Closed Window LEDs = 0x%.2X",
                       led_data);
            }

        }

        if (err_close)
        {
            if (err)
            {
                // commit new erro with PLID  or original err
                err_close->plid(err->plid());
                SB_ERR("detectPhysPresence: Error in closing window. "
                       "Committing err_close eid=0x%X  "
                       "with plid of original err: 0x%X",
                       err_close->eid(), err_close->plid());

                err_close->collectTrace( SECURE_COMP_NAME );
                errlCommit(err_close, SECURE_COMP_ID);
            }
            else
            {
                SB_ERR("detectPhysPresence: Error in closing window. "
                       "err_close eid=0x%X plid=0x%X",
                       err_close->eid(), err_close->plid());
                err_close->collectTrace( SECURE_COMP_NAME );
                err = err_close;
                err_close = nullptr;
            }
        }
    } // end of 'must close window'

    if (err == nullptr)
    {
        // If no error, including in closing the window, then write attribute
        // for Physical Presence Assertion
        sys->setAttr<ATTR_PHYS_PRES_ASSERTED>(is_phys_pres_asserted);
    }

    SB_EXIT("detectPhysPresence: err rc=0x%X",
            ERRL_GETRC_SAFE(err));

    return err;
}

errlHndl_t handlePhysPresenceWindow(void)
{
    errlHndl_t err = nullptr;

    SB_ENTER("handlePhysPresenceWindow");

    // Declare local variables here as there might be an operation
    // after the do-while() loop
    Target * mproc = nullptr;
    uint8_t led_data = 0;
    ATTR_GPIO_INFO_PHYS_PRES_type gpioInfo = {};
    uint8_t led_window_open = 0;
    bool is_window_open = false;

    do
    {

    // Not supported in simics
    if (Util::isSimicsRunning())
    {
        SB_INF("handlePhysPresenceWindow: Skipping as not supported in simics");
        break;
    }

    // Get the attributes associated with Physical Presence
    TargetService& tS = targetService();
    Target* sys = nullptr;
    (void) tS.getTopLevelTarget( sys );
    assert(sys, "handlePhysPresenceWindow: system target is nullptr");

    // NOTE: Using attributes to request opening the physical presence window
    // and/or fake the assertion of physical presence is only for testing
    // purposes.  Both attributes will default to 'no' and cannot be changed
    // when security is enabled in a production driver since attribute
    // overrides are not allowed in that scenario.
    uint8_t attr_open_window =
        sys->getAttr<ATTR_PHYS_PRES_REQUEST_OPEN_WINDOW>();
    uint8_t attr_phys_pres_asserted = sys->getAttr<ATTR_PHYS_PRES_ASSERTED>();

    if (attr_open_window == 0)
    {
        SB_INF("handlePhysPresenceWindow: attr_open_window=0x%.2X: "
               "no need to open window (attr_phys_pres_asserted=0x%.2X)",
               attr_open_window, attr_phys_pres_asserted);
        break;
    }
    // This solves the issue of using attribute overrides to open the window,
    // as they don't always get cleared on re-IPLs and attr_open_window might
    // still != 0
    else if (attr_phys_pres_asserted != 0)
    {
        SB_INF("handlePhysPresenceWindow: attr_open_window=0x%.2X, but "
               "attr_phys_pres_asserted=0x%.2X, so no need to open window. "
               "Clearing open window request",
               attr_open_window, attr_phys_pres_asserted);

        // Close request to open the window
        sys->setAttr<ATTR_PHYS_PRES_REQUEST_OPEN_WINDOW>(0x00);
        break;
    }
    else
    {
        SB_INF("handlePhysPresenceWindow: attr_open_window=0x%.2X, "
               "attr_phys_pres_asserted=0x%.2X: "
               "Will Open Window To Detect Physical Presence",
               attr_open_window, attr_phys_pres_asserted);
    }

    // The PCA9551 device that controls the "window open" and
    // "physical presence asserted" logic is connected to the master processor
    err = targetService().queryMasterProcChipTargetHandle(mproc);
    if(err)
    {
        SB_ERR("handlePhysPresenceWindow: call to queryMasterProcChipTargetHandle "
               "failed.  err_plid=0x%X, err_rc=0x%X",
               ERRL_GETPLID_SAFE(err),
               ERRL_GETRC_SAFE(err));

        err->collectTrace(SECURE_COMP_NAME);
        break;
    }

    // Get "window open" LED/Pin
    led_window_open = PCA9551_LED0 << gpioInfo.windowOpenPin;


    // Open The Window
    led_data=0; // For INPUT register read-back
    err = gpioPca9551SetLed(mproc,
                            static_cast<GPIO::PCA9551_LEDS_t>
                              (led_window_open),
                            PCA9551_OUTPUT_LOW,
                            led_data);

    // Verify that the "window open" LED is set
    // LEDs/PINs represent "WINDOW_OPEN_N" and "PHYS_PRESENCE_N" so need
    // to invert their values to get their true meaning
    is_window_open = ! (led_window_open & led_data);
    if (is_window_open == true)
    {
        SB_INF("handlePhysPresenceWindow: Window is Opened: "
               "led_window_open=0x%X, led_data=0x%.2X",
                led_window_open, led_data);
    }
    else
    {
        SB_ERR("handlePhysPresenceWindow: ERROR: Window is NOT Opened: "
               "led_window_open=0x%X, led_data=0x%.2X",
                led_window_open, led_data);

        /*@
         * @errortype
         * @reasoncode       RC_PHYS_PRES_WINDOW_NOT_OPENED
         * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid         MOD_PHYS_PRES_OPEN_WINDOW
         * @userdata1        HUID of Master Processor Target
         * @userdata2[0:31]  LED Data from PCA9551
         * @userdata2[32:63] LED Windoow Open LED (aka PIN)
         * @devdesc          Attempt to open physical presence window
         *                   did not close the window
         * @custdesc         A problem occurred during the IPL
         *                   of the system.
         */
        err = new ERRORLOG::ErrlEntry(
                                  ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                  MOD_PHYS_PRES_OPEN_WINDOW,
                                  RC_PHYS_PRES_WINDOW_NOT_OPENED,
                                  get_huid(mproc),
                                   TWO_UINT32_TO_UINT64(
                                     led_data,
                                     led_window_open),
                                   ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

        err->collectTrace( SECURE_COMP_NAME );
        break;
    }

    // Close request to open the window and sync attributes
    sys->setAttr<ATTR_PHYS_PRES_REQUEST_OPEN_WINDOW>(0x00);

    if(INITSERVICE::spBaseServicesEnabled())
    {
        // Sync all attributes to FSP before powering off
        err = TARGETING::AttrRP::syncAllAttributesToFsp();
        if( err )
        {
            // Failed to sync all attributes to FSP; this is not
            // necessarily fatal.  The power off will continue,
            // but this issue will be logged.
            SB_ERR("handlePhysPresenceWindow: Error syncing "
                   "attributes to FSP, RC=0x%04X, PLID=0x%08X",
                   ERRL_GETRC_SAFE(err),
                   ERRL_GETPLID_SAFE(err));
            errlCommit(err,SECURE_COMP_ID );
        }
    }

    // Alert the users that the system will power off
#ifdef CONFIG_CONSOLE
    CONSOLE::displayf(SECURE_COMP_NAME, "Opened Physical Presence Detection Window\n");
    CONSOLE::displayf(SECURE_COMP_NAME, "System Will Power Off and Wait For Manual Power On\n");
    CONSOLE::flush();
#endif

    // Power Off the System
#ifdef CONFIG_BMC_IPMI
    // Initiate a graceful power off
    SB_INF("handlePhysPresenceWindow: Opened Physical Presence Detection Window. "
           "System Will Power Off and Wait For Manual Power On. "
           "Requesting power off");
    INITSERVICE::requestPowerOff();
#else //non-IPMI
    SB_INF("handlePhysPresenceWindow: Opened Physical Presence Detection Window. "
           "Calling INITSERVICE::doShutdown() with "
           "RC_PHYS_PRES_WINDOW_OPENED_SHUTDOWN = 0x%08X",
           RC_PHYS_PRES_WINDOW_OPENED_SHUTDOWN);
    INITSERVICE::doShutdown(RC_PHYS_PRES_WINDOW_OPENED_SHUTDOWN);
#endif


    } while (0);

    SB_EXIT("handlePhysPresenceWindow: err_rc=0x%X",
            ERRL_GETRC_SAFE(err));

    return err;
}

} // namespace SECUREBOOT
