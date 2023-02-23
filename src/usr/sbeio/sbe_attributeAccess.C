/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_attributeAccess.C $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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
/**
* @file  sbe_attributeAccess.C
* @brief Contains the Attribute Messages for SBE FIFO chipop
*
*/

#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbe_utils.H>
#include "sbe_fifodd.H"
#include <sbeio/sbeioreasoncodes.H>
#include <targeting/common/targetservice.H>

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACD(printf_string,args...) \
TRACDCOMP(g_trac_sbeio,"AttributeAccess: " printf_string,##args)

#define SBE_TRACF(printf_string,args...) \
TRACFCOMP(g_trac_sbeio,"AttributeAccess: " printf_string,##args)


namespace SBEIO
{

    // @TODO JIRA PFHB-258 These chipops are reliant on an SBE provided interface to generate, add, and interpret
    //                     attribute data to/from the SBE.

    /**
    * @brief @TODO JIRA PFHB-258
    *
    * @param[in] i_chipTarget The chip you would like to perform the chipop on
    *                       NOTE: HB should only be sending this to non-boot procs or Odyssey chips
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t sendAttrDumpRequest(TARGETING::Target * i_chipTarget)
    {
        errlHndl_t errl = nullptr;

        do
        {
            // Make sure the target is one of the supported types.
            errl = sbeioInterfaceChecks(i_chipTarget);
            if(errl)
            {
                break;
            }
            SBE_TRACF(EXIT_MRK "Skipping unimplemented chipop sendAttrDumpRequest");


        }while(0);

        SBE_TRACD(EXIT_MRK "sendAttrDumpRequest");
        return errl;
    };

    /**
    * @brief @TODO JIRA PFHB-258
    *
    * @param[in] i_chipTarget The chip you would like to perform the chipop on
    *                       NOTE: HB should only be sending this to non-boot procs or Odyssey chips
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t sendAttrListRequest(TARGETING::Target * i_chipTarget)
    {
        errlHndl_t errl = nullptr;

        do
        {
            // Make sure the target is one of the supported types.
            errl = sbeioInterfaceChecks(i_chipTarget);
            if(errl)
            {
                break;
            }
            SBE_TRACF(EXIT_MRK "Skipping unimplemented chipop sendAttrListRequest");


        }while(0);

        SBE_TRACD(EXIT_MRK "sendAttrListRequest");
        return errl;
    };

    /**
    * @brief @TODO JIRA PFHB-258
    *
    * @param[in] i_chipTarget The chip you would like to perform the chipop on
    *                       NOTE: HB should only be sending this to non-boot procs or Odyssey chips
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t sendAttrUpdateRequest(TARGETING::Target * i_chipTarget)
    {
        errlHndl_t errl = nullptr;

        do
        {
            // Make sure the target is one of the supported types.
            errl = sbeioInterfaceChecks(i_chipTarget);
            if(errl)
            {
                break;
            }
            SBE_TRACF(EXIT_MRK "Skipping unimplemented chipop sendAttrUpdateRequest");


        }while(0);

        SBE_TRACD(EXIT_MRK "sendAttrUpdateRequest");
        return errl;
    };
} //end namespace SBEIO

