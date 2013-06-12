/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/include/pgp_common.h $                       */
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
// $Id: pgp_common.h,v 1.2 2012/08/13 16:11:58 stillgs Exp $

#ifndef __PGP_COMMON_H__
#define __PGP_COMMON_H__

/// \file pgp_common.h
/// \brief Common header for SSX and PMX versions of PgP
///
/// This header is maintained as part of the SSX port for PgP, but needs to be
/// physically present in the PMX area to allow dropping PMX code as a whole
/// to other teams.

// -*- WARNING: This file is maintained as part of SSX.  Do not edit in -*-
// -*- the PMX area as your edits will be lost.                         -*-

#ifndef __ASSEMBLER__
#include <stdint.h>
#endif

////////////////////////////////////////////////////////////////////////////
// Configuration
////////////////////////////////////////////////////////////////////////////

#define PGP_NCORES  16
#define PGP_NMCS     8
#define PGP_NCENTAUR 8
#define PGP_NTHREADS 8

////////////////////////////////////////////////////////////////////////////
// Clocking
////////////////////////////////////////////////////////////////////////////

/// PgP nest runs at 2.4 GHz
///
/// \todo This drives the pervasive domain clocking, and there is some idea to
/// make this frequency variable.  If so then this will be a system-specific
/// constant.  Thus it's a good idea to keep as much timing information as
/// possible relative to the nest frequency.
///
/// \bug This constant needs to be read and handled as an attribute
#define NEST_FREQUENCY_KHZ 2400000

/// Pervasive clock is nest / 4
#define PERVASIVE_FREQUENCY_HZ (NEST_FREQUENCY_KHZ * 250)

/// PgP/OCC uses the pervasive frequency directly to drive PPC405 timers
#define SSX_TIMEBASE_FREQUENCY_HZ PERVASIVE_FREQUENCY_HZ

/// The pervasive hang timer divider used for the OCB
#define OCB_TIMER_DIVIDER 512

/// The OCB timer frequency
///
/// The frequency is based on a pervasive hang timer that is formed by
/// dividing the nominal 600 MHz pervasive clock by 512 to yield a 1.1719 MHz
/// clock (853ns period).  This is a dynamic configuration option, but is
/// assumed to be initialized as the given frequency.  If not, then firmware
/// will have to do some SCOMs to figure out what the real divider and
/// frequency are.
#define OCB_TIMER_FREQUENCY_HZ (PERVASIVE_FREQUENCY_HZ / OCB_TIMER_DIVIDER)


/// The pervasive hang timer divider used for the PMC
#define PMC_HANG_PULSE_DIVIDER (32 * 1024)

/// The PMC Hang Pulse Frequency
///
/// The frequency is based on a pervasive hang timer that is formed by
/// dividing the nominal 600 MHz pervasive clock by 32K to yield a 18.3 KHz
/// clock (54.6us period).  This is a dynamic configuration option, but is
/// assumed to be initialized as the given frequency.  If not, then firmware
/// will have to do some SCOMs to figure out what the real divider and
/// frequency are.
#define PMC_HANG_PULSE_FREQUENCY_HZ \
    (PERVASIVE_FREQUENCY_HZ / PMC_HANG_PULSE_DIVIDER)


////////////////////////////////////////////////////////////////////////////
// OCI
////////////////////////////////////////////////////////////////////////////

// OCI Master Id assigments - required for PBA slave programming.  These Ids
// also appear as bits 12:15 of the OCI register space addresses of the OCI
// registers for each device that contains OCI-addressable registers (GPE,
// PMC, PBA, SLW and OCB).

#define OCI_MASTER_ID_PORE_GPE 0
#define OCI_MASTER_ID_PMC      1
#define OCI_MASTER_ID_PBA      2
#define OCI_MASTER_ID_UNUSED   3
#define OCI_MASTER_ID_PORE_SLW 4
#define OCI_MASTER_ID_OCB      5
#define OCI_MASTER_ID_OCC_ICU  6
#define OCI_MASTER_ID_OCC_DCU  7


