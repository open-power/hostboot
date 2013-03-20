/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_slw_build/p8_slw_build.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
// $Id: p8_slw_build.C,v 1.21 2013/03/14 03:07:11 cmolsen Exp $
/*------------------------------------------------------------------------------*/
/* *! TITLE : p8_slw_build                                                      */
/* *! DESCRIPTION : Extracts and decompresses delta ring states from EPROM      */
//                  image. Utilizes the linked list approach (LLA) to extract
//                  and position wiggle-flip programs in .rings according to 
//                  back pointer, DD level, phase and override settings. 
/* *! OWNER NAME : Michael Olsen                  cmolsen@us.ibm.com            */
//
/* *! EXTENDED DESCRIPTION :                                                    */
//
/* *! USAGE : To build (for Hostboot) -                                         */
//              buildfapiprcd  -C "p8_image_help.C,p8_image_help_base.C,p8_scan_compression.C"  -c "sbe_xip_image.c,pore_inline_assembler.c" -e "../../xml/error_info/p8_slw_build_errors.xml"  p8_slw_build.C
//            To build (for command-line) -
//              buildfapiprcd  -r ver-13-0  -C "p8_image_help.C,p8_image_help_base.C,p8_scan_compression.C"  -c "sbe_xip_image.c,pore_inline_assembler.c" -e "../../xml/error_info/p8_slw_build_errors.xml"  -u "SLW_COMMAND_LINE,IMGBUILD_PPD_IGNORE_XIPC,IMGBUILD_PPD_WF_POLLING_PROT"  p8_slw_build.C
//            Other Pre-Processor Directive (PPD) options - 
//            To debug WF programs:
//              -u "IMGBUILD_PPD_DEBUG_WF"
//            To add worst-case PIB access to wf programs:
//              -u "IMGBUILD_PPD_WF_WORST_CASE_PIB"
//            To add polling protocol to wf programs:
//              -u "IMGBUILD_PPD_WF_POLLING_PROT"
//            (NB!  This will eventually be changed to IMGBUILD_PPD_WF_NO POLLING_PROT
//                  because we want the polling protocol to be default.)
//            To NOT run xip_customize:
//              -u "IMGBUILD_PPD_IGNORE_XIPC"
//            (NB!  Thus, by defaul for HB and PHYP, since they don't used PPDs,
//                  xip_customize() will always be called.)
//
/* *! ASSUMPTIONS :                                                             */
//    - For Hostboot environment:
//      - No precompiler directives needed
//      - dynamic P0/P1 calculation
//      - polling scan protocol
//      - check header word after WF
//      - sysPhase=1
//      - non-command-line mode, FAPI call
//
/* *! COMMENTS :                                                                */
//    - All image content, incl .initf content and ring layout, is handled
//      in BE format. No matter which platform.
//    - A ring may only be requested with the sysPhase=0 or 1. Any other 
//      sysPhase value, incl sysPhase=2, will cause no rings to be found.
//
/*------------------------------------------------------------------------------*/

#include <p8_pore_api_custom.h>
#include <HvPlicModule.H>
#include <p8_slw_build.H>
#include <p8_xip_customize.H>
#include <p8_delta_scan_rw.h>
#include <p8_pore_table_gen_api.H>

