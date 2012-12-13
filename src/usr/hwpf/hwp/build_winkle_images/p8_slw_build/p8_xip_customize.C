/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_slw_build/p8_xip_customize.C $ */
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
// $Id: p8_xip_customize.C,v 1.12 2012/12/07 18:22:32 cmolsen Exp $
/*------------------------------------------------------------------------------*/
/* *! TITLE : p8_xip_customize                                                  */
/* *! DESCRIPTION : Obtains repair rings from VPD and adds them to either       */
//                  IPL or SLW mainstore images.    
/* *! OWNER NAME : Michael Olsen                  cmolsen@us.ibm.com            */
//
/* *! EXTENDED DESCRIPTION :                                                    */
//
/* *! USAGE : To build (for Hostboot) -                                         */
//              buildfapiprcd  -c "sbe_xip_image.c,pore_inline_assembler.c,p8_ring_identification.c" -C "p8_image_help.C"  -e "$PROC_PATH/../../xml/error_info/p8_xip_customize_errors.xml,../../../../../../hwpf/hwp/xml/attribute_info/chip_attributes.xml,../../../../../../hwpf/hwp/xml/error_info/mvpd_errors.xml"  p8_xip_customize.C
//            To build (for VBU/command-line) - assuming getMvpdRing_x86.so already exist.
//              buildfapiprcd  -r ver-13-0  -c "sbe_xip_image.c,pore_inline_assembler.c,p8_ring_identification.c" -C "p8_image_help.C"  -e "../../xml/error_info/p8_xip_customize_errors.xml,../../../../../../hwpf/hwp/xml/attribute_info/chip_attributes.xml,../../../../../../hwpf/hwp/xml/error_info/mvpd_errors.xml"  -u "XIPC_COMMAND_LINE"  p8_xip_customize.C
//            To build (for VBU/command-line) - incorporating getMvpdRing etc into build:
//            (NB! Not recommended - it's a mess - the following is incoomplete)
//              buildfapiprcd  -r ver-13-0  -c "sbe_xip_image.c,pore_inline_assembler.c,p8_ring_identification.c" -C "p8_image_help.C,getMvpdRing.C"  -e "../../xml/error_info/p8_xip_customize_errors.xml,../../../../../../hwpf/hwp/xml/error_info/mvpd_errors.xml,../../../../../../hwpf/hwp/xml/attribute_info/chip_attributes.xml,../../../../../../hwpf/hwp/xml/error_info/mvpd_errors.xml"  -u "XIPC_COMMAND_LINE"  p8_xip_customize.C
//            Other usages -
//                          using "IMGBUILD_PPD_IGNORE_VPD" will ignore adding MVPD rings.
//                          using "IMGBUILD_PPD_IGNORE_VPD_FIELD" will ignore using fapiGetMvpdField.
//                          using "IMGBUILD_PPD_IGNORE_PLL_UPDATE" will ignore PLL attribute ring.
//
/* *! ASSUMPTIONS :                                                             */
//
/* *! COMMENTS :                                                                */
//
/*------------------------------------------------------------------------------*/
// The IMGBUILD_PPD_IGNORE_PLL_UPDATE macro is defined to temporarily disable
// the call usage of attributes which are not yet supported.
// @Todo:  RTC 60670 will remove the macro when the attributes are supported.
#define IMGBUILD_PPD_IGNORE_PLL_UPDATE

#include <p8_pore_api_custom.h>
#include <HvPlicModule.H>
#include <getMvpdRing.H>
#include <fapiMvpdAccess.H>
#include <p8_xip_customize.H>
#include <p8_delta_scan_rw.h>
#include <p8_ring_identification.H>

