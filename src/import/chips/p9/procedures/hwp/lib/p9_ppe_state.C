/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/lib/p9_ppe_state.C $       */
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
/// @file  p9_ppe_state.C
/// @brief Get PPE's internal state
///
/// *HWP HW Owner        : Ashish More <ashish.more.@in.ibm.com>
/// *HWP HW Backup Owner : Brian Vanderpool <vanderp@us.ibm.com>
/// *HWP FW Owner        : Sangeetha T S <sangeet2@in.ibm.com>
/// *HWP Team            : PM
/// *HWP Level           : 2
/// *HWP Consumed by     : SBE, Cronus
///
/// @verbatim
///
/// Procedure Summary:
///   - Dump out PPE's internal state
///
/// @endverbatim

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <fapi2.H>
#include <p9_ppe_state.H>
#include <p9_ppe_utils.H>
#include <p9_ppe_utils.C>


#include <p9_hcd_common.H>
// Vector defining the special acceess egisters
//std::vector<uint16_t> v_ppe_special_regs =
//{
//    { MSR   },
//    { CR    },
//};
// Vector defining the other xsr regs
//std::vector<uint16_t> v_ppe_xsr_regs =
//{
//    { XSR    },
//    { IAR    },
//    { IR     },
//    { EDR    },
//    { SPRG0  },

//};


// Vector defining the major SPRs
// Note: SPRG0 is not include as it is saved and restored as the means for
// accessing the other SPRS
std::vector<uint16_t> v_ppe_major_sprs =
{
    { CTR    },
    { LR     },
    { ISR    },
    { SRR0   },
    { SRR1   },
    { TCR    },
    { TSR    },
};

// Vector defining the minor SPRs
std::vector<uint16_t> v_ppe_minor_sprs =
{
    { DACR  },
    { DBCR  },
    { DEC   },
    { IVPR  },
    { PIR   },
    { PVR   },
    { XER   },
};

// Vector defining the GPRs
std::vector<uint16_t> v_ppe_gprs =
{
    { R0 },
    { R1 },
    { R2 },
    { R3 },
    { R4 },
    { R5 },
    { R6 },
    { R7 },
    { R8 },
    { R9 },
    { R10},
    { R13},
    { R28},
    { R29},
    { R30},
    { R31},
};

//-----------------------------------------------------------------------------

/**
 * @brief Perform PPE internal reg "read" operation
 * @param[in]   i_target        Chip Target
 * @param[in]   i_base_address  Base SCOM address of the PPE
 * @param[in]   i_mode          PPE Dump Mode
 * @param[out]  v_ppe_minor_sprs_value   Returned data
 * @param[out]  v_ppe_major_sprs_value   Returned data
 * @param[out]  v_ppe_xirs_value   Returned data
 * @param[out]  v_ppe_gprs_value   Returned data
 * @param[out]  v_ppe_special_sprs_value   Returned data
 * @return  fapi2::ReturnCode
 */
