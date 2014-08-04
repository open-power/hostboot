/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_slw_build/p8_image_help.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
// $Id: p8_image_help.C,v 1.61 2014/07/23 20:08:36 jmcgill Exp $
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



// calc_ring_delta_state() parms:
// i_init - init (flush) ring state
// i_alter - altered (desired) ring state
// o_delta - ring delta state, caller allocates buffer
// i_ringLen - length of ring in bits
int calc_ring_delta_state( const uint32_t  *i_init,
													 const uint32_t  *i_alter,
													 uint32_t        *o_delta,
													 const uint32_t  i_ringLen )
{
  int      i=0, count=0, remainder=0, remainingBits=0;
  uint32_t init, alter;
  uint32_t mask=0;

  // Do some checking of input parms
  if ( (i_init==NULL) || (i_alter==NULL) || (o_delta==NULL) || (i_ringLen==0) )  {
  	MY_ERR("Bad input arguments.\n");
    return IMGBUILD_BAD_ARGS;
  }

  // Check how many 32-bit shift ops are needed and if we need final shift of remaining bit.
  count = i_ringLen/32;
  remainder = i_ringLen%32;
	if (remainder>0)
	    count = count + 1;
	remainingBits = i_ringLen;
	MY_DBG("count=%i  rem=%i  remBits=%i\n",count,remainder,remainingBits);

  // XOR flush and init values 32 bits at a time.  Store result in o_delta buffer.
	for (i=0; i<count; i++)  {

		if (remainingBits<=0)  {
			MY_ERR("remaingBits can not be negative.\n");
			return IMGBUILD_ERR_CHECK_CODE;
		}

    init  = i_init[i];
    alter = i_alter[i];

    if (remainingBits>=32)
      remainingBits = remainingBits-32;
	  else  {  //If remaining bits are less than 32 bits, mask unused bits
		  MY_DBG("remainingBits=%i<32. Padding w/zeros. True bit length unaltered. (@word count=%i)\n",remainingBits,count);
      mask = BITS32(0,remainingBits); // BE mask
      mask = myRev32(mask);           // Convert to LE if on LE machine
	    init  = init & mask;
	    alter = alter & mask;
	    remainingBits = 0;
	  }

    // Do the XORing.
		o_delta[i]  = init ^ alter;
	}

  return IMGBUILD_SUCCESS;
}



