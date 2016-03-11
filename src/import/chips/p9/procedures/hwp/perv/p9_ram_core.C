/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/perv/p9_ram_core.C $                  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
//-----------------------------------------------------------------------------------
///
/// @file p9_ram_core.C
/// @brief Class that implements the base ramming capability
///
//-----------------------------------------------------------------------------------
// *HWP HWP Owner        : Liu Yang Fan <shliuyf@cn.ibm.com>
// *HWP HWP Backup Owner : Gou Peng Fei <shgoupf@cn.ibm.com>
// *HWP FW Owner         : Sachin Gupta <sgupta2m@in.ibm.com>
// *HWP Team             : Perv
// *HWP Level            : 2
// *HWP Consumed by      : SBE
//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <p9_ram_core.H>
#include "p9_quad_scom_addresses.H"
#include "p9_quad_scom_addresses_fld.H"

// opcode for ramming
const uint32_t OPCODE_MTSPR_FROM_GPR0_TO_SPRD     = 0x7C1543A6;
const uint32_t OPCODE_MTSPR_FROM_GPR1_TO_SPRD     = 0x7C3543A6;
const uint32_t OPCODE_MFSPR_FROM_SPRD_TO_GPR0     = 0x7C1542A6;
const uint32_t OPCODE_MFSPR_FROM_SPRD_TO_GPR1     = 0x7C3542A6;
const uint32_t OPCODE_MFSPR_FROM_SPR0_TO_GPR0     = 0x7C0002A6;
const uint32_t OPCODE_MTSPR_FROM_GPR0_TO_SPR0     = 0x7C0003A6;
const uint32_t OPCODE_MFFPRD_FROM_FPR0_TO_GPR0    = 0x7C000066;
const uint32_t OPCODE_MTFPRD_FROM_GPR0_TO_FPR0    = 0x7C000166;
const uint32_t OPCODE_MFVSRD_FROM_VSR0_TO_GPR0    = 0x7C000067;
const uint32_t OPCODE_MTVSRD_FROM_GPR0_TO_VSR0    = 0x7C000167;
const uint32_t OPCODE_MFVSRLD_FROM_VSR0_TO_GPR0   = 0x7C000267;
const uint32_t OPCODE_MTVSRDD_FROM_GPR1_0_TO_VSR0 = 0x7C010367;

// poll count for check ram status
const uint32_t RAM_CORE_STAT_POLL_CNT = 10;

// Scom register field
// TODO: replace the const with FLD macro define when it's ready
const uint32_t C_RAM_MODEREG_ENABLE                = 0;
const uint32_t C_THREAD_INFO_VTID0_ACTIVE          = 0;
const uint32_t C_RAM_CTRL_VTID                     = 0;
const uint32_t C_RAM_CTRL_VTID_LEN                 = 2;
const uint32_t C_RAM_CTRL_PREDECODE                = 2;
const uint32_t C_RAM_CTRL_PREDECODE_LEN            = 4;
const uint32_t C_RAM_CTRL_INSTRUCTION              = 8;
const uint32_t C_RAM_CTRL_INSTRUCTION_LEN          = 32;
const uint32_t C_RAM_STATUS_ACCESS_DURING_RECOVERY = 0;
const uint32_t C_RAM_STATUS_COMPLETION             = 1;
const uint32_t C_RAM_STATUS_EXCEPTION              = 2;
const uint32_t C_RAM_STATUS_LSU_EMPTY              = 3;

//-----------------------------------------------------------------------------------
// Function definitions
//-----------------------------------------------------------------------------------
RamCore::RamCore(const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target, const uint8_t i_thread)
{
    iv_target = i_target;
    iv_thread = i_thread;
    iv_ram_enable = false;
    iv_ram_setup  = false;
    iv_write_gpr0 = false;
    iv_write_gpr1 = false;
    iv_backup_buf0 = 0;
    iv_backup_buf1 = 0;
    iv_backup_buf2 = 0;
}

RamCore::~RamCore()
{
    if(iv_ram_setup)
    {
        FAPI_ERR("RamCore Destructor error: Ram is still in active state!!!");
    }
}

