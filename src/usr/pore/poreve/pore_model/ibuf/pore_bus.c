/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/pore_model/ibuf/pore_bus.c $              */
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

/**
 * 24-bit address:
 *             11.1111.1111.2222
 * 0123.4567.8901.2345.6789.0123
 * || Mcase, ChipletId ...
 * ||
 * |`0: PIB_base_0
 * |    PIB_base_1
 * |
 * `0: PIB
 *  1: Memory (fi2c when used as SBE or OCI otherwise)
 *  |
 *  ` 0: OCI_base_0 & MEM_RELOC
 *    1: OCI_base_1 & MEM_RELOC
 */
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "pore_regs.h"
#include "pore_model.h"
#include "pore_ibuf.h"

/**
 * When running against hardware-simulated I2C memories, the PORE model needs
 * to honor the timeout specified in the I2C0 parameter register, as it may
 * take a large number of polls for the transaction to complete.  In no event
 * however do we ever poll more than 2^29 times.
 *
 * ** HACK FIX ME **
 */
#if 1
#define I2C_COMMAND_COMPLETION ({				     \
	int __pollThreshold = ((p->i2c_e_param[0].val >> 32) & 0xf); \
	if (__pollThreshold == 0) {				     \
		__pollThreshold = 15;				     \
	}							     \
	1u << ((__pollThreshold * 2) - 1);			     \
})
#else
#define I2C_COMMAND_COMPLETION  16 /* MAX iterations before aborting I2C */
#endif

/*** OCI Bus access **********************************************************/

static int oci_write(struct pore_bus *b, uint64_t addr,
		     const uint8_t *buf, unsigned int len,
		     int *err_code)
{
	struct pore_bus *oci = b->slaves[0];

	if (!oci) {
		eprintf(b->pore, "err: no oci available!\n");
		return PORE_ERR_NOACK;
	}

	bprintf(b->pore, "  %-12s: %s(%p, 0x%llx, %p, %x)\n", b->name,
		__func__, b, (long long)addr, buf, len);
	return poreb_write(oci, addr & PORE_BITS_32_63, buf, len, err_code);
}

static int oci_read(struct pore_bus *b, uint64_t addr, uint8_t *buf,
		    unsigned int len, int *err_code)
{
	struct pore_bus *oci = b->slaves[0];

	if (!oci) {
		eprintf(b->pore, "err: no oci available!\n");
		return PORE_ERR_NOACK;
	}

	bprintf(b->pore, "  %-12s: %s(%p, 0x%llx, %p, %x)\n", b->name,
		__func__, b, (long long)addr, buf, len);
	return poreb_read(oci, addr & PORE_BITS_32_63, buf, len, err_code);
}

/// Fetch Instruction Word from OCI Buffer
///
/// This method returns an instruction word from the fetch buffer. If
/// the fetch buffer is empty, it does an OCI interface read and
/// populates the buffer before returning the word.

static int fetchInstructionWordOci(struct pore_bus *b, _PoreAddress *pc,
				   uint32_t *word, int *err_code)
{
	int me = 0;
	uint32_t offset = pc->offset;
	pore_model_t p = b->pore;
	struct pore_bus *oci = b->slaves[0];

	// If the fetch buffer is not valid, or the data is not
	// already present it is fetched. Then the correct word is
	// returned from the buffer.

	if(!p->oci_fetchBufferValid ||
	   (p->oci_fetchBufferCursor != (offset & 0xfffffff8))) {

		p->oci_fetchBufferCursor = offset & 0xfffffff8;
		me = poreb_read(oci, p->oci_fetchBufferCursor,
				(uint8_t *)&p->oci_fetchBuffer,
				sizeof(p->oci_fetchBuffer), err_code);
		if (me < 0)
			return PORE_ERR_FETCH;

		p->oci_fetchBufferValid = 1;
	}
	*word = ((offset & 0x7) == 0) ?
		p->oci_fetchBuffer >> 32 :
		p->oci_fetchBuffer & 0xffffffff;

	return me;
}

