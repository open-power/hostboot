//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/hbotcompid.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
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
 *
 *  Oct 2011:  Temporarily set ERRL component ID to the
 *  same as FSP ERRL in order to make the FSP x86 errl tool
 *  format Hostboot error logs with traces.  For user-defined
 *  trace sections, that tools expects component 0x3100,
 *  section ID  0x0C, and version 1.
 *
 *  Requirement SW105241 is opened for fips8xx errl tool
 *  to start becoming Hostboot aware.  TODO When errl becomes
 *  Hostboot aware, ERRL comp id can revert to 0x0100.  Monte
 */
//@{
const compId_t ERRL_COMP_ID = 0x3100;
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