fapi2::ReturnCode
ppe_state_data(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
               const uint64_t i_base_address,
               const PPE_DUMP_MODE i_mode,
               std::vector<PPERegValue_t>& v_ppe_minor_sprs_value,
               std::vector<PPERegValue_t>& v_ppe_major_sprs_value,
               std::vector<PPERegValue_t>& v_ppe_xirs_value,
               std::vector<PPERegValue_t>& v_ppe_gprs_value,
               std::vector<PPERegValue_t>& v_ppe_special_sprs_value)
{
    fapi2::buffer<uint64_t> l_raminstr;
    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint32_t> l_data32;
    fapi2::buffer<uint32_t> l_gpr0_save;
    fapi2::buffer<uint64_t> l_sprg0_save;
    bool l_ppe_halt_state = false;
    PPERegValue_t l_regVal;

    char outstr[32];

    FAPI_INF("Base Address : 0x%08llX", i_base_address);

    //If requested make sense to halt PPE first if requested (XIR reads are not dependent on this ,
    //But XSR content can change after halt and it is better to capture XSR content after halt(if requested)
    if (i_mode == HALT)
    {
        FAPI_TRY(ppe_halt(i_target, i_base_address));

    }

    if (i_mode == FORCE_HALT)
    {
        FAPI_TRY(ppe_force_halt(i_target, i_base_address));

    }

    FAPI_INF("------   XIRs   ------");
    // XSR and IAR
    FAPI_TRY(getScom(i_target, i_base_address + PPE_XIDBGPRO, l_data64), "Error in GETSCOM");
    l_data64.extractToRight(l_data32, 0, 32);
    sprintf(outstr, "XSR");
    FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
    l_regVal.number = XSR;   //Using some unique number which will not clash with any existing PPE SPRN
    l_regVal.value = l_data32;
    v_ppe_xirs_value.push_back(l_regVal);

    l_data64.extractToRight(l_data32, 32, 32);
    sprintf(outstr, "IAR");
    FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
    l_regVal.number = IAR;
    l_regVal.value = l_data32;
    v_ppe_xirs_value.push_back(l_regVal);

    // IR and EDR
    FAPI_TRY(getScom(i_target, i_base_address + PPE_XIRAMEDR, l_data64), "Error in GETSCOM");
    l_data64.extractToRight(l_data32, 0, 32);
    sprintf(outstr, "IR");
    FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
    l_regVal.number = IR;
    l_regVal.value = l_data32;
    v_ppe_xirs_value.push_back(l_regVal);


    l_data64.extractToRight(l_data32, 32, 32);
    sprintf(outstr, "EDR");
    FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
    l_regVal.number = EDR;
    l_regVal.value = l_data32;
    v_ppe_xirs_value.push_back(l_regVal);


    // Save SPRG0
    FAPI_TRY(getScom(i_target, i_base_address + PPE_XIRAMDBG, l_sprg0_save), "Error in GETSCOM");
    l_sprg0_save.extractToRight(l_data32, 32, 32);
    sprintf(outstr, "SPRG0");
    FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
    l_regVal.number = SPRG0;
    l_regVal.value = l_data32;
    v_ppe_xirs_value.push_back(l_regVal);


    //Initially Check for halt
    FAPI_TRY(getScom(i_target, i_base_address + PPE_XIRAMDBG, l_data64), "Error in GETSCOM");

    if (l_data64.getBit(0, 1))
    {
        l_ppe_halt_state  = true;

    }
    else
    {
        l_ppe_halt_state  = false;
    }

    //IF PPE is halted(by default or due to halt/force_halt swicthes) or SNAPSHOT mode , get the other internal registers
    if ( ((i_mode == SNAPSHOT) || l_ppe_halt_state) && (i_mode != XIRS))
    {
        //If SNAPSHOT mode and PPE is not halted do XCR halt; before ramming
        if((i_mode == SNAPSHOT) && !(l_ppe_halt_state))
        {
            FAPI_TRY(ppe_halt(i_target, i_base_address));
        }

        FAPI_DBG("Save GPR0");
        l_raminstr.flush<0>().insertFromRight(ppe_getMtsprInstruction(R0, SPRG0), 0, 32);
        FAPI_DBG("ppe_getMtsprInstruction(%d, SPRG0): 0x%16llX", 0, l_raminstr );

        FAPI_TRY(ppe_RAMRead(i_target, i_base_address, l_raminstr, l_gpr0_save));
        FAPI_DBG("Saved GPR0 value : 0x%08llX", l_gpr0_save );

        FAPI_INF("---   Major SPRs    --");

        for (auto it : v_ppe_major_sprs)
        {

            // SPR to R0
            l_raminstr.flush<0>().insertFromRight(ppe_getMfsprInstruction(0, it), 0, 32);
            FAPI_DBG("ppe_getMfsprInstruction(R0, %5d): 0x%16llX", it, l_raminstr );
            FAPI_TRY(ppe_pollHaltState(i_target, i_base_address));
            FAPI_TRY(fapi2::putScom(i_target, i_base_address + PPE_XIRAMEDR, l_raminstr));

            // R0 to SPRG0
            l_raminstr.flush<0>().insertFromRight(ppe_getMtsprInstruction(0, SPRG0), 0, 32);
            FAPI_DBG(": ppe_getMtsprInstruction(R0, SPRG0): 0x%16llX" , l_raminstr );

            FAPI_TRY(ppe_RAMRead(i_target, i_base_address, l_raminstr, l_data32));

            FAPI_INF("data = 0x%08llX",  l_data32);

            l_regVal.number = it;
            l_regVal.value = l_data32;
            v_ppe_major_sprs_value.push_back(l_regVal);


        }

        FAPI_INF("--- State Registers --");
        // MSR

        // MSR to R0
        l_raminstr.flush<0>().insertFromRight(ppe_getMfmsrInstruction(0), 0, 32);
        FAPI_DBG("      ppe_getMfmsrInstruction(R0): 0x%16llX", l_raminstr );
        FAPI_TRY(ppe_pollHaltState(i_target, i_base_address));
        FAPI_TRY(fapi2::putScom(i_target, i_base_address + PPE_XIRAMEDR, l_raminstr));

        // R0 to SPRG0
        l_raminstr.flush<0>().insertFromRight(ppe_getMtsprInstruction(0, SPRG0), 0, 32);
        FAPI_DBG("          : ppe_getMtsprInstruction(R0, SPRG0): 0x%16llX", l_raminstr );

        FAPI_TRY(ppe_RAMRead(i_target, i_base_address, l_raminstr, l_data32));

        sprintf(outstr, "MSR");
        FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
        l_regVal.number = MSR; //Using some unique number which will not clash with any existing PPE SPRN
        l_regVal.value = l_data32;
        v_ppe_special_sprs_value.push_back(l_regVal);
        // CR

        // CR to R0
        l_raminstr.flush<0>().insertFromRight(ppe_getMfcrInstruction(0), 0, 32);
        FAPI_DBG("          ppe_getMfcrInstruction(R0): 0x%16llX", l_raminstr );
        FAPI_TRY(ppe_pollHaltState(i_target, i_base_address));
        FAPI_TRY(fapi2::putScom(i_target, i_base_address + PPE_XIRAMEDR, l_raminstr));

        // R0 to SPRG0
        l_raminstr.flush<0>().insertFromRight(ppe_getMtsprInstruction(0, SPRG0), 0, 32);
        FAPI_DBG("          : ppe_getMtsprInstruction(R0, SPRG0): 0x%16llX", l_raminstr );

        FAPI_TRY(ppe_RAMRead(i_target, i_base_address, l_raminstr, l_data32));

        sprintf(outstr, "CR");
        FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
        l_regVal.number = CR; //Using some unique number which will not clash with any existing PPE SPRN
        l_regVal.value = l_data32;
        v_ppe_special_sprs_value.push_back(l_regVal);
        FAPI_INF("-------  GPRs  -------");

        for (auto it : v_ppe_gprs)
        {
            l_raminstr.flush<0>().insertFromRight(ppe_getMtsprInstruction(it, SPRG0), 0, 32);
            //l_raminstr.flush<0>().insertFromRight(ppe_getMtsprInstruction(0, SPRG0), 0, 32);
            FAPI_DBG("ppe_getMtsprInstruction(%d, SPRG0): 0x%16llX", it, l_raminstr );
            FAPI_TRY(ppe_RAMRead(i_target, i_base_address, l_raminstr, l_data32));

            sprintf(outstr, "GPR%d", it);

            if (it == 0)
            {
                FAPI_INF("%-9s = 0x%08llX", outstr, l_gpr0_save);
                l_regVal.number = it;
                l_regVal.value = l_gpr0_save;
                v_ppe_gprs_value.push_back(l_regVal);
            }
            else
            {
                FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
                l_regVal.number = it;
                l_regVal.value = l_data32;
                v_ppe_gprs_value.push_back(l_regVal);
            }
        }

        FAPI_INF("----- Minor SPRs -----");

        for (auto it : v_ppe_minor_sprs)
        {
            // SPR to R0
            l_raminstr.flush<0>().insertFromRight(ppe_getMfsprInstruction(0, it), 0, 32);
            FAPI_DBG("ppe_getMfsprInstruction(R0, %5d): 0x%16llX",  it, l_raminstr );
            FAPI_TRY(fapi2::putScom(i_target, i_base_address + PPE_XIRAMEDR, l_raminstr));

            // R0 to SPRG0
            //ashish
            //l_raminstr.flush<0>().insertFromRight(ppe_getMtsprInstruction(it, SPRG0), 0, 32);
            l_raminstr.flush<0>().insertFromRight(ppe_getMtsprInstruction(0, SPRG0), 0, 32);

            FAPI_DBG("ppe_getMtsprInstruction(R0, SPRG0): 0x%16llX",  l_raminstr );
            l_data32.flush<0>().insertFromRight(0XDEADBEEF, 0, 31);
            FAPI_TRY(ppe_RAMRead(i_target, i_base_address, l_raminstr, l_data32));

            FAPI_INF("data = 0x%08llX", l_data32);

            l_regVal.number = it;
            l_regVal.value = l_data32;
            v_ppe_minor_sprs_value.push_back(l_regVal);

        }


        FAPI_DBG("Restore GPR0");
        l_gpr0_save.extractToRight(l_data64, 0, 32);  // Put 32b save value into 64b buffer
        FAPI_TRY(fapi2::putScom(i_target, i_base_address + PPE_XIRAMDBG, l_data64));
        l_data64.flush<0>().insertFromRight(ppe_getMfsprInstruction(R0, SPRG0), 0, 32);
        FAPI_DBG("ppe_getMtsprInstruction(%d, SPRG0): 0x%16llX", 0, l_data64 );
        FAPI_TRY(ppe_pollHaltState(i_target, i_base_address));
        FAPI_TRY(fapi2::putScom(i_target, i_base_address + PPE_XIRAMEDR, l_data64));


        FAPI_DBG("Restore SPRG0");
        FAPI_TRY(ppe_pollHaltState(i_target, i_base_address));
        FAPI_TRY(putScom(i_target, i_base_address + PPE_XIRAMDBG , l_sprg0_save), "Error in GETSCOM");

        //If SNAPSHOT mode and only if initially PPE was not halted then do XCR(resume)
        if ((i_mode == SNAPSHOT) && ~(l_ppe_halt_state))
        {
            FAPI_TRY(ppe_resume(i_target, i_base_address));

            FAPI_INF("------   XIRs After resume   ------");
            // XSR and IAR
            FAPI_TRY(getScom(i_target, i_base_address + PPE_XIDBGPRO, l_data64), "Error in GETSCOM");
            l_data64.extractToRight(l_data32, 0, 32);
            sprintf(outstr, "XSR");
            FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
            l_regVal.number = XSR; //Using some unique number which will not clash with any existing PPE SPRN
            l_regVal.value = l_data32;

            l_data64.extractToRight(l_data32, 32, 32);
            sprintf(outstr, "IAR");
            FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
            l_regVal.number = IAR;
            l_regVal.value = l_data32;


            // IR and EDR
            FAPI_TRY(getScom(i_target, i_base_address + PPE_XIRAMEDR, l_data64), "Error in GETSCOM");
            l_data64.extractToRight(l_data32, 0, 32);
            sprintf(outstr, "IR");
            FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
            l_regVal.number = IR;
            l_regVal.value = l_data32;


            l_data64.extractToRight(l_data32, 32, 32);
            sprintf(outstr, "EDR");
            FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
            l_regVal.number = EDR;
            l_regVal.value = l_data32;

            // Save SPRG0
            FAPI_TRY(getScom(i_target, i_base_address + PPE_XIRAMDBG, l_sprg0_save), "Error in GETSCOM");
            l_sprg0_save.extractToRight(l_data32, 32, 32);
            sprintf(outstr, "SPRG0");
            FAPI_INF("%-9s = 0x%08llX", outstr, l_data32);
            l_regVal.number = SPRG0;
            l_regVal.value = l_data32;


        }


    }
    else
    {
        FAPI_INF("\nPPE is not Halted\n");
    }

fapi_try_exit:
    return fapi2::current_err;
}

