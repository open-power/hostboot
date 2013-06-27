/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_slw_build/p8_xip_customize.H $ */
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
// $Id: p8_xip_customize.H,v 1.8 2013/06/13 16:52:41 jeshua Exp $

#include <fapi.H>

typedef fapi::ReturnCode (*fapiGetMvpdField_FP_t) ( const fapi::MvpdRecord i_record,
                                                    const fapi::MvpdKeyword i_keyword,
                                                    const fapi::Target &i_procTarget,
                                                    uint8_t * const i_pBuffer,
                                                    uint32_t &io_fieldSize);

typedef fapi::ReturnCode (*p8_xip_customize_FP_t) (  const fapi::Target&, 
                                                    void*,
                                                    void*,
                                                    uint32_t&,
                                                    const uint8_t,
                                                    const uint8_t,
                                                    void*,
                                                    const uint32_t,
                                                    void*,
                                                    const uint32_t,
                                                     uint32_t& );

extern "C"
{

//
// Function declares.
//

  // Description: 
  // FAPI HWP entry point for p8_xip_customize().
  // p8_xip_customize() adds VPD rings to the IPL and SLW images and updates
  //   various vectors in the images.
  //
  // Parameters:  
  // fapi::Target &i_target:        Processor chip target.
  // void         *i_imageIn:       Ptr to input IPL or SLW image.
  // void         *i_imageOut:      Ptr to output IPL img. (Ignored for SLW/RAM imgs.)
  // uint32_t     &io_sizeImageOut: In: Max size of IPL/SRAM img. Out: Final size.
  // uint8_t      i_sysPhase:       0: IPL  1: SLW
  // uint8_t      i_modeBuild:      0: HB/IPL  1: PHYP/Rebuild  2: SRAM 
  // void         *i_buf1:          Temp buffer1 for dexed RS4 ring. Caller allocs/frees.
  // uint32_t     i_sizeBuf1:       Size of buf1.
  // void         *i_buf2:          Temp buffer2 for WF ring. Caller allocs/frees.
  // uint32_t     i_sizeBuf22       Size of buf2.
  // uint32_t     &io_bootCoreMask  In: Mask of the desired boot cores (bits 16:31 = EX0:EX15)
  //                                    (value is ignored when i_sysPhase != 0)
  //                                Out: Mask of the valid boot cores in the image
  fapi::ReturnCode p8_xip_customize( const fapi::Target &i_target,
                                     void           *i_imageIn,
                                     void           *i_imageOut,
                                     uint32_t       &io_sizeImageOut,
                                     const uint8_t  i_sysPhase,
                                     const uint8_t  i_modeBuild, 
                                     void           *i_buf1,
                                     const uint32_t i_sizeBuf1,
                                     void           *i_buf2,
                                     const uint32_t i_sizeBuf2,
                                     uint32_t       &io_bootCoreMask);
}