////////////////////////////////////////////////////////////////////////////
// IRQ
////////////////////////////////////////////////////////////////////////////

// The OCB interrupt controller consists of 2 x 32-bit controllers.  Unlike
// PPC ASICs, the OCB controllers are _not_ cascaded.  The combined
// controllers are presented to the application as if there were a single
// 64-bit interrupt controller, while the code underlying the abstraction
// manipulates the 2 x 32-bit controllers independently.
//
// Note that the bits named *RESERVED* are actually implemented in the
// controller, but the interrupt input is tied low. That means they can also
// be used as IPI targets. Logical bits 32..63 are not implemented.

#define PGP_IRQ_DEBUGGER                        0 /* 0x00 */
#define PGP_IRQ_TRACE_TRIGGER                   1 /* 0x01 */
#define PGP_IRQ_RESERVED_2                      2 /* 0x02 */
#define PGP_IRQ_PBA_ERROR                       3 /* 0x03 */
#define PGP_IRQ_SRT_ERROR                       4 /* 0x04 */
#define PGP_IRQ_PORE_SW_ERROR                   5 /* 0x05 */
#define PGP_IRQ_PORE_GPE0_FATAL_ERROR           6 /* 0x06 */
#define PGP_IRQ_PORE_GPE1_FATAL_ERROR           7 /* 0x07 */
#define PGP_IRQ_PORE_SBE_FATAL_ERROR            8 /* 0x08 */
#define PGP_IRQ_PMC_ERROR                       9 /* 0x09 */
#define PGP_IRQ_OCB_ERROR                      10 /* 0x0a */
#define PGP_IRQ_SPIPSS_ERROR                   11 /* 0x0b */
#define PGP_IRQ_CHECK_STOP                     12 /* 0x0c */
#define PGP_IRQ_PMC_MALF_ALERT                 13 /* 0x0d */
#define PGP_IRQ_ADU_MALF_ALERT                 14 /* 0x0e */
#define PGP_IRQ_EXTERNAL_TRAP                  15 /* 0x0f */
#define PGP_IRQ_OCC_TIMER0                     16 /* 0x10 */
#define PGP_IRQ_OCC_TIMER1                     17 /* 0x11 */
#define PGP_IRQ_PORE_GPE0_ERROR                18 /* 0x12 */
#define PGP_IRQ_PORE_GPE1_ERROR                19 /* 0x13 */
#define PGP_IRQ_PORE_SBE_ERROR                 20 /* 0x14 */
#define PGP_IRQ_PMC_INTERCHIP_MSG_RECV         21 /* 0x15 */
#define PGP_IRQ_RESERVED_22                    22 /* 0x16 */
#define PGP_IRQ_PORE_GPE0_COMPLETE             23 /* 0x17 */
#define PGP_IRQ_PORE_GPE1_COMPLETE             24 /* 0x18 */
#define PGP_IRQ_ADCFSM_ONGOING                 25 /* 0x19 */
#define PGP_IRQ_RESERVED_26                    26 /* 0x1a */
#define PGP_IRQ_PBA_OCC_PUSH0                  27 /* 0x1b */
#define PGP_IRQ_PBA_OCC_PUSH1                  28 /* 0x1c */
#define PGP_IRQ_PBA_BCDE_ATTN                  29 /* 0x1d */
#define PGP_IRQ_PBA_BCUE_ATTN                  30 /* 0x1e */
#define PGP_IRQ_RESERVED_31                    31 /* 0x1f */

