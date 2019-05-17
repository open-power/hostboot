/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/initservice/mboxRegs.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
#ifndef MBOXREGS_H_
#define MBOXREGS_H_

#include <builtins.h>

namespace INITSERVICE
{
namespace SPLESS
{
    /* Documentation for these registers can be found in the P10 IPL
     * Flow document */

    template<uint32_t REG_NUM>
    struct MboxScratch_t
    {
        // This is just a helper structure to generate the members for
        // the actual MboxScratchN_t structures. It is only meant to
        // be inherited from. The template argument REG_NUM should be
        // the *number* of the scratch register (not the
        // index/offset), i.e. MboxScratchRegN_t should inherit from
        // MboxScratch_t<N>.

        static_assert(1 <= REG_NUM && REG_NUM <= 16,
                      "Invalid mailbox scratch register number in MboxScratch_t; "
                      "we only support registers 1 through 16");

    private:
        // The SCOM and CFAM base addresses for the mailbox scratch
        // registers in range [1, 8] differ from those in the range
        // [9, 16].
        static constexpr uint32_t SCOM_BASE = (REG_NUM < 9
                                               ? 0x00050038
                                               : 0x00050180);

        static constexpr uint32_t CFAM_BASE = (REG_NUM < 9
                                               ? 0x00002838
                                               : 0x00000180);

        // The offset of this register in its contiguous block of
        // address space (regs 1-16 are separated into two contiguous
        // blocks, one for 1-8 and one for 9-16, based at different
        // addresses).
        static constexpr uint32_t REG_OFFSET = (REG_NUM < 9
                                                ? REG_NUM - 1
                                                : REG_NUM - 1 - 8);

    public:
        // REG_ADDR is the SCOM address of the register.
        static constexpr uint32_t REG_ADDR  = SCOM_BASE + REG_OFFSET;

        static constexpr uint32_t CFAM_ADDR = CFAM_BASE + REG_OFFSET;

        // This is the zero-based index of this register.
        static constexpr uint32_t REG_IDX   = REG_NUM - 1;

    protected:
        MboxScratch_t() = default;
    };

    // Mailbox Scratch Register 1 - FW functional Cores
    // SCOM address: 0x00050038
    // CFAM address: 0x2838
    struct MboxScratch1_t : MboxScratch_t<1>
    {
        // This outer MboxScratchN_t struct is required to contain the
        // static data members, because certain versions of GCC have a
        // bug which disallows unions to contain them

        // each member of this union represents a different way in
        // which the scratch register is used in the boot process
        union
        {
            uint32_t data32;

            // This is the structure of this register according to the
            // P10 IPL flow doc
            struct
            {
                // Each bit in this mask corresponds to the core at
                // the bit offset (i.e. bit 0 corresponds to core 0).
                // A 1 in a bit position means the part is NOT functional,
                // a 0 means the part is functional.
                // Tracks ATTR_CORE_GARD
                uint32_t ecGardMask      :32;  //0:31
            } gardedCores;


            // Used by debug tools to pass buffers around in
            // conjunction with MboxScratch2_t::msg_length
            struct
            {
                uint32_t msgBuffer       :32;  //0:31
            } debug;
        };
        // NOTE: Used for debug tool communication during Hostboot IPL
    };

    // Unfortunately we can't put these static_asserts inside
    // MboxScratch_t even if we use CRTP, because the template type
    // parameter would still be an incomplete type for which sizeof()
    // would error. We could put it in the constructor of
    // MboxScratch_t which would prevent the duplication, but the
    // assert would only be checked when the MboxScratchN_t struct
    // were instantiated, and we want them checked even when the
    // struct is never instantiated.
    static_assert(sizeof(MboxScratch1_t) == sizeof(uint32_t),
                  "MboxScratch1_t must be 32 bits");

    // Mailbox Scratch Register 2 - FW functional Targets
    // SCOM address: 0x00050039
    // CFAM address: 0x2839
    struct MboxScratch2_t : MboxScratch_t<2>
    {
        union
        {
            uint32_t data32;

            // This is the structure of this register according to the
            // P10 IPL flow doc
            struct
            {
                // For each of these masks, a 1 in a bit position
                // means that that part is clock-gated and should not
                // be used.

                uint32_t pciChipletMask     :2;   //0:1
                uint32_t nmmu1Mask          :1;   //2

