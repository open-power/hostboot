/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/pore_model/ibuf/pore_fi2c.h $             */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
// $Id: pore_fi2c.h,v 1.2 2013/11/27 15:50:47 thi Exp $
#ifndef __PORE_FI2C_H__
#define __PORE_FI2C_H__

/******************************************************************************
 *
 * Virtual PORe Engine
 *
 *****************************************************************************/

#include <stdint.h>

/* FIXME An I2C controller can support more than one ports and it can
 * also have more than one device listening on one of those. Just like
 * real world I2C busses connected to an I2C master with an output
 * multiplexor. For our purpose one i2c_port with one device address
 * is enough.
 */
struct pore_bus *poreb_create_fi2c(const char *name, uint8_t *mem_buf,
				   unsigned int mem_size,
				   unsigned int prv_port,
				   unsigned int address_bytes,
				   unsigned int i2c_port,
				   unsigned int deviceAddress);

#endif /* __PORE_FI2C_H__ */
