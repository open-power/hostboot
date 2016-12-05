/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/securerom/ROM.C $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/****************************************************************************
 *
 ****************************************************************************/
#ifndef PHYPLIBFUNCTIONS
#include <ROM.h>
#endif
#include <ecverify.h>
#include <status_codes.h>
#include <string.h>

/****************************************************************************/
#define valid_magic_number(header) (GET32((header)->magic_number) == ROM_MAGIC_NUMBER)
#define valid_container_version(header) (GET16((header)->version) == CONTAINER_VERSION)

/****************************************************************************/
static int valid_ver_alg(ROM_version_raw* ver_alg, uint8_t sig_alg) {
  if (GET16(ver_alg->version) != HEADER_VERSION) return 0;
  if (ver_alg->hash_alg != HASH_ALG_SHA512) return 0;
  if (!sig_alg) return 1;
  if (ver_alg->sig_alg != sig_alg) return 0;
  return 1;
}

/****************************************************************************/
static int valid_ecid(int ecid_count, uint8_t* ecids, uint8_t* hw_ecid) {
  if (!ecid_count) return 1;
  for (;ecid_count;ecid_count--,ecids+=ECID_SIZE)
    if (!memcmp (hw_ecid, ecids, ECID_SIZE)) return 1;
  return 0;
}

/****************************************************************************/
static int multi_key_verify(uint8_t* digest, int key_count, uint8_t* keys, uint8_t* sigs) {
  for (;key_count;key_count--,keys+=sizeof(ecc_key_t),sigs+=sizeof(ecc_signature_t))
    if (ec_verify (keys, digest, sigs)<1) return 0;
  return 1;
}

#ifndef PHYPLIBFUNCTIONS
/****************************************************************************/
static inline ROM_container_raw* cast_container(uint64_t addr) {
  return (ROM_container_raw*) Convert_Mem_Addr(physical_addr(addr));
}

/****************************************************************************/
static inline void ROM_init_cache_area(uint64_t target, uint64_t size) {
  uint64_t i;
  for (i=0;i<size;i+=CACHE_LINE) {
    assem_DCBZ(target);
    target+=CACHE_LINE;
  }
}

/****************************************************************************/
//static inline void ROM_invalidate_cache_area(uint64_t target, uint64_t size) {
//  uint64_t i;
//  for (i=0;i<size;i+=CACHE_LINE) {
//    assem_DCBI(target);
//    target+=CACHE_LINE;
//  }
//}

/****************************************************************************/
static void ROM_memcpy_icbi (uint64_t* to, uint64_t* from, int64_t size) {
  uint64_t* src=from;
  uint64_t* dst=to;
  for(;size>0;size-=sizeof(uint64_t)) {
    *dst++ = *src++;
  }
  assem_SYNC();   //heavy weight form of sync instruction
                  //which ensures all stores have been performed
                  //prior to the subsequent icbi
  assem_ICBI(to); //only need one of these to any address....
                  //this is only needed to set internal scoreboard bit
                  //to tell the processor to flush
                  //when it sees a subsequent isync
  assem_ISYNC();
}

//extern void* __toc_start;

#if 0

#define STACK_ASSUMPTION 128*1024
#define STACK_FRAME      (2*8)
/****************************************************************************/
#undef  CONTEXT
#define CONTEXT  ROM_INSTRUCTION_START
/****************************************************************************/
static inline void Create_C_Environment(uint64_t stack) {
 #ifdef EMULATE_HW
  printf ("Creating C Environment with stack pointer 0x%016llX\n",stack);
 #else
  // zero (create) stack area
  ROM_init_cache_area(stack-STACK_ASSUMPTION, STACK_ASSUMPTION);
  LOG(STACK_ZERO_DONE);

  // set stackpointer
  register volatile uint64_t r1 __asm__ ("r1"); // if you remove the volatile keyword then the compiler removes your code - grr
  r1 = stack-8;
  //*((uint64_t*)stack) = 0ull; -- end stackframe --already 0 by dcbz above

  //setup initial stackframe
  asm("stdu r1, -56(r1)");

 #endif
}

