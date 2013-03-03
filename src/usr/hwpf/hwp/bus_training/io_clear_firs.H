/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/io_clear_firs.H $               */
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
// $Id: io_clear_firs.H,v 1.4 2013/02/20 09:40:22 jaswamin Exp $
#ifndef IO_CLEAR_FIRS_H
#define IO_CLEAR_FIRS_H

#include <fapi.H>
#include "gcr_funcs.H"

using namespace fapi;

/**
 * io_clear_firs HWP func pointer typedef
 *
 */
typedef fapi::ReturnCode (*io_clear_firs_FP_t)(const fapi::Target &target);

// P8 chip interfaces
const uint32_t FIR_INTERFACES=8;
const uint32_t FIR_ISOLATION_REGS=42;

enum fir_io_interface_t {FIR_CP_FABRIC_X0,
                FIR_CP_FABRIC_X1,
                FIR_CP_FABRIC_X2,
                FIR_CP_FABRIC_X3,
                FIR_CP_FABRIC_A0,
                FIR_CP_IOMC0_P0,  
                FIR_CP_IOMC1_P0,  
                FIR_CEN_DMI };
           
const char * const fir_interface_name[FIR_INTERFACES] = {"CP_FABRIC_X0",
                                            "CP_FABRIC_X1",
                                            "CP_FABRIC_X2",
                                            "CP_FABRIC_X3",
                                            "CP_FABRIC_A0",
                                            "CP_IOMC0_P0",  
                                            "CP_IOMC1_P0",  
                                            "CEN_DMI" };
                                            
// FIR register addresses for interfaces
const uint32_t fir_clear_reg_addr[FIR_INTERFACES] = {   0x04011001,
                                                  0x04011401,
                                                  0x04011c01,
                                                  0x04011801,
                                                  0x08010c01, 
                                                  0x02011a01, 
                                                  0x02011e01, 
                                                  0x02010401  };
                                                  
const uint32_t fir_rw_reg_addr[FIR_INTERFACES]={0x04011000,
                                                  0x04011400,
                                                  0x04011c00,
                                                  0x04011800,
                                                  0x08010c00, 
                                                  0x02011a00, 
                                                  0x02011e00, 
                                                  0x02010400  };
                                                  
const uint32_t fir_clear_mask_reg_addr[FIR_INTERFACES]={0x04011004,
                                                  0x04011404,
                                                  0x04011c04,
                                                  0x04011804,
                                                  0x08010c04, 
                                                  0x02011a04, 
                                                  0x02011e04, 
                                                  0x02010404  };
enum fir_error_type{
    RX_PARITY,
    TX_PARITY,
    GCR_HANG_ERROR,
    BUS0_SPARE_DEPLOYED=9,
    BUS0_MAX_SPARES_EXCEEDED=10,
    BUS0_RECALIBRATION_ERROR=11,
    BUS0_TOO_MANY_BUS_ERRORS=12,
    BUS1_SPARE_DEPLOYED=17,
    BUS1_MAX_SPARES_EXCEEDED=18,
    BUS1_RECALIBRATION_ERROR=19,
    BUS1_TOO_MANY_BUS_ERRORS=20,
    BUS2_SPARE_DEPLOYED=25,
    BUS2_MAX_SPARES_EXCEEDED=26,
    BUS2_RECALIBRATION_ERROR=27,
    BUS2_TOO_MANY_BUS_ERRORS=28,
    BUS3_SPARE_DEPLOYED=33,
    BUS3_MAX_SPARES_EXCEEDED=34,
    BUS3_RECALIBRATION_ERROR=35,
    BUS3_TOO_MANY_BUS_ERRORS=36,
    BUS4_SPARE_DEPLOYED=41,
    BUS4_MAX_SPARES_EXCEEDED=42,
    BUS4_RECALIBRATION_ERROR=43,
    BUS4_TOO_MANY_BUS_ERRORS=44,                                              
};
const char * const fir1_reg[16] = {"RX_PG_FIR_ERR_PG_REGS",
                                            "RX_PG_FIR_ERR_GCR_BUFF",
                                            "RESERVED_FIR",
                                            "RX_PG_FIR_ERR_GCRS_LD_SM",
                                            "RX_PG_FIR_ERR_GCRS_UNLD_SM",
                                            "RX_PG_FIR_ERR_GLB_INIT_SND_MSG_SM",  
                                            "RX_PG_FIR_ERR_MAIN_INIT_SM",  
                                            "RX_PG_FIR_ERR_WTM_SM",
                                            "RX_PG_FIR_ERR_WTR_SM",
                                            "RX_PG_FIR_ERR_WTL_SM",
                                            "RX_PG_FIR_ERR_RPR_SM",
                                            "RX_PG_FIR_ERR_EYEOPT_SM",
                                            "RX_PG_FIR_ERR_DSM_SM",
                                            "RX_PG_FIR_ERR_RXDSM_SM",
                                            "RX_PG_CHAN_FAIL_RSVD",
                                            "RX_PL_FIR_ERR"};
                                            

const char * const fir2_reg[16] = {"RX_PG_FIR_ERR_DYN_RPR_SM",
                                            "RX_PG_FIR_ERR_SLS_HNDSHK_SM",
                                            "RX_PG_FIR_ERR_DYN_RPR_SND_MSG_SM",
                                            "RX_PG_FIR_ERR_RECAL_SM",
                                            "RX_PG_FIR_ERR_SLS_ENC_SND_MSG_SM",
                                            "RX_PG_FIR_ERR_GLB_CAL_SND_MSG_SM",
                                            "RX_PG_FIR_ERR_STAT_RPR_SND_MSG_SM",
                                            "RESERVED_FIR",
                                            "RESERVED_FIR",
                                            "RESERVED_FIR",
                                            "RESERVED_FIR",
                                            "RESERVED_FIR",
                                            "RESERVED_FIR",
                                            "RESERVED_FIR",
                                            "RESERVED_FIR",
                                            "RESERVED_FIR"};

extern "C"
{

/**
 * io_clear_firs HWP 
 *
 * target is any IO target P8 MCS,XBUS,Abus or centaur
 * 
 * 
 *
 * 
 */

fapi::ReturnCode io_clear_firs(const fapi::Target &target);

fapi::ReturnCode clear_fir_err_regs(const Target &target,io_interface_t chip_interface,uint32_t group);

fapi::ReturnCode clear_fir_reg(const Target &target,fir_io_interface_t chip_interface);

fapi::ReturnCode clear_fir_mask_reg(const Target &target,fir_io_interface_t chip_interface);

fapi::ReturnCode read_fir_reg(const Target &target,fir_io_interface_t chip_interface,ecmdDataBufferBase &databuf_64bit);




    
} // extern "C"
#endif // CLEAR_IO_FIRS_H_