//-----------------------------------------------------------------------------------
fapi2::ReturnCode RamCore::ram_setup()
{
    FAPI_INF("Start ram setup");
    fapi2::buffer<uint64_t> l_data = 0;
    uint32_t l_opcode = 0;
    bool l_thread_active = false;

    // set RAM_MODEREG Scom to enable RAM mode
    FAPI_TRY(fapi2::getScom(iv_target, C_RAM_MODEREG, l_data));
    l_data.setBit<C_RAM_MODEREG_ENABLE>();
    FAPI_TRY(fapi2::putScom(iv_target, C_RAM_MODEREG, l_data));

    // read THREAD_INFO Scom to check the thread is active for ramming
    l_data.flush<0>();
    FAPI_TRY(fapi2::getScom(iv_target, C_THREAD_INFO, l_data));
    FAPI_DBG("THREAD_INFO:%#lx", l_data());
    FAPI_TRY(l_data.extractToRight(l_thread_active, C_THREAD_INFO_VTID0_ACTIVE + iv_thread, 1));

    FAPI_ASSERT(l_thread_active,
                fapi2::P9_RAM_THREAD_INACTIVE_ERR()
                .set_THREAD(iv_thread),
                "Thread to perform ram is inactive");

    iv_ram_enable = true;

    // backup registers SCR0/GPR0/GPR1
    //SCR0->iv_backup_buf0
    FAPI_TRY(fapi2::getScom(iv_target, C_SCR0, iv_backup_buf0));

    //GPR0->iv_backup_buf1
    //1.setup SPRC to use SCRO as SPRD
    l_data.flush<0>();
    FAPI_TRY(fapi2::getScom(iv_target, C_SPR_MODE, l_data));
    FAPI_TRY(l_data.setBit(C_SPR_MODE_MODEREG_SPRC_LT0_SEL + iv_thread));
    FAPI_TRY(fapi2::putScom(iv_target, C_SPR_MODE, l_data));
    l_data.flush<0>();
    FAPI_TRY(fapi2::getScom(iv_target, C_SCOMC, l_data));
    l_data.insertFromRight<C_SCOMC_MODE, C_SCOMC_MODE_LEN>(0);
    FAPI_TRY(fapi2::putScom(iv_target, C_SCOMC, l_data));

    //2.create mtsprd<gpr0> opcode, ram into thread to get GPR0
    l_opcode = OPCODE_MTSPR_FROM_GPR0_TO_SPRD;
    FAPI_TRY(ram_opcode(l_opcode, true));

    //3.get GPR0 from SCR0
    FAPI_TRY(fapi2::getScom(iv_target, C_SCR0, iv_backup_buf1));

    //GPR1->iv_backup_buf2
    //1.create mtsprd<gpr1> opcode, ram into thread to get GPR1
    l_opcode = OPCODE_MTSPR_FROM_GPR1_TO_SPRD;
    FAPI_TRY(ram_opcode(l_opcode, true));

    //2.get GPR1 from SCR0
    FAPI_TRY(fapi2::getScom(iv_target, C_SCR0, iv_backup_buf2));

    iv_ram_setup = true;

fapi_try_exit:
    FAPI_INF("Exiting ram setup");
    return fapi2::current_err;
}

