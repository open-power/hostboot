/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_slw_build/p8_xip_customize.C $ */
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
// $Id: p8_xip_customize.C,v 1.58 2013/10/29 16:51:57 jeshua Exp $
/*------------------------------------------------------------------------------*/
/* *! TITLE : p8_xip_customize                                                  */
/* *! DESCRIPTION : Obtains repair rings from VPD and adds them to either       */
//                  IPL or SLW mainstore images.    
/* *! OWNER NAME : Michael Olsen                  cmolsen@us.ibm.com            */
//
/* *! EXTENDED DESCRIPTION :                                                    */
//
/* *! USAGE : To build (for Hostboot) -                                         */
//              buildfapiprcd  -c "sbe_xip_image.c,pore_inline_assembler.c,p8_ring_identification.c" -C "p8_image_help.C,p8_image_help_base.C,p8_scan_compression.C,p8_pore_table_gen_api_fixed.C"  -e "$PROC_PATH/../../xml/error_info/p8_xip_customize_errors.xml,$HWPF_PATH/hwp/xml/error_info/mvpd_errors.xml"  p8_xip_customize.C
//            To build (for VBU/command-line) -
//              buildfapiprcd  -r ver-13-0  -c "sbe_xip_image.c,pore_inline_assembler.c,p8_ring_identification.c" -C "p8_image_help.C,p8_image_help_base.C,p8_scan_compression.C,p8_pore_table_gen_api_fixed.C"  -e "../../xml/error_info/p8_xip_customize_errors.xml,../../../../../../hwpf/hwp/xml/error_info/mvpd_errors.xml"  -u "XIPC_COMMAND_LINE"  p8_xip_customize.C
//            Other usages -
//                          using "IMGBUILD_PPD_IGNORE_VPD" will ignore adding MVPD rings.
//                          using "IMGBUILD_PPD_IGNORE_VPD_FIELD" will ignore using fapiGetMvpdField.
//                          using "IMGBUILD_PPD_IGNORE_PLL_UPDATE" will ignore PLL attribute ring.
//													using "IMGBUILD_PPD_IGNORE_L3_BAR" will ignore updating L3 Bar Scoms.
//
/* *! ASSUMPTIONS :                                                             */
//
/* *! COMMENTS :                                                                */
//
/*------------------------------------------------------------------------------*/
#include <p8_pore_api_custom.h>
#include <getMvpdRing.H>
#include <fapiMvpdAccess.H>
#include <p8_xip_customize.H>
#include <p8_delta_scan_rw.h>
#include <p8_ring_identification.H>
#include <p8_pore_table_gen_api.H>
#include <p8_scom_addresses.H>
#include <p8_mailbox_utils.H>

#define min(a,b) ((a<b)?a:b)

extern "C"  {

using namespace fapi;

  const uint32_t MINIMUM_VALID_EXS = 3;


//------------------------------------------------------------------------------
// function:
//      Insert the 32-bit mailbox value into the correct spot in the image
//
// parameters: o_imageOut         The image to modify
//             i_tocName          The name of the entry to modify
//             i_value            The value to insert (in host byte order)
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
  ReturnCode p8_xip_customize_insert_mbox( void *o_imageOut, const char *i_tocName, uint32_t i_value )
  {
    void    *hostMboxVec;
    uint8_t *byteVector;
    fapi::ReturnCode rc;
    uint32_t   rcLoc=0;
    SbeXipItem xipTocItem;
    SBE_XIP_ERROR_STRINGS(errorStrings);

    rcLoc = sbe_xip_find( o_imageOut, i_tocName, &xipTocItem);
    if (rcLoc)  {
      FAPI_ERR("sbe_xip_find() failed w/rc=%i and %s", rcLoc, SBE_XIP_ERROR_STRING(errorStrings, rcLoc));
      FAPI_ERR("Probable cause:");
      FAPI_ERR("\tThe keyword (=%s) was not found.",i_tocName);
      uint32_t & RC_LOCAL = rcLoc;
      FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_KEYWORD_NOT_FOUND_ERROR);
      return rc;
    }
    sbe_xip_pore2host( o_imageOut, xipTocItem.iv_address, &hostMboxVec);
    FAPI_INF("%s: Before (in BE)=0x%016llX\n",i_tocName,*((uint64_t*)hostMboxVec));
    byteVector = (uint8_t*)hostMboxVec;
    // Copy the bytes over one by one
    *(byteVector+0) = (uint8_t)((i_value & 0xFF000000) >> 24);
    *(byteVector+1) = (uint8_t)((i_value & 0x00FF0000) >> 16);
    *(byteVector+2) = (uint8_t)((i_value & 0x0000FF00) >> 8);
    *(byteVector+3) = (uint8_t)((i_value & 0x000000FF) >> 0);
    FAPI_INF("                         After (in BE)=0x%016llX\n",myRev64(*(uint64_t*)hostMboxVec));
    FAPI_INF("    field value (in host)             =0x%08X\n",i_value);
    return rc;
  }

#ifndef IMGBUILD_PPD_IGNORE_VPD

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
//  Parameter list:
//  const fapi::Target &i_target:  Processor chip target.
//  void      *i_imageIn:      Ptr to input img. The IPL img for IPL and the ref img for SLW.
//  void      *o_imageOut:     Ptr to output img.
//  uint32_t  io_sizeImageOut: In: Max size of IPL/SRAM workspace/img. Out: Final size.
//                             MUST equal FIXED_SEEPROM_WORK_SPACE for IPL Seeprom build.
//  uint8_t   i_sysPhase:      0: IPL  1: SLW
//  uint8_t   i_modeBuild:     0: HB/IPL  1: PHYP/Rebuild  2: SRAM 
//  void      *i_buf1:         Temp buffer 1 for dexed RS4 ring. Caller allocs/frees.
//                             Space MUST equal FIXED_RING_BUF_SIZE
//  uint32_t  i_sizeBuf1:      Size of buf1.
//                             MUST equal FIXED_RING_BUF_SIZE
//  void      *i_buf2:         Temp buffer 2 for WF ring. Caller allocs/frees.
//                             Space MUST equal FIXED_RING_BUF_SIZE
//  uint32_t  i_sizeBuf22      Size of buf2.
//                             MUST equal FIXED_RING_BUF_SIZE
ReturnCode p8_xip_customize_insert_chiplet_rings( const fapi::Target &i_target,
                                                  void               *i_imageIn,
                                                  void               *o_imageOut,
                                                  const uint8_t       i_sysPhase,
                                                  void               *i_buf1,
                                                  const uint32_t      i_sizeBuf1,
                                                  void               *i_buf2,
                                                  const uint32_t      i_sizeBuf2,
                                                  const uint8_t       attrDdLevel,
                                                  const uint32_t      sizeImageMax,
                                                  uint8_t             chipletId,
                                                  const SbeXipSection &xipSectionDcrings
                                                  )
{
  fapi::ReturnCode rcFapi, rc=FAPI_RC_SUCCESS;
  uint32_t   rcLoc=0;

  uint8_t    iVpdType;
  RingIdList *ring_id_list=NULL;
  uint32_t   ring_id_list_size;
  uint32_t   iRing;
  uint32_t   sizeVpdRing=0;
  uint8_t    ringId;
  uint8_t    *bufVpdRing;
  uint32_t   ddLevel=attrDdLevel;
  uint32_t   sizeImageOut=sizeImageMax;
  uint8_t    chipletIdVpd;
	
  // Now wade through all conceivable Mvpd rings and add any that's there to the image.
  for (iVpdType=0; iVpdType<NUM_OF_VPD_TYPES; iVpdType++)  {
    if (iVpdType==0)  {
      ring_id_list = (RingIdList*)RING_ID_LIST_PG;
      ring_id_list_size = (uint32_t)RING_ID_LIST_PG_SIZE;
    }
    else  {
      ring_id_list = (RingIdList*)RING_ID_LIST_PR;
      ring_id_list_size = (uint32_t)RING_ID_LIST_PR_SIZE;
    }
   
    for (iRing=0; iRing<ring_id_list_size; iRing++)  {
      ringId = (ring_id_list+iRing)->ringId;
      if((chipletId>=(ring_id_list+iRing)->chipIdMin && chipletId<=(ring_id_list+iRing)->chipIdMax))  {
        FAPI_INF("(iRing,ringId,chipletId) = (%i,0x%02X,0x%02x)",iRing,ringId,chipletId);

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
        FAPI_DBG("XIPC: Mvpd rings: rcFapi=0x%08x",(uint32_t)rcFapi);
        if (rcFapi==RC_REPAIR_RING_NOT_FOUND)  {
          // No match, do nothing. Next ringId.
          FAPI_INF("XIPC: Mvpd rings: (iRing,ringId,chipletId)=(%i,0x%02X,0x%02X) not found.",iRing,ringId,chipletId);
          rcFapi = FAPI_RC_SUCCESS;
        }
        else  {
          // Couple of other checks...
          // 1. General rc error check.
          if (rcFapi!=FAPI_RC_SUCCESS)  {
            FAPI_ERR("getMvpdRing() returned error.");
            return rcFapi;
          }
          // 2. Checking that chipletId didn't somehow get messed up.
          chipletIdVpd = ((CompressedScanData*)bufVpdRing)->iv_chipletId;
          if (chipletIdVpd!=chipletId)  {
            FAPI_ERR("VPD ring's chipletId in scan container (=0x%02X) doesn't match the requested chipletId (=0x%02X).\n",chipletIdVpd,chipletId);
            uint8_t & DATA_CHIPLET_ID_VPD = chipletIdVpd;
            uint8_t & DATA_CHIPLET_ID_REQ = chipletId;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_CHIPLET_ID_MESS);
            return rc;
          }
          // 3. Checking for buffer overflow.
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
            // Enforce flush optimization for Mvpd rings.
            ((CompressedScanData*)bufVpdRing)->iv_flushOptimization = 1;
            // Do datacare, if needed.
            if ( xipSectionDcrings.iv_offset!=0 )  {
              FAPI_INF("Calling check_and_perform_ring_datacare()\n");
              rcLoc = check_and_perform_ring_datacare( 
                                                      i_imageIn,
                                                      (void*)bufVpdRing,  //HB buf1
                                                      attrDdLevel,        //Playing it safe.
                                                      i_sysPhase,
                                                      (char*)(ring_id_list+iRing)->ringNameImg,
                                                      (void*)i_buf2,			//HB buf2
                                                      i_sizeBuf2);
              if (rcLoc)  {
                FAPI_ERR("check_and_perform_ring_datacare() failed w/rc=%i  ",rcLoc);
                uint32_t & RC_LOCAL = rcLoc;
                FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_PERFORM_RING_DATACARE_ERROR);
                return rc;
              }
            }
            if (i_sysPhase==0)  {
              // Check if the VPD ring is redundant
              int redundant = 0;
              rcLoc = rs4_redundant((CompressedScanData*)bufVpdRing, &redundant);
              if(rcLoc) {
                FAPI_ERR("rs4_redundant() failed w/rc=%i  ",rcLoc);
                uint32_t & RC_LOCAL = rcLoc;
                FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_CHECK_REDUNDANT_ERROR);
                return rc;
              }
              rcLoc = 0;
              // Add VPD ring to image if not redundant
              if( redundant ) {
                FAPI_INF("Skipping VPD ring because it doesn't change the ring (iRing,ringId,chipletId)=(%i,0x%02X,0x%02X).",iRing,ringId,chipletId);
              } else {
                // Add VPD ring to --->>> IPL <<<--- image
                rcLoc = write_vpd_ring_to_ipl_image(
                                                    o_imageOut,
                                                    sizeImageOut,
                                                    (CompressedScanData*)bufVpdRing, //HB buf1
                                                    ddLevel,
                                                    i_sysPhase,
                                                    (char*)(ring_id_list+iRing)->ringNameImg,
                                                    (void*)i_buf2,                   //HB buf2
                                                    i_sizeBuf2,
                                                    SBE_XIP_SECTION_RINGS);
                if (rcLoc) {
                  //Check if the add failed because of space issues, and return a unique error for that
                  if (rcLoc==SBE_XIP_WOULD_OVERFLOW) {
                    uint32_t & RC_LOCAL   = rcLoc;
                    uint8_t  & CHIPLET_ID = chipletId;
                    uint8_t  & RING_ID    = ringId;
                    uint32_t & RING_SIZE  = sizeVpdRing;
                    uint32_t & IMAGE_SIZE = sizeImageOut;
                    FAPI_DBG("Ring %s won't fit into image. Size would be %i.", (char*)(ring_id_list+iRing)->ringNameImg, sizeImageOut);
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_RING_WRITE_WOULD_OVERFLOW);
                    return rc;
                  } else {
                    FAPI_ERR("write_vpd_ring_to_ipl_image() failed w/rc=%i",rcLoc);
                    uint32_t & RC_LOCAL = rcLoc;
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_WRITE_VPD_RING_TO_IPL_IMAGE_ERROR);
                    return rc;
                  }
                }
              } //if not redundant
            }
            else  {
              // Add VPD ring to --->>> SLW <<<--- image
              rcLoc = write_vpd_ring_to_slw_image(
                                                  o_imageOut,
                                                  sizeImageOut,
                                                  (CompressedScanData*)bufVpdRing, //HB buf1
                                                  ddLevel,
                                                  i_sysPhase,
                                                  (char*)(ring_id_list+iRing)->ringNameImg,
                                                  (void*)i_buf2,                   //HB buf2
                                                  i_sizeBuf2,
                                                  (ring_id_list+iRing)->bWcSpace);
              if (rcLoc)  {
                FAPI_ERR("write_vpd_ring_to_slw_image() failed w/rc=%i",rcLoc);
                uint32_t & RC_LOCAL = rcLoc;
                FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_WRITE_VPD_RING_TO_SLW_IMAGE_ERROR);
                return rc;
              }
            }
          } //no buffer overflow
        } //ring found in VPD
      } //chiplet ID is valid for this ring name
    } //loop on ring names
  } //loop on VPD types
  return rc;
}
#endif


