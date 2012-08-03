/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/dram_initialization/mss_maint_cmds/mss_maint_cmds.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
// $Id: mss_maint_cmds.C,v 1.9 2012/07/18 21:37:50 gollub Exp $
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|   Date:  | Author: | Comment:
//---------|----------|---------|-----------------------------------------------
//         | 11/02/11 | gollub  | Created
//         | 12/01/11 | gollub  | Fixed problem with end address
//         | 03/30/12 | gollub  | Made stop condition parm into a mask.
//         |          |         | Added support for both MBAs
//         |          |         | Calculate real start/end address, but run on 2
//         |          |         | addresses if sim
//         | 04/25/12 | gollub  | Updated error paths
//         | 05/23/12 | gollub  | Updates from review.
//         | 07/13/12 | gollub  | Updates from review.
//   1.8   | 07/16/12 | bellows | added in Id tag
//   1.9   | 07/18/12 | gollub  | Updates from review.
//         |          |         | Updates for timebase scrub.

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------

#include <mss_maint_cmds.H>
#include <cen_scom_addresses.H>
using namespace fapi;


//------------------------------------------------------------------------------
// Constants and enums
//------------------------------------------------------------------------------

/**
 * @brief Max 8 master ranks per MB
 */ 
const uint8_t MSS_MAX_RANKS =                         8;

/**
 * @brief The number of symbols per rank
 */ 
const uint8_t MSS_SYMBOLS_PER_RANK =                  72;

/**
 * @brief 9 x8 DRAMs we can steer, plus one for no steer option
 */ 
const uint8_t MSS_X8_STEER_OPTIONS_PER_PORT =         10;

/**
 * @brief 18 x4 DRAMs we can steer on port0, plus one for no steer option
 */ 
const uint8_t MSS_X4_STEER_OPTIONS_PER_PORT0 =        19;

/**
 * @brief 17 x4 DRAMs we can steer on port1, plus one no steer option
 *        NOTE: Only 17 DRAMs we can steer since one DRAM is used for the 
 *        ECC spare.
 */ 
const uint8_t MSS_X4_STEER_OPTIONS_PER_PORT1 =        18;

/**
 * @brief 18 on port0, 17 on port1, plus one no steer option
 *        NOTE: Can's use ECC spare to fix bad spare DRAMs     
 */                                                         
const uint8_t MSS_X4_ECC_STEER_OPTIONS =              36;        
                                                            

namespace mss_MemConfig
{
/**
 * @brief DRAM size in gigabits, used to determine address range for maint cmds
 */ 
    enum DramSize
    {
        GBIT_2 = 0,
        GBIT_4 = 1,
        GBIT_8 = 2,
    };
    
/**
 * @brief DRAM width, used to determine address range for maint cmds
 */
    enum DramWidth
    {
        X8 = 0,
        X4 = 1,
    };

/**
 * @brief DRAM row, column, and bank bits, used to determine address range 
 *        for maint cmds
 */
    enum MemOrg
    {
        ROW_15 = 0x00007FFF,
        ROW_16 = 0x0000FFFF,
        COL_10 = 0x000003F8,    // c2, c1, c0 always 0    
        COL_11 = 0x000007F8,    // c2, c1, c0 always 0    
        COL_12 = 0x00000FF8,    // c2, c1, c0 always 0    
        BANK_3 = 0x00000007,
    };
};




static const uint32_t mss_mbaxcr[2]={
    // port0/1                     port2/3
    MBAXCR01Q_0x0201140B,          MBAXCR23Q_0x0201140C};

static const uint32_t mss_mbeccfir[2]={
    // port0/1                     port2/3
    MBS_ECC0_MBECCFIR_0x02011440,  MBS_ECC1_MBECCFIR_0x02011480};

static const uint32_t mss_mbsecc[2]={
    // port0/1                     port2/3
    MBS_ECC0_MBSECCQ_0x0201144A,   MBS_ECC1_MBSECCQ_0x0201148A};

static const uint32_t mss_markStoreRegs[8][2]={
    // port0/1                     port2/3
    {MBS_ECC0_MBMS0_0x0201144B,    MBS_ECC1_MBMS0_0x0201148B},
    {MBS_ECC0_MBMS1_0x0201144C,    MBS_ECC1_MBMS1_0x0201148C},
    {MBS_ECC0_MBMS2_0x0201144D,    MBS_ECC1_MBMS2_0x0201148D},
    {MBS_ECC0_MBMS3_0x0201144E,    MBS_ECC1_MBMS3_0x0201148E},
    {MBS_ECC0_MBMS4_0x0201144F,    MBS_ECC1_MBMS4_0x0201148F},
    {MBS_ECC0_MBMS5_0x02011450,    MBS_ECC1_MBMS5_0x02011490},
    {MBS_ECC0_MBMS6_0x02011451,    MBS_ECC1_MBMS6_0x02011491},
    {MBS_ECC0_MBMS7_0x02011452,    MBS_ECC1_MBMS7_0x02011492}};
                                          
static const uint32_t mss_readMuxRegs[8][2]={
    // port0/1                     port2/3
    {MBS_ECC0_MBSBS0_0x0201145E,   MBS_ECC1_MBSBS0_0x0201149E},
    {MBS_ECC0_MBSBS1_0x0201145F,   MBS_ECC1_MBSBS1_0x0201149F},
    {MBS_ECC0_MBSBS2_0x02011460,   MBS_ECC1_MBSBS2_0x020114A0},    
    {MBS_ECC0_MBSBS3_0x02011461,   MBS_ECC1_MBSBS3_0x020114A1},
    {MBS_ECC0_MBSBS4_0x02011462,   MBS_ECC1_MBSBS4_0x020114A2},
    {MBS_ECC0_MBSBS5_0x02011463,   MBS_ECC1_MBSBS5_0x020114A3},
    {MBS_ECC0_MBSBS6_0x02011464,   MBS_ECC1_MBSBS6_0x020114A4},
    {MBS_ECC0_MBSBS7_0x02011465,   MBS_ECC1_MBSBS7_0x020114A5}};                
        
static const uint32_t mss_writeMuxRegs[8]={    

    MBA01_MBABS0_0x03010440,
    MBA01_MBABS1_0x03010441,
    MBA01_MBABS2_0x03010442,
    MBA01_MBABS3_0x03010443,
    MBA01_MBABS4_0x03010444,
    MBA01_MBABS5_0x03010445,
    MBA01_MBABS6_0x03010446,
    MBA01_MBABS7_0x03010447};

//------------------------------------------------------------------------------
// Conversion from symbol index to galois field stored in markstore
//------------------------------------------------------------------------------
static const uint8_t mss_symbol2Galois[MSS_SYMBOLS_PER_RANK] = 
    {
    0x80, 0xa0, 0x90, 0xf0, 0x08, 0x0a, 0x09, 0x0f, // symbols  0- 7
    0x98, 0xda, 0xb9, 0x7f, 0x91, 0xd7, 0xb2, 0x78, // symbols  8-15
    0x28, 0xea, 0x49, 0x9f, 0x9a, 0xd4, 0xbd, 0x76, // symbols 16-23
    0x60, 0xb0, 0xc0, 0x20, 0x06, 0x0b, 0x0c, 0x02, // symbols 24-31
    0xc6, 0xfb, 0x1c, 0x42, 0xca, 0xf4, 0x1d, 0x46, // symbols 32-39
    0xd6, 0x8b, 0x3c, 0xc2, 0xcb, 0xf3, 0x1f, 0x4e, // symbols 40-47
    0xe0, 0x10, 0x50, 0xd0, 0x0e, 0x01, 0x05, 0x0d, // symbols 48-55
    0x5e, 0x21, 0xa5, 0x3d, 0x5b, 0x23, 0xaf, 0x3e, // symbols 56-63
    0xfe, 0x61, 0x75, 0x5d, 0x51, 0x27, 0xa2, 0x38, // symbols 64-71
    };
      
static const uint8_t mss_x8dramSparePort0Index_to_symbol[MSS_X8_STEER_OPTIONS_PER_PORT]={
    // symbol
    0xff,    // Port0 DRAM spare not used
    68,      // DRAM 17 (x8)
    64,      // DRAM 16 (x8)
    60,      // DRAM 15 (x8)
    56,      // DRAM 14 (x8)
    52,      // DRAM 13 (x8)
    48,      // DRAM 12 (x8)
    44,      // DRAM 11 (x8)
    40,      // DRAM 10 (x8)
    4};      // DRAM 1 (x8)

static const uint8_t mss_x4dramSparePort0Index_to_symbol[MSS_X4_STEER_OPTIONS_PER_PORT0]={
    // symbol
    0xff,   // Port0 DRAM spare not used
    70,     // DRAM 35 (x4)
    68,     // DRAM 34 (x4)
    66,     // DRAM 33 (x4)
    64,     // DRAM 32 (x4)
    62,     // DRAM 31 (x4)
    60,     // DRAM 30 (x4)
    58,     // DRAM 29 (x4)
    56,     // DRAM 28 (x4)
    54,     // DRAM 27 (x4) 
    52,     // DRAM 26 (x4)
    50,     // DRAM 25 (x4)
    48,     // DRAM 24 (x4)
    46,     // DRAM 23 (x4)
    44,     // DRAM 22 (x4)
    42,     // DRAM 21 (x4)
    40,     // DRAM 20 (x4)
    6,      // DRAM 3 (x4)
    4};     // DRAM 2 (x4)



static const uint8_t mss_x8dramSparePort1Index_to_symbol[MSS_X8_STEER_OPTIONS_PER_PORT]={
    // symbol
    0xff,    // Port1 DRAM spare not used
    36,      // DRAM 9 (x8)
    32,      // DRAM 8 (x8)
    28,      // DRAM 7 (x8)
    24,      // DRAM 6 (x8)
    20,      // DRAM 5 (x8)
    16,      // DRAM 4 (x8)
    12,      // DRAM 3 (x8)
    8,       // DRAM 2 (x8)
    0};      // DRAM 0 (x8)



static const uint8_t mss_x4dramSparePort1Index_to_symbol[MSS_X4_STEER_OPTIONS_PER_PORT1]={
    // symbol
    0xff,   // Port1 DRAM spare not used
    38,     // DRAM 19 (x4)
    36,     // DRAM 18 (x4)
    34,     // DRAM 17 (x4)
    32,     // DRAM 16 (x4)
    30,     // DRAM 15 (x4)
    28,     // DRAM 14 (x4)
    26,     // DRAM 13 (x4)
    24,     // DRAM 12 (x4)
    22,     // DRAM 11 (x4) 
    20,     // DRAM 10 (x4)
    18,     // DRAM 9 (x4)
    16,     // DRAM 8 (x4)
    14,     // DRAM 7 (x4)
    12,     // DRAM 6 (x4)
    10,     // DRAM 5 (x4)
    8,      // DRAM 4 (x4)
    2};     // DRAM 1 (x4)
    // NOTE: DRAM 0 (x4) (symbols 0,1) on Port1 is used for the ECC spare, 
    // so can't use DRAM spare to fix DRAM 0.



static const uint8_t mss_eccSpareIndex_to_symbol[MSS_X4_ECC_STEER_OPTIONS]={
    // symbol
    0xff,      // ECC spare not used
    70,        // DRAM 35 (x4)
    68,        // DRAM 34 (x4)
    66,        // DRAM 33 (x4)
    64,        // DRAM 32 (x4)
    62,        // DRAM 31 (x4)
    60,        // DRAM 30 (x4)
    58,        // DRAM 29 (x4)
    56,        // DRAM 28 (x4)
    54,        // DRAM 27 (x4)
    52,        // DRAM 26 (x4)
    50,        // DRAM 25 (x4)
    48,        // DRAM 24 (x4)
    46,        // DRAM 23 (x4)
    44,        // DRAM 22 (x4)
    42,        // DRAM 21 (x4)
    40,        // DRAM 20 (x4)
    38,        // DRAM 19 (x4)
    36,        // DRAM 18 (x4)
    34,        // DRAM 17 (x4)
    32,        // DRAM 16 (x4)
    30,        // DRAM 15 (x4)
    28,        // DRAM 14 (x4)
    26,        // DRAM 13 (x4)
    24,        // DRAM 12 (x4)
    22,        // DRAM 11 (x4)
    20,        // DRAM 10 (x4)
    18,        // DRAM 9 (x4)
    16,        // DRAM 8 (x4)
    14,        // DRAM 7 (x4)
    12,        // DRAM 6 (x4)
    10,        // DRAM 5 (x4)
    8,         // DRAM 4 (x4)
    6,         // DRAM 3 (x4)
    4,         // DRAM 2 (x4)
    2};        // DRAM 1 (x4)
    // NOTE: DRAM 0 (x4) (symbols 0,1) used for the ECC spare.
    // NOTE: Can't use ECC spare to fix bad spare DRAMs on Port0 or Port1



//------------------------------------------------------------------------------
// Parent class
//------------------------------------------------------------------------------

//---------------------------------------------------------
// mss_MaintCmd Constructor
//---------------------------------------------------------
mss_MaintCmd::mss_MaintCmd(const fapi::Target & i_target,
                           const ecmdDataBufferBase & i_startAddr,
                           const ecmdDataBufferBase & i_endAddr,
                           StopCondition i_stopCondition,
                           bool i_poll,
                           CmdType i_cmdType ) :
    iv_target( i_target ),
    iv_startAddr( i_startAddr ),
    iv_endAddr( i_endAddr ),
    iv_stopCondition( i_stopCondition),
    iv_poll (i_poll),
    iv_cmdType(i_cmdType){}




//---------------------------------------------------------
// mss_cleanupCmd
//---------------------------------------------------------
fapi::ReturnCode mss_MaintCmd::cleanupCmd()
{
    fapi::ReturnCode l_rc;
    FAPI_INF("ENTER mss_MaintCmd::cleanupCmd()");
    
    // Clear maintenance command complete attention, scrub stats, etc...
    
    FAPI_INF("EXIT mss_MaintCmd::cleanupCmd()");
    return l_rc;
}


