//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/plat/fapiPlatSystemConfig.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
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
    // TODO. Need to support i_state

    FAPI_INF(ENTER_MRK "fapiGetChildChiplets. Chiplet Type: 0x%x. State: 0x%x",
             i_chipletType, i_state);

    fapi::ReturnCode l_rc;
    o_chiplets.clear();

    // Create a Class/Type/Model predicate to look for units
    TARGETING::PredicateCTM l_predicate(TARGETING::CLASS_UNIT);

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
        // Update the predicate to look for the specified type
        if (i_chipletType == fapi::TARGET_TYPE_EX_CHIPLET)
        {
            l_predicate.setType(TARGETING::TYPE_EX);
        }
        else if (i_chipletType == fapi::TARGET_TYPE_MBA_CHIPLET)
        {
            l_predicate.setType(TARGETING::TYPE_MBA);
        }
        else if (i_chipletType == fapi::TARGET_TYPE_MCS_CHIPLET)
        {
            l_predicate.setType(TARGETING::TYPE_MCS);
        }
        else if (i_chipletType == fapi::TARGET_TYPE_XBUS_ENDPOINT)
        {
            l_predicate.setType(TARGETING::TYPE_XBUS);
        }
        else if (i_chipletType == fapi::TARGET_TYPE_ABUS_ENDPOINT)
        {
            l_predicate.setType(TARGETING::TYPE_ABUS);
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
    }

    do
    {
        if (l_rc)
        {
            break;
        }

        // Extract the HostBoot Target pointer for the input chip
        TARGETING::Target * l_pChip =
            reinterpret_cast<TARGETING::Target*>(i_chip.get());

        if (l_pChip == NULL)
        {
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
            break;
        }

        // Create a vector of TARGETING::Target pointers
        TARGETING::TargetHandleList l_chipletList;

        // Get children chiplets
        TARGETING::targetService().
            getAssociated(l_chipletList, l_pChip,
                          TARGETING::TargetService::CHILD,
                          TARGETING::TargetService::ALL, &l_predicate);

        // Return fapi::Targets to the caller
        for (uint32_t i = 0; i < l_chipletList.size(); i++)
        {
            fapi::Target l_chiplet(i_chipletType,
                                   reinterpret_cast<void *>(l_chipletList[i]));
            o_chiplets.push_back(l_chiplet);
        }
    } while(0);

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
    // TODO. Need to support i_state

    FAPI_INF(ENTER_MRK "fapiGetAssociatedDimms. State: 0x%x", i_state);

    fapi::ReturnCode l_rc;
    o_dimms.clear();

    // Create a Class/Type/Model predicate to look for dimm cards
    TARGETING::PredicateCTM l_predicate(TARGETING::CLASS_LOGICAL_CARD,
                                        TARGETING::TYPE_DIMM);

    // Extract the HostBoot Target pointer for the input target
    TARGETING::Target * l_pTarget =
        reinterpret_cast<TARGETING::Target*>(i_target.get());

    // Create a vector of TARGETING::Target pointers
    TARGETING::TargetHandleList l_dimmList;

    if (l_pTarget == NULL)
    {
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
        TARGETING::targetService().
        getAssociated(l_dimmList, l_pTarget,
                      TARGETING::TargetService::CHILD_BY_AFFINITY,
                      TARGETING::TargetService::ALL, &l_predicate);
    }

    // Return fapi::Targets to the caller
    for (uint32_t i = 0; i < l_dimmList.size(); i++)
    {
        fapi::Target l_dimm(fapi::TARGET_TYPE_DIMM,
                            reinterpret_cast<void *>(l_dimmList[i]));
        o_dimms.push_back(l_dimm);
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

    do
    {

        if (l_rc)
        {
            break;
        }

        // Create a Class/Type/Model predicate to look for chips
        TARGETING::PredicateCTM l_predicate(TARGETING::CLASS_CHIP);

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
            break;
        }

        // Create a vector of TARGETING::Target pointers
        TARGETING::TargetHandleList l_chipList;

        // Get parent
        TARGETING::targetService().
            getAssociated(l_chipList, l_pChiplet,
                          TARGETING::TargetService::PARENT,
                          TARGETING::TargetService::ALL, &l_predicate);

        if (l_chipList.size() != 1)
        {
            // One parent chip was not found
            FAPI_ERR("fapiGetParentChip. Number of parents found is %d",
                     l_chipList.size());

            /*@
             * @errortype
             * @moduleid     MOD_FAPI_GET_PARENT_CHIP
             * @reasoncode   RC_NO_SINGLE_PARENT
             * @userdata1    Number of parents found
             * @devdesc      fapiGetParentChip request did not find one parent
             */
            errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                fapi::MOD_FAPI_GET_PARENT_CHIP,
                fapi::RC_NO_SINGLE_PARENT,
                l_chipList.size());

            // Attach the error log to the fapi::ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
        }
        else
        {
            // Set the output chip type
            if (l_chipList[0]->getAttr<TARGETING::ATTR_TYPE>() ==
                TARGETING::TYPE_PROC)
            {
                o_chip.setType(fapi::TARGET_TYPE_PROC_CHIP);
            }
            else
            {
                o_chip.setType(fapi::TARGET_TYPE_MEMBUF_CHIP);
            }

            // Set the output chip (platform specific) handle
            o_chip.set(reinterpret_cast<void *>(l_chipList[0]));
        }
    } while(0);

    FAPI_INF(EXIT_MRK "fapiGetParentChip");
    return l_rc;
}


} // extern "C"