#define PGP_IRQ_RESERVED_32                    32 /* 0x20 */
#define PGP_IRQ_RESERVED_33                    33 /* 0x21 */
#define PGP_IRQ_STRM0_PULL                     34 /* 0x22 */
#define PGP_IRQ_STRM0_PUSH                     35 /* 0x23 */
#define PGP_IRQ_STRM1_PULL                     36 /* 0x24 */
#define PGP_IRQ_STRM1_PUSH                     37 /* 0x25 */
#define PGP_IRQ_STRM2_PULL                     38 /* 0x26 */
#define PGP_IRQ_STRM2_PUSH                     39 /* 0x27 */
#define PGP_IRQ_STRM3_PULL                     40 /* 0x28 */
#define PGP_IRQ_STRM3_PUSH                     41 /* 0x29 */
#define PGP_IRQ_RESERVED_42                    42 /* 0x2a */
#define PGP_IRQ_RESERVED_43                    43 /* 0x2b */
#define PGP_IRQ_PMC_VOLTAGE_CHANGE_ONGOING     44 /* 0x2c */
#define PGP_IRQ_PMC_PROTOCOL_ONGOING           45 /* 0x2d */
#define PGP_IRQ_PMC_SYNC                       46 /* 0x2e */
#define PGP_IRQ_PMC_PSTATE_REQUEST             47 /* 0x2f */
#define PGP_IRQ_RESERVED_48                    48 /* 0x30 */
#define PGP_IRQ_RESERVED_49                    49 /* 0x31 */
#define PGP_IRQ_PMC_IDLE_EXIT                  50 /* 0x32 */
#define PGP_IRQ_PORE_SW_COMPLETE               51 /* 0x33 */
#define PGP_IRQ_PMC_IDLE_ENTER                 52 /* 0x34 */
#define PGP_IRQ_RESERVED_53                    53 /* 0x35 */
#define PGP_IRQ_PMC_INTERCHIP_MSG_SEND_ONGOING 54 /* 0x36 */
#define PGP_IRQ_OCI2SPIVID_ONGOING             55 /* 0x37 */
#define PGP_IRQ_PMC_OCB_O2P_ONGOING            56 /* 0x38 */
#define PGP_IRQ_PSSBRIDGE_ONGOING              57 /* 0x39 */
#define PGP_IRQ_PORE_SBE_COMPLETE              58 /* 0x3a */
#define PGP_IRQ_IPI0                           59 /* 0x3b */
#define PGP_IRQ_IPI1                           60 /* 0x3c */
#define PGP_IRQ_IPI2                           61 /* 0x3d */
#define PGP_IRQ_IPI3                           62 /* 0x3e */
#define PGP_IRQ_RESERVED_63                    63 /* 0x3f */


// Note: All standard-product IPI uses are declared here to avoid conflicts
// Validation- and lab-only IPI uses are documented in validation.h

/// The deferred callback queue interrupt
///
/// This IPI is reserved for use of the async deferred callback mechanism.
/// This IPI is used by both critical and noncritical async handlers to
/// activate the deferred callback mechanism.
#define PGP_IRQ_ASYNC_IPI PGP_IRQ_IPI3


// Please keep the string definitions up-to-date as they are used for
// reporting in the Simics simulation.

