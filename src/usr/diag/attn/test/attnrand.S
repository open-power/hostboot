#   IBM_PROLOG_BEGIN_TAG
#   This is an automatically generated prolog.
# 
#   $Source: src/usr/diag/attn/test/attnrand.S $
# 
#   IBM CONFIDENTIAL
# 
#   COPYRIGHT International Business Machines Corp. 2012
# 
#   p1
# 
#   Object Code Only (OCO) source materials
#   Licensed Internal Code Source Materials
#   IBM HostBoot Licensed Internal Code
# 
#   The source code for this program is not published or other-
#   wise divested of its trade secrets, irrespective of what has
#   been deposited with the U.S. Copyright Office.
# 
#   Origin: 30
# 
#   IBM_PROLOG_END
.include "kernel/ppcconsts.S"

.section .text

.global generate_random 

generate_random:
    li r3, 0
    rlwimi 0x1b,0x1b,0x0,0x6,0x10
    blr
