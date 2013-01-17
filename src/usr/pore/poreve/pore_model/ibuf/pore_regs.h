/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/pore_model/ibuf/pore_regs.h $             */
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
#ifndef __PORE_REGS__
#define __PORE_REGS__

/******************************************************************************
 *
 * Virtual PORe Engine
 *
 *****************************************************************************/

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


/* 64-bit in IBM notation:
            11.1111.1111.2222.2222.2233|3333.3333.4444.4444.4455.5555.5555.6666
0123.4567.8901.2345.6789.0123.4567.8901|2345.6789.0123.4567.8901.2345.6789.0123
*/

typedef union {
	struct {
#if (__BYTE_ORDER == __BIG_ENDIAN)
		uint64_t cur_state: 8;
		uint64_t freeze_action: 1;
		uint64_t spare : 3;
		uint64_t stack_pointer : 4;
		uint64_t pc : 48;
#else
		uint64_t pc : 48;
		uint64_t stack_pointer : 4;
		uint64_t spare : 3;
		uint64_t freeze_action: 1;
		uint64_t cur_state: 8;
#endif
	};
	uint64_t val;
} pore_status_reg;

typedef union {
	struct {
#if (__BYTE_ORDER == __BIG_ENDIAN)
		/* bits 0:3 */
		uint64_t start_stop : 1;
		uint64_t continue_step : 1;
		uint64_t skip : 1;
		uint64_t set_pc : 1;
		/* bits 4:7 */
		uint64_t set_tp_scan_clk : 3;
		uint64_t lock_exe_trig : 1;
		/* bits 8:11 */
		uint64_t freeze_mask : 1;
		uint64_t check_parity : 1;
		uint64_t prv_parity : 1;
		uint64_t trap_enable : 1;
		/* bits 12:15 */
		uint64_t narrow_mode_trace : 1;
		uint64_t pore_interruptible : 1;
		uint64_t pore_done_override : 1;
		uint64_t interrupt_sequencer_enabled : 1;
		/* bits 16:63 */
		uint64_t pc_brk_pt : 48;
#else
		uint64_t pc_brk_pt : 48;
		uint64_t interrupt_sequencer_enabled : 1;
		uint64_t pore_done_override : 1;
		uint64_t pore_interruptible : 1;
		uint64_t narrow_mode_trace : 1;
		uint64_t trap_enable : 1;
		uint64_t prv_parity : 1;
		uint64_t check_parity : 1;
		uint64_t freeze_mask : 1;
		uint64_t lock_exe_trig : 1;
		uint64_t set_tp_scan_clk : 3;
		uint64_t set_pc : 1;
		uint64_t skip : 1;
		uint64_t continue_step : 1;
		uint64_t start_stop : 1;

#endif
	};
	uint64_t val;
} pore_control_reg;

#define PORE_RESET_VALID_BITS 0xe000000000000000ull

typedef union {
	struct {
#if (__BYTE_ORDER == __BIG_ENDIAN)
		uint64_t fn_reset : 1;
		uint64_t oci_reset : 1;
		uint64_t restart_sbe_trigger : 1;
		uint64_t reserved0 : 61;
#else
		uint64_t reserved0 : 61;
		uint64_t restart_sbe_trigger : 1;
		uint64_t oci_reset : 1;
		uint64_t fn_reset : 1;
#endif
	};
	uint64_t val;
} pore_reset_reg;

#define PORE_ERROR_MASK_VALID_BITS 0xfffff80000000000ull