#define PGP_IRQ_STRINGS(var)                      \
    const char* var[64] = {                       \
        "PGP_IRQ_DEBUGGER",                       \
        "PGP_IRQ_TRACE_TRIGGER",                  \
        "PGP_IRQ_RESERVED_2",                     \
        "PGP_IRQ_PBA_ERROR",                      \
        "PGP_IRQ_SRT_ERROR",                      \
        "PGP_IRQ_PORE_SW_ERROR",                  \
        "PGP_IRQ_PORE_GPE0_FATAL_ERROR",          \
        "PGP_IRQ_PORE_GPE1_FATAL_ERROR",          \
        "PGP_IRQ_PORE_SBE_FATAL_ERROR",           \
        "PGP_IRQ_PMC_ERROR",                      \
        "PGP_IRQ_OCB_ERROR",                      \
        "PGP_IRQ_SPIPSS_ERROR",                   \
        "PGP_IRQ_CHECK_STOP",                     \
        "PGP_IRQ_PMC_MALF_ALERT",                 \
        "PGP_IRQ_ADU_MALF_ALERT",                 \
        "PGP_IRQ_EXTERNAL_TRAP",                  \
        "PGP_IRQ_OCC_TIMER0",                     \
        "PGP_IRQ_OCC_TIMER1",                     \
        "PGP_IRQ_PORE_GPE0_ERROR",                \
        "PGP_IRQ_PORE_GPE1_ERROR",                \
        "PGP_IRQ_PORE_SBE_ERROR",                 \
        "PGP_IRQ_PMC_INTERCHIP_MSG_RECV",         \
        "PGP_IRQ_RESERVED_22",                    \
        "PGP_IRQ_PORE_GPE0_COMPLETE",             \
        "PGP_IRQ_PORE_GPE1_COMPLETE",             \
        "PGP_IRQ_ADCFSM_ONGOING",                 \
        "PGP_IRQ_RESERVED_26",                    \
        "PGP_IRQ_PBA_OCC_PUSH0",                  \
        "PGP_IRQ_PBA_OCC_PUSH1",                  \
        "PGP_IRQ_PBA_BCDE_ATTN",                  \
        "PGP_IRQ_PBA_BCUE_ATTN",                  \
        "PGP_IRQ_RESERVED_31",                    \
        "PGP_IRQ_RESERVED_32",                    \
        "PGP_IRQ_RESERVED_33",                    \
        "PGP_IRQ_STRM0_PULL",                     \
        "PGP_IRQ_STRM0_PUSH",                     \
        "PGP_IRQ_STRM1_PULL",                     \
        "PGP_IRQ_STRM1_PUSH",                     \
        "PGP_IRQ_STRM2_PULL",                     \
        "PGP_IRQ_STRM2_PUSH",                     \
        "PGP_IRQ_STRM3_PULL",                     \
        "PGP_IRQ_STRM3_PUSH",                     \
        "PGP_IRQ_RESERVED_42",                    \
        "PGP_IRQ_RESERVED_43",                    \
        "PGP_IRQ_PMC_VOLTAGE_CHANGE_ONGOING",     \
        "PGP_IRQ_PMC_PROTOCOL_ONGOING",           \
        "PGP_IRQ_PMC_SYNC",                       \
        "PGP_IRQ_PMC_PSTATE_REQUEST",             \
        "PGP_IRQ_RESERVED_48",                    \
        "PGP_IRQ_RESERVED_49",                    \
        "PGP_IRQ_PMC_IDLE_EXIT",                  \
        "PGP_IRQ_PORE_SW_COMPLETE",               \
        "PGP_IRQ_PMC_IDLE_ENTER",                 \
        "PGP_IRQ_RESERVED_53",                    \
        "PGP_IRQ_PMC_INTERCHIP_MSG_SEND_ONGOING", \
        "PGP_IRQ_OCI2SPIVID_ONGOING",             \
        "PGP_IRQ_PMC_OCB_O2P_ONGOING",            \
        "PGP_IRQ_PSSBRIDGE_ONGOING",              \
        "PGP_IRQ_PORE_SBE_COMPLETE",              \
        "PGP_IRQ_IPI0",                           \
        "PGP_IRQ_IPI1",                           \
        "PGP_IRQ_IPI2",                           \
        "PGP_IRQ_IPI3 (ASYNC-IPI)",               \
        "PGP_IRQ_RESERVED_63"                     \
    };


/// This constant is used to define the size of the table of interrupt handler
/// structures as well as a limit for error checking.  The entire 64-bit
/// vector is now in use.

#define PPC405_IRQS 64

#ifndef __ASSEMBLER__

/// This expression recognizes only those IRQ numbers that have named
/// (non-reserved) interrupts in the OCB interrupt controller.

// There are so many invalid interrupts now that it's a slight improvement in
// code size to let the compiler optimize the invalid IRQs to a bit mask for
// the comparison.