//---------------------------------------------------------
// mss_preConditionCheck
//---------------------------------------------------------
fapi::ReturnCode mss_MaintCmd::preConditionCheck()
{
    fapi::ReturnCode l_rc;
    ecmdDataBufferBase l_mbmccq(64);
    ecmdDataBufferBase l_mbmsrq(64);
    ecmdDataBufferBase l_mbaxcr(64);
    ecmdDataBufferBase l_ccs_modeq(64);
    ecmdDataBufferBase l_mbsecc(64);
           
    FAPI_INF("ENTER mss_MaintCmd::preConditionCheck()");
    
    // Get Centaur target for the given MBA
    l_rc = fapiGetParentChip(iv_target, iv_targetCentaur);
    if(l_rc)
    {
        FAPI_ERR("Error getting Centaur parent target for the given MBA");
        return l_rc;
    }
    
    
    // Get MBA position: 0 = mba01, 1 = mba23
    l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &iv_target, iv_mbaPosition);
    if(l_rc)
    {
        FAPI_ERR("Error getting MBA position");
        return l_rc;
    }    

    // Read MBMCCQ        
    l_rc = fapiGetScom(iv_target, MBA01_MBMCCQ_0x0301060B, l_mbmccq); 
    if(l_rc) return l_rc;

    // Read MBMSRQ
    l_rc = fapiGetScom(iv_target, MBA01_MBMSRQ_0x0301060C, l_mbmsrq); 
    if(l_rc) return l_rc;
    
    // Read MBAXCRn
    l_rc = fapiGetScom(iv_targetCentaur, mss_mbaxcr[iv_mbaPosition], l_mbaxcr); 
    if(l_rc) return l_rc;
    
    // Read CCS_MODEQ
    l_rc = fapiGetScom(iv_target, MEM_MBA01_CCS_MODEQ_0x030106A7, l_ccs_modeq);
    if(l_rc) return l_rc;
    
    // Read MBSECC
    l_rc = fapiGetScom(iv_targetCentaur, mss_mbsecc[iv_mbaPosition], l_mbsecc); 
    if(l_rc) return l_rc;


    // Check for MBMCCQ[0], maint_cmd_start, to be reset by hw.
    if (l_mbmccq.isBitSet(0))
    {
        // Create new log
        FAPI_ERR("MCMCCQ[0]: maint_cmd_start not reset by hw.");       
        FAPI_SET_HWP_ERROR(l_rc, RC_MSS_MAINT_START_NOT_RESET);
    }

    // Check for MBMCCQ[1], maint_cmd_stop, to be reset by hw.
    if (l_mbmccq.isBitSet(1))
    {
        // Log previous error before creating new log
        if (l_rc) fapiLogError(l_rc);
        
        // Create new log
        FAPI_ERR("MCMCCQ[1]: maint_cmd_stop not reset by hw.");       
        FAPI_SET_HWP_ERROR(l_rc, RC_MSS_MAINT_STOP_NOT_RESET);
    }

    // Check for MBMSRQ[0], maint_cmd_in_progress, to be reset.
    if (l_mbmsrq.isBitSet(0))
    {    
        // Log previous error before creating new log
        if (l_rc) fapiLogError(l_rc);
        
        // Create new log
        FAPI_ERR("MBMSRQ[0]: Can't start new cmd if previous cmd still in progress.");
        FAPI_SET_HWP_ERROR(l_rc, RC_MSS_MAINT_CMD_IN_PROGRESS);
    }

    // Check MBAXCRn, to show memory configured behind this MBA
    if (l_mbaxcr.isBitClear(0,4))
    {
        // Log previous error before creating new log
        if (l_rc) fapiLogError(l_rc);
                
        // Create new log
        FAPI_ERR("MBAXCRn[0:3] = 0, meaning no memory configured behind this MBA.");
        FAPI_SET_HWP_ERROR(l_rc, RC_MSS_MAINT_NO_MEM_CNFG);
    }
    
    // Check CCS_MODEQ[29] to make sure mux switched from CCS to mainline
    if (l_ccs_modeq.isBitSet(29))
    {
        // Log previous error before creating new log
        if (l_rc) fapiLogError(l_rc);
        
        // Create new log
        FAPI_ERR("CCS_MODEQ[29] = 1, meaning mux set for CCS instead of mainline.");
        FAPI_SET_HWP_ERROR(l_rc, RC_MSS_MAINT_CCS_MUX_NOT_MAINLINE);
    }

    // Check MBSECC[0] = 0, to make sure ECC check/correct is enabled
    if (l_mbsecc.isBitSet(0))
    {
        // Log previous error before creating new log
        if (l_rc) fapiLogError(l_rc);
        
        // Create new log
        FAPI_ERR("MBSECC[0] = 1, meaning ECC check/correct disabled.");
        FAPI_SET_HWP_ERROR(l_rc, RC_MSS_MAINT_ECC_DISABLED);
    }

  
    FAPI_INF("EXIT mss_MaintCmd::preConditionCheck()");
    return l_rc;
}


//---------------------------------------------------------
// mss_loadCmdType
//---------------------------------------------------------
fapi::ReturnCode mss_MaintCmd::loadCmdType()
{
    fapi::ReturnCode l_rc;
    uint32_t l_ecmd_rc = 0;    
    ecmdDataBufferBase l_data(64);

    FAPI_INF("ENTER mss_MaintCmd::loadCmdType()");
    
    l_rc = fapiGetScom(iv_target, MBA01_MBMCTQ_0x0301060A, l_data); 
    if(l_rc) return l_rc;
    l_ecmd_rc |= l_data.insert( (uint32_t)iv_cmdType, 0, 5, 32-5 );
    
    // NOTE: Setting super fast address increment mode, where COL bits are LSB.
    // Valid for all cmds. 
    l_ecmd_rc |= l_data.setBit(5);
    if(l_ecmd_rc)
    {
        l_rc.setEcmdError(l_ecmd_rc);
        return l_rc;
    }
    l_rc = fapiPutScom(iv_target, MBA01_MBMCTQ_0x0301060A, l_data);
    if(l_rc) return l_rc;
  
    FAPI_INF("EXIT mss_MaintCmd::loadCmdType()");
    return l_rc;
}



//---------------------------------------------------------
// mss_loadStartAddress
//---------------------------------------------------------
fapi::ReturnCode mss_MaintCmd::loadStartAddress()
{
    fapi::ReturnCode l_rc;
    uint32_t l_ecmd_rc = 0;        
    ecmdDataBufferBase l_data(64);

    FAPI_INF("ENTER mss_MaintCmd::loadStartAddress()");
    
    l_rc = fapiGetScom(iv_target, MBA01_MBMACAQ_0x0301060D, l_data);
    if(l_rc) return l_rc;
    
    // Load address bits 0:39
    l_ecmd_rc |= l_data.insert( iv_startAddr, 0, 40, 0 ); 
    
    // Clear error status bits 40:46
    l_ecmd_rc |= l_data.clearBit(40,7);

    if(l_ecmd_rc)
    {
        l_rc.setEcmdError(l_ecmd_rc);
        return l_rc;
    }
    l_rc = fapiPutScom(iv_target, MBA01_MBMACAQ_0x0301060D, l_data);
    if(l_rc) return l_rc;
  
    FAPI_INF("EXIT mss_MaintCmd::loadStartAddress()");
    return l_rc;
}


//---------------------------------------------------------
// mss_loadEndAddress
//---------------------------------------------------------
fapi::ReturnCode mss_MaintCmd::loadEndAddress()
{
    fapi::ReturnCode l_rc;
    uint32_t l_ecmd_rc = 0;            
    ecmdDataBufferBase l_data(64);

    FAPI_INF("ENTER mss_MaintCmd::loadEndAddress()");
    
    l_rc = fapiGetScom(iv_target, MBA01_MBMEAQ_0x0301060E, l_data);
    if(l_rc) return l_rc;
    
    l_ecmd_rc |= l_data.insert( iv_endAddr, 0, 40, 0 ); 
    if(l_ecmd_rc)
    {
        l_rc.setEcmdError(l_ecmd_rc);
        return l_rc;
    }    
    l_rc = fapiPutScom(iv_target, MBA01_MBMEAQ_0x0301060E, l_data); 
    if(l_rc) return l_rc;
  
    FAPI_INF("EXIT mss_MaintCmd::loadEndAddress()");
    return l_rc;
}


//---------------------------------------------------------
// mss_loadStopCondMask
//---------------------------------------------------------
fapi::ReturnCode mss_MaintCmd::loadStopCondMask()
{
    fapi::ReturnCode l_rc;
    uint32_t l_ecmd_rc = 0;   
    ecmdDataBufferBase l_mbasctlq(64);

    FAPI_INF("ENTER mss_MaintCmd::loadStopCondMask()");    

    // Get stop conditions from MBASCTLQ
    l_rc = fapiGetScom(iv_target, MBA01_MBASCTLQ_0x0301060F, l_mbasctlq); 
    if(l_rc) return l_rc;
    
    // Start by clearing all bits 0:12
    l_ecmd_rc |= l_mbasctlq.clearBit(0,13);

    // Stop location
    // Enable stop end of rank    
    if ( 0 != (iv_stopCondition & STOP_END_OF_RANK) ) 
    l_ecmd_rc |= l_mbasctlq.setBit(1);
    // Enable stop immediate
    else l_ecmd_rc |= l_mbasctlq.setBit(0);
    
    // Stop on hard NCE ETE
    if ( 0 != (iv_stopCondition & STOP_ON_HARD_NCE_ETE) ) 
    l_ecmd_rc |= l_mbasctlq.setBit(2);

    // Stop on intermittent NCE ETE
    if ( 0 != (iv_stopCondition & STOP_ON_INT_NCE_ETE) ) 
    l_ecmd_rc |= l_mbasctlq.setBit(3);

    // Stop on soft NCE ETE
    if ( 0 != (iv_stopCondition & STOP_ON_SOFT_NCE_ETE) ) 
    l_ecmd_rc |= l_mbasctlq.setBit(4);

    // Stop on SCE
    if ( 0 != (iv_stopCondition & STOP_ON_SCE) ) 
    l_ecmd_rc |= l_mbasctlq.setBit(5);

    // Stop on MCE
    if ( 0 != (iv_stopCondition & STOP_ON_MCE) ) 
    l_ecmd_rc |= l_mbasctlq.setBit(6);

    // Stop on retry CE ETE
    if ( 0 != (iv_stopCondition & STOP_ON_RETRY_CE) ) 
    l_ecmd_rc |= l_mbasctlq.setBit(7);

    // Stop on MPE
    if ( 0 != (iv_stopCondition & STOP_ON_MPE) ) 
    l_ecmd_rc |= l_mbasctlq.setBit(8);    

    // Stop on UE
    if ( 0 != (iv_stopCondition & STOP_ON_UE) ) 
    l_ecmd_rc |= l_mbasctlq.setBit(9);

    // Stop on end address
    if ( 0 != (iv_stopCondition & STOP_ON_END_ADDRESS) ) 
    l_ecmd_rc |= l_mbasctlq.setBit(10);

    // Enable command complete attention
    if ( 0 != (iv_stopCondition & ENABLE_CMD_COMPLETE_ATTENTION) ) 
    l_ecmd_rc |= l_mbasctlq.setBit(11);

    // Stop on SUE
    if ( 0 != (iv_stopCondition & STOP_ON_SUE) ) 
    l_ecmd_rc |= l_mbasctlq.setBit(12);

    if(l_ecmd_rc)
    {
        l_rc.setEcmdError(l_ecmd_rc);
        return l_rc;
    }    

    // Write stop conditions to MBASCTLQ
    l_rc = fapiPutScom(iv_target, MBA01_MBASCTLQ_0x0301060F, l_mbasctlq); 
    if(l_rc) return l_rc;

    FAPI_INF("EXIT mss_MaintCmd::loadStopCondMask()");    
    
    return l_rc;
}


//---------------------------------------------------------
// mss_startMaintCmd
//---------------------------------------------------------
fapi::ReturnCode mss_MaintCmd::startMaintCmd()
{
    fapi::ReturnCode l_rc;
    uint32_t l_ecmd_rc = 0;                    
    ecmdDataBufferBase l_data(64);

    FAPI_INF("ENTER mss_MaintCmd::startMaintCmd()");    
    
    l_rc = fapiGetScom(iv_target, MBA01_MBMCCQ_0x0301060B, l_data); 
    if(l_rc) return l_rc;
    
    l_ecmd_rc |= l_data.setBit(0);
    if(l_ecmd_rc)
    {
        l_rc.setEcmdError(l_ecmd_rc);
        return l_rc;
    }    
    l_rc = fapiPutScom(iv_target, MBA01_MBMCCQ_0x0301060B, l_data);
    if(l_rc) return l_rc;

    FAPI_INF("EXIT mss_MaintCmd::startMaintCmd()");    
    return l_rc;
}

//---------------------------------------------------------
// mss_postConditionCheck
//---------------------------------------------------------
fapi::ReturnCode mss_MaintCmd::postConditionCheck()
{
    fapi::ReturnCode l_rc;
    ecmdDataBufferBase l_mbmccq(64);
    ecmdDataBufferBase l_mbafirq(64);

    FAPI_INF("ENTER mss_MaintCmd::postConditionCheck()");    
    
    // Read MBMCCQ        
    l_rc = fapiGetScom(iv_target, MBA01_MBMCCQ_0x0301060B, l_mbmccq); 
    if(l_rc) return l_rc;

    // Read MBAFIRQ
    l_rc = fapiGetScom(iv_target, MBA01_MBAFIRQ_0x03010600, l_mbafirq); 
    if(l_rc) return l_rc;
    
    // Check for MBMCCQ[0], maint_cmd_start, to be reset by hw.
    if (l_mbmccq.isBitSet(0))
    {
        // Create new log
        FAPI_ERR("MCMCCQ[0]: maint_cmd_start not reset by hw.");       
        FAPI_SET_HWP_ERROR(l_rc, RC_MSS_MAINT_START_NOT_RESET);
    }

    // Check for MBAFIRQ[0], invalid_maint_cmd.
    if (l_mbafirq.isBitSet(0))
    {
        // Log previous error before creating new log
        if (l_rc) fapiLogError(l_rc);
        
        // Create new log
        FAPI_ERR("MBAFIRQ[0], invalid_maint_cmd.");       
        FAPI_SET_HWP_ERROR(l_rc, RC_MSS_MAINT_INVALID_CMD);
    }

    // Check for MBAFIRQ[1], invalid_maint_address.
    if (l_mbafirq.isBitSet(1))
    {
        // Log previous error before creating new log
        if (l_rc) fapiLogError(l_rc);
        
        // Create new log
        FAPI_ERR("MBAFIRQ[1], cmd started with invalid_maint_address.");       
        FAPI_SET_HWP_ERROR(l_rc, RC_MSS_MAINT_INVALID_ADDR);
    }

    
    FAPI_INF("EXIT mss_MaintCmd::postConditionCheck()");        
    return l_rc;
}

//---------------------------------------------------------
// mss_pollForMaintCmdComplete
//---------------------------------------------------------
fapi::ReturnCode mss_MaintCmd::pollForMaintCmdComplete()
{
    
    fapi::ReturnCode l_rc;
    ecmdDataBufferBase l_data(64);

    FAPI_INF("ENTER mss_MaintCmd::pollForMaintCmdComplete()");    
    
    uint32_t count = 0;
    
    // 1 ms delay for HW mode
    const uint64_t  HW_MODE_DELAY = 1000000;
    
    // 200000 sim cycle delay for SIM mode  
    const uint64_t  SIM_MODE_DELAY = 200000; 
    
    uint32_t loop_limit = 500;
    
    do
    {
        fapiDelay(HW_MODE_DELAY, SIM_MODE_DELAY); 
                
        FAPI_INF("Read MBMACAQ just to see if it's incrementing");    
        l_rc = fapiGetScom(iv_target, MBA01_MBMACAQ_0x0301060D, l_data); 
        if(l_rc) return l_rc;

        FAPI_INF("Waiting for MBMSRQ[0] maint cmd in progress bit to turn off");
        l_rc = fapiGetScom(iv_target, MBA01_MBMSRQ_0x0301060C, l_data); 
        if(l_rc) return l_rc;

        count++;

    }
    // Poll until cmd in progress bit goes off 
    while (l_data.isBitSet(0) && (count < loop_limit)); 

    if (count == loop_limit)
    {
        // Create new log
        FAPI_ERR("Maint cmd timeout.");       
        FAPI_SET_HWP_ERROR(l_rc, RC_MSS_MAINT_CMD_TIMEOUT);
    }
    else
    {
        FAPI_INF("Maint cmd complete. ");
    }

    FAPI_INF("EXIT mss_MaintCmd::pollForMaintCmdComplete()");        
    return l_rc;
}

