/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/perv/p9_ram_getspr.H $                */
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
/// @file p9_ram_getspr.H
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

#ifndef _P9_RAM_GETSPR_H_
#define _P9_RAM_GETSPR_H_

//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <fapi2.H>
#include <p9_ram_core.H>
#include <p9_spr_name_map.H>

//function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_ram_getspr_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
        const uint8_t i_thread,
        const std::string i_name,
        fapi2::buffer<uint64_t>* o_buffer);


extern "C" {
//-----------------------------------------------------------------------------------
// Function prototype
//-----------------------------------------------------------------------------------
/// @brief Implement Get SPR Register by ramming
/// @param[in] i_target   => core target
/// @param[in] i_thread   => thread number
/// @param[in] i_name     => register name
/// @param[out] o_buffer   => register value
/// @return FAPI_RC_SUCCESS if the setup completes successfully
//
    fapi2::ReturnCode p9_ram_getspr(const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
                                    const uint8_t i_thread,
                                    const std::string i_name,
                                    fapi2::buffer<uint64_t>* o_buffer);

} //extern"C"

#endif //_P9_RAM_GETSPR_H_

