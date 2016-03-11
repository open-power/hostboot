/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/perv/p9_ram_getreg.C $                */
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
/// @file p9_ram_getreg.C
/// @brief Utility to implement Get Register by ramming
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
#include <p9_ram_getreg.H>

//-----------------------------------------------------------------------------------
// Function definitions
//-----------------------------------------------------------------------------------
fapi2::ReturnCode p9_ram_getreg(const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
                                const uint8_t i_thread,
                                const Enum_RegType i_type,
                                const uint32_t i_reg_num,
                                fapi2::buffer<uint64_t>* o_buffer)
{
    FAPI_INF("Start");
    // instantiate the basic RamCore class
    RamCore ram(i_target, i_thread);
    // call RamCore get_reg method
    FAPI_TRY(ram.get_reg(i_type, i_reg_num, o_buffer));

fapi_try_exit:
    FAPI_INF("End");
    return fapi2::current_err;
}


