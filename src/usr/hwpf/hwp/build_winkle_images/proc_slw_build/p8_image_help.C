/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/build_winkle_images/proc_slw_build/p8_image_help.C $
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

#include "p8_delta_scan_rw.h"

#ifdef __FAPI
#include <fapi.H>
#endif
extern "C"  {


// get_ring_layout_from_image()
//
int get_ring_layout_from_image(  const void  *i_imageIn,
                                uint32_t    i_ddLevel,
                                uint8_t      i_sysPhase,
                                DeltaRingLayout  *o_rs4RingLayout,
                                void        **nextRing)
{
  uint32_t rc=0, rcLoc=0;
  uint8_t bRingFound=0, bRingEOS=0;
  DeltaRingLayout *thisRingLayout, *nextRingLayout; //Pointers into memory mapped image. DO NOT CHANGE MEMBERS!
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
  // Since RS4 launch size is only word-aligned, make sure to point to nearest [higher] double-word boundary.
  o_rs4RingLayout->rs4Delta      = (uint32_t*)((((uintptr_t)thisRingLayout + 
                                                myRev64(thisRingLayout->entryOffset) +
                                                ASM_RS4_LAUNCH_BUF_SIZE-1)/8+1)*8);

  // Check that the ring layout structure in the memory is double-word aligned. This must be so because:
  //   - The entryOffset address must be on an 8-byte boundary because the start of the .initf ELF section must
  //     be 8-byte aligned AND because the rs4Delta member is the last member and which must itself be 8-byte aligned.
  //   - These two things together means that both the beginning and end of the delta ring layout must be 8-byte
  //     aligned, and thus the whole block,i.e. sizeOfThis, must be 8-byte aligned.
  // Also check that the RS4 delta ring is double-word aligned.
  // Also check that the RS4 launcher is word aligned.
  //
  if (((uintptr_t)thisRingLayout-(uintptr_t)i_imageIn)%8 || 
      myRev32(o_rs4RingLayout->sizeOfThis)%8 || 
      (uintptr_t)o_rs4RingLayout->rs4Launch%4 || 
      (uintptr_t)o_rs4RingLayout->rs4Delta%8)  {
    MY_ERR("ERROR : Ring layout is not double-word-aligned or RS4 launcher is not word aligned.");
    MY_ERR("  thisRingLayout#8 = 0x%016llx",(uint64_t)thisRingLayout%8);
    MY_ERR("  myRev32(o_rs4RingLayout->sizeOfThis)#8 = %i",myRev32(o_rs4RingLayout->sizeOfThis)%8);
    MY_ERR("  o_rs4RingLayout->rs4Launch#4 = 0x%016llx",(uint64_t)o_rs4RingLayout->rs4Launch%4);
    MY_ERR("  o_rs4RingLayout->rs4Delta#8 = 0x%016llx",(uint64_t)o_rs4RingLayout->rs4Delta%8);
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
// - WF procedure needs to be updated with polling protocol.
// - WF procedure needs to reflect P0/P1 usage policy
int create_wiggle_flip_prg( uint32_t *i_deltaRing,          // scan ring delta state
                            uint32_t i_ringBitLen,          // length of ring
                            uint32_t i_scanSelectData,      // Scan ring modifier data
                            uint32_t i_chipletID,            // Chiplet ID
                            uint32_t **o_wfInline,       // location of the PORE instructions data stream
                            uint32_t *o_wfInlineLenInWords)   // final length of data stream
{
  uint32_t rc=P8_PORE_SUCCESS_RC;  //defined in p8_pore_api_const.h
  uint32_t i=0;
  uint32_t scanSelectAddr=0;
  uint32_t scanRing_baseAddr=0;
  uint32_t scanRing_poreAddr=0;
  uint32_t scanRingCheckWord=0;
  uint32_t count=0;
  uint32_t rotateLen=0, remainder=0, remainingBits=0;
  uint32_t osIndex=0;
  int pgas_rc=0;
  uint64_t pore_imm64b=0;
  uint32_t maxWfInlineLenInWords = 10*MAX_RING_SIZE/32;
  PoreInlineContext ctx;
  PoreInlineLocation src3=0, tgt3=0;

  *o_wfInline = (uint32_t*)malloc(maxWfInlineLenInWords);

  //pore_inline_context_create(&ctx, buf, P8_PORE_BUFSIZE * 4, 0, PORE_INLINE_CHECK_PARITY);
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
  
  // Program scanselq reg for scan clock control setup before ring scan
  // --------------------------------------------------------------------------
  
#ifndef SLW_BUILD_WF_P0_FIX
// The following fix is a direct copy of the setp1_mcreadand macro in ./ipl/sbe/p8_slw.H 
  uint64_t CLEAR_MC_TYPE_MASK=0x47;
  PoreInlineLocation src1=0, src2=0, tgt1=0, tgt2=0;
  pgas_rc = pore_MR( &ctx, D1, P0)             ||
            pore_ANDI( &ctx, D1, D1, BIT(57))  ||
            PORE_LOCATION( &ctx, src1)         ||
            pore_BRANZ( &ctx, D1, src1)        ||
            pore_MR( &ctx, P1, P0)            ||
            PORE_LOCATION( &ctx, src2)        ||
            pore_BRA( &ctx, tgt2)              ||
            PORE_LOCATION( &ctx, tgt1)        ||
            pore_MR( &ctx, D1, P0)            ||
            pore_ANDI( &ctx, D1, D1, CLEAR_MC_TYPE_MASK)  ||
            pore_ORI( &ctx, D1, D1, BIT(60))  ||
            pore_MR( &ctx, P1, D1)            ||
            PORE_LOCATION( &ctx, tgt2);
  if (pgas_rc>0)  {
    MY_ERR("***setp1_mcreadand rc = %d", pgas_rc);
    return pgas_rc;
  }
  pgas_rc = pore_inline_branch_fixup( &ctx, src1, tgt1) ||
            pore_inline_branch_fixup( &ctx, src2, tgt2);
  if (pgas_rc>0)  {
    MY_ERR("***inline_branch_fixup rc = %d", pgas_rc);
    return pgas_rc;
  }
#else
  uint32_t epmCID = 0x11;
  pgas_rc = pore_LS(&ctx, P0, epmCID);    //bits 2:7 get loaded to perv reg 26:31
  if (pgas_rc>0)  {
    MY_ERR("***LS rc = %d", pgas_rc);
    return pgas_rc;
  }
#endif
  
  pore_imm64b = ((uint64_t)i_scanSelectData) << 32;
  pgas_rc = pore_STI(&ctx, scanSelectAddr, P0, pore_imm64b);
  if (pgas_rc>0)  {
    MY_ERR("***STI rc = %d", pgas_rc);
    return pgas_rc;
  }

  // Preload the scan data/shift reg with the scan header check word.
  //
  pore_imm64b = ((uint64_t)scanRingCheckWord) << 32;
  pgas_rc = pore_LI(&ctx, D0, pore_imm64b );
  if (pgas_rc > 0)  {
    MY_ERR("***(1)LI D0 rc = %d", pgas_rc);
    return pgas_rc;
  }
  pgas_rc = pore_STD(&ctx, D0, scanRing_baseAddr, P0);
  if (pgas_rc > 0)  {
    MY_ERR("***STD D0 rc = %d", pgas_rc);
    return pgas_rc;
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
  // TODO: check if p8 still requires skipping the 1st 32 bit 

  // Read and compare init and flush values 32 bits at a time.  Store delta in o_delta buffer.
  //for (i=1; i<count; i++)  {   //Yong impl
  for (i=0; i<count; i++)  {   //Mike impl
    
    //====================================================================================
    // If flush & init values are identical, increase the read count, no code needed.
    // When the discrepancy is found, read (rotate the ring) up to current address 
    // then scan/write in the last 32 bits
    //====================================================================================
    // TODO: add polling routine and change the max ring to 65535?  Need to check with HW team
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
        //CMO: This addr calc only works if baseAddr=0 in those bits where rotateLen=1?
        scanRing_poreAddr=scanRing_baseAddr | rotateLen;

        MY_DBG("base addr = 0x8%x, pore addr = 0x8%x, rotatelen = %d", scanRing_baseAddr, scanRing_poreAddr, rotateLen);

        //SCR1RD: shift out then read
        pgas_rc=pore_LD(&ctx, D0, scanRing_poreAddr, P0);
        if (pgas_rc > 0)  {
          MY_ERR("***LD D0 rc = %d", pgas_rc);
          return pgas_rc;
        }  

      } // End of if (rotateLen>0)

      // If the rotate length is <= 32, rotate by 32 or remaining bits if len <32
      if (remainingBits>32)
        scanRing_poreAddr = scanRing_baseAddr | 32;
      else
        scanRing_poreAddr = scanRing_baseAddr | remainingBits;

      //LI : Load XORed value to Scratch 1 reg.   (same as p7+)
      //TODO:    Check why not overwrite with init values?
      pore_imm64b = ((uint64_t)i_deltaRing[i]) << 32;

      pgas_rc = pore_LI(&ctx, D0, pore_imm64b );
      if (pgas_rc > 0)  {
        MY_ERR("***(2)LI D0 rc = %d", pgas_rc);
        return pgas_rc;
      }

      pgas_rc = pore_STD(&ctx, D0, scanRing_poreAddr, P0);
      if (pgas_rc > 0)  {
        MY_ERR("***STD D0 rc = %d", pgas_rc);
        return pgas_rc;
      }

      rotateLen=0;  //reset rotate length
    }  
    else  {  
      // OK, so i_deltaRing==0 (init and alter states are identical)
      // Increase rotate length by remaining scan bits (32 by default)
        // TODO : the max rotate ring size needs to be modified.
      //        there will be no size limit, but will add polling once the feture is available
      
      // Increase rotate length by remaining scan bits (default 32 bits)
      if (remainingBits>32)
        rotateLen = rotateLen + 32;
      else
         rotateLen = rotateLen + remainingBits;

      // This section will be modfied
      // PORE does not release PIB/PCB until CC acks, thus limiting bandwidth
      // It will time out if more than 4095 bits need to be rotated
      // If rotate length is more than 4032 (allows to rotate up to 4064 bits
      // Rotate the chain and reset rotate length counter
      if (rotateLen>0xFC0)  {
        scanRing_poreAddr = scanRing_baseAddr | rotateLen;
        pgas_rc = pore_LD(&ctx, D0, scanRing_poreAddr, P0);
        if (pgas_rc > 0)  {
          MY_ERR("***LD D0 rc = %d", pgas_rc);
          return pgas_rc;
        }

        rotateLen=0;
      } //end of if (roateLen >0xFC0)

    } //end of else (i_deltaRing==0)

    if (remainingBits>32)
      remainingBits = remainingBits - 32;
    else
       remainingBits = 0;

  } // End of for loop
       
  // If the scan ring has not been rotated to the original position
  //  shift the ring by remaining shift bit length
  if (rotateLen>0)  {
    scanRing_poreAddr=scanRing_baseAddr | rotateLen;
    pgas_rc = pore_LD(&ctx, D0, scanRing_poreAddr, P0);
    if (pgas_rc > 0)  {
      MY_ERR("***LD D0 rc = %d", pgas_rc);
      return pgas_rc;
    }
    rotateLen=0;
  }

  // Finally, check that our header check word went through in one piece.
  //
  // Load the output check word...
  pgas_rc = pore_LD(&ctx, D0, scanRing_baseAddr, P0) |
  // Compare against the reference header check word...
            pore_XORI( &ctx, D0, D0, ((uint64_t)scanRingCheckWord) << 32) |
  // For now, branch to HALT instruction if not equal, otherwise return in the following instruction...
  // But eventually branch to firmware error_handler if not equal
  //          pore_BRANZ(&ctx, D0, error_handler) ||
            PORE_LOCATION( &ctx, src3)   |
//            pore_BRANZ( &ctx, D0, ctx.lc+8) ||  // Jump two 4-byte instr (incl this one) to get to HALT.
            pore_BRANZ( &ctx, D0, tgt3)  |  // Jump two 4-byte instr (incl this one) to get to HALT.
            pore_RET( &ctx)             |
            PORE_LOCATION( &ctx, tgt3)  |
            pore_HALT( &ctx);
  if (pgas_rc > 0)  {
    MY_ERR("***LD, XORI, BRANZ, RET or HALT went wrong  rc = %d", pgas_rc);
    return pgas_rc;
  }
  pgas_rc = pore_inline_branch_fixup( &ctx, src3, tgt3);
  if (pgas_rc>0)  {
    MY_ERR("***inline_branch_fixup rc = %d", pgas_rc);
    return pgas_rc;
  }

  osIndex = ctx.lc/4;
  *o_wfInlineLenInWords = osIndex;

  return rc;
}



// write_wiggle_flip_to_image()
// 1 - mmap input image,
// 2 - Compose delta binary buffer containing RS4 launcher + RS4 delta data,
// 3 - Append delta buffer to .initf section.
// 4 - Save new image to output image file.
int write_wiggle_flip_to_image(  void *io_imageOut,
                                uint32_t  *i_sizeImageMaxNew,
                                DeltaRingLayout *i_ringLayout,
                                uint32_t  *i_wfInline,
                                uint32_t  i_wfInlineLenInWords)
{
  uint32_t rc=0, bufLC;
  uint32_t sizeImageIn, sizeNewDataBlock;
  uint32_t sizeImageOutThisEst=0, sizeImageOutThis=0;
  void *initfBuffer=NULL;
  uint32_t ringRingsOffset=0;
  uint64_t ringPoreAddress=0,backPtr=0,fwdPtr=0,fwdPtrCheck;
  
  SBE_XIP_ERROR_STRINGS(errorStrings);

  MY_DBG("wfInlineLenInWords=%i", i_wfInlineLenInWords);  
  
  // Modify the input ring layout content
  // - Remove the qualifier section: ddLevel, sysPhase, override and reserved1+2.  This means
  //    reducing the entryOffset by the size of these qualifiers.
  // - Adjust sizeOfThis
  // - Use new wfInline member of ring layout struct.
  // - Ignore the rs4Delta member
  //
  // For sizeOfThis, we must ensure 4-byte alignment WF code.  That is easy since both entryOffset
  //  and wfInlineLenInWord are already word-aligned.
  //
  i_ringLayout->entryOffset  =  myRev64(  myRev64(i_ringLayout->entryOffset) -
                                      sizeof(i_ringLayout->ddLevel) -
                                      sizeof(i_ringLayout->sysPhase) -
                                      sizeof(i_ringLayout->override) -
                                      sizeof(i_ringLayout->reserved1) -
                                      sizeof(i_ringLayout->reserved2) ); 
  i_ringLayout->sizeOfThis   =  myRev32(  myRev64(i_ringLayout->entryOffset) + 
                                      i_wfInlineLenInWords*4 );
  // Not really any need for this. Just being consistent. Once we have transitioned completely to new
  //  headers, then ditch i_wfInline from parm list and assign wfInline to layout in main program. 
  i_ringLayout->wfInline    = i_wfInline;
  
  if (((uintptr_t)i_ringLayout)%4 || myRev64(i_ringLayout->entryOffset)%4)  {
    MY_ERR("ERROR : Ring layout is not word-aligned.");
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
  
  MY_DBG("Input image size\t\t= %6i\n\tNew initf data block size\t= %6i\n\tOutput image size\t\t<=%6i",
    sizeImageIn, sizeNewDataBlock, sizeImageOutThisEst);
  MY_DBG("entryOffset = %i\n\tsizeOfThis = %i\n\tMeta data size = %i",
    (uint32_t)myRev64(i_ringLayout->entryOffset), myRev32(i_ringLayout->sizeOfThis), myRev32(i_ringLayout->sizeOfMeta));
  MY_DBG("Back item ptr = 0x%016llx",myRev64(i_ringLayout->backItemPtr));
  MY_DBG("DD level = %i\n\tSys phase = %i\n\tOverride = %i\n\tReserved1+2 = %i",
    myRev32(i_ringLayout->ddLevel), i_ringLayout->sysPhase, i_ringLayout->override, i_ringLayout->reserved1|i_ringLayout->reserved2);

  // Combine rs4RingLayout members into a unified buffer (initfBuffer).
  //
  initfBuffer = malloc((size_t)sizeNewDataBlock);
  if (initfBuffer == NULL)  {
    MY_ERR("ERROR : malloc() of initf buffer failed.");
    return IMGBUILD_ERR_MEMORY;
  }
  // ... and copy the WF ring layout content into initfBuffer in BIG-ENDIAN format.
  bufLC = 0;
  memcpy( (uint8_t*)initfBuffer+bufLC, &i_ringLayout->entryOffset, (uintptr_t)&i_ringLayout->metaData-(uintptr_t)&i_ringLayout->entryOffset);
  bufLC = (uintptr_t)&i_ringLayout->metaData-(uintptr_t)&i_ringLayout->entryOffset;
  memcpy( (uint8_t*)initfBuffer+bufLC, i_ringLayout->metaData, myRev32(i_ringLayout->sizeOfMeta));

  bufLC = (uint32_t)myRev64(i_ringLayout->entryOffset); 
  // The above forces word-alignment of bufLC as [previous] metaData member is only byte aligned.
  memcpy( (uint8_t*)initfBuffer+bufLC, i_wfInline, i_wfInlineLenInWords*4);
  
  // Append WF ring layout to .rings section of in-memory input image.
  //   Note! All layout members should already be 4-byte-aligned.
  //
  rc = sbe_xip_append( io_imageOut, 
                       SBE_XIP_SECTION_RINGS, 
                       (void*)initfBuffer,
                       sizeNewDataBlock,
                       sizeImageOutThisEst,
                       &ringRingsOffset);
  MY_DBG("ringRingsOffset=0x%08x",ringRingsOffset);
  if (rc)   {
    MY_ERR("ERROR : sbe_xip_append() failed: %s", SBE_XIP_ERROR_STRING(errorStrings, rc));
    if (initfBuffer)  free(initfBuffer);
    return IMGBUILD_ERR_XIP_MISC;
  }
  // ...get new image size, update return size, and test if successful update.
  sbe_xip_image_size( io_imageOut, &sizeImageOutThis);
  MY_DBG("Output image size (final)\t=%i",sizeImageOutThis);
	*i_sizeImageMaxNew = sizeImageOutThis;
  rc = sbe_xip_validate( io_imageOut, sizeImageOutThis);
  if (rc)   {
    MY_ERR("ERROR : sbe_xip_validate() of output image failed: %s", SBE_XIP_ERROR_STRING(errorStrings, rc));
    if (initfBuffer)  free(initfBuffer);
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
    if (initfBuffer)  free(initfBuffer);
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
    if (initfBuffer)  free(initfBuffer);
    return IMGBUILD_ERR_XIP_MISC;
  }
  if (fwdPtrCheck!=ringPoreAddress || backPtr!=myRev64(i_ringLayout->backItemPtr))  {
    MY_ERR("ERROR : Forward or backward pointer mess. Check code."); 
    MY_ERR("fwdPtr       =0x%016llx",fwdPtr);
    MY_ERR("fwdPtrCheck  =0x%016llx",fwdPtrCheck);
    MY_ERR("layout bckPtr=0x%016llx",myRev64(i_ringLayout->backItemPtr));
    MY_ERR("backPtr      =0x%016llx",backPtr);
    if (initfBuffer)  free(initfBuffer);
    return IMGBUILD_ERR_FWD_BACK_PTR_MESS;
  }
  // ...test if successful update.
  rc = sbe_xip_validate( io_imageOut, sizeImageOutThis);
  if (rc)   {
    MY_ERR("ERROR : sbe_xip_validate() of output image failed: %s", SBE_XIP_ERROR_STRING(errorStrings, rc));
    MY_ERR("Probable cause:");
    MY_ERR("\tsbe_xip_write_uint64() updated at the wrong address (=0x%016llx)",
      myRev64(i_ringLayout->backItemPtr));
    if (initfBuffer)  free(initfBuffer);
    return IMGBUILD_ERR_XIP_MISC;
  }
  
  if (initfBuffer)  free(initfBuffer);
    
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