extern "C"  {

using namespace fapi;

//  Parameter list:
//  fapi::Target &i_target:    Hardware target
//  void       *i_imageIn:     Pointer to memory mapped input Reference PNOR image
//  uint32_t  i_sizeImageIn:  Size of input image.
//  void      *i_imageOut:    Pointer to where to put SLW mainstore image
//  uint32_t  *io_sizeImageOut:  Size of output image. Initial upper limit supplied by HB. Final size returned.
//
ReturnCode p8_slw_build( const fapi::Target    &i_target,
                         const void       *i_imageIn,
                         uint32_t         i_sizeImageIn,
                         void             *i_imageOut,
                         uint32_t         *io_sizeImageOut)
{
  ReturnCode rc;
  uint8_t   l_uint8 = 0;
  uint32_t  ddLevel=0;
  uint8_t   sysPhase=1;
  uint32_t  rcLoc=0, rcSearch=0, i, countWF=0;
  uint32_t  sizeImage=0, sizeImageOutMax, sizeImageTmp, sizeImageOld;
  CompressedScanData *deltaRingRS4=NULL;
  DeltaRingLayout rs4RingLayout;
  void  		*nextRing=NULL;
  uint32_t  ringBitLen=0;
  uint32_t  *wfInline=NULL;
  uint32_t  wfInlineLenInWords;
	uint64_t  scanMaxRotate=SCAN_ROTATE_DEFAULT;
  sizeImageOutMax = *io_sizeImageOut;
	
	
	// 2012-11-13: CMO- Temporary defines of ring buffers. This will be changed by
	//             Dec 03 where we'll switch over to a fixed size image for ffdc
	//             support and will schedule the enhancement to slw_build's 
	//             interface to accept these buffers as well as to ditch
	//             io_sizeImageOut. We also should drop i_sizeImageIn. It really
	//             serves no purpose to require caller to pass this when we can 
	//             immediately retrieve through xip_image_size().
	//             CMO- Very important. Stop freeing buffers, incl wfInline, once
	//             these buffers are being passed as parms by slw_build().
  void      *buf1=NULL, *buf2=NULL;
  uint32_t  sizeBuf1=0, sizeBuf2=0;
	uint32_t  rcTmp=1;
  sizeBuf1 = FIXED_RING_BUF_SIZE;
  buf1 = malloc(sizeBuf1);
  if (!buf1)  {
    FAPI_ERR("malloc() for ring buffer 1 failed.");
    uint32_t & RC_LOCAL = rcTmp;
	  FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_MEMORY_ERROR);
	  return rc;
	}
  sizeBuf2 = FIXED_RING_BUF_SIZE;
  buf2 = malloc(sizeBuf2);
  if (!buf2)  {
    FAPI_ERR("malloc() for ring buffer 1 failed.");
    uint32_t & RC_LOCAL = rcTmp;
	  FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_MEMORY_ERROR);
    free(buf1);
	  return rc;
  }


	// Sanity check.
  if (sizeImageOutMax<i_sizeImageIn)  {
    FAPI_ERR("Inp image size (from caller): %i",i_sizeImageIn);
    FAPI_ERR("Max image size (from caller): %i",*io_sizeImageOut);
    uint32_t & DATA_IMG_SIZE_INP = i_sizeImageIn;
		uint32_t & DATA_IMG_SIZE_MAX = *io_sizeImageOut;
		FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_INPUT_IMAGE_SIZE_MESS);
    return rc;
  }
    
  // ==========================================================================
  // Check and copy image to mainstore and clean it up.
  // ==========================================================================
  // ToDo:
  // - Eventually, automate emptying sections in proper order (last section goes first).
  // - For 5/15, assume following order of removal: rings, pibmem0, and halt.
  //
  // First, check supplied size and validation of input EPROM image.
  //
  sbe_xip_image_size((void*)i_imageIn, &sizeImage);
  rcLoc = sbe_xip_validate((void*)i_imageIn, sizeImage);
  if (rcLoc)  {
    FAPI_ERR("xip_validate() failed w/rcLoc=%i",rcLoc);
    uint32_t & RC_LOCAL = rcLoc;
    FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_INTERNAL_IMAGE_ERR);
    return rc;
  }
  if (sizeImage!=i_sizeImageIn)  {
    FAPI_ERR("Size obtained from image's header (=%i) differs from supplied size (=%i).",
      sizeImage,i_sizeImageIn);
    uint32_t & DATA_IMG_SIZE_INP = i_sizeImageIn;
    uint32_t & DATA_IMG_SIZE = sizeImage;
    FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_IMAGE_SIZE_MISMATCH);
    return rc;
  }
  FAPI_DBG("Image size (in EPROM): %i",i_sizeImageIn);
  
  // Second, copy input image to supplied mainstore location.
  //
  memcpy( i_imageOut, i_imageIn, i_sizeImageIn);
  sbe_xip_image_size(i_imageOut, &sizeImage);
  rcLoc = sbe_xip_validate(i_imageOut, sizeImage);
  if (rcLoc)  {
    FAPI_ERR("xip_validate() failed w/rcLoc=%i",rcLoc);
		uint32_t & RC_LOCAL=rcLoc;
    FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_MS_INTERNAL_IMAGE_ERR);
    return rc;
  }
  if (sizeImage!=i_sizeImageIn)  {
    FAPI_ERR("Size obtained from image's header (=%i) differs from supplied size (=%i).",
      sizeImage,i_sizeImageIn);
    uint32_t & DATA_IMG_SIZE_INP = i_sizeImageIn;
    uint32_t & DATA_IMG_SIZE = sizeImage;
    FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_MS_IMAGE_SIZE_MISMATCH);
    return rc;
  }

  // Third, delete .rings and .pibmem0 sections (but keep .halt)
  //
  rcLoc = sbe_xip_delete_section( i_imageOut, SBE_XIP_SECTION_RINGS);
  if (rcLoc)  {
    FAPI_ERR("xip_delete_section(.rings) failed w/rcLoc=%i",rcLoc);
	  uint32_t & RC_LOCAL=rcLoc;
    FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_DELETE_IMAGE_SECTION_ERROR);
    return rc;
  }
  sbe_xip_image_size(i_imageOut, &sizeImage);
  rcLoc =  sbe_xip_validate(i_imageOut, sizeImage);
  if (rcLoc)  {
	  FAPI_ERR("xip_validate() failed w/rcLoc=%i",rcLoc);
	  uint32_t & RC_LOCAL=rcLoc;
    FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_MS_INTERNAL_IMAGE_ERR);
    return rc;
  }
  FAPI_DBG("Image size (after .rings delete): %i",sizeImage);

  rcLoc = sbe_xip_delete_section( i_imageOut, SBE_XIP_SECTION_PIBMEM0);
  if (rcLoc)  {
    FAPI_ERR("xip_delete_section(.pibmem0) failed w/rcLoc=%i",rcLoc);
	  uint32_t & RC_LOCAL=rcLoc;
    FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_DELETE_IMAGE_SECTION_ERROR);
    return rc;
  }
  sbe_xip_image_size(i_imageOut, &sizeImage);
  rcLoc =  sbe_xip_validate(i_imageOut, sizeImage);
  if (rcLoc)  {
	  FAPI_ERR("xip_validate() failed w/rcLoc=%i",rcLoc);
	  uint32_t & RC_LOCAL=rcLoc;
    FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_MS_INTERNAL_IMAGE_ERR);
    return rc;
  }
	FAPI_DBG("Image size (after .pibmem0 delete): %i",sizeImage);

	//
	// DD level.
	//
  rc = FAPI_ATTR_GET_PRIVILEGED(ATTR_EC, &i_target, l_uint8);
  ddLevel = (uint32_t)l_uint8;
  if (rc)  {
    FAPI_ERR("FAPI_ATTR_GET_PRIVILEGED() failed w/rc=%i and  ddLevel=0x%02x",(uint32_t)rc,l_uint8);
    return rc;
  }


