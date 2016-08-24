/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/lib/p9_ppe_utils.H $       */
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

///
/// @file  p9_ppe_utils.H
/// @brief PPE commonly used functions
///
/// *HWP HW Owner        : Ashish More <ashish.more.@in.ibm.com>
/// *HWP HW Backup Owner : Brian Vanderpool <vanderp@us.ibm.com>
/// *HWP FW Owner        : Sangeetha T S <sangeet2@in.ibm.com>
/// *HWP Team            : PM
/// *HWP Level           : 2
/// *HWP Consumed by     : CMEs, GPEs, SBE, Cronus
#include <map>
#ifndef __P9_PPE_UTILS_H__
#define __P9_PPE_UTILS_H__
typedef struct
{
    uint16_t    number;
    uint32_t    value;
} PPERegValue_t;

typedef struct
{
    PPERegValue_t     reg;
    std::string  name;
} PPEReg_t;

typedef struct
{
    uint16_t    number;
    uint64_t    value;
} SCOMRegValue_t;


typedef struct
{
    SCOMRegValue_t    reg;
    std::string  name;
} SCOMReg_t;
/**
 * @brief enumerates opcodes for few instructions.
 */
enum
{
    OPCODE_31         = 31,
    MTSPR_CONST1      = 467,
    MTSPR_BASE_OPCODE = (OPCODE_31 << (31 - 5)) | (MTSPR_CONST1 << (31 - 30)),
    MFSPR_CONST1      = 339,
    MFSPR_BASE_OPCODE = (OPCODE_31 << (31 - 5)) | (MFSPR_CONST1 << (31 - 30)),
    MFMSRD_CONST1     = 83,
    MFCR_CONST1       = 19,
    ANDIS_CONST       = 29,
    ORIS_CONST        = 25,
};


/**
 * @brief Offsets from base address for XIRs.
 */
const static uint64_t PPE_XIXCR    = 0x0; //XCR_NONE
const static uint64_t PPE_XIRAMRA  = 0x1; //XCR_SPRG0
const static uint64_t PPE_XIRAMGA  = 0x2; //IR_SPRG0
const static uint64_t PPE_XIRAMDBG = 0x3; //XSR_SPRG0
const static uint64_t PPE_XIRAMEDR = 0x4; //IR_EDR
const static uint64_t PPE_XIDBGPRO = 0x5; //XSR_IAR

enum PPE_DUMP_MODE
{
    NONE           = 0x0,
    XIRS           = 0x4,
    SNAPSHOT       = 0x1,
    HALT           = 0x2,
    FORCE_HALT     = 0x3
};
enum VERBOSE_MODE
{
    NOVERBOSE        = 0x0,
    VERBOSE          = 0x1,
    VERBOSEP         = 0x2,
    VERBOSE1         = 0x3,

};

enum INT_VEC_OFFSET
{
    MCHK_VEC = 0x000  ,  // 0,
    SRST_VEC = 0x040  ,  // 64,
    DSI_VEC  =  0x060 ,  // 96,
    ISI_VEC  =  0x080 ,  // 128,
    EXT_VEC  =  0x0A0 ,  // 160,
    ALIG_VEC = 0x0C0  ,  // 192,
    PRG_VEC  =  0x0E0 ,  // 224,
    DEC_VEC  =  0x100 ,  // 256,
    FIT_VEC  =  0x120 ,  // 288,
    WDT_VEC  =  0x140 ,  // 320,
} ;
enum PPE_XIRS
{
    XIR_XSR,
    XIR_IAR,
    XIR_IR,
    XIR_EDR,
    XIR_SPRG0,
};

//enum PPE_SPECIAL_ACCESS
//{
//    MSR,
//    CR,
//};
enum PPE_SPRS
{
    CTR     = 9,
    DACR    = 316,
    DBCR    = 308,
    DEC     = 22,
    EDR     = 61,
    IVPR    = 63,
    ISR     = 62,
    LR      = 8,
    PIR     = 286,
    PVR     = 287,
    SPRG0   = 272,
    SRR0    = 26,
    SRR1    = 27,
    TCR     = 340,
    TSR     = 336,
    XER     = 1,
    //Some unique identification no. FOR OTHER REGS(non sprn)
    XSR     = 4200,
    IAR     = 2,
    IR      = 3,
    MSR     = 42,
    CR      = 420,

};


// Note: EDR is available via XIR
enum PPE_GPRS
{
    R0  = 0,
    R1  = 1,
    R2  = 2,
    R3  = 3,
    R4  = 4,
    R5  = 5,
    R6  = 6,
    R7  = 7,
    R8  = 8,
    R9  = 9,
    R10 = 10,
    R13 = 13,
    R28 = 28,
    R29 = 29,
    R30 = 30,
    R31 = 31,
};
// Vector defining all spr acceess egisters
const std::map<uint16_t, std::string> v_ppe_sprs_num_name =
{
    { MSR,   "MSR"    },
    { CR,    "CR"     },
    { CTR,   "CTR"    },
    { LR,    "LR"     },
    { ISR,   "ISR"    },
    { SRR0,  "SRR0"   },
    { SRR1,  "SRR1"   },
    { TCR,   "TCR"    },
    { TSR,   "TSR"    },
    { DACR,  "DACR"   },
    { DBCR,  "DBCR"   },
    { DEC,   "DEC"    },
    { IVPR,  "IVPR"   },
    { PIR,   "PIR"    },
    { PVR,   "PVR"    },
    { XER,   "XER"    }
};

// Vector defining the GPRs
const std::map<uint16_t, std::string> v_ppe_gprs_num_name =
{
    { R0,    "R0"     },
    { R1,    "R1"     },
    { R2,    "R2"     },
    { R3,    "R3"     },
    { R4,    "R4"     },
    { R5,    "R5"     },
    { R6,    "R6"     },
    { R7,    "R7"     },
    { R8,    "R8"     },
    { R9,    "R9"     },
    { R10,   "R10"    },
    { R13,   "R13"    },
    { R28,   "R28"    },
    { R29,   "R29"    },
    { R30,   "R30"    },
    { R31,   "R31"    }
};
// Vector defining the other xsr regs
const std::map<uint16_t, std::string> v_ppe_xsr_num_name =
{
    { XSR,   "XSR"    },
    { IAR,   "IAR"    },
    { IR,    "IR"     },
    { EDR,   "EDR"    },
    { SPRG0, "SPRG0"  }
};


#endif  // __P9_PPE_UTILS_H__
