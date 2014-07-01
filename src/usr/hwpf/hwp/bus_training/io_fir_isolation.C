/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/io_fir_isolation.C $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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
// $Id: io_fir_isolation.C,v 1.14 2014/03/20 14:06:08 varkeykv Exp $
// *!***************************************************************************
// *! (C) Copyright International Business Machines Corp. 2012  , 2013
// *!           All Rights Reserved -- Property of IBM
// *!                   ***  ***
// *!***************************************************************************
// *! FILENAME             : io_fir_isolation.C
// *! TITLE                :
// *! DESCRIPTION          : To isolate the error causing the firs to flag
// *! CONTEXT              :
// *!
// *! OWNER  NAME          : Swaminathan, Janani         Email: jaswamin@in.ibm.com
// *! BACKUP NAME          : Varghese, Varkey            Email: varkey.kv@in.ibm.com
// *!
// *!***************************************************************************
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|Author: | Date:  | Comment:
// --------|--------|--------|--------------------------------------------------
//   1.9   |jaswamin|04/19/13| Fixes for firmware compile issues.
//   1.8   |jaswamin|03/22/13| Added comments
//   1.7   |jaswamin|03/18/13| Changed indentation
//   1.6   |jaswamin|03/13/13| Returncode logging
//   1.5   |jaswamin|03/12/13| Return in case of a gcr operation error.
//   1.4   |jaswamin|03/06/13| Removed commented out portion.
//   1.3   |jaswamin|03/04/13| Changes as per review comment.
//   1.2   |jaswamin|02/20/13| Changes as per review comment
//   1.1   |jaswamin|02/14/13| Initial check in .
//------------------------------------------------------------------------------

#include <fapi.H>
#include "io_fir_isolation.H"
#include "gcr_funcs.H"


