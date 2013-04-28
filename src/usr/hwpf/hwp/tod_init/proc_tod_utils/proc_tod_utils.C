/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/tod_init/proc_tod_utils/proc_tod_utils.C $   */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
// $Id: proc_tod_utils.C,v 1.4 2012/10/23 19:17:00 jklazyns Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *!
// *! TITLE : proc_tod_utils.C
// *!
// *! DESCRIPTION : TOD helper functions; not called directly, but used by other
// *!               FAPI procedures
// *!
// *! OWNER NAME  : Nick Klazynski  Email: jklazyns@us.ibm.com
// *! BACKUP NAME :                 Email:
// *!
// *! ADDITIONAL COMMENTS :
// *!
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "proc_tod_utils.H"
#include "p8_scom_addresses.H"

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

extern "C"
{

//------------------------------------------------------------------------------
// function: proc_tod_utils_get_tfmr_reg
//
// parameters: i_target     => chip target
//             o_tfmr_val   => TFMR value read
// returns: FAPI_RC_SUCCESS if TFMR read is successful
//          else FAPI or ECMD error is sent through
//
//------------------------------------------------------------------------------
fapi::ReturnCode proc_tod_utils_get_tfmr_reg(
    const fapi::Target& i_target,
    ecmdDataBufferBase& o_tfmr_val)
{
    fapi::ReturnCode rc;
    ecmdDataBufferBase data(64);
    uint32_t rc_ecmd = 0;

    FAPI_INF("proc_tod_utils_get_tfmr_reg: Start");

    do
    {
        //FAPI_DBG("proc_tod_utils_get_tfmr_reg: Setting SPR_MODE to LPAR0/T0");
        rc_ecmd |= data.flushTo0();
        rc_ecmd |= data.setBit(SPR_MODE_REG_MODE_SPRC_WR_EN);
        rc_ecmd |= data.setBit(SPR_MODE_REG_MODE_SPRC0_SEL);
        rc_ecmd |= data.setBit(SPR_MODE_REG_MODE_SPRC_T0_SEL);
        if (rc_ecmd)
        {
            FAPI_ERR("proc_tod_utils_get_tfmr_reg: Error 0x%08X in ecmdDataBuffer setup for EX_PERV_SPR_MODE_10013281 SCOM.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom(i_target, EX_PERV_SPR_MODE_10013281, data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_tod_utils_get_tfmr_reg: fapiPutScom error for EX_PERV_SPR_MODE_10013281 SCOM.");
            break;
        }
        //FAPI_DBG("proc_tod_utils_get_tfmr_reg: Setting SPRC to T0's TMFR");
        rc_ecmd |= data.flushTo0();
        rc_ecmd |= data.insertFromRight(SPRC_REG_SEL_TFMR_T0,SPRC_REG_SEL,SPRC_REG_SEL_LEN);
        if (rc_ecmd)
        {
            FAPI_ERR("proc_tod_utils_get_tfmr_reg: Error 0x%08X in ecmdDataBuffer setup for EX_PERV_L0_SCOM_SPRC_10013280 SCOM.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom(i_target, EX_PERV_L0_SCOM_SPRC_10013280, data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_tod_utils_get_tfmr_reg: fapiPutScom error for EX_PERV_L0_SCOM_SPRC_10013280 SCOM.");
            break;
        }

        //FAPI_DBG("proc_tod_utils_get_tfmr_reg: Reading SPRD for T0's TMFR");
        rc = fapiGetScom(i_target, EX_PERV_SPRD_L0_100132A3, o_tfmr_val);
        if (!rc.ok())
        {
            FAPI_ERR("proc_tod_utils_get_tfmr_reg: fapiGetScom error for EX_PERV_SPRD_L0_100132A3 SCOM.");
            break;
        }

    } while(0);

    FAPI_INF("proc_tod_utils_get_tfmr_reg: End");
    return rc;
}

//------------------------------------------------------------------------------
// function: proc_tod_utils_set_tfmr_reg
//
// parameters: i_target     => chip target
//             i_tfmr_val   => TFMR value to write
// returns: FAPI_RC_SUCCESS if TFMR write is successful
//          else FAPI or ECMD error is sent through
//
//------------------------------------------------------------------------------
fapi::ReturnCode proc_tod_utils_set_tfmr_reg(
    const fapi::Target& i_target,
    ecmdDataBufferBase& i_tfmr_val)
{
    fapi::ReturnCode rc;
    ecmdDataBufferBase data(64);
    uint32_t rc_ecmd = 0;

    FAPI_INF("proc_tod_utils_set_tfmr_reg: Start");

    do
    {
        //FAPI_DBG("proc_tod_utils_set_tfmr_reg: Setting SPR_MODE to LPAR0/T0");
        rc_ecmd |= data.flushTo0();
        rc_ecmd |= data.setBit(SPR_MODE_REG_MODE_SPRC_WR_EN);
        rc_ecmd |= data.setBit(SPR_MODE_REG_MODE_SPRC0_SEL);
        rc_ecmd |= data.setBit(SPR_MODE_REG_MODE_SPRC_T0_SEL);
        if (rc_ecmd)
        {
            FAPI_ERR("proc_tod_utils_set_tfmr_reg: Error 0x%08X in ecmdDataBuffer setup for EX_PERV_SPR_MODE_10013281 SCOM.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom(i_target, EX_PERV_SPR_MODE_10013281, data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_tod_utils_set_tfmr_reg: fapiPutScom error for EX_PERV_SPR_MODE_10013281 SCOM.");
            break;
        }
        //FAPI_DBG("proc_tod_utils_set_tfmr_reg: Setting SPRC to T0's TMFR");
        rc_ecmd |= data.flushTo0();
        rc_ecmd |= data.insertFromRight(SPRC_REG_SEL_TFMR_T0,SPRC_REG_SEL,SPRC_REG_SEL_LEN);
        if (rc_ecmd)
        {
            FAPI_ERR("proc_tod_utils_set_tfmr_reg: Error 0x%08X in ecmdDataBuffer setup for EX_PERV_L0_SCOM_SPRC_10013280 SCOM.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom(i_target, EX_PERV_L0_SCOM_SPRC_10013280, data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_tod_utils_set_tfmr_reg: fapiPutScom error for EX_PERV_L0_SCOM_SPRC_10013280 SCOM.");
            break;
        }
        //FAPI_DBG("proc_tod_utils_set_tfmr_reg: Writing SPRD to set T0's TMFR");
        rc = fapiPutScom(i_target, EX_PERV_SPRD_L0_100132A3, i_tfmr_val);
        if (!rc.ok())
        {
            FAPI_ERR("proc_tod_utils_set_tfmr_reg: fapiGetScom error for EX_PERV_SPRD_L0_100132A3 SCOM.");
            break;
        }
    } while(0);

    FAPI_INF("proc_tod_utils_set_tfmr_reg: End");
    return rc;
}

} // extern "C"