                // Using DONOTUSE() here causes the compiler to emit a warning
                // whenever this member is used, which helps avoid inadvertent
                // dependencies on reserved bits.
                DONOTUSE()
                uint32_t reserved1          :1;   //3

                uint32_t mcChipletMask      :4;   //4:7
                /* Physical PAU as separate from logical PAU because PAU
                   chiplet can be required for IOPPE, common TL logic and
                   yet both PAUs could be unused */
                uint32_t pauChipletMask     :4;   //08:11
                /* Logical PAU targets inside of the PAU chiplets (2 per
                   physical PAU chiplet). Note that PG will always disable
                   logical PAU.
                   Logical PAUs 1 and 2 are never enabled so the
                   corresponding bits are ignored. */
                uint32_t pauMask            :8;   //12:19
                uint32_t iohsChipletMask    :8;   //20:27

                DONOTUSE()
                uint32_t reserved2          :4;   //28:31
            } clockGatedTargets;

            // Used by debug tools to pass message buffers around in
            // conjunction with MboxScratch1_t::msg_buffer
            struct
            {
                uint32_t msgLength;
            } debug;
        };
        // NOTE: Used for debug tool communication during Hostboot IPL
    };

    static_assert(sizeof(MboxScratch2_t) == sizeof(uint32_t),
                  "MboxScratch2_t must be 32 bits");

    // Mailbox Scratch Register 3 - FW Mode/Control flags
    // SCOM address: 0x0005003A
    // CFAM address: 0x283A
    struct MboxScratch3_t : MboxScratch_t<3>
    {
        enum smtMode_t
        {
            SMT4 = 0, // default
            SMT1 = 1,
            SMT2 = 2
        };

        union
        {
            uint32_t data32;

            struct
            {
                uint32_t istepMode                   :1;   //0

                // Whether or not the SBE should go directly to the
                // runtime (i.e. not to hostboot).
                uint32_t sbeShouldGoToRuntime        :1;   //1

                uint32_t isMpipl                     :1;   //2
                uint32_t fspAttached                 :1;   //3

                DONOTUSE()
                uint32_t reserved1                   :1;   //4 -- do not repurpose

                // If this is set, indicates that the SBE should not
                // send back internal FFDC on any chipop failure
                // response.
                uint32_t sbeSuppressExternalFFDC     :1;   //5

                uint32_t overrideSecurity            :1;   //6
                uint32_t allowAttrOverrides          :1;   //7

                // This is really a tri-state variable, but if the
                // value 3 is specified then it defaults to the value
                // 0 (i.e. SMT4).
                smtMode_t smtMode                    :2;   //8:9

                DONOTUSE()
                uint32_t reserved2                   :1;   //10

                uint32_t disableScomWhiteBlacklist   :1;   //11
                uint32_t disableInvalidScomAddrCheck :1;   //12
                uint32_t mfgMode                     :1;   //13
                uint32_t enableSBEOutput             :1;   //14

                DONOTUSE()
                uint32_t reserved3                   :13;  //15:27 -- Available

                // @TODO RTC: 210612
                // The riskLevel field is being deprecated in P10 but
                // is used in targetservicestart.C
                uint32_t riskLevel                   :4;   //28:31
            } fwModeCtlFlags;
        };
    };

    static_assert(sizeof(MboxScratch3_t) == sizeof(uint32_t),
                  "MboxScratch3_t must be 32 bits");

    // Mailbox Scratch Register 4
    // SCOM address: 0x0005003B
    // CFAM address: 0x283B
    struct MboxScratch4_t : MboxScratch_t<4>
    {
        union
        {
            uint32_t data32;

            // This is the structure of this register according to the
            // P10 IPL flow doc
            struct
            {
                // Maps to ATTR_I2C_BUS_DIV_REF
                union {
                    uint16_t value              :16; //0:15

                    struct
                    {
                        uint16_t divider        :12; //0:11
                        uint16_t roundTripDelay :4;  //12:15
                    };
                } refSpiBusDivider;                  //0:15

                // Maps to ATTR_BOOT_FREQ_MULT
                uint16_t bootFreqMult           :16; //16:31
            } nestBootFreq;