extern "C" {


using namespace fapi;

 //! Function    : io_fir_too_many_bus_err_isolation
 //! Parameters  : i_target => FAPI target,
 //!               chip_interface => io_chip_interface viz., A, X, DMI, CEN
 //!               current_group  => current clock group under test in the interface
 //! Returns     : o_rc => FFDC data for too many bus error. This includes the target
 //!                                              details and the source of the error.
 //! Description : This function provides the target details including the clock group
 //!               which had this error. This is sent as FFDC data along with the training
 //!               register contents.
ReturnCode io_fir_too_many_bus_err_isolation(const fapi::Target &i_target,
                                             io_interface_t i_chip_interface,
                                             uint32_t i_current_group){

        ReturnCode o_rc;
        ecmdDataBufferBase    error_data(16);

        o_rc=GCR_read(i_target ,  i_chip_interface, rx_fir_training_pg,  i_current_group,0, error_data);
        if(o_rc)
                return o_rc;
        if(error_data.isBitSet(8,1)){
            ecmdDataBufferBase & BUS_ERROR_REG = error_data; //bit1 of the register represnts the spare deployed bit.
            const fapi::Target & ENDPOINT = i_target;
            FAPI_SET_HWP_ERROR(o_rc,IO_FIR_TOO_MANY_BUS_ERROR_RC);
			fapiLogError(o_rc,FAPI_ERRL_SEV_UNRECOVERABLE);
        }
        return(FAPI_RC_SUCCESS);
}

 //! Function    : io_fir_recal_error_isolation
 //! Parameters  : i_target => FAPI target,
 //!               chip_interface => io_chip_interface viz., A, X, DMI, CEN
 //!               current_group  => current clock group under test in the interface
 //! Returns     : o_rc => FFDC data for recal error. This includes the target details
 //!               and the source of the error.
 //! Description : This function collects the register contents of the training register
 //!               that would help root cause the error which could be due to
 //!               dynamic repair fail or dynamic recal fail. This is given
 //!               as FFDC data.
ReturnCode io_fir_recal_error_isolation(const fapi::Target &i_target,
                                        io_interface_t i_chip_interface,
                                        uint32_t i_current_group){

        ReturnCode o_rc;
        ecmdDataBufferBase    error_data(16);

        o_rc=GCR_read(i_target ,  i_chip_interface, rx_fir_training_pg,  i_current_group,0, error_data);
        if(o_rc)
                return o_rc;
        if(error_data.isBitSet(3,1) || error_data.isBitSet(6,1)){       //can be caused by dynamic repair or recal error (bits 3 and 6 respectively)
            ecmdDataBufferBase & RECAL_ERROR_REG = error_data ; //bit1 of the register represnts the spare deployed bit.
            const fapi::Target & ENDPOINT = i_target;
            FAPI_SET_HWP_ERROR(o_rc,IO_FIR_RECALIBRATION_ERROR_RC);
			fapiLogError(o_rc,FAPI_ERRL_SEV_RECOVERED);
        }
        return(FAPI_RC_SUCCESS); // bilicon: This needs to be changed to "return(o_rc)"
}

 //! Function    : io_fir_max_spares_exceeded_isolation
 //! Parameters  : i_target => FAPI target,
 //!               chip_interface => io_chip_interface viz., A, X, DMI, CEN
 //!               current_group  => current clock group under test in the interface
 //! Returns     : o_rc => FFDC data for maximum deployable spares exceeded error.
 //!               This includes the target details and the source of the error.
 //! Description : This function collects the register contents of the training register
 //!               that would help root cause the error as being from pre/during training,
 //!               post training or during recal that caused the spares to exceed.
 //!               This is provided as FFDC dump.
ReturnCode io_fir_max_spares_exceeded_isolation(const fapi::Target &i_target,
                                                io_interface_t i_chip_interface,
                                                uint32_t i_current_group){

        ReturnCode o_rc;
        ecmdDataBufferBase    error_data(16);

        o_rc=GCR_read(i_target ,  i_chip_interface, rx_fir_training_pg,  i_current_group,0, error_data);
        if(o_rc)
                return o_rc;
        if(error_data.isBitSet(2,1) || error_data.isBitSet(5,1)|| error_data.isBitSet(8,1)){    // can be caused by a static (pre training - bit 2) or dynamic (post training - bit 5) or recal(bit 8)
            ecmdDataBufferBase & SPARE_ERROR_REG = error_data; //bit2 /bit 5 /bit 8of the register represents the max spare exceeded bit.To determine what caused the max spares exceeded error
            const fapi::Target & ENDPOINT = i_target;
            FAPI_SET_HWP_ERROR(o_rc,IO_FIR_MAX_SPARES_EXCEEDED_FIR_RC);
			fapiLogError(o_rc,FAPI_ERRL_SEV_UNRECOVERABLE);
        }
        return(FAPI_RC_SUCCESS); // bilicon: This needs to be changed to "return(o_rc)"
}

 //! Function    : io_fir_spare_deployed_isolation
 //! Parameters  : i_target => FAPI target,
 //!               chip_interface => io_chip_interface viz., A, X, DMI, CEN
 //!               current_group  => current clock group under test in the interface
 //! Returns     : o_rc => FFDC data for spare deployed error. This includes the
 //!               target details and the source of the error.
 //! Description : This function collects the register contents of the training register
 //!               that would help root cause the error as being from pre/during training,
 //!               post training or during recal that caused the spares to be deployed.
 //!               This is provided as FFDC dump.
ReturnCode io_fir_spare_deployed_isolation(const fapi::Target &i_target,
                                           io_interface_t i_chip_interface,
                                           uint32_t i_current_group){

        ReturnCode o_rc;
        ecmdDataBufferBase    error_data(16);

        o_rc=GCR_read(i_target ,  i_chip_interface, rx_fir_training_pg,  i_current_group,0, error_data);
        if(o_rc)
                return o_rc;
        if(error_data.isBitSet(1,1) || error_data.isBitSet(4,1) || error_data.isBitSet(7,1)){ // can be caused by a spare deployment prior to training , post training or during recal
            ecmdDataBufferBase & SPARE_ERROR_REG = error_data; //bit1 /bit4 / bit 7 of the register represnts the spare deployed bit. To determine which type of error caused the spare to be deployed
            const fapi::Target & ENDPOINT = i_target;
            FAPI_SET_HWP_ERROR(o_rc,IO_FIR_SPARES_DEPLOYED_FIR_RC);
			fapiLogError(o_rc,FAPI_ERRL_SEV_RECOVERED);
        }
        return(FAPI_RC_SUCCESS);// bilicon: This needs to be changed to "return(o_rc)"
}

 //! Function    : io_fir_tx_parity_isolation
 //! Parameters  : i_target => FAPI target,
 //!               chip_interface => io_chip_interface viz., A, X, DMI, CEN
 //!               current_group  => current clock group under test in the interface
 //! Returns     : o_rc => FFDC data for the tx fir parity error. This includes
 //!               the target details, the parity error that caused this bit to be set
 //!               and the lane id if it is a lane level error.
 //! Description : This function collects the register contents that would help
 //!               determine the source of the parity error and provides it as a FFDC data dump.

ReturnCode io_fir_tx_parity_isolation(const fapi::Target &i_target,
                                      io_interface_t i_chip_interface,
                                      uint32_t i_current_group){

        ReturnCode o_rc;
        ecmdDataBufferBase    error_data(16);
        uint32_t loop_val=0;
        uint32_t lane,group;

        if(i_chip_interface==CP_FABRIC_X0){
                lane=77;
        }
        else if(i_chip_interface==CP_FABRIC_A0){
                lane=23;
        }
        else if(i_chip_interface==CP_IOMC0_P0){
                lane=17;
        }
        else{
                lane=24;
        }

        for(loop_val=0;loop_val<lane;loop_val++){

                if(i_chip_interface==CP_FABRIC_X0){
                        group=loop_val%20;
                }
                else{
                        group=i_current_group;
                }

                o_rc=GCR_read(i_target ,  i_chip_interface, tx_fir_pl,  group,loop_val, error_data);
                if(o_rc){
                    FAPI_ERR("io_fir_isolation: Error reading rx fir per lane register\n");
                    return(o_rc);
                }
                //bit 0 for rx_fir_pl in case of X and bit 0 and 1 for A and DMI
                if(error_data.isBitSet(0,1)){

                    // find the current lane and group to send information

                    uint32_t & LANE_ID = loop_val;
                    ecmdDataBufferBase & TX_ERROR_REG = error_data;
                    const fapi::Target & ENDPOINT = i_target;
                    FAPI_DBG("io_fir_rx_parity_isolation:A per lane register or state machine error has occured. Lane is %d\n",loop_val);
                    FAPI_SET_HWP_ERROR(o_rc,IO_FIR_LANE_TX_PARITY_ERROR_RC);
					fapiLogError(o_rc,FAPI_ERRL_SEV_RECOVERED);
                    break;
                }
        }


        o_rc=GCR_read(i_target ,i_chip_interface, tx_fir_pg,  i_current_group,0, error_data);
        if(o_rc)
                return o_rc;
        for(loop_val=0;loop_val<16;loop_val++){

                if(error_data.isBitSet(loop_val,1)){

                    ecmdDataBufferBase & TX_ERROR_REG = error_data;
                    const fapi::Target & ENDPOINT = i_target;
                    FAPI_SET_HWP_ERROR(o_rc,IO_FIR_GROUP_TX_PARITY_ERROR_RC);
					fapiLogError(o_rc,FAPI_ERRL_SEV_RECOVERED);
                    break;
                }
        }

        return(FAPI_RC_SUCCESS);

}

 //! Function    : io_fir_rx_parity_isolation
 //! Parameters  : i_target => FAPI target,
 //!               chip_interface => io_chip_interface viz., A, X, DMI, CEN
 //!               current_group  => current clock group under test in the interface
 //! Returns     : o_rc => FFDC data for the rx fir parity error. This includes
 //!               the target details, the parity error that caused this bit to be set
 //!               and the lane id if it is a lane level error.
 //! Description : This function collects the register contents that would help determine
 //!               the source of the parity error and provides it as a FFDC data dump.
ReturnCode io_fir_rx_parity_isolation(const fapi::Target &i_target,
                                      io_interface_t i_chip_interface,
                                      uint32_t i_current_group){


        ReturnCode o_rc;
        ecmdDataBufferBase    error_data(16);
        uint32_t loop_val=0;
        uint32_t lane,group;

        //in case its bit 0 it is the rx_parity error. To find which bit is set read the registers that contribute to it. This is a per lane register. Hence we need to loop through each
        //lane to determine which is erroring out.
        if(i_chip_interface==CP_FABRIC_X0){
                lane=77;
        }
        else if(i_chip_interface==CP_FABRIC_A0){
                lane=23;
        }
        else if(i_chip_interface==CP_IOMC0_P0){
                lane=24;
        }
        else{
                lane=17;
        }

        for(loop_val=0;loop_val<lane;loop_val++){

                if(i_chip_interface==CP_FABRIC_X0){
                        group=loop_val%20;
                }
                else{
                        group=i_current_group;
                }

                o_rc=GCR_read(i_target ,  i_chip_interface, rx_fir_pl,  group,loop_val, error_data);

                if(o_rc){
                    FAPI_DBG("io_fir_isolation: Error reading rx fir per lane register\n");
                    return(o_rc);
                }
                //bit 0 for rx_fir_pl in case of X and bit 0 and 1 for A and DMI
                if(error_data.isBitSet(0,1) || error_data.isBitSet(1,1)){


                    // find the current lane and group to send information
                    uint32_t & LANE_ID = loop_val;
                    ecmdDataBufferBase & RX_ERROR_REG = error_data;
                    const fapi::Target & ENDPOINT = i_target;
                    FAPI_DBG("io_fir_rx_parity_isolation:A per lane register or state machine error has occured. Lane is %d\n",loop_val);
                    FAPI_SET_HWP_ERROR(o_rc,IO_FIR_LANE_RX_PARITY_ERROR_RC);
					fapiLogError(o_rc,FAPI_ERRL_SEV_RECOVERED);
                    break;
                }
        }

        //for fir1_reg and fir2_reg it is group wise hence do not need lane information

        o_rc=GCR_read(i_target ,i_chip_interface, rx_fir1_pg,  i_current_group,0, error_data);
        if(o_rc)
                return o_rc;
        for(loop_val=0;loop_val<16;loop_val++){

                if(error_data.isBitSet(loop_val,1)){
                    ecmdDataBufferBase & RX_ERROR_REG = error_data;
                    const fapi::Target & ENDPOINT = i_target;
                    FAPI_DBG("io_fir_isolation: %s\n",fir1_reg[loop_val]);
                    FAPI_SET_HWP_ERROR(o_rc,IO_FIR_GROUP_RX_PARITY_ERROR_RC);
					fapiLogError(o_rc,FAPI_ERRL_SEV_RECOVERED);
                    break;
                }
        }


        o_rc=GCR_read(i_target ,  i_chip_interface, rx_fir2_pg,  i_current_group,0, error_data);
        if(o_rc)
                return o_rc;
        for(loop_val=0;loop_val<16;loop_val++){

                if(error_data.isBitSet(loop_val,1)){
                    ecmdDataBufferBase & RX_ERROR_REG = error_data;
                    const fapi::Target & ENDPOINT = i_target;
                    FAPI_DBG("io_fir_isolation: %s\n",fir2_reg[loop_val]);
                    FAPI_SET_HWP_ERROR(o_rc,IO_FIR_GROUP_RX_PARITY_ERROR_RC);
					fapiLogError(o_rc,FAPI_ERRL_SEV_RECOVERED);
                    break;
                }
        }


        o_rc=GCR_read(i_target,i_chip_interface,rx_fir_pb,i_current_group,0,error_data);
        if(o_rc)
                return o_rc;
        for(loop_val=0;loop_val<16;loop_val++){

                if(error_data.isBitSet(loop_val,1)){
                    ecmdDataBufferBase & RX_ERROR_REG = error_data;
                    const fapi::Target & ENDPOINT = i_target;
                    FAPI_SET_HWP_ERROR(o_rc,IO_FIR_BUS_RX_PARITY_ERROR_RC);
					fapiLogError(o_rc,FAPI_ERRL_SEV_RECOVERED);
                    break;
                }
        }
        return(FAPI_RC_SUCCESS);
}

 //! Function    : io_error_isolation
 //! Parameters  : i_target => FAPI target,
 //!               chip_interface => io_chip_interface viz., A, X, DMI, CEN
 //!               current_group  => current clock group under test in the interface
 //!               fir_data       => data in the 64 bit flat scom fir register
 //! Returns     : o_rc => FFDC data for the FIR error if any (determined using the bit
 //!               set in the 64 bit fir register)
 //! Description : This function determines the type of error based on the fir bit that
 //!               is set and calls the appropriate isolation function for that error.
ReturnCode io_error_isolation(const fapi::Target &i_target,
                              io_interface_t i_chip_interface,
                              uint32_t i_current_group,
                              ecmdDataBufferBase &i_fir_data){

        ReturnCode o_rc;
        //ecmdDataBufferBase    error_data(16),id_data(16);


        //need to determine what error it represents.

        //if it is a rx_parity error
        if(i_fir_data.isBitSet(RX_PARITY,1)){
                o_rc=io_fir_rx_parity_isolation(i_target,i_chip_interface,i_current_group);
				if(o_rc)
                        return(o_rc);
        }

        //check for tx_parity error
        if(i_fir_data.isBitSet(TX_PARITY,1)){

                o_rc=io_fir_tx_parity_isolation(i_target,i_chip_interface,i_current_group);
				if(o_rc)
                        return(o_rc);
        }

        //GCR hang error
        if(i_fir_data.isBitSet(GCR_HANG_ERROR,1)){
            //check whether the gcr hang error bit is set


                const fapi::Target & ENDPOINT = i_target;
                FAPI_SET_HWP_ERROR(o_rc,IO_FIR_GCR_HANG_ERROR_RC);
                fapiLogError(o_rc,FAPI_ERRL_SEV_UNRECOVERABLE); //since the logging of error needs to happen here for this error.


        }

        //spare deploy?
        if(i_fir_data.isBitSet(BUS0_SPARE_DEPLOYED,1) ||
           i_fir_data.isBitSet(BUS1_SPARE_DEPLOYED,1) ||
           i_fir_data.isBitSet(BUS2_SPARE_DEPLOYED,1) ||
           i_fir_data.isBitSet(BUS3_SPARE_DEPLOYED,1) ||
           i_fir_data.isBitSet(BUS4_SPARE_DEPLOYED,1) ){

           o_rc=io_fir_spare_deployed_isolation(i_target,i_chip_interface,i_current_group);
		   if(o_rc)
                        return(o_rc);


        }

        //maximum spares deployed and exceeded?
        if(i_fir_data.isBitSet(BUS0_MAX_SPARES_EXCEEDED,1) ||
           i_fir_data.isBitSet(BUS1_MAX_SPARES_EXCEEDED,1) ||
           i_fir_data.isBitSet(BUS2_MAX_SPARES_EXCEEDED,1) ||
           i_fir_data.isBitSet(BUS3_MAX_SPARES_EXCEEDED,1) ||
           i_fir_data.isBitSet(BUS4_MAX_SPARES_EXCEEDED,1)){

           o_rc=io_fir_max_spares_exceeded_isolation(i_target,i_chip_interface,i_current_group);
           if(o_rc)
                return(o_rc);

        }

        //recalibration error
        if(i_fir_data.isBitSet(BUS0_RECALIBRATION_ERROR,1) ||
           i_fir_data.isBitSet(BUS1_RECALIBRATION_ERROR,1) ||
           i_fir_data.isBitSet(BUS2_RECALIBRATION_ERROR,1) ||
           i_fir_data.isBitSet(BUS3_RECALIBRATION_ERROR,1) ||
           i_fir_data.isBitSet(BUS4_RECALIBRATION_ERROR,1)){


           o_rc=io_fir_recal_error_isolation(i_target,i_chip_interface,i_current_group);
		   if(o_rc)
				return(o_rc);

        }

       //too many bus errors
        if(i_fir_data.isBitSet(BUS0_TOO_MANY_BUS_ERRORS,1) ||
           i_fir_data.isBitSet(BUS1_TOO_MANY_BUS_ERRORS,1) ||
           i_fir_data.isBitSet(BUS2_TOO_MANY_BUS_ERRORS,1) ||
           i_fir_data.isBitSet(BUS3_TOO_MANY_BUS_ERRORS,1) ||
           i_fir_data.isBitSet(BUS4_TOO_MANY_BUS_ERRORS,1)){

           o_rc=io_fir_too_many_bus_err_isolation(i_target,i_chip_interface,i_current_group);
		   if(o_rc)
				return(o_rc);

        }

        return(FAPI_RC_SUCCESS); // Currently this does not cause any harm as you are returning all the errors in the middle of the function, but it is good to change this to  "return(o_r)".
}

ReturnCode io_fir_isolation(const fapi::Target &i_target){

    ReturnCode o_rc;
    uint32_t rc_ecmd=0;
    fir_io_interface_t interface;
    io_interface_t gcr_interface; // requires different base address for gcr scoms
    uint32_t group;
    ecmdDataBufferBase    fir_data(64);
    rc_ecmd|=fir_data.flushTo0();
    if(rc_ecmd)
    {
        o_rc.setEcmdError(rc_ecmd);
        return(o_rc);
    }

    //on dmi
    if( (i_target.getType() == fapi::TARGET_TYPE_MCS_CHIPLET )){
          FAPI_DBG("This is a Processor DMI bus using base DMI scom address");
          interface=FIR_CP_IOMC0_P0; // base scom for MC bus
          gcr_interface=CP_IOMC0_P0;
          o_rc=read_fir_reg(i_target,interface,fir_data);
          group=3;
          if(o_rc)
                        return(o_rc);
          o_rc=io_error_isolation(i_target,gcr_interface,group,fir_data);

     }
     //on cen side
     else if((i_target.getType() ==  fapi::TARGET_TYPE_MEMBUF_CHIP)){
            FAPI_DBG("This is a Centaur DMI bus using base DMI scom address");
            interface=FIR_CEN_DMI;
            gcr_interface=CEN_DMI;
            o_rc=read_fir_reg(i_target,interface,fir_data);
            group=0;
            if(o_rc)
                        return(o_rc);
            o_rc=io_error_isolation(i_target,gcr_interface,group,fir_data);

     }
     // on x bus
     else if((i_target.getType() == fapi::TARGET_TYPE_XBUS_ENDPOINT)){
            FAPI_DBG("This is a X Bus invocation");
            interface=FIR_CP_FABRIC_X0;
            gcr_interface=CP_FABRIC_X0;
            o_rc=read_fir_reg(i_target,interface,fir_data);
            group=0;
            if(o_rc)
                        return(o_rc);
            o_rc=io_error_isolation(i_target,gcr_interface,group,fir_data);

     }
     //on a bus
     else if((i_target.getType() == fapi::TARGET_TYPE_ABUS_ENDPOINT)){
            FAPI_DBG("This is an A Bus invocation");
            interface=FIR_CP_FABRIC_A0;
            gcr_interface=CP_FABRIC_A0;
            o_rc=read_fir_reg(i_target,interface,fir_data);
            group=0;
            if(o_rc)
                        return(o_rc);
            o_rc=io_error_isolation(i_target,gcr_interface,group,fir_data);

     }
     else{
        FAPI_ERR("Invalid io_fir HWP invocation . Target doesnt belong to DMI/X/A instances");
        const fapi::Target & ENDPOINT = i_target;
        FAPI_SET_HWP_ERROR(o_rc, IO_FIR_INVALID_INVOCATION_RC);
     }

     return(o_rc);


}


}
