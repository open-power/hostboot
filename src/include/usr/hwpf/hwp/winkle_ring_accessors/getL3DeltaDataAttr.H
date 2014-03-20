/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/winkle_ring_accessors/getL3DeltaDataAttr.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: getL3DeltaDataAttr.H,v 1.2 2014/03/20 16:24:43 whs Exp $
/**
 *  @file getL3DeltaDataAttr.H
 *
 *  @brief Prototype for getL3DeltaDataAttr() -
 *         fetch L3 delta data attribute based on chip EC and PROC_PBIEX_ASYNC_SEL from data from static arrays (fapiL3DeltaDataAttr.H)
 */

 #ifndef    _HWP_GETL3DELTADATAATTR_
 #define    _HWP_GETL3DELTADATAATTR_

#include   <fapi.H>
#include    <fapiL3DeltaDataAttr.H>

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*getL3DeltaDataAttr_FP_t)
     (const fapi::Target &, uint32_t (&)[DELTA_DATA_SIZE], uint32_t &);


extern "C"
{
/**
 * @brief   get processor ex func L3 delta data attribute for the specified target CPU.
 *
 * @param i_fapiTarget      -   cpu target
 * @param o_data            -   out:    L3 delta data data.
 * @param o_ringLength      -   out:    Length of decompressed data
 *
 * @return fapi::ReturnCode -   FAPI_RC_SUCCESS if success,
 *                              relevant error code for failure.
 */
fapi::ReturnCode getL3DeltaDataAttr( const fapi::Target  &i_fapiTarget,
                                     uint32_t (&o_data)[DELTA_DATA_SIZE],
                                     uint32_t (&o_ringLength));

}

#endif