#ifndef IMGBUILD_PPD_IGNORE_XIPC
  // ==========================================================================
  // Get various FAPI attributes and variables needed for ring unraveling.
  // ==========================================================================
	uint8_t    attrAsyncSafeMode=0, bAsyncSafeMode;
	uint32_t   attrFuncL3RingList[MAX_FUNC_L3_RING_LIST_ENTRIES]={0};
	uint8_t    attrFuncL3RingData[MAX_FUNC_L3_RING_SIZE]={0};
	uint32_t   attrFuncL3RingLength=0;
	SbeXipItem xipTocItem;
	uint64_t   xipFuncL3RingVector=0;
	uint32_t   iEntry;

	// Safe mode status.
	//
  rc = FAPI_ATTR_GET(ATTR_PROC_FABRIC_ASYNC_SAFE_MODE, NULL, attrAsyncSafeMode);
  FAPI_DBG("--> attrAsyncSafeMode = 0x%x ",attrAsyncSafeMode);
  if (rc)  {
    FAPI_ERR("FAPI_ATTR_GET(ATTR_PROC_FABRIC_ASYNC_SAFE_MODE) returned error.");
    return rc;
  }
	bAsyncSafeMode = attrAsyncSafeMode;
  FAPI_DBG("--> bAsyncSafeMode = 0x%x ",bAsyncSafeMode);
	
	// Obtain ex_func_l3_ring overlay data and length from attributes.
	// Obtain ring name and ring's vector location from image.
	//
  FAPI_DBG("--> (1) Check if we should modify the ex_func_l3_ring with attribute data.");
	if (!bAsyncSafeMode)  {
    FAPI_DBG("--> (1) Yes, we should modify the ex_func_l3_ring with attribute data.");
		// Get overlay ring from attributes.
	  rc = FAPI_ATTR_GET(ATTR_PROC_EX_FUNC_L3_DELTA_DATA, &i_target, attrFuncL3RingList);
	  if (rc)  {
	    FAPI_ERR("FAPI_ATTR_GET(ATTR_PROC_EX_FUNC_L3_DELTA_DATA) returned error.");
	    return rc;
	  }
	  rc = FAPI_ATTR_GET(ATTR_PROC_EX_FUNC_L3_LENGTH, &i_target, attrFuncL3RingLength);
	  if (rc)  {
	    FAPI_ERR("FAPI_ATTR_GET(ATTR_PROC_EX_FUNC_L3_LENGTH) returned error.");
	    return rc;
	  }
		//attrFuncL3RingLength = 0xBEBA;
		for (iEntry=0; iEntry<MAX_FUNC_L3_RING_LIST_ENTRIES; iEntry++)  {
			if (attrFuncL3RingList[iEntry]!=0xffff0000)  {
				attrFuncL3RingData[attrFuncL3RingList[iEntry]>>16] = (uint8_t)((attrFuncL3RingList[iEntry]<<24)>>24);
			}
			else
				break;
        }
		FAPI_DBG("Overlay [raw] ring created. ");
		// Get ring name from xip image.
		rcLoc = sbe_xip_find((void*)i_imageIn, FUNC_L3_RING_TOC_NAME, &xipTocItem);
		if (rcLoc)  {
	    FAPI_ERR("sbe_xip_find() failed w/rc=%i", rcLoc);
	    FAPI_ERR("Probable cause:");
	    FAPI_ERR("\tThe keyword (=%s) was not found.", FUNC_L3_RING_TOC_NAME);
	    uint32_t & RC_LOCAL = rcLoc;
	    FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_KEYWORD_NOT_FOUND_ERROR);
	    return rc;
	  }
		xipFuncL3RingVector = xipTocItem.iv_address;
	}
