#ifndef __KERNEL_TYPES_H
#define __KNERLE_TYPES_H

#include <stdint.h>

typedef uint16_t 	tid_t;	// This is 16-bit for the VMM mapping of 
				// stacks.  See VmmManager.
struct task_t;

typedef uint64_t	cpuid_t;
struct cpu_t;

#endif
