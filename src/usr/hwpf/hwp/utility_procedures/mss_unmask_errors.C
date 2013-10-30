/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/utility_procedures/mss_unmask_errors.C $     */
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
// $Id: mss_unmask_errors.C,v 1.4 2013/10/22 18:55:06 gollub Exp $
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|   Date:  | Author: | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.1   | 09/05/12 | gollub  | Created
//   1.2   | 01/31/13 | gollub  | Keeping maint UE/MPE, and MBSPA threshold
//         |          |         | errors masked until mss_unmask_fetch_errors,
//         |          |         | so they will be masked during memdiags, and
//         |          |         | unmasked before scrub is started.
//   1.3   | 03/08/13 | gollub  | Masking MBSPA[0] for DD1, and using MBSPA[8] instead.
//   1.4   | 10/22/13 | gollub  | Keep maint ECC errors masked, since PRD intends
//         |          |         | to use cmd complete attention instead.

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------

#include <mss_unmask_errors.H>
#include <cen_scom_addresses.H>
using namespace fapi;


//------------------------------------------------------------------------------
// Constants and enums
//------------------------------------------------------------------------------
        

//------------------------------------------------------------------------------
// mss_unmask_inband_errors
//------------------------------------------------------------------------------
                                           
fapi::ReturnCode mss_unmask_inband_errors( const fapi::Target & i_target,
                                           fapi::ReturnCode i_bad_rc )
                                           
{

    FAPI_INF("ENTER mss_unmask_inband_errors()"); 
    
    fapi::ReturnCode l_rc;
    uint32_t l_ecmd_rc = 0;            

    //*************************
    //*************************
    // MBS_FIR_REG
    //*************************
    //*************************

    ecmdDataBufferBase l_mbs_fir_mask(64);
    ecmdDataBufferBase l_mbs_fir_mask_or(64);    
    ecmdDataBufferBase l_mbs_fir_mask_and(64);
    ecmdDataBufferBase l_mbs_fir_action0(64);
    ecmdDataBufferBase l_mbs_fir_action1(64);
    
    // Read mask 
    l_rc = fapiGetScom_w_retry(i_target, MBS_FIR_MASK_REG_0x02011403, l_mbs_fir_mask); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }    
    
    // TODO: Here is where I could clear bits that were bogus, before I unmask 
    //       them. But typically we are expecting the bit set at this point
    //       to be valid errors for PRD to log.


    //(Action0, Action1, Mask)
    //
    // (0,0,0) = checkstop
    // (0,1,0) = recoverable error
    // (1,0,0) = report unused
    // (1,1,0) = machine check
    // (x,x,1) = error is masked

    l_ecmd_rc |= l_mbs_fir_action0.flushTo0();
    l_ecmd_rc |= l_mbs_fir_action1.flushTo0();
    l_ecmd_rc |= l_mbs_fir_mask_or.flushTo0();
    l_ecmd_rc |= l_mbs_fir_mask_and.flushTo1();

    // 0    host_protocol_error     channel checkstop   unmask
    l_ecmd_rc |= l_mbs_fir_action0.clearBit(0);            
    l_ecmd_rc |= l_mbs_fir_action1.clearBit(0);
    l_ecmd_rc |= l_mbs_fir_mask_and.clearBit(0);
    
    // 1    int_protocol_error      channel checkstop   unmask
    l_ecmd_rc |= l_mbs_fir_action0.clearBit(1);            
    l_ecmd_rc |= l_mbs_fir_action1.clearBit(1);
    l_ecmd_rc |= l_mbs_fir_mask_and.clearBit(1);
    
    // 2    invalid_address_error   channel checkstop   mask (until unmask_fetch_errors)
    l_ecmd_rc |= l_mbs_fir_action0.clearBit(2);            
    l_ecmd_rc |= l_mbs_fir_action1.clearBit(2);
    l_ecmd_rc |= l_mbs_fir_mask_or.setBit(2);

    // 3    external_timeout        channel checkstop   mask (until unmask_fetch_errors)
    l_ecmd_rc |= l_mbs_fir_action0.clearBit(3);            
    l_ecmd_rc |= l_mbs_fir_action1.clearBit(3);
    l_ecmd_rc |= l_mbs_fir_mask_or.setBit(3);
    
    // 4    internal_timeout        channel checkstop   mask (until unmask_fetch_errors)
    l_ecmd_rc |= l_mbs_fir_action0.clearBit(4);            
    l_ecmd_rc |= l_mbs_fir_action1.clearBit(4);
    l_ecmd_rc |= l_mbs_fir_mask_or.setBit(4);

    // 5    int_buffer_ce           recoverable         unmask
    l_ecmd_rc |= l_mbs_fir_action0.clearBit(5);            
    l_ecmd_rc |= l_mbs_fir_action1.setBit(5);
    l_ecmd_rc |= l_mbs_fir_mask_and.clearBit(5);

    // 6    int_buffer_ue           recoverable         unmask
    l_ecmd_rc |= l_mbs_fir_action0.clearBit(6);            
    l_ecmd_rc |= l_mbs_fir_action1.setBit(6);
    l_ecmd_rc |= l_mbs_fir_mask_and.clearBit(6);

    // 7    int_buffer_sue          recoverable         mask (forever)
    l_ecmd_rc |= l_mbs_fir_action0.clearBit(7);            
    l_ecmd_rc |= l_mbs_fir_action1.setBit(7);
    l_ecmd_rc |= l_mbs_fir_mask_or.setBit(7);

    // 8    int_parity_error        channel checkstop   unmask
    l_ecmd_rc |= l_mbs_fir_action0.clearBit(8); 
    l_ecmd_rc |= l_mbs_fir_action1.clearBit(8); 
    l_ecmd_rc |= l_mbs_fir_mask_and.clearBit(8);

    // 9    cache_srw_ce            recoverable         mask (until unmask_fetch_errors)
    l_ecmd_rc |= l_mbs_fir_action0.clearBit(9);            
    l_ecmd_rc |= l_mbs_fir_action1.setBit(9);
    l_ecmd_rc |= l_mbs_fir_mask_or.setBit(9);

    // 10    cache_srw_ue           recoverable         mask (until unmask_fetch_errors)
    l_ecmd_rc |= l_mbs_fir_action0.clearBit(10);            
    l_ecmd_rc |= l_mbs_fir_action1.setBit(10);
    l_ecmd_rc |= l_mbs_fir_mask_or.setBit(10);

    // 11    cache_srw_sue          recoverable         mask (forever)
    l_ecmd_rc |= l_mbs_fir_action0.clearBit(11);            
    l_ecmd_rc |= l_mbs_fir_action1.setBit(11);
    l_ecmd_rc |= l_mbs_fir_mask_or.setBit(11);

    // 12    cache_co_ce            recoverable         mask (until unmask_fetch_errors)
    l_ecmd_rc |= l_mbs_fir_action0.clearBit(12);            
    l_ecmd_rc |= l_mbs_fir_action1.setBit(12);
    l_ecmd_rc |= l_mbs_fir_mask_or.setBit(12);

    // 13    cache_co_ue            recoverable         mask (until unmask_fetch_errors)
    l_ecmd_rc |= l_mbs_fir_action0.clearBit(13);            
    l_ecmd_rc |= l_mbs_fir_action1.setBit(13);
    l_ecmd_rc |= l_mbs_fir_mask_or.setBit(13);

    // 14    cache_co_sue           recoverable         mask (forever)
    l_ecmd_rc |= l_mbs_fir_action0.clearBit(14);            
    l_ecmd_rc |= l_mbs_fir_action1.setBit(14);
    l_ecmd_rc |= l_mbs_fir_mask_or.setBit(14);

    // 15    dir_ce                 recoverable         mask (until unmask_fetch_errors)
    l_ecmd_rc |= l_mbs_fir_action0.clearBit(15);            
    l_ecmd_rc |= l_mbs_fir_action1.setBit(15);
    l_ecmd_rc |= l_mbs_fir_mask_or.setBit(15);

    // 16    dir_ue                 channel checkstop   mask (until unmask_fetch_errors)
    l_ecmd_rc |= l_mbs_fir_action0.clearBit(16);            
    l_ecmd_rc |= l_mbs_fir_action1.clearBit(16);
    l_ecmd_rc |= l_mbs_fir_mask_or.setBit(16);

    // 17    dir_member_deleted     recoverable         mask (forever)
    l_ecmd_rc |= l_mbs_fir_action0.clearBit(17);            
    l_ecmd_rc |= l_mbs_fir_action1.setBit(17);
    l_ecmd_rc |= l_mbs_fir_mask_or.setBit(17);

    // 18    dir_all_members_deleted channel checkstop  mask (until unmask_fetch_errors)
    l_ecmd_rc |= l_mbs_fir_action0.clearBit(18);            
    l_ecmd_rc |= l_mbs_fir_action1.clearBit(18);
    l_ecmd_rc |= l_mbs_fir_mask_or.setBit(18);

    // 19    lru_error               recoverable        mask (until unmask_fetch_errors)
    l_ecmd_rc |= l_mbs_fir_action0.clearBit(19);            
    l_ecmd_rc |= l_mbs_fir_action1.setBit(19);
    l_ecmd_rc |= l_mbs_fir_mask_or.setBit(19);

    // 20    eDRAM error             channel checkstop  mask (until unmask_fetch_errors)
    l_ecmd_rc |= l_mbs_fir_action0.clearBit(20);            
    l_ecmd_rc |= l_mbs_fir_action1.clearBit(20);
    l_ecmd_rc |= l_mbs_fir_mask_or.setBit(20);

    // 21    emergency_throttle_set  recoverable        mask (forever)
    l_ecmd_rc |= l_mbs_fir_action0.clearBit(21);            
    l_ecmd_rc |= l_mbs_fir_action1.setBit(21);
    l_ecmd_rc |= l_mbs_fir_mask_or.setBit(21);

    // 22    Host Inband Read Error  recoverable        mask (forever)
    l_ecmd_rc |= l_mbs_fir_action0.clearBit(22);            
    l_ecmd_rc |= l_mbs_fir_action1.setBit(22);
    l_ecmd_rc |= l_mbs_fir_mask_or.setBit(22);

    // 23    Host Inband Write Error recoverable        mask (forever)
    l_ecmd_rc |= l_mbs_fir_action0.clearBit(23);            
    l_ecmd_rc |= l_mbs_fir_action1.setBit(23);
    l_ecmd_rc |= l_mbs_fir_mask_or.setBit(23);

    // 24    OCC Inband Read Error   recoverable        mask (forever)
    l_ecmd_rc |= l_mbs_fir_action0.clearBit(24);            
    l_ecmd_rc |= l_mbs_fir_action1.setBit(24);
    l_ecmd_rc |= l_mbs_fir_mask_or.setBit(24);

    // 25    OCC Inband Write Error  recoverable        mask (forever)
    l_ecmd_rc |= l_mbs_fir_action0.clearBit(25);            
    l_ecmd_rc |= l_mbs_fir_action1.setBit(25);
    l_ecmd_rc |= l_mbs_fir_mask_or.setBit(25);

    // 26    srb_buffer_ce           recoverable        mask (until unmask_fetch_errors)
    l_ecmd_rc |= l_mbs_fir_action0.clearBit(26);            
    l_ecmd_rc |= l_mbs_fir_action1.setBit(26);
    l_ecmd_rc |= l_mbs_fir_mask_or.setBit(26);

    // 27    srb_buffer_ue           recoverable         mask (until unmask_fetch_errors)
    l_ecmd_rc |= l_mbs_fir_action0.clearBit(27);            
    l_ecmd_rc |= l_mbs_fir_action1.setBit(27);
    l_ecmd_rc |= l_mbs_fir_mask_or.setBit(27);

    // 28    srb_buffer_sue          recoverable         mask (forever)
    l_ecmd_rc |= l_mbs_fir_action0.clearBit(28);            
    l_ecmd_rc |= l_mbs_fir_action1.setBit(28);
    l_ecmd_rc |= l_mbs_fir_mask_or.setBit(28);

    // 29    internal_scom_error     recoverable         mask (tbd)
    l_ecmd_rc |= l_mbs_fir_action0.clearBit(29);            
    l_ecmd_rc |= l_mbs_fir_action1.setBit(29);
    l_ecmd_rc |= l_mbs_fir_mask_or.setBit(29);

    // 30    internal_scom_error_copy recoverable        mask (tbd)
    l_ecmd_rc |= l_mbs_fir_action0.clearBit(30);            
    l_ecmd_rc |= l_mbs_fir_action1.setBit(30);
    l_ecmd_rc |= l_mbs_fir_mask_or.setBit(30);

    // 31:63    Reserved                not implemented, so won't touch these
    
    if(l_ecmd_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        

        l_rc.setEcmdError(l_ecmd_rc);
        return l_rc;
    }                                                                              

    // Write action0
    l_rc = fapiPutScom_w_retry(i_target, MBS_FIR_ACTION0_REG_0x02011406, l_mbs_fir_action0);
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }

    // Write action1
    l_rc = fapiPutScom_w_retry(i_target, MBS_FIR_ACTION1_REG_0x02011407, l_mbs_fir_action1);
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }

    
    // Write mask OR
    l_rc = fapiPutScom_w_retry(i_target, MBS_FIR_MASK_REG_OR_0x02011405, l_mbs_fir_mask_or); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }

    // Write mask AND
    l_rc = fapiPutScom_w_retry(i_target, MBS_FIR_MASK_REG_AND_0x02011404, l_mbs_fir_mask_and); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }


    //************************************************    
    // DEBUG: read them all back to verify
    l_rc = fapiGetScom_w_retry(i_target, MBS_FIR_ACTION0_REG_0x02011406, l_mbs_fir_action0); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }
    l_rc = fapiGetScom_w_retry(i_target, MBS_FIR_ACTION1_REG_0x02011407, l_mbs_fir_action1); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }
    l_rc = fapiGetScom_w_retry(i_target, MBS_FIR_MASK_REG_0x02011403, l_mbs_fir_mask); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }

    //************************************************    
    
    
    FAPI_INF("EXIT mss_unmask_inband_errors()"); 

    return i_bad_rc;
}



