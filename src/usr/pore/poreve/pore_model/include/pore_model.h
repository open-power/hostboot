/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/pore_model/include/pore_model.h $         */
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
#ifndef __PORE_MODEL__
#define __PORE_MODEL__

/**
 * @file   pore_model.h
 * @Author Frank Haverkamp
 * @date   October, 2011
 *
 * @brief C interface for the Virtual Power-On-Reset Engine
 * vPORe. This code should be as portable as possible and have just a
 * few references to the outside envirnonment. To use this code in the
 * existing C++ environment one needs to use it together with the vsbe
 * C++ wrapper.
 *
 * The model assumes 4 or 8 byte data in host-byte order. That makes
 * it necessarry for the outside code to do the endian swapping before
 * the data is hand over to the model. Same is true for write requests
 * by the model. Here the data is passed in host-endian order to the
 * outside of the model.
 */

#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Version of the vPORe model */
#define PORE_MODEL_VERSION		0x00010012

/**
 * Different PORe incarations
 *   PORE_GPE has two IBUF instances: IBUF0_ID = 0b0000, IBUF1_ID = 0b0001
 *   PORE_SLW has one IBUF instance:  IBUF0_ID = 0b1000
 *   PORE_SBE has one IBUF instance:  IBUF0_ID = 0b0100
 */
#define PORE_IBUF_ID_GPE0		0x00
#define PORE_IBUF_ID_GPE1		0x01
#define PORE_IBUF_ID_SLW		0x08
#define PORE_IBUF_ID_SBE		0x04

/** Status Codes */
#define PORE_SUCCESS			0
#define PORE_IN_RESET			1
#define PORE_STOPPED			2
#define PORE_BREAKPOINT_HIT		3
#define PORE_ERROR_IGNORED		4

/** Error Codes */
#define PORE_FAILURE			-100
#define PORE_ERR_NOACK			-102
#define PORE_ERR_READ			-103
#define PORE_ERR_WRITE			-104
#define PORE_ERR_FETCH			-105
#define PORE_ERR_DECODE			-106
#define PORE_ERR_EXECUTE		-107
#define PORE_ERR_NOSPACE		-108
#define PORE_ERR_FI2CM			-109
#define PORE_ERR_INVALID_PARAM		-110
#define PORE_ERR_NOT_IMPLEMENTED	-111
#define PORE_ERR_I2C_POLLING		-112
#define PORE_ERR_IN_RESET		-113
#define PORE_ERR_ILLEGAL_FORCED_BRANCH	-114
#define PORE_ERR_NOT_STOPPED		-115
#define PORE_ERR_NOT_STOPPED_WAIT	-116
#define PORE_ERR_BEHAVIOR_NOT_MODELED	-117
#define PORE_ERR_REGISTER_LOCKED	-118
#define PORE_ERR_BUG_INVALID_VECTOR	-119
#define PORE_ERR_INVALID_STACK_POINTER	-120
#define PORE_ERR_STACK_OVERFLOW		-121
#define PORE_ERR_STACK_UNDERFLOW	-122
#define PORE_ERR_INVALID_OPCODE		-123
#define PORE_ERR_UNIMPLEMENTED_INSTR	-124
#define PORE_ERR_INVALID_OPERAND	-125
#define PORE_ERR_HOOK_FAILED		-126
#define PORE_ERR_UNCONNECTED_BUS	-127
#define PORE_ERR_WRITE_ONLY_REGISTER    -128
#define PORE_ERR_READ_ONLY_REGISTER     -129
#define PORE_ERR_FASTI2C_SEQUENCE_ERROR -130
#define PORE_ERR_FASTI2C_CONTROL_ERROR  -131
#define PORE_ERR_ILLEGAL_REG_OFFSET     -132
#define PORE_ERR_I2CMEMORY_ILLEGAL_ADDR -133
#define PORE_ERR_NOT_MAPPED_ON_FASTI2C  -134
#define PORE_ERR_BUS_COLLISION		-135

