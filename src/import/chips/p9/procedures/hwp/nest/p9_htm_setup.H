/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_htm_setup.H $                 */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/// ----------------------------------------------------------------------------
/// @file  p9_htm_setup.H
///
/// @brief Perform p9_htm_setup on a processor chip
///
/// The purpose of this procedure is to setup and start HTM on a processor
/// chip.
/// Some start/setup attributes are used as part of the setup process.
///
/// ----------------------------------------------------------------------------
/// *HWP HWP Owner   : Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner    : Thi Tran <thi@us.ibm.com>
/// *HWP Team        : Nest
/// *HWP Level       : 1
/// *HWP Consumed by : HB
/// ----------------------------------------------------------------------------

#ifndef _P9_HTM_SETUP_H_
#define _P9_HTM_SETUP_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

// Function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_htm_setup_FP_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);

//----------------------------------------------------------------------------
// Constant definitions
//----------------------------------------------------------------------------
const uint8_t NUM_OF_HTM_REGIONS = 2;

//-----------------
// Register offsets
//-----------------
// Register offsets from HTM Collection Mode Register, for NHTM and CHTM
const uint32_t HTM_MODE = 0x0;
const uint32_t HTM_MEM  = 0x1;
const uint32_t HTM_STAT = 0x2;
const uint32_t HTM_LAST = 0x3;
const uint32_t HTM_TRIG = 0x4;
const uint32_t HTM_CTRL = 0x5;

// Register offsets from HTM Collection Mode Register, for NHTM only
const uint32_t NHTM_FILT       = 0x6;
const uint32_t NHTM_TTYPE_FILT = 0x7;
const uint32_t NHTM_CFG        = 0x8;

// Register offsets from HTM Collection Mode Register, for CHTM only
const uint32_t CHTM_IMA_STAT = 0xA;
const uint32_t CHTM_PDBAR    = 0xB;

//--------------------------------------------------------
//             HTM_MODE definitions
//--------------------------------------------------------
// Bit definitions for HTM_MODE
const uint32_t HTM_MODE_TRACE_ENABLE              = 0;
const uint32_t HTM_MODE_CONTENT_SEL               = 1;
const uint32_t HTM_MODE_CAPTURE                   = 4;
const uint32_t HTM_MODE_WRAP_MODE                 = 13;
const uint32_t HTM_MODE_DISABLE_TSTAMPS           = 14;
const uint32_t HTM_MODE_SINGLE_TSTAMPS            = 15;
const uint32_t HTM_MODE_MARKERS_ONLY              = 17;
const uint32_t HTM_MODE_DISABLE_FORCE_GRP_SCOPE   = 18;
const uint32_t HTM_MODE_SYNC_STAMP_FORCE          = 19;
const uint32_t HTM_MODE_WRITETOIO                 = 22;
const uint32_t HTM_MODE_VGTARGET                  = 24;

// Bit len definitions
const uint32_t HTM_MODE_CONTENT_SEL_LEN        = 2;
const uint32_t HTM_MODE_CAPTURE_LEN            = 9;
const uint32_t HTM_MODE_SYNC_STAMP_FORCE_LEN   = 3;
const uint32_t HTM_MODE_VGTARGET_LEN           = 16;

// Bit data values
const uint32_t HTM_MODE_CONTENT_SEL_CHTM_CORE = 0;
const uint32_t HTM_MODE_CONTENT_SEL_CHTM_LLAT = 1;
const uint32_t HTM_MODE_CONTENT_SEL_CHTM_OHA  = 2;
const uint32_t HTM_MODE_CONTENT_SEL_CHTM_MEM  = 3;

