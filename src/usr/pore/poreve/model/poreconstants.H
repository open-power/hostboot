/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pore/poreve/model/poreconstants.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
#ifndef __VSBE_PORECONSTANTS_H
#define __VSBE_PORECONSTANTS_H

// $Id: poreconstants.H,v 1.3 2011/10/14 21:35:19 bcbrock Exp $

/// \file poreconstants.H
/// \brief Constants associated with the The PORE hardware interface classes

#include <stdint.h>

namespace vsbe {

    /// PORE instruction buffer IDs
    ///
    /// These are the PORE instruction buffer IDs that PORE programs can read
    /// out as the low-order 4 bits of the IDFLAGS register.  This allows a
    /// PORE program to determine which engine it is running on. Most
    /// importantly, the Ibuf ID is required by various constructors and
    /// methods as there are hardware differences between the various engines.
    enum PoreIbufId {
        PORE_GPE0 = 0,
        PORE_GPE1 = 1,
        PORE_SLW  = 8,
        PORE_SBE  = 4
    };

    /// \defgroup pore_status PORE Hardware Abstract Status
    ///
    /// The PoreModel produces an abstract status return code that succinctly
    /// captures the state of the machine.  The status consists of an
    /// OR-combination of the PORE_STATUS_* flags.  The status flags
    /// effectively enumerate all of the reasons that the PORE engine may be
    /// physically or abstractly halted or unrunnable.  A status of 0
    /// indicates that the PORE engine is runnable and ready to execute the
    /// next instruction. Since several of these conditions could be true at
    /// once, the status is represented as an OR-mask rather than as a C++
    /// enum.
    ///
    /// Most of the status conditions require a specific action to clear the
    /// status and allow instruction execution to resume.  Some conditions are
    /// considered fatal and require a reset() to continue.
    ///
    /// \note The status is currently compiled only by examining the PORE
    /// state that is visible in the hardware.  Currently this makes it
    /// difficult to determine unequivically why the engine stopped.  Change
    /// requests are pending for the hardware to correct this.  If it remains
    /// difficult to determine from hardware status precisely why the PORE
    /// engine is stopped, then we will have to decide whether to include APIs
    /// in the virtual environment to transmit this information, and perhaps
    /// diverge the capabilities of the virtual PORE from the real PORE.

    /// @{

    /// The PORE executed a WAIT 0 (HALT) instruction
    ///
    /// This condition is determined by noting that the PORE is stopped, and
    /// the instruction currently visible in the IBUF0 register is WAIT 0.  To
    /// continue, the user should either restart() the machine or write a
    /// value into the EXE_TRIGGER register.  Simply continuing from a HALT
    /// would resume execution at the instruction following the HALT, and the
    /// PoreModel::run() method will not continue execution as long as
    /// this condition is true.
    const int PORE_STATUS_HALTED = 0x01;

    /// The PORE halted due to an architected error
    ///
    /// This bit is determined by seeing the PORE is stopped and examining bit
    /// 63 of PIBMS_DBG. 'Debug registers are locked'. To continue, the user
    /// should restart () the machine.  The PoreModel::run() method will not
    /// continue execution as long as this condition is true.
    const int PORE_STATUS_ERROR_HALT = 0x02;

    /// The PORE is in the hardware STOP state
    ///
    /// This flag indicates that bit 0 of the PORE control register is set,
    /// signifying that the hardware is stopped.  The stop may be due to a
    /// halt, error halt, trap or address breakpoint, or may have been
    /// commanded by the user. The PoreModel::run() method will normally
    /// continue execution from this condition unless specifically prohibited
    /// by another status bit.
    const int PORE_STATUS_HARDWARE_STOP = 0x04;

    /// The PORE stopped due to an address breakpoint
    ///
    /// This condition is determined by noting that the PORE engine is stopped
    /// in the ABR state, and either 1) the current PC is equal to the visible
    /// address breakpoint address, or 2) the PORE_STATUS_TRAP condition is
    /// not met.  The second condition would arise if the address breakpoint
    /// hit on a taken branch, because in the case the PC will end up pointing
    /// to the branch target. If this status is set, the PoreModel::run()
    /// method will generate the correct sequence to continue execution.
    const int PORE_STATUS_BREAKPOINT = 0x08;

