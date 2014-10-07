/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_slw_build/p8_slw_build_fixed.C $ */
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
// $Id: p8_slw_build_fixed.C,v 1.23 2014/09/11 22:47:00 cmolsen Exp $
/*------------------------------------------------------------------------------*/
/* *! TITLE : p8_slw_build_fixed                                                      */
/* *! DESCRIPTION : Extracts and decompresses delta ring states from EPROM      */
//                  image. Utilizes the linked list approach (LLA) to extract
//                  and position wiggle-flip programs in .rings according to 
//                  back pointer, DD level, phase and override settings. 
/* *! OWNER NAME : Michael Olsen                  cmolsen@us.ibm.com            */
//
/* *! EXTENDED DESCRIPTION :                                                    */
//
/* *! USAGE : 
              To build (for Hostboot) -
              buildfapiprcd   -C "p8_image_help.C,p8_image_help_base.C,p8_scan_compression.C"   -c "sbe_xip_image.c,pore_inline_assembler.c"   -e "../../xml/error_info/p8_slw_build_errors.xml,../../xml/error_info/proc_sbe_decompress_scan_halt_codes.xml"   p8_slw_build_fixed.C
              To build (for command-line) -
              buildfapiprcd   -C "p8_image_help.C,p8_image_help_base.C,p8_scan_compression.C"   -c "sbe_xip_image.c,pore_inline_assembler.c"   -e "../../xml/error_info/p8_slw_build_errors.xml,../../xml/error_info/proc_sbe_decompress_scan_halt_codes.xml"   -u "SLW_COMMAND_LINE"   p8_slw_build_fixed.C
              To add polling protocol to wf programs:
                -u "IMGBUILD_PPD_WF_POLLING_PROT"
              To NOT run xip_customize:
                -u "IMGBUILD_PPD_IGNORE_XIPC"                                   */
//
/* *! ASSUMPTIONS :                                                             */
//
/* *! COMMENTS :                                                                */
//
/*------------------------------------------------------------------------------*/

#include <p8_pore_api_custom.h>
#include <p8_slw_build.H>
#include <p8_xip_customize.H>
#include <p8_delta_scan_rw.h>
#include <p8_pore_table_gen_api.H>

