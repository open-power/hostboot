/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/customize/p9_xip_customize.C $        */
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
#include <p9_xip_customize.H>
#include <p9_xip_image.h>
//#include <p9_ring_identification.H>
//#include <p9_get_mvpd_ring.H>
//#include <p9_tor.H>
//#include <p9_scan_compression.H>
#include <p9_infrastruct_help.H>

using namespace fapi2;

template<typename T>
T min (T a, T b)
{
    return ((a < b) ? a : b);
}

#define MBOX_ATTR_WRITE(ID,TARGET,IMAGE) \
    { \
        fapi2::ID##_Type ID##_attrVal; \
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ID,TARGET,ID##_attrVal),\
                 "MBOX_ATTR_WRITE: Error getting %s", #ID); \
        FAPI_TRY(p9_xip_set_scalar(IMAGE,#ID,ID##_attrVal),\
                 "MBOX_ATTR_WRITE: Error writing attr %s to seeprom image",\
                 #ID); \
    }

fapi2::ReturnCode writeMboxRegs (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
    void* i_image)
{
    FAPI_DBG ("writeMboxRegs Entering...");
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    MBOX_ATTR_WRITE (ATTR_I2C_BUS_DIV_REF,         i_proc_target,   i_image);
    MBOX_ATTR_WRITE (ATTR_FUNCTIONAL_EQ_EC_VALID,  i_proc_target,   i_image);
    MBOX_ATTR_WRITE (ATTR_EQ_GARD,                 i_proc_target,   i_image);
    MBOX_ATTR_WRITE (ATTR_EC_GARD,                 i_proc_target,   i_image);
    MBOX_ATTR_WRITE (ATTR_I2C_BUS_DIV_REF_VALID,   i_proc_target,   i_image);
    MBOX_ATTR_WRITE (ATTR_FW_MODE_FLAGS_VALID,     i_proc_target,   i_image);
    MBOX_ATTR_WRITE (ATTR_ISTEP_MODE,              i_proc_target,   i_image);
    MBOX_ATTR_WRITE (ATTR_SBE_RUNTIME_MODE,        i_proc_target,   i_image);
    MBOX_ATTR_WRITE (ATTR_IS_MPIPL,                FAPI_SYSTEM,     i_image);
    MBOX_ATTR_WRITE (ATTR_IS_SP_MODE,              i_proc_target,   i_image);
    MBOX_ATTR_WRITE (ATTR_SBE_FFDC_ENABLE,         i_proc_target,   i_image);
    MBOX_ATTR_WRITE (ATTR_SBE_INTERNAL_FFDC_ENABLE, i_proc_target,  i_image);
    MBOX_ATTR_WRITE (ATTR_BOOT_FREQUENCY_VALID,    i_proc_target,   i_image);
    MBOX_ATTR_WRITE (ATTR_NEST_PLL_BUCKET,         FAPI_SYSTEM,     i_image);
    MBOX_ATTR_WRITE (ATTR_BOOT_FREQ_MULT,          i_proc_target,   i_image);
    MBOX_ATTR_WRITE (ATTR_HWP_CONTROL_FLAGS_VALID, i_proc_target,   i_image);
    MBOX_ATTR_WRITE (ATTR_SYSTEM_IPL_PHASE,        FAPI_SYSTEM,     i_image);
    MBOX_ATTR_WRITE (ATTR_SYS_FORCE_ALL_CORES,     FAPI_SYSTEM,     i_image);
    MBOX_ATTR_WRITE (ATTR_RISK_LEVEL,              FAPI_SYSTEM,     i_image);
    MBOX_ATTR_WRITE (ATTR_DISABLE_HBBL_VECTORS,    FAPI_SYSTEM,     i_image);
    MBOX_ATTR_WRITE (ATTR_CHIP_SELECTION_VALID,    i_proc_target,   i_image);
    MBOX_ATTR_WRITE (ATTR_CHIP_SELECTION,          i_proc_target,   i_image);
    MBOX_ATTR_WRITE (ATTR_NODE_POS,                i_proc_target,   i_image);
    MBOX_ATTR_WRITE (ATTR_CHIP_POS,                i_proc_target,   i_image);
    MBOX_ATTR_WRITE (ATTR_SCRATCH6_VALID,          i_proc_target,   i_image);
    MBOX_ATTR_WRITE (ATTR_SCRATCH7_VALID,          i_proc_target,   i_image);

fapi_try_exit:
    FAPI_DBG ("writeMboxRegs Exiting...");
    return fapi2::current_err;
}



fapi2::ReturnCode p9_xip_customize (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
    void*     i_image,
    uint32_t& io_imageSize,             // In: Max, Out: Actual
    void*     i_ringSectionBuf,
    uint32_t& io_ringSectionBufSize,    // In: Max, Out: Actual
    uint8_t   i_sysPhase,
    uint8_t   i_modeBuild,
    void*     i_ringBuf1,
    uint32_t  i_ringBufSize1,
    void*     i_ringBuf2,
    uint32_t  i_ringBufSize2,
    uint32_t& io_bootCoreMask )
{
    FAPI_DBG ("Entering p9_xip_customize...");
    auto l_rc = 0;


    ///////////////////////////////////////////////////////////////////////////
    // Write mailbox attributes
    ///////////////////////////////////////////////////////////////////////////
    if (i_sysPhase == SYSPHASE_HB_SBE)
    {
        FAPI_TRY(writeMboxRegs(i_proc_target, i_image),
                 "p9_xip_customize: error writing mbox regs in SBE image rc=0x%.8x",
                 (uint64_t)fapi2::current_err);
    }
    else
    {
        FAPI_DBG("\n"
                 "*----------------------------------*\n"
                 "*  Nothing to do for Runtime yet.  *\n"
                 "*----------------------------------*");
    }

    l_rc = p9_xip_image_size(i_image, &io_imageSize);

    if (l_rc)
    {
        FAPI_ERR("p9_xip_image_size() failed w/rc=0x%08X", (uint32_t)l_rc);
        fapi2::current_err = l_rc;
        goto fapi_try_exit;
    }

    FAPI_DBG("Input image size is: %d", io_imageSize);

fapi_try_exit:
    FAPI_DBG("Exiting p9_xip_customize");
    return fapi2::current_err;

}




#if 0
fapi2::ReturnCode append_ex_rings()
{
    if (desiredBootCoreMask & (0x80000000 >> chipletId))
    {
        rc = fetch_and_insert_vpd_rings( i_target,
                                         i_imageIn,
                                         o_imageOut,
                                         i_sysPhase,
                                         i_buf1,
                                         i_sizeBuf1,
                                         i_buf2,
                                         i_sizeBuf2,
                                         attrDdLevel,
                                         sizeImageMax,
                                         chipletId,
                                         xipSectionDcrings );

        if (rc)
        {
            // Check if this is just a case of trying to fit in too many EXs
            if ((i_sysPhase == 0) &&
                (rc == RC_PROC_XIPC_RING_WRITE_WOULD_OVERFLOW))
            {
                uint32_t MINIMUM_VALID_EXS;
                fapi::ReturnCode lrc;
                lrc = FAPI_ATTR_GET(ATTR_SBE_IMAGE_MINIMUM_VALID_EXS, NULL, MINIMUM_VALID_EXS);

                if (lrc)
                {
                    FAPI_INF("Unable to determine ATTR_SBE_IMAGE_MINIMUM_VALID_EXS, so don't know if the minimum was met");
                    fapiLogError(lrc);
                    uint32_t& VALID_COUNT = validEXCount;
                    uint32_t& MINIMUM = MINIMUM_VALID_EXS;
                    const uint32_t& DESIRED_CORES = desiredBootCoreMask;
                    uint32_t& BOOT_CORE_MASK = io_bootCoreMask;
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_RING_WRITE_WOULD_OVERFLOW_ADD_INFO);
                    return rc;
                }

                if (validEXCount < MINIMUM_VALID_EXS)
                {
                    FAPI_ERR("Was only able to put %i EXs into the IPL image (minimum is %i)", validEXCount,        MINIMUM_VALID_EXS);
                    fapiLogError(rc);
                    uint32_t& VALID_COUNT = validEXCount;
                    uint32_t& MINIMUM = MINIMUM_VALID_EXS;
                    const uint32_t& DESIRED_CORES = desiredBootCoreMask;
                    uint32_t& BOOT_CORE_MASK = io_bootCoreMask;
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_OVERFLOW_BEFORE_REACHING_MINIMUM_EXS);
                    return rc;
                }
                else
                {
                    // out of space for this chiplet, but got enough EXs in to run
                    // so jump to the end of EXs and continue
                    rc = FAPI_RC_SUCCESS;
                    chipletId = CHIPLET_ID_EX_MAX;
                    FAPI_INF("Skipping the rest of the EX rings because image is full");
                }
            }
            else
            {
                //This is a real error, so return it
                FAPI_INF("Hit an error adding cores to the image");
                return rc;
            }
        }
        else
        {
            // Successfully added this chiplet
            // Update tracking of valid EX chiplets in the image
            io_bootCoreMask |= (0x80000000 >> chipletId);
            validEXCount++;
        }
    }
    else
    {
        FAPI_INF("Skipping EX chiplet ID 0x%X because it's not in the bootCoreMask", chipletId);
    }

}
#endif