typedef union {
	struct {
#if (__BYTE_ORDER == __BIG_ENDIAN)
		uint64_t enable_err_handler0 : 1;
		uint64_t enable_err_handler1 : 1;
		uint64_t enable_err_handler2 : 1;
		uint64_t enable_err_handler3 : 1;

		uint64_t enable_err_handler4 : 1;
		uint64_t enable_err_output0  : 1;
		uint64_t enable_err_output1  : 1;
		uint64_t enable_err_output2  : 1;

		uint64_t enable_err_output3  : 1;
		uint64_t enable_err_output4  : 1;
		uint64_t enable_fatal_error0 : 1;
		uint64_t enable_fatal_error1 : 1;

		uint64_t enable_fatal_error2 : 1;
		uint64_t enable_fatal_error3 : 1;
		uint64_t enable_fatal_error4 : 1;
		uint64_t stop_exe_on_error0  : 1;

		uint64_t stop_exe_on_error1  : 1;
		uint64_t stop_exe_on_error2  : 1;
		uint64_t stop_exe_on_error3  : 1;
		uint64_t stop_exe_on_error4  : 1;

		uint64_t gate_chiplet_offline_err : 1;
		uint64_t _reserved0 : 43;
#else
		uint64_t _reserved0 : 43;
		uint64_t gate_chiplet_offline_err : 1;

		uint64_t stop_exe_on_error4  : 1;
		uint64_t stop_exe_on_error3  : 1;
		uint64_t stop_exe_on_error2  : 1;
		uint64_t stop_exe_on_error1  : 1;

		uint64_t stop_exe_on_error0  : 1;
		uint64_t enable_fatal_error4 : 1;
		uint64_t enable_fatal_error3 : 1;
		uint64_t enable_fatal_error2 : 1;

		uint64_t enable_fatal_error1 : 1;
		uint64_t enable_fatal_error0 : 1;
		uint64_t enable_err_output4  : 1;
		uint64_t enable_err_output3  : 1;

		uint64_t enable_err_output2  : 1;
		uint64_t enable_err_output1  : 1;
		uint64_t enable_err_output0  : 1;
		uint64_t enable_err_handler4 : 1;

		uint64_t enable_err_handler3 : 1;
		uint64_t enable_err_handler2 : 1;
		uint64_t enable_err_handler1 : 1;
		uint64_t enable_err_handler0 : 1;
#endif
	};
	uint64_t val;
} pore_error_mask_reg;

#define PORE_PRV_BASE_ADDRESS_VALID_BITS 0x0000007fffffffffull

typedef union {
	struct {
#if (__BYTE_ORDER == __BIG_ENDIAN)
		uint64_t spare : 25;
		uint64_t mc : 1;
		uint64_t chiplet_id : 6;
		uint64_t reserved0 : 32;
#else
		uint64_t reserved0 : 32;
		uint64_t chiplet_id : 6;
		uint64_t mc : 1;
		uint64_t spare : 25;
#endif
	};
	uint64_t val;
} pore_prv_base_address_reg;

#define PORE_OCI_BASE_ADDRESS_VALID_BITS 0x00003fffffffffffull

typedef union {
	struct {
#if (__BYTE_ORDER == __BIG_ENDIAN)
		uint64_t spare : 18;
		uint64_t oci_mem_route : 14;
		/**
		 * oci_mem_route : 14 results in:
		 *   18:32 chiplet_id : 6
		 *   24:27 pib_master : 4;
		 *   28:31 prv_port_no : 4;
		 */
		uint64_t oci_base_address : 32;
#else
		uint64_t oci_base_address : 32;
		uint64_t oci_mem_route : 14;
		uint64_t spare : 18;
#endif
	};
	uint64_t val;
} pore_oci_base_address_reg;

typedef union {
	struct {
#if (__BYTE_ORDER == __BIG_ENDIAN)
		uint64_t reserved : 16;
		uint64_t memory_space : 16;
		uint64_t table_base_address : 32;
#else
		uint64_t table_base_address : 32;
		uint64_t memory_space : 16;
		uint64_t reserved : 16;
#endif
	};
	uint64_t val;
} pore_table_base_addr_reg;

#define PORE_EXE_TRIGGER_VALID_BITS 0x00fff000ffffffffull

typedef union {
	struct {
#if (__BYTE_ORDER == __BIG_ENDIAN)
		uint64_t reserved : 8;
		uint64_t start_vector : 4;
		uint64_t zeroes : 8;
		uint64_t unused : 12;
		uint64_t mc_chiplet_select_mask : 32;
#else
		uint64_t mc_chiplet_select_mask : 32;
		uint64_t unused : 12;
		uint64_t zeroes : 8;
		uint64_t start_vector : 4;
		uint64_t reserved : 8;
#endif
	};
	uint64_t val;
} pore_exe_trigger_reg;