//  Parameter list:
//  const fapi::Target &i_target:  Processor chip target.
//  void      *i_imageIn:      Ptr to input img. The IPL img for IPL and the ref img for SLW.
//  void      *o_imageOut:     Ptr to output img.
//  uint32_t  io_sizeImageOut: In: Max size of IPL/SRAM workspace/img. Out: Final size.
//                             MUST equal FIXED_SEEPROM_WORK_SPACE for IPL Seeprom build.
//  uint8_t   i_sysPhase:      0: IPL  1: SLW
//  uint8_t   i_modeBuild:     0: HB/IPL  1: PHYP/Rebuild  2: SRAM 
//  void      *i_buf1:         Temp buffer 1 for dexed RS4 ring. Caller allocs/frees.
//                             Space MUST equal FIXED_RING_BUF_SIZE
//  uint32_t  i_sizeBuf1:      Size of buf1.
//                             MUST equal FIXED_RING_BUF_SIZE
//  void      *i_buf2:         Temp buffer 2 for WF ring. Caller allocs/frees.
//                             Space MUST equal FIXED_RING_BUF_SIZE
//  uint32_t  i_sizeBuf22      Size of buf2.
//                             MUST equal FIXED_RING_BUF_SIZE
//  uint32_t  &io_bootCoreMask In: Mask of the desired boot cores (bits 16:31 = EX0:EX15)
//                                 (value is ignored when i_sysPhase != 0)
//                             Out: Mask of the valid boot cores in the image
//
ReturnCode p8_xip_customize( const fapi::Target &i_target,
                             void            *i_imageIn,
                             void            *o_imageOut,
                             uint32_t        &io_sizeImageOut,
                             const uint8_t   i_sysPhase,
                             const uint8_t   i_modeBuild,
                             void            *i_buf1,
                             const uint32_t  i_sizeBuf1,
                             void            *i_buf2,
                             const uint32_t  i_sizeBuf2,
                             uint32_t        &io_bootCoreMask)
{
  fapi::ReturnCode rcFapi, rc=FAPI_RC_SUCCESS;
  uint32_t   rcLoc=0;
  uint32_t   sizeImage, sizeImageIn, sizeImageOutMax, sizeImageMax;
  uint32_t   iVec=0;
  uint8_t    attrDdLevel=0;
  uint64_t   attrCombGoodVec[MAX_CHIPLETS]={ (uint64_t(0xfedcba98)<<32)+0x76543210 };
  void       *hostCombGoodVec;
  SbeXipItem xipTocItem;
  uint32_t   attrL2RT0Eps, attrL2RT1Eps, attrL2RT2Eps, attrL2WEps;
  uint8_t    attrL2ForceRT2Eps;
  uint32_t   attrL3RT0Eps, attrL3RT1Eps, attrL3RT2Eps, attrL3WEps;
  uint8_t    attrL3ForceRT2Eps;
  uint64_t   attrL3BAR1, attrL3BAR2, attrL3BARMask;
  uint64_t   scomData;
  uint8_t    coreId, bScomEntry;
  uint32_t   sizeImageTmp;
  uint64_t   ptrTmp1, ptrTmp2;
  uint32_t   dataTmp1, dataTmp2, dataTmp3;
  bool       largeSeeprom = false;
  uint8_t    seepromAddrBytes = 0;
  const uint32_t   desiredBootCoreMask = (i_sysPhase==0)?io_bootCoreMask:0x0000FFFF;
  FAPI_DBG("Desired boot core mask is 0x%08X, io_bootCoreMask is 0x%08X", desiredBootCoreMask, io_bootCoreMask);

  SBE_XIP_ERROR_STRINGS(errorStrings);

  sizeImageOutMax = io_sizeImageOut;
  
	// First, get the system DD level. We'll need it several places.
  rc = FAPI_ATTR_GET_PRIVILEGED(ATTR_EC, &i_target, attrDdLevel);
  if (rc)  {
    FAPI_ERR("FAPI_ATTR_GET_PRIVILEGED() failed w/rc=%i and ddLevel=0x%02x",(uint32_t)rc,attrDdLevel);
    return rc;
  }

	// Check I2C address size to see if we need to use large seeprom support
  rc = FAPI_ATTR_GET(ATTR_SBE_SEEPROM_I2C_ADDRESS_BYTES, &i_target, seepromAddrBytes);
  if (rc)  {
    FAPI_ERR("FAPI_ATTR_GET failed w/rc=%i and seepromAddrBytes=0x%02x",(uint32_t)rc,seepromAddrBytes);
    return rc;
  }
  if(seepromAddrBytes > 0x02) {
    FAPI_INF("Using large seeprom support when building seeprom image. This image will not work with real SBE");
    largeSeeprom = true;
  }

  // ==========================================================================
  // Check and copy (if IPL phase) image to mainstore and clean it up.
  // ==========================================================================
  //
  // First, check supplied size and validation of input EPROM image.
  //
  sbe_xip_image_size(i_imageIn, &sizeImageIn);
  rcLoc = sbe_xip_validate(i_imageIn, sizeImageIn);
  if (rcLoc)  {
    FAPI_ERR("xip_validate() failed w/rcLoc=%i",rcLoc);
    uint32_t & RC_LOCAL = rcLoc;
    FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_INTERNAL_IMAGE_ERR);
    return rc;
  }
  FAPI_INF("Input image:\n  location=0x%016llx\n  size=%i=0x%x\n",
     (uint64_t)i_imageIn, sizeImageIn, sizeImageIn);

  // Second, if IPL phase, check image and buffer sizes and copy input image to 
  //   output mainstore [work] location.
	// Note, we don't do this for SLW since it was already done in slw_build().
  //    
  if (i_sysPhase==0)  {
    FAPI_INF("Output image:\n  location=0x%016llx\n  size (max)=%i\n",
      (uint64_t)o_imageOut, sizeImageOutMax);
    //
    // First, we'll check image size.
    //
    if (sizeImageOutMax!=FIXED_SEEPROM_WORK_SPACE)  {
      FAPI_ERR("Max work space for output image (=%i) is not equal to FIXED_SEEPROM_WORK_SPACE (=%i).\n",
        sizeImageOutMax,FIXED_SEEPROM_WORK_SPACE);
      sizeImageTmp = FIXED_SEEPROM_WORK_SPACE;
      uint32_t & DATA_IMG_SIZE_MAX = sizeImageOutMax;
      uint32_t & DATA_IMG_SIZE_WORK_SPACE = sizeImageTmp;
      FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_IMAGE_WORK_SPACE_MESS);
      return rc;
    }
    if (sizeImageOutMax<sizeImageIn)  {
      FAPI_ERR("Max output image size (=%i) is smaller than input image size (=%i).",
        sizeImageOutMax,sizeImageIn);
      uint32_t & DATA_IMG_SIZE = sizeImageIn;
      uint32_t & DATA_IMG_SIZE_MAX = sizeImageOutMax;
      FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_IMAGE_SIZE_MESS);
      return rc;
    }
    memcpy( o_imageOut, i_imageIn, sizeImageIn);
    sbe_xip_image_size(o_imageOut, &sizeImage);
    rcLoc = sbe_xip_validate(o_imageOut, sizeImage);
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
    //
    // Next, we'll check the ring buffers.
    //
    if (!i_buf1 || !i_buf2)  {
      FAPI_ERR("The [assumed] pre-allocated ring buffers, i_buf1/2, do not exist.");
      ptrTmp1 = (uint64_t)i_buf1;
      ptrTmp2 = (uint64_t)i_buf2;
      uint64_t & DATA_BUF1_PTR = ptrTmp1;
      uint64_t & DATA_BUF2_PTR = ptrTmp2;
      FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_BUF_PTR_ERROR);
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
      FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_BUF_SIZE_NOT_FIXED);
      return rc;
    }
  }


  // ==========================================================================
  // ==========================================================================
  //                                     *---------*
  //                    CUSTOMIZATION OF | VECTORS |
  //                                     *---------*
  // ==========================================================================
  // ==========================================================================  


  // ==========================================================================
  // CUSTOMIZE item:    Combined good vectors update.
  // Retrieval method:  Attribute.
  // System phase:      IPL and SLW sysPhase.
  // Note: The 32 vectors are listed in order from chiplet 0x00 to 0x1f.
  // Note: We will use the content of these vectors to determine if each
  //       chiplet is functional. This is to avoid the messy "walking the
  //       chiplets approach" using fapiGetChildChiplets().
  // ==========================================================================
  
  rc = FAPI_ATTR_GET(ATTR_CHIP_REGIONS_TO_ENABLE, &i_target, attrCombGoodVec);
  if (rc)  {
    FAPI_ERR("FAPI_ATTR_GET(ATTR_CHIP_REGIONS_TO_ENABLE) returned error.\n");
    return rc;
  }
  //Make sure we always enable the pervasive chiplet
  attrCombGoodVec[0] = 0x0f18000000000000ull;
  attrCombGoodVec[1] = 0x0f18000000000000ull;
  rcLoc = sbe_xip_find( o_imageOut, COMBINED_GOOD_VECTORS_TOC_NAME, &xipTocItem);
  if (rcLoc)  {
    FAPI_ERR("sbe_xip_find() failed w/rc=%i and %s", rcLoc, SBE_XIP_ERROR_STRING(errorStrings, rcLoc));
    FAPI_ERR("Probable cause:");
    FAPI_ERR("\tThe keyword (=%s) was not found.",COMBINED_GOOD_VECTORS_TOC_NAME);
    uint32_t & RC_LOCAL = rcLoc;
    FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_KEYWORD_NOT_FOUND_ERROR);
    return rc;
  }
  sbe_xip_pore2host( o_imageOut, xipTocItem.iv_address, &hostCombGoodVec);
  FAPI_DBG("Dumping [initial] global variable content of combined_good_vectors, then the updated value:\n");
  for (iVec=0; iVec<MAX_CHIPLETS; iVec++)  {
    FAPI_DBG("combined_good_vectors[%2i]: Before=0x%016llX\n",iVec,myRev64(*((uint64_t*)hostCombGoodVec+iVec)));
    *((uint64_t*)hostCombGoodVec+iVec) = myRev64(attrCombGoodVec[iVec]);
    FAPI_DBG("                             After=0x%016llX\n",myRev64(*((uint64_t*)hostCombGoodVec+iVec)));
  }
  
  
  // ==========================================================================
  // CUSTOMIZE item:    L2 "single member mode" enable.
  // Retrieval method:  Attribute.
  // System phase:      IPL and SLW sysPhase.
  // Note: Governs if which cores' L2  may be flipped into single member mode.
  // ==========================================================================
  
  uint32_t   attrL2SingleMember=0;
  void       *hostL2SingleMember;
  rc = FAPI_ATTR_GET(ATTR_EX_L2_SINGLE_MEMBER_ENABLE, &i_target, attrL2SingleMember);
  if (rc)  {
    FAPI_ERR("FAPI_ATTR_GET(ATTR_EX_L2_SINGLE_MEMBER_ENABLE) returned error.\n");
    return rc;
  }
  rcLoc = sbe_xip_find( o_imageOut, L2_SINGLE_MEMBER_ENABLE_TOC_NAME, &xipTocItem);
  if (rcLoc)  {
    FAPI_ERR("sbe_xip_find() failed w/rc=%i and %s", rcLoc, SBE_XIP_ERROR_STRING(errorStrings, rcLoc));
    FAPI_ERR("Probable cause:");
    FAPI_ERR("\tThe keyword (=%s) was not found.",L2_SINGLE_MEMBER_ENABLE_TOC_NAME);
    uint32_t & RC_LOCAL = rcLoc;
    FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_KEYWORD_NOT_FOUND_ERROR);
    return rc;
  }
  sbe_xip_pore2host( o_imageOut, xipTocItem.iv_address, &hostL2SingleMember);
  FAPI_DBG("Dumping [initial] global variable content of %s, and then the updated value:\n",
						L2_SINGLE_MEMBER_ENABLE_TOC_NAME);
  FAPI_DBG(" Before=0x%016llX\n",myRev64(*(uint64_t*)hostL2SingleMember));
  *(uint64_t*)hostL2SingleMember = myRev64((uint64_t)attrL2SingleMember<<32);
  FAPI_DBG(" After =0x%016llX\n",myRev64(*(uint64_t*)hostL2SingleMember));
  
  
  // ==========================================================================
  // CUSTOMIZE item:    Security setup.
  // Retrieval method:  Attribute.
  // System phase:      IPL sysPhase.
  // Note: TBD
  // ==========================================================================

	if (i_sysPhase==0)  {
	  uint64_t   attrSecuritySetupVec=0;
		void       *hostSecuritySetupVec;
	  rc = FAPI_ATTR_GET(ATTR_PROC_SECURITY_SETUP_VECTOR, &i_target, attrSecuritySetupVec);
	  if (rc)  {
	    FAPI_ERR("FAPI_ATTR_GET(ATTR_PROC_SECURITY_SETUP_VECTOR) returned error.\n");
	    return rc;
	  }
	  rcLoc = sbe_xip_find( o_imageOut, SECURITY_SETUP_VECTOR_TOC_NAME, &xipTocItem);
	  if (rcLoc)  {
	    FAPI_ERR("sbe_xip_find() failed w/rc=%i and %s", rcLoc, SBE_XIP_ERROR_STRING(errorStrings, rcLoc));
	    FAPI_ERR("Probable cause:");
	    FAPI_ERR("\tThe keyword (=%s) was not found.",SECURITY_SETUP_VECTOR_TOC_NAME);
	    uint32_t & RC_LOCAL = rcLoc;
	    FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_KEYWORD_NOT_FOUND_ERROR);
	    return rc;
	  }
	  sbe_xip_pore2host( o_imageOut, xipTocItem.iv_address, &hostSecuritySetupVec);
	  FAPI_DBG("Dumping [initial] global variable content of %s, and then the updated value:\n",
							SECURITY_SETUP_VECTOR_TOC_NAME);
	  FAPI_DBG(" Before=0x%016llX\n",myRev64(*(uint64_t*)hostSecuritySetupVec));
	  *(uint64_t*)hostSecuritySetupVec = myRev64(attrSecuritySetupVec);
	  FAPI_DBG(" After =0x%016llX\n",myRev64(*(uint64_t*)hostSecuritySetupVec));
	}

  // ==========================================================================
  // CUSTOMIZE item:    Untrusted bar settings
  // Retrieval method:  Attribute.
  // System phase:      IPL sysPhase.
  // Note: TBD
  // ==========================================================================

	if (i_sysPhase==0)  {
	  uint64_t   attrAduUntrustedBarBase;
    uint64_t   attrAduUntrustedBarSize;

	  uint64_t   attrPsiUntrustedBar0Base;
    uint64_t   attrPsiUntrustedBar0Size;

	  uint64_t   attrPsiUntrustedBar1Base;
    uint64_t   attrPsiUntrustedBar1Size;
    
		void       *hostAduUntrustedBar;
    uint64_t   *untrustbar_field;

    //-------------------------------------------------------------------------------------------
    // ADU BAR
	  rc = FAPI_ATTR_GET(ATTR_PROC_ADU_UNTRUSTED_BAR_BASE_ADDR, &i_target, attrAduUntrustedBarBase);
	  if (rc)  {
	    FAPI_ERR("FAPI_ATTR_GET(ATTR_PROC_ADU_UNTRUSTED_BAR_BASE_ADDR) returned error.\n");
	    return rc;
	  }

	  rc = FAPI_ATTR_GET(ATTR_PROC_ADU_UNTRUSTED_BAR_SIZE, &i_target, attrAduUntrustedBarSize);
	  if (rc)  {
	    FAPI_ERR("FAPI_ATTR_GET(ATTR_PROC_ADU_UNTRUSTED_BAR_SIZE) returned error.\n");
	    return rc;
	  }

    //-------------------------------------------------------------------------------------------
    // PSI BAR0
	  rc = FAPI_ATTR_GET(ATTR_PROC_PSI_UNTRUSTED_BAR0_BASE_ADDR, &i_target, attrPsiUntrustedBar0Base);
	  if (rc)  {
	    FAPI_ERR("FAPI_ATTR_GET(ATTR_PROC_PSI_UNTRUSTED_BAR0_BASE_ADDR) returned error.\n");
	    return rc;
	  }

	  rc = FAPI_ATTR_GET(ATTR_PROC_PSI_UNTRUSTED_BAR0_SIZE, &i_target, attrPsiUntrustedBar0Size);
	  if (rc)  {
	    FAPI_ERR("FAPI_ATTR_GET(ATTR_PROC_PSI_UNTRUSTED_BAR0_SIZE) returned error.\n");
	    return rc;
	  }

    //-------------------------------------------------------------------------------------------
    // PSI BAR1
	  rc = FAPI_ATTR_GET(ATTR_PROC_PSI_UNTRUSTED_BAR1_BASE_ADDR, &i_target, attrPsiUntrustedBar1Base);
	  if (rc)  {
	    FAPI_ERR("FAPI_ATTR_GET(ATTR_PROC_PSI_UNTRUSTED_BAR1_BASE_ADDR) returned error.\n");
	    return rc;
	  }

	  rc = FAPI_ATTR_GET(ATTR_PROC_PSI_UNTRUSTED_BAR1_SIZE, &i_target, attrPsiUntrustedBar1Size);
	  if (rc)  {
	    FAPI_ERR("FAPI_ATTR_GET(ATTR_PROC_PSI_UNTRUSTED_BAR1_SIZE) returned error.\n");
	    return rc;
	  }

    //------------------------------------------------------------------------------------------
    //Look up fabric_config location
	  rcLoc = sbe_xip_find( o_imageOut, UNTRUSTED_BAR_TOC_NAME, &xipTocItem);
	  if (rcLoc)  {
	    FAPI_ERR("sbe_xip_find() failed w/rc=%i and %s", rcLoc, SBE_XIP_ERROR_STRING(errorStrings, rcLoc));
	    FAPI_ERR("Probable cause:");
	    FAPI_ERR("\tThe keyword (=%s) was not found.",UNTRUSTED_BAR_TOC_NAME);
	    uint32_t & RC_LOCAL = rcLoc;
	    FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_KEYWORD_NOT_FOUND_ERROR);
	    return rc;
	  }
	  sbe_xip_pore2host( o_imageOut, xipTocItem.iv_address, &hostAduUntrustedBar);
    untrustbar_field = (uint64_t*)hostAduUntrustedBar;
	  FAPI_DBG("Dumping [initial] global variable content of %s, and then the updated value:\n",
							UNTRUSTED_BAR_TOC_NAME);

	  *(untrustbar_field + 0) = myRev64(attrAduUntrustedBarBase);
	  *(untrustbar_field + 1) = myRev64(attrAduUntrustedBarSize);

 	  *(untrustbar_field + 2) = myRev64(attrPsiUntrustedBar0Base);
	  *(untrustbar_field + 3) = myRev64(attrPsiUntrustedBar0Size);

 	  *(untrustbar_field + 4) = myRev64(attrPsiUntrustedBar1Base);
	  *(untrustbar_field + 5) = myRev64(attrPsiUntrustedBar1Size);

	}