            // This is the structure of this register as used by debug
            // tooling
            //SPLessCmd spcmd; // Note: this can't be an actual member of the
                               // union here because it has a nontrivial
                               // constructor but it's commented for
                               // documentation purposes.

            // This is how the register is used by the SBE message
            // passing code
            struct
            {
                uint32_t sbeMsgProcessingComplete   :1;  // 0
                uint32_t sbeMsgProcessingInProgress :1;  // 1

                DONOTUSE()
                uint32_t reserved                   :30; // 2:31
            } sbeMsgProc;
        };
        // NOTE: Used for debug tooling (SPLessCmd) during Hostboot IPL
        // NOTE: Used for sbe comm during runtime
    };

    static_assert(sizeof(MboxScratch4_t) == sizeof(uint32_t),
                  "MboxScratch4_t must be 32 bits");

    // Mailbox Scratch Register 5 - SBE Usage
    // SCOM address: 0x0005003C
    // CFAM address: 0x283C
    struct MboxScratch5_t : MboxScratch_t<5>
    {
        // Used as the value of debug::magic
        static constexpr uint8_t ISTEP_PROGRESS_MAGIC = 0xAA;

        enum systemIplPhase_t
        {
            HOSTBOOT        = 0,
            CACHE_CONTAINED = 1,
            CHIP_CONTAINED  = 2
        };

        union
        {
            uint32_t data32;

            // This is the structure of this register according to the
            // P10 IPL flow doc
            struct
            {
                // This is a tri-state variable; the value of 3 has no
                // meaning.
                systemIplPhase_t systemIplPhase :2;    //0:1

                // Maps to ATTR_SYS_FORCE_ALL_CORES
                uint32_t forceSbeToInitAllCores :1;    //2

                // Maps to ATTR_DISABLE_HBBL_VECTORS
                // @TODO RTC: 210612
                // Is this needed?
                uint32_t disableHbblVectors     :1;    //3

                DONOTUSE()
                uint32_t reserved               :4;    //4:7

                uint32_t chipletPllMuxDebugCtl  :24;   //8:31
            } hwpCtlFlags;

            // used by istepdispatcher.C to hold debug info during ipl
            struct
            {
                uint32_t magic               :8;    //0:7
                uint32_t stepStart           :1;    //8
                uint32_t stepFinish          :1;    //9

                DONOTUSE()
                uint32_t reserved            :2;    //10:11

                uint32_t internalStep        :4;    //12:15
                uint32_t majorStep           :8;    //16:23
                uint32_t minorStep           :8;    //24:31
            } debug;

            // @TODO RTC: 210612
            // The following struct is slated to be removed but the
            // oldRiskLevel and mcSyncMode members are still used
            // because there are no replacements yet.
            struct
            {
                uint32_t              :1;    //0
                uint32_t              :1;    //1
                uint32_t oldRiskLevel :1;    //2
                uint32_t              :1;    //3
                uint32_t mcSyncMode   :1;    //4
                uint32_t              :1;    //5
                uint32_t              :6;    //6:11
                uint32_t              :20;   //12:31
            } deprecated;
        };
    };

    static_assert(sizeof(MboxScratch5_t) == sizeof(uint32_t),
                  "MboxScratch5_t must be 32 bits");

    // Mailbox Scratch Register 6 - Master/Slave, node/chip selection
    // SCOM address: 0x0005003D
    // CFAM address: 0x283D
    struct MboxScratch6_t : MboxScratch_t<6>
    {
        enum fabricTopologyMode_t
        {
            GGG_C = 0,
            GG_CC = 1
        };

        enum fabricBroadcastMode_t
        {
            ONE_HOP_CHIP_IS_GROUP = 0,
            ONE_HOP_CHIP_IS_NODE  = 1,
            // value 2 is reserved
            TWO_HOP_CHIP_IS_NODE  = 3
        };

        union
        {
            uint32_t data32;

            struct
            {
                DONOTUSE()                            //       Tracks:
                uint32_t reserved1               : 8; // 0:7