/// Model the 1 or 3 word instruction fetch from OCI.
///
/// This is for GPE0/1 and SLW, and goes through the OCI 8-byte instruction
/// buffer.
static int oci_fetch(struct pore_bus *b, uint64_t _pc,
		       uint64_t *ibuf_01, uint64_t *ibuf_2,
		       unsigned int *size, int *err_code)
{
	int me;
	uint32_t i_word;
	_PoreAddress pc;
	pore_model_t p = b->pore;

	if (!b || !ibuf_01 || !ibuf_2 || !size || !err_code)
		return PORE_ERR_INVALID_PARAM;

	pc.val = _pc;
	*ibuf_01 = *ibuf_2 = 0;
	pore_relocateAddress(p, &pc.val);

	me = fetchInstructionWordOci(b, &pc, &i_word, err_code);
	if (me < 0)
		return PORE_ERR_FETCH;
	*ibuf_01 = (uint64_t)i_word << 32;
	*size = 4;

	if (i_word & 0x80000000) {
		pc.offset += 4;
		me = fetchInstructionWordOci(b, &pc, &i_word, err_code);
		if (me < 0)
			return PORE_ERR_FETCH;
		*size += 4;
		*ibuf_01 |= i_word;
		pc.offset += 4;
		me = fetchInstructionWordOci(b, &pc, &i_word, err_code);
		if (me < 0)
			return PORE_ERR_FETCH;
		*size += 4;
		*ibuf_2 = (uint64_t)i_word << 32;
	}
	return me;
}

static int oci_reset(pore_bus_t b)
{
	pore_model_t p = b->pore;

	p->oci_fetchBufferValid = 0;
	p->oci_fetchBufferCursor = 0;
	p->oci_fetchBuffer = 0;
	return 0;
}

struct pore_bus *poreb_create_pore2oci(struct pore_model *p,
				       const char *name,
				       struct pore_bus *oci)
{
	struct pore_bus *b;

	if (!p) {
		BUG();
		return NULL;
	}

	b = poreb_create(name, 0, oci_read,  oci_write,
			 oci_fetch, oci_reset);
	if (!b)
		return NULL;

	p->oci_fetchBufferValid = 0;
	p->oci_fetchBufferCursor = 0;
	p->oci_fetchBuffer = 0;
	b->slaves[0] = oci;
	b->pore = p;

	return b;
}

/*** Virtual bus to represent the address range for an fi2c master ***********/

struct pore_fi2cm {
	struct pore_bus *pib;
	pore_i2c_en_param_reg *i2c_param; /* reference to pore_model */
};

/**
 * Convert a _PoreAddress + I2C register offset into a PIB address
 */
static uint32_t
i2cPibAddress(_PoreAddress *address, uint16_t offset)
{
	return ((address->memorySpace & 0x3fff) << 16) + offset;
}

/* Modeling Notes
 *
 * The PORE engine optimizes read access to "fast I2C" memories by using two
 * types of read transactions: The first, "Set Address", establishes an
 * address in the memory, returns 4 or 8 bytes of data, and effectively
 * increments the address in memory. The second, "Read Data", returns data and
 * increments the stored address.  When fetching instructions the PORE engine
 * first establishes the fetch address (and gets the first instruction) with
 * "Set Address" and then continues to fetch using "Read Data" until a branch
 * is encountered.
 *
 * This optimization is currently _not_ modeled here. Instead all reads are
 * performed using the "Set Address" type operation.  There is no functional
 * difference between this model and the real hardware other than the fact
 * that it is not as efficient as the real hardware, but this would only be
 * noticed when running the virtual PORE against a real fast I2C memory
 * controller.
 *
 * The PORE engine does not optimize fast I2C writes.  Each write operation
 * always includes the address and data.
 */

