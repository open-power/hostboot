/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_slw_build/p8_image_help_base.C $ */
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
// $Id: p8_image_help_base.C,v 1.14 2013-08-01 13:34:16 dcrowell Exp $
/*------------------------------------------------------------------------------*/
/* *! TITLE : p8_image_help_base.c                                              */
/* *! DESCRIPTION : Basic helper functions for building and extracting          */
//                  information from SBE-XIP images.
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

#ifdef __FAPI
#include <fapi.H>
#endif
extern "C"  {


// get_ring_layout_from_image2()
// - This is a simplified version of get_ring_layout_from_image():
//   - It returns a pointer to the ring layout structure in the input image.
//   - It DOES NOT populate members of the ring layout structure!
//   - Don't attempt to populate members either or it will bomb since there is
//     no real structure being allocated. It's merely a pointer of type
//     DeltaRingLayout, so you can use the non-ptr members to point to values
//     in the image.
//
int get_ring_layout_from_image2(  const void      *i_imageIn,
                                  uint32_t        i_ddLevel,
                                  uint8_t         i_sysPhase,
                                  DeltaRingLayout **o_rs4RingLayout,
                                  void            **nextRing,
																	uint8_t 				i_xipSectionId)
{
  uint32_t  rc=0, rcLoc=0;
  uint8_t   bRingFound=0, bRingEOS=0;
  DeltaRingLayout *thisRingLayout=NULL, *nextRingLayout=NULL; //Pointers into memory mapped image. DO NOT CHANGE MEMBERS!
  uint32_t  sizeRings;
  SbeXipSection xipSection;
  void      *hostSection;
  
  SBE_XIP_ERROR_STRINGS(g_errorStrings);

  // Always first get the .rings stats from the TOC:
  // - .rings host address offset and
  // - .rings size
  //
  rc = sbe_xip_get_section( i_imageIn, i_xipSectionId, &xipSection);
  if (rc)   {
    MY_INF("ERROR : sbe_xip_get_section() failed: %s", SBE_XIP_ERROR_STRING(g_errorStrings, rc));
    MY_INF("Probable cause:");
    MY_INF("\tThe section (=SBE_XIP_SECTION_<xyz>=%i) was not found.",i_xipSectionId);
    return IMGBUILD_ERR_KEYWORD_NOT_FOUND;
  }
  if (xipSection.iv_offset==0)  {
    MY_INF("INFO : No ring data exists for the section ID = SBE_XIP_SECTION_<xyz> =%i\n",i_xipSectionId);
    return IMGBUILD_RING_SEARCH_NO_MATCH; // Implies exhaust search as well.
  }
  hostSection = (void*)((uintptr_t)i_imageIn + xipSection.iv_offset); 
  sizeRings = xipSection.iv_size;

  // On first call, get the base offset to the .rings section.
  // On subsequent calls, we're into the search for ddLevel and sysPhase, so use nextRing instead.
  //
  if (*nextRing==NULL)
    nextRingLayout = (DeltaRingLayout*)hostSection;
  else
    nextRingLayout = (DeltaRingLayout*)*nextRing;

  MY_DBG("hostSection = 0x%016llx",(uint64_t)hostSection);
  MY_DBG("sizeRings = %i", sizeRings);
  MY_DBG("nextRingLayout = 0x%016llx",(uint64_t)nextRingLayout);
  MY_DBG("i_ddLevel = 0x%02x",i_ddLevel);
  MY_DBG("i_sysPhase = %i",i_sysPhase);
  
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
        MY_DBG("Ring match found! \n");
      }
    }
    nextRingLayout = (DeltaRingLayout*)((uintptr_t)thisRingLayout + myRev32(thisRingLayout->sizeOfThis));
    *nextRing = (void*)nextRingLayout;
    if (nextRingLayout>=(DeltaRingLayout*)((uintptr_t)hostSection+sizeRings))  {
      bRingEOS = 1;
      *nextRing = NULL;
      MY_DBG("Ring search exhausted! \n");
    }
    
  }  // End of SEARCH.

  if (bRingFound)  {
    if (bRingEOS)
      rcLoc = IMGBUILD_RING_SEARCH_EXHAUST_MATCH;
    else
      rcLoc = IMGBUILD_RING_SEARCH_MATCH;
  }    
  else  {
    *nextRing = NULL;
    if (bRingEOS)
      return IMGBUILD_RING_SEARCH_NO_MATCH; // Implies exhaust search as well.
    else  {
      MY_INF("Messed up ring search. Check code and .rings content. Returning nothing.");
      return IMGBUILD_RING_SEARCH_MESS;
    }
  }

  *o_rs4RingLayout = thisRingLayout;

  // Check that the ring layout structure in the memory is 8-byte aligned:
  //   - The entryOffset address must be on an 8-byte boundary because the start of the 
  //     .rings section must be 8-byte aligned AND because the rs4Delta member is the 
  //     last member and which must itself be 8-byte aligned.  These two things together 
  //     means that both the beginning and end of the delta ring layout must be 8-byte
  //     aligned, and thus the whole block,i.e. sizeOfThis, must be 8-byte aligned.
  // Also check that the RS4 delta ring is 8-byte aligned.
  // Also check that the RS4 launcher is 8-byte aligned.
  //
  if (((uintptr_t)thisRingLayout-(uintptr_t)i_imageIn)%8 || 
      myRev32(thisRingLayout->sizeOfThis)%8 || 
      myRev64(thisRingLayout->entryOffset)%8 )  {
    MY_INF("Ring block or ring code section is not 8-byte aligned:");
    MY_INF("  thisRingLayout-imageIn = 0x%08x",(uint32_t)((uintptr_t)thisRingLayout-(uintptr_t)i_imageIn));
    MY_INF("  thisRingLayout->sizeOfThis = 0x%08x",myRev32(thisRingLayout->sizeOfThis));
    MY_INF("  thisRingLayout->entryOffset = 0x%016llx",(uint64_t)myRev64(thisRingLayout->entryOffset));
    return IMGBUILD_ERR_MISALIGNED_RING_LAYOUT;
  }

  if (*nextRing > (void*)((uintptr_t)hostSection + sizeRings))  {
    MY_INF("Book keeping got messed up during .rings search. .rings section does not appear aligned.");
    MY_INF("hostSection+sizeRings = 0x%016llx",(uint64_t)hostSection+sizeRings);
    MY_INF("nextRing = 0x%016llx",*(uint64_t*)nextRing);
    MY_INF("Continuing...");
  }

  return rcLoc;
}



