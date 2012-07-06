/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/plat/fapiPlatHwAccess.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2011-2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/plat/fapiPlatHwAccess.C $
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
 *  @file fapiPlatHwAccess.C
 *
 *  @brief Implements the fapiHwAccess.H functions.
 *
 *  Note that platform code must provide the implementation.
 */

#include <fapiHwAccess.H>
#include <fapiPlatTrace.H>
#include <fapiPlatHwAccess.H>
#include <errl/errlentry.H>
#include <devicefw/userif.H>
#include <ecmdDataBufferBase.H>
#include <fapiPlatReasonCodes.H>
#include <targeting/common/predicates/predicates.H>
#include <targeting/common/targetservice.H>

extern "C"
{

//******************************************************************************
// platGetScom function, the platform implementation
//******************************************************************************
fapi::ReturnCode platGetScom(const fapi::Target& i_target,
                             const uint64_t i_address,
                             ecmdDataBufferBase & o_data)
{
    FAPI_DBG(ENTER_MRK "platGetScom");

    fapi::ReturnCode l_rc;
    errlHndl_t l_err = NULL;
    uint32_t l_ecmdRc = ECMD_DBUF_SUCCESS;

    // Extract the component pointer
    TARGETING::Target* l_target =
            reinterpret_cast<TARGETING::Target*>(i_target.get());

    // Perform SCOM read
    uint64_t l_data = 0;
    size_t l_size = sizeof(uint64_t);

    l_err = deviceRead(l_target,
                       &l_data,
                       l_size,
                       DEVICE_SCOM_ADDRESS(i_address));
    if (l_err)
    {
        // Add the error log pointer as data to the ReturnCode
        l_rc.setPlatError(reinterpret_cast<void *> (l_err));
    }
    else
    {
        // Set buffer to 64-bit long to store data
        l_ecmdRc = o_data.setBitLength(64);
        if (l_ecmdRc == ECMD_DBUF_SUCCESS)
        {
            l_ecmdRc = o_data.setDoubleWord(0, l_data);
        }

        if (l_ecmdRc)
        {
            FAPI_ERR("platGetScom: ecmdDataBufferBase setBitLength() or setDoubleWord() returns error, ecmdRc 0x%.8X",
                    l_ecmdRc);
            l_rc.setEcmdError(l_ecmdRc);
        }
    }

    FAPI_DBG(EXIT_MRK "platGetScom");
    return l_rc;
}

//******************************************************************************
// platPutScom function
//******************************************************************************
fapi::ReturnCode platPutScom(const fapi::Target& i_target,
                             const uint64_t i_address,
                             ecmdDataBufferBase & i_data)
{
    FAPI_DBG(ENTER_MRK "platPutScom");
    fapi::ReturnCode l_rc;
    errlHndl_t l_err = NULL;

    // Extract the component pointer
    TARGETING::Target* l_target =
            reinterpret_cast<TARGETING::Target*>(i_target.get());

    // Perform SCOM write
    uint64_t l_data = i_data.getDoubleWord(0);
    size_t l_size = sizeof(uint64_t);
    l_err = deviceWrite(l_target,
                        &l_data,
                        l_size,
                        DEVICE_SCOM_ADDRESS(i_address));
    if (l_err)
    {
        // Add the error log pointer as data to the ReturnCode
        l_rc.setPlatError(reinterpret_cast<void *> (l_err));
    }

    FAPI_DBG(EXIT_MRK "platPutScom");
    return l_rc;
}

//******************************************************************************
// platPutScomUnderMask function
//******************************************************************************
fapi::ReturnCode platPutScomUnderMask(const fapi::Target& i_target,
                                      const uint64_t i_address,
                                      ecmdDataBufferBase & i_data,
                                      ecmdDataBufferBase & i_mask)
{
    FAPI_DBG(ENTER_MRK "platPutScomUnderMask");
    fapi::ReturnCode l_rc;
    errlHndl_t l_err = NULL;

    // Extract the component pointer
    TARGETING::Target* l_target =
            reinterpret_cast<TARGETING::Target*>(i_target.get());

    do
    {
        // Get current value from HW
        uint64_t l_data = 0;
        size_t l_size = sizeof(uint64_t);
        l_err = deviceRead(l_target,
                           &l_data,
                           l_size,
                           DEVICE_SCOM_ADDRESS(i_address));
        if (l_err)
        {
            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_err));
            break;
        }

        // Calculate new value to write to reg
        uint64_t l_inData = i_data.getDoubleWord(0); // Data to write
        uint64_t l_inMask = i_mask.getDoubleWord(0); // Write mask
        uint64_t l_inMaskInverted = ~(l_inMask);     // Write mask inverted
        uint64_t l_newMask = (l_inData & l_inMask);  // Retain set data bits

        // l_data = current data set bits
        l_data &= l_inMaskInverted;

        // l_data = current data set bit + set mask bits
        l_data |= l_newMask;

        // Write new value
        l_err = deviceWrite(l_target,
                            &l_data,
                            l_size,
                            DEVICE_SCOM_ADDRESS(i_address));
        if (l_err)
        {
            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_err));
            break;
        }

    }
    while(0);

    FAPI_DBG(EXIT_MRK "platPutScomUnderMask");
    return l_rc;
}