                uint32_t cpSpreadFilterPllBypass : 1; // 8     ATTR_FILTER_1_BYPASS
                uint32_t cpFilterPllBypass       : 1; // 9     ATTR_FILTER_2_BYPASS
                uint32_t ioSpreadPllBypass       : 1; // 10    ATTR_FILTER_3_BYPASS
                uint32_t ioPllBypass             : 1; // 11    ATTR_FILTER_4_BYPASS
                uint32_t nestDpllBypass          : 1; // 12    ATTR_NEST_DPLL_BYPASS
                uint32_t pauDpllBypass           : 1; // 13    ATTR_PAU_DPLL_BYPASS
                uint32_t allIohsOmiPcieBypass    : 1; // 14    ATTR_IO_TANK_PLL_BYPASS

                DONOTUSE()
                uint32_t reserved2               : 1; // 15

                uint32_t fabricEffTopologyId     : 4; // 16:19 ATTR_FABRIC_EFF_TOPOLOGY_ID

                fabricTopologyMode_t
                    fabricTopologyMode           : 1; // 20    ATTR_FABRIC_TOPOLOGY_MODE

                DONOTUSE()
                uint32_t reserved3               : 1; // 21

                fabricBroadcastMode_t
                    fabricBroadcastMode          : 2; // 22:23 ATTR_FABRIC_BROADCAST_MODE

                uint32_t isSlave                 : 1; // 24    ATTR_PROC_SBE_MASTER_CHIP
                                                      //       but with inverse polarity

                DONOTUSE()
                uint32_t reserved4               : 3; // 25:27

                uint32_t fabricTopologyId        : 4; // 28:31 ATTR_FABRIC_TOPOLOGY_ID
            } masterSlaveNodeChipSel;
        };
    };

    static_assert(sizeof(MboxScratch6_t) == sizeof(uint32_t),
                  "MboxScratch6_t must be 32 bits");

    // Mailbox Scratch Register 7 - IOHS DL Mode
    // SCOM address: 0x0005003E
    // CFAM address: 0x283E
    struct MboxScratch7_t : MboxScratch_t<7>
    {
        union
        {
            uint32_t data32;

            // This is the structure of this register according to the
            // P10 IPL flow doc
            struct
            {
                // A bit set to 1 means that the part is clock-gated

                uint32_t pdlLayer            :8; // 0:7
                uint32_t ndlLayer            :8; // 8:15
                uint32_t odlLayer            :8; // 16:23

                DONOTUSE()
                uint32_t reserved            :8; // 24:31
            } clockGatedDls;

            // used by ipc mbox code
            struct
            {
                // most significant 4 bytes of an ipc address
                // lower 4 bytes are in MboxScratch8_t
                uint32_t remoteAddrHigh32;
            } ipc;
        };
    };

    static_assert(sizeof(MboxScratch7_t) == sizeof(uint32_t),
                  "MboxScratch7_t must be 32 bits");

    // Mailbox Scratch Register 8
    // SCOM address: 0x0005003F
    // CFAM address: 0x283F
    struct MboxScratch8_t : MboxScratch_t<8>
    {
        union
        {
            uint32_t data32;

            // This is the structure of this register according to the
            // P10 IPL flow doc
            struct
            {
                // @TODO RTC: 210612
                // Update these bits to reflect the correct names, and
                // also add bits for registers 9 and 10 if they go here.
                uint32_t validFwFunctionalEqEc    :1;  //0
                uint32_t validSbeI2cBusSpeed      :1;  //1
                uint32_t validFwMode              :1;  //2
                uint32_t validBootFreq            :1;  //3
                uint32_t validHwpCtlFlags         :1;  //4
                uint32_t validMasterSlaveChipNode :1;  //5
                uint32_t validDrtmPayloadAddr     :1;  //6
                uint32_t validBytes               :1;  //7

                DONOTUSE()
                uint32_t reserved                 :24; //8:31
            } scratchRegValid;

            // used by ipc mbox code
            struct
            {
                // least significant 4 bytes of an ipc address
                // upper 4 bytes are in MboxScratch7_t
                uint32_t remoteAddrLow32;
            } ipc;
        };
    };

    static_assert(sizeof(MboxScratch8_t) == sizeof(uint32_t),
                  "MboxScratch8_t must be 32 bits");

    // Mailbox Scratch Register 9 - PAU, MC Freq
    // SCOM address: 0x00050180
    // CFAM address: 0x0180
    struct MboxScratch9_t : MboxScratch_t<9>
    {
        union
        {
            uint32_t data32;