extern "C"  {

using namespace fapi;

//  Parameter list:
//  fapi::Target &i_target:   Hardware target
//  void      *i_imageIn:     Pointer to memory mapped input Reference PNOR image
//  void      *i_imageOut:    Pointer to where to put SLW mainstore image
//  uint32_t  &io_sizeImageOut: In: Max size of outp img. Out: Final size of outp img.
//                            On input, this MUST be equal to FIXED_SLW_IMAGE_SIZE for
//                            i_modeBuild={0,1}.
//  uint8_t   i_modeBuild:    0: HB/IPL mode, 1: PHYP/Rebuild mode, 2: SRAM mode.
//  void      *i_buf1:        Temp buffer 1 for dexed RS4 ring. (Caller allocs/frees.)
//  uint32_t  i_sizeBuf1:     Size of buf1.
//                            This MUST be equal to FIXED_RING_BUF_SIZE.
//  void      *i_buf2:        Temp buffer 2 for WF ring. (Caller allocs/frees.)
//  uint32_t  i_sizeBuf22     Size of buf2.
//                            This MUST be equal to FIXED_RING_BUF_SIZE.
//
ReturnCode p8_slw_build_fixed( const fapi::Target &i_target,
                         void               *i_imageIn,
                         void               *i_imageOut,
												 uint32_t           &io_sizeImageOut,
                         const uint8_t      i_modeBuild, 
												 void               *i_buf1,
												 const uint32_t     i_sizeBuf1,
												 void               *i_buf2,
												 const uint32_t     i_sizeBuf2 )
{
  ReturnCode rc;
  uint8_t   l_uint8=0;
	uint8_t   bSearchDone=0;
  uint32_t  ddLevel=0;
  uint8_t   sysPhase=1; // SLW image build phase.
  uint32_t  rcLoc=0, rcSearch=0, i, countWF=0;
  uint32_t  sizeImage=0, sizeImageIn=0, sizeImageOutMax, sizeImageTmp;
  CompressedScanData *deltaRingRS4=NULL;
  DeltaRingLayout rs4RingLayout;
  void *nextRing=NULL;
  uint32_t  ringBitLen=0;
  uint32_t  *wfInline=NULL;
  uint32_t  wfInlineLenInWords;
	uint64_t  scanMaxRotate=SCAN_ROTATE_DEFAULT;
  uint32_t  dataTmp1, dataTmp2, dataTmp3;
  uint64_t  ptrTmp1, ptrTmp2;
  uint32_t  bufLC;
  uint8_t   ffdc_temp;
 	// Sanity checks on buffers and image.
  // - validate image.
	// - do pre-allocated buffers exist?
	// - are pre-allocated buffers the correct size?
  // - is supplied output image size the correct size?
	// - is input image smaller than the output image size?
	// - is modeBuild valid?
	//
  sbe_xip_image_size((void*)i_imageIn, &sizeImageIn);
  rcLoc = sbe_xip_validate((void*)i_imageIn, sizeImageIn);
  if (rcLoc)  {
    FAPI_ERR("xip_validate() failed w/rcLoc=%i",rcLoc);
    uint32_t & RC_LOCAL = rcLoc;
    FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_INTERNAL_IMAGE_ERR);
    return rc;
  }
	if (i_imageOut==i_imageIn)  {
		FAPI_ERR("The images, imageIn and imageOut, point to the same buffer space.");
    ptrTmp1 = (uint64_t)i_imageIn;
    ptrTmp2 = (uint64_t)i_imageOut;
    uint64_t & DATA_BUF1_PTR = ptrTmp1;
    uint64_t & DATA_BUF2_PTR = ptrTmp2;
	  FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_IMG_PTR_ERROR);
	  return rc;
	}
  sizeImageOutMax = io_sizeImageOut; // This should be 1MB for mode 0 and 1.
  FAPI_DBG("Mode build = %i\n",i_modeBuild);
	if ((i_modeBuild==P8_SLW_MODEBUILD_IPL || 
       i_modeBuild==P8_SLW_MODEBUILD_REBUILD) && 
       sizeImageOutMax!=FIXED_SLW_IMAGE_SIZE)  {
    FAPI_ERR("Supplied output image size differs from agreed upon fixed SLW image size.");
    FAPI_ERR("Supplied output image size: %i",sizeImageOutMax);
    FAPI_ERR("Agreed upon fixed SLW image size: %i",FIXED_SLW_IMAGE_SIZE);
    dataTmp1 = FIXED_SLW_IMAGE_SIZE;
    uint32_t & DATA_IMG_SIZE_MAX = sizeImageOutMax;
		uint32_t & DATA_IMG_SIZE_FIXED = dataTmp1;
    FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_IMAGE_SIZE_NOT_FIXED);
    return rc;
  }
  if ((i_modeBuild==P8_SLW_MODEBUILD_IPL || 
       i_modeBuild==P8_SLW_MODEBUILD_REBUILD) && 
       sizeImageIn>sizeImageOutMax)  {
    FAPI_ERR("Input image size exceeds fixed output image size.");
    FAPI_ERR("Size of supplied input image: %i",sizeImageIn);
    FAPI_ERR("Supplied output image size: %i",sizeImageOutMax);
    uint32_t & DATA_IMG_SIZE_INP = sizeImageIn;
		uint32_t & DATA_IMG_SIZE_MAX = sizeImageOutMax;
		FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_INPUT_IMAGE_SIZE_MESS);
    return rc;
  }
	if (!i_buf1 || !i_buf2)  {
		FAPI_ERR("The [assumed] pre-allocated ring buffers, i_buf1/2, do not exist.");
    ptrTmp1 = (uint64_t)i_buf1;
    ptrTmp2 = (uint64_t)i_buf2;
    uint64_t & DATA_BUF1_PTR = ptrTmp1;
    uint64_t & DATA_BUF2_PTR = ptrTmp2;
	  FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_BUF_PTR_ERROR);
	  return rc;
	}
	if (i_buf1==i_buf2)  {
		FAPI_ERR("The buffers, buf1 and buf2, point to the same buffer space.");
    ptrTmp1 = (uint64_t)i_buf1;
    ptrTmp2 = (uint64_t)i_buf2;
    uint64_t & DATA_BUF1_PTR = ptrTmp1;
    uint64_t & DATA_BUF2_PTR = ptrTmp2;
	  FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_BUF_PTR_ERROR);
	  return rc;
	}
	if (i_sizeBuf1!=FIXED_RING_BUF_SIZE || i_sizeBuf2!=FIXED_RING_BUF_SIZE)  {
    FAPI_ERR("Supplied ring buffer size(s) differs from agreed upon fixed size.");
    FAPI_ERR("Supplied ring buf1 size: %i",i_sizeBuf1);
    FAPI_ERR("Supplied ring buf2 size: %i",i_sizeBuf2);
    FAPI_ERR("Agreed upon fixed ring buf size: %i",FIXED_RING_BUF_SIZE);
    dataTmp1 = i_sizeBuf1;
    dataTmp2 = i_sizeBuf2;
    dataTmp3 = FIXED_RING_BUF_SIZE;
    uint32_t & DATA_BUF1_SIZE = dataTmp1;
    uint32_t & DATA_BUF2_SIZE = dataTmp2;
		uint32_t & DATA_BUF_SIZE_FIXED = dataTmp3;
    FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_BUF_SIZE_NOT_FIXED);
    return rc;
	}
  if (i_modeBuild>P8_SLW_MODEBUILD_MAX_VALUE)  {
    FAPI_ERR("modeBuild=%i invalid. Valid range is [0;%i].",
      i_modeBuild,P8_SLW_MODEBUILD_MAX_VALUE);
    ffdc_temp = i_modeBuild;
    uint8_t & MODE_BUILD=ffdc_temp;
		FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_BAD_CODE_OR_PARM);
    return rc;
  }
  FAPI_DBG("Reference/input image size: %i",sizeImageIn);
  

  // ==========================================================================
  // Check and copy image to mainstore and clean it up.
  // ==========================================================================
  // ToDo:
  // - Eventually, automate emptying sections in proper order (last section goes first).
  // - For 5/15, assume following order of removal: rings, pibmem0, and halt.
  //
  // First, copy input image to supplied mainstore location.
  //
  memcpy( i_imageOut, i_imageIn, sizeImageIn);
  sbe_xip_image_size(i_imageOut, &sizeImage);
  rcLoc = sbe_xip_validate(i_imageOut, sizeImage);
  if (rcLoc)  {
    FAPI_ERR("xip_validate() failed w/rcLoc=%i",rcLoc);
		uint32_t & RC_LOCAL=rcLoc;
    FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_MS_INTERNAL_IMAGE_ERR);
    return rc;
  }
  if (sizeImage!=sizeImageIn)  {
    FAPI_ERR("Size obtained from copied image's header (=%i) differs from input image's size (=%i).",
      sizeImage,sizeImageIn);
    uint32_t & DATA_IMG_SIZE = sizeImage;
    uint32_t & DATA_IMG_SIZE_INP = sizeImageIn;
    FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_MS_IMAGE_SIZE_MISMATCH);
    return rc;
  }

  // Second, delete .dcrings, .rings and .pibmem0 sections (but keep .halt)
  //
  rcLoc = sbe_xip_delete_section( i_imageOut, SBE_XIP_SECTION_DCRINGS);
  if (rcLoc)  {
    FAPI_ERR("xip_delete_section(.dcrings) failed w/rcLoc=%i",rcLoc);
    ffdc_temp=(uint8_t)SBE_XIP_SECTION_DCRINGS;
    uint8_t & SBE_XIP_SECTION=ffdc_temp;
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
  FAPI_DBG("Image size (after .dcrings delete): %i",sizeImage);

  rcLoc = sbe_xip_delete_section( i_imageOut, SBE_XIP_SECTION_RINGS);
  if (rcLoc)  {
    FAPI_ERR("xip_delete_section(.rings) failed w/rcLoc=%i",rcLoc);
    ffdc_temp=(uint8_t)SBE_XIP_SECTION_RINGS;
    uint8_t & SBE_XIP_SECTION=ffdc_temp;
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
    ffdc_temp=(uint8_t)SBE_XIP_SECTION_PIBMEM0;
    uint8_t & SBE_XIP_SECTION=ffdc_temp;
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
	uint8_t    attrSleepEnable=1, bSleepEnable;
	uint32_t   attrFuncL3RingList[MAX_FUNC_L3_RING_LIST_ENTRIES]={0};
	uint8_t    attrFuncL3RingData[MAX_FUNC_L3_RING_SIZE]={0};
	uint32_t   attrFaryL2RingList[MAX_FARY_L2_RING_LIST_ENTRIES]={0};
	uint8_t    attrFaryL2RingData[MAX_FARY_L2_RING_SIZE]={0};
	uint32_t   attrFuncL3RingLength=0;
        uint32_t   attrFaryL2RingLength=0;
	SbeXipItem xipTocItem;
	uint64_t   xipFuncL3RingVector=0;
	uint64_t   xipFaryL2RingVector=0;
	uint32_t   iEntry;

	// Safe mode status.
	//
  rc = FAPI_ATTR_GET(ATTR_PROC_FABRIC_ASYNC_SAFE_MODE, NULL, attrAsyncSafeMode);
  if (rc)  {
    FAPI_ERR("FAPI_ATTR_GET(ATTR_PROC_FABRIC_ASYNC_SAFE_MODE) returned error.");
    return rc;
  }
	bAsyncSafeMode = attrAsyncSafeMode;
	
	// Obtain ex_func_l3_ring overlay data and length from attributes.
	// Obtain ring name and ring's vector location from image.
	//
	if (!bAsyncSafeMode)  {
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
				attrFuncL3RingData[attrFuncL3RingList[iEntry]>>16] =
 																		(uint8_t)((attrFuncL3RingList[iEntry]<<24)>>24);
			}
			else
				break;
		}
		FAPI_DBG("Overlay [raw] ring created for func L3.");
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

	// sleep enable/disable
    rc = FAPI_ATTR_GET(ATTR_PM_SLEEP_ENABLE, NULL, attrSleepEnable);
    FAPI_DBG("--> attrSleepEnable = 0x%x ", attrSleepEnable);
    if (rc)  {
      FAPI_ERR("FAPI_ATTR_GET(ATTR_PROC_SLEEP_ENABLE) returned error.");
      return rc;
    }
	bSleepEnable = attrSleepEnable;
    FAPI_DBG("--> bSleepEnable = 0x%x ",bSleepEnable);
	// Obtain ring name and ring's vector location from image.
    if (bSleepEnable) {
        uint8_t chipType;
      rc = FAPI_ATTR_GET_PRIVILEGED(ATTR_NAME, &i_target, chipType);
      if (rc)  {
        FAPI_ERR("FAPI_ATTR_GET_PRIVILEGED() failed w/rc=%i and  chipType=0x%02x",(uint32_t)rc,chipType);
        return rc;
      }
      // configure overlay ring/ring length based on CT/EC
      if ((chipType == fapi::ENUM_ATTR_NAME_MURANO) && (ddLevel < 0x20))
      {
        attrFaryL2RingList[0] = 0x1E2100C0;
        attrFaryL2RingList[1] = 0xFFFF0000;
        attrFaryL2RingLength = 82649;
      }
      else if ((chipType == fapi::ENUM_ATTR_NAME_MURANO) && (ddLevel >= 0x20))
      {
        attrFaryL2RingList[0] = 0x1DC4000C;
        attrFaryL2RingList[1] = 0xFFFF0000;
        attrFaryL2RingLength = 83294;
      }
      else if ((chipType == fapi::ENUM_ATTR_NAME_VENICE) && (ddLevel < 0x20))
      {
        attrFaryL2RingList[0] = 0x1DA600C0;
        attrFaryL2RingList[1] = 0xFFFF0000;
        attrFaryL2RingLength = 83050;
      }
      else if (((chipType == fapi::ENUM_ATTR_NAME_VENICE) && (ddLevel >= 0x20)) ||
               (chipType == fapi::ENUM_ATTR_NAME_NAPLES))
      {
        attrFaryL2RingList[0] = 0x1DC50003;
        attrFaryL2RingList[1] = 0xFFFF0000;
        attrFaryL2RingLength = 83304;
      }
      else
      {
        FAPI_ERR("Unsupported CT/EC combination in sleep processing code!");
        const uint8_t CT = chipType;
        const uint8_t EC = ddLevel;
        FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_SLEEP_PROCESSING_ERROR);
        return rc;
      }

      for (iEntry=0; iEntry<MAX_FARY_L2_RING_LIST_ENTRIES; iEntry++)  {
        if (attrFaryL2RingList[iEntry]!=0xffff0000)  {
          attrFaryL2RingData[attrFaryL2RingList[iEntry]>>16] = (uint8_t)((attrFaryL2RingList[iEntry]<<24)>>24);
        }
        else
          break;
      }
      FAPI_DBG("Overlay [raw] ring created for func L3 ring.");

      // Get ring name from xip image.
      rcLoc = sbe_xip_find((void*)i_imageIn, FARY_L2_RING_TOC_NAME, &xipTocItem);
      if (rcLoc)  {
        FAPI_ERR("sbe_xip_find() failed w/rc=%i", rcLoc);
        FAPI_ERR("Probable cause:");
        FAPI_ERR("\tThe keyword (=%s) was not found.", FARY_L2_RING_TOC_NAME);
        uint32_t & RC_LOCAL = rcLoc;
        FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_KEYWORD_NOT_FOUND_ERROR);
        return rc;
      }
      xipFaryL2RingVector = xipTocItem.iv_address;
    }
