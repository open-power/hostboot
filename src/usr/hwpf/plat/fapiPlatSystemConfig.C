/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/plat/fapiPlatSystemConfig.C $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2014                        */
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
 *  @file fapiPlatSystemConfig.C
 *
 *  @brief Implements the fapiSystemConfig.H functions.
 *
 *  Note that platform code must provide the implementation.
 */

#include <fapiPlatTrace.H>
#include <fapiSystemConfig.H>
#include <hwpf/hwpf_reasoncodes.H>
#include <errl/errlentry.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/predicates/predicatectm.H>

extern "C"
{
using   namespace   TARGETING;

//******************************************************************************
// fapiGetOtherSideOfMemChannel function
//******************************************************************************
fapi::ReturnCode fapiGetOtherSideOfMemChannel(
    const fapi::Target& i_target,
    fapi::Target & o_target,
    const fapi::TargetState i_state)
{
    fapi::ReturnCode l_rc;
    TargetHandleList l_targetList;

    FAPI_DBG(ENTER_MRK "fapiGetOtherSideOfMemChannel. State: 0x%08x",
             i_state);

   TargetHandle_t   l_target =
          reinterpret_cast<TargetHandle_t>(i_target.get());

    if (l_target == NULL)
    {
        FAPI_ERR("fapiGetOtherSideOfMemChannel. Embedded NULL target pointer");
        /*@
         * @errortype
         * @moduleid     fapi::MOD_FAPI_GET_OTHER_SIDE_OF_MEM_CHANNEL
         * @reasoncode   fapi::RC_EMBEDDED_NULL_TARGET_PTR
         * @devdesc      Target has embedded null target pointer
         */
        const bool hbSwError = true;
        errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    fapi::MOD_FAPI_GET_OTHER_SIDE_OF_MEM_CHANNEL,
                    fapi::RC_EMBEDDED_NULL_TARGET_PTR,
                    0, 0, hbSwError);

        // Attach the error log to the fapi::ReturnCode
        l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
    }
    else if (i_target.getType() == fapi::TARGET_TYPE_MCS_CHIPLET)
    {
        // find the Centaur that is associated with this MCS
        getChildAffinityTargetsByState(l_targetList, l_target,
                        CLASS_CHIP, TYPE_MEMBUF, UTIL_FILTER_PRESENT);

        if(l_targetList.size() != 1) // one and only one expected
        {
            FAPI_ERR("fapiGetOtherSideOfMemChannel. expect 1 Centaur %d",
                     l_targetList.size());
            /*@
             * @errortype
             * @moduleid     fapi::MOD_FAPI_GET_OTHER_SIDE_OF_MEM_CHANNEL
             * @reasoncode   fapi::RC_NO_SINGLE_MEMBUFF
             * @userdata1    Number of Memory Buffers
             * @userdata2    MCS HUID
             * @devdesc      fapiGetOtherSideOfMemChannel could not find exactly
             *               one target on the other side of the correct state
             * @custdesc  A problem occurrred during the IPL of the system.
             */
            const bool hbSwError = true;
            errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                fapi::MOD_FAPI_GET_OTHER_SIDE_OF_MEM_CHANNEL,
                fapi::RC_NO_SINGLE_MEMBUFF,
                l_targetList.size(),
                TARGETING::get_huid(l_target),
                hbSwError);

            // Attach the error log to the fapi::ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_pError));

        }
        else
        {
            o_target.setType(fapi::TARGET_TYPE_MEMBUF_CHIP);
            o_target.set(reinterpret_cast<void *>(l_targetList[0]));
        }

    }
    else if (i_target.getType() == fapi::TARGET_TYPE_MEMBUF_CHIP)
    {
        // find the MCS that is associated with this Centaur
        getParentAffinityTargets (l_targetList, l_target,
                           CLASS_UNIT, TYPE_MCS, false);

        if(l_targetList.size() != 1) // one and only one expected
        {
            FAPI_ERR("fapiGetOtherSideOfMemChannel. expect 1 MCS %d",
                     l_targetList.size());
            /*@
             * @errortype
             * @moduleid     fapi::MOD_FAPI_GET_OTHER_SIDE_OF_MEM_CHANNEL
             * @reasoncode   fapi::RC_NO_SINGLE_MCS
             * @userdata1    Number of MCSs
             * @userdata2    Membuf HUID
             * @devdesc      fapiGetOtherSideOfMemChannel could not find exactly
             *               one target on the other side of the correct state
             * @custdesc  A problem occurrred during the IPL of the system.
             */
            const bool hbSwError = true;
            errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                fapi::MOD_FAPI_GET_OTHER_SIDE_OF_MEM_CHANNEL,
                fapi::RC_NO_SINGLE_MCS,
                l_targetList.size(),
                TARGETING::get_huid(l_target),
                hbSwError);

            // Attach the error log to the fapi::ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
        }
        else
        {
            o_target.setType(fapi::TARGET_TYPE_MCS_CHIPLET);
            o_target.set(reinterpret_cast<void *>(l_targetList[0]));
        }

    }
    else
    {
      FAPI_ERR("fapiGetOtherSideOfMemChannel. target 0x%08x not supported",
                     i_target.getType());
        /*@
         * @errortype
         * @moduleid     fapi::MOD_FAPI_GET_OTHER_SIDE_OF_MEM_CHANNEL
         * @reasoncode   fapi::RC_UNSUPPORTED_REQUEST
         * @userdata1    Requested type
         * @userdata2    Unsupported Target HUID
         * @devdesc      fapiGetOtherSideOfMemChannel request for unsupported
         *               or invalid target type
         * @custdesc  A problem occurrred during the IPL of the system: Request
         *            for unsupported or invalid target type.
         */
        const bool hbSwError = true;
        errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                fapi::MOD_FAPI_GET_OTHER_SIDE_OF_MEM_CHANNEL,
                fapi::RC_UNSUPPORTED_REQUEST,
                i_target.getType(),
                TARGETING::get_huid(l_target),
                hbSwError);

        // Attach the error log to the fapi::ReturnCode
        l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
    }

    if (!l_rc)  // OK so far, check that state is as requested 
    {
       HwasState l_state =
                l_targetList[0]->getAttr<ATTR_HWAS_STATE>();

       if (((i_state == fapi::TARGET_STATE_PRESENT) && !l_state.present) ||
           ((i_state == fapi::TARGET_STATE_FUNCTIONAL) && !l_state.functional))
       {
           FAPI_ERR("fapiGetOtherSideOfMemChannel. state mismatch");
           /*@
            * @errortype
            * @moduleid     fapi::MOD_FAPI_GET_OTHER_SIDE_OF_MEM_CHANNEL
            * @reasoncode   fapi::RC_STATE_MISMATCH
            * @userdata1    Requested state
            * @userdata2    Other Target HUID
            * @devdesc      fapiGetOtherSideOfMemChannel target not present or
            *               functional as requested
            * @custdesc     A problem occurred during the IPL of the system:
            *               Requested target not present or not functional.
            */
           const bool hbSwError = true;
           errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                fapi::MOD_FAPI_GET_OTHER_SIDE_OF_MEM_CHANNEL,
                fapi::RC_STATE_MISMATCH,
                i_state,
                TARGETING::get_huid(l_targetList[0]),
                hbSwError);

           // Attach the error log to the fapi::ReturnCode
           l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
       }

    }

    FAPI_DBG(EXIT_MRK "fapiGetOtherSideOfMemChannel. rc = 0x%x",
           static_cast<uint32_t>(l_rc));

    return l_rc;
}