/****************************************************************************
 *  @brief Verify target of a cfam access
 *         We can't access the cfam engine of the master processor; therefore,
 *         we should not allow a cfam access on any processor in any position
 *         from a FAPI standpoint
 *         This function will return an error if the input target is of
 *         processor type.
 *
 *  @param[in]  i_target        The target where cfam access is called on.
 *
 *  @return errlHndl_t if target is a processor, NULL otherwise.
 ****************************************************************************/
static errlHndl_t verifyCfamAccessTarget(const fapi::Target& i_target)
{
    errlHndl_t l_err = NULL;

    // Can't access cfam engine on processors
    if (i_target.getType() == fapi::TARGET_TYPE_PROC_CHIP)
    {
        // Add the error log pointer as data to the ReturnCode
        FAPI_ERR("verifyCfamAccessTarget: Attempt to access CFAM register on a processor chip");

        /*@
         * @errortype
         * @moduleid     MOD_VERIFY_CFAM_ACCESS_TARGET
         * @reasoncode   RC_CFAM_ACCESS_ON_PROC_ERR
         * @userdata1    Target type
         * @devdesc      Attempt to access CFAM register on a processor chip
         */
        l_err = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    fapi::MOD_VERIFY_CFAM_ACCESS_TARGET,
                    fapi::RC_CFAM_ACCESS_ON_PROC_ERR,
                    i_target.getType());
    }

    return l_err;
}

/****************************************************************************
 *  @brief Get chip target for cfam access
 *         HW procedures may pass in non-chip targets (such as MBA or
 *         MBS as a target), so we need to find the parent chip in order
 *         to pass it to the device driver.
 *
 *  @param[in]  i_target        The target as passed in by the procedure.
 *
 *  @return errlHndl_t if can't find parent, NULL otherwise.
 ****************************************************************************/
static errlHndl_t getCfamChipTarget(const TARGETING::Target* i_target,
                                    TARGETING::Target*& o_chipTarget)
{
    errlHndl_t l_err = NULL;

    // Default to input target
    o_chipTarget = const_cast<TARGETING::Target*>(i_target);

    // Check to see if this is a chiplet
    if (i_target->getAttr<TARGETING::ATTR_CLASS>() == TARGETING::CLASS_UNIT)
    {
        // Look for its chip parent
        TARGETING::PredicateCTM l_chipClass(TARGETING::CLASS_CHIP);
        TARGETING::TargetHandleList l_list;
        TARGETING::TargetService& l_targetService = TARGETING::targetService();
        (void) l_targetService.getAssociated(
                l_list,
                i_target,
                TARGETING::TargetService::PARENT,
                TARGETING::TargetService::ALL,
                &l_chipClass);

        if ( l_list.size() == 1 )
        {
            o_chipTarget = l_list[0];
        }
        else
        {
            // Something is wrong here, can't have more than one parent chip
            FAPI_ERR("getCfamChipTarget: Invalid number of parent chip for this target chiplet - # parent chips %d", l_list.size());
            /*@
             * @errortype
             * @moduleid     MOD_GET_CFAM_CHIP_TARGET
             * @reasoncode   RC_INVALID_NUM_PARENT_CHIP
             * @userdata1    Number of parent chip found
             * @devdesc      Invalid num of parent chip found for input CFAM target chiplet
             */
            l_err = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        fapi::MOD_GET_CFAM_CHIP_TARGET,
                        fapi::RC_INVALID_NUM_PARENT_CHIP,
                        l_list.size());
        }
    }
    return l_err;
}