// Function:  write_ring_block_to_image()
// Comments:
// - Appends an RS4 or WF ring block to the .rings section. It doesn't care
//   what type of ring it is. The only data that might be updated in the ring
//   block is the backItemPtr which is shared between both types of rings.
// - If ringName=NULL:  Assumes fwd ptr already exists in .ipl_data or .data 
//                      section. Back pointer in ring block is unchanged.
// - If ringName!=NULL: Adds fwd ptr to .ipl_data or .data section. Updates back
//                      pointer in input ring block.
// - idxVector:   Contains the index number of a vector array. This is pretty much
//                limited for ex_ chiplet IDs. It is ignored if ringName==NULL.
// - override:    Indicates if the ring is an override ring. It is ignored if 
//                ringName==NULL.
// - overridable: Indicates if a ring can be overridden. It is ignored if
//                ringName==NULL.
// - Assumes ring block is in BE format.
int write_ring_block_to_image(  void             *io_image,
                                const char       *i_ringName,
                                DeltaRingLayout  *i_ringBlock,
                                const uint8_t    i_idxVector,
                                const uint8_t    i_override,
                                const uint8_t    i_overridable,
                                const uint32_t   i_sizeImageMax,
                                const uint8_t    i_xipSectionId,
                                void             *i_bufTmp,
                                const uint32_t   i_sizeBufTmp)
{
  uint32_t   rc=0;
  SbeXipItem tocItem;
  uint32_t   offsetRingBlock=1;  // Initialize to anything but zero.
  uint32_t   sizeImage=0;
  uint64_t   ringPoreAddress=0,backPtr=0,fwdPtrCheck;

  SBE_XIP_ERROR_STRINGS(g_errorStrings);

  if (myRev64(i_ringBlock->entryOffset)%8)  {
    MY_ERR("Ring code section is not 8-byte aligned.");
    return IMGBUILD_ERR_MISALIGNED_RING_LAYOUT;
  }

  if (i_ringName)  {
    // Obtain the back pointer to the .data item, i.e. the location of the ptr associated with the 
    //   ring/var name in the TOC.
    //
    rc = sbe_xip_find( io_image, i_ringName, &tocItem);
    if (rc)  {
      MY_ERR("sbe_xip_find() failed w/rc=%i", rc);
      MY_ERR("Probable cause: Ring name (=%s) not found in image.", i_ringName);
      return IMGBUILD_ERR_KEYWORD_NOT_FOUND;
    } 
    i_ringBlock->backItemPtr = myRev64( tocItem.iv_address +
                                        i_idxVector*8*(1+i_overridable) +
                                        8*i_override*i_overridable );
  }

  //
  // Insert ring block to .rings or .dcrings section.
  // ------
  
  // Temporarily copy .dcrings section if inserting into .rings section.
  SbeXipSection xipSectionDcrings;
  void          *hostSectionDcrings=NULL;
  
  if (i_xipSectionId==SBE_XIP_SECTION_RINGS) {
    rc = sbe_xip_get_section(io_image, SBE_XIP_SECTION_DCRINGS, &xipSectionDcrings);
    if (rc)  {
      MY_ERR("_get_section(.dcrings...) failed with rc=%i  ",rc);
      return IMGBUILD_ERR_GET_SECTION;
    }
    if (!(xipSectionDcrings.iv_size==0 && xipSectionDcrings.iv_offset==0))  {
      hostSectionDcrings = (void*)((uint64_t)io_image + (uint64_t)xipSectionDcrings.iv_offset);
      if (xipSectionDcrings.iv_size<=i_sizeBufTmp)  {
        memcpy(i_bufTmp, hostSectionDcrings, (size_t)xipSectionDcrings.iv_size);
      }
      else  {
        MY_ERR("Size of .dcrings section (=%i) exceeds buffer size (=%i).  ",
                xipSectionDcrings.iv_size, i_sizeBufTmp);
        return IMGBUILD_BUFFER_TOO_SMALL;
      }
      rc = sbe_xip_delete_section(io_image, SBE_XIP_SECTION_DCRINGS);
      if (rc)  {
        MY_ERR("_delete_section(.dcrings...) failed w/rc=%i  ",rc);
        return IMGBUILD_ERR_SECTION_DELETE;
      }
    }
  }
  
  rc = sbe_xip_append(io_image, 
                      i_xipSectionId, 
                      (void*)i_ringBlock,
                      myRev32(i_ringBlock->sizeOfThis),
                      //don't allow ring append to use up space the .dcrings needs
                      i_sizeImageMax - xipSectionDcrings.iv_size,
                      &offsetRingBlock);
  if (rc)   {
    MY_ERR("sbe_xip_append() failed: %s  ", SBE_XIP_ERROR_STRING(g_errorStrings, rc));
    sbe_xip_image_size(io_image,&sizeImage);
    MY_ERR("Input image size: %i  ", sizeImage);
    MY_ERR("Max image size allowed: %i  ", i_sizeImageMax);
    if (rc==SBE_XIP_WOULD_OVERFLOW) {
      return rc;
    } else {
      return IMGBUILD_ERR_APPEND;
    }
  }
  
  // Re-append .dcrings section if inserting into .rings section.
  if (i_xipSectionId==SBE_XIP_SECTION_RINGS) {
    if (!(xipSectionDcrings.iv_size==0 && xipSectionDcrings.iv_offset==0))  {
      rc = sbe_xip_append(io_image,
                          SBE_XIP_SECTION_DCRINGS,
                          i_bufTmp,
                          xipSectionDcrings.iv_size,
                          i_sizeImageMax,
                          NULL);
      if (rc)  {
        MY_ERR("_append(.dcrings...) failed: w/rc=%i  ", rc);
        if (rc==SBE_XIP_WOULD_OVERFLOW) {
          return rc;
        } else {
          return IMGBUILD_ERR_APPEND;
        }
      }
    }
  }

  // ...get new image size and test if successful update.
  rc = sbe_xip_image_size( io_image, &sizeImage);
  MY_DBG("Updated image size (after append): %i",sizeImage);
  if (rc)   {
    MY_ERR("sbe_xip_image_size() of output image failed: %s", SBE_XIP_ERROR_STRING(g_errorStrings, rc));
    return IMGBUILD_ERR_XIP_MISC;
  }
  rc = sbe_xip_validate( io_image, sizeImage);
  if (rc)   {
    MY_ERR("sbe_xip_validate() of output image failed: %s", SBE_XIP_ERROR_STRING(g_errorStrings, rc));
    return IMGBUILD_ERR_XIP_MISC;
  }
  
  // Update forward pointer associated with the ring/var name + any override offset.
	// (Note, we ONLY do this for .rings as we can't have forward ptrs to [non-scannable]
	//    rings in the .dcrings section.)
  //
  // Convert the ring offset to an PORE address
	if (i_xipSectionId==SBE_XIP_SECTION_RINGS)  {
	  rc = sbe_xip_section2pore(io_image, i_xipSectionId, offsetRingBlock, &ringPoreAddress);
	  MY_DBG("fwdPtr=0x%016llx", ringPoreAddress);
	  if (rc)   {
	    MY_ERR("sbe_xip_section2pore() failed: %s", SBE_XIP_ERROR_STRING(g_errorStrings, rc));
	    return IMGBUILD_ERR_XIP_MISC;
	  }
	}
	else  {
    MY_DBG("Inserting Gptr overlay ring into .dcrings section and ensuring forward ptr is cleared. ");
		// We can not have forward ptr to [non-scannanble] rings in the .dcrings section.
		ringPoreAddress = 0;
  }
  
  // Now, update the forward pointer, making sure that it's zero for .dcrings section.
  //
  // First, retrieve the ring block's backPtr which tells us where the fwd ptr
  // is located.
  //
  // Note that the fwd ptr's addr is the old variable/ring name's pointer location
  // from the ref image. DO NOT add an 8-byte offset if override ring. The 
  // backItemPtr in the input ring block already has this from the ref image, 
  // and it shouldn't have changed after having been ported over to an 
  // IPL/Seeprom image.
  backPtr = myRev64(i_ringBlock->backItemPtr);
  MY_DBG("backPtr = 0x%016llx ",  backPtr);
  // Second, put the ring's Pore addr into the location pointed to by the back ptr.
  rc = sbe_xip_write_uint64(  io_image, 
                              backPtr,
                              ringPoreAddress);
  // Third, let's read it back to make sure we're OK a little further down.
  rc = rc+sbe_xip_read_uint64(io_image,
                              backPtr,
                              &fwdPtrCheck);
  if (rc)  {
    MY_ERR("sbe_xip_[write,read]_uint64() failed: %s", SBE_XIP_ERROR_STRING(g_errorStrings, rc));
    return IMGBUILD_ERR_XIP_MISC;
  }
  
  // Check for pointer mess.
  if (fwdPtrCheck!=ringPoreAddress || backPtr!=myRev64(i_ringBlock->backItemPtr))  {
    MY_ERR("Forward or backward pointer mess. Check code."); 
    MY_ERR("fwdPtr       =0x%016llx",ringPoreAddress);
    MY_ERR("fwdPtrCheck  =0x%016llx",fwdPtrCheck);
    MY_ERR("layout bckPtr=0x%016llx",myRev64(i_ringBlock->backItemPtr));
    MY_ERR("backPtr      =0x%016llx",backPtr);
    return IMGBUILD_ERR_FWD_BACK_PTR_MESS;
  }
  MY_DBG("fwdPtr = 0x%016llx ",fwdPtrCheck);
  // ...test if successful update.
  rc = sbe_xip_validate( io_image, sizeImage);
  if (rc)   {
    MY_ERR("sbe_xip_validate() of output image failed: %s", SBE_XIP_ERROR_STRING(g_errorStrings, rc));
    MY_ERR("Probable cause: sbe_xip_write_uint64() updated at the wrong address (=0x%016llx)",
      myRev64(i_ringBlock->backItemPtr));
    return IMGBUILD_ERR_XIP_MISC;
  }
  
  return IMGBUILD_SUCCESS;
}


