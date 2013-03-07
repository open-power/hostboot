/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_pba_init.C $           */
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
/* begin_generated_IBM_copyright_prolog                            */
/*                                                                 */
/* This is an automatically generated copyright prolog.            */
/* After initializing,  DO NOT MODIFY OR MOVE                      */ 
/* --------------------------------------------------------------- */
/* IBM Confidential                                                */
/*                                                                 */
/* Licensed Internal Code Source Materials                         */
/*                                                                 */
/* (C)Copyright IBM Corp.  2014, 2014                              */
/*                                                                 */
/* The Source code for this program is not published  or otherwise */
/* divested of its trade secrets,  irrespective of what has been   */
/* deposited with the U.S. Copyright Office.                       */
/*  -------------------------------------------------------------- */
/*                                                                 */
/* end_generated_IBM_copyright_prolog                              */
// $Id: p8_pba_init.C,v 1.7 2012/10/25 11:59:45 kgungl Exp $
// $Source: /afs/awd.austin.ibm.com/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pba_init.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Klaus P. Gungl         Email: kgungl@de.ibm.com
// *!  
// *! 
/// \file p8_pba_init.C
/// \brief Initialize PBA registers for modes PM_INIT, PM_RESET and PM_CONFIG 
// *!        
// *! Functional description: setup the PBA registers depending on mode
// *!   calling parameters:   
// *! :   Target i_target  // target according to calling conventions
// *!     uint64_t mode    // mode according to power_up spec: PM_CONFIG, PM_INIT, PM_RESET
// *! 
// *! high level flow:
// *!  if (mode == PM_CONFIG) { 
// *!      rc =  p8_pba_init_PM_CONFIG(i_target); 
// *!   } else {
// *!       if (mode == PM_INIT) { 
// *!          rc =  p8_pba_init_PM_INIT(i_target); 
// *!       } else { 
// *!          if (mode == PM_RESET) { 
// *!             rc =  p8_pba_init_PM_RESET(i_target); 
// *!          } else {
// *!             FAPI_SET_HWP_ERROR(rc,RC_P8_PBA_INIT_INCORRECT_MODE);
// *!          }  
// *!       }
// *!    } // endif
// *! } // endif  
// *!  
// *!  
// *! list of changes
// *! 2012/10/11 applied changes and error corrections according to Terry Opie and reformatting if-else
// *! 2012/10/11 applied changes according to Terry Opie
// *! 2012/07/26 applied the changes as recommended by Greg's second review, pbax attributes included, 
// *! 2012/07/18 applied the changes as recommended by Greg, attribute coding, TODO: correct constants
// *! 2012/05/09 global variables removed, "mode" used according to common rules.  
// *! 2012/05/17 temporary commented out the accesses assumed wrong address   
// *!
//------------------------------------------------------------------------------

    
// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <fapi.H>
#include "p8_scom_addresses.H"
#include "p8_pba_init.H"
#include "pba_firmware_register.H" 
#include "p8_pm.H"
#include <ecmdDataBufferBase.H>

// get the constants from here
// #include "pgp_pba.h"
// #include "pgp_common.h" 
  