static int fi2cm_read(struct pore_bus *b, uint64_t addr, uint8_t *buf,
		      unsigned int size, int *err_code)
{
	int rc;
	unsigned int count;
	pore_model_t p = b->pore;
	struct pore_fi2cm *fi2cm = (struct pore_fi2cm *)poreb_get_priv(b);
	pore_i2c_en_param_reg *i2cp = fi2cm->i2c_param;
	_PoreAddress address;
	fasti2c_control_reg control;
	fasti2c_status_reg status;
	uint32_t pib_addr;
	uint64_t read_data = 0;

	if (((size != 8) && (size != 4)) ||
	    ((i2cp->i2c_engine_address_range != 2) &&
	     (i2cp->i2c_engine_address_range != 4)))
		return PORE_ERR_INVALID_PARAM;

	iprintf(p, "############ I2C READ (len=%d) #######################\n",
		size);

	/* 4.7.3.2 Get Data (4 byte or 8 byte) */
	address.val = addr;

	/* 1. Write fast I2C Control Register at PRV address */
	control.val = 0;
	control.with_start     = 1;
	control.with_address   = 1;
	control.with_stop      = 1;
	control.read_continue  = 0;
	control.data_length    = size;
	control.device_address = i2cp->i2c_engine_device_id;
	control.read_not_write = 1; /* read */
	control.speed	       = i2cp->i2c_engine_speed;
	control.port_number    = i2cp->i2c_engine_port;
	control.address_range  = i2cp->i2c_engine_address_range;

	/* Add required address bytes to control register */
	control.val |= (address.offset <<
			((4 - i2cp->i2c_engine_address_range)*8));

	pib_addr = i2cPibAddress(&address, FASTI2C_CONTROL_OFFSET);
	rc = pore_pib_write(p, pib_addr, (uint8_t *)&control.val,
			    sizeof(control.val), err_code);
	if (rc < 0)
		return rc;

	/* 2. Wait for Data fill-level is 4/8 Bytes by polling fast
	 *    I2C status register at PRV address
	 */
	pib_addr = i2cPibAddress(&address, FASTI2C_STATUS_OFFSET);
	for (count = 0; count < I2C_COMMAND_COMPLETION; count++) {

		rc = pore_pib_read(p, pib_addr, (uint8_t *)&status.val,
				   sizeof(status.val), err_code);
		if (rc != sizeof(status.val))
			break;

		iprintf(p, "I2C_COMMAND_STATUS=%016llx count=%d\n"
			"  i2c_command_complete = %x\n"
			"  i2c_fifo_entry_count = %x\n",
			(long long)status.val, count,
			(unsigned int)status.i2c_command_complete,
			(unsigned int)status.i2c_fifo_entry_count);

		if ((status.i2c_command_complete) &&
		    (status.i2c_fifo_entry_count == size)) {
			break;
		}
	}
	/* Check for timeout or error */
	if (count == I2C_COMMAND_COMPLETION || (rc < 0))
		return pore_handleErrEvent(p, 1, PORE_ERR_I2C_POLLING);

	/* 3. Read 32 or 64 bit from fast I2C data register at PRV address */
	pib_addr = i2cPibAddress(&address, FASTI2C_DATA_OFFSET);
	rc = pore_pib_read(p, pib_addr, (uint8_t *)&read_data,
			   sizeof(read_data), err_code);
	read_data >>= (8 - size) * 8;

	/* Thi N Trans proposal
	 *
	 * #if (__BYTE_ORDER == __LITTLE_ENDIAN)
	 * memcpy(buf, (uint8_t *)&read_data, size);
	 * #else
	 * memcpy(buf, (uint8_t *)&read_data + (8 - size), size);
	 * #endif
	 */

	switch (size) {
	case 4: *(uint32_t *)buf = read_data; break;
	case 8: *(uint64_t *)buf = read_data; break;
	}
	return size;
}

/**
 * I2C Write
 *  o Fill control register with the address and the required data. If
 *    the i2c_engine_address_range allows, we need to fill the first few bytes
 *    of data into the control register behind the address bytes.
 *  o Write the data register with the remaining bytes.
 *  o Write the control register.
 *  o Poll for completion of the operation.
 */