// Hardware procedure
fapi2::ReturnCode
p9_ppe_state(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
             const uint64_t i_base_address,
             const PPE_DUMP_MODE i_mode,
             std::vector<PPERegValue_t>& v_ppe_sprs_value,
             std::vector<PPERegValue_t>& v_ppe_xirs_value,
             std::vector<PPERegValue_t>& v_ppe_gprs_value
            )
{
    std::vector<PPERegValue_t> v_ppe_minor_sprs_value;
    std::vector<PPERegValue_t> v_ppe_major_sprs_value;
    std::vector<PPERegValue_t> v_ppe_special_sprs_value;


    //Call the function to collect the data.
    ppe_state_data(i_target,
                   i_base_address,
                   i_mode,
                   v_ppe_minor_sprs_value,
                   v_ppe_major_sprs_value,
                   v_ppe_xirs_value,
                   v_ppe_gprs_value,
                   v_ppe_special_sprs_value);


    v_ppe_sprs_value.reserve(v_ppe_special_sprs_value.size() + v_ppe_major_sprs_value.size() +
                             v_ppe_minor_sprs_value.size()); // preallocate memory
    v_ppe_sprs_value.insert( v_ppe_sprs_value.end(), v_ppe_special_sprs_value.begin(), v_ppe_special_sprs_value.end() );
    v_ppe_sprs_value.insert( v_ppe_sprs_value.end(), v_ppe_major_sprs_value.begin(), v_ppe_major_sprs_value.end() );
    v_ppe_sprs_value.insert( v_ppe_sprs_value.end(), v_ppe_minor_sprs_value.begin(), v_ppe_minor_sprs_value.end() );

//fapi_try_exit:
    return fapi2::current_err;
} // Procedure
