/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pm_pba_firinit.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: p8_pm_pba_firinit.H,v 1.7 2013/08/26 12:44:35 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pm_pba_firinit.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : p8_pm_pba_firinit.H
// *! DESCRIPTION : SET PBA FIRINITS
// *!
// *! OWNER NAME  : Greg Still    Email: stillgs@us.ibm.com
// *! BACKUP NAME : Pradeep CN    Email: padeepcn@in.ibm.com
// *!
//------------------------------------------------------------------------------

#include "p8_pm_firinit.H"

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*p8_pm_pba_firinit_FP_t) (const fapi::Target&  , uint32_t mode);

const uint32_t        PBA_FIR_REGISTER_LENGTH = 46 ;
enum PBA_FIRS
{
    PBAFIR_OCI_APAR_ERR          = 0 ,
    PBAFIR_PB_RDADRERR_FW        = 1 ,
    PBAFIR_PB_RDDATATO_FW        = 2 ,
    PBAFIR_PB_SUE_FW             = 3 ,
    PBAFIR_PB_UE_FW              = 4 ,
    PBAFIR_PB_CE_FW              = 5 ,
    PBAFIR_OCI_SLAVE_INIT        = 6 ,
    PBAFIR_OCI_WRPAR_ERR         = 7 ,
    PBAFIR_OCI_REREQTO           = 8 ,
    PBAFIR_PB_UNEXPCRESP         = 9 ,
    PBAFIR_PB_UNEXPDATA          = 10,
    PBAFIR_PB_PARITY_ERR         = 11,
    PBAFIR_PB_WRADRERR_FW        = 12,
    PBAFIR_PB_BADCRESP           = 13,
    PBAFIR_PB_ACKDEAD_FW_RD      = 14,
    PBAFIR_PB_CRESPTO            = 15,
    PBAFIR_BCUE_SETUP_ERR        = 16,
    PBAFIR_BCUE_PB_ACK_DEAD      = 17,
    PBAFIR_BCUE_PB_ADRERR        = 18,
    PBAFIR_BCUE_OCI_DATERR       = 19,
    PBAFIR_BCDE_SETUP_ERR        = 20,
    PBAFIR_BCDE_PB_ACK_DEAD      = 21,
    PBAFIR_BCDE_PB_ADRERR        = 22,
    PBAFIR_BCDE_RDDATATO_ERR     = 23,
    PBAFIR_BCDE_SUE_ERR          = 24,
    PBAFIR_BCDE_UE_ERR           = 25,
    PBAFIR_BCDE_CE               = 26,
    PBAFIR_BCDE_OCI_DATERR       = 27,
    PBAFIR_INTERNAL_ERR          = 28,
    PBAFIR_ILLEGAL_CACHE_OP      = 29,
    PBAFIR_OCI_BAD_REG_ADDR      = 30,
    PBAFIR_AXPUSH_WRERR          = 31,
    PBAFIR_AXRCV_DLO_ERR         = 32,
    PBAFIR_AXRCV_DLO_TO          = 33,
    PBAFIR_AXRCV_RSVDATA_TO      = 34,
    PBAFIR_AXFLOW_ERR            = 35,
    PBAFIR_AXSND_DHI_RTYTO       = 36,
    PBAFIR_AXSND_DLO_RTYTO       = 37,
    PBAFIR_AXSND_RSVTO           = 38,
    PBAFIR_AXSND_RSVERR          = 39,
    PBAFIR_PB_ACKDEAD_FW_WR      = 40,
    PBAFIR_RESERVED_41           = 41,
    PBAFIR_RESERVED_42           = 42,
    PBAFIR_RESERVED_43           = 43,
    PBAFIR_FIR_PARITY_ERR2       = 44,
    PBAFIR_FIR_PARITY_ERR        = 45
};

extern "C" {

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// function: FAPI p8_pm_pba_firinit  HWP entry point
//           operates on chips passed in i_target argument to perform
//           desired settings of FIRS of OHA macro
// parameters: i_target        => chip target

// returns: FAPI_RC_SUCCESS if all specified operations complete successfully,
//          else return code for failing operation
//------------------------------------------------------------------------------
fapi::ReturnCode
p8_pm_pba_firinit(const fapi::Target& i_target, uint32_t mode );


} // extern "C"