static int fi2cm_write(struct pore_bus *b, uint64_t addr,
		       const uint8_t *buf, unsigned int size,
		       int *err_code)
{
	int rc;
	unsigned int count;
	pore_model_t p = b->pore;
	struct pore_fi2cm *fi2cm = (struct pore_fi2cm *)poreb_get_priv(b);
	pore_i2c_en_param_reg *i2cp = fi2cm->i2c_param;
	fasti2c_control_reg control;
	fasti2c_status_reg status;
	_PoreAddress address;
	uint32_t pib_addr;
	uint64_t write_data;

	if ((size != 8) ||
	    ((i2cp->i2c_engine_address_range != 2) &&
	     (i2cp->i2c_engine_address_range != 4)))
		return PORE_ERR_INVALID_PARAM;

	iprintf(p, "############ I2C WRITE ###############################\n");

	/* 4.7.3.3 Write Data (8 byte, SBE memory interface only) */
	address.val = addr;
	write_data = *((uint64_t *)buf);

	/* 1. Set up fast I2C Control Register */
	control.val = 0;
	control.with_start     = 1;
	control.with_address   = 1;
	control.with_stop      = 1;
	control.read_continue  = 0;
	control.data_length    = size;
	control.device_address = i2cp->i2c_engine_device_id;
	control.read_not_write = 0; /* write */
	control.speed	       = i2cp->i2c_engine_speed;
	control.port_number    = i2cp->i2c_engine_port;
	control.address_range  = i2cp->i2c_engine_address_range;

	/* Add required address bytes to control register */
	control.val |= (address.offset <<
			((4 - i2cp->i2c_engine_address_range)*8));

	/* Add possible data bytes to control register */
	if (i2cp->i2c_engine_address_range < 4)
		control.val |= (write_data >>
				(64 - ((4-i2cp->i2c_engine_address_range)*8)));

	/* 2. Write fast I2C Data Register at PRV address */
	/* Write remaining data bytes to data register (left algined)*/
	write_data = write_data << ((4 - i2cp->i2c_engine_address_range) * 8);

	pib_addr = i2cPibAddress(&address, FASTI2C_DATA_OFFSET);
	rc = pore_pib_write(p, pib_addr, (uint8_t *)&write_data,
			    sizeof(write_data), err_code);
	if (rc < 0)
		return rc;

	/* 3. Write fast I2C Control Register at PRV address */
	pib_addr = i2cPibAddress(&address, FASTI2C_CONTROL_OFFSET);
	rc = pore_pib_write(p, pib_addr, (uint8_t *)&control.val,
			    sizeof(control.val), err_code);
	if (rc < 0)
		return rc;

	/**
	 * 4. Wait and poll fast I2C status register for operation to
	 * complete at PRV address
	 */
	/* FIXME Check instead bit 44 (which is not right in my
	 * register definition!
	 */
	pib_addr = i2cPibAddress(&address, FASTI2C_STATUS_OFFSET);
	for (count = 0; count < I2C_COMMAND_COMPLETION; count++) {

		rc = pore_pib_read(p, pib_addr, (uint8_t *)&status.val,
				   sizeof(status.val), err_code);
		if (rc != sizeof(status.val))
			break;

		iprintf(p, "I2C_COMMAND_STATUS=%016llx count=%d\n"
			"  i2c_command_complete = %x\n"
			"  i2c_fifo_entry_count = %x\n",
			(long long)status.val, count,
			(unsigned int)status.i2c_command_complete,
			(unsigned int)status.i2c_fifo_entry_count);

		if (status.i2c_command_complete) {
			return size;
		}
	}
	return pore_handleErrEvent(p, 1, PORE_ERR_I2C_POLLING);
}

struct pore_bus *poreb_create_fi2cm(pore_model_t p, const char *name,
				    pore_bus_t pib,
				    pore_i2c_en_param_reg *i2c_param)
{
	struct pore_bus *b;
	struct pore_fi2cm *e;

	b = poreb_create(name, sizeof(*e), fi2cm_read, fi2cm_write,
			 NULL, NULL);
	if (!b)
		return NULL;

	e = (struct pore_fi2cm *)poreb_get_priv(b);
	e->i2c_param = i2c_param;
	e->pib = pib;
	b->pore = p;

	return b;
}

/* FIXME
 * 1. Select fi2c master using memory_reloc and oci_base register.
 * 2. Perform fi2c access.
 */
static int fi2c_read(struct pore_bus *b, uint64_t addr, uint8_t *buf,
		     unsigned int len, int *err_code)
{
	int i;
	uint32_t port;
	pore_model_t p = b->pore;
	_PoreAddress address;

	bprintf(p, "  %-12s: %s(%p, 0x%llx, %p, %x)\n", b->name, __func__, b,
		(long long)addr, buf, len);

	address.val = addr;
	port = address.memorySpace & 0xf; /* must match i2c_engine_id */

	for (i = 0; i < 3; i++) {
		struct pore_bus *fi2cm = b->slaves[i];

		if (!fi2cm)
			continue;
		if (!fi2cm->read)
			continue;

		/* Is this fi2c master target of the desired transfer?
		 * Check i2c_engine_identifier against the port number
		 * encoded in the upper parts of he address we got.
		 * The upper part is contructed using the OCI_base register
		 * used for this acess.
		 */
		if (p->i2c_e_param[i].i2c_engine_identifier != port) {
			continue;
		}

		return poreb_read(fi2cm, addr, buf, len, err_code);
	}

	return PORE_ERR_READ;
}

