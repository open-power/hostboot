/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_slw_build/p8_pore_table_gen_api.C $ */
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
// $Id: p8_pore_table_gen_api.C,v 1.11 2012/10/04 02:39:07 cmolsen Exp $
//
/*------------------------------------------------------------------------------*/
/* *! (C) Copyright International Business Machines Corp. 2012                  */
/* *! All Rights Reserved -- Property of IBM                                    */
/* *! *** IBM Confidential ***                                                  */
/*------------------------------------------------------------------------------*/
/* *! TITLE :       p8_pore_table_gen_api.C                                     */
/* *! DESCRIPTION : PORE SLW table generaion APIs                               */
/* *! OWNER NAME :  Michael Olsen            Email: cmolsen@us.ibm.com          */
/* *! USAGE :       To build for PHYP command-line -                            */
//                  buildecmdprcd_cmo  -d "sbe_xip_image.c,pore_inline_assembler.c"  p8_pore_table_gen_api.C
//                  Other usages:
//                  - Passing the DYNAMIC_RAM_TABLE PPD, gen_cpureg() will build
//                    up the ramming table in a space saving way, occupying only
//                    as much space as needed in the [pre-defined sized] .slw
//                    section. This implementation, even though presently not
//                    safe due to race condition to the ramming vector, may come
//                    in handy at a later stage.
//
/* *! COMMENTS :   Start file: p7p_pore_api.c                                   */
//
/*------------------------------------------------------------------------------*/

#define __P8_PORE_TABLE_GEN_API_C
#include <HvPlicModule.H>
#include <p8_pore_api_custom.h>
#include <p8_pore_table_gen_api.H>
#include <p8_delta_scan_rw.h>

