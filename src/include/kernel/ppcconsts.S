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
                .set HSRR0,314
                .set HSRR1,315
                .set SPRG0,272
                .set SPRG1,273
                .set SPRG2,274
                .set SPRG3,275
                .set EAR,282
                .set TBL,284
                .set TBU,285
                .set PVR,287
                .set IBAT0U,528
                .set IBAT0L,529
                .set IBAT1U,530
                .set IBAT1L,531
                .set IBAT2U,532
                .set IBAT2L,533
                .set IBAT3U,534
                .set IBAT3L,535

                .set DBAT0U,536
                .set DBAT0L,537
                .set DBAT1U,538
                .set DBAT1L,539
                .set DBAT2U,540
                .set DBAT2L,541
                .set DBAT3U,542
                .set DBAT3L,543

                .set DMISS,976
                .set DCMP,977
                .set HASH1,978
                .set HASH2,979
                .set IMISS,980   
                .set ICMP,981
                .set RPA,982
                .set HID0,1008
                .set IABR,1010

		.set PIR, 1023

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