#endif


  /***************************************************************************
   *                          SEARCH LOOP - Begin                            *
   ***************************************************************************/
  do  {

  FAPI_DBG("nextRing (at top)=0x%016llx",(uint64_t)nextRing);
  

  // ==========================================================================
  // Get ring layout from image
  // ==========================================================================
  FAPI_DBG("--> Reading RS4 delta ring info from SBE-XIP Image.");
  rcLoc = get_ring_layout_from_image( i_imageIn,
                                      ddLevel,
                                      sysPhase,
                                      &rs4RingLayout,
                                      &nextRing);
  rcSearch = rcLoc;
  if (rcSearch!=DSLWB_RING_SEARCH_MATCH && 
      rcSearch!=DSLWB_RING_SEARCH_EXHAUST_MATCH && 
      rcSearch!=DSLWB_RING_SEARCH_NO_MATCH)  {
    FAPI_ERR("\tGetting delta ring from image was unsuccessful (rcSearch=%i).",rcSearch);
    FAPI_ERR("\tNo wiggle-flip programs will be stored in .rings section.");
    FAPI_ERR("\tThe following ELF sections have been emptied: .rings, .pibmem0, .ipl_text.");
    uint32_t & RC_LOCAL=rcLoc;
	  FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_RING_RETRIEVAL_ERROR);
    return rc;
  }
  if (rcSearch==DSLWB_RING_SEARCH_MATCH || 
      rcSearch==DSLWB_RING_SEARCH_EXHAUST_MATCH)
    FAPI_DBG("\tRetrieving RS4 delta ring was successful.");

  // Check if we're done at this point.
  //      
  if (rcSearch==DSLWB_RING_SEARCH_NO_MATCH)  {
    FAPI_INF("Wiggle-flip programming done.");
    FAPI_INF("Number of wf programs appended: %i", countWF);
    if (countWF==0)
      FAPI_INF("ZERO WF programs appended to .rings section.");
#ifndef IMGBUILD_PPD_IGNORE_XIPC
		// Do various customizations to image.
		if (!buf1 || !buf2)  {
			FAPI_ERR("The [assumed] pre-allocated ring buffers, buf1/2, do not exist.\n");
      uint32_t & RC_LOCAL = rcTmp;
		  FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_MEMORY_ERROR);
		  return rc;
		}
    sizeImageTmp = sizeImageOutMax;
		FAPI_INF("Calling xip_customize().\n");
		FAPI_EXEC_HWP(rc, p8_xip_customize,	
		                  i_target,
											i_imageOut,   // This is both in and out image for xip_customize.
											NULL,         // No need to pass a separate out image
											sizeImageTmp,
											sysPhase,
											2, // We're only interested in SRAM mode for non-fixed img.
											buf1,
											sizeBuf1,
											buf2,
											sizeBuf2);
		free(buf1);
		free(buf2);
    buf1 = buf2 = NULL;
		if (rc!=FAPI_RC_SUCCESS)  {
    	FAPI_ERR("Xip customization failed.");
			return rc;
		}
    FAPI_INF("Xip customization done.");