#define PORE_ERR_HANDLED_BY_CODE	-200
/* ... more to come */

/******************************************************************************
 * PORe Bus: master and slave
 *****************************************************************************/

/**
 * @enum pore_PcbReturnCode
 *
 * This enumeration follows the 3-bit return code as specified in the
 * Pervasive Workbook.
 */
enum pore_PcbReturnCode {
	PORE_PCB_SUCCESS = 0,
	PORE_PCB_RESOURCE_OCCUPIED = 1,
	PORE_PCB_CHIPLET_OFFLINE = 2,
	PORE_PCB_PARTIAL_GOOD = 3,
	PORE_PCB_ADDRESS_ERROR = 4,
	PORE_PCB_CLOCK_ERROR = 5,
	PORE_PCB_PACKET_ERROR = 6,
	PORE_PCB_TIMEOUT = 7
};

/**
 * @enum pore_OciReturnCode
 *
 * These return codes are abstractions; The OCI_BUS_ERROR is a
 * catch-all for now.
 */
enum pore_OciReturnCode {
	PORE_OCI_SUCCESS = 0,
	PORE_OCI_BUS_ERROR = 1
};

#define PORE_MAX_BUS	64 /** maximum number of possible busses/slaves */

typedef struct pore_bus *pore_bus_t;

typedef int (* poreb_read_f)  (pore_bus_t p, uint64_t addr,
			       uint8_t *buf, unsigned int size,
			       int *err_code);

typedef int (* poreb_write_f) (pore_bus_t p, uint64_t addr,
			       const uint8_t *buf, unsigned int size,
			       int *err_code);

typedef int (* poreb_fetch_f) (pore_bus_t p, uint64_t pc,
			       uint64_t *i_buf01, uint64_t *i_buf2,
			       unsigned int *size,
			       int *err_code);

typedef int (* poreb_reset_f) (pore_bus_t p);


/**
 * @brief The pore_bus structure is public because the user should be
 * able to attach his/her own behavior if needed. The read, write, or
 * fetch functions are called by the pore-model or by an
 * address-translation object.
 */
struct pore_bus {
	const char *name;	/**< name of the bus, for debug prints */
	struct pore_model *pore;/**< reference to pore_model */

	poreb_read_f  read;	/**< read data from bus */
	poreb_write_f write;	/**< write data to bus */
	poreb_fetch_f fetch;	/**< fetch instructions via the bus */
	poreb_reset_f reset;	/**< reset the bus, clear buffers */

	struct pore_bus *slaves[PORE_MAX_BUS]; /** slave devices/busses */
	uint8_t priv_data[0];	/**< keep internal data here */
};

static inline void *poreb_get_priv(struct pore_bus *b)
{
	return (void *)b->priv_data;
}

/**
 * @brief Create PORe bus-object. The user must create own bus-objects
 * to implement PIB and/or OCI accesses.
 *
 * @param [in] pore    reference to PORe model
 * @param [in] name    name of this bus-object
 * @param [in] priv_data_size size of private information
 * @return             NULL on failure, or reference to bus-object
 */
struct pore_bus *poreb_create(const char *name,
			      size_t priv_data_size,
			      poreb_read_f  r,
			      poreb_write_f w,
			      poreb_fetch_f f,
			      poreb_reset_f R);

/**
 * @brief Destroy poreb-bus.
 *
 * @param [in] b       reference to PORe bus
 */
void poreb_destroy(pore_bus_t b);

/**
 * @brief Attach a slave to a bus-object.
 *
 * @param [in] b       reference to bus-object
 * @param [in] s       reference to bus-object which should be attached to b
 * @return             PORE_SUCCESS, or negative error code
 */
int poreb_attach_slave(struct pore_bus *b, struct pore_bus *s);

/**
 * @brief Read data from bus.
 *
 * @param [in] p         reference to PORe model
 * @param [in] addr      address for data access
 * @param [in] buf       address where data should be written to
 * @param [in] size      size of buf in bytes
 * @param [out] err_code Bus error code @see pore_PcbReturnCode,
 *                       @see pore_OciReturnCode
 */