//------------------------------------------------------------------------------
// mss_unmask_ddrphy_errors
//------------------------------------------------------------------------------
                                           
fapi::ReturnCode mss_unmask_ddrphy_errors( const fapi::Target & i_target,
                                           fapi::ReturnCode i_bad_rc )
                                           
{

    FAPI_INF("ENTER mss_unmask ddrphy_errors()"); 
    
    fapi::ReturnCode l_rc;
    uint32_t l_ecmd_rc = 0;            

    //*************************
    //*************************
    // DDRPHY_FIR_REG
    //*************************
    //*************************

    ecmdDataBufferBase l_ddrphy_fir_mask(64);
    ecmdDataBufferBase l_ddrphy_fir_mask_or(64);
    ecmdDataBufferBase l_ddrphy_fir_mask_and(64);        
    ecmdDataBufferBase l_ddrphy_fir_action0(64);
    ecmdDataBufferBase l_ddrphy_fir_action1(64);

    
    // TODO: Here is where I could clear bits that were bogus, before I unmask 
    //       them. But typically we are expecting the bit set at this point
    //       to be valid errors for PRD to log.


    //(Action0, Action1, Mask)
    //
    // (0,0,0) = checkstop
    // (0,1,0) = recoverable error
    // (1,0,0) = report unused
    // (1,1,0) = machine check
    // (x,x,1) = error is masked
        
    l_ecmd_rc |= l_ddrphy_fir_action0.flushTo0();
    l_ecmd_rc |= l_ddrphy_fir_action1.flushTo0();
    l_ecmd_rc |= l_ddrphy_fir_mask_or.flushTo0();
    l_ecmd_rc |= l_ddrphy_fir_mask_and.flushTo0();
    l_ecmd_rc |= l_ddrphy_fir_mask_and.setBit(48,16);
        
    // 0:47 Reserved                not implemented, so won't touch these
    
    // 48   ddr0_fsm_ckstp          channel checkstop   unmask
    l_ecmd_rc |= l_ddrphy_fir_action0.clearBit(48);            
    l_ecmd_rc |= l_ddrphy_fir_action1.clearBit(48);
    l_ecmd_rc |= l_ddrphy_fir_mask_and.clearBit(48);
    
    // 49   ddr0_parity_ckstp       channel checkstop   unmask
    l_ecmd_rc |= l_ddrphy_fir_action0.clearBit(49);            
    l_ecmd_rc |= l_ddrphy_fir_action1.clearBit(49);
    l_ecmd_rc |= l_ddrphy_fir_mask_and.clearBit(49);

    // 50   ddr0_calibration_error  recoverable         mask (forever)
    l_ecmd_rc |= l_ddrphy_fir_action0.clearBit(50);            
    l_ecmd_rc |= l_ddrphy_fir_action1.setBit(50);
    l_ecmd_rc |= l_ddrphy_fir_mask_or.setBit(50);

    // 51   ddr0_fsm_err            recoverable         unmask
    l_ecmd_rc |= l_ddrphy_fir_action0.clearBit(51);            
    l_ecmd_rc |= l_ddrphy_fir_action1.setBit(51);
    l_ecmd_rc |= l_ddrphy_fir_mask_and.clearBit(51);

    // 52   ddr0_parity_err         recoverable         unmask
    l_ecmd_rc |= l_ddrphy_fir_action0.clearBit(52);            
    l_ecmd_rc |= l_ddrphy_fir_action1.setBit(52);
    l_ecmd_rc |= l_ddrphy_fir_mask_and.clearBit(52);

    // 53   ddr01_fir_parity_err    recoverable         mask (forever)
    l_ecmd_rc |= l_ddrphy_fir_action0.clearBit(53);            
    l_ecmd_rc |= l_ddrphy_fir_action1.setBit(53);
    l_ecmd_rc |= l_ddrphy_fir_mask_or.setBit(53);
    
    // 54   Reserved                recoverable         mask (forever)
    l_ecmd_rc |= l_ddrphy_fir_action0.clearBit(54);            
    l_ecmd_rc |= l_ddrphy_fir_action1.setBit(54);
    l_ecmd_rc |= l_ddrphy_fir_mask_or.setBit(54);

    // 55   Reserved                recoverable         mask (forever)
    l_ecmd_rc |= l_ddrphy_fir_action0.clearBit(55);            
    l_ecmd_rc |= l_ddrphy_fir_action1.setBit(55);
    l_ecmd_rc |= l_ddrphy_fir_mask_or.setBit(55);

    // 56   ddr1_fsm_ckstp          channel checkstop   unmask
    l_ecmd_rc |= l_ddrphy_fir_action0.clearBit(56);            
    l_ecmd_rc |= l_ddrphy_fir_action1.clearBit(56);
    l_ecmd_rc |= l_ddrphy_fir_mask_and.clearBit(56);
    
    // 57   ddr1_parity_ckstp       channel checkstop   unmask
    l_ecmd_rc |= l_ddrphy_fir_action0.clearBit(57);            
    l_ecmd_rc |= l_ddrphy_fir_action1.clearBit(57);
    l_ecmd_rc |= l_ddrphy_fir_mask_and.clearBit(57);

    // 58   ddr1_calibration_error  recoverable         mask (forever)
    l_ecmd_rc |= l_ddrphy_fir_action0.clearBit(58);            
    l_ecmd_rc |= l_ddrphy_fir_action1.setBit(58);
    l_ecmd_rc |= l_ddrphy_fir_mask_or.setBit(58);

    // 59   ddr1_fsm_err            recoverable         unmask
    l_ecmd_rc |= l_ddrphy_fir_action0.clearBit(59);            
    l_ecmd_rc |= l_ddrphy_fir_action1.setBit(59);
    l_ecmd_rc |= l_ddrphy_fir_mask_and.clearBit(59);

    // 60   ddr1_parity_err         recoverable         unmask
    l_ecmd_rc |= l_ddrphy_fir_action0.clearBit(60);            
    l_ecmd_rc |= l_ddrphy_fir_action1.setBit(60);
    l_ecmd_rc |= l_ddrphy_fir_mask_and.clearBit(60);

    // 61   Reserved                recoverable         mask (forever)
    l_ecmd_rc |= l_ddrphy_fir_action0.clearBit(61);            
    l_ecmd_rc |= l_ddrphy_fir_action1.setBit(61);
    l_ecmd_rc |= l_ddrphy_fir_mask_or.setBit(61);

    // 62   Reserved                recoverable         mask (forever)
    l_ecmd_rc |= l_ddrphy_fir_action0.clearBit(62);            
    l_ecmd_rc |= l_ddrphy_fir_action1.setBit(62);
    l_ecmd_rc |= l_ddrphy_fir_mask_or.setBit(62);

    // 63   Reserved                recoverable         mask (forever)
    l_ecmd_rc |= l_ddrphy_fir_action0.clearBit(63);            
    l_ecmd_rc |= l_ddrphy_fir_action1.setBit(63);
    l_ecmd_rc |= l_ddrphy_fir_mask_or.setBit(63);



    if(l_ecmd_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        

        l_rc.setEcmdError(l_ecmd_rc);
        return l_rc;
    }                                                                              

    // Write action0
    l_rc = fapiPutScom_w_retry(i_target, PHY01_DDRPHY_FIR_ACTION0_REG_0x800200960301143f, l_ddrphy_fir_action0);
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }

    // Write action1
    l_rc = fapiPutScom_w_retry(i_target, PHY01_DDRPHY_FIR_ACTION1_REG_0x800200970301143f, l_ddrphy_fir_action1);
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }

    
    // Write mask OR
    l_rc = fapiPutScom_w_retry(i_target, PHY01_DDRPHY_FIR_MASK_REG_OR_0x800200950301143f, l_ddrphy_fir_mask_or); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }

    // Write mask AND
    l_rc = fapiPutScom_w_retry(i_target, PHY01_DDRPHY_FIR_MASK_REG_AND_0x800200940301143f, l_ddrphy_fir_mask_and); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }


    //************************************************    
    // DEBUG: read them all back to verify
    l_rc = fapiGetScom_w_retry(i_target, PHY01_DDRPHY_FIR_ACTION0_REG_0x800200960301143f, l_ddrphy_fir_action0); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }
    l_rc = fapiGetScom_w_retry(i_target, PHY01_DDRPHY_FIR_ACTION1_REG_0x800200970301143f, l_ddrphy_fir_action1); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }
    l_rc = fapiGetScom_w_retry(i_target, PHY01_DDRPHY_FIR_MASK_REG_0x800200930301143f, l_ddrphy_fir_mask); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }

    //************************************************    
    
    
    //*************************
    //*************************
    // MBAFIR
    //*************************
    //*************************
    
    ecmdDataBufferBase l_mbafir_mask(64);
    ecmdDataBufferBase l_mbafir_mask_or(64);
    ecmdDataBufferBase l_mbafir_mask_and(64);
    ecmdDataBufferBase l_mbafir_action0(64);
    ecmdDataBufferBase l_mbafir_action1(64);
            
    
    // Read mask
    l_rc = fapiGetScom_w_retry(i_target,
                               MBA01_MBAFIRMASK_0x03010603,
                               l_mbafir_mask); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }
    
    // TODO: Here is where I could clear bits that were bogus, before I unmask 
    //       them. But typically we are expecting the bit set at this point
    //       to be valid errors for PRD to log.


    //(Action0, Action1, Mask)
    //
    // (0,0,0) = checkstop
    // (0,1,0) = recoverable error
    // (1,0,0) = report unused
    // (1,1,0) = machine check
    // (x,x,1) = error is masked
                
    l_ecmd_rc |= l_mbafir_action0.flushTo0();
    l_ecmd_rc |= l_mbafir_action1.flushTo0();
    l_ecmd_rc |= l_mbafir_mask_or.flushTo0();
    l_ecmd_rc |= l_mbafir_mask_and.flushTo1();


    // 0	Invalid_Maint_Cmd           recoverable         masked (forever)
    l_ecmd_rc |= l_mbafir_action0.clearBit(0);            
    l_ecmd_rc |= l_mbafir_action1.setBit(0);
    l_ecmd_rc |= l_mbafir_mask_or.setBit(0);
    
    // 1	Invalid_Maint_Address       recoverable         masked (forever)
    l_ecmd_rc |= l_mbafir_action0.clearBit(1);            
    l_ecmd_rc |= l_mbafir_action1.setBit(1);
    l_ecmd_rc |= l_mbafir_mask_or.setBit(1);

    // 2	Multi_address_Maint_timeout recoverable         masked (until mss_unmask_maint_errors)
    l_ecmd_rc |= l_mbafir_action0.clearBit(2);            
    l_ecmd_rc |= l_mbafir_action1.setBit(2);
    l_ecmd_rc |= l_mbafir_mask_or.setBit(2);

    // 3	Internal_fsm_error          recoverable         unmask
    l_ecmd_rc |= l_mbafir_action0.clearBit(3);            
    l_ecmd_rc |= l_mbafir_action1.setBit(3);
    l_ecmd_rc |= l_mbafir_mask_and.clearBit(3);

    // 4	MCBIST_Error                recoverable         mask (forever)
    l_ecmd_rc |= l_mbafir_action0.clearBit(4);            
    l_ecmd_rc |= l_mbafir_action1.setBit(4);
    l_ecmd_rc |= l_mbafir_mask_or.setBit(4);
    
    // 5	scom_cmd_reg_pe             recoverable         unmask
    l_ecmd_rc |= l_mbafir_action0.clearBit(5);            
    l_ecmd_rc |= l_mbafir_action1.setBit(5);
    l_ecmd_rc |= l_mbafir_mask_and.clearBit(5);

    // 6	channel_chkstp_err          channel checkstop   unmask
    l_ecmd_rc |= l_mbafir_action0.clearBit(6);            
    l_ecmd_rc |= l_mbafir_action1.clearBit(6);
    l_ecmd_rc |= l_mbafir_mask_and.clearBit(6);

    // 7	wrd_caw2_data_ce_ue_err     recoverable         masked (until mss_unmask_maint_errors)
    l_ecmd_rc |= l_mbafir_action0.clearBit(7);            
    l_ecmd_rc |= l_mbafir_action1.setBit(7);
    l_ecmd_rc |= l_mbafir_mask_or.setBit(7);

    // 8:14	RESERVED                    recoverable         mask (forever)
    l_ecmd_rc |= l_mbafir_action0.clearBit(8,7);            
    l_ecmd_rc |= l_mbafir_action1.setBit(8,7);
    l_ecmd_rc |= l_mbafir_mask_or.setBit(8,7);

    // 15	internal scom error         recoverable         mask (tbd)
    l_ecmd_rc |= l_mbafir_action0.clearBit(15);            
    l_ecmd_rc |= l_mbafir_action1.setBit(15);
    l_ecmd_rc |= l_mbafir_mask_or.setBit(15);

    // 16	internal scom error clone   recoverable         mask (tbd)
    l_ecmd_rc |= l_mbafir_action0.clearBit(16);            
    l_ecmd_rc |= l_mbafir_action1.setBit(16);
    l_ecmd_rc |= l_mbafir_mask_or.setBit(16);


    // 17:63 RESERVED           not implemented, so won't touch these

    if(l_ecmd_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        

        l_rc.setEcmdError(l_ecmd_rc);
        return l_rc;
    }                                                                              

    // Write action0
    l_rc = fapiPutScom_w_retry(i_target,
                               MBA01_MBAFIRACT0_0x03010606,
                               l_mbafir_action0);
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }

    // Write action1
    l_rc = fapiPutScom_w_retry(i_target,
                               MBA01_MBAFIRACT1_0x03010607,
                               l_mbafir_action1);
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }

    
    // Write mask OR
    l_rc = fapiPutScom_w_retry(i_target,
                               MBA01_MBAFIRMASK_OR_0x03010605,
                               l_mbafir_mask_or); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }


    // Write mask AND
    l_rc = fapiPutScom_w_retry(i_target,
                               MBA01_MBAFIRMASK_AND_0x03010604,
                               l_mbafir_mask_and); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }


    //************************************************    
    // DEBUG: read them all back to verify
    l_rc = fapiGetScom_w_retry(i_target,
                               MBA01_MBAFIRACT0_0x03010606,
                               l_mbafir_action0); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }
    l_rc = fapiGetScom_w_retry(i_target,
                               MBA01_MBAFIRACT1_0x03010607,
                               l_mbafir_action1); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }
    l_rc = fapiGetScom_w_retry(i_target,
                               MBA01_MBAFIRMASK_0x03010603,
                               l_mbafir_mask); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }

    //************************************************    
    
    
    FAPI_INF("EXIT mss_unmask_ddrphy_errors()"); 

    return i_bad_rc;
}


