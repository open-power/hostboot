/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_slw_build/p8_image_help.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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
// $Id: p8_image_help.C,v 1.28 2012/09/27 20:59:51 cmolsen Exp $
//
/*------------------------------------------------------------------------------*/
/* *! TITLE : p8_image_help.C                                                   */
/* *! DESCRIPTION : Helper functions for building and extracting information    */
//                  from SBE-XIP images.
/* *! OWNER NAME :  Michael Olsen                  cmolsen@us.ibm.com           */
//
/* *! EXTENDED DESCRIPTION :                                                    */
//
/* *! USAGE :                                                                   */
//
/* *! ASSUMPTIONS :                                                             */
//
/* *! COMMENTS :                                                                */
//
/*------------------------------------------------------------------------------*/

#include <p8_delta_scan_rw.h>
#include <p8_pore_table_gen_api.H>
#include <common_scom_addresses.H>

#ifdef __FAPI
#include <fapi.H>
#endif
extern "C"  {


// get_ring_layout_from_image()
//
int get_ring_layout_from_image( const void  *i_imageIn,
                                uint32_t    i_ddLevel,
                                uint8_t     i_sysPhase,
                                DeltaRingLayout  *o_rs4RingLayout,
                                void        **nextRing)
{
  uint32_t rc=0, rcLoc=0;
  uint8_t bRingFound=0, bRingEOS=0;
  DeltaRingLayout *thisRingLayout=NULL, *nextRingLayout=NULL; //Pointers into memory mapped image. DO NOT CHANGE MEMBERS!
  uint32_t sizeInitf;
  SbeXipSection hostSection;
  void     *initfHostAddress0;

  SBE_XIP_ERROR_STRINGS(errorStrings);

  // Always first get the .initf stats from the TOC:
  // - .initf host address offset and
  // - .initf size
  //
  rc = sbe_xip_get_section( i_imageIn, SBE_XIP_SECTION_RINGS, &hostSection);
  if (rc)   {
      MY_ERR("ERROR : sbe_xip_get_section() failed: %s", SBE_XIP_ERROR_STRING(errorStrings, rc));
      MY_ERR("Probable cause:");
      MY_ERR("\tThe section (=SBE_XIP_SECTION_RINGS=%i) was not found.",SBE_XIP_SECTION_RINGS);
      return IMGBUILD_ERR_KEYWORD_NOT_FOUND;
  }
  if (hostSection.iv_offset==0)  {
    MY_INF("INFO : No ring data exists for the section ID = SBE_XIP_SECTION_RINGS (ID=%i).",SBE_XIP_SECTION_RINGS);
    return DSLWB_RING_SEARCH_NO_MATCH; // Implies exhaust search as well.
  }
  initfHostAddress0 = (void*)((uintptr_t)i_imageIn + hostSection.iv_offset);
  sizeInitf = hostSection.iv_size;

  // On first call, get the base offset to the .initf section.
  // On subsequent calls, we're into the search for ddLevel and sysPhase, so use nextRing instead.
  //
  if (*nextRing==NULL)
    nextRingLayout = (DeltaRingLayout*)initfHostAddress0;
  else
    nextRingLayout = (DeltaRingLayout*)*nextRing;

  MY_DBG("initfHostAddress0 = 0x%016llx",(uint64_t)initfHostAddress0);
  MY_DBG("sizeInitf = %i", sizeInitf);
  MY_DBG("nextRingLayout = 0x%016llx",(uint64_t)nextRingLayout);

  // Populate the output RS4 ring BE layout structure as well as local structure in host LE format where needed.
  // Note! Entire memory content is in BE format. So we do LE conversions where needed.
  //
  bRingFound = 0;
  bRingEOS = 0;

  // SEARCH loop:  Parse ring blocks successively until we find a ring that matches:
  //     ddLevel == i_ddLevel
  //     sysPhase == i_sysPhase
  //
  while (!bRingFound && !bRingEOS)  {
    thisRingLayout = nextRingLayout;
    MY_DBG("Next backItemPtr = 0x%016llx",myRev64(thisRingLayout->backItemPtr));
    MY_DBG("Next ddLevel = 0x%02x",myRev32(thisRingLayout->ddLevel));
    MY_DBG("Next sysPhase = %i",thisRingLayout->sysPhase);
    MY_DBG("Next override = %i",thisRingLayout->override);
    MY_DBG("Next reserved1 = %i",thisRingLayout->reserved1);
    MY_DBG("Next reserved2 = %i",thisRingLayout->reserved2);

    if (myRev32(thisRingLayout->ddLevel)==i_ddLevel)  { // Is there a non-specific DD level, like for sys phase?
      if ((thisRingLayout->sysPhase==0 && i_sysPhase==0) ||
          (thisRingLayout->sysPhase==1 && i_sysPhase==1) ||
          (thisRingLayout->sysPhase==2 && (i_sysPhase==0 || i_sysPhase==1)))  {
        bRingFound = 1;
        MY_DBG("\tRing match found!");
      }
    }
    nextRingLayout = (DeltaRingLayout*)((uintptr_t)thisRingLayout + myRev32(thisRingLayout->sizeOfThis));
    *nextRing = (void*)nextRingLayout;
    if (nextRingLayout>=(DeltaRingLayout*)((uintptr_t)initfHostAddress0+sizeInitf))  {
      bRingEOS = 1;
      *nextRing = NULL;
      MY_DBG("\tRing search exhausted!");
    }

  }  // End of SEARCH.

  if (bRingFound)  {
    if (bRingEOS)
      rcLoc = DSLWB_RING_SEARCH_EXHAUST_MATCH;
    else
      rcLoc = DSLWB_RING_SEARCH_MATCH;
  }
  else  {
    *nextRing = NULL;
    if (bRingEOS)
      return DSLWB_RING_SEARCH_NO_MATCH; // Implies exhaust search as well.
    else  {
      MY_ERR("Messed up ring search. Check code and .rings content. Returning nothing.");
      return DSLWB_RING_SEARCH_MESS;
    }
  }

  o_rs4RingLayout->entryOffset = thisRingLayout->entryOffset;
  o_rs4RingLayout->backItemPtr = thisRingLayout->backItemPtr;
  o_rs4RingLayout->sizeOfThis  = thisRingLayout->sizeOfThis;
  o_rs4RingLayout->sizeOfMeta  = thisRingLayout->sizeOfMeta;
  o_rs4RingLayout->ddLevel     = thisRingLayout->ddLevel;
  o_rs4RingLayout->sysPhase    = thisRingLayout->sysPhase;
  o_rs4RingLayout->override    = thisRingLayout->override;
  o_rs4RingLayout->reserved1   = thisRingLayout->reserved1;
  o_rs4RingLayout->reserved2   = thisRingLayout->reserved2;
  o_rs4RingLayout->metaData      =  (char*)(&thisRingLayout->reserved2 +
                                            sizeof(thisRingLayout->reserved2));
  o_rs4RingLayout->rs4Launch    = (uint32_t*)((uintptr_t)thisRingLayout +
                                                myRev64(thisRingLayout->entryOffset));
  // entryOffset, rs4Launch and ASM_RS4_LAUNCH_BUF_SIZE should already be 8-byte aligned.
  o_rs4RingLayout->rs4Delta      = (uint32_t*)( (uintptr_t)thisRingLayout +
                                                myRev64(thisRingLayout->entryOffset) +
                                                ASM_RS4_LAUNCH_BUF_SIZE );

  // Check that the ring layout structure in the memory is 8-byte aligned. This must
	// be so because:
  // - The entryOffset address must be on an 8-byte boundary because the start of the
	//   .rings section must be 8-byte aligned AND because the rs4Delta member is the
	//   last member and which must itself be 8-byte aligned.
  // - These two things together means that both the beginning and end of the delta
	//   ring layout must be 8-byte aligned, and thus the whole block, i.e. sizeOfThis,
	//   must therefore automatically be 8-byte aligned.
  // Also check that the RS4 delta ring is 8-byte aligned.
  // Also check that the RS4 launcher is 8-byte aligned.
  //
  if (((uintptr_t)thisRingLayout-(uintptr_t)i_imageIn)%8 ||
      myRev32(o_rs4RingLayout->sizeOfThis)%8 ||
      myRev64(o_rs4RingLayout->entryOffset)%8 ||
      ASM_RS4_LAUNCH_BUF_SIZE%8)  {
    MY_ERR("ERROR : Ring block or layout structure is not 8-byte aligned:");
    MY_ERR("  thisRingLayout-imageIn = %i",(uintptr_t)thisRingLayout-(uintptr_t)i_imageIn);
    MY_ERR("  o_rs4RingLayout->sizeOfThis = %i",myRev32(o_rs4RingLayout->sizeOfThis));
    MY_ERR("  o_rs4RingLayout->entryOffset = %i",(uint32_t)myRev64(o_rs4RingLayout->entryOffset));
    MY_ERR("  ASM_RS4_LAUNCH_BUF_SIZE = %i",(uint32_t)ASM_RS4_LAUNCH_BUF_SIZE);
    return IMGBUILD_ERR_MISALIGNED_RING_LAYOUT;
  }

  if (*nextRing > (void*)((uintptr_t)initfHostAddress0 + sizeInitf))  {
    MY_INF("INFO : Book keeping got messed up during .initf search. Initf section does not appear aligned.");
    MY_INF("initfHostAddress0+sizeInitf = 0x%016llx",(uint64_t)initfHostAddress0+sizeInitf);
    MY_INF("nextRing = %i",*(uint32_t*)nextRing);
    MY_INF("Continuing...");
  }

  return rcLoc;
}



// create_wiggle_flip_prg() function
// Notes:
// - WF routine implements dynamic P1 multicast bit set based on P0 status.
// - WF routine checks header word on scan complete.
// - WF routine is 8-byte aligned.
int create_wiggle_flip_prg( uint32_t *i_deltaRing,          // scan ring delta state (in BE format)
                            uint32_t i_ringBitLen,          // length of ring
                            uint32_t i_scanSelectData,      // Scan ring modifier data
                            uint32_t i_chipletID,            // Chiplet ID
                            uint32_t **o_wfInline,       // location of the PORE instructions data stream
                            uint32_t *o_wfInlineLenInWords,   // final length of data stream
														uint32_t i_scanMaxRotate)       // Max rotate bit len on 38xxx
{
  uint32_t rc=0;  //defined in p8_pore_api_const.h
  uint32_t i=0;
  uint32_t scanSelectAddr=0;
  uint32_t scanRing_baseAddr=0;
  uint32_t scanRing_poreAddr=0;
  uint32_t scanRingCheckWord=0;
  uint32_t count=0;
  uint32_t rotateLen=0, remainder=0, remainingBits=0;
  uint64_t pore_imm64b=0;
  uint32_t maxWfInlineLenInWords = 3*MAX_RING_SIZE/32;
  PoreInlineContext ctx;

  *o_wfInline = (uint32_t*)malloc(maxWfInlineLenInWords);

  pore_inline_context_create(&ctx, *o_wfInline, maxWfInlineLenInWords * 4, 0, 0);

  // Get chiplet and Ring Addr info.
  // --------------------------------------------------------------------------

  // Set Default scanselq addr and scanring addr vars
  scanSelectAddr=P8_PORE_CLOCK_CONTROLLER_REG;  // 0x00030007: port 3 - clock cotrol endpt, x07- scanselq (regin & types)
                                                // Descr: Addr of clock control SCOM reg.
  scanRing_baseAddr=P8_PORE_SHIFT_REG;          // 0x00038000: port 3, addr bit 16 must be set to 1
                                                // Also called GENERIC_CLK_SCANDATA0
                                                // Descr: SCOM reg for scan ring shifting.
  scanRing_poreAddr=scanRing_baseAddr;          // Init scan ring rotate addr
  scanRingCheckWord=P8_SCAN_CHECK_WORD;          // Header check word for checking ring write was successful

  // This fix is a direct copy of the setp1_mcreadand macro in ./ipl/sbe/p8_slw.H
  uint64_t CLEAR_MC_TYPE_MASK=0x47;
  PoreInlineLocation src1=0, src2=0, tgt1=0, tgt2=0;
  pore_MR( &ctx, D1, P0);
  pore_ANDI( &ctx, D1, D1, BIT(57));
  PORE_LOCATION( &ctx, src1);
  pore_BRANZ( &ctx, D1, src1);
  pore_MR( &ctx, P1, P0);
  PORE_LOCATION( &ctx, src2);
  pore_BRA( &ctx, tgt2);
  PORE_LOCATION( &ctx, tgt1);
  pore_MR( &ctx, D1, P0);
  pore_ANDI( &ctx, D1, D1, CLEAR_MC_TYPE_MASK);
  pore_ORI( &ctx, D1, D1, BIT(60));
  pore_MR( &ctx, P1, D1);
  PORE_LOCATION( &ctx, tgt2);
  if (ctx.error > 0)  {
    MY_ERR("***setp1_mcreadand rc = %d", ctx.error);
    return ctx.error;
  }
  pore_inline_branch_fixup( &ctx, src1, tgt1);
  if (ctx.error > 0)  {
    MY_ERR("***inline_branch_fixup error (1) rc = %d", ctx.error);
    return ctx.error;
  }
  pore_inline_branch_fixup( &ctx, src2, tgt2);
  if (ctx.error > 0)  {
    MY_ERR("***inline_branch_fixup error (2) rc = %d", ctx.error);
    return ctx.error;
  }

	// We can assume that atomic lock is already in effect prior to WF calls.
	// It can probably also be assumed that functional clocks are stopped, but
	//   let's do it and check for it anyway.
/* CMO: 20120927 - Not working - Being debugged by EPM
	PoreInlineLocation  src0=0,tgt0=0;
  pore_imm64b = uint64_t(0x8C200E00)<<32;
	pore_STI(&ctx, P8_PORE_CLOCK_REGION_0x00030006, P0, pore_imm64b);
	pore_LD(&ctx, D1, P8_PORE_CLOCK_STATUS_0x00030008, P1);
	pore_imm64b = uint64_t(0xFFFFFFFF)<<32 | uint64_t(0xFFFFFFFF);
  pore_XORI( &ctx, D1, D1, pore_imm64b);
  PORE_LOCATION( &ctx, src0);
  pore_BRAZ( &ctx, D1, src0);
	pore_HALT( &ctx);
  PORE_LOCATION( &ctx, tgt0);
  pore_inline_branch_fixup( &ctx, src0, tgt0);
  if (ctx.error > 0)  {
    MY_ERR("***inline_branch_fixup error (0) rc = %d", ctx.error);
    return ctx.error;
  }
*/

  // Program scanselq reg for scan clock control setup before ring scan
  pore_imm64b = ((uint64_t)i_scanSelectData) << 32;
  pore_STI(&ctx, scanSelectAddr, P0, pore_imm64b);
  if (ctx.error > 0)  {
    MY_ERR("***STI rc = %d", ctx.error);
    return ctx.error;
  }

#ifdef IMGBUILD_PPD_WF_POLLING_PROT
	// Setup On Product Clock Generator (OPCG) for polling.
	pore_imm64b = uint64_t(0x01800000)<<32;
	pore_STI(&ctx, P8_PORE_OPCG_CTRL_REG0_0x00030002, P0, pore_imm64b);
	pore_imm64b = uint64_t(0x11480000)<<32 | uint64_t(0x00014800);
	pore_STI(&ctx, P8_PORE_OPCG_CTRL_REG1_0x00030003, P0, pore_imm64b);
	pore_imm64b = uint64_t(0x00000000)<<32 | uint64_t(0x0fff2800);
	pore_STI(&ctx, P8_PORE_OPCG_CTRL_REG2_0x00030004, P0, pore_imm64b);
	pore_imm64b = uint64_t(0x00000000);
	pore_STI(&ctx, P8_PORE_OPCG_START_REG3_0x00030005, P0, pore_imm64b);
  if (ctx.error > 0)  {
    MY_ERR("***POLLING PROT(1) rc = %d", ctx.error);
    return ctx.error;
  }
#endif


#ifdef IMGBUILD_PPD_WF_WORST_CASE_PIB
  uint32_t poreCTR=0;
	// Save CTR value and restore it when done.
/*
  pore_MV(&ctx, A1, CTR);
  if (ctx.error > 0)  {
    MY_ERR("***WORST CASE PIB(1) rc = %d", ctx.error);
    return ctx.error;
  }
*/
#endif

	// Preload the scan data/shift reg with the scan header check word.
  //
  pore_imm64b = ((uint64_t)scanRingCheckWord) << 32;
  pore_LI(&ctx, D0, pore_imm64b );
  if (ctx.error > 0)  {
    MY_ERR("***(1)LI D0 rc = %d", ctx.error);
    return ctx.error;
  }
  pore_STD(&ctx, D0, scanRing_baseAddr, P0);
  if (ctx.error > 0)  {
    MY_ERR("***STD D0 rc = %d", ctx.error);
    return ctx.error;
  }

  // Check how many 32-bit shift ops are needed and if we need final shift of remaining bit.
  count = i_ringBitLen/32;
  remainder = i_ringBitLen%32;
  if (remainder >0)
      count = count + 1;

  // From P7+: skip first 32 bits associated with FSI engine
  //TODO: check with perv design team if FSI 32 bit assumption is still valid in p8
  //remainingBits=i_ringBitLen-32;
  // CMO: I changed the following to not skip the first 32-bit.
  //remainingBits = i_ringBitLen-32;  //Yong impl.
  remainingBits = i_ringBitLen;   //Mike impl.

  MY_DBG("count=%i  rem=%i  remBits=%i",count,remainder,remainingBits);

  // Compare 32 bit data at a time then shift ring (p7+ reqmt)

  // Read and compare init and flush values 32 bits at a time.  Store delta in o_delta buffer.
  //for (i=1; i<count; i++)  {   //Yong impl
  for (i=0; i<count; i++)  {   //Mike impl

    //====================================================================================
    // If flush & init values are identical, increase the read count, no code needed.
    // When the discrepancy is found, read (rotate the ring) up to current address
    // then scan/write in the last 32 bits
    //====================================================================================
    // Note: For PORE scan instruction, set Port to 3.  Bit 16 Must be set to 1.

    if (i_deltaRing[i] > 0)  {

      if (rotateLen > 0)  {
        //--------------------------------------------------------------------------
        // Rotate scan ring by the current rotate length
        // rotate length is equivalent to current rotate addr - previous rotate addr
        //
        // Note space overflow is checked by inline assembler in P8
        // TODO: Not useing SCR1RDA : check with perv team
        // TODO: what to do with 1st 32 bit for FSI??
        //--------------------------------------------------------------------------

#ifdef IMGBUILD_PPD_WF_POLLING_PROT
				uint32_t  nwait1=0;
				PoreInlineLocation  srcp1=0,tgtp1=0;
				if (rotateLen>0x20)  {
        	scanRing_poreAddr=scanRing_baseAddr | 0x20;
        	pore_LD(&ctx, D0, scanRing_poreAddr, P1);
					rotateLen = rotateLen-0x20;
					nwait1 = rotateLen * OPCG_SCAN_RATIO / 20 + 1; // 20x over sampling.
					pore_STI(&ctx, P8_PORE_OPCG_CTRL_REG0_0x00030002, P0,
									         P8_OPCG_SCAN_RATIO_BITS|P8_OPCG_GO_BITS|uint64_t(rotateLen-1));
					PORE_LOCATION(&ctx, tgtp1);
					pore_WAITS(&ctx, nwait1);
					pore_LD(&ctx, D0, GENERIC_GP1_0x00000001, P1);
					pore_ANDI(&ctx, D0, D0, P8_SCAN_POLL_MASK_BIT15);
					PORE_LOCATION(&ctx, srcp1);
					pore_BRAZ(&ctx, D0, tgtp1);
					pore_inline_branch_fixup(&ctx, srcp1, tgtp1);
				}
				else  {
        	scanRing_poreAddr=scanRing_baseAddr | rotateLen;
        	pore_LD(&ctx, D0, scanRing_poreAddr, P1);
				}
        if (ctx.error > 0)  {
          MY_ERR("***POLLING PROT(2) rc = %d", ctx.error);
          return ctx.error;
        }
#else
#ifdef IMGBUILD_PPD_WF_WORST_CASE_PIB
				PoreInlineLocation  srcwc1=0,tgtwc1=0;
				poreCTR = rotateLen/i_scanMaxRotate-1;
				if (poreCTR>=0)  {
					scanRing_poreAddr = scanRing_baseAddr | i_scanMaxRotate;
					pore_LS(&ctx, CTR, poreCTR);
					PORE_LOCATION(&ctx, tgtwc1);
        	pore_LD(&ctx, D0, scanRing_poreAddr, P1);
					PORE_LOCATION(&ctx, srcwc1);
					pore_LOOP(&ctx, tgtwc1);
					pore_inline_branch_fixup(&ctx, srcwc1, tgtwc1);
				}
				scanRing_poreAddr = scanRing_baseAddr | (rotateLen-i_scanMaxRotate*(poreCTR+1));
        pore_LD(&ctx, D0, scanRing_poreAddr, P1);
        if (ctx.error > 0)  {
          MY_ERR("***WORST CASE PIB(1) rc = %d", ctx.error);
          return ctx.error;
        }
#else
        scanRing_poreAddr=scanRing_baseAddr | rotateLen;
        pore_LD(&ctx, D0, scanRing_poreAddr, P1);
        if (ctx.error > 0)  {
          MY_ERR("***LD D0 rc = %d", ctx.error);
          return ctx.error;
        }
#endif
#endif

      } // End of if (rotateLen>0)

      if (remainingBits>32)
        scanRing_poreAddr = scanRing_baseAddr | 32;
      else
        scanRing_poreAddr = scanRing_baseAddr | remainingBits;

      pore_imm64b = ((uint64_t)myRev32(i_deltaRing[i])) << 32;

      pore_LI(&ctx, D0, pore_imm64b );
      if (ctx.error > 0)  {
        MY_ERR("***(2)LI D0 rc = %d", ctx.error);
        return ctx.error;
      }

      pore_STD(&ctx, D0, scanRing_poreAddr, P0);
      if (ctx.error > 0)  {
        MY_ERR("***STD D0 rc = %d", ctx.error);
        return ctx.error;
      }

      rotateLen=0;  //reset rotate length

		}
    else  {
      // i_deltaRing[i]==0 (i.e., init and alter states are identical).
      // Increase rotate length by remaining scan bits (32 by default).

			// Increase rotate length by remaining scan bits (default 32 bits)
      if (remainingBits>32)
        rotateLen = rotateLen + 32;
      else
        rotateLen = rotateLen + remainingBits;

#ifdef IMGBUILD_PPD_WF_POLLING_PROT
			uint32_t nwait2=0;
			PoreInlineLocation  srcp2=0,tgtp2=0;
			// Max loop count is 16^7-1, so make sure we never exceed that.
			if (rotateLen>=0xFFFFFE0)  {
			  MY_DBG("/n/nScanning should never be here, should it?/n/n");
       	scanRing_poreAddr=scanRing_baseAddr | 0x20;
       	pore_LD(&ctx, D0, scanRing_poreAddr, P1);
				rotateLen = rotateLen-0x20;
				nwait2 = rotateLen * OPCG_SCAN_RATIO / 20 + 1; // 20x over sampling.
				pore_STI(&ctx, P8_PORE_OPCG_CTRL_REG0_0x00030002, P0,
									         P8_OPCG_SCAN_RATIO_BITS|P8_OPCG_GO_BITS|uint64_t(rotateLen-1));
				PORE_LOCATION(&ctx, tgtp2);
				pore_WAITS(&ctx, nwait2);
				pore_LD(&ctx, D0, GENERIC_GP1_0x00000001, P1);
				pore_ANDI(&ctx, D0, D0, P8_SCAN_POLL_MASK_BIT15);
				PORE_LOCATION(&ctx, srcp2);
				pore_BRAZ(&ctx, D0, tgtp2);
				pore_inline_branch_fixup(&ctx, srcp2, tgtp2);
	      if (ctx.error > 0)  {
	        MY_ERR("***POLLING PROT(3) rc = %d", ctx.error);
	        return ctx.error;
	      }
				rotateLen=0;
			}
#else
#ifdef IMGBUILD_PPD_WF_WORST_CASE_PIB
      // There is no max rotateLen issue in this case since we rotate 32 bits
			// at a time.
#else
			// PORE does not release PIB/PCB until CC acks, thus limiting bandwidth.
      // It will time out if more than 4095 bits need to be rotated.
      // If rotate length is more than 4032 (allows to rotate up to 4064 bits)
      // rotate the chain and reset rotate length counter.
      if (rotateLen>0xFC0)  {
        scanRing_poreAddr = scanRing_baseAddr | rotateLen;
        pore_LD(&ctx, D0, scanRing_poreAddr, P1);
        if (ctx.error > 0)  {
          MY_ERR("***LD D0 rc = %d", ctx.error);
          return ctx.error;
        }
        rotateLen=0;
      }
#endif
#endif

    } //end of else (i_deltaRing==0)

    if (remainingBits>32)
      remainingBits = remainingBits - 32;
    else
      remainingBits = 0;

  } // End of for loop

  // If the scan ring has not been rotated to the original position
  // shift the ring by remaining shift bit length. (No need to do polling here.)
  if (rotateLen>0)  {
#ifdef IMGBUILD_PPD_WF_POLLING_PROT
		uint32_t nwait3=0;
		PoreInlineLocation  srcp3=0,tgtp3=0;
    if (rotateLen>0x20)  {
		  scanRing_poreAddr=scanRing_baseAddr | 0x20;
      pore_LD(&ctx, D0, scanRing_poreAddr, P1);
			rotateLen = rotateLen-0x20;
			nwait3 = rotateLen * OPCG_SCAN_RATIO / 20 + 1; // 20x over sampling.
			pore_STI(&ctx, P8_PORE_OPCG_CTRL_REG0_0x00030002, P0,
							         P8_OPCG_SCAN_RATIO_BITS|P8_OPCG_GO_BITS|uint64_t(rotateLen-1));
			PORE_LOCATION(&ctx, tgtp3);
			pore_WAITS(&ctx, nwait3);
			pore_LD(&ctx, D0, GENERIC_GP1_0x00000001, P1);
			pore_ANDI(&ctx, D0, D0, P8_SCAN_POLL_MASK_BIT15);
			PORE_LOCATION(&ctx, srcp3);
			pore_BRAZ(&ctx, D0, tgtp3);
			pore_inline_branch_fixup(&ctx, srcp3, tgtp3);
		}
		else  {
		  scanRing_poreAddr=scanRing_baseAddr | rotateLen;
      pore_LD(&ctx, D0, scanRing_poreAddr, P1);
		}
    if (ctx.error > 0)  {
      MY_ERR("***POLLING PROT(4) rc = %d", ctx.error);
      return ctx.error;
    }
		rotateLen=0;
#else
#ifdef IMGBUILD_PPD_WF_WORST_CASE_PIB
		PoreInlineLocation  srcwc2=0,tgtwc2=0;
		poreCTR = rotateLen/i_scanMaxRotate-1;
		if (poreCTR>=0)  {
			scanRing_poreAddr = scanRing_baseAddr | i_scanMaxRotate;
			pore_LS(&ctx, CTR, poreCTR);
			PORE_LOCATION(&ctx, tgtwc2);
    	pore_LD(&ctx, D0, scanRing_poreAddr, P1);
			PORE_LOCATION(&ctx, srcwc2);
			pore_LOOP(&ctx, tgtwc2);
			pore_inline_branch_fixup(&ctx, srcwc2, tgtwc2);
		}
		scanRing_poreAddr = scanRing_baseAddr | (rotateLen-i_scanMaxRotate*(poreCTR+1));
    pore_LD(&ctx, D0, scanRing_poreAddr, P1);
    if (ctx.error > 0)  {
      MY_ERR("***WORST CASE PIB(2) rc = %d", ctx.error);
      return ctx.error;
    }
		rotateLen=0;
#else
    scanRing_poreAddr=scanRing_baseAddr | rotateLen;
    pore_LD(&ctx, D0, scanRing_poreAddr, P1);
    if (ctx.error > 0)  {
      MY_ERR("***LD D0 rc = %d", ctx.error);
      return ctx.error;
    }
    rotateLen=0;
#endif
#endif
  }

/*
#ifdef IMGBUILD_PPD_WF_WORST_CASE_PIB
  // Restore CTR value.
	pore_MV(&ctx, CTR, A1);
  if (ctx.error > 0)  {
    MY_ERR("***WORST CASE PIB(5) rc = %d", ctx.error);
    return ctx.error;
  }
#endif
*/

  // Finally, check that our header check word went through in one piece.
  // Note, we first do the MC-READ-AND check, then the MC-READ-OR check
  //
  // ...First, do the MC-READ-AND check
  //    (Reference: setp1_mcreadand macro in ./ipl/sbe/p8_slw.H)
  //
  PoreInlineLocation src3=0, src5=0, src7=0, src8=0, tgt3=0, tgt5=0, tgt7=0, tgt8=0;
  pore_MR( &ctx, D1, P0);
  pore_ANDI( &ctx, D1, D1, BIT(57));
  PORE_LOCATION( &ctx, src3);
  pore_BRANZ( &ctx, D1, src3);
  pore_MR( &ctx, P1, P0); // If here, MC=0. Omit MC check in OR case.
  PORE_LOCATION( &ctx, src7);
  pore_BRA( &ctx, tgt7);
  PORE_LOCATION( &ctx, tgt3);
  pore_MR( &ctx, D1, P0);
  pore_ANDI( &ctx, D1, D1, CLEAR_MC_TYPE_MASK);
  pore_ORI( &ctx, D1, D1, BIT(60));
  pore_MR( &ctx, P1, D1);
  if (ctx.error > 0)  {
    MY_ERR("***setp1_mcreadand rc = %d", ctx.error);
    return ctx.error;
  }
  pore_inline_branch_fixup( &ctx, src3, tgt3);
  if (ctx.error > 0)  {
    MY_ERR("***inline_branch_fixup error (3) rc = %d", ctx.error);
    return ctx.error;
  }
  // ...Load the output check word...
  pore_LD(&ctx, D0, scanRing_baseAddr, P1);
  // Compare against the reference header check word...
  pore_XORI( &ctx, D0, D0, ((uint64_t)scanRingCheckWord) << 32);
#ifdef IMGBUILD_PPD_DEBUG_WF
pore_LI( &ctx, D1, ((uint64_t)scanRingCheckWord)<<32);
#endif
  PORE_LOCATION( &ctx, src5);
  pore_BRAZ( &ctx, D0, tgt5);
#ifdef IMGBUILD_PPD_DEBUG_WF
if (i_scanSelectData==0x00200800 || i_scanSelectData==0x04000800)  {
pore_LD(&ctx, D1, scanRing_baseAddr, P1);
if (i_scanSelectData==0x00200800)  {
  pore_XORI( &ctx, D1, D1, ((uint64_t)0x00000001)<<32); // Yields B in last nibble.
}
if (i_scanSelectData==0x04000800)  {
  pore_XORI( &ctx, D1, D1, ((uint64_t)0x00000006)<<32); // Yields C in last nibble.
}
pore_RET( &ctx);
}
#endif
  pore_HALT( &ctx);
  PORE_LOCATION( &ctx, tgt5);
  if (ctx.error > 0)  {
    MY_ERR("***LD, XORI, BRANZ, RET or HALT went wrong  rc = %d", ctx.error);
    return ctx.error;
  }
  pore_inline_branch_fixup( &ctx, src5, tgt5);
  if (ctx.error > 0)  {
    MY_ERR("***inline_branch_fixup error (5) rc = %d", ctx.error);
    return ctx.error;
  }
  //
  // ...Now do the MC-READ-OR check
  //    (Reference: setp1_mcreador macro in ./ipl/sbe/p8_slw.H)
  //    Note. If we made is this far, we know that MC=1 already, so don't check for it.
  //
  pore_MR( &ctx, D1, P0);
  pore_ANDI( &ctx, D1, D1, CLEAR_MC_TYPE_MASK); // This also clears bit-60.
  pore_MR( &ctx, P1, D1);
  PORE_LOCATION( &ctx, tgt7);
  if (ctx.error > 0)  {
    MY_ERR("***setp1_mcreadand rc = %d", ctx.error);
    return ctx.error;
  }
  pore_inline_branch_fixup( &ctx, src7, tgt7);
  if (ctx.error > 0)  {
    MY_ERR("***inline_branch_fixup error (7) rc = %d", ctx.error);
    return ctx.error;
  }
  // ...Load the output check word...
  pore_LD(&ctx, D0, scanRing_baseAddr, P1);
  pore_XORI( &ctx, D0, D0, ((uint64_t)scanRingCheckWord) << 32);
#ifdef IMGBUILD_PPD_DEBUG_WF
pore_LI( &ctx, D1, ((uint64_t)scanRingCheckWord)<<32);
#endif
  PORE_LOCATION( &ctx, src8);
  pore_BRAZ( &ctx, D0, tgt8);
#ifdef IMGBUILD_PPD_DEBUG_WF
if (i_scanSelectData==0x00200800 || i_scanSelectData==0x04000800)  {
pore_LD(&ctx, D1, scanRing_baseAddr, P1);
if (i_scanSelectData==0x00200800)  {
  pore_XORI( &ctx, D1, D1, ((uint64_t)0x00000001)<<32); // Yields B in last nibble.
}
if (i_scanSelectData==0x04000800)  {
  pore_XORI( &ctx, D1, D1, ((uint64_t)0x00000006)<<32); // Yields C in last nibble.
}
pore_RET( &ctx);
}
#endif
  pore_HALT( &ctx);
  PORE_LOCATION( &ctx, tgt8);
  pore_LI( &ctx, D0, 0x0);  // Do shadowing by setpulse.
	pore_STD( &ctx, D0, GENERIC_CLK_SCAN_UPDATEDR_0x0003A000, P0);
	pore_RET( &ctx);
  if (ctx.error > 0)  {
    MY_ERR("***LD, XORI, BRANZ, RET or HALT went wrong  rc = %d", ctx.error);
    return ctx.error;
  }
  pore_inline_branch_fixup( &ctx, src8, tgt8);
  if (ctx.error > 0)  {
    MY_ERR("***inline_branch_fixup error (8) rc = %d", ctx.error);
    return ctx.error;
  }

  *o_wfInlineLenInWords = ctx.lc/4;

  // 8-byte align code, just as a precaution.
  if ((*o_wfInlineLenInWords*4)%8)  {
    // Insert 4-byte NOP at end.
    pore_NOP( &ctx);
    if (ctx.error > 0)  {
      MY_ERR("***NOP went wrong rc = %d", ctx.error);
      return ctx.error;
    }
    *o_wfInlineLenInWords = ctx.lc/4;
  }

  return rc;
}



// write_wiggle_flip_to_image()
int write_wiggle_flip_to_image( void *io_imageOut,
                                uint32_t  *i_sizeImageMaxNew,
                                DeltaRingLayout *i_ringLayout,
                                uint32_t  *i_wfInline,
                                uint32_t  i_wfInlineLenInWords)
{
  uint32_t rc=0, bufLC;
	int      deltaLC, i;
  uint32_t sizeImageIn, sizeNewDataBlock;
  uint32_t sizeImageOutThisEst=0, sizeImageOutThis=0;
  void *ringsBuffer=NULL;
  uint32_t ringRingsOffset=0;
  uint64_t ringPoreAddress=0,backPtr=0,fwdPtr=0,fwdPtrCheck;

	SBE_XIP_ERROR_STRINGS(errorStrings);

  MY_DBG("wfInlineLenInWords=%i", i_wfInlineLenInWords);

  // Modify the input ring layout content
  // - Remove the qualifier section: ddLevel, sysPhase, override and reserved1+2.
  //   This means reducing the entryOffset by the size of these qualifiers.
  // - The new WF ring block and start of WF code must both be 8-byte aligned.
  //   - RS4 entryOffset is already 8-byte aligned.
  //   - The WF code section, i.e. wfInlineLenInWords, is already 8-byte aligned.
  //
  i_ringLayout->entryOffset  =
    myRev64(  myByteAlign(8, myRev64(i_ringLayout->entryOffset) -
                             sizeof(i_ringLayout->ddLevel) -
                             sizeof(i_ringLayout->sysPhase) -
                             sizeof(i_ringLayout->override) -
                             sizeof(i_ringLayout->reserved1) -
                             sizeof(i_ringLayout->reserved2) ) );
  i_ringLayout->sizeOfThis   =
    myRev32( myRev64(i_ringLayout->entryOffset) + i_wfInlineLenInWords*4 );

  // Not really any need for this. Just being consistent. Once we have transitioned completely to new
  //  headers, then ditch i_wfInline from parm list and assign wfInline to layout in main program.
  i_ringLayout->wfInline    = i_wfInline;

  if (myRev64(i_ringLayout->entryOffset)%8 || myRev32(i_ringLayout->sizeOfThis)%8)  {
    MY_ERR("ERROR : Ring block or WF code origin not 8-byte aligned.");
    return IMGBUILD_ERR_MISALIGNED_RING_LAYOUT;
  }

  // Calc the size of the data section we're adding and the resulting output image.
  //
  rc = sbe_xip_image_size( io_imageOut, &sizeImageIn);
  if (rc)  {
    MY_ERR("ERROR : sbe_xip_image_size() failed: %s", SBE_XIP_ERROR_STRING(errorStrings, rc));
    return IMGBUILD_ERR_XIP_MISC;
  }
  sizeNewDataBlock = myRev32(i_ringLayout->sizeOfThis);
  // ...estimate max size of new image
  sizeImageOutThisEst = sizeImageIn + sizeNewDataBlock + SBE_XIP_MAX_SECTION_ALIGNMENT; //

  if (sizeImageOutThisEst>*i_sizeImageMaxNew)  {
    MY_ERR("ERROR : Estimated new image size (=%i) would exceed max allowed size (=%i).",
      sizeImageOutThisEst, *i_sizeImageMaxNew);
    *i_sizeImageMaxNew = sizeImageOutThisEst;
    return IMGBUILD_ERR_IMAGE_TOO_LARGE;
  }

  MY_DBG("Input image size\t\t= %6i\n\tNew rings data block size\t= %6i\n\tOutput image size (max)\t\t<=%6i",
    sizeImageIn, sizeNewDataBlock, sizeImageOutThisEst);
  MY_DBG("entryOffset = %i\n\tsizeOfThis = %i\n\tMeta data size = %i",
    (uint32_t)myRev64(i_ringLayout->entryOffset), myRev32(i_ringLayout->sizeOfThis), myRev32(i_ringLayout->sizeOfMeta));
  MY_DBG("Back item ptr = 0x%016llx",myRev64(i_ringLayout->backItemPtr));
  MY_DBG("DD level = 0x%02x\n\tSys phase = %i\n\tOverride = %i\n\tReserved1+2 = %i",
    myRev32(i_ringLayout->ddLevel), i_ringLayout->sysPhase, i_ringLayout->override, i_ringLayout->reserved1|i_ringLayout->reserved2);

  // Combine rs4RingLayout members into a unified buffer (ringsBuffer).
  //
  ringsBuffer = malloc((size_t)sizeNewDataBlock);
  if (ringsBuffer == NULL)  {
    MY_ERR("ERROR : malloc() of initf buffer failed.");
    return IMGBUILD_ERR_MEMORY;
  }
  // ... First, copy WF ring layout header into ringsBuffer in BIG-ENDIAN format.
  bufLC = 0;
  deltaLC =  (uintptr_t)&i_ringLayout->ddLevel-(uintptr_t)&i_ringLayout->entryOffset;
  memcpy( (uint8_t*)ringsBuffer+bufLC, &i_ringLayout->entryOffset, deltaLC);
  // ... then meta data
  bufLC = bufLC + deltaLC;
  deltaLC = myRev32(i_ringLayout->sizeOfMeta);
  memcpy( (uint8_t*)ringsBuffer+bufLC, i_ringLayout->metaData, deltaLC);
  // ... Is this padding or WF buffer?
  bufLC = bufLC + deltaLC;
  deltaLC = (uint32_t)myRev64(i_ringLayout->entryOffset) - bufLC;
  if (deltaLC<0 || deltaLC>=8)  {
	  MY_ERR("ERROR : Ring layout mess. Check code or delta_scan(). deltaLC=%i",deltaLC);
	  return IMGBUILD_ERR_CHECK_CODE;
	}
  if (deltaLC>0)  {
    // OK, it's padding time.
    for (i=0; i<deltaLC; i++)
      *(uint8_t*)((uint8_t*)ringsBuffer+bufLC+i) = 0;
  }
  // ... now do the WF buffer
  bufLC = bufLC + deltaLC;
  if (bufLC!=(uint32_t)myRev64(i_ringLayout->entryOffset))  {
    MY_ERR("ERROR : Ring layout messup. Check code or delta_scan().");
    return IMGBUILD_ERR_CHECK_CODE;
  }
  deltaLC = i_wfInlineLenInWords*4;
  memcpy( (uint8_t*)ringsBuffer+bufLC, i_wfInline, deltaLC);

  // Append WF ring layout to .rings section of in-memory input image.
  //   Note! All layout members should already be 8-byte aligned.
  //
  rc = sbe_xip_append( io_imageOut,
                       SBE_XIP_SECTION_RINGS,
                       (void*)ringsBuffer,
                       sizeNewDataBlock,
                       sizeImageOutThisEst,
                       &ringRingsOffset);
  MY_DBG("ringRingsOffset=0x%08x",ringRingsOffset);
  if (rc)   {
    MY_ERR("ERROR : sbe_xip_append() failed: %s", SBE_XIP_ERROR_STRING(errorStrings, rc));
    if (ringsBuffer)  free(ringsBuffer);
    return IMGBUILD_ERR_XIP_MISC;
  }
  // ...get new image size, update return size, and test if successful update.
  sbe_xip_image_size( io_imageOut, &sizeImageOutThis);
  MY_DBG("Output image size (final)\t=%i",sizeImageOutThis);
  *i_sizeImageMaxNew = sizeImageOutThis;
  rc = sbe_xip_validate( io_imageOut, sizeImageOutThis);
  if (rc)   {
    MY_ERR("ERROR : sbe_xip_validate() of output image failed: %s", SBE_XIP_ERROR_STRING(errorStrings, rc));
    if (ringsBuffer)  free(ringsBuffer);
    return IMGBUILD_ERR_XIP_MISC;
  }
  MY_DBG("Successful append of RS4 ring to .rings. Next, update forward ptr...");

  // Update forward pointer associated with the ring/var name + any override offset.
  //
  // Convert the ring offset (wrt .rings address) to an PORE address
  rc = sbe_xip_section2pore(io_imageOut, SBE_XIP_SECTION_RINGS, ringRingsOffset, &ringPoreAddress);
  fwdPtr = ringPoreAddress;
  MY_DBG("fwdPtr=0x%016llx", fwdPtr);
  if (rc)   {
    MY_ERR("ERROR : sbe_xip_section2pore() failed: %s", SBE_XIP_ERROR_STRING(errorStrings, rc));
    if (ringsBuffer)  free(ringsBuffer);
    return IMGBUILD_ERR_XIP_MISC;
  }
  // ...then update the forward pointer, i.e. the old "variable/ring name's" pointer.
  //    DO NOT add any 8-byte offset if override ring. The backItemPtr already has this
  //    from p8_delta_scan.
  //
  backPtr = myRev64(i_ringLayout->backItemPtr);
  MY_DBG("backPtr = 0x%016llx",  backPtr);
  rc = sbe_xip_write_uint64(  io_imageOut,
                              backPtr,
                              fwdPtr);
  rc = rc+sbe_xip_read_uint64(io_imageOut,
                              backPtr,
                              &fwdPtrCheck);
  if (rc)  {
    MY_ERR("ERROR : sbe_xip_[write,read]_uint64() failed: %s", SBE_XIP_ERROR_STRING(errorStrings, rc));
    if (ringsBuffer)  free(ringsBuffer);
    return IMGBUILD_ERR_XIP_MISC;
  }
  if (fwdPtrCheck!=ringPoreAddress || backPtr!=myRev64(i_ringLayout->backItemPtr))  {
    MY_ERR("ERROR : Forward or backward pointer mess. Check code.");
    MY_ERR("fwdPtr       =0x%016llx",fwdPtr);
    MY_ERR("fwdPtrCheck  =0x%016llx",fwdPtrCheck);
    MY_ERR("layout bckPtr=0x%016llx",myRev64(i_ringLayout->backItemPtr));
    MY_ERR("backPtr      =0x%016llx",backPtr);
    if (ringsBuffer)  free(ringsBuffer);
    return IMGBUILD_ERR_FWD_BACK_PTR_MESS;
  }
  // ...test if successful update.
  rc = sbe_xip_validate( io_imageOut, sizeImageOutThis);
  if (rc)   {
    MY_ERR("ERROR : sbe_xip_validate() of output image failed: %s", SBE_XIP_ERROR_STRING(errorStrings, rc));
    MY_ERR("Probable cause:");
    MY_ERR("\tsbe_xip_write_uint64() updated at the wrong address (=0x%016llx)",
      myRev64(i_ringLayout->backItemPtr));
    if (ringsBuffer)  free(ringsBuffer);
    return IMGBUILD_ERR_XIP_MISC;
  }

  if (ringsBuffer)  free(ringsBuffer);

  return rc;
}



// append_empty_section()
int append_empty_section( void      *io_image,
                          uint32_t  *i_sizeImageMaxNew,
                          uint32_t  i_sectionId,
                          uint32_t  i_sizeSection)
{
  uint32_t rc=0;
  uint32_t sizeImageIn=0, sizeImageOutThis=0, sizeImageOutThisEst=0;
  uint32_t offsetCheck=1;
  void *bufEmpty=NULL;

  SBE_XIP_ERROR_STRINGS(errorStrings);

  rc = 0;

  if (i_sizeSection==0)  {
    MY_INF("INFO : Requested append size = 0. Nothing to do.");
    return rc;
  }

  // Check if there is enough room in the new image to add section.
  //
  sbe_xip_image_size( io_image, &sizeImageIn);
  // ...estimate max size of new image
  sizeImageOutThisEst = sizeImageIn + i_sizeSection + SBE_XIP_MAX_SECTION_ALIGNMENT;
  if (sizeImageOutThisEst>*i_sizeImageMaxNew)  {
    MY_ERR("ERROR : Estimated new image size (=%i) would exceed max allowed size (=%i).",
      sizeImageOutThisEst, *i_sizeImageMaxNew);
    *i_sizeImageMaxNew = sizeImageOutThisEst;
    return IMGBUILD_ERR_IMAGE_TOO_LARGE;
  }

  // Add the 0-initialized buffer as a section append.
  //
  bufEmpty = calloc( i_sizeSection, 1);
  rc = sbe_xip_append( io_image,
                       i_sectionId,
                       bufEmpty,
                       i_sizeSection,
                       sizeImageOutThisEst,
                       &offsetCheck);
  if (rc)  {
    MY_ERR("ERROR : xip_append() failed: %s\n",SBE_XIP_ERROR_STRING(errorStrings, rc));
    if (bufEmpty)
      free(bufEmpty);
    return DSLWB_SLWB_IMAGE_ERROR;
  }
  if (offsetCheck)
    MY_INF("INFO : Section was not empty at time of xip_append(). It contained %i bytes.",offsetCheck);
  // ...get new image size, update return size, and test if successful update.
  sbe_xip_image_size( io_image, &sizeImageOutThis);
  MY_DBG("Output image size (final)\t=%i",sizeImageOutThis);
  *i_sizeImageMaxNew = sizeImageOutThis;
  rc = sbe_xip_validate( io_image, sizeImageOutThis);
  if (rc)   {
    MY_ERR("ERROR : xip_validate() of output image failed: %s", SBE_XIP_ERROR_STRING(errorStrings, rc));
    if (bufEmpty)  free(bufEmpty);
    return IMGBUILD_ERR_XIP_MISC;
  }

  if (bufEmpty)
    free(bufEmpty);

  return rc;
}



// initialize_slw_section()
// - allocate space for Ramming and Scomming
// - populate Scomming table with ret/nop/nop/nop (RNNN) inline asm instructions
// - update Scomming vector
int initialize_slw_section( void      *io_image,
                            uint32_t  *i_sizeImageMaxNew)
{
  uint32_t rc=0, i_coreId=0, i_iis=0;
  PoreInlineContext ctx;
  SbeXipSection  xipSection;
  SbeXipItem     xipTocItem;
  void   *hostScomTableFirst, *hostScomTableNext, *hostScomVectorFirst, *hostScomVectorNext;
  uint64_t xipScomTableFirst;
  ////void     *bufRNNN=NULL;
  uint8_t  bufRNNN[XIPSIZE_SCOM_ENTRY];

  SBE_XIP_ERROR_STRINGS(errorStrings);

  rc = append_empty_section( io_image,
                             i_sizeImageMaxNew,
                             SBE_XIP_SECTION_SLW,
                             SLW_RAM_TABLE_SIZE + SLW_SCOM_TABLE_SIZE_ALL);
  if (rc)
    return rc;

  //
  // Ramming table:  Nothing to do.  Already 0-initialized in append_empty_section().
  //

  //
  // Scomming table:  Fill with RNNN (16-byte) instruction sequences.
  //

  // ... create RNNN instruction sequence.
  pore_inline_context_create( &ctx, (void*)bufRNNN, XIPSIZE_SCOM_ENTRY, 0, 0);
  pore_RET( &ctx);
  pore_NOP( &ctx);
  pore_NOP( &ctx);
  pore_NOP( &ctx);
  if (ctx.error > 0)  {
    MY_ERR("***_RET or _NOP generated rc = %d", ctx.error);
    return IMGBUILD_ERR_PORE_INLINE_ASM;
  }

  // ... get host and pore location of Scom table in .slw section.
  rc = sbe_xip_get_section( io_image, SBE_XIP_SECTION_SLW, &xipSection);
  if (rc)   {
    MY_ERR("ERROR : sbe_xip_get_section() failed: %s", SBE_XIP_ERROR_STRING(errorStrings, rc));
    MY_ERR("Probable cause:");
    MY_ERR("\tThe section (=SBE_XIP_SECTION_SLW=%i) was not found.",SBE_XIP_SECTION_SLW);
    return IMGBUILD_ERR_KEYWORD_NOT_FOUND;
  }
  hostScomTableFirst = (void*)((uintptr_t)io_image + xipSection.iv_offset + SLW_RAM_TABLE_SIZE);
  sbe_xip_host2pore( io_image, hostScomTableFirst, &xipScomTableFirst);

  // ... get location of Scom vector from TOC.
  rc = sbe_xip_find( io_image, SLW_HOST_SCOM_VECTOR_TOC_NAME, &xipTocItem);
  if (rc)  {
    MY_ERR("ERROR : sbe_xip_find() failed w/rc=%i and %s", rc, SBE_XIP_ERROR_STRING(errorStrings, rc));
    MY_ERR("Probable cause:");
    MY_ERR("\tThe keyword (=%s) was not found.",SLW_HOST_SCOM_VECTOR_TOC_NAME);
    return IMGBUILD_ERR_KEYWORD_NOT_FOUND;
  }
  sbe_xip_pore2host( io_image, xipTocItem.iv_address, &hostScomVectorFirst);

  // ... populate entire Scom table with RNNN IIS.
  for (i_iis=0; i_iis<SLW_SCOM_TABLE_SIZE_ALL; i_iis=i_iis+XIPSIZE_SCOM_ENTRY)  {
    hostScomTableNext = (void*)( (uintptr_t)hostScomTableFirst + i_iis);
    memcpy( hostScomTableNext, (void*)bufRNNN, XIPSIZE_SCOM_ENTRY);
  }

  // ... update Non-cache Scom vector.
  for (i_coreId=0; i_coreId<SLW_MAX_CORES; i_coreId++)  {
    hostScomVectorNext = (void*)( (uint64_t*)hostScomVectorFirst + i_coreId);
    *(uint64_t*)hostScomVectorNext = myRev64( xipScomTableFirst +
                                              SLW_SCOM_TABLE_SPACE_PER_CORE_NC*i_coreId);
  }

  return rc;
}



// update_runtime_scom_pointer()
// - reprogram host_runtime_scom data to point to sub_slw_runtime_scom
// - reprogram ex_enable_runtime_scom data to point to sub_slw_ex_enable_runtime_scom
int update_runtime_scom_pointer( void *io_image)
{
  int rc=0;
  uint64_t xipSlwRuntimeAddr;
	uint64_t xipSlwExEnableRuntimeAddr;

  SBE_XIP_ERROR_STRINGS(errorStrings);

	// Get address of sub_slw_runtime_scom subroutine.
	//
	rc = sbe_xip_get_scalar( io_image, SLW_RUNTIME_SCOM_TOC_NAME, &xipSlwRuntimeAddr);
  if (rc)  {
    MY_ERR("ERROR : sbe_xip_set_scalar() failed w/rc=%i and %s", rc, SBE_XIP_ERROR_STRING(errorStrings, rc));
    MY_ERR("Probable cause:");
    MY_ERR("\tThe keyword (=%s) was not found.",SLW_RUNTIME_SCOM_TOC_NAME);
		return IMGBUILD_ERR_KEYWORD_NOT_FOUND;
  }

	// Update host_runtime_scom with sub_slw_runtime_scom's address.
	//
  rc = sbe_xip_set_scalar( io_image, HOST_RUNTIME_SCOM_TOC_NAME, xipSlwRuntimeAddr);
  if (rc)  {
    MY_ERR("ERROR : sbe_xip_set_scalar() failed w/rc=%i and %s", rc, SBE_XIP_ERROR_STRING(errorStrings, rc));
    MY_ERR("Probable cause:");
    MY_ERR("\tThe keyword (=%s) was not found.",HOST_RUNTIME_SCOM_TOC_NAME);
		return IMGBUILD_ERR_KEYWORD_NOT_FOUND;
  }

	// Get address of sub_slw_ex_enable_runtime_scom subroutine.
	//
	rc = sbe_xip_get_scalar( io_image, SLW_EX_ENABLE_RUNTIME_SCOM_TOC_NAME, &xipSlwExEnableRuntimeAddr);
  if (rc)  {
    MY_ERR("ERROR : sbe_xip_set_scalar() failed w/rc=%i and %s", rc, SBE_XIP_ERROR_STRING(errorStrings, rc));
    MY_ERR("Probable cause:");
    MY_ERR("\tThe keyword (=%s) was not found.",SLW_EX_ENABLE_RUNTIME_SCOM_TOC_NAME);
		return IMGBUILD_ERR_KEYWORD_NOT_FOUND;
  }

	// Update host_runtime_scom with sub_slw_ex_enable_runtime_scom's address.
	//
  rc = sbe_xip_set_scalar( io_image, EX_ENABLE_RUNTIME_SCOM_TOC_NAME, xipSlwExEnableRuntimeAddr);
  if (rc)  {
    MY_ERR("ERROR : sbe_xip_set_scalar() failed w/rc=%i and %s", rc, SBE_XIP_ERROR_STRING(errorStrings, rc));
    MY_ERR("Probable cause:");
    MY_ERR("\tThe keyword (=%s) was not found.",EX_ENABLE_RUNTIME_SCOM_TOC_NAME);
		return IMGBUILD_ERR_KEYWORD_NOT_FOUND;
  }

  return 0;
}



void cleanup( void *buf1,
              void *buf2,
              void *buf3,
              void *buf4,
              void *buf5)
{
  if (buf1) free(buf1);
  if (buf2) free(buf2);
  if (buf3) free(buf3);
  if (buf4) free(buf4);
  if (buf5) free(buf5);
}


}