int poreb_read (pore_bus_t p, uint64_t addr, uint8_t *buf,
		unsigned int size, int *err_code);

/**
 * @brief Write data to bus.
 *
 * @param [in] p         reference to PORe model
 * @param [in] addr      address for data access
 * @param [in] buf       address of the data
 * @param [in] size      size of buf in bytes
 * @param [out] err_code Bus error code @see pore_PcbReturnCode,
 *                       @see pore_OciReturnCode
 */
int poreb_write(pore_bus_t p, uint64_t addr, const uint8_t *buf,
		unsigned int size, int *err_code);

/**
 * @brief Fetch instruction from bus.
 *
 * @param [in] p         reference to PORe model
 * @param [in] pc        address for data access
 * @param [out] i_buf01  1st part of the instruction
 * @param [out] i_buf2   2nd part of the instruction (only for large instr.)
 * @param [out] size     4 for normal instr. and 12 for large instr.
 * @param [out] err_code Bus error code @see pore_PcbReturnCode,
 *                       @see pore_OciReturnCode
 */
int poreb_fetch(pore_bus_t p, uint64_t pc, uint64_t *i_buf01,
		uint64_t *i_buf2, unsigned int *size, int *err_code);

/**
 * @brief Reset the PORe model. Including all busses attached to it.
 *
 * @param [in] p         reference to PORe model
 */
int poreb_reset(pore_bus_t p);

/**
 * @brief Create fast i2c bus-object.
 *
 * @bugs An I2C controller can support more than one ports and it can
 * also have more than one device listening on one of those. Just like
 * real world I2C busses connected to an I2C master with an output
 * multiplexor. For our purpose one i2c_port with one device address
 * is enough.
 *
 * @param [in] name       Name of fi2c device
 * @param [in] mem_buf    Memory area used to emulate content
 * @param [in] mem_size   Size of memory area
 * @param [in] mem_start  Start offset of memory area, e.g. LPC bus has
 *                        flash at end
 * @param [in] prv_port   Pervasive port number (part of the address)
 * @param [in] address_bytes Number of required address bytes
 * @param [in] i2c_port   Pervasive I2C masters support muxing multiple
 *                        I2C ports
 * @param [in] deviceAddress Address of the to be accessed I2C chip
 * @return                Pointer to pore_bus object, or NULL in case of
 *                        failure
 */
struct pore_bus *poreb_create_fi2c(const char *name,
				   uint8_t *mem_buf,
				   unsigned int mem_size,
				   unsigned int mem_start,
				   unsigned int prv_port,
				   unsigned int address_bytes,
				   unsigned int i2c_port,
				   unsigned int deviceAddress);

/******************************************************************************
 * PORe Model
 *****************************************************************************/

/**
 * @brief Reference to PORe model. This reference is used for all functions
 * dealing with the PORe model.
 */
typedef struct pore_model *pore_model_t; /** Representation of the virtual
					     PORE model */

/**
 * @brief Functions to create different instances of a PORe model.
 * @see pore_sbe_create, pore_slw_create, pore_gpe0_create, and
 * pore_gpe1_create.
 */
pore_model_t pore_model_create(const char *name);

/**
 * @brief Destroy poreb-bus.
 * @param [in] p       reference to PORe model
 */
void pore_model_destroy(pore_model_t p);

void pore_relocateAddress(pore_model_t p, uint64_t *address);

/**
 * @brief Create pore-bus object which can be used to implement
 * selfscomming behavior when attached as slave to the PIB
 * implementation.
 *
 * @param [in] name       Name of fi2c device
 * @param [in] prv_port   Pervasive port number (part of the address)
 * @return                Pointer to pore_bus object, or NULL in case of
 *                        failure
 */
struct pore_bus *poreb_create_selfscom(const char *name,
				       unsigned int chiplet_id,
				       unsigned int prv_port);

