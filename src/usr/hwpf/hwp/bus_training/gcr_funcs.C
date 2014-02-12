/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/gcr_funcs.C $                   */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: gcr_funcs.C,v 1.10 2014/02/06 10:27:48 jaswamin Exp $
// *!***************************************************************************
// *! (C) Copyright International Business Machines Corp. 1997, 1998
// *!           All Rights Reserved -- Property of IBM
// *!                   *** IBM Confidential ***
// *!***************************************************************************
// *! FILENAME             : gcr_funcs.C
// *! TITLE                : 
// *! DESCRIPTION          : 
// *! CONTEXT              : 
// *!
// *! OWNER  NAME          : Varghese, Varkey         Email: varkeykv@in.ibm.com
// *! BACKUP NAME          : Swaminathan, Janani      Email: jaswamin@in.ibm.com
// *!
// *!***************************************************************************
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|Author: | Date:  | Comment:
// --------|--------|--------|--------------------------------------------------
//   1.0   |varkeykv|01/19/12| Initial check in to solve hostboot linker 
//------------------------------------------------------------------------------
#include "gcr_funcs.H"
using namespace fapi;
ReturnCode  GCR_read(const Target& chip_target, io_interface_t interface,GCR_sub_registers target_io_reg, uint32_t group_address,  uint32_t lane_address, ecmdDataBufferBase &databuf_16bit)
{
   ReturnCode rc;
   uint32_t rc_ecmd=0;
   ecmdDataBufferBase set_bits(16), clear_bits(16);
   rc_ecmd|=set_bits.flushTo0();
   rc_ecmd|=clear_bits.flushTo1();
   
   if(rc_ecmd){
      FAPI_ERR("Unexpected error in buffer manipulation\n");
      rc.setEcmdError(rc_ecmd);
   }
   else{
        rc=doGCRop(chip_target, interface, gcr_op_read, target_io_reg, group_address, lane_address, set_bits, clear_bits, databuf_16bit);
        if(!rc.ok())
        {
          FAPI_ERR("Unexpected error while performing GCR OP \n");
        }
   }

   return  rc;
}
//------------------------------------------------------------------------------------------------------------------------------------
// GCR SCOM WRITE  - main api for write - do not use doGCRop directly
//------------------------------------------------------------------------------------------------------------------------------------
ReturnCode  GCR_write(const Target& chip_target, io_interface_t interface, GCR_sub_registers target_io_reg, uint32_t group_address,  uint32_t lane_address,  ecmdDataBufferBase set_bits,  ecmdDataBufferBase clear_bits, int skipCheck,int bypass_rmw)
{
   ReturnCode rc;
   uint32_t rc_ecmd=0;
   ecmdDataBufferBase databuf_16bit(16);
   rc_ecmd|=databuf_16bit.flushTo0();
   skipCheck=1; //forcing this argument to one as this is redundant.
   if(rc_ecmd){
      FAPI_ERR("Unexpected error in buffer manipulation\n");
      rc.setEcmdError(rc_ecmd);
   }
   else{
        rc=doGCRop(chip_target, interface, gcr_op_write, target_io_reg, group_address, lane_address, set_bits, clear_bits, databuf_16bit, skipCheck,bypass_rmw);
        if(!rc.ok())
        {
          FAPI_ERR("Unexpected error while performing GCR OP \n");
        }
   }
   return rc;
}

// UPPER LAYER FUNCTIONS

//------------------------------------------------------------------------------------------------------------------------------------
// generate the 64 bit scom address for the GCR
//------------------------------------------------------------------------------------------------------------------------------------
uint64_t scom_address_64bit(uint32_t gcr_addr, uint64_t gcr_data) {
  uint32_t rc_ecmd=0;
  ecmdDataBufferBase reg_scom_address(64), temp(64);
  temp.flushTo0();
  temp.setDoubleWord(0,gcr_data);

  // 64 bit address
  rc_ecmd|= reg_scom_address.setWord(0,temp.getWord(0));
  rc_ecmd |= reg_scom_address.setWord(1,gcr_addr);
  rc_ecmd |= reg_scom_address.setBit(0);

  if(rc_ecmd)
  {
    FAPI_ERR("io_run_training: Unexpected failure in scom_address_64bit helper func");
  }
  return(reg_scom_address.getDoubleWord(0));
}


// use GCR_read and GCR_write for reg access - not this function!!!!
/*************************************************************************************************************************/
/* gcr2 is pgp mailbox format                                                                                            */
/* gcr2        0         0         64      # total length                                                                */
/* gcr2        wr        0         1       # gcr register read/write bit (read=1, write=0, opposite of gcr0)             */
/* gcr2        reg_addr  12        9       # gcr ring (register) address (ext_addr)                                      */
/* gcr2        rxtx      21        1       # =1 for a tx group                                                           */
/* gcr2        group     22        5       # does NOT include tx/rx as leading bit                                       */
/* gcr2        lane      27        5       # lane address                                                                */
/* gcr2        data      48        16      # data                                                                        */
/* gcr2        readvalid 39        1       # read data valid bit                                                         */
/*************************************************************************************************************************/