/*
// io_image - pointer to SLW image
// i_sizeImage - size of SLW image
// i_regName - unswizzled enum SPR value (NOT a name)
// i_regData - data to write
// i_coreIndex - core ID
// i_threadIndex - thread to operate on, API changes thread num to 0 for shared SPRs, except for HRMOR which
//                 is always done on thread 3 to be the last SPR
*/
uint32_t p8_pore_gen_cpureg(  void      *io_image,
                              uint32_t  i_sizeImage,
                              uint32_t  i_regName, 
                              uint64_t  i_regData, 
                              uint32_t  i_coreId,   // [0:15]
                              uint32_t  i_threadId)
{
  uint32_t  rc=0, rcLoc=0, iCount=0;
  int       i=0, iReg=-1;
  uint32_t  sizeImageIn=0;
	uint64_t  xipSlwRamSection;
  void      *hostSlwRamSection;
  uint64_t  xipRamTableThis;
  void      *hostRamVector;
  void      *hostRamTableThis;
  void      *hostRamEntryThis, *hostRamEntryNext;
  uint8_t   bNewTable=0, bFound=0;
  uint8_t   bEntryEnd=1, headerType=0;
  SbeXipSection  xipSection;
  SbeXipItem    xipTocItem;
  RamTableEntry ramEntryThis, *ramEntryNext;
  uint32_t  sprSwiz=0;
#ifdef DYNAMIC_RAM_TABLE
  uint32_t  iCore=0, sizeTableThis=0, sizeTableAll=0;
  void      *hostRamEntryFirstAll; // First entry of all Ram tables. 
  void      *hostRamEntryLastAll;  // Last entry of all Ram tables. 
  uint64_t  xipRamTableNext;
	void      *hostRamTableNext;
#endif
  
	// -------------------------------------------------------------------------
  // Validate Ramming parameters.
  //
  // ...check register value
  bFound = 0;
  for (i=0;i<SLW_SPR_REGS_SIZE;i++)  {
    if (i_regName==SLW_SPR_REGS[i].value)  {
      bFound = 1;
      iReg = i;
      break;
    }
  }
  if (!bFound)  {
    MY_ERR("Register value = %i is not supported.\n",i_regName);
    MY_ERR("The following registers are supported:\n");
    for (i=0;i<SLW_SPR_REGS_SIZE;i++)
      MY_ERR("\t(%s,%i)\n",SLW_SPR_REGS[i].name,SLW_SPR_REGS[i].value);
    rcLoc = 1;
  }
  // ...check core ID
  if (i_coreId>=SLW_MAX_CORES)  {
    MY_ERR("Core ID = %i is not within valid range of [0;%i]\n",i_coreId,SLW_MAX_CORES-1);
    rcLoc = 1;
  }
  // ...check thread ID
  if (i_threadId>=SLW_CORE_THREADS)  {
    MY_ERR("Thread ID = %i is not within valid range of [0;%i]\n",i_threadId,SLW_CORE_THREADS-1);
    rcLoc = 1;
  }
  if (rcLoc)
    return IMGBUILD_ERR_RAM_INVALID_PARM;
  rcLoc = 0;
  
  // -------------------------------------------------------------------------
  // Validate image and get pointer to SLW section.
  //
  // ...validate
  rc = sbe_xip_validate( io_image, i_sizeImage);
  if (rc)  {
    MY_ERR("Invalid image.\n");
    return IMGBUILD_INVALID_IMAGE;
  }
  // ...size check
  sbe_xip_image_size( io_image, &sizeImageIn);
  if (sizeImageIn!=i_sizeImage)  {
    MY_ERR("Supplied image size (=%i) differs from size in image header (=%i).\n",
              i_sizeImage, sizeImageIn);
    return IMGBUILD_IMAGE_SIZE_MISMATCH;
  }
  // ...get pointer to SLW section where Ram table resides
  rc = sbe_xip_get_section( io_image, SBE_XIP_SECTION_SLW, &xipSection);
  if (rc)  {
    MY_ERR("Probably invalid section name for SBE_XIP_SECTION_SLW.\n");
    return IMGBUILD_ERR_GET_SECTION;
  }
  hostSlwRamSection = (void*)((uint8_t*)io_image + xipSection.iv_offset);
  sbe_xip_host2pore( io_image, hostSlwRamSection, &xipSlwRamSection);
      
  // -------------------------------------------------------------------------
  // Cross check SPR register and table defines
  //
  if (SLW_SPR_REGS_SIZE!=(SLW_MAX_CPUREGS_CORE+SLW_MAX_CPUREGS_THREADS))  {
    MY_ERR("Defines in *.H header file not in sync.\n");
    return IMGBUILD_ERR_RAM_HDRS_NOT_SYNCED;
  }
  if (xipSection.iv_size!=SLW_RAM_TABLE_SIZE+SLW_SCOM_TABLE_SIZE_ALL)  {
    MY_ERR("SLW table size in *.H header file differs from SLW section size in image.\n"); 
    MY_ERR("Check code or image version.\n");
    return IMGBUILD_ERR_RAM_HDRS_NOT_SYNCED;
  }
  // -------------------------------------------------------------------------
  // Summarize parameters and checking results.
  //
  MY_INF("Input parameter checks - OK\n");
  MY_INF("\tRegister  = (%s,%i)\n",SLW_SPR_REGS[iReg].name,SLW_SPR_REGS[iReg].value);
  MY_INF("\tCore ID   = %i\n",i_coreId);
  MY_INF("\tThread ID = %i\n",i_threadId);
  MY_INF("Image validation and size checks - OK\n");
  MY_INF("\tImage size      = %i\n",i_sizeImage);
  MY_INF("\tSLW section size=  %i\n",xipSection.iv_size);
  
  // -------------------------------------------------------------------------
  // Locate RAM vector and locate RAM table associated with "This" core ID.
  //
  rc = sbe_xip_find( io_image, SLW_HOST_REG_VECTOR_TOC_NAME, &xipTocItem);
  if (rc)  {
    MY_ERR("Probably invalid key word for SLW_HOST_REG_VECTOR_TOC_NAME.\n");
    return IMGBUILD_ERR_KEYWORD_NOT_FOUND;
  }
  sbe_xip_pore2host( io_image, xipTocItem.iv_address, &hostRamVector);
  xipRamTableThis = myRev64(*((uint64_t*)hostRamVector + i_coreId));
  if (xipRamTableThis)  {
    sbe_xip_pore2host( io_image, xipRamTableThis, &hostRamTableThis);
    bNewTable = 0;
  }
  else  {
    hostRamTableThis = NULL;
    bNewTable = 1;
  }
  
#ifdef DYNAMIC_RAM_TABLE
  hostRamEntryFirstAll = hostSlwRamSection;
  hostRamEntryLastAll  = hostRamEntryFirstAll;

  // -------------------------------------------------------------------------
  // Walk the RAM vector and RAM tables to 
  // - determine size of present tables, sizeTableAll - we'll need it when/if shifting entries forward
  // - check for RAM table overflow.
  //
  sizeTableAll = 0;
  for (iCore=0; iCore<SLW_MAX_CORES; iCore++)  {
    xipRamTableNext = myRev64(*((uint64_t*)hostRamVector + iCore));
    if (xipRamTableNext)
      sbe_xip_pore2host( io_image, xipRamTableNext, &hostRamTableNext);
    else
      hostRamTableNext = NULL;
    sizeTableThis = 0;
    if (hostRamTableNext)  {
      hostRamEntryNext = hostRamTableNext;
      ramEntryNext = (RamTableEntry*)hostRamEntryNext;
      sizeTableThis = sizeTableThis + XIPSIZE_RAM_ENTRY;
      while ((myRev32(ramEntryNext->header) & RAM_HEADER_END_MASK_C)==0)  {
        hostRamEntryNext = (void*)((uint8_t*)hostRamEntryNext + XIPSIZE_RAM_ENTRY);
        ramEntryNext = (RamTableEntry*)hostRamEntryNext;
        sizeTableThis = sizeTableThis + XIPSIZE_RAM_ENTRY;
      }
      // Keep searching for last entry.
      if ((uint64_t)hostRamEntryLastAll<(uint64_t)hostRamEntryNext)
        hostRamEntryLastAll = hostRamEntryNext;
      // Check hostRamTableThis for sizeTableThis>SLW_MAX_CPUREGS_OPS
      if ((uint64_t)hostRamTableNext==(uint64_t)hostRamTableThis)  {
        if ((sizeTableThis/XIPSIZE_RAM_ENTRY+1)>SLW_MAX_CPUREGS_OPS)  {
          MY_ERR("RAM table is full. Max %i entries allowed.\n",SLW_MAX_CPUREGS_OPS);
          return IMGBUILD_ERR_RAM_TABLE_FULL;
        }
      }
      // Update total table size.
      sizeTableAll = sizeTableAll + sizeTableThis;
      // Increment RAM vector entries, if needed, but not if a new table which goes at the end.
      // (This must be done at this stage while walking everything.)
      if (!bNewTable && ((uint64_t)hostRamTableNext>(uint64_t)hostRamTableThis))  {
        sbe_xip_host2pore( io_image, (void*)((uint8_t*)hostRamTableNext + XIPSIZE_RAM_ENTRY), &xipRamTableNext);
        *((uint64_t*)hostRamVector + iCore) = myRev64(xipRamTableNext);
      }
    }
  }
#else
  // -------------------------------------------------------------------------
  // We don't need to walk the "this" RAM table to check for RAM table 
	//   as this is done further down during insertion of the entry.
  //
#endif
  
  
  // -------------------------------------------------------------------------
  // Walk the "This" core ID's RAM table to 
  // - determine insertion point, hostRamEntryThis, of new RAM entry
  //
  if (bNewTable)  {
#ifdef DYNAMIC_RAM_TABLE
    // Append to end of table.
    hostRamTableThis = (void*)((uint8_t*)hostRamEntryFirstAll + sizeTableAll);
    hostRamEntryThis = hostRamTableThis;
    // ...update RAM vector (since it is currently NULL)
    sbe_xip_host2pore( io_image, hostRamTableThis, &xipRamTableThis);
    *((uint64_t*)hostRamVector + i_coreId) = myRev64(xipRamTableThis);
    bEntryEnd = 1;
#else
    // Append to beginning of agreed upon static position for this coreId.
    hostRamTableThis = (void*)((uint8_t*)hostSlwRamSection + 
		                                                  (uint32_t)(SLW_RAM_TABLE_SIZE/SLW_MAX_CORES)*i_coreId );
    hostRamEntryThis = hostRamTableThis;
    // ...update RAM vector (since it is currently NULL)
    *((uint64_t*)hostRamVector + i_coreId) = myRev64( xipSlwRamSection + 
		                                                  (uint32_t)(SLW_RAM_TABLE_SIZE/SLW_MAX_CORES)*i_coreId );
    bEntryEnd = 1;
#endif
  }
  else  {
    // Insert at end of existing table.
    hostRamEntryNext = hostRamTableThis;
    ramEntryNext = (RamTableEntry*)hostRamEntryNext;
    iCount = 1;
		while ((myRev32(ramEntryNext->header) & RAM_HEADER_END_MASK_C)==0)  {
			if (iCount>=SLW_MAX_CPUREGS_OPS)  {
				MY_ERR("Bad table! Header end bit not found and RAM table full (=%i entries).\n",SLW_MAX_CPUREGS_OPS);
        return IMGBUILD_ERR_RAM_TABLE_END_NOT_FOUND;
			}
      hostRamEntryNext = (void*)((uint8_t*)hostRamEntryNext + XIPSIZE_RAM_ENTRY);
      ramEntryNext = (RamTableEntry*)hostRamEntryNext;
			iCount++;
    }
		if (iCount<SLW_MAX_CPUREGS_OPS)  {
	    // ...zero out previous END bit in header
	    if ((myRev32(ramEntryNext->header) & RAM_HEADER_END_MASK_C))  {
	      ramEntryNext->header = ramEntryNext->header & myRev32(~RAM_HEADER_END_MASK_C);
	    }
	    else  {
	      MY_ERR("We should never get here. Check code. Dumping data:\n");
	      MY_ERR("myRev32(ramEntryNext->header) = 0x%08x\n",myRev32(ramEntryNext->header));
	      MY_ERR("RAM_HEADER_END_MASK_C         = 0x%08x\n",RAM_HEADER_END_MASK_C);
	      return IMGBUILD_ERR_RAM_CODE;
	    }
		}
		else  {
			MY_ERR("RAM table is full. Max %i entries allowed.\n",SLW_MAX_CPUREGS_OPS);
      return IMGBUILD_ERR_RAM_TABLE_FULL;
		}
    // ...this is the spot for the new entry
    hostRamEntryThis = (void*)((uint8_t*)hostRamEntryNext + XIPSIZE_RAM_ENTRY);
    bEntryEnd = 1;
  }

#ifdef DYNAMIC_RAM_TABLE
  // -------------------------------------------------------------------------
  // Shift RAM entries forward by XIPSIZE_RAM_ENTRY
  // (Need to do this before inserting new RAM entry at hostRamEntryThis.)
  //
  if (!bNewTable)
    for ( ramEntryNext=(RamTableEntry*)hostRamEntryLastAll; 
          ramEntryNext>=(RamTableEntry*)hostRamEntryThis; 
          ramEntryNext--  )  {
      *(ramEntryNext+1) = *ramEntryNext;
      if ((ramEntryNext+1)->instr!=ramEntryNext->instr)  {
        MY_ERR("Incorrect shifting of table entries. Check code.\n");
        return IMGBUILD_ERR_RAM_CODE;
      }
    }
#endif

  // -------------------------------------------------------------------------
  // Create, or modify, the RAM entry.
  //
	if (i_regName==P8_MSR_MSR)  {
  	// ...do the MSR header
  	headerType = 0x1; // MTMSRD header.
  	ramEntryThis.header = ( ((uint32_t)bEntryEnd)  << RAM_HEADER_END_START_C    & RAM_HEADER_END_MASK_C )    |
  	                      ( ((uint32_t)headerType) << RAM_HEADER_TYPE_START_C   & RAM_HEADER_TYPE_MASK_C );
  	// ...do the MSR instr
		ramEntryThis.instr =  RAM_MTMSRD_INSTR_TEMPL_C;
	}
	else  {
  	// ...do the SPR header
  	headerType = 0x0; // MTSPR header.
  	ramEntryThis.header = ( ((uint32_t)bEntryEnd)  << RAM_HEADER_END_START_C    & RAM_HEADER_END_MASK_C )    |
  	                      ( ((uint32_t)headerType) << RAM_HEADER_TYPE_START_C   & RAM_HEADER_TYPE_MASK_C )   |
  	                      (            i_regName   << RAM_HEADER_SPRN_START_C   & RAM_HEADER_SPRN_MASK_C )   |
  	                      (            i_threadId  << RAM_HEADER_THREAD_START_C & RAM_HEADER_THREAD_MASK_C );
  	// ...do the SPR instr 
  	sprSwiz = i_regName>>5 | (i_regName & 0x0000001f)<<5;
  	if (sprSwiz!=SLW_SPR_REGS[iReg].swizzled)  {
  	  MY_ERR("Inconsistent swizzle rules implemented. Check code. Dumping data.\n");
  	  MY_ERR("\tsprSwiz (on-the-fly-calc)=%i\n",sprSwiz);
  	  MY_ERR("\tSLW_SPR_REGS[%i].swizzled=%i\n",iReg,SLW_SPR_REGS[iReg].swizzled);
  	  return IMGBUILD_ERR_RAM_CODE;
  	}
  	ramEntryThis.instr =  RAM_MTSPR_INSTR_TEMPL_C | ( ( sprSwiz<<RAM_MTSPR_SPR_START_C ) & RAM_MTSPR_SPR_MASK_C );
  }
	// ...do the data
  ramEntryThis.data  = i_regData;
  // ...summarize new table entry data
  MY_INF("New table entry data (host format):\n");
  MY_INF("\theader = 0x%08x\n",ramEntryThis.header);
  MY_INF("\tinstr  = 0x%08x\n",ramEntryThis.instr);
  MY_INF("\tdata   = 0x%016llx\n",ramEntryThis.data);

  // -------------------------------------------------------------------------
  // Insert the new RAM entry into the table in BE format.
  //
  ramEntryNext = (RamTableEntry*)hostRamEntryThis;
  // ...some redundant checking
  if (bNewTable)  {
    // For any new table, the insertion location should be clean. We check for this here.
    if (myRev32(ramEntryNext->header)!=0)  {
      MY_ERR("WARNING : Table entry location should be empty for a new table. Check code and image. Dumping data:\n");
      MY_ERR("\theader = 0x%08x\n",myRev32(ramEntryNext->header));
      MY_ERR("\tinstr  = 0x%08x\n",myRev32(ramEntryNext->instr));
      MY_ERR("\tdata   = 0x%016llx\n",myRev64(ramEntryNext->data));
      rc = IMGBUILD_WARN_RAM_TABLE_CONTAMINATION;
    }
  }
  ramEntryNext->header = myRev32(ramEntryThis.header);
  ramEntryNext->instr  = myRev32(ramEntryThis.instr);
  ramEntryNext->data   = myRev64(ramEntryThis.data);

  return rc;
}


