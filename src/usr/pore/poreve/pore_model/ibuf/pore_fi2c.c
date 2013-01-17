/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/pore_model/ibuf/pore_fi2c.c $             */
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
/******************************************************************************
 *
 * Virtual PORe Engine
 *
 *****************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "pore_model.h"
#include "pore_ibuf.h"
#include "pore_regs.h"

/// \enum FastI2cState
///
/// The state of the controller.  Sequences of register operations are
/// only allowed in a prescribed sequence, depending on the state of the
/// controller. The ERROR state represents a bug in the model and is
/// non-recoverable.

typedef enum  {
	ERROR = 0,
	IDLE = 1,
	ADDRESS_WRITE_ONGOING = 2,
	DATA_READ_ONGOING = 3,
	DATA_AVAILABLE = 4,
	WRITE_DATA_EXPECTED = 5,
	DATA_WRITE_ONGOING = 6
} FastI2cState;

#define COMMAND_COMPLETION   3	/* command completion timeout */

struct fi2c {
	pore_bus_t bus;

	uint8_t *mem_buf;	/* memory used to emulate data access */
	unsigned int mem_size;	/* maximum size of attached memory */
	unsigned int mem_start;	/* memory start offset in address space */
	unsigned int address;	/* read/write offset */
	uint64_t i2c_en_param_reg; /* figure out if transfer was for us */

	unsigned int prv_port;	/* pervasive port number */
	size_t addressBytes;	/* address bytes used, must match request */

	unsigned int i2c_port;	/* i2c port; a master can support multiple */
	unsigned int deviceAddress; /* One FI2C can serve multiple
				       i2c_port/deviceAddress
				       combinations aka memory
				       areas. Support only one for
				       now. */
	unsigned int command_completion;

	FastI2cState state;
	fasti2c_control_reg control;
	fasti2c_status_reg status;
	uint64_t fifo;		/* Data is left-justified in this reg. */
};

/* Memory Access */

static int mem_addressWrite(struct fi2c *p, size_t i_bytes, uint32_t i_address)
{
	if (i_bytes != p->addressBytes) {
		BUG();
		p->state = ERROR;
		return PORE_ERR_I2CMEMORY_ILLEGAL_ADDR;
	}
	p->address = i_address;
	return i_bytes;
}

/**
 * We keep everything outside the PORe model big endian and turn it
 * into host-byteorder when reading it in or vice versa when writing
 * it out.
 */
static int mem_dataRead(struct fi2c *p, size_t i_bytes, uint64_t *o_data)
{
	unsigned int mem_offs = p->address - p->mem_start;

	if ((p->address < p->mem_start) ||
	    (mem_offs + i_bytes > p->mem_size)) {
		BUG();
		p->state = ERROR;
		return PORE_ERR_I2CMEMORY_ILLEGAL_ADDR;
	}

	switch (i_bytes) {
	case 4:
		*o_data = pore_be32toh(*((uint32_t *)&p->mem_buf[mem_offs]));
		break;
	case 8:
		*o_data = pore_be64toh(*((uint64_t *)&p->mem_buf[mem_offs]));
		break;
	default:
		return PORE_ERR_INVALID_PARAM;
	}

	p->address += i_bytes;
	return i_bytes;
}


static int mem_dataWrite(struct fi2c *p, size_t i_bytes, uint64_t i_data)
{
	unsigned int mem_offs = p->address - p->mem_start;

	if ((p->address < p->mem_start) ||
	    (mem_offs + i_bytes > p->mem_size)) {
		BUG();
		p->state = ERROR;
		return PORE_ERR_I2CMEMORY_ILLEGAL_ADDR;
	}

	switch (i_bytes) {
	case 4:
		*((uint32_t *)&p->mem_buf[mem_offs]) = pore_htobe32(i_data);
		break;
	case 8:
		*((uint64_t *)&p->mem_buf[mem_offs]) = pore_htobe64(i_data);
		break;
	default:
		return PORE_ERR_INVALID_PARAM;
	}

	p->address += i_bytes;
	return i_bytes;
}