// calc_ring_layout_entry_offset()
// - Calculates the entry offset from the beginning of the ring block to the
//   first line of inline Pore code.
//
uint64_t calc_ring_layout_entry_offset( 
                              uint8_t  i_typeRingLayout, // 0: RS4  1: WF
                              uint32_t i_sizeMetaData )  // Meta data size.
{
  DeltaRingLayout ringBlock;
  if (i_typeRingLayout==0)  {
    // RS4 ring block.
    ringBlock.entryOffset = (uint64_t)(
                            sizeof(ringBlock.entryOffset) +
                            sizeof(ringBlock.backItemPtr) +
                            sizeof(ringBlock.sizeOfThis) +
                            sizeof(ringBlock.sizeOfMeta) +
                            sizeof(ringBlock.ddLevel) +
                            sizeof(ringBlock.sysPhase) +
                            sizeof(ringBlock.override) +
                            sizeof(ringBlock.reserved1) +
                            sizeof(ringBlock.reserved2) +
                            myByteAlign(8, i_sizeMetaData) ); // 8-byte align RS4 launch.
  }
  else  
  if (i_typeRingLayout==1)  {
    // Wiggle-flip ring block.
    ringBlock.entryOffset = (uint64_t)(
                            sizeof(ringBlock.entryOffset) +
                            sizeof(ringBlock.backItemPtr) +
                            sizeof(ringBlock.sizeOfThis) +
                            sizeof(ringBlock.sizeOfMeta) +
                            myByteAlign(8, i_sizeMetaData) ); // 8-byte align WF prg.
  }
  else
    return MAX_UINT64_T;
    
  return ringBlock.entryOffset;
}



