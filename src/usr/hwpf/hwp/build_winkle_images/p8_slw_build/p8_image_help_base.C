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
// $Id: p8_image_help_base.C,v 1.6 2013/01/02 03:01:28 cmolsen Exp $
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
int get_ring_layout_from_image2(	const void	*i_imageIn,
																	uint32_t		i_ddLevel,
																	uint8_t			i_sysPhase,
																	DeltaRingLayout	**o_rs4RingLayout,
																	void				**nextRing)
{
	uint32_t rc=0, rcLoc=0;
	uint8_t bRingFound=0, bRingEOS=0;
	DeltaRingLayout *thisRingLayout, *nextRingLayout; //Pointers into memory mapped image. DO NOT CHANGE MEMBERS!
	uint32_t sizeInitf;
	SbeXipSection hostSection;
	void		 *initfHostAddress0;
	
	SBE_XIP_ERROR_STRINGS(g_errorStrings);

	// Always first get the .initf stats from the TOC:
	// - .initf host address offset and
	// - .initf size
	//
  rc = sbe_xip_get_section( i_imageIn, SBE_XIP_SECTION_RINGS, &hostSection);
  if (rc)   {
      MY_INF("ERROR : sbe_xip_get_section() failed: %s", SBE_XIP_ERROR_STRING(g_errorStrings, rc));
			MY_INF("Probable cause:");
			MY_INF("\tThe section (=SBE_XIP_SECTION_RINGS=%i) was not found.",SBE_XIP_SECTION_RINGS);
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
			MY_INF("Messed up ring search. Check code and .rings content. Returning nothing.");
			return DSLWB_RING_SEARCH_MESS;
		}
	}

  *o_rs4RingLayout = thisRingLayout;

	// Check that the ring layout structure in the memory is 8-byte aligned. This must be so because:
	//   - The entryOffset address must be on an 8-byte boundary because the start of the .initf ELF section must
	//     be 8-byte aligned AND because the rs4Delta member is the last member and which must itself be 8-byte aligned.
	//   - These two things together means that both the beginning and end of the delta ring layout must be 8-byte
	//     aligned, and thus the whole block,i.e. sizeOfThis, must be 8-byte aligned.
	// Also check that the RS4 delta ring is 8-byte aligned.
	// Also check that the RS4 launcher is 8-byte aligned.
	//
	if (((uintptr_t)thisRingLayout-(uintptr_t)i_imageIn)%8 || 
			myRev32(thisRingLayout->sizeOfThis)%8 || 
			myRev64(thisRingLayout->entryOffset)%8 )  {
		MY_INF("Ring block or ring code section is not 8-byte aligned:");
		MY_INF("  thisRingLayout-imageIn = %i",(uintptr_t)thisRingLayout-(uintptr_t)i_imageIn);
		MY_INF("  thisRingLayout->sizeOfThis = %i",myRev32(thisRingLayout->sizeOfThis));
		MY_INF("  thisRingLayout->entryOffset = %i",(uint32_t)myRev64(thisRingLayout->entryOffset));
		return IMGBUILD_ERR_MISALIGNED_RING_LAYOUT;
	}

	if (*nextRing > (void*)((uintptr_t)initfHostAddress0 + sizeInitf))  {
		MY_INF("Book keeping got messed up during .initf search. Initf section does not appear aligned.");
		MY_INF("initfHostAddress0+sizeInitf = 0x%016llx",(uint64_t)initfHostAddress0+sizeInitf);
		MY_INF("nextRing = %i",*(uint32_t*)nextRing);
		MY_INF("Continuing...");
	}

	return rcLoc;
}



