/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_set_pore_bar/p8_pmc_deconfig_setup.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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
// $Id: p8_pmc_deconfig_setup.C,v 1.6 2012/09/28 15:24:33 stillgs Exp $
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

// ----------------------------------------------------------------------
// Constant definitions
// ----------------------------------------------------------------------


// ----------------------------------------------------------------------
// Global variables
// ----------------------------------------------------------------------


// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------


// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------


/// \param[in] i_target Chip target

/// \retval RC_PROCPM_PMC_DECONFIG_NO_CORESPM_PORE if no functional cores
///         are found
ReturnCode
p8_pmc_deconfig_setup(const Target& i_target)
{

    fapi::ReturnCode                l_rc;
    uint32_t                        e_rc = 0;
    ecmdDataBufferBase              data(64);
    ecmdDataBufferBase              config_data(64);
    std::vector<fapi::Target>       l_exChiplets;
    uint8_t                         l_functional = 0;
    uint8_t                         l_ex_number = 0;
    bool                            core_flag = false;


    FAPI_INF("Executing p8_pmc_deconfig_setup...");

    l_rc = fapiGetChildChiplets (i_target, TARGET_TYPE_EX_CHIPLET, l_exChiplets, TARGET_STATE_PRESENT);
	if (l_rc)
	{
	    FAPI_ERR("Error from fapiGetChildChiplets!");
	    return l_rc;
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
        l_rc.setEcmdError(e_rc);
        return l_rc;
    }

    // Iterate through the returned chiplets
	for (uint8_t j=0; j < l_exChiplets.size(); j++)
	{

        // Determine if it's functional
        l_rc = FAPI_ATTR_GET(ATTR_FUNCTIONAL, &l_exChiplets[j], l_functional);
        if (l_rc)
        {
            FAPI_ERR("fapiGetAttribute of ATTR_FUNCTIONAL error");
            break;
        }
        else
        {
            if ( l_functional )
            {
                // Get the core number
                l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &l_exChiplets[j], l_ex_number);
                if (l_rc)
                {
                    FAPI_ERR("fapiGetAttribute of ATTR_CHIP_UNIT_POS error");
                    break;
                }

                l_rc=fapiGetScom(i_target, (EX_GP3_0x100F0012+(l_ex_number*0x01000000)), data);
                if(l_rc)
                {
                    FAPI_ERR("GetScom error");
                    break;
                }

                FAPI_DBG("\tGP0(0) from core %x (@ %08llx) => 0x%16llx",
                                l_ex_number,
                                (EX_GP3_0x100F0012+(l_ex_number*0x01000000)),
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
                        l_rc.setEcmdError(e_rc);
                        break;
                    }
                    core_flag =  true;
                }
            }
            else  // Not Functional so skip it
            {
                // Do nothing
            }
        }
	}

    // If no errors, write the deconfig register
    if (!l_rc)
    {
	    if ( core_flag )
        {
            l_rc=fapiPutScom(i_target, PMC_CORE_DECONFIG_REG_0x0006200D , config_data);
            if(l_rc)
            {
                FAPI_ERR("PutScom error");
            }
            else
            {
                FAPI_INF("\tWriting PMC Core Deconfig Register with 0x%16llx", config_data.getDoubleWord(0));
            }
        }
        else
	    {
	        FAPI_ERR("No configured cores were detected!");
	        FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PMC_DECONFIG_NO_CORES);
	    }
    }
    return l_rc;
}


} //end extern C