//------------------------------------------------------------------------------
// mss_unmask_draminit_errors
//------------------------------------------------------------------------------
                                           
fapi::ReturnCode mss_unmask_draminit_errors( const fapi::Target & i_target,
                                             fapi::ReturnCode i_bad_rc )
                                           
{

    FAPI_INF("ENTER mss_unmask_draminit_errors()"); 
    
    fapi::ReturnCode l_rc;
    uint32_t l_ecmd_rc = 0;            

    //*************************
    //*************************
    // MBACALFIR
    //*************************
    //*************************

    ecmdDataBufferBase l_mbacalfir_mask(64);
    ecmdDataBufferBase l_mbacalfir_mask_or(64);
    ecmdDataBufferBase l_mbacalfir_mask_and(64);        
    ecmdDataBufferBase l_mbacalfir_action0(64);
    ecmdDataBufferBase l_mbacalfir_action1(64);


    // Read mask
    l_rc = fapiGetScom_w_retry(i_target, MBA01_MBACALFIR_MASK_0x03010403, l_mbacalfir_mask); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }
    
    // TODO: Here is where I could clear bits that were bogus, before I unmask 
    //       them. But typically we are expecting the bit set at this point
    //       to be valid errors for PRD to log.


    //(Action0, Action1, Mask)
    //
    // (0,0,0) = checkstop
    // (0,1,0) = recoverable error
    // (1,0,0) = report unused
    // (1,1,0) = machine check
    // (x,x,1) = error is masked
        
    l_ecmd_rc |= l_mbacalfir_action0.flushTo0();
    l_ecmd_rc |= l_mbacalfir_action1.flushTo0();
    l_ecmd_rc |= l_mbacalfir_mask_or.flushTo0();
    l_ecmd_rc |= l_mbacalfir_mask_and.flushTo1();        
    
    // 0	MBA Recoverable Error       recoverable         mask
    l_ecmd_rc |= l_mbacalfir_action0.clearBit(0);            
    l_ecmd_rc |= l_mbacalfir_action1.setBit(0);
    l_ecmd_rc |= l_mbacalfir_mask_or.setBit(0);

    // 1	MBA Nonrecoverable Error    channel checkstop   mask
    l_ecmd_rc |= l_mbacalfir_action0.clearBit(1);            
    l_ecmd_rc |= l_mbacalfir_action1.clearBit(1);
    l_ecmd_rc |= l_mbacalfir_mask_or.setBit(1);

    // 2	Refresh Overrun             recoverable         mask
    l_ecmd_rc |= l_mbacalfir_action0.clearBit(2);            
    l_ecmd_rc |= l_mbacalfir_action1.setBit(2);
    l_ecmd_rc |= l_mbacalfir_mask_or.setBit(2);

    // 3	WAT error                   recoverable         mask (forever)
    l_ecmd_rc |= l_mbacalfir_action0.clearBit(3);            
    l_ecmd_rc |= l_mbacalfir_action1.setBit(3);
    l_ecmd_rc |= l_mbacalfir_mask_or.setBit(3);

    // 4	RCD Parity Error 0          recoverable         unmask (only if set)
    // TODO: Unmask, only if set, only if ISD DIMM
    l_ecmd_rc |= l_mbacalfir_action0.clearBit(4);            
    l_ecmd_rc |= l_mbacalfir_action1.setBit(4);
    l_ecmd_rc |= l_mbacalfir_mask_or.setBit(4);

    // 5	ddr0_cal_timeout_err        recoverable         mask
    l_ecmd_rc |= l_mbacalfir_action0.clearBit(5);            
    l_ecmd_rc |= l_mbacalfir_action1.setBit(5);
    l_ecmd_rc |= l_mbacalfir_mask_or.setBit(5);

    // 6	ddr1_cal_timeout_err        recoverable         mask
    l_ecmd_rc |= l_mbacalfir_action0.clearBit(6);            
    l_ecmd_rc |= l_mbacalfir_action1.setBit(6);
    l_ecmd_rc |= l_mbacalfir_mask_or.setBit(6);

    // 7	RCD Parity Error 1          recoverable         unmask (only if set)
    // TODO: Unmask, only if set, only if ISD DIMM
    l_ecmd_rc |= l_mbacalfir_action0.clearBit(7);            
    l_ecmd_rc |= l_mbacalfir_action1.setBit(7);
    l_ecmd_rc |= l_mbacalfir_mask_or.setBit(7);


    // 8	mbx to mba par error        channel checkstop   mask
    l_ecmd_rc |= l_mbacalfir_action0.clearBit(8);            
    l_ecmd_rc |= l_mbacalfir_action1.clearBit(8);
    l_ecmd_rc |= l_mbacalfir_mask_or.setBit(8);

    // 9	mba_wrd ue                  recoverable         mask
    l_ecmd_rc |= l_mbacalfir_action0.clearBit(9);            
    l_ecmd_rc |= l_mbacalfir_action1.setBit(9);
    l_ecmd_rc |= l_mbacalfir_mask_or.setBit(9);

    // 10	mba_wrd ce                  recoverable         mask
    l_ecmd_rc |= l_mbacalfir_action0.clearBit(10);            
    l_ecmd_rc |= l_mbacalfir_action1.setBit(10);
    l_ecmd_rc |= l_mbacalfir_mask_or.setBit(10);

    // 11	mba_maint ue                recoverable         mask
    l_ecmd_rc |= l_mbacalfir_action0.clearBit(11);            
    l_ecmd_rc |= l_mbacalfir_action1.setBit(11);
    l_ecmd_rc |= l_mbacalfir_mask_or.setBit(11);

    // 12	mba_maint ce                recoverable         mask
    l_ecmd_rc |= l_mbacalfir_action0.clearBit(12);            
    l_ecmd_rc |= l_mbacalfir_action1.setBit(12);
    l_ecmd_rc |= l_mbacalfir_mask_or.setBit(12);

    // 13	ddr_cal_reset_timeout       channel checkstop   mask
    // TODO: Leaving masked until I find proper spot to unmask this
    l_ecmd_rc |= l_mbacalfir_action0.clearBit(13);            
    l_ecmd_rc |= l_mbacalfir_action1.clearBit(13);
    l_ecmd_rc |= l_mbacalfir_mask_or.setBit(13);

    // 14	wrq_data_ce                 recoverable         mask
    l_ecmd_rc |= l_mbacalfir_action0.clearBit(14);            
    l_ecmd_rc |= l_mbacalfir_action1.setBit(14);
    l_ecmd_rc |= l_mbacalfir_mask_or.setBit(14);

    // 15	wrq_data_ue                 recoverable         mask
    l_ecmd_rc |= l_mbacalfir_action0.clearBit(15);            
    l_ecmd_rc |= l_mbacalfir_action1.setBit(15);
    l_ecmd_rc |= l_mbacalfir_mask_or.setBit(15);

    // 16	wrq_data_sue                recoverable         mask
    l_ecmd_rc |= l_mbacalfir_action0.clearBit(16);            
    l_ecmd_rc |= l_mbacalfir_action1.setBit(16);
    l_ecmd_rc |= l_mbacalfir_mask_or.setBit(16);

    // 17	wrq_rrq_hang_err            recoverable         mask
    l_ecmd_rc |= l_mbacalfir_action0.clearBit(17);            
    l_ecmd_rc |= l_mbacalfir_action1.setBit(17);
    l_ecmd_rc |= l_mbacalfir_mask_or.setBit(17);

    // 18	sm_1hot_err                 recoverable         unmask
    l_ecmd_rc |= l_mbacalfir_action0.clearBit(18);            
    l_ecmd_rc |= l_mbacalfir_action1.setBit(18);
    l_ecmd_rc |= l_mbacalfir_mask_and.clearBit(18);

    // 19	wrd_scom_error              recoverable         mask (tbd)
    l_ecmd_rc |= l_mbacalfir_action0.clearBit(19);            
    l_ecmd_rc |= l_mbacalfir_action1.setBit(19);
    l_ecmd_rc |= l_mbacalfir_mask_or.setBit(19);

    // 20	internal_scom_error         recoverable         mask (tbd)
    l_ecmd_rc |= l_mbacalfir_action0.clearBit(20);            
    l_ecmd_rc |= l_mbacalfir_action1.setBit(20);
    l_ecmd_rc |= l_mbacalfir_mask_or.setBit(20);

    // 21	internal_scom_error_copy    recoverable         mask (tbd)
    l_ecmd_rc |= l_mbacalfir_action0.clearBit(21);            
    l_ecmd_rc |= l_mbacalfir_action1.setBit(21);
    l_ecmd_rc |= l_mbacalfir_mask_or.setBit(21);

    // 22-63	Reserved            not implemented, so won't touch these          


    if(l_ecmd_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        

        l_rc.setEcmdError(l_ecmd_rc);
        return l_rc;
    }                                                                              

    // Write action0
    l_rc = fapiPutScom_w_retry(i_target, MBA01_MBACALFIR_ACTION0_0x03010406, l_mbacalfir_action0);
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }

    // Write action1
    l_rc = fapiPutScom_w_retry(i_target, MBA01_MBACALFIR_ACTION1_0x03010407, l_mbacalfir_action1);
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }

    
    // Write mask OR
    l_rc = fapiPutScom_w_retry(i_target, MBA01_MBACALFIR_MASK_OR_0x03010405, l_mbacalfir_mask_or); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }

    // Write mask AND
    l_rc = fapiPutScom_w_retry(i_target, MBA01_MBACALFIR_MASK_AND_0x03010404, l_mbacalfir_mask_and); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }


    //************************************************    
    // DEBUG: read them all back to verify
    l_rc = fapiGetScom_w_retry(i_target, MBA01_MBACALFIR_ACTION0_0x03010406, l_mbacalfir_action0); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }
    l_rc = fapiGetScom_w_retry(i_target, MBA01_MBACALFIR_ACTION1_0x03010407, l_mbacalfir_action1); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }
    l_rc = fapiGetScom_w_retry(i_target, MBA01_MBACALFIR_MASK_0x03010403, l_mbacalfir_mask); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }

    //************************************************    
    
    
    FAPI_INF("EXIT mss_unmask_draminit_errors()"); 

    return i_bad_rc;
}


