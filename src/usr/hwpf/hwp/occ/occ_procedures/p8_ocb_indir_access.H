/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_ocb_indir_access.H $   */
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
// $Id: p8_ocb_indir_access.H,v 1.1 2012/08/23 04:58:50 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_ocb_indir_access.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : p8_ocb_indir_access.H
// *! DESCRIPTION : Access procedure to the OCC OCB indirect channels
// *!
// *! OWNER NAME : Jim Yacynych  Email: jimyac@us.ibm.com
// *! BACKUP NAME : Greg Still    Email: stillgs@us.ibm.com

//------------------------------------------------------------------------------

#ifndef _P8_OCBINDIRACC_H_
#define _P8_OCBINDIRACC_H_


extern "C" {


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------


// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*p8_ocb_indir_access_FP_t) 
                (   const fapi::Target&, 
                    uint32_t,  
                    uint32_t, 
                    uint32_t, 
                    ecmdDataBufferBase&, 
                    uint32_t&, 
                    bool, 
                    uint32_t
                );

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

#ifndef _P8_OCB_ACCESS_OP_
#define _P8_OCB_ACCESS_OP_
enum P8_OCB_ACCESS_OP {
        OCB_GET     = 0x1,
        OCB_PUT     = 0x2
        };
#endif  // _P8_OCB_ACCESS_OP_


//------------------------------------------------------------------------------
// Parameter structure definitions
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------

/// \brief Provides for the abstract access to an OCB indirect channel that has
/// been configured previously via p8_ocb_indir_setup_[linear/circular] 
/// procedures
/// 
/// \param[in]      &i_target           Chip target
/// \param[in]      i_ocb_chan          OCB channel number (0, 1, 2, 3) 
/// \param[in]      i_ocb_op            Operation (Get, Put)
/// \param[in]      i_ocb_req_length    Requested length in the number of 8B 
///                                     elements to be accessed (unit origin)
///                                     Number of bytes = (i_ocb_req_length) * 
///                                     8B
/// \param[in/out] &io_ocb_buffer       Reference to ecmdDataBuffer
/// \param[out]    &o_ocb_act_length    Address containing to contain the actual 
///                                     length in the number of 8B elements to 
///                                     be accessed (zero origin)
///                                     Number of bytes = (i_ocb_act_length+1) *
///                                     8B
/// \param[in]      i_oci_address_valid Indicator that oci_address is to be used
/// \param[in]      i_oci_address       OCI Address to be used for the operation

/// \retval ECMD_SUCCESS if something good happens,
/// \retval BAD_RETURN_CODE otherwise
fapi::ReturnCode 
p8_ocb_indir_access(const fapi::Target& i_target, 
                    uint32_t            i_ocb_chan, 
                    uint32_t            i_ocb_op, 
                    uint32_t            i_ocb_req_length, 
                    ecmdDataBufferBase& io_ocb_buffer,
                    uint32_t&           o_ocb_act_length, 
                    bool                i_oci_address_valid, 
                    uint32_t            i_oci_address);

                

} // extern "C"

#endif // _P8_OCBINDIRACC_H_