//******************************************************************************
// platGetCfamRegister function
//******************************************************************************
fapi::ReturnCode platGetCfamRegister(const fapi::Target& i_target,
                                     const uint32_t i_address,
                                     ecmdDataBufferBase & o_data)
{
    FAPI_DBG(ENTER_MRK "platGetCfamRegister");
    fapi::ReturnCode l_rc;
    errlHndl_t l_err = NULL;
    uint32_t l_ecmdRc = ECMD_DBUF_SUCCESS;

    do
    {
        // Can't access cfam engine on processors
        l_err = verifyCfamAccessTarget(i_target);
        if (l_err)
        {
            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_err));
            break;
        }

        // Extract the component pointer
        TARGETING::Target* l_target =
                reinterpret_cast<TARGETING::Target*>(i_target.get());

        // Get the chip target if l_target is not a chip
        TARGETING::Target* l_myChipTarget = NULL;
        l_err = getCfamChipTarget(l_target, l_myChipTarget);
        if (l_err)
        {
            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_err));
            break;
        }

        // Perform CFAM read via FSI
        // Address needs to be multiply by 4 because register addresses are word
        // offsets but the FSI addresses are byte offsets.
        // However, we need to preserve the engine's offset of 0x0C00 and 0x1000.
        uint64_t l_addr = ((i_address & 0x003F) << 2) | (i_address & 0xFF00);
        uint32_t l_data = 0;
        size_t l_size = sizeof(uint32_t);
        l_err = deviceRead(l_myChipTarget,
                           &l_data,
                           l_size,
                           DEVICE_FSI_ADDRESS(l_addr));
        if (l_err)
        {
            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_err));
            break;
        }

        // Set buffer to 32-bit long to store data
        l_ecmdRc = o_data.setBitLength(32);
        if (l_ecmdRc == ECMD_DBUF_SUCCESS)
        {
            l_ecmdRc = o_data.setWord(0, l_data);
        }
        if (l_ecmdRc)
        {
            FAPI_ERR("platGetCfamRegister: ecmdDataBufferBase setBitLength() or setWord() returns error, ecmdRc 0x%.8X",
                     l_ecmdRc);
            l_rc.setEcmdError(l_ecmdRc);
        }

    } while(0);

    FAPI_DBG(EXIT_MRK "platGetCfamRegister");
    return l_rc;
}

//******************************************************************************
// platPutCfamRegister function
//******************************************************************************
fapi::ReturnCode platPutCfamRegister(const fapi::Target& i_target,
                                     const uint32_t i_address,
                                     ecmdDataBufferBase & i_data)
{
    FAPI_DBG(ENTER_MRK "platPutCfamRegister");
    fapi::ReturnCode l_rc;
    errlHndl_t l_err = NULL;

    do
    {
        // Can't access cfam engine on processors
        l_err = verifyCfamAccessTarget(i_target);
        if (l_err)
        {
            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_err));
            break;
        }

        // Extract the component pointer
        TARGETING::Target* l_target =
                reinterpret_cast<TARGETING::Target*>(i_target.get());

        TARGETING::Target* l_myChipTarget = NULL;
        // Get the chip target if l_target is not a chip
        l_err = getCfamChipTarget(l_target, l_myChipTarget);
        if (l_err)
        {
            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_err));
            break;
        }

        // Perform CFAM write via FSI
        // Address needs to be multiply by 4 because register addresses are word
        // offsets but the FSI addresses are byte offsets
        // However, we need to preserve the engine's offset of 0x0C00 and 0x1000.
        uint64_t l_addr = ((i_address & 0x003F) << 2) | (i_address & 0xFF00);
        uint32_t l_data = i_data.getWord(0);
        size_t l_size = sizeof(uint32_t);
        l_err = deviceWrite(l_myChipTarget,
                            &l_data,
                            l_size,
                            DEVICE_FSI_ADDRESS(l_addr));
        if (l_err)
        {
            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_err));
            break;
        }

    } while (0);

    FAPI_DBG(EXIT_MRK "platPutCfamRegister");
    return l_rc;
}

/****************************************************************************
 * @brief   Modifying input 32-bit data with the specified mode
 *
 * This method modify 32-bit input data (io_modifiedData) by applying the
 * specified modify mode along with the input data (i_origData).
 *
 * @param[in]  i_modifyMode         Modification mode
 * @param[in]  i_origData           32-bit data to be used for modification
 * @param[out] io_modifiedData      32-bit data to be modified
 *
 * @return void
 *
 ****************************************************************************/