extern "C" {
 
using namespace fapi;  

// ----------------------------------------------------------------------
// Constant definitions
// ----------------------------------------------------------------------
// constant definitions are currently in the *.h files, need to consolidate?

// move the following to p8_scom_addresses.H 
// CONST_UINT64_T( PBAXSNDTX_00064020    , ULL(0x00064020) );
// CONST_UINT64_T( PBAXCFG_00064021      , ULL(0x00064021) );
// CONST_UINT64_T( PBAXSHBR0_00064026    , ULL(0x00064026) );
// CONST_UINT64_T( PBAXSHBR1_0006402A    , ULL(0x0006402A) );

  // from  "pgp_pba.h" "pgp_common.h" 
////////////////////////////////////
// Macros for fields of PBA_SLVCTLn
////////////////////////////////////

// PBA write Ttypes

#define PBA_WRITE_TTYPE_DMA_PR_WR    0x0 /// DMA Partial Write
#define PBA_WRITE_TTYPE_LCO_M        0x1 /// L3 LCO, Tsize denotes chiplet
#define PBA_WRITE_TTYPE_ATOMIC_RMW   0x2 /// Atomic operations
#define PBA_WRITE_TTYPE_CACHE_INJECT 0x3 /// ?
#define PBA_WRITE_TTYPE_CI_PR_W      0x4 /// Cache-inhibited partial write for Centaur putscom().

#define PBA_WRITE_TTYPE_DC PBA_WRITE_TTYPE_DMA_PR_WR // Don't care

#define PBA_OCI_REGION 0

#define PBA_BCE_OCI_TRANSACTION_32_BYTES 0
#define PBA_BCE_OCI_TRANSACTION_64_BYTES 1
#define PBA_BCE_OCI_TRANSACTION_8_BYTES  2

#define PBA_OCI_MARKER_BASE 0x40070000

#define PBA_SLAVE_PORE_GPE 0    /* GPE0/1, but only 1 can access mainstore */
#define PBA_SLAVE_OCC      1	/* 405 I- and D-cache */
#define PBA_SLAVE_PORE_SLW 2	
#define PBA_SLAVE_OCB      3

#define OCI_MASTER_ID_PORE_GPE 0
#define OCI_MASTER_ID_PMC      1
#define OCI_MASTER_ID_PBA      2
#define OCI_MASTER_ID_UNUSED   3
#define OCI_MASTER_ID_PORE_SLW 4
#define OCI_MASTER_ID_OCB      5
#define OCI_MASTER_ID_OCC_ICU  6
#define OCI_MASTER_ID_OCC_DCU  7

// PBA write gather timeouts are defined in terms of the number of 'pulses'. A
// pulse occurs every 64 OCI cycles. The timing of the last write of a
// sequence is variable, so the timeout will occur somewhere between (N - 1) *
// 64 and N * 64 OCI cycles.  If write gather timeouts are disabled, the PBA
// holds the data until some condition occurs that causes it to disgorge the
// data. Slaves using cache-inhibited partial write never gather write
// data. Note from spec. : "Write gather timeouts must NOT be disabled if
// multiple masters are enabled to write through the PBA".  The only case
// where write gather timeouts will be disabled is for the IPL-time injection
// of data into the L3 caches.

#define PBA_WRITE_GATHER_TIMEOUT_DISABLE   0x0
#define PBA_WRITE_GATHER_TIMEOUT_2_PULSES  0x4
#define PBA_WRITE_GATHER_TIMEOUT_4_PULSES  0x5
#define PBA_WRITE_GATHER_TIMEOUT_8_PULSES  0x6
#define PBA_WRITE_GATHER_TIMEOUT_16_PULSES 0x7

/// PBA write gather timeout don't care assignment
#define PBA_WRITE_GATHER_TIMEOUT_DC PBA_WRITE_GATHER_TIMEOUT_2_PULSES


// PBA read Ttype

#define PBA_READ_TTYPE_CL_RD_NC      0x0 /// Cache line read
#define PBA_READ_TTYPE_CI_PR_RD      0x1 /// Cache-inhibited partial read for Centaur getscom().

/// PBA read TTYPE don't care assignment
#define PBA_READ_TTYPE_DC PBA_READ_TTYPE_CL_RD_NC      
  

// PBA read prefetch options

#define PBA_READ_PREFETCH_AUTO_EARLY  0x0 /// Aggressive prefetch
#define PBA_READ_PREFETCH_NONE        0x1 /// No prefetch
#define PBA_READ_PREFETCH_AUTO_LATE   0x2 /// Non-aggressive prefetch

/// PBA read prefetch don't care assignment
#define PBA_READ_PREFETCH_DC PBA_READ_PREFETCH_NONE  


// ----------------------------------------------------------------------
// Global variables
// ----------------------------------------------------------------------
// mandated: do not use global variables

// ----------------------------------------------------------------------
// local Function definitions / prototypes
// ----------------------------------------------------------
ReturnCode p8_pba_init_PM_CONFIG ( const Target& i_target );
ReturnCode p8_pba_init_PM_INIT ( const Target& i_target );
ReturnCode p8_pba_init_PM_RESET ( const Target& i_target );

ReturnCode pba_slave_setup_init ( const Target& i_target );
ReturnCode pba_slave_setup_reset ( const Target& i_target );

  // from pgp_pba.h
int pba_slave_reset(int id);


// **********************************************************************************************
// ----------------------------------------------- p8_pba_init --------------------------------
// function: 
// set the pba registers depending on "mode", no default mode
// returns: fapi return codes
ReturnCode
p8_pba_init(const Target& i_target, 
                uint64_t mode
             )
{
ReturnCode rc;
// calling the selected function from here
 
 if (mode == PM_CONFIG) { 
    rc =  p8_pba_init_PM_CONFIG(i_target); 
 } else {
    if (mode == PM_INIT) { 
       rc =  p8_pba_init_PM_INIT(i_target); 
    } else { 
       if (mode == PM_RESET) { 
          rc =  p8_pba_init_PM_RESET(i_target); 
       } else {
          FAPI_SET_HWP_ERROR(rc,RC_P8_PBA_INIT_INCORRECT_MODE);
       } // endif
    } // endif
 } // endif

 return rc;
}

// **********************************************************************************************
 // ******************************************************** mode = PM_RESET ********************

ReturnCode
  p8_pba_init_PM_RESET(const Target& i_target)
  {

 ReturnCode rc;
 ecmdDataBufferBase data(64);
 uint32_t l_rc;              // local returncode

            
 //  if (mode == PM_RESET) {
   FAPI_INF("mode = PM_RESET..\n");
   l_rc =  data.setDoubleWord(0, 0x0);
   if (l_rc) 
   { 
      FAPI_ERR("data.setDoubleWord ( ) failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    
   } // end if
 

   // For reset phase, write these with 0x0
   // No content for config or init phase as all initialization is done by OCC FW   
   rc = fapiPutScom(i_target, PBA_BCDE_CTL_0x00064010 , data);
   if (rc) 
   {  
      FAPI_ERR("fapiPutScom(PBA_BCDE_CTL_0x00064010  ) failed. With rc = 0x%x", (uint32_t)rc); return rc; 
   }  else 
   {
      FAPI_INF("Done with PBA_BCDE_CTL_0x00064010  \n "); 
   }  // end if-else

   rc = fapiPutScom(i_target, PBA_BCDE_SET_0x00064011 , data);
   if (rc) 
   {  
      FAPI_ERR("fapiPutScom( PBA_BCDE_SET_0x00064011 ) failed. With rc = 0x%x", (uint32_t)rc); return rc; 
   } else 
   {
      FAPI_INF("Done with PBA_BCDE_SET_0x00064011  \n "); 
   } // end if-else

   rc = fapiPutScom(i_target, PBA_BCDE_STAT_0x00064012 , data);
   if (rc) 
   {  
      FAPI_ERR("fapiPutScom( PBA_BCDE_STAT_0x00064012 ) failed. With rc = 0x%x", (uint32_t)rc); return rc; 
   } else 
   {
      FAPI_INF("Done with PBA_BCDE_STAT_0x00064012  \n "); 
   } // end if-else

   rc = fapiPutScom(i_target, PBA_BCDE_PBADR_0x00064013 , data);
   if (rc) 
   {  
      FAPI_ERR("fapiPutScom( PBA_BCDE_PBADR_0x00064013 ) failed. With rc = 0x%x", (uint32_t)rc); return rc; 
   } else 
   {
      FAPI_INF("Done with PBA_BCDE_PBADR_0x00064013  \n "); 
   }

   rc = fapiPutScom(i_target, PBA_BCDE_OCIBAR_0x00064014 , data);
   if (rc) 
   {  
      FAPI_ERR("fapiPutScom( PBA_BCDE_OCIBAR_0x00064014 ) failed. With rc = 0x%x", (uint32_t)rc); return rc; 
   } else 
   {
      FAPI_INF("Done with PBA_BCDE_OCIBAR_0x00064014  \n "); 
   }

   rc = fapiPutScom(i_target, PBA_BCUE_CTL_0x00064015 , data);
   if (rc) 
   {  
      FAPI_ERR("fapiPutScom( PBA_BCUE_CTL_0x0006401 ) failed. With rc = 0x%x", (uint32_t)rc); return rc; 
   } else 
   {
      FAPI_INF("Done with PBA_BCUE_CTL_0x00064015  \n "); 
   }

   rc = fapiPutScom(i_target, PBA_BCUE_SET_0x00064016 , data);
   if (rc) 
   {  
      FAPI_ERR("fapiPutScom( PBA_BCUE_SET_0x00064016 ) failed. With rc = 0x%x", (uint32_t)rc); return rc; 
   } else 
   {
      FAPI_INF("Done with PBA_BCUE_SET_0x00064016  \n "); 
   } // end if-else

   rc = fapiPutScom(i_target, PBA_BCUE_STAT_0x00064017 , data);
   if (rc) 
   {  
      FAPI_ERR("fapiPutScom(PBA_BCUE_STAT_0x00064017  ) failed. With rc = 0x%x", (uint32_t)rc); return rc; 
   } else 
   {
      FAPI_INF("Done with PBA_BCUE_STAT_0x00064017  \n "); 
   } // end if-else

   rc = fapiPutScom(i_target, PBA_BCUE_PBADR_0x00064018 , data);
   if (rc) 
   {  
      FAPI_ERR("fapiPutScom(PBA_BCUE_PBADR_0x00064018  ) failed. With rc = 0x%x", (uint32_t)rc); return rc; 
   } else 
   {
      FAPI_INF("Done with PBA_BCUE_PBADR_0x00064018  \n "); 
   } // end if-else

   rc = fapiPutScom(i_target, PBA_BCUE_OCIBAR_0x00064019 , data);
   if (rc) 
   {  
      FAPI_ERR("fapiPutScom( PBA_BCUE_OCIBAR_0x00064019  ) failed. With rc = 0x%x", (uint32_t)rc); return rc; 
   } else 
   {
      FAPI_INF("Done with PBA_BCUE_OCIBAR_0x00064019  \n "); 
   }  // end if-else 
 
   // For reset, written with 0x0s to restore to fresh value.
   rc = fapiPutScom(i_target, PBA_SLVCTL0_0x00064004 , data);
   if (rc) 
   {  
      FAPI_ERR("fapiPutScom( PBA_SLVCTL0_0x00064004 ) failed. With rc = 0x%x", (uint32_t)rc); return rc; 
   } else 
   {
      FAPI_INF("Done with PBA_SLVCTL0_0x0006400  \n "); 
   }   // end if-else

   rc = fapiPutScom(i_target, PBA_SLVCTL1_0x00064005 , data);
   if (rc) 
   {  
      FAPI_ERR("fapiPutScom( PBA_SLVCTL1_0x00064005 ) failed. With rc = 0x%x", (uint32_t)rc); return rc; 
   } else 
   {
      FAPI_INF("Done with PBA_SLVCTL1_0x00064005  \n "); 
   }  // end if-else

   rc = fapiPutScom(i_target, PBA_SLVCTL2_0x00064006 , data);
   if (rc) 
   {  
      FAPI_ERR("fapiPutScom(  PBA_SLVCTL2_0x00064006 ) failed. With rc = 0x%x", (uint32_t)rc); return rc; 
   } else 
   {
      FAPI_INF("Done with PBA_SLVCTL2_0x00064006  \n "); 
   } // end if-else

   rc = fapiPutScom(i_target, PBA_SLVCTL3_0x00064007 , data);
   if (rc) 
   {  
      FAPI_ERR("fapiPutScom( PBA_SLVCTL3_0x00064007 ) failed. With rc = 0x%x", (uint32_t)rc); return rc; 
   } else 
   {
      FAPI_INF("Done with PBA_SLVCTL3_0x00064007  \n "); 
   } // end if-else

   // Clear the PBA FIR (Reset) only
   l_rc = data.setDoubleWord(0, 0x0);
   if (l_rc) 
   { 
      FAPI_ERR("data.setDoubleWord ( ) failed. With rc = 0x%x", (uint32_t)l_rc); rc.setEcmdError(l_rc); return rc;    
   }   // end if
   rc = fapiPutScom(i_target, PBA_FIR_0x02010840   , data);
   if (rc) 
   {  
      FAPI_ERR("fapiPutScom( PBA_FIR_0x02010840 ) failed. With rc = 0x%x", (uint32_t)rc); return rc; 
   } else 
   {
      FAPI_DBG("Done with PBA_FIR_0x02010840 \n "); 
   } // end if-else

 // For reset, this register should be written with the value from figtree to restore the initial hardware state. 
 // Therefore fix this constant:
 // For init, needs detailing for performance and/or CHSW enable/disable
 // reset case
   // data still 0
   rc = fapiPutScom(i_target, PBA_CONFIG_0x0201084B  , data);
   if (rc) 
   {  
      FAPI_ERR("fapiPutScom( PBA_CONFIG_0x0201084B  ) failed. With rc = 0x%x", (uint32_t)rc); return rc; 
   } else 
   {
      FAPI_INF("Done with, PBA_CONFIG_0x0201084B   \n "); 
   } // end if-else 

   // pba slave register handling for PM_RESET
   rc = pba_slave_setup_reset(i_target);
   if (rc) 
   {  
      FAPI_ERR("pba_slave_setup_reset failed. With rc = 0x%x", (uint32_t)rc); return rc; 
   } else 
   {
      FAPI_INF("Done with, pba_slave_setup_reset   \n "); 
   }  // end if-else

   // For reset, written with 0x0s to restore to fresh value.
   rc = fapiPutScom(i_target, PBA_ERR_RPT0_0x0201084C  , data);
   if (rc) 
   {  
      FAPI_ERR("fapiPutScom( PBA_ERR_RPT0_0x0201084C ) failed. With rc = 0x%x", (uint32_t)rc); return rc; 
   } else 
   {
      FAPI_INF("Done with PBA_ERR_RPT0_0x0201084C  \n "); 
   } // end if-else
   // the following operations are not required, keep this in mind, don't erase them here
   //    l_rc = fapiPutScom(i_target, PBA_ERR_RPT1_0x0201084D  , data);
   //    if(l_rc) { FAPI_SET_HWP_ERROR(l_rc, RC_PROC_PBA_INIT_PUTSCOM_FAILED); return l_rc; }
   //      else {FAPI_INF("Done with PBA_ERR_RPT1_0x0201084D  \n ") };

   //    l_rc = fapiPutScom(i_target, PBA_ERR_RPT2_0x0201084E   , data);
   //     if(l_rc) { FAPI_SET_HWP_ERROR(l_rc, RC_PROC_PBA_INIT_PUTSCOM_FAILED); return l_rc; }
   //       else {FAPI_INF("Done with PBA_ERR_RPT2_0x0201084E  \n ") };


   // The following apply to Reset mode (
   rc = fapiPutScom(i_target, PBA_SLVRST_0x00064001 , data);
   if (rc) {  FAPI_ERR("fapiPutScom( PBA_SLVRST_0x00064001 ) failed. With rc = 0x%x", (uint32_t)rc); return rc; } 
      else {FAPI_INF("Done with PBA_SLVRST_0x00064001  \n "); }
 
    // last step: pba slave setup for reset
    rc = pba_slave_setup_reset (i_target);
    if (rc) {  FAPI_ERR("fapi pba_slave_setup_reset failed. With rc = 0x%x", (uint32_t)rc); return rc; }
      else {FAPI_INF("Done with fapi pba_slave_setup_reset \n "); }

   return rc;

 } // endif (mode == PM_RESET)
  

  
 // ***********************************************************************************************
 // ************************************************************ mode = PM_INIT *******************
 // call pba_slave_setup
 ReturnCode
  p8_pba_init_PM_INIT(const Target& i_target)
  {

 ReturnCode rc;
 ecmdDataBufferBase data(64);
 uint32_t l_rc;              // local returncode

  uint8_t ATTR_PM_PBAX_RCV_RESERV_TIMEOUT_value = 0 ;
  uint8_t ATTR_PM_PBAX_SND_RETRY_COUNT_OVERCOMMIT_ENABLE_value = 0 ;
  uint8_t ATTR_PM_PBAX_SND_RETRY_THRESHOLD_value = 0 ;
  uint8_t ATTR_PM_PBAX_SND_RESERV_TIMEOUT_value = 0 ;

  pbaxcfg_t pbaxcfg_setup ;

 // if (mode == PM_INIT) {
   FAPI_INF("mode = PM_INIT..\n");
   l_rc =  data.setDoubleWord(0, 0x0);
   if (l_rc) 
   { 
      FAPI_ERR("data.setDoubleWord ( ) failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    
   } // end if  
   // For reset, this register should be written with the value from figtree to restore the
   // initial hardware state.
   // For init, needs detailing for performance and/or CHSW enable/disable TODO
   // init case
   rc = fapiPutScom(i_target, PBA_CONFIG_0x0201084B  , data);
   if (rc) 
   {  
      FAPI_ERR("fapiPutScom( PBA_CONFIG_0x0201084B ) failed. With rc = 0x%x", (uint32_t)rc); return rc; 
   }  else 
   {
      FAPI_INF("Done with, PBA_CONFIG_0x0201084B   \n "); 
   }  // end if-else

   // Clear the PBA FIR (Reset) only
   // data still 0
   rc = fapiPutScom(i_target, PBA_FIR_0x02010840   , data);
   if (rc) 
   {  
      FAPI_ERR("fapiPutScom( PBA_FIR_0x02010840 ) failed. With rc = 0x%x", (uint32_t)rc); return rc; 
   } else 
   {
      FAPI_DBG("Done with PBA_FIR_0x02010840 \n "); 
   } // end if-else

   // The following registers are ROX, hence need not be touched:
   // PBA_RBUFVAL0_0x02010850
   // PBA_RBUFVAL1_0x02010851
   // PBA_RBUFVAL2_0x02010852
   // PBA_RBUFVAL3_0x02010853
   // PBA_RBUFVAL4_0x02010854
   // PBA_RBUFVAL5_0x02010855
   // PBA_WBUFVAL0_0x02010858
   // PBA_WBUFVAL1_0x02010859

   // These PowerBus Overcommit regs are read-only, therefore no action required:
   // PBA_PBOCR0_0x00064020
   // PBA_PBOCR1_0x00064021
   // PBA_PBOCR2_0x00064022
   // PBA_PBOCR3_0x00064023
   // PBA_PBOCR4_0x00064024
   // PBA_PBOCR5_0x0006402

   // The PBA BARs and their associated Masks are done outside of this FAPI set.  Thus, during
   // a reset, the BARS/MASKS are retained. this applies to
   // PBA_BAR0_0x02013F00
   // PBA_BARMSK0_0x02013F04
   // PBA_BARMSK1_0x02013F05
   // PBA_BAR1_0x02013F01
   // PBA_BAR2_0x02013F02
   // PBA_BAR3_0x02013F03
   // PBA_TRUSTMODE_0x02013F08   

   // any checkreads => NO

    rc = FAPI_ATTR_GET ( ATTR_PM_PBAX_RCV_RESERV_TIMEOUT   , &i_target, ATTR_PM_PBAX_RCV_RESERV_TIMEOUT_value  );
    if (rc) 
    {  
       FAPI_ERR("fapi_attr_get( ATTR_PM_PBAX_RCV_RESERV_TIMEOUT ) failed. With rc = 0x%x", (uint32_t)rc); return rc; 
    } // end if

    rc = FAPI_ATTR_GET ( ATTR_PM_PBAX_SND_RETRY_COUNT_OVERCOMMIT_ENABLE   , &i_target, ATTR_PM_PBAX_SND_RETRY_COUNT_OVERCOMMIT_ENABLE_value );
    if (rc) 
    {  
       FAPI_ERR("fapi_attr_get( ATTR_PM_PBAX_SND_RETRY_COUNT_OVERCOMMIT_ENABL ) failed. With rc = 0x%x", (uint32_t)rc); return rc; 
    } // end if

    rc = FAPI_ATTR_GET ( ATTR_PM_PBAX_SND_RETRY_THRESHOLD , &i_target, ATTR_PM_PBAX_SND_RETRY_THRESHOLD_value  ); 
    if (rc) 
    {  
       FAPI_ERR("fapi_attr_get( ATTR_PM_PBAX_SND_RETRY_THRESHOLD ) failed. With rc = 0x%x", (uint32_t)rc); return rc; 
    } // end if

    rc = FAPI_ATTR_GET ( ATTR_PM_PBAX_SND_RESERV_TIMEOUT  , &i_target, ATTR_PM_PBAX_SND_RESERV_TIMEOUT_value ); 
    if (rc) 
    {  
       FAPI_ERR("fapi_attr_get( ATTR_PM_PBAX_SND_RESERV_TIMEOU ) failed. With rc = 0x%x", (uint32_t)rc); return rc; 
    } // end if
  
    // assemble the attributes
    // 20:24, ATTR_PM_PBAX_RCV_RESERV_TIMEOUT_value
    // 27; ATTR_PM_PBAX_SND_RETRY_COUNT_OVERCOMMIT_ENABLE_value
    // 28:35; ATTR_PM_PBAX_SND_RETRY_THRESHOLD_value
    // 36:40  ATTR_PM_PBAX_SND_RESERV_TIMEOUT_value
    pbaxcfg_setup.fields.ATTR_PM_PBAX_RCV_RESERV_TIMEOUT = ATTR_PM_PBAX_RCV_RESERV_TIMEOUT_value;
    pbaxcfg_setup.fields.ATTR_PM_PBAX_SND_RETRY_COUNT_OVERCOMMIT_ENABLE = ATTR_PM_PBAX_SND_RETRY_COUNT_OVERCOMMIT_ENABLE_value;
    pbaxcfg_setup.fields.ATTR_PM_PBAX_SND_RETRY_THRESHOLD = ATTR_PM_PBAX_SND_RETRY_THRESHOLD_value;
    pbaxcfg_setup.fields.ATTR_PM_PBAX_SND_RESERV_TIMEOUT = ATTR_PM_PBAX_SND_RESERV_TIMEOUT_value;

    // put the attribute values into PBAXCFG
    l_rc = data.setDoubleWord(0, pbaxcfg_setup.value); 
    if (l_rc) 
    { 
       FAPI_ERR("data.setDoubleWord ( ) failed. With rc = 0x%x", (uint32_t)l_rc); rc.setEcmdError(l_rc); return rc;    
    }  // end if
    rc = fapiPutScom(i_target, PBAXCFG_00064021   , data);
    if (rc) 
    {  
       FAPI_ERR("fapiPutScom(PBAXCFG_00064021) failed. With rc = 0x%x", (uint32_t)rc); return rc; 
    }  else 
    { 
       FAPI_INF("Done with attr_pbaxsndtx_value ");  
    } // end if-else
  
    // last step: pba slave setup for init
    rc = pba_slave_setup_init (i_target);
    if (rc) 
    {  
       FAPI_ERR("fapi pba_slave_setup_init failed. With rc = 0x%x", (uint32_t)rc); return rc; 
    } else 
    {
       FAPI_INF("Done with api_pba_slave_init \n "); 
    } // end if-else

    return rc;

 } // end PM_INIT

  
 // *************************************************************************************************
 // ************************************************************* mode = PM_CONFIG ******************
 //  
 /// Configuration:  perform translation of any Platform Attributes into
 /// Feature Attributes that are applied during Initalization of PBAX
 ReturnCode
  p8_pba_init_PM_CONFIG(const Target& i_target)
  {
    ReturnCode rc;
    ecmdDataBufferBase data(64);
    uint32_t l_rc;              // local returncode
    FAPI_INF("mode = PM_CONFIG..\n");
    l_rc = data.setDoubleWord(0, 0x0);
    if (l_rc) { FAPI_ERR("data.setDoubleWord ( ) failed. With rc = 0x%x", (uint32_t)l_rc); rc.setEcmdError(l_rc); return rc; }   

    FAPI_INF("PBAX configuration...");
    FAPI_INF("Getting PBAX configuration values via attribute settings."); 
 
 return rc;
}; 


// ************************************************************************************************
// **************************************************** pba_slave_setup ***************************
/// PgP PBA Setup
///
/// The PBA is 'set up' twice. The first set up is via scan-0 settings or
/// SBE-IPL code to enable the Host Boot image to be injected into the cache
/// of the IPL core.
///
/// This procedure documents the second setup that will normally be done by a
/// FAPI procedure prior to releasing the OCC from reset.  This setup serves
/// both for the initial boot of OCC as well as for the OCC (GPE), SLW and FSP
/// runtime.  This procedure documents how the PBA should be set up the second
/// time.
///
/// PBA slave 0 is reserved to the GPE engines, which must be able to switch
/// modes to read from mainstore or Centaur inband SCOM spaces, and write
/// Centaur inband SCOMs and also write into mainstore using IMA to support
/// the Power Proxy Trace application.
///
/// PBA slave 1 is dedicated to the 405 ICU/DCU. This PBA slave is used for
/// the initial boot, and for the initial runtime code that manages the OCC
/// applet table.  Once OCC has initialzied applets, OCC FW will remove all
/// TLB mappings associated with mainstore, effectively disabling this slave.
///
/// PBA Slave 2 is dedicated to the PORE-SLW.  Since 24x7 performance
/// monitoring code now runs on PORE-SLW, the PORE-SLW is no longer a
/// read-only master, but instead serves as a generic read-write master like
/// all of the others.
///
/// PBA Slave 3 is mapped to the OCB in order to service FSP direct read/write
/// of mainstore.
///
/// The design of PBA allows read buffers to be dedicated to a particular
/// slave, and requires that a slave have a dedicated read buffer in order to
/// do aggressive prefetching. In the end there is little reason to partition
/// the resources.  The PORE-SLW will be running multiple applications that
/// read and write main memory so we want to allow PORE-SLW access to all
/// resources.  It also isn't clear that aggressive prefetching provides any
/// performacne boost. Another wrinkle is that the BCDE claims read buffer C
/// whenever it runs, and the 405 I + D sides never run after the initial OCC
/// startup. For these reasons all slaves are programmed to share all
/// resources.
///
/// \bug Need to disable slave prefetch for now for all shared buffers until a
/// mode bit gets added too the PBA logic.
///
/// \bug The dis_slvmatch_order bit is going away

ReturnCode
pba_slave_setup_init(const Target& i_target)
{
    pba_mode_t pm;
    pba_slvctln_t ps;
    ReturnCode rc;
    uint32_t l_rc;              // local returncode
    ecmdDataBufferBase data(64);

    // Set the PBA_MODECTL register. It's not yet clear how PBA BCE
    // transaction size will affect performance - for now we go with the
    // largest size.  The HTM marker space is enabled and configured. Slave
    // fairness is enabled. The setting 'dis_slvmatch_order' ensures that PBA
    // will correctly flush write data before allowing a read of the same
    // address from a different master on a different slave.  The second write
    // buffer is enabled.
    // prepare the value to be set:
    pm.value = 0;
    pm.fields.pba_region = PBA_OCI_REGION;
    pm.fields.bcde_ocitrans = PBA_BCE_OCI_TRANSACTION_64_BYTES;
    pm.fields.bcue_ocitrans = PBA_BCE_OCI_TRANSACTION_64_BYTES;
    pm.fields.en_marker_ack = 1; 
    pm.fields.oci_marker_space = (PBA_OCI_MARKER_BASE >> 16) & 0x7;
    pm.fields.en_slave_fairness = 1; 
    pm.fields.dis_slvmatch_order = 1; 
    pm.fields.en_second_wrbuf = 1;

    l_rc = data.setDoubleWord(0, pm.value);
    if (l_rc) 
    { 
       FAPI_ERR("data.setDoubleWord ( ) failed. With rc = 0x%x", (uint32_t)l_rc);   rc.setEcmdError(l_rc); return rc;    
    }

    // write the prepared value
    rc = fapiPutScom(i_target, PBA_MODE_0x00064000 , data);
    if (rc) 
    {  
       FAPI_ERR("fapiPutScom( PBA_MODE_0x00064000 ) failed. With rc = 0x%x", (uint32_t)rc); return rc; 
    } else 
    {
       FAPI_INF("Done with PBA_MODE \n "); 
    } // end if-else


    // Slave 0 (PORE-GPE).  This is a read/write slave. We only do 'static'
    // setup here. Dynamic setup will be done by each GPE program that needs
    // to access mainstore, before issuing any trasactions targeting the PBA
    // bridge.  

    //   pba_slave_reset(PBA_SLAVE_PORE_GPE);
    ps.value = 0;
    ps.fields.enable = 1;
    ps.fields.mid_match_value = OCI_MASTER_ID_PORE_GPE;
    ps.fields.mid_care_mask = 0x7;
    ps.fields.buf_alloc_a = 1;
    ps.fields.buf_alloc_b = 1;
    ps.fields.buf_alloc_c = 1;
    ps.fields.buf_alloc_w = 1;
    l_rc = data.setDoubleWord(0, ps.value);
    if (l_rc) 
    { 
       FAPI_ERR("data.setDoubleWord ( ) failed. With rc = 0x%x", (uint32_t)l_rc);   rc.setEcmdError(l_rc); return rc;    
    } // end if  
    rc = fapiPutScom(i_target, PBA_SLVCTL0_0x00064004 , data);
    if (rc) 
    {  
       FAPI_ERR("fapiPutScom( PBA_SLVCTL0_0x00064004 ) failed. With rc = 0x%x", (uint32_t)rc); return rc; 
    } else 
    { 
       FAPI_INF("Done with PBA_MODE \n "); 
    } // end if-else

    // Slave 1 (405 ICU/DCU).  This is a read/write slave.  Write gethering is
    // allowed, but with the shortest possible timeout. This slave is
    // effectively disabled soon after IPL.

    //    pba_slave_reset(PBA_SLAVE_OCC);
    ps.value = 0;
    ps.fields.enable = 1;
    ps.fields.mid_match_value = OCI_MASTER_ID_OCC_ICU & OCI_MASTER_ID_OCC_DCU;
    ps.fields.mid_care_mask = OCI_MASTER_ID_OCC_ICU & OCI_MASTER_ID_OCC_DCU;
    ps.fields.read_ttype = PBA_READ_TTYPE_CL_RD_NC;
    ps.fields.read_prefetch_ctl = PBA_READ_PREFETCH_NONE;
    ps.fields.write_ttype = PBA_WRITE_TTYPE_DMA_PR_WR;
    ps.fields.wr_gather_timeout = PBA_WRITE_GATHER_TIMEOUT_2_PULSES;
    ps.fields.buf_alloc_a = 1;
    ps.fields.buf_alloc_b = 1;
    ps.fields.buf_alloc_c = 1;
    ps.fields.buf_alloc_w = 1;
    l_rc = data.setDoubleWord(0, ps.value);
    if (l_rc) 
    { 
       FAPI_ERR("data.setDoubleWord ( ) failed. With rc = 0x%x", (uint32_t)l_rc);   rc.setEcmdError(l_rc); return rc;    
    } // end if 
    rc = fapiPutScom(i_target, PBA_SLVCTL1_0x00064005 , data);
    if (rc) 
    {  
       FAPI_ERR("fapiPutScom( PBA_SLVCTL1_0x00064005 ) failed. With rc = 0x%x", (uint32_t)rc); return rc; 
    } else 
    { 
       FAPI_INF("Done with PBA_MODE \n "); 
    } // end if-else


    // Slave 2 (PORE-SLW).  This is a read/write slave. Write gathering is
    // allowed, but with the shortest possible timeout.  The slave is set up
    // to allow normal reads and writes at initialization.  The 24x7 code may
    // reprogram this slave for IMA writes using special code sequences that
    // restore normal DMA writes after each IMA sequence.

    //   pba_slave_reset(PBA_SLAVE_PORE_SLW);
    ps.value = 0;
    ps.fields.enable = 1;
    ps.fields.mid_match_value = OCI_MASTER_ID_PORE_SLW;
    ps.fields.mid_care_mask = 0x7;
    ps.fields.read_ttype = PBA_READ_TTYPE_CL_RD_NC;
    ps.fields.read_prefetch_ctl = PBA_READ_PREFETCH_NONE;
    ps.fields.write_ttype = PBA_WRITE_TTYPE_DMA_PR_WR;
    ps.fields.wr_gather_timeout = PBA_WRITE_GATHER_TIMEOUT_2_PULSES;
    ps.fields.buf_alloc_a = 1;
    ps.fields.buf_alloc_b = 1;
    ps.fields.buf_alloc_c = 1;
    ps.fields.buf_alloc_w = 1;
    l_rc = data.setDoubleWord(0, ps.value);
    if (l_rc) 
    { 
       FAPI_ERR("data.setDoubleWord ( ) failed. With rc = 0x%x", (uint32_t)l_rc);  rc.setEcmdError(l_rc); return rc;    
    } // end if 
    rc = fapiPutScom(i_target, PBA_SLVCTL2_0x00064006 , data);
    if (rc) 
    {  
       FAPI_ERR("fapiPutScom( PBA_SLVCTL2_0x00064006 ) failed. With rc = 0x%x", (uint32_t)rc); return rc; 
    } else 
    {
       FAPI_INF("Done with PBA_MODE \n "); 
    } // end if-else


    // Slave 3 (OCB).  This is a read/write slave. Write gathering is
    // allowed, but with the shortest possible timeout.

    //   pba_slave_reset(PBA_SLAVE_OCB);
    ps.value = 0;
    ps.fields.enable = 1;
    ps.fields.mid_match_value = OCI_MASTER_ID_OCB;
    ps.fields.mid_care_mask = 0x7;
    ps.fields.read_ttype = PBA_READ_TTYPE_CL_RD_NC;
    ps.fields.read_prefetch_ctl = PBA_READ_PREFETCH_NONE;
    ps.fields.write_ttype = PBA_WRITE_TTYPE_DMA_PR_WR;
    ps.fields.wr_gather_timeout = PBA_WRITE_GATHER_TIMEOUT_2_PULSES;
    ps.fields.buf_alloc_a = 1;
    ps.fields.buf_alloc_b = 1;
    ps.fields.buf_alloc_c = 1;
    ps.fields.buf_alloc_w = 1;
    l_rc = data.setDoubleWord(0, ps.value);
    if (l_rc) 
    { 
       FAPI_ERR("data.setDoubleWord ( ) failed. With rc = 0x%x", (uint32_t)l_rc);   rc.setEcmdError(l_rc); return rc;    
    } // end if
    rc = fapiPutScom(i_target, PBA_SLVCTL3_0x00064007 , data);
    if (rc) 
    {  
       FAPI_ERR("fapiPutScom( PBA_SLVCTL3_0x00064007 ) failed. With rc = 0x%x", (uint32_t)rc); return rc; 
    } else 
    {
        
       FAPI_INF("Done with PBA_MODE \n "); 
    } // end if-else

    return rc;
}  // end pba_slave_setup_init


// for reset, set all register contents to zero
ReturnCode
pba_slave_setup_reset(const Target& i_target)
{
    ReturnCode rc;
    uint32_t l_rc;              // local returncode
    ecmdDataBufferBase data(64);

    l_rc= data.setDoubleWord(0, 0x00000000);
    if (l_rc) 
    { 
       FAPI_ERR("data.setDoubleWord ( ) failed. With rc = 0x%x", (uint32_t)l_rc); rc.setEcmdError(l_rc); return rc;    
    } // end if  

    rc = fapiPutScom(i_target, PBA_MODE_0x00064000 , data);
    if (rc) 
    {  
       FAPI_ERR("fapiPutScom( PBA_MODE_0x00064000 ) failed. With rc = 0x%x", (uint32_t)rc); return rc; 
    } else 
    {
       FAPI_INF("Done with PBA_MODE \n "); 
    } // end if-else

    rc = fapiPutScom(i_target, PBA_SLVCTL0_0x00064004 , data);
    if (rc) 
    {  
       FAPI_ERR("fapiPutScom( PBA_SLVCTL0_0x00064004 ) failed. With rc = 0x%x", (uint32_t)rc); return rc; 
    } else 
    {
       FAPI_INF("Done with PBA_MODE \n "); 
    } // end if-else

    rc = fapiPutScom(i_target, PBA_SLVCTL1_0x00064005 , data);
    if (rc) 
    {  
       FAPI_ERR("fapiPutScom( PBA_SLVCTL1_0x00064005 ) failed. With rc = 0x%x", (uint32_t)rc); return rc; 
    } else 
    {
       FAPI_INF("Done with PBA_MODE \n "); 
    } // end if-else

    rc = fapiPutScom(i_target, PBA_SLVCTL2_0x00064006 , data);
    if (rc) 
    {  
       FAPI_ERR("fapiPutScom( PBA_SLVCTL2_0x00064006 ) failed. With rc = 0x%x", (uint32_t)rc); return rc; 
    } else 
    {
       FAPI_INF("Done with PBA_MODE \n "); 
    } // end if-else

    rc = fapiPutScom(i_target, PBA_SLVCTL3_0x00064007 , data);
    if (rc) 
    {  
       FAPI_ERR("fapiPutScom( PBA_SLVCTL3_0x00064007 ) failed. With rc = 0x%x", (uint32_t)rc); return rc; 
    } else 
    {
       FAPI_INF("Done with PBA_MODE \n "); 
    } // end if-else

    return rc;

}  // end pba_slave_setup_reset


} //end extern C

