/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/perv/p9_ram_getspr.C $                */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
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
/// @file p9_ram_getspr.C
/// @brief Utility to implement Get SPR Register by ramming
///
//-----------------------------------------------------------------------------------
// *HWP HWP Owner        : Liu Yang Fan <shliuyf@cn.ibm.com>
// *HWP HWP Backup Owner : Gou Peng Fei <shgoupf@cn.ibm.com>
// *HWP FW Owner         : Thi Tran <thi@us.ibm.com>
// *HWP Team             : Perv
// *HWP Level            : 2
// *HWP Consumed by      : None (Cronus test only)
//-----------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <p9_ram_getspr.H>

//-----------------------------------------------------------------------------------
// Function definitions
//-----------------------------------------------------------------------------------
fapi2::ReturnCode p9_ram_getspr(const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
                                const uint8_t i_thread,
                                const std::string i_name,
                                fapi2::buffer<uint64_t>* o_buffer)
{
    FAPI_INF("Start");
    uint32_t spr_num = 0;
    bool l_check_flag = false;

    // instantiate the basic RamCore class
    RamCore ram(i_target, i_thread);

    // init SPR_MAP
    l_check_flag = p9_spr_name_map_init();
    FAPI_ASSERT(l_check_flag,
                fapi2::P9_SPR_NAME_MAP_INIT_ERR(),
                "SPR name map is not empty when initialization");

    // map spr name to spr number
    l_check_flag = p9_spr_name_map(i_name, false, spr_num);
    FAPI_ASSERT(l_check_flag,
                fapi2::P9_SPR_NAME_MAP_ACCESS_ERR()
                .set_REGNAME(i_name),
                "SPR name map access failed");

    // call RamCore get_reg method
    FAPI_TRY(ram.get_reg(REG_SPR, spr_num, o_buffer));

fapi_try_exit:
    FAPI_INF("End");
    return fapi2::current_err;
}


