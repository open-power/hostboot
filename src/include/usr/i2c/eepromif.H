/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/i2c/eepromif.H $                              */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
#ifndef __EEPROMIF_H
#define __EEPROMIF_H

namespace EEPROM
{

/**
 * @brief Enumerations to link EEPROM types to EEPROM's chip number behind
 *        a device
*/
typedef enum
{
  VPD_PRIMARY   = 0,
  VPD_BACKUP    = 1,
  SBE_PRIMARY   = 2,
  SBE_BACKUP    = 3,
  LAST_CHIP_TYPE
} eeprom_chip_types_t;


};  // end namespace I2C

#endif  // end __EEPROMIF_H