//---------------------------------------------------------
// mss_collectFFDC
//---------------------------------------------------------
fapi::ReturnCode mss_MaintCmd::collectFFDC()
{
    fapi::ReturnCode l_rc;
    ecmdDataBufferBase l_data(64);

    FAPI_INF("ENTER mss_MaintCmd::collectFFDC()");        
    
    FAPI_INF("MBMCTQ");
    l_rc = fapiGetScom(iv_target, MBA01_MBMCTQ_0x0301060A, l_data);
    if(l_rc) return l_rc;
    
    FAPI_INF("MBMACAQ");
    l_rc = fapiGetScom(iv_target, MBA01_MBMACAQ_0x0301060D, l_data);
    if(l_rc) return l_rc;

    // Print out error status bits from MBMACAQ
    if (l_data.isBitSet(40)) FAPI_ERR("40:NCE");
    if (l_data.isBitSet(41)) FAPI_ERR("41:SCE");
    if (l_data.isBitSet(42)) FAPI_ERR("42:MCE");    
    if (l_data.isBitSet(43)) FAPI_ERR("43:RCE");    
    if (l_data.isBitSet(44)) FAPI_ERR("44:MPE");    
    if (l_data.isBitSet(45)) FAPI_ERR("45:SUE");    
    if (l_data.isBitSet(46)) FAPI_ERR("46:UE");    
    
    FAPI_INF("MBMEAQ");
    l_rc = fapiGetScom(iv_target, MBA01_MBMEAQ_0x0301060E, l_data);
    if(l_rc) return l_rc;
    
    FAPI_INF("MBASCTLQ");
    l_rc = fapiGetScom(iv_target, MBA01_MBASCTLQ_0x0301060F, l_data);
    if(l_rc) return l_rc;
    FAPI_INF("MBASCTLQ = 0x%.8X 0x%.8X", l_data.getWord(0), l_data.getWord(1));
    
    FAPI_INF("MBMCCQ");
    l_rc = fapiGetScom(iv_target, MBA01_MBMCCQ_0x0301060B, l_data); 
    if(l_rc) return l_rc;
    
    FAPI_INF("MBMSRQ");
    l_rc = fapiGetScom(iv_target, MBA01_MBMSRQ_0x0301060C, l_data); 
    if(l_rc) return l_rc;
    
    FAPI_INF("MBAFIRQ");
    l_rc = fapiGetScom(iv_target, MBA01_MBAFIRQ_0x03010600, l_data); 
    if(l_rc) return l_rc;
    
    FAPI_INF("MBSPAQ");
    l_rc = fapiGetScom(iv_target, MBA01_MBSPAQ_0x03010611, l_data); 
    if(l_rc) return l_rc;
    
    FAPI_INF("MBACALFIR");
    l_rc = fapiGetScom(iv_target, MBA01_MBACALFIR_0x03010400, l_data); 
    if(l_rc) return l_rc;
    
    FAPI_INF("MBECCFIR");
    l_rc = fapiGetScom(iv_targetCentaur, mss_mbeccfir[iv_mbaPosition], l_data); 
    if(l_rc) return l_rc;
    
    // Print out maint ECC FIR bits from MBECCFIR
    if (l_data.isBitSet(20,8)) FAPI_ERR("20-27:Maint MPE");
    if (l_data.isBitSet(36)) FAPI_ERR("36: Maint NCE");
    if (l_data.isBitSet(37)) FAPI_ERR("37: Maint SCE");    
    if (l_data.isBitSet(38)) FAPI_ERR("38: Maint MCE");    
    if (l_data.isBitSet(39)) FAPI_ERR("39: Maint RCE");    
    if (l_data.isBitSet(40)) FAPI_ERR("40: Maint SUE");    
    if (l_data.isBitSet(41)) FAPI_ERR("41: Maint UE");    

    FAPI_INF("Markstore: MBMS0-7");
    for ( uint8_t i = 0; i < MSS_MAX_RANKS; i++ )
    {
        l_rc = fapiGetScom(iv_targetCentaur, mss_markStoreRegs[i][iv_mbaPosition], l_data);
        if(l_rc) return l_rc;
    }
    
    FAPI_INF("EXIT mss_MaintCmd::collectFFDC()");        
    return l_rc;
}


//---------------------------------------------------------
// mss_loadPattern
//---------------------------------------------------------
fapi::ReturnCode mss_MaintCmd::loadPattern(PatternIndex i_initPattern)
{

    FAPI_INF("ENTER mss_MaintCmd::loadPattern()");        
    
    static const uint32_t maintBufferDataRegs[2][16][2]={
    // port0/1                                                         
   {{MAINT0_MBS_MAINT_BUFF0_DATA0_0x0201160A, MAINT0_MBS_MAINT_BUFF0_DATA_ECC0_0x02011612},
    {MAINT0_MBS_MAINT_BUFF0_DATA1_0x0201160B, MAINT0_MBS_MAINT_BUFF0_DATA_ECC1_0x02011613},
    {MAINT0_MBS_MAINT_BUFF0_DATA2_0x0201160C, MAINT0_MBS_MAINT_BUFF0_DATA_ECC2_0x02011614},
    {MAINT0_MBS_MAINT_BUFF0_DATA3_0x0201160D, MAINT0_MBS_MAINT_BUFF0_DATA_ECC3_0x02011615},
    {MAINT0_MBS_MAINT_BUFF1_DATA0_0x0201161A, MAINT0_MBS_MAINT_BUFF1_DATA_ECC0_0x02011622},
    {MAINT0_MBS_MAINT_BUFF1_DATA1_0x0201161B, MAINT0_MBS_MAINT_BUFF1_DATA_ECC1_0x02011623},
    {MAINT0_MBS_MAINT_BUFF1_DATA2_0x0201161C, MAINT0_MBS_MAINT_BUFF1_DATA_ECC2_0x02011624},
    {MAINT0_MBS_MAINT_BUFF1_DATA3_0x0201161D, MAINT0_MBS_MAINT_BUFF1_DATA_ECC3_0x02011625},
    {MAINT0_MBS_MAINT_BUFF2_DATA0_0x0201162A, MAINT0_MBS_MAINT_BUFF2_DATA_ECC0_0x02011632},
    {MAINT0_MBS_MAINT_BUFF2_DATA1_0x0201162B, MAINT0_MBS_MAINT_BUFF2_DATA_ECC1_0x02011633},
    {MAINT0_MBS_MAINT_BUFF2_DATA2_0x0201162C, MAINT0_MBS_MAINT_BUFF2_DATA_ECC2_0x02011634},
    {MAINT0_MBS_MAINT_BUFF2_DATA3_0x0201162D, MAINT0_MBS_MAINT_BUFF2_DATA_ECC3_0x02011635},
    {MAINT0_MBS_MAINT_BUFF3_DATA0_0x0201163A, MAINT0_MBS_MAINT_BUFF3_DATA_ECC0_0x02011642},
    {MAINT0_MBS_MAINT_BUFF3_DATA1_0x0201163B, MAINT0_MBS_MAINT_BUFF3_DATA_ECC1_0x02011643},
    {MAINT0_MBS_MAINT_BUFF3_DATA2_0x0201163C, MAINT0_MBS_MAINT_BUFF3_DATA_ECC2_0x02011644},
    {MAINT0_MBS_MAINT_BUFF3_DATA3_0x0201163D, MAINT0_MBS_MAINT_BUFF3_DATA_ECC3_0x02011645}},
    // port2/3                                                         
   {{MAINT1_MBS_MAINT_BUFF0_DATA0_0x0201170A, MAINT1_MBS_MAINT_BUFF0_DATA_ECC0_0x02011712},
    {MAINT1_MBS_MAINT_BUFF0_DATA1_0x0201170B, MAINT1_MBS_MAINT_BUFF0_DATA_ECC1_0x02011713},
    {MAINT1_MBS_MAINT_BUFF0_DATA2_0x0201170C, MAINT1_MBS_MAINT_BUFF0_DATA_ECC2_0x02011714},
    {MAINT1_MBS_MAINT_BUFF0_DATA3_0x0201170D, MAINT1_MBS_MAINT_BUFF0_DATA_ECC3_0x02011715},
    {MAINT1_MBS_MAINT_BUFF1_DATA0_0x0201171A, MAINT1_MBS_MAINT_BUFF1_DATA_ECC0_0x02011722},
    {MAINT1_MBS_MAINT_BUFF1_DATA1_0x0201171B, MAINT1_MBS_MAINT_BUFF1_DATA_ECC1_0x02011723},
    {MAINT1_MBS_MAINT_BUFF1_DATA2_0x0201171C, MAINT1_MBS_MAINT_BUFF1_DATA_ECC2_0x02011724},
    {MAINT1_MBS_MAINT_BUFF1_DATA3_0x0201171D, MAINT1_MBS_MAINT_BUFF1_DATA_ECC3_0x02011725},
    {MAINT1_MBS_MAINT_BUFF2_DATA0_0x0201172A, MAINT1_MBS_MAINT_BUFF2_DATA_ECC0_0x02011732},
    {MAINT1_MBS_MAINT_BUFF2_DATA1_0x0201172B, MAINT1_MBS_MAINT_BUFF2_DATA_ECC1_0x02011733},
    {MAINT1_MBS_MAINT_BUFF2_DATA2_0x0201172C, MAINT1_MBS_MAINT_BUFF2_DATA_ECC2_0x02011734},
    {MAINT1_MBS_MAINT_BUFF2_DATA3_0x0201172D, MAINT1_MBS_MAINT_BUFF2_DATA_ECC3_0x02011735},
    {MAINT1_MBS_MAINT_BUFF3_DATA0_0x0201173A, MAINT1_MBS_MAINT_BUFF3_DATA_ECC0_0x02011742},
    {MAINT1_MBS_MAINT_BUFF3_DATA1_0x0201173B, MAINT1_MBS_MAINT_BUFF3_DATA_ECC1_0x02011743},
    {MAINT1_MBS_MAINT_BUFF3_DATA2_0x0201173C, MAINT1_MBS_MAINT_BUFF3_DATA_ECC2_0x02011744},
    {MAINT1_MBS_MAINT_BUFF3_DATA3_0x0201173D, MAINT1_MBS_MAINT_BUFF3_DATA_ECC3_0x02011745}}};

    // DEBUG    
    /*
    static const uint32_t maintBufferData[16][2]={
    {0x00000000, 0x10000000},    
    {0x00000001, 0x10000001},    
    {0x00000002, 0x10000002},    
    {0x00000003, 0x10000003},    
    {0x00000004, 0x10000004},    
    {0x00000005, 0x10000005},    
    {0x00000006, 0x10000006},    
    {0x00000007, 0x10000007},    
    {0x00000008, 0x10000008},    
    {0x00000009, 0x10000009},    
    {0x0000000A, 0x1000000A},    
    {0x0000000B, 0x1000000B},    
    {0x0000000C, 0x1000000C},    
    {0x0000000D, 0x1000000D},    
    {0x0000000E, 0x1000000E},    
    {0x0000000F, 0x1000000F}};    
    */
    
    
    static const uint32_t maintBufferData[16][2]={
    {0x00000000, 0x00000000},    
    {0x00000000, 0x00000000},    
    {0x00000000, 0x00000000},    
    {0x00000000, 0x00000000},    
    {0x00000000, 0x00000000},    
    {0x00000000, 0x00000000},    
    {0x00000000, 0x00000000},    
    {0x00000000, 0x00000000},    
    {0x00000000, 0x00000000},    
    {0x00000000, 0x00000000},    
    {0x00000000, 0x00000000},    
    {0x00000000, 0x00000000},    
    {0x00000000, 0x00000000},    
    {0x00000000, 0x00000000},    
    {0x00000000, 0x00000000},    
    {0x00000000, 0x00000000}};    
    


    static const uint32_t maintBuffer65thRegs[4][2]={
    {MAINT0_MBS_MAINT_BUFF_65TH_BYTE_64B_ECC0_0x0201164A,    MAINT1_MBS_MAINT_BUFF_65TH_BYTE_64B_ECC0_0x0201174A},
    {MAINT0_MBS_MAINT_BUFF_65TH_BYTE_64B_ECC1_0x0201164B,    MAINT1_MBS_MAINT_BUFF_65TH_BYTE_64B_ECC1_0x0201174B},
    {MAINT0_MBS_MAINT_BUFF_65TH_BYTE_64B_ECC2_0x0201164C,    MAINT1_MBS_MAINT_BUFF_65TH_BYTE_64B_ECC2_0x0201174C},
    {MAINT0_MBS_MAINT_BUFF_65TH_BYTE_64B_ECC3_0x0201164D,    MAINT1_MBS_MAINT_BUFF_65TH_BYTE_64B_ECC3_0x0201174D}};

 
     fapi::ReturnCode l_rc;
    uint32_t l_ecmd_rc = 0;                
    ecmdDataBufferBase l_data(64);
    ecmdDataBufferBase l_ecc(64);
    ecmdDataBufferBase l_65th(64);
    uint32_t loop = 0;

    //----------------------------------------------------
    // Load the data: 16 loops x 64bits = 128B cacheline
    //----------------------------------------------------
    FAPI_INF("Load the data: 16 loops x 64bits = 128B cacheline");
        
    // Set bit 9 so that hw will generate the fabric ECC.
    // This is an 8B ECC protecting the data moving on internal buses in 
    // the Centaur.
    l_ecmd_rc |= l_ecc.flushTo0();    
    l_ecmd_rc |= l_ecc.setBit(9);
    
    for(loop=0; loop<16; loop++ )
    {
        // A write to MAINT_BUFFx_DATAy will not update until the corresponding 
        // MAINT_BUFFx_DATA_ECCy is written to.
        l_ecmd_rc |= l_data.insert(maintBufferData[loop][0], 0, 32, 0);
        l_ecmd_rc |= l_data.insert(maintBufferData[loop][1], 32, 32, 0);
        if(l_ecmd_rc)
        {
            l_rc.setEcmdError(l_ecmd_rc);
            return l_rc;
        }                                                                              
        l_rc = fapiPutScom(iv_targetCentaur, maintBufferDataRegs[iv_mbaPosition][loop][0], l_data); 
        if(l_rc) return l_rc;   
        
        l_rc = fapiPutScom(iv_targetCentaur, maintBufferDataRegs[iv_mbaPosition][loop][1], l_ecc); 
        if(l_rc) return l_rc;   
    }
    
    //----------------------------------------------------
    // Load the 65th byte: 4 loops to fill in the two 65th bytes in cacheline  
    //----------------------------------------------------
    FAPI_INF("Load the 65th byte: 4 loops to fill in the two 65th bytes in the cacheline");
    
    // For now, just use all 0's
    l_ecmd_rc |= l_65th.flushTo0();    
    
    // Set bit 56 so that hw will generate the fabric ECC.
    // This is an 8B ECC protecting the data moving on internal buses in Centaur.
    l_ecmd_rc |= l_65th.setBit(56);
    if(l_ecmd_rc)
    {
        l_rc.setEcmdError(l_ecmd_rc);
        return l_rc;
    }                                                                              

        
    for(loop=0; loop<4; loop++ )
    {
        l_rc = fapiPutScom(iv_targetCentaur, maintBuffer65thRegs[loop][iv_mbaPosition], l_65th); 
        if(l_rc) return l_rc;   
    }

    
    if (i_initPattern == PATTERN_1)
    {
        FAPI_INF("loading PATTERN_1");        
    }
    
    
    FAPI_INF("EXIT mss_MaintCmd::loadPattern()");        

    return l_rc;
}