#else
    // Initialize .slw section with PORE table.
		sizeImageTmp = sizeImageOutMax;
    rcLoc = initialize_slw_section( i_imageOut,
                                    &sizeImageTmp);
    if (rcLoc)  {
      if (rcLoc==IMGBUILD_ERR_IMAGE_TOO_LARGE)  {
		    uint32_t & DATA_IMG_SIZE_OLD=sizeImageOld;
		    uint32_t & DATA_IMG_SIZE_EST=sizeImageTmp;
			  uint32_t & DATA_IMG_SIZE_MAX=sizeImageOutMax;
		    FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_MAX_IMAGE_SIZE_EXCEEDED);
		  }
			else  {
			  uint32_t & RC_LOCAL=rcLoc;
        FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_APPEND_SLW_SECTION_ERROR);
      }
			return rc;
    }
    FAPI_INF("SLW section allocated for Ramming and Scomming tables.");
#endif

    // Update host_runtime_scom pointer to point to sub_slw_runtime_scom
		rcLoc = update_runtime_scom_pointer( i_imageOut);
		if (rcLoc==IMGBUILD_ERR_KEYWORD_NOT_FOUND)  {
			uint32_t &RC_LOCAL=rcLoc;
			FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_KEYWORD_NOT_FOUND_ERROR);
			return rc;
		}
		// Report final size.
    sbe_xip_image_size( i_imageOut, io_sizeImageOut);
    FAPI_INF("Final SLW image size: %i", *io_sizeImageOut);
    return FAPI_RC_SUCCESS;
  }
  
  deltaRingRS4 = (CompressedScanData*)rs4RingLayout.rs4Delta;
  
  FAPI_DBG("Dumping ring layout:");
  FAPI_DBG("\tentryOffset      = %i",(uint32_t)myRev64(rs4RingLayout.entryOffset));
  FAPI_DBG("\tbackItemPtr     = 0x%016llx",myRev64(rs4RingLayout.backItemPtr));
  FAPI_DBG("\tsizeOfThis      = %i",myRev32(rs4RingLayout.sizeOfThis));
  FAPI_DBG("\tsizeOfMeta      = %i",myRev32(rs4RingLayout.sizeOfMeta));
  FAPI_DBG("\tddLevel         = %i",myRev32(rs4RingLayout.ddLevel));
  FAPI_DBG("\tsysPhase        = %i",rs4RingLayout.sysPhase);
  FAPI_DBG("\toverride        = %i",rs4RingLayout.override);
  FAPI_DBG("\treserved1+2     = %i",rs4RingLayout.reserved1|rs4RingLayout.reserved2);
  FAPI_DBG("\tRS4 magic #     = 0x%08x",myRev32(deltaRingRS4->iv_magic));    
  FAPI_DBG("\tRS4 total size  = %i",myRev32(deltaRingRS4->iv_size));
  FAPI_DBG("\tUnXed data size = %i",myRev32(deltaRingRS4->iv_length));
  FAPI_DBG("\tScan select     = 0x%08x",myRev32(deltaRingRS4->iv_scanSelect));
  FAPI_DBG("\tHeader version  = 0x%02x",deltaRingRS4->iv_headerVersion);
  FAPI_DBG("\tFlush optimize  = 0x%02x (reverse of override)",deltaRingRS4->iv_flushOptimization);
  FAPI_DBG("\tRing ID         = 0x%02x",deltaRingRS4->iv_ringId);
  FAPI_DBG("\tChiplet ID      = 0x%02x",deltaRingRS4->iv_chipletId);
  FAPI_DBG("Dumping meta data:");
  FAPI_DBG("\tsizeOfData = %i",myRev32(rs4RingLayout.sizeOfMeta));
  FAPI_DBG("\tMeta data  = ");
  for (i=0; i<myRev32(rs4RingLayout.sizeOfMeta); i++)  { // String may not be null terminated.
    FAPI_DBG("%c",rs4RingLayout.metaData[i]);
  }


  // ==========================================================================
  // Decompress RS4 delta state.
  // ==========================================================================
  FAPI_DBG("--> Decompressing RS4 delta ring.");
  rcLoc = _rs4_decompress((uint8_t*)buf2,
                          sizeBuf2,
													&ringBitLen,
                          deltaRingRS4);
  if (rcLoc)  {
    FAPI_ERR("\t_rs4_decompress() failed: rc=%i",rcLoc);
    if (buf2)  free(buf2);
		uint32_t & RC_LOCAL=rcLoc;
    FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_RS4_DECOMPRESSION_ERROR);
    return rc;
  }
  FAPI_DBG("\tDecompression successful.\n");
  

