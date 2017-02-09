/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_dimmBadDqBitmapFuncs.C $ */
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
/// @file p9c_dimmBadDqBitmapFuncs.C
/// @brief FW Team Utility functions that accesses the Bad DQ Bitmap.
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
///

#include <p9c_dimmBadDqBitmapFuncs.H>
#include <p9c_dimmBadDqBitmapAccessHwp.H>
#include <string.h>
#include <c_str.H>


extern "C"
{
    ///
    /// @brief Utility function to check parameters and find a DIMM target
    /// @param[in] i_mba mba target
    /// @param[in] i_port Port number
    /// @param[in] i_dimm Dimm number
    /// @param[in] i_rank Rank number
    /// @param[out] o_dimm Dimm target
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    fapi2::ReturnCode dimmBadDqCheckParamFindDimm(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_mba,
            const uint8_t i_port,
            const uint8_t i_dimm,
            const uint8_t i_rank,
            fapi2::Target<fapi2::TARGET_TYPE_DIMM>& o_dimm)
    {
        uint8_t l_port = 0;
        uint8_t l_dimm = 0;
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_DIMM>> l_dimms;
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_DIMM>>::const_iterator dimmIter;

        FAPI_ASSERT((i_port < MAX_PORTS_PER_MBA) &&
                    (i_dimm < MAX_DIMM_PER_PORT) &&
                    (i_rank < MAX_RANKS_PER_DIMM),
                    fapi2::CEN_BAD_DQ_DIMM_BAD_PARAM().
                    set_FFDC_PORT(i_port).
                    set_FFDC_DIMM(i_dimm).
                    set_FFDC_RANK(i_rank),
                    "dimmBadDqCheckParamFindDimm: %s Bad parameter. %d:%d:%d",
                    mss::c_str(i_mba), i_port, i_dimm, i_rank);

        // Get the functional DIMMs associated with the MBA chiplet
        l_dimms = i_mba.getChildren<fapi2::TARGET_TYPE_DIMM>();
        // Find the DIMM with the correct MBA port/dimm

        for (dimmIter = l_dimms.begin(); dimmIter != l_dimms.end(); ++dimmIter)
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MBA_PORT, *dimmIter, l_port));

            if (l_port == i_port)
            {
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MBA_DIMM, *dimmIter, l_dimm));

                if (l_dimm == i_dimm)
                {
                    o_dimm = *dimmIter;
                    break;
                }
            }
        }

        FAPI_ASSERT(dimmIter != l_dimms.end(),
                    fapi2::CEN_BAD_DQ_DIMM_NOT_FOUND().
                    set_FFDC_PORT(i_port).
                    set_FFDC_DIMM(i_dimm),
                    "dimmBadDqCheckParamFindDimm: "
                    "Did not find DIMM for %s:%d:%d",
                    mss::c_str(i_mba), i_port, i_dimm);

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief FW Team Utility function that gets the Bad DQ Bitmap.
    /// @param[in]  i_mba  Reference to MBA Chiplet
    /// @param[in]  i_port MBA port number (0-(MAX_PORTS_PER_MBA - 1))
    /// @param[in]  i_dimm MBA port DIMM number (0-(MAX_DIMM_PER_PORT - 1))
    /// @param[in]  i_rank DIMM rank number (0-(MAX_RANKS_PER_DIMM -1))
    /// @param[out] o_data Reference to data where Bad DQ bitmap is copied to
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    fapi2::ReturnCode dimmGetBadDqBitmap(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_mba,
                                         const uint8_t i_port,
                                         const uint8_t i_dimm,
                                         const uint8_t i_rank,
                                         uint8_t (&o_data)[DIMM_DQ_RANK_BITMAP_SIZE])
    {
        FAPI_INF(">>dimmGetBadDqBitmap. %s:%d:%d:%d", mss::c_str(i_mba), i_port,
                 i_dimm, i_rank);

        // Check parameters and find the DIMM fapi2::Target<fapi2::TARGET_TYPE_MBA>
        fapi2::Target<fapi2::TARGET_TYPE_DIMM>  l_dimm;

        // Get the Bad DQ bitmap by querying ATTR_BAD_DQ_BITMAP.
        // Use a heap based array to avoid large stack alloc
        uint8_t (&l_dqBitmap)[MAX_RANKS_PER_DIMM][DIMM_DQ_RANK_BITMAP_SIZE] =
            *(reinterpret_cast<uint8_t(*)[MAX_RANKS_PER_DIMM][DIMM_DQ_RANK_BITMAP_SIZE]>
              (new uint8_t[MAX_RANKS_PER_DIMM * DIMM_DQ_RANK_BITMAP_SIZE]));

        FAPI_TRY(dimmBadDqCheckParamFindDimm(i_mba, i_port, i_dimm, i_rank, l_dimm));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_BAD_DQ_BITMAP, l_dimm, l_dqBitmap));

        //Write contents of DQ bitmap for specific rank to o_data.
        memcpy(o_data, l_dqBitmap[i_rank], DIMM_DQ_RANK_BITMAP_SIZE);

        delete [] &l_dqBitmap;

        FAPI_INF("<<dimmGetBadDqBitmap");
    fapi_try_exit:
        return fapi2::current_err;
    }

    /// @brief FW Team Utility function that sets the Bad DQ Bitmap.
    /// @param[in] i_mba  Reference to MBA Chiplet
    /// @param[in] i_port MBA port number (0-(MAX_PORTS_PER_MBA - 1))
    /// @param[in] i_dimm MBA port DIMM number (0-(MAX_DIMM_PER_PORT - 1))
    /// @param[in] i_rank DIMM rank number (0-(MAX_RANKS_PER_DIMM -1))
    /// @param[in] i_data Reference to data where Bad DQ bitmap is copied from
    /// @return FAPI2_RC_SUCCESS
    fapi2::ReturnCode dimmSetBadDqBitmap(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_mba,
                                         const uint8_t i_port,
                                         const uint8_t i_dimm,
                                         const uint8_t i_rank,
                                         const uint8_t (&i_data)[DIMM_DQ_RANK_BITMAP_SIZE])
    {
        FAPI_INF(">>dimmSetBadDqBitmap. %s:%d:%d:%d", mss::c_str(i_mba), i_port, i_dimm, i_rank);

        // Check parameters and find the DIMM fapi2::Target<fapi2::TARGET_TYPE_MBA>
        fapi2::Target<fapi2::TARGET_TYPE_DIMM> l_dimm;

        // Get the Bad DQ bitmap by querying ATTR_BAD_DQ_BITMAP.
        // Use a heap based array to avoid large stack alloc
        uint8_t (&l_dqBitmap)[MAX_RANKS_PER_DIMM][DIMM_DQ_RANK_BITMAP_SIZE] =
            *(reinterpret_cast<uint8_t(*)[MAX_RANKS_PER_DIMM][DIMM_DQ_RANK_BITMAP_SIZE]>
              (new uint8_t[MAX_RANKS_PER_DIMM * DIMM_DQ_RANK_BITMAP_SIZE]));

        FAPI_TRY(dimmBadDqCheckParamFindDimm(i_mba, i_port, i_dimm, i_rank, l_dimm));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_BAD_DQ_BITMAP, l_dimm, l_dqBitmap));

        // Add the rank bitmap to the DIMM bitmap and write the bitmap
        memcpy(l_dqBitmap[i_rank], i_data, DIMM_DQ_RANK_BITMAP_SIZE);

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_BAD_DQ_BITMAP, l_dimm, l_dqBitmap));

        delete [] &l_dqBitmap;

        FAPI_INF("<<dimmSetBadDqBitmap");
    fapi_try_exit:
        return fapi2::current_err;
    }

} // extern "C"