//------------------------------------------------------------------------------
// mss_unmask_draminit_training_errors
//------------------------------------------------------------------------------
                                           
fapi::ReturnCode mss_unmask_draminit_training_errors( 
                                             const fapi::Target & i_target,
                                             fapi::ReturnCode i_bad_rc )
                                           
{

    FAPI_INF("ENTER mss_unmask_draminit_training_errors()"); 
    
    fapi::ReturnCode l_rc;
    uint32_t l_ecmd_rc = 0;            

    //*************************
    //*************************
    // MBACALFIR
    //*************************
    //*************************

    ecmdDataBufferBase l_mbacalfir_mask(64);
    ecmdDataBufferBase l_mbacalfir_mask_and(64);

    // NOTE: In the IPL sequence, mss_unmask_draminit_errors has already been
    // called, which has already set the MBACALFIR action regs to their runtime
    // values, so no need to touch the action regs here.

    // NOTE: In the IPL sequence, mss_unmask_draminit_errors has already been
    // called, which has already unmasked the approproiate MBACALFIR errors
    // following mss_draminit. So all we will do here is unmask a few more
    // errors that would be considered valid after the mss_draminit_training
    // procedure. 
    

    // Read mask
    l_rc = fapiGetScom_w_retry(i_target, MBA01_MBACALFIR_MASK_0x03010403, l_mbacalfir_mask); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }
    
    // TODO: Here is where I could clear bits that were bogus, before I unmask 
    //       them. But typically we are expecting the bit set at this point
    //       to be valid errors for PRD to log.


    //(Action0, Action1, Mask)
    //
    // (0,0,0) = checkstop
    // (0,1,0) = recoverable error
    // (1,0,0) = report unused
    // (1,1,0) = machine check
    // (x,x,1) = error is masked
                
    l_ecmd_rc |= l_mbacalfir_mask_and.flushTo1();        
        
    // 0	MBA Recoverable Error       recoverable         umask
    l_ecmd_rc |= l_mbacalfir_mask_and.clearBit(0);

    // 4	RCD Parity Error 0          recoverable         unmask (only if set)
    // TODO: Unmask, only if set, only if ISD DIMM

    // 7	RCD Parity Error 1          recoverable         unmask (only if set)
    // TODO: Unmask, only if set, only if ISD DIMM

    if(l_ecmd_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        

        l_rc.setEcmdError(l_ecmd_rc);
        return l_rc;
    }                                                                              

    
    // Write mask AND
    l_rc = fapiPutScom_w_retry(i_target, MBA01_MBACALFIR_MASK_AND_0x03010404, l_mbacalfir_mask_and); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }

    //************************************************    
    // DEBUG: read them all back to verify
    l_rc = fapiGetScom_w_retry(i_target, MBA01_MBACALFIR_MASK_0x03010403, l_mbacalfir_mask); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }

    //************************************************    
    
    
    FAPI_INF("EXIT mss_unmask_draminit_training_errors()"); 

    return i_bad_rc;
}


//------------------------------------------------------------------------------
// mss_unmask_draminit_training_advanced_errors
//------------------------------------------------------------------------------
                                           
fapi::ReturnCode mss_unmask_draminit_training_advanced_errors( 
                                             const fapi::Target & i_target,
                                             fapi::ReturnCode i_bad_rc )
                                           
{

    FAPI_INF("ENTER mss_unmask_draminit_training_advanced_errors()"); 
    
    fapi::ReturnCode l_rc;
    uint32_t l_ecmd_rc = 0;            

    //*************************
    //*************************
    // MBACALFIR
    //*************************
    //*************************

    ecmdDataBufferBase l_mbacalfir_mask(64);
    ecmdDataBufferBase l_mbacalfir_mask_and(64);

    // NOTE: In the IPL sequence, mss_unmask_draminit_errors has already been
    // called, which has already set the MBACALFIR action regs to their runtime
    // values, so no need to touch the action regs here.

    // NOTE: In the IPL sequence, mss_unmask_draminit_errors and 
    // mss_unmask_draminit_training has already been
    // called, which has already unmasked the approproiate MBACALFIR errors
    // following mss_draminit and mss_draminit_training. So all we will do here
    // is unmask a few more errors that would be considered valid after the
    // mss_draminit_training_advanced procedure. 
    

    // Read mask
    l_rc = fapiGetScom_w_retry(i_target, MBA01_MBACALFIR_MASK_0x03010403, l_mbacalfir_mask); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }
    
    // TODO: Here is where I could clear bits that were bogus, before I unmask 
    //       them. But typically we are expecting the bit set at this point
    //       to be valid errors for PRD to log.


    //(Action0, Action1, Mask)
    //
    // (0,0,0) = checkstop
    // (0,1,0) = recoverable error
    // (1,0,0) = report unused
    // (1,1,0) = machine check
    // (x,x,1) = error is masked
                
    l_ecmd_rc |= l_mbacalfir_mask_and.flushTo1();            
    
    // 4	RCD Parity Error 0          recoverable         unmask 
    // TODO: Unmask, only if ISD DIMM

    // 7	RCD Parity Error 1          recoverable         unmask 
    // TODO: Unmask, only if ISD DIMM

    // 8	mbx to mba par error        channel checkstop   unmask
    l_ecmd_rc |= l_mbacalfir_mask_and.clearBit(8);

    // 11	mba_maint ue                recoverable         unmask
    l_ecmd_rc |= l_mbacalfir_mask_and.clearBit(11);

    // 12	mba_maint ce                recoverable         unmask
    l_ecmd_rc |= l_mbacalfir_mask_and.clearBit(12);

    // 17	wrq_rrq_hang_err            recoverable         unmask
    l_ecmd_rc |= l_mbacalfir_mask_and.clearBit(17);


    if(l_ecmd_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        

        l_rc.setEcmdError(l_ecmd_rc);
        return l_rc;
    }                                                                              

    
    // Write mask AND
    l_rc = fapiPutScom_w_retry(i_target, MBA01_MBACALFIR_MASK_AND_0x03010404, l_mbacalfir_mask_and); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }

    //************************************************    
    // DEBUG: read them all back to verify
    l_rc = fapiGetScom_w_retry(i_target, MBA01_MBACALFIR_MASK_0x03010403, l_mbacalfir_mask); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }

    //************************************************ 
    

    //*************************
    //*************************
    // MBSFIR
    //*************************
    //*************************    
    
    fapi::Target l_targetCentaur;
    uint8_t l_mbaPosition;             // 0 = mba01, 1 = mba23

    uint32_t l_mbsfir_mask_address[2]={
    // port0/1                       port2/3
    MBS01_MBSFIRMASK_0x02011603,     MBS23_MBSFIRMASK_0x02011703};

    uint32_t l_mbsfir_mask_or_address[2]={
    // port0/1                       port2/3
    MBS01_MBSFIRMASK_OR_0x02011605,  MBS23_MBSFIRMASK_OR_0x02011705};

    uint32_t l_mbsfir_mask_and_address[2]={
    // port0/1                       port2/3
    MBS01_MBSFIRMASK_AND_0x02011604, MBS23_MBSFIRMASK_AND_0x02011704};

    uint32_t l_mbsfir_action0_address[2]={
    // port0/1                       port2/3
    MBS01_MBSFIRACT0_0x02011606,     MBS23_MBSFIRACT0_0x02011706};

    uint32_t l_mbsfir_action1_address[2]={
    // port0/1                       port2/3
    MBS01_MBSFIRACT1_0x02011607,     MBS23_MBSFIRACT1_0x02011707};

    ecmdDataBufferBase l_mbsfir_mask(64);
    ecmdDataBufferBase l_mbsfir_mask_or(64);
    ecmdDataBufferBase l_mbsfir_mask_and(64);        
    ecmdDataBufferBase l_mbsfir_action0(64);
    ecmdDataBufferBase l_mbsfir_action1(64);

    // Get Centaur target for the given MBA
    l_rc = fapiGetParentChip(i_target, l_targetCentaur);
    if(l_rc)
    {
        FAPI_ERR("Error getting Centaur parent target for the given MBA");
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }
    
    // Get MBA position: 0 = mba01, 1 = mba23
    l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target, l_mbaPosition);
    if(l_rc)
    {
        FAPI_ERR("Error getting MBA position");
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);                
        return l_rc;
    }    
    
    // Read mask
    l_rc = fapiGetScom_w_retry(l_targetCentaur, 
                               l_mbsfir_mask_address[l_mbaPosition], 
                               l_mbsfir_mask); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }
    
    // TODO: Here is where I could clear bits that were bogus, before I unmask 
    //       them. But typically we are expecting the bit set at this point
    //       to be valid errors for PRD to log.


    //(Action0, Action1, Mask)
    //
    // (0,0,0) = checkstop
    // (0,1,0) = recoverable error
    // (1,0,0) = report unused
    // (1,1,0) = machine check
    // (x,x,1) = error is masked
                
    l_ecmd_rc |= l_mbsfir_action0.flushTo0();
    l_ecmd_rc |= l_mbsfir_action1.flushTo0();
    l_ecmd_rc |= l_mbsfir_mask_or.flushTo0();
    l_ecmd_rc |= l_mbsfir_mask_and.flushTo1();

    // 0	scom_par_errors             recoverable         unmask
    l_ecmd_rc |= l_mbsfir_action0.clearBit(0);            
    l_ecmd_rc |= l_mbsfir_action1.setBit(0);
    l_ecmd_rc |= l_mbsfir_mask_and.clearBit(0);

    // 1	mbx_par_errors              channel checkstop   unmask
    l_ecmd_rc |= l_mbsfir_action0.clearBit(1);            
    l_ecmd_rc |= l_mbsfir_action1.clearBit(1);
    l_ecmd_rc |= l_mbsfir_mask_and.clearBit(1);

    // 2:14	RESERVED                    recoverable         mask (forever)
    l_ecmd_rc |= l_mbsfir_action0.clearBit(2,13);            
    l_ecmd_rc |= l_mbsfir_action1.setBit(2,13);
    l_ecmd_rc |= l_mbsfir_mask_or.setBit(2,13);

    // 15	internal scom error         recoverable         mask (tbd)
    l_ecmd_rc |= l_mbsfir_action0.clearBit(15);            
    l_ecmd_rc |= l_mbsfir_action1.setBit(15);
    l_ecmd_rc |= l_mbsfir_mask_or.setBit(15);

    // 16	internal scom error clone   recoverable         mask (tbd)
    l_ecmd_rc |= l_mbsfir_action0.clearBit(16);            
    l_ecmd_rc |= l_mbsfir_action1.setBit(16);
    l_ecmd_rc |= l_mbsfir_mask_or.setBit(16);

    // 17:63 RESERVED           not implemented, so won't touch these
    
        
    if(l_ecmd_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        

        l_rc.setEcmdError(l_ecmd_rc);
        return l_rc;
    }                                                                              

    // Write action0
    l_rc = fapiPutScom_w_retry(l_targetCentaur, 
                               l_mbsfir_action0_address[l_mbaPosition], 
                               l_mbsfir_action0); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }

    // Write action1
    l_rc = fapiPutScom_w_retry(l_targetCentaur, 
                               l_mbsfir_action1_address[l_mbaPosition], 
                               l_mbsfir_action1); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }

    
    // Write mask OR
    l_rc = fapiPutScom_w_retry(l_targetCentaur, 
                               l_mbsfir_mask_or_address[l_mbaPosition], 
                               l_mbsfir_mask_or); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }


    // Write mask AND
    l_rc = fapiPutScom_w_retry(l_targetCentaur, 
                               l_mbsfir_mask_and_address[l_mbaPosition], 
                               l_mbsfir_mask_and); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }


    //************************************************    
    // DEBUG: read them all back to verify
    l_rc = fapiGetScom_w_retry(l_targetCentaur, 
                               l_mbsfir_action0_address[l_mbaPosition], 
                               l_mbsfir_action0); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }

    l_rc = fapiGetScom_w_retry(l_targetCentaur, 
                               l_mbsfir_action1_address[l_mbaPosition], 
                               l_mbsfir_action1); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }

    l_rc = fapiGetScom_w_retry(l_targetCentaur, 
                               l_mbsfir_mask_address[l_mbaPosition], 
                               l_mbsfir_mask); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }

    //************************************************    
   
    
    FAPI_INF("EXIT mss_unmask_draminit_training_advanced_errors()"); 

    return i_bad_rc;
}



//------------------------------------------------------------------------------
// mss_unmask_maint_errors
//------------------------------------------------------------------------------
                                           
fapi::ReturnCode mss_unmask_maint_errors(const fapi::Target & i_target,
                                         fapi::ReturnCode i_bad_rc )
                                           