#ifndef IMGBUILD_PPD_IGNORE_VPD_FIELD
  void     *hostPibmemRepairVec, *hostNestSkewAdjVec;
  uint8_t  *bufVpdField;
  uint32_t sizeVpdField=0;
  uint8_t  *byteField, *byteVector;
  // ==========================================================================
  // CUSTOMIZE item:    Update 20 swizzled bits for PIB repair vector.
  // Retrieval method:  MVPD field.
  // System phase:      IPL sysPhase.
  // Note:  Mvpd field data is returned in BE format.
  // ==========================================================================

  if (i_sysPhase==0)  {
    bufVpdField = (uint8_t*)i_buf1;
    sizeVpdField = i_sizeBuf1; // We have to use fixed and max size buffer.
    rcFapi = fapiGetMvpdField(  MVPD_RECORD_CP00,
                                MVPD_KEYWORD_PB,
                                i_target,
                                bufVpdField,
                                sizeVpdField);
    if (rcFapi)  {
      FAPI_ERR("fapiGetMvpdField() w/keyword=PB returned error.");
      return rcFapi;
    }
    rcLoc = sbe_xip_find( o_imageOut, PROC_PIB_REPR_VECTOR_TOC_NAME, &xipTocItem);
    if (rcLoc)  {
      FAPI_ERR("sbe_xip_find() failed w/rc=%i and %s", rcLoc, SBE_XIP_ERROR_STRING(errorStrings, rcLoc));
      FAPI_ERR("Probable cause:");
      FAPI_ERR("\tThe keyword (=%s) was not found.",PROC_PIB_REPR_VECTOR_TOC_NAME);
      uint32_t & RC_LOCAL = rcLoc;
      FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_KEYWORD_NOT_FOUND_ERROR);
      return rc;
    }
    if (sizeVpdField!=5)  {
      FAPI_ERR("fapiGetMvpdField() w/keyword=PB returned sizeVpdField=%i but we expected size=5.",sizeVpdField);
      uint32_t & DATA_SIZE_VPD_FIELD = sizeVpdField;
      FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_UNEXPECTED_FIELD_SIZE);
      return rc;
    }
    FAPI_DBG("Dumping global variable content of pibmem_repair_vector:\n");
    sbe_xip_pore2host( o_imageOut, xipTocItem.iv_address, &hostPibmemRepairVec);
    FAPI_INF("pibmem_repair_vector:Before (in BE)=0x%016llX\n",*(uint64_t*)hostPibmemRepairVec);
    byteField  = (uint8_t*)bufVpdField;
    byteVector = (uint8_t*)hostPibmemRepairVec;
    // Copy the bytes over one by one, skipping first byte (version indicator). 
    *(byteVector+0) = *(byteField+1);
    *(byteVector+1) = *(byteField+2);
    *(byteVector+2) = *(byteField+3);
    *(byteVector+3) = *(byteField+4);
    FAPI_INF("                      After (in BE)=0x%016llX\n",*(uint64_t*)hostPibmemRepairVec);
    FAPI_INF("VPD field value (unalterd & in BE))=0x%016llX\n",*(uint64_t*)bufVpdField);
  }


  // ==========================================================================
  // CUSTOMIZE item:    Update nest skewadjust vector.
  // Retrieval method:  MVPD field.
  // System phase:      IPL sysPhase.
  // ==========================================================================

  if (i_sysPhase==0)  {
    bufVpdField = (uint8_t*)i_buf1;
    sizeVpdField = i_sizeBuf1; // We have to use fixed and max size buffer.
    rcFapi = fapiGetMvpdField(  MVPD_RECORD_CP00,
                                MVPD_KEYWORD_MK,
                                i_target,
                                bufVpdField,
                                 sizeVpdField);
    if (rcFapi)  {
      FAPI_ERR("fapiGetMvpdField() w/keyword=MK returned error.");
      return rcFapi;
    }
    rcLoc = sbe_xip_find( o_imageOut, NEST_SKEWADJUST_VECTOR_TOC_NAME, &xipTocItem);
    if (rcLoc)  {
      FAPI_ERR("sbe_xip_find() failed w/rc=%i and %s", rcLoc, SBE_XIP_ERROR_STRING(errorStrings, rcLoc));
      FAPI_ERR("Probable cause:");
      FAPI_ERR("\tThe keyword (=%s) was not found.",NEST_SKEWADJUST_VECTOR_TOC_NAME);
      uint32_t & RC_LOCAL = rcLoc;
      FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_KEYWORD_NOT_FOUND_ERROR);
      return rc;
    }
    if (sizeVpdField!=5)  {
      FAPI_ERR("fapiGetMvpdField() w/keyword=MK returned sizeVpdField=%i but we expected size=5.",sizeVpdField);
      uint32_t & DATA_SIZE_VPD_FIELD = sizeVpdField;
      FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_UNEXPECTED_FIELD_SIZE);
      return rc;
    }
    FAPI_DBG("Dumping global variable content of nest_skewadjust_vector:\n");
    sbe_xip_pore2host( o_imageOut, xipTocItem.iv_address, &hostNestSkewAdjVec);
    FAPI_INF("nest_skewadjust_vector: Before (in BE)=0x%016llX\n",*((uint64_t*)hostNestSkewAdjVec));
    byteField  = (uint8_t*)bufVpdField;
    byteVector = (uint8_t*)hostNestSkewAdjVec;
    // Copy the bytes over one by one, skipping first byte (version indicator). 
    *(byteVector+0) = *(byteField+1);
    *(byteVector+1) = *(byteField+2);
    *(byteVector+2) = *(byteField+3);
    *(byteVector+3) = *(byteField+4);
    FAPI_INF("                         After (in BE)=0x%016llX\n",*(uint64_t*)hostNestSkewAdjVec);
    FAPI_INF("VPD field value (unaltered & in BE)   =0x%016llX\n",*(uint64_t*)bufVpdField);
  }


  // ==========================================================================
  // CUSTOMIZE item:    Insert the standalone mbox 0-3 register values
  // Retrieval method:  Attributes
  // System phase:      IPL sysPhase
  // ==========================================================================

  if (i_sysPhase==0)  {
    uint32_t mboxValue = 0;

    //MBOX 0 (Note: utils functions number them 1-4, not 0-3)
    rc = p8_mailbox_utils_get_mbox1(i_target, mboxValue);
    if( rc ) {
      FAPI_ERR("Getting the MBOX 0 value failed, so returning the error");
      return rc;
    }

    rc = p8_xip_customize_insert_mbox( o_imageOut, STANDALONE_MBOX0_VALUE_TOC_NAME, mboxValue );
    if( rc ) {
      FAPI_ERR("Putting the MBOX 0 value into the image failed, so returning the error");
      return rc;
    }

    //MBOX 1 (Note: utils functions number them 1-4, not 0-3)
    rc = p8_mailbox_utils_get_mbox2(i_target, mboxValue);
    if( rc ) {
      FAPI_ERR("Getting the MBOX 1 value failed, so returning the error");
      return rc;
    }

    rc = p8_xip_customize_insert_mbox( o_imageOut, STANDALONE_MBOX1_VALUE_TOC_NAME, mboxValue );
    if( rc ) {
      FAPI_ERR("Putting the MBOX 1 value into the image failed, so returning the error");
      return rc;
    }

    //MBOX 2 (Note: utils functions number them 1-4, not 0-3)
    rc = p8_mailbox_utils_get_mbox3(i_target, mboxValue);
    if( rc ) {
      FAPI_ERR("Getting the MBOX 2 value failed, so returning the error");
      return rc;
    }

    rc = p8_xip_customize_insert_mbox( o_imageOut, STANDALONE_MBOX2_VALUE_TOC_NAME, mboxValue );
    if( rc ) {
      FAPI_ERR("Putting the MBOX 2 value into the image failed, so returning the error");
      return rc;
    }

    //MBOX 3 (Note: utils functions number them 1-4, not 0-3)
    //Don't want to include the node info in the SBE image, because that would cause Stradale problems
    rc = p8_mailbox_utils_get_mbox4(i_target, mboxValue, false);
    if( rc ) {
      FAPI_ERR("Getting the MBOX 3 value failed, so returning the error");
      return rc;
    }

    rc = p8_xip_customize_insert_mbox( o_imageOut, STANDALONE_MBOX3_VALUE_TOC_NAME, mboxValue );
    if( rc ) {
      FAPI_ERR("Putting the MBOX 3 value into the image failed, so returning the error");
      return rc;
    }

  } //IF sysPhase == 0