// Function:  write_ring_block_to_image()
// Comments:
// - Appends an RS4 or WF ring block to the .rings section. It doesn't care
//   what type of ring it is. The only data that might be updated in the ring
//   block is the back pointer which is shared between both types of rings.
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
int write_ring_block_to_image(	void             *io_image,
                                const char       *i_ringName,
																DeltaRingLayout  *i_ringBlock,
																const uint8_t    i_idxVector,
																const uint8_t    i_override,
																const uint8_t    i_overridable,
																const uint32_t   i_sizeImageMax)
{
	uint32_t   rc=0;
	SbeXipItem tocItem;
	uint32_t   offsetRingBlock=1;  // Initialize to anything but zero.
	uint32_t   sizeImage=0;
	uint64_t   ringPoreAddress=0,backPtr=0,fwdPtrCheck;

	SBE_XIP_ERROR_STRINGS(g_errorStrings);

	if (myRev64(i_ringBlock->entryOffset)%8)  {
		MY_INF("Ring code section is not 8-byte aligned.");
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
	  i_ringBlock->backItemPtr = myRev64(	tocItem.iv_address + 
																				i_idxVector*8*(1+i_overridable) +
																				8*i_override*i_overridable );
  }

	// Append ring block to .rings section.
	//
	rc = sbe_xip_append(io_image, 
											SBE_XIP_SECTION_RINGS, 
											(void*)i_ringBlock,
											myRev32(i_ringBlock->sizeOfThis),
											i_sizeImageMax,
											&offsetRingBlock);
  if (rc)   {
    MY_INF("sbe_xip_append() failed: %s", SBE_XIP_ERROR_STRING(g_errorStrings, rc));
    return IMGBUILD_ERR_APPEND;
  }
	// ...get new image size and test if successful update.
	rc = sbe_xip_image_size( io_image, &sizeImage);
	MY_DBG("Updated image size (after append): %i",sizeImage);
  if (rc)   {
    MY_INF("sbe_xip_image_size() of output image failed: %s", SBE_XIP_ERROR_STRING(g_errorStrings, rc));
    return IMGBUILD_ERR_XIP_MISC;
  }
  rc = sbe_xip_validate( io_image, sizeImage);
  if (rc)   {
    MY_INF("sbe_xip_validate() of output image failed: %s", SBE_XIP_ERROR_STRING(g_errorStrings, rc));
    return IMGBUILD_ERR_XIP_MISC;
  }
	
	// Update forward pointer associated with the ring/var name + any override offset.
	//
	// Convert the ring offset (wrt .rings address) to an PORE address
	rc = sbe_xip_section2pore(io_image, SBE_XIP_SECTION_RINGS, offsetRingBlock, &ringPoreAddress);
  MY_DBG("fwdPtr=0x%016llx", ringPoreAddress);
  if (rc)   {
    MY_INF("sbe_xip_section2pore() failed: %s", SBE_XIP_ERROR_STRING(g_errorStrings, rc));
    return IMGBUILD_ERR_XIP_MISC;
  }
  
	// Now, update the forward pointer.
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
  MY_DBG("backPtr = 0x%016llx",	backPtr);
  // Second, put the ring's Pore addr into the location pointed to by the back ptr.
	rc = sbe_xip_write_uint64(	io_image, 
															backPtr,
															ringPoreAddress);
  // Third, let's read it back to make sure we're OK a little further down.
	rc = rc+sbe_xip_read_uint64(io_image,
															backPtr,
															&fwdPtrCheck);
	if (rc)  {
		MY_INF("sbe_xip_[write,read]_uint64() failed: %s", SBE_XIP_ERROR_STRING(g_errorStrings, rc));
		return IMGBUILD_ERR_XIP_MISC;
	}
  
  // Check for pointer mess.
	if (fwdPtrCheck!=ringPoreAddress || backPtr!=myRev64(i_ringBlock->backItemPtr))  {
	  MY_INF("Forward or backward pointer mess. Check code."); 
	  MY_INF("fwdPtr       =0x%016llx",ringPoreAddress);
	  MY_INF("fwdPtrCheck  =0x%016llx",fwdPtrCheck);
	  MY_INF("layout bckPtr=0x%016llx",myRev64(i_ringBlock->backItemPtr));
	  MY_INF("backPtr      =0x%016llx",backPtr);
		return IMGBUILD_ERR_FWD_BACK_PTR_MESS;
	}
	// ...test if successful update.
  rc = sbe_xip_validate( io_image, sizeImage);
  if (rc)   {
    MY_INF("sbe_xip_validate() of output image failed: %s", SBE_XIP_ERROR_STRING(g_errorStrings, rc));
		MY_INF("Probable cause: sbe_xip_write_uint64() updated at the wrong address (=0x%016llx)",
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



}