/*
// io_image - pointer to SLW image
// i_sizeImage - size of SLW image
// i_scomAddr - Scom address
// i_scomData - Data to write to scom register
// i_operation - What to do with the scom addr and data
// i_coreId - The core ID [0:15].
*/
uint32_t p8_pore_gen_scom(  void       *io_image,
                            uint32_t   i_sizeImage,
                            uint32_t   i_scomAddr,
                            uint32_t   i_coreId,     // [0:15] 
                            uint64_t   i_scomData,
                            uint32_t   i_operation,  // [0:5]
														uint32_t   i_section)      // [0,2,3]
{
  uint32_t  rc=0, rcLoc=0, iEntry=0;
  uint32_t  chipletId=0;
  uint32_t  operation=0;
  uint32_t  entriesCount=0, entriesMatch=0, entriesNOP=0;
  uint32_t  sizeImageIn=0;
  void      *hostSlwSection;
  uint64_t  xipScomTableThis;
  void      *hostScomVector, *hostScomTableThis;
  void      *hostScomEntryNext;       // running entry pointer
  void      *hostScomEntryMatch=NULL; // pointer to entry that matches scomAddr
  void      *hostScomEntryRET=NULL;   // pointer to first return instr after table
  void      *hostScomEntryNOP=NULL;   // pointer to first nop IIS
  uint8_t   bufIIS[XIPSIZE_SCOM_ENTRY], bufNOP[4], bufRET[4];
  SbeXipSection xipSection;
  SbeXipItem    xipTocItem;
  PoreInlineContext ctx;
  
  // -------------------------------------------------------------------------
  // Validate Scom parameters.
  //
  // ...check if valid Scom register (is there anything we can do here to check?)
  // Skipping check. We blindly trust caller.
  //
  // ...check Scom operation
  if (i_operation<P8_PORE_SCOM_FIRST_OP || i_operation>P8_PORE_SCOM_LAST_OP)  {
    MY_ERR("Scom operation = %i is not within valid range of [%d;%d]\n",
      i_operation, P8_PORE_SCOM_FIRST_OP, P8_PORE_SCOM_LAST_OP);
    rcLoc = 1;
  }
  // ...check that core ID corresponds to valid chiplet ID
  chipletId = i_coreId + P8_CID_EX_LOW;
  if (chipletId<P8_CID_EX_LOW || chipletId>P8_CID_EX_HIGH)  {
    MY_ERR("Chiplet ID = 0x%02x is not within valid range of [0x%02x;0x%02x]\n",
      chipletId, P8_CID_EX_LOW, P8_CID_EX_HIGH);
    rcLoc = 1;
  }
  if (rcLoc)
    return IMGBUILD_ERR_SCOM_INVALID_PARM;
  rcLoc = 0;
  
  // -------------------------------------------------------------------------
  // Validate image and get pointer to SLW section.
  //
  // ...validate
  rc = sbe_xip_validate( io_image, i_sizeImage);
  if (rc)  {
    MY_ERR("Invalid image.\n");
    return IMGBUILD_INVALID_IMAGE;
  }
  // ...size check
  sbe_xip_image_size( io_image, &sizeImageIn);
  if (sizeImageIn!=i_sizeImage)  {
    MY_ERR("Supplied image size (=%i) differs from size in image header (=%i).\n",
              i_sizeImage, sizeImageIn);
    return IMGBUILD_IMAGE_SIZE_MISMATCH;
  }
  // ...get pointer to SLW section where Scom table resides
  rc = sbe_xip_get_section( io_image, SBE_XIP_SECTION_SLW, &xipSection);
  if (rc)  {
    MY_ERR("Probably invalid section name for SBE_XIP_SECTION_SLW.\n");
    return IMGBUILD_ERR_GET_SECTION;
  }
  hostSlwSection = (void*)((uint8_t*)io_image + xipSection.iv_offset);
  // ...check .slw section size
  if (xipSection.iv_size!=SLW_RAM_TABLE_SIZE+SLW_SCOM_TABLE_SIZE_ALL)  {
    MY_ERR("SLW table size in *.H header file differs from SLW section size in image.\n"); 
    MY_ERR("Check code or image version.\n");
    return IMGBUILD_ERR_SCOM_HDRS_NOT_SYNCD;
  }

  // -------------------------------------------------------------------------
  // Summarize parameters and checking results.
  //
  MY_INF("Input parameter checks - OK\n");
  MY_INF("\tRegister  = 0x%08x\n",i_scomAddr);
  MY_INF("\tOperation = %i\n",i_operation);
  MY_INF("\tSection   = %i\n",i_section);
  MY_INF("\tCore ID   = %i\n",i_coreId);
  MY_INF("Image validation and size checks - OK\n");
  MY_INF("\tImage size      = %i\n",i_sizeImage);
  MY_INF("\tSLW section size=  %i\n",xipSection.iv_size);
  
  // -------------------------------------------------------------------------
  // Locate Scom vector according to i_section and then locate Scom table 
	//   associated with "This" core ID.
  //
	switch (i_section)  {
	case 0:
    rc = sbe_xip_find( io_image, SLW_HOST_SCOM_NC_VECTOR_TOC_NAME, &xipTocItem);
    if (rc)  {
		  MY_ERR("Probably invalid key word for SLW_HOST_SCOM_NC_VECTOR_TOC_NAME.\n");
      return IMGBUILD_ERR_KEYWORD_NOT_FOUND;
		}
		break;
	case 2:
    rc = sbe_xip_find( io_image, SLW_HOST_SCOM_L2_VECTOR_TOC_NAME, &xipTocItem);
    if (rc)  {
		  MY_ERR("Probably invalid key word for SLW_HOST_SCOM_L2_VECTOR_TOC_NAME.\n");
      return IMGBUILD_ERR_KEYWORD_NOT_FOUND;
		}
		break;
	case 3:
    rc = sbe_xip_find( io_image, SLW_HOST_SCOM_L3_VECTOR_TOC_NAME, &xipTocItem);
    if (rc)  {
		  MY_ERR("Probably invalid key word for SLW_HOST_SCOM_L3_VECTOR_TOC_NAME.\n");
      return IMGBUILD_ERR_KEYWORD_NOT_FOUND;
		}
		break;
	default:
    MY_ERR("Invalid value for i_section (=%i).\n",i_section);
		MY_ERR("Valid values for i_section = [0,2,3].\n");
    return IMGBUILD_ERR_SCOM_INVALID_SUBSECTION;
	}
  MY_INF("xipTocItem.iv_address = 0x%016llx\n",xipTocItem.iv_address);
  sbe_xip_pore2host( io_image, xipTocItem.iv_address, &hostScomVector);
  MY_INF("hostScomVector = 0x%016llx\n",(uint64_t)hostScomVector);
  xipScomTableThis = myRev64(*((uint64_t*)hostScomVector + i_coreId));
  MY_INF("xipScomTableThis = 0x%016llx\n",xipScomTableThis);
  if (xipScomTableThis)  {
    sbe_xip_pore2host( io_image, xipScomTableThis, &hostScomTableThis);
  }
  else  {  // Should never be here.
    MY_ERR("Code or image bug. Scom vector table entries should never be null.\n");
    return IMGBUILD_ERR_CHECK_CODE;
  }

  //
  // Determine where to place/do Scom action and if entry already exists.
  // Insertion rules:
  // - If entry doesn't exist, insert at first NOP. (Note that if you don't do
  //   this, then the table might potentially overflow since the max table size
  //   doesn't include NOP entries.)
  // - If no NOP found, insert at first RET.
  //
  
  // First, create search strings for addr, nop and ret.
  // Note, the following IIS will also be used in case of
	// - i_operation==append
	// - i_operation==replace
  pore_inline_context_create( &ctx, (void*)bufIIS, XIPSIZE_SCOM_ENTRY, 0, 0);
  pore_LS( &ctx, P1, chipletId);
  pore_STI( &ctx, i_scomAddr, P1, i_scomData);
  if (ctx.error  > 0)  {
    MY_ERR("pore_LS or _STI generated rc = %d", ctx.error);
    return IMGBUILD_ERR_PORE_INLINE_ASM;
  }
  pore_inline_context_create( &ctx, (void*)bufRET, 4, 0, 0);
  pore_RET( &ctx);
  if (ctx.error > 0)  {
    MY_ERR("pore_RET generated rc = %d", ctx.error);
    return IMGBUILD_ERR_PORE_INLINE_ASM;
  }
  pore_inline_context_create( &ctx, (void*)bufNOP, 4, 0, 0);
  pore_NOP( &ctx);
  if (ctx.error > 0)  {
    MY_ERR("pore_NOP generated rc = %d", ctx.error);
    return IMGBUILD_ERR_PORE_INLINE_ASM;
  }
  
  // Second, search for addr and nop in relevant coreId table until first RET.
  // Note:
  // - We go through ALL entries until first RET instr. We MUST find a RET instr,
	//   though we don't check for overrun until later. (Should be improved.)
	// - Count number of entries and check for overrun, though we'll continue
	//   searching until we find an RET. (Should be improved.)
  // - The STI(+SCOM_addr) opcode is in the 2nd word of the Scom entry.
  // - For an append operation, if a NOP is found (before a RET obviously), the 
	//   SCOM is replacing that NNNN sequence.
  hostScomEntryNext = hostScomTableThis;
  while (*(uint32_t*)hostScomEntryNext!=*(uint32_t*)bufRET)  {
	  entriesCount++;
		if (*((uint32_t*)bufIIS+1)==*((uint32_t*)hostScomEntryNext+1) && entriesMatch==0)  {// +1 skips 1st word in Scom entry (which loads the PC in an LS operation.)
      hostScomEntryMatch = hostScomEntryNext;
      entriesMatch++;
    }
    if (*(uint32_t*)hostScomEntryNext==*(uint32_t*)bufNOP && entriesNOP==0)  {
      hostScomEntryNOP = hostScomEntryNext;
			entriesNOP++;
		}
    hostScomEntryNext = (void*)((uintptr_t)hostScomEntryNext + XIPSIZE_SCOM_ENTRY);
  }
  hostScomEntryRET = hostScomEntryNext; // The last EntryNext will always be the first RET.
  
	switch (i_section)  {
	case 0:
	  if (entriesCount>=SLW_MAX_SCOMS_NC)  {
		  MY_ERR("SCOM table NC is full. Max %i entries allowed.\n",SLW_MAX_SCOMS_NC);
		  return IMGBUILD_ERR_CHECK_CODE;
	  }
		break;
	case 2:
	  if (entriesCount>=SLW_MAX_SCOMS_L2)  {
		  MY_ERR("SCOM table L2 is full. Max %i entries allowed.\n",SLW_MAX_SCOMS_L2);
		  return IMGBUILD_ERR_CHECK_CODE;
	  }
		break;
	case 3:
	  if (entriesCount>=SLW_MAX_SCOMS_L3)  {
		  MY_ERR("SCOM table L3 is full. Max %i entries allowed.\n",SLW_MAX_SCOMS_L3);
		  return IMGBUILD_ERR_CHECK_CODE;
	  }
		break;
	default:
    MY_ERR("Invalid value for i_section (=%i).\n",i_section);
		MY_ERR("Valid values for i_section = [0,2,3].\n");
    return IMGBUILD_ERR_SCOM_INVALID_SUBSECTION;
	}

  //
  // Further qualify (translate) operation and IIS.
  //
	if (i_operation==P8_PORE_SCOM_APPEND)  {
	  operation = i_operation;
	}
  else if (i_operation==P8_PORE_SCOM_REPLACE)  {
    if (hostScomEntryMatch)
      // ... do a replace
      operation = i_operation;
    else
      // ... do an append
      operation = P8_PORE_SCOM_APPEND;
  }
  else if (i_operation==P8_PORE_SCOM_NOOP)  {
    // ...overwrite earlier bufIIS from the search step
    pore_inline_context_create( &ctx, (void*)bufIIS, XIPSIZE_SCOM_ENTRY, 0, 0);
    pore_NOP( &ctx);
    pore_NOP( &ctx);
    pore_NOP( &ctx);
    pore_NOP( &ctx);
    if (ctx.error > 0)  {
      MY_ERR("*** _NOP generated rc = %d", ctx.error);
      return IMGBUILD_ERR_PORE_INLINE_ASM;
    }
    operation = i_operation;
  }
  else if (i_operation==P8_PORE_SCOM_AND ||
           i_operation==P8_PORE_SCOM_OR)  {
    operation = i_operation;
  }
	else if (i_operation==P8_PORE_SCOM_RESET)  {
  // ... create RNNN instruction sequence.
	  pore_inline_context_create( &ctx, (void*)bufIIS, XIPSIZE_SCOM_ENTRY, 0, 0);
	  pore_RET( &ctx);
	  pore_NOP( &ctx);
	  pore_NOP( &ctx);
	  pore_NOP( &ctx);
	  if (ctx.error > 0)  {
	    MY_ERR("***_RET or _NOP generated rc = %d", ctx.error);
			return IMGBUILD_ERR_PORE_INLINE_ASM;
	  }
		operation = i_operation;
	}
  else  {
    MY_ERR("Scom operation = %i is not within valid range of [%d;%d]\n",
      i_operation, P8_PORE_SCOM_FIRST_OP, P8_PORE_SCOM_LAST_OP);
    return IMGBUILD_ERR_SCOM_INVALID_PARM;
  }
  
  // -------------------------------------------------------------------------
  // Assuming pre-allocated Scom table (after pre-allocated Ram table):
  // - Table is pre-filled with RNNN ISS.
  // - Each core Id has dedicated space, uniformly distributed by SLW_MAX_SCOMS_NC*
  //   XIPSIZE_SCOM_ENTRY.
  // - Remember to check for more than SLW_MAX_SCOMS_NC entries!
  switch (operation)  {

  case P8_PORE_SCOM_APPEND:  // Append a Scom at first occurring NNNN or RNNN,  
    if (hostScomEntryNOP)  {
      // ... replace the NNNN
			MY_INF("Append at NOP\n");
      memcpy(hostScomEntryNOP,(void*)bufIIS,XIPSIZE_SCOM_ENTRY);
		}
    else if (hostScomEntryRET)  {
      // ... replace the RNNN
			MY_INF("Append at RET\n");
      memcpy(hostScomEntryRET,(void*)bufIIS,XIPSIZE_SCOM_ENTRY);
		}
		else  {
      // We should never be here.
      MY_ERR("In case=_SCOM_APPEND: EntryRET=NULL is impossible. Check code.\n");
      return IMGBUILD_ERR_CHECK_CODE;
		}
    break;
  case P8_PORE_SCOM_REPLACE: // Replace existing Scom with new data
    if (hostScomEntryMatch)  {
      // ... do a vanilla replace
			MY_INF("Replace existing Scom\n");
      memcpy(hostScomEntryMatch,(void*)bufIIS,XIPSIZE_SCOM_ENTRY);
		}
    else  {
      // We should never be here.
      MY_ERR("In case=_SCOM_REPLACE: EntryMatch=NULL is impossible. Check code.\n");
      return IMGBUILD_ERR_CHECK_CODE;
    }
    break;
  case P8_PORE_SCOM_NOOP:
    if (hostScomEntryMatch)  {
      // ... do a vanilla replace
			MY_INF("Replace existing Scom w/NOPs\n");
      memcpy(hostScomEntryMatch,(void*)bufIIS,XIPSIZE_SCOM_ENTRY);
		}
    else  { 
      // do nothing, and assume everything is fine, since we did no damage.
    }
    break;
  case P8_PORE_SCOM_OR:      // Overlay Scom data onto existing data by bitwise OR
    if (hostScomEntryMatch)  {
      // ... do an OR on the data (which is the 2nd DWord in the entry)
			MY_INF("Overlay existing Scom - OR case\n");
      *((uint64_t*)hostScomEntryMatch+1) = 
        *((uint64_t*)hostScomEntryMatch+1) | myRev64(i_scomData);
		}
    else  { 
      MY_ERR("No Scom entry found to do OR operation with.\n");
      return IMGBUILD_ERR_SCOM_ENTRY_NOT_FOUND;
    }
    break;
  case P8_PORE_SCOM_AND:     // Overlay Scom data onto existing data by bitwise AND
    if (hostScomEntryMatch)  {
      // ... do an AND on the data (which is the 2nd DWord in the entry)
			MY_INF("Overlay existing Scom - AND case\n");
      *((uint64_t*)hostScomEntryMatch+1) = 
        *((uint64_t*)hostScomEntryMatch+1) & myRev64(i_scomData);
		}
    else  { 
      MY_ERR("No Scom entry found to do AND operation with.\n");
      return IMGBUILD_ERR_SCOM_ENTRY_NOT_FOUND;
    }
    break;
	case P8_PORE_SCOM_RESET:   // Reset (delete) table. Refill w/RNNN ISS.
		MY_INF("Reset table\n");
    hostScomEntryNext = hostScomTableThis;
		for ( iEntry=0; iEntry<entriesCount; iEntry++)  {
			memcpy( hostScomEntryNext, (void*)bufIIS, XIPSIZE_SCOM_ENTRY);
			hostScomEntryNext = (void*)((uintptr_t)hostScomEntryNext + XIPSIZE_SCOM_ENTRY);
		}
		break;
  default:
    MY_ERR("Impossible value of operation (=%i). Check code.\n",operation);
    return IMGBUILD_ERR_CHECK_CODE;
  
  }  // End of switch(operation)

  return rc;
}
