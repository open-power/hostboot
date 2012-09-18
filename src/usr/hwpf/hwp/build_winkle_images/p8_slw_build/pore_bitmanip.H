/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/build_winkle_images/proc_slw_build/pore_bitmanip.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
#ifndef __PORE_BITMANIP_H
#define __PORE_BITMANIP_H

/// \file pore_bitmanip.H
/// \brief Standard bit-manipulation macros (C and Assembler) for PORE code

#ifdef __ASSEMBLER__
#include "pgas.h"
#endif

#include "fapi_sbe_common.H"

/// \defgroup be64_bits Bit manipulation for 64-bit Big-Endian values
///
/// \note These macros only work in the assembler context because we build our
/// assemblers to do 64-bit arithmetic, which is required for PORE assembly.
///
/// @{

/// Create a multi-bit mask of \a n bits starting at bit \a b
#define BITS(b, n) ((ULL(0xffffffffffffffff) << (64 - (n))) >> (b))

/// Create a single bit mask at bit \a b
#define BIT(b) BITS((b), 1)

#ifdef __ASSEMBLER__

/// Check b, n for legality

        .macro  ..checkbits, b:req, n=1
        .if     (((\b) < 0) || ((\b) > 63))
        .error  "Illegal bit number, must be 0,...,63"
        .endif
        .if     (((\n) < 1) || ((\n) > 64))
        .error  "Illegal number of bits, must be 1,...,64"
        .endif
        .if     (((\b) + (\n)) > 64)
        .error  "Illegal (b + n), must be <= 64"
        .endif
        .endm


/// Set a single bit in a data register
///
/// \param[in,out] data A Data register (D0/D1), modified by setting bit \a b
/// to 1.
/// 
/// \param[in] b The bit position (64-bit, big-endian) to set

        .macro  setbit, data:req, b:req
        ..checkbits (\b)
        ori     (\data), (\data), BIT(\b)
        .endm


/// Set multiple contiguous bits in a data register
///
/// \param[in,out] data A Data register (D0/D1), modified by setting \a n bits
/// starting at bit \a b to 1.
/// 
/// \param[in] b The bit position (64-bit, big-endian) to begin
///
/// \param[in] n The number of contiguous bits to set

        .macro  setbits, data:req, b:req, n:req
        ..checkbits (\b), (\n)
        ori     (\data), (\data), BITS((\b), (\n))
        .endm


/// Read-modify-write a SCOM register by setting a bit
///
/// \param[in,out] data A Data register (D0/D1), first loaded with the value
/// of the SCOM register, then modified by setting bit \a b to 1. The final
/// value of \a data is then stored back to the SCOM register.
///
/// \param[in] address A 32-bit SCOM address
///
/// \param[in] prv A pervasive base register (P0/P1) which contains the
/// chiplet ID + multicast bit to use with \a address
///
/// \param[in] b The bit position (64-bit, big-endian) to set

        .macro  setbitscom data:req, address:req, prv:req, b:req
        ..checkbits (\b)
        .if     ((\data) == D0)
        bsi     D0, (\address), (\prv), BIT(\b)
        .else
        ld      (\data), (\address), (\prv)
        setbit  (\data), (\b)
        std     (\data), (\address), (\prv)
        .endif
        .endm


/// Read-modify-write a SCOM register by setting a range of contiguous bits
///
/// \param[in,out] data A Data register (D0/D1), first loaded with the value
/// of the SCOM register, then modified by setting \a n bits starting at bit
/// \a b to 1. The final value of \a data is then stored back to the SCOM
/// register.
///
/// \param[in] address A 32-bit SCOM address
///
/// \param[in] prv A pervasive base register (P0/P1) which contains the
/// chiplet ID + multicast bit to use with \a address
///
/// \param[in] b The bit position (64-bit, big-endian) to set
///
/// \param[in] n The number of contiguous bits to set

        .macro  setbitsscom data:req, address:req, prv:req, b:req, n:req
        ..checkbits (\b), (\n)
        .if     ((\data) == D0)
        bsi     D0, (\address), (\prv), BITS((\b),(\n))
        .else
        ld      (\data), (\address), (\prv)
        setbits (\data), (\b), (\n)
        std     (\data), (\address), (\prv)
        .endif
        .endm

