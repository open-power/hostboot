.section .text

.global _syscall0
.global _syscall1
.global _syscall2
.global _syscall3
.global _syscall4
.global _syscall5
.global _syscall6
.global _syscall7

_syscall0:
_syscall1:
_syscall2:
_syscall3:
_syscall4:
_syscall5:
_syscall6:
_syscall7:
    sc
    blr
