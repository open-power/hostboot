# **'ext'** Secureboot Services in Hostboot
This directory implements additional (or 'extended') secureboot functionality
 that is not considered part of the 'base' secureboot support.

## Files

* __makefile__
  * Standard Hostboot makefile

* __key_clear.C__
  * Implements the 'key clear'-related functions, which are used to clear a customer's sensitive information, like stored encryption keys, public keys trusted for signature verification and other information throughout the system 
  * ***See Below for Key Clear Algorithm***
  * Functions are defined in
 [key_clear_if.H](../../../include/usr/secureboot/key_clear_if.H)

* __phys_presence.C__
  * Implements the 'physical presence'-related functions, which are used to
 assert that a system owner is physically present at the site of a system.
    * This is done by using GPIO devices on the system's power button to
 capture that the button was physically pressed.
  * Functions are defined in
 [phys_presence_if.H](../../../include/usr/secureboot/phys_presence_if.H)

* __[README.md](./README.md)__
  * This file

* __service_ext.C__
  * Implements some additional (or 'extended') functionality as defined in
 [service_ext.H](../../../include/usr/secureboot/service_ext.H)


---
## Key Clear Algorithm
The Hostboot perspective of the Key Clear Algorithm is to (1) take the customer's request to clear certain sensitive information and (2) confirm that a customer is physically present at the system to validate this request.

* __At Standby Power__ the customer sets the requested Key Clear Information one of these two ways:

  1. For OpenPOWER/BMC systems: Sets an PLDM BIOS attribute via the BMC


  2. For FSP-based systems: Sets the values on the appropriate ASMI menu option

  * NOTE: The Key Clear Request values are set based on the bit-mapping of ATTR_KEY_CLEAR_REQUEST

* __In istep 6__ Hostboot will attempt to detect 'Physical Presence'

  NOTE: _This is implemented in physical_presence.C's detectPhysPresence()_

  1. Check for the 'window open' and "physical presence asserted" values on the PCA9551 device connected to the master processor

    * NOTE: Only care if 'physical presence asserted' **IF** 'window is open'

    * NOTE: Technically the PCA9551 device only allow assertion if the window is open

  2. Look for the faking this physical assertion with the test-only ATTR_PHYS_PRES_FAKE_ASSERT

    * Test-only method to fake physical assertion; not available in production drivers or in secure mode
 on imprint drivers when attributes overrides are not allowed

  3. If Physical Presence was asserted, create an informational log and alert users via console trace

  4. Regardless of any previous error, attempt to close the window here if it was open

  5. If no errors, and physical presence was asserted, set ATTR_PHYS_PRES_ASSERTED


* __In istep 10__ Hostboot will process the Key Clear Request and determine if a re-IPL is necessary to open up a window in which to detect 'Physical Presence'

  NOTE: _This is implemented in physical_presence.C's handlePhysPresenceWindow()_

  1. Gather information related to Physical Presence and Key Clear Requests:

    * Get ATTR_PHYS_PRES_ASSERTED

      * Set on istep 6 above

    * Get ATTR_PHYS_PRES_REIPL

      * Used to keep track of whether or not the current IPL should have had the window open

    * Get ATTR_OPEN_WINDOW

      * Test-only method to force the window open; not available in production drivers or in secure mode
 on imprint drivers when attributes overrides are not allowed


    * Get Key Clear Request Information:

      * For OpenPOWER/BMC systems: Read PLDM BIOS attribute and map to ATTR_KEY_CLEAR_REQUEST

      * For FSP-based systems: Read ATTR_KEY_CLEAR_REQUEST which should have been set by the FSP when the ASMI menu was set at standby


  2. Determine if there is a reason to re-IPL the system to open up a window to detect 'Physical Presence' based on the following _in order_:

  * If ATTR_PHYS_PRES_ASSERTED is set, then no need to open the window

  * If ATTR_PHYS_PRES_REIPL is set, then we know this IPL should have had the window open.  Therefore, there is no need to re-IPL to open the window again

  * If we have a reason to open due to ATTR_KEY_CLEAR_REQUEST or the debug-only ATTR_OPEN_WINDOW is set, then open the window

    * NOTE: There is a special mfg-only option for imprint/development drivers that does not require a re-IPL to assert physical presence; not available in production drivers

  3. Open up the window to detect physical presence by setting the PCA9551 device connected to the master processor

  4. Create an informational log to document request for a re-IPL

  5. Clear ATTR_PHYS_PRES_REQUEST_OPEN_WINDOW if it was set

  6. Set ATTR_PHYS_PRES_REIP to document that this re-IPL is purposely for opening a physical presence window

  7. On FSP-based systems, synchronize attributes down to the FSP

  8. For OpenPOWER/BMC systems alert the users that the system will power off via a console message

  9. Power off the system

    * Ideally this should lead to a re-IPL caused by the system owner asserting physical presence on the system by pressing the power button

* __In istep 21__ Hostboot will set the appropriate fields in HDAT to represent the 'Physical Presence' and 'Key Clear Requests' status on the system

  NOTE: _This is implemented in src/usr/runtime/populate_hbruntime.C populate_hbSecurebootData()_

  NOTE: These settings are defined in the Section "6.1 IPL Parameters Internal Data" -> "6.1.1 System Parameters" of the Hypervisor Interface Data Specifications document (aka the "HDAT spec)

  1. Populate the "System Physical Presence has been asserted" bit based on ATTR_PHYS_PRES_ASSERTED

  2.  Populate "Host FW key clear requests" section based on ATTR_KEY_CLEAR_REQUEST

    * This attribute and its enums  should sync with the expected bits in the HDAT spec

    * NOTE: If Physical Presence was not asserted, then mask off all bits except for the special mfg-only bit in case of imprint drivers

  3. Clear ATTR_KEY_CLEAR_REQUEST attribute and the sensor for OpenPOWER/BMC systems