#endif


  // ==========================================================================
  // ==========================================================================
  //                                     *-------*
  //                    CUSTOMIZATION OF | RINGS | SECTION
  //                                     *-------*
  // ==========================================================================
  // ==========================================================================


#ifndef IMGBUILD_PPD_IGNORE_PLL_UPDATE
  // ==========================================================================
  // CUSTOMIZE item:    Update PLL ring (perv_bndy_pll_ring_alt).
  // Retrieval method:  Attribute.
  // System phase:      IPL sysPhase.
  // ==========================================================================

  if (i_sysPhase==0)  {
    uint32_t  tmp32Const1, tmp32Const2;
    uint8_t   attrRingFlush[MAX_PLL_RING_SIZE]={0};
    uint8_t   attrRingData[MAX_PLL_RING_SIZE]={0};
    uint8_t   attrChipletId=0;
    uint32_t  attrScanSelect=0;
    uint32_t  attrRingDataSize=0; // Ring bit size
    uint32_t  sizeDeltaPllRingAlt=0;
    uint32_t  sizeRs4Launch=0;
    uint8_t   *bufDeltaPllRingAlt;
    CompressedScanData *bufPllRingAltRs4;
    uint32_t  sizePllRingAltRs4Max, sizePllRingAltRs4, sizePllRingAltBlockMax;
    DeltaRingLayout *bufPllRingAltBlock;
    uint32_t  bufLC=0;

    //
    // Retrieve the raw PLL rings state from attributes.
    //
    FAPI_INF("XIPC: PLL update: Retrieve the raw PLL ring state from attributes.");
    // Get ring size.
    rc = FAPI_ATTR_GET(ATTR_PROC_PERV_BNDY_PLL_LENGTH, &i_target, attrRingDataSize); // This better be in bits.
    FAPI_DBG("XIPC: PLL update: PLL ring length (bits) = %i",attrRingDataSize);
    FAPI_DBG("XIPC: PLL update: Size of buf1, i_sizeBuf1 (bytes) = %i",i_sizeBuf1);
    if (rc)  {
      FAPI_ERR("FAPI_ATTR_GET(ATTR_PROC_PERV_BNDY_PLL_LENGTH) returned error.");
      return rc;
    }
    if (attrRingDataSize>MAX_PLL_RING_SIZE*8 || attrRingDataSize>i_sizeBuf1*8)  {
      FAPI_ERR("FAPI_ATTR_GET(ATTR_PROC_PERV_BNDY_PLL_LENGTH) returned ring size =%i bits.\n",
               attrRingDataSize);
      FAPI_ERR("But that exceeds either:\n");
      FAPI_ERR("  the max pll ring size =%i bits, or\n",MAX_PLL_RING_SIZE*8);
      FAPI_ERR("  the size of the pre-allocated buf1 =%i bits.", i_sizeBuf1*8);
      uint32_t &DATA_ATTRIBUTE_RING_SIZE=attrRingDataSize;
      tmp32Const1=8*MAX_PLL_RING_SIZE;
      tmp32Const2=8*(uint32_t)i_sizeBuf1;
      uint32_t &DATA_MAX_PLL_RING_SIZE=tmp32Const1;
      uint32_t &DATA_SIZE_OF_BUF1=tmp32Const2;
      FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_PLL_RING_SIZE_TOO_LARGE);
      return rc;
    }
    sizeDeltaPllRingAlt = attrRingDataSize; // We already checked it'll fit into buf1.
    // Get flush and alter (desired) ring state data.
    rc = FAPI_ATTR_GET(ATTR_PROC_PERV_BNDY_PLL_FLUSH, &i_target, attrRingFlush);
    if (rc)  {
      FAPI_ERR("FAPI_ATTR_GET(ATTR_PROC_PERV_BNDY_PLL_FLUSH) returned error.");
      return rc;
    }
    rc = FAPI_ATTR_GET(ATTR_PROC_PERV_BNDY_PLL_DATA, &i_target, attrRingData);
    if (rc)  {
      FAPI_ERR("FAPI_ATTR_GET(ATTR_PROC_PERV_BNDY_PLL_DATA) returned error.");
      return rc;
    }
    rc = FAPI_ATTR_GET(ATTR_PROC_PERV_BNDY_PLL_CHIPLET_ID, &i_target, attrChipletId);
    if (rc)  {
      FAPI_ERR("FAPI_ATTR_GET(ATTR_PROC_PERV_BNDY_PLL_CHIPLET_ID) returned error.");
      return rc;
    }
    rc = FAPI_ATTR_GET(ATTR_PROC_PERV_BNDY_PLL_SCAN_SELECT, &i_target, attrScanSelect);
    if (rc)  {
      FAPI_ERR("FAPI_ATTR_GET(ATTR_PROC_PERV_BNDY_PLL_SCAN_SELECT) returned error.");
      return rc;
    }
    
    //
    // Calculate the delta scan ring.
    //
    FAPI_INF("XIPC: PLL update: Calculate the delta scan ring.");
    bufDeltaPllRingAlt = (uint8_t*)i_buf1;
    rcLoc = calc_ring_delta_state( (uint32_t*)attrRingFlush,
                                   (uint32_t*)attrRingData,
                                   (uint32_t*)bufDeltaPllRingAlt, // Pre-allocated buffer.
                                   sizeDeltaPllRingAlt );
    if (rcLoc)  {
      FAPI_ERR("calc_ring_delta_state() returned error w/rc=%i",rcLoc);
      FAPI_ERR("Check p8_delta_scan_rw.h for meaning of IMGBUILD_xyz rc code.");
      uint32_t &RC_LOCAL=rcLoc;
      FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_IMGBUILD_ERROR);
      return rc;
    }
                              
    //
    // RS4 compress the delta scan ring.
    //
    FAPI_INF("XIPC: PLL update: RS4 compressing the delta scan ring.");
    bufPllRingAltRs4 = (CompressedScanData*)i_buf2;
    sizePllRingAltRs4Max = i_sizeBuf2; // Always supply max buffer space for ring.
    rcLoc = _rs4_compress(bufPllRingAltRs4,     // Contains PLL _alt RS4 ring on return.
                          sizePllRingAltRs4Max, // Max size of buffer.
                          &sizePllRingAltRs4,   // Returned final size of RS4 ring + container.
                          bufDeltaPllRingAlt,   // Input delta scan ring.
                          sizeDeltaPllRingAlt,  // Input delta scan ring size.
                          (uint64_t)attrScanSelect<<32,
                          0,
                          attrChipletId,
                          1 ); // Always flush optimize for base rings.
    if (rcLoc)  {
      FAPI_ERR("_rs4_compress() failed w/rc=%i",rcLoc);
      uint32_t &RC_LOCAL=rcLoc;
      FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_RS4_COMPRESS_ERROR);
      return rc;
    }
    else
    if (sizePllRingAltRs4!=myRev32(bufPllRingAltRs4->iv_size))  {
      FAPI_ERR("_rs4_compress() problem with size of RS4 ring (incl container).");
      FAPI_ERR("Returned size = %i", sizePllRingAltRs4);
      FAPI_ERR("Size from container = %i", myRev32(bufPllRingAltRs4->iv_size));
      uint32_t &DATA_SIZE_RS4_COMPRESS_RETURN=sizePllRingAltRs4;
      tmp32Const1=myRev32(bufPllRingAltRs4->iv_size);
      uint32_t &DATA_SIZE_RS4_COMPRESS_CONTAINER=tmp32Const1;
      FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_RS4_COMPRESS_SIZE_MESS);
      return rc;
    }
    else
      FAPI_INF("Compression Successful.");

    //
    // Build the PLL _alt ring block (= ring header + RS4 launcher + RS4 ring). 
    //
    uint64_t scanChipletAddress=0;
    uint32_t asmBuffer[ASM_RS4_LAUNCH_BUF_SIZE/4];
    PoreInlineContext ctx;

    FAPI_INF("XIPC: PLL update: Building the RS4 PLL ring block.");
    // Reuse i_buf1 to hold the ring block.
    bufPllRingAltBlock = (DeltaRingLayout*)i_buf1;
    sizePllRingAltBlockMax = i_sizeBuf1;
    
    // Construct RS4 launcher:
    // ...get the RS4 decompress address.
    rcLoc = sbe_xip_get_scalar( o_imageOut, "proc_sbe_decompress_scan_chiplet_address", &scanChipletAddress);
    if (rcLoc)  {
      FAPI_ERR("sbe_xip_get_scalar() failed w/rc=%i", rcLoc);
      FAPI_ERR("Probable cause: Key word =proc_sbe_decompress_scan_chiplet_address not found in image.");
      uint32_t &RC_LOCAL=rcLoc;
      FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_KEYWORD_NOT_FOUND_ERROR);
      return rc;
    }
    if (scanChipletAddress==0)  {
      FAPI_ERR("Value of key word (=proc_sbe_decompress_scan_chiplet_address=0) not permitted.");
      uint64_t &DATA_RS4_DECOMPRESS_ADDR=scanChipletAddress;
      FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_ILLEGAL_RS4_DECOMPRESS_ADDR);
      return rc;
    }
    // ... create inline asm code.
    pore_inline_context_create( &ctx, asmBuffer, ASM_RS4_LAUNCH_BUF_SIZE*4, 0, 0);
    rcLoc = ctx.error;
    if (rcLoc)  {
      FAPI_ERR("pore_inline_context_create() failed w/rc=%i", rcLoc);
      uint32_t &RC_LOCAL=rcLoc;
      FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_PORE_INLINE_CTX_CREATE_ERROR);
      return rc;
    }
    pore_MR(&ctx, A0, PC);
    pore_ADDS(&ctx, A0, A0, ASM_RS4_LAUNCH_BUF_SIZE);
    pore_LI(&ctx, D0, scanChipletAddress);
    pore_BRAD(&ctx, D0);
    rcLoc = ctx.error;
    if (rcLoc)  {
      FAPI_ERR("pore_MR/ADDS/LI/BRAD() failed w/rc=%i", rcLoc);
      uint32_t &RC_LOCAL=rcLoc;
      FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_PORE_INLINE_RS4_LAUNCH_CREATE_ERROR);
      return rc;
    }
    sizeRs4Launch = ctx.lc;
    
    // Populate ring header and put ring header, RS4 launcher and RS4 ring into 
    // proper spots in pre-allocated bufPllRingAltBlock buffer.
    //
    uint64_t entryOffsetPllRingAltBlock;
    uint32_t sizeOfThisPllRingAltBlock;
    entryOffsetPllRingAltBlock      = calc_ring_layout_entry_offset( 0, 0);
    bufPllRingAltBlock->entryOffset = myRev64(entryOffsetPllRingAltBlock);
    bufPllRingAltBlock->backItemPtr  = 0; // Will be updated below, as we don't know yet.
    sizeOfThisPllRingAltBlock       =  entryOffsetPllRingAltBlock +  // Must be 8-byte aligned.
                                      sizeRs4Launch +               // Must be 8-byte aligned.
                                      sizePllRingAltRs4;            // Must be 8-byte aligned.
    bufPllRingAltBlock->sizeOfThis  = myRev32(sizeOfThisPllRingAltBlock);
    // Quick check to see if final ring block size will fit in buf1.
    if (sizeOfThisPllRingAltBlock>sizePllRingAltBlockMax)  {
      FAPI_ERR("PLL _alt ring block size (=%i) exceeds pre-allocated buf1 size (=%i).",
        sizeOfThisPllRingAltBlock, sizePllRingAltBlockMax);
      uint32_t &DATA_RING_BLOCK_SIZEOFTHIS=sizeOfThisPllRingAltBlock;
      uint32_t &DATA_SIZE_OF_BUF1=sizePllRingAltBlockMax;
      FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_PLL_RING_BLOCK_TOO_LARGE);
      return rc;
    }
    bufPllRingAltBlock->sizeOfMeta  =  0;
    bufPllRingAltBlock->ddLevel      = myRev32((uint32_t)attrDdLevel);
    bufPllRingAltBlock->sysPhase     = i_sysPhase;
    bufPllRingAltBlock->override     = 0;
    bufPllRingAltBlock->reserved1    = 0;
    bufPllRingAltBlock->reserved2    = 0;
    bufLC = (uint32_t)entryOffsetPllRingAltBlock;
    // Copy over meta data which is zero, so nothing to do in this case!
    // Copy over RS4 launch code which is [already] BE and 8-byte aligned.
    memcpy( (uint8_t*)bufPllRingAltBlock+bufLC, asmBuffer, (size_t)sizeRs4Launch);
    // Copy over RS4 PLL _alt delta scan ring which is [already] 8-byte aligned.
    bufLC = bufLC + sizeRs4Launch;               
    memcpy( (uint8_t*)bufPllRingAltBlock+bufLC, bufPllRingAltRs4, (size_t)sizePllRingAltRs4);

    // Now, some post-sanity checks on alignments.
    if ( sizeRs4Launch!=ASM_RS4_LAUNCH_BUF_SIZE ||
         entryOffsetPllRingAltBlock%8 || 
         sizeRs4Launch%8 ||
         sizeOfThisPllRingAltBlock%8)  {
      FAPI_ERR("Member(s) of PLL _alt ring block are not 8-byte aligned:");
      FAPI_ERR("  Size of RS4 launch code = %i", sizeRs4Launch);
      FAPI_ERR("  Entry offset            = %i", (uint32_t)entryOffsetPllRingAltBlock);
      FAPI_ERR("  Size of ring block      = %i", sizeOfThisPllRingAltBlock);
      uint32_t &DATA_SIZE_OF_RS4_LAUNCH=sizeRs4Launch;
      tmp32Const1=(uint32_t)entryOffsetPllRingAltBlock;
      uint32_t &DATA_RING_BLOCK_ENTRYOFFSET=tmp32Const1;
      uint32_t &DATA_RING_BLOCK_SIZEOFTHIS=sizeOfThisPllRingAltBlock;
      FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_RING_BLOCK_ALIGN_ERROR);
      return rc;
    }

  
    //
    // Append PLL _alt ring to image.
    //
    FAPI_INF("XIPC: PLL update: Appending RS4 PLL ring block to .rings section.");
    rcLoc = write_ring_block_to_image( o_imageOut,
                                       PERV_BNDY_PLL_RING_ALT_TOC_NAME,
                                       bufPllRingAltBlock,
                                       0,
                                       0,
                                       0,
                                       largeSeeprom? sizeImageOutMax:MAX_SEEPROM_IMAGE_SIZE, // OK, since sysPhase=0.
                                       SBE_XIP_SECTION_RINGS,
																			 i_buf2,
																			 i_sizeBuf2);
    if (rcLoc)  {
      FAPI_ERR("write_ring_block_to_image() failed w/rc=%i",rcLoc);
      FAPI_ERR("Check p8_delta_scan_rw.h for meaning of IMGBUILD_xyz rc code.");
      uint32_t &RC_LOCAL=rcLoc;
      FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_IMGBUILD_ERROR);
      return rc;
    }

  }
