/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/dimm/kind.H $              */
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

///
/// @file dimm.H
/// @brief Encapsulation for dimms of all types
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Craig Hamilton <cchamilt@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_DIMM_H_
#define _MSS_DIMM_H_

#include <fapi2.H>

#include <mss_attribute_accessors.H>
#include "../utils/c_str.H"

namespace mss
{

namespace dimm
{

///
/// @class mss::dimm::kind
/// @brief A class containing information about a dimm like ranks, density, configuration - what kind of dimm is it?
///
class kind
{
    public:

        kind(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target):
            iv_target(i_target)
        {
            FAPI_TRY( mss::eff_dram_gen(i_target, iv_dram_generation) );
            FAPI_TRY( mss::eff_dimm_type(i_target, iv_dimm_type) );
            FAPI_TRY( mss::eff_dram_density(i_target, iv_dram_density) );
            FAPI_TRY( mss::eff_dram_width(i_target, iv_dram_width) );
            FAPI_TRY( mss::eff_num_master_ranks_per_dimm(i_target, iv_master_ranks) );
            FAPI_TRY( mss::eff_dram_row_bits(i_target, iv_rows) );
            FAPI_TRY( mss::eff_dimm_size(i_target, iv_size) );

            // TK: Attribute for slave ranks.
            iv_slave_ranks = 0;

        fapi_try_exit:
            // Not 100% sure what to do here ...
            FAPI_ERR("error initializing DIMM structure: %s 0x%016lx", mss::c_str(i_target), uint64_t(fapi2::current_err));
        }

        const fapi2::Target<fapi2::TARGET_TYPE_DIMM> iv_target;
        uint8_t iv_master_ranks;
        uint8_t iv_slave_ranks;
        uint8_t iv_dram_density;
        uint8_t iv_dram_width;
        uint8_t iv_dram_generation;
        uint8_t iv_dimm_type;
        uint8_t iv_rows;
        uint32_t iv_size;
};

}

}
#endif