static inline void initTOCpointer() {
 #ifdef EMULATE_HW
  printf ("Initialize r2 with TOC pointer\n");
 #else
  // set TOC pointer (unused because no global variables)
  // register uint64_t r2 __asm__ ("r2");
  // r2 = (uint64_t)__toc_start+0x8000; //only for one TOC
  // r2 = ((uint64_t*)&ROM_instruction_start)[1]; //saver to get from { entry_point, toc_base, environment }
  asm(
   "springboard2:                                           \n"
   "	b		boingboing2                                 \n" // set CFAR
   "boingboing2:                                            \n"
   "	mfspr   r2, 28           	                        \n" // mfCFAR get address of springboard2
   "	addi	r2, r2,              0x4000                 \n" // adjust to __toc_start (part 1)
   "	addi	r2, r2, (__toc_start+0x4000-springboard2)@l \n" // adjust to __toc_start (part 2)
  );
 #endif
}

/****************************************************************************/
#undef  CONTEXT
#define CONTEXT  ROM_SELFTEST
/****************************************************************************/
static void ROM_selftest(void) {
#ifndef EMULATE_HW
  selftest_t const *selftest_p;
  asm volatile("li   %0,(__toc_start)@l  ### %0 := base+0x8000 \n\t" // because li does not work
		       "sub  %0,r2,%0 \n\t" // because subi does not work
               "addi %0,%0,(selftest-0x8000)@l" : "=r" (selftest_p) );
#else
  selftest_t const *selftest_p = &selftest;  //this line would introduce a absolute address in the toc
#endif

  sha2_hash_t digest;
  LOG(BEGIN);
  // sha512 good selftest
  SHA512_Hash((uint8_t*)&selftest_p->ec, sizeof(selftest_p->ec), &digest);
  if(memcmp(digest, selftest_p->sha.hash, sizeof(sha2_hash_t)))
    ERROR_STOP(SHA_GOOD_TEST,"sha512 good selftest failed");
  // sha512 bad selftest
  SHA512_Hash((uint8_t*)&selftest_p->ec, sizeof(selftest_p->ec)-1, &digest);
  if(!memcmp (digest, selftest_p->sha.hash, sizeof(sha2_hash_t)))
    ERROR_STOP(SHA_BAD_TEST,"sha512 bad selftest failed");
  // ecdsa verify good selftest
  if (ec_verify (selftest_p->ec.pkey, selftest_p->ec.hash, selftest_p->ec.sig)<1)
    ERROR_STOP(ECDSA_GOOD_TEST,"ecdsa good selftest failed");
  // ecdsa verify bad selftest (use digest from sha512 bad test)
  if (ec_verify (selftest_p->ec.pkey, digest, selftest_p->ec.sig)!=0)
    ERROR_STOP(ECDSA_BAD_TEST,"ecdsa bad selftest failed");
}