#endif


#ifndef IMGBUILD_PPD_IGNORE_VPD
  // ==========================================================================
  // CUSTOMIZE item:    Add #G and #R rings.
  // Retrieval method:  MVPD
  // System phase:      Applies to both sysPhase modes: IPL and SLW.
  // Notes: For SLW, only update ex_ chiplet rings.
  // ==========================================================================
  SbeXipSection xipSectionDcrings;
  
  // First, is there an .dcrings section yet in the input image?  We need this to know 
  //   if we should do datacare on #G rings a little later.
  // (Note, it makes no sense checking in output image since SLW has been wiped clean, and 
  //    the same may be the case with IPL image in the future.)
  rcLoc = sbe_xip_get_section(i_imageIn, SBE_XIP_SECTION_DCRINGS, &xipSectionDcrings);
  if (rcLoc)  {
    FAPI_ERR("_get_section(.dcrings...) failed with rc=%i  ",rcLoc);
    uint32_t &RC_LOCAL=rcLoc;
    FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_IMGBUILD_ERROR);
    return rc;
  }

  if (i_sysPhase==0 && !largeSeeprom) {
    // The .dcrings section will eventually be removed from the image, so set the
    // max size to final output size max + .dcrings size if we can
    sizeImageMax = min(MAX_SEEPROM_IMAGE_SIZE + xipSectionDcrings.iv_size, sizeImageOutMax);
  } else {
    sizeImageMax = sizeImageOutMax;
  }

  // First, insert the chiplet XX rings
  rc = p8_xip_customize_insert_chiplet_rings( i_target,
                                              i_imageIn,
                                              o_imageOut,
                                              i_sysPhase,
                                              i_buf1,
                                              i_sizeBuf1,
                                              i_buf2,
                                              i_sizeBuf2,
                                              attrDdLevel,

                                              sizeImageMax,
                                              0xFF,
                                              xipSectionDcrings
                                              );
  if (rc) return rc;

  // Then loop through the chiplets
  uint32_t validEXCount = 0;
  uint8_t  chipletId;
  io_bootCoreMask = 0;
  for (chipletId = CHIPLET_ID_MIN; chipletId <= CHIPLET_ID_MAX; chipletId++) {
    // Only process functional chiplets
    // Note - currently the SBE treats bad cores (0x93) as non-functional (0x00)
    //        so inserting rings for those wastes space. I'll assume that they
    //        won't be in the desiredBootCoreMask and thus won't get rings,
    //        rather than checking for that case because the SBE code may change.
    if (attrCombGoodVec[chipletId]) {
      // Special handling for EX chiplet IDs
      if ((chipletId >= CHIPLET_ID_EX_MIN) && (chipletId <= CHIPLET_ID_EX_MAX)) {
        if (desiredBootCoreMask & (0x80000000 >> chipletId)) {
          rc = p8_xip_customize_insert_chiplet_rings( i_target,
                                                      i_imageIn,
                                                      o_imageOut,
                                                      i_sysPhase,
                                                      i_buf1,
                                                      i_sizeBuf1,
                                                      i_buf2,
                                                      i_sizeBuf2,
                                                      attrDdLevel,
                                                      sizeImageMax,
                                                      chipletId,
                                                      xipSectionDcrings
                                                      );
          if (rc) {
            // fail out unless this was an overflow error for IPL and we've already met the mimimum
            if ((validEXCount < MINIMUM_VALID_EXS) ||
                (rc != RC_PROC_XIPC_RING_WRITE_WOULD_OVERFLOW) ||
                (i_sysPhase!=0)) {
              FAPI_DBG("Was only able to put %i EXs into the image (minimum is %i for IPL, all for SLW)", validEXCount, MINIMUM_VALID_EXS);
              return rc;
            }
            // out of space for this chiplet, but got enough EXs in to run
            // so jump to the end of EXs and continue
            rc = FAPI_RC_SUCCESS;
            chipletId = CHIPLET_ID_EX_MAX;
            FAPI_DBG("Skipping the rest of the rings because image is full");
          } else {
            // Successfully added this chiplet
            // Update tracking of valid EX chiplets in the image
            io_bootCoreMask |= (0x80000000 >> chipletId);
            validEXCount++;
          }
        } else {
          FAPI_DBG("Skipping EX chiplet ID 0x%X because it's not in the bootCoreMask", chipletId);
        }
      } else {
        // Normal handling for non-EX chiplet IDs
        rc = p8_xip_customize_insert_chiplet_rings( i_target,
                                                    i_imageIn,
                                                    o_imageOut,
                                                    i_sysPhase,
                                                    i_buf1,
                                                    i_sizeBuf1,
                                                    i_buf2,
                                                    i_sizeBuf2,
                                                    attrDdLevel,
                                                    sizeImageMax,
                                                    chipletId,
                                                    xipSectionDcrings
                                                    );
        if (rc) return rc;
      } //end else non-EX chiplet
    } //end if valid chiplet
  } //end loop on chiplets