void platProcess32BitModifyMode(const fapi::ChipOpModifyMode i_modifyMode,
                                const uint32_t i_origDataBuf,
                                uint32_t& io_modifiedData)
{

    // OR operation
    if (fapi::CHIP_OP_MODIFY_MODE_OR == i_modifyMode)
    {
        io_modifiedData |= i_origDataBuf;
    }
    // AND operation
    else if (fapi::CHIP_OP_MODIFY_MODE_AND == i_modifyMode)
    {
        io_modifiedData &= i_origDataBuf;
    }
    // Must be XOR operation
    else
    {
        io_modifiedData ^= i_origDataBuf;
    }

    return;
}

//******************************************************************************
// platModifyCfamRegister function
//******************************************************************************
fapi::ReturnCode platModifyCfamRegister(const fapi::Target& i_target,
                                    const uint32_t i_address,
                                    ecmdDataBufferBase& i_data,
                                    const fapi::ChipOpModifyMode i_modifyMode)
{
    FAPI_DBG(ENTER_MRK "platModifyCfamRegister");
    fapi::ReturnCode l_rc;
    errlHndl_t l_err = NULL;

    do
    {
        // Can't access cfam engine on processors
        l_err = verifyCfamAccessTarget(i_target);
        if (l_err)
        {
            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_err));
            break;
        }

        // Extract the component pointer
        TARGETING::Target* l_target =
                reinterpret_cast<TARGETING::Target*>(i_target.get());

        // Get the chip target if l_target is not a chip
        TARGETING::Target* l_myChipTarget = NULL;
        l_err = getCfamChipTarget(l_target, l_myChipTarget);
        if (l_err)
        {
            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_err));
            break;
        }

        // Read current value
        // Address needs to be multiply by 4 because register addresses are word
        // offsets but the FSI addresses are byte offsets.
        // However, we need to preserve the engine's offset of 0x0C00 and 0x1000.
        uint64_t l_addr = ((i_address & 0x003F) << 2) | (i_address & 0xFF00);
        uint32_t l_data = 0;
        size_t l_size = sizeof(uint32_t);
        l_err = deviceRead(l_myChipTarget,
                           &l_data,
                           l_size,
                           DEVICE_FSI_ADDRESS(l_addr));
        if (l_err)
        {
            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_err));
            break;
        }

        // Applying modification
        platProcess32BitModifyMode(i_modifyMode, i_data.getWord(0), l_data);

        // Write back
        l_err = deviceWrite(l_target,
                            &l_data,
                            l_size,
                            DEVICE_FSI_ADDRESS(l_addr));
        if (l_err)
        {
            // Add the error log pointer as data to the ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_err));
            break;
        }

    } while (0);

    FAPI_DBG(EXIT_MRK "platModifyCfamRegister");
    return l_rc;
}

//******************************************************************************
// platGetRing function, the platform implementation
//******************************************************************************
fapi::ReturnCode platGetRing(const fapi::Target& i_target,
                             const uint32_t i_address,
                             ecmdDataBufferBase & o_data)
{
    FAPI_DBG(ENTER_MRK "platGetRing");

    fapi::ReturnCode l_rc;

    //TODO - Implement getRing when RTC 34014 is ready

    FAPI_DBG(EXIT_MRK "platGetRing");
    return l_rc;
}

//******************************************************************************
// platPutRing function
//******************************************************************************
fapi::ReturnCode platPutRing(const fapi::Target& i_target,
                             const uint32_t i_address,
                             ecmdDataBufferBase & i_data)
{
    FAPI_DBG(ENTER_MRK "platPutRing");
    fapi::ReturnCode l_rc;

    //TODO - Implement getRing when RTC 34014 is ready

    FAPI_DBG(EXIT_MRK "platPutRing");
    return l_rc;
}

//******************************************************************************
// platModifyRing function
//******************************************************************************
fapi::ReturnCode platModifyRing(const fapi::Target& i_target,
                             const uint32_t i_address,
                             ecmdDataBufferBase & i_data,
                             const fapi::ChipOpModifyMode i_modifyMode)
{
    FAPI_DBG(ENTER_MRK "platModifyRing");
    fapi::ReturnCode l_rc;

    //TODO - Implement ModifyRing when RTC 34014 is ready

    FAPI_DBG(EXIT_MRK "platModifyRing");
    return l_rc;
}

} // extern "C"