#define PGP_IRQ_VALID(irq) \
    ({unsigned __irq = (unsigned)(irq); \
        ((__irq < PPC405_IRQS) &&                               \
         ((PGP_IRQ_MASK64(__irq) &                              \
           (PGP_IRQ_MASK64(PGP_IRQ_RESERVED_2)  |               \
            PGP_IRQ_MASK64(PGP_IRQ_RESERVED_22) |               \
            PGP_IRQ_MASK64(PGP_IRQ_RESERVED_26) |               \
            PGP_IRQ_MASK64(PGP_IRQ_RESERVED_31) |               \
            PGP_IRQ_MASK64(PGP_IRQ_RESERVED_32) |               \
            PGP_IRQ_MASK64(PGP_IRQ_RESERVED_33) |               \
            PGP_IRQ_MASK64(PGP_IRQ_RESERVED_42) |               \
            PGP_IRQ_MASK64(PGP_IRQ_RESERVED_43) |               \
            PGP_IRQ_MASK64(PGP_IRQ_RESERVED_48) |               \
            PGP_IRQ_MASK64(PGP_IRQ_RESERVED_49) |               \
            PGP_IRQ_MASK64(PGP_IRQ_RESERVED_53) |               \
            PGP_IRQ_MASK64(PGP_IRQ_RESERVED_63))) == 0));})

/// This is a 32-bit mask, with big-endian bit (irq % 32) set.
#define PGP_IRQ_MASK32(irq) (((uint32_t)0x80000000) >> ((irq) % 32))

/// This is a 64-bit mask, with big-endian bit 'irq' set.
#define PGP_IRQ_MASK64(irq) (0x8000000000000000ull >> (irq))

#endif  /* __ASSEMBLER__ */


////////////////////////////////////////////////////////////////////////////
// OCB
////////////////////////////////////////////////////////////////////////////

/// The base address of the OCI control register space
#define OCI_REGISTER_SPACE_BASE 0x40000000

/// The base address of the entire PIB port mapped by the OCB.  The
/// OCB-contained PIB registers are based at OCB_PIB_BASE.
#define OCB_PIB_SLAVE_BASE 0x00060000

/// The size of the OCI control register address space
///
/// There are at most 8 slaves, each of which maps 2**16 bytes of register
/// address space.
#define OCI_REGISTER_SPACE_SIZE POW2_32(19)

/// This macro converts an OCI register space address into a PIB address as
/// seen through the OCB direct bridge.
#define OCI2PIB(addr) ((((addr) & 0x0007ffff) >> 3) + OCB_PIB_SLAVE_BASE)


// OCB communication channel constants

#define OCB_INDIRECT_CHANNELS 4

#define OCB_RW_READ  0
#define OCB_RW_WRITE 1

#define OCB_STREAM_MODE_DISABLED 0
#define OCB_STREAM_MODE_ENABLED  1

#define OCB_STREAM_TYPE_LINEAR   0
#define OCB_STREAM_TYPE_CIRCULAR 1

#define OCB_INTR_ACTION_FULL      0
#define OCB_INTR_ACTION_NOT_FULL  1
#define OCB_INTR_ACTION_EMPTY     2
#define OCB_INTR_ACTION_NOT_EMPTY 3

#ifndef __ASSEMBLER__

// These macros select OCB interrupt controller registers based on the IRQ
// number.

#define OCB_OIMR_AND(irq) (((irq) & 0x20) ? OCB_OIMR1_AND : OCB_OIMR0_AND)
#define OCB_OIMR_OR(irq)  (((irq) & 0x20) ? OCB_OIMR1_OR  : OCB_OIMR0_OR)

#define OCB_OISR(irq)     (((irq) & 0x20) ? OCB_OISR1     : OCB_OISR0)
#define OCB_OISR_AND(irq) (((irq) & 0x20) ? OCB_OISR1_AND : OCB_OISR0_AND)
#define OCB_OISR_OR(irq)  (((irq) & 0x20) ? OCB_OISR1_OR  : OCB_OISR0_OR)

#define OCB_OIEPR(irq) (((irq) & 0x20) ? OCB_OIEPR1 : OCB_OIEPR0)
#define OCB_OITR(irq)  (((irq) & 0x20) ? OCB_OITR1  : OCB_OITR0)
#define OCB_OCIR(irq)  (((irq) & 0x20) ? OCB_OCIR1  : OCB_OCIR0)
#define OCB_OUDER(irq) (((irq) & 0x20) ? OCB_OUDER1 : OCB_OUDER0)