#ifndef IMGBUILD_PPD_IGNORE_XIPC
  // ==========================================================================
  // CUSTOMIZE item:    Overlay ex_func_l3_ring.
	// Retrieval method:  Attribute.
	// Note: Check if ex_func_l3_ring's vector address matches current backPtr.
	//       If so, perform OR operation with new attribute data for this ring.
	// Assumptions:
	// - Base ring only.
	// - Correct DD level rings only.
  // ==========================================================================
	uint8_t   byteExisting=0, byteOverlay=0, bGoodByte=1;
	uint32_t  iByte, sizeRingInBytes;
  FAPI_DBG("--> (2) Check if we should modify the ex_func_l3_ring with attribute data.");
	if (!bAsyncSafeMode)  {
    FAPI_DBG("--> (2) Yes, we should modify the ex_func_l3_ring with attribute data.");
		// Find ring match by comparing backItemPtr and ring lengths. Note that
		//   we can't use fwdPtr for finding a match since we don't know which DD 
		//   level ring it ended up pointing at.
		if (xipFuncL3RingVector==myRev64(rs4RingLayout.backItemPtr) &&
				attrFuncL3RingLength==myRev32(deltaRingRS4->iv_length))  {
			// Perform OR between the existing ring and attribute ring.
			sizeRingInBytes = (attrFuncL3RingLength-1)/8 + 1;
			bGoodByte = 1;
////			FAPI_DBG("Byte[  # ]: ER  OR  FR ");
			FAPI_DBG("Byte[  # ]: ER  OR =ER? ");
			FAPI_DBG("-----------------------");
			for (iByte=0; (iByte<sizeRingInBytes && bGoodByte); iByte++)  {
////				FAPI_DBG("Byte[%4i]: %02x ",
////								iByte,
////									*((uint8_t*)buf2+iByte));
				if (*(attrFuncL3RingData+iByte))  {
					// Check there are 0-bits in the existing byte where there are
					//   1-bits in the overlay byte.
					byteExisting = *((uint8_t*)buf2+iByte);
					byteOverlay  = *(&attrFuncL3RingData[0]+iByte);
					if (byteExisting!=(byteExisting & ~byteOverlay))  {
						FAPI_ERR("Byte[%4i]: %02x  %02x  %02x <-violation",iByte,byteExisting,byteOverlay,byteExisting&~byteOverlay);
						bGoodByte = 0;
						break;
					}
					else  {
						FAPI_DBG("Byte[%4i]: %02x  %02x  %02x ",iByte,byteExisting,byteOverlay,byteExisting&~byteOverlay);
					}
					// Only update existing ring when there's content in overlay data.
////					FAPI_DBG("Byte[%4i]: %02x  %02x  %02x ",
////										iByte,
////										*((uint8_t*)buf2+iByte),
////										*(&attrFuncL3RingData[0]+iByte),
////										*((uint8_t*)buf2+iByte) | *(&attrFuncL3RingData[0]+iByte));
					*((uint8_t*)buf2+iByte) = byteExisting | byteOverlay;
////					FAPI_DBG("Byte[%4i]:         %02x ",
////										iByte,
////										*((uint8_t*)buf2+iByte));
				}
////				FAPI_DBG("Byte[%4i]:         %02x ",
////									iByte,
////									*((uint8_t*)buf2+iByte));
			}
			FAPI_DBG("-----------------------");
			if (!bGoodByte)  {
 			  FAPI_ERR("The existing ex_l3_func_ring has 1-bits in overlay locations. ");
 			  if (buf2)  free(buf2);
				uint32_t & DATA_FAIL_BYTE_NO = iByte;
				uint8_t & DATA_EXISTING_RING_BYTE = byteExisting;
				uint8_t & DATA_OVERLAY_RING_BYTE = byteOverlay; 
 			  FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_L3_FUNC_OVERLAY_ERROR);
 			  return rc;
			}
		}
	}