//-----------------------------------------------------------------------------------
fapi2::ReturnCode RamCore::ram_cleanup()
{
    FAPI_INF("Start ram cleanup");
    uint32_t l_opcode = 0;
    fapi2::buffer<uint64_t> l_data = 0;

    FAPI_ASSERT(iv_ram_setup,
                fapi2::P9_RAM_NOT_SETUP_ERR(),
                "Attempting to cleanup ram without setup before");

    // restore GPR1/GPR0/SCR0
    if(!iv_write_gpr0 && !iv_write_gpr1)
    {
        //iv_backup_buf2->GPR1
        //1.setup SPRC to use SCRO as SPRD
        FAPI_TRY(fapi2::getScom(iv_target, C_SPR_MODE, l_data));
        FAPI_TRY(l_data.setBit(C_SPR_MODE_MODEREG_SPRC_LT0_SEL + iv_thread));
        FAPI_TRY(fapi2::putScom(iv_target, C_SPR_MODE, l_data));
        l_data.flush<0>();
        FAPI_TRY(fapi2::getScom(iv_target, C_SCOMC, l_data));
        l_data.insertFromRight<C_SCOMC_MODE, C_SCOMC_MODE_LEN>(0);
        FAPI_TRY(fapi2::putScom(iv_target, C_SCOMC, l_data));

        //2.put restore data into SCR0
        FAPI_TRY(fapi2::putScom(iv_target, C_SCR0, iv_backup_buf2));

        //3.create mfsprd<gpr1> opcode, ram into thread to restore GPR1
        l_opcode = OPCODE_MFSPR_FROM_SPRD_TO_GPR1;
        FAPI_TRY(ram_opcode(l_opcode, true));

        //iv_backup_buf1->GPR0
        //1.put restore data into SCR0
        FAPI_TRY(fapi2::putScom(iv_target, C_SCR0, iv_backup_buf1));

        //2.create mfsprd<gpr0> opcode, ram into thread to restore GPR0
        l_opcode = OPCODE_MFSPR_FROM_SPRD_TO_GPR0;
        FAPI_TRY(ram_opcode(l_opcode, true));

        //iv_backup_buf0->SCR0
        FAPI_TRY(fapi2::putScom(iv_target, C_SCR0, iv_backup_buf0));
    }
    // restore GPR0/SCR0
    else if(!iv_write_gpr0 && iv_write_gpr1)
    {
        //iv_backup_buf1->GPR0
        //1.setup SPRC to use SCRO as SPRD
        FAPI_TRY(fapi2::getScom(iv_target, C_SPR_MODE, l_data));
        FAPI_TRY(l_data.setBit(C_SPR_MODE_MODEREG_SPRC_LT0_SEL + iv_thread));
        FAPI_TRY(fapi2::putScom(iv_target, C_SPR_MODE, l_data));
        l_data.flush<0>();
        FAPI_TRY(fapi2::getScom(iv_target, C_SCOMC, l_data));
        l_data.insertFromRight<C_SCOMC_MODE, C_SCOMC_MODE_LEN>(0);
        FAPI_TRY(fapi2::putScom(iv_target, C_SCOMC, l_data));

        //2.put restore data into SCR0
        FAPI_TRY(fapi2::putScom(iv_target, C_SCR0, iv_backup_buf1));

        //3.create mfsprd<gpr0> opcode, ram into thread to restore GPR0
        l_opcode = OPCODE_MFSPR_FROM_SPRD_TO_GPR0;
        FAPI_TRY(ram_opcode(l_opcode, true));

        //iv_backup_buf0->SCR0
        FAPI_TRY(fapi2::putScom(iv_target, C_SCR0, iv_backup_buf0));
    }
    // restore GPR1/SCR0
    else if(iv_write_gpr0 && !iv_write_gpr1)
    {
        //iv_backup_buf2->GPR1
        //1.setup SPRC to use SCRO as SPRD
        FAPI_TRY(fapi2::getScom(iv_target, C_SPR_MODE, l_data));
        FAPI_TRY(l_data.setBit(C_SPR_MODE_MODEREG_SPRC_LT0_SEL + iv_thread));
        FAPI_TRY(fapi2::putScom(iv_target, C_SPR_MODE, l_data));
        l_data.flush<0>();
        FAPI_TRY(fapi2::getScom(iv_target, C_SCOMC, l_data));
        l_data.insertFromRight<C_SCOMC_MODE, C_SCOMC_MODE_LEN>(0);
        FAPI_TRY(fapi2::putScom(iv_target, C_SCOMC, l_data));

        //2.put restore data into SCR0
        FAPI_TRY(fapi2::putScom(iv_target, C_SCR0, iv_backup_buf2));

        //3.create mfsprd<gpr0> opcode, ram into thread to restore GPR1
        l_opcode = OPCODE_MFSPR_FROM_SPRD_TO_GPR1;
        FAPI_TRY(ram_opcode(l_opcode, true));

        //iv_backup_buf0->SCR0
        FAPI_TRY(fapi2::putScom(iv_target, C_SCR0, iv_backup_buf0));
    }
    // restore SCR0
    else
    {
        //iv_backup_buf0->SCR0
        FAPI_TRY(fapi2::putScom(iv_target, C_SCR0, iv_backup_buf0));
    }

    // set RAM_MODEREG Scom to clear RAM mode
    l_data.flush<0>();
    FAPI_TRY(fapi2::getScom(iv_target, C_RAM_MODEREG, l_data));
    l_data.clearBit<C_RAM_MODEREG_ENABLE>();
    FAPI_TRY(fapi2::putScom(iv_target, C_RAM_MODEREG, l_data));

    iv_ram_enable = false;
    iv_ram_setup  = false;
    iv_write_gpr0 = false;
    iv_write_gpr1 = false;

fapi_try_exit:
    FAPI_INF("Exiting ram cleanup");
    return fapi2::current_err;
}

