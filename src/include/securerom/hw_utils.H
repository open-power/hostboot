/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/securerom/hw_utils.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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

#ifndef HW_UTILS_H
#define HW_UTILS_H

#include <stdint.h>

#include <securerom/sha512.H>
#include <securerom/status_codes.H>

#define ECID_SIZE            16
#define CACHE_LINE           128
#define XSCOM_MASK           0x0003fe0000000000ull // bit 14:22 implemented
#define HRMOR_MASK           0x0003fffffe000000ull // 32MB aligned
#define STACK_MASK           0x0003fffffffff000ull // 4KB page aligned
#define ENTRY_MASK           0x7ffffffffffffffCull // 4Byte page aligned

#define HRMOR_IGNORE         0x8000000000000000ull
#define HRMOR_RELATIVE(_a) ((_a)&~HRMOR_IGNORE)
#define ABSOLUTE_ADDR(_a)  ((_a)|HRMOR_IGNORE)


#define CONTEXT   0

#ifdef EMULATE_HW

extern int FAIL;
extern int GOOD;

#define HOST_RESET_VECTOR    0x100

#define TEST_SYSTEM_MEMORY   (64*1024*1024)
#define TRUSTED_MEMORY_BASE  (8*1024*1024) // should be 256MB
#define TOTAL_TEST_MEMORY    (TEST_SYSTEM_MEMORY+4*1024)
#define MEMORY_MASK          0x7fffffffffffffffull
#define CACHE_MASK           0x7fffffffffffff80ull // 128B cache line aligned

#define PHYSICAL(_a)       ((_a)&MEMORY_MASK)

#define LOG(_c)            Log(CONTEXT|(_c))
#define CHECK_STOP(_m)     Check_Stop(_m)
#define ERROR_STOP(_c,_m)  Error_Stop(CONTEXT|(_c), _m)

typedef struct
{
    uint64_t     GPR[32];
    uint64_t     SCRATCH0;
    uint64_t     SCRATCH1;
    uint64_t     SCRATCH2;
    uint64_t     SCRATCH3;
    uint64_t     HRMOR;
    struct
    {
        uint64_t   value;
        uint64_t   mask;
    }            FSP_BAR;
    uint8_t      ECID[ECID_SIZE];
    SHA512_t     PIBMEM_HW_KEY_HASH;
    uint8_t*     data;    // 64M+4K malloc/mmap
    uint8_t*     memory;  // 64M (4K aligned)
    int          mfd;
} hw_settings;

extern hw_settings HW;

#define r1      HW.GPR[1]
#define r2      HW.GPR[2]

extern void     HW_Init (void);
extern void     HW_Free (void);

extern void     Log        (uint64_t code);
extern void     Error      (uint64_t code);
extern void     Check_Stop (char* msg);
extern void     Error_Stop (uint64_t code, char* msg);

extern void     assem_DCBI  (uint64_t addr);
extern void     assem_DCBZ  (uint64_t addr);
extern void     assem_DCBST (uint8_t* addr);
extern void     assem_ICBI  (uint64_t* addr);
extern void     assem_SYNC  (void);
extern void     assem_ISYNC (void);

extern void     mtspr_HRMOR (uint64_t addr);
//extern uint64_t mfspr_HRMOR (void);

static inline uint64_t mfspr_SCRATCH0(void)
{
    return HW.SCRATCH0;
}

static inline void mtspr_SCRATCH0(uint64_t val)
{
    HW.SCRATCH0 = val;
}

static inline uint64_t mfspr_SCRATCH1(void)
{
    return HW.SCRATCH1;
}

static inline void mtspr_SCRATCH1(uint64_t val)
{
    HW.SCRATCH1 = val;
}

static inline void mtspr_SCRATCH2(uint64_t val)
{
    HW.SCRATCH2 = val;
}

static inline uint64_t mfspr_SCRATCH2(void)
{
    return HW.SCRATCH2;
}

static inline void mtspr_SCRATCH3(uint64_t val)
{
    HW.SCRATCH3 = val;
}

static inline uint64_t mfspr_SCRATCH3(void)
{
    return HW.SCRATCH3;
}

