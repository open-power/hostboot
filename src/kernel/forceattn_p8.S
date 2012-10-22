/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/forceattn_p8.S $                                   */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2012              */
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
.include "kernel/ppcconsts.S"


.global p8_force_attn
p8_force_attn:
    li r0, 1
    mfspr r9, HID0
    insrdi r9,r0,1,31 	/* Turn on bit 31. */
    sync
    mtspr HID0,r9	/* Enable attentions */
    mfspr r9, HID0
    mfspr r9, HID0
    mfspr r9, HID0
    mfspr r9, HID0
    mfspr r9, HID0
    mfspr r9, HID0
    isync
    attn
    b 0
