# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/kernel/softpatch_p8.S $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2011,2013
#
# p1
#
# Object Code Only (OCO) source materials
# Licensed Internal Code Source Materials
# IBM HostBoot Licensed Internal Code
#
# The source code for this program is not published or otherwise
# divested of its trade secrets, irrespective of what has been
# deposited with the U.S. Copyright Office.
#
# Origin: 30
#
# IBM_PROLOG_END_TAG
.include "kernel/ppcconsts.S"

/** @fn p8_softpatch_denorm_assist
 *  @brief Performs denormalization assistance for floating point operations.
 *
 *  Called by the softpatch exception when a denormalization assistance is
 *  detected.  The procedure is to run a denormalization instruction through
 *  the VSX unit on each floating point register so that the floating point
 *  instruction which took the exception may execute correctly.
 *
 *  @param[in] r3 - Pointer to task's context_fp_t structure.
 *
 *  Destroys the data in r4/r5.  This is safe by the ABI since these are
 *  parameter registers which are otherwise unused by this function.
 */
.global p8_softpatch_denorm_assist
p8_softpatch_denorm_assist:
    mfmsr  r4                  # Load the MSR
    oris   r5,r4,0x2080        # Turn on FP,VSX available
    mtmsrd r5                  # Set the MSR
                               # Load the FPRs from task context.
    lfd f0, TASK_FPR_0(r3)
    lfd f1, TASK_FPR_1(r3)
    lfd f2, TASK_FPR_2(r3)
    lfd f3, TASK_FPR_3(r3)
    lfd f4, TASK_FPR_4(r3)
    lfd f5, TASK_FPR_5(r3)
    lfd f6, TASK_FPR_6(r3)
    lfd f7, TASK_FPR_7(r3)
    lfd f8, TASK_FPR_8(r3)
    lfd f9, TASK_FPR_9(r3)
    lfd f10, TASK_FPR_10(r3)
    lfd f11, TASK_FPR_11(r3)
    lfd f12, TASK_FPR_12(r3)
    lfd f13, TASK_FPR_13(r3)
    lfd f14, TASK_FPR_14(r3)
    lfd f15, TASK_FPR_15(r3)
    lfd f16, TASK_FPR_16(r3)
    lfd f17, TASK_FPR_17(r3)
    lfd f18, TASK_FPR_18(r3)
    lfd f19, TASK_FPR_19(r3)
    lfd f20, TASK_FPR_20(r3)
    lfd f21, TASK_FPR_21(r3)
    lfd f22, TASK_FPR_22(r3)
    lfd f23, TASK_FPR_23(r3)
    lfd f24, TASK_FPR_24(r3)
    lfd f25, TASK_FPR_25(r3)
    lfd f26, TASK_FPR_26(r3)
    lfd f27, TASK_FPR_27(r3)
    lfd f28, TASK_FPR_28(r3)
    lfd f29, TASK_FPR_29(r3)
    lfd f30, TASK_FPR_30(r3)
    lfd f31, TASK_FPR_31(r3)

    xvcpsgndp f0,f0,f0         # Normalize all of the FPR contents
    xvcpsgndp f1,f1,f1
    xvcpsgndp f2,f2,f2
    xvcpsgndp f3,f3,f3
    xvcpsgndp f4,f4,f4
    xvcpsgndp f5,f5,f5
    xvcpsgndp f6,f6,f6
    xvcpsgndp f7,f7,f7
    xvcpsgndp f8,f8,f8
    xvcpsgndp f9,f9,f9
    xvcpsgndp f10,f10,f10
    xvcpsgndp f11,f11,f11
    xvcpsgndp f12,f12,f12
    xvcpsgndp f13,f13,f13
    xvcpsgndp f14,f14,f14
    xvcpsgndp f15,f15,f15
    xvcpsgndp f16,f16,f16
    xvcpsgndp f17,f17,f17
    xvcpsgndp f18,f18,f18
    xvcpsgndp f19,f19,f19
    xvcpsgndp f20,f20,f20
    xvcpsgndp f21,f21,f21
    xvcpsgndp f22,f22,f22
    xvcpsgndp f23,f23,f23
    xvcpsgndp f24,f24,f24
    xvcpsgndp f25,f25,f25
    xvcpsgndp f26,f26,f26
    xvcpsgndp f27,f27,f27
    xvcpsgndp f28,f28,f28
    xvcpsgndp f29,f29,f29
    xvcpsgndp f30,f30,f30
    xvcpsgndp f31,f31,f31
                                # Save the FPRs to task context.
    stfd f0, TASK_FPR_0(r3)
    stfd f1, TASK_FPR_1(r3)
    stfd f2, TASK_FPR_2(r3)
    stfd f3, TASK_FPR_3(r3)
    stfd f4, TASK_FPR_4(r3)
    stfd f5, TASK_FPR_5(r3)
    stfd f6, TASK_FPR_6(r3)
    stfd f7, TASK_FPR_7(r3)
    stfd f8, TASK_FPR_8(r3)
    stfd f9, TASK_FPR_9(r3)
    stfd f10, TASK_FPR_10(r3)
    stfd f11, TASK_FPR_11(r3)
    stfd f12, TASK_FPR_12(r3)
    stfd f13, TASK_FPR_13(r3)
    stfd f14, TASK_FPR_14(r3)
    stfd f15, TASK_FPR_15(r3)
    stfd f16, TASK_FPR_16(r3)
    stfd f17, TASK_FPR_17(r3)
    stfd f18, TASK_FPR_18(r3)
    stfd f19, TASK_FPR_19(r3)
    stfd f20, TASK_FPR_20(r3)
    stfd f21, TASK_FPR_21(r3)
    stfd f22, TASK_FPR_22(r3)
    stfd f23, TASK_FPR_23(r3)
    stfd f24, TASK_FPR_24(r3)
    stfd f25, TASK_FPR_25(r3)
    stfd f26, TASK_FPR_26(r3)
    stfd f27, TASK_FPR_27(r3)
    stfd f28, TASK_FPR_28(r3)
    stfd f29, TASK_FPR_29(r3)
    stfd f30, TASK_FPR_30(r3)
    stfd f31, TASK_FPR_31(r3)

    mtmsrd r5;                  # Reset the MSR
    blr