/**
 * @brief Attach MEM/OCI bus to PORe model. This includes setting up
 * the pore member variable of the pore_bus_t object recursively.
 *
 * @param [in] p         reference to PORe model
 * @param [in] b         referenct to OCI/MEM bus-object
 */
int pore_attach_mem(pore_model_t p, struct pore_bus *b);

/**
 * @brief Unit2: PORE_SBE (1 thread self-boot engine to support
 * initial booting)
 *
 * @param [in] pib    reference to pib bus-object
 * @return            NULL on error, or reference PORe model
 */
pore_model_t pore_sbe_create  (pore_bus_t pib);

/**
 * @brief Unit1: PORE_SLW (1 thread engine for waking-up from sleep
 * and winkle modes)
 *
 * @param [in] pib    reference to pib bus-object
 * @param [in] oci    reference to oci bus-object
 * @return            NULL on error, or reference PORe model
 */
pore_model_t pore_slw_create  (pore_bus_t pib, pore_bus_t oci);

/**
 * @brief Unit0: PORE_GPE (2 thread engine to replace OCA)
 *
 * @param [in] pib    reference to pib bus-object
 * @param [in] oci    reference to oci bus-object
 * @return            NULL on error, or reference PORe model
 */
pore_model_t pore_gpe0_create (pore_bus_t pib, pore_bus_t oci);

/**
 * @brief Unit0: PORE_GPE (2 thread engine to replace OCA)
 *
 * @param [in] pib    reference to pib bus-object
 * @param [in] oci    reference to oci bus-object
 * @return            NULL on error, or reference PORe model
 */
pore_model_t pore_gpe1_create (pore_bus_t pib, pore_bus_t oci);

void pore_reset(pore_model_t p);
int pore_step(pore_model_t p);
int pore_run(pore_model_t p, int steps);

typedef enum {
	PORE_R_STATUS		     = 0x00,
	PORE_R_CONTROL		     = 0x08,
	PORE_R_RESET		     = 0x10,
	PORE_R_ERROR_MASK	     = 0x18,
	PORE_R_PRV_BASE_ADDR0	     = 0x20,
	PORE_R_PRV_BASE_ADDR1	     = 0x28,
	PORE_R_OCI_MEMORY_BASE_ADDR0 = 0x30,
	PORE_R_OCI_MEMORY_BASE_ADDR1 = 0x38,
	PORE_R_TABLE_BASE_ADDR	     = 0x40,
	PORE_R_EXE_TRIGGER	     = 0x48,
	PORE_R_SCRATCH0		     = 0x50,
	PORE_R_SCRATCH1		     = 0x58,
	PORE_R_SCRATCH2		     = 0x60,
	PORE_R_IBUF_01		     = 0x68,
	PORE_R_IBUF_2		     = 0x70,
	PORE_R_DBG0		     = 0x78,
	PORE_R_DBG1		     = 0x80,
	PORE_R_PC_STACK0	     = 0x88,
	PORE_R_PC_STACK1	     = 0x90,
	PORE_R_PC_STACK2	     = 0x98,
	PORE_R_ID_FLAGS		     = 0xa0,
	PORE_R_DATA0		     = 0xa8,
	PORE_R_MEM_RELOC	     = 0xb0,
	PORE_R_I2C_E0_PARAM	     = 0xb8,
	PORE_R_I2C_E1_PARAM	     = 0xc0,
	PORE_R_I2C_E2_PARAM	     = 0xc8,
	/* ------------------------------ */
	/* 4 x uint64_t internal state    */
	PORE_R_SIZEOF_PORE_STATE     = 0xf0, /**< size of PORe state */
	PORE_R_ILLEGAL		     = 0xff, /**< illegal offs, err checking */
} pore_reg_t;			/**< register encodings */

/** Bits 0:31 of a 64-bit register */
#define PORE_BITS_0_31  0xffffffff00000000ull

/** Bits 32:63 of a 64-bit register */
#define PORE_BITS_32_63 0x00000000ffffffffull