            struct
            {
                                                  //       Maps to:
                uint32_t pauPllFreqMult      :16; //0:15   ATTR_PAU_FREQ_MULT
                uint32_t mc0PllBucket        :3;  //16:18  ATTR_MC0_PLL_BUCKET
                uint32_t mc1PllBucket        :3;  //19:21  ATTR_MC1_PLL_BUCKET
                uint32_t mc2PllBucket        :3;  //22:24  ATTR_MC2_PLL_BUCKET
                uint32_t mc3PllBucket        :3;  //25:27  ATTR_MC3_PLL_BUCKET

                // @TODO RTC: 210612
                // Is this needed?
                uint32_t ndlMeshCtlSetup     :4;  //28:31  ATTR_NDL_MESHCTRL_SETUP
            } pauMcFreq;
        };
    };

    static_assert(sizeof(MboxScratch9_t) == sizeof(uint32_t),
                  "MboxScratch9_t must be 32 bits");

    // Mailbox Scratch Register 10 - IOHS PLL
    // SCOM address: 0x00050181
    // CFAM address: 0x0181
    struct MboxScratch10_t : MboxScratch_t<10>
    {
        union
        {
            uint32_t data32;

            struct
            {
                                                 //       Maps to:
                uint32_t iohs0PllBucket      :3; //0:2    ATTR_IOHS0_PLL_BUCKET
                uint32_t iohs1PllBucket      :3; //3:5    ATTR_IOHS1_PLL_BUCKET
                uint32_t iohs2PllBucket      :3; //6:8    ATTR_IOHS2_PLL_BUCKET
                uint32_t iohs3PllBucket      :3; //9:11   ATTR_IOHS3_PLL_BUCKET
                uint32_t iohs4PllBucket      :3; //12:14  ATTR_IOHS4_PLL_BUCKET
                uint32_t iohs5PllBucket      :3; //15:17  ATTR_IOHS5_PLL_BUCKET
                uint32_t iohs6PllBucket      :3; //18:20  ATTR_IOHS6_PLL_BUCKET
                uint32_t iohs7PllBucket      :3; //21:23  ATTR_IOHS7_PLL_BUCKET

                DONOTUSE()
                uint32_t reserved            :8; //24:31
            } iohsPll;
        };
    };

    static_assert(sizeof(MboxScratch10_t) == sizeof(uint32_t),
                  "MboxScratch10_t must be 32 bits");

    // SCOM address: 0x00050182
    // CFAM address: 0x0182
    struct MboxScratch11_t : MboxScratch_t<11>
    {
        // Placeholder
        uint32_t value;
    };

    static_assert(sizeof(MboxScratch11_t) == sizeof(uint32_t),
                  "MboxScratch11_t must be 32 bits");

    // SCOM address: 0x00050183
    // CFAM address: 0x0183
    struct MboxScratch12_t : MboxScratch_t<12>
    {
        // Placeholder
        uint32_t value;
    };

    static_assert(sizeof(MboxScratch12_t) == sizeof(uint32_t),
                  "MboxScratch12_t must be 32 bits");

    // SCOM address: 0x00050184
    // CFAM address: 0x0184
    struct MboxScratch13_t : MboxScratch_t<13>
    {
        // Placeholder
        uint32_t value;
    };

    static_assert(sizeof(MboxScratch13_t) == sizeof(uint32_t),
                  "MboxScratch13_t must be 32 bits");

    // SCOM address: 0x00050185
    // CFAM address: 0x0185
    struct MboxScratch14_t : MboxScratch_t<14>
    {
        // Placeholder
        uint32_t value;
    };

    static_assert(sizeof(MboxScratch14_t) == sizeof(uint32_t),
                  "MboxScratch14_t must be 32 bits");

    // SCOM address: 0x00050186
    // CFAM address: 0x0186
    struct MboxScratch15_t : MboxScratch_t<15>
    {
        // Placeholder
        uint32_t value;
    };

    static_assert(sizeof(MboxScratch15_t) == sizeof(uint32_t),
                  "MboxScratch15_t must be 32 bits");

    // SCOM address: 0x00050187
    // CFAM address: 0x0187
    struct MboxScratch16_t : MboxScratch_t<16>
    {
        // Placeholder
        uint32_t value;
    };

    static_assert(sizeof(MboxScratch16_t) == sizeof(uint32_t),
                  "MboxScratch16_t must be 32 bits");
};
};
#endif
