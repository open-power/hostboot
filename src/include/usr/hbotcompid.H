/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hbotcompid.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2014                        */
/* [+] Google Inc.                                                        */
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
#ifndef HBOTCOMPID_H
#define HBOTCOMPID_H
/**
 *  @file hbotcompid.H
 *
 *  @brief  Component IDs in Host Boot environment
 *  This header file contains the definition of all component IDs in
 *  Host Boot environment. This component ID is to be used to identify
 *  the firmware such as in error logging (or somewhere else).
 *
 */

typedef unsigned short  compId_t;

/**
 * @brief Component ID declarations
 * Range of component IDs is from 01-FF, which is stored in
 * the LSB (left) of the value.
 * Note that the MSB (right) of the value are to be used as
 * error code in the component code.
 * Together, the 4-digit value is called Reason Code, which
 * is to be passed in when the component creates an error log.
 */

/** @name My component ID
 *  Example of defining my component ID
 */
//@{
const compId_t MY_COMP_ID = 0x0000;
const char MY_COMP_NAME[] = "myname";
//@}

/** @name ERRL
 *  Error Logging component.
 */
//@{
const compId_t ERRL_COMP_ID = 0x0100;
const char ERRL_COMP_NAME[] = "errl";
//@}

/** @name DEVFW
 *  Device Framework component
 */
//@{
const compId_t DEVFW_COMP_ID = 0x0200;
const char DEVFW_COMP_NAME[] = "devfw";
//@}

/** @name SCOM
 *  SCOM component
 */
//@{
const compId_t SCOM_COMP_ID = 0x0300;
const char SCOM_COMP_NAME[] = "scom";
//@}

/** @name XSCOM
 *  XSCOM component
 */
//@{
const compId_t XSCOM_COMP_ID = 0x0400;
const char XSCOM_COMP_NAME[] = "xscom";
//@}
/** @name INITSERVICE
 *  Initialization Service component
 */
//@{
const compId_t INITSVC_COMP_ID = 0x0500;
const char INITSVC_COMP_NAME[] = "initservice";
//@}

/** @name PNOR
 *  PNOR component, includes RP and DD
 */
//@{
const compId_t PNOR_COMP_ID = 0x0600;
const char PNOR_COMP_NAME[] = "pnor";
//@}

/** @name I2C
 *  I2C component
 */
//@{
const compId_t I2C_COMP_ID = 0x0700;
const char I2C_COMP_NAME[] = "i2c";
//@}

/** @name VFS
 *  Virtual File System component
 */
//@{
const compId_t VFS_COMP_ID = 0x0800;
const char VFS_COMP_NAME[] = "vfs";

/** @name HWPF
 *  HW Procedure Framework component
 */
//@{
const compId_t HWPF_COMP_ID = 0x0900;
const char HWPF_COMP_NAME[] = "hwpf";
//@}

/** @name FSI
 *  FSI component
 */
//@{
const compId_t FSI_COMP_ID = 0x0A00;
const char FSI_COMP_NAME[] = "fsi";
//@}

/** @name TARG
 *  Targeting component
 */
//@{
const compId_t TARG_COMP_ID = 0x0B00;
const char TARG_COMP_NAME[] = "targ";
//@}

/** @name HWAS
 *  Hardware Availability Service
 */
//@{
const compId_t HWAS_COMP_ID = 0x0C00;
const char HWAS_COMP_NAME[] = "hwas";
//@}

/** @name FSISCOM
 *  FSI SCOM component
 */
//@{
const compId_t FSISCOM_COMP_ID = 0x0D00;
const char FSISCOM_COMP_NAME[] = "fsiscom";
//@}

/** @name EEPROM
 *  EEPROM device driver component
 */
//@{
const compId_t EEPROM_COMP_ID = 0x0E00;
const char EEPROM_COMP_NAME[] = "eeprom";
//@}

/** @name INTR
 *  Interrupt presenter component
 */
//@{
const compId_t INTR_COMP_ID = 0x0F00;
const char INTR_COMP_NAME[] = "intr";
//@}

/** @name TOD
 *  TOD component
 */
//@{
const compId_t TOD_COMP_ID = 0x1000;
const char TOD_COMP_NAME[] = "tod";
//@}

/** @name MBOX
 *  MBOX component
 */
//@{
const compId_t MBOX_COMP_ID = 0x1100;
const char MBOX_COMP_NAME[] = "mbox";
//@}

/** @name DUMP
 *  DUMP component
 */
//@{
const compId_t DUMP_COMP_ID = 0x1200;
const char DUMP_COMP_NAME[] = "dump";
//@}


/** @name CONSOLE
 *  Console component.
 */