/** Bits 0:63 of a 64-bit register */
#define PORE_BITS_0_63  0xffffffffffffffffull

/**
 * @brief Write to PORe register _with_ side effects.
 *
 * @param [in] p     reference to pore_model
 * @param [in] reg   register id
 * @param [in] d     data
 * @param [in] msk   mask for write. 4 and 8 bytes are supported
 *	             Use PORE_BITS_0_31, PORE_BITS_32_63 PORE_BITS_0_63.
 * @return           0 on success, else negative error code
 */
int pore_writeReg(pore_model_t p, pore_reg_t reg, uint64_t d, uint64_t msk);

/**
 * @brief Read PORe register _with_ side effects.
 *
 * @param [in] p     reference to pore_model
 * @param [in] reg   register id
 * @param [in] msk   mask for read. 4 and 8 bytes are supported
 *	             Use PORE_BITS_0_31, PORE_BITS_32_63 PORE_BITS_0_63.
 * @return           value of register to read
 */
uint64_t pore_readReg(pore_model_t p, pore_reg_t reg, uint64_t msk);

/**
 * @brief Writes are done _without_ side effects.
 *
 * @param [in] p     reference to pore_model
 * @param [in] reg   register id
 * @param [in] d     data
 * @param [in] msk   mask for read/write. 4 and 8 bytes are supported
 *	             Use PORE_BITS_0_31, PORE_BITS_32_63 PORE_BITS_0_63.
 * @return           0 on success, else negative error code
 */
int pore_writeRegRaw(pore_model_t p, pore_reg_t reg, uint64_t d, uint64_t msk);

/**
 * @brief Reads are done _without_ side effects.
 *
 * @param [in] p     reference to pore_model
 * @param [in] reg   register id
 * @param [in] msk   mask for read/write. 4 and 8 bytes are supported
 *	             Use PORE_BITS_0_31, PORE_BITS_32_63 PORE_BITS_0_63.
 * @return           value of register to read
 */
uint64_t pore_readRegRaw(pore_model_t p, pore_reg_t reg, uint64_t msk);

/**
 * @brief The pore_state_t structure defines the state of the
 * model. It is used to backup and restore the model state via
 * pore_extractState and pore_installState. The structure contains the
 * architected registers first and the model/implementation specific
 * data hidden at the end. When installing the state the resources
 * are restored without any hardware side effects compared to the
 * regular writeReg, readReg functionality.
 *
 * @note The size of the structure must not exceed
 * PORE_R_SIZEOF_PORE_STATE.
 */
typedef struct pore_state {
	/** start of architected register set */
	uint64_t status;			/* 0x00000000 */
	uint64_t pore_control;			/* 0x00000008 */
	uint64_t pore_reset;			/* 0x00000010 */
	uint64_t pore_error_mask;		/* 0x00000018 */
	uint64_t prv_base0;			/* 0x00000020 */
	uint64_t prv_base1;			/* 0x00000028 */
	uint64_t oci_base0;			/* 0x00000030 */
	uint64_t oci_base1;			/* 0x00000038 */
	uint64_t pore_table_base_addr;		/* 0x00000040 */
	uint64_t exe_trigger;			/* 0x00000048 */
	uint64_t scratch0;			/* 0x00000050 */
	uint64_t scratch1;			/* 0x00000058 */
	uint64_t scratch2;			/* 0x00000060 */
	uint64_t ibuf_01;			/* 0x00000068 */
	uint64_t ibuf_2;			/* 0x00000070 */
	uint64_t dbg0;				/* 0x00000078 */
	uint64_t dbg1;				/* 0x00000080 */
	uint64_t pc_stack0;			/* 0x00000088 */
	uint64_t pc_stack1;			/* 0x00000090 */
	uint64_t pc_stack2;			/* 0x00000098 */
	uint64_t id_flags;			/* 0x000000a0 */
	uint64_t data0;				/* 0x000000a8 */
	uint64_t memory_reloc;			/* 0x000000b0 */
	uint64_t i2c_e_param[3];		/* 0x000000b8 *
						 * 0x000000c0 *
						 * 0x000000c8 */
	/** end of architected register set */

	uint64_t priv[4];			/* private data */
} pore_state_t;

