/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete/proc_read_seeprom.C $ */
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

// -*- mode: C++; c-file-style: "linux";  -*-
// $Id: proc_read_seeprom.C,v 1.9 2012/11/16 23:44:55 szhong Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/utils/proc_read_seeprom.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_read_seeprom.C
// *! DESCRIPTION : Read the value of seeprom given a starting address and read length 
// *!
// *! OWNER NAME  : Christina Kuhfal            Email: ckuhfal@us.ibm.com
// *! MODIFIED BY : William Zhong               Email: szhong@us.ibm.com
// *!
// *! Overview:
// *!   Set the address that is going to be read
// *!	Read from that address
// *!	Send the data that was read back to the user 
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "proc_read_seeprom.H"
#include <fapi.H>

//*******************************************************
//Experiments on s1_e8052 wafer model shows first read takes 29*200000 cycles
//other normal reads takes 19*200000 cycles.
//*******************************************************

#define TIMEOUT_LIMIT 40         //total time_out: TIMEOUT_LIMIT*LOOP_DELAY_CYCLE or TIMEOUT_LIMIT*LOOP_DELAY_TIME
#define LOOP_DELAY_CYCLE 200000
#define LOOP_DELAY_TIME  200000  //!!!this number should be rechecked!!!


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

extern "C"
{


//------------------------------------------------------------------------------
// function:
//      Set the address that is going to be read
//	Read from that address
//	Send the data that was read back to the user 
//
// parameters:  i_target  => chip target
//		i_start_addr => start address
//		i_length => length to read in bytes
//              o_data => The data that is read is sent back to the user
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
    


    

    fapi::ReturnCode check_status_register_errors(ecmdDataBufferBase is_ready)
    {
	fapi::ReturnCode rc;
	////////////////////////////////////////////////////////////////////
	//*****************Check if any errorbits are set*****************//
	do{
	    if(is_ready.isBitSet(0))
		{
		    FAPI_ERR("ERROR:PIB_BUS_ADDR_NVLD_ERR");
		    FAPI_SET_HWP_ERROR(rc,RC_PROC_READ_SEEPROM_PIB_BUS_ADDR_NVLD_ERR_BIT_SET);
		    break;
		}
	    if(is_ready.isBitSet(1))
		{
		    FAPI_ERR("ERROR: PIB_BUS_WRITE_NVLD_ERR");
		    FAPI_SET_HWP_ERROR(rc,RC_PROC_READ_SEEPROM_PIB_BUS_WRITE_NVLD_ERR_BIT_SET);
		    break;
		}
	    if(is_ready.isBitSet(2))
		{
		    FAPI_ERR("ERROR:PIB_BUS_READ_NVLD_ERR");
		    FAPI_SET_HWP_ERROR(rc,RC_PROC_READ_SEEPROM_PIB_BUS_READ_NVLD_ERR_BIT_SET);
		    break;
		}
	    if(is_ready.isBitSet(3))
		{
		    FAPI_ERR("ERROR:PIB_BUS_ADDR_PAR_ERR");
		    FAPI_SET_HWP_ERROR(rc,RC_PROC_READ_SEEPROM_PIB_BUS_ADDR_PAR_ERR_BIT_SET);
		    break;
		}
	    if(is_ready.isBitSet(4))
		{
		    FAPI_ERR("ERROR:PIB_BUS_PAR_ERR");
		    FAPI_SET_HWP_ERROR(rc,RC_PROC_READ_SEEPROM_PIB_BUS_PAR_ERR_BIT_SET);
		    break;
		}
	    if(is_ready.isBitSet(5))
		{
		    FAPI_ERR("ERROR:LOCAL_BUS_PAR_ERR");
		    FAPI_SET_HWP_ERROR(rc,RC_PROC_READ_SEEPROM_LOCAL_BUS_PAR_ERR_BIT_SET);
		    break;
		}
	    //38:40 
	    if(is_ready.isBitSet(45))
		{
		    FAPI_ERR("ERROR:PIB_INVALID_COMMAND");
		    FAPI_SET_HWP_ERROR(rc,RC_PROC_READ_SEEPROM_PIB_INVALID_COMMAND_BIT_SET);
		    break;
		}
	    if(is_ready.isBitSet(46))
		{
		    FAPI_ERR("ERROR:PIB_PARITY_ERR");
		    FAPI_SET_HWP_ERROR(rc,RC_PROC_READ_SEEPROM_PIB_PARITY_ERR_BIT_SET);
		    break;
		}
	    if(is_ready.isBitSet(47))
		{
		    FAPI_ERR("ERROR:I2C_BACK_END_OVERRUN_ERR");
		    FAPI_SET_HWP_ERROR(rc,RC_PROC_READ_SEEPROM_I2C_BACK_END_OVERRUN_ERR_BIT_SET);
		    break;
		}
	    if(is_ready.isBitSet(48))
		{
		    FAPI_ERR("ERROR:I2C_BACK_END_ACCESS_ERR");
		    FAPI_SET_HWP_ERROR(rc,RC_PROC_READ_SEEPROM_I2C_BACK_END_ACCESS_ERR_BIT_SET);
		    break;
		}
	    if(is_ready.isBitSet(49))
		{
		    FAPI_ERR("ERROR:I2C_ARBITRATION_LOST_ERR");
		    FAPI_SET_HWP_ERROR(rc,RC_PROC_READ_SEEPROM_I2C_ARBITRATION_LOST_ERR_BIT_SET);
		    break;
		}
	    if(is_ready.isBitSet(50))
		{
		    FAPI_ERR("ERROR:I2C_NACK_RECIEVED_ERR");
		    FAPI_SET_HWP_ERROR(rc,RC_PROC_READ_SEEPROM_I2C_NACK_RECIEVED_ERR_BIT_SET);
		    break;
		}
	    if(is_ready.isBitSet(53))
		{
		    FAPI_ERR("ERROR:I2C_STOP_ERR");
		    FAPI_SET_HWP_ERROR(rc,RC_PROC_READ_SEEPROM_I2C_STOP_ERR_BIT_SET);
		    break;
		}
	    //check if bits 54, 55 are errors.
	    if(is_ready.isBitSet(56))
		{
		    FAPI_ERR("ERROR:I2C_STOP_ERR");
		    FAPI_SET_HWP_ERROR(rc,RC_PROC_READ_SEEPROM_PARITY_ERROR_BIT_SET);
		    break;
		}
	    if(is_ready.isBitSet(57))
		{
		    FAPI_ERR("ERROR:CE_COUNTER_OVERFLOW_BIT_SET");
		    FAPI_SET_HWP_ERROR(rc,RC_PROC_READ_SEEPROM_CE_COUNTER_OVERFLOW_BIT_SET);
		    break;
		}

	    //38:40
	    uint16_t err32to47=is_ready.getHalfWord(2);
	    uint16_t e_38_40=(err32to47 & 0x0380)>>7;
	    if(e_38_40!=0)
		{
		    FAPI_ERR("ERROR:PIB_MASTER_RESP_INFO is not zero");
		    FAPI_SET_HWP_ERROR(rc,RC_PROC_READ_SEEPROM_PIB_MASTER_RESP_INFO_BITS_SET);
		    break; 
		}

	    uint16_t e_41_43=(err32to47 & 0x0070)>>4;;
	    if(e_41_43!=0)
		{
		    if(e_41_43==4)//0b100
			{
			    FAPI_ERR("ERROR:PIB_CONTROL_REG_DATA_LGT_ERR, pib control reg data length error");
			    FAPI_SET_HWP_ERROR(rc,RC_PROC_READ_SEEPROM_PIB_CONTROL_REG_DATA_LGT_ERR);
			    break;
			}
		    else if(e_41_43==5)//0b101
			{
			    FAPI_ERR("ERROR:PIB_CONTROL_REG_ADD LENGTH ERROR");
			    FAPI_SET_HWP_ERROR(rc,RC_PROC_READ_SEEPROM_PIB_CONTROL_REG_ADD_LGT_ERR);
			    break;
			}
		    else if(e_41_43==6)//0b110)
			{
			    FAPI_ERR("ERROR:PIB_CONTROL_REG_ADDR_BDY_ERR, address boundary error");
			    FAPI_SET_HWP_ERROR(rc,RC_PROC_READ_SEEPROM_PIB_CONTROL_REG_ADDR_BDY_ERR);
			    break;
			}
		    else if(e_41_43==7)//0b111)
			{
			    FAPI_ERR("ERROR:PIB_ECCADDR_REG_ERR");
			    FAPI_SET_HWP_ERROR(rc,RC_PROC_READ_SEEPROM_PIB_ECCADDR_REG_ERR);
			    break;
			}
		    else if(e_41_43==2)//0b010)
			{
			    FAPI_ERR("ERROR:EFF_PIBM_RESET, pib master reset");
			    FAPI_SET_HWP_ERROR(rc,RC_PROC_READ_SEEPROM_PIB_EFF_PIBM_RESET);
			    break;
			}
		    else if(e_41_43==1)//0b001)
			{
			    FAPI_ERR("ERROR:UCE_Q, uncorrectable ecc error");
			    FAPI_SET_HWP_ERROR(rc,RC_PROC_READ_SEEPROM_PIB_UEC_Q);
			    break;
			}
		    else //0b011, 3
			{
			    FAPI_ERR("ERROR:reset from pib slave");
			    FAPI_SET_HWP_ERROR(rc,RC_PROC_READ_SEEPROM_PIB_SLAVE_RESET);
			    break;
			}

		}
	    
	    //41:43 (100:data length error, 110:address boundary error,
	    //010 pibmaster reset,  001 uncorrectable ecc error. 
	}while(0);
	return rc;
	//*********************************************************************
	///////////////////////////////////////////////////////////////////////

    }




    fapi::ReturnCode proc_read_seeprom(const fapi::Target & i_target,
				       uint32_t & i_start_addr, uint32_t & i_length, bool & i_ecc_disable, uint64_t * return_data, bool & use_secondary)
    {
	fapi::ReturnCode rc;
	//----------------------------Buffers-----------------------------------------------
	//The buffer that set 000A0006 which we need to do before anything else 
	ecmdDataBufferBase beginning_buff = ecmdDataBufferBase (64);
	//The buffer that will tell whether or not the data is ready to be read
	ecmdDataBufferBase is_ready = ecmdDataBufferBase (64);
	//The buffer that will hold the data to be returned
	ecmdDataBufferBase data = ecmdDataBufferBase (64);
	uint64_t clearallbits = 0x0000000000000000LLU;
	data.setDoubleWord(0,clearallbits);
	//The buffer that contains the value of the first time we call the control register
	ecmdDataBufferBase control_reg_buff1 = ecmdDataBufferBase (64);
	//The buffer that contins the value of the second time we call the control register 
	ecmdDataBufferBase control_reg_buff2 = ecmdDataBufferBase (64);
	//The buffer that contains the value of continuing to get more than just 8 bytes of data
	ecmdDataBufferBase control_reg_buff3 = ecmdDataBufferBase (64); 
	//The device_id buffer
	ecmdDataBufferBase device_id_buff = ecmdDataBufferBase (64);
	//The port number buffer
	ecmdDataBufferBase port_buff = ecmdDataBufferBase (64);
	//The address buffer
	ecmdDataBufferBase address_buff = ecmdDataBufferBase (64); 
	//ECC Buffer
	ecmdDataBufferBase ecc_buff = ecmdDataBufferBase (64);
	ecmdDataBufferBase   vital_reg_buff=ecmdDataBufferBase(64);





	
	uint64_t ecc_value; 
	//uint64_t fix_offset=0;//read from logic address of 2000
	uint32_t rc_ecmd=0;
	do 
	{
	    //Putting the value of the 000A0006 into the buffer 
	    uint64_t beginning = 0x0003000100000000LLU; //bit_rate_devisor: 0x0003, wrap_mode bit31is 1
	    beginning_buff.setDoubleWord(0, beginning);

	    //Whether ecc is disabled(1) or not(0)
	    if(i_ecc_disable){
		ecc_value = 0x0000000000000000LLU;
		FAPI_DBG("ecc disabled\n");
	    }
	    else{
		ecc_value = 0x0000FFFF00001C78LLU; 
		FAPI_DBG("ecc enabled\n");
	    }
	    //Put the ecc value into the ecc buffer
	    ecc_buff.setDoubleWord(0, ecc_value); 

	    //Figure out how many times we will need to get data
	    int num_times = i_length / 8 ; 

	    //Put the value of the device_id into the device_id buffer
	    uint64_t device_id = 86; //0b1010110 
	    if(use_secondary)
		{
		    device_id=87; //secondary seeprom id, test this.
		}
	    
	    device_id = device_id << 49; 
	    device_id_buff.setDoubleWord(0, device_id);
 
	    //Put the value of the port number into the port buffer
	    uint64_t port = 0; // 0b00000;
	    port = port << 39;
	    port_buff.setDoubleWord(0, port);

	    //Put the value of the address into the address buffer
	    FAPI_DBG("i_start_addr: %08x\n",i_start_addr);
	    uint64_t start_addr = i_start_addr << 16;
	    address_buff.setDoubleWord(0, start_addr); 

	    //The base value of the first time that the control register is used 
	    uint64_t control_reg_data1 = 0xD801008000000000LLU;
	    //11011000<device ID>100<port number>010000000<register address> 
         
	    //Put the initial value of the control registers
	    control_reg_buff1.setDoubleWord (0, control_reg_data1);
	    //control_reg_buff2.setDoubleWord (0, control_reg_data2);
	
	    //Include the device id in the control registers
	    //control_reg_buff2.merge(device_id_buff);
	    control_reg_buff1.merge(device_id_buff);

	    //Include the port number in the control registers
	    control_reg_buff1.merge(port_buff);
	    //control_reg_buff2.merge(port_buff);
	
	    //Include the starting address in the control registers
	    control_reg_buff1.merge(address_buff);
	    //control_reg_buff2.merge(address_buff); 

	    //Set the ECC write or no ECC write
	    rc = fapiPutScom(i_target, 0x000C0004, ecc_buff);
	    if(rc)
	    {
		FAPI_ERR("Failed to perform fapiPutScom on ECC Address register 0x000C0004");
		break;
	    }
	    //This is the Instruction Sequence to I2CM for Data Write
	    //I got this from page 307 of the PervasiveWorkbook_P8.pdf
	    rc = fapiPutScom(i_target, I2CM_MODE_REGISTER_0_0x000A0006, beginning_buff);
	    if(rc)
	    {
		FAPI_ERR("Failed to perform fapiPutScom on MODE_REGISTER_0 0x000A0006");
		break;
	    }
	    //Write control registerclk
	    
            //Read Status Register
	    int i = 0;
	    rc_ecmd=0;
	    for(i = 0; i < num_times; i++)
		{
		    if(i==0)
			{
			    if(num_times==1)
				{
				    //printf("first time only\n");//add read conti if multiple read needed
				    rc = fapiPutScom(i_target, PORE_ECCB_CONTROL_REGISTER_0x000C0000, control_reg_buff1); 
				    if(rc)
					{
					    FAPI_ERR("Failed to perform fapiPutScom on PORE_ECCB_CONTROL_REGISTER 0x000C0000");
					    break;
					}
				}
			    else
				{
				    rc_ecmd|=control_reg_buff1.clearBit(3);//clear the withstop
				    rc_ecmd|=control_reg_buff1.setBit(2);//set read cont
				    
				    rc.setEcmdError(rc_ecmd);
				    if(!rc.ok())
					{
					    FAPI_ERR("proc_read_seeprom: Error 0x%x failed setting/clearing bits",rc_ecmd);
					    break;
					}
				    FAPI_DBG("control: %016llx\n",control_reg_buff1.getDoubleWord(0));
				    rc = fapiPutScom(i_target, PORE_ECCB_CONTROL_REGISTER_0x000C0000, control_reg_buff1); 
				    if(rc)
					{
					    FAPI_ERR("Failed to perform fapiPutScom on PORE_ECCB_CONTROL_REGISTER 0x000C0000");
					    break;
					}
				}
			    
			}
		    else if(i==num_times-1)//last read, wstart=0, wa=0, wrc=0,wstop=1, 0  for 23:25, 0 for 32:63
			{
			    rc_ecmd|=control_reg_buff1.clearBit(0);
			    rc_ecmd|=control_reg_buff1.clearBit(1);
			    rc_ecmd|=control_reg_buff1.clearBit(2);
			    rc_ecmd|=control_reg_buff1.setBit(3);
			    rc_ecmd|=control_reg_buff1.setAnd((uint32_t)0,23,3);//clearbit(,)
			    rc_ecmd|=control_reg_buff1.setAnd((uint32_t)0,32,32);
			    rc.setEcmdError(rc_ecmd);
			    if(!rc.ok())
				{
				    FAPI_ERR("proc_read_seeprom: Error 0x%x failed setting/clearing bits",rc_ecmd);
				    break;
				}
			    FAPI_DBG("control: %016llx\n",control_reg_buff1.getDoubleWord(0));
							    
			    rc = fapiPutScom(i_target, PORE_ECCB_CONTROL_REGISTER_0x000C0000, control_reg_buff1);
			    if(rc)
				{
				    FAPI_ERR("Failed to perform fapiPutScom on PORE_ECCB_CONTROL_REGISTER 0x000C0000");
				    break;
				}
			}
		    else
			{
			    rc_ecmd|=control_reg_buff1.clearBit(0);
			    rc_ecmd|=control_reg_buff1.clearBit(1);
			    rc_ecmd|=control_reg_buff1.setBit(2);
			    rc_ecmd|=control_reg_buff1.clearBit(3);
			    rc_ecmd|=control_reg_buff1.setAnd((uint32_t)0,23,3);
			    rc_ecmd|=control_reg_buff1.setAnd((uint32_t)0,32,32);
			    rc.setEcmdError(rc_ecmd);
			    if(!rc.ok())
				{
				    FAPI_ERR("proc_read_seeprom: Error 0x%x failed setting/clearing bits",rc_ecmd);
				    break;
				}
			    FAPI_DBG("control: %016llx\n",control_reg_buff1.getDoubleWord(0));

			    rc = fapiPutScom(i_target, PORE_ECCB_CONTROL_REGISTER_0x000C0000, control_reg_buff1); 
			    if(rc)
				{
				    FAPI_ERR("Failed to perform fapiPutScom on PORE_ECCB_CONTROL_REGISTER 0x000C0000");
				    break;
				}
				   
			}			    
		    //Wait until the value is ready to be collected 
		    bool is_not_complete = true; 
		    uint16_t counter=0;
		    while(is_not_complete)
			{
			    counter++;
			    //printf( "counter: %d\n",counter);
			    rc = fapiGetScom(i_target, PORE_ECCB_STATUS_REGISTER_READ_0x000C0002, is_ready);
			    if(rc)
				{
				    FAPI_ERR("Failed to perform fapiGetScom on PORE_ECCB_STATUS_REGISTER 0x000C0002");
				    break;
				}
			    rc=check_status_register_errors(is_ready);
			    if(rc) break;
			    if(!is_ready.isBitSet(44))
				{
				    is_not_complete = false;
				    if(is_ready.isBitClear(52))
					{
					    FAPI_ERR("ERROR:I2C_COMMAND_COMPLETE is not set after bit 44 is cleared");
					    FAPI_SET_HWP_ERROR(rc,RC_PROC_READ_SEEPROM_I2C_COMMAND_COMPLETE_NOT_SET);
					    break;  
					}
				}
			    rc=fapiDelay(LOOP_DELAY_TIME,LOOP_DELAY_CYCLE);
			    if (rc) break;

			    if(counter>TIMEOUT_LIMIT)
				{
				    FAPI_SET_HWP_ERROR(rc,RC_PROC_READ_SEEPROM_I2C_COMMAND_COMPLETE_TIME_OUT);
				    FAPI_ERR("ERROR: I2C_COMMAND_COMPLETE not set, TIME OUT");
				    break;
				}
			}
		    if(rc)
			{
			    FAPI_ERR("ECCB Status Register reported an error");
			    break;
			}
		    //Read Data Register
		    rc = fapiGetScom(i_target, PORE_ECCB_DATA_REGISTER_0x000C0003, data);
		    if(rc)
			{
			    FAPI_ERR("Failed to perform fapiGetScom on PORE_ECCB_DATA_REGISTER 0x000C0003");
			    break;
			}
		    uint64_t data_temp = data.getDoubleWord (0);
		    FAPI_INF ("Byte - 0x%4x, data: %016llx\n",i*8,data_temp);
		    *return_data = data_temp;
		    //Increment the array pointer that will get passed back
		    return_data++;
		}
	}while(0);
	return rc; 
	
    }
} // extern "C"
/* Local Variables: */
/* c-basic-offset: 4 */
/* End: */