/// Set any number of individual bits in a data register
///
/// \param[in] data The Data register (D0/D1) to modify
///
/// \param[in] ...bits 1 or more bit positions (64-bit, big-endian) to set
///
/// For example:
///
/// - setbitmult D0, 1, 3, 13
///
/// sets bits 1, 3 and 13 of D0.

        .macro	setbitmult, data:req, bits:vararg
	..setbitmult 0, (\data), \bits
	.endm

	// The best I can come up with to implement this macro currently is to
	// use a special symbol to accumulate the bit masks. I don't know of a
	// way to do this recursively.

	.macro	..accumulate_bitmask, symbol:req, bits:vararg
	.ifb	\bits
	.error	"At least 1 bit position must be specified"
	.endif
	.set	\symbol, 0
	.irp	b, \bits
	.if	(((\b) < 0) || ((\b) > 63))
	.error	"Illegal bit position, must be 0 <= b < 63"
	.endif
	.set	\symbol, (BIT(\b) | \symbol)
	.endr
	.endm

        .macro	..setbitmult, invert:req, data:req, bits:vararg
	..accumulate_bitmask __SETBITMULT__, \bits
	.if	(\invert)
	andi	(\data), (\data), ~__SETBITMULT__
	.else
	ori	(\data), (\data), __SETBITMULT__
	.endif
	.endm

	
/// Read-modify-write a SCOM register by setting any number of individual bits
///
/// \param[in,out] data A Data register (D0/D1), first loaded with the value
/// of the SCOM register, then modified by setting any number (> 0) of
/// individual bits.
///
/// \param[in] address A 32-bit SCOM address
///
/// \param[in] prv A pervasive base register (P0/P1) which contains the
/// chiplet ID + multicast bit to use with \a address
///
/// \param[in] ...bits 1 or more bit positions (64-bit, big-endian) to set
///
/// For example:
///
/// - setbitmultscom D0, OCC_CONTROL_0x0006B000, P0, 1, 3, 13
///
/// sets bits 1, 3 and 13 of OCC_CONTROL.

        .macro	setbitmultscom, data:req, address:req, prv:req, bits:vararg
	..setbitmultscom 0, (\data), (\address), (\prv), \bits
	.endm

	.macro	..setbitmultscom, \
		invert:req, data:req, address:req, prv:req, bits:vararg
	..accumulate_bitmask __SETBITMULTSCOM__, \bits
	.if	((\data) == D0)
	
	.if	(\invert)
	bci	D0, (\address), (\prv), __SETBITMULTSCOM__
	.else
	bsi	D0, (\address), (\prv), __SETBITMULTSCOM__
	.endif

	.else

	.if	(\invert)
	ldandi	(\data), (\address), (\prv), ~__SETBITMULTSCOM__
	.else
	ld	(\data), (\address), (\prv)
	ori	(\data), (\data), __SETBITMULTSCOM__
	.endif
	std	(\data), (\address), (\prv)

	.endif	
	.endm
	

/// Clear a single bit in a data register
///
/// This macro is the bit-clearing analogue of the \c setbit macro

        .macro  clrbit, data:req, b:req
        ..checkbits (\b)
        andi    (\data), (\data), ~BIT(\b)
        .endm


/// Clear multiple contiguous bits in a data register
///
/// This macro is the bit-clearing analogue of the \c setbits macro


        .macro  clrbits, data:req, b:req, n:req
        ..checkbits (\b), (\n)
        andi    (\data), (\data), ~BITS((\b), (\n))
        .endm


/// Read-modify-write a SCOM register by clearing a bit
///
/// This macro is the bit-clearing analogue of the \c setbitscom macro

        .macro  clrbitscom data:req, address:req, prv:req, b:req
        ..checkbits (\b)
        .if     ((\data) == D0)
        bci     D0, (\address), (\prv), BIT(\b)
        .else
        ld      (\data), (\address), (\prv)
        clrbit  (\data), (\b)
        std     (\data), (\address), (\prv)
        .endif
        .endm


/// Read-modify-write a SCOM register by clearing a range of contiguous bits
///
/// This macro is the bit-clearing analogue of the \c setbitsscom macro

        .macro  clrbitsscom, data:req, address:req, prv:req, b:req, n:req
        ..checkbits (\b), (\n)
        .if     ((\data) == D0)
        bci     D0, (\address), (\prv), BITS((\b), (\n))
        .else
        ld      (\data), (\address), (\prv)
        clrbits (\data), (\b), (\n)
        std     (\data), (\address), (\prv)
        .endif
        .endm


