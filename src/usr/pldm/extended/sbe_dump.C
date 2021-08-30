/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/extended/sbe_dump.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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

/* @brief Implementation of PLDM SBE dump functions.
 */

// Targeting
#include <targeting/common/target.H>

// PLDM
#include <pldm/extended/sbe_dump.H>
#include <pldm/pldm_errl.H>
#include <pldm/requests/pldm_pdr_requests.H>
#include <pldm/extended/pdr_manager.H>
#include "../common/pldmtrace.H"
#include <pldm/pldm_reasoncodes.H>
#include <openbmc/pldm/libpldm/platform.h>

// Error logging


using namespace PLDM;
using namespace ERRORLOG;
using namespace TARGETING;

// @TODO RTC 247294: Update this number to the correct value
const uint16_t SBE_DUMP_NUMERIC_EFFECTER_SEMANTIC_ID = 0x1234;

/* @brief Get the SBE Dump effecter ID for the given proc. Returns 0 if not found.
 */
effector_id_t getSbeDumpEffecterId(const Target* const i_proc)
{
    const auto entity_id = i_proc->getAttr<ATTR_PLDM_ENTITY_ID_INFO>();

    effector_id_t effecter_id = 0;

    thePdrManager().foreachPdrOfType(PLDM_NUMERIC_EFFECTER_PDR,
                                     [&effecter_id, &entity_id]
                                     (const uint8_t* pdr_data, uint32_t pdr_data_size)
                                     {
                                         const auto numeric_effecter_pdr
                                             = reinterpret_cast<const pldm_numeric_effecter_value_pdr*>(pdr_data);

                                         if (le16toh(numeric_effecter_pdr->entity_type) == entity_id.entityType
                                             && le16toh(numeric_effecter_pdr->entity_instance) == entity_id.entityInstanceNumber
                                             && le16toh(numeric_effecter_pdr->container_id) == entity_id.containerId)
                                         {
                                             if (le16toh(numeric_effecter_pdr->effecter_semantic_id) == SBE_DUMP_NUMERIC_EFFECTER_SEMANTIC_ID)
                                             {
                                                 effecter_id = le16toh(numeric_effecter_pdr->effecter_id);
                                                 return true; // halt the iteration
                                             }
                                         }
                                         return false; // continue the iteration
                                     });

    return effecter_id;
}

errlHndl_t PLDM::dumpSbe(Target* const i_proc, errlHndl_t i_errorlog)
{
    PLDM_ENTER("dumpSbe(0x%08x, 0x%08x)", get_huid(i_proc), ERRL_GETPLID_SAFE(i_errorlog));

    errlHndl_t errl = nullptr;

    do
    {

    const effector_id_t sbe_dump_effecter = getSbeDumpEffecterId(i_proc);

    if (sbe_dump_effecter == 0)
    {
        PLDM_ERR("dumpSbe: Can't find SBE dump effecter on processor 0x%08x", get_huid(i_proc));

        /*@
         * @errorlog
         * @errortype       ERRL_SEV_UNRECOVERABLE
         * @moduleid        MOD_SBE_DUMP
         * @reasoncode      RC_EFFECTER_NOT_FOUND
         * @userdata1       Processor HUID
         * @devdesc         Missing SBE dump effecter ID
         * @custdesc        Error occurred during system boot.
         */
        errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                             MOD_SBE_DUMP,
                             RC_EFFECTER_NOT_FOUND,
                             get_huid(i_proc),
                             0,
                             ErrlEntry::NO_SW_CALLOUT);

        addBmcErrorCallouts(errl);
        break;
    }

    const auto plid = ERRL_GETPLID_SAFE(i_errorlog);

    errl = sendSetNumericEffecterValueRequest(sbe_dump_effecter, plid, sizeof(plid));

    if (errl)
    {
        PLDM_ERR("dumpSbe: Failed to send numeric effecter value set request for processor 0x%08x (err = 0x%08x)",
                 get_huid(i_proc), ERRL_GETPLID_SAFE(errl));
        break;
    }

    assert(false);
    // @TODO RTC 247294: Wait on the response from the BMC

    } while (false);

    PLDM_EXIT("dumpSbe(0x%08x, 0x%08x) = 0x%08x",
              get_huid(i_proc), ERRL_GETPLID_SAFE(i_errorlog), ERRL_GETPLID_SAFE(errl));

    return errl;
}