//--------------------------------------------------------
//             HTM_MEM definitions
//--------------------------------------------------------
const uint32_t HTM_MEM_TRC_MEM_ALLOC      = 0;  // Bit  0
const uint32_t HTM_MEM_TRC_MEM_SCOPE      = 1;  // Bits 1:3
const uint32_t HTM_MEM_TRC_MEM_PRIORITY   = 4;  // Bit  4
const uint32_t HTM_MEM_TRC_MEM_SIZE_SMALL = 5;  // Bit  5
const uint32_t HTM_MEM_TRC_MEM_BASE_ADDR  = 8;  // Bits 8:39
const uint32_t HTM_MEM_TRC_MEM_SIZE       = 40; // Bits 40:48

// MEM_SCOPE definitions
const uint32_t HTM_MEM_TRC_MEM_SCOPE_LEN     = 3;  // Bits 1:3

// MEM_PRIORITY definitions
const uint32_t HTM_MEM_TRC_MEM_PRIORITY_LOW  = 0;
const uint32_t HTM_MEM_TRC_MEM_PRIORITY_HIGH = 1;

// MEM_BASE_ADDR definitions
const uint32_t HTM_MEM_TRC_MEM_BASE_ADDR_LEN = 32;

// MEM_SIZE definitions
const uint32_t HTM_MEM_TRC_MEM_SIZE_LEN      = 9;

//--------------------------------------------------------
//             HTM_STAT definitions
//--------------------------------------------------------
// Bit definitions for HTM_STAT
const uint32_t HTM_STAT_PURGE_IN_PROG = 0;
const uint32_t HTM_STAT_PURGE_DONE    = 1;
const uint32_t HTM_STAT_CRESP_OV      = 2;
const uint32_t HTM_STAT_REPAIR        = 3;
const uint32_t HTM_STAT_BUF_WAIT      = 4;
const uint32_t HTM_STAT_TRIG_DROPPED  = 5;
const uint32_t HTM_STAT_ADDR_ERROR    = 6;
const uint32_t HTM_STAT_REC_DROPPED   = 7;
const uint32_t HTM_STAT_INIT          = 8;
const uint32_t HTM_STAT_PREREQ        = 9;
const uint32_t HTM_STAT_READY         = 10;
const uint32_t HTM_STAT_TRACING       = 11;
const uint32_t HTM_STAT_PAUSED        = 12;
const uint32_t HTM_STAT_FLUSH         = 13;
const uint32_t HTM_STAT_COMPLETE      = 14;
const uint32_t HTM_STAT_ENABLE        = 15;
const uint32_t HTM_STAT_STAMP         = 16;
const uint32_t HTM_STAT_SCOM_ERROR    = 17;
const uint32_t HTM_STAT_PARITY_ERROR  = 18;
const uint32_t HTM_STAT_INVALID_CRESP = 18;

//--------------------------------------------------------
//             HTM_CTRL definitions
//--------------------------------------------------------
// Bit definitions for HTM_CTRL
const uint32_t HTM_CTRL_TRIG_CTRL               = 0;
const uint32_t HTM_CTRL_MARKER_CTRL             = 4;
const uint32_t HTM_CTRL_STOP_ON_DBG_TRIG0       = 6;
const uint32_t HTM_CTRL_STOP_ON_DBG_TRIG1       = 7;
const uint32_t HTM_CTRL_TRC_RUN_TRIG_ACTION     = 8;
const uint32_t HTM_CTRL_STOP_ON_OTHER_DBG_TRIG0 = 9;
const uint32_t HTM_CTRL_STOP_ON_CHIPLET_XSTOP   = 13;

// Bit len definitions
const uint32_t HTM_CTRL_TRIG_CTRL_LEN = 2;
const uint32_t HTM_CTRL_MARKER_CTRL_LEN  = 2;

//--------------------------------------------------------
//             NHTM_TTYPE_FILT definitions
//--------------------------------------------------------
// TODO: Verify p9_scomdef is correct (i.e. start from bit 1 instead of 0)
// Bit definitions for NHTM_TTYPE_FILT
const uint32_t NHTM_TTYPE_FILT_TTYPE_PATTERN = 1;
const uint32_t NHTM_TTYPE_FILT_TSIZE_PATTERN = 8;
const uint32_t NHTM_TTYPE_FILT_TTYPE_MASK    = 17;
const uint32_t NHTM_TTYPE_FILT_TSIZE_MASK    = 24;
const uint32_t NHTM_TTYPE_FILT_TTYPEFILT_INV = 32;
const uint32_t NHTM_TTYPE_FILT_CRESPFILT_INV = 33;