/// Clear any number of individual bits in a data register
///
/// This macro is the bit-clearing analogue of the \c setbitmult macro

	.macro	clrbitmult, data:req, bits:vararg
	..setbitmult 1, (\data), \bits
	.endm


/// Read-modify-write a SCOM register by clearing any number of individual bits
///
/// This macro is the bit-clearing analogue of the \c setbitmultscom macro

        .macro	clrbitmultscom, data:req, address:req, prv:req, bits:vararg
	..setbitmultscom 1, (\data), (\address), (\prv), \bits
	.endm


/// Extract and right-justify an unsigned bit field
///
/// \param[out] dest The destination Data register (D0/D1) to receive the
/// right-justified unsigned bit field.  
///
/// \param[in] src The source Data register (D0/D1) that contains the unsigned
/// bit field to extract.
///
/// \param[in] b The bit positon (64-bit, big-endian) where the bit field
/// begins. 
///
/// \param[in] n The number of contiguous bits beginning at bit \a b to
/// extract. 
///
/// The execution of this macro computes:
///
/// - dest[64-n:63] <- src[b:b+n-1]
/// - dest[0:64-n] <- 0
///
/// Note that the \a dest and \a src registers may be the same Data register.

        .macro  extractbits, dest:req, src:req, b:req, n:req
        ..checkbits (\b), (\n)
        extrdi  (\dest), (\src), (\n), (\b)
        .endm


/// Destructively insert a right-justified immediate value into a bit field
///
/// \param[out] dest The destination Data register (D0/D1) to be modified.
///
/// \param[in] b The bit positon (64-bit, big-endian) where the bit field
/// begins. 
///
/// \param[in] n The number of contiguous bits beginning at bit \a b to
/// modify
///
/// The execution of this macro computes:
///
/// - dest <- (dest & ~BITS(b, n)) | ((imm & BITS(64 - n, n)) << (64 - n - b))

        .macro  insertbits, dest:req, b:req, n:req, imm:req
        ..checkbits (\b), (\n)
        andi    (\dest), (\dest), ~BITS((\b), (\n))
        ori     (\dest), (\dest), \
                (((\imm) & BITS(64 - (\n), (\n))) << ((64 - (\n) - (\b))))
        .endm
        

/// Poll for a bit to be set in a SCOM register with timeout
///
/// \param[in] dest A Data register (D0/D1) to use for the polling
///
/// \param[in] address A 32-bit SCOM address
///
/// \param[in] prv A Pervasive Chiplet Id register (P0/P1) containing the
/// chiplet ID and multicast bit to use with the \a address
///
/// \param[in] b The bit number of the bit to poll
///
/// \param[in] count The number (count > 0) of times to poll for the bit.  If
/// the bit is not set the \a count-th time the SCOM is read then the error
/// action occurs (see below). The maximum legal value is 0x1000000.
///
/// \param[in] delay The number of PORE clock cycles (delay >= 0) to wait
/// between polls of the SCOM register.  Specify a delay of 0 to avoid waiting
/// between polls. There is no waiting before the first poll, therefore the
/// WAIT is only executed \a count - 1 times in the worst case. The maximum
/// legal value is 0xffffff. The PORE engines run at nest / 4 normally, but at
/// the reference frequency during the early IPL.
///
/// \param[in] error A branch target (symbol) in the event of error (see
/// below).
///
/// This macro polls a SCOM register for a single set bit with a programmable
/// timeout, branching to an error handler in the event of a timeout.  This
/// macro always uses the \c CTR register for the poll count.  Therefore if
/// the CTR is currently in use the caller will need to save the current
/// contents of CTR to another register prior to invoking this macro.
///
/// In the event of a polling timeout the code will branch to the \a
/// error target.  Prior to the branch, the \a dest register will be loaded
/// with the PC to help diagnose the error.

        .macro  pollbitset, dest:req, address:req, prv:req, b:req \
                count:req, delay:req, error:req
        ..pollbit branz, (\dest), (\address), (\prv), (\b), \
                (\count), (\delay), (\error)
        .endm

        
