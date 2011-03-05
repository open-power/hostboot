.include "kernel/ppcconsts.S"

.global hal_p7_terminate_immediate
hal_p7_terminate_immediate:
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
