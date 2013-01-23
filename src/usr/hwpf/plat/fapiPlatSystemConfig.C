/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/plat/fapiPlatSystemConfig.C $                    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
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
/**
 *  @file fapiPlatSystemConfig.C
 *
 *  @brief Implements the fapiSystemConfig.H functions.
 *
 *  Note that platform code must provide the implementation.
 */

#include <fapiPlatTrace.H>
#include <fapiSystemConfig.H>
#include <fapiPlatReasonCodes.H>
#include <errl/errlentry.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/predicates/predicatectm.H>

extern "C"
{

//******************************************************************************
// fapiGetChildChiplets function
//******************************************************************************
fapi::ReturnCode fapiGetChildChiplets(
    const fapi::Target & i_chip,
    const fapi::TargetType i_chipletType,
    std::vector<fapi::Target> & o_chiplets,
    const fapi::TargetState i_state)
{
    FAPI_INF(ENTER_MRK "fapiGetChildChiplets. Chiplet Type: 0x%x. State: 0x%x",
             i_chipletType, i_state);

    fapi::ReturnCode l_rc;
    o_chiplets.clear();

    // Check that the input target is a chip
    if (!i_chip.isChip())
    {
        FAPI_ERR("fapiGetChildChiplets. Input target type 0x%x is not a chip",
                 i_chip.getType());
        /*@
         * @errortype
         * @moduleid     MOD_FAPI_GET_CHILD_CHIPLETS
         * @reasoncode   RC_INVALID_REQUEST
         * @userdata1    Type of input target
         * @devdesc      fapiGetChildChiplets request for non-chip
         */
        errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            fapi::MOD_FAPI_GET_CHILD_CHIPLETS,
            fapi::RC_INVALID_REQUEST,
            i_chip.getType());

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
        else
        {
            FAPI_ERR("fapiGetChildChiplets. Chiplet type 0x%x not supported",
                     i_chipletType);
            /*@
             * @errortype
             * @moduleid     MOD_FAPI_GET_CHILD_CHIPLETS
             * @reasoncode   RC_UNSUPPORTED_REQUEST
             * @userdata1    Type of requested chiplet
             * @devdesc      fapiGetChildChiplets request for unsupported
             *               or invalid chiplet type
             */
            errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                fapi::MOD_FAPI_GET_CHILD_CHIPLETS,
                fapi::RC_UNSUPPORTED_REQUEST,
                i_chipletType);

            // Attach the error log to the fapi::ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
        }

        if (!l_rc)
        {
            // Extract the HostBoot Target pointer for the input chip
            TARGETING::Target * l_pChip =
                reinterpret_cast<TARGETING::Target*>(i_chip.get());

            if (l_pChip == NULL)
            {
                FAPI_ERR("fapiGetChildChiplets. Embedded NULL target pointer");
                /*@
                 * @errortype
                 * @moduleid     MOD_FAPI_GET_CHILD_CHIPLETS
                 * @reasoncode   RC_EMBEDDED_NULL_TARGET_PTR
                 * @devdesc      fapi target has embedded null target pointer
                 */
                errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    fapi::MOD_FAPI_GET_CHILD_CHIPLETS,
                    fapi::RC_EMBEDDED_NULL_TARGET_PTR);

                // Attach the error log to the fapi::ReturnCode
                l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
            }
            else
            {
                TARGETING::TargetHandleList l_chipletList;

                TARGETING::getChildChiplets(l_chipletList, l_pChip, l_type,
                                            false);

                // Return fapi::Targets to the caller
                for (uint32_t i = 0; i < l_chipletList.size(); i++)
                {
                    TARGETING::HwasState l_state =
                        l_chipletList[i]->getAttr<TARGETING::ATTR_HWAS_STATE>();

                    if ((fapi::TARGET_STATE_PRESENT == i_state) &&
                        !l_state.present)
                    {
                        continue;
                    }
                    if ((fapi::TARGET_STATE_FUNCTIONAL == i_state) &&
                        !l_state.functional)
                    {
                        continue;
                    }

                    fapi::Target l_chiplet(i_chipletType,
                        reinterpret_cast<void *>(l_chipletList[i]));
                    o_chiplets.push_back(l_chiplet);
                }
            }
        }
    }

    FAPI_INF(EXIT_MRK "fapiGetChildChiplets. %d results", o_chiplets.size());
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
    FAPI_INF(ENTER_MRK "fapiGetAssociatedDimms. State: 0x%x", i_state);

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
         * @moduleid     MOD_FAPI_GET_ASSOCIATE_DIMMS
         * @reasoncode   RC_EMBEDDED_NULL_TARGET_PTR
         * @devdesc      fapi target has embedded null target pointer
         */
        errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                fapi::MOD_FAPI_GET_ASSOCIATE_DIMMS,
                fapi::RC_EMBEDDED_NULL_TARGET_PTR);

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
        for (uint32_t i = 0; i < l_dimmList.size(); i++)
        {
            TARGETING::HwasState l_state =
                l_dimmList[i]->getAttr<TARGETING::ATTR_HWAS_STATE>();

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
                                reinterpret_cast<void *>(l_dimmList[i]));
            o_dimms.push_back(l_dimm);
        }
    }

    FAPI_INF(EXIT_MRK "fapiGetAssociatedDimms. %d results", o_dimms.size());
    return l_rc;
}