//******************************************************************************
// fapiGetChildChiplets function
//******************************************************************************
fapi::ReturnCode fapiGetChildChiplets(
    const fapi::Target & i_chip,
    const fapi::TargetType i_chipletType,
    std::vector<fapi::Target> & o_chiplets,
    const fapi::TargetState i_state)
{
    FAPI_DBG(ENTER_MRK "fapiGetChildChiplets. Chiplet Type:0x%08x State:0x%08x",
             i_chipletType, i_state);

    fapi::ReturnCode l_rc;
    o_chiplets.clear();

    // Extract the HostBoot Target pointer for the input chip
    TARGETING::Target * l_pChip =
        reinterpret_cast<TARGETING::Target*>(i_chip.get());

    // Check that the input target is a chip
    if (!i_chip.isChip())
    {
        FAPI_ERR("fapiGetChildChiplets. Input target type 0x%08x is not a chip",
                 i_chip.getType());
        /*@
         * @errortype
         * @moduleid     fapi::MOD_FAPI_GET_CHILD_CHIPLETS
         * @reasoncode   fapi::RC_INVALID_REQUEST
         * @userdata1    Type of input target
         * @userdata2    Input Target HUID
         * @devdesc      fapiGetChildChiplets request for non-chip
         * @custdesc     A problem occurred during the IPL of the system.
         */
        const bool hbSwError = true;
        errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            fapi::MOD_FAPI_GET_CHILD_CHIPLETS,
            fapi::RC_INVALID_REQUEST,
            i_chip.getType(),
            TARGETING::get_huid(l_pChip),
            hbSwError);

        // Attach the error log to the fapi::ReturnCode
        l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
    }
    else
    {
        TARGETING::TYPE l_type = TARGETING::TYPE_NA;

        if (i_chipletType == fapi::TARGET_TYPE_EX_CHIPLET)
        {
            l_type = TARGETING::TYPE_EX;
        }
        else if (i_chipletType == fapi::TARGET_TYPE_MBA_CHIPLET)
        {
            l_type = TARGETING::TYPE_MBA;
        }
        else if (i_chipletType == fapi::TARGET_TYPE_MCS_CHIPLET)
        {
            l_type = TARGETING::TYPE_MCS;
        }
        else if (i_chipletType == fapi::TARGET_TYPE_XBUS_ENDPOINT)
        {
            l_type = TARGETING::TYPE_XBUS;
        }
        else if (i_chipletType == fapi::TARGET_TYPE_ABUS_ENDPOINT)
        {
            l_type = TARGETING::TYPE_ABUS;
        }
        else if (i_chipletType == fapi::TARGET_TYPE_L4)
        {
            l_type = TARGETING::TYPE_L4;
        }
        else
        {
            FAPI_ERR("fapiGetChildChiplets. Chiplet type 0x%08x not supported",
                     i_chipletType);
            /*@
             * @errortype
             * @moduleid     fapi::MOD_FAPI_GET_CHILD_CHIPLETS
             * @reasoncode   fapi::RC_UNSUPPORTED_REQUEST
             * @userdata1    Type of requested chiplet
             * @userdata2    Input Chip Target HUID
             * @devdesc      fapiGetChildChiplets request for unsupported
             *               or invalid chiplet type
            * @custdesc     A problem occurred during the IPL of the system:
            *               Request for an unsupported or invalid chiplet type.
             */
            const bool hbSwError = true;
            errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                fapi::MOD_FAPI_GET_CHILD_CHIPLETS,
                fapi::RC_UNSUPPORTED_REQUEST,
                i_chipletType,
                TARGETING::get_huid(l_pChip),
                hbSwError);

            // Attach the error log to the fapi::ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
        }
        if (!l_rc)
        {
            if (l_pChip == NULL)
            {
                FAPI_ERR("fapiGetChildChiplets. Embedded NULL target pointer");
                /*@
                 * @errortype
                 * @moduleid     fapi::MOD_FAPI_GET_CHILD_CHIPLETS
                 * @reasoncode   fapi::RC_EMBEDDED_NULL_TARGET_PTR
                 * @devdesc      Target has embedded null target pointer
                 */
                const bool hbSwError = true;
                errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    fapi::MOD_FAPI_GET_CHILD_CHIPLETS,
                    fapi::RC_EMBEDDED_NULL_TARGET_PTR,
                    0, 0, hbSwError);

                // Attach the error log to the fapi::ReturnCode
                l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
            }
            else
            {
                TARGETING::TargetHandleList l_chipletList;

                TARGETING::getChildChiplets(l_chipletList, l_pChip, l_type,
                                            false);

                // Return fapi::Targets to the caller
                for (TARGETING::TargetHandleList::const_iterator
                        chipletIter = l_chipletList.begin();
                        chipletIter != l_chipletList.end();
                        ++chipletIter)
                {
                    TARGETING::HwasState l_state =
                        (*chipletIter)->getAttr<TARGETING::ATTR_HWAS_STATE>();

                    // HWPs/FAPI considers partial good chiplets as present, but
                    // firmware considers them not-present. Return all chiplets
                    // in the model when caller requests PRESENT
                    if ((fapi::TARGET_STATE_FUNCTIONAL == i_state) &&
                        !l_state.functional)
                    {
                        continue;
                    }

                    fapi::Target l_chiplet(i_chipletType,
                        reinterpret_cast<void *>(*chipletIter));
                    o_chiplets.push_back(l_chiplet);
                }
            }
        }
    }

    FAPI_DBG(EXIT_MRK "fapiGetChildChiplets. %d results", o_chiplets.size());
    return l_rc;
}