#endif

  // Now, we can safely remove the .dcrings section from the output image. Though, no
  //   need to do it for SLW which was wiped clean in slw_build().
  //
  if (i_sysPhase==0)  {
    rcLoc = sbe_xip_delete_section(o_imageOut, SBE_XIP_SECTION_DCRINGS);
    if (rcLoc)  {
      MY_ERR("_delete_section(.dcrings...) failed w/rc=%i  ",rcLoc);
      uint32_t & RC_LOCAL = rcLoc;
      FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_XIP_DELETE_SECTION_ERROR);
      return rc;
    }
    // Now that the section is removed, lower sizeImageMax to the actual max if needed
    if (!largeSeeprom) {
      sizeImageMax = min(MAX_SEEPROM_IMAGE_SIZE, sizeImageOutMax);
    }
  }

  // ==========================================================================
  // CUSTOMIZE item:    valid_boot_cores_mask
  // Retrieval method:  Generated by this code
  // System phase:      IPL sysPhase.
  // Note: Indicates which EX cores had #G and #R rings inserted
  // ==========================================================================
  if (i_sysPhase==0)  {
    void       *hostValidBootCoresMask;
    rcLoc = sbe_xip_find( o_imageOut, VALID_BOOT_CORES_MASK_TOC_NAME, &xipTocItem);
    if (rcLoc)  {
      FAPI_ERR("sbe_xip_find() failed w/rc=%i and %s", rcLoc, SBE_XIP_ERROR_STRING(errorStrings, rcLoc));
      FAPI_ERR("Probable cause:");
      FAPI_ERR("\tThe keyword (=%s) was not found.",VALID_BOOT_CORES_MASK_TOC_NAME);
      uint32_t & RC_LOCAL = rcLoc;
      FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_KEYWORD_NOT_FOUND_ERROR);
      return rc;
    }
    sbe_xip_pore2host( o_imageOut, xipTocItem.iv_address, &hostValidBootCoresMask);
    FAPI_DBG("Dumping [initial] global variable content of valid_boot_cores_mask, then the updated value:\n");
    FAPI_DBG(" Before=0x%016llX\n",myRev64(*(uint64_t*)hostValidBootCoresMask));
    *(uint64_t*)hostValidBootCoresMask = myRev64(((uint64_t)io_bootCoreMask)<<32);
    FAPI_DBG(" After =0x%016llX\n",myRev64(*(uint64_t*)hostValidBootCoresMask));
  }


  // ==========================================================================
  // ==========================================================================
  //                                     *-----*
  //                    CUSTOMIZATION OF | SLW | SECTION
  //                                     *-----*
  // ==========================================================================
  // ==========================================================================
  
  if (i_sysPhase==1)  {
  
  // ==========================================================================
  // INITIALIZE item:   .slw section (aka runtime section).
  // Retrieval method:  N/A
  // System phase:      SLW sysPhase.
  // Note: This item was originally in slw_build but has to be put here for
  //       practical reasons.
  // ==========================================================================

  switch (i_modeBuild)  {
	
  // --------------------------------------------------------------------
  // case 0:  IPL mode.
  // - This is first time SLW image is built. Go all out.
  // --------------------------------------------------------------------
  case P8_SLW_MODEBUILD_IPL:  // IPL mode.
    rcLoc = create_and_initialize_fixed_image(o_imageOut);
    if (rcLoc)  {
      uint32_t & RC_LOCAL=rcLoc;
      FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_CREATE_FIXED_IMAGE_ERROR);
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
    rcLoc = create_and_initialize_fixed_image(o_imageOut);
    if (rcLoc)  {
      uint32_t & RC_LOCAL=rcLoc;
      FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_CREATE_FIXED_IMAGE_ERROR);
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
    sizeImageTmp = sizeImageOutMax;
    rcLoc = initialize_slw_section(o_imageOut,
                                   &sizeImageTmp);
    if (rcLoc)  {
      if (rcLoc==IMGBUILD_ERR_IMAGE_TOO_LARGE)  {
        uint32_t & DATA_IMG_SIZE_NEW=sizeImageTmp;
        uint32_t & DATA_IMG_SIZE_MAX=sizeImageOutMax;
        FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_MAX_IMAGE_SIZE_EXCEEDED);
      }
      else  {
        uint32_t & RC_LOCAL=rcLoc;
        FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_APPEND_SLW_SECTION_ERROR);
      }
      return rc;
    }
    FAPI_INF("SRAM mode build: SLW section allocated for Ramming and Scomming tables.");
    break;
  // Default case - Should never get here.
  default:
    FAPI_ERR("Bad code, or bad modeBuild (=%i) parm.",i_modeBuild);
    FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_BAD_CODE_OR_PARM);
    return rc;
  
	}  // End of switch (i_modeBuild)


  // ==========================================================================
  // CUSTOMIZE item:    L2 and L3 Epsilon config register SCOM table updates.
  // Retrieval method:  Attribute.
  // System phase:      IPL and SLW sysPhase.
  // ==========================================================================

  // L2
  //  
  rc = FAPI_ATTR_GET(ATTR_L2_R_T0_EPS, NULL, attrL2RT0Eps);
  if (rc)  {
    FAPI_ERR("FAPI_ATTR_GET(ATTR_L2_R_T0_EPS) returned error.\n");
    return rc;
  }
  rc = FAPI_ATTR_GET(ATTR_L2_R_T1_EPS, NULL, attrL2RT1Eps);
  if (rc)  {
    FAPI_ERR("FAPI_ATTR_GET(ATTR_L2_R_T1_EPS) returned error.\n");
    return rc;
  }
  rc = FAPI_ATTR_GET(ATTR_L2_R_T2_EPS, NULL, attrL2RT2Eps);
  if (rc)  {
    FAPI_ERR("FAPI_ATTR_GET(ATTR_L2_R_T2_EPS) returned error.\n");
    return rc;
  }
  rc = FAPI_ATTR_GET(ATTR_L2_W_EPS, NULL, attrL2WEps);
  if (rc)  {
    FAPI_ERR("FAPI_ATTR_GET(ATTR_L2_W_EPS) returned error.\n");
    return rc;
  }
  rc = FAPI_ATTR_GET(ATTR_L2_FORCE_R_T2_EPS, NULL, attrL2ForceRT2Eps);
  if (rc)  {
    FAPI_ERR("FAPI_ATTR_GET(ATTR_L2_FORCE_R_T2_EPS) returned error.\n");
    return rc;
  }
  bScomEntry = 0;
  scomData = ( (uint64_t)attrL2RT0Eps     <<(63-8)  & (uint64_t)0x1ff<<(63-8) )  |
             ( (uint64_t)attrL2RT1Eps     <<(63-17) & (uint64_t)0x1ff<<(63-17) ) |
             ( (uint64_t)attrL2RT2Eps     <<(63-28) & (uint64_t)0x7ff<<(63-28) ) |
             ( (uint64_t)attrL2WEps       <<(63-35) & (uint64_t)0x07f<<(63-35) ) |
             ( (uint64_t)attrL2ForceRT2Eps<<(63-36) & (uint64_t)0x001<<(63-36) );
  FAPI_DBG("scomData =0x%016llx",scomData);
  for (coreId=0; coreId<=15; coreId++)  {
    if (attrCombGoodVec[P8_CID_EX_LOW+coreId])  {
      rcLoc = p8_pore_gen_scom_fixed( 
                      o_imageOut, 
                      i_modeBuild,
                      (uint32_t)EX_L2_CERRS_RD_EPS_REG_0x10012814, // Scom addr.
                      coreId,   // The core ID.
                      scomData,
                      1,        // Repl first matching Scom addr,if any, or add to EOT.
                      0);       // Put in general Scom section.
      if (rcLoc)  {
        FAPI_ERR("Updating SCOM NC table w/L2 Epsilon data unsuccessful (rcLoc=%i)\n",rcLoc);
        uint32_t & RC_LOCAL = rcLoc;
        FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_GEN_SCOM_ERROR); 
        return rc;
      }
      bScomEntry = 1;
    }
  }
  if (bScomEntry)  {
    FAPI_INF("Updating SCOM NC table w/L2 Epsilon data successful.\n");
  }
  else  {
    FAPI_INF("No active cores found. Did not update SCOM NC table w/L3 Epsilon data (2).\n");
  }
  
  // L3
  //
  rc = FAPI_ATTR_GET(ATTR_L3_R_T0_EPS, NULL, attrL3RT0Eps);
  if (rc)  {
    FAPI_ERR("FAPI_ATTR_GET(ATTR_L3_R_T0_EPS) returned error.\n");
    return rc;
  }
  rc = FAPI_ATTR_GET(ATTR_L3_R_T1_EPS, NULL, attrL3RT1Eps);
  if (rc)  {
    FAPI_ERR("FAPI_ATTR_GET(ATTR_L3_R_T1_EPS) returned error.\n");
    return rc;
  }
  rc = FAPI_ATTR_GET(ATTR_L3_R_T2_EPS, NULL, attrL3RT2Eps);
  if (rc)  {
    FAPI_ERR("FAPI_ATTR_GET(ATTR_L3_R_T2_EPS) returned error.\n");
    return rc;
  }
  rc = FAPI_ATTR_GET(ATTR_L3_FORCE_R_T2_EPS, NULL, attrL3ForceRT2Eps);
  if (rc)  {
    FAPI_ERR("FAPI_ATTR_GET(ATTR_L3_FORCE_R_T2_EPS) returned error.\n");
    return rc;
  }
  rc = FAPI_ATTR_GET(ATTR_L3_W_EPS, NULL, attrL3WEps);
  if (rc)  {
    FAPI_ERR("FAPI_ATTR_GET(ATTR_L3_W_EPS) returned error.\n");
    return rc;
  }
  bScomEntry = 0;
  scomData = ( (uint64_t)attrL3RT0Eps     <<(63-8)  & (uint64_t)0x1ff<<(63-8) )  |
             ( (uint64_t)attrL3RT1Eps     <<(63-17) & (uint64_t)0x1ff<<(63-17) ) |
             ( (uint64_t)attrL3RT2Eps     <<(63-28) & (uint64_t)0x7ff<<(63-28) ) |
             ( (uint64_t)attrL3ForceRT2Eps<<(63-30) & (uint64_t)0x003<<(63-30) );
  FAPI_DBG("scomData =0x%016llx",scomData);
  for (coreId=0; coreId<=15; coreId++)  {
    if (attrCombGoodVec[P8_CID_EX_LOW+coreId])  {
      rcLoc = p8_pore_gen_scom_fixed( 
                      o_imageOut, 
                      i_modeBuild,
                      (uint32_t)EX_L3_CERRS_RD_EPS_REG_0x10010829, // Scom addr.
                      coreId,   // The core ID.
                      scomData,
                      1,        // Repl first matching Scom addr,if any, or add to EOT.
                      0);       // Put in general Scom section.
      if (rcLoc)  {
        FAPI_ERR("\tUpdating SCOM NC table w/L3 Epsilon data (1) unsuccessful.\n");
        uint32_t & RC_LOCAL = rcLoc;
        FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_GEN_SCOM_ERROR); 
        return rc;
      }
      bScomEntry = 1;
    }
  }
  if (bScomEntry)  {
    FAPI_INF("Updating SCOM NC table w/L3 Epsilon data (1) successful.\n");
  }
  else  {
    FAPI_INF("No active cores found. Did not update SCOM NC table w/L3 Epsilon data (1).\n");
  }

  bScomEntry = 0;
  scomData = ( (uint64_t)attrL3WEps       <<(63-6)  & (uint64_t)0x07f<<(63-6) );
  FAPI_DBG("scomData =0x%016llx",scomData);
  for (coreId=0; coreId<=15; coreId++)  {
    if (attrCombGoodVec[P8_CID_EX_LOW+coreId])  {
      rcLoc = p8_pore_gen_scom_fixed( 
                      o_imageOut, 
                      i_modeBuild,
                      (uint32_t)EX_L3_CERRS_WR_EPS_REG_0x1001082A, // Scom addr.
                      coreId,   // The core ID.
                      scomData,
                      1,        // Repl first matching Scom addr,if any, or add to EOT.
                      0);       // Put in general Scom section.
      if (rcLoc)  {
        FAPI_ERR("\tUpdating SCOM NC table w/L3 Epsilon data (2) unsuccessful.\n");
        uint32_t & RC_LOCAL = rcLoc;
        FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_GEN_SCOM_ERROR); 
        return rc;
      }
      bScomEntry = 1;
    }
  }
  if (bScomEntry)  {
    FAPI_INF("Updating SCOM NC table w/L3 Epsilon data (2) successful.\n");
  }
  else  {
    FAPI_INF("No active cores found. Did not update SCOM NC table w/L3 Epsilon data (2).\n");
  }


  // ==========================================================================
  // CUSTOMIZE item:    L3 BAR config register SCOM table updates. (By JoeM)
  // Retrieval method:  Attribute.
  // System phase:      IPL and SLW sysPhase.
  // ==========================================================================