//---------------------------------------------------------
// mss_loadSpeed
//---------------------------------------------------------
fapi::ReturnCode mss_MaintCmd::loadSpeed(TimeBaseSpeed i_speed)
{

    FAPI_INF("ENTER mss_MaintCmd::loadSpeed()");        

    fapi::ReturnCode l_rc;
    uint32_t l_ecmd_rc = 0;                
    ecmdDataBufferBase l_data(64);
    
    // burst_window_sel
    // MBMCTQ[6]: 0 = 512 Maint Clks
    //            1 = 536870912 Maint Clks
    uint8_t l_burst_window_sel = 0;
    
    // timebase_sel
    // MBMCTQ[9:10]: 00 = 1 Maint Clk
    //               01 = 8192 Maint clks
    uint8_t l_timebase_sel = 0;
    
    // timebase_burst_sel
    // MBMCTQ[11]: 0 = disable burst mode
    //             1 = enable burst mode
    uint8_t l_timebase_burst_sel = 0;
    
    // timebase_interval
    // MBMCTQ[12:23]: The operation interval for timebase operations
    //                equals the timebase_sel x MBMCTQ[12:23].
    // NOTE: Should never be 0, or will hang mainline traffic.
    uint32_t l_timebase_interval = 1;
    
    // burst_window
    // MBMCTQ[24:31]: The burst window for timebase operations with burst mode
    //                enabled equals burst_window_sel x MBMCTQ[24:31]
    uint8_t l_burst_window = 0;

    // burst_interval
    // MBMCTQ[32:39]: The burst interval for timebase operations with burst mode
    //                enabled equals the number of burst windows that will have
    //                no operations occurring in them.
    uint8_t l_burst_interval = 0;

    l_rc = fapiGetScom(iv_target, MBA01_MBMCTQ_0x0301060A, l_data); 
    if(l_rc) return l_rc;
    

    // FAST_AS_POSSIBLE
    if (i_speed == FAST_AS_POSSIBLE)
    {
        // TODO: Need to figure out what fastest possible setting is.
        l_burst_window_sel = 0;
        l_timebase_sel = 0;
        l_timebase_burst_sel = 0;
        l_timebase_interval = 32;
        l_burst_window = 0;
        l_burst_interval = 0;
    }
    // SLOW_12H
    else
    {
        // TODO: Need to figure out setting are for 12H cycle.
        l_burst_window_sel = 0;
        l_timebase_sel = 0;
        l_timebase_burst_sel = 0;
        l_timebase_interval = 512;
        l_burst_window = 0;
        l_burst_interval = 0;
    }
    
    
    // burst_window_sel
    // MBMCTQ[6]
    l_ecmd_rc |= l_data.insert( l_burst_window_sel, 6, 1, 8-1 );
    
    // timebase_sel
    // MBMCTQ[9:10]
    l_ecmd_rc |= l_data.insert( l_timebase_sel, 9, 2, 8-2 );
    
    // timebase_burst_sel
    // MBMCTQ[11]
    l_ecmd_rc |= l_data.insert( l_timebase_burst_sel, 11, 1, 8-1 );

    // timebase_interval
    // MBMCTQ[12:23]
    l_ecmd_rc |= l_data.insert( l_timebase_interval, 12, 12, 32-12 ); 
    
    // burst_window
    // MBMCTQ[24:31]
    l_ecmd_rc |= l_data.insert( l_burst_window, 24, 8, 8-8 ); 

    // burst_interval
    // MBMCTQ[32:39]
    l_ecmd_rc |= l_data.insert( l_burst_interval, 32, 8, 8-8 ); 

    if(l_ecmd_rc)
    {
        l_rc.setEcmdError(l_ecmd_rc);
        return l_rc;
    }

    l_rc = fapiPutScom(iv_target, MBA01_MBMCTQ_0x0301060A, l_data);
    if(l_rc) return l_rc;

    FAPI_INF("EXIT mss_MaintCmd::loadSpeed()");        

    return l_rc;
}


//---------------------------------------------------------
// mss_setupAndExecuteCmd
//---------------------------------------------------------
fapi::ReturnCode mss_MaintCmd::setupAndExecuteCmd()
{

    FAPI_INF("ENTER mss_MaintCmd::setupAndExecuteCmd()");        
    fapi::ReturnCode l_rc;
    FAPI_INF("EXIT mss_MaintCmd::setupAndExecuteCmd()");        

    return l_rc;
}









//------------------------------------------------------------------------------
// Child classes
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// SuperFastInit
//------------------------------------------------------------------------------


const mss_MaintCmd::CmdType mss_SuperFastInit::cv_cmdType = SUPERFAST_INIT;

//---------------------------------------------------------
// mss_SuperFastInit Constructor
//---------------------------------------------------------
mss_SuperFastInit::mss_SuperFastInit( const fapi::Target & i_target,
                                      const ecmdDataBufferBase & i_startAddr,
                                      const ecmdDataBufferBase & i_endAddr,
                                      PatternIndex i_initPattern,
                                      StopCondition i_stopCondition,
                                      bool i_poll ) :
    mss_MaintCmd( i_target,
                  i_startAddr,
                  i_endAddr,
                  i_stopCondition,
                  i_poll,
                  cv_cmdType),
    iv_initPattern( i_initPattern ) // NOTE: iv_initPattern is instance 
                                    // variable of SuperFastInit, since not
                                    // needed in parent class
    {}





//---------------------------------------------------------
// mss_SuperFastInit setupAndExecuteCmd
//---------------------------------------------------------
fapi::ReturnCode mss_SuperFastInit::setupAndExecuteCmd()
{
    

    FAPI_INF("ENTER mss_SuperFastInit::setupAndExecuteCmd()"); 

        
    fapi::ReturnCode l_rc;
    ecmdDataBufferBase l_data(64);
    
    // Gather data that needs to be stored. For testing purposes we will just 
    // set an abitrary number.
    //l_rc = setSavedData( 0xdeadbeef ); if(l_rc) return l_rc;
    //printf( "Saved data: 0x%08x\n", getSavedData() );
    

    // Make sure maint logic in valid state to run new cmd
    l_rc = preConditionCheck(); if(l_rc) return l_rc;
   
    // Load pattern
    l_rc = loadPattern(iv_initPattern); if(l_rc) return l_rc;

    // Load cmd type: MBMCTQ
    l_rc = loadCmdType(); if(l_rc) return l_rc;    
    
    // Load start address: MBMACAQ
    l_rc = loadStartAddress(); if(l_rc) return l_rc;    

    // Load end address: MBMEAQ
    l_rc = loadEndAddress(); if(l_rc) return l_rc;    
    

    // Load stop conditions: MBASCTLQ
    l_rc = loadStopCondMask(); if(l_rc) return l_rc;

    // Start the command: MBMCCQ
    l_rc = startMaintCmd(); if(l_rc) return l_rc;
    
    // Check for early problems with maint cmd instead of waiting for 
    // cmd timeout
    l_rc = postConditionCheck(); if(l_rc) return l_rc;
        
    if(iv_poll == false)
    {
        FAPI_INF("Cmd has started. Use attentions to detect cmd complete.");
        return l_rc;
    }

    // Poll for command complete: MBMSRQ
    l_rc = pollForMaintCmdComplete(); if(l_rc) return l_rc;
    
    // Collect FFDC
    l_rc = collectFFDC(); if(l_rc) return l_rc;

    FAPI_INF("EXIT mss_SuperFastInit::setupAndExecuteCmd()");            

    return l_rc;
}




fapi::ReturnCode mss_SuperFastInit::stopCmd()
{

    FAPI_INF("ENTER mss_SuperFastInit::stopCmd()");            
    
    fapi::ReturnCode l_rc;

    // Stop the maintenace command if it is running.

    // Update the iv_startAddr to the addr the maintenenance command 
    // stopped on. For testing purposes we will just set an abitrary number.
    //iv_startAddr = 0x0000dead0000beefll;
    //printf( "addr stopped on: 0x%016llx\n", iv_startAddr );

    FAPI_INF("EXIT mss_SuperFastInit::stopCmd()");            
    
    return l_rc;
}

fapi::ReturnCode mss_SuperFastInit::cleanupCmd()
{

    FAPI_INF("ENTER mss_SuperFastInit::cleanupCmd()");            
        
    fapi::ReturnCode l_rc;

    // Clear maintenance command complete attention, scrub stats, etc...

    // Restore the saved data.

    FAPI_INF("EXIT mss_SuperFastInit::cleanupCmd()");            
    
    return l_rc;
}


//------------------------------------------------------------------------------
// mss_SuperFastRandomInit
//------------------------------------------------------------------------------


const mss_MaintCmd::CmdType mss_SuperFastRandomInit::cv_cmdType = SUPERFAST_RANDOM_INIT;

//---------------------------------------------------------
// mss_SuperFastInit Constructor
//---------------------------------------------------------
mss_SuperFastRandomInit::mss_SuperFastRandomInit( const fapi::Target & i_target,
                                                  const ecmdDataBufferBase & i_startAddr,
                                                  const ecmdDataBufferBase & i_endAddr,
                                                  PatternIndex i_initPattern,
                                                  StopCondition i_stopCondition,
                                                  bool i_poll ) :
    mss_MaintCmd( i_target,
                  i_startAddr,
                  i_endAddr,
                  i_stopCondition,
                  i_poll,
                  cv_cmdType),
    iv_initPattern( i_initPattern ) 
    {}





//---------------------------------------------------------
// mss_SuperFastRandomInit setupAndExecuteCmd
//---------------------------------------------------------
fapi::ReturnCode mss_SuperFastRandomInit::setupAndExecuteCmd()
{


    FAPI_INF("ENTER mss_SuperFastRandomInit::setupAndExecuteCmd()");            

            
    fapi::ReturnCode l_rc;
    uint32_t l_ecmd_rc = 0;
    
    // Gather data that needs to be stored. For testing purposes we will just 
    // set an abitrary number.
    //l_rc = setSavedData( 0xdeadbeef ); if(l_rc) return l_rc;
    //printf( "Saved data: 0x%08x\n", getSavedData() );
    

    // Make sure maint logic in valid state to run new cmd
    l_rc = preConditionCheck(); if(l_rc) return l_rc;       

    // Load pattern
    l_rc = loadPattern(iv_initPattern); if(l_rc) return l_rc;

    // Load cmd type: MBMCTQ
    l_rc = loadCmdType(); if(l_rc) return l_rc;    
    
    // Load start address: MBMACAQ
    l_rc = loadStartAddress(); if(l_rc) return l_rc;    

    // Load end address: MBMEAQ
    l_rc = loadEndAddress(); if(l_rc) return l_rc;    
    
    // Load stop conditions: MBASCTLQ
    l_rc = loadStopCondMask(); if(l_rc) return l_rc;

    // Disable 8B ECC check/correct on WRD data bus: MBA_WRD_MODE(0:1) = 11
    // before a SuperFastRandomInit command is issued
    l_rc = fapiGetScom(iv_target, MBA01_MBA_WRD_MODE_0x03010429, iv_saved_MBA_WRD_MODE);
    if(l_rc) return l_rc;
    
    ecmdDataBufferBase l_data(64);
    l_ecmd_rc |= l_data.insert(iv_saved_MBA_WRD_MODE, 0, 64, 0);
    l_ecmd_rc |= l_data.setBit(0);
    l_ecmd_rc |= l_data.setBit(1);
    if(l_ecmd_rc)
    {
        l_rc.setEcmdError(l_ecmd_rc);
        return l_rc;
    }                                                                              
    l_rc = fapiPutScom(iv_target, MBA01_MBA_WRD_MODE_0x03010429, l_data);
    if(l_rc) return l_rc;

    // Start the command: MBMCCQ
    l_rc = startMaintCmd(); if(l_rc) return l_rc;
    
    // Check for early problems with maint cmd instead of waiting for 
    //cmd timeout
    l_rc = postConditionCheck(); if(l_rc) return l_rc;
      
    if(iv_poll == false)
    {
        FAPI_INF("Cmd has started. Use attentions to detect cmd complete.");
        return l_rc;
    }

    // Poll for command complete: MBMSRQ
    l_rc = pollForMaintCmdComplete(); if(l_rc) return l_rc;
    
    // Collect FFDC
    l_rc = collectFFDC(); if(l_rc) return l_rc;
    
    FAPI_INF("EXIT mss_SuperFastRandomInit::setupAndExecuteCmd()");            
        
    return l_rc;
}




fapi::ReturnCode mss_SuperFastRandomInit::stopCmd()
{

    FAPI_INF("ENTER mss_SuperFastRandomInit::stopCmd()");                

    fapi::ReturnCode l_rc;

    // Stop the maintenace command if it is running.

    // Update the iv_startAddr to the addr the maintenenance command 
    // stopped on. For testing purposes we will just set an abitrary number.
    //iv_startAddr = 0x0000dead0000beefll;
    //printf( "addr stopped on: 0x%016llx\n", iv_startAddr );

    FAPI_INF("EXIT mss_SuperFastRandomInit::stopCmd()");                
    
    return l_rc;
}

fapi::ReturnCode mss_SuperFastRandomInit::cleanupCmd()
{

    FAPI_INF("ENTER mss_SuperFastRandomInit::cleanupCmd()");                    
    
    fapi::ReturnCode l_rc;

    // Clear maintenance command complete attention, scrub stats, etc...

    // Restore MBA_WRD_MODE
    l_rc = fapiPutScom(iv_target, MBA01_MBA_WRD_MODE_0x03010429, iv_saved_MBA_WRD_MODE);
    if(l_rc) return l_rc;

    FAPI_INF("EXIT mss_SuperFastRandomInit::cleanupCmd()");                    
    
    return l_rc;
}



//------------------------------------------------------------------------------
// mss_SuperFastRead
//------------------------------------------------------------------------------

const mss_MaintCmd::CmdType mss_SuperFastRead::cv_cmdType = SUPERFAST_READ;

//---------------------------------------------------------
// mss_SuperFastRead Constructor
//---------------------------------------------------------

mss_SuperFastRead::mss_SuperFastRead( const fapi::Target & i_target,
                                      const ecmdDataBufferBase & i_startAddr,
                                      const ecmdDataBufferBase & i_endAddr,
                                      StopCondition i_stopCondition,
                                      bool i_poll ) :
    mss_MaintCmd( i_target,
                  i_startAddr,
                  i_endAddr,
                  i_stopCondition,
                  i_poll,
                  cv_cmdType){}

//---------------------------------------------------------
// mss_SuperReadInit setupAndExecuteCmd
//---------------------------------------------------------