//-----------------------------------------------------------------------------------
fapi2::ReturnCode RamCore::ram_opcode(const uint32_t i_opcode, const bool i_allow_mult)
{
    FAPI_INF("Start ram opcode");
    fapi2::buffer<uint64_t> l_data = 0;
    uint8_t l_predecode = 0;
    uint8_t l_poll_count = RAM_CORE_STAT_POLL_CNT;
    bool l_is_load_store = false;

    // check the opcode for load/store
    l_is_load_store = is_load_store(i_opcode);

    // ram_setup
    if(!i_allow_mult)
    {
        FAPI_TRY(ram_setup());
    }

    FAPI_ASSERT(iv_ram_enable,
                fapi2::P9_RAM_NOT_SETUP_ERR(),
                "Attempting to ram opcode without enable RAM mode before");

    // write RAM_CTRL Scom for ramming the opcode
    l_data.insertFromRight<C_RAM_CTRL_VTID, C_RAM_CTRL_VTID_LEN>(iv_thread);
    l_predecode = gen_predecode(i_opcode);
    l_data.insertFromRight<C_RAM_CTRL_PREDECODE, C_RAM_CTRL_PREDECODE_LEN>(l_predecode);
    l_data.insertFromRight<C_RAM_CTRL_INSTRUCTION, C_RAM_CTRL_INSTRUCTION_LEN>(i_opcode);
    FAPI_TRY(fapi2::putScom(iv_target, C_RAM_CTRL, l_data));

    // poll RAM_STATUS_REG Scom for the completion
    l_data.flush<0>();

    while(1)
    {
        FAPI_TRY(fapi2::getScom(iv_target, C_RAM_STATUS, l_data));

        // attempting to ram during recovery
        FAPI_ASSERT(!l_data.getBit<C_RAM_STATUS_ACCESS_DURING_RECOVERY>(),
                    fapi2::P9_RAM_STATUS_IN_RECOVERY_ERR(),
                    "Attempting to ram during recovery");

        // exception or interrupt
        FAPI_ASSERT(!l_data.getBit<C_RAM_STATUS_EXCEPTION>(),
                    fapi2::P9_RAM_STATUS_EXCEPTION_ERR(),
                    "Exception or interrupt happened during ramming");

        // load/store opcode need to check LSU empty and PPC complete
        if (l_is_load_store)
        {
            if(l_data.getBit<C_RAM_STATUS_COMPLETION>() && l_data.getBit<C_RAM_STATUS_LSU_EMPTY>())
            {
                FAPI_DBG("ram_opcode:: RAM is done");
                break;
            }
        }
        else
        {
            if(l_data.getBit<C_RAM_STATUS_COMPLETION>())
            {
                FAPI_DBG("ram_opcode:: RAM is done");
                break;
            }
        }

        --l_poll_count;

        FAPI_ASSERT(l_poll_count > 0,
                    fapi2::P9_RAM_STATUS_POLL_THRESHOLD_ERR(),
                    "Timeout for ram to complete, poll count expired");
    }

    // ram_cleanup
    if(!i_allow_mult)
    {
        FAPI_TRY(ram_cleanup());
    }

fapi_try_exit:
    FAPI_INF("Exiting ram opcode");
    return fapi2::current_err;
}

//-----------------------------------------------------------------------------------
uint8_t RamCore::gen_predecode(const uint32_t i_opcode)
{
    //TODO: implement when the PC workbook is updated
    return 0;
}

//-----------------------------------------------------------------------------------
bool RamCore::is_load_store(const uint32_t i_opcode)
{
    //TODO: implement when the PC workbook is updated
    return false;
}

