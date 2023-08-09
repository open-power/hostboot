/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/stdlib.h $                                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2023                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef __STDLIB_H
#define __STDLIB_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

 /**
  * @brief allocates memory contiguous in physical memory
  * @param[in]  size  size of allocation.
  * @return Pointer to beginning of allocation block
  */
void* contiguous_malloc(size_t)__attribute__((malloc));

 /**
  * @brief allocates memory discontiguous in physical memory
  * @param[in]  size  size of allocation.
  * @return Pointer to beginning of allocation block
  */
void* discontiguous_malloc(size_t);

 /**
  * @brief Uses the currently active allocator (contiguous or
  * discontiguous). Always uses the contiguous allocator in kernel
  * mode.
  * @param[in]  size  size of allocation.
  * @return pointer to beginning of allocation block
  */
void* malloc(size_t)__attribute__((malloc));

 /**
  * @brief Function to free allocated block. Can be used with the
  *        results of either contiguous or discontiguous allocator.
  * @param[in]  ptr  pointer to allocation block needed to be freed
  */
void  free(void*);

 /**
  * @brief called in istep 6.5 to switch the default allocator to
  * discontiguous malloc. This is the earliest point when the VMM
  * system is ready to handle a call mm_alloc_block.
  */
void activate_discontiguous_malloc_heap();

/**
 * @brief Called in exit_cache_contained to return to the
 * physically contiguous allocator. We do this because we
 * currently have limited virtual address space, and after exiting
 * cache, we don't have tight memory constraints.
 */
void deactivate_discontiguous_malloc_heap();

/**
 *  @brief Can be used with a pointer from either allocator.
 */
void* realloc(void*, size_t);

/**
 * @brief Uses the current allocator.
 */
void* calloc(size_t, size_t) __attribute__((malloc));

/**
 * @brief converts a given char string to uint64_t
 *
 * @param[in] nptr input string in the form of pointer to char
 * @param[in] endptr UNUSED
 * @param[in] base UNUSED (always base 16)
 * @return the uint64_t representation of the input string or 0
 *         if the function failed to convert
 */
uint64_t strtoul(const char *nptr, char **endptr, int base);

/**
 * @brief Returns the absolute value of parameter n ( /n/ )
 * See C spec for details
 */
int abs(int n);

#ifdef __cplusplus
};
#endif

#endif