fapi::ReturnCode mss_SuperFastRead::setupAndExecuteCmd()
{
    FAPI_INF("ENTER mss_SuperFastRead::setupAndExecuteCmd()");                    
        
    fapi::ReturnCode l_rc;
    
    // Gather data that needs to be stored. For testing purposes we will just 
    // set an abitrary number.
    //l_rc = setSavedData( 0xdeadbeef ); if(l_rc) return l_rc;
    //printf( "Saved data: 0x%08x\n", getSavedData() );

    // Make sure maint logic in valid state to run new cmd
    l_rc = preConditionCheck(); if(l_rc) return l_rc;
              
    // Load cmd type: MBMCTQ
    l_rc = loadCmdType(); if(l_rc) return l_rc;    
      
    // Load start address: MBMACAQ
    l_rc = loadStartAddress(); if(l_rc) return l_rc;    

    // Load end address: MBMEAQ
    l_rc = loadEndAddress(); if(l_rc) return l_rc;    
    
    // Load stop conditions: MBASCTLQ
    l_rc = loadStopCondMask(); if(l_rc) return l_rc;
    
    /*
    // DEBUG. Set hard CE threshold to 1: MBSTRQ
    FAPI_INF("\nDEBUG. Set hard CE threshold to 1: MBSTRQ");
    ecmdDataBufferBase l_data(64);
    uint32_t l_hardCEThreshold = 1;
    l_rc = fapiGetScom(iv_target, MBS01_MBSTRQ_0x02011655, l_data);
    if(l_rc) return l_rc;
    l_data.insert( l_hardCEThreshold, 28, 12, 32-12 ); // 28:39 hard ce threshold
    l_data.setBit(2);   // Enable hard ce ETE special attention
    l_data.setBit(57);  // Enable per-symbol counters to count hard ces
    l_rc = fapiPutScom(iv_target, MBS01_MBSTRQ_0x02011655, l_data);
    if(l_rc) return l_rc;
    */

    // Start the command: MBMCCQ
    l_rc = startMaintCmd(); if(l_rc) return l_rc;
        
    // Check for early problems with maint cmd instead of waiting for 
    // cmd timeout
    l_rc = postConditionCheck(); if(l_rc) return l_rc;

    if(iv_poll == false)
    {
        FAPI_INF("Cmd has started. Use attentions to detect cmd complete.");
        return l_rc;
    }

    // Poll for command complete: MBMSRQ
    l_rc = pollForMaintCmdComplete(); if(l_rc) return l_rc;
    
    // Collect FFDC
    l_rc = collectFFDC(); if(l_rc) return l_rc;    

    FAPI_INF("EXIT mss_SuperFastRead::setupAndExecuteCmd()");                    
    
    return l_rc;

}

fapi::ReturnCode mss_SuperFastRead::stopCmd()
{

    FAPI_INF("ENTER mss_SuperFastRead::stopCmd()");                        
    
    fapi::ReturnCode l_rc;

    // Stop the maintenace command if it is running.

    // Update the iv_startAddr to the addr the maintenenance command 
    // stopped on. For testing purposes we will just set an abitrary number.
    //iv_startAddr = 0x0000dead0000beefll;
    //printf( "addr stopped on: 0x%016llx\n", iv_startAddr );

    FAPI_INF("EXIT mss_SuperFastRead::stopCmd()");                        
    
    return l_rc;
}

fapi::ReturnCode mss_SuperFastRead::cleanupCmd()
{

    FAPI_INF("ENTER mss_SuperFastRead::cleanupCmd()");                        
    
    fapi::ReturnCode l_rc;
       
    // Clear maintenance command complete attention, scrub stats, etc...

    // Restore the saved data.
    //printf( "Saved data: 0x%08x\n", getSavedData() );

    FAPI_INF("EXIT mss_SuperFastRead::cleanupCmd()");                        
    
    return l_rc;
}



//------------------------------------------------------------------------------
// AtomicInject
//------------------------------------------------------------------------------

const mss_MaintCmd::CmdType mss_AtomicInject::cv_cmdType = ATOMIC_ALTER_ERROR_INJECT;

//---------------------------------------------------------
// AtomicInject Constructor
//---------------------------------------------------------

mss_AtomicInject::mss_AtomicInject( const fapi::Target & i_target,
                                    const ecmdDataBufferBase & i_startAddr,
                                    InjectType i_injectType ) :
    mss_MaintCmd( i_target,
                  i_startAddr,
                  ecmdDataBufferBase(64),   // i_endAddr not used for this cmd
                  NO_STOP_CONDITIONS,   // i_stopCondition not used for this cmd
                  true,                     // i_poll always true for this cmd
                  cv_cmdType),
                                          
     iv_injectType( i_injectType ) // NOTE: iv_injectType is instance variable
                                   // of AtomicInject, since not needed
                                   // in parent class
    {}


//---------------------------------------------------------
// mss_AtomicInject setupAndExecuteCmd
//---------------------------------------------------------

fapi::ReturnCode mss_AtomicInject::setupAndExecuteCmd()
{
    FAPI_INF("ENTER mss_AtomicInject::setupAndExecuteCmd()");                            
       
    fapi::ReturnCode l_rc;
    uint32_t l_ecmd_rc = 0;    
    
    // Gather data that needs to be stored. For testing purposes we will just 
    // set an abitrary number.
    //l_rc = setSavedData( 0xdeadbeef ); if(l_rc) return l_rc;
    //printf( "Saved data: 0x%08x\n", getSavedData() );

    // Make sure maint logic in valid state to run new cmd
    l_rc = preConditionCheck(); if(l_rc) return l_rc;
   
    // Load cmd type: MBMCTQ
    l_rc = loadCmdType(); if(l_rc) return l_rc;    
    
    // Load start address: MBMACAQ
    l_rc = loadStartAddress(); if(l_rc) return l_rc;    
  
    // Load inject type: MBECTLQ
    ecmdDataBufferBase l_injectType(64);
    l_rc = fapiGetScom(iv_target, MBA01_MBECTLQ_0x03010610, l_injectType);
    if(l_rc) return l_rc;
    l_ecmd_rc |= l_injectType.flushTo0();
    l_ecmd_rc |= l_injectType.setBit(iv_injectType);
    if(l_ecmd_rc)
    {
        l_rc.setEcmdError(l_ecmd_rc);
        return l_rc;
    }                                                                              
    l_rc = fapiPutScom(iv_target, MBA01_MBECTLQ_0x03010610, l_injectType);
    if(l_rc) return l_rc;

    // Start the command: MBMCCQ
    l_rc = startMaintCmd(); if(l_rc) return l_rc;
        
    // Check for early problems with maint cmd instead of waiting for
    // cmd timeout
    l_rc = postConditionCheck(); if(l_rc) return l_rc;

    // Poll for command complete: MBMSRQ
    l_rc = pollForMaintCmdComplete(); if(l_rc) return l_rc;
    
    // Collect FFDC
    l_rc = collectFFDC(); if(l_rc) return l_rc;
    
    // Clear MBECCFIR
    ecmdDataBufferBase l_data(64);
    l_ecmd_rc |= l_data.flushTo0();
    if(l_ecmd_rc)
    {
        l_rc.setEcmdError(l_ecmd_rc);
        return l_rc;
    }                                                                              
         
    l_rc = fapiPutScom(iv_targetCentaur, mss_mbeccfir[iv_mbaPosition], l_data);
    if(l_rc) return l_rc;

    FAPI_INF("EXIT mss_AtomicInject::setupAndExecuteCmd()");                            

        
    return l_rc;

}

fapi::ReturnCode mss_AtomicInject::stopCmd()
{

    FAPI_INF("ENTER mss_AtomicInject::stopCmd()");                                
    fapi::ReturnCode l_rc;
    FAPI_INF("EXIT mss_AtomicInject::stopCmd()");                                
    
    return l_rc;
}




//------------------------------------------------------------------------------
// Display
//------------------------------------------------------------------------------

const mss_MaintCmd::CmdType mss_Display::cv_cmdType = MEMORY_DISPLAY;

//---------------------------------------------------------
// Display Constructor
//---------------------------------------------------------

mss_Display::mss_Display( const fapi::Target & i_target,
                          const ecmdDataBufferBase & i_startAddr) :
    mss_MaintCmd( i_target,
                  i_startAddr,
                  ecmdDataBufferBase(64),    // i_endAddr not used for this cmd
                  NO_STOP_CONDITIONS,   // i_stopCondition not used for this cmd
                  true,                      // i_poll always true for this cmd
                  cv_cmdType){}
              

//---------------------------------------------------------
// mss_Display setupAndExecuteCmd
//---------------------------------------------------------

fapi::ReturnCode mss_Display::setupAndExecuteCmd()
{
    FAPI_INF("ENTER mss_Display::setupAndExecuteCmd()");                                        
       
    fapi::ReturnCode l_rc;
    
    // Gather data that needs to be stored. For testing purposes we will just 
    // set an abitrary number.
    //l_rc = setSavedData( 0xdeadbeef ); if(l_rc) return l_rc;
    //printf( "Saved data: 0x%08x\n", getSavedData() );

    // Make sure maint logic in valid state to run new cmd
    l_rc = preConditionCheck(); if(l_rc) return l_rc;
   
    // Load cmd type: MBMCTQ
    l_rc = loadCmdType(); if(l_rc) return l_rc;    
    
    // Load start address: MBMACAQ
    l_rc = loadStartAddress(); if(l_rc) return l_rc;    
    
    // Start the command: MBMCCQ
    l_rc = startMaintCmd(); if(l_rc) return l_rc;
        
    // Check for early problems with maint cmd instead of waiting for
    // cmd timeout
    l_rc = postConditionCheck(); if(l_rc) return l_rc;

    if(iv_poll == false)
    {
        FAPI_INF("Cmd has started. Use attentions to detect cmd complete.");
        return l_rc;
    }

    // Poll for command complete: MBMSRQ
    l_rc = pollForMaintCmdComplete(); if(l_rc) return l_rc;
    
    // Read the data from the display cmd: MBMSRQ
    
    static const uint32_t maintBufferReadDataRegs[16]={
      MAINT0_MBA_MAINT_BUFF0_DATA0_0x03010655,
      MAINT0_MBA_MAINT_BUFF0_DATA1_0x03010656,
      MAINT0_MBA_MAINT_BUFF0_DATA2_0x03010657,
      MAINT0_MBA_MAINT_BUFF0_DATA3_0x03010658,
      
      MAINT0_MBA_MAINT_BUFF1_DATA0_0x03010665,
      MAINT0_MBA_MAINT_BUFF1_DATA1_0x03010666,
      MAINT0_MBA_MAINT_BUFF1_DATA2_0x03010667,
      MAINT0_MBA_MAINT_BUFF1_DATA3_0x03010668,
      
      MAINT0_MBA_MAINT_BUFF2_DATA0_0x03010675,
      MAINT0_MBA_MAINT_BUFF2_DATA1_0x03010676,
      MAINT0_MBA_MAINT_BUFF2_DATA2_0x03010677,
      MAINT0_MBA_MAINT_BUFF2_DATA3_0x03010678,
      
      MAINT0_MBA_MAINT_BUFF3_DATA0_0x03010685,
      MAINT0_MBA_MAINT_BUFF3_DATA1_0x03010686,
      MAINT0_MBA_MAINT_BUFF3_DATA2_0x03010687,
      MAINT0_MBA_MAINT_BUFF3_DATA3_0x03010688};

    uint32_t loop = 0;
    ecmdDataBufferBase l_data(64);
   
    //----------------------------------------------------
    // Read the data: 16 loops x 64bits = 128B cacheline
    //----------------------------------------------------
    FAPI_INF("Read the data: 16 loops x 64bits = 128B cacheline");
        
    for(loop=0; loop<16; loop++ )
    {
        l_rc = fapiGetScom(iv_target, maintBufferReadDataRegs[loop], l_data);
        if(l_rc) return l_rc;
    }
 
    // Collect FFDC
    l_rc = collectFFDC(); if(l_rc) return l_rc;
    
    // Clear MBECCFIR
    l_data.flushTo0();         
    l_rc = fapiPutScom(iv_targetCentaur, mss_mbeccfir[iv_mbaPosition], l_data);
    if(l_rc) return l_rc;

    FAPI_INF("EXIT Display::setupAndExecuteCmd()");                                        
        
    return l_rc;

}

fapi::ReturnCode mss_Display::stopCmd()
{

    FAPI_INF("ENTER mss_Display::stopCmd()"); 
    fapi::ReturnCode l_rc;
    FAPI_INF("EXIT mss_Display::stopCmd()"); 
    
    return l_rc;
}



//------------------------------------------------------------------------------
// Increment MBMACA Address
//------------------------------------------------------------------------------

const mss_MaintCmd::CmdType mss_IncrementAddress::cv_cmdType = INCREMENT_MBMACA_ADDRESS;

//---------------------------------------------------------
// IncrementAddress Constructor
//---------------------------------------------------------

mss_IncrementAddress::mss_IncrementAddress( const fapi::Target & i_target ):
    
    mss_MaintCmd( i_target,
                  ecmdDataBufferBase(64),  // i_startAddr not used for this cmd
                  ecmdDataBufferBase(64),  // i_endAddr not used for this cmd
                  NO_STOP_CONDITIONS,   // i_stopCondition not used for this cmd
                  true,                    // i_poll always true for this cmd
                  cv_cmdType){}

//---------------------------------------------------------
// mss_IncrementAddress setupAndExecuteCmd
//---------------------------------------------------------

fapi::ReturnCode mss_IncrementAddress::setupAndExecuteCmd()
{


    FAPI_INF("ENTER mss_IncrementAddress::setupAndExecuteCmd()");                                        

        
    fapi::ReturnCode l_rc;
    
    // Make sure maint logic in valid state to run new cmd
    l_rc = preConditionCheck(); if(l_rc) return l_rc;
   
    // Load cmd type: MBMCTQ
    l_rc = loadCmdType(); if(l_rc) return l_rc;    
    
    // Read start address: MBMACAQ
    ecmdDataBufferBase l_mbmacaq(64);
    l_rc = fapiGetScom(iv_target, MBA01_MBMACAQ_0x0301060D, l_mbmacaq); 
    if(l_rc) return l_rc;
    FAPI_INF("MBMACAQ = 0x%.8X 0x%.8X", l_mbmacaq.getWord(0), l_mbmacaq.getWord(1));
  
    // Start the command: MBMCCQ
    l_rc = startMaintCmd(); if(l_rc) return l_rc;
        
    // Check for early problems with maint cmd instead of waiting for 
    // cmd timeout
    l_rc = postConditionCheck(); if(l_rc) return l_rc;

    // Poll for command complete: MBMSRQ
    l_rc = pollForMaintCmdComplete(); if(l_rc) return l_rc;
       
    // Read incremented start address: MBMACAQ
    l_rc = fapiGetScom(iv_target, MBA01_MBMACAQ_0x0301060D, l_mbmacaq);
    if(l_rc) return l_rc;

    // Collect FFDC
    l_rc = collectFFDC(); if(l_rc) return l_rc;

    FAPI_INF("EXIT mss_IncrementAddress::setupAndExecuteCmd()");                                        
        
    return l_rc;
}


fapi::ReturnCode mss_IncrementAddress::stopCmd()
{

    FAPI_INF("ENTER mss_IncrementAddress::stopCmd()"); 
    fapi::ReturnCode l_rc;
    FAPI_INF("EXIT mss_IncrementAddress::stopCmd()"); 
    
    return l_rc;
}


//------------------------------------------------------------------------------
// mss_TimeBaseScrub
//------------------------------------------------------------------------------

const mss_MaintCmd::CmdType mss_TimeBaseScrub::cv_cmdType = TIMEBASE_SCRUB;

//---------------------------------------------------------
// mss_TimeBaseScrub Constructor
//---------------------------------------------------------

