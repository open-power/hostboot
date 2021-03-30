# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/include/kernel/ppcconsts.S $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2010,2021
# [+] International Business Machines Corp.
#
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
# implied. See the License for the specific language governing
# permissions and limitations under the License.
#
# IBM_PROLOG_END_TAG
#*--------------------------------------------------------------------*#
#*  Register Constants                                                *#
#*--------------------------------------------------------------------*#

                .set r0,0
                .set r1,1
                .set r2,2
                .set r3,3
                .set r4,4
                .set r5,5
                .set r6,6
                .set r7,7
                .set r8,8
                .set r9,9
                .set r10,10
                .set r11,11
                .set r12,12
                .set r13,13
                .set r14,14
                .set r15,15
                .set r16,16
                .set r17,17
                .set r18,18
                .set r19,19
                .set r20,20
                .set r21,21
                .set r22,22
                .set r23,23
                .set r24,24
                .set r25,25
                .set r26,26
                .set r27,27
                .set r28,28
                .set r29,29
                .set r30,30
                .set r31,31

                .set f0,0
                .set f1,1
                .set f2,2
                .set f3,3
                .set f4,4
                .set f5,5
                .set f6,6
                .set f7,7
                .set f8,8
                .set f9,9
                .set f10,10
                .set f11,11
                .set f12,12
                .set f13,13
                .set f14,14
                .set f15,15
                .set f16,16
                .set f17,17
                .set f18,18
                .set f19,19
                .set f20,20
                .set f21,21
                .set f22,22
                .set f23,23
                .set f24,24
                .set f25,25
                .set f26,26
                .set f27,27
                .set f28,28
                .set f29,29
                .set f30,30
                .set f31,31

#*--------------------------------------------------------------------*#
#*  CR Register Constants                                             *#
#*--------------------------------------------------------------------*#

                .set cr0,0
                .set cr1,1
                .set cr2,2
                .set cr3,3
                .set cr4,4
                .set cr5,5
                .set cr6,6
                .set cr7,7
                .set lt,0
                .set gt,1
                .set eq,2
                .set so,3

#*--------------------------------------------------------------------*#
#*  SR Register Constants                                             *#
#*--------------------------------------------------------------------*#

                .set sr0,0
                .set sr1,1
                .set sr2,2
                .set sr3,3
                .set sr4,4
                .set sr5,5
                .set sr6,6
                .set sr7,7
                .set sr8,8
                .set sr9,9
                .set sr10,10
                .set sr11,11
                .set sr12,12
                .set sr13,13
                .set sr14,14
                .set sr15,15

#*--------------------------------------------------------------------*#
#*  SPR Constants                                                     *#
#*--------------------------------------------------------------------*#

                .set XER,1
                .set LR,8
                .set CTR,9
                .set DSISR,18
                .set DAR,19
                .set DEC,22
                .set SDR1,25
                .set SRR0,26
                .set SRR1,27
                .set CFAR,28
                .set HFSCR,190
                .set TB,268
                .set SPRG0,272
                .set SPRG1,273
                .set SPRG2,274
                .set SPRG3,275
                .set SPRC,276
                .set SPRD,277
                .set EAR,282
                .set TBL,284
                .set TBU,285
                .set PVR,287
                .set HSPRG0,304
                .set HSPRG1,305
                .set HDSISR,306
                .set HDEC,310
                .set HRMOR,313
                .set HSRR0,314
                .set HSRR1,315
                .set LPIDR,319
                .set HMER,336
                .set PTCR,464
                .set HID0,1008
                .set PIR, 1023
                .set URMOR,505
                .set USRR0,506
                .set USRR1,507
                .set USPRG0,496
                .set USPRG1,497

#*--------------------------------------------------------------------*#
#*  Task offset Constants                                             *#
#*--------------------------------------------------------------------*#