#endif


  // ==========================================================================
  // Create Wiggle-Flip Programs (but first resolve max rotate status.)
  // ==========================================================================
  FAPI_DBG("--> Creating Wiggle-Flip Program.");
  rcLoc = sbe_xip_get_scalar( (void*)i_imageIn, SCAN_MAX_ROTATE_38XXX_NAME, &scanMaxRotate);
  if (rcLoc)  {
    FAPI_INF("WARNING: sbe_xip_get_scalar() failed...but we might wing it.");
    if (rcLoc==SBE_XIP_ITEM_NOT_FOUND)  {
      FAPI_INF("Probable cause:");
      FAPI_INF("\tThe key word in SCAN_MAX_ROTATE_38XXX_NAME does not exist the TOC.");
      scanMaxRotate = SCAN_ROTATE_DEFAULT;
		  FAPI_INF("\tscanMaxRotate set to 0x%llx", scanMaxRotate);
			FAPI_INF("Continuing...");
	  }
		else  {
			FAPI_ERR("ERROR: Nope, couldn't wing it.");
      if (buf2)  free(buf2);
		  uint32_t & RC_LOCAL=rcLoc;
		  FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_UNKNOWN_XIP_ERROR);
		  return rc;
		}
	}
	if (scanMaxRotate<0x20 || scanMaxRotate>SCAN_MAX_ROTATE)  {
	  FAPI_INF("WARNING: Value of key word SCAN_MAX_ROTATE_38XXX_NAME=0x%llx is not permitted.\n",scanMaxRotate);
    scanMaxRotate = SCAN_ROTATE_DEFAULT;
		FAPI_INF("\tscanMaxRotate set to 0x%llx\n", scanMaxRotate);
		FAPI_INF("Continuing...\n");
	}

  // Support for enforcing delay after WF scan write scoms.
  uint64_t waitsScanDelay=10;
  rcLoc = sbe_xip_get_scalar( (void*)i_imageIn, "waits_delay_for_scan", &waitsScanDelay);
  if (rcLoc)  {
		FAPI_ERR("Error obtaining waits_delay_for_scan keyword.\n");
    if (buf2)  free(buf2);
	  uint32_t & RC_LOCAL=rcLoc;
	  FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_UNKNOWN_XIP_ERROR);
	  return rc;
  }

	wfInline = (uint32_t*)buf1;
	wfInlineLenInWords = sizeBuf1/4;
  rcLoc = create_wiggle_flip_prg( (uint32_t*)buf2, 
                                  ringBitLen,
                                  myRev32(deltaRingRS4->iv_scanSelect),
                                  (uint32_t)deltaRingRS4->iv_chipletId,
                                  &wfInline,
                                  &wfInlineLenInWords,
                                  deltaRingRS4->iv_flushOptimization,
																	(uint32_t)scanMaxRotate,
                                  (uint32_t)waitsScanDelay);
	if (rcLoc)  {
    FAPI_ERR("create_wiggle_flip_prg() failed w/rcLoc=%i",rcLoc);
    //if (deltaRingDxed)  free(deltaRingDxed);
    if (buf1)  free(buf1);
    if (buf2)  free(buf2);
		uint32_t & RC_LOCAL=rcLoc;
    FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_WF_CREATION_ERROR);
    return rc;
  }
  FAPI_DBG("\tWiggle-flip programming successful.");
  

  // ==========================================================================
  // Append Wiggle-Flip programs to .rings section.
  // ==========================================================================
  FAPI_DBG("--> Appending wiggle-flip and layout header to .rings section.");
  sizeImageTmp = sizeImageOutMax;
	rcLoc = write_wiggle_flip_to_image( i_imageOut,
                                      &sizeImageTmp,
                                      &rs4RingLayout,
                                      wfInline,
                                      wfInlineLenInWords);
  if (rcLoc)  {
    FAPI_ERR("write_wiggle_flip_to_image() failed w/rcLoc=%i",rcLoc);
    //if (deltaRingDxed)  free(deltaRingDxed);
    if (buf1)  free(buf1);
    if (buf2)  free(buf2);
    if (rcLoc==IMGBUILD_ERR_IMAGE_TOO_LARGE)  {
		  uint32_t & DATA_IMG_SIZE_OLD=sizeImageOld;
		  uint32_t & DATA_IMG_SIZE_EST=sizeImageTmp;
			uint32_t & DATA_IMG_SIZE_MAX=sizeImageOutMax;
		  FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_MAX_IMAGE_SIZE_EXCEEDED);
		}
		else  {
		  uint32_t & RC_LOCAL=rcLoc;
		  FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_IMAGE_UPDATE_ERROR);
		}
    return rc;
  }
  FAPI_DBG("\tUpdating image w/wiggle-flip program + header was successful.");
  
  // Update some variables for debugging and error reporting.
  sizeImageOld = sizeImageTmp;
  countWF++;

  // ==========================================================================
  // Are we done?
  // ==========================================================================
  if (rcSearch==DSLWB_RING_SEARCH_EXHAUST_MATCH)  {
    FAPI_INF("Wiggle-flip programming done.");
    FAPI_INF("Number of wf programs appended: %i", countWF);
    if (countWF==0)
      FAPI_INF("ZERO WF programs appended to .rings section.");
#ifndef IMGBUILD_PPD_IGNORE_XIPC
		// Do various customizations to image.
		if (!buf1 || !buf2)  {
			FAPI_ERR("The [assumed] pre-allocated ring buffers, buf1/2, do not exist.\n");
      uint32_t & RC_LOCAL = rcTmp;
		  FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_MEMORY_ERROR);
		  return rc;
		}
    sizeImageTmp = sizeImageOutMax;
		FAPI_INF("Calling xip_customize().\n");
		FAPI_EXEC_HWP(rc, p8_xip_customize,	
		                  i_target,
											i_imageOut,   // This is both in and out image for xip_customize.
											NULL,         // No need to pass a separate out image
											sizeImageTmp,
											sysPhase,
											2, // We're only interested in SRAM mode for non-fixed img.
											buf1,
											sizeBuf1,
											buf2,
											sizeBuf2);
		free(buf1);
		free(buf2);
    buf1 = buf2 = NULL;
		if (rc!=FAPI_RC_SUCCESS)  {
    	FAPI_ERR("Xip customization failed.");
			return rc;
		}
    FAPI_INF("Xip customization done.");