/**
 * @brief pore_extract is used to extract the current state of the
 * model. Using those functions will not cause register read/write
 * side effects.
 *
 * @param [in] p     reference to pore_model
 * @param [in] s     reference to the pore_state structure which needs to be
 *                   provided by the caller.
 * @return           0 on success, else negative error code
 */
int pore_extractState (pore_model_t p, pore_state_t *s);

/**
 * @brief pore_install is used to isntall the current state of the
 * model. Using those functions will not cause register read/write
 * side effects.
 *
 * @param [in] p     reference to pore_model
 * @param [in] s     reference to the pore_state structure which needs to be
 *                   provided by the caller.
 * @return           0 on success, else negative error code
 */
int pore_installState (pore_model_t p, const pore_state_t *s);

/**
 * @brief Print out model status and registers. This function is
 * mainly intended for debugging the model.
 *
 * @param [in] p     reference to pore_model
 */
void pore_dump (pore_model_t p);

/**
 * @brief pore_get|setpriv are used to store private data for
 * Hook and Callbacks. Use the set function to store and the
 * get function to retrieve the data.
 *
 * @param [in] p     reference to pore_model
 * @param [in] priv  private data
 */
void pore_setpriv (pore_model_t p, void *priv);
void *pore_getpriv (pore_model_t p);

/**
 * @brief The instruction hook call back is called whenever a "hook"
 * instruction got decoded.
 */
typedef int  (* instrHook_f)     (pore_model_t p, uint64_t addr, uint32_t im24,
				  uint64_t im64);
/**
 * @brief The read hook call back is called before a read to the PIB
 * or OCI bus-object is done.
 */
typedef int  (* readHook_f)      (pore_model_t p, uint64_t addr);

/**
 * @brief The write hook call back is called before a write to the PIB
 * or OCI bus-object is done.
 */
typedef int  (* writeHook_f)     (pore_model_t p, uint64_t addr);

/**
 * @brief The fetch hook call back is called before a fetch from the
 * PIB or OCI bus-object is done.
 */
typedef int  (* fetchHook_f)     (pore_model_t p, uint64_t addr);

/**
 * @brief The decode call back is called before a fetched instruction
 * gets decoded.
 */
typedef int  (* decodeHook_f)    (pore_model_t p, uint8_t *instr,
				  unsigned int size);
/**
 * @brief waitCallback_f functions will be called when certain events or
 * situations occur within the model. E.g. if a delay is required the
 * outside code has to implement the correct wait time since the model
 * has no knowledge about the time.
 */
typedef void (* waitCallback_f)  (pore_model_t p, uint32_t delay);

/**
 * @brief errorCallback_f is called on an error. There are "normal" as
 * well as "fatal" errors which can occur.
 */
typedef void (* errorCallback_f) (pore_model_t p);

/** pore_bus implementation needs to call some the hook callbacks */
int pore_instrHook (pore_model_t p, uint64_t addr,
		    uint32_t im24,  uint64_t im64);
int pore_readHook  (pore_model_t p, uint64_t addr);
int pore_writeHook (pore_model_t p, uint64_t addr);
int pore_fetchHook (pore_model_t p, uint64_t addr);

/**
 * @brief Hooks will be called with p as parameter. Use
 * pore_set/getpriv to keep internal data. Hooks are expected to
 * return 0 on success. If they do not return 0 the model will stop
 * executing.
 */
int pore_registerHooks(pore_model_t p,
		       instrHook_f  instrHook,
		       readHook_f   readHook,
		       writeHook_f  writeHook,
		       fetchHook_f  fetchHook,
		       decodeHook_f decodeHook);

void pore_set_enableHookInstr(pore_model_t p, int enabled);
int pore_get_enableHookInstr(pore_model_t p);
void pore_set_enableAddressHooks(pore_model_t p, int enabled);
int pore_get_enableAddressHooks(pore_model_t p);

