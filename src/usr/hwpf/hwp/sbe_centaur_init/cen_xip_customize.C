/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/sbe_centaur_init/cen_xip_customize.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2015                        */
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
// $Id: cen_xip_customize.C,v 1.15 2014/09/12 21:29:23 mklight Exp $
/*------------------------------------------------------------------------------*/
/* *! TITLE : cen_xip_customize.C                                               */
/* *! DESCRIPTION : Customizes Centaur images from a Centaur reference image.   */
/* *! OWNER NAME : Michael Olsen                  cmolsen@us.ibm.com            */
//
/* *! EXTENDED DESCRIPTION :                                                    */
//
/* *! USAGE : 
              To build (for Hostboot) -
              buildfapiprcd   -c "sbe_xip_image.c,pore_inline_assembler.c,p8_ring_identification.c"   -C "p8_image_help.C,p8_image_help_base.C,p8_pore_table_gen_api_fixed.C,p8_scan_compression.C"   -e "../../xml/error_info/cen_xip_customize_errors.xml,../../xml/error_info/proc_sbe_decompress_scan_halt_codes.xml,../../../../../../hwpf/hwp/xml/error_info/mvpd_errors.xml"   cen_xip_customize.C                                               */
//
/* *! ASSUMPTIONS :                                                             */
//
/* *! COMMENTS :                                                                */
//
/*------------------------------------------------------------------------------*/
#define __CEN_XIP_CUSTOMIZE_C
#include <cen_xip_customize.H>
#include <p8_delta_scan_rw.h>
#include <p8_pore_table_gen_api.H>