/****************************************************************************/
#undef  CONTEXT
#define CONTEXT  C_INSTRUCTION_START
/****************************************************************************/
uint64_t C_instruction_start( uint64_t xscom
                            , uint64_t fsp_bar
                            , uint64_t stack
                            , ROM_container_raw* container
                            ) {
  LOG(BEGIN);

  // run crypto selftests
  ROM_selftest();
  LOG(SELFTEST_DONE);

  // test for valid target hrmor address in trusted memory (security checks)
  uint64_t target_hrmor = GET64(container->target_hrmor);
  if(target_hrmor < 4096)
    ERROR_STOP(TARGET_LOW_TEST,"target hrmor too low");
  if(target_hrmor & ~HRMOR_MASK)
    ERROR_STOP(TARGET_VALID_TEST,"invalid target hrmor address");
  if(physical_addr(target_hrmor-4096)<fsp_bar)
    ERROR_STOP(TARGET_TRUST_TEST,"target hrmor in untrusted memory");
  target_hrmor = ABSOLUTE_ADDR(target_hrmor); //WEH bug fix, moved to allow previous test to work

  // test for stack and container collision
  uint64_t size = GET64(container->container_size);
  if( stack > target_hrmor-4096
    && stack-STACK_ASSUMPTION <= target_hrmor+size
    )
    ERROR_STOP(STACK_VS_TARGET_TEST,"container vs stack collision");

  mtspr_HRMOR(target_hrmor);

  // clear ERATS because hrmor has changed
  #ifdef EMULATE_HW
    printf ("clear ERATS because hrmor has changed\n");
  #else
    asm volatile ("slbia");
  #endif

  // zero target area and copy container
  ROM_init_cache_area(target_hrmor-4096, size);
  LOG(TARGET_ZERO_DONE);
  ROM_container_raw* target = cast_container(target_hrmor-4096);
  ROM_memcpy_icbi((uint64_t*)target, (uint64_t*)container, size);
  LOG(CONTAINER_COPY_DONE);

  // test for prefix header with HBI base code (firmware) signing keys
  ROM_prefix_header_raw* prefix = (ROM_prefix_header_raw*) &target->prefix;
  if(!valid_ver_alg(&prefix->ver_alg, SIG_ALG_ECDSA521))
    ERROR_STOP(PREFIX_VER_ALG_TEST,"bad prefix header version,alg's");
  uint32_t flags = GET32 (prefix->flags);
  if(!(flags & HBI_BASE_SIGNING_KEY))
    ERROR_STOP(HBI_KEY_TEST,"not HBI base code key prefix");

  // verify

  // fill verify hw params
  ROM_hw_params params;
  getscom_PIBMEM_HW_Key_Hash(xscom, params.hw_key_hash);
  getscom_HW_ECID(xscom, params.my_ecid);
  if (ROM_verify(target,&params) != ROM_DONE)
    ERROR_STOP(params.log,"see above");  // this will added C_INSTRUCTION_START to ROM_VERIFY for 0600
  LOG(CONTAINER_VERIFY_DONE);

  return HRMOR_RELATIVE(params.entry_point);
}

#endif

