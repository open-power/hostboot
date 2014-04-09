/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/io_cleanup.C $                  */
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
// $Id: io_cleanup.C,v 1.8 2014/04/09 16:23:51 varkeykv Exp $
// *!***************************************************************************
// *! (C) Copyright International Business Machines Corp. 1997, 1998
// *!           All Rights Reserved -- Property of IBM
// *!                   *** IBM Confidential ***
// *!***************************************************************************
// *! FILENAME             : io_cleanup.C
// *! TITLE                :
// *! DESCRIPTION          : Cleanup procedure for re-init loop
// *! CONTEXT              :
// *!
// *! OWNER  NAME          : Varghese, Varkey         Email: varkey.kv@in.ibm.com
// *! BACKUP NAME          : Janani Swaminathan      Email:  jaswamin@in.ibm.com
// *!
// *!***************************************************************************
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|Author: | Date:  | Comment:
// --------|--------|--------|--------------------------------------------------
//   1.0   |varkeykv|07/30/11|Initial check in .
//------------------------------------------------------------------------------
#include <fapi.H>
#include "io_cleanup.H"
#include "gcr_funcs.H"



extern "C" {
     using namespace fapi;
// For clearing the FIR mask , used by io run training
// As per Irving , it should be ok to clear all FIRs here since we will scom init , also we dont touch mask values
ReturnCode clear_fir_reg(const Target &i_target,fir_io_interface_t i_chip_interface){
    ReturnCode rc;
    ecmdDataBufferBase data(64);
    FAPI_INF("io_cleanup:In the Clear FIR RW register function ");

     // use FIR AND mask register to un-mask selected bits
     rc = fapiPutScom(i_target, fir_rw_reg_addr[i_chip_interface], data);
     if (!rc.ok())
     {
         FAPI_ERR("Error writing FIR mask register (=%08X)!",
                  fir_rw_reg_addr[i_chip_interface]);
     }
    return(rc);
}

/*
 from Megan's ipl1.sh

 istep -s0..11
## forcing channel fail
getscom pu  02011C4A -pall -call -vs1
        getscom cen 0201080A -pall -call -vs1
        putscom pu 02011C4A 8000000480400000 -pall -call
        putscom cen 0201080A 8000000000000000 -pall -call
        getscom pu  02011C4A -pall -call -vs1
        getscom cen 0201080A -pall -call -vs1
## masking fir bit
putscom pu.mcs 2011843 FFFFFFFFFFFFFFFF -all
### IO reset
iotk put rx_fence=1 -t=p8:bmcs
iotk put rx_fence=1 -t=cn
iotk put ioreset_hard_bus0=111111 -t=p8:bmcs
iotk put ioreset_hard_bus0=111111 -t=cn

#exit
##clear_fir
./clear_fir.pl
### Reload
istep proc_dmi_scominit
istep dmi_scominit
##checking Zcal
iotk get tx_zcal_p_4x -t=p8:bmcs
iotk get tx_zcal_p_4x -t=cn
iotk get  tx_zcal_sm_min_val -t=p8:bmcs
iotk get tx_zcal_sm_min_val -t=cn
iotk get  tx_zcal_sm_max_val -t=p8:bmcs
iotk get tx_zcal_sm_max_val -t=cn
### Loading Zcal
iotk put tx_zcal_p_4x=00100
iotk put tx_zcal_sm_min_val=0010101
iotk put tx_zcal_sm_max_val=1000110
## Runing Zcal
istep dmi_io_dccal
## forcing channel fail
        getscom pu  02011C4A -pall -call -vs1
        getscom cen 0201080A -pall -call -vs1
        putscom pu 02011C4A 8000000480400000 -pall -call
        putscom cen 0201080A 8000000000000000 -pall -call
        getscom pu  02011C4A -pall -call -vs1
        getscom cen 0201080A -pall -call -vs1
*/

ReturnCode do_cleanup(const Target &master_target,io_interface_t master_interface,uint32_t master_group,const Target &slave_target,io_interface_t slave_interface,uint32_t slave_group)
{
     ReturnCode rc;
     uint32_t rc_ecmd = 0;
     uint8_t chip_unit = 0;
     ecmdDataBufferBase data(64);
     ecmdDataBufferBase reg_data(16),set_bits(16),clear_bits(16),temp_bits(16);

     //iotk put rx_fence=1 -t=p8:bmcs
     // No other field in this reg , so no need for RMW
     rc_ecmd = temp_bits.setBit(0);
     if(rc_ecmd)
     {
        rc.setEcmdError(rc_ecmd);
        return(rc);
     }
     rc=GCR_write(master_target, master_interface,  rx_fence_pg, master_group,0,   temp_bits, temp_bits,1,1);
     if(rc) return rc;

     //iotk put rx_fence=1 -t=cn
     rc=GCR_write(slave_target, slave_interface, rx_fence_pg, slave_group,0,   temp_bits, temp_bits,1,1);
     if(rc) return rc;

     rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS,
                    &master_target,
                    chip_unit);
     if (!rc.ok())
     {
     FAPI_ERR("Error retreiving MCS chiplet number!");
     return rc;
     }

     // swizzle to DMI number
     if (master_interface == CP_IOMC0_P0)
     {
          chip_unit = 3-(chip_unit % 4);
          // swap 0 and 1 due to Clock group swap in layout
          if(chip_unit==1){
               chip_unit=0;
          }
          else if(chip_unit==0){
               chip_unit=1;
          }


          FAPI_DBG("CHIP UNIT IS %d",chip_unit);

     }
     rc = fapiGetScom(master_target, scom_mode_pb_reg_addr[FIR_CP_IOMC0_P0], data);
     if (!rc.ok())
     {
         FAPI_ERR("Error Reading SCOM mode PB register for ioreset_hard_bus0 on master side(=%08X)!",
                  scom_mode_pb_reg_addr[FIR_CP_IOMC0_P0]);
          return rc;
     }

     rc_ecmd = data.setBit(2+chip_unit,1);  // Scom_mode_pb ,ioreset starts at bit 2
     if(rc_ecmd)
     {
        rc.setEcmdError(rc_ecmd);
        return(rc);
     }
     FAPI_DBG("Writing the Hard reset on PU ");
     // use FIR AND mask register to un-mask selected bits
     rc = fapiPutScom(master_target, scom_mode_pb_reg_addr[FIR_CP_IOMC0_P0], data);
     if (!rc.ok())
     {
         FAPI_ERR("Error writing SCOM mode PB register for ioreset_hard_bus0 on master side(=%08X)!",
                  scom_mode_pb_reg_addr[FIR_CP_IOMC0_P0]);
          return rc;
     }

     rc_ecmd = data.flushTo0();
     if(rc_ecmd)
     {
        rc.setEcmdError(rc_ecmd);
        return(rc);
     }
     // Centaur is always bus0 in reset register
     if(slave_interface == CEN_DMI){
          chip_unit=0;
     }
     rc = fapiGetScom(slave_target, scom_mode_pb_reg_addr[FIR_CEN_DMI], data);
     if (!rc.ok())
     {
         FAPI_ERR("Error Reading SCOM mode PB register for ioreset_hard_bus0 on Slave side(=%08X)!",
                   scom_mode_pb_reg_addr[FIR_CEN_DMI]);
          return rc;
     }
     rc_ecmd = data.setBit(2+chip_unit,1);  // Scom_mode_pb ,ioreset starts at bit 2
     if(rc_ecmd)
     {
        rc.setEcmdError(rc_ecmd);
        return(rc);
     }
     // use FIR AND mask register to un-mask selected bits
     rc = fapiPutScom(slave_target, scom_mode_pb_reg_addr[FIR_CEN_DMI], data);
     if (!rc.ok())
     {
         FAPI_ERR("Error writing SCOM mode PB register for ioreset_hard_bus0 on Slave side(=%08X)!",
                   scom_mode_pb_reg_addr[FIR_CEN_DMI]);
          return rc;
     }


    // NOW We clear FIRS.. need to see if we need to do this or some other procedure will do this . Bellows/Irving to respond

    rc = clear_fir_reg(slave_target,FIR_CEN_DMI);
     if(rc)
     {
        return(rc);
     }
    rc = clear_fir_reg(master_target,FIR_CP_IOMC0_P0);
     if(rc)
     {
        return(rc);
     }
    return rc;
}


