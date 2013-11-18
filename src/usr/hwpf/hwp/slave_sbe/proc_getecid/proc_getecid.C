/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_getecid/proc_getecid.C $      */
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
// $Id: proc_getecid.C,v 1.9 2013/11/09 18:39:29 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/utils/proc_getecid.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_getecid.C
// *! DESCRIPTION : Get ECID string from target using SCOM
// *!
// *! OWNER NAME  : Joe McGill     Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <proc_getecid.H>

extern "C" {

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


// HWP entry point
fapi::ReturnCode proc_getecid(
    const fapi::Target& i_target,
    ecmdDataBufferBase& io_fuseString)
{
    // return code
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;
    uint64_t attr_data[2];

    // mark HWP entry
    FAPI_DBG("proc_getecid: Start");

    io_fuseString.setBitLength(112); // sets size and zeros out buffer
    ecmdDataBufferBase otprom_mode_data(64);
    ecmdDataBufferBase ecid_data(64);

    do
    {

      //
      // clear ECC enable before reading ECID data (read-modify-write OTPROM Mode register)
      //

      rc = fapiGetScom(i_target, OTPC_M_MODE_REGISTER_0x00010008, otprom_mode_data);
      if (!rc.ok())
      {
          FAPI_ERR("proc_getecid: fapiGetScom error (OTPC_M_MODE_REGISTER_0x00010008) for %s",
                   i_target.toEcmdString());
          break;
      }

      rc_ecmd |= otprom_mode_data.clearBit(OTPC_M_MODE_REGISTER_ECC_ENABLE_BIT);
      if (rc_ecmd)
      {
          FAPI_ERR("proc_getecid: Error 0x%X setting up OTPROM Mode register data buffer",
                   rc_ecmd);
          rc.setEcmdError(rc_ecmd);
          break;
      }

      rc = fapiPutScom(i_target, OTPC_M_MODE_REGISTER_0x00010008, otprom_mode_data);
      if (!rc.ok())
      {
          FAPI_ERR("proc_getecid: fapiPutScom error (OTPC_M_MODE_REGISTER_0x00010008) for %s",
                   i_target.toEcmdString());
          break;
      }


      //
      // extract and manipulate ECID data
      //

      rc = fapiGetScom(i_target, ECID_PART_0_0x00018000, ecid_data);
      if (!rc.ok())
      {
          FAPI_ERR("proc_getecid: fapiGetScom error (ECID_PART_0_0x00018000) for %s",
                   i_target.toEcmdString());
          break;
      }

      // 0:63 become 63:0
      rc_ecmd |= ecid_data.reverse();
      // copy bits 0:63 from the scom into 0:63 of the fuseString/attribute data
      rc_ecmd |= io_fuseString.insert(ecid_data,  0, 64);
      attr_data[0] = ecid_data.getDoubleWord(0);

      if (rc_ecmd)
      {
          FAPI_ERR("proc_getecid: Error 0x%X processing ECID (part 0) data buffer",
                   rc_ecmd);
          rc.setEcmdError(rc_ecmd);
          break;
      }

      rc = fapiGetScom(i_target, ECID_PART_1_0x00018001, ecid_data);
      if (!rc.ok())
      {
          FAPI_ERR("proc_getecid: fapiGetScom error (ECID_PART_1_0x00018001) for %s",
                   i_target.toEcmdString());
          break;
      }

      // 0:63 become 63:0
      rc_ecmd |= ecid_data.reverse();
      // copy bits 0:47 from the scom into 64:111 of the fuseString
      // all bits into attribute data
      rc_ecmd |= io_fuseString.insert(ecid_data, 64, 48);
      attr_data[1] = ecid_data.getDoubleWord(0);

      if (rc_ecmd)
      {
          FAPI_ERR("proc_getecid: Error 0x%X processing ECID (part 1) data buffer",
                   rc_ecmd);
          rc.setEcmdError(rc_ecmd);
          break;
      }

      // push fuse string into attribute
      rc = FAPI_ATTR_SET(ATTR_ECID,
                         &i_target,
                         attr_data);
      if (!rc.ok())
      {
          FAPI_ERR("proc_getecid: Error from FAPI_ATTR_SET (ATTR_ECID) for %s (attr_data[0] = %016llX, attr_data[1] = %016llX",
                   i_target.toEcmdString(), attr_data[0], attr_data[1]);
          break;
      }

      //
      // restore ECC enable setting
      //

      rc_ecmd |= otprom_mode_data.setBit(OTPC_M_MODE_REGISTER_ECC_ENABLE_BIT);
      if (rc_ecmd)
      {
          FAPI_ERR("proc_getecid: Error 0x%X setting up OTPROM Mode register data buffer",
                   rc_ecmd);
          rc.setEcmdError(rc_ecmd);
          break;
      }

      rc = fapiPutScom(i_target, OTPC_M_MODE_REGISTER_0x00010008, otprom_mode_data);
      if (!rc.ok())
      {
          FAPI_ERR("proc_getecid: fapiPutScom error (OTPC_M_MODE_REGISTER_0x00010008) for %s",
                   i_target.toEcmdString());
          break;
      }

    } while(0);

    // mark HWP exit
    FAPI_DBG("proc_getecid: End");
    return rc;
}

} // extern "C"