#endif  /* __ASSEMBLER__ */


////////////////////////////////////////////////////////////////////////////
// PMC
////////////////////////////////////////////////////////////////////////////

#ifndef __ASSEMBLER__

/// A Pstate type
///
/// Pstates are signed, but our register access macros operate on unsigned
/// values.  To avoid bugs, Pstate register fields should always be extracted
/// to a variable of type Pstate.  If the size of Pstate variables ever
/// changes we will have to revisit this convention.
typedef int8_t Pstate;

/// A DPLL frequency code
///
/// DPLL frequency codes moved from 8 to 9 bits going from P7 to P8
typedef uint16_t DpllCode;

/// A VRM11 VID code
typedef uint8_t Vid11;

#endif  /* __ASSEMBLER__ */

/// The minimum Pstate
#define PSTATE_MIN -128

/// The maximum Pstate
#define PSTATE_MAX 127

/// The minimum \e legal DPLL frequency code
///
/// This is ~1GHz with a 16.6MHz tick frequency.
#define DPLL_MIN 0x03c

/// The maximum DPLL frequency code
#define DPLL_MAX 0x1ff

/// The minimum \a legal (non-power-off) VRM11 VID code
#define VID11_MIN 0x02

/// The maximum \a legal (non-power-off) VRM11 VID code
#define VID11_MAX 0xfd


////////////////////////////////////////////////////////////////////////////
// PCB
////////////////////////////////////////////////////////////////////////////

/// Convert a core chiplet 0 SCOM address to the equivalent address for any
/// other core chiplet.
///
/// Note that it is unusual to address core chiplet SCOMs directly.  Normally
/// this is done as part of a GPE program where the program iterates over core
/// chiplets, using the chiplet-0 address + a programmable offset held in a
/// chiplet address register.  Therefore the only address macro defined is the
/// chiplet-0 address. This macro is used for the rare cases of explicit
/// getscom()/ putscom() to a particular chiplet.

#define CORE_CHIPLET_ADDRESS(addr, core) ((addr) + ((core) << 24))


// PCB Error codes

#define PCB_ERROR_NONE              0
#define PCB_ERROR_RESOURCE_OCCUPIED 1
#define PCB_ERROR_CHIPLET_OFFLINE   2
#define PCB_ERROR_PARTIAL_GOOD      3
#define PCB_ERROR_ADDRESS_ERROR     4
#define PCB_ERROR_CLOCK_ERROR       5
#define PCB_ERROR_PACKET_ERROR      6
#define PCB_ERROR_TIMEOUT           7

// PCB Multicast modes

#define PCB_MULTICAST_OR      0
#define PCB_MULTICAST_AND     1
#define PCB_MULTICAST_SELECT  2
#define PCB_MULTICAST_COMPARE 4
#define PCB_MULTICAST_WRITE   5

/// \defgroup pcb_multicast_groups PCB Multicast Groups
///
/// Technically the multicast groups are programmable; This is the multicast
/// grouping established by proc_sbe_chiplet_init().
///
/// - Group 0 : All functional chiplets (PRV PB XBUS ABUS PCIE TPCEX)
/// - Group 1 : All functional EX chiplets (no cores)
/// - Group 2 : All functional EX chiplets (core only)
/// - Group 3 : All functional chiplets except pervasive (PRV)
///
/// @{

#define MC_GROUP_ALL         0
#define MC_GROUP_EX          1
#define MC_GROUP_EX_CORE     2
#define MC_GROUP_ALL_BUT_PRV 3

/// @}


/// Convert any SCOM address to a multicast address
#define MC_ADDRESS(address, group, mode) \
    (((address) & 0x00ffffff) | ((0x40 | ((mode) << 3) | (group)) << 24))



////////////////////////////////////////////////////////////////////////////
// PBA
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////
// Macros for fields of PBA_MODECTL
////////////////////////////////////