static int fi2c_write(struct pore_bus *b, uint64_t addr,
		      const uint8_t *buf, unsigned int len,
		      int *err_code)
{
	int i;
	uint32_t port;
	pore_model_t p = b->pore;
	_PoreAddress address;

	address.val = addr;
	port = address.memorySpace & 0xf; /* must match i2c_engine_id */

	for (i = 0; i < 3; i++) {
		struct pore_bus *fi2cm = b->slaves[i];

		if (!fi2cm)
			continue;
		if (!fi2cm->write)
			continue;

		/* is this fi2c master target of the desired transfer?
		 * I originally wanted to do this compare in the fi2cm
		 * code but that did not work with memory emulation
		 * which is not aware of the condition below.
		 */
		if (p->i2c_e_param[i].i2c_engine_identifier != port) {
			continue;
		}

		return poreb_write(fi2cm, addr, buf, len, err_code);

	}

	return PORE_ERR_WRITE;
}

/// Model 1 or 3 word instruction fetch using indirect PIB addressing (SBE).
static int fi2c_fetch(struct pore_bus *b, uint64_t _pc,
		      uint64_t *ibuf_01, uint64_t *ibuf_2,
		      unsigned int *size, int *err_code)
{
	int me = PORE_SUCCESS;
	uint32_t i_word;
	_PoreAddress pc;
	pore_model_t p = b->pore;

	if (!b || !ibuf_01 || !ibuf_2 || !size || !err_code)
		return PORE_ERR_INVALID_PARAM;

	*size = 0;
	*ibuf_01 = *ibuf_2 = 0;
	pc.val = _pc;
	pore_relocateAddress(p, &pc.val);

	me = fi2c_read(b, pc.val, (uint8_t *)&i_word,
		       sizeof(i_word), err_code);
	if (me != sizeof(i_word))
		return PORE_ERR_FETCH;

	*ibuf_01 = (uint64_t)i_word << 32;
	*size = 4;

	if (i_word & 0x80000000) {
		pc.offset += 4;
		me = fi2c_read(b, pc.val, (uint8_t *)&i_word,
			       sizeof(i_word), err_code);
		if (me != sizeof(i_word))
			return PORE_ERR_FETCH;
		*size += 4;
		*ibuf_01 |= i_word;
		pc.offset += 4;
		me = fi2c_read(b, pc.val, (uint8_t *)&i_word,
			       sizeof(i_word), err_code);
		if (me != sizeof(i_word))
			return PORE_ERR_FETCH;
		*size += 4;
		*ibuf_2 = (uint64_t)i_word << 32;
	}
	return me;
}


struct pore_bus *poreb_create_pore2fi2c(pore_model_t p,
					const char *name,
					struct pore_bus *fi2c0,
					struct pore_bus *fi2c1,
					struct pore_bus *fi2c2)
{
	struct pore_bus *b;

	b = poreb_create(name, 0, fi2c_read, fi2c_write, fi2c_fetch, NULL);
	if (!b)
		return NULL;

	b->slaves[0] = fi2c0;
	b->slaves[1] = fi2c1;
	b->slaves[2] = fi2c2;
	b->pore = p;

	return b;
}

/*** PIB slave to implement self-scomming functionality **********************/

