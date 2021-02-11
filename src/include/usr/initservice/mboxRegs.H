/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/initservice/mboxRegs.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
                // This 0:31 range is used in src/usr/hwas/hwasPlat.C
                // verifyDeconfiguration() function, if that's edited here it
                // must also be edited there.
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
            // The ranges used here are also used in src/usr/hwas/hwasPlat.C
            // verifyDeconfiguration() function, if they're edited here they
            // must also be edited there.
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

                DONOTUSE() // Previously the risk_level field
                uint32_t reserved4                   :4;   //28:31
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
                // Maps to ATTR_SPI_BUS_DIV_REF
                union {
                    uint16_t value              :16; //0:15

                    struct
                    {
                        uint16_t divider        :12; //0:11
                        uint16_t roundTripDelay :4;  //12:15
                    };
                } refSpiBusDivider;                  //0:15

                // Maps to ATTR_FREQ_CORE_BOOT_MHZ
                uint16_t coreBootFreqMhz        :16; //16:31
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

        enum sbeExPolicy_t
        {
            HB_DEFAULT                   = 0,
            CRONUS_MAX_ACTIVE            = 1,
            HB_MAX_FOOTPRINT             = 2,
            HB_MAX_THREADS               = 4,
            HB_MAX_FOOTPRINT_MAX_THREADS = HB_MAX_FOOTPRINT | HB_MAX_THREADS
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
                systemIplPhase_t systemIplPhase :2; //0:1

                DONOTUSE()
                uint32_t reserved1              :1; //2

                // Maps to ATTR_DISABLE_HBBL_VECTORS
                uint32_t disableHbblVectors     :1; //3

                // Maps to ATTR_SBE_SELECT_EX_POLICY
                sbeExPolicy_t sbeSelectExPolicy :3; //4:6

                DONOTUSE()
                uint32_t reserved2              :5; //7:11

                /* NOTE: bits 12:29 are don't-cares if the chiplet is knocked
                 * out. Chip-level mux selects are controlled in separate root
                 * control register */

                uint32_t iohs0Lcpll             :2; //12:13
                uint32_t iohs1Lcpll             :2; //14:15

                DONOTUSE()
                uint32_t reserved3              :10;//16:25

                uint32_t pci0Lcpll              :2; //26:27
                uint32_t pci1Lcpll              :2; //28:29

                DONOTUSE()
                uint32_t reserved4              :2; //30:31
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
            PROC_FABRIC_TOPOLOGY_MODE_MODE0, //GGG_C
            PROC_FABRIC_TOPOLOGY_MODE_MODE1  //GG_CC
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
                uint32_t reserved1                :8; // 0:7

                uint32_t forceTodFilterPllBypass  :1; // 8     ATTR_CP_PLLTODFLT_BYPASS
                uint32_t forceNestFilterPllBypass :1; // 9     ATTR_CP_PLLNESTFLT_BYPASS
                uint32_t forceIoFilterPllBypass   :1; // 10    ATTR_CP_PLLIOFLT_BYPASS
                uint32_t
                   forceIoSpreadSpectrumPllBypass :1; // 11    ATTR_CP_PLLIOSSFLT_BYPASS
                uint32_t forceNestDpllBypass      :1; // 12    ATTR_NEST_DPLL_BYPASS
                uint32_t forcePauDpllBypass       :1; // 13    ATTR_PAU_DPLL_BYPASS
                uint32_t
                   forceAllIohsOmiPcieBypass      :1; // 14    ATTR_IO_TANK_PLL_BYPASS

                DONOTUSE()
                uint32_t reserved2                :1; // 15

                uint32_t fabricEffTopologyId      :4; // 16:19 ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID

                fabricTopologyMode_t
                    fabricTopologyMode            :1; // 20    ATTR_PROC_FABRIC_TOPOLOGY_MODE

                DONOTUSE()
                uint32_t reserved3                :1; // 21

                fabricBroadcastMode_t
                    fabricBroadcastMode           :2; // 22:23 ATTR_PROC_FABRIC_BROADCAST_MODE

                // If this is set to 0 then this overrides the external C4 pin
                // indicating master/slave; if this is set to 1 then use the
                // external C4 pin to determine whether master or slave
                uint32_t isMaster                 :1; // 24    ATTR_PROC_SBE_MASTER_CHIP

                DONOTUSE()
                uint32_t reserved4                :3; // 25:27

                uint32_t fabricTopologyId         :4; // 28:31 ATTR_PROC_FABRIC_TOPOLOGY_ID
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

            // This is the structure of this register according to the P10 IPL
            // flow doc if the chip IS NOT configured in chip-contained mode
            struct
            {
                DONOTUSE()
                uint32_t reserved1           :8; // 0:7

                // A bit set to 1 means that the part is power-gated
                uint32_t ndlLayerMask        :8; // 8:15

                DONOTUSE()
                uint32_t reserved2           :16;// 16:31
            } clockGatedDls;

            // This is the structure of this register according to the P10 IPL
            // flow doc if the chip IS configured in chip-contained mode
            struct
            {
                // A bitvector of active cores, where bit X indicates whether
                // core X is active
                // Maps to ATTR_CHIP_CONTAINED_ACTIVE_CORES_VEC
                uint32_t activeCoresMask     :32;//0:31
            } activeCores;

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
                uint32_t validFwFunctionalEqEc    :1;  //0
                uint32_t validSbeI2cBusSpeed      :1;  //1
                uint32_t validFwMode              :1;  //2
                uint32_t validBootFreq            :1;  //3
                uint32_t validHwpCtlFlags         :1;  //4
                uint32_t validMasterSlaveChipNode :1;  //5
                uint32_t validDrtmPayloadAddr     :1;  //6
                uint32_t validBytes               :1;  //7
                uint32_t validPauMcFreq           :1;  //8
                uint32_t validIohsPll             :1;  //9

                // TODO: Update these members when registers are named
                uint32_t validReg11               :1;  //10
                uint32_t validReg12               :1;  //11
                uint32_t validReg13               :1;  //12
                uint32_t validReg14               :1;  //13
                uint32_t validReg15               :1;  //14
                uint32_t validReg16               :1;  //15

                DONOTUSE()
                uint32_t reserved                 :16; //16:31
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
                uint32_t pauPllFreqMhz       :16; //0:15   ATTR_FREQ_PAU_MHZ

                // These bitfields are the least-significant bits of the array
                // entries in the attribute that they reflect
                uint32_t mc0PllBucket        :3;  //16:18  ATTR_MC_PLL_BUCKET[0]
                uint32_t mc1PllBucket        :3;  //19:21  ATTR_MC_PLL_BUCKET[1]
                uint32_t mc2PllBucket        :3;  //22:24  ATTR_MC_PLL_BUCKET[2]
                uint32_t mc3PllBucket        :3;  //25:27  ATTR_MC_PLL_BUCKET[3]

                // @TODO RTC: 212818
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

            // This is the structure of this register if the chip IS NOT
            // configured in chip-contained mode
            struct
            {
                // These bitfields are the least-significant bits of the array
                // entries in the attribute that they reflect
                                                 //       Maps to:
                uint32_t iohs0PllBucket      :4; //0:3    ATTR_IOHS_PLL_BUCKET[0]
                uint32_t iohs1PllBucket      :4; //4:7    ATTR_IOHS_PLL_BUCKET[1]
                uint32_t iohs2PllBucket      :4; //8:11   ATTR_IOHS_PLL_BUCKET[2]
                uint32_t iohs3PllBucket      :4; //12:15  ATTR_IOHS_PLL_BUCKET[3]
                uint32_t iohs4PllBucket      :4; //16:19  ATTR_IOHS_PLL_BUCKET[4]
                uint32_t iohs5PllBucket      :4; //20:23  ATTR_IOHS_PLL_BUCKET[5]
                uint32_t iohs6PllBucket      :4; //24:27  ATTR_IOHS_PLL_BUCKET[6]
                uint32_t iohs7PllBucket      :4; //28:31  ATTR_IOHS_PLL_BUCKET[7]
            } iohsPll;

            // This is the structure of this register if the chip IS configured
            // in chip-contained mode
            struct
            {
                // A bitvector of chip contained backing caches, where bit X
                // indicates whether cache X is active
                // Maps to ATTR_CHIP_CONTAINED_BACKING_CACHES_VEC
                uint32_t backingCachesMask   :32; //0:31
            } chipCaches;
        };
    };

    static_assert(sizeof(MboxScratch10_t) == sizeof(uint32_t),
                  "MboxScratch10_t must be 32 bits");

    // SCOM address: 0x00050182
    // CFAM address: 0x0182
    struct MboxScratch11_t : MboxScratch_t<11>
    {
        // For P10 SBE will use this scratch register to pass FFDC on a secureboot validation
        // error up to hostboot to log an error
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
