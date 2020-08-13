# **'trusted'** Secureboot Services in Hostboot
This directory implements the 'trusted' boot functionality that Hostboot
 provides.
It primarily does this by measuring and storing firmware images and system
 data into the system's TPMs (Trusted Platform Modules).

## Key Points
* This code measures specific information on the system, including different
 firmware images that are loaded onto the system by hostboot
* These mesasurements, along with other system data, are stored in the TPMs
 on the system
* This code also determines which TPMs exist on the system, if they are
 functional, and initializes them
* To directly talk to the TPMs this code uses the TPM Device Driver, which
 is built on top of the SPI Device Driver:
  * [src/usr/spi/tmpdd.C](../../spi/tpmdd.C)
  * [src/usr/spi/tpmdd.H](../../spi/tpmdd.H)

* The **libsecureboot_trusted.so** module created here is available in
 Hostboot's extended image
* However, the code in the 'base' sub-directory is built into
 libsecureboot_base.so and is available in Hostboot's base image
* This module implements the interfaces defined in
 [trustedbootif.H](../../../include/usr/secureboot/trustedbootif.H)

## Files

* __makefile__
  * Standard Hostboot makefile

* __[README.md](./README.md)__
  * This file

* __tpmLogMgr.C, tpmLogMgr.H__
  * Defines and implements functions around the TPM Event Log, including
 adding new events, extending the log to the TPM,  and moving the log to
 different memory locations

* __trustedTypes.C, trustedTypes.H__
  * Defines different structures and methods for sending and receiving data
 to and from the TPM

* __trustedboot.C, trustedboot.H__
  * Defines and implements the majority of the functions that interact with the
 TPMs
  * Implements the majority of the functions that verify and initialize the TPMs

* __trustedbootCmds.C, trustedbootCmds.H__
  * Defines and implements commands sent to the TPM and then processes (aka
 marshall and unmarshall) the data appropriately

* __trustedbootUtils.C, trustedbootUtils.H__
  * Defines and implements a few utility functions like a wrapper to the TPM
 Device Driver and creating trustedboot error logs.


## sub-directories
* __base__
  * These files create a message queue to reserve operations that can be
 implemented once the full Hostboot extended code, including
 libsecureboot_trusted.so, is available to process them
  * These files also take the basic operations that the Hostboot base code
 needs and sends them to the message queue
  * __trustedboot_base.C__
    * Implements early trustedboot/TPM calls be calling into a message
 queue so that they can be processed later

  * __trustedbootMsg.C, trustedbootMsg.H__
    * Defines and implements the message queue so that commands can be
 processed later when libsecureboot_trusted.so is available

* __test__
  * Standard Hostboot test directory that implements CXX Unit Tests