//******************************************************************************
// fapiGetAssociatedDimms function
//******************************************************************************
fapi::ReturnCode fapiGetAssociatedDimms(
    const fapi::Target& i_target,
    std::vector<fapi::Target> & o_dimms,
    const fapi::TargetState i_state)
{
    FAPI_DBG(ENTER_MRK "fapiGetAssociatedDimms. State: 0x%08x", i_state);

    fapi::ReturnCode l_rc;
    o_dimms.clear();

    // Extract the HostBoot Target pointer for the input target
    TARGETING::Target * l_pTarget =
        reinterpret_cast<TARGETING::Target*>(i_target.get());

    if (l_pTarget == NULL)
    {
        FAPI_ERR("fapiGetAssociatedDimms. Embedded NULL target pointer");
        /*@
         * @errortype
         * @moduleid     fapi::MOD_FAPI_GET_ASSOCIATE_DIMMS
         * @reasoncode   fapi::RC_EMBEDDED_NULL_TARGET_PTR
         * @devdesc      Target has embedded null target pointer
         */
        const bool hbSwError = true;
        errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                fapi::MOD_FAPI_GET_ASSOCIATE_DIMMS,
                fapi::RC_EMBEDDED_NULL_TARGET_PTR,
                0, 0, hbSwError);

        // Attach the error log to the fapi::ReturnCode
        l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
    }
    else
    {
        // Get associated dimms
        TARGETING::PredicateCTM l_predicate(TARGETING::CLASS_LOGICAL_CARD,
                                            TARGETING::TYPE_DIMM);
        TARGETING::TargetHandleList l_dimmList;

        TARGETING::targetService().
        getAssociated(l_dimmList, l_pTarget,
                      TARGETING::TargetService::CHILD_BY_AFFINITY,
                      TARGETING::TargetService::ALL, &l_predicate);

        // Return fapi::Targets to the caller
        for (TARGETING::TargetHandleList::const_iterator
                dimmIter = l_dimmList.begin();
                dimmIter != l_dimmList.end();
                ++dimmIter)
        {
            TARGETING::HwasState l_state =
                (*dimmIter)->getAttr<TARGETING::ATTR_HWAS_STATE>();

            if ((fapi::TARGET_STATE_PRESENT == i_state) && !l_state.present)
            {
                continue;
            }
            if ((fapi::TARGET_STATE_FUNCTIONAL == i_state) &&
                !l_state.functional)
            {
                continue;
            }

            fapi::Target l_dimm(fapi::TARGET_TYPE_DIMM,
                                reinterpret_cast<void *>(*dimmIter));
            o_dimms.push_back(l_dimm);
        }
    }

    FAPI_DBG(EXIT_MRK "fapiGetAssociatedDimms. %d results", o_dimms.size());
    return l_rc;
}