extern uint64_t getscom_FSP_BAR_value (uint64_t base);
extern uint64_t getscom_FSP_BAR_mask (uint64_t base);

extern void getscom_HW_ECID (uint64_t base, uint8_t* buf);

extern uint64_t physical_addr (uint64_t addr);
extern uint8_t* Convert_Mem_Addr (uint64_t);
extern uint64_t Convert_Mem_Offset (uint8_t*);

extern uint16_t GET16 (uint16_t data);
extern uint32_t GET32 (uint32_t data);
extern uint64_t GET64 (uint64_t data);

#else //emulate_hw

/* SPRs numbers -- the wrong ones: */
//#define SPRG0			272 /* Software Special Purpose Register 0 */
//#define SPRG1			273 /* Software Special Purpose Register 1 */
//#define SPRG2			274 /* Software Special Purpose Register 2 */
//#define SPRG3			275 /* Software Special Purpose Register 3 */

#define SPRC			276
#define SPRC_SCRATCH0	0x0000000000000040
#define SPRC_SCRATCH1	0x0000000000000048
#define SPRC_SCRATCH2	0x0000000000000050
#define SPRC_SCRATCH3	0x0000000000000058
#define SPRC_AVP_out	0x00000000000001C8
#define SPRD			277

#define HRMOR			313

#define HMER_REG        336
#define HMER_XSCOM_FAIL	0x0080000000000000  //Bit 8
#define HMER_XSCOM_DONE 0x0040000000000000  //Bit 9
#define HMER_XSCOM_RSLT	0x0000070000000000  //Bit 21-23
#define HMER_XSCOM_RTRY	0x0000010000000000  //RSLT = 001 = retry

/* SCOM Register addresses */
#define OTP					0x00018000
#define OTP_ECID			OTP       +0x0000
#define PIBMEM				0x00080000
#define PIBMEM_HW_KEY_HASH	PIBMEM    +0x0008

#define ALTD_UNTRUSTED_BAR_ADDR_REG       0x02020015
#define ALTD_UNTRUSTED_BAR_MASK_ADDR_REG  0x02020016
#define PSIHB_NOTRUST_BAR0                0x02013f40
#define PSIHB_NOTRUST_BAR0MASK            0x02013f42
#define PSIHB_NOTRUST_BAR1                0x02013f41
#define PSIHB_NOTRUST_BAR1MASK            0x02013f43

static inline void assem_DCBI(uint64_t addr)
{
    asm volatile(" dcbi 0,%0 " : : "r" (addr) : "memory");
}
static inline void assem_DCBZ(uint64_t addr)
{
    asm volatile(" dcbz 0,%0 " : : "r" (addr) : "memory");
}
static inline void assem_ICBI(uint64_t* addr)
{
    asm volatile(" icbi 0,%0 " : : "r" (addr) : "memory");
}
static inline void assem_SYNC(void)
{
    asm volatile("sync 0":::"memory");
}
static inline void assem_ISYNC(void)
{
    asm volatile("isync":::"memory");
}

static inline uint64_t mfspr(int reg)
{
    unsigned long val;
    asm volatile("mfspr %0, %1" : "=r" (val) : "i" (reg));
    return val;
}

static inline void mtspr(int reg, uint64_t val)
{
    asm volatile("mtspr %0, %1" : : "i" (reg), "r" (val));
}

static inline void mtspr_HRMOR(uint64_t addr)
{
    asm volatile("mtspr %0, %1" : : "i" (HRMOR), "r" (addr & HRMOR_MASK));
}

static inline uint64_t mfspr_SCRATCH0(void)
{
    mtspr(SPRC,SPRC_SCRATCH0);
    return mfspr(SPRD);
}

static inline void mtspr_SCRATCH0(uint64_t val)
{
    mtspr(SPRC,SPRC_SCRATCH0);
    mtspr(SPRD,val);
}

static inline uint64_t mfspr_SCRATCH1(void)
{
    mtspr(SPRC,SPRC_SCRATCH1);
    return mfspr(SPRD);
}

static inline void mtspr_SCRATCH1(uint64_t val)
{
    mtspr(SPRC,SPRC_SCRATCH1);
    mtspr(SPRD,val);
}