static uint32_t getI2cAddress(fasti2c_control_reg *control)
{
	size_t addressBytes = control->address_range;
	return (control->val & 0xffffffff) >> ((4 - addressBytes) * 8);
}

// The address is left-justified in the low-order 32 bits of the control
// register.

static int addressWrite(struct fi2c *p)
{
	int me;
	unsigned i2c_port = p->control.port_number;
	unsigned deviceAddress = p->control.device_address;
	size_t addressBytes = p->control.address_range;

	if ((p->i2c_port != i2c_port) || (p->deviceAddress != deviceAddress)) {
		BUG();
		return PORE_ERR_NOT_MAPPED_ON_FASTI2C;
	}

	me = mem_addressWrite(p, addressBytes, getI2cAddress(&p->control));
	p->state = ADDRESS_WRITE_ONGOING;
	return me;
}


static int dataRead(struct fi2c *p)
{
	int me;
	unsigned i2c_port = p->control.port_number;
	unsigned deviceAddress = p->control.device_address;
	size_t dataBytes = p->control.data_length;
	uint64_t data = 0;

	if ((p->i2c_port != i2c_port) || (p->deviceAddress != deviceAddress)) {
		BUG();
		return PORE_ERR_NOT_MAPPED_ON_FASTI2C;
	}

	me = mem_dataRead(p, dataBytes, &data);
	p->fifo = data << (64 - (dataBytes * 8));
	p->state = DATA_READ_ONGOING;
	return me;
}

// For addresses < 4 bytes, the first slug of data occupies the
// remainder of the low-order word of the control register.  Any
// remaining bytes come in on the next transaction targeting the data
// register.  This code assumes 8-byte only data writes.

static int initialDataWrite(struct fi2c *p)
{
	unsigned addressBytes = p->control.address_range;

	if (addressBytes < 4) {
		p->fifo = BE64_GET_FIELD(p->control.val & 0xffffffff,
					 32 + (addressBytes * 8), 63)
			<< (64 - (4 - addressBytes) * 8);
	}
	p->state = WRITE_DATA_EXPECTED;
	return PORE_SUCCESS;
}

// Assume 8-byte only write transactions

static int finalDataWrite(struct fi2c *p, const uint8_t *buf, unsigned int len)
{
	int me;
	unsigned i2c_port = p->control.port_number;
	unsigned deviceAddress = p->control.device_address;
	size_t addressBytes = p->control.address_range;
	uint64_t i_data, i_merge;

	if ((p->i2c_port != i2c_port) || (p->deviceAddress != deviceAddress)) {
		BUG();
		return PORE_ERR_NOT_MAPPED_ON_FASTI2C;
	}
	i_data  = *(uint64_t *)buf;
	i_merge = BE64_GET_FIELD(i_data, 0, (8 - addressBytes) * 8 - 1);
	p->fifo = BE64_SET_FIELD(p->fifo,	   /* target */
				 addressBytes * 8, /* begin */
				 63,		   /* end */
				 i_merge);

	me = mem_dataWrite(p, len, p->fifo);
	p->state = DATA_WRITE_ONGOING;
	return me;
}

//
// o  The RESET register is not modeled here
//
// o  Our models ignore the I2C Speed
//
// o  Transactions complete in 0 time and polling always succeeds on the first
//    read of the status register.  This is done to simplify the PORE
//    engine model.
//
// o  Only the following types of control register actions are modeled:
//
//    *  Set address : with_start; with_address; !with_continue; with_stop;
//                     RNW == 1; Data_length == [4, 8];
//                     Address length != 0; Address provided
//                     Setting the address also fetches data and increments
//                     the address stored in memory
//
//    *  Data Read   : with_start; with_address; !with_continue; with_stop;
//                     RNW == 1; Data_length == [4, 8];
//                      Address length == 0; No address provided
//                     This operation fetches data and increments the address
//                     stored in memory.
//
//    *  Data write  : with_start; with_address; !with_continue; with_stop;
//                     RNW == 0; Data_length == 8
//                     Addrress length != 0; Address provided
//
// o  The memory models hold the last address written and implement the
//    address auto-increment after every read or write
//
// o  Redundant reads of the STATUS register are allowed
//
// o  PORE only allows 4/8 byte reads and 8 byte writes.