    /// The PORE hit an enabled trap
    ///
    /// This condition is determined by noting that the PORE engine is stopped
    /// in the ABR state, the TRAP instruction is enabled, and the instruction
    /// currently visible in the IBUF0 register is a TRAP.  If this status is
    /// set, the PoreModel::run() method will generate the correct sequence to
    /// continue execution.
    const int PORE_STATUS_TRAP = 0x10;
    
    /// The PORE model experienced a modeling error
    ///
    /// This conditon only exists in the virtual PORE model, and indicates
    /// that the \a iv_ModelError attribute of the PoreModel is non-0.  The
    /// only ways to continue from this error are to restart() the machine or
    /// to call the clearModelError() method, as the PoreModel::run() method
    /// will not continue execution as long as this condition is true.
    const int PORE_STATUS_MODEL_ERROR = 0x20;

    /// A debug stop
    ///
    /// This flag indicates that application code requested a stop by using
    /// the stop() method, and the getStopCode() method can be used to recover
    /// the argument of the stop() call. This is a debugging aid for use by
    /// hooks, and does not actually stop the hardware.  The PoreModel::run()
    /// method will normally continue execution from this condition unless
    /// specifically prohibited by another status bit.
    const int PORE_STATUS_DEBUG_STOP = 0x40;

    /// @};


    /// \enum PoreRegisterOffset
    ///
    /// These are the 8-byte aligned address offsets for 4- and 8-byte
    /// register accesses.  For 4-byte accesses to the low-order word of an
    /// 8-byte register, add 4 to the offset.
    ///
    /// These are the OCI address-space offsets used for the PORE-SLW,
    /// PORE-GPE0 and PORE-GPE1 models. The PORE-SBE has a PIB interface, and
    /// in that case the PIB slave (SCOM) offsets are actually these offsets /
    /// 8.  For consistency across all models we use the OCI offset below for
    /// all PORE instances however, including the PORE-SBE.
    ///
    /// The PORE engine contains a number of visible registers, however there
    /// remains state that is not visible but must be saved/restored to
    /// checkpoint the engine.  The final entry in the enumeration defines the
    /// total size (in bytes) of the PORE state.  This constant is used in the
    /// definition of the PoreState struct.  The area between
    /// SIZEOF_VISIBLE_PORE_STATE and SIZEOF_PORE_STATE is model-specific,
    /// programmer-invisible data.  Currently there is no established protocol
    /// for moving states between different software models or between
    /// software and hardware models due to the presence of non-architected
    /// state.  The hidden state variables are enumerated for consistency with
    /// the fapiPoreVe text-based register save/restore methodology.
    ///
    /// The register names appearing below are taken from the PORE hardware
    /// specification.
    enum PoreRegisterOffset {
        // Visible registers
	PORE_STATUS                = 0x00,
	PORE_CONTROL               = 0x08,
	PORE_RESET                 = 0x10,
	PORE_ERROR_MASK            = 0x18,
	PORE_PRV_BASE_ADDR0        = 0x20,
	PORE_PRV_BASE_ADDR1        = 0x28,
	PORE_OCI_MEMORY_BASE_ADDR0 = 0x30,
	PORE_OCI_MEMORY_BASE_ADDR1 = 0x38,
	PORE_TABLE_BASE_ADDR       = 0x40,
	PORE_EXE_TRIGGER           = 0x48,
	PORE_EXE_TRIGGER_HI        = 0x4c, // Programmer-writable bits 32:63
	PORE_SCRATCH0              = 0x50,
	PORE_SCRATCH1              = 0x58,
	PORE_SCRATCH2              = 0x60,
	PORE_IBUF_01               = 0x68,
	PORE_IBUF_2                = 0x70,
	PORE_DBG0                  = 0x78,
	PORE_DBG1                  = 0x80,
	PORE_PC_STACK0             = 0x88,
	PORE_PC_STACK1             = 0x90,
	PORE_PC_STACK2             = 0x98,
	PORE_ID_FLAGS              = 0xa0,
	PORE_DATA0                 = 0xa8,
        PORE_MEM_RELOC             = 0xb0,
        PORE_I2C_E0_PARAM          = 0xb8,
        PORE_I2C_E1_PARAM          = 0xc0,
        PORE_I2C_E2_PARAM          = 0xc8,
        // The size of the visible state
        SIZEOF_VISIBLE_PORE_STATE  = 0xd0,
        // Add hidden state variables
        PORE_HIDDEN_STATE_0        = 0xd0,
        PORE_HIDDEN_STATE_1        = 0xd8,
        PORE_HIDDEN_STATE_2        = 0xe0,
        PORE_HIDDEN_STATE_3        = 0xe8,
        PORE_HIDDEN_STATE_4        = 0xf0,
        SIZEOF_PORE_STATE          = 0xf8, 
        // An illegal offset, for robust error checking
        PORE_ILLEGAL               = 0xff
    };