extern "C"  {

using namespace fapi;

//  Parameter list:
//  const fapi::Target &i_target:  Processor chip target.
//  void      *i_imageIn:      Ptr to input IPL or input/output SLW image.
//  void      *i_imageOut:     Ptr to output IPL img. (Ignored for SLW/RAM imgs.)
//  uint32_t  io_sizeImageOut: In: Max size of IPL/SRAM img. Out: Final size.
//  uint8_t   i_sysPhase:      0: IPL  1: SLW
//  void      *i_buf1:         Temp buffer 1 for dexed RS4 ring. Caller allocs/frees.
//  uint32_t  i_sizeBuf1:      Size of buf1.
//  void      *i_buf2:         Temp buffer 2 for WF ring. Caller allocs/frees.
//  uint32_t  i_sizeBuf22      Size of buf2.
//
ReturnCode p8_xip_customize( const fapi::Target &i_target,
                             void            *i_imageIn,
														 void            *i_imageOut,
												     uint32_t        &io_sizeImageOut,
														 const uint8_t   i_sysPhase,
														 void            *i_buf1,
														 const uint32_t  i_sizeBuf1,
														 void            *i_buf2,
														 const uint32_t  i_sizeBuf2 )
{
  fapi::ReturnCode rcFapi, rc=FAPI_RC_SUCCESS;
	uint32_t  rcLoc=0;
  void      *imageOut;
  uint32_t  sizeImage, sizeImageIn, sizeImageOut, sizeImageOutMax;

	SBE_XIP_ERROR_STRINGS(errorStrings);

  sizeImageOutMax = io_sizeImageOut;
  
  // ==========================================================================
  // Check and copy (if IPL phase) image to mainstore and clean it up.
  // ==========================================================================
  //
  // First, check supplied size and validation of input EPROM image.
  //
  sbe_xip_image_size((void*)i_imageIn, &sizeImageIn);
  rcLoc = sbe_xip_validate((void*)i_imageIn, sizeImageIn);
  if (rcLoc)  {
    FAPI_ERR("xip_validate() failed w/rcLoc=%i",rcLoc);
    uint32_t & RC_LOCAL = rcLoc;
    FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_INTERNAL_IMAGE_ERR);
    return rc;
  }
  
  // Second, if IPL phase, copy input image to supplied mainstore location.
  //
	if (i_sysPhase==0)  {
	  imageOut = (void*)i_imageOut;
		memcpy( imageOut, i_imageIn, sizeImageIn);
	  sbe_xip_image_size(imageOut, &sizeImage);
	  rcLoc = sbe_xip_validate(imageOut, sizeImage);
	  if (rcLoc)  {
	    FAPI_ERR("xip_validate() failed w/rcLoc=%i",rcLoc);
			uint32_t & RC_LOCAL=rcLoc;
	    FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_MS_INTERNAL_IMAGE_ERR);
	    return rc;
	  }
	  if (sizeImage!=sizeImageIn)  {
	    FAPI_ERR("Size obtained from image's header (=%i) differs from supplied size (=%i).",
	      sizeImage,sizeImageIn);
	    uint32_t & DATA_IMG_SIZE_INP = sizeImageIn;
	    uint32_t & DATA_IMG_SIZE = sizeImage;
	    FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_MS_IMAGE_SIZE_MISMATCH);
	    return rc;
	  }
	}
	else  // Output image is same as input image in SLW case (even for an SRAM build).
		imageOut = (void*)i_imageIn;

  // Customization defines.
  //
	uint32_t iVec=0;
	uint64_t attrCombGoodVec[MAX_CHIPLETS]={ (uint64_t(0xfedcba98)<<32)+0x76543210 };
	void     *hostCombGoodVec;
	SbeXipItem xipTocItem;
	
	// --------------------------------------------------------------------------
	// CUSTOMIZE item:    Combined good vectors update.
	// Retrieval method:  Attribute.
	// System phase:      IPL and SLW sysPhase.
	// Note: The 32 vectors are listed in order from chiplet 0x00 to 0x1f.
	// Note: We will use the content of these vectors to determine if each
	//       chiplet is functional. This is to avoid the messy "walking the
	//       chiplets approach" using fapiGetChildChiplets().
	// --------------------------------------------------------------------------
	
	rc = FAPI_ATTR_GET(ATTR_CHIP_REGIONS_TO_ENABLE, &i_target, attrCombGoodVec);
	if (rc)  {
		FAPI_ERR("FAPI_ATTR_GET(ATTR_CHIP_REGIONS_TO_ENABLE) returned error.\n");
	  return rc;
	}
	rcLoc = sbe_xip_find( imageOut, COMBINED_GOOD_VECTORS_TOC_NAME, &xipTocItem);
	if (rcLoc)  {
    FAPI_ERR("sbe_xip_find() failed w/rc=%i and %s", rcLoc, SBE_XIP_ERROR_STRING(errorStrings, rcLoc));
    FAPI_ERR("Probable cause:");
    FAPI_ERR("\tThe keyword (=%s) was not found.",COMBINED_GOOD_VECTORS_TOC_NAME);
    uint32_t & RC_LOCAL = rcLoc;
	  FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_KEYWORD_NOT_FOUND_ERROR);
	  return rc;
  }
	sbe_xip_pore2host( imageOut, xipTocItem.iv_address, &hostCombGoodVec);
	FAPI_DBG("Dumping [initial] global variable content of combined_good_vectors, then the updated value:\n");
	for (iVec=0; iVec<MAX_CHIPLETS; iVec++)  {
		FAPI_INF("combined_good_vectors[%2i]: Before=0x%16llX",iVec,*((uint64_t*)hostCombGoodVec+iVec));
	  *((uint64_t*)hostCombGoodVec+iVec) = myRev64(attrCombGoodVec[iVec]);
		FAPI_INF("                             After=0x%16llX\n",*((uint64_t*)hostCombGoodVec+iVec));
	}