// Cleans up for Centaur Reconfig or Abus hot plug case
ReturnCode io_cleanup(const Target &master_target,const Target &slave_target){
     ReturnCode rc;
     io_interface_t master_interface,slave_interface;
     uint32_t master_group=0;
     uint32_t slave_group=0;


     // This is a DMI/MC bus
     if( (master_target.getType() == fapi::TARGET_TYPE_MCS_CHIPLET )&& (slave_target.getType() == fapi::TARGET_TYPE_MEMBUF_CHIP)){
          FAPI_DBG("This is a DMI bus using base DMI scom address");
          master_interface=CP_IOMC0_P0; // base scom for MC bus
          slave_interface=CEN_DMI; // Centaur scom base
          master_group=3; // Design requires us to do this as per scom map and layout
          slave_group=0;
          rc=do_cleanup(master_target,master_interface,master_group,slave_target,slave_interface,slave_group);
          if(rc) return rc;
     }
     //This is an A Bus
     else if( (master_target.getType() == fapi::TARGET_TYPE_ABUS_ENDPOINT )&& (slave_target.getType() == fapi::TARGET_TYPE_ABUS_ENDPOINT)){
        // This procedure only supports DMI for now
     }
     else{
          const Target &MASTER_TARGET = master_target;
          const Target &SLAVE_TARGET = slave_target;
          FAPI_ERR("Invalid io_cleanup HWP invocation . Pair of targets dont belong to DMI or A bus instances");
          FAPI_SET_HWP_ERROR(rc, IO_CLEANUP_INVALID_INVOCATION_RC);
     }
     return rc;
}



} // extern