//-----------------------------------------------------------------------------------
fapi2::ReturnCode RamCore::get_reg(const Enum_RegType i_type, const uint32_t i_reg_num,
                                   fapi2::buffer<uint64_t>* o_buffer, const bool i_allow_mult)
{
    FAPI_INF("Start get register");
    uint32_t l_opcode = 0;
    uint32_t l_spr_regnum_lo = 0;
    uint32_t l_spr_regnum_hi = 0;

    // ram_setup
    if(!i_allow_mult)
    {
        FAPI_TRY(ram_setup());
    }

    FAPI_ASSERT(iv_ram_setup,
                fapi2::P9_RAM_NOT_SETUP_ERR(),
                "Attempting to get register without setup before");

    // get register value
    if(i_type == REG_GPR)
    {
        //1.create mtsprd<i_reg_num> opcode, ram into thread
        l_opcode = OPCODE_MTSPR_FROM_GPR0_TO_SPRD;
        l_opcode += (i_reg_num << 21);
        FAPI_TRY(ram_opcode(l_opcode, true));

        //2.get GPR value from SCR0
        FAPI_TRY(fapi2::getScom(iv_target, C_SCR0, o_buffer[0]));
    }
    else if(i_type == REG_SPR)
    {
        //1.create mfspr<gpr0, i_reg_num> opcode, ram into thread
        l_opcode = OPCODE_MFSPR_FROM_SPR0_TO_GPR0;
        l_spr_regnum_lo = i_reg_num & 0x0000001F;
        l_spr_regnum_hi = i_reg_num & 0x000003E0;
        l_opcode += (l_spr_regnum_lo << 16);
        l_opcode += (l_spr_regnum_hi << 11);
        FAPI_TRY(ram_opcode(l_opcode, true));

        //2.create mtsprd<gpr0> opcode, ram into thread
        l_opcode = OPCODE_MTSPR_FROM_GPR0_TO_SPRD;
        FAPI_TRY(ram_opcode(l_opcode, true));

        //3.get GPR value from SCR0
        FAPI_TRY(fapi2::getScom(iv_target, C_SCR0, o_buffer[0]));
    }
    else if(i_type == REG_FPR)
    {
        //1.create mffprd<gpr0, i_reg_num>#SX=0 opcode, ram into thread
        l_opcode = OPCODE_MFFPRD_FROM_FPR0_TO_GPR0;
        l_opcode += (i_reg_num << 21);
        FAPI_TRY(ram_opcode(l_opcode, true));

        //2.create mtsprd<gpr0> opcode, ram into thread
        l_opcode = OPCODE_MTSPR_FROM_GPR0_TO_SPRD;
        FAPI_TRY(ram_opcode(l_opcode, true));

        //3.get GPR value from SCR0
        FAPI_TRY(fapi2::getScom(iv_target, C_SCR0, o_buffer[0]));
    }
    else if(i_type == REG_VSR)
    {
        //1.create mfvsrd<gpr0, i_reg_num>#SX=1 opcode, ram into thread to get dw0
        l_opcode = OPCODE_MFVSRD_FROM_VSR0_TO_GPR0;
        l_opcode += (i_reg_num << 21);
        FAPI_TRY(ram_opcode(l_opcode, true));

        //2.create mtsprd<gpr0> opcode, ram into thread
        l_opcode = OPCODE_MTSPR_FROM_GPR0_TO_SPRD;
        FAPI_TRY(ram_opcode(l_opcode, true));

        //3.get VSR dw0 value from SCR0
        FAPI_TRY(fapi2::getScom(iv_target, C_SCR0, o_buffer[0]));

        //4.create mfvrld<gpr0, i_reg_num>#SX=1 opcode, ram into thread to get dw1
        l_opcode = OPCODE_MFVSRLD_FROM_VSR0_TO_GPR0;
        l_opcode += (i_reg_num << 21);
        FAPI_TRY(ram_opcode(l_opcode, true));

        //5.create mtsprd<gpr0> opcode, ram into thread
        l_opcode = OPCODE_MTSPR_FROM_GPR0_TO_SPRD;
        FAPI_TRY(ram_opcode(l_opcode, true));

        //6.get VSR dw1 value from SCR0
        FAPI_TRY(fapi2::getScom(iv_target, C_SCR0, o_buffer[1]));
    }
    else
    {
        FAPI_ASSERT(false,
                    fapi2::P9_RAM_INVALID_REG_TYPE_ACCESS_ERR()
                    .set_REGTYPE(i_type),
                    "Type of reg is not supported");
    }

    // ram_cleanup
    if(!i_allow_mult)
    {
        FAPI_TRY(ram_cleanup());
    }

fapi_try_exit:
    FAPI_INF("Exiting get register");
    return fapi2::current_err;
}