//@{
const compId_t CONSOLE_COMP_ID = 0x1300;
const char CONSOLE_COMP_NAME[] = "console";
//@}

/** @name MDIA
 *  MDIA memory diagnostics component
 */
//@{
const compId_t MDIA_COMP_ID = 0x1400;
const char MDIA_COMP_NAME[] = "mdia";
//@}

/** @name TRACE
 *  Trace component
 */
//@{
const compId_t TRACE_COMP_ID = 0x1500;
const char TRACE_COMP_NAME[] = "trace";
//@}

/** @name UTIL
 *  Util component
 */
//@{
const compId_t UTIL_COMP_ID = 0x1600;
const char UTIL_COMP_NAME[] = "util";
//@}

/** @name ISTEP
 *  Istep component
 */
//@{
const compId_t ISTEP_COMP_ID = 0x1700;
const char ISTEP_COMP_NAME[] = "istep";

/** @name ATTN
 *  ATTN attention service component
 */
//@{
const compId_t ATTN_COMP_ID = 0x1800;
const char ATTN_COMP_NAME[] = "attn";
//@}

/** @name SCAN
 *  SCAN component
 */
//@{
const compId_t SCAN_COMP_ID = 0x1900;
const char SCAN_COMP_NAME[] = "scan";
//@}

/** @name RUNTIME
 *  RUNTIME component
 */
//@{
const compId_t RUNTIME_COMP_ID = 0x1A00;
const char RUNTIME_COMP_NAME[] = "runtime";
//@}

/** @name KERNEL
 *  KERNEL component
 */
//@{
const compId_t KERNEL_COMP_ID = 0x1B00;
const char KERNEL_COMP_NAME[] = "kernel";
//@}

/** @name IBSCOM
 *  IBSCOM - Inband SCOM component
 */
//@{
const compId_t IBSCOM_COMP_ID = 0x1C00;
const char IBSCOM_COMP_NAME[] = "ibscom";
//@}


/** @name VPD
 *  Common VPD device driver component
 */
//@{
const compId_t VPD_COMP_ID = 0x1D00;
const char VPD_COMP_NAME[] = "vpd";
//@}

/** @name SECURE
 *  Secureboot Support component
 */
//@{
const compId_t SECURE_COMP_ID = 0x1E00;
const char SECURE_COMP_NAME[] = "secure";

/** @name IPC
 * IPC - Inter Processor Communication component
 */
//@{
const compId_t IPC_COMP_ID = 0x1F00;
const char IPC_COMP_NAME[] = "ipc";
//@}

/** @name HSVC
 * Host Services component
 * For the code running under PHYP
 */
//@{
const compId_t HSVC_COMP_ID = 0x2000;
const char HSVC_COMP_NAME[] = "hsvc";

/** @name DEVTREE
 *  DEVTREE component
 */
//@{
const compId_t DEVTREE_COMP_ID = 0x2100;
const char DEVTREE_COMP_NAME[] = "devtree";
//@}

/** @name SBE
 *  SBE utility component
 */
//@{
const compId_t SBE_COMP_ID = 0x2200;
const char SBE_COMP_NAME[] = "sbe";
//@}

/** @name GPIO
 * General Purpose IO device
 */
const compId_t GPIO_COMP_ID = 0x2300;
const char GPIO_COMP_NAME[] = "gpio";
//@}

/** @name LPC
 * Low Pin Count Bus
 */
//@{
const compId_t LPC_COMP_ID = 0x2400;
const char LPC_COMP_NAME[] = "lpc";
//@}

/** @name IPMI
 * IPMI
 */
//@{
const compId_t IPMI_COMP_ID = 0x2500;
const char IPMI_COMP_NAME[] = "ipmi";
//@}


/** @name RESERVED
 *  Reserved component ID. x3100 is the component ID
 *  of FipS ERRL component. Due to our use of
 *  of the FipS errl tool, let no Hostboot component
 *  use this component ID.
 */
//@{
const compId_t FIPS_ERRL_COMP_ID = 0x3100;
const char FIPS_ERRL_COMP_NAME[] = "hb-trace";
//@}

/** @name PRDF
 *  PRDF component
 *  @Note PRDF_COMP_ID=0xE500 matches with what
 *  defined in fips_comp_id.H for PRDF which is
 *  common between Hostboot and FSP
 */
//@{
const compId_t PRDF_COMP_ID = 0xE500;
const char PRDF_COMP_NAME[] = "prdf";
//@}

//  ----------------------------------------------------------
//  CXXTEST Unit Test, reserve compid near the end...
/** @name CXXTEST
 *  CxxTest component
 */
//@{
const compId_t CXXTEST_COMP_ID = 0xFD00;
const char CXXTEST_COMP_NAME[] = "CxxTest";
//@}

#endif
