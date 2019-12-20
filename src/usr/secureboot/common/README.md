# **'common'** Secureboot Services in Hostboot
This directory implements utility functions for tracing and error logging
 that other secureboot modules in the peer directories can use.
For example, the secureboot_base, secureboot_rt (runtime), secureboot_trusted,
secureboot_ext, and node_comm modules use these functions.

## Files

* __common.mk__
  * Makefile that other makefiles can call to include the generated .o files

* __containerheader.C__
  * Implements the ContainerHeader class's member functions
  * Functions are defined in
 [containerheader.H](../../../include/usr/secureboot/containerheader.H)

* __errlud_secure.C, errlud_secure.H__
  * These files define and implement custom error log user detail sections to
 capture security information on the system

* __[README.md](./README.md)__
  * This file

* __securetrace.C, securetrace.H__
  * Defines and implements standard Hostboot trace descriptors for the
 secureboot component

## sub-directories
* __plugins__
  * Standard Hostboot 'plugins' directory where the errorlog parser finds the
 information to properly parse the custom error log user detail sections
 defined in errlud_secure.H

