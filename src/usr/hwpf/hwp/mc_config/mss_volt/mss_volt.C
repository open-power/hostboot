/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_volt/mss_volt.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
// $Id: mss_volt.C,v 1.22 2015/05/01 15:14:45 jdsloat Exp $
/* File mss_volt.C created by JEFF SABROWSKI on Fri 21 Oct 2011. */

//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2007
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE : mss_volt.C
// *! DESCRIPTION : Tools for centaur procedures
// *! OWNER NAME :   Jacob Sloat (jdsloat@us.ibm.com)
// *! BACKUP NAME :
// #! ADDITIONAL COMMENTS :
//
// General purpose funcs

//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:   | Comment:
//---------|----------|----------|-----------------------------------------------
//  1.0    | jsabrow  | 09/30/11 | Initial draft.
//  1.1    | jsabrow  | 12/13/11 | This version compiles. Attributes dont work yet.
//  1.3    | bellows  | 12/21/11 | fapiGetAssociatedDimms funciton does not work, added quick exit
//  1.4    | jsabrow  | 02/13/12 | Updates for code review
//  1.5    | jsabrow  | 03/26/12 | Updates for code review
//  1.8    | jdsloat  | 04/26/12 | fixed 1.5V issue
//  1.9    | jdsloat  | 05/08/12 | Removed debug message
//  1.10   | jdsloat  | 05/09/12 | Fixed typo
//  1.11   | bellows  | 07/16/12 | added in Id tag
//  1.11   | jdsloat  | 10/18/12 | Added check for violation of tolerant voltages of non-functional dimms.
//  1.12   | jdsloat  | 03/05/14 | RAS review Edits -- Error HW callouts
//  1.13   | jdsloat  | 06/05/14 | Added ATTR_MSS_VOLT_VPP being set, as well as ATTR_MSS_VOLT_OVERRIDE
//  1.14   | jdsloat  | 06/19/14 | Added error checking associated ATTR_MSS_VOLT_OVERRIDE
//  1.16   | jdsloat  | 11/05/14 | Fixed a if to else if in error checking of ATTR_MSS_VOLT_OVERRIDE
//  1.17   | jdsloat  | 11/19/14 | Fixed a variable not being set preventing use of ATTR_MSS_VOLT_OVERRIDE, fixed internal log numbering
//  1.18   | pardeik  | 02/17/15 | initialize ATTR_MSS_VMEM_REGULATOR_MAX_DIMM_COUNT
//  1.19   | jdsloat  | 04/07/15 | Called out dimms configured for 1.5V unless specified in ATTR_MSS_VOLT_COMPLIANT_DIMMS
//  1.20   | jdsloat  | 04/08/15 | Added fapi:: to Enums used with ATTR_MSS_VOLT_COMPLIANT_DIMMS
//  1.21   | jdsloat  | 04/29/15 | Made the error return for compliant unique and added a return RC
//  1.22   | jdsloat  | 05/01/15 | Fixed initialization of dimm_spd and Enum use for DDR4 dimms, Added FAPI_INF message

// This procedure takes a vector of Centaurs behind a voltage domain,
// reads in supported DIMM voltages from SPD and determines optimal
//  voltage bin for the DIMM voltage domain.
// supported voltage bins:  DDR3: 1.35   DDR4: 1.25V (expected)


//----------------------------------------------------------------------
//  Includes - FAPI
//----------------------------------------------------------------------
#include <fapi.H>
#include <mss_volt.H>

//----------------------------------------------------------------------
//  Constants
//----------------------------------------------------------------------
const uint32_t MAX_TOLERATED_VOLT = 1500;
const uint32_t MAX_TOLERATED_DDR3_VOLT = 1500;
const uint32_t MAX_TOLERATED_DDR4_VOLT = 1200;
const uint32_t DDR3_VPP_VOLT = 0000;
const uint32_t DDR4_VPP_VOLT = 2500;

