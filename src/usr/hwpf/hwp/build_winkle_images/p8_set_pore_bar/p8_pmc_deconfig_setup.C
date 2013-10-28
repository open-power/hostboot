/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_set_pore_bar/p8_pmc_deconfig_setup.C $ */
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
// $Id: p8_pmc_deconfig_setup.C,v 1.10 2013/10/22 03:21:48 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pmc_deconfig_setup.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Greg Still         Email: stillgs@us.ibm.com
// *!
/// \file p8_pmc_deconfig_setup.C
/// \brief Setup PMC Deconfig based on EX chiplet enable bit (GP0(0))
///
///
/// High-level procedure flow:
/// \verbatim
///
///     Loop over Functional EX chiplets
///     {
///         Read GP0(0)
///         if ( clear )  // disabled
///         {
///             Set the respective core bit in PMC_CORE_DECONFIGURATION_REG
///             // Cores are held in 0:15
///         }
///     }
///
///  Procedure Prereq:
///     - System clocks are running
/// \endverbatim
///
//------------------------------------------------------------------------------


// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <fapi.H>
#include "p8_scom_addresses.H"
#include "p8_pmc_deconfig_setup.H"

extern "C" {

using namespace fapi;

//------------------------------------------------------------------------------
/**
 * p8_pmc_deconfig_setup -  Set PMC Deconfig register based on chiplet GP3(0)
 *
 * @param[in] i_target Chip target
 *
 *
 * @retval FAPI_RC_SUCCESS
 * @retval ERROR defined in xml
 */
ReturnCode
p8_pmc_deconfig_setup(const Target& i_target)
{

    fapi::ReturnCode                rc;
    uint32_t                        e_rc = 0;
    uint64_t                        address = 0;
    ecmdDataBufferBase              data(64);
    ecmdDataBufferBase              config_data(64);
    std::vector<fapi::Target>       l_exChiplets;
    uint8_t                         l_ex_number = 0;

    
    do
    {
        FAPI_INF("Executing p8_pmc_deconfig_setup on target %s...", i_target.toEcmdString());

        rc = fapiGetChildChiplets ( i_target, 
                                    TARGET_TYPE_EX_CHIPLET, 
                                    l_exChiplets, 
                                    TARGET_STATE_FUNCTIONAL);
        if (rc)
        {   
            FAPI_ERR("Error from fapiGetChildChiplets!");
            break;
        }

        FAPI_DBG("\tChiplet vector size  => %u ", l_exChiplets.size());

        // Set the buffer to assume that all chiplets are deconfigured.  Validly configured
        // chiplets will then turn off this deconfiguration.
        FAPI_INF("\tAssuming all cores are non-functional");
        e_rc |= config_data.flushTo0();
        e_rc |= config_data.setBit(0, 16);
        if (e_rc)
        {
            FAPI_ERR("Error (0x%x) flushing ecmdDataBufferBase", e_rc);
            rc.setEcmdError(e_rc);
            return rc;
        }

        // Iterate through the returned chiplets
        for (uint8_t j=0; j < l_exChiplets.size(); j++)
        {
                 
            // Get the core number
            rc = FAPI_ATTR_GET( ATTR_CHIP_UNIT_POS, 
                                &l_exChiplets[j], 
                                l_ex_number);
            if (rc)
            {
                FAPI_ERR("fapiGetAttribute of ATTR_CHIP_UNIT_POS error");
                break;
            }

            FAPI_INF(" Working on ex chiplet number %d", l_ex_number);
            
            address = EX_GP3_0x100F0012 + (l_ex_number * 0x01000000);
            rc=fapiGetScom(i_target, address, data);
            if (rc)
            {
                FAPI_ERR("fapiGetScom address 0x%08llX failed. rc = 0x%x", 
                            address,
                            (uint32_t)rc);
                break;
            }

            FAPI_DBG("\tGP0(0) from core %x (@ %08llx) => 0x%16llx",
                            l_ex_number,
                            address,
                            data.getDoubleWord(0));

            // Check if chiplet enable bit is set (configured);  If so,
            // clear the chiplet bit in PMC Core Deconfig Register (0:15)
            // indexed by ex number
            if ( data.isBitSet(0) )
            {
                FAPI_INF("\tSetting Core %X as functional", l_ex_number);
                e_rc |= config_data.clearBit(l_ex_number);
                if (e_rc)
                {
                    FAPI_ERR("Error (0x%x) setting bit in ecmdDataBufferBase", e_rc);
                    rc.setEcmdError(e_rc);
                    break;
                }
            }                            
        }
        
        address = PMC_CORE_DECONFIG_REG_0x0006200D;
        rc = fapiPutScom(i_target, address , config_data);
        if(rc)
        {
            FAPI_ERR("fapiPutScom address 0x%08llX failed. rc = 0x%x", 
                        address, 
                        (uint32_t)rc);
            break;
        }
        
        FAPI_INF("\tWriting PMC Core Deconfig Register with 0x%16llx", 
                        config_data.getDoubleWord(0));      
           
    } while (0);
    
    return rc;
}


} //end extern C

