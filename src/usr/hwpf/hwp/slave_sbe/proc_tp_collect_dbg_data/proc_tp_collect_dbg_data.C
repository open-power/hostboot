/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_tp_collect_dbg_data/proc_tp_collect_dbg_data.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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
// $Id: proc_tp_collect_dbg_data.C,v 1.7 2014/10/03 20:25:36 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_tp_collect_dbg_data.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
//------------------------------------------------------------------------------
// *! TITLE       : proc_tp_collect_dbg_data.C
// *! DESCRIPTION : Procedure to collect TP debug data
// *!
// *! OWNER NAME : Benedikt Geukes        Email: bgeukes@de.ibm.com
// *!
// *! ADDITIONAL COMMENTS :
// *!
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <proc_tp_collect_dbg_data.H>
#include <utility>
//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

const uint32_t PROC_TP_COLLECT_DBG_DATA_FSI_SHIFT_CTRL 	= 0x00000043;
const uint32_t PERV_VITL_CHAIN_RING_ADDRESS = 0x0103800C;
const uint32_t TP_VITL_SPY_MAX_SPY_RANGES = 24;


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

extern "C" {

// HWP entry point, comments in header
fapi::ReturnCode proc_tp_collect_dbg_data(const fapi::Target & i_target,
                                          fapi::ReturnCode & o_rc)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;

	ecmdDataBufferBase ring_data;
    ecmdDataBufferBase spy_data;
    uint32_t ring_length;
    uint32_t spy_length;
    uint32_t spy_offsets[TP_VITL_SPY_MAX_SPY_RANGES];
	ecmdDataBufferBase fsi_data(32);
	ecmdDataBufferBase scom_data(64);

    // mark HWP entry
    FAPI_INF("proc_tp_collect_dbg_data: Start");

    do
    {
		// Setting Prevent AutoStart Bit to avoid scan chain corruption
        rc = fapiGetCfamRegister(i_target, CFAM_FSI_SBE_VITAL_0x0000281C, fsi_data);
        if (rc)
        {
            FAPI_ERR("proc_tp_collect_dbg_data: fapiGetCfamRegister error (CFAM_FSI_SBE_VITAL_0x0000281c)");
            break;
        }
        
        rc_ecmd |= fsi_data.setBit(1);
        rc_ecmd |= fsi_data.setBit(3);
        if (rc_ecmd)
        {
            FAPI_ERR("proc_tp_collect_dbg_data: Error 0x%x setting up FSI SBE Vital Register",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        rc = fapiPutCfamRegister(i_target, CFAM_FSI_SBE_VITAL_0x0000281C, fsi_data);
        if (rc)
        {
            FAPI_ERR("proc_tp_collect_dbg_data: fapiPutCfamRegister error (CFAM_FSI_SBE_VITAL_0x0000281C)");
            break;
        }
		
		
        // Setting FSI Shift Speed
        rc = fapiGetCfamRegister(i_target, CFAM_FSI_SHIFT_CTRL_0x00000C10, fsi_data);
        if (rc)
        {
        	FAPI_ERR("proc_tp_collect_dbg_data: fapiGetCfamRegister error (CFAM_FSI_SHIFT_CTRL_0x00000C10)");
            break;
        }
        
        rc_ecmd |= fsi_data.setWord(0,PROC_TP_COLLECT_DBG_DATA_FSI_SHIFT_CTRL);
        if (rc_ecmd)
        {
            FAPI_ERR("proc_tp_collect_dbg_data: Error 0x%x setting up FSI SHIFT CTRL register data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        rc = fapiPutCfamRegister(i_target, CFAM_FSI_SHIFT_CTRL_0x00000C10, fsi_data);
        if (rc)
        {
            FAPI_ERR("proc_tp_collect_dbg_data: fapiPutCfamRegister error (CFAM_FSI_SHIFT_CTRL_0x00000C10)");
            break;
        }
        
        // Changing Fences for Vital scan
        rc = fapiGetCfamRegister(i_target, CFAM_FSI_GP3_0x00002812, fsi_data);
        if (rc)
        {
            FAPI_ERR("proc_tp_collect_dbg_data: fapiGetCfamRegister error (CFAM_FSI_GP3_0x00002812)");
            break;
        }
        
        rc_ecmd |= fsi_data.clearBit(23);
        rc_ecmd |= fsi_data.setBit(24);
        rc_ecmd |= fsi_data.setBit(25);
        rc_ecmd |= fsi_data.setBit(26);
        rc_ecmd |= fsi_data.clearBit(27);
        if (rc_ecmd)
        {
            FAPI_ERR("proc_tp_collect_dbg_data: Error 0x%x setting up FSI GP3 data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        
        rc = fapiPutCfamRegister(i_target, CFAM_FSI_GP3_0x00002812, fsi_data);
        if (rc)
        {
            FAPI_ERR("proc_tp_collect_dbg_data: fapiPutCfamRegister error (CFAM_FSI_GP3_0x00002812)");
            break;
        }
        
        rc = fapiGetCfamRegister(i_target, CFAM_FSI_GP3_MIRROR_0x0000281B, fsi_data);
        if (rc)
        {
            FAPI_ERR("proc_tp_collect_dbg_data: fapiGetCfamRegister error (CFAM_FSI_GP3_MIRROR_0x0000281B)");
            break;
        }
        
        rc_ecmd |= fsi_data.setBit(16);
        if (rc_ecmd)
        {
            FAPI_ERR("proc_tp_collect_dbg_data: Error 0x%x setting up FSI GP3 MIRROR data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        
        rc = fapiPutCfamRegister(i_target, CFAM_FSI_GP3_MIRROR_0x0000281B, fsi_data);
        if (rc)
        {
            FAPI_ERR("proc_tp_collect_dbg_data: fapiPutCfamRegister error (CFAM_FSI_GP3_MIRROR_0x0000281B)");
            break;
        }
        
        rc = fapiGetCfamRegister(i_target, CFAM_FSI_GP3_MIRROR_0x0000281B, fsi_data);
        if (rc)
        {
            FAPI_ERR("proc_tp_collect_dbg_data: fapiGetCfamRegister error (CFAM_FSI_GP3_MIRROR_0x0000281B)");
            break;
        }
        
        rc_ecmd |= fsi_data.setBit(26);
        if (rc_ecmd)
        {
            FAPI_ERR("proc_tp_collect_dbg_data: Error 0x%x setting up FSI GP3 MIRROR data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        
        rc = fapiPutCfamRegister(i_target, CFAM_FSI_GP3_MIRROR_0x0000281B, fsi_data);
        if (rc)
        {
            FAPI_ERR("proc_tp_collect_dbg_data: fapiPutCfamRegister error (CFAM_FSI_GP3_MIRROR_0x0000281B)");
            break;
        }

        // obtain ring/spy attribute data
        rc = FAPI_ATTR_GET(ATTR_PROC_PERV_VITL_LENGTH, &i_target, ring_length);
        if (rc)
        {
            FAPI_ERR("proc_tp_collect_dbg_data: Error from FAPI_ATTR_GET (ATTR_PROC_PERV_VITL_LENGTH)");
            break;
        }

        rc = FAPI_ATTR_GET(ATTR_PROC_TP_VITL_SPY_LENGTH, &i_target, spy_length);
        if (rc)
        {
            FAPI_ERR("proc_tp_collect_dbg_data: Error from FAPI_ATTR_GET (ATTR_PROC_TP_VITL_SPY_LENGTH)");
            break;
        }

        rc = FAPI_ATTR_GET(ATTR_PROC_TP_VITL_SPY_OFFSETS, &i_target, spy_offsets);
        if (rc)
        {
            FAPI_ERR("proc_tp_collect_dbg_data: Error from FAPI_ATTR_GET (ATTR_PROC_TP_VITL_SPY_OFFSETS)");
            break;
        }

        rc_ecmd |= ring_data.setBitLength(ring_length);
        rc_ecmd |= spy_data.setBitLength(spy_length);
        if (rc_ecmd)
        {
            FAPI_ERR("proc_tp_collect_dbg_data: Error 0x%x sizing FFDC data buffers",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        
        // collect data from ring
        rc = fapiGetRing(i_target, PERV_VITL_CHAIN_RING_ADDRESS, ring_data);
        if (rc)
        {
            FAPI_ERR("proc_tp_collect_dbg_data: Error from fapiGetRing (PERV_VITL_CHAIN)");
            break;
        }

        // extract spy data from ring image
        uint32_t spy_offset_curr = 0;
        for (uint32_t spy_offset_index = 0;
             spy_offset_index < TP_VITL_SPY_MAX_SPY_RANGES;
             spy_offset_index++)
        {
            if (spy_offsets[spy_offset_index] == 0xFFFFFFFF)
            {
                break;
            }

            uint32_t first = ((spy_offsets[spy_offset_index] >> 16) & 0xFFFF);
            uint32_t second = (spy_offsets[spy_offset_index] & 0xFFFF);

            uint32_t chunk_size = (second - first + 1);
            rc_ecmd |= spy_data.insert(ring_data,
                                       spy_offset_curr,
                                       chunk_size,
                                       first);
            spy_offset_curr += chunk_size;
        }

        if (rc_ecmd)
        {
            FAPI_ERR("proc_tp_collect_dbg_data: Error 0x%x forming FFDC spy data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        ecmdDataBufferBase & VITL_DATA = spy_data;
        FAPI_ADD_INFO_TO_HWP_ERROR(o_rc, RC_TP_COLLECT_DBG_DATA);

    } while(0);

    // mark HWP exit
    FAPI_INF("proc_tp_collect_dbg_data: End");
    return rc;
}


} // extern "C"