#else
		// Initialize .slw section with PORE table.
    sizeImageTmp = sizeImageOutMax;
		rcLoc = initialize_slw_section( i_imageOut,
                                    &sizeImageTmp);
    if (rcLoc)  {
      if (rcLoc==IMGBUILD_ERR_IMAGE_TOO_LARGE)  {
		    uint32_t & DATA_IMG_SIZE_OLD=sizeImageOld;
		    uint32_t & DATA_IMG_SIZE_EST=sizeImageTmp;
			  uint32_t & DATA_IMG_SIZE_MAX=sizeImageOutMax;
		    FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_MAX_IMAGE_SIZE_EXCEEDED);
		  }
			else  {
        uint32_t & RC_LOCAL=rcLoc;
			  FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_APPEND_SLW_SECTION_ERROR);
      }
			return rc;
    }
    FAPI_INF("SLW section initialized for Ramming and Scomming tables.");
#endif
    
		// Update host_runtime_scom pointer to point to sub_slw_runtime_scom
		rcLoc = update_runtime_scom_pointer(i_imageOut);
		if (rcLoc==IMGBUILD_ERR_KEYWORD_NOT_FOUND)  {
			uint32_t &RC_LOCAL=rcLoc;
			FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_KEYWORD_NOT_FOUND_ERROR);
			return rc;
		}
		
		// Report final size.
		sbe_xip_image_size( i_imageOut, io_sizeImageOut);
    FAPI_INF("Final SLW image size: %i", *io_sizeImageOut);
    return FAPI_RC_SUCCESS;
  }

  FAPI_DBG("nextRing (at bottom)=0x%016llx",(uint64_t)nextRing);
    
  }   while (nextRing!=NULL);
  /***************************************************************************
   *                            SEARCH LOOP - End                              *
   ***************************************************************************/

  FAPI_ERR("Shouldn't be in this code section. Check code.");
  rcLoc = IMGBUILD_ERR_CHECK_CODE;
  uint32_t & RC_LOCAL=rcLoc;
  FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_UNKNOWN_ERROR);
  return rc;

}

} // End of extern C