#define PORE_SCRATCH0_VALID_BITS 0x0fffffff00000000ull

typedef union {
	struct {
#if (__BYTE_ORDER == __BIG_ENDIAN)
		uint64_t zeroes : 8;
		uint64_t scratch0 : 24;
		uint64_t reserved : 32;
#else
		uint64_t reserved : 32;
		uint64_t scratch0 : 24;
		uint64_t zeroes : 8;
#endif
	};
	uint64_t val;
} pore_scratch0_reg;

typedef union {
	struct {
#if (__BYTE_ORDER == __BIG_ENDIAN)
		uint64_t ibuf0 : 32;
		uint64_t ibuf1 : 32;
#else
		uint64_t ibuf1 : 32;
		uint64_t ibuf0 : 32;
#endif
	};
	uint64_t val;
} pore_ibuf_01_reg;

typedef union {
	struct {
#if (__BYTE_ORDER == __BIG_ENDIAN)
		uint64_t ibuf2 : 32;
		uint64_t reserved0 : 32;
#else
		uint64_t reserved0 : 32;
		uint64_t ibuf2 : 32;
#endif
	};
	uint64_t val;
} pore_ibuf_2_reg;

#define PORE_DBG0_VALID_BITS 0xffffffffffff0000ull

typedef union {
	struct {
#if (__BYTE_ORDER == __BIG_ENDIAN)
		uint64_t last_completed_address : 32;
		uint64_t last_acc_parity_fail_ind : 1; /* clearOnAnyWrite */
		uint64_t last_ret_code_prv : 3;	       /* clearOnAnyWrite */
		uint64_t i2c_bad_status_0 : 1;	       /* clearOnAnyWrite */
		uint64_t i2c_bad_status_1 : 1;	       /* clearOnAnyWrite */
		uint64_t i2c_bad_status_2 : 1;	       /* clearOnAnyWrite */
		uint64_t i2c_bad_status_3 : 1;	       /* clearOnAnyWrite */
		uint64_t interrupt_counter : 8;	       /* ROX */
		uint64_t spare : 16;		       /* clearOnAnyWrite */
#else
		uint64_t spare : 16;
		uint64_t interrupt_counter : 8;	       /* ROX */
		uint64_t i2c_bad_status_3 : 1;	       /* clearOnAnyWrite */
		uint64_t i2c_bad_status_2 : 1;	       /* clearOnAnyWrite */
		uint64_t i2c_bad_status_1 : 1;	       /* clearOnAnyWrite */
		uint64_t i2c_bad_status_0 : 1;	       /* clearOnAnyWrite */
		uint64_t last_ret_code_prv : 3;
		uint64_t last_acc_parity_fail_ind : 1;
		uint64_t last_completed_address : 32;
#endif
	};
	uint64_t val;
} pore_dbg0_reg;

#define PORE_DBG1_VALID_BITS 0xfffffffffffffffdull

typedef union {
	struct {
#if (__BYTE_ORDER == __BIG_ENDIAN)
		uint64_t pc_last_access : 48;
		uint64_t oci_master_rd_parity_err : 1;
		uint64_t last_ret_code_oci : 3;
		uint64_t bad_instr_parity : 1;
		uint64_t invalid_instr_code : 1;
		uint64_t pc_overflow_underrun : 1;
		uint64_t bad_scan_crc : 1;
		uint64_t pc_stack_ovflw_undrn_err : 1;
		uint64_t instruction_fetch_error : 1;
		uint64_t invalid_instruction_operand : 1;
		uint64_t invalid_instruction_path : 1;
		uint64_t invalid_start_vector : 1;
		uint64_t fi2c_protocol_hang : 1;
		uint64_t spare : 1;
		uint64_t debug_regs_locked : 1;
#else
		uint64_t debug_regs_locked : 1;
		uint64_t spare : 1;
		uint64_t fi2c_protocol_hang : 1;
		uint64_t invalid_start_vector : 1;
		uint64_t invalid_instruction_path : 1;
		uint64_t invalid_instruction_operand : 1;
		uint64_t instruction_fetch_error : 1;
		uint64_t pc_stack_ovflw_undrn_err : 1;
		uint64_t bad_scan_crc : 1;
		uint64_t pc_overflow_underrun : 1;
		uint64_t invalid_instr_code : 1;
		uint64_t bad_instr_parity : 1;
		uint64_t last_ret_code_oci : 3;
		uint64_t oci_master_rd_parity_err : 1;
		uint64_t pc_last_access : 48;
#endif
	};
	uint64_t val;
} pore_dbg1_reg;

