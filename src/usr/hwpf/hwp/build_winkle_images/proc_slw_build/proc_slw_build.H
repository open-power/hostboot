/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/build_winkle_images/proc_slw_build/proc_slw_build.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */

#include <fapi.H>
#include "p8_delta_scan_rw.h"
#include "p8_pore_table_gen_api.H"

typedef fapi::ReturnCode (*proc_slw_build_FP_t) (	const fapi::Target&, 
																									const void*,
																									uint32_t,
																									void*,
																									uint32_t*);

extern "C"
{
	// Description:  FAPI HWP entry point.  proc_slw_build() constructs the 
	//               Sleep-Winkle (SLW) image in mainstore during Hostboot
	//               IPL.
	// Parameters:   i_target:    Processor chip target.
	//               *i_imageIn:  Pointer to location of input SBE-XIP image.
	//               i_sizeImageIn: Size of input image.
	//               *i_imageOut: Pointer to location of output SLW image in
	//                            mainstore.
	//               *io_sizeImageOut: On input, upper limit of size of output 
	//                            image.  On output, final size of output image.
	fapi::ReturnCode proc_slw_build( 	const fapi::Target &i_target,
																		const void 	*i_imageIn,
																		uint32_t 		i_sizeImageIn,
																		void 				*i_imageOut,
																		uint32_t 		*io_sizeImageOut);
}