/**
 * @brief Register callback functions.
 *
 * @param [in] p                  reference to pore model
 * @param [in] waitCallback       called when a wait instruction is executed.
 * @param [in] errorCallback      called when an error occurs.
 * @param [in] fatalErrorCallback called when a fatal error occurs.
 */
int pore_registerCallbacks(pore_model_t p,
			   waitCallback_f  waitCallback,
			   errorCallback_f errorCallback,
			   errorCallback_f fatalErrorCallback);

/**
 * @brief Perform model reset.
 * @param [in] p     reference to pore model
 */
int pore_flush_reset(pore_model_t p);

/**
 * @brief Changes the internal branch location to something else. This
 * could be used within hooks if there is need to branch to different
 * code. FIXME Is this really needed? Is this not dangerous and error
 * prone?
 *
 * @param [in] p     reference to pore model
 * @param [in] addr  new program counter
 */
int pore_forceBranch(pore_model_t p, uint64_t addr);

#define PORE_TRACE_ERR	      0x0001 /**< trace error situations */
#define PORE_TRACE_IBUF	      0x0002 /**< trace fetch/decode/execute */
#define PORE_TRACE_BUS	      0x0004 /**< trace bus events */
#define PORE_TRACE_I2C	      0x0008 /**< trace i2c transactions */
#define PORE_TRACE_PIB	      0x0010 /**< trace PIB traffic */
#define PORE_TRACE_MEM	      0x0020 /**< trace OCI/MEM traffic */
#define PORE_TRACE_ALL	     ( PORE_TRACE_ERR  | PORE_TRACE_IBUF |	\
			       PORE_TRACE_BUS  | PORE_TRACE_I2C  |	\
			       PORE_TRACE_PIB  | PORE_TRACE_MEM  )

/**
 * @brief The PORe model supports tracing the execution flow for
 * debugging. Different code areas have individual trace enable
 * bits. To print out the trace the instantiator has to provide a
 * vprintf function which will get called when tracing is enabled.
 *
 * @param [in] p     reference to pore model
 * @param [in] trace bitfield identifying the areas which should be trace.
 */
void pore_set_trace(pore_model_t p, uint64_t trace);
uint64_t pore_get_trace(pore_model_t p);

/**
 * @brief The following function are for easy model operation. They
 * make use of the side effects when writing to the PORe control
 * register to start/stop the engine or to set/clear breakpoints of
 * the program counter PC.
 */

/**
 * @brief Stop a potentially running pore-model via write to
 * PORE_R_CONTROL register.
 *
 * @param [in] p     reference to pore model
 */
int pore_stop(pore_model_t p);

/**
 * @brief Start pore-model via write to PORE_R_CONTROL register.
 *
 * @param [in] p     reference to pore model
 */
int pore_start(pore_model_t p);

/**
 * @brief Set program counter to given address. This involves stopping
 * the engine and setting the program counter via PORE_R_CONTROL
 * register. After calling this funnction the engine will stay
 * stopped.
 *
 * @param [in] p     reference to pore model
 * @param [in] pc    new program counter content
 */
int pore_setPc(pore_model_t p, uint64_t pc);

/**
 * @brief Set a pore-model breakpoint. This is done by using the
 * PORE_R_CONTROL register. When the pore-model hits the breakpoint
 * address it will automatically stop.
 *
 * @param [in] p     reference to pore model
 * @param [in] bp    breakpoint address
 */
int pore_setBreakpoint(pore_model_t p, uint64_t bp);

/**
 * @brief Enable/disable the trap instruction by setting the
 * appropriate bit in the PORE_R_CONTROL register.
 *
 * @param [in] p      reference to pore model
 * @param [in] enable 0: disable, 1: enable
 */
int pore_enableTrap(pore_model_t p, int enable);

#ifdef __cplusplus
} /* closing brace for extern "C" */
#endif

#endif	/* __PORE_MODEL_H__ */