mss_TimeBaseScrub::mss_TimeBaseScrub( const fapi::Target & i_target,
                                      const ecmdDataBufferBase & i_startAddr,
                                      const ecmdDataBufferBase & i_endAddr,
                                      TimeBaseSpeed i_speed,             
                                      StopCondition i_stopCondition,
                                      bool i_poll ) :
    mss_MaintCmd( i_target,
                  i_startAddr,
                  i_endAddr,
                  i_stopCondition,
                  i_poll,
                  cv_cmdType),

    // NOTE: iv_speed is instance variable of TimeBaseScrub, since not 
    // needed in parent class
    iv_speed( i_speed ) 
    {}



//---------------------------------------------------------
// mss_TimeBaseScrub setupAndExecuteCmd
//---------------------------------------------------------

fapi::ReturnCode mss_TimeBaseScrub::setupAndExecuteCmd()
{
    FAPI_INF("ENTER mss_TimeBaseScrub::setupAndExecuteCmd()");                    
        
    fapi::ReturnCode l_rc;
    
    // Gather data that needs to be stored. For testing purposes we will just 
    // set an abitrary number.
    //l_rc = setSavedData( 0xdeadbeef ); if(l_rc) return l_rc;
    //printf( "Saved data: 0x%08x\n", getSavedData() );

    // Make sure maint logic in valid state to run new cmd
    l_rc = preConditionCheck(); if(l_rc) return l_rc;
              
    // Load cmd type: MBMCTQ
    l_rc = loadCmdType(); if(l_rc) return l_rc;    
      
    // Load start address: MBMACAQ
    l_rc = loadStartAddress(); if(l_rc) return l_rc;    

    // Load end address: MBMEAQ
    l_rc = loadEndAddress(); if(l_rc) return l_rc; 
    
    // Load speed: MBMCTQ
    l_rc = loadSpeed(iv_speed); if(l_rc) return l_rc;   
    
    // Load stop conditions: MBASCTLQ
    l_rc = loadStopCondMask(); if(l_rc) return l_rc;
    
    /*
    // DEBUG. Set hard CE threshold to 1: MBSTRQ
    FAPI_INF("\nDEBUG. Set hard CE threshold to 1: MBSTRQ");
    ecmdDataBufferBase l_data(64);
    uint32_t l_hardCEThreshold = 1;
    l_rc = fapiGetScom(iv_target, MBS01_MBSTRQ_0x02011655, l_data); 
    if(l_rc) return l_rc;
    l_data.insert( l_hardCEThreshold, 28, 12, 32-12 ); // 28:39 hard ce threshold
    l_data.setBit(2);   // Enable hard ce ETE special attention
    l_data.setBit(57);  // Enable per-symbol counters to count hard ces
    l_rc = fapiPutScom(iv_target, MBS01_MBSTRQ_0x02011655, l_data); 
    if(l_rc) return l_rc;
    */

    // Start the command: MBMCCQ
    l_rc = startMaintCmd(); if(l_rc) return l_rc;
        
    // Check for early problems with maint cmd instead of waiting for 
    // cmd timeout
    l_rc = postConditionCheck(); if(l_rc) return l_rc;

    if(iv_poll == false)
    {
        FAPI_INF("Cmd has started. Use attentions to detect cmd complete.");
        return l_rc;
    }

    // Poll for command complete: MBMSRQ
    l_rc = pollForMaintCmdComplete(); if(l_rc) return l_rc;
    
    // Collect FFDC
    l_rc = collectFFDC(); if(l_rc) return l_rc;    

    FAPI_INF("EXIT mss_TimeBaseScrub::setupAndExecuteCmd()");                    
    
    return l_rc;

}

fapi::ReturnCode mss_TimeBaseScrub::stopCmd()
{

    FAPI_INF("ENTER mss_TimeBaseScrub::stopCmd()");                        
    
    fapi::ReturnCode l_rc;

    // Stop the maintenace command if it is running.

    // Update the iv_startAddr to the addr the maintenenance command 
    // stopped on. For testing purposes we will just set an abitrary number.
    //iv_startAddr = 0x0000dead0000beefll;
    //printf( "addr stopped on: 0x%016llx\n", iv_startAddr );

    FAPI_INF("EXIT mss_TimeBaseScrub::stopCmd()");                        
    
    return l_rc;
}

fapi::ReturnCode mss_TimeBaseScrub::cleanupCmd()
{

    FAPI_INF("ENTER mss_TimeBaseScrub::cleanupCmd()");                        
    
    fapi::ReturnCode l_rc;
       
    // Clear maintenance command complete attention, scrub stats, etc...

    // Restore the saved data.
    //printf( "Saved data: 0x%08x\n", getSavedData() );

    FAPI_INF("EXIT mss_TimeBaseScrub::cleanupCmd()");                        
    
    return l_rc;
}


//------------------------------------------------------------------------------
// Utility funcitons
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// mss_get_address_range
//------------------------------------------------------------------------------
fapi::ReturnCode mss_get_address_range( const fapi::Target & i_target,
                                        uint8_t i_rank,
                                        ecmdDataBufferBase & o_startAddr,
                                        ecmdDataBufferBase & o_endAddr )
{


    FAPI_INF("ENTER mss_get_address_range()"); 

    
    static const uint8_t memConfigType[9][4][2]={
    
    //       SUBTYPE_A                   SUBTYPE_B                     SUBTYPE_C                     SUBTYPE_D    
    //SLOT_0_ONLY SLOT_0_AND_1    SLOT_0_ONLY SLOT_0_AND_1    SLOT_0_ONLY    SLOT_0_AND_1    SLOT_0_ONLY    SLOT_0_AND_1
    {{0xff,          0xff},        {0xff,        0xff},            {0xff,        0xff},            {0xff,        0xff}},    // TYPE_0
    {{0x00,          0x04},        {0x01,        0x05},            {0x03,        0x07},            {0xff,        0xff}},    // TYPE_1
    {{0xff,          0xff},        {0xff,        0xff},            {0xff,        0xff},            {0xff,        0xff}},    // TYPE_2
    {{0x01,          0x05},        {0x01,        0x05},            {0x01,        0x05},            {0xff,        0xff}},    // TYPE_3
    {{0x03,          0x07},        {0x03,        0x07},            {0x03,        0x07},            {0xff,        0xff}},    // TYPE_4
    {{0x00,          0x04},        {0x01,        0x05},            {0x03,        0x07},            {0x07,        0xff}},    // TYPE_5
    {{0xff,          0xff},        {0xff,        0xff},            {0xff,        0xff},            {0xff,        0xff}},    // TYPE_6
    {{0x01,          0x05},        {0x01,        0x05},            {0x01,        0x05},            {0xff,        0xff}},    // TYPE_7                
    {{0x03,          0x07},        {0x03,        0x07},            {0x03,        0x07},            {0xff,        0xff}}};// TYPE_8

    
    fapi::ReturnCode l_rc;
    uint32_t l_ecmd_rc = 0;            
    ecmdDataBufferBase l_data(64);
    mss_MemConfig::MemOrg l_row;
    mss_MemConfig::MemOrg l_col;
    mss_MemConfig::MemOrg l_bank;
    uint32_t l_dramSize = 0;
    uint32_t l_dramWidth = 0;
    fapi::Target l_targetCentaur;
    uint8_t l_mbaPosition = 0;
    uint8_t l_isSIM = 1;
    
    uint8_t l_slotConfig = 0;
    uint8_t l_configType = 0;
    uint8_t l_configSubType = 0;
    uint8_t l_end_rank = 0;
    
    // Get Centaur target for the given MBA
    l_rc = fapiGetParentChip(i_target, l_targetCentaur); 
    if(l_rc)
    {
        FAPI_ERR("Error getting Centaur parent target for the given MBA");
        return l_rc;
    }
    
    // Get MBA position: 0 = mba01, 1 = mba23    
    l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target, l_mbaPosition);
    if(l_rc)
    {
        FAPI_ERR("Error getting MBA position");
        return l_rc;
    }
    
    // Check system attribute if sim: 1 = Awan/HWSimulator. 0 = Simics/RealHW.
    l_rc = FAPI_ATTR_GET(ATTR_IS_SIMULATION, NULL, l_isSIM);
    if(l_rc)
    {
        FAPI_ERR("Error getting ATTR_IS_SIMULATION");
        return l_rc;
    }
                    
    // Check MBAXCRn, to show memory configured behind this MBA
    l_rc = fapiGetScom(l_targetCentaur, mss_mbaxcr[l_mbaPosition], l_data);
    if(l_rc) return l_rc;
    if (l_data.isBitClear(0,4))
    {
        // Create new log. 
        FAPI_ERR("MBAXCRn[0:3] = 0, meaning no memory configured behind this MBA.");
        // DEBUG
        // FAPI_SET_HWP_ERROR(l_rc, RC_MSS_MAINT_NO_MEM_CNFG);
        return l_rc;
    }
    
    //********************************************************************
    // Find max row/col/bank, based on l_dramSize and l_dramWidth
    //********************************************************************

    // Get l_dramSize and l_dramWidth 
    l_ecmd_rc |= l_data.extractPreserve(&l_dramSize, 6, 2, 32-2);      // (6:7)
    l_ecmd_rc |= l_data.extractPreserve(&l_dramWidth, 9, 1, 32-1);     // (9)
    if(l_ecmd_rc)
    {
        l_rc.setEcmdError(l_ecmd_rc);
        return l_rc;
    }                                                                              

    if((l_dramWidth == mss_MemConfig::X8) && (l_dramSize == mss_MemConfig::GBIT_2)) 
    {
        // For memory part Size = 256Mbx8 (2Gb), row/col/bank = 15/10/3
        FAPI_INF("For memory part Size = 256Mbx8 (2Gb), row/col/bank = 15/10/3");
        l_row =     mss_MemConfig::ROW_15;
        l_col =     mss_MemConfig::COL_10;
        l_bank =    mss_MemConfig::BANK_3;
    }
    else if((l_dramWidth == mss_MemConfig::X4) && (l_dramSize == mss_MemConfig::GBIT_2)) 
    {
        // For memory part Size = 512Mbx4 (2Gb), row/col/bank = 15/11/3
        FAPI_INF("For memory part Size = 512Mbx4 (2Gb), row/col/bank = 15/11/3");
        l_row =     mss_MemConfig::ROW_15;
        l_col =     mss_MemConfig::COL_11;
        l_bank =    mss_MemConfig::BANK_3;
    }
    else if((l_dramWidth == mss_MemConfig::X8) && (l_dramSize == mss_MemConfig::GBIT_4))
    {
        // For memory part Size = 512Mbx8 (4Gb), row/col/bank = 16/10/3
        FAPI_INF("For memory part Size = 512Mbx8 (4Gb), row/col/bank = 16/10/3");           
        l_row =     mss_MemConfig::ROW_16;
        l_col =     mss_MemConfig::COL_10;
        l_bank =    mss_MemConfig::BANK_3;
    }
    else if((l_dramWidth == mss_MemConfig::X4) && (l_dramSize == mss_MemConfig::GBIT_4)) 
    {
        // For memory part Size = 1Gbx4 (4Gb), row/col/bank = 16/11/3
        FAPI_INF("For memory part Size = 1Gbx4 (4Gb), row/col/bank = 16/11/3");           
        l_row =     mss_MemConfig::ROW_16;
        l_col =     mss_MemConfig::COL_11;
        l_bank =     mss_MemConfig::BANK_3;
    }
    else if((l_dramWidth == mss_MemConfig::X8) && (l_dramSize == mss_MemConfig::GBIT_8))
    {
        // For memory part Size = 1Gbx8 (8Gb), row/col/bank = 16/11/3
        FAPI_INF("For memory part Size = 1Gbx8 (8Gb), row/col/bank = 16/11/3");           
        l_row =     mss_MemConfig::ROW_16;
        l_col =     mss_MemConfig::COL_11;
        l_bank =     mss_MemConfig::BANK_3;
    }
    else if((l_dramWidth == mss_MemConfig::X4) && (l_dramSize == mss_MemConfig::GBIT_8))
    {
        // For memory part Size = 2Gbx4 (8Gb), row/col/bank = 16/12/3
        FAPI_INF("For memory part Size = 2Gbx4 (8Gb), row/col/bank = 16/12/3");           
        l_row =     mss_MemConfig::ROW_16;
        l_col =     mss_MemConfig::COL_12;
        l_bank =     mss_MemConfig::BANK_3;
    }
    else
    {
        // Create new log. 
        FAPI_ERR("Invalid l_dramSize = %d or l_dramWidth = %d in MBAXCRn.", l_dramSize, l_dramWidth );
        FAPI_SET_HWP_ERROR(l_rc, RC_MSS_MAINT_INVALID_DRAM_SIZE_WIDTH);
        return l_rc;
    }


    //********************************************************************
    // Find l_end_rank based on DIMM configuration
    //********************************************************************                    

    // (0:3) Configuration type (1-8)
    l_ecmd_rc |= l_data.extractPreserve(&l_configType, 0, 4, 8-4); 
    
    // (4:5) Configuration subtype (A, B, C, D)
    l_ecmd_rc |= l_data.extractPreserve(&l_configSubType, 4, 2, 8-2);
    
    // (8)   Slot Configuration 
    // 0 = Centaur DIMM or IS DIMM, slot0 only, 1 = IS DIMM slots 0 and 1 
    l_ecmd_rc |= l_data.extractPreserve(&l_slotConfig, 8, 1, 8-1); 
    if(l_ecmd_rc)
    {
        l_rc.setEcmdError(l_ecmd_rc);
        return l_rc;
    }                                                                              


    l_end_rank = memConfigType[l_configType][l_configSubType][l_slotConfig];
    
    if (l_end_rank == 0xff)
    {
        // Create new log. 
        FAPI_ERR("MBAXCRn configured with invalid combination of l_configType, l_configSubType, l_slotConfig");
        FAPI_SET_HWP_ERROR(l_rc, RC_MSS_MAINT_INVALID_DIMM_CNFG);
        return l_rc;
    }
           
    //********************************************************************       
    // Get address range for all ranks configured behind this MBA
    //********************************************************************    
    if (i_rank == MSS_ALL_RANKS)
    {
        FAPI_INF("Get address range for rank = ALL_RANKS");
        
        // Start address is just rank 0 with row/col/bank all 0's
        o_startAddr.flushTo0();         
        
        // If Awan/HWSimulator, end address is just start address +3
        if (l_isSIM)
        {
            FAPI_INF("ATTR_IS_SIMULATION = 1, Awan/HWSimulator, so use smaller address range.");
            
            /*
            l_ecmd_rc |= o_endAddr.flushTo0();
            l_ecmd_rc |= o_endAddr.setBit(36);
            l_ecmd_rc |= o_endAddr.setBit(35);
            l_ecmd_rc |= o_endAddr.setBit(34); // DEBUG
            l_ecmd_rc |= o_endAddr.setBit(33); // DEBUG
            l_ecmd_rc |= o_endAddr.setBit(32); // DEBUG
            l_ecmd_rc |= o_endAddr.setBit(31); // DEBUG
            l_ecmd_rc |= o_endAddr.setBit(30); // DEBUG
            */

            // DEBUG - try whole rank0, row0, all banks all cols
            l_end_rank = 0;             
            uint32_t l_row_zero = 0;
            l_ecmd_rc |= o_endAddr.flushTo0();

            // RANK = 0:3          
            l_ecmd_rc |= o_endAddr.insert( l_end_rank, 0, 4, 8-4 );
            
            // BANK = 7:10         
            l_ecmd_rc |= o_endAddr.insert( (uint32_t)l_bank, 7, 4, 32-4 ); 
            
            // ROW = 11:27                    
            l_ecmd_rc |= o_endAddr.insert( (uint32_t)l_row_zero, 11, 17, 32-17 );
            
            // COL = 28:39, note: c2, c1, c0 always 0   
            l_ecmd_rc |= o_endAddr.insert( (uint32_t)l_col, 28, 12, 32-12 );     
            

        }
        // Else, set end address to be last address of l_end_rank
        else
        {
            l_ecmd_rc |= o_endAddr.flushTo0();
                      
            // RANK = 0:3
            l_ecmd_rc |= o_endAddr.insert( l_end_rank, 0, 4, 8-4 );
            
            // BANK = 7:10
            l_ecmd_rc |= o_endAddr.insert( (uint32_t)l_bank, 7, 4, 32-4 );
            
            // ROW = 11:27      
            l_ecmd_rc |= o_endAddr.insert( (uint32_t)l_row, 11, 17, 32-17 );
            
            // COL = 28:39, note: c2, c1, c0 always 0                
            l_ecmd_rc |= o_endAddr.insert( (uint32_t)l_col, 28, 12, 32-12 );    
        }           
    }
    
    //********************************************************************       
    // Get address range for single rank configured behind this MBA
    //********************************************************************    
    else
    {
        FAPI_INF("Get address range for rank = %d\n", i_rank );
           
        // NOTE: If this rank is not valid, we should see MBAFIR[1]: invalid 
        // maint address, when cmd started

        // DEBUG: Set start address to 8 addresses away from end of rank
        //l_ecmd_rc |= o_startAddr.flushTo0();         
        //l_ecmd_rc |= o_startAddr.insert( i_rank, 0, 4, 8-4 );                 
        //l_ecmd_rc |= o_startAddr.insert( (uint32_t)l_bank, 7, 4, 32-4 );      
        //l_ecmd_rc |= o_startAddr.insert( (uint32_t)l_row, 11, 17, 32-17 );    
        //l_ecmd_rc |= o_startAddr.insert( (uint32_t)l_col, 28, 9, 32-9 );      
        //l_ecmd_rc |= o_startAddr.clearBit(32);
        //l_ecmd_rc |= o_startAddr.clearBit(33);
        //l_ecmd_rc |= o_startAddr.clearBit(34);
        //l_ecmd_rc |= o_startAddr.clearBit(35);
        //l_ecmd_rc |= o_startAddr.clearBit(36);

        // Start address is just i_rank with row/col/bank all 0's
        l_ecmd_rc |= o_startAddr.flushTo0();

        // RANK = 0:3         
        l_ecmd_rc |= o_startAddr.insert( i_rank, 0, 4, 8-4 );                   
               
        // If Awan/HWSimulator, end address is just start address +3
        if (l_isSIM)
        {
            FAPI_INF("ATTR_IS_SIMULATION = 1, Awan/HWSimulator, so use smaller address range.");
            uint32_t l_row_zero = 0;
            l_ecmd_rc |= o_endAddr.flushTo0();
            // RANK = 0:3
            l_ecmd_rc |= o_endAddr.insert( i_rank, 0, 4, 8-4 );
            // BANK = 7:10
            l_ecmd_rc |= o_endAddr.insert( (uint32_t)l_bank, 7, 4, 32-4 );
            // ROW = 11:27            
            l_ecmd_rc |= o_endAddr.insert( (uint32_t)l_row_zero, 11, 17, 32-17 );
            // COL = 28:39, note: c2, c1, c0 always 0
            l_ecmd_rc |= o_endAddr.insert( (uint32_t)l_col, 28, 12, 32-12 );
            //l_ecmd_rc |= o_endAddr.setBit(35); // DEBUG
            //l_ecmd_rc |= o_endAddr.setBit(34); // DEBUG
            //l_ecmd_rc |= o_endAddr.setBit(33); // DEBUG
            //l_ecmd_rc |= o_endAddr.setBit(32); // DEBUG
            //l_ecmd_rc |= o_endAddr.setBit(31); // DEBUG
            //l_ecmd_rc |= o_endAddr.setBit(30); // DEBUG

        }
        // Else, set end address to be last address of i_rank
        else
        {
            l_ecmd_rc |= o_endAddr.flushTo0();
            // RANK = 0:3
            l_ecmd_rc |= o_endAddr.insert( i_rank, 0, 4, 8-4 );
            // BANK = 7:10
            l_ecmd_rc |= o_endAddr.insert( (uint32_t)l_bank, 7, 4, 32-4 );
            // ROW = 11:27            
            l_ecmd_rc |= o_endAddr.insert( (uint32_t)l_row, 11, 17, 32-17 );
            // COL = 28:36
            l_ecmd_rc |= o_endAddr.insert( (uint32_t)l_col, 28, 9, 32-9 );
        }           
    }
    
    if(l_ecmd_rc)
    {
        l_rc.setEcmdError(l_ecmd_rc);
        return l_rc;
    }                                                                              

    

    FAPI_INF("EXIT mss_get_address_range()"); 

    return l_rc;
}