#endif


  /***************************************************************************
   *                            SEARCH LOOP - Begin                            *
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

  //
	// Check if we're done at this point, and save status in bSearchDone.
  //      
  if (rcSearch==DSLWB_RING_SEARCH_NO_MATCH)  {

		bSearchDone = 1;

	}
	else  {  // More rings to search...
  
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
	  rcLoc = _rs4_decompress((uint8_t*)i_buf2,
	                          i_sizeBuf2,
														&ringBitLen,
	                          deltaRingRS4);
	  if (rcLoc)  {
	    FAPI_ERR("\t_rs4_decompress() failed: rc=%i",rcLoc);
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
  	FAPI_DBG("--> Check if we should modify the ex_func_l3_ring with attribute data.");
		if (!bAsyncSafeMode)  {
			// Find ring match by comparing backItemPtr and ring lengths. Note that
			//   we can't use fwdPtr for finding a match since we don't know which DD 
			//   level ring it ended up pointing at.
			if (xipFuncL3RingVector==myRev64(rs4RingLayout.backItemPtr) &&
					attrFuncL3RingLength==myRev32(deltaRingRS4->iv_length))  {
				// Perform OR between the existing ring and attribute ring.
				sizeRingInBytes = (attrFuncL3RingLength-1)/8 + 1;
				bGoodByte = 1;
				FAPI_DBG("Byte[  # ]: ER  OR =ER? ");
				FAPI_DBG("-----------------------");
				for (iByte=0; (iByte<sizeRingInBytes && bGoodByte); iByte++)  {
					if (*(attrFuncL3RingData+iByte))  {
						// Check there are 0-bits in the existing byte where there are
						//   1-bits in the overlay byte.
						byteExisting = *((uint8_t*)i_buf2+iByte);
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
						*((uint8_t*)i_buf2+iByte) = byteExisting | byteOverlay;
					}
				}
				FAPI_DBG("-----------------------");
				if (!bGoodByte)  {
 				  FAPI_ERR("The existing ex_l3_func_ring has 1-bits in overlay locations. ");
					uint32_t & DATA_FAIL_BYTE_NO = iByte;
					uint8_t & DATA_EXISTING_RING_BYTE = byteExisting;
					uint8_t & DATA_OVERLAY_RING_BYTE = byteOverlay; 
 				  FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_L3_FUNC_OVERLAY_ERROR);
 				  return rc;
				}
			}
		}
#endif


#ifndef IMGBUILD_PPD_IGNORE_XIPC
  // ==========================================================================
  // CUSTOMIZE item:    Overlay ex_fary_l2_ring
  // Note: Check if ex_fary_l2_ring's vector address matches current backPtr.
  //       If so, perform OR operation with new attribute data for this ring.
  // Assumptions:
  // - Base ring only.
  // - Correct DD level rings only.
  // ==========================================================================
  byteExisting=0, byteOverlay=0, bGoodByte=1;
  if (bSleepEnable) {
	// Find ring match by comparing backItemPtr and ring lengths. Note that
	//   we can't use fwdPtr for finding a match since we don't know which DD 
	//   level ring it ended up pointing at.
	if (xipFaryL2RingVector==myRev64(rs4RingLayout.backItemPtr) &&
		attrFaryL2RingLength==myRev32(deltaRingRS4->iv_length))  {
      // Perform OR between the existing ring and attribute ring.
      sizeRingInBytes = (attrFaryL2RingLength-1)/8 + 1;
      bGoodByte = 1;
      FAPI_DBG("Byte[  # ]: ER  OR =ER? ");
      FAPI_DBG("-----------------------");
      for (iByte=0; (iByte<sizeRingInBytes && bGoodByte); iByte++)  {
        if (*(attrFaryL2RingData+iByte))  {
          // Check there are 0-bits in the existing byte where there are
          //   1-bits in the overlay byte.
          byteExisting = *((uint8_t*)i_buf2+iByte);
          byteOverlay  = *(&attrFaryL2RingData[0]+iByte);
          if (byteExisting!=(byteExisting & ~byteOverlay))  {
          	FAPI_ERR("Byte[%4i]: %02x  %02x  %02x <-violation",iByte,byteExisting,byteOverlay,byteExisting&~byteOverlay);
          	bGoodByte = 0;
          	break;
          }
          else  {
          	FAPI_DBG("Byte[%4i]: %02x  %02x  %02x ",iByte,byteExisting,byteOverlay,byteExisting&~byteOverlay);
          }
          // Only update existing ring when there's content in overlay data.
          *((uint8_t*)i_buf2+iByte) = byteExisting | byteOverlay;
        }
      }
      FAPI_DBG("-----------------------");
      if (!bGoodByte)  {
        FAPI_ERR("The existing ex_l2_fary_ring has 1-bits in overlay locations. ");
      	uint32_t & DATA_FAIL_BYTE_NO = iByte;
      	uint8_t & DATA_EXISTING_RING_BYTE = byteExisting;
      	uint8_t & DATA_OVERLAY_RING_BYTE = byteOverlay; 
        FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_L2_FARY_OVERLAY_ERROR);
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
		  uint32_t & RC_LOCAL=rcLoc;
		  FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_UNKNOWN_XIP_ERROR);
		  return rc;
	  }
	
		wfInline = (uint32_t*)i_buf1;
		wfInlineLenInWords = i_sizeBuf1/4;
                //WSZ query ec feature for poolling protocol for Murano/Venice >=20, Naples >=10
                uint8_t usePollingProt = 0x00; //true 0x01 false 0x00
                rc = FAPI_ATTR_GET(ATTR_CHIP_EC_FEATURE_USE_POLLING_PROT, &i_target,usePollingProt);
                if (rc) {
                        FAPI_ERR("p8_slw_build: fapiGetAttribute error (ATTR_CHIP_EC_FEATURE_USE_POLLING_PROT)");
                        return rc;
                }
                FAPI_DBG("p8_slw_build_fixed use PollingProt = 0x%02X (true=0x01, false=0x00)", usePollingProt);

	  rcLoc = create_wiggle_flip_prg( (uint32_t*)i_buf2,  // Input buffer, buf2
	                                  ringBitLen,
	                                  myRev32(deltaRingRS4->iv_scanSelect),
	                                  (uint32_t)deltaRingRS4->iv_chipletId,
	                                  &wfInline,          // Output buffer, buf1
	                                  &wfInlineLenInWords,
                                          deltaRingRS4->iv_flushOptimization,
                                          (uint32_t)scanMaxRotate,
	                                  (uint32_t)waitsScanDelay,
                                          usePollingProt);
	  if (rcLoc)  {
	    FAPI_ERR("create_wiggle_flip_prg() failed w/rcLoc=%i",rcLoc);
			uint32_t & RC_LOCAL=rcLoc;
	    FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_WF_CREATION_ERROR);
	    return rc;
	  }
	  FAPI_DBG("\tWiggle-flip programming successful.");
	  
	
	  // ==========================================================================
	  // Append Wiggle-Flip programs to .rings section. (But 1st put ring block together.)
	  // ==========================================================================
	  FAPI_DBG("--> Building WF ring header.");
    //
    // Populate ring header and put ring header and Wf ring into 
    // proper spots in pre-allocated bufWfRingBlock buffer (HB buf1).
    //
    DeltaRingLayout *bufWfRingBlock;
    uint64_t entryOffsetWfRingBlock;
    uint32_t sizeWfRingBlock, sizeWfRingBlockMax;

    bufWfRingBlock = (DeltaRingLayout*)i_buf2;  // Previously contained delta ring state.
    sizeWfRingBlockMax = i_sizeBuf2;

    entryOffsetWfRingBlock      = calc_ring_layout_entry_offset( 
                                                    1, 
                                                    myRev32(rs4RingLayout.sizeOfMeta) );
    bufWfRingBlock->entryOffset = myRev64(entryOffsetWfRingBlock);
    bufWfRingBlock->sizeOfMeta  = rs4RingLayout.sizeOfMeta;
    bufWfRingBlock->backItemPtr = rs4RingLayout.backItemPtr;
    sizeWfRingBlock             = entryOffsetWfRingBlock +  // Must be 8-byte aligned.
                                  wfInlineLenInWords*4;     // Must be 8-byte aligned.
    // Quick check to see if final ring block size will fit in HB buffer.
    if (sizeWfRingBlock>sizeWfRingBlockMax)  {
      FAPI_ERR("WF ring block size (=%i) exceeds pre-allocated buf1 size (=%i).",
      sizeWfRingBlock, sizeWfRingBlockMax);
      uint32_t &DATA_RING_BLOCK_SIZEOFTHIS=sizeWfRingBlock;
      uint32_t &DATA_SIZE_OF_BUF1=sizeWfRingBlock;
      FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_RING_BLOCK_TOO_LARGE);
      return rc;
    }
    bufWfRingBlock->sizeOfThis  = myRev32(sizeWfRingBlock);
    // Find where meta data goes.
    bufLC = (uint32_t)( entryOffsetWfRingBlock - 
                        myByteAlign(8, myRev32(bufWfRingBlock->sizeOfMeta)) );
    // Copy over meta data. Do not worry about alignment here.
    memcpy( (uint8_t*)bufWfRingBlock+bufLC, 
            rs4RingLayout.metaData, 
            (size_t)myRev32(rs4RingLayout.sizeOfMeta));
    // Find where WF prg goes.
    bufLC = (uint32_t)entryOffsetWfRingBlock;
    // Copy over WF ring prg which is already 8-byte aligned.
    memcpy( (uint8_t*)bufWfRingBlock+bufLC, 
            wfInline, 
            (size_t)wfInlineLenInWords*4);

    // Now, some post-sanity checks on alignments.
    if ( entryOffsetWfRingBlock%8 ||
         sizeWfRingBlock%8)  {
      FAPI_ERR("Member(s) of WF ring block are not 8-byte aligned:");
      FAPI_ERR("  Entry offset            = %i", (uint32_t)entryOffsetWfRingBlock);
      FAPI_ERR("  Size of ring block      = %i", sizeWfRingBlock);
      dataTmp1=(uint32_t)entryOffsetWfRingBlock;
      uint32_t &DATA_RING_BLOCK_ENTRYOFFSET=dataTmp1;
      uint32_t &DATA_RING_BLOCK_SIZEOFTHIS=sizeWfRingBlock;
      FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_RING_BLOCK_ALIGN_ERROR);
      return rc;
    }

	  FAPI_DBG("--> Appending WF ring to .rings section.");
		rcLoc = write_ring_block_to_image(i_imageOut,
                                      NULL,
                                      bufWfRingBlock,
                                      0,
                                      rs4RingLayout.override,
                                      1,
                                      sizeImageOutMax,
                                      SBE_XIP_SECTION_RINGS,
                                      i_buf1,     // Use buf1 as temp buf.
                                      i_sizeBuf1);
    if (rcLoc)  {
      FAPI_ERR("write_ring_block_to_image() failed w/rc=%i",rcLoc);
      FAPI_ERR("Check p8_delta_scan_rw.h for meaning of IMGBUILD_xyz rc code.");
      uint32_t &RC_LOCAL=rcLoc;
      FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_IMGBUILD_ERROR);
      return rc;
    }

	  FAPI_DBG("\tUpdating image w/WF prg + ring header was successful.");
	  
	  countWF++;

	
	}  // End of if (rcSearch!=DSLWB_RING_SEARCH_NO_MATCH)
	
  // ============================================================================
  // Are we done now?
  // ============================================================================
  if (bSearchDone || rcSearch==DSLWB_RING_SEARCH_EXHAUST_MATCH)  {
    FAPI_INF("Wiggle-flip programming done.");
    FAPI_INF("Number of wf programs appended: %i", countWF);
    if (countWF==0)
      FAPI_INF("ZERO WF programs appended to .rings section.");
#ifndef IMGBUILD_PPD_IGNORE_XIPC
    uint32_t  bootCoreMask=0x000FFFF;
		//
		// Do various customizations to image.
    //
    sizeImageTmp = sizeImageOutMax;
		FAPI_INF("Calling xip_customize().\n");
		FAPI_EXEC_HWP(rc, p8_xip_customize,	
		                  i_target,
											i_imageIn,
											i_imageOut,
											sizeImageTmp,
											sysPhase,
											i_modeBuild,
											i_buf1,
											i_sizeBuf1,
											i_buf2,
											i_sizeBuf2,
                      bootCoreMask);
		if (rc!=FAPI_RC_SUCCESS)  {
    	FAPI_ERR("Xip customization failed.");
			return rc;
		}
    FAPI_INF("Xip customization done.");
#else
	  uint32_t sizeImageOld;
		//
		// Initialize .slw section, just in case we ignore xip_customize in a build.
		//
		switch (i_modeBuild)  {
		// --------------------------------------------------------------------
		// case 0:  IPL mode.
		// - This is first time SLW image is built. Go all out.
		// --------------------------------------------------------------------
		case P8_SLW_MODEBUILD_IPL:  // IPL mode.
			rcLoc = create_and_initialize_fixed_image( i_imageOut);
    	if (rcLoc)  {
				uint32_t & RC_LOCAL=rcLoc;
    	  FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_CREATE_FIXED_IMAGE_ERROR);
				return rc;
    	}
    	FAPI_INF("IPL mode build: Fixed SLW and FFDC sections allocated and SLW section initialized for Ramming and Scomming tables.");
			break;
	  // --------------------------------------------------------------------
		// case 1:  Rebuild mode - Nothing to do.
		// - Image size already fixed at 1MB during IPL mode.
		// - Fixed positioning of .slw and .ffdc already done during IPL mode. 
		// --------------------------------------------------------------------
		case P8_SLW_MODEBUILD_REBUILD:  // Rebuild mode. (Need to update Ram/Scom vectors.)
			rcLoc = create_and_initialize_fixed_image( i_imageOut);
    	if (rcLoc)  {
				uint32_t & RC_LOCAL=rcLoc;
    	  FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_CREATE_FIXED_IMAGE_ERROR);
				return rc;
    	}
    	FAPI_INF("Rebuild mode build: Fixed SLW and FFDC sections allocated and SLW section initialized for Ramming and Scomming tables.");
			break;
		// --------------------------------------------------------------------
		// case 2:  SRAM mode.
		// - Assumption: slw_build() called by OCC.
		// - Need to make image as slim as possible.
		// - Do not append .fit.
		// - Position .slw right after .rings.
		// - Do not append .ffdc.
		// --------------------------------------------------------------------
		case P8_SLW_MODEBUILD_SRAM:  // SRAM mode.
	    sizeImageOld = sizeImageTmp;
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
    	FAPI_INF("SRAM mode build: SLW section allocated for Ramming and Scomming tables.");
			break;
		// Default case - Should never get here.
		default:
			FAPI_ERR("Bad code, or bad modeBuild (=%i) parm.",i_modeBuild);
      ffdc_temp = i_modeBuild;
      uint8_t & MODE_BUILD=ffdc_temp;
			FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_BAD_CODE_OR_PARM);
			return rc;
		}
#endif

    // Update host_runtime_scom pointer to point to sub_slw_runtime_scom
		rcLoc = update_runtime_scom_pointer(i_imageOut);
		if (rcLoc==IMGBUILD_ERR_KEYWORD_NOT_FOUND)  {
			uint32_t &RC_LOCAL=rcLoc;
			FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_KEYWORD_NOT_FOUND_ERROR);
			return rc;
		}
		// Report final size.
		sbe_xip_image_size( i_imageOut, &io_sizeImageOut);
    FAPI_INF("Final SLW image size (should be 1MB for modeBuild={0,1}): %i", io_sizeImageOut);
    return FAPI_RC_SUCCESS;
  }

  FAPI_DBG("nextRing (at bottom)=0x%016llx",(uint64_t)nextRing);
    
  }   while (nextRing!=NULL);
  /***************************************************************************
   *                          RING SEARCH LOOP - End                         *
   ***************************************************************************/

  FAPI_ERR("Shouldn't be in this code section. Check code.");
  rcLoc = IMGBUILD_ERR_CHECK_CODE;
  uint32_t & RC_LOCAL=rcLoc;
  FAPI_SET_HWP_ERROR(rc, RC_PROC_SLWB_UNKNOWN_ERROR);
  return rc;

}

} // End of extern C