#ifndef IMGBUILD_PPD_IGNORE_L3_BAR
  rc = FAPI_ATTR_GET(ATTR_PROC_L3_BAR1_REG, &i_target, attrL3BAR1);
  if (rc)  {
    FAPI_ERR("FAPI_ATTR_GET(ATTR_PROC_L3_BAR1_REG) returned error.\n");
    return rc;
  }

  rc = FAPI_ATTR_GET(ATTR_PROC_L3_BAR2_REG, &i_target, attrL3BAR2);
  if (rc)  {
    FAPI_ERR("FAPI_ATTR_GET(ATTR_PROC_L3_BAR2_REG) returned error.\n");
    return rc;
  }

  rc = FAPI_ATTR_GET(ATTR_PROC_L3_BAR_GROUP_MASK_REG, &i_target, attrL3BARMask);
  if (rc)  {
    FAPI_ERR("FAPI_ATTR_GET(ATTR_PROC_L3_BAR_GROUP_MASK_REG) returned error.\n");
    return rc;
  }

  bScomEntry = 0;
  scomData = ( (uint64_t)attrL3BAR1);
  FAPI_DBG("scomData =0x%016llx",scomData);
  for (coreId=0; coreId<=15; coreId++)  {
    if (attrCombGoodVec[P8_CID_EX_LOW+coreId])  {
      rcLoc = p8_pore_gen_scom_fixed( 
                      o_imageOut, 
                      i_modeBuild,
                      (uint32_t)EX_L3_BAR1_REG_0x1001080B, // Scom addr.
                      coreId,   // The core ID.
                      scomData,
                      1,        // Repl first matching Scom addr,if any, or add to EOT.
                      0);       // Put in general Scom section.
      if (rcLoc)  {
        FAPI_ERR("\tUpdating SCOM NC table w/L3 BAR data (1) unsuccessful.\n");
        uint32_t & RC_LOCAL = rcLoc;
        FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_GEN_SCOM_ERROR); 
        return rc;
      }
      bScomEntry = 1;
    }
  }
  if (bScomEntry)  {
    FAPI_INF("Updating SCOM NC table w/L3 BAR (1) successful.\n");
  }
  else  {
    FAPI_INF("No active cores found. Did not update SCOM NC table w/L3 BAR data (1).\n");
  }

  bScomEntry = 0;
  scomData = ( (uint64_t)attrL3BAR2);
  FAPI_DBG("scomData =0x%016llx",scomData);
  for (coreId=0; coreId<=15; coreId++)  {
    if (attrCombGoodVec[P8_CID_EX_LOW+coreId])  {
      rcLoc = p8_pore_gen_scom_fixed( 
                      o_imageOut, 
                      i_modeBuild,
                      (uint32_t)EX_L3_BAR2_REG_0x10010813, // Scom addr.
                      coreId,   // The core ID.
                      scomData,
                      1,        // Repl first matching Scom addr,if any, or add to EOT.
                      0);       // Put in general Scom section.
      if (rcLoc)  {
        FAPI_ERR("\tUpdating SCOM NC table w/L3 BAR data (2) unsuccessful.\n");
        uint32_t & RC_LOCAL = rcLoc;
        FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_GEN_SCOM_ERROR); 
        return rc;
      }
      bScomEntry = 1;
    }
  }
  if (bScomEntry)  {
    FAPI_INF("Updating SCOM NC table w/L3 BAR (2) successful.\n");
  }
  else  {
    FAPI_INF("No active cores found. Did not update SCOM NC table w/L3 BAR data (2).\n");
  }

  bScomEntry = 0;
  scomData = ( (uint64_t)attrL3BARMask);
  FAPI_DBG("scomData =0x%016llx",scomData);
  for (coreId=0; coreId<=15; coreId++)  {
    if (attrCombGoodVec[P8_CID_EX_LOW+coreId])  {
      rcLoc = p8_pore_gen_scom_fixed( 
                      o_imageOut, 
                      i_modeBuild,
                      (uint32_t)EX_L3_BAR_GROUP_MASK_REG_0x10010816, // Scom addr.
                      coreId,   // The core ID.
                      scomData,
                      1,        // Repl first matching Scom addr,if any, or add to EOT.
                      0);       // Put in general Scom section.
      if (rcLoc)  {
        FAPI_ERR("\tUpdating SCOM NC table w/L3 BAR data (3) unsuccessful.\n");
        uint32_t & RC_LOCAL = rcLoc;
        FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_GEN_SCOM_ERROR); 
        return rc;
      }
      bScomEntry = 1;
    }
  }
  if (bScomEntry)  {
    FAPI_INF("Updating SCOM NC table w/L3 BAR (3) successful.\n");
  }
  else  {
    FAPI_INF("No active cores found. Did not update SCOM NC table w/L3 BAR data (3).\n");
  }
