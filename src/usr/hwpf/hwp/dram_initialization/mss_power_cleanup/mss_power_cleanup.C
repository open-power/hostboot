/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_initialization/mss_power_cleanup/mss_power_cleanup.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: mss_power_cleanup.C,v 1.10 2014/03/25 18:06:03 jdsloat Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/mss_power_cleanup.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_power_cleanup
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Jacob Sloat      Email: jdsloat@us.ibm.com
// *! BACKUP NAME : Anuwat Saetow     Email: asaetow@us.ibm.com

// *! ADDITIONAL COMMENTS :
//
// power clean up
// needs to deconfig centaurs and mba - (needs three targets)
//    Two reasons:  centaur is bad and no DIMMs
//    Needed to set up fences and turn off power / clock drivers
//
// There is a sub function that cleans up an mba that needs to be called if we deconfigure an mba
// this procedure does not write attributes just shuts down hardware
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.10  | jdsloat  |25-MAR-14| ENUM_ATTR_MSS_INIT_STATE_COLD became fapi::ENUM_ATTR_MSS_INIT_STATE_COLD
//   1.9   | jdsloat  |25-MAR-14| Fixed 1.8
//   1.8   | jdsloat  |25-MAR-14| Added a check to break procedure if HW non-functional
//   1.7   | bellows  |19-FEB-14| RAS Review Updates Pass 2
//   1.6   |bellows   |17-FEB-14| RAS review updates
//   1.5   |bellows   |05-FEB-14| Making this procedure work on really non-functional centaurs
//   1.4   |bellows   |21-Nov-13| Gerrit Review Updates - unused variable removed
//   1.3   |bellows   |11-Nov-13| Gerrit Review Updates
//   1.2   |bellows   |11-Nov-13| Update due to new istep location
//   1.1   |bellows   |07-Nov-13| copied from mss_cnfg_cleanup version 1.3
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// My Includes
//------------------------------------------------------------------------------
#include <cen_stopclocks.H>
#include <mss_power_cleanup.H>
#include <cen_scom_addresses.H>
#include <mss_eff_config.H>
#include <common_scom_addresses.H>

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi.H>

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------

const uint8_t PORT_SIZE = 2;
const uint8_t DIMM_SIZE = 2;


