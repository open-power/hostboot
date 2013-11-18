/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/getPllRingAttr.H $                   */
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
// $Id: getPllRingAttr.H,v 1.1 2013/09/16 15:40:22 dpeterso Exp $
/**
 *  @file getPllRingAttr.H
 *
 *  @brief Prototype for getPllRingAttr() -
 *         fetch PLL ring attributes based on chip EC and frequencies
 *         from data from static arrays (fapiPllRingAttr.H)
 */

 #ifndef    _HWP_GETPLLRINGATTR_
 #define    _HWP_GETPLLRINGATTR_

#include   <fapi.H>
#define MAX_PLL_RING_SIZE_BYTES 256

//#include   <fapiPllRingAttr.H>


// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*getPllRingAttr_FP_t)
       (const fapi::AttributeId, const fapi::Target &, uint32_t &, uint8_t *);

extern "C"
{
/**
 * @brief   get specified PLL ring attribute for the specified target CPU.
 *
 * @param i_attrId          -   fapi attribute requested by the caller.
 * @param i_fapiTarget      -   cpu target
 * @param o_ringLength      -   out:    size of ring buffer that caller has
 *                                      allocated
 * @param 0_data            -   out:    PLL ring data.
 *
 * @return fapi::ReturnCode -   FAPI_RC_SUCCESS if success,
 *                              relevant error code for failure.
 */
    fapi::ReturnCode getPllRingAttr( const fapi::AttributeId  i_attrId,
                                     const fapi::Target  i_pChipTarget,
                                     uint32_t & o_ringBitLength,
                                     uint8_t *o_data);

}

#endif
