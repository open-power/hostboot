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
 *  Error Logging component
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

#endif