#endif


    
  // ==========================================================================
  // CUSTOMIZE item:    Put RAMs in RAM table to suppurt malfunction alert.
  // Retrieval method:  N/A.
  // System phase:      SLW sysPhase. (By MikeO)
  // ==========================================================================
    uint8_t   threadId;
    uint64_t  lpcrData=(uint64_t)0x00005000; // Set bit(49) and bit(51).
    uint64_t  hmeerData=((uint64_t)0x80000000)<<32; // Set bit(0).
    for (coreId=0; coreId<=15; coreId++)  {
      // Do the LPCR rams.
      for (threadId=0; threadId<=7; threadId++)  {
        rcLoc = p8_pore_gen_cpureg_fixed( 
                        o_imageOut, 
                        i_modeBuild,
                        (uint32_t)P8_SPR_LPCR,
                        lpcrData,
                        coreId,
                        threadId);
        if (rcLoc)  {
          FAPI_ERR("Updating RAM table w/LPCR ram unsuccessful (rcLoc=%i)\n",rcLoc);
          uint32_t & RC_LOCAL = rcLoc;
          FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_GEN_RAM_ERROR); 
          return rc;
        }
      }  // End of for(threadId)
      // Do the HMEER rams.
      rcLoc = p8_pore_gen_cpureg_fixed( 
                      o_imageOut, 
                      i_modeBuild,
                      (uint32_t)P8_SPR_HMEER,
                      hmeerData,
                      coreId,
                      0);
      if (rcLoc)  {
        FAPI_ERR("Updating RAM table w/HMEER ram unsuccessful (rcLoc=%i)\n",rcLoc);
        uint32_t & RC_LOCAL = rcLoc;
        FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_GEN_RAM_ERROR); 
        return rc;
      }
    }  // End of for(coreId)

  }  // End of if (i_sysPhase==1)


  //
  // Done customizing, yeah!!
  //  

  sbe_xip_image_size( o_imageOut, &io_sizeImageOut);
  
  FAPI_INF("XIPC:  Final output image:\n ");
  FAPI_INF("  location=0x%016llx\n  size (actual)=%i\n  size (max allowed)=%i\n ", 
    (uint64_t)o_imageOut, io_sizeImageOut, sizeImageMax);
  FAPI_INF("XIPC:  Input image (just for reference):\n ");
  FAPI_INF("  location=0x%016llx\n  size=%i\n ", 
    (uint64_t)i_imageIn, sizeImageIn);
  
  if (io_sizeImageOut>sizeImageMax)  {
    FAPI_ERR("XIPC: Final output image size (=%i) exceeds max size allowed (=%i).",
      io_sizeImageOut, sizeImageMax);
    uint32_t & DATA_IMG_SIZE = io_sizeImageOut;
    uint32_t & DATA_IMG_SIZE_MAX = sizeImageMax;
    FAPI_SET_HWP_ERROR(rc, RC_PROC_XIPC_IMAGE_SIZE_MESS);
    return rc;
  }

  return FAPI_RC_SUCCESS;
  
}


} // End of extern C
