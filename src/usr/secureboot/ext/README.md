# **'ext'** Secureboot Services in Hostboot
This directory implements additional (or 'extended') secureboot functionality
 that is not considered part of the 'base' secureboot support.

## Files

* __makefile__
  * Standard Hostboot makefile

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