{

    // Target: Centaur
    
    FAPI_INF("ENTER mss_unmask_maint_errors()"); 
    
    fapi::ReturnCode l_rc;
    uint32_t l_ecmd_rc = 0; 
    std::vector<fapi::Target> l_mbaChiplets;
    uint8_t l_mbaPosition;             // 0 = mba01, 1 = mba23

    ecmdDataBufferBase l_mbacalfir_mask(64);
    ecmdDataBufferBase l_mbacalfir_mask_and(64);    

    ecmdDataBufferBase l_mbafir_mask(64);
    ecmdDataBufferBase l_mbafir_mask_and(64);
           
    ecmdDataBufferBase l_mbaspa_mask(64);

    uint32_t l_mbeccfir_mask_address[2]={
    // port0/1                            port2/3
    MBS_ECC0_MBECCFIR_MASK_0x02011443,    MBS_ECC1_MBECCFIR_MASK_0x02011483};

    uint32_t l_mbeccfir_mask_or_address[2]={
    // port0/1                            port2/3
    MBS_ECC0_MBECCFIR_MASK_OR_0x02011445, MBS_ECC1_MBECCFIR_MASK_OR_0x02011485};

    uint32_t l_mbeccfir_mask_and_address[2]={
    // port0/1                            port2/3
    MBS_ECC0_MBECCFIR_MASK_AND_0x02011444,MBS_ECC1_MBECCFIR_MASK_AND_0x02011484};

    uint32_t l_mbeccfir_action0_address[2]={
    // port0/1                            port2/3
    MBS_ECC0_MBECCFIR_ACTION0_0x02011446, MBS_ECC1_MBECCFIR_ACTION0_0x02011486};

    uint32_t l_mbeccfir_action1_address[2]={
    // port0/1                            port2/3
    MBS_ECC0_MBECCFIR_ACTION1_0x02011447, MBS_ECC1_MBECCFIR_ACTION1_0x02011487};

    ecmdDataBufferBase l_mbeccfir_mask(64);
    ecmdDataBufferBase l_mbeccfir_mask_or(64);
    ecmdDataBufferBase l_mbeccfir_mask_and(64);
    ecmdDataBufferBase l_mbeccfir_action0(64);
    ecmdDataBufferBase l_mbeccfir_action1(64);



    // Get associated functional MBAs on this centaur
    l_rc = fapiGetChildChiplets(i_target,
                                fapi::TARGET_TYPE_MBA_CHIPLET,
                                l_mbaChiplets);
    if(l_rc)
    {
        FAPI_ERR("Error getting functional MBAs on this Centaur");
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);                
        return l_rc;
    }    

    // Loop through functional MBAs on this Centaur
    for (uint32_t i=0; i < l_mbaChiplets.size(); i++)
    {

        // Get MBA position: 0 = mba01, 1 = mba23
        l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &l_mbaChiplets[i], l_mbaPosition);
        if(l_rc)
        {
            FAPI_ERR("Error getting MBA position");
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);                
            return l_rc;
        }    




        //*************************
        //*************************
        // MBACALFIR
        //*************************
        //*************************    


        // NOTE: In the IPL sequence, mss_unmask_draminit_errors has already been
        // called, which has already set the MBACALFIR action regs to their runtime
        // values, so no need to touch the action regs here.

        // NOTE: In the IPL sequence, mss_unmask_draminit_errors,
        // mss_unmask_draminit_training and mss_unmask_draminit_training_advanced
        // have already been called, which have already unmasked the approproiate
        // MBACALFIR errors following mss_draminit, mss_draminit_training, and
        // mss_unmask_draminit_training_advanced. So all we will do here
        // is unmask a few more errors that would be considered valid after the
        // mss_draminit_mc procedure. 
    
        // Read mask
        l_rc = fapiGetScom_w_retry(l_mbaChiplets[i],
                                   MBA01_MBACALFIR_MASK_0x03010403,
                                   l_mbacalfir_mask);       
        if(l_rc)
        {
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);        
            return l_rc;
        }
        
        // TODO: Here is where I could clear bits that were bogus, before I unmask 
        //       them. But typically we are expecting the bit set at this point
        //       to be valid errors for PRD to log.


        //(Action0, Action1, Mask)
        //
        // (0,0,0) = checkstop
        // (0,1,0) = recoverable error
        // (1,0,0) = report unused
        // (1,1,0) = machine check
        // (x,x,1) = error is masked
        
        l_ecmd_rc |= l_mbacalfir_mask_and.flushTo1();            
                    
        // 1	MBA Nonrecoverable Error    channel checkstop   unmask
        l_ecmd_rc |= l_mbacalfir_mask_and.clearBit(1);

        // 2	Refresh Overrun             recoverable         unmask
        l_ecmd_rc |= l_mbacalfir_mask_and.clearBit(2);
        
        // 5	ddr0_cal_timeout_err        recoverable         unmask
        l_ecmd_rc |= l_mbacalfir_mask_and.clearBit(5);

        // 6	ddr1_cal_timeout_err        recoverable         unmask
        l_ecmd_rc |= l_mbacalfir_mask_and.clearBit(6);
        
        if(l_ecmd_rc)
        {
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);        

            l_rc.setEcmdError(l_ecmd_rc);
            return l_rc;
        }                                                                              

        // Write mask AND
        l_rc = fapiPutScom_w_retry(l_mbaChiplets[i],
                                   MBA01_MBACALFIR_MASK_AND_0x03010404,
                                   l_mbacalfir_mask_and); 
        if(l_rc)
        {
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);        
            return l_rc;
        }

        //************************************************    
        // DEBUG: read them all back to verify
        l_rc = fapiGetScom_w_retry(l_mbaChiplets[i],
                                   MBA01_MBACALFIR_MASK_0x03010403,
                                   l_mbacalfir_mask);       
        if(l_rc)
        {
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);        
            return l_rc;
        }

        //************************************************ 
    

        //*************************
        //*************************
        // MBAFIR
        //*************************
        //*************************    
        
        // NOTE: In the IPL sequence, mss_unmask_ddr_phy_errors has already been
        // called, which has already set the MBAFIR action regs to their runtime
        // values, so no need to touch the action regs here.

        // NOTE: In the IPL sequence, mss_unmask_ddr_phy_errors,
        // has already been called, which has already unmasked the approproiate
        // MBAFIR errors following mss_ddr_phy_reset. So all we will do here
        // is unmask a few more errors that would be considered valid after the
        // mss_draminit_mc procedure. 
        
        // Read mask
        l_rc = fapiGetScom_w_retry(l_mbaChiplets[i],
                                   MBA01_MBAFIRMASK_0x03010603,
                                   l_mbafir_mask); 
        if(l_rc)
        {
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);        
            return l_rc;
        }
        
        // TODO: Here is where I could clear bits that were bogus, before I unmask 
        //       them. But typically we are expecting the bit set at this point
        //       to be valid errors for PRD to log.


        //(Action0, Action1, Mask)
        //
        // (0,0,0) = checkstop
        // (0,1,0) = recoverable error
        // (1,0,0) = report unused
        // (1,1,0) = machine check
        // (x,x,1) = error is masked
                    
        l_ecmd_rc |= l_mbafir_mask_and.flushTo1();

        // 2	Multi_address_Maint_timeout recoverable         unmask
        l_ecmd_rc |= l_mbafir_mask_and.clearBit(2);


        // 7	wrd_caw2_data_ce_ue_err     recoverable         unmask
        l_ecmd_rc |= l_mbafir_mask_and.clearBit(7);

        if(l_ecmd_rc)
        {
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);        

            l_rc.setEcmdError(l_ecmd_rc);
            return l_rc;
        }                                                                              

        // Write mask AND
        l_rc = fapiPutScom_w_retry(l_mbaChiplets[i],
                                   MBA01_MBAFIRMASK_AND_0x03010604,
                                   l_mbafir_mask_and); 
        if(l_rc)
        {
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);        
            return l_rc;
        }


        //************************************************    
        // DEBUG: read them all back to verify
        l_rc = fapiGetScom_w_retry(l_mbaChiplets[i],
                                   MBA01_MBAFIRMASK_0x03010603,
                                   l_mbafir_mask); 
        if(l_rc)
        {
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);        
            return l_rc;
        }

        //************************************************    


        //*************************
        //*************************
        // MBASPA
        //*************************
        //*************************
        
                
        // Read mask
        l_rc = fapiGetScom_w_retry(l_mbaChiplets[i],
                                   MBA01_MBSPAMSKQ_0x03010614,
                                   l_mbaspa_mask); 
        if(l_rc)
        {
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);        
            return l_rc;
        }
        
        // TODO: Here is where I could clear bits that were bogus, before I unmask 
        //       them. But typically we are expecting the bit set at this point
        //       to be valid errors for PRD to log.


        // 0	Command_Complete                             mask (broken on DD1)
        // NOTE: This bit broken in DD1.
        // It can be made to come on when cmd completes clean, or make to come
        // on when cmd stops on error, but can't be set to do both. 
        l_ecmd_rc |= l_mbaspa_mask.setBit(0);            

        // 1	Hard_CE_ETE_Attn                             mask (forever)
        // NOTE: FW wants to mask these and rely instead on detecting the 
        // cmd complete attention, then checking these manually to see if 
        // they cause the cmd to stop
        // NOTE: Hards counted during super fast read, but can't be called 
        // true hard CEs since super fast read doesn't write back and read again.
        l_ecmd_rc |= l_mbaspa_mask.setBit(1);            

        // 2	Soft_CE_ETE_Attn                             mask (forever)
        // NOTE: FW wants to mask these and rely instead on detecting the 
        // cmd complete attention, then checking these manually to see if 
        // they cause the cmd to stop
        // NOTE: Softs not counted during super fast read.
        l_ecmd_rc |= l_mbaspa_mask.setBit(2);            

        // 3	Intermittent_ETE_Attn                        mask (forever)
        // NOTE: FW wants to mask these and rely instead on detecting the 
        // cmd complete attention, then checking these manually to see if 
        // they cause the cmd to stop
        // NOTE: Intermittents not counted during super fast read.
        l_ecmd_rc |= l_mbaspa_mask.setBit(3);            

        // 4	RCE_ETE_Attn                                 mask (forever)
        // NOTE: FW wants to mask these and rely instead on detecting the 
        // cmd complete attention, then checking these manually to see if 
        // they cause the cmd to stop
        // NOTE: RCEs not counted during super fast read.
        l_ecmd_rc |= l_mbaspa_mask.setBit(4);            

        // 5	Emergency_Throttle_Attn                      masked (forever)
        l_ecmd_rc |= l_mbaspa_mask.setBit(5);            

        // 6	Firmware_Attn0                               masked (forever)
        l_ecmd_rc |= l_mbaspa_mask.setBit(6);            

        // 7	Firmware_Attn1                               masked (forever)
        l_ecmd_rc |= l_mbaspa_mask.setBit(7);            

        // 8	wat_debug_attn                               unmasked
        // NOTE: DD1 workaround for broken bit 0. This bit will come on whenever 
        // cmd stops, either stop clean or stop on error.
        l_ecmd_rc |= l_mbaspa_mask.clearBit(8);            

        // 9	Spare_Attn1                                  masked (forever)
        l_ecmd_rc |= l_mbaspa_mask.setBit(9);            

        // 10	MCBIST_Done                                  masked (forever)
        l_ecmd_rc |= l_mbaspa_mask.setBit(10);            

        // 11:63 RESERVED     not implemented, so won't touch these
                    

        if(l_ecmd_rc)
        {
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);        

            l_rc.setEcmdError(l_ecmd_rc);
            return l_rc;
        }                                                                              
        
        // Write mask
        l_rc = fapiPutScom_w_retry(l_mbaChiplets[i],
                                   MBA01_MBSPAMSKQ_0x03010614,
                                   l_mbaspa_mask); 
        if(l_rc)
        {
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);        
            return l_rc;
        }

        //************************************************    
        // DEBUG: read them all back to verify
        l_rc = fapiGetScom_w_retry(l_mbaChiplets[i],
                                   MBA01_MBSPAMSKQ_0x03010614,
                                   l_mbaspa_mask);
        if(l_rc)
        {
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);        
            return l_rc;
        }
        //************************************************    



        //*************************
        //*************************
        // MBECCFIR
        //*************************
        //*************************    
        
        // Get MBA position: 0 = mba01, 1 = mba23
        l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &l_mbaChiplets[i], l_mbaPosition);
        if(l_rc)
        {
            FAPI_ERR("Error getting MBA position");
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);                
            return l_rc;
        }    
        
        // Read mask
        l_rc = fapiGetScom_w_retry(i_target, 
                                   l_mbeccfir_mask_address[l_mbaPosition], 
                                   l_mbeccfir_mask); 
        if(l_rc)
        {
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);        
            return l_rc;
        }
        
        // TODO: Here is where I could clear bits that were bogus, before I unmask 
        //       them. But typically we are expecting the bit set at this point
        //       to be valid errors for PRD to log.


        //(Action0, Action1, Mask)
        //
        // (0,0,0) = checkstop
        // (0,1,0) = recoverable error
        // (1,0,0) = report unused
        // (1,1,0) = machine check
        // (x,x,1) = error is masked
                    
        l_ecmd_rc |= l_mbeccfir_action0.flushTo0();
        l_ecmd_rc |= l_mbeccfir_action1.flushTo0();
        l_ecmd_rc |= l_mbeccfir_mask_or.flushTo0();
        l_ecmd_rc |= l_mbeccfir_mask_and.flushTo1();

        // 0:7	Memory MPE Rank 0:7         recoverable         mask (until mainline traffic)
        l_ecmd_rc |= l_mbeccfir_action0.clearBit(0,8);            
        l_ecmd_rc |= l_mbeccfir_action1.setBit(0,8);
        l_ecmd_rc |= l_mbeccfir_mask_or.setBit(0,8);

        // 8:15	Reserved                    recoverable         mask (forever)
        l_ecmd_rc |= l_mbeccfir_action0.clearBit(8,8);            
        l_ecmd_rc |= l_mbeccfir_action1.setBit(8,8);
        l_ecmd_rc |= l_mbeccfir_mask_or.setBit(8,8);
        
        // 16	Memory NCE                  recoverable         mask (until mainline traffic)
        l_ecmd_rc |= l_mbeccfir_action0.clearBit(16);            
        l_ecmd_rc |= l_mbeccfir_action1.setBit(16);
        l_ecmd_rc |= l_mbeccfir_mask_or.setBit(16);

        // 17	Memory RCE                  recoverable         mask (until mainline traffic)
        l_ecmd_rc |= l_mbeccfir_action0.clearBit(17);            
        l_ecmd_rc |= l_mbeccfir_action1.setBit(17);
        l_ecmd_rc |= l_mbeccfir_mask_or.setBit(17);

        // 18	Memory SUE                  recoverable         mask (forever)
        l_ecmd_rc |= l_mbeccfir_action0.clearBit(18);            
        l_ecmd_rc |= l_mbeccfir_action1.setBit(18);
        l_ecmd_rc |= l_mbeccfir_mask_or.setBit(18);

        // 19	Memory UE                   recoverable         mask (until mainline traffic)
        l_ecmd_rc |= l_mbeccfir_action0.clearBit(19);            
        l_ecmd_rc |= l_mbeccfir_action1.setBit(19);
        l_ecmd_rc |= l_mbeccfir_mask_or.setBit(19);

        // 20:27	Maint MPE Rank 0:7      recoverable         mask (forever)
        // NOTE: FW wants to mask these and rely instead on detecting the 
        // cmd complete attention, then checking these manually to see if 
        // they cause the cmd to stop
        l_ecmd_rc |= l_mbeccfir_action0.clearBit(20,8);            
        l_ecmd_rc |= l_mbeccfir_action1.setBit(20,8);
        l_ecmd_rc |= l_mbeccfir_mask_or.setBit(20,8);

        // 28:35	Reserved                recoverable         mask (forever)
        l_ecmd_rc |= l_mbeccfir_action0.clearBit(28,8);            
        l_ecmd_rc |= l_mbeccfir_action1.setBit(28,8);
        l_ecmd_rc |= l_mbeccfir_mask_or.setBit(28,8);
        
        // 36	Maintenance NCE             recoverable         mask (forever)
        // NOTE: PRD planning to use maint CE thresholds instead.
        l_ecmd_rc |= l_mbeccfir_action0.clearBit(36);            
        l_ecmd_rc |= l_mbeccfir_action1.setBit(36);
        l_ecmd_rc |= l_mbeccfir_mask_or.setBit(36);

        // 37	Maintenance SCE             recoverable         mask (forever)
        // NOTE: Don't care if symbol still bad after it's symbol marked.
        l_ecmd_rc |= l_mbeccfir_action0.clearBit(37);            
        l_ecmd_rc |= l_mbeccfir_action1.setBit(37);
        l_ecmd_rc |= l_mbeccfir_mask_or.setBit(37);

        // 38	Maintenance MCE             recoverable         mask (forever)
        // NOTE: PRD plans to check manually as part of verify chip mark procedure.
        l_ecmd_rc |= l_mbeccfir_action0.clearBit(38);            
        l_ecmd_rc |= l_mbeccfir_action1.setBit(38);
        l_ecmd_rc |= l_mbeccfir_mask_or.setBit(38);

        // 39	Maintenance RCE             recoverable         mask (forever)
        // NOTE: PRD planning to use maint RCE thresholds instead.
        l_ecmd_rc |= l_mbeccfir_action0.clearBit(39);            
        l_ecmd_rc |= l_mbeccfir_action1.setBit(39);
        l_ecmd_rc |= l_mbeccfir_mask_or.setBit(39);

        // 40	Maintenance SUE             recoverable         mask (forever)
        l_ecmd_rc |= l_mbeccfir_action0.clearBit(40);            
        l_ecmd_rc |= l_mbeccfir_action1.setBit(40);
        l_ecmd_rc |= l_mbeccfir_mask_or.setBit(40);

        // 41	Maintenance UE              recoverable         mask (forever)
        // NOTE: FW wants to mask these and rely instead on detecting the 
        // cmd complete attention, then checking these manually to see if 
        // they cause the cmd to stop
        l_ecmd_rc |= l_mbeccfir_action0.clearBit(41);            
        l_ecmd_rc |= l_mbeccfir_action1.setBit(41);
        l_ecmd_rc |= l_mbeccfir_mask_or.setBit(41);

        // 42	MPE during maintenance mark mode  recoverable   mask (forever)
        l_ecmd_rc |= l_mbeccfir_action0.clearBit(42);            
        l_ecmd_rc |= l_mbeccfir_action1.setBit(42);
        l_ecmd_rc |= l_mbeccfir_mask_or.setBit(42);

        // 43	Prefetch Memory UE          recoverable         mask (until mainline traffic)
        l_ecmd_rc |= l_mbeccfir_action0.clearBit(43);            
        l_ecmd_rc |= l_mbeccfir_action1.setBit(43);
        l_ecmd_rc |= l_mbeccfir_mask_or.setBit(43);

        // 44	Memory RCD parity error     recoverable         mask (forever)
        l_ecmd_rc |= l_mbeccfir_action0.clearBit(44);            
        l_ecmd_rc |= l_mbeccfir_action1.setBit(44);
        l_ecmd_rc |= l_mbeccfir_mask_or.setBit(44);

        // 45	Maint RCD parity error.     recoverable         mask (forever)
        l_ecmd_rc |= l_mbeccfir_action0.clearBit(45);            
        l_ecmd_rc |= l_mbeccfir_action1.setBit(45);
        l_ecmd_rc |= l_mbeccfir_mask_or.setBit(45);

        // 46	Recoverable reg parity      recoverable         unmask
        l_ecmd_rc |= l_mbeccfir_action0.clearBit(46);            
        l_ecmd_rc |= l_mbeccfir_action1.setBit(46);
        l_ecmd_rc |= l_mbeccfir_mask_and.clearBit(46);


        // 47	Unrecoverable reg parity    channel checkstop   unmask
        l_ecmd_rc |= l_mbeccfir_action0.clearBit(47);            
        l_ecmd_rc |= l_mbeccfir_action1.clearBit(47);
        l_ecmd_rc |= l_mbeccfir_mask_and.clearBit(47);

        // 48	Maskable reg parity error   recoverable         mask (forever)
        l_ecmd_rc |= l_mbeccfir_action0.clearBit(48);            
        l_ecmd_rc |= l_mbeccfir_action1.setBit(48);
        l_ecmd_rc |= l_mbeccfir_mask_or.setBit(48);

        // 49	ecc datapath parity error   channel checkstop   unmask
        l_ecmd_rc |= l_mbeccfir_action0.clearBit(49);            
        l_ecmd_rc |= l_mbeccfir_action1.clearBit(49);
        l_ecmd_rc |= l_mbeccfir_mask_and.clearBit(49);

        // 50	internal scom error         recovereble         mask
        l_ecmd_rc |= l_mbeccfir_action0.clearBit(50);            
        l_ecmd_rc |= l_mbeccfir_action1.setBit(50);
        l_ecmd_rc |= l_mbeccfir_mask_or.setBit(50);

        // 51	internal scom error clone   recovereble         mask
        l_ecmd_rc |= l_mbeccfir_action0.clearBit(51);            
        l_ecmd_rc |= l_mbeccfir_action1.setBit(51);
        l_ecmd_rc |= l_mbeccfir_mask_or.setBit(51);

        // 52:63	Reserved    not implemented, so won't touch these


        
            
        if(l_ecmd_rc)
        {
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);        

            l_rc.setEcmdError(l_ecmd_rc);
            return l_rc;
        }                                                                              

        // Write action0
        l_rc = fapiPutScom_w_retry(i_target, 
                                   l_mbeccfir_action0_address[l_mbaPosition], 
                                   l_mbeccfir_action0); 
        if(l_rc)
        {
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);        
            return l_rc;
        }

        // Write action1
        l_rc = fapiPutScom_w_retry(i_target, 
                                   l_mbeccfir_action1_address[l_mbaPosition], 
                                   l_mbeccfir_action1); 
        if(l_rc)
        {
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);        
            return l_rc;
        }

        
        // Write mask OR
        l_rc = fapiPutScom_w_retry(i_target, 
                                   l_mbeccfir_mask_or_address[l_mbaPosition], 
                                   l_mbeccfir_mask_or); 
        if(l_rc)
        {
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);        
            return l_rc;
        }

        // Write mask AND
        l_rc = fapiPutScom_w_retry(i_target, 
                                   l_mbeccfir_mask_and_address[l_mbaPosition], 
                                   l_mbeccfir_mask_and); 
        if(l_rc)
        {
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);        
            return l_rc;
        }


        //************************************************    
        // DEBUG: read them all back to verify
        l_rc = fapiGetScom_w_retry(i_target, 
                                   l_mbeccfir_action0_address[l_mbaPosition], 
                                   l_mbeccfir_action0); 
        if(l_rc)
        {
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);        
            return l_rc;
        }

        l_rc = fapiGetScom_w_retry(i_target, 
                                   l_mbeccfir_action1_address[l_mbaPosition], 
                                   l_mbeccfir_action1); 
        if(l_rc)
        {
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);        
            return l_rc;
        }

        l_rc = fapiGetScom_w_retry(i_target, 
                                   l_mbeccfir_mask_address[l_mbaPosition], 
                                   l_mbeccfir_mask); 
        if(l_rc)
        {
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);        
            return l_rc;
        }

        //************************************************    

   } // End for loop through functional MBAs on this Centaur
    
    FAPI_INF("EXIT mss_unmask_maint_errors()"); 

    return i_bad_rc;
}