.set TASK_CPUPTR, 0
.set TASK_STACKPTR, TASK_CPUPTR+8
.set TASK_NIP, TASK_STACKPTR+8
.set TASK_GPR_0, TASK_NIP+8
.set TASK_GPR_1, TASK_GPR_0+8
.set TASK_GPR_2, TASK_GPR_1+8
.set TASK_GPR_3, TASK_GPR_2+8
.set TASK_GPR_4, TASK_GPR_3+8
.set TASK_GPR_5, TASK_GPR_4+8
.set TASK_GPR_6, TASK_GPR_5+8
.set TASK_GPR_7, TASK_GPR_6+8
.set TASK_GPR_8, TASK_GPR_7+8
.set TASK_GPR_9, TASK_GPR_8+8
.set TASK_GPR_10, TASK_GPR_9+8
.set TASK_GPR_11, TASK_GPR_10+8
.set TASK_GPR_12, TASK_GPR_11+8
.set TASK_GPR_13, TASK_GPR_12+8
.set TASK_GPR_14, TASK_GPR_13+8
.set TASK_GPR_15, TASK_GPR_14+8
.set TASK_GPR_16, TASK_GPR_15+8
.set TASK_GPR_17, TASK_GPR_16+8
.set TASK_GPR_18, TASK_GPR_17+8
.set TASK_GPR_19, TASK_GPR_18+8
.set TASK_GPR_20, TASK_GPR_19+8
.set TASK_GPR_21, TASK_GPR_20+8
.set TASK_GPR_22, TASK_GPR_21+8
.set TASK_GPR_23, TASK_GPR_22+8
.set TASK_GPR_24, TASK_GPR_23+8
.set TASK_GPR_25, TASK_GPR_24+8
.set TASK_GPR_26, TASK_GPR_25+8
.set TASK_GPR_27, TASK_GPR_26+8
.set TASK_GPR_28, TASK_GPR_27+8
.set TASK_GPR_29, TASK_GPR_28+8
.set TASK_GPR_30, TASK_GPR_29+8
.set TASK_GPR_31, TASK_GPR_30+8
.set TASK_LR, TASK_GPR_31+8
.set TASK_CR, TASK_LR+8
.set TASK_CTR, TASK_CR+8
.set TASK_XER, TASK_CTR+8
.set TASK_MSR_MASK, TASK_XER+8

.set TASK_FP_CONTEXT, TASK_MSR_MASK+8
.set TASK_FPR_0, 0
.set TASK_FPR_1, TASK_FPR_0+8
.set TASK_FPR_2, TASK_FPR_1+8
.set TASK_FPR_3, TASK_FPR_2+8
.set TASK_FPR_4, TASK_FPR_3+8
.set TASK_FPR_5, TASK_FPR_4+8
.set TASK_FPR_6, TASK_FPR_5+8
.set TASK_FPR_7, TASK_FPR_6+8
.set TASK_FPR_8, TASK_FPR_7+8
.set TASK_FPR_9, TASK_FPR_8+8
.set TASK_FPR_10, TASK_FPR_9+8
.set TASK_FPR_11, TASK_FPR_10+8
.set TASK_FPR_12, TASK_FPR_11+8
.set TASK_FPR_13, TASK_FPR_12+8
.set TASK_FPR_14, TASK_FPR_13+8
.set TASK_FPR_15, TASK_FPR_14+8
.set TASK_FPR_16, TASK_FPR_15+8
.set TASK_FPR_17, TASK_FPR_16+8
.set TASK_FPR_18, TASK_FPR_17+8
.set TASK_FPR_19, TASK_FPR_18+8
.set TASK_FPR_20, TASK_FPR_19+8
.set TASK_FPR_21, TASK_FPR_20+8
.set TASK_FPR_22, TASK_FPR_21+8
.set TASK_FPR_23, TASK_FPR_22+8
.set TASK_FPR_24, TASK_FPR_23+8
.set TASK_FPR_25, TASK_FPR_24+8
.set TASK_FPR_26, TASK_FPR_25+8
.set TASK_FPR_27, TASK_FPR_26+8
.set TASK_FPR_28, TASK_FPR_27+8
.set TASK_FPR_29, TASK_FPR_28+8
.set TASK_FPR_30, TASK_FPR_29+8
.set TASK_FPR_31, TASK_FPR_30+8
.set TASK_FPSCR, TASK_FPR_31+8

.set TASK_TLS_CONTEXT, TASK_FP_CONTEXT+8

.set CPU_KERNEL_STACK, 0
.set CPU_KERNEL_STACK_BOTTOM, CPU_KERNEL_STACK+8
.set CPU_CPUID, CPU_KERNEL_STACK_BOTTOM+8
.set CPU_STATUS, CPU_CPUID+4

.set CPU_STATUS_MASTER, 0
.set CPU_STATUS_ACTIVE, CPU_STATUS_MASTER+1
.set CPU_STATUS_WINKLED, CPU_STATUS_ACTIVE+1
