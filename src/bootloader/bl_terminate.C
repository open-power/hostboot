/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/bootloader/bl_terminate.C $                               */
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
#include <bootloader/bootloader.H>
#include <bootloader/hbblreasoncodes.H>
#include <arch/ppc.H>

#define bl_terminate_C

// Redefine kernel_TIDataArea to use space in Bootloader data
#define kernel_TIDataArea Bootloader::g_blData->bl_TIDataArea

#include <../kernel/terminate.C>

#define UINT64_HIGH(data) ((data & 0xFFFFFFFF00000000) >> 32)
#define UINT64_LOW(data) (data & 0x00000000FFFFFFFF)
#define WORD7_WORD8(data) UINT64_HIGH(data), UINT64_LOW(data)


extern "C"
void kernel_std_exception()
{
    uint64_t exception = getSPRG2();
    uint64_t nip = getSRR0();

    /*@
     * @errortype
     * @moduleid     Bootloader::MOD_BOOTLOADER_TERMINATE
     * @reasoncode   Bootloader::RC_STD_EXCEPTION
     * @userdata1[0:15]   TI_WITH_SRC
     * @userdata1[16:31]  TI_BOOTLOADER
     * @userdata1[32:63]  Exception vector address
     * @userdata2    NIP / SRR0
     * @devdesc      Exception occurred during execution of HBBL
     * @custdesc     A problem occurred while running processor
     *               boot code.
     */
    bl_terminate(Bootloader::MOD_BOOTLOADER_TERMINATE,
                 Bootloader::RC_STD_EXCEPTION,
                 WORD7_WORD8(nip),
                 true,
                 exception);
}

extern "C"
void kernel_std_exception_w_dsisr()
{
    uint64_t exception = getSPRG2();
    uint64_t nip = getSRR0();
    uint64_t dsisr = getDSISR();

    /*@
     * @errortype
     * @moduleid     Bootloader::MOD_BOOTLOADER_TERMINATE
     * @reasoncode   Bootloader::RC_STD_EX_W_DSISR
     * @userdata1[0:15]   TI_WITH_SRC
     * @userdata1[16:31]  TI_BOOTLOADER
     * @userdata1[32:63]  Exception vector address
     * @userdata2    NIP / SRR0
     * @devdesc      Exception occurred during execution of HBBL
     * @custdesc     A problem occurred while running processor
     *               boot code.
     */
    kernel_TIDataArea.src.SRCword3 = UINT64_HIGH(dsisr);
    kernel_TIDataArea.src.SRCword4 = UINT64_LOW(dsisr);
    bl_terminate(Bootloader::MOD_BOOTLOADER_TERMINATE,
                 Bootloader::RC_STD_EX_W_DSISR,
                 WORD7_WORD8(nip),
                 true,
                 exception);
}

extern "C"
void kernel_std_exception_w_srr1()
{
    uint64_t exception = getSPRG2();
    uint64_t nip = getSRR0();
    uint64_t srr1 = getSRR1();

    /*@
     * @errortype
     * @moduleid     Bootloader::MOD_BOOTLOADER_TERMINATE
     * @reasoncode   Bootloader::RC_STD_EX_W_SRR1
     * @userdata1[0:15]   TI_WITH_SRC
     * @userdata1[16:31]  TI_BOOTLOADER
     * @userdata1[32:63]  Exception vector address
     * @userdata2    NIP / SRR0
     * @devdesc      Exception occurred during execution of HBBL
     * @custdesc     A problem occurred while running processor
     *               boot code.
     */
    kernel_TIDataArea.src.SRCword3 = UINT64_HIGH(srr1);
    kernel_TIDataArea.src.SRCword4 = UINT64_LOW(srr1);
    bl_terminate(Bootloader::MOD_BOOTLOADER_TERMINATE,
                 Bootloader::RC_STD_EX_W_SRR1,
                 WORD7_WORD8(nip),
                 true,
                 exception);
}

extern "C"
void kernel_hype_exception()
{
    uint64_t exception = getSPRG2();
    uint64_t nip = getHSRR0();

    /*@
     * @errortype
     * @moduleid     Bootloader::MOD_BOOTLOADER_TERMINATE
     * @reasoncode   Bootloader::RC_HYPE_EXCEPTION
     * @userdata1[0:15]   TI_WITH_SRC
     * @userdata1[16:31]  TI_BOOTLOADER
     * @userdata1[32:63]  Exception vector address
     * @userdata2    NIP / HSRR0
     * @devdesc      Exception occurred during execution of HBBL
     * @custdesc     A problem occurred while running processor
     *               boot code.
     */
    bl_terminate(Bootloader::MOD_BOOTLOADER_TERMINATE,
                 Bootloader::RC_HYPE_EXCEPTION,
                 WORD7_WORD8(nip),
                 true,
                 exception);
}

#undef bl_terminate_C