//------------------------------------------------------------------------------
// extern encapsulation
//------------------------------------------------------------------------------
extern "C"
{

//------------------------------------------------------------------------------
// @brief mss_power_cleanup(): This function will disable a centaur - fencing it and powering it down
//
// @param const fapi::Target i_target_centaur: the fapi target of the centaur
// @param const fapi::Target i_target_mba0: the mba0 target
// @param const fapi::Target i_target_mba1: the mba1 target
//
// @return fapi::ReturnCode
//------------------------------------------------------------------------------
  fapi::ReturnCode mss_power_cleanup(const fapi::Target & i_target_centaur, const fapi::Target & i_target_mba0, const fapi::Target & i_target_mba1)
  {
    fapi::ReturnCode rc,rc0,rc1,rcf,rcc;
    uint8_t centaur_functional=1, mba0_functional=1, mba1_functional=1;
    uint8_t cen_init_state = 0;

    FAPI_INF("Running mss_power_cleanupon %s\n", i_target_centaur.toEcmdString());

    do
    {
      rc = FAPI_ATTR_GET(ATTR_FUNCTIONAL, &i_target_centaur, centaur_functional);
      if(rc) { FAPI_ERR("ERROR: Cannot get ATTR_FUNCTIONAL"); break; }

      rc = FAPI_ATTR_GET(ATTR_FUNCTIONAL, &i_target_mba0, mba0_functional);
      if(rc) { FAPI_ERR("ERROR: Cannot get ATTR_FUNCTIONAL"); break; }

      rc = FAPI_ATTR_GET(ATTR_FUNCTIONAL, &i_target_mba1, mba1_functional);
      if(rc) { FAPI_ERR("ERROR: Cannot get ATTR_FUNCTIONAL"); break; }

      rc = FAPI_ATTR_GET(ATTR_MSS_INIT_STATE, &i_target_centaur, cen_init_state);
      if(rc) { FAPI_ERR("ERROR: Cannot get ATTR_INIT_STATE"); break; }

      if (cen_init_state == fapi::ENUM_ATTR_MSS_INIT_STATE_COLD)
      {
	FAPI_ERR("Centaur clocks not on.  Cannot execute mss_power_cleanup on this target: %s", i_target_centaur.toEcmdString()); break;
      } 

      rc0 = mss_power_cleanup_mba_part1(i_target_centaur, i_target_mba0);
      rc1 = mss_power_cleanup_mba_part1(i_target_centaur, i_target_mba1);

      rcf = mss_power_cleanup_mba_fence(i_target_centaur, i_target_mba0, i_target_mba1);

      rcc = mss_power_cleanup_centaur(i_target_centaur);



      if(rc0) {
        if(mba0_functional) {
          FAPI_ERR("mba0 was functional yet it got a bad return code");
          const fapi::Target & MBA_CHIPLET = i_target_mba0;
          FAPI_SET_HWP_ERROR(rc0, RC_MSS_POWER_CLEANUP_MBA0_UNEXPECTED_BAD_RC);
          rc=rc0;
          break;
        }
        else {
          FAPI_INF("mba0 was not functional and it got a bad return code");
        }
      }

      if(rc1) {
        if(mba1_functional) {
          FAPI_ERR("mba1 was functional yet it got a bad return code");
          const fapi::Target & MBA_CHIPLET = i_target_mba1;
          FAPI_SET_HWP_ERROR(rc1, RC_MSS_POWER_CLEANUP_MBA1_UNEXPECTED_BAD_RC);
          rc=rc1;
          break;
        }
        else {
          FAPI_INF("mba1 was not functional and it got a bad return code");
        }
      }

      if(rcf) {
        if(centaur_functional) {
          FAPI_ERR("centaur was functional yet it got a bad return code during fencing");
          const fapi::Target & CENTAUR = i_target_centaur;
          FAPI_SET_HWP_ERROR(rcf, RC_MSS_POWER_CLEANUP_FENCING_UNEXPECTED_BAD_RC);
          rc=rcf;
          break;
        }
        else {
          FAPI_INF("centaur was not functional and it got a bad return code");
        }
      }

      if(rcc) {
        if(centaur_functional) {
          FAPI_ERR("centaur was functional yet it got a bad return code during cleanup");
          const fapi::Target & CENTAUR = i_target_centaur;
          FAPI_SET_HWP_ERROR(rcc, RC_MSS_POWER_CLEANUP_CENTAUR_UNEXPECTED_BAD_RC);
          rc=rcc;
          break;
        }
        else {
          FAPI_INF("centaur was not functional and it got a bad return code");
        }
      }

    } while(0); 

    return rc;
  } // end mss_power_cleanup()

  fapi::ReturnCode set_powerdown_bits(int mba_functional,  ecmdDataBufferBase &data_buffer_64)
  {
    fapi::ReturnCode rc;
    uint32_t rc_num = 0;

    if(mba_functional == 0)
    {
      FAPI_INF("set_powerdown_bits MBA not Functional");
      rc_num |= data_buffer_64.setBit(0  +48);    // MASTER_PD_CNTL (48)
      rc_num |= data_buffer_64.setBit(1  +48);    // ANALOG_INPUT_STAB2 (49)
      rc_num |= data_buffer_64.setBit(7  +48);    // ANALOG_INPUT_STAB1 (55)
      rc_num |= data_buffer_64.setBit(8  +48,2);  // SYSCLK_CLK_GATE (56:57)
      rc_num |= data_buffer_64.setBit(10 +48);    // DP18_RX_PD(0) (58)
      rc_num |= data_buffer_64.setBit(11 +48);    // DP18_RX_PD(1) (59)
      rc_num |= data_buffer_64.setBit(14 +48);    // TX_TRISTATE_CNTL (62)
      rc_num |= data_buffer_64.setBit(15 +48);    // VCC_REG_PD (63)
    }
    else
    {
      rc_num |= data_buffer_64.clearBit(0  +48);    // MASTER_PD_CNTL (48)
      rc_num |= data_buffer_64.clearBit(1  +48);    // ANALOG_INPUT_STAB2 (49)
      rc_num |= data_buffer_64.clearBit(7  +48);    // ANALOG_INPUT_STAB1 (55)
      rc_num |= data_buffer_64.clearBit(8  +48,2);  // SYSCLK_CLK_GATE (56:57)
      rc_num |= data_buffer_64.clearBit(10 +48);    // DP18_RX_PD(0) (58)
      rc_num |= data_buffer_64.clearBit(11 +48);    // DP18_RX_PD(1) (59)
      rc_num |= data_buffer_64.clearBit(14 +48);    // TX_TRISTATE_CNTL (62)
      rc_num |= data_buffer_64.clearBit(15 +48);    // VCC_REG_PD (63)
    }

    if (rc_num)
    {
      FAPI_ERR( "Error setting up buffers");
      rc.setEcmdError(rc_num);
    }

    return rc;
  }

  fapi::ReturnCode mss_power_cleanup_mba_part1(const fapi::Target & i_target_centaur, const fapi::Target & i_target_mba)
  {
  // turn off functional vector
    fapi::ReturnCode rc;
    uint8_t centaur_functional;
    uint8_t mba_functional;
    ecmdDataBufferBase data_buffer_64(64);
    uint32_t rc_num = 0;
    uint8_t unit_pos = 0;
    ecmdDataBufferBase cfam_data(32);
    int memon=0;

    do
    {
      FAPI_INF("Starting mss_power_cleanup_mba_part1");

      rc = FAPI_ATTR_GET(ATTR_FUNCTIONAL, &i_target_centaur, centaur_functional);
      if(rc)
      {
        FAPI_ERR("ERROR: Cannot get ATTR_FUNCTIONAL");
        break;
      }
      FAPI_INF("working on a centaur whose functional is %d", centaur_functional);

      rc = FAPI_ATTR_GET(ATTR_FUNCTIONAL, &i_target_mba, mba_functional);
      if(rc) {
        FAPI_ERR("ERROR: Cannot get ATTR_FUNCTIONAL");
        break;
      }
      FAPI_INF("working on an mba whose functional is %d", mba_functional);

// But to clarify so there's no misconception, you can only turn off the clocks to the MEMS grid (Ports 2/3).  If you want to deconfigure Ports 0/1, there is no way to turn those clocks off. The best you can do there is shut down the PHY inside DDR (I think they have an ultra low power mode where you can turn off virtually everything including their PLLs, phase rotators, analogs , FIFOs, etc) plus of course you can disable their I/O. I think those steps should be done no matter which port you're deconfiguring, but in terms of the chip clock grid, you only get that additional power savings in the bad Port 2/3 case.
      if(centaur_functional == 1 && mba_functional == 0)
      {
        FAPI_INF("cleanup_part1 MBA not functional");
      // check that clocks are up to the DDR partition before turning it off
      // this case will only happen if we get memory up and later come back and want to
      // deconfigure it.  The first time, it may not even be up yet.
        rc = fapiGetScom(i_target_centaur, TP_CLK_STATUS_0x01030008, data_buffer_64);
        if(rc) {
          FAPI_ERR("ERROR: Cannot getScom 0x1030008");
          break;
        }
        if(data_buffer_64.getDoubleWord(0) == 0x000007FFFFFFFFFFull)
        { // pervasive clocks are on
          rc = fapiGetScom(i_target_centaur, MEM_CLK_STATUS_0x03030008, data_buffer_64);
          if(rc)
          {
            FAPI_ERR("ERROR: Cannot getScom 0x3030008");
            break;
          }
          if(data_buffer_64.getDoubleWord(0) == 0x0000001FFFFFFFFFull)
          {
            memon=1;
          }
        }


        if(memon)
        {
          FAPI_INF("Mem Clocks On");

          if(mba_functional == 0)
          {

            FAPI_INF("This mba is not functional, doing more transactions");

      // Do Port 0
            rc = fapiGetScom(i_target_mba, DPHY01_DDRPHY_PC_POWERDOWN_1_P0_0x8000C0100301143F, data_buffer_64);
            if(rc)
            {
              FAPI_ERR("ERROR: Cannot getScom DPHY01_DDRPHY_PC_POWERDOWN_1_P0_0x8000C0100301143F");
              break;
            }

            rc = set_powerdown_bits(mba_functional, data_buffer_64);
            if(rc) break;

            rc = fapiPutScom(i_target_mba, DPHY01_DDRPHY_PC_POWERDOWN_1_P0_0x8000C0100301143F, data_buffer_64);
            if(rc)
            {
              FAPI_ERR("ERROR: Cannot putScom DPHY01_DDRPHY_PC_POWERDOWN_1_P0_0x8000C0100301143F");
              break;
            }

      // Do Port 1
            rc = fapiGetScom(i_target_mba, DPHY01_DDRPHY_PC_POWERDOWN_1_P1_0x8001C0100301143F, data_buffer_64);
            if(rc)
            {
              FAPI_ERR("ERROR: Cannot getScom DPHY01_DDRPHY_PC_POWERDOWN_1_P1_0x8001C0100301143F");
              break;
            }

            rc = set_powerdown_bits(mba_functional, data_buffer_64);
            if(rc) break;

            rc = fapiPutScom(i_target_mba, DPHY01_DDRPHY_PC_POWERDOWN_1_P1_0x8001C0100301143F, data_buffer_64);
            if(rc)
            {
              FAPI_ERR("ERROR: Cannot putScom DPHY01_DDRPHY_PC_POWERDOWN_1_P1_0x8001C0100301143F");
              break;
            }
// From Section 10.4
          } // mba functional
        }
//12. Grid Clock off , South Port Pair. This is done by asserting the GP bit controlling
//TP_CHIP_DPHY23_GRID_DISABLE (Table 57 ). This must be decided during CFAMINIT . it may not be
//dynamically updated
        rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target_mba, unit_pos); // 0 = MBA01 and 1 = MBA23
        if(rc)
        {
          FAPI_ERR("ERROR: Cannot get ATTR_CHIP_UNIT_POS");
          break;
        }

        if(unit_pos == 1)
        {
          rc = fapiGetCfamRegister( i_target_centaur, CFAM_FSI_GP4_0x00001013, cfam_data);
          if(rc)
          {
            FAPI_ERR("ERROR: Cannot getCfamRegister CFAM_FSI_GP4_0x00001013");
            break;
          }

          if(mba_functional == 0)
          {
            rc_num |= cfam_data.setBit(1);
          }
          else
          {
            rc_num |= cfam_data.clearBit(1);
          }

          if (rc_num)
          {
            FAPI_ERR( "Error setting up buffers");
            rc.setEcmdError(rc_num);
            break;
          }

          rc = fapiPutCfamRegister( i_target_centaur, CFAM_FSI_GP4_0x00001013, cfam_data);
          if(rc)
          {
            FAPI_ERR("ERROR: Cannot putCfamRegister CFAM_FSI_GP4_0x00001013");
            break;
          }
        } // mba 1 only code

      }
    }
    while(0);

    if(rc) {
      FAPI_ERR("ERROR: Bad RC in mss_power_cleanup_mba_part1");
    }
    return rc;
  } // end of mss_power_cleanup_mba_part1

  fapi::ReturnCode mss_power_cleanup_mba_fence(const fapi::Target & i_target_centaur, const fapi::Target & i_target_mba0, const fapi::Target & i_target_mba1) {
  // turn off functional vector
    fapi::ReturnCode rc;
    uint8_t mba_functional0, mba_functional1;
    ecmdDataBufferBase data_buffer_64(64);
    uint32_t rc_num = 0;
    ecmdDataBufferBase cfam_data(32);
    int memon=0;

    do
    {
      FAPI_INF("Starting mss_power_cleanup_mba_fence");
      rc = FAPI_ATTR_GET(ATTR_FUNCTIONAL, &i_target_mba0, mba_functional0);
      if(rc) break;
      rc = FAPI_ATTR_GET(ATTR_FUNCTIONAL, &i_target_mba1, mba_functional1);
      if(rc) break;
      FAPI_INF("mba0 functional is %d", mba_functional0);
      FAPI_INF("mba1 functional is %d", mba_functional1);


//enable_partial_good_dc memn_fence_dc mems_fence_dc Fencing Behavior
//0 0 0 Normal operation, no fencing enabled
//0 1 1 Chiplet boundary (inter chiplet nets) fencing enabled. Both
//      bits set for full fencing. Both MBAs fenced from MBS but
//      not from each other
//0 0 1 Not a valid setting. Fencing enabled for MEMS chiplet boundary only.
//0 1 0 Not a valid setting. Fencing enabled for MEMS chiplet boundary only.
//1 0 0 No Fencing enabled .
//1 0 1 MEMS (Ports 2/3) bad, fencing enabled to MEMN and at chiplet boundary of MEMS
//1 1 0 MEMN (Ports 0/1) bad, fencing enabled to MEMS and at chiplet boundary of MEMN
//1 1 1 Fencing enabled between MEMN and MEMS and at chiplet boundary.
      rc = fapiGetScom(i_target_centaur, TP_CLK_STATUS_0x01030008, data_buffer_64);
      if(rc) break;
      if(data_buffer_64.getDoubleWord(0) == 0x000007FFFFFFFFFFull)
      { // pervasive clocks are on
        rc = fapiGetScom(i_target_centaur, MEM_CLK_STATUS_0x03030008, data_buffer_64);
        if(rc) break;
        if(data_buffer_64.getDoubleWord(0) == 0x0000001FFFFFFFFFull)
        {
          memon=1;
        }
      }

      if(memon) {
        FAPI_INF("Mem Clocks On");
        rc = fapiGetScom( i_target_centaur, MEM_GP3_0x030F0012, data_buffer_64);
        if (rc) break;

        if(mba_functional0 == 0 || mba_functional1 == 0)
        { // one of the two are non-functional
          rc_num |= data_buffer_64.setBit(31); // enable_partial_good_dc
        }
        else
        {
          rc_num |= data_buffer_64.clearBit(31); 
        }

        if(mba_functional0 == 0)
        {
          rc_num |= data_buffer_64.setBit(18); // memn_fence_dc
        }
        else
        {
          rc_num |= data_buffer_64.clearBit(18); // memn_fence_dc
        }
        if(mba_functional1 == 0)
        {
          rc_num |= data_buffer_64.setBit(17); // mems_fence_dc
        }
        else {
          rc_num |= data_buffer_64.clearBit(17); // mems_fence_dc
        }

        if (rc_num)
        {
          FAPI_ERR( "Error setting up buffers");
          rc.setEcmdError(rc_num);
          break;
        }

        rc = fapiPutScom( i_target_centaur, MEM_GP3_0x030F0012, data_buffer_64);
        if (rc) break;
      }


    } while(0);

    if(rc)
    {
      FAPI_ERR("ERROR: during mss_power_cleanup_mba_fence");
    }
    return rc;
  } // end of mss_power_cleanup_mba_fense

  fapi::ReturnCode mss_power_cleanup_centaur(const fapi::Target & i_target_centaur) {
  // turn off functional vector
    fapi::ReturnCode rc;
    uint8_t centaur_functional;

    do
    {
      FAPI_INF("Starting mss_power_cleanup_centaur");
      rc = FAPI_ATTR_GET(ATTR_FUNCTIONAL, &i_target_centaur, centaur_functional);
      if(rc) {
        FAPI_ERR("ERROR: Cannot get ATTR_FUNCTIONAL");
        break;
      }

      int memon=0;
      int pervon=0;
      ecmdDataBufferBase data_buffer_64(64);

      if(centaur_functional == 0) { 
      // check that clocks are up to the DDR partition before turning it off
      // this case will only happen if we get memory up and later come back and want to
      // deconfigure it.  The first time, it may not even be up yet.
        rc = fapiGetScom(i_target_centaur, TP_CLK_STATUS_0x01030008, data_buffer_64);
        if(rc)
        {
          FAPI_ERR("ERROR: Cannot getScom 0x1030008");
          break;
        }
        if(data_buffer_64.getDoubleWord(0) == 0x000007FFFFFFFFFFull)
        { // pervasive clocks are on
          pervon=1;
          rc = fapiGetScom(i_target_centaur, MEM_CLK_STATUS_0x03030008, data_buffer_64);
          if(rc)
          {
            FAPI_ERR("ERROR: Cannot getScom 0x3030008");
            break;
          }
          if(data_buffer_64.getDoubleWord(0) == 0x0000001FFFFFFFFFull)
          {
            memon=1;
          }
        }


        if(pervon || memon)
        {
          bool l_stop_mem_clks=true;
          bool l_stop_nest_clks=true;
          bool l_stop_dram_rfrsh_clks=true;
          bool l_stop_tp_clks=false;
          bool l_stop_vitl_clks=false;
          FAPI_INF("Calling cen_stopclocks");
          rc = cen_stopclocks(i_target_centaur, l_stop_mem_clks, l_stop_nest_clks, l_stop_dram_rfrsh_clks, l_stop_tp_clks, l_stop_vitl_clks );

        } // clocks are on, so kill them
      } // non functional centaurs
      FAPI_INF("Ending mss_power_cleanup_centaur");
    }
    while(0);

    if(rc) { FAPI_ERR("ERROR: Bad RC in mss_power_cleanup_centaur"); }
    return rc;
  } // end of mss_power_cleanup_centaur


} // extern "C"

