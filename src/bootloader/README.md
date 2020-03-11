# Hostboot Bootloader (HBBL)

HBBLs main tasks are to:

* Read the configuration data given to it from the Self Boot Engine (SBE)
* Load the Hostboot base image with Error-Correcting Code (ECC) into memory
* Strip ECC off the base image
* Securely verify the base image
* Measure the sha512 hash of the base image into the SPI TPM @TODO RTC 209585
* Place the base image at Hostboot's HRMOR
* Forward the configuration from SBE/HBBL into Hostboot
* Execute Hostboot entry point

# FAPI2 Platform

For P10, the Trusted Platform Module (TPM) will be communicated to via Serial
Perphiral Interface (SPI) instead of I2C. It is accessible only through the
Pervasive Interconnect Bus (PIB) and it is attached to SPI Master engine 4.

Since SBE and Hostboot share a FAPI2 hardware procedure SPI Device Driver, HBBL
has become a FAPI2 platform so that it may also take advantage of commonized
code.

To reduce the amount of common FAPI2 code that needed to be changed to enable
HBBL to compile FAPI2 into its codebase many platform specific files originating
from Hostboot were copied into the bootloader directories. Many of these files
share names with HB FAPI2 platform files. This is to seemlessly "fool" FAPI2
into compiling HBBL's files instead of HBs since HBBL isn't a submodule of HB.

src/bootloader/fapi2

This is where the HBBL specific FAPI2 implementations reside. There is a
makefile that defines various policies that HBBL doesn't support. An example
would be FAPI2_NO_FFDC which tells the compiler not to pull in all of the
advanced FFDC that FAPI2 supports. Instead, only minimal FFDC--such as return
codes--are supported by HBBL.

src/include/bootloader/

This is where all of the header files for HBBL and HBBL's FAPI2 reside. Many of
these files were duplicated from HB to strip out unnecessary features and
functions that HBBL won't support (or doesn't make sense to support).

# FAPI2 Tracing

Currently, there is no support for FAPI2 tracing in HBBL but this will be
investigated in the future. @TODO RTC 249817

# FAPI2 XSCOM Support and Functionality

Currently, FAPI2 has only been compiled into HBBL to determine size constraints.
It has not been tested and SCOM support was stubbed out for future
implementation. @TODO RTC 244855