#define PORE_PC_STACK0_VALID_BITS 0xffffffffffff001full
#define PORE_PC_STACK1_VALID_BITS 0xffffffffffff0000ull
#define PORE_PC_STACK2_VALID_BITS 0xffffffffffff0000ull

typedef union {
	struct {
#if (__BYTE_ORDER == __BIG_ENDIAN)
		uint64_t pc_stack : 48;
		uint64_t reserved0 : 11;
		uint64_t set_stack_pointer : 1;	/* clearOnAnyWrite */
		uint64_t new_stack_pointer : 4;	/* clearOnAnyWrite */
#else
		uint64_t new_stack_pointer : 4;	/* clearOnAnyWrite */
		uint64_t set_stack_pointer : 1;	/* clearOnAnyWrite */
		uint64_t reserved0 : 11;
		uint64_t pc_stack : 48;
#endif
	};
	uint64_t val;
} pore_pc_stack0_reg;

#define PORE_ID_FLAGS_VALID_BITS 0xffffffffffffff0full

typedef union {
	struct {
#if (__BYTE_ORDER == __BIG_ENDIAN)
		uint64_t reserved0 : 32;	/* 0..31 */
		uint64_t pib_parity_fail : 1;	/* 32 */
		uint64_t pib_status : 3;	/* 33..35 */
		uint64_t oci_parity_fail : 1;	/* 36 */
		uint64_t oci_status : 3;	/* 37..39 */
		uint64_t reserved1 : 8;		/* 40..47 */
		uint64_t ugt : 1;		/* 48 unsigned greater than */
		uint64_t ult : 1;		/* 49 unsigned less than */
		uint64_t sgt : 1;		/* 50 signed greater than */
		uint64_t slt : 1;		/* 51 signed smaller than */
		uint64_t c : 1;			/* 52 carry */
		uint64_t o : 1;			/* 53 overflow */
		uint64_t n : 1;			/* 54 negative */
		uint64_t z : 1;			/* 55 zero flag */
		uint64_t reserved2 : 4;		/* 56..59 */
		uint64_t ibuf_id : 4;		/* 60..63 */
#else
		uint64_t ibuf_id : 4;
		uint64_t reserved2 : 4;
		uint64_t z : 1;
		uint64_t n : 1;
		uint64_t o : 1;
		uint64_t c : 1;
		uint64_t slt : 1;
		uint64_t sgt : 1;
		uint64_t ult : 1;
		uint64_t ugt : 1;
		uint64_t reserved1 : 8;
		uint64_t oci_status : 3;
		uint64_t oci_parity_fail : 1;
		uint64_t pib_status : 3;
		uint64_t pib_parity_fail : 1;
		uint64_t reserved0 : 32;
#endif
	};
	uint64_t val;
} pore_id_flags_reg;

#define PORE_MEMORY_RELOC_VALID_BITS 0x00000003fffff000ull

typedef union {
	struct {
#if (__BYTE_ORDER == __BIG_ENDIAN)
		uint64_t reserved0 : 30;
		uint64_t memory_reloc_region : 2;
		uint64_t memory_reloc_base : 20;
		uint64_t reserved1 : 12;
#else
		uint64_t reserved1 : 12;
		uint64_t memory_reloc_base : 20;
		uint64_t memory_reloc_region : 2;
		uint64_t reserved0 : 30;
#endif
	};
	uint64_t val;
} pore_memory_reloc_reg;

#define PORE_DATA0_VALID_BITS 0xffffffff00000000ull