//------------------------------------------------------------------------------
// mss_get_mark_store
//------------------------------------------------------------------------------
fapi::ReturnCode mss_get_mark_store( const fapi::Target & i_target,
                                     uint8_t i_rank,
                                     uint8_t & o_symbolMark,
                                     uint8_t & o_chipMark )
{


    FAPI_INF("ENTER mss_get_mark_store()");     

        
    fapi::ReturnCode l_rc;
    uint32_t l_ecmd_rc = 0;
    ecmdDataBufferBase l_markstore(64);
    ecmdDataBufferBase l_mbeccfir(64);
    ecmdDataBufferBase l_data(64);
    uint32_t l_dramWidth = 0;
    uint8_t l_symbolMarkGalois = 0;
    uint8_t l_chipMarkGalois = 0;
    uint8_t l_symbolsPerChip = 4;
    fapi::Target l_targetCentaur;
    uint8_t l_mbaPosition = 0;

    // Get Centaur target for the given MBA
    l_rc = fapiGetParentChip(i_target, l_targetCentaur);
    if(l_rc)
    {
        FAPI_ERR("Error getting Centaur parent target for the given MBA");
        return l_rc;
    }

    
    // Get MBA position: 0 = mba01, 1 = mba23
    l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target, l_mbaPosition);
    if(l_rc)
    {
        FAPI_ERR("Error getting MBA position");
        return l_rc;
    } 

    // Get l_dramWidth                     
    l_rc = fapiGetScom(l_targetCentaur, mss_mbaxcr[l_mbaPosition], l_data); 
    if(l_rc) return l_rc;
    l_ecmd_rc |= l_data.extractPreserve(&l_dramWidth, 9, 1, 32-1);
                    
    // Read markstore register for the given rank
    l_rc = fapiGetScom(l_targetCentaur, mss_markStoreRegs[i_rank][l_mbaPosition], l_markstore); 
    if(l_rc) return l_rc;
    
    // If MPE FIR for the given rank (scrub or fetch) is on after the read,
    // we will read one more time just to make sure we get latest.
    l_rc = fapiGetScom(l_targetCentaur, mss_mbeccfir[l_mbaPosition], l_mbeccfir); 
    if(l_rc) return l_rc;
    if (l_mbeccfir.isBitSet(i_rank) || l_mbeccfir.isBitSet(20 + i_rank))
    {
        l_rc = fapiGetScom(l_targetCentaur, mss_markStoreRegs[i_rank][l_mbaPosition], l_markstore); 
        if(l_rc) return l_rc;
    }

    // Get l_symbolMarkGalois
    l_ecmd_rc |= l_markstore.extractPreserve(&l_symbolMarkGalois, 0, 8, 8-8);
    if(l_ecmd_rc)
    {
        l_rc.setEcmdError(l_ecmd_rc);
        return l_rc;
    }                                                                              
   
    if (l_symbolMarkGalois == 0x00) // No symbol mark
    {
        o_symbolMark = 0xff; 
    }
    else if (l_dramWidth == mss_MemConfig::X4)
    {
        // Create new log. 
        FAPI_ERR("l_symbolMarkGalois invalid: symbol mark not allowed in x4 mode.");
        FAPI_SET_HWP_ERROR(l_rc, RC_MSS_MAINT_NO_X4_SYMBOL);
        return l_rc;
    }
    else // Converted from galois field to symbol index
    {
        o_symbolMark = MSS_SYMBOLS_PER_RANK;
        for ( uint32_t i = 0; i < MSS_SYMBOLS_PER_RANK; i++ )
        {
            if ( l_symbolMarkGalois == mss_symbol2Galois[i] )
            {
                o_symbolMark = i;
                break;
            }
        }

        if ( MSS_SYMBOLS_PER_RANK <= o_symbolMark )
        {
            // Create new log. 
            FAPI_ERR("Invalid galois field in markstore.");
            FAPI_SET_HWP_ERROR(l_rc, RC_MSS_MAINT_INVALID_MARKSTORE);
            return l_rc;            
        }
    }
    
    // Get l_chipMarkGalois
    l_ecmd_rc |= l_markstore.extractPreserve(&l_chipMarkGalois, 8, 8, 8-8);
    if(l_ecmd_rc)
    {
        l_rc.setEcmdError(l_ecmd_rc);
        return l_rc;
    }                                                                              

    
    if (l_chipMarkGalois == 0x00) // No chip mark
    {
        o_chipMark = 0xff; 
    }
    else // Converted from galois field to chip index
    {

        if (l_dramWidth == mss_MemConfig::X4)
        {
            l_symbolsPerChip = 2;
        }
        else if (l_dramWidth == mss_MemConfig::X8)
        {
            l_symbolsPerChip = 4;
        }
        
        o_chipMark = MSS_SYMBOLS_PER_RANK;
        for ( uint32_t i = 0; i < MSS_SYMBOLS_PER_RANK; i=i+l_symbolsPerChip)
        {
            if ( l_chipMarkGalois == mss_symbol2Galois[i] )
            {
                o_chipMark = i;
                break;
            }
        }

        if ( MSS_SYMBOLS_PER_RANK <= o_chipMark )
        {
            // Create new log. 
            FAPI_ERR("Invalid galois field in markstore.");
            FAPI_SET_HWP_ERROR(l_rc, RC_MSS_MAINT_INVALID_MARKSTORE);
            return l_rc;            
        }
    }


    FAPI_INF("EXIT mss_get_mark_store()");     

    return l_rc;
}



//------------------------------------------------------------------------------
// mss_put_mark_store
//------------------------------------------------------------------------------
fapi::ReturnCode mss_put_mark_store( const fapi::Target & i_target,
                                     uint8_t i_rank,
                                     uint8_t i_symbolMark,
                                     uint8_t i_chipMark )
{

    FAPI_INF("ENTER mss_put_mark_store()");     

            
    fapi::ReturnCode l_rc;
       uint32_t l_ecmd_rc = 0;       
    ecmdDataBufferBase l_markstore(64);
    ecmdDataBufferBase l_mbeccfir(64);
    ecmdDataBufferBase l_data(64);
    uint32_t l_dramWidth = 0;
    uint8_t l_symbolMarkGalois = 0;
    uint8_t l_chipMarkGalois = 0;
    fapi::Target l_targetCentaur;
    uint8_t l_mbaPosition = 0;

    // Get Centaur target for the given MBA
    l_rc = fapiGetParentChip(i_target, l_targetCentaur);
    if(l_rc)
    {
        FAPI_ERR("Error getting Centaur parent target for the given MBA");
        return l_rc;
    }
    
    
    // Get MBA position: 0 = mba01, 1 = mba23
    l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target, l_mbaPosition);
    if(l_rc)
    {
        FAPI_ERR("Error getting MBA position");
        return l_rc;
    }     

    // Get l_dramWidth                     
    l_rc = fapiGetScom(l_targetCentaur, mss_mbaxcr[l_mbaPosition], l_data); 
    if(l_rc) return l_rc;
    l_ecmd_rc |= l_data.extractPreserve(&l_dramWidth, 9, 1, 32-1);
    if(l_ecmd_rc)
    {
        l_rc.setEcmdError(l_ecmd_rc);
        return l_rc;
    }                                                                                                  

    // Get l_symbolMarkGalois
    if (i_symbolMark == 0xff) // No symbol mark
    {
        l_symbolMarkGalois = 0x00;
    }
    else if ( l_dramWidth == mss_MemConfig::X4 ) 
    {
        // Create new log. 
        FAPI_ERR("i_symbolMark invalid: symbol mark not allowed in x4 mode.");
        FAPI_SET_HWP_ERROR(l_rc, RC_MSS_MAINT_NO_X4_SYMBOL);
        return l_rc;        
    }
    else if ( MSS_SYMBOLS_PER_RANK <= i_symbolMark ) 
    {
        // Create new log. 
        FAPI_ERR("i_symbolMark invalid: symbol index out of range.");
        FAPI_SET_HWP_ERROR(l_rc, RC_MSS_MAINT_INVALID_SYMBOL_INDEX);
        return l_rc;                
    }
    else // Convert from symbol index to galois field
    {
        l_symbolMarkGalois = mss_symbol2Galois[i_symbolMark];
    }
    l_ecmd_rc |= l_markstore.insert( l_symbolMarkGalois, 0, 8, 0 );
    

    // Get l_chipMarkGalois
    if (i_chipMark == 0xff) // No chip mark
    {
    l_chipMarkGalois = 0x00;
    }
    else if ( MSS_SYMBOLS_PER_RANK <= i_chipMark ) 
    {
        // Create new log. 
        FAPI_ERR("i_chipMark invalid: symbol index out of range.");
        FAPI_SET_HWP_ERROR(l_rc, RC_MSS_MAINT_INVALID_SYMBOL_INDEX);
        return l_rc;                        
    }
    else if ((l_dramWidth == mss_MemConfig::X8) && (i_chipMark % 4) ) 
    {
        // Create new log. 
        FAPI_ERR("i_chipMark invalid: not first symbol index of a x8 chip.");
        FAPI_SET_HWP_ERROR(l_rc, RC_MSS_MAINT_INVALID_CHIP_INDEX);
        return l_rc;                        
        
    }
    else if ((l_dramWidth == mss_MemConfig::X4) && (i_chipMark % 2) ) 
    {
        // Create new log. 
        FAPI_ERR("i_chipMark invalid: not first symbol index of a x4 chip.");
        FAPI_SET_HWP_ERROR(l_rc, RC_MSS_MAINT_INVALID_CHIP_INDEX);
           return l_rc;                        
    }
    else // Convert from symbol index to galois field
    {
        l_chipMarkGalois = mss_symbol2Galois[i_chipMark];
    }
    l_ecmd_rc |= l_markstore.insert( l_chipMarkGalois, 8, 8, 0 );        
    if(l_ecmd_rc)
    {
        l_rc.setEcmdError(l_ecmd_rc);
        return l_rc;
    }                                                                              
 
   // Write markstore register for the given rank
    l_rc = fapiPutScom(l_targetCentaur, mss_markStoreRegs[i_rank][l_mbaPosition], l_markstore); 
    if(l_rc) return l_rc;
    
    // If MPE FIR for the given rank (scrub or fetch) is on after the read,
    // we will return TBD fapi::ReturnCode to indicate write may not have worked.
    // Up to caller to read again if they want to see what new chip mark is.
    l_rc = fapiGetScom(l_targetCentaur, mss_mbeccfir[l_mbaPosition], l_mbeccfir); 
    if(l_rc) return l_rc;
    if (l_mbeccfir.isBitSet(i_rank) || l_mbeccfir.isBitSet(20 + i_rank))
    {
        // Create new log. 
        FAPI_ERR("Markstore write may have been blocked due to MPE FIR set.");
        FAPI_SET_HWP_ERROR(l_rc, RC_MSS_MAINT_MARKSTORE_WRITE_BLOCKED);
        return l_rc;                                      
    }
           
    FAPI_INF("EXIT mss_put_mark_store()");     
    return l_rc;
}