// create_wiggle_flip_prg() function
// Notes:
// - WF routine implements dynamic P1 multicast bit set based on P0 status.
// - WF routine checks header word on scan complete.
// - WF routine is 8-byte aligned.
int create_wiggle_flip_prg( uint32_t *i_deltaRing,          // scan ring delta state (in BE format)
                            uint32_t i_ringBitLen,          // length of ring
                            uint32_t i_scanSelectData,      // Scan ring modifier data
                            uint32_t i_chipletID,           // Chiplet ID
                            uint32_t **o_wfInline,          // location of the PORE instructions data stream
                            uint32_t *o_wfInlineLenInWords, // final length of data stream
                            uint8_t  i_flushOptimization,   // flush optimize or not
                            uint32_t i_scanMaxRotate,       // Max rotate bit len on 38xxx, or polling threshold on 39xxx.
                            uint32_t i_waitsScanDelay,      // Temporary debug support.
                            uint32_t i_ddLevel)             // DD level.
{
  uint32_t rc=0;
  uint32_t i=0;
  uint32_t scanSelectAddr=0;
  uint32_t scanRing_baseAddr=0;
  uint32_t scanRing_poreAddr=0;
  uint32_t scanRingCheckWord=0;
  uint32_t bitShift=0;
  uint32_t count=0;
  uint32_t rotateLen=0, remainder=0, remainingBits=0;
  uint32_t clear_excess_dirty_bits_mask=0xffffffff;
  uint32_t clean_up_shift_reg_mask=0xffffffff;
  uint64_t pore_imm64b=0;
  uint32_t maxWfInlineLenInWords;
  PoreInlineContext ctx;
  uint32_t waitsScanPoll=0;
  uint32_t scanRing_baseAddr_long=0;

	maxWfInlineLenInWords = *o_wfInlineLenInWords;

  pore_inline_context_create(&ctx, *o_wfInline, maxWfInlineLenInWords * 4, 0, 0);

  //
  // Set Default scanselq addr and scanring addr vars
  //

  // 0x00030007: port 3 - clock cotrol endpt, x07- scanselq (regin & types)
  scanSelectAddr = P8_PORE_CLOCK_CONTROLLER_REG;

  // Addr of clock control SCOM register(s) for short and long rotates.
  //
  // Short: 0x00038000: port 3, addr bit 16 must be set to 1 and bit 19 to 0.
  scanRing_baseAddr = P8_PORE_SHIFT_REG;
  scanRing_poreAddr = scanRing_baseAddr;

  // Long (poll): 0x00039000: port 3, addr bit 16 must be set to 1 and bit 19 to 1.
  scanRing_baseAddr_long = P8_PORE_SHIFT_REG | 0x00001000;

  // Header check word for checking ring write was successful
  scanRingCheckWord = P8_SCAN_CHECK_WORD;

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

  // Program scanselq reg for scan clock control setup before ring scan
  pore_imm64b = ((uint64_t)i_scanSelectData) << 32;
  pore_STI(&ctx, scanSelectAddr, P0, pore_imm64b);
  if (ctx.error > 0)  {
    MY_ERR("***STI rc = %d", ctx.error);
    return ctx.error;
  }

	// Preload the scan data/shift reg with the scan header check word.
  //
  pore_imm64b = ((uint64_t)scanRingCheckWord) << 32;
	pore_STI(&ctx, scanRing_baseAddr, P0, pore_imm64b);
  if (i_waitsScanDelay)  {
    pore_WAITS(&ctx, i_waitsScanDelay);
  }
  if (ctx.error > 0)  {
    MY_ERR("***STI(1) rc = %d", ctx.error);
    return ctx.error;
  }

  // Check how many 32-bit shift ops are needed and if we need final shift of remaining bit.
  count = i_ringBitLen/32;
  remainder = i_ringBitLen%32;
  if (remainder >0)
      count = count + 1;

  remainingBits = i_ringBitLen;

  MY_DBG("count=%i  rem=%i  remBits=%i",count,remainder,remainingBits);

  for (i=0; i<count; i++)  {

    if (i==(count-1))  {
      // Cleanup any leftover bits in dirty buffer. (Only applies to last word.)
      MY_DBG("Clearing any dirty bits in last WF word:\n");
      MY_DBG("i_deltaRing[%i] (before)     = 0x%08x\n",i,i_deltaRing[i]);
      MY_DBG("remainingBits                = %i\n",remainingBits);
      clear_excess_dirty_bits_mask = BITS32(0,remainingBits); // BE mask
      clear_excess_dirty_bits_mask = myRev32(clear_excess_dirty_bits_mask); // Convert to LE if on LE machine
      i_deltaRing[i] = i_deltaRing[i]&clear_excess_dirty_bits_mask;
      MY_DBG("clear_excess_dirty_bits_mask = 0x%08x\n",clear_excess_dirty_bits_mask);
      MY_DBG("i_deltaRing[%i] (after)      = 0x%08x\n",i,i_deltaRing[i]);
    }

    //====================================================================================
    // If flush & init values are identical, increase the read count, no code needed.
    // When the discrepancy is found, read (rotate the ring) up to current address
    // then scan/write in the last 32 bits
    //====================================================================================
    if (i_deltaRing[i] > 0)  {

      if (rotateLen > 0)  {

				if (i_ddLevel>=0x20)  {   // Use polling protocol.

          PoreInlineLocation  srcp1=0,tgtp1=0;

          pore_imm64b = uint64_t(rotateLen)<<32;
				  pore_STI(&ctx, scanRing_baseAddr_long, P0, pore_imm64b);

          waitsScanPoll = rotateLen/OVER_SAMPLING_POLL;
          if (waitsScanPoll<WAITS_POLL_MIN)
            waitsScanPoll = WAITS_POLL_MIN;
				  PORE_LOCATION(&ctx, tgtp1);
				  pore_WAITS(&ctx, waitsScanPoll);
				  pore_LDANDI(&ctx, D0, GENERIC_GP1_0x00000001, P1, P8_SCAN_POLL_MASK_BIT15);
				  PORE_LOCATION(&ctx, srcp1);
				  pore_BRAZ(&ctx, D0, tgtp1);
				  pore_inline_branch_fixup(&ctx, srcp1, tgtp1);
          if (ctx.error > 0)  {
            MY_ERR("***POLLING PROT(2) rc = %d", ctx.error);
            return ctx.error;
          }
        }
        else  {                   // Do not use polling protocol.

          scanRing_poreAddr = scanRing_baseAddr | rotateLen;
          pore_LD(&ctx, D0, scanRing_poreAddr, P1);
          if (ctx.error > 0)  {
            MY_ERR("***LD D0 rc = %d", ctx.error);
            return ctx.error;
          }

        }

      } // End of if (rotateLen>0)

      //
      // Shift in the delta state word, or parts of it if last word.
      //
      if (remainingBits>32)
        bitShift = 32;
      else
        bitShift = remainingBits;
      scanRing_poreAddr = scanRing_baseAddr | bitShift;

      if (i==(count-1) && bitShift<32)  {
        // --------------------------------------------------------------------
        // Be very careful shifting in last word content as it can mess up the
        //   current shift register content when loaded.
        // --------------------------------------------------------------------
        // Take snapshot of present content of shift reg and put in D1.
        if (i_flushOptimization)  {
          pore_LD(&ctx, D1, scanRing_baseAddr, P1);
          // Calculate shift reg cleanup mask and put in D0. The intent is to
          //   clear bit in the ring data positions while keeping any header
          //   check word content untouched.
          clean_up_shift_reg_mask = 0xffffffff>>bitShift;
          pore_imm64b = ((uint64_t)clean_up_shift_reg_mask) << 32;
          pore_LI(&ctx, D0, pore_imm64b );
          // Cleanup shift register snapshot and put in D1.
          pore_AND(&ctx, D1, D0, D1);
          // Put ring data in D0.
          // Note, any dirty content was removed earlier.
          pore_imm64b = ((uint64_t)myRev32(i_deltaRing[i])) << 32;
          pore_LI(&ctx, D0, pore_imm64b );
          // Finally, combine the ring data and the shift reg content and put in D0.
          pore_OR(&ctx, D0, D0, D1);
				  pore_STD(&ctx, D0, scanRing_poreAddr, P0);
        }
        else  {
          pore_LD(&ctx, D1, scanRing_baseAddr, P1);
          // Bring ring data in as an immediate.
          // Note, any dirty content was removed earlier.
          pore_imm64b = ((uint64_t)myRev32(i_deltaRing[i])) << 32;
          pore_XORI(&ctx, D0, D1, pore_imm64b);
          pore_STD(&ctx, D0, scanRing_poreAddr, P0);
        }
      }
      else  {
        // --------------------------------------------------------------------
        // Not the last word OR the last word has exactly 32-bit of ring data.
        // --------------------------------------------------------------------
        if (i_flushOptimization)  {
          pore_imm64b = ((uint64_t)myRev32(i_deltaRing[i])) << 32;
        // Shift it in by bitShift bits.
		  		pore_STI(&ctx, scanRing_poreAddr, P0, pore_imm64b);
        }
        else  {
          pore_LD(&ctx, D1, scanRing_baseAddr, P1);
          pore_imm64b = ((uint64_t)myRev32(i_deltaRing[i])) << 32;
          pore_XORI(&ctx, D0, D1, pore_imm64b);
          pore_STD(&ctx, D0, scanRing_poreAddr, P0);
        }
      }
      if (i_waitsScanDelay)  {
        pore_WAITS(&ctx, i_waitsScanDelay);
      }
      if (ctx.error > 0)  {
        MY_ERR("***STI(2) (or STD) rc = %d", ctx.error);
        return ctx.error;
      }

      rotateLen=0;  //reset rotate length

		}
    else  {  // i_deltaRing[i]==0 (i.e., init and alter states are identical).
      if (remainingBits>32)
        rotateLen = rotateLen + 32;
      else
        rotateLen = rotateLen + remainingBits;

			if (i_ddLevel>=0x20)  {    // Use polling protocol.

        PoreInlineLocation  srcp2=0,tgtp2=0;

        // Max rotate length is 2^20-1, i.e., data BITS(12-31)=>0x000FFFFF
  			if (rotateLen>=SCAN_MAX_ROTATE_LONG)  {
			    MY_INF("Scanning should never be here since max possible ring length is\n");
          MY_INF("480,000 bits but MAX_LONG_ROTATE=0x%0x and rotateLen=0x%0x\n",
                   SCAN_MAX_ROTATE_LONG, rotateLen);
          pore_imm64b = uint64_t(SCAN_MAX_ROTATE_LONG)<<32;
				  pore_STI(&ctx, scanRing_baseAddr_long, P0, pore_imm64b);
	        if (ctx.error > 0)  {
	          MY_ERR("***POLLING PROT(3a) rc = %d", ctx.error);
	          return ctx.error;
  	      }
		  	  waitsScanPoll = rotateLen/OVER_SAMPLING_POLL;
          if (waitsScanPoll<WAITS_POLL_MIN)
            waitsScanPoll = WAITS_POLL_MIN;
	  		  PORE_LOCATION(&ctx, tgtp2);
    			pore_WAITS(&ctx, waitsScanPoll);
				  pore_LDANDI(&ctx, D0, GENERIC_GP1_0x00000001, P1, P8_SCAN_POLL_MASK_BIT15);
			   	PORE_LOCATION(&ctx, srcp2);
		  	  pore_BRAZ(&ctx, D0, tgtp2);
    			pore_inline_branch_fixup(&ctx, srcp2, tgtp2);
  	      if (ctx.error > 0)  {
	          MY_ERR("***POLLING PROT(3) rc = %d", ctx.error);
	          return ctx.error;
	        }
          rotateLen = rotateLen - SCAN_MAX_ROTATE_LONG;
      	}

      }
      else  {                   // Do not use polling protocol.

        if (rotateLen>i_scanMaxRotate)  {
          scanRing_poreAddr = scanRing_baseAddr | i_scanMaxRotate;
          pore_LD(&ctx, D0, scanRing_poreAddr, P1);
          if (ctx.error > 0)  {
            MY_ERR("***LD D0 rc = %d", ctx.error);
            return ctx.error;
          }
          rotateLen = rotateLen - i_scanMaxRotate;
        }

      }

    } //end of else (i_deltaRing==0)

    if (remainingBits>32)
      remainingBits = remainingBits - 32;
    else
      remainingBits = 0;

  } // End of for loop

  // If the scan ring has not been rotated to the original position
  // shift the ring by remaining shift bit length.
  if (rotateLen>0)  {
    if (i_ddLevel>=0x20)  {   // Use polling protocol.

  		PoreInlineLocation  srcp3=0,tgtp3=0;

      pore_imm64b = uint64_t(rotateLen)<<32;
		  pore_STI(&ctx, scanRing_baseAddr_long, P0, pore_imm64b);

      waitsScanPoll = rotateLen/OVER_SAMPLING_POLL;
      if (waitsScanPoll<WAITS_POLL_MIN)
        waitsScanPoll = WAITS_POLL_MIN;
      PORE_LOCATION(&ctx, tgtp3);
	    pore_WAITS(&ctx, waitsScanPoll);
  		pore_LDANDI(&ctx, D0, GENERIC_GP1_0x00000001, P1, P8_SCAN_POLL_MASK_BIT15);
	   	PORE_LOCATION(&ctx, srcp3);
	    pore_BRAZ(&ctx, D0, tgtp3);
    	pore_inline_branch_fixup(&ctx, srcp3, tgtp3);
      if (ctx.error > 0)  {
        MY_ERR("***POLLING PROT(4) rc = %d", ctx.error);
        return ctx.error;
      }
	  	rotateLen=0;

    }
    else  {                   // Do not use polling protocol.

      scanRing_poreAddr=scanRing_baseAddr | rotateLen;
      pore_LD(&ctx, D0, scanRing_poreAddr, P1);
      if (ctx.error > 0)  {
        MY_ERR("***LD D0 rc = %d", ctx.error);
        return ctx.error;
      }
      rotateLen=0;

    }
  }

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
  PORE_LOCATION( &ctx, src5);
  pore_BRAZ( &ctx, D0, tgt5);
  pore_inline_instruction1( &ctx, 0x34, 0x616C74);
  pore_inline_instruction1( &ctx, 0x00, 0xCB0DA9);
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
  PORE_LOCATION( &ctx, src8);
  pore_BRAZ( &ctx, D0, tgt8);
  pore_inline_instruction1( &ctx, 0x34, 0x616C74);
  pore_inline_instruction1( &ctx, 0x00, 0xCB0DA9);
  PORE_LOCATION( &ctx, tgt8);
	pore_STI(&ctx, GENERIC_CLK_SCAN_UPDATEDR_0x0003A000, P0, 0x0);
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


#if !(defined IMGBUILD_PPD_CEN_XIP_CUSTOMIZE)

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
      MY_ERR("sbe_xip_get_section() failed: %s", SBE_XIP_ERROR_STRING(errorStrings, rc));
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
    MY_ERR("Ring block or layout structure is not 8-byte aligned:");
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
    MY_ERR("Ring block or WF code origin not 8-byte aligned.");
    return IMGBUILD_ERR_MISALIGNED_RING_LAYOUT;
  }

  // Calc the size of the data section we're adding and the resulting output image.
  //
  rc = sbe_xip_image_size( io_imageOut, &sizeImageIn);
  if (rc)  {
    MY_ERR("sbe_xip_image_size() failed: %s", SBE_XIP_ERROR_STRING(errorStrings, rc));
    return IMGBUILD_ERR_XIP_MISC;
  }
  sizeNewDataBlock = myRev32(i_ringLayout->sizeOfThis);
  // ...estimate max size of new image
  sizeImageOutThisEst = sizeImageIn + sizeNewDataBlock + SBE_XIP_MAX_SECTION_ALIGNMENT; //

  if (sizeImageOutThisEst>*i_sizeImageMaxNew)  {
    MY_ERR("Estimated new image size (=%i) would exceed max allowed size (=%i).",
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
    MY_ERR("malloc() of initf buffer failed.");
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
	  MY_ERR("Ring layout mess. Check code or delta_scan(). deltaLC=%i",deltaLC);
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
    MY_ERR("Ring layout messup. Check code or delta_scan().");
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
    MY_ERR("sbe_xip_append() failed: %s", SBE_XIP_ERROR_STRING(errorStrings, rc));
    if (ringsBuffer)  free(ringsBuffer);
    return IMGBUILD_ERR_XIP_MISC;
  }
  // ...get new image size, update return size, and test if successful update.
  sbe_xip_image_size( io_imageOut, &sizeImageOutThis);
  MY_DBG("Output image size (final)\t=%i",sizeImageOutThis);
  *i_sizeImageMaxNew = sizeImageOutThis;
  rc = sbe_xip_validate( io_imageOut, sizeImageOutThis);
  if (rc)   {
    MY_ERR("sbe_xip_validate() of output image failed: %s", SBE_XIP_ERROR_STRING(errorStrings, rc));
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
    MY_ERR("sbe_xip_section2pore() failed: %s", SBE_XIP_ERROR_STRING(errorStrings, rc));
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
    MY_ERR("sbe_xip_[write,read]_uint64() failed: %s", SBE_XIP_ERROR_STRING(errorStrings, rc));
    if (ringsBuffer)  free(ringsBuffer);
    return IMGBUILD_ERR_XIP_MISC;
  }
  if (fwdPtrCheck!=ringPoreAddress || backPtr!=myRev64(i_ringLayout->backItemPtr))  {
    MY_ERR("Forward or backward pointer mess. Check code.");
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
    MY_ERR("sbe_xip_validate() of output image failed: %s", SBE_XIP_ERROR_STRING(errorStrings, rc));
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
                          int       *i_sizeImageMaxNew,
                          uint32_t  i_sectionId,
                          int       *i_sizeSection,
													uint8_t   i_bFixed)
{
  int      rc=0;
  uint32_t sizeImageIn=0, sizeImageOutThis=0;
	int      sizeImageOutThisEst=0;
  uint32_t offsetCheck=1;
 	SbeXipSection xipSection;

  SBE_XIP_ERROR_STRINGS(errorStrings);

  rc = 0;

  if (*i_sizeSection==0)  {
    MY_INF("INFO : Requested append size = 0. Nothing to do.");
    return rc;
  }

  // Check if there is enough room in the new image to add section.
  //
  sbe_xip_image_size( io_image, &sizeImageIn);
  // ...estimate max size of new image
	if (i_bFixed)
  	sizeImageOutThisEst = sizeImageIn + *i_sizeSection;
  else
		sizeImageOutThisEst = sizeImageIn + *i_sizeSection + SBE_XIP_MAX_SECTION_ALIGNMENT;
  if (sizeImageOutThisEst>*i_sizeImageMaxNew)  {
    MY_ERR("Estimated new image size (=%i) would exceed max allowed size (=%i).",
      sizeImageOutThisEst, *i_sizeImageMaxNew);
    *i_sizeImageMaxNew = sizeImageOutThisEst;
    return IMGBUILD_ERR_IMAGE_TOO_LARGE;
  }

  // Add the NULL buffer as a section append. sbe_xip_append() initializes with 0s.
  //
  rc = sbe_xip_append( io_image,
                       i_sectionId,
                       NULL,
                       *i_sizeSection,
                       sizeImageOutThisEst,
                       &offsetCheck);
  if (rc)  {
    MY_ERR("xip_append() failed: %s\n",SBE_XIP_ERROR_STRING(errorStrings, rc));
    return DSLWB_SLWB_IMAGE_ERROR;
  }
  if (offsetCheck)
    MY_INF("INFO : Section was not empty at time of xip_append(). It contained %i bytes.",offsetCheck);
  // ...get new image size, update return size, and test if successful update.
  sbe_xip_image_size( io_image, &sizeImageOutThis);
  MY_DBG("Output image size (after section append) = %i\n",sizeImageOutThis);
  *i_sizeImageMaxNew = sizeImageOutThis;
  rc = sbe_xip_validate( io_image, sizeImageOutThis);
  if (rc)   {
    MY_ERR("xip_validate() of output image failed: %s", SBE_XIP_ERROR_STRING(errorStrings, rc));
    return IMGBUILD_ERR_XIP_MISC;
  }

	// Return final section size.
	//
  rc = sbe_xip_get_section( io_image, i_sectionId, &xipSection);
 	*i_sizeSection = xipSection.iv_size;

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
	int    sizeSectionChk=0;
  void   *hostScomTableNext, *hostScomVectorNext;
	void   *hostScomVectorFirstNC, *hostScomVectorFirstL2, *hostScomVectorFirstL3;
	void   *hostScomTableNC, *hostScomTableL2, *hostScomTableL3;
  uint64_t xipScomTableNC, xipScomTableL2, xipScomTableL3;
  uint8_t  bufRNNN[XIPSIZE_SCOM_ENTRY];

  SBE_XIP_ERROR_STRINGS(errorStrings);

  sizeSectionChk = FIXED_SLW_SECTION_SIZE;
  rc = append_empty_section( io_image,
                             (int*)i_sizeImageMaxNew,
                             SBE_XIP_SECTION_SLW,
                             &sizeSectionChk,
														 0);
  if (rc)
    return rc;
  if (sizeSectionChk!=FIXED_SLW_SECTION_SIZE)  {
    MY_ERR("Section size of .slw (=%i) not equal to requested size (=%i).\n",
      sizeSectionChk, FIXED_SLW_SECTION_SIZE);
    return IMGBUILD_ERR_SECTION_SIZING;
  }

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
	// Note that we will assume, further down, that the NC section goes first,
	//   then the L2 section and then the L3 section.
  rc = sbe_xip_get_section( io_image, SBE_XIP_SECTION_SLW, &xipSection);
  if (rc)   {
    MY_ERR("sbe_xip_get_section() failed: %s", SBE_XIP_ERROR_STRING(errorStrings, rc));
    MY_ERR("Probable cause:");
    MY_ERR("\tThe section (=SBE_XIP_SECTION_SLW=%i) was not found.",SBE_XIP_SECTION_SLW);
    return IMGBUILD_ERR_KEYWORD_NOT_FOUND;
  }
  hostScomTableNC = (void*)((uintptr_t)io_image + xipSection.iv_offset + SLW_RAM_TABLE_SIZE);

  // ... populate entire Scom table with RNNN IIS, incl NC, L2 and L3 sections.
  for (i_iis=0; i_iis<SLW_SCOM_TABLE_SIZE_ALL; i_iis=i_iis+XIPSIZE_SCOM_ENTRY)  {
    hostScomTableNext = (void*)( (uintptr_t)hostScomTableNC + i_iis);
    memcpy( hostScomTableNext, (void*)bufRNNN, XIPSIZE_SCOM_ENTRY);
  }

	hostScomTableL2 = (void*)((uintptr_t)hostScomTableNC + SLW_SCOM_TABLE_SIZE_NC);
	hostScomTableL3 = (void*)((uintptr_t)hostScomTableL2 + SLW_SCOM_TABLE_SIZE_L2);

	// ... get location of  ----> Scom NC <----  vector from TOC.
  rc = sbe_xip_find( io_image, SLW_HOST_SCOM_NC_VECTOR_TOC_NAME, &xipTocItem);
  if (rc)  {
    MY_ERR("sbe_xip_find() failed w/rc=%i and %s", rc, SBE_XIP_ERROR_STRING(errorStrings, rc));
    MY_ERR("Probable cause:");
    MY_ERR("\tThe keyword (=%s) was not found.",SLW_HOST_SCOM_NC_VECTOR_TOC_NAME);
    return IMGBUILD_ERR_KEYWORD_NOT_FOUND;
  }
  sbe_xip_pore2host( io_image, xipTocItem.iv_address, &hostScomVectorFirstNC);

  // ... update Scom NC vector.
	sbe_xip_host2pore( io_image, hostScomTableNC, &xipScomTableNC);
  for (i_coreId=0; i_coreId<SLW_MAX_CORES; i_coreId++)  {
    hostScomVectorNext = (void*)( (uint64_t*)hostScomVectorFirstNC + i_coreId);
    *(uint64_t*)hostScomVectorNext = myRev64( xipScomTableNC +
                                              SLW_SCOM_TABLE_SPACE_PER_CORE_NC*i_coreId);
  }

	// ... get location of  ----> Scom L2 <----  vector from TOC.
  rc = sbe_xip_find( io_image, SLW_HOST_SCOM_L2_VECTOR_TOC_NAME, &xipTocItem);
  if (rc)  {
    MY_ERR("sbe_xip_find() failed w/rc=%i and %s", rc, SBE_XIP_ERROR_STRING(errorStrings, rc));
    MY_ERR("Probable cause:");
    MY_ERR("\tThe keyword (=%s) was not found.",SLW_HOST_SCOM_L2_VECTOR_TOC_NAME);
    return IMGBUILD_ERR_KEYWORD_NOT_FOUND;
  }
  sbe_xip_pore2host( io_image, xipTocItem.iv_address, &hostScomVectorFirstL2);

  // ... update Scom L2 vector.
	sbe_xip_host2pore( io_image, hostScomTableL2, &xipScomTableL2);
  for (i_coreId=0; i_coreId<SLW_MAX_CORES; i_coreId++)  {
    hostScomVectorNext = (void*)( (uint64_t*)hostScomVectorFirstL2 + i_coreId);
    *(uint64_t*)hostScomVectorNext = myRev64( xipScomTableL2 +
                                              SLW_SCOM_TABLE_SPACE_PER_CORE_L2*i_coreId);
  }

	// ... get location of  ----> Scom L3 <----  vector from TOC.
  rc = sbe_xip_find( io_image, SLW_HOST_SCOM_L3_VECTOR_TOC_NAME, &xipTocItem);
  if (rc)  {
    MY_ERR("sbe_xip_find() failed w/rc=%i and %s", rc, SBE_XIP_ERROR_STRING(errorStrings, rc));
    MY_ERR("Probable cause:");
    MY_ERR("\tThe keyword (=%s) was not found.",SLW_HOST_SCOM_L3_VECTOR_TOC_NAME);
    return IMGBUILD_ERR_KEYWORD_NOT_FOUND;
  }
  sbe_xip_pore2host( io_image, xipTocItem.iv_address, &hostScomVectorFirstL3);

  // ... update Scom L3 vector.
	sbe_xip_host2pore( io_image, hostScomTableL3, &xipScomTableL3);
  for (i_coreId=0; i_coreId<SLW_MAX_CORES; i_coreId++)  {
    hostScomVectorNext = (void*)( (uint64_t*)hostScomVectorFirstL3 + i_coreId);
    *(uint64_t*)hostScomVectorNext = myRev64( xipScomTableL3 +
                                              SLW_SCOM_TABLE_SPACE_PER_CORE_L3*i_coreId);
  }

  return rc;
}



// create_and_initialize_fixed_image()
// - swell image to fixed size of 1MB by:
//   - appending elastic section .fit
//   - appending fixed section .slw
//     - allocate space for Ramming and Scomming
//   - appending fixed section .ffdc
// - populate Scomming table with ret/nop/nop/nop (RNNN) inline asm instructions
// - update Scomming vector
int create_and_initialize_fixed_image( void      *io_image)
{
  int      rc=0;
  uint32_t i_coreId=0, i_iis=0;
  uint32_t sizeImageIn=0;
	int      sizeImageChk=0;
  int      sizeSectionFit=0, sizeSectionReq=0, sizeSectionChk=0;
  PoreInlineContext ctx;
  SbeXipSection  xipSection;
  SbeXipItem     xipTocItem;
  void   *hostRamVectorFirst, *hostRamVectorNext, *hostRamTable;
	void   *hostScomVectorFirstNC, *hostScomVectorFirstL2, *hostScomVectorFirstL3;
	void   *hostScomVectorNext;
	void   *hostScomTableNC, *hostScomTableL2, *hostScomTableL3;
	void   *hostScomTableNext;
  uint64_t xipRamTable, xipScomTableNC, xipScomTableL2, xipScomTableL3;
  uint8_t  bufRNNN[XIPSIZE_SCOM_ENTRY];

  SBE_XIP_ERROR_STRINGS(errorStrings);

  sbe_xip_image_size( io_image, &sizeImageIn);

	// Ensure, to play it safe, that last two sections (.slw & .ffdc) are both on
	// 128-byte boundaries. The max [fixed] image size must itself already be
	// 128-byte aligned.
  sizeSectionFit  = (int) ( FIXED_SLW_IMAGE_SIZE -
                    				sizeImageIn -
                    				FIXED_SLW_SECTION_SIZE -
                    				FIXED_FFDC_SECTION_SIZE );
  if (sizeSectionFit<0)  {
    MY_ERR("Size of .fit section (=%i) can not be negative.\n",sizeSectionFit);
    MY_ERR("Size of fixed image   = %i\n",FIXED_SLW_IMAGE_SIZE);
    MY_ERR("Size of input image   = %i\n",sizeImageIn);
    MY_ERR("Size of .slw section  = %i\n",FIXED_SLW_SECTION_SIZE);
    MY_ERR("Size of .ffdc section = %i\n",FIXED_FFDC_SECTION_SIZE);
    return IMGBUILD_ERR_SECTION_SIZING;
  }

  // Append .fit
  //
  sizeImageChk = FIXED_SLW_IMAGE_SIZE;
	sizeSectionReq = sizeSectionFit;
	sizeSectionChk = sizeSectionReq;
	MY_INF("Appending .fit w/size=%i\n",sizeSectionReq);
  rc = append_empty_section( io_image,
                             &sizeImageChk,
                             SBE_XIP_SECTION_FIT,
                             &sizeSectionChk,
														 1);
  if (rc)
    return rc;
	if (sizeSectionChk!=sizeSectionReq)  {
		MY_ERR("Section size of .fit (=%i) not equal to requested size (=%i).\n",
		  sizeSectionChk, sizeSectionReq);
		return IMGBUILD_ERR_SECTION_SIZING;
	}

  // Append .slw
  //
  sizeImageChk = FIXED_SLW_IMAGE_SIZE;
	sizeSectionReq = FIXED_SLW_SECTION_SIZE;
	sizeSectionChk = sizeSectionReq;
	MY_INF("Appending .slw w/size=%i\n",sizeSectionReq);
  rc = append_empty_section( io_image,
                             &sizeImageChk,
                             SBE_XIP_SECTION_SLW,
                             &sizeSectionChk,
														 1);
  if (rc)
    return rc;
	if (sizeSectionChk!=sizeSectionReq)  {
		MY_INF("Section size of .slw (=%i) not equal to requested size (=%i).\n",
		  sizeSectionChk, sizeSectionReq);
		return IMGBUILD_ERR_SECTION_SIZING;
	}


  // Append .ffdc
  //
  sizeImageChk = FIXED_SLW_IMAGE_SIZE;
	sizeSectionReq = FIXED_FFDC_SECTION_SIZE;
	sizeSectionChk = sizeSectionReq;
	MY_ERR("Appending .ffdc w/size=%i\n",sizeSectionReq);
  rc = append_empty_section( io_image,
                             &sizeImageChk,
                             SBE_XIP_SECTION_FFDC,
                             &sizeSectionChk,
														 1);
  if (rc)
    return rc;
	if (sizeSectionChk!=sizeSectionReq)  {
		MY_ERR("Section size of .ffdc (=%i) not equal to requested size (=%i).\n",
		  sizeSectionChk, sizeSectionReq);
		return IMGBUILD_ERR_SECTION_SIZING;
	}

  // --------------------------------------------------------------------------
  // Ramming table:   Already 0-initialized in append_empty_section().
  // --------------------------------------------------------------------------

  // ... calc host ptr to Ram table in .slw section.
  rc = sbe_xip_get_section( io_image, SBE_XIP_SECTION_SLW, &xipSection);
  if (rc)   {
    MY_ERR("sbe_xip_get_section() failed: %s", SBE_XIP_ERROR_STRING(errorStrings, rc));
    MY_ERR("Probable cause:");
    MY_ERR("\tThe section (=SBE_XIP_SECTION_SLW=%i) was not found.",SBE_XIP_SECTION_SLW);
    return IMGBUILD_ERR_KEYWORD_NOT_FOUND;
  }
  hostRamTable = (void*)((uintptr_t)io_image + xipSection.iv_offset);

	// ... get location of Ram vector.
  rc = sbe_xip_find( io_image, SLW_HOST_REG_VECTOR_TOC_NAME, &xipTocItem);
  if (rc)  {
    MY_ERR("sbe_xip_find() failed w/rc=%i and %s", rc, SBE_XIP_ERROR_STRING(errorStrings, rc));
    MY_ERR("Probable cause:");
    MY_ERR("\tThe keyword (=%s) was not found.",SLW_HOST_REG_VECTOR_TOC_NAME);
    return IMGBUILD_ERR_KEYWORD_NOT_FOUND;
  }
  sbe_xip_pore2host( io_image, xipTocItem.iv_address, &hostRamVectorFirst);

  // ... update Ram vector.
	sbe_xip_host2pore( io_image, hostRamTable, &xipRamTable);
  for (i_coreId=0; i_coreId<SLW_MAX_CORES; i_coreId++)  {
    hostRamVectorNext = (void*)( (uint64_t*)hostRamVectorFirst + i_coreId);
    *(uint64_t*)hostRamVectorNext = myRev64( xipRamTable +
                                              SLW_RAM_TABLE_SPACE_PER_CORE*i_coreId);
  }

  // --------------------------------------------------------------------------
  // Scomming table:  Fill with RNNN (16-byte) instruction sequences.
  // --------------------------------------------------------------------------

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

	// ... calc host ptr to Scom NC subsection.
	// Note that we will assume, further down, that the NC section goes first,
	//   then the L2 section and then the L3 section.
  rc = sbe_xip_get_section( io_image, SBE_XIP_SECTION_SLW, &xipSection);
  if (rc)   {
    MY_ERR("sbe_xip_get_section() failed: %s", SBE_XIP_ERROR_STRING(errorStrings, rc));
    MY_ERR("Probable cause:");
    MY_ERR("\tThe section (=SBE_XIP_SECTION_SLW=%i) was not found.",SBE_XIP_SECTION_SLW);
    return IMGBUILD_ERR_KEYWORD_NOT_FOUND;
  }
  hostScomTableNC = (void*)((uintptr_t)io_image + xipSection.iv_offset + SLW_RAM_TABLE_SIZE);

  // ... populate entire Scom table with RNNN IIS, incl NC, L2 and L3 sections.
  for (i_iis=0; i_iis<SLW_SCOM_TABLE_SIZE_ALL; i_iis=i_iis+XIPSIZE_SCOM_ENTRY)  {
    hostScomTableNext = (void*)( (uintptr_t)hostScomTableNC + i_iis);
    memcpy( hostScomTableNext, (void*)bufRNNN, XIPSIZE_SCOM_ENTRY);
  }

	hostScomTableL2 = (void*)((uintptr_t)hostScomTableNC + SLW_SCOM_TABLE_SIZE_NC);
	hostScomTableL3 = (void*)((uintptr_t)hostScomTableL2 + SLW_SCOM_TABLE_SIZE_L2);

	// ... get location of  ----> Scom NC <----  vector from TOC.
  rc = sbe_xip_find( io_image, SLW_HOST_SCOM_NC_VECTOR_TOC_NAME, &xipTocItem);
  if (rc)  {
    MY_ERR("sbe_xip_find() failed w/rc=%i and %s", rc, SBE_XIP_ERROR_STRING(errorStrings, rc));
    MY_ERR("Probable cause:");
    MY_ERR("\tThe keyword (=%s) was not found.",SLW_HOST_SCOM_NC_VECTOR_TOC_NAME);
    return IMGBUILD_ERR_KEYWORD_NOT_FOUND;
  }
  sbe_xip_pore2host( io_image, xipTocItem.iv_address, &hostScomVectorFirstNC);

  // ... update Scom NC vector.
	sbe_xip_host2pore( io_image, hostScomTableNC, &xipScomTableNC);
  for (i_coreId=0; i_coreId<SLW_MAX_CORES; i_coreId++)  {
    hostScomVectorNext = (void*)( (uint64_t*)hostScomVectorFirstNC + i_coreId);
    *(uint64_t*)hostScomVectorNext = myRev64( xipScomTableNC +
                                              SLW_SCOM_TABLE_SPACE_PER_CORE_NC*i_coreId);
  }

	// ... get location of  ----> Scom L2 <----  vector from TOC.
  rc = sbe_xip_find( io_image, SLW_HOST_SCOM_L2_VECTOR_TOC_NAME, &xipTocItem);
  if (rc)  {
    MY_ERR("sbe_xip_find() failed w/rc=%i and %s", rc, SBE_XIP_ERROR_STRING(errorStrings, rc));
    MY_ERR("Probable cause:");
    MY_ERR("\tThe keyword (=%s) was not found.",SLW_HOST_SCOM_L2_VECTOR_TOC_NAME);
    return IMGBUILD_ERR_KEYWORD_NOT_FOUND;
  }
  sbe_xip_pore2host( io_image, xipTocItem.iv_address, &hostScomVectorFirstL2);

  // ... update Scom L2 vector.
	sbe_xip_host2pore( io_image, hostScomTableL2, &xipScomTableL2);
  for (i_coreId=0; i_coreId<SLW_MAX_CORES; i_coreId++)  {
    hostScomVectorNext = (void*)( (uint64_t*)hostScomVectorFirstL2 + i_coreId);
    *(uint64_t*)hostScomVectorNext = myRev64( xipScomTableL2 +
                                              SLW_SCOM_TABLE_SPACE_PER_CORE_L2*i_coreId);
  }

	// ... get location of  ----> Scom L3 <----  vector from TOC.
  rc = sbe_xip_find( io_image, SLW_HOST_SCOM_L3_VECTOR_TOC_NAME, &xipTocItem);
  if (rc)  {
    MY_ERR("sbe_xip_find() failed w/rc=%i and %s", rc, SBE_XIP_ERROR_STRING(errorStrings, rc));
    MY_ERR("Probable cause:");
    MY_ERR("\tThe keyword (=%s) was not found.",SLW_HOST_SCOM_L3_VECTOR_TOC_NAME);
    return IMGBUILD_ERR_KEYWORD_NOT_FOUND;
  }
  sbe_xip_pore2host( io_image, xipTocItem.iv_address, &hostScomVectorFirstL3);

  // ... update Scom L3 vector.
	sbe_xip_host2pore( io_image, hostScomTableL3, &xipScomTableL3);
  for (i_coreId=0; i_coreId<SLW_MAX_CORES; i_coreId++)  {
    hostScomVectorNext = (void*)( (uint64_t*)hostScomVectorFirstL3 + i_coreId);
    *(uint64_t*)hostScomVectorNext = myRev64( xipScomTableL3 +
                                              SLW_SCOM_TABLE_SPACE_PER_CORE_L3*i_coreId);
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
//	uint64_t xipSlwExEnableRuntimeAddr;

  SBE_XIP_ERROR_STRINGS(errorStrings);

	// Get address of sub_slw_runtime_scom subroutine.
	//
	rc = sbe_xip_get_scalar( io_image, SLW_RUNTIME_SCOM_TOC_NAME, &xipSlwRuntimeAddr);
  if (rc)  {
    MY_ERR("sbe_xip_set_scalar() failed w/rc=%i and %s", rc, SBE_XIP_ERROR_STRING(errorStrings, rc));
    MY_ERR("Probable cause:");
    MY_ERR("\tThe keyword (=%s) was not found.",SLW_RUNTIME_SCOM_TOC_NAME);
		return IMGBUILD_ERR_KEYWORD_NOT_FOUND;
  }

	// Update host_runtime_scom with sub_slw_runtime_scom's address.
	//
  rc = sbe_xip_set_scalar( io_image, HOST_RUNTIME_SCOM_TOC_NAME, xipSlwRuntimeAddr);
  if (rc)  {
    MY_ERR("sbe_xip_set_scalar() failed w/rc=%i and %s", rc, SBE_XIP_ERROR_STRING(errorStrings, rc));
    MY_ERR("Probable cause:");
    MY_ERR("\tThe keyword (=%s) was not found.",HOST_RUNTIME_SCOM_TOC_NAME);
		return IMGBUILD_ERR_KEYWORD_NOT_FOUND;
  }

/*
  // Get address of sub_slw_ex_enable_runtime_scom subroutine.
	//
	rc = sbe_xip_get_scalar( io_image, SLW_EX_ENABLE_RUNTIME_SCOM_TOC_NAME, &xipSlwExEnableRuntimeAddr);
  if (rc)  {
    MY_INF("WARNING : sbe_xip_get_scalar() failed w/rc=%i and msg=%s, but it's probably OK.", rc, SBE_XIP_ERROR_STRING(errorStrings, rc));
		MY_INF("Will skip trying to update ex_enable_runtime_scom.\n");
    MY_INF("Probable cause:");
    MY_INF("\tThe keyword (=%s) was not found.",SLW_EX_ENABLE_RUNTIME_SCOM_TOC_NAME);
  }
  else  {
		// Next, update ex_enable_runtime_scom with sub_slw_ex_enable_runtime_scom's address.
		// (Assumption is that if sub_slw_ex_enable... exists then ex_enable... exists too.)
	  rc = sbe_xip_set_scalar( io_image, EX_ENABLE_RUNTIME_SCOM_TOC_NAME, xipSlwExEnableRuntimeAddr);
	  if (rc)  {
	    MY_ERR("sbe_xip_set_scalar() failed w/rc=%i and msg=%s", rc, SBE_XIP_ERROR_STRING(errorStrings, rc));
			MY_ERR("This is an odd error, indicating messed up or old image.\n");
	    MY_ERR("Probable cause:");
	    MY_ERR("\tThe keyword (=%s) was not found.",EX_ENABLE_RUNTIME_SCOM_TOC_NAME);
			return IMGBUILD_ERR_KEYWORD_NOT_FOUND;
	  }
	}
*/

  return 0;
}


// write_vpd_ring_to_ipl_image()
// - For VPD rings, there is no notion of a base and override ring. There can only be
//   one ring. Thus, for core ID specific rings, their vector locations are updated only
//   by 8-bytes, unlike 16-bytes for non-VPD rings which have base+override.
// - Any ring, including ex_ rings, that have a chipletId==0xFF will get stored at its
//   zero-offset position, i.e. as if it was coreId=0, or chipletId=0x10.
// - For IPL images, #R/G must be accessible through .fixed_toc since .toc is removed.
//   and same is true for proc_sbe_decompress_scan_chiplet_address (for RS4 launch.)
// Notes:
// - This code has great similarity to write_delta_ring_to_image() in p8_delta_scan_w.C.
//   Consider merging the two codes.
int write_vpd_ring_to_ipl_image(void			*io_image,
                                uint32_t  &io_sizeImageOut,
														  	CompressedScanData *i_bufRs4Ring, // HB buf1. BE format.
															  uint32_t  i_ddLevel,
															  uint8_t   i_sysPhase,
															  char 			*i_ringName,
															  void      *i_bufTmp,              // HB buf2
															  uint32_t  i_sizeBufTmp,
                                uint8_t   i_xipSectionId)         // Used by delta_scan()
{
	uint32_t rc=0, bufLC;
	uint8_t  chipletId, idxVector=0;
	uint32_t sizeRs4Launch, sizeRs4Ring;
	uint32_t sizeImageIn,sizeImage;
	PoreInlineContext ctx;
	uint32_t asmInitLC=0;
	uint32_t asmBuffer[ASM_RS4_LAUNCH_BUF_SIZE/4];
	uint64_t scanChipletAddress=0;

  SBE_XIP_ERROR_STRINGS(errorStrings);

	MY_INF("i_ringName=%s; \n",	i_ringName);

  if (i_bufTmp == NULL)  {
    MY_ERR("\tTemporary ring buffer passed by caller points to NULL and is invalid.\n");
    return IMGBUILD_ERR_MEMORY;
  }

  sbe_xip_image_size( io_image, &sizeImageIn);

  chipletId = i_bufRs4Ring->iv_chipletId;

	// Create RS4 launcher and store in asmBuffer.
	//
	rc = sbe_xip_get_scalar( io_image, "proc_sbe_decompress_scan_chiplet_address", &scanChipletAddress);
  if (rc)   {
      MY_INF("\tWARNING: sbe_xip_get_scalar() failed: %s\n", SBE_XIP_ERROR_STRING(errorStrings, rc));
      if (rc==SBE_XIP_ITEM_NOT_FOUND)  {
				MY_ERR("\tProbable cause:\n");
				MY_ERR("\t\tThe key word (=proc_sbe_decompress_scan_chiplet_address) does not exist in the image. (No TOC record.)\n");
				return IMGBUILD_ERR_KEYWORD_NOT_FOUND;
			}
			else
      if (rc==SBE_XIP_BUG)  {
				MY_ERR("\tProbable cause:\n");
				MY_ERR("\t\tIllegal keyword, maybe?\n");
				return IMGBUILD_ERR_XIP_MISC;
			}
			else  {
				MY_ERR("\tUnknown cause.\n");
  	    return IMGBUILD_ERR_XIP_UNKNOWN;
  	  }
  }
  if (scanChipletAddress==0)  {
  	MY_ERR("\tValue of key word (proc_sbe_decompress_scan_chiplet_address=0) is not permitted. Exiting.\n");
  	return IMGBUILD_ERR_CHECK_CODE;
  }
  // Now, create the inline assembler code.
	rc = pore_inline_context_create( &ctx, asmBuffer, ASM_RS4_LAUNCH_BUF_SIZE, asmInitLC, 0);
	if (rc)  {
		MY_ERR("\tpore_inline_context_create() failed w/rc=%i =%s\n", rc, pore_inline_error_strings[rc]);
		return IMGBUILD_ERR_PORE_INLINE;
	}
	pore_MR(&ctx, A0, PC);
	pore_ADDS(&ctx, A0, A0, ASM_RS4_LAUNCH_BUF_SIZE);
	pore_LI(&ctx, D0, scanChipletAddress);
	pore_BRAD(&ctx, D0);
	if (ctx.error)  {
		MY_ERR("\tpore_MR/ADDS/LI/BRAD() failed w/rc=%i =%s\n", ctx.error, pore_inline_error_strings[ctx.error]);
		return IMGBUILD_ERR_PORE_INLINE_ASM;
	}

	// Check sizeRs4Launch and that sizeRs4Launch and sizeRs4Ring both are 8-byte aligned.
	sizeRs4Launch = ctx.lc - asmInitLC;
	sizeRs4Ring = myRev32(i_bufRs4Ring->iv_size);
	if (sizeRs4Launch!=ASM_RS4_LAUNCH_BUF_SIZE)  {
		MY_ERR("\tSize of RS4 launch code differs from assumed size.\n\tsizeRs4Launch=%i\n\tASM_RS4_LAUNCH_BUF_SIZE=%i\n",
		  sizeRs4Launch,ASM_RS4_LAUNCH_BUF_SIZE);
			return IMGBUILD_ERR_CHECK_CODE;
	}
	if (sizeRs4Launch%8 || sizeRs4Ring%8)  {
		MY_ERR("\tRS4 launch code or data not 8-byte aligned.\n\tsizeRs4Launch=%i\n\tASM_RS4_LAUNCH_BUF_SIZE=%i\n\tsizeRs4Ring=%i\n",
		  sizeRs4Launch,ASM_RS4_LAUNCH_BUF_SIZE,sizeRs4Ring);
			return IMGBUILD_ERR_CHECK_CODE;
	}

	// Populate ring header and put ring header and Rs4 ring into
	// proper spots in pre-allocated bufRs4RingBlock buffer (HB buf2).
	//
	DeltaRingLayout *bufRs4RingBlock;
	uint64_t entryOffsetRs4RingBlock;
	uint32_t sizeRs4RingBlock, sizeRs4RingBlockMax;

	bufRs4RingBlock = (DeltaRingLayout*)i_bufTmp; //HB buf2.
  sizeRs4RingBlockMax = i_sizeBufTmp;
  entryOffsetRs4RingBlock      = calc_ring_layout_entry_offset( 0, 0);
  bufRs4RingBlock->entryOffset = myRev64(entryOffsetRs4RingBlock);
  bufRs4RingBlock->backItemPtr = 0; // Will be updated later.
	sizeRs4RingBlock     	       =	entryOffsetRs4RingBlock +  // Must be 8-byte aligned.
  												        sizeRs4Launch +            // Must be 8-byte aligned.
  												        sizeRs4Ring;               // Must be 8-byte aligned.
	// Quick check to see if final ring block size will fit in HB buffer.
	if (sizeRs4RingBlock>sizeRs4RingBlockMax)  {
	  MY_ERR("RS4 ring block size (=%i) exceeds HB buf2 size (=%i).",
	    sizeRs4RingBlock, sizeRs4RingBlockMax);
	  return IMGBUILD_ERR_RING_TOO_LARGE;
	}
	// Populate RS4 ring block members.
	bufRs4RingBlock->sizeOfThis  = myRev32(sizeRs4RingBlock);
	bufRs4RingBlock->sizeOfMeta	 = 0;
	bufRs4RingBlock->ddLevel     = myRev32(i_ddLevel);
	bufRs4RingBlock->sysPhase    = i_sysPhase;
	bufRs4RingBlock->override    = 0;
	bufRs4RingBlock->reserved1   = 0;
	bufRs4RingBlock->reserved2   = 0;
  // Add the RS4 launch code and RS4 ring data...
	bufLC = (uint32_t)entryOffsetRs4RingBlock;
	// Copy over meta data which is zero, so nothing to do in this case!
	// Copy over RS4 launch code which is already 8-byte aligned.
	memcpy( (uint8_t*)bufRs4RingBlock+bufLC, (uint8_t*)asmBuffer, (size_t)sizeRs4Launch);
	bufLC = bufLC + sizeRs4Launch;
	// Copy over RS4 delta ring which is already BE formatted.
	memcpy( (uint8_t*)bufRs4RingBlock+bufLC, (uint8_t*)i_bufRs4Ring, (size_t)sizeRs4Ring);

  // Now, some post-sanity checks on alignments.
	if ( entryOffsetRs4RingBlock%8 ||
	     sizeRs4RingBlock%8)  {
		MY_ERR("Member(s) of RS4 ring block are not 8-byte aligned; \n");
    MY_ERR("  Entry offset            = %i; \n", (uint32_t)entryOffsetRs4RingBlock);
		MY_ERR("  Size of ring block      = %i; \n", sizeRs4RingBlock);
		return IMGBUILD_ERR_MISALIGNED_RING_LAYOUT;
	}

  // Calculate any vector offset, i.e., in case of ex_ chiplet common ring name.
	if (chipletId>=CID_EX_LOW && chipletId<=CID_EX_HIGH)
    idxVector = chipletId - CID_EX_LOW;
	else
  	idxVector = 0;

    // Write ring block to image.
    sbe_xip_image_size( io_image, &sizeImage);
    rc = write_ring_block_to_image(io_image,
                                   i_ringName,
                                   bufRs4RingBlock,
                                   idxVector,
                                   0,
                                   0,
                                   io_sizeImageOut,
                                   i_xipSectionId,
                                   (void*)i_bufRs4Ring, // Reuse buffer as temp work buf.
                                   i_sizeBufTmp);
    if (rc)  {
      MY_ERR("write_ring_block_to_image() failed w/rc=%i \n",rc);
      MY_ERR("Check p8_delta_scan_rw.h for meaning of IMGBUILD_xyz rc code. \n");
      MY_ERR("Ring name: %s\n ", i_ringName);
      MY_ERR("Size of image before wrbti() call: %i\n ", sizeImage);
      MY_ERR("Size of ring block being added: %i\n ", sizeRs4RingBlock);
      MY_ERR("Max size of image allowed: %i\n ", io_sizeImageOut);
      if (rc==SBE_XIP_WOULD_OVERFLOW) {
        return rc;
      } else {
        return IMGBUILD_ERR_RING_WRITE_TO_IMAGE;
      }
    }

	MY_INF("\tSuccessful IPL image update; \n");

	return rc;
}


// write_vpd_ring_to_slw_image()
// - For VPD rings, there is no notion of a base and override ring. There can only be
//   one ring. Thus, for core ID specific rings, their vector locations are updated only
//   by 8-bytes, unlike 16-bytes for non-VPD rings which have base+override.
// - Any ring, including ex_ rings, that have a chipletId==0xFF will get stored at its
//   "top" or base position, i.e. as if it was coreId=0, or chipletId=0x10.
// - For IPL images, #R/G must be accessible through .fixed_toc since .toc is removed.
//   and same is true for proc_sbe_decompress_scan_chiplet_address (for RS4 launch.)
// Notes:
int write_vpd_ring_to_slw_image(void			*io_image,
                                uint32_t  &io_sizeImageOut,
														  	CompressedScanData *i_bufRs4Ring, // HB buf1. BE format.
															  uint32_t  i_ddLevel,
															  uint8_t   i_sysPhase,
															  char 			*i_ringName,
															  void      *i_bufTmp,              // HB buf2
															  uint32_t  i_sizeBufTmp,
																uint8_t 	i_bWcSpace)
{
	uint32_t rc=0, bufLC;
	uint8_t  chipletId, idxVector=0;
	uint32_t sizeRingRaw=0, sizeRingRawChk;
	uint32_t sizeImageIn,sizeImage;
	uint32_t *wfInline=NULL;
	uint32_t wfInlineLenInWords;
	uint64_t scanMaxRotate=SCAN_ROTATE_DEFAULT;
  uint64_t waitsScanDelay=0;
	uint64_t twinHaltOpCodes;
	uint32_t iFill;

	MY_INF("i_ringName=%s; \n",	i_ringName);

  if (i_bufTmp == NULL)  {
    MY_ERR("Temporary ring buffer passed by caller points to NULL and is invalid.\n");
    return IMGBUILD_ERR_MEMORY;
  }

  sbe_xip_image_size( io_image, &sizeImageIn);

  chipletId = i_bufRs4Ring->iv_chipletId;

  // Decompress RS4 VPD ring.
  //
  sizeRingRaw = myRev32(i_bufRs4Ring->iv_length);
  if ((sizeRingRaw+7)/8 > i_sizeBufTmp)  {
    MY_ERR("Decompressed byte size of VPD ring (=%i) exceeds size of buffer (=%i).",
      (sizeRingRaw+7)/8, i_sizeBufTmp);
    return IMGBUILD_ERR_RING_TOO_LARGE;
  }
  rc = _rs4_decompress((uint8_t*)i_bufTmp,
                       i_sizeBufTmp,
                       &sizeRingRawChk,  // Uncompressed raw ring size in bits.
                       i_bufRs4Ring);
  if (rc)  {
    MY_ERR("_rs4_decompress() failed w/rc=%i; ",rc);
    return IMGBUILD_ERR_RS4_DECOMPRESS;
  }
  if (sizeRingRaw != sizeRingRawChk)  {
    MY_ERR("Ring size from RS4 container (=%i) differs from ring size returned by _rs4_decompress (=%i).",
      sizeRingRaw, sizeRingRawChk);
    return IMGBUILD_ERR_RS4_DECOMPRESS;
  }

	// Create wiggle-flip program.
	//
	rc = sbe_xip_get_scalar( io_image, SCAN_MAX_ROTATE_38XXX_NAME, &scanMaxRotate);
	if (rc)  {
	  MY_ERR("Strange error from sbe_xip_get_scalar(SCAN_MAX_ROTATE_38XXX_NAME) w/rc=%i; ",rc);
	  MY_ERR("Already retrieved SCAN_MAX_ROTATE_38XXX_NAME in slw_build() w/o trouble; ");
	  return IMGBUILD_ERR_XIP_MISC;
	}
	if (scanMaxRotate<0x20 || scanMaxRotate>SCAN_MAX_ROTATE)  {
	  MY_INF("WARNING: Value of key word SCAN_MAX_ROTATE_38XXX_NAME=0x%llx is not permitted; ",scanMaxRotate);
    scanMaxRotate = SCAN_ROTATE_DEFAULT;
		MY_INF("scanMaxRotate set to 0x%llx; ", scanMaxRotate);
		MY_INF("Continuing...; ");
	}

  // Temporary support for enforcing delay after scan WF scoms.
  // Also remove all references and usages of waitsScanDelay in this file.
  rc = sbe_xip_get_scalar( io_image, "waits_delay_for_scan", &waitsScanDelay);
  if (rc)  {
    MY_ERR("Error obtaining waits_delay_for_scan keyword.\n");
	  return IMGBUILD_ERR_XIP_MISC;
  }

	wfInline = (uint32_t*)i_bufRs4Ring;  // Reuse this buffer (HB buf1) for wiggle-flip prg.
	wfInlineLenInWords = i_sizeBufTmp/4; // Assuming same size of both HB buf1 and buf2.
	rc = create_wiggle_flip_prg((uint32_t*)i_bufTmp,
	                            sizeRingRaw,
	                            myRev32(i_bufRs4Ring->iv_scanSelect),
	                            (uint32_t)i_bufRs4Ring->iv_chipletId,
	                            &wfInline,
	                            &wfInlineLenInWords, // Is 8-byte aligned on return.
                              i_bufRs4Ring->iv_flushOptimization,
	                            (uint32_t)scanMaxRotate,
                              (uint32_t)waitsScanDelay,
                              i_ddLevel );
	if (rc)  {
	  MY_ERR("create_wiggle_flip_prg() failed w/rc=%i; ",rc);
	  return IMGBUILD_ERR_WF_CREATE;
	}

  // Populate ring header and put ring header and Wf ring into
  // proper spots in pre-allocated bufWfRingBlock buffer (HB buf2).
  //
  DeltaRingLayout *bufWfRingBlock;
  uint64_t entryOffsetWfRingBlock;
  uint32_t sizeWfRingBlock, sizeWfRingBlockMax;

  bufWfRingBlock = (DeltaRingLayout*)i_bufTmp; // Reuse this buffer (HB buf2) for WF ring block.
  sizeWfRingBlockMax = i_sizeBufTmp;
  entryOffsetWfRingBlock      = calc_ring_layout_entry_offset( 1, 0);
  bufWfRingBlock->entryOffset = myRev64(entryOffsetWfRingBlock);
  bufWfRingBlock->backItemPtr	= 0; // Will be updated below, as we don't know yet.

	// Allocate either fitted or worst-case space for the ring.  For example, the
	// rings, ex_repr_core/eco, need worst-case space allocation.
	if (i_bWcSpace==0)  {
		// Fitted space sizing.
		sizeWfRingBlock =	entryOffsetWfRingBlock +  // Must be 8-byte aligned.
  									  wfInlineLenInWords*4;     // Must be 8-byte aligned.
	}
	else  {
		// Worst-case space sizing.
		sizeWfRingBlock = ((sizeRingRaw-1)/32 + 1) * 4 * WF_WORST_CASE_SIZE_FAC +
											WF_ENCAP_SIZE;
		sizeWfRingBlock = (uint32_t)myByteAlign(8, sizeWfRingBlock);
		// Fill void with "halt" instructions, 0x02000000 (LE). Note, void is whole multiple of 8x.
    twinHaltOpCodes = myRev64((uint64_t)0x02000000<<32 | (uint64_t)0x02000000);
		for (iFill=0; iFill<(sizeWfRingBlock-entryOffsetWfRingBlock); iFill=iFill+8)  {
			*(uint64_t*)((uint64_t)bufWfRingBlock+entryOffsetWfRingBlock+iFill) = twinHaltOpCodes;
		}
	}
	// Quick check to see if final ring block size will fit in HB buffer.
	if (sizeWfRingBlock>sizeWfRingBlockMax)  {
	  MY_ERR("WF ring block size (=%i) exceeds HB buf2 size (=%i).",
	    sizeWfRingBlock, sizeWfRingBlockMax);
	  return IMGBUILD_ERR_RING_TOO_LARGE;
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
		MY_ERR("Member(s) of WF ring block are not 8-byte aligned:");
    MY_ERR("  Entry offset            = %i", (uint32_t)entryOffsetWfRingBlock);
		MY_ERR("  Size of ring block      = %i", sizeWfRingBlock);
		return IMGBUILD_ERR_MISALIGNED_RING_LAYOUT;
	}

  // Calculate any vector offset, i.e., in case of ex_ chiplet common ring name.
	if (chipletId>=CID_EX_LOW && chipletId<=CID_EX_HIGH)
    idxVector = chipletId - CID_EX_LOW;
	else
  	idxVector = 0;

    // Write ring block to image.
    sbe_xip_image_size( io_image, &sizeImage);
    rc = write_ring_block_to_image(io_image,
                                   i_ringName,
                                   bufWfRingBlock,
                                   idxVector,
                                   0,
                                   0,
                                   io_sizeImageOut,
                                   SBE_XIP_SECTION_RINGS,
                                   (void*)i_bufRs4Ring, // Reuse buffer as temp work buf.
                                   i_sizeBufTmp);
    if (rc)  {
      MY_ERR("write_ring_block_to_image() failed w/rc=%i; \n",rc);
      MY_ERR("Check p8_delta_scan_rw.h for meaning of IMGBUILD_xyz rc code; \n");
      MY_ERR("Ring name: %s\n ", i_ringName);
      MY_ERR("Size of image before wrbti() call: %i\n ", sizeImage);
      MY_ERR("Size of ring block being added: %i\n ", sizeWfRingBlock);
      MY_ERR("Max size of image allowed: %i\n ", io_sizeImageOut);
      if (rc==SBE_XIP_WOULD_OVERFLOW) {
        return rc;
      } else {
        return IMGBUILD_ERR_RING_WRITE_TO_IMAGE;
      }
    }

	MY_INF("Successful SLW image update; \n");

	return rc;
}


// check_and_perform_ring_datacare()
//
// Checks if the Mvpd ring passed has a datacare ring in the .dcrings image section. If it does,
// the Mvpd's ring bits corresponding to the care bits in the 1st half of the dc cring will be
// overwritten by the data bits in the 2nd half of the dc ring.
int check_and_perform_ring_datacare(	void     *i_imageRef,
																			void  	 *io_buf1, // Mvpd ring in/out. BE format.
																			uint8_t  i_ddLevel,
																			uint8_t  i_sysPhase,
																			char     *i_ringName,
																			void     *io_buf2, // Work buffer.
																			uint32_t i_sizeBuf2)
{
	int         rc=0, rcLoc=0;
	uint32_t    bitLength, ringBitLen, ringBitLenDc;
	uint32_t    scanSelect;
	uint8_t     ringId, chipletId, flushOpt;
	DeltaRingLayout  *rs4Datacare=NULL;
	void        *nextRing=NULL;
	SbeXipItem  xipTocItem;
	uint8_t     bMatch=0;
	uint32_t		sizeRs4Container;


	bitLength  = myRev32(((CompressedScanData*)io_buf1)->iv_length);
	scanSelect = myRev32(((CompressedScanData*)io_buf1)->iv_scanSelect);
	ringId     = ((CompressedScanData*)io_buf1)->iv_ringId;
	chipletId  = ((CompressedScanData*)io_buf1)->iv_chipletId;
	flushOpt   = ((CompressedScanData*)io_buf1)->iv_flushOptimization;

	MY_INF("In check_and_perform_ring_datacare()...\n");

	MY_DBG("Mvpd ring characteristics:\n");
	MY_DBG("Ring name:   %s\n",i_ringName);
	MY_DBG("Ring ID:     0x%02x\n",ringId);
	MY_DBG("Chiplet ID:  0x%02x\n",chipletId);
	MY_DBG("Flush Opt:   %i\n",flushOpt);
	MY_DBG("Scan select: 0x%08x\n",scanSelect);

	rc = sbe_xip_find( i_imageRef, i_ringName, &xipTocItem);
	if (rc)  {
		MY_ERR("_find() failed w/rc=%i\n",rc);
		return IMGBUILD_ERR_KEYWORD_NOT_FOUND;
	}
	MY_DBG("xipTocItem.iv_address=0x%016llx\n",xipTocItem.iv_address);

	// Now look for datacare match in .dcrings section.
	nextRing = NULL;
	rs4Datacare = NULL;
	bMatch = 0;
	do  {
		// Retrieve ptr to next ring in .dcrings
		rcLoc = get_ring_layout_from_image2(i_imageRef,
																				i_ddLevel,
																				i_sysPhase,
																				&rs4Datacare, // Will pt to gptr overlay ring.
																				&nextRing,
																				SBE_XIP_SECTION_DCRINGS);
		if (rcLoc==IMGBUILD_RING_SEARCH_MATCH ||
				rcLoc==IMGBUILD_RING_SEARCH_EXHAUST_MATCH ||
				rcLoc==IMGBUILD_RING_SEARCH_NO_MATCH)  {
			MY_DBG("get_ring_layout_from_image2() returned rc=%i \n",rc);
			rc = 0;
		}
		else {
			MY_ERR("get_ring_layout_from_image2() failed w/rc=%i\n",rcLoc);
			return IMGBUILD_ERR_RING_SEARCH;
		}
		// Does the rings backPtr match the Vpd ring's vector addr?
		if (rs4Datacare)  {
			MY_DBG("rs4Datacare->backItemPtr=0x%016llx\n",myRev64(rs4Datacare->backItemPtr));
			if (myRev64(rs4Datacare->backItemPtr)==xipTocItem.iv_address)  {
				MY_DBG("Found a match in .dcrings. \n");
				bMatch = 1;
				// TBD
			}
		}
		else
			MY_DBG("rs4Datacare=NULL (no ring matched search criteria, or empty ring section.)\n");
	}  while (nextRing!=NULL && !bMatch);

	if (bMatch)  {

		// Decompress Mvpd ring.
		MY_DBG("Decompressing Mvpd ring.\n");
	 	rc = _rs4_decompress( (uint8_t*)io_buf2,
	   	                    i_sizeBuf2,
													&ringBitLen,
	    	                  (CompressedScanData*)io_buf1);
	 	if (rc)  {
	 	  MY_ERR("_rs4_decompress(mvpdring...) failed: rc=%i\n",rc);
	 	  return IMGBUILD_ERR_RS4_DECOMPRESS;
	 	}

		// Decompress datacare overlay ring.
		MY_DBG("Decompressing datacare ring.\n");
  	rc = _rs4_decompress( (uint8_t*)io_buf1,
    	                    i_sizeBuf2, // Assumption is that sizeBuf2=sizeBuf1
													&ringBitLenDc,
        	                (CompressedScanData*)( (uintptr_t)rs4Datacare +
																								 myRev64(rs4Datacare->entryOffset) +
																								 ASM_RS4_LAUNCH_BUF_SIZE) );
  	if (rc)  {
  	  MY_ERR("_rs4_decompress(datacare...) failed: rc=%i\n",rc);
  	  return IMGBUILD_ERR_RS4_DECOMPRESS;
  	}

		MY_DBG("bitLength=%i\n",bitLength);
		MY_DBG("ringBitLen=%i\n",ringBitLen);
		MY_DBG("ringBitLenDc=%i\n",ringBitLenDc);
		if ( bitLength!=ringBitLen || (2*ringBitLen)!=ringBitLenDc )  {
			MY_ERR("Mvpd ring length (=%i) is not exactly half of datacare ring length (=%i)\n",
							ringBitLen, ringBitLenDc);
			return IMGBUILD_ERR_DATACARE_RING_MESS;
		}

                // Overlay io_buf2 bits according to care and data bits in io_buf1

                // Split apart the raw datacare ring into data (1st part) and care (2nd part).
                // Note that the order is already in BE for both Datacare and Mvpd rings.
                // Further note that the care part is fractured into two words that need to
                //   be combined into a single word. (That's the black magic part below).
                // Once there are less than two words left to process, care part will be
                // less than two words from the buffer end, so go byte-by-byte at that point
                uint32_t dataVpd, dataDc, careDc, careDc1, careDc2;
                int32_t remBits = ringBitLen;
                uint32_t * pDataWord = (uint32_t*)io_buf1;
                uint32_t * pCareWord = (uint32_t*)io_buf1 + (ringBitLen/32);
                uint32_t * pDataVPD  = (uint32_t*)io_buf2;
                uint32_t careLeftShift = ringBitLen%32;
                uint32_t careRightShift = 32-careLeftShift;
                while (remBits > 64) {
                    dataDc  = *pDataWord++;                         // Data part
                    // Split off the care part, do BE->LE, shift the two parts properly, and finally do
                    //   LE->BE again. It's f*kin' black magic...
                    careDc1 = myRev32(*pCareWord++);                // Care part a
                    careDc2 = myRev32(*pCareWord);                  // Care part b
                    careDc  = myRev32(careDc1<<careLeftShift | careDc2>>careRightShift);
                    dataVpd = *(pDataVPD);
                    MY_DBG("data: %08x  remBits=%i\n",dataDc,remBits);
                    MY_DBG("care: %08x\n",careDc);
                    MY_DBG("orig: %08x\n",dataVpd);
                    dataVpd = ( dataVpd & ~careDc ) | dataDc;
                    MY_DBG("new:  %08x\n",dataVpd);
                    *pDataVPD++ = dataVpd;
                    // Check for data+care construction. I.e., a 1-bit in data is illegal if corresponding
                    //   care bit is a 0-bit.
                    if ((dataDc & ~careDc)!=0)  {
                        MY_ERR("DataCare ring construction error:\n");
                        MY_ERR("A data bit (in word i=%i) is set but the care bit is not set.\n",
                               (ringBitLen-remBits)/32);
                        return IMGBUILD_ERR_DATACARE_RING_MESS;
                    }
                    remBits-=32;
                }
                //Less than 64 bits left, so must do byte-by-byte modifications
                uint8_t dataVpdByte, dataDcByte, careDcByte, careDc1Byte, careDc2Byte;
                uint8_t * pDataByte = (uint8_t*)pDataWord;
                uint8_t * pCareByte = (uint8_t*)pCareWord;
                uint8_t * pDataVPDByte = (uint8_t*)pDataVPD;
                careLeftShift = ringBitLen%8;
                careRightShift = 8-careLeftShift;
                while(remBits > 0) {
                    dataDcByte = *pDataByte++;                     // Data part
                    // Split off the care part and shift the two parts propoerly
                    careDc1Byte = *pCareByte++;                    // Care part a
                    if(remBits > 8) {
                        careDc2Byte = *pCareByte;                  // Care part b
                        careDcByte = ((careDc1Byte<<careLeftShift) | (careDc2Byte>>careRightShift));
                    } else {
                        careDcByte = careDc1Byte << careLeftShift; // There is no part b
                    }
                    dataVpdByte = *(pDataVPDByte);
                    MY_DBG("data: %02x  remBits=%i\n",dataDcByte,remBits);
                    MY_DBG("care: %02x\n",careDcByte);
                    MY_DBG("orig: %02x\n",dataVpdByte);
                    dataVpdByte = ( dataVpdByte & ~careDcByte ) | dataDcByte;
                    MY_DBG("new:  %02x\n",dataVpdByte);
                    *pDataVPDByte++ = dataVpdByte;
                    // Check for data+care construction. I.e., a 1-bit in data is illegal if corresponding
                    //   care bit is a 0-bit.
                    if ((dataDcByte & ~careDcByte)!=0)  {
                        MY_ERR("DataCare ring construction error:\n");
                        MY_ERR("A data bit (in byte i=%i) is set but the care bit is not set.\n",
                               (ringBitLen-remBits)/8);
                        return IMGBUILD_ERR_DATACARE_RING_MESS;
                    }
                    remBits-=8;
                  }

		// Compress overlayed Mvpd ring.
		rc = _rs4_compress(	(CompressedScanData*)io_buf1,
												i_sizeBuf2,
												&sizeRs4Container,
												(uint8_t*)io_buf2,
												bitLength,
												(uint64_t)scanSelect<<32,
												ringId,
												chipletId,
												flushOpt);
 		if (rc)  {
 		  MY_ERR("\t_rs4_compress() failed: rc=%i ",rc);
 		  return IMGBUILD_ERR_RS4_DECOMPRESS;
 		}

	}

	MY_INF("Leaving check_and_perform_ring_datacare()...\n");

	return rc;
}


// CMO-20130208: Not used in:
// - p8_image_help.C
// - p8_image_help_base.C
// - cen_xip_customize.C
// - p8_pore_table_gen_api.C
// - p8_slw_repair.C
// - ???
// It is used in:
// - p8_delta_scan_w
// - p8_delta_scan_r
// - ???
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

#endif // End of !(defined IMGBUILD_PPD_CEN_XIP_CUSTOMIZE)

}