#define PORE_I2C_E0_PARAM_VALID_BITS 0xff3f7fff00000000ull
#define PORE_I2C_E1_PARAM_VALID_BITS 0xff3f7ff000000000ull
#define PORE_I2C_E2_PARAM_VALID_BITS 0xff3f7ff000000000ull

typedef union {
	struct {
#if (__BYTE_ORDER == __BIG_ENDIAN)
		uint64_t i2c_engine_identifier : 4;
		uint64_t i2c_engine_address_range : 4;
		uint64_t reserved1 : 2;
		uint64_t i2c_engine_port : 6;
		uint64_t reserved2 : 1;
		uint64_t i2c_engine_device_id : 7;
		uint64_t i2c_engine_speed : 8;
		uint64_t reserved0 : 32;
#else
		uint64_t reserved0 : 32;
		uint64_t i2c_engine_speed : 8;
		uint64_t i2c_engine_device_id : 7;
		uint64_t reserved2 : 1;
		uint64_t i2c_engine_port : 6;
		uint64_t reserved1 : 2;
		uint64_t i2c_engine_address_range : 4;
		uint64_t i2c_engine_identifier : 4;

#endif
	};
	uint64_t val;
} pore_i2c_en_param_reg;

typedef union {
	struct {
#if (__BYTE_ORDER == __BIG_ENDIAN)
		uint32_t r_n_w : 1;
		uint32_t bc  : 1;
		uint32_t chiplet_select : 6;
		uint32_t res0 : 4;
		uint32_t port : 4;
		uint32_t region_select : 8;
		uint32_t res1 : 4;
		uint32_t type_sel_bin : 4;
#else
		uint32_t type_sel_bin : 4;
		uint32_t res1 : 4;
		uint32_t region_select : 8;
		uint32_t port : 4;
		uint32_t res0 : 4;
		uint32_t chiplet_select : 6;
		uint32_t bc  : 1;
		uint32_t r_w : 1;
#endif
	};
	uint32_t val;
} shift_eng_cmd_reg;

typedef union {
	struct {
#if (__BYTE_ORDER == __BIG_ENDIAN)
		uint64_t region_select : 8;
		uint64_t res0 : 8;
		uint64_t type_sel_unary : 16;
		uint64_t res1 : 32;
#else
		uint64_t res1 : 32;
		uint64_t type_sel_unary : 16;
		uint64_t res0 : 8;
		uint64_t region_select : 8;
#endif
	};
	uint64_t val;
} scan_type_select_reg;

/* Scan controller register */
#define SCAN_REGION_OFFSET	0x0007
#define SCAN_DATA_OFFSET(cDR, uDR, bits) (0x8000	      |	\
					  ((cDR) & 0x1) << 14 |	\
					  ((uDR) & 0x1) << 13 |	\
					  ((bits) & 0x3f))

#ifndef FASTI2C_BASE_OFFSET
/* #  define FASTI2C_BASE_OFFSET    0x00008000 */
#  define FASTI2C_BASE_OFFSET    0x00000000 /* new default */
#endif

#define FASTI2C_CONTROL_OFFSET   (FASTI2C_BASE_OFFSET + 0x00000000)
#define FASTI2C_RESET_OFFSET     (FASTI2C_BASE_OFFSET + 0x00000001)
#define FASTI2C_STATUS_OFFSET    (FASTI2C_BASE_OFFSET + 0x00000002)
#define FASTI2C_DATA_OFFSET      (FASTI2C_BASE_OFFSET + 0x00000003)

typedef union {
	struct {
#if (__BYTE_ORDER == __BIG_ENDIAN)
		uint64_t with_start : 1;
		uint64_t with_address : 1;
		uint64_t read_continue : 1;
		uint64_t with_stop : 1;
		uint64_t data_length : 4;
		uint64_t device_address : 7;
		uint64_t read_not_write : 1;

		uint64_t speed : 2;
		uint64_t port_number : 5;
		uint64_t address_range : 3;
		uint64_t _reserved0 : 6;

		uint64_t data0 : 8;
		uint64_t data1 : 8;
		uint64_t data2 : 8;
		uint64_t data3 : 8;
#else
		uint64_t data3 : 8;
		uint64_t data2 : 8;
		uint64_t data1 : 8;
		uint64_t data0 : 8;
		uint64_t _reserved0 : 6;
		uint64_t address_range : 3;
		uint64_t port_number : 5;
		uint64_t speed : 2;
		uint64_t read_not_write : 1;
		uint64_t device_address : 7;
		uint64_t data_length : 4;
		uint64_t with_stop : 1;
		uint64_t read_continue : 1;
		uint64_t with_address : 1;
		uint64_t with_start : 1;
#endif
	};
	uint64_t val;
} fasti2c_control_reg;