//------------------------------------------------------------------------------
// mss_unmask_fetch_errors
//------------------------------------------------------------------------------
                                           
fapi::ReturnCode mss_unmask_fetch_errors(const fapi::Target & i_target,
                                         fapi::ReturnCode i_bad_rc )
                                           
{

    // Target: Centaur

    FAPI_INF("ENTER mss_unmask_fetch_errors()"); 
    
    fapi::ReturnCode l_rc;
    uint32_t l_ecmd_rc = 0;            


    //*************************
    //*************************
    // SCAC_LFIR
    //*************************
    //*************************    
    
    ecmdDataBufferBase l_scac_lfir_mask(64);
    ecmdDataBufferBase l_scac_lfir_mask_or(64);
    ecmdDataBufferBase l_scac_lfir_mask_and(64);
    ecmdDataBufferBase l_scac_lfir_action0(64);
    ecmdDataBufferBase l_scac_lfir_action1(64);
    
    // Read mask
    l_rc = fapiGetScom_w_retry(i_target, SCAC_FIRMASK_0x020115C3, l_scac_lfir_mask); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }
    
    // TODO: Here is where I could clear bits that were bogus, before I unmask 
    //       them. But typically we are expecting the bit set at this point
    //       to be valid errors for PRD to log.


    //(Action0, Action1, Mask)
    //
    // (0,0,0) = checkstop
    // (0,1,0) = recoverable error
    // (1,0,0) = report unused
    // (1,1,0) = machine check
    // (x,x,1) = error is masked

    l_ecmd_rc |= l_scac_lfir_action0.flushTo0();
    l_ecmd_rc |= l_scac_lfir_action1.flushTo0();
    l_ecmd_rc |= l_scac_lfir_mask_or.flushTo0();
    l_ecmd_rc |= l_scac_lfir_mask_and.flushTo1();
                
    // 0	I2CMInvAddr                 recoverable         masked (forever)
    l_ecmd_rc |= l_scac_lfir_action0.clearBit(0);            
    l_ecmd_rc |= l_scac_lfir_action1.setBit(0);
    l_ecmd_rc |= l_scac_lfir_mask_or.setBit(0);
    
    // 1	I2CMInvWrite                recoverable         masked (forever)
    l_ecmd_rc |= l_scac_lfir_action0.clearBit(1);            
    l_ecmd_rc |= l_scac_lfir_action1.setBit(1);
    l_ecmd_rc |= l_scac_lfir_mask_or.setBit(1);

    // 2	I2CMInvRead                 recoverable         masked (forever)
    l_ecmd_rc |= l_scac_lfir_action0.clearBit(2);            
    l_ecmd_rc |= l_scac_lfir_action1.setBit(2);
    l_ecmd_rc |= l_scac_lfir_mask_or.setBit(2);

    // 3	I2CMApar                    recoverable         masked (forever)
    l_ecmd_rc |= l_scac_lfir_action0.clearBit(3);            
    l_ecmd_rc |= l_scac_lfir_action1.setBit(3);
    l_ecmd_rc |= l_scac_lfir_mask_or.setBit(3);

    // 4	I2CMPar                     recoverable         masked (forever)
    l_ecmd_rc |= l_scac_lfir_action0.clearBit(4);            
    l_ecmd_rc |= l_scac_lfir_action1.setBit(4);
    l_ecmd_rc |= l_scac_lfir_mask_or.setBit(4);

    // 5	I2CMLBPar                   recoverable         masked (forever)
    l_ecmd_rc |= l_scac_lfir_action0.clearBit(5);            
    l_ecmd_rc |= l_scac_lfir_action1.setBit(5);
    l_ecmd_rc |= l_scac_lfir_mask_or.setBit(5);

    // 6:9	Expansion                   recoverable         masked (forever)
    l_ecmd_rc |= l_scac_lfir_action0.clearBit(6,4);            
    l_ecmd_rc |= l_scac_lfir_action1.setBit(6,4);
    l_ecmd_rc |= l_scac_lfir_mask_or.setBit(6,4);    
    
    // 10	I2CMInvCmd                  recoverable         masked (forever)
    l_ecmd_rc |= l_scac_lfir_action0.clearBit(10);            
    l_ecmd_rc |= l_scac_lfir_action1.setBit(10);
    l_ecmd_rc |= l_scac_lfir_mask_or.setBit(10);

    // 11	I2CMPErr                    recoverable         masked (forever)
    l_ecmd_rc |= l_scac_lfir_action0.clearBit(11);            
    l_ecmd_rc |= l_scac_lfir_action1.setBit(11);
    l_ecmd_rc |= l_scac_lfir_mask_or.setBit(11);

    // 12	I2CMOverrun                 recoverable         masked (forever)
    l_ecmd_rc |= l_scac_lfir_action0.clearBit(12);            
    l_ecmd_rc |= l_scac_lfir_action1.setBit(12);
    l_ecmd_rc |= l_scac_lfir_mask_or.setBit(12);

    // 13	I2CMAccess                  recoverable         masked (forever)
    l_ecmd_rc |= l_scac_lfir_action0.clearBit(13);            
    l_ecmd_rc |= l_scac_lfir_action1.setBit(13);
    l_ecmd_rc |= l_scac_lfir_mask_or.setBit(13);

    // 14	I2CMArb                     recoverable         masked (forever)
    l_ecmd_rc |= l_scac_lfir_action0.clearBit(14);            
    l_ecmd_rc |= l_scac_lfir_action1.setBit(14);
    l_ecmd_rc |= l_scac_lfir_mask_or.setBit(14);

    // 15	I2CMNack                    recoverable         masked (forever)
    l_ecmd_rc |= l_scac_lfir_action0.clearBit(15);            
    l_ecmd_rc |= l_scac_lfir_action1.setBit(15);
    l_ecmd_rc |= l_scac_lfir_mask_or.setBit(15);

    // 16	I2CMStop                    recoverable         masked (forever)
    l_ecmd_rc |= l_scac_lfir_action0.clearBit(16);            
    l_ecmd_rc |= l_scac_lfir_action1.setBit(16);
    l_ecmd_rc |= l_scac_lfir_mask_or.setBit(16);

    // 17	LocalPib1                   recoverable         masked (forever)
    l_ecmd_rc |= l_scac_lfir_action0.clearBit(17);            
    l_ecmd_rc |= l_scac_lfir_action1.setBit(17);
    l_ecmd_rc |= l_scac_lfir_mask_or.setBit(17);

    // 18	LocalPib2                   recoverable         masked (forever)
    l_ecmd_rc |= l_scac_lfir_action0.clearBit(18);            
    l_ecmd_rc |= l_scac_lfir_action1.setBit(18);
    l_ecmd_rc |= l_scac_lfir_mask_or.setBit(18);

    // 19	LocalPib3                   recoverable         masked (forever)
    l_ecmd_rc |= l_scac_lfir_action0.clearBit(19);            
    l_ecmd_rc |= l_scac_lfir_action1.setBit(19);
    l_ecmd_rc |= l_scac_lfir_mask_or.setBit(19);

    // 20	LocalPib4                   recoverable         masked (forever)
    l_ecmd_rc |= l_scac_lfir_action0.clearBit(20);            
    l_ecmd_rc |= l_scac_lfir_action1.setBit(20);
    l_ecmd_rc |= l_scac_lfir_mask_or.setBit(20);

    // 21	LocalPib5                   recoverable         masked (forever)
    l_ecmd_rc |= l_scac_lfir_action0.clearBit(21);            
    l_ecmd_rc |= l_scac_lfir_action1.setBit(21);
    l_ecmd_rc |= l_scac_lfir_mask_or.setBit(21);

    // 22	LocalPib6                   recoverable         masked (forever)
    l_ecmd_rc |= l_scac_lfir_action0.clearBit(22);            
    l_ecmd_rc |= l_scac_lfir_action1.setBit(22);
    l_ecmd_rc |= l_scac_lfir_mask_or.setBit(22);

    // 23	LocalPib7                   recoverable         masked (forever)
    l_ecmd_rc |= l_scac_lfir_action0.clearBit(23);            
    l_ecmd_rc |= l_scac_lfir_action1.setBit(23);
    l_ecmd_rc |= l_scac_lfir_mask_or.setBit(23);

    // 24	StallError                  recoverable         masked (forever)
    l_ecmd_rc |= l_scac_lfir_action0.clearBit(24);            
    l_ecmd_rc |= l_scac_lfir_action1.setBit(24);
    l_ecmd_rc |= l_scac_lfir_mask_or.setBit(24);

    // 25	RegParErr                   channel checkstop   unmask
    l_ecmd_rc |= l_scac_lfir_action0.clearBit(25);            
    l_ecmd_rc |= l_scac_lfir_action1.clearBit(25);
    l_ecmd_rc |= l_scac_lfir_mask_and.clearBit(25);

    // 26	RegParErrX                  channel checkstop   unmask
    l_ecmd_rc |= l_scac_lfir_action0.clearBit(26);            
    l_ecmd_rc |= l_scac_lfir_action1.clearBit(26);
    l_ecmd_rc |= l_scac_lfir_mask_and.clearBit(26);

    // 27:31	Reserved                recoverable         masked (forever)
    l_ecmd_rc |= l_scac_lfir_action0.clearBit(27,5);            
    l_ecmd_rc |= l_scac_lfir_action1.setBit(27,5);
    l_ecmd_rc |= l_scac_lfir_mask_or.setBit(27,5);
    
    // 32	SMErr                       recoverable         unmask
    l_ecmd_rc |= l_scac_lfir_action0.clearBit(32);            
    l_ecmd_rc |= l_scac_lfir_action1.setBit(32);
    l_ecmd_rc |= l_scac_lfir_mask_and.clearBit(32);
    
    // 33	RegAccErr                   recoverable         unmask
    l_ecmd_rc |= l_scac_lfir_action0.clearBit(33);            
    l_ecmd_rc |= l_scac_lfir_action1.setBit(33);
    l_ecmd_rc |= l_scac_lfir_mask_and.clearBit(33);

    // 34	ResetErr                    recoverable         masked (forever)
    l_ecmd_rc |= l_scac_lfir_action0.clearBit(34);            
    l_ecmd_rc |= l_scac_lfir_action1.setBit(34);
    l_ecmd_rc |= l_scac_lfir_mask_or.setBit(34);

    // 35	internal_scom_error         recoverable         masked (tbd)
    l_ecmd_rc |= l_scac_lfir_action0.clearBit(35);            
    l_ecmd_rc |= l_scac_lfir_action1.setBit(35);
    l_ecmd_rc |= l_scac_lfir_mask_or.setBit(35);

    // 36	internal_scom_error_clone   recoverable         masked (tbd)
    l_ecmd_rc |= l_scac_lfir_action0.clearBit(36);            
    l_ecmd_rc |= l_scac_lfir_action1.setBit(36);
    l_ecmd_rc |= l_scac_lfir_mask_or.setBit(36);

    // 37:63	Reserved
    // Can we write to these bits?


    if(l_ecmd_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        

        l_rc.setEcmdError(l_ecmd_rc);
        return l_rc;
    }                                                                              

    // Write action0
    l_rc = fapiPutScom_w_retry(i_target, SCAC_FIRACTION0_0x020115C6, l_scac_lfir_action0);
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }

    // Write action1
    l_rc = fapiPutScom_w_retry(i_target, SCAC_FIRACTION1_0x020115C7, l_scac_lfir_action1);
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }

    
    // Write mask OR
    l_rc = fapiPutScom_w_retry(i_target, SCAC_FIRMASK_OR_0x020115C5, l_scac_lfir_mask_or); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }

    // Write mask AND
    l_rc = fapiPutScom_w_retry(i_target, SCAC_FIRMASK_AND_0x020115C4, l_scac_lfir_mask_and); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }



    //************************************************    
    // DEBUG: read them all back to verify
    l_rc = fapiGetScom_w_retry(i_target, SCAC_FIRACTION0_0x020115C6, l_scac_lfir_action0); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }
    l_rc = fapiGetScom_w_retry(i_target, SCAC_FIRACTION1_0x020115C7, l_scac_lfir_action1); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }
    l_rc = fapiGetScom_w_retry(i_target, SCAC_FIRMASK_0x020115C3, l_scac_lfir_mask); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }

    //************************************************    


    //*************************
    //*************************
    // MBS_FIR_REG
    //*************************
    //*************************
    
    
    // NOTE: In the IPL sequence, mss_unmask_inband_errors has already been
    // called, which has already set the MBS_FIR_REG action regs to their 
    // runtime values, so no need to touch the action regs here.

    // NOTE: In the IPL sequence, mss_unmask_inband_errors,
    // has already been called, which has already unmasked the approproiate
    // MBS_FIR_REG errors following mss_unmask_inband_errors. So all we will do 
    // here is unmask errors requiring mainline traffic which would be 
    // considered valid after the mss_thermal_init procedure. 
    

    ecmdDataBufferBase l_mbs_fir_mask(64);
    ecmdDataBufferBase l_mbs_fir_mask_and(64);
    
    // Read mask 
    l_rc = fapiGetScom_w_retry(i_target, MBS_FIR_MASK_REG_0x02011403, l_mbs_fir_mask); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }    
    
    // TODO: Here is where I could clear bits that were bogus, before I unmask 
    //       them. But typically we are expecting the bit set at this point
    //       to be valid errors for PRD to log.

    l_ecmd_rc |= l_mbs_fir_mask_and.flushTo1();
    
    // 2    invalid_address_error   channel checkstop   unmask
    l_ecmd_rc |= l_mbs_fir_mask_and.clearBit(2);

    // 3    external_timeout        channel checkstop   unmask
    l_ecmd_rc |= l_mbs_fir_mask_and.clearBit(3);
    
    // 4    internal_timeout        channel checkstop   unmask
    l_ecmd_rc |= l_mbs_fir_mask_and.clearBit(4);

    // 9    cache_srw_ce            recoverable         unmask
    l_ecmd_rc |= l_mbs_fir_mask_and.clearBit(9);

    // 10    cache_srw_ue           recoverable         unmask
    l_ecmd_rc |= l_mbs_fir_mask_and.clearBit(10);

    // 12    cache_co_ce            recoverable         unmask
    l_ecmd_rc |= l_mbs_fir_mask_and.clearBit(12);

    // 13    cache_co_ue            recoverable         unmask
    l_ecmd_rc |= l_mbs_fir_mask_and.clearBit(13);

    // 15    dir_ce                 recoverable         unmask
    l_ecmd_rc |= l_mbs_fir_mask_and.clearBit(15);

    // 16    dir_ue                 channel checkstop   unmask
    l_ecmd_rc |= l_mbs_fir_mask_and.clearBit(16);

    // 18    dir_all_members_deleted channel checkstop  unmask
    l_ecmd_rc |= l_mbs_fir_mask_and.clearBit(18);

    // 19    lru_error               recoverable        unmask
    l_ecmd_rc |= l_mbs_fir_mask_and.clearBit(19);

    // 20    eDRAM error             channel checkstop  unmask
    l_ecmd_rc |= l_mbs_fir_mask_and.clearBit(20);

    // 26    srb_buffer_ce           recoverable        unmask
    l_ecmd_rc |= l_mbs_fir_mask_and.clearBit(26);

    // 27    srb_buffer_ue           recoverable        unmask
    l_ecmd_rc |= l_mbs_fir_mask_and.clearBit(27);
    
    if(l_ecmd_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        

        l_rc.setEcmdError(l_ecmd_rc);
        return l_rc;
    }                                                                              

    // Write mask AND
    l_rc = fapiPutScom_w_retry(i_target, MBS_FIR_MASK_REG_AND_0x02011404, l_mbs_fir_mask_and); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }


    //************************************************    
    // DEBUG: read them all back to verify
    l_rc = fapiGetScom_w_retry(i_target, MBS_FIR_MASK_REG_0x02011403, l_mbs_fir_mask); 
    if(l_rc)
    {
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);        
        return l_rc;
    }

    //************************************************    


    
    std::vector<fapi::Target> l_mbaChiplets;
    uint8_t l_mbaPosition;             // 0 = mba01, 1 = mba23


    uint32_t l_mbeccfir_mask_address[2]={
    // port0/1                            port2/3
    MBS_ECC0_MBECCFIR_MASK_0x02011443,MBS_ECC1_MBECCFIR_MASK_0x02011483};

    uint32_t l_mbeccfir_mask_and_address[2]={
    // port0/1                            port2/3
    MBS_ECC0_MBECCFIR_MASK_AND_0x02011444,MBS_ECC1_MBECCFIR_MASK_AND_0x02011484};

    ecmdDataBufferBase l_mbeccfir_mask(64);
    ecmdDataBufferBase l_mbeccfir_mask_and(64);

    //ecmdDataBufferBase l_mbaspa_mask(64);

    // Get associated functional MBAs on this centaur
    l_rc = fapiGetChildChiplets(i_target,
                                fapi::TARGET_TYPE_MBA_CHIPLET,
                                l_mbaChiplets);
    if(l_rc)
    {
        FAPI_ERR("Error getting functional MBAs on this Centaur");
        // Log passed in error before returning with new error
        if (i_bad_rc) fapiLogError(i_bad_rc);                
        return l_rc;
    }    

    // Loop through functional MBAs on this Centaur
    for (uint32_t i=0; i < l_mbaChiplets.size(); i++)
    {

        // Get MBA position: 0 = mba01, 1 = mba23
        l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &l_mbaChiplets[i], l_mbaPosition);
        if(l_rc)
        {
            FAPI_ERR("Error getting MBA position");
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);                
            return l_rc;
        }    
    

        // NOTE: FW wants to mask these and rely instead on detecting the 
        // cmd complete attention, then checking these manually to see if 
        // they cause the cmd to stop
        
        //*************************
        //*************************
        // MBASPA
        //*************************
        //*************************        
        /*        
        // Read mask
        l_rc = fapiGetScom_w_retry(l_mbaChiplets[i],
                                   MBA01_MBSPAMSKQ_0x03010614,
                                   l_mbaspa_mask); 
        if(l_rc)
        {
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);        
            return l_rc;
        }
        
        // TODO: Here is where I could clear bits that were bogus, before I unmask 
        //       them. But typically we are expecting the bit set at this point
        //       to be valid errors for PRD to log.

        
        // 1	Hard_CE_ETE_Attn                             unmask       
        // NOTE: Unmasking, but PRD responsible for setting and enabling the threshold.
        l_ecmd_rc |= l_mbaspa_mask.clearBit(1);            

        // 2	Soft_CE_ETE_Attn                             unmask
        // NOTE: Unmasking, but PRD responsible for setting and enabling the threshold.
        l_ecmd_rc |= l_mbaspa_mask.clearBit(2);            

        // 3	Intermittent_ETE_Attn                        unmask
        // NOTE: Unmasking, but PRD responsible for setting and enabling the threshold.
        l_ecmd_rc |= l_mbaspa_mask.clearBit(3);            

        // 4	RCE_ETE_Attn                                 unmask
        // NOTE: Unmasking, but PRD responsible for setting and enabling the threshold.
        l_ecmd_rc |= l_mbaspa_mask.clearBit(4);            

        if(l_ecmd_rc)
        {
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);        

            l_rc.setEcmdError(l_ecmd_rc);
            return l_rc;
        }                                                                              
        
        // Write mask
        l_rc = fapiPutScom_w_retry(l_mbaChiplets[i],
                                   MBA01_MBSPAMSKQ_0x03010614,
                                   l_mbaspa_mask); 
        if(l_rc)
        {
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);        
            return l_rc;
        }
        */
        //************************************************    
        // DEBUG: read them all back to verify
        /*
        l_rc = fapiGetScom_w_retry(l_mbaChiplets[i],
                                   MBA01_MBSPAMSKQ_0x03010614,
                                   l_mbaspa_mask);
        if(l_rc)
        {
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);        
            return l_rc;
        }
        */
        //************************************************    
        


        //*************************
        //*************************
        // MBECCFIR
        //*************************
        //*************************    

        // Read mask
        l_rc = fapiGetScom_w_retry(i_target, 
                                   l_mbeccfir_mask_address[l_mbaPosition], 
                                   l_mbeccfir_mask); 
        if(l_rc)
        {
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);        
            return l_rc;
        }
    
        // TODO: Here is where I could clear bits that were bogus, before I unmask 
        //       them. But typically we are expecting the bit set at this point
        //       to be valid errors for PRD to log.
                    
        // NOTE: In the IPL sequence, mss_unmask_maint_errors has already been
        // called, which has already set the MBECCFIR action regs to their runtime
        // values, so no need to touch the action regs here.

        // NOTE: In the IPL sequence, mss_unmask_maint_errors,
        // has already been called, which has already unmasked the approproiate
        // MBECCFIR errors following mss_unmask_maint_errors. So all we will do 
        // here is unmask errors requiring mainline traffic which would be 
        // considered valid after the mss_thermal_init procedure. 

        l_ecmd_rc |= l_mbeccfir_mask_and.flushTo1();

        // 0:7	Memory MPE Rank 0:7         recoverable         unmask
        l_ecmd_rc |= l_mbeccfir_mask_and.clearBit(0,8);

        // 16	Memory NCE                  recoverable         unmask
        l_ecmd_rc |= l_mbeccfir_mask_and.clearBit(16);

        // 17	Memory RCE                  recoverable         unmask
        l_ecmd_rc |= l_mbeccfir_mask_and.clearBit(17);

        // 19	Memory UE                   recoverable         unmask
        l_ecmd_rc |= l_mbeccfir_mask_and.clearBit(19);
        
        // NOTE: FW wants to mask these and rely instead on detecting the 
        // cmd complete attention, then checking these manually to see if 
        // they cause the cmd to stop
        /*
        // 20:27	Maint MPE Rank 0:7      recoverable         unmask
        l_ecmd_rc |= l_mbeccfir_mask_and.clearBit(20,8);
        
        // 41	Maintenance UE              recoverable         unmask
        l_ecmd_rc |= l_mbeccfir_mask_and.clearBit(41);
        */
        
        // 43	Prefetch Memory UE          recoverable         unmask
        l_ecmd_rc |= l_mbeccfir_mask_and.clearBit(43);

            
        if(l_ecmd_rc)
        {
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);        

            l_rc.setEcmdError(l_ecmd_rc);
            return l_rc;
        }                                                                              
        
        // Write mask AND
        l_rc = fapiPutScom_w_retry(i_target,
                                   l_mbeccfir_mask_and_address[l_mbaPosition], 
                                   l_mbeccfir_mask_and); 
        if(l_rc)
        {
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);        
            return l_rc;
        }

        //************************************************    
        // DEBUG: read them all back to verify
        l_rc = fapiGetScom_w_retry(i_target,
                                   l_mbeccfir_mask_address[l_mbaPosition], 
                                   l_mbeccfir_mask); 
        if(l_rc)
        {
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);        
            return l_rc;
        }

        //************************************************    
    }
    
    
    //*************************
    //*************************
    // MBACALFIR
    //*************************
    //*************************

    ecmdDataBufferBase l_mbacalfir_mask(64);
    ecmdDataBufferBase l_mbacalfir_mask_and(64);        
    
    // NOTE: In the IPL sequence, mss_unmask_draminit_errors has already been
    // called, which has already set the MBACALFIR action regs to their runtime
    // values, so no need to touch the action regs here.

    // NOTE: In the IPL sequence, various bits have already been unmasked
    // after the approproiate procedures. So all we will do here is unmask
    // errors requiring mainline traffic which would be considered valid after
    // the mss_thermal_init procedure. 

    // Loop through functional MBAs on this Centaur
    for (uint32_t i=0; i < l_mbaChiplets.size(); i++)
    {

        // Read mask
        l_rc = fapiGetScom_w_retry(l_mbaChiplets[i],
                                   MBA01_MBACALFIR_MASK_0x03010403,
                                   l_mbacalfir_mask); 
        if(l_rc)
        {
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);        
            return l_rc;
        }
        
        // TODO: Here is where I could clear bits that were bogus, before I unmask 
        //       them. But typically we are expecting the bit set at this point
        //       to be valid errors for PRD to log.
            
        l_ecmd_rc |= l_mbacalfir_mask_and.flushTo1();        
        
        // 9	mba_wrd ue                  recoverable         unmask
        l_ecmd_rc |= l_mbacalfir_mask_and.clearBit(9);

        // 10	mba_wrd ce                  recoverable         unmask
        l_ecmd_rc |= l_mbacalfir_mask_and.clearBit(10);

        // 14	wrq_data_ce                 recoverable         unmask
        l_ecmd_rc |= l_mbacalfir_mask_and.clearBit(14);

        // 15	wrq_data_ue                 recoverable         unmask
        l_ecmd_rc |= l_mbacalfir_mask_and.clearBit(15);

        if(l_ecmd_rc)
        {
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);        

            l_rc.setEcmdError(l_ecmd_rc);
            return l_rc;
        }                                                                              

        // Write mask AND
        l_rc = fapiPutScom_w_retry(l_mbaChiplets[i],
                                   MBA01_MBACALFIR_MASK_AND_0x03010404,
                                   l_mbacalfir_mask_and); 
        if(l_rc)
        {
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);        
            return l_rc;
        }


        //************************************************    
        // DEBUG: read them all back to verify
        l_rc = fapiGetScom_w_retry(l_mbaChiplets[i],
                                   MBA01_MBACALFIR_MASK_0x03010403,
                                   l_mbacalfir_mask); 
        if(l_rc)
        {
            // Log passed in error before returning with new error
            if (i_bad_rc) fapiLogError(i_bad_rc);        
            return l_rc;
        }

        //************************************************    
    }


   
    
    FAPI_INF("EXIT mss_unmask_fetch_errors()"); 

    return i_bad_rc;
}