/****************************************************************************/
#undef  CONTEXT
#define CONTEXT  ROM_SRESET
/****************************************************************************/
#ifdef EMULATE_HW
void ROM_sreset (void) {
#else
void ROM_sreset(void) {
  asm volatile (".globl rom_sreset\n rom_sreset:"); //skip prologue
#endif
  // should never get here unless started too soon by fsp/sbe, checkstop
  ERROR_STOP(EXECUTION_ERROR,"sreset");
}

#if 0
/****************************************************************************/
#undef  CONTEXT
#define CONTEXT  ROM_INSTRUCTION_START
/****************************************************************************/
//static inline void ROM_Cleanup_Stack(uint64_t stack) {
//#ifdef EMULATE_HW
//  printf ("Cleaning up stack\n");
//#endif
//  ROM_invalidate_cache_area(stack-STACK_ASSUMPTION, STACK_ASSUMPTION);
//}

/****************************************************************************/
#ifdef EMULATE_HW
static void Call_Entry_Point(uint64_t start) {
  printf ("Branching to entry point 0x%016llX (PHY 0x%016llX)\n",start,physical_addr(start));
  return;
#else
static void __attribute__((noreturn)) Call_Entry_Point(uint64_t start) {

  asm volatile ( " mtctr %0 \n"
                 " bctr     \n"
                 " nop        "
              :              // no output
              : "r"  (start) // input,  %0
                             // no impacts ?
              );

  ERROR_STOP(RETURNED_ERROR,"returned from Entry_Point");
  #if !defined(_lint_)
    for (;;);
  #endif
#endif
}

/* Check the maximum limit of a untrusted memory BAR
 *
 * A BAR are two SCOM register one containing a mask and the other the pattern
 * the address is in the untrusted memory when this is true:
 * (address & mask) == pattern
 * If this is true then a untrusted PIB master (like FSI) can write it.
 * Remark:
 * If a mask bit is 0 and the coresponding pattern bit is 1 then it is always false.
 *
 * parameter:
 * 	 limit   = previous limit from other BARs or 0
 * 	 xscom   = the xscom base address
 * 	 bar     = the pib address of the BAR register containing the pattern
 * 	 barMask = the pib address of the BAR register containing the mask
 * return value:
 *  the new limit is the maximum from previous limit and the bars limit
 */
uint64_t check_bar(uint64_t limit, uint64_t xscom, uint64_t bar, uint64_t barMask) {
    uint64_t barValue     = getscom(xscom,bar);
    uint64_t barMaskValue = getscom(xscom,barMask);

    barMaskValue |= 0xFFFC000000000000;  // bit 0:13 not implemented and must be '1'

    uint64_t barLimit     = (barValue | ~barMaskValue) + 1;
    if(  ( (barValue & ~barMaskValue) == 0)
      && ( barLimit > limit)
      ) {
    	limit=barLimit;
    }
    return limit;
}

#endif

/****************************************************************************/
#ifdef EMULATE_HW
void ROM_instruction_start(void) {
#else
void __attribute__((noreturn)) ROM_instruction_start(void) {
  asm volatile (".globl instruction_start\ninstruction_start:"); //skip prologue
#endif

#if 0

  initTOCpointer();

  LOG(BEGIN);

  // test for reasonable xscom base address (security check)
  register uint64_t xscom = mfspr_SCRATCH0();
  if(!xscom) {
    ERROR_STOP(XSCOM_LOW_TEST,"xscom base address too low");
  }
  if(xscom & ~XSCOM_MASK) {
    ERROR_STOP(XSCOM_VALID_TEST,"invalid xscom base address");
  }
  xscom = ABSOLUTE_ADDR(xscom);

#ifndef EMULATE_HW
  // get trusted memory base
  uint64_t fsp_bar=0;
  fsp_bar = check_bar(fsp_bar, xscom, ALTD_UNTRUSTED_BAR_ADDR_REG, ALTD_UNTRUSTED_BAR_MASK_ADDR_REG);
  fsp_bar = check_bar(fsp_bar, xscom, PSIHB_NOTRUST_BAR0,          PSIHB_NOTRUST_BAR0MASK          );
  fsp_bar = check_bar(fsp_bar, xscom, PSIHB_NOTRUST_BAR1,          PSIHB_NOTRUST_BAR1MASK          );
#else
  // get trusted memory base
  uint64_t fsp_bar = (getscom_FSP_BAR_value(xscom) | ~getscom_FSP_BAR_mask(xscom)) + 1;
#endif

  LOG(TRUSTED_MEM_BAR);

  register uint64_t raw_container = mfspr_SCRATCH1();
  if (raw_container < 4096)   //must check for value that will wrap around
    ERROR_STOP(CONTAINER_LOW_TEST,"container too low");
  raw_container = ABSOLUTE_ADDR(raw_container)-4096;
  ROM_container_raw* container = cast_container(raw_container);

  // test for valid container magic number, version, hash & signature algorithms (sanity checks)
  if(!valid_magic_number(container))
    ERROR_STOP(MAGIC_NUMBER_TEST,"bad container magic number");
  if (!valid_container_version (container))
    ERROR_STOP(CONTAINER_VERSION_TEST,"bad container version");

  // test for trusted memory stack pointer (assumes 8K max depth)
  register uint64_t stack = GET64(container->stack_pointer);
  stack += STACK_ASSUMPTION;
  if(stack < STACK_ASSUMPTION) {
    ERROR_STOP(STACK_LOW_TEST,"stack pointer too low");
  }
  if(stack & ~STACK_MASK)
    ERROR_STOP(STACK_VALID_TEST,"invalid stack pointer address");
  if(physical_addr(stack-STACK_ASSUMPTION)<fsp_bar)
    ERROR_STOP(STACK_TRUST_TEST,"stack in untrusted memory");
  stack = ABSOLUTE_ADDR(stack); //WEH bug fix, moved to allow previous test to work

  // launch C environment (zero stack)
  Create_C_Environment(stack);

  // Jump to C code
  register uint64_t entry = C_instruction_start(xscom,fsp_bar,stack,container);

  // cleanup (invalidate) stack - no longer required HBI takes care
  //ROM_Cleanup_Stack(stack);
  //LOG(STACK_CLEANUP_DONE);

  // clear scratch 0 and 1 reg - no longer required
  //mtspr_SCRATCH0(0);
  //mtspr_SCRATCH1(0);

  LOG(COMPLETED);
  Call_Entry_Point(entry);  // never return from here!!!
  #endif
}

/****************************************************************************/
#endif

#ifdef EMULATE_HW
  #define FAILED(_c,_m) { params->log=ERROR_EVENT|CONTEXT|(_c); printf ("FAILED '%s'\n", (_m)); return ROM_FAILED; }
#else
  #define FAILED(_c,_m) { params->log=ERROR_EVENT|CONTEXT|(_c);                                 return ROM_FAILED; }
#endif

//****************************************************************************
#undef  CONTEXT
#ifndef PHYPLIBFUNCTIONS
#define CONTEXT  ROM_VERIFY
//****************************************************************************
// NOTE: ROM_verify is called with absolute addresses from c_instruction_start
//  and with hrmor relative addresses from Hostboot
asm(".globl .L.ROM_verify");
ROM_response ROM_verify( ROM_container_raw* container,
                         ROM_hw_params*     params ) {
#else
#define CONTEXT  PHYP_VERIFY
//****************************************************************************
// NOTE: PHYP_verify is called with hrmor relative addresses from PHYP
ROM_response PHYP_verify( PHYP_command       cmnd,
                          ROM_container_raw* container,
                          PHYP_hw_params*    params,
                          PHYP_verify_state* state ) {
#endif
  sha2_hash_t digest;
  ROM_prefix_header_raw* prefix;
  ROM_prefix_data_raw* hw_data;
  ROM_sw_header_raw* header;
  ROM_sw_sig_raw* sw_sig;
  uint64_t size;

  params->log=CONTEXT|BEGIN;

#ifdef PHYPLIBFUNCTIONS
  if(cmnd != PHYP_CONTINUE) {
#endif
    // test for valid container magic number, version, hash & signature algorithms (sanity check)
    if(!valid_magic_number(container))
      FAILED(MAGIC_NUMBER_TEST,"bad container magic number");
    if(!valid_container_version(container))
      FAILED(CONTAINER_VERSION_TEST,"bad container version");
#ifdef PHYPLIBFUNCTIONS
    // initialize verify state
    state->state = PHYP_START_VERIFY;
  }

  do {
    switch(state->state) {
    case PHYP_START_VERIFY:
#endif
      // process hw keys
      // test for valid hw keys
      SHA512_Hash(container->hw_pkey_a, 3*sizeof(ecc_key_t), &digest);
      if(memcmp(params->hw_key_hash, digest, sizeof(sha2_hash_t)))
        FAILED(HW_KEY_HASH_TEST,"invalid hw keys");

      // process prefix header
      prefix = (ROM_prefix_header_raw*) &container->prefix;
      // test for valid header version, hash & signature algorithms (sanity check)
      if(!valid_ver_alg(&prefix->ver_alg, SIG_ALG_ECDSA521))
        FAILED(PREFIX_VER_ALG_TEST,"bad prefix header version,alg's");
      // test for valid prefix header signatures (all)
      hw_data = (ROM_prefix_data_raw*) (prefix->ecid + prefix->ecid_count*ECID_SIZE);
      SHA512_Hash((uint8_t*)prefix, PREFIX_HEADER_SIZE(prefix), &digest);
      if(!multi_key_verify(digest, 3, container->hw_pkey_a, hw_data->hw_sig_a))
        FAILED(HW_SIGNATURE_TEST,"invalid hw signature");
      // test for machine specific matching ecid
      if(!valid_ecid(prefix->ecid_count, prefix->ecid, params->my_ecid))
        FAILED(PREFIX_ECID_TEST,"unauthorized prefix ecid");
      // test for valid prefix payload hash
      size = GET64(prefix->payload_size);
      SHA512_Hash(hw_data->sw_pkey_p, size, &digest);
      if(memcmp(prefix->payload_hash, digest, sizeof(sha2_hash_t)))
        FAILED(PREFIX_HASH_TEST,"invalid prefix payload hash");
      // test for special prefix header
      if(!prefix->sw_key_count) {
        // finish processing special prefix header
        // test for machine specfic (sanity check)
        if(prefix->ecid_count == 0)
          FAILED(SPECIAL_NO_ECID_TEST,"special prefix with ecid_count == 0");
        // test for signing of keys only (sanity check)
        if(size != 0)
          FAILED(SPECIAL_SIZE_0_TEST,"special prefix with payload_size != 0");
        // return hrmor relative code start address
        params->entry_point = GET64(prefix->code_start_offset);
        //check if the entry is HRMOR-relative and aligned
        if(params->entry_point & ~(ENTRY_MASK))
          FAILED(ENTRY_VALID_TEST,"entry is not HRMOR relative or not aligned");
        params->log=CONTEXT|COMPLETED;
        return ROM_DONE;
      }
      // finish processing prefix header
      // test for protection of all sw key material (sanity check)
      if(size != (prefix->sw_key_count * sizeof(ecc_key_t)))
        FAILED(SW_KEY_PROTECTION_TEST,"incomplete sw key protection in prefix header");

      // start processing sw header
      header = (ROM_sw_header_raw*) (hw_data->sw_pkey_p + prefix->sw_key_count*sizeof(ecc_key_t));
      // test for valid header version, hash & signature algorithms (sanity check)
      if(!valid_ver_alg(&header->ver_alg, 0))
        FAILED(HEADER_VER_ALG_TEST,"bad sw header version,alg");
      // test for valid sw header signatures (all)
      sw_sig = (ROM_sw_sig_raw*) (header->ecid + header->ecid_count*ECID_SIZE);
      SHA512_Hash((uint8_t*)header, SW_HEADER_SIZE(header), &digest);
      if(!multi_key_verify(digest, prefix->sw_key_count, hw_data->sw_pkey_p, sw_sig->sw_sig_p))
        FAILED(SW_SIGNATURE_TEST,"invalid sw signature");
      // test for machine specific matching ecid
      if(!valid_ecid(header->ecid_count, header->ecid, params->my_ecid))
        FAILED(HEADER_ECID_TEST,"unauthorized sw ecid");
      // test for entry point within protected payload (sanity check)
      params->entry_point = GET64(header->code_start_offset);
      //check if the entry is HRMOR-relative and aligned
      if(params->entry_point & ~(ENTRY_MASK))
    	FAILED(ENTRY_VALID_TEST,"entry is not HRMOR relative or not aligned");
      size = GET64(header->payload_size);
      if(params->entry_point+3 >= size) // must have full instruction (3 more bytes)
        FAILED(CODE_PROTECTION_TEST,"unprotected code_start in sw header");
      // begin test for valid sw payload hash
#ifdef PHYPLIBFUNCTIONS
      state->message = (uint8_t*)container + 4096;
      state->remain = size;
      SHA512_Init(&state->sha);
      state->header = header;
      state->state = PHYP_CONT_VERIFY;
      params->log=CONTEXT|PARTIAL;
      break;

    case PHYP_CONT_VERIFY:
      if(state->remain > params->max_hash) {
        // continue test for valid sw payload hash
        SHA512_Update(&state->sha, state->message, params->max_hash);
        state->message += params->max_hash;
        state->remain -= params->max_hash;
      } else {
        // finish test for valid sw payload hash
        SHA512_Update(&state->sha, state->message, state->remain);
        SHA512_Final(&state->sha, &digest);
        header = state->header;
#else
        SHA512_Hash((uint8_t*)container + 4096, size, &digest);
#endif
        if(memcmp(header->payload_hash, digest, sizeof(sha2_hash_t)))
          FAILED(HEADER_HASH_TEST,"invalid sw payload hash");
        params->log=CONTEXT|COMPLETED;
        return ROM_DONE;
#ifdef PHYPLIBFUNCTIONS
      }
      break;

    default:
      FAILED(EXECUTION_ERROR,"bad internal state");
      break;
    }
  } while (cmnd == PHYP_WHOLE);
  params->log=CONTEXT|PARTIAL;
  return PHYP_PARTIAL;
#endif
}