static int selfscom_read(struct pore_bus *b, uint64_t addr,
			 uint8_t *buf, unsigned int len,
			 int *err_code)
{
	uint64_t *val64 = (uint64_t *)buf;
	PibAddress pib_addr, *pore_addr = (PibAddress *)poreb_get_priv(b);

	pib_addr.val = addr;
	if ((pib_addr.chiplet_id != pore_addr->chiplet_id) ||
	    (pib_addr.prv_port   != pore_addr->prv_port))
		return PORE_ERR_NOACK;

	if (!b->pore)
		return PORE_ERR_NOACK;

	switch (addr & 0xffff) {
		/* vPORe register - self-scomming */
	case PORE_R_STATUS:
	case PORE_R_CONTROL:
	case PORE_R_RESET:
	case PORE_R_ERROR_MASK:
	case PORE_R_PRV_BASE_ADDR0:
	case PORE_R_PRV_BASE_ADDR1:
	case PORE_R_OCI_MEMORY_BASE_ADDR0:
	case PORE_R_OCI_MEMORY_BASE_ADDR1:
	case PORE_R_TABLE_BASE_ADDR:
	case PORE_R_EXE_TRIGGER:
	case PORE_R_SCRATCH0:
	case PORE_R_SCRATCH1:
	case PORE_R_SCRATCH2:
	case PORE_R_IBUF_01:
	case PORE_R_IBUF_2:
	case PORE_R_DBG0:
	case PORE_R_DBG1:
	case PORE_R_PC_STACK0:
	case PORE_R_PC_STACK1:
	case PORE_R_PC_STACK2:
	case PORE_R_ID_FLAGS:
	case PORE_R_DATA0:
	case PORE_R_MEM_RELOC:
	case PORE_R_I2C_E0_PARAM:
	case PORE_R_I2C_E1_PARAM:
	case PORE_R_I2C_E2_PARAM:
		*val64 = pore_readReg(b->pore, (pore_reg_t)(addr & 0xff),
				      PORE_BITS_0_63);
		*err_code = PORE_PCB_SUCCESS;
		return len;
	}

	return PORE_ERR_NOACK;
}

static int selfscom_write(struct pore_bus *b, uint64_t addr,
			  const uint8_t *buf, unsigned int len,
			  int *err_code)
{
	uint64_t *val64 = (uint64_t *)buf;
	PibAddress pib_addr, *pore_addr = (PibAddress *)poreb_get_priv(b);

	pib_addr.val = addr;
	if ((pib_addr.chiplet_id != pore_addr->chiplet_id) ||
	    (pib_addr.prv_port   != pore_addr->prv_port))
		return PORE_ERR_NOACK;

	if (!b->pore)
		return PORE_ERR_NOACK;

	switch (addr & 0xffff) {
		/* vPORe register - self-scomming */
	case PORE_R_STATUS:
	case PORE_R_CONTROL:
	case PORE_R_RESET:
	case PORE_R_ERROR_MASK:
	case PORE_R_PRV_BASE_ADDR0:
	case PORE_R_PRV_BASE_ADDR1:
	case PORE_R_OCI_MEMORY_BASE_ADDR0:
	case PORE_R_OCI_MEMORY_BASE_ADDR1:
	case PORE_R_TABLE_BASE_ADDR:
	case PORE_R_EXE_TRIGGER:
	case PORE_R_SCRATCH0:
	case PORE_R_SCRATCH1:
	case PORE_R_SCRATCH2:
	case PORE_R_IBUF_01:
	case PORE_R_IBUF_2:
	case PORE_R_DBG0:
	case PORE_R_DBG1:
	case PORE_R_PC_STACK0:
	case PORE_R_PC_STACK1:
	case PORE_R_PC_STACK2:
	case PORE_R_ID_FLAGS:
	case PORE_R_DATA0:
	case PORE_R_MEM_RELOC:
	case PORE_R_I2C_E0_PARAM:
	case PORE_R_I2C_E1_PARAM:
	case PORE_R_I2C_E2_PARAM:
		pore_writeReg(b->pore, (pore_reg_t)(addr & 0xff),
			      *val64, PORE_BITS_0_63);
		*err_code = PORE_PCB_SUCCESS;
		return len;
	}

	return PORE_ERR_NOACK;
}

struct pore_bus *poreb_create_selfscom(const char *name,
				       unsigned int chiplet_id,
				       unsigned int prv_port)
{
	struct pore_bus *b;
	PibAddress *pib_addr;

	b = poreb_create(name, sizeof(*pib_addr), selfscom_read,
			 selfscom_write, NULL, NULL);
	if (!b)
		return NULL;
	pib_addr = (PibAddress *)poreb_get_priv(b);
	pib_addr->val = 0;
	pib_addr->chiplet_id = chiplet_id;
	pib_addr->prv_port = prv_port;

	return b;
}

/*** Generic Bus functionality ***********************************************/

