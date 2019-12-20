# **'base'** Secureboot Services in Hostboot
This directory implements the core of the secureboot-related functionality
 that Hostboot provides.
It is available in the Hostboot Base Image (ie the HBB partition) and all
 non-runtime Hostboot code can invoke functions provided by it.

## Key Points
* The **libsecureboot_base.so** module created here is available in Hostboot's
 base image and is used to securely bringup the rest of the Hostboot.
* It implements the functions in these header files:
  * [service.H](../../../include/usr/secureboot/service.H)
  * [settings.H](../../../include/usr/secureboot/settings.H)
* It is used to tell if security is enabled at the system or processor level
* It is used to determine the state of the secureboot jumper on the different
 processors
* It provides the interface into the SecureRom to verify code packages run
 on the system

## Files

* __header.C__
  * Implements functions related to loading and retrieving the
 Hostboot Base header from Hostboot Base (HBB) PNOR partition

* __makefile__
  * Standard Hostboot makefile

* __purge.H__
  * Defines a special purge function

* __[README.md](./README.md)__
  * This file

* __securerommgr.C, securerommgr.H__
  * Defines and implements the SecureRomManager class and its member functions
  * These functions call into the securerom and takes advantage of
 its functionality

* __service.C__
  * Retrieves the secureboot registers on the processors in the system
    * These functions are then used to add information to errorlogs and traces
  * Initliaizes the SecureRomManager class
  * Function to handle special secureboot failures
  * Retrieves some global secureboot settings taken from Hostboot's bootloader
  * NOTE: Functions in this file call into functions in settings.C when
 appropriate

* __settings.C__
  * Gets and Sets the two primary Secureboot-related SCOM registers:
    * ProcSecurity (aka Proc Security Switch)
    * ProcCbsControl
  * Also applies knowledge of key bits of these two registers, like returning
 if a processor is set in 'secureboot enabled mode' and what the state of its
 secureboot jumper is


## sub-directories
* __test__
  * Standard Hostboot test directory that implements CXX Unit Tests

