/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pm_pba_firinit.C $     */
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
// $Id: p8_pm_pba_firinit.C,v 1.15 2013/04/12 01:17:25 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pm_pba_firinit.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Pradeep CN         Email: pradeepcn@in.ibm.com
// *!
// *! General Description:
// *!
// *!   The purpose of this procedure is to ......
// *!
// *!   High-level procedure flow:
// *!     o Set the particluar bits of databuffers action0 , action 1 and mask for the correspoding actions via MACROS
// *!     o Write the action1 , actionn0 and mask registers of FIRs
// *!     o
// *!     o
// *!     o
// *!     o
// *!     o Check if all went well
// *!     o   If so celebrate
// *!     o   Else write logs, set bad return code
// *!
// *!
// *! Procedure Prereq:
// *!   o System clocks are running
// *!
//------------------------------------------------------------------------------



// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <fapi.H>
#include "p8_scom_addresses.H"
#include "p8_pm_pba_firinit.H"

extern "C" {

using namespace fapi;

// ----------------------------------------------------------------------
// Constant definitions
// ----------------------------------------------------------------------


    // \todo move these to p8_scom_addresses after testing
  //   CONST_UINT64_T( PBA_FIR_ACTION1_0x02010847        , ULL(0x02010847)) ;
  //   CONST_UINT64_T( PBA_FIR_ACTION0_0x02010846        , ULL(0x02010846)) ;
   CONST_UINT64_T( PBA_FIR_MASK_WR_0x02010843        , ULL(0x02010843)) ;
   CONST_UINT64_T( PBA_FIR_MASK_WR_AND_0x02010844        , ULL(0x02010844)) ;
   CONST_UINT64_T( PBA_FIR_MASK_WR_OR_0x02010845        , ULL(0x02010845)) ;


// ----------------------------------------------------------------------
// Macro definitions
// ----------------------------------------------------------------------

// #define SET_CHECK_STOP(b){SET_FIR_ACTION(b, 0, 0);}
// #define SET_RECOV_ATTN(b){SET_FIR_ACTION(b, 0, 1);}
// #define SET_RECOV_INTR(b){SET_FIR_ACTION(b, 1, 0);}
// #define SET_MALF_ALERT(b){SET_FIR_ACTION(b, 1, 1);}
// #define SET_FIR_MASKED(b){SET_FIR_MASK(b,1);}

// ----------------------------------------------------------------------
// Global variables
// ----------------------------------------------------------------------

fapi::ReturnCode
p8_pm_pba_firinit(const fapi::Target&  i_target , uint32_t mode )
{

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// function: FAPI p8_pm_pba_firinit  HWP entry point
//           operates on chips passed in i_target argument to perform
//           desired settings of FIRS of PBA macro
// parameters: i_target        => chip target

// returns: FAPI_RC_SUCCESS if all specified operations complete successfully,
//          else return code for failing operation
//------------------------------------------------------------------------------

    fapi::ReturnCode    rc;
    ecmdDataBufferBase  fir(64);
    ecmdDataBufferBase  action_0(64);
    ecmdDataBufferBase  action_1(64);
    ecmdDataBufferBase  mask(64);
    uint32_t            e_rc = 0;

    enum PBA_FIRS
    {
        PBAFIR_OCI_APAR_ERR          =0  ,
        PBAFIR_PB_RDADRERR_FW        =1  ,
        PBAFIR_PB_RDDATATO_FW        =2  ,
        PBAFIR_PB_SUE_FW             =3  ,
        PBAFIR_PB_UE_FW              =4  ,
        PBAFIR_PB_CE_FW              =5  ,
        PBAFIR_OCI_SLAVE_INIT        =6  ,
        PBAFIR_OCI_WRPAR_ERR         =7  ,
        PBAFIR_OCI_REREQTO           =8  ,
        PBAFIR_PB_UNEXPCRESP         =9  ,
        PBAFIR_PB_UNEXPDATA          =10 ,
        PBAFIR_PB_PARITY_ERR         =11 ,
        PBAFIR_PB_WRADRERR_FW        =12 ,
        PBAFIR_PB_BADCRESP           =13 ,
        PBAFIR_PB_ACKDEAD_FW_RD      =14 ,
        PBAFIR_PB_CRESPTO            =15 ,
        PBAFIR_BCUE_SETUP_ERR        =16 ,
        PBAFIR_BCUE_PB_ACK_DEAD      =17 ,
        PBAFIR_BCUE_PB_ADRERR        =18 ,
        PBAFIR_BCUE_OCI_DATERR       =19 ,
        PBAFIR_BCDE_SETUP_ERR        =20 ,
        PBAFIR_BCDE_PB_ACK_DEAD      =21 ,
        PBAFIR_BCDE_PB_ADRERR        =22 ,
        PBAFIR_BCDE_RDDATATO_ERR     =23 ,
        PBAFIR_BCDE_SUE_ERR          =24 ,
        PBAFIR_BCDE_UE_ERR           =25 ,
        PBAFIR_BCDE_CE               =26 ,
        PBAFIR_BCDE_OCI_DATERR       =27 ,
        PBAFIR_INTERNAL_ERR          =28 ,
        PBAFIR_ILLEGAL_CACHE_OP      =29 ,
        PBAFIR_OCI_BAD_REG_ADDR      =30 ,
        PBAFIR_AXPUSH_WRERR          =31 ,
        PBAFIR_AXRCV_DLO_ERR         =32 ,
        PBAFIR_AXRCV_DLO_TO          =33 ,
        PBAFIR_AXRCV_RSVDATA_TO      =34 ,
        PBAFIR_AXFLOW_ERR            =35 ,
        PBAFIR_AXSND_DHI_RTYTO       =36 ,
        PBAFIR_AXSND_DLO_RTYTO       =37 ,
        PBAFIR_AXSND_RSVTO           =38 ,
        PBAFIR_AXSND_RSVERR          =39 ,
        PBAFIR_PB_ACKDEAD_FW_WR      =40 ,
        PBAFIR_RESERVED_41           =41 ,
        PBAFIR_RESERVED_42           =42 ,
        PBAFIR_RESERVED_43           =43 ,
        PBAFIR_FIR_PARITY_ERR2       =44 ,
        PBAFIR_FIR_PARITY_ERR        =45
    };


    FAPI_DBG("Executing p8_pm_pba_firinit  ....");
    do
    {
        if (mode == PM_RESET)
        {

            e_rc  = mask.flushTo0();
            e_rc |= mask.setBit(0, PBA_FIR_REGISTER_LENGTH);
            if (e_rc)
            {
                rc.setEcmdError(e_rc);
                break;
            }

            //--******************************************************************************
            //-- PBA_FIR_MASK (W0_OR_45) (WR_43) (WO_AND_44)
            //--******************************************************************************
            rc = fapiPutScom(i_target, PBA_FIR_MASK_WR_0x02010843, mask );
            if (rc)
            {
	            FAPI_ERR("fapiPutScom(PBA_FIR_MASK_WR_0x02010843) failed.");
                break;
            }
        }
        else
        {
            e_rc |= fir.flushTo0();
            e_rc |= action_0.flushTo0();
            e_rc |= action_1.flushTo0();
            e_rc |= mask.flushTo0()    ;
            if (e_rc)
            {
                rc.setEcmdError(e_rc);
                break;
            }

            SET_RECOV_ATTN  (PBAFIR_OCI_APAR_ERR      ) ; // 0   PBAFIR_OCI_APAR_ERR
            SET_RECOV_ATTN  (PBAFIR_PB_RDADRERR_FW    ) ; // 1   PBAFIR_PB_RDADRERR_FW
            SET_RECOV_ATTN  (PBAFIR_PB_RDDATATO_FW    ) ; // 2   PBAFIR_PB_RDDATATO_FW
            SET_RECOV_ATTN  (PBAFIR_PB_SUE_FW         ) ; // 3   PBAFIR_PB_SUE_FW
            SET_RECOV_ATTN  (PBAFIR_PB_UE_FW          ) ; // 4   PBAFIR_PB_UE_FW
            SET_RECOV_ATTN  (PBAFIR_PB_CE_FW          ) ; // 5   PBAFIR_PB_CE_FW
            SET_RECOV_ATTN  (PBAFIR_OCI_SLAVE_INIT    ) ; // 6   PBAFIR_OCI_SLAVE_INIT
            SET_RECOV_ATTN  (PBAFIR_OCI_WRPAR_ERR     ) ; // 7   PBAFIR_OCI_WRPAR_ERR
            SET_RECOV_ATTN  (PBAFIR_OCI_REREQTO       ) ; // 8   PBAFIR_OCI_REREQTO
            SET_RECOV_ATTN  (PBAFIR_PB_UNEXPCRESP     ) ; // 9   PBAFIR_PB_UNEXPCRESP
            SET_RECOV_ATTN  (PBAFIR_PB_UNEXPDATA      ) ; // 10  PBAFIR_PB_UNEXPDATA
            SET_RECOV_ATTN  (PBAFIR_PB_PARITY_ERR     ) ; // 11  PBAFIR_PB_PARITY_ERR
            SET_RECOV_ATTN  (PBAFIR_PB_WRADRERR_FW    ) ; // 12  PBAFIR_PB_WRADRERR_FW
            SET_RECOV_ATTN  (PBAFIR_PB_BADCRESP       ) ; // 13  PBAFIR_PB_BADCRESP
            SET_RECOV_ATTN  (PBAFIR_PB_ACKDEAD_FW_RD  ) ; // 14  PBAFIR_PB_ACKDEAD_FW_RD
            SET_RECOV_ATTN  (PBAFIR_PB_CRESPTO        ) ; // 15  PBAFIR_PB_CRESPTO
            SET_FIR_MASKED  (PBAFIR_BCUE_SETUP_ERR    ) ; // 16  PBAFIR_BCUE_SETUP_ERR
            SET_FIR_MASKED  (PBAFIR_BCUE_PB_ACK_DEAD  ) ; // 17  PBAFIR_BCUE_PB_ACK_DEAD
            SET_FIR_MASKED  (PBAFIR_BCUE_PB_ADRERR    ) ; // 18  PBAFIR_BCUE_PB_ADRERR
            SET_FIR_MASKED  (PBAFIR_BCUE_OCI_DATERR   ) ; // 19  PBAFIR_BCUE_OCI_DATERR
            SET_FIR_MASKED  (PBAFIR_BCDE_SETUP_ERR    ) ; // 20  PBAFIR_BCDE_SETUP_ERR
            SET_FIR_MASKED  (PBAFIR_BCDE_PB_ACK_DEAD  ) ; // 21  PBAFIR_BCDE_PB_ACK_DEAD
            SET_FIR_MASKED  (PBAFIR_BCDE_PB_ADRERR    ) ; // 22  PBAFIR_BCDE_PB_ADRERR
            SET_FIR_MASKED  (PBAFIR_BCDE_RDDATATO_ERR ) ; // 23  PBAFIR_BCDE_RDDATATO_ERR
            SET_FIR_MASKED  (PBAFIR_BCDE_SUE_ERR      ) ; // 24  PBAFIR_BCDE_SUE_ERR
            SET_FIR_MASKED  (PBAFIR_BCDE_UE_ERR       ) ; // 25  PBAFIR_BCDE_UE_ERR
            SET_FIR_MASKED  (PBAFIR_BCDE_CE           ) ; // 26  PBAFIR_BCDE_CE
            SET_FIR_MASKED  (PBAFIR_BCDE_OCI_DATERR   ) ; // 27  PBAFIR_BCDE_OCI_DATERR
            SET_RECOV_ATTN  (PBAFIR_INTERNAL_ERR      ) ; // 28  PBAFIR_INTERNAL_ERR
            SET_RECOV_ATTN  (PBAFIR_ILLEGAL_CACHE_OP  ) ; // 29  PBAFIR_ILLEGAL_CACHE_OP
            SET_RECOV_ATTN  (PBAFIR_OCI_BAD_REG_ADDR  ) ; // 30  PBAFIR_OCI_BAD_REG_ADDR
            SET_FIR_MASKED  (PBAFIR_AXPUSH_WRERR      ) ; // 31  PBAFIR_AXPUSH_WRERR
            SET_FIR_MASKED  (PBAFIR_AXRCV_DLO_ERR     ) ; // 32  PBAFIR_AXRCV_DLO_ERR
            SET_FIR_MASKED  (PBAFIR_AXRCV_DLO_TO      ) ; // 33  PBAFIR_AXRCV_DLO_TO
            SET_FIR_MASKED  (PBAFIR_AXRCV_RSVDATA_TO  ) ; // 34  PBAFIR_AXRCV_RSVDATA_TO
            SET_FIR_MASKED  (PBAFIR_AXFLOW_ERR        ) ; // 35  PBAFIR_AXFLOW_ERR
            SET_FIR_MASKED  (PBAFIR_AXSND_DHI_RTYTO   ) ; // 36  PBAFIR_AXSND_DHI_RTYTO
            SET_FIR_MASKED  (PBAFIR_AXSND_DLO_RTYTO   ) ; // 37  PBAFIR_AXSND_DLO_RTYTO
            SET_FIR_MASKED  (PBAFIR_AXSND_RSVTO       ) ; // 38  PBAFIR_AXSND_RSVTO
            SET_FIR_MASKED  (PBAFIR_AXSND_RSVERR      ) ; // 39  PBAFIR_AXSND_RSVERR
            SET_RECOV_ATTN  (PBAFIR_PB_ACKDEAD_FW_WR  ) ; // 40  PBAFIR_PB_ACKDEAD_FW_WR
            SET_FIR_MASKED  (PBAFIR_RESERVED_41       ) ; // 41  PBAFIR_RESERVED_41
            SET_FIR_MASKED  (PBAFIR_RESERVED_42       ) ; // 42  PBAFIR_RESERVED_42
            SET_FIR_MASKED  (PBAFIR_RESERVED_43       ) ; // 43  PBAFIR_RESERVED_43
            SET_RECOV_ATTN  (PBAFIR_FIR_PARITY_ERR2   ) ; // 44  PBAFIR_FIR_PARITY_ERR2
            SET_RECOV_ATTN  (PBAFIR_FIR_PARITY_ERR    ) ; // 45  PBAFIR_FIR_PARITY_ERR

            if (e_rc)
            {
                rc.setEcmdError(e_rc);
                break;
            }

            // ---------------
            // PBA_FIR - cleared
            // ---------------
            rc = fapiPutScom(i_target, PBA_FIR_0x02010840, fir);
            if (!rc.ok())
            {
                FAPI_ERR("fapiPutScom(PBA_FIR_0x02010840) failed.");
                 break;
            }            
            
            FAPI_DBG(" action_0  => 0x%16llx ",  action_0.getDoubleWord(0));
            FAPI_DBG(" action_1  => 0x%16llx ",  action_1.getDoubleWord(0));
            FAPI_DBG(" mask      => 0x%16llx ",  mask.getDoubleWord(0));

            //#--******************************************************************************
            //#-- PBA_FIR_ACTION0
            //#--******************************************************************************

            rc = fapiPutScom(i_target, PBA_FIR_ACTION0_0x02010846, action_0 );
            if (rc)
            {
	            FAPI_ERR("fapiPutScom(PBA_FIR_ACTION0_0x02010846) failed.");
                break;
            }

            //#--******************************************************************************
            //#-- PBA_FIR_ACTION1
            //#--******************************************************************************

            rc = fapiPutScom(i_target, PBA_FIR_ACTION1_0x02010847, action_1 );
            if (rc)
            {
	            FAPI_ERR("fapiPutScom(PBA_FIR_ACTION1_0x02010847) failed.");
                break;
            }

            //--******************************************************************************
            //-- PBA_FIR_MASK (W0_OR_45) (WR_43) (WO_AND_44)
            //--******************************************************************************
            rc = fapiPutScom(i_target, PBA_FIR_MASK_WR_0x02010843, mask );
            if (rc)
            {
	            FAPI_ERR("fapiPutScom(PBA_FIR_MASK_WR_0x02010843) failed.");
                 break;
            }
        } // Mode
    } while(0);
    return rc;

} // Procedure

} //end extern C