    /// \enum PoreRegisterEncoding
    ///
    /// These are the 4-bit encodings used in the PORE instruction set to
    /// identify the programmaer-visible registers.  These are the register
    /// names and encodings as defined in the PGAS manual.  Abstract register
    /// names are defined as extra encodings.  Every register named here must
    /// also be mapped in PORE_REGISTER_MAP.
    enum PoreRegisterEncoding {
        // These are "real" register encodings
        PORE_P0    = 0x0,
        PORE_P1    = 0x1,
        PORE_A0    = 0x2,
        PORE_A1    = 0x3,
        PORE_CTR   = 0x4,
        PORE_D0    = 0x5,
        PORE_D1    = 0x6,
        PORE_EMR   = 0x7,
        PORE_ETR   = 0x9,
        PORE_SPRG0 = 0xa,
        PORE_PC    = 0xe,
        PORE_IFR   = 0xf,
        // These are model-only encodings
        PORE_CIA   = 0x10
    };

    /// This constant maps a PoreRegisterEncoding to the PoreRegisterOffset of
    /// the register that contains the programmer-visible or abstract register.
    const PoreRegisterOffset PORE_REGISTER_MAP[] = {
        // These are "real" register encodings
        PORE_PRV_BASE_ADDR0,          // 0x0
        PORE_PRV_BASE_ADDR1,          // 0x1
	PORE_OCI_MEMORY_BASE_ADDR0,   // 0x2
	PORE_OCI_MEMORY_BASE_ADDR1,   // 0x3
        PORE_SCRATCH0,                // 0x4
        PORE_SCRATCH1,                // 0x5
        PORE_SCRATCH2,                // 0x6
        PORE_ERROR_MASK,              // 0x7
        PORE_ILLEGAL,                 // 0x8
        PORE_EXE_TRIGGER,             // 0x9
        PORE_DATA0,                   // 0xa
        PORE_ILLEGAL,                 // 0xb
        PORE_ILLEGAL,                 // 0xc
        PORE_ILLEGAL,                 // 0xd
        PORE_STATUS,                  // 0xe
        PORE_ID_FLAGS,                // 0xf
        // These are model-only encodings
        PORE_DBG1                     // 0x10      
    };

    /// 'Infinity' for the purposes of the Pore run() method.
    const uint64_t RUN_UNLIMITED = 0xffffffffffffffffull;

    /// The 'Stop Code' used by setPc() when it stops the processor.
    const int STOP_CODE_SET_PC = -1;

    /// A bogus address to install as the breakpoint address to effectively
    /// disable PORE address breakpoints.
    const uint64_t PORE_UNBREAKABLE_ADDRESS = 0xfffffffffffcull;
};

#endif  // __VSBE_PORECONSTANTS_H