/// The 64KB OCI HTM marker space is enabled by default at 0x40070000
///
/// See the comments for pgp_trace.h

#define PBA_OCI_MARKER_BASE 0x40070000


// SSX Kernel reserved trace addresses, see pgp_trace.h.

#define SSX_TRACE_CRITICAL_IRQ_ENTRY_BASE           0xf000
#define SSX_TRACE_CRITICAL_IRQ_EXIT_BASE            0xf100
#define SSX_TRACE_NONCRITICAL_IRQ_ENTRY_BASE        0xf200
#define SSX_TRACE_NONCRITICAL_IRQ_EXIT_BASE         0xf300
#define SSX_TRACE_THREAD_SWITCH_BASE                0xf400
#define SSX_TRACE_THREAD_SLEEP_BASE                 0xf500
#define SSX_TRACE_THREAD_WAKEUP_BASE                0xf600
#define SSX_TRACE_THREAD_SEMAPHORE_PEND_BASE        0xf700
#define SSX_TRACE_THREAD_SEMAPHORE_POST_BASE        0xf800
#define SSX_TRACE_THREAD_SEMAPHORE_TIMEOUT_BASE     0xf900
#define SSX_TRACE_THREAD_SUSPENDED_BASE             0xfa00
#define SSX_TRACE_THREAD_DELETED_BASE               0xfb00
#define SSX_TRACE_THREAD_COMPLETED_BASE             0xfc00
#define SSX_TRACE_THREAD_MAPPED_RUNNABLE_BASE       0xfd00
#define SSX_TRACE_THREAD_MAPPED_SEMAPHORE_PEND_BASE 0xfe00
#define SSX_TRACE_THREAD_MAPPED_SLEEPING_BASE       0xff00


// Please keep the string definitions up to date as they are used for
// reporting in the Simics simulation.

#define SSX_TRACE_STRINGS(var)                  \
    const char* var[16] = {                     \
        "Critical IRQ Entry             ",      \
        "Critical IRQ Exit              ",      \
        "Noncritical IRQ Entry          ",      \
        "Noncritical IRQ Exit           ",      \
        "Thread Switch                  ",      \
        "Thread Blocked : Sleep         ",      \
        "Thread Unblocked : Wakeup      ",      \
        "Thread Blocked : Semaphore     ",      \
        "Thread Unblocked : Semaphore   ",      \
        "Thread Unblocked : Sem. Timeout",      \
        "Thread Suspended               ",      \
        "Thread Deleted                 ",      \
        "Thread Completed               ",      \
        "Thread Mapped Runnable         ",      \
        "Thread Mapped Semaphore Pend.  ",      \
        "Thread Mapped Sleeping         ",      \
    };


// PBA transaction sizes for the block copy engines

#define PBA_BCE_OCI_TRANSACTION_32_BYTES 0
#define PBA_BCE_OCI_TRANSACTION_64_BYTES 1
#define PBA_BCE_OCI_TRANSACTION_8_BYTES  2


// PBAX communication channel constants

#define PBAX_CHANNELS 2

#define PBAX_INTR_ACTION_FULL      0
#define PBAX_INTR_ACTION_NOT_FULL  1
#define PBAX_INTR_ACTION_EMPTY     2
#define PBAX_INTR_ACTION_NOT_EMPTY 3


////////////////////////////////////////////////////////////////////////////
// VRM
////////////////////////////////////////////////////////////////////////////

// These are the command types recognized by the VRMs

#define VRM_WRITE_VOLTAGE  0x0
#define VRM_READ_STATE     0xc
#define VRM_READ_VOLTAGE   0x3

// Voltage rail designations for the read voltage command
#define VRM_RD_VDD_RAIL    0x0
#define VRM_RD_VCS_RAIL    0x1


////////////////////////////////////////////////////////////////////////////
// OHA
////////////////////////////////////////////////////////////////////////////

// Power proxy trace record idle state encodings.  These encodings are unique
// to the Power proxy trace record.

