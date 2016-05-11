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

#define MBOX_ATTR_WRITE(ID,TARGET,IMAGE) \
    { \
        fapi2::ID##_Type ID##_attrVal; \
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ID,TARGET,ID##_attrVal),\
                 "MBOX_ATTR_WRITE: Error getting %s", #ID); \
        p9_xip_set_scalar(IMAGE,#ID,ID##_attrVal); \
    }

fapi2::ReturnCode writeMboxRegs (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_system_target,
    void* io_image)
{
    FAPI_DBG ("writeMboxRegs Entering...");

    MBOX_ATTR_WRITE (ATTR_I2C_BUS_DIV_REF,         i_proc_target,   io_image);
    MBOX_ATTR_WRITE (ATTR_FUNCTIONAL_EQ_EC_VALID,  i_proc_target,   io_image);
    MBOX_ATTR_WRITE (ATTR_EQ_GARD,                 i_proc_target,   io_image);
    MBOX_ATTR_WRITE (ATTR_EC_GARD,                 i_proc_target,   io_image);
    MBOX_ATTR_WRITE (ATTR_I2C_BUS_DIV_REF_VALID,   i_proc_target,   io_image);
    MBOX_ATTR_WRITE (ATTR_FW_MODE_FLAGS_VALID,     i_proc_target,   io_image);
    MBOX_ATTR_WRITE (ATTR_ISTEP_MODE,              i_proc_target,   io_image);
    MBOX_ATTR_WRITE (ATTR_SBE_RUNTIME_MODE,        i_proc_target,   io_image);
    MBOX_ATTR_WRITE (ATTR_IS_MPIPL,                i_system_target, io_image);
    MBOX_ATTR_WRITE (ATTR_IS_SP_MODE,              i_proc_target,   io_image);
    MBOX_ATTR_WRITE (ATTR_SBE_FFDC_ENABLE,         i_proc_target,   io_image);
    MBOX_ATTR_WRITE (ATTR_SBE_INTERNAL_FFDC_ENABLE, i_proc_target,   io_image);
    MBOX_ATTR_WRITE (ATTR_BOOT_FREQUENCY_VALID,    i_proc_target,   io_image);
    MBOX_ATTR_WRITE (ATTR_NEST_PLL_BUCKET,         i_system_target,   io_image);
    MBOX_ATTR_WRITE (ATTR_BOOT_FREQ_MULT,          i_proc_target,   io_image);
    MBOX_ATTR_WRITE (ATTR_HWP_CONTROL_FLAGS_VALID, i_proc_target,   io_image);
    MBOX_ATTR_WRITE (ATTR_SYSTEM_IPL_PHASE,        i_system_target, io_image);
    MBOX_ATTR_WRITE (ATTR_SYS_FORCE_ALL_CORES,     i_system_target,   io_image);
    MBOX_ATTR_WRITE (ATTR_RISK_LEVEL,              i_system_target,   io_image);
    MBOX_ATTR_WRITE (ATTR_DISABLE_HBBL_VECTORS,    i_system_target,   io_image);
    MBOX_ATTR_WRITE (ATTR_CHIP_SELECTION_VALID,    i_proc_target,   io_image);
    MBOX_ATTR_WRITE (ATTR_CHIP_SELECTION,          i_proc_target,   io_image);
    MBOX_ATTR_WRITE (ATTR_NODE_POS,                i_proc_target,   io_image);
    MBOX_ATTR_WRITE (ATTR_CHIP_POS,                i_proc_target,   io_image);
    MBOX_ATTR_WRITE (ATTR_SCRATCH6_VALID,          i_proc_target,   io_image);
    MBOX_ATTR_WRITE (ATTR_SCRATCH7_VALID,          i_proc_target,   io_image);

fapi_try_exit:
    FAPI_DBG ("writeMboxRegs Exiting...");
    return fapi2::current_err;
}

fapi2::ReturnCode p9_xip_customize (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_system_target,
    void* io_image)
{
    FAPI_DBG ("Entering p9_xip_customize...");

    FAPI_TRY(writeMboxRegs(i_proc_target, i_system_target, io_image),
             "p9_xip_customize: error writing mbox regs in SBE image rc=0x%.8x",
             (uint64_t)fapi2::current_err);


fapi_try_exit:
    FAPI_DBG("Exiting p9_xip_customize");
    return fapi2::current_err;

}