#ifndef IMGBUILD_PPD_IGNORE_VPD_FIELD
	void     *hostPibmemRepairVec, *hostNestSkewAdjVec;
	uint8_t  *bufVpdField;
	uint32_t sizeVpdField=0; 
  // --------------------------------------------------------------------------
	// CUSTOMIZE item:    Update 20 swizzled bits for PIB repair vector.
	// Retrieval method:  MVPD field.
	// System phase:      IPL sysPhase.
	// --------------------------------------------------------------------------
	if (i_sysPhase==0)  {
		bufVpdField = (uint8_t*)i_buf1;
		sizeVpdField = i_sizeBuf1; // We have to use fixed and max size buffer.
		FAPI_EXEC_HWP(rcFapi, fapiGetMvpdField,
																MVPD_RECORD_CP00,
					                      MVPD_KEYWORD_PB, // Use _PR temporarily. Should be _PB.
															  i_target,
	        	      	      		  bufVpdField,
	        	 	      	          sizeVpdField);
	  if (rcFapi)  {
	    FAPI_ERR("fapiGetMvpdField() w/keyword=PB returned error.");
			return rcFapi;
    }
		rcLoc = sbe_xip_find( imageOut, PERV_PIB_REPR_VECTOR_TOC_NAME, &xipTocItem);
		if (rcLoc)  {
  	  FAPI_ERR("sbe_xip_find() failed w/rc=%i and %s", rcLoc, SBE_XIP_ERROR_STRING(errorStrings, rcLoc));
  	  FAPI_ERR("Probable cause:");
  	  FAPI_ERR("\tThe keyword (=%s) was not found.",PERV_PIB_REPR_VECTOR_TOC_NAME);
  	  uint32_t & RC_LOCAL = rcLoc;
		  FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_KEYWORD_NOT_FOUND_ERROR);
		  return rc;
  	}
		if (sizeVpdField!=4)  {
			FAPI_ERR("fapiGetMvpdField() w/keyword=PB returned sizeVpdField=%i but expected size=4.",sizeVpdField);
			uint32_t & DATA_SIZE_VPD_FIELD = sizeVpdField;
			FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_UNEXPECTED_FIELD_SIZE);
			return rc;
		}
		FAPI_DBG("Dumping global variable content of pibmem_repair_vector:\n");
		sbe_xip_pore2host( imageOut, xipTocItem.iv_address, &hostPibmemRepairVec);
		FAPI_INF("pibmem_repair_vector:Before=0x%16llX\n",*((uint64_t*)hostPibmemRepairVec));
		*(uint64_t*)hostPibmemRepairVec = myRev64(((uint64_t)(*(uint32_t*)bufVpdField))<<32);
		FAPI_INF("                      After=0x%16llX\n",*((uint64_t*)hostPibmemRepairVec));
	}

  // --------------------------------------------------------------------------
	// CUSTOMIZE item:    Update nest skewadjust vector.
	// Retrieval method:  MVPD field.
	// System phase:      IPL sysPhase.
	// --------------------------------------------------------------------------
	if (i_sysPhase==0)  {
		bufVpdField = (uint8_t*)i_buf1;
		sizeVpdField = i_sizeBuf1; // We have to use fixed and max size buffer.
		FAPI_EXEC_HWP(rcFapi, fapiGetMvpdField,
																MVPD_RECORD_CP00,
					                      MVPD_KEYWORD_MK, // Use _PR temporarily. Should be _MK.
															  i_target,
	        	      	      		  bufVpdField,
	        	 	      	          sizeVpdField);
	  if (rcFapi)  {
	    FAPI_ERR("fapiGetMvpdField() w/keyword=MK returned error.");
			return rcFapi;
    }
		rcLoc = sbe_xip_find( imageOut, NEST_SKEWADJUST_VECTOR_TOC_NAME, &xipTocItem);
		if (rcLoc)  {
  	  FAPI_ERR("sbe_xip_find() failed w/rc=%i and %s", rcLoc, SBE_XIP_ERROR_STRING(errorStrings, rcLoc));
  	  FAPI_ERR("Probable cause:");
  	  FAPI_ERR("\tThe keyword (=%s) was not found.",NEST_SKEWADJUST_VECTOR_TOC_NAME);
  	  uint32_t & RC_LOCAL = rcLoc;
		  FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_KEYWORD_NOT_FOUND_ERROR);
		  return rc;
  	}
		if (sizeVpdField!=4)  {
			FAPI_ERR("fapiGetMvpdField() w/keyword=MK returned sizeVpdField=%i but expected size=4.",sizeVpdField);
			uint32_t & DATA_SIZE_VPD_FIELD = sizeVpdField;
			FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_UNEXPECTED_FIELD_SIZE);
			return rc;
		}
		FAPI_DBG("Dumping global variable content of nest_skewadjust_vector:\n");
		sbe_xip_pore2host( imageOut, xipTocItem.iv_address, &hostNestSkewAdjVec);
		FAPI_INF("nest_skewadjust_vector: Before=0x%16llX\n",*((uint64_t*)hostNestSkewAdjVec));
  	*(uint64_t*)hostNestSkewAdjVec = myRev64(((uint64_t)(*(uint32_t*)bufVpdField))<<32);
		FAPI_INF("                         After=0x%16llX\n",*((uint64_t*)hostNestSkewAdjVec));
	}