static inline void mtspr_SCRATCH2(uint64_t val)
{
    mtspr(SPRC,SPRC_SCRATCH2);
    mtspr(SPRD,val);
}

static inline void mtspr_SCRATCH3(uint64_t val)
{
    mtspr(SPRC,SPRC_SCRATCH3);
    mtspr(SPRD,val);
}

extern "C"
void __attribute__((noreturn)) Check_Stop(void);

#define LOG(_c)             mtspr_SCRATCH2(CONTEXT|(_c))
#define ERROR_STOP(_c,_m) { mtspr_SCRATCH3(ERROR_EVENT|CONTEXT|(_c)); \
                            asm volatile("b .Check_Stop"); }

/* Bit 56,  61, 62, 63 is not used in XSCOM addresss and must be 0 */
#define PCB2PBUS(scom_addr) \
    ((((scom_addr) & 0x7FFFFFF0) << 4) | \
    (((scom_addr) & 0x0000000F) << 3))


static inline uint64_t ci_read(const uint64_t reg)
{
    unsigned long val;
    asm volatile( "ldcix %0, 0, %1"
                  : "=r" (val)   // output, %0
                  : "r"  (reg)   // input,  %1
                             // no impacts
                );
  return val;
}

static inline void ci_write(const uint64_t reg, uint64_t val)
{
    asm volatile("stdcix %0, 0, %1"
                 :                       // no outputs
                 : "r" (val), "r" (reg)  // inputs, %0, %1
                 : "memory"              // affects memory
                );
}

#define getscom(a, b) _getscom((a)+PCB2PBUS(b))
static inline uint64_t _getscom(uint64_t addr)
{
    mtspr(HMER_REG,0);
    uint64_t value;
    uint64_t rslt;
    do {
        value = ci_read(addr);
        do {
            rslt = mfspr(HMER_REG)&(HMER_XSCOM_RSLT|HMER_XSCOM_DONE|HMER_XSCOM_FAIL);
        } while( (rslt & HMER_XSCOM_DONE)==0 );
    } while(rslt == (HMER_XSCOM_RTRY|HMER_XSCOM_DONE|HMER_XSCOM_FAIL) ); // 001 retry
    if(rslt != HMER_XSCOM_DONE)
    {
        ERROR_STOP(XSCOM_ERROR,"XScom read returned unexpected result code");
    }
    return value;
}

#define putscom(xscom_base, scom_addr, value) _putscom(xscom_base \
        + PCB2PBUS(scom_addr),value)
static inline void _putscom(uint64_t addr, uint64_t value)
{
    mtspr(HMER_REG,0);
    uint64_t rslt = -1;
    do {
        ci_write(addr,value);
        do {
            rslt = mfspr(HMER_REG)&(HMER_XSCOM_RSLT|HMER_XSCOM_DONE|HMER_XSCOM_FAIL);
        } while( (rslt & HMER_XSCOM_DONE)==0 );
    } while(rslt == (HMER_XSCOM_RTRY|HMER_XSCOM_DONE|HMER_XSCOM_FAIL) ); // 001 retry
    if(rslt != HMER_XSCOM_DONE)
    {
        ERROR_STOP(XSCOM_ERROR,"XScom write returned unexpected result code");
    }
}

static inline uint64_t popcountll(uint64_t input)
{
    unsigned long result;
    asm volatile("popcntd %0, %1" : "=r" (result) : "r" (input));
    return result;
}

static inline void getscom_HW_ECID(uint64_t base, uint8_t* buf)
{
    uint64_t* buf64 = (uint64_t *) buf;
    unsigned int i;
    for(i=0; i<ECID_SIZE/sizeof(uint64_t);i++)
    {
        uint64_t val=getscom(base,OTP_ECID+i);
        buf64[i] = val;
    }
}

#define Convert_Mem_Addr(_addr)   ((uint8_t*) (_addr))
#define Convert_Mem_Offset(_addr) ((uint64_t) (_addr))

#define physical_addr(_addr) _addr

#define GET16(_data) _data
#define GET32(_data) _data
#define GET64(_data) _data

#endif //emulate_hw - else case

#endif
