/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/ext/phys_presence.C $                      */
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
 * @file phys_presence.C
 *
 * @brief Implements Interfaces to Detect and Open Physical Presence Windows
 *
 */

#include <targeting/common/util.H>
#include <targeting/common/target.H>
#include <targeting/targplatutil.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <devicefw/driverif.H>
#include <console/consoleif.H>
#include <util/misc.H>
#include <initservice/initserviceif.H>
#include <initservice/initsvcreasoncodes.H>
#include <initservice/istepdispatcherif.H>
#include <secureboot/secure_reasoncodes.H>
#include <secureboot/phys_presence_if.H>
#include <secureboot/key_clear_if.H>
#include "../common/securetrace.H"
#include <gpio/gpioif.H>
#include <pnor/pnorif.H>

using namespace TARGETING;
using namespace GPIO;
using namespace ERRORLOG;

namespace SECUREBOOT
{

errlHndl_t detectPhysPresence(void)
{
    errlHndl_t err = nullptr;

    SB_ENTER("detectPhysPresence");

    // Not supported in simics
    if (Util::isSimicsRunning())
    {
        SB_INF("detectPhysPresence: Skipping as not supported in simics");

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
    bool doesKeyClearRequestPhysPres = false;

    // Get the attributes associated with Physical Presence
    Target* sys = UTIL::assertGetToplevelTarget();

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


    // Get info associated with Key Clear Requests to see if physical presence
    // detection is REALLY necessary
    KEY_CLEAR_REQUEST keyClearRequests = KEY_CLEAR_REQUEST_NONE;
#ifdef CONFIG_KEY_CLEAR
    getKeyClearRequest(doesKeyClearRequestPhysPres, keyClearRequests);
    SB_INF("detectPhysPresence: call to getKeyClearRequest "
           "returned: doesKeyClearRequestPhysPres=%d, "
           "keyClearRequests=0x%.4X",
           doesKeyClearRequestPhysPres,keyClearRequests);
#endif

    // The PCA9551 device that controls the "window open" and
    // "physical presence asserted" logic is connected to the master processor
    err = targetService().queryMasterProcChipTargetHandle(mproc);
    if(err)
    {
        SB_ERR("detectPhysPresence: call to queryMasterProcChipTargetHandle "
               "failed. "
               TRACE_ERR_FMT,
               TRACE_ERR_ARGS(err));

        break;
    }

    // Get the attribute with the needed GPIO information
    if (mproc->tryGetAttr<ATTR_GPIO_INFO_PHYS_PRES>(gpioInfo))
    {
        SB_INF("detectPhysPresence: gpioInfo: mproc=0x%0.8X "
               "e%d/p%d/devAddr=0x%X, windowOpenPin=%d, physPresPin=%d",
               get_huid(mproc),
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
         * @severity         ERRL_SEV_UNRECOVERABLE
         * @moduleid         MOD_DETECT_PHYS_PRES
         * @userdata1        HUID of Master Processor Target
         * @userdata2        ATTR_GPIO_INFO_PHYS_PRES hash value
         * @devdesc          Master processor target did not have
         *                   ATTR_GPIO_INFO_PHYS_PRES associated with it
         * @custdesc         A problem occurred during the IPL
         *                   of the system.
         */
        err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                            MOD_DETECT_PHYS_PRES,
                            RC_PHYS_PRES_ATTR_NOT_FOUND,
                            get_huid(mproc),
                            ATTR_GPIO_INFO_PHYS_PRES,
                            ErrlEntry::ADD_SW_CALLOUT);

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
        sys->setAttr<ATTR_PHYS_PRES_FAKE_ASSERT>(0x0);
    }

    SB_INF("detectPhysPresence: LEDs=0x%.2X, led_WO=0x%X, led_PPA=0x%X, "
           "attrWO=0x%X, attr_FA=0x%X, is_WO=%d, is_PPA=%d",
           led_data, led_window_open, led_phys_pres_asserted,
           attr_open_window, attr_fake_assert,
           is_window_open, is_phys_pres_asserted);

    // If Physical Presence was asserted, create an informational log and
    // alert users via console trace
    if (is_phys_pres_asserted == true)
    {
        /*@
         * @errortype
         * @moduleid          MOD_DETECT_PHYS_PRES
         * @reasoncode        RC_PHYS_PRES_ASSERTED
         * @userdata1[0:31]   Value of Attribute Requesting an Open Window
         * @userdata1[32:63]  Value of Attribute to Fake Physical Presence
         *                    Assertion
         * @userdata2[0:31]   Logic of 'is_window_open'
         * @userdata2[32:63]  Logic of 'is_phys_pres_asserted'
         * @devdesc      Physical Presence was Asserted
         * @custdesc     Physical Presence was Asserted
         */
        errlHndl_t err_info = new ErrlEntry(
                                  ERRL_SEV_INFORMATIONAL,
                                  MOD_DETECT_PHYS_PRES,
                                  RC_PHYS_PRES_ASSERTED,
                                  TWO_UINT32_TO_UINT64(
                                      attr_open_window,
                                      attr_fake_assert),
                                  TWO_UINT32_TO_UINT64(
                                      is_window_open,
                                      is_phys_pres_asserted));

        err_info->collectTrace( SECURE_COMP_NAME );

        errlCommit( err_info, SECURE_COMP_ID );

#ifdef CONFIG_CONSOLE
        CONSOLE::displayf(CONSOLE::DEFAULT, SECURE_COMP_NAME, "Physical Presence Was Asserted In Detection Window\n");
        CONSOLE::flush();
#endif
    }

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
                 * @severity         ERRL_SEV_UNRECOVERABLE
                 * @moduleid         MOD_DETECT_PHYS_PRES
                 * @userdata1        HUID of Master Processor Target
                 * @userdata2[0:31]  LED Data from PCA9551
                 * @userdata[32:63]  LED Windoow Open LED (aka PIN)
                 * @devdesc          Attempt to close physical presence window
                 *                   did not close the window
                 * @custdesc         A problem occurred during the IPL
                 *                   of the system.
                 */
                err_close = new ErrlEntry(
                                ERRL_SEV_UNRECOVERABLE,
                                MOD_DETECT_PHYS_PRES,
                                RC_PHYS_PRES_WINDOW_NOT_CLOSED,
                                get_huid(mproc),
                                TWO_UINT32_TO_UINT64(
                                  led_data,
                                  led_window_open),
                                ErrlEntry::ADD_SW_CALLOUT);
            }
            else
            {
                SB_INF("detectPhysPresence: Closed Window LEDs = 0x%.2X",
                       led_data);
            }

        }