#endif

  // --------------------------------------------------------------------------
	// CUSTOMIZE item:    Update PLL ring (perv_bndy_pll_ring).
	// Retrieval method:  Attribute.
	// System phase:      IPL sysPhase.
	// --------------------------------------------------------------------------
#ifndef IMGBUILD_PPD_IGNORE_PLL_UPDATE
#define MAX_PLL_RING_SIZE 256
  uint8_t  attrRingData[MAX_PLL_RING_SIZE] = { 0 };
  uint32_t attrRingDataSize=0; 
  if (i_sysPhase==0)  {
    rc = FAPI_ATTR_GET(ATTR_RING_DATA_SIZE, $i_target, attrRingDataSize);
	  if (rc)  {
		  FAPI_ERR("FAPI_ATTR_GET(ATTR_RING_DATA_SIZE) returned error.\n");
	    return rc;
	  }
    if (attrRingDataSize>MAX_PLL_RING_SIZE)  {
      FAPI_ERR("FAPI_ATTR_GET(ATTR_RING_DATA_SIZE) returned ring size=%i > max pll ring size=%i bytes.\n",
               attrRingDataSize,MAX_PLL_RING_SIZE);
	    return rc;
	  }
  	rc = FAPI_ATTR_GET(ATTR_RING_DATA, &i_target, attrRingData);
	  if (rc)  {
		  FAPI_ERR("FAPI_ATTR_GET(ATTR_RING_DATA) returned error.\n");
	    return rc;
	  }
  }
  // Check that this is final "xor'ed" ring state, so I can proceed directly to RS4 compression.