static int __poreb_read(struct pore_bus *b, uint64_t addr,
			uint8_t *buf, unsigned int len,
			int *err_code)
{
	int last_rc = PORE_ERR_NOACK, good_rcs = 0, rc = 0;
	unsigned int i;

	for (i = 0; i < PORE_MAX_BUS; i++) {
		struct pore_bus *s = b->slaves[i];

		if (s == NULL)
			continue;

		/* We expect PORE_ERR_NOACK if slave is ok, but not
		 * responsible for this transfer. If anything else is
		 * returned the first one has it, else try another
		 * slave.
		 */
		rc = poreb_read(s, addr, buf, len, err_code);
		if (rc != PORE_ERR_NOACK) {
			last_rc = rc;
			good_rcs++;

			return last_rc;	/* FIXME Do not return!!! */
		}
	}
	if (good_rcs > 1) {
		BUG();
		return PORE_ERR_BUS_COLLISION;
	}

	return last_rc;
}


static int __poreb_write(struct pore_bus *b, uint64_t addr,
			 const uint8_t *buf, unsigned int len,
			 int *err_code)
{
	int last_rc = PORE_ERR_NOACK, good_rcs = 0, rc = 0;
	unsigned int i;

	for (i = 0; i < PORE_MAX_BUS; i++) {
		struct pore_bus *s = b->slaves[i];

		if (s == NULL)
			continue;

		/* We expect PORE_ERR_NOACK if slave is ok, but not
		 * responsible for this transfer. If anything else is
		 * returned the first one has it, else try another
		 * slave.
		 */
		rc = poreb_write(s, addr, buf, len, err_code);
		if (rc != PORE_ERR_NOACK) {
			last_rc = rc;
			good_rcs++;

			return last_rc;	/* FIXME Do not return!!! */
		}
	}
	if (good_rcs > 1) {
		BUG();
		return PORE_ERR_BUS_COLLISION;
	}

	return last_rc;
}

void poreb_destroy(pore_bus_t b)
{
	unsigned int i;

	if (!b) return;
	for (i = 0; i < PORE_MAX_BUS; i++) {
		if (b->slaves[i])
			poreb_destroy(b->slaves[i]);
	}
	free(b);
}

struct pore_bus *
poreb_create(const char *name, size_t priv_data_size,
	     poreb_read_f  r, poreb_write_f w,
	     poreb_fetch_f f, poreb_reset_f R)
{
	struct pore_bus *b;

	b = (struct pore_bus *)malloc(sizeof(*b) + priv_data_size);
	if (!b)
		return NULL;
	memset(b, 0, sizeof(*b) + priv_data_size);

	b->name  = name;
	b->read  = (r) ? (r) : (__poreb_read);
	b->write = (w) ? (w) : (__poreb_write);
	b->fetch = (f) ? (f) : (NULL);
	b->reset = (R) ? (R) : (NULL);

	return b;
}

int poreb_read(pore_bus_t b, uint64_t addr, uint8_t *buf,
	       unsigned int size, int *err_code)
{
	if (!b)
		return PORE_ERR_INVALID_PARAM;
	if (!b->read)
		return PORE_ERR_NOT_IMPLEMENTED;
	return b->read(b, addr, buf, size, err_code);
}

int poreb_write(pore_bus_t b, uint64_t addr, const uint8_t *buf,
		unsigned int size, int *err_code)
{
	if (!b)
		return PORE_ERR_INVALID_PARAM;
	if (!b->write)
		return PORE_ERR_NOT_IMPLEMENTED;
	return b->write(b, addr, buf, size, err_code);
}

int poreb_fetch(pore_bus_t b, uint64_t pc, uint64_t *i_buf01,
		uint64_t *i_buf2, unsigned int *size, int *err_code)
{
	if (!b)
		return PORE_ERR_INVALID_PARAM;
	if (!b->fetch)
		return PORE_ERR_NOT_IMPLEMENTED;
	return b->fetch(b, pc, i_buf01, i_buf2, size, err_code);
}

int poreb_reset(pore_bus_t p)
{
	if (!p)
		return PORE_ERR_INVALID_PARAM;
	if (!p->reset)
		return PORE_ERR_NOT_IMPLEMENTED;
	return p->reset(p);
}

int poreb_attach_slave(struct pore_bus *b, struct pore_bus *s)
{
	unsigned int i;

	for (i = 0; i < PORE_MAX_BUS; i++) {
		if (!b->slaves[i]) {
			b->slaves[i] = s;
			return 0;
		}
	}
	return PORE_ERR_NOSPACE;
}
