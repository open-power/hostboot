/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/bootloader/bl_terminate.C $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2022                        */
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
#include <bootloader/bl_console.H>
#include <bootloader/bl_xscom.H>
#include <arch/ppc.H>
#include <stddef.h>

#define bl_terminate_C

// Redefine kernel_TIDataArea to use space in Bootloader data
#define kernel_TIDataArea g_blData->bl_TIDataArea

#include <../kernel/terminate.C>

#define UINT64_HIGH(data) ((data & 0xFFFFFFFF00000000) >> 32)
#define UINT64_LOW(data) (data & 0x00000000FFFFFFFF)
#define WORD7_WORD8(data) UINT64_HIGH(data), UINT64_LOW(data)

void bl_terminate(uint8_t  i_moduleID,
                  uint16_t i_reasoncode,
                  uint32_t i_word7,
                  uint32_t i_word8,
                  bool     i_executeTI,
                  uint64_t i_failAddr,
                  uint32_t i_error_info)
{
    termWriteSRC(TI_BOOTLOADER,
                 i_reasoncode,
                 i_failAddr,
                 i_error_info);

    termModifySRC(i_moduleID,
                  i_word7,
                  i_word8);

    // ptr to the TI data area structure
    HB_TI_DataArea *TI_DataAreaPtr = reinterpret_cast<HB_TI_DataArea*>(
        (HBB_WORKING_ADDR | Bootloader::IGNORE_HRMOR_MASK) + 0x2008);
    *TI_DataAreaPtr = g_blData->bl_TIDataArea;

    // 0xBC = hostboot first byte
    // 0x8A = general hostboot firmware
    bl_console::putString("Fatal Error SRC: ");
    long unsigned int type = TI_DataAreaPtr->type;
    const unsigned char* error_src = reinterpret_cast<unsigned char*>(&type);
    bl_console::displayHex(error_src, sizeof(type));

    // convert int reasoncode to hex
    const unsigned char* start_addr = reinterpret_cast<unsigned char*>(&i_reasoncode);
    bl_console::displayHex(start_addr, sizeof(i_reasoncode));

    // display the progress buffer along with TI area dump
    bl_console::putString("\r\n\nDump:\r\n");
    start_addr = reinterpret_cast<const unsigned char*>(g_blData);
    size_t offset = offsetof(Bootloader::blData, bl_hbbSection);
    bl_console::displayHex(start_addr, offset);

    if(i_executeTI)
    {
        terminateExecuteTI();
    }
}


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


namespace Bootloader
{


/**
  * @brief Forces a checkstop when LPC Error(s) are seen such that PRD
  *        can appropriately handle the callout
  *
  * @return - void, since this function should theoretically not return
  */
void bl_forceCheckstopOnLpcErrors()
{
    // When LPC errors are seen force a checkstop with this signature:
    // N1_LOCAL_FIR[61] - Host detected LPC timeout
    // PRD running on the BMC or FSP will then recognize this specific checkstop and
    // handle the callout appropriately
    // NOTE: No console trace because LPC bus can't be trusted
    BOOTLOADER_TRACE(BTLDR_TRC_LPC_ERR_FORCE_XSTOP);

    const uint64_t data_all_clear    = 0x0000000000000000ull;
    const uint64_t data_all_set      = 0xFFFFFFFFFFFFFFFFull;
    const uint64_t data_clear_bit_61 = 0xFFFFFFFFFFFFFFFBull;
    const uint64_t data_set_bit_61   = 0x0000000000000004ull;

    const uint64_t N1_LOCAL_FIR_MASK_REG_SCOM_WOR  = 0x03040105ull;
    const uint64_t N1_LOCAL_FIR_MASK_REG_SCOM_WAND = 0x03040104ull;
    const uint64_t N1_LOCAL_FIR_ACTION0_REG_SCOM   = 0x03040106ull;
    const uint64_t N1_LOCAL_FIR_ACTION1_REG_SCOM   = 0x03040107ull;
    const uint64_t N1_LOCAL_FIR_REG_SCOM_WOR       = 0x03040102ull;


    const size_t NUM_OPS = 5; // See 5 steps below
    uint64_t data_array[NUM_OPS];
    uint64_t addr_array[NUM_OPS];
    size_t scomSize = sizeof(uint64_t);

    // 1) write-OR N1 LOCAL FIR MASK to disable everything
    data_array[0] = data_all_set;
    addr_array[0] = N1_LOCAL_FIR_MASK_REG_SCOM_WOR;

    // Steps 2 and 3 will set ACTION0 and ACTION1 registers such that the N1_LOCAL_FIR[61]
    // FIR bit will cause a checkstop
    // 2) write ACTION0 to zero (thus clearing bit 61)
    data_array[1] = data_all_clear;
    addr_array[1] = N1_LOCAL_FIR_ACTION0_REG_SCOM;

    // 3) write ACTION1 to zero (thus clearing bit 61)
    data_array[2] = data_all_clear;
    addr_array[2] = N1_LOCAL_FIR_ACTION1_REG_SCOM;

    // 4) write-AND N1 LOCAL FIR MASK to clear bit 61 to just allow this 1 attention through
    data_array[3] = data_clear_bit_61;
    addr_array[3] = N1_LOCAL_FIR_MASK_REG_SCOM_WAND;

    // 5) write-OR N1 LOCAL FIR bit 61 to trigger checkstop
    data_array[4] = data_set_bit_61;
    addr_array[4] = N1_LOCAL_FIR_REG_SCOM_WOR;

    for (size_t i = 0; i < NUM_OPS; i++)
    {
        Bootloader::hbblReasonCode rc = XSCOM::xscomPerformOp(DeviceFW::WRITE,
                                   &data_array[i],
                                   scomSize,
                                   addr_array[i]);

        // Ignore rc because best hope is that we can still properly cause the checkstop
        // NOTE: need this block otherwise compiler thinks rc is unused
        if(rc)
        {
          rc = Bootloader::RC_NO_ERROR;
        }
    }

    // At this point the system should checkstop, but just return back
    // into the existing fail path if it doesn't
    return;

} // end of bl_forceCheckstopOnOpbMasterTimeout()


} // end of namespace BOOTLOADER

#undef bl_terminate_C