#endif

	// --------------------------------------------------------------------------
	// CUSTOMIZE item:  Add #G and #R rings.
	// Applies to both sysPhase modes: IPL and SLW.
	// For SLW, only update ex_ chiplet rings.
	// --------------------------------------------------------------------------
	
	/***************************************************************************
   *                        CHIPLET WALK LOOP - Begin                        *
   ***************************************************************************/
	//
	// Walk through #G rings first, then #R rings.
	//   iVpdType=0 : #G Repair rings
	//   iVpdType=1 : #R Repair rings
	// Notes about VPD rings:
	//   - Only space for the base ring is allocated in the TOC. No override space!
	//   - Some ex_ rings are non-core-ID-specific and will have chipletID=0xFF.
	//     Add these rings only once!!
	// Notes about #G rings:
	//   - Some ex_ rings are core ID specific. Add the fwd ptr based on the core ID.
	// Notes about $R rings:
	//   - The ex_ rings are core ID specific. Add the fwd ptr based on the core ID.
	//
	uint8_t iVpdType;
	RingIdList *ring_id_list=NULL;
	uint32_t ring_id_list_size;
	
	for (iVpdType=0; iVpdType<NUM_OF_VPD_TYPES; iVpdType++)  {
    if (iVpdType==0)  {
		  ring_id_list = (RingIdList*)RING_ID_LIST_PG;
		  ring_id_list_size = (uint32_t)RING_ID_LIST_PG_SIZE;
		}
		else  {
		  ring_id_list = (RingIdList*)RING_ID_LIST_PR;
		  ring_id_list_size = (uint32_t)RING_ID_LIST_PR_SIZE;
		}
#ifndef IMGBUILD_PPD_IGNORE_VPD
	uint32_t  iRing;
	uint32_t  sizeVpdRing=0;
	uint8_t   chipletId, ringId;
	uint8_t   *bufVpdRing;
	uint32_t  ddLevel=0xFFFFFFFF;
	uint8_t   bValidChipletId=0,bRingAlreadyAdded=0;
	uint8_t   chipletIdVpd;
   
		for (iRing=0; iRing<ring_id_list_size; iRing++)  {
			ringId = (ring_id_list+iRing)->ringId;
			bRingAlreadyAdded = 0;
			for ( chipletId=(ring_id_list+iRing)->chipIdMin; 
			     (chipletId>=(ring_id_list+iRing)->chipIdMin && chipletId<=(ring_id_list+iRing)->chipIdMax); 
						chipletId++)  {
				FAPI_INF("(iRing,chipletId) = (%2i,0x%02x)",iRing,chipletId);
				bValidChipletId = 0;
				if (chipletId>=CHIPLET_ID_MIN && chipletId<=CHIPLET_ID_MAX)  {
					// Using known_good_vectors data to determine of a chiplet is functional.
					if (attrCombGoodVec[chipletId])
						bValidChipletId = 1;
					else
						bValidChipletId = 0;
				}
				else  {
					if (chipletId==0xFF)
						bValidChipletId = 1;
					else  {
						bValidChipletId = 0;
						FAPI_INF("chipletId=0x%02x is not a valid chiplet ID. Check chiplet ID range in p8_ring_identification.c.",chipletId);
					}
				}
				if (bValidChipletId)  {
					bufVpdRing = (uint8_t*)i_buf1;
					sizeVpdRing = i_sizeBuf1; // We always supply max buffer space for ring.
				  // 2012-11-14: CMO- A thought: Once getMvpdRing() becomes available, add 
					//             get_mvpd_keyword() func at bottom in this file. Then
					//             put prototype in *.H file. The func should map the
					//             vpd keyword (0,1,2,...) to mvpd keyword in the include
					//             file, fapiMvpdAccess.H.
					//rcFapi = get_mvpd_keyword((ring_id_list+iRing)->vpdKeyword, mvpdKeyword);
					//if (rcFapi)  {
					//  FAPI_ERR("get_mvpd_keyword() returned error.");
					//  return rcFapi;
					//}
					fapi::MvpdKeyword mvpd_keyword;
					if ((ring_id_list+iRing)->vpdKeyword==VPD_KEYWORD_PDG) 
						mvpd_keyword = MVPD_KEYWORD_PDG;
					else
					if ((ring_id_list+iRing)->vpdKeyword==VPD_KEYWORD_PDR)
						mvpd_keyword = MVPD_KEYWORD_PDR;
					else  {
						FAPI_ERR("Unable to resolve VPD keyword from ring list table.");
					  uint8_t & DATA_RING_LIST_VPD_KEYWORD = (ring_id_list+iRing)->vpdKeyword;
						FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_VPD_KEYWORD_RESOLVE_ERROR);
						return rc;
					}
					FAPI_EXEC_HWP(rcFapi, getMvpdRing,
																MVPD_RECORD_CP00,
					                      mvpd_keyword,
															  i_target,
								  						  chipletId,
	    	   	    	 			        ringId,
	        	      	      		  bufVpdRing,
	        	 	      	          sizeVpdRing);
					if (rcFapi!=FAPI_RC_SUCCESS && rcFapi!=RC_REPAIR_RING_NOT_FOUND)  {
						FAPI_ERR("getMvpdRing() returned error.");
						return rcFapi;
					}
					chipletIdVpd = ((CompressedScanData*)bufVpdRing)->iv_chipletId;
					if (chipletIdVpd!=chipletId && chipletIdVpd!=0xFF)  {
						FAPI_ERR("VPD ring's chipletId in scan container (=0x%02X) is not equal to 0xFF nor does it match the requested chipletId (=0x%02X).\n",chipletIdVpd,chipletId);
						uint8_t & DATA_CHIPLET_ID_VPD = chipletIdVpd;
						uint8_t & DATA_CHIPLET_ID_REQ = chipletId;
						FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_CHIPLET_ID_MESS);
						return rc;
					}
					//if (sizeVpdRing==0)  {
					if (rcFapi==RC_REPAIR_RING_NOT_FOUND)  {
						// No match, do nothing. Next (chipletId,ringId)-pair.
					}
					else  {
						if (sizeVpdRing>i_sizeBuf1)  {
							// Supplied buffer from HB/PHYP is too small. Error out. Is this right
							//   decision or should we ignore and proceed to next ring.
							uint32_t sizeBuf1=(uint32_t)i_sizeBuf1;
							uint32_t & DATA_RING_SIZE_REQ = sizeVpdRing;
					    uint32_t & DATA_RING_SIZE_MAX = sizeBuf1;
	   					switch (iVpdType)  {
								case 0:
								FAPI_ERR("#G ring too large.");
								FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_PG_RING_TOO_LARGE);
								break;
								case 1:
								FAPI_ERR("#R ring too large.");
								FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_PR_RING_TOO_LARGE);
								break;
								default:
								uint8_t & DATA_VPD_TYPE = iVpdType;
								FAPI_ERR("#Invalid VPD type.");
								FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_INVALID_VPD_TYPE);
								break;
							}
							return rc;
						}
						else  {
							// Add VPD ring to image.
							if (!bRingAlreadyAdded)  {
								sizeImageOut = sizeImageOutMax;
								if (i_sysPhase==0)  {
									// Add VPD ring to --->>> IPL <<<--- image
									rcLoc = write_vpd_ring_to_ipl_image(
																					imageOut,
								     			                sizeImageOut,
														    					(CompressedScanData*)bufVpdRing, //i_buf1
																    			ddLevel,
																		    	i_sysPhase,
																				  (char*)((ring_id_list+iRing)->ringNameImg),
																	        (void*)i_buf2,
																	        i_sizeBuf2);
									//CMO: How do we return a more informative rc, say one that indicates
									//     successful img build but no rings found?
								}
								else  {
									// Add VPD ring to --->>> SLW <<<--- image
									rcLoc = write_vpd_ring_to_ipl_image(
																					imageOut,
								     			                sizeImageOut,
														    					(CompressedScanData*)bufVpdRing, //i_buf1
																    			ddLevel,
																		    	i_sysPhase,
																				  (char*)(ring_id_list+iRing)->ringNameImg,
																	        (void*)i_buf2,
																	        i_sizeBuf2);
								}
								if (chipletIdVpd==0xFF)
									bRingAlreadyAdded = 1;
							}
						}
					}
				}
			}
		}
#endif
  }

  i_imageOut = imageOut;
  io_sizeImageOut = sizeImageOut;
  
  return FAPI_RC_SUCCESS;
  
}


} // End of extern C
