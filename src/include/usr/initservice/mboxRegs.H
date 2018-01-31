/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/initservice/mboxRegs.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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

namespace INITSERVICE
{
namespace SPLESS
{
    const   uint32_t    MBOX_SCRATCH_REG1 =   0x00050038; //CFAM 2838
    const   uint32_t    MBOX_SCRATCH_REG2 =   0x00050039; //CFAM 2839
    const   uint32_t    MBOX_SCRATCH_REG3 =   0x0005003a; //CFAM 283A
    const   uint32_t    MBOX_SCRATCH_REG4 =   0x0005003b; //CFAM 283B
    const   uint32_t    MBOX_SCRATCH_REG5 =   0x0005003c; //CFAM 283C
    const   uint32_t    MBOX_SCRATCH_REG6 =   0x0005003d; //CFAM 283D
    const   uint32_t    MBOX_SCRATCH_REG7 =   0x0005003e; //CFAM 283E
    const   uint32_t    MBOX_SCRATCH_REG8 =   0x0005003f; //CFAM 283F

    enum
    {
        SCRATCH_1 =   0x0, //Location in array is reg num -1
        SCRATCH_2 =   0x1,
        SCRATCH_3 =   0x2,
        SCRATCH_4 =   0x3,
        SCRATCH_5 =   0x4,
        SCRATCH_6 =   0x5,
        SCRATCH_7 =   0x6,
        SCRATCH_8 =   0x7,
    };

    // Mailbox Scratch Register 1
    union MboxScratch1_t
    {
        uint32_t data32;
        struct
        {
            // bit=1 means part is NOT functional
            uint32_t eqGard          :8;   //0:7
            uint32_t ecGard          :24;  //8:31
        } PACKED;
        // NOTE: Used for debug tool communication during Hostboot IPL
    };

    // Mailbox Scratch Register 2
    union MboxScratch2_t
    {
        uint32_t data32;
        struct
        {
            uint32_t i2cRefClockDiv  :16;  //00:15
            uint32_t ndlMeshCtl      :4;   //16:19
            uint32_t reserved        :12;  //20:31
        } PACKED;
        // NOTE: Used for debug tool communication during Hostboot IPL
    };

    // Mailbox Scratch Register 3
    union MboxScratch3_t
    {
        uint32_t data32;
        struct
        {
            uint32_t istepMode           :1;   //0
            uint32_t goToRuntime         :1;   //1
            uint32_t isMpipl             :1;   //2
            uint32_t fspAttached         :1;   //3
            uint32_t reserved            :1;   //4 -- do not repurpose
            uint32_t sbeInternalFFDC     :1;   //5
            uint32_t overrideSecurity    :1;   //6
            uint32_t allowAttrOverrides  :1;   //7
            uint32_t smtMode             :2;   //8:9
            uint32_t unused              :18;  //10:27 -- Available
            uint32_t riskLevel           :4;   //28:31
        } PACKED;
        // NOTE: Used for debug tool communication during Hostboot IPL
    };

    // Mailbox Scratch Register 4
    union MboxScratch4_t
    {
        uint32_t data32;
        struct
        {
            uint32_t bootFreqMult        :16;   //0:15
            uint32_t cpFilterBypass      :1;    //16
            uint32_t ssFilterBypass      :1;    //17
            uint32_t ioFilterBypass      :1;    //18
            uint32_t dpllBypass          :1;    //19
            uint32_t nestMemXoPcieBypass :1;    //20
            uint32_t obusHalfSpeed       :1;    //21
            uint32_t reserved            :2;    //22:23
            uint32_t nestPllBucket       :8;    //24:31
        } PACKED;
        // NOTE: Used for debug tooling (SPLessCmd) during Hostboot IPL
        // NOTE: Used for sbe comm during runtime
    };

    // Mailbox Scratch Register 5 - SBE Usage
    union MboxScratch5_t
    {
        uint32_t data32;
        struct
        {
            uint32_t cacheContained      :1;    //0
            uint32_t initAllCores        :1;    //1
            uint32_t oldRiskLevel        :1;    //2
            uint32_t noBLVectors         :1;    //3
            uint32_t mcSyncMode          :1;    //4
            uint32_t slowPci             :1;    //5
            uint32_t reserved            :6;    //6:11
            uint32_t clockPllMux         :20;   //12:31
        } PACKED;
    };
    // Mailbox Scratch Register 5 - HB Usage
    union MboxScratch5_HB_t
    {
        uint32_t data32;
        struct
        {
            uint32_t magic               :8;    //0:7
            uint32_t stepStart           :1;    //8
            uint32_t stepFinish          :1;    //9
            uint32_t reserved            :2;    //10:11
            uint32_t internalStep        :4;    //12:15
            uint32_t majorStep           :8;    //16:23
            uint32_t minorStep           :8;    //24:31
        } PACKED;
    };
    const uint8_t ISTEP_PROGRESS_MAGIC = 0xAA;

    // Mailbox Scratch Register 6
    union MboxScratch6_t
    {
        uint32_t data32;
        struct
        {
            uint32_t reserved1           :23;   //0:22
            uint32_t groupPumpMode       :1;    //23
            uint32_t isSlave             :1;    //24
            uint32_t reserved2           :1;    //25
            uint32_t groupId             :3;    //26:28
            uint32_t chipId              :3;    //29:31
        } PACKED;
    };

    // Mailbox Scratch Register 7
    union MboxScratch7_t
    {
        uint32_t data32;
        struct
        {
            uint32_t drtmPayloadAddrMb   :32;   //0
        } PACKED;
    };

    // Mailbox Scratch Register 8
    union MboxScratch8_t
    {
        uint32_t data32;
        struct
        {
            uint32_t validFwFunctionalEqEc    :1;  //0
            uint32_t validSbeI2cBusSpeed      :1;  //1
            uint32_t validFwMode              :1;  //2
            uint32_t validBootFreq            :1;  //3
            uint32_t validHwpControlFlags     :1;  //4
            uint32_t validMasterSlaveChipNode :1;  //5
            uint32_t validDrtmPayloadAddr     :1;  //6
            uint32_t validBytes               :1;  //7
            uint32_t reserved                 :24; //8:31
        } PACKED;
    };

};
};
#endif