typedef union {
	struct {
#if (__BYTE_ORDER == __BIG_ENDIAN)
		uint64_t pib_address_invalid : 1; /* 0 */
		uint64_t pib_write_invalid : 1;	/* 1 */
		uint64_t pib_read_invalid : 1; /* 2 */
		uint64_t pib_address_parity_error : 1; /* 3 */
		uint64_t pib_parity_error : 1; /* 4 */
		uint64_t lb_parity_error : 1; /* 5 */
		uint64_t read_data : 32; /* 6..38 */
		uint64_t _reserved0 : 6; /* 39..45 */
		uint64_t i2c_macro_busy : 1; /* 46 */
		uint64_t i2c_invalid_command : 1;
		uint64_t i2c_parity_error : 1;
		uint64_t i2c_back_end_overrun_error : 1;
		uint64_t i2c_back_end_access_error : 1;
		uint64_t i2c_arbitration_lost : 1;
		uint64_t i2c_nack_received : 1;
		uint64_t i2c_data_request : 1;
		uint64_t i2c_command_complete : 1;
		uint64_t i2c_stop_error : 1;
		uint64_t i2c_port_busy : 1;
		uint64_t i2c_interface_busy : 1;
		uint64_t i2c_fifo_entry_count : 8;
#else
		uint64_t i2c_fifo_entry_count : 8;
		uint64_t i2c_interface_busy : 1;
		uint64_t i2c_port_busy : 1;
		uint64_t i2c_stop_error : 1;
		uint64_t i2c_command_complete : 1;
		uint64_t i2c_data_request : 1;
		uint64_t i2c_nack_received : 1;
		uint64_t i2c_arbitration_lost : 1;
		uint64_t i2c_back_end_access_error : 1;
		uint64_t i2c_back_end_overrun_error : 1;
		uint64_t i2c_parity_error : 1;
		uint64_t i2c_invalid_command : 1;
		uint64_t i2c_macro_busy : 1;
		uint64_t _reserved0 : 6;
		uint64_t read_data : 32;
		uint64_t lb_parity_error : 1;
		uint64_t pib_parity_error : 1;
		uint64_t pib_address_parity_error : 1;
		uint64_t pib_read_invalid : 1;
		uint64_t pib_write_invalid : 1;
		uint64_t pib_address_invalid : 1;
#endif
	};
	uint64_t val;
} fasti2c_status_reg;

/* Different address definitions */
typedef union {
	struct {
#if (__BYTE_ORDER == __BIG_ENDIAN)
		uint64_t reserved : 16;
		uint64_t memorySpace : 16;
		uint64_t offset : 32;
#else
		uint64_t offset : 32;
		uint64_t memorySpace : 16;
		uint64_t reserved : 16;
#endif
	};
	uint64_t val;
} _PoreAddress;

typedef union {
	struct {
#if (__BYTE_ORDER == __BIG_ENDIAN)
		uint64_t reserved : 33;
		uint64_t mc : 1;
		uint64_t chiplet_id : 6;
		uint64_t pibms_id : 4;
		uint64_t prv_port : 4;
		uint64_t local_addr : 16;
#else
		uint64_t local_addr : 16;
		uint64_t prv_port : 4;
		uint64_t pibms_id : 4;
		uint64_t chiplet_id : 6;
		uint64_t mc : 1;
		uint64_t reserved : 33;
#endif
	};
	uint64_t val;
} PibAddress;

#ifdef __cplusplus
} /* closing brace for extern "C" */
#endif

#endif /* __PORE_REGS__ */