//------------------------------------------------------------------------------
// mss_get_steer_mux
//------------------------------------------------------------------------------

fapi::ReturnCode mss_get_steer_mux( const fapi::Target & i_target,
                                    uint8_t i_rank,
                                    mss_SteerMux::muxType i_muxType,
                                    uint8_t & o_dramSparePort0Symbol,
                                    uint8_t & o_dramSparePort1Symbol,
                                    uint8_t & o_eccSpareSymbol )
{

    FAPI_INF("ENTER mss_get_steer_mux()");     

        
    fapi::ReturnCode l_rc;
    uint32_t l_ecmd_rc = 0;       
    ecmdDataBufferBase l_steerMux(64);
    ecmdDataBufferBase l_data(64);
    uint32_t l_dramWidth = 0;
    uint8_t l_dramSparePort0Index = 0;
    uint8_t l_dramSparePort1Index = 0;
    uint8_t l_eccSpareIndex = 0;
    fapi::Target l_targetCentaur;
    uint8_t l_mbaPosition = 0;

    // Get Centaur target for the given MBA
    l_rc = fapiGetParentChip(i_target, l_targetCentaur);
    if(l_rc)
    {
        FAPI_ERR("Error getting Centaur parent target for the given MBA");
        return l_rc;
    }


    // Get MBA position: 0 = mba01, 1 = mba23
    l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target, l_mbaPosition);
    if(l_rc)
    {
        FAPI_ERR("Error getting MBA position");
        return l_rc;
    }

    // Get l_dramWidth                     
    l_rc = fapiGetScom(l_targetCentaur, mss_mbaxcr[l_mbaPosition], l_data); 
    if(l_rc) return l_rc;
    l_ecmd_rc |= l_data.extractPreserve(&l_dramWidth, 9, 1, 32-1);
    
    // Read steer mux register for the given rank and mux type (read or write).
    if (i_muxType == mss_SteerMux::READ_MUX)
    {   
        // Read muxes are in the MBS
        l_rc = fapiGetScom(l_targetCentaur, mss_readMuxRegs[i_rank][l_mbaPosition], l_steerMux); 
        if(l_rc) return l_rc;
    }
    else    
    {           
        // Write muxes are in the MBA
        l_rc = fapiGetScom(i_target, mss_writeMuxRegs[i_rank], l_steerMux); 
        if(l_rc) return l_rc;
    }
    
    //***************************************
    // Get l_dramSparePort0Index
    l_ecmd_rc |= l_steerMux.extractPreserve(&l_dramSparePort0Index, 0, 5, 8-5);
    if(l_ecmd_rc)
    {
        l_rc.setEcmdError(l_ecmd_rc);
        return l_rc;
    }                                                                              
       
    // Get o_dramSparePort0Symbol if index in valid range
    if ((l_dramWidth == mss_MemConfig::X8) && (l_dramSparePort0Index < MSS_X8_STEER_OPTIONS_PER_PORT))
    {
        o_dramSparePort0Symbol = mss_x8dramSparePort0Index_to_symbol[l_dramSparePort0Index];
    }
    else if ((l_dramWidth == mss_MemConfig::X4) && (l_dramSparePort0Index < MSS_X4_STEER_OPTIONS_PER_PORT0))
    {
        o_dramSparePort0Symbol = mss_x4dramSparePort0Index_to_symbol[l_dramSparePort0Index];
    }
    else
    {
        FAPI_ERR("l_dramSparePort0Index out of range.");
        // Caller needs to recognize a symbol value of 0xfe as invalid.    
        o_dramSparePort0Symbol = 0xfe;    
    }
       
       
    //***************************************       
    // Get l_dramSparePort1Index
    l_ecmd_rc |= l_steerMux.extractPreserve(&l_dramSparePort1Index, 5, 5, 8-5);
    if(l_ecmd_rc)
    {
        l_rc.setEcmdError(l_ecmd_rc);
        return l_rc;
    }                                                                                     
       
    // Get o_dramSparePort1Symbol if index in valid range
    if ((l_dramWidth == mss_MemConfig::X8) && (l_dramSparePort1Index < MSS_X8_STEER_OPTIONS_PER_PORT))
    {
        o_dramSparePort1Symbol = mss_x8dramSparePort1Index_to_symbol[l_dramSparePort1Index];
    }
    else if ((l_dramWidth == mss_MemConfig::X4) && (l_dramSparePort1Index < MSS_X4_STEER_OPTIONS_PER_PORT1))
    {
        o_dramSparePort1Symbol = mss_x4dramSparePort1Index_to_symbol[l_dramSparePort1Index];
    }
    else
    {
        FAPI_ERR("l_dramSparePort1Index out of range.");
        // Caller needs to recognize a symbol value of 0xfe as invalid.    
        o_dramSparePort1Symbol = 0xfe;    
    }

       
    //***************************************
    // Get l_eccSpareIndex
    l_ecmd_rc |= l_steerMux.extractPreserve(&l_eccSpareIndex, 10, 5, 8-5);
    if(l_ecmd_rc)
    {
        l_rc.setEcmdError(l_ecmd_rc);
        return l_rc;
    }                                                                                     

    // Get o_eccSpareSymbol if index in valid range
    if (l_eccSpareIndex < MSS_X4_ECC_STEER_OPTIONS)
    {
        o_eccSpareSymbol = mss_eccSpareIndex_to_symbol[l_eccSpareIndex];
    }
    else
    {
        FAPI_ERR("o_eccSpareSymbol out of range.");
        // Caller needs to recognize a symbol value of 0xfe as invalid.    
        o_eccSpareSymbol = 0xfe; 
    }


    FAPI_INF("EXIT mss_get_steer_mux()");     

    return l_rc;
    
}




//------------------------------------------------------------------------------
// mss_put_steer_mux
//------------------------------------------------------------------------------

fapi::ReturnCode mss_put_steer_mux( const fapi::Target & i_target,
                                    uint8_t i_rank,
                                    mss_SteerMux::muxType i_muxType,
                                    mss_SteerMux::steerType i_steerType,
                                    uint8_t i_symbol )



{

    // TODO: i_symbol = 0xff will result 0's entered in steer mux, which 
    // means no steer.
    // Do I want to allow writing of no steer?
    
    // TODO: i_symbol has to be first symbol in the chip for us to accept it. 
    // Do I want to allow any symbol as the input? 


    FAPI_INF("ENTER mss_put_steer_mux()");         

    
    fapi::ReturnCode l_rc;
    uint32_t l_ecmd_rc = 0;       
    ecmdDataBufferBase l_steerMux(64);
    ecmdDataBufferBase l_data(64);
    uint32_t l_dramWidth = 0;
    uint8_t l_dramSparePort0Index = 0;
    uint8_t l_dramSparePort1Index = 0;
    uint8_t l_eccSpareIndex = 0;
    fapi::Target l_targetCentaur;
    uint8_t l_mbaPosition = 0;

    // Get Centaur target for the given MBA
    l_rc = fapiGetParentChip(i_target, l_targetCentaur);
    if(l_rc)
    {
        FAPI_ERR("Error getting Centaur parent target for the given MBA");
        return l_rc;
    }
    

    // Get MBA position: 0 = mba01, 1 = mba23
    l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target, l_mbaPosition);
    if(l_rc)
    {
        FAPI_ERR("Error getting MBA position");
        return l_rc;
    }    
    
    // Get l_dramWidth                     
    l_rc = fapiGetScom(l_targetCentaur, mss_mbaxcr[l_mbaPosition], l_data);
    if(l_rc) return l_rc;
    l_ecmd_rc |= l_data.extractPreserve(&l_dramWidth, 9, 1, 31-1);
    if(l_ecmd_rc)
    {
        l_rc.setEcmdError(l_ecmd_rc);
        return l_rc;
    }                                                                                     
  
    // Read steer mux register for the given rank and mux type (read or write).
    if (i_muxType == mss_SteerMux::READ_MUX)
    {   
        // Read muxes are in the MBS
        l_rc = fapiGetScom(l_targetCentaur, mss_readMuxRegs[i_rank][l_mbaPosition], l_steerMux);
        if(l_rc) return l_rc;
    }
    else    
    {
        // Write muxes are in the MBA
        l_rc = fapiGetScom(i_target, mss_writeMuxRegs[i_rank], l_steerMux);
        if(l_rc) return l_rc;
    }

   
    // Convert from i_symbol to l_dramSparePort0Index
    if (i_steerType == mss_SteerMux::DRAM_SPARE_PORT0)
    {
        if (l_dramWidth == mss_MemConfig::X8)
        {
            l_dramSparePort0Index = MSS_X8_STEER_OPTIONS_PER_PORT;
            for ( uint32_t i = 0; i < MSS_X8_STEER_OPTIONS_PER_PORT; i++ )
            {
                if ( i_symbol == mss_x8dramSparePort0Index_to_symbol[i] )
                {
                    l_dramSparePort0Index = i;
                    break;
                }
            }

            if ( MSS_X8_STEER_OPTIONS_PER_PORT <= l_dramSparePort0Index )
            {
                // Create new log. 
                FAPI_ERR("No match for i_symbol in mss_x8dramSparePort0Index_to_symbol[].");
                FAPI_SET_HWP_ERROR(l_rc, RC_MSS_MAINT_INVALID_SYMBOL_TO_STEER);
                return l_rc;
            }
        }

        else if (l_dramWidth == mss_MemConfig::X4)
        {
            l_dramSparePort0Index = MSS_X4_STEER_OPTIONS_PER_PORT0;
            for ( uint32_t i = 0; i < MSS_X4_STEER_OPTIONS_PER_PORT0; i++ )
            {
                if ( i_symbol == mss_x4dramSparePort0Index_to_symbol[i] )
                {
                    l_dramSparePort0Index = i;
                    break;
                }
            }

            if ( MSS_X4_STEER_OPTIONS_PER_PORT0 <= l_dramSparePort0Index )
            {
                // Create new log. 
                FAPI_ERR("No match for i_symbol in mss_x4dramSparePort0Index_to_symbol[].");
                FAPI_SET_HWP_ERROR(l_rc, RC_MSS_MAINT_INVALID_SYMBOL_TO_STEER);
                return l_rc;
            }
        }

        l_ecmd_rc |= l_steerMux.insert( l_dramSparePort0Index, 0, 5, 8-5 ); 
    } 
   
   
    // Convert from i_symbol to l_dramSparePort1Index
    if (i_steerType == mss_SteerMux::DRAM_SPARE_PORT1)
    {
        if (l_dramWidth == mss_MemConfig::X8)
        {
            l_dramSparePort1Index = MSS_X8_STEER_OPTIONS_PER_PORT;
            for ( uint32_t i = 0; i < MSS_X8_STEER_OPTIONS_PER_PORT; i++ )
            {
                if ( i_symbol == mss_x8dramSparePort1Index_to_symbol[i] )
                {
                    l_dramSparePort1Index = i;
                    break;
                }
            }

            if ( MSS_X8_STEER_OPTIONS_PER_PORT <= l_dramSparePort1Index )
            {
                // Create new log. 
                FAPI_ERR("No match for i_symbol in mss_x8dramSparePort1Index_to_symbol[].");
                FAPI_SET_HWP_ERROR(l_rc, RC_MSS_MAINT_INVALID_SYMBOL_TO_STEER);
                return l_rc;
            }
        }
        
        else if (l_dramWidth == mss_MemConfig::X4)
        {
            l_dramSparePort1Index = MSS_X4_STEER_OPTIONS_PER_PORT1;
            for ( uint32_t i = 0; i < MSS_X4_STEER_OPTIONS_PER_PORT1; i++ )
            {
                if ( i_symbol == mss_x4dramSparePort1Index_to_symbol[i] )
                {
                    l_dramSparePort1Index = i;
                    break;
                }
            }

            if ( MSS_X4_STEER_OPTIONS_PER_PORT1 <= l_dramSparePort1Index )
            {
                // Create new log. 
                FAPI_ERR("No match for i_symbol in mss_x4dramSparePort1Index_to_symbol[].");
                FAPI_SET_HWP_ERROR(l_rc, RC_MSS_MAINT_INVALID_SYMBOL_TO_STEER);
                return l_rc;
            }
        }

        l_ecmd_rc |= l_steerMux.insert( l_dramSparePort1Index, 5, 5, 8-5 ); 
    }

   
   
    // Convert from i_symbol to l_eccSpareIndex
    if (i_steerType == mss_SteerMux::ECC_SPARE)
    {
        if (l_dramWidth == mss_MemConfig::X4)
        {
            l_eccSpareIndex = MSS_X4_ECC_STEER_OPTIONS;
            for ( uint32_t i = 0; i < MSS_X4_ECC_STEER_OPTIONS; i++ )
            {
                if ( i_symbol == mss_eccSpareIndex_to_symbol[i] )
                {
                    l_eccSpareIndex = i;
                    break;
                }
            }

            if ( MSS_X4_ECC_STEER_OPTIONS <= l_eccSpareIndex )
            {
                // Create new log. 
                FAPI_ERR("No match for i_symbol in mss_eccSpareIndex_to_symbol[].");
                FAPI_SET_HWP_ERROR(l_rc, RC_MSS_MAINT_INVALID_SYMBOL_TO_STEER);
                return l_rc;
            }
        }
        else if (l_dramWidth == mss_MemConfig::X8)
        {
   
            // Create new log. 
            FAPI_ERR("ECC_SPARE not valid with x8 mode.");
            FAPI_SET_HWP_ERROR(l_rc, RC_MSS_MAINT_NO_X8_ECC_SPARE);
            return l_rc;
        }
        
        l_ecmd_rc |= l_steerMux.insert( l_eccSpareIndex, 10, 5, 8-5 ); 
    }
    
    if(l_ecmd_rc)
    {
        l_rc.setEcmdError(l_ecmd_rc);
        return l_rc;
    }                                                                                 

    // Write the steer mux register for the given rank and mux 
    // type (read or write).
    if (i_muxType == mss_SteerMux::READ_MUX)
    {   
        // Read muxes are in the MBS
        l_rc = fapiPutScom(l_targetCentaur, mss_readMuxRegs[i_rank][l_mbaPosition], l_steerMux); 
        if(l_rc) return l_rc;
    }
    else    
    {
        // Write muxes are in the MBA
        l_rc = fapiPutScom(i_target, mss_writeMuxRegs[i_rank], l_steerMux); 
        if(l_rc) return l_rc;
    }


    FAPI_INF("EXIT mss_put_steer_mux()");         

    return l_rc;
    
}
