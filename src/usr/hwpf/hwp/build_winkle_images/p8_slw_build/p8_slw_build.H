/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_slw_build/p8_slw_build.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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

// $Id: p8_slw_build.H,v 1.4 2013-02-12 23:25:58 cmolsen Exp $

#include <fapi.H>

#include <p8_scan_compression.H>

typedef fapi::ReturnCode (*p8_slw_build_FP_t) (	const fapi::Target&, 
                                                const void*,
                                                uint32_t,
                                                void*,
                                                uint32_t*);

typedef fapi::ReturnCode (*p8_slw_build_fixed_FP_t) (	const fapi::Target&, 
                                                        void*,
                                                        void*,
                                                        uint32_t&,
                                                        const uint8_t, 
                                                        void*,
                                                        const uint32_t,
                                                        void*,
                                                        const uint32_t );

typedef fapi::ReturnCode (*p8_slw_repair_FP_t) (const fapi::Target&, 
                                                void*,
                                                CompressedScanData*,
                                                void*,
                                                const uint32_t,
                                                void*,
                                                const uint32_t);


extern "C"
{
	// Description:  FAPI HWP entry point.  p8_slw_build() constructs the 
	//               Sleep-Winkle (SLW) image in mainstore during Hostboot
	//               IPL.
	// Parameters:   i_target:    Processor chip target.
	//               *i_imageIn:  Pointer to location of input SBE-XIP image.
	//               i_sizeImageIn: Size of input image.
	//               *i_imageOut: Pointer to location of output SLW image in
	//                            mainstore.
	//               *io_sizeImageOut: On input, upper limit of size of output 
	//                            image.  On output, final size of output image.
    fapi::ReturnCode p8_slw_build( 	const fapi::Target &i_target,
                                        const void 	*i_imageIn,
                                        uint32_t 		i_sizeImageIn,
                                        void 				*i_imageOut,
                                        uint32_t 		*io_sizeImageOut);


	// Description:  FAPI HWP entry point.  p8_slw_build_fixed() constructs the 
	//               fixed Sleep-Winkle (SLW) image in mainstore during Hostboot
	//               IPL, PHYP rebuild and non-fixed image for SRAM.
	// Parameters:   i_target:    Processor chip target.
	//               *i_imageIn:  Pointer to input Reference image (from PNOR).
	//               *i_imageOut: Pointer to output SLW image.
	//               &io_sizeImageOut: In: Max size of output img. 
	//                                 Out: Final size of output img.
  //               i_modeBuild:    0: HB/IPL mode, 1: PHYP/Rebuild mode, 
  //                               2: SRAM mode.
  //               *i_buf1:        Temp buffer 1 for dexed RS4 ring. (Caller 
  //                               allocs/frees.)
  //               i_sizeBuf1:     Size of buf1.
  //               *i_buf2:        Temp buffer 2 for WF ring. (Caller 
  //                               allocs/frees.)
  //               i_sizeBuf2:     Size of buf2.
        fapi::ReturnCode p8_slw_build_fixed( 	const fapi::Target &i_target,
                                                void               *i_imageIn,
                                                void               *i_imageOut,
                                                uint32_t           &io_sizeImageOut,
                                                const uint8_t      i_modeBuild, 
                                                void               *i_buf1,
                                                const uint32_t     i_sizeBuf1,
                                                void               *i_buf2,
                                                const uint32_t     i_sizeBuf2 );


	// Description:  FAPI HWP entry point.  p8_slw_repair() updates the L2 (core) 
	//               and L3 (eco) cashes during concurrent rebuilds.            
	// Parameters:   i_target:    Processor chip target.
	//               *io_image:   Pointer to SLW image.
	//               *i_bufRs4:   Pointer to the RS4 ring data.
  //               *i_buf1:        Temp buffer 1 for dexed RS4 ring. (Caller 
  //                               allocs/frees.)
  //               i_sizeBuf1:     Size of buf1.
  //               *i_buf2:        Temp buffer 2 for WF ring. (Caller 
  //                               allocs/frees.)
  //               i_sizeBuf2:     Size of buf2.
        fapi::ReturnCode p8_slw_repair( const fapi::Target &i_target, 
                                        void							 *io_image,
                                        CompressedScanData *i_bufRs4,
                                        void							 *i_buf1,
                                        const uint32_t		 i_sizeBuf1,
                                        void							 *i_buf2,
                                        const uint32_t		 i_sizeBuf2);

}
