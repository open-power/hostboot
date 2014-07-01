/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/occ/occ_procedures/p8_ocb_indir_access.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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
// $Id: p8_ocb_indir_access.C,v 1.3 2014/03/07 14:55:01 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_ocb_indir_access.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Greg Still         Email: stillgs@us.ibm.com
// *!
/// \file p8_ocb_indir_access.C
/// \brief Performs the data transfer to/from an OCB indirect channel
///
///
/// \todo add to required proc ENUM requests
///
/// High-level procedure flow:
/// \verbatim
///
///
///     Per HW220256, for Murano DD1, a push (Put) must first check for non-full
///     condition to avoid a data corruption scenario.  This is fixed in
///     Venice DD1.
/// \endverbatim
///
/// buildfapiprcd -e "../../xml/error_info/proc_ocb_indir_access_errors.xml" p8_ocb_indir_access.C
//------------------------------------------------------------------------------


// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include "p8_pm.H"
#include "p8_ocb_indir_access.H"


using namespace fapi;

extern "C" {

// ----------------------------------------------------------------------
// Constant definitions
// ----------------------------------------------------------------------

// Needed for HW220256 protection
// Set to 10ms at 2us per read
//#define OCB_FULL_POLL_MAX 10000/2
// temp for sim
#define OCB_FULL_POLL_MAX 4
#define OCB_FULL_POLL_DELAY_HDW 0
#define OCB_FULL_POLL_DELAY_SIM 0

// ----------------------------------------------------------------------
// Global variables
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
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
p8_ocb_indir_access(  const fapi::Target& i_target, \
                      uint32_t            i_ocb_chan, \
                      uint32_t            i_ocb_op, \
                      uint32_t            i_ocb_req_length, \
                      ecmdDataBufferBase& io_ocb_buffer, \
                      uint32_t&           o_ocb_act_length, \
                      bool                i_oci_address_valid,  \
                      uint32_t            i_oci_address)
{
    
    fapi::ReturnCode    rc;
    uint32_t            l_ecmdRc = 0;
    ecmdDataBufferBase  data(64);
    ecmdDataBufferBase  address(64);
    
    uint64_t            OCBAR_address = 0;
    uint64_t            OCBDR_address = 0;
    uint64_t            OCBCSR_address = 0;
    uint64_t            OCBSHCR_address = 0;
    uint64_t            temp_address = 0;

    uint32_t            buffer_ptr;
    
    FAPI_INF("Executing p8_ocb_indir_access op %x channel %x of length (in 8B) %x....", 
            i_ocb_op, i_ocb_chan, i_ocb_req_length);
  
    FAPI_DBG("Checking channel validity");
    switch ( i_ocb_chan )
    {
        case 0:
            OCBAR_address = OCB0_ADDRESS_0x0006B010;
            OCBDR_address = OCB0_DATA_0x0006B015;
            OCBCSR_address = OCB0_STATUS_CONTROL_0x0006B011;
            OCBSHCR_address = OCB0_PUSH_STATUS_CONTROL_0x0006A204;
            break;
        case 1:
            OCBAR_address = OCB1_ADDRESS_0x0006B030;
            OCBDR_address = OCB1_DATA_0x0006B035;
            OCBCSR_address = OCB1_STATUS_CONTROL_0x0006B031;
            OCBSHCR_address = OCB1_PUSH_STATUS_CONTROL_0x0006A214;
            break;
        case 2:
            OCBAR_address = OCB2_ADDRESS_0x0006B050;
            OCBDR_address = OCB2_DATA_0x0006B055;
            OCBCSR_address = OCB2_STATUS_CONTROL_0x0006B051;
            OCBSHCR_address = OCB2_PUSH_STATUS_CONTROL_0x0006A224;
            break;
        case 3:
            OCBAR_address = OCB3_ADDRESS_0x0006B070;
            OCBDR_address = OCB3_DATA_0x0006B075;
            break;
        default:
            FAPI_ERR("Invalid OCB access channel %x", i_ocb_chan);
            FAPI_SET_HWP_ERROR(rc, RC_PROCPM_OCB_ACCESS_CHANNEL);
            return rc;
    }   

    /// -------------------------------
    /// Deal with oci_address_valid condition.
    /// If address is valid, write the relevant channel OCBAR
    if ( i_oci_address_valid )
    {

        /// The following cases apply:
        ///     Circular Channel:   OCBAR is irrelevant; write it anyway
        ///     Linear:             OCBAR will set the accessed location
        ///     Linear Stream:      OCBAR will establish the address from which
        ///                             auto-increment will commence after
        ///                             the first access

        /// \todo:  need to perform relevant error checking on the address value

        FAPI_DBG("OCI Address Valid set with OCI Address =  %08x", 
                i_oci_address);
 
        l_ecmdRc |= data.flushTo0();
        l_ecmdRc |= data.setWord(0, i_oci_address);    
        if (l_ecmdRc) 
        {
           FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", l_ecmdRc);
           rc.setEcmdError(l_ecmdRc);
           return rc;
         }

        rc=fapiPutScom(i_target, (const uint64_t)OCBAR_address, data);
        if(rc) 
        {
            FAPI_ERR("OCBAR Putscom failed");
            return rc;
        }

    }

    /// The else case is to not touch the OCBAR.
    /// The following cases apply:
    ///     Circular Channel:   OCBAR is irrelevant
    ///     Linear:             OCBAR will continue to access the same location
    ///     Linear Stream:      OCBAR will auto-increment

    // Initialize output length
    o_ocb_act_length    = 0;

    /// Based on the op, perform the data access
    if ( i_ocb_op == OCB_PUT ) 
    {

        // Start HW220256 protection
        
        // Determine if the channel is in circular mode.  If so, proceed with
        // checks.
      
        temp_address = OCBCSR_address;
        rc=fapiGetScom(i_target, temp_address, data);
        if (rc)
        {
            FAPI_ERR("Get SCOM error for address 0x%08llX", temp_address);
            return rc;
        }
        
        if (data.isBitSet(4) && data.isBitSet(5))
        {
            FAPI_DBG("Put: (MurDD1) Circular mode Put detected.  Engage extra checks");
            
            // Check if push queue is enabled.  If not, let the store occur 
            // anyway to let the PIB error response return occur.  (that is 
            // what will happen if this checking code were not here)
            temp_address = OCBSHCR_address;
            rc=fapiGetScom(i_target, temp_address, data);
            if (rc)
            {
                FAPI_ERR("Get SCOM error for address 0x%08llX", temp_address);
                return rc;
            }

            if (data.isBitSet(31))
            {           
                FAPI_DBG("Put: (MurDD1) Poll for a non-full condition to a push "
                            "queue to avoid data corruption problem");

                bool push_ok_flag = false; 
                int p = 0;
                do
                {
                    // If the OCB_OCI_OCBSHCS0_PUSH_FULL bit (bit 0) is clear, proceed.
                    // Otherwise, poll
                    if (data.isBitClear(0))
                    {
                        push_ok_flag = true;
                        FAPI_DBG("Put: (MurDD1) Push queue not full. Proceeding.");
                        break;
                    }            
                    
                    // Point to put in any needed delay.
                    // rc=fapiDelay(OCB_FULL_POLL_DELAY_HDW, OCB_FULL_POLL_DELAY_SIM);
                    
                    rc=fapiGetScom(i_target, temp_address, data);
                    if (rc)
                    {
                        FAPI_ERR("Get SCOM error for address 0x%08llX", temp_address);
                        return rc;
                    }
                    
                    p++;
                
                } while (p < OCB_FULL_POLL_MAX);
                   
                if (!push_ok_flag)
                {
                    FAPI_ERR("Put: Polling timeout waiting on push non-full");
                    FAPI_SET_HWP_ERROR(rc, RC_PROCPM_OCB_PUT_DATA_POLL_NOT_FULL_ERROR);
                    return rc;

                }
            }          
        }
        // End HW220256 protection

        FAPI_DBG("Put: Doublewords in passed io_ocb_buffer %x", 
                io_ocb_buffer.getDoubleWordLength());
        if (io_ocb_buffer.getDoubleWordLength() == 0) 
        {
            FAPI_ERR("Put: No data passed in io_ocb_buffer");
            FAPI_SET_HWP_ERROR(rc, RC_PROCPM_OCB_PUT_DATA_LENGTH_ERROR);
            return rc;
        }
        
        FAPI_DBG("Put: Checking buffer lengths - i_ocb_req_length: %x; io_ocb_buffer: %x", 
                i_ocb_req_length, io_ocb_buffer.getDoubleWordLength());
        
        if ((i_ocb_req_length) != io_ocb_buffer.getDoubleWordLength())
        {
            FAPI_ERR("Put: io_ocb_buffer length does not match i_ocb_req_length");
            FAPI_SET_HWP_ERROR(rc, RC_PROCPM_OCB_PUT_DATA_LENGTH_ERROR);
            return rc;
        }
        
        
        // Walk the input buffer (io_ocb_buffer) 8B (64bits) at a time to write 
        // the channel data register
        for (buffer_ptr=0; buffer_ptr < (i_ocb_req_length)*64; buffer_ptr+=64)
        {
            
            FAPI_DBG("Put: Copy 8B from parameter buffer at location %x into "
                    "working data buffer.", buffer_ptr);
           
            l_ecmdRc |= data.insert(io_ocb_buffer, 0, 64, buffer_ptr);
            if (l_ecmdRc)
            {
                FAPI_ERR("Put: data insert failed");
                rc.setEcmdError(l_ecmdRc);
                return rc;
            }
            
            rc = fapiPutScom(i_target, (const uint64_t)OCBDR_address, data); 
            if (rc)
            { 
                FAPI_ERR("Put SCOM error for OCB indirect access");
                return rc;
            }
            o_ocb_act_length++;
            FAPI_DBG("Put: Increment output length to %x", o_ocb_act_length);
        }
    }
    else if ( i_ocb_op == OCB_GET )
    {      
        
        FAPI_DBG("Get: Setting the io_ocb_buffer size to %x doublewords",
                i_ocb_req_length);
        // Note: i_ocb_req_length is unit origin (eg 8B = length of 1)
        l_ecmdRc |= io_ocb_buffer.setDoubleWordLength(i_ocb_req_length); 
        if (l_ecmdRc)
           {
               FAPI_ERR("Get: setDoubleWord failed");
               rc.setEcmdError(l_ecmdRc);
               return rc;
           }

        for (buffer_ptr=0; buffer_ptr < (i_ocb_req_length)*64; buffer_ptr+=64)
        {
            rc=fapiGetScom(i_target, (const uint64_t)OCBDR_address, data);
            if (rc)
            {
                FAPI_ERR("Get SCOM error for OCB indirect access");
                return rc;
            }

            FAPI_DBG("Get: Copy 8B from working data buffer into parameter "
                "buffer at location: %x", buffer_ptr);
            l_ecmdRc |= io_ocb_buffer.insert(data, buffer_ptr, 64, 0);
            if (l_ecmdRc)
            {
                FAPI_ERR("Get Buffer copy error");
                rc.setEcmdError(l_ecmdRc);
                return rc;
            }
            o_ocb_act_length++;
            FAPI_DBG("Get: Increment output length to %x", o_ocb_act_length);
        }
    }
    else
    {
        FAPI_ERR("Invalid OCB access operation %x", i_ocb_op);
        FAPI_SET_HWP_ERROR(rc, RC_PROCPM_OCB_ACCESS_OP);
        return rc;
    }
    
    // If not non-zero SCOM rc, check that the lengths match.
    if (i_ocb_req_length != o_ocb_act_length)
    {
        FAPI_ERR("OCB access length check failure:  input = %8X; output = %8X", 
                i_ocb_req_length, o_ocb_act_length);
        FAPI_SET_HWP_ERROR(rc, RC_PROCPM_OCB_ACCESS_LENGTH_CHECK);
        return rc;
    }
    
    return rc;
  
}


} // extern "C"