/// Poll for a bit to be clear in a SCOM register with timeout
///
/// This macro is analogous to the pollbitset macro

        .macro  pollbitclr, dest:req, address:req, prv:req, b:req \
                count:req, delay:req, error:req
        ..pollbit braz, (\dest), (\address), (\prv), (\b), \
                (\count), (\delay), (\error)
        .endm

        
// Implements pollbitset and pollbitclr - the only difference is 'branz' vs
// 'braz'.

        .macro  ..pollbit, instr:req, dest:req, address:req, prv:req, b:req \
                count:req, delay:req, error:req

        .if     (((\count) <= 0) || ((\count) > 0x1000000))
        .error  "The poll count must satisfy 0 < count <= 0x1000000"
        .endif
        .if     (((\delay) < 0) || ((\delay) >= 0x1000000))
        .error  "The wait delay must satisfy 0 <= delay < 0x1000000"
        .endif

        ls      CTR, ((\count) - 1)
        bra     7665249f
7665248:
	.if	((\delay) != 0)
        waits   (\delay)
	.endif
7665249:
        ldandi  (\dest), (\address), (\prv), BIT(\b)
        \instr  (\dest), 7665250f
        loop    7665248b
        mr      (\dest), PC
        braa    (\error)        
7665250:
        
        .endm


/// Test and branch if a bit is set in a data register
///
/// \param[out] scratch This Data register (D0/D1) is destroyed to perform the
/// comparison. This may be the same as the \a data register if the \a data is
/// no longer needed after the comparison.
///
/// \param[in] data This Data register (D0/D1) contains the data to be tested.
///
/// \param[in] b The bit number (64-bit, big-endian) to test
///
/// \param[in] target The branch target in the event that bit \a b is set in
/// \a data.

	.macro	ifbitset, scratch:req, data:req, b:req, target:req
	..checkbits (\b)
	andi	(\scratch), (\data), BIT(\b)
	branz	(\scratch), (\target)
	.endm


/// Test and branch is a bit is clear in a data register
///
/// This macro is the bit-clear-test analogue of the ifbitset macro 

	.macro	ifbitclr, scratch:req, data:req, b:req, target:req
	..checkbits (\b)
	andi	(\scratch), (\data), BIT(\b)
	braz	(\scratch), (\target)
	.endm
             

/// Read a SCOM register and branch if a bit is set
///
/// \param[out] scratch This Data register (D0/D1) is destroyed to perform the
/// comparison. This may be the same as the \a data register if the \a data is
/// no longer needed after the comparison.
///
/// \param[in] data This Data register (D0/D1) is first loaded from the SCOM
/// \a address, then tested for the bit being set. If \a scratch and \a data
/// are different register then this register will hold the original SCOM data
/// after the execution of the macro.
///
/// \param[in] address A 32-bit SCOM address
///
/// \param[in] prv A Pervasive Chiplet Id register (P0/P1) containing the
/// chiplet ID and multicast bit to use with the \a address
///
/// \param[in] b The bit number (64-bit, big-endian) to test
///
/// \param[in] target The branch target in the event that bit \a b is set in
/// \a data.
			
	.macro	ifbitsetscom, scratch:req, data:req, address:req, prv:req, \
		b:req, target:req
	..checkbits (\b)
	.if	((\scratch) == (\data))
	ldandi	(\scratch), (\address), (\prv), BIT(\b)
	.else
	ld	(\data), (\address), (\prv)
	andi	(\scratch), (\data), BIT(\b)
	.endif	
	branz	(\scratch), (\target)
	.endm


/// Read a SCOM register and branch if a bit is clear
///
/// This is the bit-clear-test analogue of the ifbitsetscom macro

	.macro	ifbitclrscom, scratch:req, data:req, address:req, prv:req, \
		b:req, target:req
	..checkbits (\b)
	.if	((\scratch) == (\data))
	ldandi	(\scratch), (\address), (\prv), BIT(\b)
	.else
	ld	(\data), (\address), (\prv)
	andi	(\scratch), (\data), BIT(\b)
	.endif	
	braz	(\scratch), (\target)
	.endm
	
	
/// @}

#endif  // __ASSEMBLER__

#endif  // __PORE_BITMANIP_H