//------------------------------------------------------------------------------
// fapiGetScom_w_retry
//------------------------------------------------------------------------------
fapi::ReturnCode fapiGetScom_w_retry(const fapi::Target& i_target,
                                     const uint64_t i_address,
                                     ecmdDataBufferBase & o_data)
{
    fapi::ReturnCode l_rc;
    
    l_rc = fapiGetScom(i_target, i_address, o_data);
    if(l_rc)
    {
        FAPI_ERR("1st Centaur fapiGetScom failed, so attempting retry.");

        // Log centaur scom error
        fapiLogError(l_rc);        

        // Retry centaur scom with assumption that retry is done via FSI,
        // which may still work.
        // NOTE: If scom fail was due to channel fail a retry via FSI may
        // work. But if scom fail was due to PIB error, retry via FSI may
        // also fail.
        l_rc = fapiGetScom(i_target, i_address, o_data); 
        if(l_rc)
        {
            FAPI_ERR("fapiGetScom retry via FSI failed.");       
            // Retry didn't work either so give up and pass 
            // back centaur scom error
        }
    }    
    
    return l_rc;
}


//------------------------------------------------------------------------------
// fapiPutScom_w_retry
//------------------------------------------------------------------------------
fapi::ReturnCode fapiPutScom_w_retry(const fapi::Target& i_target,
                                     const uint64_t i_address,
                                     ecmdDataBufferBase & i_data)
{
    fapi::ReturnCode l_rc;
    
    // NOTE: Inband scom device driver takes care of read to special reg after
    // an inband scom write in order to detect SUE
    l_rc = fapiPutScom(i_target, i_address, i_data);
    if(l_rc)
    {
        FAPI_ERR("1st Centaur fapiPutScom failed, so attempting retry.");

        // Log centaur scom error
        fapiLogError(l_rc);        

        // Retry centaur scom with assumption that retry is done via FSI,
        // which may still work.
        // NOTE: If scom fail was due to channel fail a retry via FSI may
        // work. But if scom fail was due to PIB error, retry via FSI may
        // also fail.
        l_rc = fapiPutScom(i_target, i_address, i_data); 
        if(l_rc)
        {
            FAPI_ERR("fapiPutScom retry via FSI failed.");       
            // Retry didn't work either so give up and pass 
            // back centaur scom error
        }
    }    
    
    return l_rc;
}