static int fi2c_read(struct pore_bus *b, uint64_t addr,
		     uint8_t *buf, unsigned int len,
		     int *err_code)
{
	int rc = PORE_FAILURE;
	PibAddress pib_addr;
	struct fi2c *p = (struct fi2c *)poreb_get_priv(b);

	iprintf(b->pore, "  %-12s: %s(%p, 0x%llx, %p, %x)\n",
		b->name, __func__, b, (long long)addr, buf, len);

	/* SBE has: prv_port 0xa SEEPROM 2 byte addresses
	 *           "       0x1 OTP     2 byte addresses
	 *           "       0xb PNOR    4 byte addresses
	 *
	 * This is adjusted in the i2c_en_param_reg in the fields
	 * i2c_engine_identifier == prv_port and
	 * i2c_engine_address_range == addressBytes.
	 *
	 * All FI2CMs are in the pervasive chiplet which has 0x0.
	 */
	pib_addr.val = addr;
	if ((pib_addr.chiplet_id != 0x0) || (pib_addr.prv_port != p->prv_port))
		return PORE_ERR_NOACK; /* not for this fi2cm */

	switch (pib_addr.local_addr) {

	case FASTI2C_CONTROL_OFFSET:
		p->state = ERROR;
		rc = PORE_ERR_WRITE_ONLY_REGISTER;
		break;

	case FASTI2C_STATUS_OFFSET:
		if (len != 8) {
			rc = PORE_ERR_INVALID_PARAM;
			break;
		}

		switch (p->state) {

		case ADDRESS_WRITE_ONGOING:
		case DATA_WRITE_ONGOING:
			p->command_completion++; /* simulate access duration */
			if (p->command_completion < COMMAND_COMPLETION) {
				p->status.val = 0;
				*(uint64_t *)buf = p->status.val;
				rc = len;
				break;
			}

			p->command_completion = 0;
			p->status.val = 0;
			p->status.i2c_command_complete = 1;
			*(uint64_t *)buf = p->status.val;
			p->state = IDLE;
			rc = len;
			break;

		case DATA_READ_ONGOING:

			p->command_completion++; /* simulate access duration */
			if (p->command_completion < COMMAND_COMPLETION) {
				p->status.val = 0;
				*(uint64_t *)buf = p->status.val;
				rc = len;
				break;
			}

			p->command_completion = 0;
			p->status.val = 0;
			p->status.i2c_command_complete = 1;
			p->status.i2c_fifo_entry_count =
				p->control.data_length;
			*(uint64_t *)buf = p->status.val;
			p->state = DATA_AVAILABLE;
			rc = len;
			break;

		case IDLE:
			*(uint64_t *)buf = p->status.val;
			rc = len;
			break;

		default:
			BUG();
			p->state = ERROR;
			rc = PORE_ERR_FASTI2C_SEQUENCE_ERROR;
			break;
		}
		break;

	case FASTI2C_DATA_OFFSET:
		switch (p->state) {

		case DATA_AVAILABLE:
			rc = len;
			switch (len) {
			case 4: *(uint32_t *)buf = (uint32_t)p->fifo; break;
			case 8: *(uint64_t *)buf = (uint64_t)p->fifo; break;
			default:
				rc = PORE_ERR_INVALID_PARAM;
				break;
			}
			p->state = IDLE;
			break;

		default:
			BUG();
			p->state = ERROR;
			rc = PORE_ERR_FASTI2C_SEQUENCE_ERROR;
			break;
		}
		break;

	default:
		return PORE_ERR_NOACK; /* not for this fi2cm */
	}

	*err_code = PORE_PCB_SUCCESS;
	return rc;
}


