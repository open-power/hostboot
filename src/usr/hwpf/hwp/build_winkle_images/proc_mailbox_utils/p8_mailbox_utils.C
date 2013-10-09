/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/proc_mailbox_utils/p8_mailbox_utils.C $ */
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
// -*- mode: C++; c-file-style: "linux";  -*-
// $Id: p8_mailbox_utils.C,v 1.1 2013/09/18 17:28:20 dcrowell Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_mailbox_utils.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_mailbox_utils.C
// *! DESCRIPTION : Functions to calculate the mailbox values
// *!
// *! OWNER NAME  : Jeshua Smith            Email: jeshua@us.ibm.com
// *! BACKUP NAME : TBD                     Email: TBD@us.ibm.com
// *!
// *! Overview:
// *!    Utility functions to calculate each mailbox value
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "p8_mailbox_utils.H"

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

extern "C"
{

using namespace fapi;

//------------------------------------------------------------------------------
// function:
//      Translate a VRM-11 VID code to a voltage value
//
//
// parameters: i_vid_7_0    VRM-11 VID code
//              o_voltage   Voltage in .01mv units
//
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode vid2mv(uint8_t i_vid_7_0, uint32_t &o_voltage)
{
    fapi::ReturnCode l_fapirc;

    switch(i_vid_7_0)
    {
        case      0x1   : o_voltage =  0    ; break;
        case      0x2   : o_voltage =160000 ; break;
        case      0x3   : o_voltage =159375 ; break;
        case      0x4   : o_voltage =158750 ; break;
        case      0x5   : o_voltage =158125 ; break;
        case      0x6   : o_voltage =157500 ; break;
        case      0x7   : o_voltage =156875 ; break;
        case      0x8   : o_voltage =156250 ; break;
        case      0x9   : o_voltage =155625 ; break;
        case      0xA   : o_voltage =155000 ; break;
        case      0xB   : o_voltage =154375 ; break;
        case      0xC   : o_voltage =153750 ; break;
        case      0xD   : o_voltage =153125 ; break;
        case      0xE   : o_voltage =152500 ; break;
        case      0xF   : o_voltage =151875 ; break;
        case      0x10  : o_voltage =151250 ; break;
        case      0x11  : o_voltage =150625 ; break;
        case      0x12  : o_voltage =150000 ; break;
        case      0x13  : o_voltage =149375 ; break;
        case      0x14  : o_voltage =148750 ; break;
        case      0x15  : o_voltage =148125 ; break;
        case      0x16  : o_voltage =147500 ; break;
        case      0x17  : o_voltage =146875 ; break;
        case      0x18  : o_voltage =146250 ; break;
        case      0x19  : o_voltage =145625 ; break;
        case      0x1A  : o_voltage =145000 ; break;
        case      0x1B  : o_voltage =144375 ; break;
        case      0x1C  : o_voltage =143750 ; break;
        case      0x1D  : o_voltage =143125 ; break;
        case      0x1E  : o_voltage =142500 ; break;
        case      0x1F  : o_voltage =141875 ; break;
        case      0x20  : o_voltage =141250 ; break;
        case      0x21  : o_voltage =140625 ; break;
        case      0x22  : o_voltage =140000 ; break;
        case      0x23  : o_voltage =139375 ; break;
        case      0x24  : o_voltage =138750 ; break;
        case      0x25  : o_voltage =138125 ; break;
        case      0x26  : o_voltage =137500 ; break;
        case      0x27  : o_voltage =136875 ; break;
        case      0x28  : o_voltage =136250 ; break;
        case      0x29  : o_voltage =135625 ; break;
        case      0x2a  : o_voltage =135000 ; break;
        case      0x2b  : o_voltage =134375 ; break;
        case      0x2c  : o_voltage =133750 ; break;
        case      0x2d  : o_voltage =133125 ; break;
        case      0x2e  : o_voltage =132500 ; break;
        case      0x2f  : o_voltage =131875 ; break;
        case      0x30  : o_voltage =131250 ; break;
        case      0x31  : o_voltage =130625 ; break;
        case      0x32  : o_voltage =130000 ; break;
        case      0x33  : o_voltage =129375 ; break;
        case      0x34  : o_voltage =128750 ; break;
        case      0x35  : o_voltage =128125 ; break;
        case      0x36  : o_voltage =127500 ; break;
        case      0x37  : o_voltage =126875 ; break;
        case      0x38  : o_voltage =126250 ; break;
        case      0x39  : o_voltage =125625 ; break;
        case      0x3a  : o_voltage =125000 ; break;
        case      0x3b  : o_voltage =124375 ; break;
        case      0x3c  : o_voltage =123750 ; break;
        case      0x3d  : o_voltage =123125 ; break;
        case      0x3e  : o_voltage =122500 ; break;
        case      0x3f  : o_voltage =121875 ; break;
        case      0x40  : o_voltage =121250 ; break;
        case      0x41  : o_voltage =120625 ; break;
        case      0x42  : o_voltage =120000 ; break;
        case      0x43  : o_voltage =119375 ; break;
        case      0x44  : o_voltage =118750 ; break;
        case      0x45  : o_voltage =118125 ; break;
        case      0x46  : o_voltage =117500 ; break;
        case      0x47  : o_voltage =116875 ; break;
        case      0x48  : o_voltage =116250 ; break;
        case      0x49  : o_voltage =115625 ; break;
        case      0x4a  : o_voltage =115000 ; break;
        case      0x4b  : o_voltage =114375 ; break;
        case      0x4c  : o_voltage =113750 ; break;
        case      0x4d  : o_voltage =113125 ; break;
        case      0x4e  : o_voltage =112500 ; break;
        case      0x4f  : o_voltage =111875 ; break;
        case      0x50  : o_voltage =111250 ; break;
        case      0x51  : o_voltage =110625 ; break;
        case      0x52  : o_voltage =110000 ; break;
        case      0x53  : o_voltage =109375 ; break;
        case      0x54  : o_voltage =108750 ; break;
        case      0x55  : o_voltage =108125 ; break;
        case      0x56  : o_voltage =107500 ; break;
        case      0x57  : o_voltage =106875 ; break;
        case      0x58  : o_voltage =106250 ; break;
        case      0x59  : o_voltage =105625 ; break;
        case      0x5a  : o_voltage =105000 ; break;
        case      0x5b  : o_voltage =104375 ; break;
        case      0x5c  : o_voltage =103750 ; break;
        case      0x5d  : o_voltage =103125 ; break;
        case      0x5e  : o_voltage =102500 ; break;
        case      0x5f  : o_voltage =101875 ; break;
        case      0x60  : o_voltage =101250 ; break;
        case      0x61  : o_voltage =100625 ; break;
        case      0x62  : o_voltage =100000 ; break;
        case      0x63  : o_voltage = 99375 ; break;
        case      0x64  : o_voltage = 98750 ; break;
        case      0x65  : o_voltage = 98125 ; break;
        case      0x66  : o_voltage = 97500 ; break;
        case      0x67  : o_voltage = 96875 ; break;
        case      0x68  : o_voltage = 96250 ; break;
        case      0x69  : o_voltage = 95625 ; break;
        case      0x6a  : o_voltage = 95000 ; break;
        case      0x6b  : o_voltage = 94375 ; break;
        case      0x6c  : o_voltage = 93750 ; break;
        case      0x6d  : o_voltage = 93125 ; break;
        case      0x6e  : o_voltage = 92500 ; break;
        case      0x6f  : o_voltage = 91875 ; break;
        case      0x70  : o_voltage = 91250 ; break;
        case      0x71  : o_voltage = 90625 ; break;
        case      0x72  : o_voltage = 90000 ; break;
        case      0x73  : o_voltage = 89375 ; break;
        case      0x74  : o_voltage = 88750 ; break;
        case      0x75  : o_voltage = 88125 ; break;
        case      0x76  : o_voltage = 87500 ; break;
        case      0x77  : o_voltage = 86875 ; break;
        case      0x78  : o_voltage = 86250 ; break;
        case      0x79  : o_voltage = 85625 ; break;
        case      0x7a  : o_voltage = 85000 ; break;
        case      0x7b  : o_voltage = 84375 ; break;
        case      0x7c  : o_voltage = 83750 ; break;
        case      0x7d  : o_voltage = 83125 ; break;
        case      0x7e  : o_voltage = 82500 ; break;
        case      0x7f  : o_voltage = 81875 ; break;
        case      0x80  : o_voltage = 81250 ; break;
        case      0x81  : o_voltage = 80625 ; break;
        case      0x82  : o_voltage = 80000 ; break;
        case      0x83  : o_voltage = 79375 ; break;
        case      0x84  : o_voltage = 78750 ; break;
        case      0x85  : o_voltage = 78125 ; break;
        case      0x86  : o_voltage = 77500 ; break;
        case      0x87  : o_voltage = 76875 ; break;
        case      0x88  : o_voltage = 76250 ; break;
        case      0x89  : o_voltage = 75625 ; break;
        case      0x8a  : o_voltage = 75000 ; break;
        case      0x8b  : o_voltage = 74375 ; break;
        case      0x8c  : o_voltage = 73750 ; break;
        case      0x8d  : o_voltage = 73125 ; break;
        case      0x8e  : o_voltage = 72500 ; break;
        case      0x8f  : o_voltage = 71875 ; break;
        case      0x90  : o_voltage = 71250 ; break;
        case      0x91  : o_voltage = 70625 ; break;
        case      0x92  : o_voltage = 70000 ; break;
        case      0x93  : o_voltage = 69375 ; break;
        case      0x94  : o_voltage = 68750 ; break;
        case      0x95  : o_voltage = 68125 ; break;
        case      0x96  : o_voltage = 67500 ; break;
        case      0x97  : o_voltage = 66875 ; break;
        case      0x98  : o_voltage = 66250 ; break;
        case      0x99  : o_voltage = 65625 ; break;
        case      0x9a  : o_voltage = 65000 ; break;
        case      0x9b  : o_voltage = 64375 ; break;
        case      0x9c  : o_voltage = 63750 ; break;
        case      0x9d  : o_voltage = 63125 ; break;
        case      0x9e  : o_voltage = 62500 ; break;
        case      0x9f  : o_voltage = 61875 ; break;
        case      0xa0  : o_voltage = 61250 ; break;
        case      0xa1  : o_voltage = 60625 ; break;
        case      0xa2  : o_voltage = 60000 ; break;
        case      0xa3  : o_voltage = 59375 ; break;
        case      0xa4  : o_voltage = 58750 ; break;
        case      0xa5  : o_voltage = 58125 ; break;
        case      0xa6  : o_voltage = 57500 ; break;
        case      0xa7  : o_voltage = 56875 ; break;
        case      0xa8  : o_voltage = 56250 ; break;
        case      0xa9  : o_voltage = 55625 ; break;
        case      0xaa  : o_voltage = 55000 ; break;
        case      0xab  : o_voltage = 54375 ; break;
        case      0xac  : o_voltage = 53750 ; break;
        case      0xad  : o_voltage = 53125 ; break;
        case      0xae  : o_voltage = 52500 ; break;
        case      0xaf  : o_voltage = 51875 ; break;
        case      0xb0  : o_voltage = 51250 ; break;
        case      0xb1  : o_voltage = 50625 ; break;
        case      0xb2  : o_voltage = 50000 ; break;
        case      0xb3  : o_voltage = 49375 ; break;
        case      0xb4  : o_voltage = 48750 ; break;
        case      0xb5  : o_voltage = 48125 ; break;
        case      0xb6  : o_voltage = 47500 ; break;
        case      0xb7  : o_voltage = 46875 ; break;
        case      0xb8  : o_voltage = 46250 ; break;
        case      0xb9  : o_voltage = 45625 ; break;
        case      0xba  : o_voltage = 45000 ; break;
        case      0xbb  : o_voltage = 44375 ; break;
        case      0xbc  : o_voltage = 43750 ; break;
        case      0xbd  : o_voltage = 43125 ; break;
        case      0xbe  : o_voltage = 42500 ; break;
        case      0xbf  : o_voltage = 41875 ; break;
        case      0xc0  : o_voltage = 41250 ; break;
        case      0xc1  : o_voltage = 40625 ; break;
        case      0xc2  : o_voltage = 40000 ; break;
        case      0xc3  : o_voltage = 39375 ; break;
        case      0xc4  : o_voltage = 38750 ; break;
        case      0xc5  : o_voltage = 38125 ; break;
        case      0xc6  : o_voltage = 37500 ; break;
        case      0xc7  : o_voltage = 36875 ; break;
        case      0xc8  : o_voltage = 36250 ; break;
        case      0xc9  : o_voltage = 35625 ; break;
        case      0xca  : o_voltage = 35000 ; break;
        case      0xcb  : o_voltage = 34375 ; break;
        case      0xcc  : o_voltage = 33750 ; break;
        case      0xcd  : o_voltage = 33125 ; break;
        case      0xce  : o_voltage = 32500 ; break;
        case      0xcf  : o_voltage = 31875 ; break;
        case      0xd0  : o_voltage = 31250 ; break;
        case      0xd1  : o_voltage = 30625 ; break;
        case      0xd2  : o_voltage = 30000 ; break;
        case      0xd3  : o_voltage = 29375 ; break;
        case      0xd4  : o_voltage = 28750 ; break;
        case      0xd5  : o_voltage = 28125 ; break;
        case      0xd6  : o_voltage = 27500 ; break;
        case      0xd7  : o_voltage = 26875 ; break;
        case      0xd8  : o_voltage = 26250 ; break;
        case      0xd9  : o_voltage = 25625 ; break;
        case      0xda  : o_voltage = 25000 ; break;
        case      0xdb  : o_voltage = 24375 ; break;
        case      0xdc  : o_voltage = 23750 ; break;
        case      0xdd  : o_voltage = 23125 ; break;
        case      0xde  : o_voltage = 22500 ; break;
        case      0xdf  : o_voltage = 21875 ; break;
        case      0xe0  : o_voltage = 21250 ; break;
        case      0xe1  : o_voltage = 20625 ; break;
        case      0xe2  : o_voltage = 20000 ; break;
        case      0xe3  : o_voltage = 19375 ; break;
        case      0xe4  : o_voltage = 18750 ; break;
        case      0xe5  : o_voltage = 18125 ; break;
        case      0xe6  : o_voltage = 17500 ; break;
        case      0xe7  : o_voltage = 16875 ; break;
        case      0xe8  : o_voltage = 16250 ; break;
        case      0xe9  : o_voltage = 15625 ; break;
        case      0xea  : o_voltage = 15000 ; break;
        case      0xeb  : o_voltage = 14375 ; break;
        case      0xec  : o_voltage = 13750 ; break;
        case      0xed  : o_voltage = 13125 ; break;
        case      0xee  : o_voltage = 12500 ; break;
        case      0xef  : o_voltage = 11875 ; break;
        case      0xf0  : o_voltage = 11250 ; break;
        case      0xf1  : o_voltage = 10625 ; break;
        case      0xf2  : o_voltage = 10000 ; break;
        case      0xf3  : o_voltage = 9375  ; break;
        case      0xf4  : o_voltage = 8750  ; break;
        case      0xf5  : o_voltage = 8125  ; break;
        case      0xf6  : o_voltage = 7500  ; break;
        case      0xf7  : o_voltage = 6875  ; break;
        case      0xf8  : o_voltage = 6250  ; break;
        case      0xf9  : o_voltage = 5625  ; break;
        case      0xfa  : o_voltage = 5000  ; break;
        case      0xfb  : o_voltage = 4375  ; break;
        case      0xfc  : o_voltage = 3750  ; break;
        case      0xfd  : o_voltage = 3125  ; break;
      //case      0xfe  : o_voltage = 0     ; break;
      //case      0xff  : o_voltage = 0     ; break;
        default         : o_voltage = 100000;
    }

    return l_fapirc;
}

//------------------------------------------------------------------------------
// function:
//      set up sbe configuration values in mbox scratch reg 1
//      (standalone_mbox0_value)
//
//  Mailbox scratch 1 (CFAM 2838, SCOM 0x50038)
//
//  Bytes 0,1   Boot frequency
//  Boot Frequency info (power management def file DPS min (% drop from
//  nominal), must cross checking between f_vmin and DPS min)
//  This is a multiplier of the processor refclk frequency based on the
//  the DPLL DIVIDER.
//
//  Bytes 2,3 EX Gard records
//  FSP provides a vector for SBE to communicate the guareded EX chiplets
//  Bits    0..3    4..7    8..11   12..15  16..19  20..23  24..27  28..31
//                  0x0000                          EX guard bits
//  One Guard bit per EX chiplet, bit location aligned to chiplet ID
//  (bit 16: EX00, bit 17: EX01, bit 18: EX02 ... bit 31: EX15)
//  Guarded EX chiplets are marked by a '0'.
//
// parameters: i_target           Reference to the processor chip target
//             o_set_data         The 32-bit mailbox value
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode p8_mailbox_utils_get_mbox1( const fapi::Target &i_target, uint32_t & o_set_data )
{
    fapi::ReturnCode l_fapirc;

    const uint32_t  BOOT_FREQ_BIT_POSITION      =   0;
    const uint32_t  BOOT_FREQ_BIT_LENGTH        =   16;
    const uint32_t  EX_GARD_BITS_BIT_POSITION   =   16;
    const uint32_t  EX_GARD_BITS_BIT_LENGTH     =   16;

    do
    {
        o_set_data = 0;

        //  boot freq should have been calculated earlier
        //  and stored in system attribute ATTR_BOOT_FREQ_MHZ
        fapi::ATTR_BOOT_FREQ_MHZ_Type l_boot_freq =   0 ;
        l_fapirc =  FAPI_ATTR_GET(  ATTR_BOOT_FREQ_MHZ,
                                    NULL,
                                    l_boot_freq );
        if  (l_fapirc )
        {
            FAPI_ERR("fapiGetAttribute of ATTR_BOOT_FREQ_MHZ failed");
            break;
        }
        FAPI_INF(   "ATTR_BOOT_FREQ_MHZ = 0x%08x => %dMHz",
                        l_boot_freq, l_boot_freq);
                        
        uint32_t l_refclk_freq =   0;
        l_fapirc =  FAPI_ATTR_GET(  ATTR_FREQ_PROC_REFCLOCK, NULL, l_refclk_freq );
        if  (l_fapirc )
        {
            FAPI_ERR("fapiGetAttribute of ATTR_FREQ_PROC_REFCLOCK failed");
            break;
        }

        FAPI_INF(   "ATTR_FREQ_PROC_REFCLOCK = 0x%08x  => %dMHz",
                        l_refclk_freq, l_refclk_freq );

        if (!l_refclk_freq)
        {
            FAPI_ERR("Attribute ATTR_FREQ_PROC_REFCLOCK failed must be non-zero");
            uint32_t & REF_FREQ = l_refclk_freq;
            FAPI_SET_HWP_ERROR(l_fapirc, RC_P8_MAILBOX_UTILS_PROC_REFCLK_ZERO_ERROR);
            break;
        }

        uint32_t l_dpll_divider = 4;
        /*
        // Future todo -- Look to have these as attribute
        unit8_t l_dpll_init_divide;
        l_fapirc =  FAPI_ATTR_GET(  ATTR_PROC_DPLL_DIV124, i_target, l_dpll_init_divide );
        if  (l_fapirc )
        {
            FAPI_ERR("fapiGetAttribute of ATTR_PROC_DPLL_DIV124 failed");
            break;
        }

        unit8_t l_dpll_out_divide;
        l_fapirc =  FAPI_ATTR_GET(  ATTR_PROC_DPLL_OUT124, i_target, l_dpll_out_divide );
        if  (l_fapirc )
        {
            FAPI_ERR("fapiGetAttribute of ATTR_PROC_DPLL_OUT124 failed");
            break;
        }

        l_dpll_divider = (uint32_t)(l_dpll_init_divide * l_dpll_out_divide);
        */

        FAPI_DBG("DPLL divider HARDCODED to %01x", l_dpll_divider);
        l_fapirc = FAPI_ATTR_SET(ATTR_PROC_DPLL_DIVIDER, &i_target, l_dpll_divider );
        if  (l_fapirc )
        {
            FAPI_ERR("fapiSetAttribute of ATTR_PROC_DPLL_DIVIDER failed");
            break;
        }

        // Calculate the multiplier that is stored into the mailbox

        // Check bounds and avoid unnecessary fp math
//         uint32_t l_freq_mult = (uint32_t)floor(
//                                     ( float)l_boot_freq /
//                                     ((float)l_refclk_freq / l_dpll_divider));
        uint64_t l_result = (((uint64_t)l_dpll_divider)*l_boot_freq)/l_refclk_freq;
        if( l_result >> BOOT_FREQ_BIT_LENGTH )
        {
            FAPI_ERR("DPLL multiplier (%lld) won't fit in the bit field (%i bits max)", 
                     l_result, BOOT_FREQ_BIT_LENGTH);
            uint32_t & BOOT_FREQ = l_boot_freq;
            uint32_t & REF_FREQ  = l_refclk_freq;
            uint32_t & DPLL_DIV  = l_dpll_divider;
            uint64_t & FREQ_MULT = l_result;
            const uint32_t & MAX_BITS  = BOOT_FREQ_BIT_LENGTH;
            FAPI_SET_HWP_ERROR(l_fapirc, RC_P8_MAILBOX_UTILS_FREQ_MULT_OOB_ERROR);
            break;
        }
        uint32_t l_freq_mult = (uint32_t)l_result;

        FAPI_DBG("Boot frequency multiplier %04x", l_freq_mult);

        o_set_data = l_freq_mult << (sizeof(o_set_data)*8 -
                                     BOOT_FREQ_BIT_POSITION -
                                     BOOT_FREQ_BIT_LENGTH);


        //  Calculate the gard record here, ATTR_EX_GARD_BITS is probably not
        //  needed.
        uint32_t l_ex_gard_bits    =   0x0000ffff;
        std::vector<fapi::Target>  l_fapiCores;
        l_fapirc = fapiGetChildChiplets( i_target,
                                         fapi::TARGET_TYPE_EX_CHIPLET,
                                         l_fapiCores,
                                         fapi::TARGET_STATE_FUNCTIONAL );
        if  (l_fapirc )
        {
            FAPI_ERR("fapiGetChildChiplets failed");
            break;
        }

        FAPI_INF( "Found %d EX cores",
                  l_fapiCores.size()    );

        //  Note: Functional chips are marked with a 0 bit; NOT a one bit.
        //  CLEAR a bit for all functional EX chiplets in the vector:
        //  (bit 16: EX00, bit 17: EX01, bit 18: EX02 ... bit 31: EX15)

        //  HWAS will eventually take into account Mfg Partial Good,
        //  Mfg Core Overrride, and Gard data records from previous fails;
        //  we should only have to filter for functional chips here.
        for ( uint32_t l_coreNum=0; l_coreNum<l_fapiCores.size(); l_coreNum++ )
        {
            fapi::ATTR_CHIP_UNIT_POS_Type  l_unit  =   0;
            l_fapirc    =   FAPI_ATTR_GET( ATTR_CHIP_UNIT_POS,
                                           &l_fapiCores[l_coreNum],
                                           l_unit  );
            if ( l_fapirc )
            {
                // oops, bail out of loop with fapirc set
                break;
            }
            l_ex_gard_bits &=   ~(( 0x00008000 >> l_unit ));
        }   // endfor

        if ( l_fapirc )
        {
            FAPI_ERR( "FAILED to retrieve ATTR_CHIP_UNIT_POS" );
            break;
        }

        FAPI_INF( "l_ex_gard_bits = 0x%08x", l_ex_gard_bits );

        o_set_data |= l_ex_gard_bits << (sizeof(o_set_data)*8 -
                                         EX_GARD_BITS_BIT_POSITION -
                                         EX_GARD_BITS_BIT_LENGTH);

        FAPI_INF(   "Return Mailbox 1 value (standalone_mbox0_value) =  0x%08x",
                    o_set_data   );
    } while (0);

    return l_fapirc;
}

//------------------------------------------------------------------------------
// function:
//      set up sbe configuration values in mbox scratch reg 2
//      (standalone_mbox1_value)
//
//  Bit 0 in this register is used to indicate a MPIPL
//  - The MPI flag will be evaluated by proc_sbe_ipl_seeprom to distinguish
//    between a normal and a memory preserving IPL
//  - attribute ATTR_IS_MPIPL will indicate MPIPL or not.
//  FSP provides a MPI (Memory Preserving IPL) flag and settings for the I2C
//  master bus speed calculation
//  Bits    | 0     |   1 2 3   |   4..7    8..11   12..15                    |
//          | MPI   |   000     | PIB I2C master Bit Rate Divisor (@refclock) |
//
//          |    16..19             20..23  24..27  28..31                    |
//          |               PIB I2C master Bit Rate Divisor (@PLL)            |
//
// parameters: i_target           Reference to the chip target
//             o_set_data         The 32-bit mailbox value
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode p8_mailbox_utils_get_mbox2( const fapi::Target &i_target, uint32_t & o_set_data )
{
    fapi::ReturnCode l_fapirc;

    const uint32_t  PIB_I2C_REFCLOCK_BIT_POSITION   =   4;
    const uint32_t  PIB_I2C_REFCLOCK_BIT_LENGTH     =   12;
    const uint32_t  PIB_I2C_NEST_PLL_BIT_POSITION   =   16;
    const uint32_t  PIB_I2C_NEST_PLL_BIT_LENGTH     =   16;


    do
    {
        //  get system attribute ATTR_IS_MPIPL
        fapi::ATTR_IS_MPIPL_Type    l_isMpIpl   =   0x00;
        l_fapirc =  FAPI_ATTR_GET(  ATTR_IS_MPIPL,
                                    NULL,
                                    l_isMpIpl );
        if  (l_fapirc )
        {
            FAPI_ERR("fapiGetAttribute of ATTR_IS_MPIPL failed");
            break;
        }

        FAPI_INF(   "ATTR_IS_MPIPL=0x%08x",
                    l_isMpIpl );

        if ( l_isMpIpl )
        {
            o_set_data = 1 << (sizeof(o_set_data)*8 - 1);
        }
        else
        {
            o_set_data = 0;
        }

        //  get system attribute ATTR_PIB_I2C_REFCLOCK
        fapi::ATTR_PIB_I2C_REFCLOCK_Type    l_pib_i2c_refclock =   0;
        l_fapirc =  FAPI_ATTR_GET(  ATTR_PIB_I2C_REFCLOCK,
                                    NULL,
                                    l_pib_i2c_refclock );
        if  (l_fapirc )
        {
            FAPI_ERR("fapiGetAttribute of ATTR_PIB_I2C_REFCLOCK failed");
            break;
        }

        FAPI_INF(   "ATTR_PIB_I2C_REFCLOCK=0x%08x",
                    l_pib_i2c_refclock );

        //  get system attribute ATTR_PIB_I2C_NEST_PLL
        fapi::ATTR_PIB_I2C_NEST_PLL_Type    l_pib_i2c_nest_pll  =   0;
        l_fapirc =  FAPI_ATTR_GET(  ATTR_PIB_I2C_NEST_PLL,
                                    NULL,
                                    l_pib_i2c_nest_pll );
        if  (l_fapirc )
        {
            FAPI_ERR("fapiGetAttribute of ATTR_PIB_I2C_NEST_PLL failed");
            break;
        }

        FAPI_INF(   "ATTR_PIB_I2C_NEST_PLL=0x%08x",
                    l_pib_i2c_nest_pll );


        //For normal IPLs set initial SBE I2C freq to ref clock
        //For MPIPL set initial SBE I2C freq to nest clock 
        if ( !l_isMpIpl )
        {
            o_set_data |= l_pib_i2c_refclock << (sizeof(o_set_data)*8 -
                                                 PIB_I2C_REFCLOCK_BIT_POSITION -
                                                 PIB_I2C_REFCLOCK_BIT_LENGTH);
        }
        else
        {
            o_set_data |= l_pib_i2c_nest_pll << (sizeof(o_set_data)*8 -
                                                PIB_I2C_REFCLOCK_BIT_POSITION -
                                                PIB_I2C_REFCLOCK_BIT_LENGTH);
        }

        //Nest ref clock is the same between Normal and MPIPLs
        o_set_data |= l_pib_i2c_nest_pll << (sizeof(o_set_data)*8 -
                                             PIB_I2C_NEST_PLL_BIT_POSITION -
                                             PIB_I2C_NEST_PLL_BIT_LENGTH    );

        FAPI_INF(   "Return Mailbox 2 value (standalone_mbox1_value) =  0x%08x",
                    o_set_data   );

    } while (0);

    return l_fapirc;
}



//------------------------------------------------------------------------------
// function:
//      set up sbe configuration values in mbox scratch reg 3
//      (standalone_mbox2_value)
//
//  32bit address of location of Hostboot image header (first block of data)
//  This is offset using an algorithm to compensate for ECC -
//  see Feature 862671 (fips810): hb pnor offset
//
// parameters: i_target           Reference to the chip target
//             o_set_data         The 32-bit mailbox value
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode p8_mailbox_utils_get_mbox3( const fapi::Target &i_target, uint32_t & o_set_data )
{
    fapi::ReturnCode l_fapirc;

    const uint32_t  SBE_IMAGE_OFFSET_BIT_POSITION   =   0;
    const uint32_t  SBE_IMAGE_OFFSET_BIT_LENGTH     =   32;

    do {

        //  get system attribute ATTR_SBE_IMAGE_OFFSET
        fapi::ATTR_SBE_IMAGE_OFFSET_Type    l_sbe_image_offset  =   0 ;
        l_fapirc =  FAPI_ATTR_GET(  ATTR_SBE_IMAGE_OFFSET,
                                    NULL,
                                    l_sbe_image_offset );
        if  (l_fapirc )
        {
            FAPI_ERR("fapiGetAttribute of ATTR_SBE_IMAGE_OFFSET failed");
            break;
        }

        FAPI_INF(   "ATTR_SBE_IMAGE_OFFSET=0x%08x",
                    l_sbe_image_offset );

        o_set_data = l_sbe_image_offset << (sizeof(o_set_data)*8 -
                                             SBE_IMAGE_OFFSET_BIT_POSITION -
                                             SBE_IMAGE_OFFSET_BIT_LENGTH    );

        FAPI_INF(   "Return Mailbox 3 (standalone_mbox2_value) =  0x%08x",
                    o_set_data   );

    } while (0);

    return l_fapirc;
}


//------------------------------------------------------------------------------
// function:
//      set up sbe configuration values in mbox scratch reg 4
//
//  Write Boot Voltage info to scratch pad 4
//
//  0:2   -> port enables (3b - system design based:
//          port 0 for non-redundant systems (100); all ports for non-redundant (111))
//  3     -> Unused
//  - current recommended default = 1000b
//  4:7   -> phase enables (4b - defined by the system power design)
//  - current recommended default = 0000b
//  8:15  -> VDD voltage (1B in VRM-11 encoded form - 6.25mV increments)
//          note: VPD is in 5mV increments
//  - current recommended default   =   0x52
//  16:23 -> VCS voltage (1B in VRM-11 encoded form - 6.25mV increments)
//          note: VPD is in 5mV increments
//  -current recommended default    =   0x4a
//  24:27 -> Unused                 =   0x00
//  28     -> Device ID mode selection (0=node ID, 1=chip ID)
//                                  =   0b1
//  29:31 -> Fabric node ID         =   Node
//
//
// parameters: i_target           Reference to the chip target
//             o_set_data         The 32-bit mailbox value
//             i_includeNode      True if the value should include node information
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode p8_mailbox_utils_get_mbox4( const fapi::Target &i_target, uint32_t & o_set_data,
                                               bool i_includeNode )
{
    fapi::ReturnCode l_fapirc;

    const uint32_t  BOOT_VOLTAGE_INFO_BIT_POSITION   =   0;
    const uint32_t  BOOT_VOLTAGE_INFO_BIT_LENGTH     =   32;
    const uint32_t  DEVICE_ID_CONTENT_BIT  = 28;
    const uint32_t  NODE_ID_BIT_POSITION   = 29;
    const uint32_t  NODE_ID_BIT_LENGTH     = 3;


    do
    {
        //  get system attribute ATTR_PROC_BOOT_VOLTAGE_VID
        fapi::ATTR_PROC_BOOT_VOLTAGE_VID_Type    l_boot_voltage_info =   0  ;
        l_fapirc =  FAPI_ATTR_GET(  ATTR_PROC_BOOT_VOLTAGE_VID,
                                    &i_target,
                                    l_boot_voltage_info );
        if  (l_fapirc )
        {
            FAPI_ERR("fapiGetAttribute of ATTR_PROC_BOOT_VOLTAGE_VID failed");
            break;
        }

        FAPI_INF(   "ATTR_PROC_BOOT_VOLTAGE_VID=0x%08x",
                    l_boot_voltage_info );

        o_set_data = l_boot_voltage_info << (sizeof(o_set_data)*8 -
                                             BOOT_VOLTAGE_INFO_BIT_POSITION -
                                             BOOT_VOLTAGE_INFO_BIT_LENGTH    );

        // Decode the value for those interested
        uint32_t    l_vdd_mv;
        uint32_t    l_vcs_mv;
        uint8_t     l_vdd_vid;
        uint8_t     l_vcs_vid;

        // Extract the VID
        l_vdd_vid = (uint8_t)(l_boot_voltage_info >> 16 & 0xFF);

        // Translate to voltage
        l_fapirc = vid2mv(l_vdd_vid, l_vdd_mv);
        if  (l_fapirc )
        {
            FAPI_ERR("Translate of VDD VID to Voltage Failed");
            break;
        }

        // Extract the VID
        l_vcs_vid = (uint8_t)(l_boot_voltage_info >>  8 & 0xFF);

        // Translate to voltage
        l_fapirc = vid2mv(l_vcs_vid, l_vcs_mv);
        if  (l_fapirc )
        {
            FAPI_ERR("Translate of VCS VID to Voltage Failed");
            break;
        }

        FAPI_INF("Boot VRM-11 VIDs:  VDD = %02X,         VCS = %02X",
                    l_vdd_vid, l_vcs_vid);

        FAPI_INF("Boot Voltage:      VDD = %1.2f mV, VCS = %1.2f mV",
                   (float)l_vdd_mv / 100, (float)l_vcs_mv / 100);

        if (!i_includeNode)
        {
            //Make sure we DON'T set NODE ID
            o_set_data &= ~( 1 << (sizeof(o_set_data)*8 - DEVICE_ID_CONTENT_BIT - 1));
        }
        else
        {

            //Also set node ID (to save Brazos)
            fapi::ATTR_FABRIC_NODE_ID_Type l_node_id =   0 ;
            l_fapirc =  FAPI_ATTR_GET(  ATTR_FABRIC_NODE_ID,
                                        &i_target,
                                        l_node_id );
            if  (l_fapirc )
            {
                FAPI_ERR("fapiGetAttribute of ATTR_FABRIC_NODE_ID failed");
                break;
            }
            FAPI_INF(   "ATTR_FABRIC_NODE_ID => %d", l_node_id);


            o_set_data |= 1 << (sizeof(o_set_data)*8 - DEVICE_ID_CONTENT_BIT - 1);
            o_set_data |= l_node_id << (sizeof(o_set_data)*8 -
                                        NODE_ID_BIT_POSITION -
                                        NODE_ID_BIT_LENGTH    );
        }

        FAPI_INF(   "Return Mailbox 4 value (standalone_mbox3_value) =  0x%08x",
                    o_set_data   );

    } while (0);

    return l_fapirc;
}

} // extern "C"