extern "C"  {

using namespace fapi;


const uint32_t FSI_GP4_DMI_REFCLOCK_TERM_START_BIT = 8;
const uint32_t FSI_GP4_DMI_REFCLOCK_TERM_END_BIT = 9;

const uint32_t FSI_GP4_DDR_REFCLOCK_TERM_START_BIT = 10;
const uint32_t FSI_GP4_DDR_REFCLOCK_TERM_END_BIT = 11;


//  Parameter list:
//  const fapi::Target &i_target:  Processor chip target.
//  void      *i_imageIn:      Ptr to input image.
//  void      *i_imageOut:     Ptr to output img.
//  uint32_t  io_sizeImageOut: In: Max size of img. Out: Final size.
//  void      *i_buf1:         Temp buffer 1 for dexed RS4 ring. Caller allocs/frees.
//  uint32_t  i_sizeBuf1:      Size of buf1.
//  void      *i_buf2:         Temp buffer 2 for WF ring. Caller allocs/frees.
//  uint32_t  i_sizeBuf22      Size of buf2.
//
ReturnCode cen_xip_customize(const fapi::Target &i_target,
                             void            *i_imageIn,
                             void            *i_imageOut,
                             uint32_t        &io_sizeImageOut,
                             void            *i_buf1,
                             const uint32_t  i_sizeBuf1,
                             void            *i_buf2,
                             const uint32_t  i_sizeBuf2 )
{
  fapi::ReturnCode rc;
  uint32_t  rcLoc=0;
  uint32_t  sizeImage, sizeImageIn, sizeImageOutMax;

  sizeImageOutMax = io_sizeImageOut;
  
  // ==========================================================================
  // Check and copy input image.
  // ==========================================================================
  //
  // First, check supplied size and validation of input image.
  //
  sbe_xip_image_size(i_imageIn, &sizeImageIn);
  rcLoc = sbe_xip_validate(i_imageIn, sizeImageIn);
  if (rcLoc)  {
    FAPI_ERR("xip_validate() failed w/rcLoc=%i",rcLoc);
    uint32_t & RC_LOCAL = rcLoc;
    FAPI_SET_HWP_ERROR(rc, RC_CEN_XIPC_UNSPECIFIED_IMAGE_ERR);
    return rc;
  }
  
  // Second, copy input image to supplied output image location.
  //    
  memcpy( i_imageOut, i_imageIn, sizeImageIn);
  sbe_xip_image_size(i_imageOut, &sizeImage);
  rcLoc = sbe_xip_validate(i_imageOut, sizeImage);
  if (rcLoc)  {
    FAPI_ERR("xip_validate() failed w/rcLoc=%i",rcLoc);
    uint32_t & RC_LOCAL=rcLoc;
    FAPI_SET_HWP_ERROR(rc, RC_CEN_XIPC_UNSPECIFIED_IMAGE_ERR);
    return rc;
  }
  if (sizeImage!=sizeImageIn)  {
    FAPI_ERR("Size obtained from image's header (=%i) differs from supplied size (=%i).",
      sizeImage,sizeImageIn);
    uint32_t & DATA_IMG_SIZE_INP = sizeImageIn;
    uint32_t & DATA_IMG_SIZE = sizeImage;
    FAPI_SET_HWP_ERROR(rc, RC_CEN_XIPC_IMAGE_SIZE_MISMATCH);
    return rc;
  }
  FAPI_DBG("Input image (w/location=0x%016llx) copied to output image and validated w/size=%i bytes and location=0x%016llx",
    (uint64_t)i_imageIn, sizeImageIn, (uint64_t)i_imageOut);

  // --------------------------------------------------------------------------
  // CUSTOMIZE item:    Update PLL ring (tp_pll_bndy_ring_alt).
  // Retrieval method:  Attribute.
  // --------------------------------------------------------------------------
  uint32_t  tmp32Const1, tmp32Const2;
  uint8_t   attrRingFlush[MAX_CEN_PLL_RING_SIZE]={0};
  uint8_t   attrRingData[MAX_CEN_PLL_RING_SIZE]={0};
  uint8_t   attrChipletId=0xff;
  uint32_t  attrScanSelect=0;
  uint32_t  attrRingDataSize=0; // Ring bit size
  uint32_t  sizeDeltaPllRingAlt=0;
  uint8_t   *bufDeltaPllRingAlt;
  uint64_t  scanMaxRotate=SCAN_ROTATE_DEFAULT;
  uint32_t  *wfInline=NULL;
  uint32_t  wfInlineLenInWords;
  uint32_t  bufLC=0;

  //
  // Retrieve the raw PLL rings state from attributes.
  //
  FAPI_INF("PLL update: Retrieve the raw PLL ring state from attributes.");
  // Get ring size.
  rc = FAPI_ATTR_GET(ATTR_MEMB_TP_BNDY_PLL_LENGTH, &i_target, attrRingDataSize); // This better be in bits.
  if (rc)  {
    FAPI_ERR("FAPI_ATTR_GET(ATTR_MEMB_TP_BNDY_PLL_LENGTH) returned error.");
    return rc;
  }
  FAPI_DBG("PLL update: PLL ring length (bits) = %i",attrRingDataSize);
  FAPI_DBG("PLL update: Size of buf1, i_sizeBuf1 (bytes) = %i",i_sizeBuf1);
  if (attrRingDataSize>MAX_CEN_PLL_RING_SIZE*8 || attrRingDataSize>i_sizeBuf1*8)  {
    FAPI_ERR("FAPI_ATTR_GET(ATTR_MEMB_TP_BNDY_PLL_LENGTH) returned ring size =%i bits.\n",
              attrRingDataSize);
    FAPI_ERR("But that exceeds either:\n");
    FAPI_ERR("  the max pll ring size =%i bits, or\n",MAX_CEN_PLL_RING_SIZE*8);
    FAPI_ERR("  the size of the pre-allocated buf1 =%i bits.", i_sizeBuf1*8);
    uint32_t &DATA_ATTRIBUTE_RING_SIZE=attrRingDataSize;
    tmp32Const1=8*MAX_CEN_PLL_RING_SIZE;
    tmp32Const2=8*(uint32_t)i_sizeBuf1;
    uint32_t &DATA_MAX_PLL_RING_SIZE=tmp32Const1;
    uint32_t &DATA_SIZE_OF_BUF1=tmp32Const2;
    FAPI_SET_HWP_ERROR(rc, RC_CEN_XIPC_PLL_RING_SIZE_TOO_LARGE);
    return rc;
  }
  sizeDeltaPllRingAlt = attrRingDataSize; // We've already checked it'll fit into buf1.
  // Get flush and alter (desired) ring state data.
  rc = FAPI_ATTR_GET(ATTR_MEMB_TP_BNDY_PLL_FLUSH, &i_target, attrRingFlush);
  if (rc)  {
    FAPI_ERR("FAPI_ATTR_GET(ATTR_MEMB_TP_BNDY_PLL_FLUSH) returned error.");
    return rc;
  }
  rc = FAPI_ATTR_GET(ATTR_MEMB_TP_BNDY_PLL_DATA, &i_target, attrRingData);
  if (rc)  {
    FAPI_ERR("FAPI_ATTR_GET(ATTR_MEMB_TP_BNDY_PLL_DATA) returned error.");
    return rc;
  }
  rc = FAPI_ATTR_GET(ATTR_MEMB_TP_BNDY_PLL_SCAN_SELECT, &i_target, attrScanSelect);
  if (rc)  {
    FAPI_ERR("FAPI_ATTR_GET(ATTR_MEMB_TP_BNDY_PLL_SCAN_SELECT) returned error.");
    return rc;
  }
/*
  rc = FAPI_ATTR_GET(ATTR_MEMB_TP_BNDY_PLL_CHIPLET_ID, &i_target, attrChipletId);
  if (rc)  {
    FAPI_ERR("FAPI_ATTR_GET(ATTR_MEMB_TP_BNDY_PLL_CHIPLET_ID) returned error.");
    return rc;
  }
*/

  //
  // Calculate the delta scan ring.
  //
  FAPI_INF("PLL update: Calculate the delta scan ring.");
  bufDeltaPllRingAlt = (uint8_t*)i_buf1;
  rcLoc = calc_ring_delta_state( (uint32_t*)attrRingFlush,
                                  (uint32_t*)attrRingData,
                                  (uint32_t*)bufDeltaPllRingAlt, // Pre-allocated buffer.
                                  sizeDeltaPllRingAlt );
  if (rcLoc)  {
    FAPI_ERR("calc_ring_delta_state() returned error w/rcLoc=%i",rcLoc);
    FAPI_ERR("Check p8_delta_scan_rw.h for meaning of IMGBUILD_xyz rc code.");
    uint32_t &RC_LOCAL=rcLoc;
    FAPI_SET_HWP_ERROR(rc, RC_CEN_XIPC_IMGBUILD_ERROR);
    return rc;
  }

  //
	// Create wiggle-flip (WF) program.
	//
  //scanMaxRotate = SCAN_MAX_ROTATE; // Max out on rotate length. P8 PLL running.
  scanMaxRotate = SCAN_ROTATE_DEFAULT; // Max out on rotate length. P8 PLL running.
/*
  rcLoc = sbe_xip_get_scalar( i_imageOut, SCAN_MAX_ROTATE_38XXX_NAME, &scanMaxRotate);
	if (rcLoc)  {
	  FAPI_ERR("Strange error from sbe_xip_get_scalar(SCAN_MAX_ROTATE_38XXX_NAME) w/rcLoc=%i; ",rcLoc);
	  FAPI_ERR("Already retrieved SCAN_MAX_ROTATE_38XXX_NAME in slw_build() w/o trouble; ");
	  uint32_t &RC_LOCAL=rcLoc;
	  FAPI_SET_HWP_ERROR(rc, RC_CEN_XIPC_UNSPECIFIED_IMAGE_ERR);
	  return rc;
	}
	if (scanMaxRotate<0x20 || scanMaxRotate>SCAN_MAX_ROTATE)  {
	  FAPI_INF("WARNING: Value of key word SCAN_MAX_ROTATE_38XXX_NAME=0x%llx is not permitted; ",scanMaxRotate);
    scanMaxRotate = SCAN_ROTATE_DEFAULT;
		FAPI_INF("scanMaxRotate set to 0x%llx; ", scanMaxRotate);
		FAPI_INF("Continuing...; ");
	}
*/
	wfInline = (uint32_t*)i_buf2;  // Use HB buf2 for wiggle-flip prg.
	wfInlineLenInWords = i_sizeBuf2/4;
	rcLoc = create_wiggle_flip_prg((uint32_t*)bufDeltaPllRingAlt,
	                            sizeDeltaPllRingAlt,
	                            attrScanSelect, //=0x00100008,  // addr=0x00030088 ?
	                            attrChipletId, //=0xff,
	                            &wfInline,
	                            &wfInlineLenInWords, // Is 8-byte aligned on return.
                              1,  // Always do flush optimization.
	                            (uint32_t)scanMaxRotate,
                              0,  // No need to use waits for Centaur.
                              0); // Centaur doesn't support scan polling.
	if (rcLoc)  {
	  FAPI_ERR("create_wiggle_flip_prg() failed w/rcLoc=%i",rcLoc);
	  uint32_t &RC_LOCAL=rcLoc;
	  FAPI_SET_HWP_ERROR(rc, RC_CEN_XIPC_IMGBUILD_ERROR);
	  return rc;
	}

  //
  // Populate ring header and put ring header and Wf ring into 
  // proper spots in pre-allocated bufWfRingBlock buffer (HB buf1).
  //
  DeltaRingLayout *bufWfRingBlock;
  uint64_t entryOffsetWfRingBlock;
  uint32_t sizeWfRingBlock, sizeWfRingBlockMax;

  bufWfRingBlock = (DeltaRingLayout*)i_buf1; // Reuse HB buf1 for WF ring block.
  sizeWfRingBlockMax = i_sizeBuf1;
  entryOffsetWfRingBlock      = calc_ring_layout_entry_offset( 1, 0);
  bufWfRingBlock->entryOffset = myRev64(entryOffsetWfRingBlock);
  bufWfRingBlock->backItemPtr	= 0; // Will be updated below, as we don't know yet.
	sizeWfRingBlock     	      =	entryOffsetWfRingBlock +  // Must be 8-byte aligned.
  												      wfInlineLenInWords*4;     // Must be 8-byte aligned.
	// Quick check to see if final ring block size will fit in HB buffer.
	if (sizeWfRingBlock>sizeWfRingBlockMax)  {
    FAPI_ERR("WF PLL _alt ring block size (=%i) exceeds pre-allocated buf1 size (=%i).",
      sizeWfRingBlock, sizeWfRingBlockMax);
    uint32_t &DATA_RING_BLOCK_SIZEOFTHIS=sizeWfRingBlock;
    uint32_t &DATA_SIZE_OF_BUF1=sizeWfRingBlock;
    FAPI_SET_HWP_ERROR(rc, RC_CEN_XIPC_PLL_RING_BLOCK_TOO_LARGE);
    return rc;
	}
	bufWfRingBlock->sizeOfThis  = myRev32(sizeWfRingBlock);
	bufWfRingBlock->sizeOfMeta	=	0;
	bufLC = (uint32_t)entryOffsetWfRingBlock;
	// Copy over meta data which is zero, so nothing to do in this case!
	// Copy over WF ring prg which is already 8-byte aligned.
	memcpy( (uint8_t*)bufWfRingBlock+bufLC, wfInline, (size_t)wfInlineLenInWords*4);

  // Now, some post-sanity checks on alignments.
	if ( entryOffsetWfRingBlock%8 || 
	     sizeWfRingBlock%8)  {
		FAPI_ERR("Member(s) of WF ring block are not 8-byte aligned:");
    FAPI_ERR("  Entry offset            = %i", (uint32_t)entryOffsetWfRingBlock);
		FAPI_ERR("  Size of ring block      = %i", sizeWfRingBlock);
    tmp32Const1=(uint32_t)entryOffsetWfRingBlock;
    uint32_t &DATA_RING_BLOCK_ENTRYOFFSET=tmp32Const1;
    uint32_t &DATA_RING_BLOCK_SIZEOFTHIS=sizeWfRingBlock;
    FAPI_SET_HWP_ERROR(rc, RC_CEN_XIPC_RING_BLOCK_ALIGN_ERROR);
    return rc;
	}

  //
  // Append PLL _alt ring to image.
  //
  FAPI_INF("PLL update: Appending WF PLL ring block to .rings section.");
  rcLoc = write_ring_block_to_image( i_imageOut,
                                     TP_PLL_BNDY_RING_ALT_TOC_NAME,
                                     bufWfRingBlock,
                                     0,
                                     0,
                                     0,
                                     sizeImageOutMax,
                                     SBE_XIP_SECTION_RINGS,
                                     i_buf2,      // Use buf2 as temp buf.
                                     i_sizeBuf2 );
  if (rcLoc)  {
    FAPI_ERR("write_ring_block_to_image() failed w/rc=%i",rcLoc);
    FAPI_ERR("Check p8_delta_scan_rw.h for meaning of IMGBUILD_xyz rc code.");
    uint32_t &RC_LOCAL=rcLoc;
    FAPI_SET_HWP_ERROR(rc, RC_CEN_XIPC_IMGBUILD_ERROR);
    return rc;
  }

  // ==========================================================================
  // CUSTOMIZE item:    Centaur reference clock termination
  // Retrieval method:  Attribute.
  // ==========================================================================

  uint8_t attrDMIRefclockTerm;
  uint8_t attrDDRRefclockTerm;
  SbeXipItem xipTocItem;
  void *xipTocItemPtr;
  uint64_t *refclockTermPtr;
  ecmdDataBufferBase refclockTerm(64);
  SBE_XIP_ERROR_STRINGS(errorStrings);

  rc = FAPI_ATTR_GET(ATTR_MEMB_DMI_REFCLOCK_RCVR_TERM, NULL, attrDMIRefclockTerm);
  if (rc) {
    FAPI_ERR("FAPI_ATTR_GET(ATTR_MEMB_DMI_REFCLOCK_RCVR_TERM) returned error.\n");
    return rc;
  }

  rc = FAPI_ATTR_GET(ATTR_MEMB_DDR_REFCLOCK_RCVR_TERM, NULL, attrDDRRefclockTerm);
  if (rc) {
    FAPI_ERR("FAPI_ATTR_GET(ATTR_MEMB_DDR_REFCLOCK_RCVR_TERM) returned error.\n");
    return rc;
  }

  // form customization data
  rcLoc |= refclockTerm.insertFromRight(attrDMIRefclockTerm,
                                        FSI_GP4_DMI_REFCLOCK_TERM_START_BIT,
                                        (FSI_GP4_DMI_REFCLOCK_TERM_END_BIT-
                                         FSI_GP4_DMI_REFCLOCK_TERM_START_BIT+1));
  rcLoc |= refclockTerm.insertFromRight(attrDDRRefclockTerm,
                                        FSI_GP4_DDR_REFCLOCK_TERM_START_BIT,
                                        (FSI_GP4_DDR_REFCLOCK_TERM_END_BIT-
                                         FSI_GP4_DDR_REFCLOCK_TERM_START_BIT+1));

  if (rcLoc) {
    FAPI_ERR("Error 0x%x forming refclock termination data buffer", rcLoc);
    rc.setEcmdError(rcLoc);
    return rc;
  }

  // look up customization location
  rcLoc = sbe_xip_find(i_imageOut, REFCLOCK_TERM_TOC_NAME, &xipTocItem);
  if (rcLoc) {
    FAPI_ERR("sbe_xip_find() failed w/rc=%i and %s", rcLoc, SBE_XIP_ERROR_STRING(errorStrings, rcLoc));
    FAPI_ERR("Probable cause:");
    FAPI_ERR("\tThe keyword (=%s) was not found.", REFCLOCK_TERM_TOC_NAME);
    uint32_t & RC_LOCAL = rcLoc;
    FAPI_SET_HWP_ERROR(rc, RC_CEN_XIPC_KEYWORD_NOT_FOUND_ERROR);
    return rc;
  }

  sbe_xip_pore2host(i_imageOut, xipTocItem.iv_address, &xipTocItemPtr);
  refclockTermPtr = (uint64_t*)xipTocItemPtr;
  *(refclockTermPtr + 0) = myRev64(refclockTerm.getDoubleWord(0));

  //
  // Done
  //  

  sbe_xip_image_size( i_imageOut, &io_sizeImageOut);
  
  return rc;
  
}


} // End of extern C