        if (err_close)
        {
            if (doesKeyClearRequestPhysPres == false)
            {
                err_close->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                SB_ERR("detectPhysPresence: Error in closing window. "
                       "Setting ERR to informational because we don't want a "
                       "physical presence detection err to halt the IPL if "
                       "there was no key clear request: "
                       TRACE_ERR_FMT,
                       TRACE_ERR_ARGS(err_close));
            }

            if (err)
            {
                // commit new error with PLID of original err
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
                       TRACE_ERR_FMT,
                       TRACE_ERR_ARGS(err));
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

    // If there is an error, but there was not a key clear request requiring
    // the assertion of physical presence, make the error informational and
    // commit it here so as not to halt the IPL
    if ((err != nullptr) &&
        (doesKeyClearRequestPhysPres == false))
    {
        err->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
        SB_ERR("detectPhysPresence: Setting ERR to informational and "
               "committing here. Don't want a physical presence detection "
               "err to halt the IPL if there was no key clear request: "
               TRACE_ERR_FMT,
               TRACE_ERR_ARGS(err));
         err->collectTrace( SECURE_COMP_NAME );
         errlCommit(err, SECURE_COMP_ID);
         err = nullptr;
    }
    else if (err != nullptr)
    {
        err->collectTrace( SECURE_COMP_NAME );
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
    bool doesKeyClearRequestPhysPres = false;

    // This code uses the value in ATTR_KEY_CLEAR_REQUEST and
    // if we continue on with the IPL we crossover that value
    // to ATTR_KEY_CLEAR_REQUEST_HB, while clearing ATTR_KEY_CLEAR_REQUEST.
    // ATTR_KEY_CLEAR_REQUEST is shared with the FSP and this allows
    // Hostboot to clear the request and have it synced down in istep 16
    KEY_CLEAR_REQUEST keyClearRequests = KEY_CLEAR_REQUEST_NONE;
    uint16_t keyClearRequests_HB = 0;
    bool doAttrCrossOver = false;

    // Used to get the attributes associated with Physical Presence
    Target* sys = UTIL::assertGetToplevelTarget();

    do
    {

    // Not supported in simics
    if (Util::isSimicsRunning())
    {
        SB_INF("handlePhysPresenceWindow: Skipping as not supported in simics");
        break;
    }

    // NOTE: Using attributes to request opening the physical presence window
    // and/or fake the assertion of physical presence is only for testing
    // purposes.  Both attributes will default to 'no' and cannot be changed
    // when security is enabled in a production driver since attribute
    // overrides are not allowed in that scenario.
    uint8_t attr_open_window =
        sys->getAttr<ATTR_PHYS_PRES_REQUEST_OPEN_WINDOW>();

    uint8_t attr_phys_pres_asserted = sys->getAttr<ATTR_PHYS_PRES_ASSERTED>();

    uint8_t attr_phys_pres_reipl = sys->getAttr<ATTR_PHYS_PRES_REIPL>();

    // Get info associated with Key Clear Requests - another possible reason
    // to open the Physical Presence Window
#ifdef CONFIG_KEY_CLEAR
    getKeyClearRequest(doesKeyClearRequestPhysPres, keyClearRequests);
    SB_INF("handlePhysPresenceWindow: call to getKeyClearRequest "
           "returned: doesKeyClearRequestPhysPres=%d, "
           "keyClearRequests=0x%X",
           doesKeyClearRequestPhysPres,keyClearRequests);
#endif

    // Trace decision-related variables
    SB_INF("handlePhysPresenceWindow: attr_open_window=0x%.2X, "
           "doesKeyClearRequestPhysPres=%d, attr_phys_pres_asserted=0x%.2X, "
           "attr_phys_pres_reipl=0x%.2X",
           attr_open_window, doesKeyClearRequestPhysPres,
           attr_phys_pres_asserted, attr_phys_pres_reipl);

    // If physical presence is already asserted, then there's no need to open
    // the window
    if (attr_phys_pres_asserted != 0)
    {
        SB_INF("handlePhysPresenceWindow: attr_phys_pres_asserted=0x%.2X. "
               "Since Physical Presence is already asserted, ignoring "
               "attr_open_window=0x%.2X and doesKeyClearRequestPhysPres=%d ",
               attr_phys_pres_asserted, attr_open_window,
               doesKeyClearRequestPhysPres);

        if (attr_open_window != 0)
        {
            // Close request to open the window
            SB_INF("handlePhysPresenceWindow: Since attr_open_window=0x%.2X, "
                   "but Physical Presence is already asserted, "
                   "clearing open window request",
                   attr_open_window);
            attr_open_window = 0x00;
            sys->setAttr<ATTR_PHYS_PRES_REQUEST_OPEN_WINDOW>(attr_open_window);
        }

        doAttrCrossOver = true;

        break;
    }

    // If this re-IPL was due to a window open request, but physical presence
    // wasn't asserted, then we don't need to re-IPL again
    // -- This avoids infinite loops
    else if (attr_phys_pres_reipl != 0)
    {
        SB_INF("handlePhysPresenceWindow: attr_phys_pres_reipl=0x%.2X. "
               "Since this IPL opened the window but Physical Presence "
               "was NOT asserted (0x%.2X) ignoring "
               "attr_open_window=0x%.2X and doesKeyClearRequestPhysPres=%d "
               "and clearing attr_phys_pres_reipl",
               attr_phys_pres_reipl, attr_phys_pres_asserted, attr_open_window,
               doesKeyClearRequestPhysPres);

        attr_phys_pres_reipl = 0x00;
        sys->setAttr<ATTR_PHYS_PRES_REIPL>(attr_phys_pres_reipl);

        doAttrCrossOver = true;

        break;
    }

    // If there's no reason to open a window, then don't open it
    else if ((attr_open_window == 0) &&
            (doesKeyClearRequestPhysPres == false))
    {
        SB_INF("handlePhysPresenceWindow: attr_open_window=0x%.2X: "
               "and doesKeyClearRequestPhysPres=%d so no need to open window "
               "(attr_phys_pres_asserted=0x%.2X)",
               attr_open_window, doesKeyClearRequestPhysPres,
               attr_phys_pres_asserted);

        doAttrCrossOver = true;

        // Document special case if it's -ONLY- KEY_CLEAR_REQUEST_MFG
        // or KEY_CLEAR_REQUEST_MFG_ALL
        // NOTE: The check that this is an imprint driver was made in
        // getKeyClearRequest()
        if ((keyClearRequests == KEY_CLEAR_REQUEST_MFG) ||
            (keyClearRequests == KEY_CLEAR_REQUEST_MFG_ALL))
        {
            SB_INF("handlePhysPresenceWindow: Create an INFORMATIONAL Log to "
                   "document special case(s) of KEY_CLEAR_REQUEST_MFG(_ALL) "
                   "(0x%.04X)",
                   keyClearRequests);

            /*@
             * @errortype
             * @moduleid          MOD_HANDLE_PHYS_PRES_WINDOW
             * @reasoncode        RC_KEY_CLEAR_REQUEST_MFG
             * @userdata1[0:31]   Value of Attribute Requesting an Open Window
             * @userdata1[32:63]  Value of Key Clear Requests
             * @userdata2[0:31]   Value of Attribute Physical Presence Asserted
             * @userdata2[32:63]  Value of Attribute Physical Presence re-IPL
             * @devdesc           Found special case of KEY_CLEAR_REQUEST_MFG;
             *                    No Re-IPL is necessary
             * @custdesc          Detected Special Key Clear Request
             */
            errlHndl_t err_info = new ErrlEntry(
                                  ERRL_SEV_INFORMATIONAL,
                                  MOD_HANDLE_PHYS_PRES_WINDOW,
                                  RC_KEY_CLEAR_REQUEST_MFG,
                                  TWO_UINT32_TO_UINT64(
                                      attr_open_window,
                                      keyClearRequests),
                                  TWO_UINT32_TO_UINT64(
                                      attr_phys_pres_asserted,
                                      attr_phys_pres_reipl));
            err_info->collectTrace( SECURE_COMP_NAME );

            errlCommit( err_info, SECURE_COMP_ID );

            // Also display a message to the console
            #ifdef CONFIG_CONSOLE
            CONSOLE::displayf(CONSOLE::DEFAULT, SECURE_COMP_NAME, "Detected KEY_CLEAR_REQUEST_MFG(_ALL); No Physical Presence Detection Necessary\n");
            #endif
        }

        break;
    }

    // Open window by continuing on in this function
    else
    {
        SB_INF("handlePhysPresenceWindow: attr_open_window=0x%.2X, "
               "doesKeyClearRequestPhysPres=%d, attr_phys_pres_asserted=0x%.2X:"
               " Will Open Window To Detect Physical Presence",
               attr_open_window, doesKeyClearRequestPhysPres, attr_phys_pres_asserted);
    }

    // The PCA9551 device that controls the "window open" and
    // "physical presence asserted" logic is connected to the master processor
    err = targetService().queryMasterProcChipTargetHandle(mproc);
    if(err)
    {
        SB_ERR("handlePhysPresenceWindow: call to queryMasterProcChipTargetHandle "
               "failed.  "
               TRACE_ERR_FMT,
               TRACE_ERR_ARGS(err));
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
    if(err)
    {
        SB_ERR("handlePhysPresenceWindow: call to gpioPca9551SetLed failed. "
               TRACE_ERR_FMT,
               TRACE_ERR_ARGS(err));
        break;
    }

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
         * @severity         ERRL_SEV_UNRECOVERABLE
         * @moduleid         MOD_HANDLE_PHYS_PRES_WINDOW
         * @userdata1        HUID of Master Processor Target
         * @userdata2[0:31]  LED Data from PCA9551
         * @userdata2[32:63] LED Windoow Open LED (aka PIN)
         * @devdesc          Attempt to open physical presence window
         *                   did not close the window
         * @custdesc         A problem occurred during the IPL
         *                   of the system.
         */
        err = new ErrlEntry(
                      ERRL_SEV_UNRECOVERABLE,
                      MOD_HANDLE_PHYS_PRES_WINDOW,
                      RC_PHYS_PRES_WINDOW_NOT_OPENED,
                      get_huid(mproc),
                      TWO_UINT32_TO_UINT64(
                          led_data,
                          led_window_open),
                      ErrlEntry::ADD_SW_CALLOUT);

        break;
    }

    // Create an informational log to document request for a re-IPL
    /*@
     * @errortype
     * @moduleid          MOD_HANDLE_PHYS_PRES_WINDOW
     * @reasoncode        RC_PHYS_PRES_REIPL
     * @userdata1[0:31]   Value of Attribute Requesting an Open Window
     * @userdata1[32:63]  Value of Key Clear Requests
     * @userdata2[0:31]   Value of Attribute Physical Presence Asserted
     * @userdata2[32:63]  Value of Attribute Physical Presence re-IPL
     * @devdesc      Re-IPLing to open a Physical Presence Window
     * @custdesc     Re-IPLing to open a Physical Presence Window
     */
    errlHndl_t err_info = new ErrlEntry(
                                  ERRL_SEV_INFORMATIONAL,
                                  MOD_HANDLE_PHYS_PRES_WINDOW,
                                  RC_PHYS_PRES_REIPL,
                                  TWO_UINT32_TO_UINT64(
                                      attr_open_window,
                                      keyClearRequests),
                                  TWO_UINT32_TO_UINT64(
                                      attr_phys_pres_asserted,
                                      attr_phys_pres_reipl));

    err_info->collectTrace( SECURE_COMP_NAME );

    errlCommit( err_info, SECURE_COMP_ID );

    // Close request to open the window and sync attributes
    sys->setAttr<ATTR_PHYS_PRES_REQUEST_OPEN_WINDOW>(0x00);
    attr_open_window = sys->getAttr<ATTR_PHYS_PRES_REQUEST_OPEN_WINDOW>();

    // Set the attribute telling us that this re-IPL is purposely for
    // opening a physical presence window
    sys->setAttr<ATTR_PHYS_PRES_REIPL>(0x01);
    attr_phys_pres_reipl = sys->getAttr<ATTR_PHYS_PRES_REIPL>();

    SB_INF("handlePhysPresenceWindow: Closing attr_open_window=0x0 (0x%.2X), "
           "and setting ATTR_PHYS_PRES_REIPL to 0x01 (0x%.2X)",
           attr_open_window, attr_phys_pres_reipl);

    // Sync all attributes to FSP or BMC before powering off
    err = TARGETING::AttrRP::syncAllAttributesToSP();
    if( err )
    {
        // Failed to sync all attributes to FSP/BMC; this is not
        // necessarily fatal.  The power off will continue,
        // but this issue will be logged.
        SB_ERR("handlePhysPresenceWindow: Error syncing "
               "attributes to FSP/BMC. "
               TRACE_ERR_FMT,
               TRACE_ERR_ARGS(err));
        err->collectTrace( SECURE_COMP_NAME );
        errlCommit(err,SECURE_COMP_ID );
    }

    // Alert the users that the system will power off
#ifdef CONFIG_CONSOLE
    CONSOLE::displayf(CONSOLE::DEFAULT, SECURE_COMP_NAME, "Opened Physical Presence Detection Window\n");
    CONSOLE::displayf(CONSOLE::DEFAULT, SECURE_COMP_NAME, "System Will Power Off and Wait For Manual Power On\n");
    CONSOLE::flush();
#endif

    // Power Off the System
#ifdef CONFIG_BMC_IPMI
    // Initiate a graceful power off
    SB_INF("handlePhysPresenceWindow: Opened Physical Presence Detection Window. "
           "System Will Power Off and Wait For Manual Power On");
    INITSERVICE::requestSoftPowerOff();
#else //non-IPMI
    SB_INF("handlePhysPresenceWindow: Opened Physical Presence Detection Window. "
           "Calling INITSERVICE::doShutdown() with "
           "RC_PHYS_PRES_WINDOW_OPENED_SHUTDOWN = 0x%08X",
           RC_PHYS_PRES_WINDOW_OPENED_SHUTDOWN);
    INITSERVICE::doShutdown(RC_PHYS_PRES_WINDOW_OPENED_SHUTDOWN);
#endif


    } while (0);

    // If there is an error, but there was not a key clear request requiring
    // the assertion of physical presence, make the error informational and
    // commit it here so as not to halt the IPL
    if ((err != nullptr) &&
        (doesKeyClearRequestPhysPres == false))
    {
        err->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
        SB_ERR("handlePhysPresenceWindow: Setting ERR to informational and "
               "committing here. Don't want a physical presence detection "
               "err to halt the IPL if there was no key clear request: "
               TRACE_ERR_FMT,
               TRACE_ERR_ARGS(err));
         err->collectTrace( SECURE_COMP_NAME );
         errlCommit(err, SECURE_COMP_ID);
         err = nullptr;
    }
    else if (err != nullptr)
    {
        err->collectTrace( SECURE_COMP_NAME );
    }

    if (doAttrCrossOver == true)
    {
        // Convert ATTR_KEY_CLEAR_REQUEST to ATTR_KEY_CLEAR_REQUEST_HB
        // and clear ATTR_KEY_CLEAR_REQUEST so this will get synced
        // down to FSP in istep 16
        keyClearRequests_HB = keyClearRequests;
        keyClearRequests = KEY_CLEAR_REQUEST_NONE;
        sys->setAttr<ATTR_KEY_CLEAR_REQUEST>(keyClearRequests);
        sys->setAttr<ATTR_KEY_CLEAR_REQUEST_HB>(keyClearRequests_HB);
    }

    SB_EXIT("handlePhysPresenceWindow: err_rc=0x%X",
            ERRL_GETRC_SAFE(err));

    return err;
}

} // namespace SECUREBOOT
