/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dimmBadDqBitmapFuncs.C $                     */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/**
 *  @file dimmBadDqBitmapFuncs.C
 *
 *  @brief FW Team Utility functions that accesses the Bad DQ Bitmap.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     02/17/2012  Created.
 *                          dedahle     06/20/2013  dimmGetBadDqBitmap/
 *                                                  dimmSetBadDqBitmap funcs
 *                                                  get/set ATTR_BAD_DQ_BITMAP
 */

#include <dimmBadDqBitmapFuncs.H>
#include <string.h>

extern "C"
{


//------------------------------------------------------------------------------
// Utility function to check parameters and find a DIMM target
//------------------------------------------------------------------------------
fapi::ReturnCode dimmBadDqCheckParamFindDimm(const fapi::Target & i_mba,
                                             const uint8_t i_port,
                                             const uint8_t i_dimm,
                                             const uint8_t i_rank,
                                             fapi::Target & o_dimm)
{
    fapi::ReturnCode l_rc;

    if ((i_port >= DIMM_DQ_MAX_MBA_PORTS) ||
        (i_dimm >= DIMM_DQ_MAX_MBAPORT_DIMMS) ||
        (i_rank >= DIMM_DQ_MAX_DIMM_RANKS))
    {
        FAPI_ERR("dimmBadDqCheckParamFindDimm: Bad parameter. %d:%d:%d",
                i_port, i_dimm, i_rank);
        const uint8_t & FFDC_PORT = i_port;
        const uint8_t & FFDC_DIMM = i_dimm;
        const uint8_t & FFDC_RANK = i_rank;
        FAPI_SET_HWP_ERROR(l_rc, RC_BAD_DQ_DIMM_BAD_PARAM);
    }
    else
    {
        std::vector<fapi::Target> l_dimms;

        // Get the functional DIMMs associated with the MBA chiplet
        l_rc = fapiGetAssociatedDimms(i_mba, l_dimms);

        if (l_rc)
        {
            FAPI_ERR("dimmBadDqCheckParamFindDimm: "
                        "Error from fapiGetAssociatedDimms");
        }
        else
        {
            // Find the DIMM with the correct MBA port/dimm
            uint8_t l_port = 0;
            uint8_t l_dimm = 0;
            std::vector<fapi::Target>::const_iterator dimmIter;

            for (dimmIter = l_dimms.begin();
                    dimmIter != l_dimms.end();
                    ++dimmIter)
            {
                l_rc = FAPI_ATTR_GET(ATTR_MBA_PORT, &(*dimmIter), l_port);

                if (l_rc)
                {
                    FAPI_ERR("dimmBadDqCheckParamFindDimm: "
                                "Error getting ATTR_MBA_PORT for dimm");
                    break;
                }
                else if (l_port == i_port)
                {
                    l_rc = FAPI_ATTR_GET(ATTR_MBA_DIMM, &(*dimmIter), l_dimm);

                    if (l_rc)
                    {
                        FAPI_ERR("dimmBadDqCheckParamFindDimm: "
                                    "Error getting ATTR_MBA_DIMM for dimm");
                        break;
                    }
                    else if (l_dimm == i_dimm)
                    {
                        o_dimm = *dimmIter;
                        break;
                    }
                }            
            }

            if (!l_rc)
            {
                if (dimmIter == l_dimms.end())
                {
                    FAPI_ERR("dimmBadDqCheckParamFindDimm: "
                             "Did not find DIMM for %s:%d:%d",
                             i_mba.toEcmdString(), i_port, i_dimm);
                    const fapi::Target & FFDC_MBA_TARGET = i_mba;
                    const uint8_t & FFDC_PORT = i_port;
                    const uint8_t & FFDC_DIMM = i_dimm;
                    FAPI_SET_HWP_ERROR(l_rc, RC_BAD_DQ_DIMM_NOT_FOUND);
                }
            }
        }
    }

    return l_rc;
}

//------------------------------------------------------------------------------
fapi::ReturnCode dimmGetBadDqBitmap(const fapi::Target & i_mba,
                                    const uint8_t i_port,
                                    const uint8_t i_dimm,
                                    const uint8_t i_rank,
                                    uint8_t (&o_data)[DIMM_DQ_RANK_BITMAP_SIZE])
{
    FAPI_INF(">>dimmGetBadDqBitmap. %s:%d:%d:%d", i_mba.toEcmdString(), i_port,
             i_dimm, i_rank);

    fapi::ReturnCode l_rc;

    // Check parameters and find the DIMM Target
    fapi::Target l_dimm;
    l_rc = dimmBadDqCheckParamFindDimm(i_mba, i_port, i_dimm, i_rank, l_dimm);

    if (!l_rc)
    {
        // Get the Bad DQ bitmap by querying ATTR_BAD_DQ_BITMAP.
        // Use a heap based array to avoid large stack alloc
        uint8_t (&l_dqBitmap)[DIMM_DQ_MAX_DIMM_RANKS][DIMM_DQ_RANK_BITMAP_SIZE] =
            *(reinterpret_cast<uint8_t(*)[DIMM_DQ_MAX_DIMM_RANKS][DIMM_DQ_RANK_BITMAP_SIZE]>
                (new uint8_t[DIMM_DQ_MAX_DIMM_RANKS*DIMM_DQ_RANK_BITMAP_SIZE]));
       
        l_rc = FAPI_ATTR_GET(ATTR_BAD_DQ_BITMAP, &l_dimm, l_dqBitmap);

        if (l_rc)
        {
            FAPI_ERR("dimmGetBadDqBitmap: Error getting ATTR_BAD_DQ_BITMAP for dimm");
        }
        else
        {
            //Write contents of DQ bitmap for specific rank to o_data.
            memcpy(o_data, l_dqBitmap[i_rank], DIMM_DQ_RANK_BITMAP_SIZE);
        }

        delete [] &l_dqBitmap;
    }

    FAPI_INF("<<dimmGetBadDqBitmap");
    return l_rc;
}

//------------------------------------------------------------------------------
fapi::ReturnCode dimmSetBadDqBitmap(
    const fapi::Target & i_mba,
    const uint8_t i_port,
    const uint8_t i_dimm,
    const uint8_t i_rank,
    const uint8_t (&i_data)[DIMM_DQ_RANK_BITMAP_SIZE])
{
    FAPI_INF(">>dimmSetBadDqBitmap. %s:%d:%d:%d", i_mba.toEcmdString(), i_port, i_dimm, i_rank);

    fapi::ReturnCode l_rc;

    // Check parameters and find the DIMM Target
    fapi::Target l_dimm;
    l_rc = dimmBadDqCheckParamFindDimm(i_mba, i_port, i_dimm, i_rank, l_dimm);

    if (!l_rc)
    {
        // Get the Bad DQ bitmap by querying ATTR_BAD_DQ_BITMAP.
        // Use a heap based array to avoid large stack alloc
        uint8_t (&l_dqBitmap)[DIMM_DQ_MAX_DIMM_RANKS][DIMM_DQ_RANK_BITMAP_SIZE] =
            *(reinterpret_cast<uint8_t(*)[DIMM_DQ_MAX_DIMM_RANKS][DIMM_DQ_RANK_BITMAP_SIZE]>
                (new uint8_t[DIMM_DQ_MAX_DIMM_RANKS*DIMM_DQ_RANK_BITMAP_SIZE]));

        l_rc = FAPI_ATTR_GET(ATTR_BAD_DQ_BITMAP, &l_dimm, l_dqBitmap);

        if (l_rc)
        {
            FAPI_ERR("dimmSetBadDqBitmap: Error getting ATTR_BAD_DQ_BITMAP for dimm");
        }
        else
        {
            // Add the rank bitmap to the DIMM bitmap and write the bitmap
            memcpy(l_dqBitmap[i_rank], i_data, DIMM_DQ_RANK_BITMAP_SIZE);

            l_rc = FAPI_ATTR_SET(ATTR_BAD_DQ_BITMAP, &l_dimm, l_dqBitmap);

            if (l_rc)
            {
                FAPI_ERR("dimmSetBadDqBitmap: Error setting ATTR_BAD_DQ_BITMAP for dimm");
            }
        }

        delete [] &l_dqBitmap;
    }


    FAPI_INF("<<dimmSetBadDqBitmap");
    return l_rc;
}

} // extern "C"