// Bit len definitions
const uint32_t NHTM_TTYPE_FILT_TTYPE_PATTERN_LEN = 7;
const uint32_t NHTM_TTYPE_FILT_TSIZE_PATTERN_LEN = 8;
const uint32_t NHTM_TTYPE_FILT_TTYPE_MASK_LEN    = 7;
const uint32_t NHTM_TTYPE_FILT_TSIZE_MASK_LEN    = 8;

//--------------------------------------------------------
//             NHTM_FILT definitions
//--------------------------------------------------------
// Bit definitions for NHTM_FILT
const uint32_t NHTM_FILT_FILTER_PATTERN         = 0;
const uint32_t NHTM_FILT_FILTER_CRESP_PATTERN   = 27;
const uint32_t NHTM_FILT_FILTER_MASK            = 32;
const uint32_t NHTM_FILT_FILTER_CRESP_MASK      = 59;

// Bit len definitions
const uint32_t NHTM_FILT_FILTER_PATTERN_LEN        = 23;
const uint32_t NHTM_FILT_FILTER_CRESP_PATTERN_LEN  = 5;
const uint32_t NHTM_FILT_FILTER_MASK_LEN           = 22;
const uint32_t NHTM_FILT_FILTER_CRESP_MASK_LEN     = 5;

// Bit data values
const uint32_t NHTM_FILT_FILTER_MASK_VAL = 0x3FFFFF;

//--------------------------------------------------------
//            HTM_TRIG definitions
//--------------------------------------------------------
// Bit definitions for HTM_TRIG
const uint32_t HTM_TRIG_START      = 0;
const uint32_t HTM_TRIG_STOP       = 1;
const uint32_t HTM_TRIG_PAUSE      = 2;
const uint32_t HTM_TRIG_RESET      = 4;
const uint32_t HTM_TRIG_MARK_VALID = 5;
const uint32_t HTM_TRIG_MARK_TYPE  = 6;
const uint32_t HTM_TRIG_MARK_TYPE_LEN  = 10;

//--------------------------------------------------------
//    EQ_NCU_MODE_REG definitions (0x1001100A)
//--------------------------------------------------------

// NCU_MODE_REG bit definitions for EQ_NCU_MODE_REG
const uint32_t NCU_MODE_REG_HTM_ENABLE      = 0; //TODO: Does't exist in P9
const uint32_t NCU_MODE_REG_HTM_QUEUE_LIMIT = 0;
const uint32_t NCU_MODE_REG_IMA_ENABLE      = 4; //TODO: Does't exist in P9

// Bit len definitions
const uint32_t NCU_MODE_REG_HTM_QUEUE_LIMIT_LEN = 2;

// Size selected via HTM_MEM.MEM_SIZE_SMALL (bit 13)
enum htm_size_t
{
    HTM_512M_OR_16M = 0x0,
    HTM_1G_OR_32M   = 0x1,
    HTM_2G_OR_64M   = 0x3,
    HTM_4G_OR_128M  = 0x7,
    HTM_8G_OR_256M  = 0xF,
    HTM_16G_OR_512M = 0x1F,
    HTM_32G_OR_1G   = 0x3F,
    HTM_64G_OR_2G   = 0x7F,
    HTM_128G_OR_4G  = 0xFF,
    HTM_256G_OR_8G  = 0x1FF
};


//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------
extern "C"
{

///
/// @brief p9_htm_setup procedure
///
/// This HWP is to setup the HTM on the input processor chip.
///
/// @param[in]    i_target   Reference to TARGET_TYPE_PROC_CHIP target
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_htm_setup(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

} // extern "C"

#endif  // _P9_HTM_SETUP_H_
