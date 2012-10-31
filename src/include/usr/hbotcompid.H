/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hbotcompid.H $                                */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2012              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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

/** @name HBERRL
 *  Error Logging component.
 */
//@{
const compId_t HBERRL_COMP_ID = 0x0100;
const char HBERRL_COMP_NAME[] = "hberrl";
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

/** @name SPD
 *  DIMM SPD device driver component
 */
//@{
const compId_t SPD_COMP_ID = 0x1000;
const char SPD_COMP_NAME[] = "spd";
//@}

/** @name HBMBOX
 *  MBOX component
 */
//@{
const compId_t HBMBOX_COMP_ID = 0x1100;
const char HBMBOX_COMP_NAME[] = "mbox";
//@}

/** @name MVPD
 *  MVPD device driver component
 */
//@{
const compId_t MVPD_COMP_ID = 0x1200;
const char MVPD_COMP_NAME[] = "mvpd";
//@}

/** @name PRDF
 *  PRDF component
 */
//@{
const compId_t HBPRDF_COMP_ID = 0x1300; //FIXME working with ERRL owner to resolve errl parsing issue
const char HBPRDF_COMP_NAME[] = "prdf"; //FIXME
//@}

/** @name MDIA
 *  MDIA memory diagnostics component
 */
//@{
const compId_t HBMDIA_COMP_ID = 0x1400;
const char HBMDIA_COMP_NAME[] = "mdia";
//@}

/** @name TRACE
 *  Trace component
 */
//@{
const compId_t HBTRACE_COMP_ID = 0x1500;
const char HBTRACE_COMP_NAME[] = "trace";
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

/** @name HBATTN
 *  HBATTN attention service component
 */
//@{
const compId_t HBATTN_COMP_ID = 0x1800;
const char HBATTN_COMP_NAME[] = "attn";
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

/** @name HSVC
 * Host Services component
 * For the code running under PHYP
 */
//@{
const compId_t HSVC_COMP_ID = 0x2000;
const char HSVC_COMP_NAME[] = "hsvc";
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