// Function:  over_write_ring_data_in_image()
// Comments:
// - Overwrites RS4 or WF ring block data in the .rings section. It doesn't care
//   what type of ring it is. The only data that might be updated in the ring
//   block is the sizeOfThis which is shared between both types of rings.
// - If ringName=NULL:  ? 
// - If ringName!=NULL: ?
// - ringData:    The actual RS4 ring data, incl container, or the WF program.
// - sizeRingData: Byte size of ring data. This includes RS4 launch in case of RS4.
// - idxVector:   Contains the index number of a vector array. This is pretty much
//                limited for ex_ chiplet IDs. It is ignored if ringName==NULL.
// - override:    Indicates if the ring is an override ring. It is ignored if 
//                ringName==NULL.
// - overridable: Indicates if a ring can be overridden. It is ignored if
//                ringName==NULL.
int over_write_ring_data_in_image(  void            *io_image,
                                    const char      *i_ringName,
                                    const void      *i_ringData,    // WF or RS4
                                    const uint32_t  i_sizeRingData, // Byte size
                                    const uint8_t   i_idxVector,
                                    const uint8_t   i_override,
                                    const uint8_t   i_overridable )
{
  uint32_t   rc=0;
  SbeXipItem tocItem;
  uint32_t   sizeImage=0;
  void       *hostVectorBase, *hostVectorThis;
  DeltaRingLayout *hostRingBlock;
  void       *hostRingData;

  // Test if valid image to start with since we're going to mess with it w/o using 
  //   sbe_xip functions.
  sbe_xip_image_size( io_image, &sizeImage);
  rc = sbe_xip_validate( io_image, sizeImage);
  if (rc)  {
    MY_ERR("sbe_xip_validate() failed w/rc=%i\n", rc);
    return IMGBUILD_ERR_XIP_MISC;
  }

  // Calculate the host location of the ring.
  //
  rc = sbe_xip_find( io_image, i_ringName, &tocItem);
  if (rc)  {
    MY_ERR("sbe_xip_find() failed w/rc=%i", rc);
    MY_ERR("Probable cause: Ring name (=%s) not found in image.", i_ringName);
    return IMGBUILD_ERR_KEYWORD_NOT_FOUND;
  }
  sbe_xip_pore2host( io_image, tocItem.iv_address, &hostVectorBase);
  hostVectorThis = (void*) ( (uint64_t)hostVectorBase + 
                             i_idxVector*8*(1+i_overridable) +
                             8*i_override*i_overridable );
  uint64_t tmp1 = (*(uintptr_t*)hostVectorThis);
  sbe_xip_pore2host( io_image, tmp1, (void**)&hostRingBlock);
  hostRingData = (void*)( (uint64_t)hostRingBlock + hostRingBlock->entryOffset );

  // Over write ringData onto existing ring data content in image.
  //
  memcpy(hostRingData, i_ringData, i_sizeRingData);
  
  // Update size of new ring block.
  //
  hostRingBlock->sizeOfThis = hostRingBlock->entryOffset + i_sizeRingData;
  
  // Test if successful update.
  rc = sbe_xip_validate( io_image, sizeImage);
  if (rc)   {
    MY_ERR("sbe_xip_validate() failed w/rc=%i\n", rc);
    MY_ERR("We really screwed up the image here. This is a coding error. Here's some data:\n");
    MY_ERR("io_image       = 0x%016llx\n",(uint64_t)io_image);
    MY_ERR("hostVectorBase = 0x%016llx\n",(uint64_t)hostVectorBase);
    MY_ERR("hostVectorThis = 0x%016llx\n",(uint64_t)hostVectorThis);
    MY_ERR("hostRingBlock  = 0x%016llx\n",(uint64_t)hostRingBlock);
    MY_ERR("hostRingData   = 0x%016llx\n",(uint64_t)hostRingData);
    return IMGBUILD_ERR_XIP_MISC;
  }
  
  MY_DBG("Dumping ring layout of over-writen ring:");
  MY_DBG("  entryOffset     = 0x%016llx",myRev64(hostRingBlock->entryOffset));
  MY_DBG("  backItemPtr     = 0x%016llx",myRev64(hostRingBlock->backItemPtr));
  MY_DBG("  sizeOfThis      = %i",myRev32(hostRingBlock->sizeOfThis));
  MY_DBG("  sizeOfMeta      = %i",myRev32(hostRingBlock->sizeOfMeta));
  MY_DBG("  ddLevel         = %i",myRev32(hostRingBlock->ddLevel));
  MY_DBG("  sysPhase        = %i",hostRingBlock->sysPhase);
  MY_DBG("  override        = %i",hostRingBlock->override);
  MY_DBG("  reserved1+2     = %i",hostRingBlock->reserved1|hostRingBlock->reserved2);

	
  return IMGBUILD_SUCCESS;
}



}