#define PPT_IDLE_NON_IDLE     0x0
#define PPT_IDLE_NAP          0x1
#define PPT_IDLE_LIGHT_SLEEP  0x2
#define PPT_IDLE_FAST_SLEEP   0x3
#define PPT_IDLE_DEEP_SLEEP   0x4
#define PPT_IDLE_LIGHT_WINKLE 0x5
#define PPT_IDLE_FAST_WINKLE  0x6
#define PPT_IDLE_DEEP_WINKLE  0x7


////////////////////////////////////////////////////////////////////////////
// PC
////////////////////////////////////////////////////////////////////////////

// SPRC numbers for PC counters.  The low-order 3 bits are always defined as
// 0. The address can also be modifed to indicate auto-increment addressing.
// Note that the frequency-sensitivity counters are called "workrate" counters
// in the hardware documentation.

#define SPRN_CORE_INSTRUCTION_DISPATCH         0x200
#define SPRN_CORE_INSTRUCTION_COMPLETE         0x208
#define SPRN_CORE_FREQUENCY_SENSITIVITY_BUSY   0x210
#define SPRN_CORE_FREQUENCY_SENSITIVITY_FINISH 0x218
#define SPRN_CORE_RUN_CYCLE                    0x220
#define SPRN_CORE_RAW_CYCLE                    0x228
#define SPRN_CORE_MEM_HIER_A                   0x230
#define SPRN_CORE_MEM_HIER_B                   0x238
#define SPRN_CORE_MEM_C_LPAR(p)                (0x240 + (8 * (p)))
#define SPRN_WEIGHTED_INSTRUCTION_PROCESSING   0x260
#define SPRN_WEIGHTED_GPR_REGFILE_ACCESS       0x268
#define SPRN_WEIGHTED_VRF_REGFILE_ACCESS       0x270
#define SPRN_WEIGHTED_FLOATING_POINT_ISSUE     0x278
#define SPRN_WEIGHTED_CACHE_READ               0x280
#define SPRN_WEIGHTED_CACHE_WRITE              0x288
#define SPRN_WEIGHTED_ISSUE                    0x290
#define SPRN_WEIGHTED_CACHE_ACCESS             0x298
#define SPRN_WEIGHTED_VSU_ISSUE                0x2a0
#define SPRN_WEIGHTED_FXU_ISSUE                0x2a8

#define SPRN_THREAD_RUN_CYCLES(t)              (0x2b0 + (0x20 * (t)))
#define SPRN_THREAD_INSTRUCTION_COMPLETE(t)    (0x2b8 + (0x20 * (t)))
#define SPRN_THREAD_MEM_HIER_A(t)              (0x2c0 + (0x20 * (t)))
#define SPRN_THREAD_MEM_HIER_B(t)              (0x2c8 + (0x20 * (t)))

#define SPRN_PC_AUTOINCREMENT                  0x400


////////////////////////////////////////////////////////////////////////////
// Centaur
////////////////////////////////////////////////////////////////////////////

// DIMM sensor status codes

/// The next sampling period began before this sensor was read or the master
/// enable is off, or the individual sensor is disabled. If the subsequent
/// read completes on time, this will return to valid reading. Sensor data may
/// be accurate, but stale.  If due to a stall, the StallError FIR will be
/// set.
#define DIMM_SENSOR_STATUS_STALLED 0

/// The sensor data was not returned correctly either due to parity
/// error or PIB bus error code. Will return to valid if the next PIB
/// access to this sensor is valid, but a FIR will be set; Refer to FIR
/// for exact error. Sensor data should not be considered valid while
/// this code is present.
#define DIMM_SENSOR_STATUS_ERROR 1

/// Sensor data is valid, and has been valid since the last time this
/// register was read.
#define DIMM_SENSOR_STATUS_VALID_OLD 2

/// Sensor data is valid and has not yet been read by a SCOM. The status code
/// return to DIMM_SENSOR_STATUS_VALID_OLD after this register is read.
#define DIMM_SENSOR_STATUS_VALID_NEW 3


#endif  /* __PGP_COMMON_H__ */