ReturnCode  doGCRop(const Target& chip_target, io_interface_t interface, gcr_op read_or_write, GCR_sub_registers target_io_reg, uint32_t group_address,  uint32_t lane_address,  ecmdDataBufferBase set_bits,  ecmdDataBufferBase clear_bits, ecmdDataBufferBase &databuf_16bit, int skipCheck,int bypass_rmw) {
    ReturnCode rc;
    uint32_t rc_ecmd=0;
    uint64_t  scom_address64=0;
    ecmdDataBufferBase getscom_data64(64), putscom_data64(64), local_data16(16);
    rc_ecmd |=getscom_data64.flushTo0();
    rc_ecmd |=putscom_data64.flushTo0();
    rc_ecmd |=local_data16.flushTo0();
    
    // Generate the  gcr2_register_data  putscom data
    /* gcr2        reg_addr  12        9       # gcr ring (register) address (ext_addr)                                      */
    // align the extended address to bit (12:20)
      rc_ecmd |= getscom_data64.insert( GCR_sub_reg_ext_addr[target_io_reg], 12, 9, 23 );
       FAPI_DBG("Register Extended address = %x\n",GCR_sub_reg_ext_addr[target_io_reg]);
  
    const char *temp;
    temp=GCR_sub_reg_names[target_io_reg];
    if(temp[0] == 'T' )
    {
      // This is a TX register/field need to set the TX bit
       rc_ecmd |= getscom_data64.setBit( 21 ); // does not include leading TX bit now since we are using only RX
    }
    /* gcr2        group     22        5       # does NOT include tx/rx as leading bit                                       */
    // align the group address to bit (22:26)
    rc_ecmd |= getscom_data64.insert( group_address, 22, 5, 27); // does not include leading TX bit now since we are using only RX
    
    /* gcr2        lane      27        5       # lane address                                                                */
    // align the lane address to bit (27:31)
    rc_ecmd |=  getscom_data64.insert( lane_address, 27, 5, 27 );
    if(rc_ecmd)
    {
        FAPI_ERR("IO gcr_funcs: DataBuffer operation error occurred\n");
        rc.setEcmdError(rc_ecmd);
    }
    else
    {
        FAPI_DBG("ei_reg_addr_GCR_scom[interface]=%x\n",ei_reg_addr_GCR_scom[interface]);
        scom_address64 =scom_address_64bit(ei_reg_addr_GCR_scom[interface], getscom_data64.getDoubleWord(0));
        if(!bypass_rmw){
           rc = fapiGetScom( chip_target, scom_address64, getscom_data64 );
        }
        else{
         getscom_data64.flushTo0();
        }
        if(!rc.ok())
        {
            FAPI_ERR("IO gcr_funcs:GETSCOM error occurred ********\n");
		             FAPI_ERR( "IO GCR FUNCS \tRead GCR %s, @ = %llX, Data = %08X%08X  Failed  group_address=%d\n",
                         GCR_sub_reg_names[target_io_reg], scom_address64, getscom_data64.getWord(0), getscom_data64.getWord(1),group_address);

        }
        else
        {
	    FAPI_DBG( "\tRead GCR2 %s:  GETSCOM 0x%llX %08X%08X \n",
                        GCR_sub_reg_names[target_io_reg], scom_address64, getscom_data64.getWord(0), getscom_data64.getWord(1) );
          rc_ecmd|=getscom_data64.extract( local_data16,   48, 16 ); // return data on read ops -- for 54/52 onwards
          
         if(rc_ecmd)
         {
            FAPI_ERR("IO gcr_funcs: DataBuffer operation error occurred\n");
            rc.setEcmdError(rc_ecmd);
         }
         else
         {
            // register write operation
            if (read_or_write == gcr_op_read) {
            databuf_16bit = local_data16;
            }
            else
            {  // write
                // write operation
                putscom_data64 = getscom_data64;
                
                // clear the desired bits first
                databuf_16bit = databuf_16bit & clear_bits;
                
                // now set desired bits
                databuf_16bit = databuf_16bit | set_bits;
                
                // data is now 64 bits and only last 16 bits are used  48:63 = 16bits  # data  
                rc_ecmd|=putscom_data64.insert( databuf_16bit, 48, 16); //-- for model 54/52 onwards
             
                if(rc_ecmd)
                {
                   FAPI_ERR("IO gcr_funcs: DataBuffer operation error occurred");
                   rc.setEcmdError(rc_ecmd);
                }
                else
                {
		    FAPI_DBG( "\tWrite GCR2 %s: PUTSCOM 0x%llX  0x%08X%08X",
                    GCR_sub_reg_names[target_io_reg], scom_address64, putscom_data64.getWord(0), putscom_data64.getWord(1) );
                   rc = fapiPutScom( chip_target, scom_address64, putscom_data64);
                   if(!rc.ok())
                   {
                   FAPI_ERR("IO gcr_funcs: PUTSCOM error occurred\n");
                   }
                   else
                   {
                       // check the write
                       if(!skipCheck){
                        rc = fapiGetScom( chip_target, scom_address64, getscom_data64 );
                       }
                       if(!rc.ok()){
                       FAPI_ERR("IO gcr_funcs: GETSCOM error occurred\n");
                       return(rc);
                       }
                       rc_ecmd=local_data16.insert(getscom_data64,0,16,48);  //-- for 54/52 onwards
                       if(rc_ecmd)
                       {
                           FAPI_ERR("IO gcr_funcs: DataBuffer operation error occurred\n");
                           rc.setEcmdError(rc_ecmd);
                       }
                       else{
                           if ( !skipCheck )
                           { //add skipCheck for tx_err_inj since self resetting -- djd 2/11/11
                               if ( local_data16 != databuf_16bit )
                               {
				        FAPI_ERR( "\t %s VALIDATE write failed: read=0x%04X  write=%04X\n",
				   GCR_sub_reg_names[target_io_reg], local_data16.getHalfWord(0), databuf_16bit.getHalfWord(0) );
                                   ecmdDataBufferBase &READ_BUF=local_data16;
                                   ecmdDataBufferBase &WRITE_BUF=databuf_16bit;
                                   FAPI_SET_HWP_ERROR(rc, IO_GCR_WRITE_MISMATCH_RC);
                               }
                           }
                           
                       }               
                   }
                   
                }
            }
         }
        }
    }
   
    return(rc);
}