//******************************************************************************
// fapiGetParentChip function
//******************************************************************************
fapi::ReturnCode fapiGetParentChip(
    const fapi::Target& i_chiplet,
    fapi::Target & o_chip)
{
    FAPI_INF(ENTER_MRK "fapiGetParentChip");

    fapi::ReturnCode l_rc;

    // Check that the input target is a chiplet
    if (!i_chiplet.isChiplet())
    {
        FAPI_ERR("fapiGetParentChip. Input target type 0x%x is not a chiplet",
                 i_chiplet.getType());

        /*@
         * @errortype
         * @moduleid     MOD_FAPI_GET_PARENT_CHIP
         * @reasoncode   RC_INVALID_REQUEST
         * @userdata1    Type of input target
         * @devdesc      fapiGetParentChip request for non-chiplet
         */
        errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            fapi::MOD_FAPI_GET_PARENT_CHIP,
            fapi::RC_INVALID_REQUEST,
            i_chiplet.getType());

        // Attach the error log to the fapi::ReturnCode
        l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
    }
    else
    {
        // Extract the HostBoot Target pointer for the input chiplet
        TARGETING::Target * l_pChiplet =
            reinterpret_cast<TARGETING::Target*>(i_chiplet.get());

        if (l_pChiplet == NULL)
        {
            /*@
             * @errortype
             * @moduleid     MOD_FAPI_GET_PARENT_CHIP
             * @reasoncode   RC_EMBEDDED_NULL_TARGET_PTR
             * @devdesc      fapi target has embedded null target pointer
             */
            errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                fapi::MOD_FAPI_GET_PARENT_CHIP,
                fapi::RC_EMBEDDED_NULL_TARGET_PTR);

            // Attach the error log to the fapi::ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
        }
        else
        {
            const TARGETING::Target * l_pChip =
                TARGETING::getParentChip(l_pChiplet);

            if (l_pChip == NULL)
            {
                // One parent chip was not found
                FAPI_ERR("fapiGetParentChip. Parent not found");
                /*@
                 * @errortype
                 * @moduleid     MOD_FAPI_GET_PARENT_CHIP
                 * @reasoncode   RC_NO_SINGLE_PARENT
                 * @devdesc      fapiGetParentChip request did not find one parent
                 */
                errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    fapi::MOD_FAPI_GET_PARENT_CHIP,
                    fapi::RC_NO_SINGLE_PARENT);

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

    FAPI_INF(EXIT_MRK "fapiGetParentChip");
    return l_rc;
}


} // extern "C"