//******************************************************************************
// fapiGetParentChip function
//******************************************************************************
fapi::ReturnCode fapiGetParentChip(
    const fapi::Target& i_chiplet,
    fapi::Target & o_chip)
{
    FAPI_DBG(ENTER_MRK "fapiGetParentChip");

    fapi::ReturnCode l_rc;

    // Extract the HostBoot Target pointer for the input chiplet
    TARGETING::Target * l_pChiplet =
        reinterpret_cast<TARGETING::Target*>(i_chiplet.get());

    // Check that the input target is a chiplet
    if (!i_chiplet.isChiplet())
    {
        FAPI_ERR("fapiGetParentChip. Input target type 0x%08x is not a chiplet",
                 i_chiplet.getType());

        /*@
         * @errortype
         * @moduleid     fapi::MOD_FAPI_GET_PARENT_CHIP
         * @reasoncode   fapi::RC_INVALID_REQUEST
         * @userdata1    Type of input target
         * @userdata2    Input Target HUID
         * @devdesc      fapiGetParentChip request for non-chiplet
         * @custdesc     A problem occurred during the IPL of the system.
         */
        const bool hbSwError = true;
        errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            fapi::MOD_FAPI_GET_PARENT_CHIP,
            fapi::RC_INVALID_REQUEST,
            i_chiplet.getType(),
            TARGETING::get_huid(l_pChiplet),
            hbSwError);

        // Attach the error log to the fapi::ReturnCode
        l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
    }
    else
    {
        if (l_pChiplet == NULL)
        {
            /*@
             * @errortype
             * @moduleid     fapi::MOD_FAPI_GET_PARENT_CHIP
             * @reasoncode   fapi::RC_EMBEDDED_NULL_TARGET_PTR
             * @devdesc      Target has embedded null target pointer
             */
            const bool hbSwError = true;
            errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                fapi::MOD_FAPI_GET_PARENT_CHIP,
                fapi::RC_EMBEDDED_NULL_TARGET_PTR,
                0, 0, hbSwError);

            // Attach the error log to the fapi::ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
        }
        else
        {
            const TARGETING::Target * l_pChip =
                TARGETING::getParentChip(l_pChiplet);

            if (l_pChip == NULL)
            {
                FAPI_ERR("fapiGetParentChip. Parent not found");
                /*@
                 * @errortype
                 * @moduleid     fapi::MOD_FAPI_GET_PARENT_CHIP
                 * @reasoncode   fapi::RC_NO_SINGLE_PARENT
                 * @userdata1    Input Chiplet Target HUID
                 * @devdesc      fapiGetParentChip did not find one parent
                 * @custdesc     A problem occurred during the IPL of the system.
                 */
                const bool hbSwError = true;
                errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    fapi::MOD_FAPI_GET_PARENT_CHIP,
                    fapi::RC_NO_SINGLE_PARENT,
                    TARGETING::get_huid(l_pChiplet),
                    0, hbSwError);

                // Attach the error log to the fapi::ReturnCode
                l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
            }
            else
            {
                // Set the output chip type
                if (l_pChip->getAttr<TARGETING::ATTR_TYPE>() ==
                    TARGETING::TYPE_PROC)
                {
                    o_chip.setType(fapi::TARGET_TYPE_PROC_CHIP);
                }
                else
                {
                    o_chip.setType(fapi::TARGET_TYPE_MEMBUF_CHIP);
                }

                // Set the output chip (platform specific) handle
                o_chip.set(reinterpret_cast<void *>
                    (const_cast<TARGETING::Target*>(l_pChip)));
            }
        }
    }

    FAPI_DBG(EXIT_MRK "fapiGetParentChip");
    return l_rc;
}


} // extern "C"
