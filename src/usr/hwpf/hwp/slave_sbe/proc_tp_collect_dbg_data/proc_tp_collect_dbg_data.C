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
// $Id: proc_tp_collect_dbg_data.C,v 1.6 2014/08/04 16:00:49 thi Exp $
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

// Murano DD1.x
const uint32_t PERV_VITL_CHAIN_LENGTH_MDD1 = 2310;
const uint32_t TP_VITL_SPY_LENGTH_MDD1 = 576;
const std::pair<uint32_t,uint32_t> TP_VITL_SPY_OFFSETS_MDD1[] =
{
    std::make_pair(1197, 1260),
    std::make_pair(1342, 1392),
    std::make_pair(1401, 1403),
    std::make_pair(1641, 1641),
    std::make_pair(1644, 1665),
    std::make_pair(1667, 1679),
    std::make_pair(1688, 1943),
    std::make_pair(1963, 2005),
    std::make_pair(1503, 1520),
    std::make_pair( 849,  889),
    std::make_pair( 744,  807)
};

// Murano DD2.x
const uint32_t PERV_VITL_CHAIN_LENGTH_MDD2 = 2288;
const uint32_t TP_VITL_SPY_LENGTH_MDD2 = 590;
const std::pair<uint32_t,uint32_t> TP_VITL_SPY_OFFSETS_MDD2[] =
{
    std::make_pair(1176, 1239),
    std::make_pair(1321, 1344),
    std::make_pair(1365, 1371),
    std::make_pair(1430, 1456),
    std::make_pair(1465, 1467),
    std::make_pair(1479, 1479),
    std::make_pair(1482, 1503),
    std::make_pair(1505, 1524),
    std::make_pair(1533, 1788),
    std::make_pair(1808, 1850),
    std::make_pair(1893, 1910),
    std::make_pair( 849,  889),
    std::make_pair( 744,  807)
};

// Venice / Naples DD1.x
const uint32_t PERV_VITL_CHAIN_LENGTH_VN = 2773;
const uint32_t TP_VITL_SPY_LENGTH_VN = 590;
const std::pair<uint32_t,uint32_t> TP_VITL_SPY_OFFSETS_VN[] =
{
    std::make_pair( 209,  272),
    std::make_pair( 354,  377),
    std::make_pair( 398,  404),
    std::make_pair( 463,  489),
    std::make_pair( 498,  500),
    std::make_pair( 512,  512),
    std::make_pair( 515,  536),
    std::make_pair( 538,  557),
    std::make_pair( 566,  821),
    std::make_pair( 841,  883),
    std::make_pair( 926,  943),
    std::make_pair(2608, 2648),
    std::make_pair(2503, 2566)
};


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

    uint8_t chip_type;
    uint8_t dd_level;
	ecmdDataBufferBase ring_data;
    ecmdDataBufferBase spy_data;
    std::vector<std::pair<uint32_t, uint32_t> > spy_offsets;
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

        // obtain chip type/EC
        rc = FAPI_ATTR_GET_PRIVILEGED(ATTR_NAME, &i_target, chip_type);
        if (rc)
        {
            FAPI_ERR("proc_tp_collect_dbg_data: Error from FAPI_ATTR_GET_PRIVILEGED (ATTR_NAME)");
            break;
        }

        rc = FAPI_ATTR_GET_PRIVILEGED(ATTR_EC, &i_target, dd_level);
        if (rc)
        {
            FAPI_ERR("proc_tp_collect_dbg_data: Error from FAPI_ATTR_GET_PRIVILEGED (ATTR_EC)");
            break;
        }
        // configure ring/spy data buffers & spy extraction offsets based on CT/EC
        if ((chip_type == fapi::ENUM_ATTR_NAME_MURANO) && (dd_level < 0x20))
        {
            rc_ecmd |= ring_data.setBitLength(PERV_VITL_CHAIN_LENGTH_MDD1);
            rc_ecmd |= spy_data.setBitLength(TP_VITL_SPY_LENGTH_MDD1);
            spy_offsets.assign(TP_VITL_SPY_OFFSETS_MDD1, TP_VITL_SPY_OFFSETS_MDD1 + (sizeof(TP_VITL_SPY_OFFSETS_MDD1) / sizeof(TP_VITL_SPY_OFFSETS_MDD1[0])));
        }
        else if ((chip_type == fapi::ENUM_ATTR_NAME_MURANO) && (dd_level >= 0x20))
        {
            rc_ecmd |= ring_data.setBitLength(PERV_VITL_CHAIN_LENGTH_MDD2);
            rc_ecmd |= spy_data.setBitLength(TP_VITL_SPY_LENGTH_MDD2);
            spy_offsets.assign(TP_VITL_SPY_OFFSETS_MDD2, TP_VITL_SPY_OFFSETS_MDD2 + (sizeof(TP_VITL_SPY_OFFSETS_MDD2) / sizeof(TP_VITL_SPY_OFFSETS_MDD2[0])));
        }
        else if ((chip_type == fapi::ENUM_ATTR_NAME_VENICE) ||
                 (chip_type == fapi::ENUM_ATTR_NAME_NAPLES))
        {
            rc_ecmd |= ring_data.setBitLength(PERV_VITL_CHAIN_LENGTH_VN);
            rc_ecmd |= spy_data.setBitLength(TP_VITL_SPY_LENGTH_VN);
            spy_offsets.assign(TP_VITL_SPY_OFFSETS_VN, TP_VITL_SPY_OFFSETS_VN + (sizeof(TP_VITL_SPY_OFFSETS_VN) / sizeof(TP_VITL_SPY_OFFSETS_VN[0])));
        }
        else
        {
            FAPI_ERR("proc_tp_collect_dbg_data: Unsupported CT/EC combination!");
            const uint8_t CT = chip_type;
            const uint8_t EC = dd_level;
            FAPI_SET_HWP_ERROR(rc, RC_TP_COLLECT_DBG_DATA_UNSUPPORTED_CHIP);
            break;
        }
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
        for (std::vector<std::pair<uint32_t, uint32_t> >::const_iterator offset = spy_offsets.begin();
             offset != spy_offsets.end();
             offset++)
        {
            uint32_t chunk_size = (offset->second - offset->first + 1);
            rc_ecmd |= spy_data.insert(ring_data,
                                       spy_offset_curr,
                                       chunk_size,
                                       offset->first);
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