static int fi2c_write(struct pore_bus *b, uint64_t addr,
		      const uint8_t *buf, unsigned int len,
		      int *err_code)
{
	int rc = PORE_FAILURE;
	PibAddress pib_addr;
	struct fi2c *p = (struct fi2c *)poreb_get_priv(b);

	iprintf(b->pore, "  %-12s: %s(%p, 0x%llx, %p, %x)\n",
		b->name, __func__, b, (long long)addr, buf, len);

	/* SBE has: prv_port 0xa SEEPROM 2 byte addresses
	 *           "       0x1 OTP     2 byte addresses
	 *           "       0xb PNOR    4 byte addresses
	 *
	 * This is adjusted in the i2c_en_param_reg in the fields
	 * i2c_engine_identifier == prv_port and
	 * i2c_engine_address_range == addressBytes.
	 *
	 * All FI2CMs are in the pervasive chiplet which has 0x0.
	 */
	pib_addr.val = addr;
	if ((pib_addr.chiplet_id != 0x0) || (pib_addr.prv_port != p->prv_port))
		return PORE_ERR_NOACK; /* not for this fi2cm */

	switch (pib_addr.local_addr) {

	case FASTI2C_CONTROL_OFFSET:
		if (len != 8) {
			rc = PORE_ERR_INVALID_PARAM;
			break;
		}
		if (p->state != IDLE) {
			BUG();
			p->state = ERROR;
			rc = PORE_ERR_FASTI2C_SEQUENCE_ERROR;
			break;
		}

		p->control.val = *(uint64_t *)buf;

		if (!p->control.with_start   ||
		    !p->control.with_address ||
		    p->control.read_continue ||
		    !p->control.with_stop) {
			BUG();
			p->state = ERROR;
			rc = PORE_ERR_FASTI2C_CONTROL_ERROR;
			break;
		}

		if (p->control.read_not_write == 0) {
			if (p->control.address_range == 0) {
				BUG();
				p->state = ERROR;
				rc = PORE_ERR_FASTI2C_CONTROL_ERROR;
				break;
			}
			if (p->control.data_length != 8) {
				BUG();
				p->state = ERROR;
				rc = PORE_ERR_FASTI2C_CONTROL_ERROR;
				break;
			}
			rc = initialDataWrite(p);
			if (rc == PORE_SUCCESS)
				rc = len;
			break;
		} else {
			if ((p->control.data_length != 4) &&
			    (p->control.data_length != 8)) {
				BUG();
				p->state = ERROR;
				rc = PORE_ERR_FASTI2C_CONTROL_ERROR;
				break;
			}
			if (p->control.address_range != 0) {
				rc = addressWrite(p);
				if (rc < 0)
					break;
			}
			rc = dataRead(p);
			break;
		}
		break;

	case FASTI2C_STATUS_OFFSET:
		BUG();
		p->state = ERROR;
		rc = PORE_ERR_READ_ONLY_REGISTER;
		break;

	case FASTI2C_DATA_OFFSET:
		if (len != 8) {
			rc = PORE_ERR_INVALID_PARAM;
			break;
		}

		switch (p->state) {

		case WRITE_DATA_EXPECTED:
			rc = finalDataWrite(p, buf, 8);
			p->state = DATA_WRITE_ONGOING;
			break;

		default:
			BUG();
			p->state = ERROR;
			rc = PORE_ERR_FASTI2C_SEQUENCE_ERROR;
			break;
		}
		break;

	default:
		return PORE_ERR_NOACK; /* not for this fi2cm */
	}

	*err_code = PORE_PCB_SUCCESS;
	return rc;
}

struct pore_bus *poreb_create_fi2c(const char *name,
				   uint8_t *mem_buf,
				   unsigned int mem_size,
				   unsigned int mem_start,
				   unsigned int prv_port,
				   unsigned int address_bytes,
				   unsigned int i2c_port,
				   unsigned int deviceAddress)
{
	struct pore_bus *b;
	struct fi2c *e;

	b = poreb_create(name, sizeof(*e), fi2c_read, fi2c_write,
			 NULL, NULL);
	if (!b)
		return NULL;

	e = (struct fi2c *)poreb_get_priv(b);
	e->bus = b;
	e->mem_buf = mem_buf;
	e->mem_size = mem_size;
	e->mem_start = mem_start;
	e->address = 0;

	e->prv_port = prv_port;
	e->addressBytes = address_bytes;

	e->i2c_port = i2c_port;
	e->deviceAddress = deviceAddress;
	e->command_completion = 0;
	e->state = IDLE;

	return b;
}