fapi::ReturnCode mss_volt(std::vector<fapi::Target> & i_targets_memb)
{

    fapi::ReturnCode l_rc;
    uint8_t l_dimm_functionality=0;
    uint8_t l_spd_dramtype=0;
    uint8_t l_spd_volts=0;
    uint8_t l_spd_volts_all_dimms=0xFF;  //start assuming all voltages supported
    uint8_t l_dram_ddr3_found_flag=0;
    uint8_t l_dram_ddr4_found_flag=0;
    uint8_t l_volt_override = 0x00;
    uint8_t l_volt_override_domain = 0x00;

    uint32_t l_selected_dram_voltage=0;  //this gets written into all centaurs when done.
    uint32_t l_selected_dram_voltage_vpp=0;
    uint32_t l_tolerated_dram_voltage = MAX_TOLERATED_VOLT; //initially set to the max tolerated voltage
    uint8_t l_dimm_count = 0;
    uint8_t l_compliant_dimm_voltages = 0;

    do
    {
	//Gather whether 1.5V only DIMMs supported
	l_rc = FAPI_ATTR_GET(ATTR_MSS_VOLT_COMPLIANT_DIMMS,NULL,l_compliant_dimm_voltages); 
        if (l_rc) break;

        // Iterate through the list of centaurs
        for (uint32_t i=0; i < i_targets_memb.size(); i++)
        {
            std::vector<fapi::Target> l_mbaChiplets;
            // Get associated MBA's on this centaur
            l_rc=fapiGetChildChiplets(i_targets_memb[i], fapi::TARGET_TYPE_MBA_CHIPLET, l_mbaChiplets);
            if (l_rc) break;


	    l_rc = FAPI_ATTR_GET(ATTR_MSS_VOLT_OVERRIDE, &i_targets_memb[i], l_volt_override);
	    if (l_rc) break;

	    // Note if there is an overrride being applied on the domain
	    if ( (l_volt_override != fapi::ENUM_ATTR_MSS_VOLT_OVERRIDE_NONE) && (l_volt_override_domain == fapi::ENUM_ATTR_MSS_VOLT_OVERRIDE_NONE) )
	    {
	    	l_volt_override_domain = l_volt_override;
	    }

	    // Error if our overides are not the same across the domain
	    if (l_volt_override_domain != l_volt_override)
	    {
                        // this just needs to callout the mismatching memb.
                        const uint8_t &OVERRIDE_TYPE = l_volt_override;
                        const uint8_t &OVERRIDE_DOMAIN_TYPE = l_volt_override_domain;
                        const fapi::Target &MEMB_TARGET = i_targets_memb[i];
                        FAPI_ERR("Mismatch volt override request.  Domain: 0x%x  Current Target Requests: 0x%x", l_volt_override_domain, l_volt_override);
                        FAPI_SET_HWP_ERROR(l_rc, RC_MSS_VOLT_OVERIDE_MIXING);
                        fapiLogError(l_rc);
	    }

            // Loop through the 2 MBA's
            for (uint32_t j=0; j < l_mbaChiplets.size(); j++)
            {
                std::vector<fapi::Target> l_dimm_targets;
                // Get a vector of DIMM targets
                l_rc = fapiGetAssociatedDimms(l_mbaChiplets[j], l_dimm_targets, fapi::TARGET_STATE_PRESENT);
                if (l_rc) break;

                for (uint32_t k=0; k < l_dimm_targets.size(); k++)
                {
                    l_rc = FAPI_ATTR_GET(ATTR_SPD_DRAM_DEVICE_TYPE, &l_dimm_targets[k], l_spd_dramtype);
                    if (l_rc) break;
                    l_rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_NOMINAL_VOLTAGE, &l_dimm_targets[k], l_spd_volts);
                    if (l_rc) break;
                    l_rc = FAPI_ATTR_GET(ATTR_FUNCTIONAL, &l_dimm_targets[k], l_dimm_functionality);
                    if (l_rc) break;

                    // spd_volts:  bit0= NOT 1.5V bit1=1.35V bit2=1.25V, assume a 1.20V in future for DDR4
                    // check for supported voltage/dram type combo  DDR3=12, DDR4=13
                    if (l_spd_dramtype == fapi::ENUM_ATTR_SPD_DRAM_DEVICE_TYPE_DDR3)
                    {
                        l_dram_ddr3_found_flag=1;
                    }
                    else if (l_spd_dramtype == fapi::ENUM_ATTR_SPD_DRAM_DEVICE_TYPE_DDR4)
                    {
                        l_dram_ddr4_found_flag=1;
                    }
                    else 
                    {
                        // this just needs to be deconfiged at the dimm level
                        const uint8_t &DEVICE_TYPE = l_spd_dramtype;
                        const fapi::Target &DIMM_TARGET = l_dimm_targets[k];
                        FAPI_ERR("Unknown DRAM Device Type 0x%x", l_spd_dramtype);
                        FAPI_SET_HWP_ERROR(l_rc, RC_MSS_VOLT_UNRECOGNIZED_DRAM_DEVICE_TYPE);
                        fapiLogError(l_rc);
                    }

                    if(l_dimm_functionality == fapi::ENUM_ATTR_FUNCTIONAL_FUNCTIONAL)
                    {
                        //AND dimm voltage capabilities together to find aggregate voltage support on all dimms
                        l_spd_volts_all_dimms = l_spd_volts_all_dimms & l_spd_volts;
                    }

                }//end of dimms loop
                if (l_rc)
                {
                    break;
                }
            }//end of mba loop
            if (l_rc)
            {
                break;
            }
        }//end of centaur (memb) loop      
        if (l_rc)
        {
            // Break out of do...while(0)
            break;
        }

        // now we figure out if we have a supported ddr type and voltage
        // note: only support DDR3=1.35V and DDR4=1.2xV


        // Mixed Dimms, Deconfig the DDR4.
        if (l_dram_ddr3_found_flag && l_dram_ddr4_found_flag)
        {
            std::vector<fapi::Target> l_dimm_targets_deconfig;
            // Iterate through the list of centaurs
            for (uint32_t i=0; i < i_targets_memb.size(); i++)
            {
                std::vector<fapi::Target> l_mbaChiplets;
                // Get associated MBA's on this centaur
                l_rc=fapiGetChildChiplets(i_targets_memb[i], fapi::TARGET_TYPE_MBA_CHIPLET, l_mbaChiplets);
                if (l_rc) break;
                // Loop through the 2 MBA's
                for (uint32_t j=0; j < l_mbaChiplets.size(); j++)
                {
                    std::vector<fapi::Target> l_dimm_targets;
                    // Get a vector of DIMM targets
                    l_rc = fapiGetAssociatedDimms(l_mbaChiplets[j], l_dimm_targets, fapi::TARGET_STATE_PRESENT);
                    if (l_rc) break;
                    for (uint32_t k=0; k < l_dimm_targets.size(); k++)
                    {

                        l_rc = FAPI_ATTR_GET(ATTR_SPD_DRAM_DEVICE_TYPE, &l_dimm_targets[k], l_spd_dramtype);
                        if (l_rc) break;

                        if (l_spd_dramtype == fapi::ENUM_ATTR_SPD_DRAM_DEVICE_TYPE_DDR4)
                        {
                            const fapi::Target &DIMM_DDR4_TARGET = l_dimm_targets[k];
                            const uint8_t &DEVICE_TYPE = l_spd_dramtype;
                            FAPI_ERR("mss_volt: DDR3 and DDR4 mixing not allowed");
                            FAPI_SET_HWP_ERROR(l_rc, RC_MSS_VOLT_DDR_TYPE_MIXING_UNSUPPORTED);
                            fapiLogError(l_rc);
                        }

                    }//end of dimms loop
                    if (l_rc)
                    {
                        break;
                    }
                }//end of mba loop
                if (l_rc)
                {
                    break;
                }
            }//end of centaur (memb) loop 

        }
        if (l_rc)
        {
            // Break out of do...while(0)
            break;
        }

	FAPI_INF( "Bitwise and of all DIMM_SPD: 0x%02x", l_spd_volts_all_dimms);

	// If we are going to land on using 1.5V and we are not enabling that usage via attribute.
	if ( ((l_spd_volts_all_dimms & fapi::ENUM_ATTR_SPD_MODULE_NOMINAL_VOLTAGE_OP1_35) != fapi::ENUM_ATTR_SPD_MODULE_NOMINAL_VOLTAGE_OP1_35) &&
	     ((l_spd_volts_all_dimms & fapi::ENUM_ATTR_SPD_MODULE_NOMINAL_VOLTAGE_OP1_2V) != fapi::ENUM_ATTR_SPD_MODULE_NOMINAL_VOLTAGE_OP1_2V) && 
	     ((l_spd_volts_all_dimms & fapi::ENUM_ATTR_SPD_MODULE_NOMINAL_VOLTAGE_NOTOP1_5) != fapi::ENUM_ATTR_SPD_MODULE_NOMINAL_VOLTAGE_NOTOP1_5) &&
	     (l_compliant_dimm_voltages == fapi::ENUM_ATTR_MSS_VOLT_COMPLIANT_DIMMS_PROCEDURE_DEFINED) )
        {	

            std::vector<fapi::Target> l_dimm_targets_deconfig;
            // Iterate through the list of centaurs
            for (uint32_t i=0; i < i_targets_memb.size(); i++)
            {
                std::vector<fapi::Target> l_mbaChiplets;
                // Get associated MBA's on this centaur
                l_rc=fapiGetChildChiplets(i_targets_memb[i], fapi::TARGET_TYPE_MBA_CHIPLET, l_mbaChiplets);
                if (l_rc) break;
                // Loop through the 2 MBA's
                for (uint32_t j=0; j < l_mbaChiplets.size(); j++)
                {
                    std::vector<fapi::Target> l_dimm_targets; 
                    // Get a vector of DIMM targets
                    l_rc = fapiGetAssociatedDimms(l_mbaChiplets[j], l_dimm_targets, fapi::TARGET_STATE_PRESENT);
                    if (l_rc) break;
                    for (uint32_t k=0; k < l_dimm_targets.size(); k++)
                    {
                        l_rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_NOMINAL_VOLTAGE, &l_dimm_targets[k], l_spd_volts);
                        if (l_rc) break;

                        if((l_spd_volts & fapi::ENUM_ATTR_SPD_MODULE_NOMINAL_VOLTAGE_NOTOP1_5) != fapi::ENUM_ATTR_SPD_MODULE_NOMINAL_VOLTAGE_NOTOP1_5)
                        {
                            const fapi::Target &DIMM_CV_TARGET = l_dimm_targets[k];
                            const uint8_t &DIMM_VOLTAGE = l_spd_volts;
                            FAPI_ERR("One or more DIMMs operate 1.5V which is not supported.");
                            FAPI_SET_HWP_ERROR(l_rc, RC_MSS_VOLT_DDR_TYPE_COMPLIANT_VOLTAGE);
                            fapiLogError(l_rc);
                        }

                    }//end of dimms loop
                    if (l_rc)
                    {
                        break;
                    }
                }//end of mba loop
                if (l_rc)
                {
                    break;
                }
            }//end of centaur (memb) loop  
	}

        if (l_rc)
        {
            break;
        }

	//Picking voltages based on overrides or supported voltages.
	if (l_volt_override != fapi::ENUM_ATTR_MSS_VOLT_OVERRIDE_NONE)
	{
	    if (l_volt_override == fapi::ENUM_ATTR_MSS_VOLT_OVERRIDE_VOLT_135)
	    {
		l_selected_dram_voltage = 1350;
		FAPI_INF( "mss_volt_overide being applied.  MSS_VOLT_OVERRIDE: 1.35V");
		FAPI_INF( "NOTE: Still checking for violations of tolerated voltage.  If DIMMs cannot tolerate, the override will not be applied.");
	    }
	    else if (l_volt_override == fapi::ENUM_ATTR_MSS_VOLT_OVERRIDE_VOLT_120)
	    {
	        l_selected_dram_voltage = 1200;
		FAPI_INF( "mss_volt_overide being applied.  MSS_VOLT_OVERRIDE: 1.20V");
		FAPI_INF( "NOTE: Still checking for violations of tolerated voltage.  If DIMMs cannot tolerate, the override will not be applied.");
	    }
	    else
	    {
                const uint8_t &OVERRIDE_TYPE = l_volt_override;
                FAPI_ERR("Unknown volt override request.  Override Request: 0x%x", l_volt_override);
                FAPI_SET_HWP_ERROR(l_rc, RC_MSS_VOLT_OVERIDE_UKNOWN);
                fapiLogError(l_rc);
	    }

	}
        else if (l_dram_ddr3_found_flag && ((l_spd_volts_all_dimms & fapi::ENUM_ATTR_SPD_MODULE_NOMINAL_VOLTAGE_OP1_35) == fapi::ENUM_ATTR_SPD_MODULE_NOMINAL_VOLTAGE_OP1_35))
        {
            l_selected_dram_voltage=1350;
	    l_selected_dram_voltage_vpp = DDR3_VPP_VOLT;
        }
        else if (l_dram_ddr4_found_flag && ((l_spd_volts_all_dimms & fapi::ENUM_ATTR_SPD_MODULE_NOMINAL_VOLTAGE_OP1_2V) == fapi::ENUM_ATTR_SPD_MODULE_NOMINAL_VOLTAGE_OP1_2V))
        {
            l_selected_dram_voltage=1200;
            l_selected_dram_voltage_vpp = DDR4_VPP_VOLT;
        }
        else if  ( ((l_spd_volts_all_dimms & fapi::ENUM_ATTR_SPD_MODULE_NOMINAL_VOLTAGE_NOTOP1_5) != fapi::ENUM_ATTR_SPD_MODULE_NOMINAL_VOLTAGE_NOTOP1_5) &&
		   (l_compliant_dimm_voltages == fapi::ENUM_ATTR_MSS_VOLT_COMPLIANT_DIMMS_ALL_VOLTAGES))
        {
            l_selected_dram_voltage=1500;
	    l_selected_dram_voltage_vpp = DDR3_VPP_VOLT;
        }
        else
        {

            std::vector<fapi::Target> l_dimm_targets_deconfig;
            // Iterate through the list of centaurs
            for (uint32_t i=0; i < i_targets_memb.size(); i++)
            {
                std::vector<fapi::Target> l_mbaChiplets;
                // Get associated MBA's on this centaur
                l_rc=fapiGetChildChiplets(i_targets_memb[i], fapi::TARGET_TYPE_MBA_CHIPLET, l_mbaChiplets);
                if (l_rc) break;
                // Loop through the 2 MBA's
                for (uint32_t j=0; j < l_mbaChiplets.size(); j++)
                {
                    std::vector<fapi::Target> l_dimm_targets; 
                    // Get a vector of DIMM targets
                    l_rc = fapiGetAssociatedDimms(l_mbaChiplets[j], l_dimm_targets, fapi::TARGET_STATE_PRESENT);
                    if (l_rc) break;
                    for (uint32_t k=0; k < l_dimm_targets.size(); k++)
                    {
                        l_rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_NOMINAL_VOLTAGE, &l_dimm_targets[k], l_spd_volts);
                        if (l_rc) break;

                        if((l_spd_volts & fapi::ENUM_ATTR_SPD_MODULE_NOMINAL_VOLTAGE_NOTOP1_5) == fapi::ENUM_ATTR_SPD_MODULE_NOMINAL_VOLTAGE_NOTOP1_5)
                        {
                            const fapi::Target &DIMM_UV_TARGET = l_dimm_targets[k];
                            const uint8_t &DIMM_VOLTAGE = l_spd_volts;
                            FAPI_ERR("One or more DIMMs do not support required voltage for DIMM type");
                            FAPI_SET_HWP_ERROR(l_rc, RC_MSS_VOLT_DDR_TYPE_REQUIRED_VOLTAGE);
                            fapiLogError(l_rc);
                        }

                    }//end of dimms loop
                    if (l_rc)
                    {
                        break;
                    }
                }//end of mba loop
                if (l_rc)
                {
                    break;
                }
            }//end of centaur (memb) loop  
        }
        if (l_rc)
        {
            // Break out of do...while(0)
            break;
        }



        // Must check to see if we violate Tolerent voltages of Non-functional Dimms
        // If so we must error/deconfigure on the dimm level primarily then centaur level.
        // Iterate through the list of centaurs
        for (uint32_t i=0; i < i_targets_memb.size(); i++)
        {
            std::vector<fapi::Target> l_dimm_targets_deconfig;

            l_tolerated_dram_voltage = MAX_TOLERATED_VOLT; // using 1.5 as this is the largest supported voltage
            std::vector<fapi::Target> l_mbaChiplets;
            // Get associated MBA's on this centaur
            l_rc=fapiGetChildChiplets(i_targets_memb[i], fapi::TARGET_TYPE_MBA_CHIPLET, l_mbaChiplets);
            if (l_rc) break;
            for (uint32_t j=0; j < l_mbaChiplets.size(); j++)
            {
                std::vector<fapi::Target> l_dimm_targets;
                // Get a vector of DIMM targets
                l_rc = fapiGetAssociatedDimms(l_mbaChiplets[j], l_dimm_targets, fapi::TARGET_STATE_PRESENT);
                if (l_rc) break;
                for (uint32_t k=0; k < l_dimm_targets.size(); k++)
                {
                    l_rc = FAPI_ATTR_GET(ATTR_FUNCTIONAL, &l_dimm_targets[k], l_dimm_functionality);
                    if (l_rc) break;

                    if(l_dimm_functionality == fapi::ENUM_ATTR_FUNCTIONAL_NON_FUNCTIONAL)
                    {
                        if (l_spd_dramtype == fapi::ENUM_ATTR_SPD_DRAM_DEVICE_TYPE_DDR3)
                        {
                            if (l_tolerated_dram_voltage > MAX_TOLERATED_DDR3_VOLT)
                            {
                                l_tolerated_dram_voltage =  MAX_TOLERATED_DDR3_VOLT;
                            }

                            if (MAX_TOLERATED_DDR3_VOLT < l_selected_dram_voltage)
                            {
                                FAPI_ERR("One or more DIMMs classified non-functional has a"
                                         " tolerated voltage below selected voltage.");
                                const fapi::Target & CHIP_TARGET = l_dimm_targets[k];
                                const uint8_t &DIMM_VOLTAGE = l_selected_dram_voltage;
                                FAPI_SET_HWP_ERROR(l_rc, RC_MSS_VOLT_TOLERATED_VOLTAGE_VIOLATION);
                                fapiLogError(l_rc);
                            }
                        }
                        if (l_spd_dramtype == fapi::ENUM_ATTR_SPD_DRAM_DEVICE_TYPE_DDR4)
                        {
                            if (l_tolerated_dram_voltage > MAX_TOLERATED_DDR4_VOLT)
                            {
                                l_tolerated_dram_voltage =  MAX_TOLERATED_DDR4_VOLT;
                            }

                            if (MAX_TOLERATED_DDR4_VOLT < l_selected_dram_voltage)
                            {
                                FAPI_ERR("One or more DIMMs classified non-functional has a"
                                         " tolerated voltage below selected voltage.");
                                const fapi::Target & CHIP_TARGET = l_dimm_targets[k];
                                const uint8_t &DIMM_VOLTAGE = l_selected_dram_voltage;
                                FAPI_SET_HWP_ERROR(l_rc, RC_MSS_VOLT_TOLERATED_VOLTAGE_VIOLATION);
                                fapiLogError(l_rc);
                            }
                        }

                    }//End of functional check
                }//End of Dimm loop
                if (l_rc)
                {
                    break;
                }
            }// End of MBA loop
            if (l_rc)
            {
                break;
            }
            if ( l_tolerated_dram_voltage < l_selected_dram_voltage )
            {

                FAPI_ERR("Deconfiguring the associated Centaur.");
                const fapi::Target & CHIP_TARGET = i_targets_memb[i];
                const uint8_t &DIMM_VOLTAGE = l_selected_dram_voltage;
                FAPI_SET_HWP_ERROR(l_rc, RC_MSS_VOLT_TOLERATED_VOLTAGE_VIOLATION);
                break;
            }
        }//End of Centaur (MEMB) loop
        if (l_rc)
        {
            // Break out of do...while(0)
            break;
        }

        // Iterate through the list of centaurs again, to update ATTR
        for (uint32_t i=0; i < i_targets_memb.size(); i++)
        {
            l_rc = FAPI_ATTR_SET(ATTR_MSS_VOLT, &i_targets_memb[i], l_selected_dram_voltage);
            FAPI_INF( "mss_volt calculation complete.  MSS_VOLT: %d", l_selected_dram_voltage);
            if (l_rc) break;

	    l_rc = FAPI_ATTR_SET(ATTR_MSS_VOLT_VPP, &i_targets_memb[i], l_selected_dram_voltage_vpp);
            FAPI_INF( "mss_volt calculation complete.  MSS_VOLT_VPP: %d", l_selected_dram_voltage_vpp);
            if (l_rc) break;

        }
	// Initialize DIMM Count Attribute for mss_volt_dimm_count to use
	l_rc = FAPI_ATTR_SET(ATTR_MSS_VMEM_REGULATOR_MAX_DIMM_COUNT, NULL, l_dimm_count);
	if (l_rc) break;

    }while(0);
    return l_rc;
}
