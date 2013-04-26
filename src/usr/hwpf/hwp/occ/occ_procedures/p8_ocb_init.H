/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_ocb_init.H $           */
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
// $Id: p8_ocb_init.H,v 1.4 2012/11/27 18:11:50 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_ocb_init.H,v $
#ifndef _P8_OCB_INIT_H_
#define _P8_OCB_INIT_H_

#include <fapi.H>
#include "p8_pm.H"

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*p8_ocb_init_FP_t) (const fapi::Target&,
                                              const uint32_t,
                                              const uint8_t,
                                              const uint8_t,
                                              const uint32_t,
                                              const uint8_t,
                                              const uint8_t,
                                              const uint8_t);

extern "C" {

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
/// \brief Configure OCB Channels based on mode and parameters passed
/// \param[in]   i_target          => Chip Target
/// \param[in]   i_mode            => PM_CONFIG, PM_RESET, PM_INIT, or PM_SETUP
/// \param[in]   i_ocb_chan        => select channel 0-3 to set up
/// \param[in]   i_ocb_type        => 0=indirect  1=linear stream  2=circular push  3=circular pull
/// \param[in]   i_ocb_bar         => 32-bit channel base address (29 bits + "000")
/// \param[in]   i_ocb_q_len       => 0-31 length of push or pull queue in  (queue_length + 1) * 8B
/// \param[in]   i_ocb_ouflow_en   => 0=disabled 1=enabled
/// \param[in]   i_ocb_itp_type    => 0=full  1=not full  2=empty  3=not empty

fapi::ReturnCode p8_ocb_init(const fapi::Target& i_target,
                             const uint32_t      i_mode,
                             const uint8_t       i_ocb_chan,
                             const uint8_t       i_ocb_type,
                             const uint32_t      i_ocb_bar,
                             const uint8_t       i_ocb_q_len,
                             const uint8_t       i_ocb_ouflow_en,
                             const uint8_t       i_ocb_itp_type);

// ---------
// Constants
// ---------
const uint8_t OCB_CHAN0                = 0x00;
const uint8_t OCB_CHAN1                = 0x01;
const uint8_t OCB_CHAN2                = 0x02;
const uint8_t OCB_CHAN3                = 0x03;

const uint8_t OCB_TYPE_NULL            = 0x00;
const uint8_t OCB_TYPE_LIN             = 0x01;
const uint8_t OCB_TYPE_LINSTR          = 0x02;
const uint8_t OCB_TYPE_LINWIN          = 0x03;
const uint8_t OCB_TYPE_CIRC            = 0x04;
const uint8_t OCB_TYPE_PUSHQ           = 0x05;
const uint8_t OCB_TYPE_PULLQ           = 0x06;

const uint8_t OCB_UPD_PIB_REG          = 0x00;
const uint8_t OCB_UPD_PIB_OCI_REG      = 0x01;

const uint8_t OCB_Q_OUFLOW_NULL        = 0x00;
const uint8_t OCB_Q_OUFLOW_EN          = 0x01;
const uint8_t OCB_Q_OUFLOW_DIS         = 0x02;

const uint8_t OCB_Q_ITPTYPE_NULL       = 0x00;
const uint8_t OCB_Q_ITPTYPE_FULL       = 0x01;
const uint8_t OCB_Q_ITPTYPE_NOTFULL    = 0x02;
const uint8_t OCB_Q_ITPTYPE_EMPTY      = 0x03;
const uint8_t OCB_Q_ITPTYPE_NOTEMPTY   = 0x04;

const uint8_t OCB_UNSECMASTER_NULL     = 0x00;
const uint8_t OCB_UNSECMASTER_ALLOW    = 0x01;
const uint8_t OCB_UNSECMASTER_NOTALLOW = 0x02;

// channel register arrrays
const uint64_t OCBARn[4]       = {OCB0_ADDRESS_0x0006B010,             OCB1_ADDRESS_0x0006B030,             OCB2_ADDRESS_0x0006B050,             OCB3_ADDRESS_0x0006B070            };
const uint64_t OCBCSRn[4]      = {OCB0_STATUS_CONTROL_0x0006B011,      OCB1_STATUS_CONTROL_0x0006B031,      OCB2_STATUS_CONTROL_0x0006B051,      OCB3_STATUS_CONTROL_0x0006B071     };
const uint64_t OCBCSRn_AND[4]  = {OCB0_STATUS_CONTROL_AND_0x0006B012,  OCB1_STATUS_CONTROL_AND_0x0006B032,  OCB2_STATUS_CONTROL_AND_0x0006B052,  OCB3_STATUS_CONTROL_AND_0x0006B072 };
const uint64_t OCBCSRn_OR[4]   = {OCB0_STATUS_CONTROL_OR_0x0006B013,   OCB1_STATUS_CONTROL_OR_0x0006B033,   OCB2_STATUS_CONTROL_OR_0x0006B053,   OCB3_STATUS_CONTROL_OR_0x0006B073  };
const uint64_t OCBESRn[4]      = {OCB0_ERROR_STATUS_0x0006B014,        OCB1_ERROR_STATUS_0x0006B034,        OCB2_ERROR_STATUS_0x0006B054,        OCB3_ERROR_STATUS_0x0006B074       };
const uint64_t OCBSLBRn[3]     = {OCB0_PULL_BASE_0x0006A200,           OCB1_PULL_BASE_0x0006A210,           OCB2_PULL_BASE_0x0006A220                                               };
const uint64_t OCBSHBRn[3]     = {OCB0_PULL_STATUS_CONTROL_0x0006A201, OCB1_PULL_STATUS_CONTROL_0x0006A211, OCB2_PULL_STATUS_CONTROL_0x0006A221                                     };
const uint64_t OCBSLCSn[3]     = {OCB0_PUSH_BASE_0x0006A203,           OCB1_PUSH_BASE_0x0006A213,           OCB2_PUSH_BASE_0x0006A223                                               };
const uint64_t OCBSHCSn[3]     = {OCB0_PUSH_STATUS_CONTROL_0x0006A204, OCB1_PUSH_STATUS_CONTROL_0x0006A214, OCB2_PUSH_STATUS_CONTROL_0x0006A224                                     };
const uint64_t OCBSESn[3]      = {OCB0_STREAM_ERR_STATUS_0x0006A206,   OCB1_STREAM_ERR_STATUS_0x0006A216,   OCB2_STREAM_ERR_STATUS_0x0006A226                                       };

const uint64_t OCBICRn[3]      = {OCB0_UNTRUSTED_CONTROL_0x0006A207,   OCB1_UNTRUSTED_CONTROL_0x0006A217,   OCB2_UNTRUSTED_CONTROL_0x0006A227                                       }; // allow unsecure master
const uint64_t OCBLWCRn[3]     = {OCB0_LIN_WINDOW_CONTROL_0x0006A208,  OCB1_LIN_WINDOW_CONTROL_0x0006A218,  OCB2_LIN_WINDOW_CONTROL_0x0006A228                                      }; // linear window write control
const uint64_t OCBLWSBRn[3]    = {OCB0_LIN_WINDOW_BASE_0x0006A20C,     OCB1_LIN_WINDOW_BASE_0x0006A21C,     OCB2_LIN_WINDOW_BASE_0x0006A22C                                         }; // linear window write base

} // extern "C"

#endif

