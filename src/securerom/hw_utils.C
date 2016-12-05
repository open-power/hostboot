/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/securerom/hw_utils.C $                                    */
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
#include <hw_utils.h>
#include <status_codes.h>

/****************************************************************************/

#ifdef EMULATE_HW

#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <limits.h>
#include <stdint.h>                /* uint_fast8_t, uintN_t        */
#include <inttypes.h>
hw_settings HW;

/****************************************************************************/
void HW_Init (void) {
  /* Open the file that will be used to fill the memory contents of the mmap */
  HW.mfd = open ("/dev/zero", O_RDWR, 0);
  if (HW.mfd < 0) {
    printf ("HW_Init: can't create memory file");
    exit(1);
  }
  /* Allocate Memory */
#ifdef HOST_64
  HW.data = (uint8_t*) mmap64 (0, TOTAL_TEST_MEMORY,
                             PROT_READ|PROT_WRITE|PROT_EXEC, MAP_PRIVATE, HW.mfd, 0);
#else
  HW.data = (uint8_t*) mmap (0, TOTAL_TEST_MEMORY,
                           PROT_READ|PROT_WRITE|PROT_EXEC, MAP_PRIVATE, HW.mfd, 0);
#endif
  if ((uint32_t) HW.data == -1) {
    printf ("Unable to allocate HW Memory of size %d", TOTAL_TEST_MEMORY);
    HW_Free();
    exit(1);
  }
  HW.memory = HW.data+0x1000-((uint32_t)HW.data&0xfff);
}

/****************************************************************************/
void  HW_Free (void)
{
  close (HW.mfd);
}

/****************************************************************************/
void Log (uint64_t code) {
  mtspr_SCRATCH2 (code);
}

/****************************************************************************/
void Check_Stop (char* msg) {
  printf ("CHECK STOP '%s'\n", msg);
  printf ("SCRATCH3= 0x%08llX\n", mfspr_SCRATCH3());
  exit(FAIL);
}

/****************************************************************************/
void Error_Stop (uint64_t code, char* msg) {
  mtspr_SCRATCH3 (ERROR_EVENT|code);
  Check_Stop (msg);
}

/****************************************************************************/
void assem_DCBI (uint64_t addr) {
  addr = physical_addr(addr)&CACHE_MASK;
  memset(Convert_Mem_Addr(addr),0xff,CACHE_LINE); // destroys contents in model
  }
/****************************************************************************/
void assem_DCBZ (uint64_t addr) {
  addr = physical_addr(addr)&CACHE_MASK;
  memset(Convert_Mem_Addr(addr),0,CACHE_LINE);
}
/****************************************************************************/
void assem_DCBST (uint8_t* addr) {}
/****************************************************************************/
void assem_ICBI (uint64_t* addr) {}
/****************************************************************************/
void assem_SYNC (void) {}
/****************************************************************************/
void assem_ISYNC (void) {}

/****************************************************************************/
void mtspr_HRMOR (uint64_t addr) {
  HW.HRMOR = addr & HRMOR_MASK;
}

/****************************************************************************/
//uint64_t mfspr_HRMOR (void) {
//  return HW.HRMOR;
//}

/****************************************************************************/

/****************************************************************************/
uint64_t getscom_FSP_BAR_value (uint64_t base) {
  return HW.FSP_BAR.value;
}

/****************************************************************************/
uint64_t getscom_FSP_BAR_mask (uint64_t base) {
  return HW.FSP_BAR.mask;
}

/****************************************************************************/
void getscom_HW_ECID (uint64_t base, uint8_t* buf) {
  memcpy(buf, HW.ECID, ECID_SIZE);
}

/****************************************************************************/
void getscom_PIBMEM_HW_Key_Hash (uint64_t base, uint8_t* buf) {
  memcpy(buf, HW.PIBMEM_HW_KEY_HASH, SHA512_DIGEST_SIZE);
}

/****************************************************************************/
uint8_t* Convert_Mem_Addr (uint64_t addr) {
  if (addr >= TEST_SYSTEM_MEMORY) return NULL;
  return HW.memory+addr;
}

/****************************************************************************/
uint64_t physical_addr (uint64_t addr) {
  if (addr & HRMOR_IGNORE) addr = PHYSICAL(addr);
  else addr = PHYSICAL(addr) | HW.HRMOR;
  return addr;
}

/****************************************************************************/
uint64_t Convert_Mem_Offset (uint8_t* addr) {
  if (addr < HW.memory) return 0;
  return (uint64_t)(uint32_t)(addr-HW.memory);
}

/****************************************************************************/
uint16_t GET16(uint16_t data) {
#ifdef __BIG_ENDIAN
  return data;
#endif
#ifdef __LITTLE_ENDIAN
  return ((data&0x00FF)<<8
		 |(data&0xFF00)>>8
		 );
#endif
}

/****************************************************************************/
uint32_t GET32 (uint32_t data) {
#ifdef __BIG_ENDIAN
  return data;
#endif
#ifdef __LITTLE_ENDIAN
  return ((data&0x000000FF)<<24
	     |(data&0x0000FF00)<<8
		 |(data&0x00FF0000)>>8
		 |(data&0xFF000000)>>24
		 );
#endif
}

/****************************************************************************/
uint64_t GET64 (uint64_t data) {
#ifdef __BIG_ENDIAN
  return data;
#endif
#ifdef __LITTLE_ENDIAN
  return ((data&0x00000000000000FFull)<<(7*8)
	     |(data&0x000000000000FF00ull)<<(5*8)
		 |(data&0x0000000000FF0000ull)<<(3*8)
		 |(data&0x00000000FF000000ull)<<(1*8)
		 |(data&0x000000FF00000000ull)>>(1*8)
 	     |(data&0x0000FF0000000000ull)>>(3*8)
 		 |(data&0x00FF000000000000ull)>>(5*8)
 		 |(data&0xFF00000000000000ull)>>(7*8)
 		 );
#endif
}

#else

void __attribute__((noreturn)) Check_Stop(void) {
  //do not use XSCOM as the XSCOM base is not known for sure

  //set AVP_out to (optionally) cause secure checkstop
  mtspr(SPRC,SPRC_AVP_out);
  mtspr(SPRD,-1LL);

  asm volatile(" li 0,0       \n"
		       " mtmsr 0      \n" //ensure there is no error handler so it will checkstop instead
		       " lis 0,-1107  \n"
		       " stdcix 0,0,0 \n" //store to invalid address
		       " eieio        ");
  for(;;) {}
}

#endif //emulate_hw