//-----------------------------------------------------------------------------------
fapi2::ReturnCode RamCore::put_reg(const Enum_RegType i_type, const uint32_t i_reg_num,
                                   const fapi2::buffer<uint64_t>* i_buffer, const bool i_allow_mult)
{
    FAPI_INF("Start put register");
    uint32_t l_opcode = 0;
    uint32_t l_spr_regnum_lo = 0;
    uint32_t l_spr_regnum_hi = 0;

    // ram_setup
    if(!i_allow_mult)
    {
        FAPI_TRY(ram_setup());
    }

    FAPI_ASSERT(iv_ram_setup,
                fapi2::P9_RAM_NOT_SETUP_ERR(),
                "Attempting to put register without setup before");

    // put register value
    if(i_type == REG_GPR)
    {
        //1.put GPR value into SCR0
        FAPI_TRY(fapi2::putScom(iv_target, C_SCR0, i_buffer[0]));

        //2.create mfsprd<i_reg_num> opcode, ram into thread
        l_opcode = OPCODE_MFSPR_FROM_SPRD_TO_GPR0;
        l_opcode += (i_reg_num << 21);
        FAPI_TRY(ram_opcode(l_opcode, true));

        if(i_reg_num == 0)
        {
            iv_write_gpr0 = true;
        }

        if(i_reg_num == 1)
        {
            iv_write_gpr1 = true;
        }
    }
    else if(i_type == REG_SPR)
    {
        //1.put SPR value into SCR0
        FAPI_TRY(fapi2::putScom(iv_target, C_SCR0, i_buffer[0]));

        //2.create mfsprd<gpr0> opcode, ram into thread
        l_opcode = OPCODE_MFSPR_FROM_SPRD_TO_GPR0;
        FAPI_TRY(ram_opcode(l_opcode, true));

        //3.create mtspr<i_reg_num, gpr0> opcode, ram into thread
        l_opcode = OPCODE_MTSPR_FROM_GPR0_TO_SPR0;
        l_spr_regnum_lo = i_reg_num & 0x0000001F;
        l_spr_regnum_hi = i_reg_num & 0x000003E0;
        l_opcode += (l_spr_regnum_lo << 16);
        l_opcode += (l_spr_regnum_hi << 11);
        FAPI_TRY(ram_opcode(l_opcode, true));
    }
    else if(i_type == REG_FPR)
    {
        //1.put FPR value into SCR0
        FAPI_TRY(fapi2::putScom(iv_target, C_SCR0, i_buffer[0]));

        //2.create mfsprd<gpr0> opcode, ram into thread
        l_opcode = OPCODE_MFSPR_FROM_SPRD_TO_GPR0;
        FAPI_TRY(ram_opcode(l_opcode, true));

        //3.create mtfprd<i_reg_num, gpr0>#TX=0 opcode, ram into thread
        l_opcode = OPCODE_MTFPRD_FROM_GPR0_TO_FPR0;
        l_opcode += (i_reg_num << 21);
        FAPI_TRY(ram_opcode(l_opcode, true));
    }
    else if(i_type == REG_VSR)
    {
        //1.put VSR dw1 value into SCR0
        FAPI_TRY(fapi2::putScom(iv_target, C_SCR0, i_buffer[1]));

        //2.create mfsprd<gpr0> opcode, ram into thread
        l_opcode = OPCODE_MFSPR_FROM_SPRD_TO_GPR0;
        FAPI_TRY(ram_opcode(l_opcode, true));

        //3.put VSR dw0 value into SCR0
        FAPI_TRY(fapi2::putScom(iv_target, C_SCR0, i_buffer[0]));

        //4.create mfsprd<gpr1> opcode, ram into thread
        l_opcode = OPCODE_MFSPR_FROM_SPRD_TO_GPR0;
        l_opcode += (1 << 21);
        FAPI_TRY(ram_opcode(l_opcode, true));

        //5.create mtvsrdd<i_reg_num, gpr0, gpr1> opcode, ram into thread
        l_opcode = OPCODE_MTVSRDD_FROM_GPR1_0_TO_VSR0;
        l_opcode += (i_reg_num << 21);
        FAPI_TRY(ram_opcode(l_opcode, true));
    }
    else
    {
        FAPI_ASSERT(false,
                    fapi2::P9_RAM_INVALID_REG_TYPE_ACCESS_ERR()
                    .set_REGTYPE(i_type),
                    "Type of reg is not supported");
    }

    // ram_cleanup
    if(!i_allow_mult)
    {
        FAPI_TRY(ram_cleanup());
    }

fapi_try_exit:
    FAPI_INF("Exiting put register");
    return fapi2::current_err;
}

