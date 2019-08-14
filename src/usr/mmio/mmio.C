/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mmio/mmio.C $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
#include <sys/mmio.h>
#include <devicefw/driverif.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <errl/errludlogregister.H>
#include <targeting/common/predicates/predicates.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/targetservice.H>
#include <arch/memorymap.H>
#include <arch/ppc.H>

#include "mmio.H"
#include <mmio/mmio.H>
#include <mmio/mmio_reasoncodes.H>

#include <p9a_mc_scom_addresses.H>
#include <p9a_mc_scom_addresses_fld.H>
#include <error_info_defs.H>

#include "mmio_explorer.H"
#include <utils/chipids.H>

// Trace definition
trace_desc_t* g_trac_mmio = NULL;
TRAC_INIT(&g_trac_mmio, MMIO_COMP_NAME, 2*KILOBYTE, TRACE::BUFFER_SLOW);

#define OMI_PER_MC 8

using namespace TARGETING;

namespace MMIO
{

// TODO RTC 201493 - Remove these consts once HW group has defined them.
static const uint8_t P9A_MC_DSTLFIR_SUBCHANNEL_A_FAIL_ACTION = 20;
static const uint8_t P9A_MC_DSTLFIR_SUBCHANNEL_B_FAIL_ACTION = 21;

// Helper function declarations (definitions at the bottom of this file)
static
TargetHandle_t getParentProc(TargetHandle_t i_ocmbTarget);
static
errlHndl_t getProcScom(TargetHandle_t i_ocmbTarget,
                       uint64_t i_scomAddr,
                       uint64_t &o_scomData);

// NOTE: removed static qualifier to prevent compiler from complaining about
//       the function not being used.
errlHndl_t setProcScom(TargetHandle_t i_ocmbTarget,
                       uint64_t i_scomAddr,
                       uint64_t i_scomData);
static
void *mmio_memcpy(void *vdest, const void *vsrc, size_t len);


/*******************************************************************************
 *
 * @brief Setup the MMIO BAR registers for all OCMB chips in the system
 *
 * @return nullptr on success, failure otherwise.
 *
 */
errlHndl_t mmioSetup()
{
    errlHndl_t l_err = nullptr;

    TRACFCOMP(g_trac_mmio, ENTER_MRK"mmioSetup");
    // called after OMI bars have been written to HW registers
    do
    {
        // map 8 OCMBs at a time, set MMIO_VM_ADDR on each OCMB
        //
        // loop through all the Memory Channels (MC Targets)
        //     call allocate of 32 GB virtual memory space with mmio_dev_map() for each MC
        TargetHandleList l_mcTargetList;
        getAllChiplets(l_mcTargetList, TYPE_MC);

        for (auto & l_mcTarget: l_mcTargetList)
        {
            uint32_t  l_mcChipUnit =
                              l_mcTarget->getAttr<ATTR_CHIP_UNIT>();

            // Get the base BAR address for OpenCapi Memory Interfaces (OMIs) of this Memory Controller (MC)
            auto l_omiBaseAddr =
                  l_mcTarget->getAttr<ATTR_OMI_INBAND_BAR_BASE_ADDR_OFFSET>();

            // Build up the full address with group/chip address considerations
            auto l_procType = TARGETING::TYPE_PROC;
            TARGETING::Target* l_parentChip = getParent(l_mcTarget, l_procType);
            uint8_t l_groupId =
                   l_parentChip->getAttr<ATTR_PROC_EFF_FABRIC_GROUP_ID>();
            uint8_t l_chipId  =
                   l_parentChip->getAttr<ATTR_PROC_EFF_FABRIC_CHIP_ID>();
            uint64_t  l_realAddr = computeMemoryMapOffset( MMIO_BASE,
                                                           l_groupId,
                                                           l_chipId );

            //  Apply the MMIO base offset so we get the final address
            l_realAddr += l_omiBaseAddr;

            // Map the device with a kernal call, each device, the MC,  is 32 GB
            uint64_t l_virtAddr = reinterpret_cast<uint64_t>
                         (mmio_dev_map(reinterpret_cast<void *>(l_realAddr),
                                       THIRTYTWO_GB));

            TRACFCOMP ( g_trac_mmio, "MC%.02X (0x%.08X) MMIO BAR PHYSICAL ADDR = 0x%lX     VIRTUAL ADDR = 0x%lX" ,
                        l_mcChipUnit ? 0x23 : 0x01, get_huid(l_mcTarget),
                        l_realAddr, l_virtAddr);

            // set VM_ADDR on each OCMB
            TargetHandleList l_omiTargetList;
            getChildChiplets(l_omiTargetList, l_mcTarget, TYPE_OMI);

            for (auto & l_omiTarget: l_omiTargetList)
            {
                // ATTR_CHIP_UNIT is relative to other OMI under this PROC
                uint32_t l_omiChipUnit =
                              l_omiTarget->getAttr<ATTR_CHIP_UNIT>();

                // Get the OMI position relative to other OMIs under its parent MC chiplet
                uint32_t l_omiPosRelativeToMc = l_omiChipUnit % OMI_PER_MC;

                // Calculate what we think the real address for this OCMB should be. This should
                // match what the ATTR_OMI_INBAND_BAR_BASE_ADDR_OFFSET attribute is set to.

                // Each Memory Controller Channel (MCC) uses 8 GB of Memory Mapped IO, 4 GB for each of its child OCMBs.
                // Each OCMB has 2 MMIO distinct spaces that get mapped. The CONFIG space, and the MMIO space. The CONFIG
                // Space is always before the MMIO space we will treat that as the BAR for the OCMB target. These
                // paired OCMB spaces get interleaved as follows :
                //       ocmb  |  BAR ATTRIBUTE     | Type | Base reg           - end addr           | size | sub-ch
                //       +-----+--------------------+------+-----------------------------------------+------+-------
                //       ocmb0 | 0xYYYYYYY000000000 | cnfg | 0xYYYYYYY000000000 - 0xYYYYYYY07FFFFFFF | 2GB  | 0
                //       ocmb1 | 0xYYYYYYY080000000 | cnfg | 0xYYYYYYY080000000 - 0xYYYYYYY0FFFFFFFF | 2GB  | 1
                //       ocmb0 | N/A                | mmio | 0xYYYYYYY100000000 - 0xYYYYYYY17FFFFFFF | 2GB  | 0
                //       ocmb1 | N/A                | mmio | 0xYYYYYYY180000000 - 0xYYYYYYY1FFFFFFFF | 2GB  | 1
                //       +-----+--------------------+------+-----------------------------------------+------+-------

                // Calculate CNFG space BAR to write to OCMB attribute
                uint64_t l_currentOmiOffset = (( l_omiPosRelativeToMc / 2) * 8 * GIGABYTE) +
                                              (( l_omiPosRelativeToMc % 2) * 2 * GIGABYTE);

                // Calculated real address for this OMI is (BAR from MC attribute) + (currentOmiOffset)
                uint64_t l_calulatedRealAddr = l_omiBaseAddr + l_currentOmiOffset;

                // Grab bar value from attribute to verify it matches
                // our calculations
                auto l_omiBarAttrVal = l_omiTarget->
                               getAttr<ATTR_OMI_INBAND_BAR_BASE_ADDR_OFFSET>();

                if(l_omiBarAttrVal != l_calulatedRealAddr)
                {
                    TRACFCOMP(g_trac_mmio,
                              "Discrepancy found between calculated OMI MMIO bar offset and what we found in ATTR_OMI_INBAND_BAR_BASE_ADDR_OFFSET");
                    TRACFCOMP(g_trac_mmio, "Calculated Offset: 0x%lX,  Attribute Value : 0x%lX", l_calulatedRealAddr, l_omiBarAttrVal);

                    /*@
                    * @errortype   ERRORLOG::ERRL_SEV_UNRECOVERABLE
                    * @moduleid    MMIO::MOD_MMIO_SETUP
                    * @reasoncode  MMIO::RC_BAR_OFFSET_MISMATCH
                    * @userdata1   Calculated Bar Offset
                    * @userdata2   Bar offset from attribute
                    * @devdesc     Mismatch between calculated map value
                    *              and what is in attribute xml
                    * @custdesc    Unexpected memory subsystem firmware error.
                    */
                    l_err = new ERRORLOG::ErrlEntry(
                                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            MMIO::MOD_MMIO_SETUP,
                                            MMIO::RC_BAR_OFFSET_MISMATCH,
                                            l_calulatedRealAddr,
                                            l_omiBarAttrVal,
                                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                    l_err->collectTrace( MMIO_COMP_NAME);
                    ERRORLOG::ErrlUserDetailsTarget(l_omiTarget).addToLog(l_err);

                    break;
                }


                uint64_t l_currentOmiVirtAddr = l_virtAddr + l_currentOmiOffset;

                // set VM_ADDR the associated OCMB
                TargetHandleList l_ocmbTargetList;
                getChildAffinityTargets(l_ocmbTargetList, l_omiTarget,
                                  CLASS_CHIP, TYPE_OCMB_CHIP);

                assert(l_ocmbTargetList.size() == 1 , "OCMB chips list found for a given OMI != 1 as expected");

                TRACFCOMP(g_trac_mmio,
                          "Setting HUID 0x%.08X MMIO vm addr to be 0x%lX, real"
                          " address is 0x%lX",
                          get_huid(l_ocmbTargetList[0]),
                          l_currentOmiVirtAddr,
                          l_calulatedRealAddr | MMIO_BASE );

                l_ocmbTargetList[0]->
                            setAttr<ATTR_MMIO_VM_ADDR>(l_currentOmiVirtAddr);
            }
        }
    } while(0);

    TRACFCOMP(g_trac_mmio, EXIT_MRK"mmioSetup");

    return l_err;
}

// Direct OCMB reads and writes to the device's memory mapped memory.
DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::MMIO,
                      TYPE_OCMB_CHIP,
                      ocmbMmioPerformOp);

/*******************************************************************************
 *
 * @brief Switch to using I2C instead of MMIO SCOMs for an OCMB
 *
 * @param[in] i_ocmbTarget Which OCMB to switch to using I2C
 *
 */
void disableInbandScomsOcmb(const TargetHandle_t i_ocmbTarget)
{
    mutex_t* l_mutex = NULL;

    TRACFCOMP(g_trac_mmio,
              "disableInbandScomsOcmb: switching to use I2C on OCMB 0x%08x",
               get_huid(i_ocmbTarget));

    //don't mess with attributes without the mutex (just to be safe)
    l_mutex = i_ocmbTarget->getHbMutexAttr<ATTR_IBSCOM_MUTEX>();
    mutex_lock(l_mutex);

    ScomSwitches l_switches = i_ocmbTarget->getAttr<ATTR_SCOM_SWITCHES>();
    l_switches.useInbandScom = 0;
    l_switches.useI2cScom = 1;

    // Modify attribute
    i_ocmbTarget->setAttr<ATTR_SCOM_SWITCHES>(l_switches);
    mutex_unlock(l_mutex);
}

/*******************************************************************************
 *
 * @brief Determine if we are on sub-channel A (OMI-0) or not.
 *
 * @param[in] Which OCMB target to query
 *
 * @return True if the OCMB target is on sub-channel A (OMI-0).  False
 *         Otherwise.
 *
 */
bool isSubChannelA(const TargetHandle_t i_ocmbTarget)
{
    const auto l_parentOMI = getImmediateParentByAffinity(i_ocmbTarget);
    return (l_parentOMI->getAttr<ATTR_REL_POS>() == 0);
}

/*******************************************************************************
 *
 * @brief Adds default callouts to error log for when further isolation
 *        cannot be performed.
 *
 * @param[in] Error log to add callouts to.
 * @param[in] OCMB target to callout
 *
 */
void addDefaultCallouts(errlHndl_t i_err,
                        const TargetHandle_t i_ocmbTarget)
{
    // Add OCMB as high priority
    i_err->addHwCallout(i_ocmbTarget,
                        HWAS::SRCI_PRIORITY_HIGH,
                        HWAS::DECONFIG,
                        HWAS::GARD_NULL);

    // Add OMI bus
    i_err->addHwCallout(getImmediateParentByAffinity(i_ocmbTarget),
                        HWAS::SRCI_PRIORITY_MED,
                        HWAS::DECONFIG,
                        HWAS::GARD_NULL);

    // Add code as low priority callout
    i_err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                               HWAS::SRCI_PRIORITY_LOW);
}

/*******************************************************************************
 *
 * @brief Determine if the OCMB detected a failure on a specific MMIO
 *        transaction to the specified OCMB target.
 *
 * @param[in] i_ocmbTarget Handle for the target OCMB chip.
 * @param[in] i_va Virtual address of the transaction to check
 * @param[in] i_accessLimit The byte range of the transaction
 * @param[in] i_offset The offset from the base address of the OCMB chip
 * @param[in] i_opType The operation type (read or write)
 * @param[out] o_errorAddressMatches Set to true if the OCMB chip detected a
 *             failure on our transaction.
 * @param[out] o_errorAddressIsZero Set to true if no error has been detected
 *             yet.
 * @return nullptr on succesful read of OCMB error status, non-null otherwise.
 *
 */
errlHndl_t checkOcmbError(const TargetHandle_t i_ocmbTarget,
                          const uint64_t i_va,
                          const uint64_t i_accessLimit,
                          const uint64_t i_offset,
                          DeviceFW::OperationType i_opType,
                          bool& o_errorAddressMatches,
                          bool& o_errorAddressIsZero)
{
    errlHndl_t l_err = nullptr;
    const auto l_ocmbChipId = i_ocmbTarget->getAttr<TARGETING::ATTR_CHIP_ID>();
    switch(l_ocmbChipId)
    {
        case POWER_CHIPID::EXPLORER_16:
        case POWER_CHIPID::GEMINI_16:
            l_err = MMIOEXP::checkExpError(i_ocmbTarget,
                                           i_va,
                                           i_accessLimit,
                                           i_offset,
                                           i_opType,
                                           o_errorAddressMatches,
                                           o_errorAddressIsZero);
            break;

        default:
            // Should never get here, but just in case...
            TRACFCOMP(g_trac_mmio, ERR_MRK
              "checkOcmbError: Unsupported chip ID[0x%08x] on OCMB[0x%08x]",
               l_ocmbChipId, get_huid(i_ocmbTarget));
            /*@
             * @errortype
             * @moduleid         MMIO::MOD_CHECK_OCMB_ERROR
             * @reasoncode       MMIO::RC_UNSUPPORTED_CHIPID
             * @userdata1        OCMB HUID
             * @userdata2        OCMB chip ID
             * @devdesc          A MMIO operation was attempted
             *                   on an unsupported OCMB chip.
             * @custdesc         Unexpected memory subsystem firmware error.
             */
            l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    MMIO::MOD_CHECK_OCMB_ERROR,
                                    MMIO::RC_UNSUPPORTED_CHIPID,
                                    get_huid(i_ocmbTarget),
                                    l_ocmbChipId,
                                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;
    }
    return l_err;
}

/*******************************************************************************
 *
 * @brief Collect additional failure data from the target OCMB chip and add
 *        appropriate FRU/Procedure callouts.
 *
 * @note Must call checkOcmbError to determine that a transaction failed before
 *       calling this function.
 *
 * @param[in] i_ocmbTarget Handle of OCMB to collect extra FFDC from
 * @param[in] i_offset The offset of the transaction address
 *                     on the OCMB chip.
 * @param[in] i_opType The operation type (read or write)
 * @param[in] i_err The error log for adding callouts/FFDC
 *
 */
void determineCallouts(const TargetHandle_t i_ocmbTarget,
                       const uint64_t i_offset,
                       DeviceFW::OperationType i_opType,
                       errlHndl_t i_err)
{
    bool l_fwFailure = false;
    errlHndl_t l_err = nullptr;

    const auto l_ocmbChipId = i_ocmbTarget->getAttr<TARGETING::ATTR_CHIP_ID>();
    switch(l_ocmbChipId)
    {
        case POWER_CHIPID::EXPLORER_16:
        case POWER_CHIPID::GEMINI_16:
            l_err = MMIOEXP::determineExpCallouts(i_ocmbTarget,
                                                  i_offset,
                                                  i_opType,
                                                  i_err,
                                                  l_fwFailure);
            break;
        default:
            // Should never get here, but just in case...
            TRACFCOMP(g_trac_mmio, ERR_MRK
              "determineCallouts: Unsupported chip ID[0x%08x] on OCMB[0x%08x]",
               l_ocmbChipId, get_huid(i_ocmbTarget));
            /*@
             * @errortype
             * @moduleid         MMIO::MOD_DETERMINE_CALLOUTS
             * @reasoncode       MMIO::RC_UNSUPPORTED_CHIPID
             * @userdata1        OCMB HUID
             * @userdata2        OCMB chip ID
             * @devdesc          A MMIO operation was attempted
             *                   on an unsupported OCMB chip.
             * @custdesc         Unexpected memory subsystem firmware error.
             */
            l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    MMIO::MOD_DETERMINE_CALLOUTS,
                                    MMIO::RC_UNSUPPORTED_CHIPID,
                                    get_huid(i_ocmbTarget),
                                    l_ocmbChipId,
                                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;
    }
    if(l_err)
    {
        TRACFCOMP(g_trac_mmio,
                  "determineCallouts: Couldn't isolate failure on"
                  " OCMB[0x%08x]",
                  get_huid(i_ocmbTarget));

        // This error is secondary to the actual error.  Log as informational
        // and add default callouts
        l_err->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
        l_err->plid(i_err->plid());
        ERRORLOG::errlCommit(l_err, MMIO_COMP_ID);
        addDefaultCallouts(i_err, i_ocmbTarget);
    }
    else
    {
        if(l_fwFailure)
        {
            TRACFCOMP(g_trac_mmio,
                      "determineCallouts: firmware error detected on"
                      " OCMB[0x%08x]",
                      get_huid(i_ocmbTarget));

            // Add HB code as high priority callout
            i_err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                       HWAS::SRCI_PRIORITY_HIGH);
        }
        else
        {
            TRACFCOMP(g_trac_mmio,
                      "determineCallouts: hardware error detected on"
                      " OCMB[0x%08x]",
                      get_huid(i_ocmbTarget));

            // Add OCMB as high priority callout
            i_err->addHwCallout(i_ocmbTarget,
                                HWAS::SRCI_PRIORITY_HIGH,
                                HWAS::DECONFIG,
                                HWAS::GARD_NULL);
        }
    }
}

/*******************************************************************************
 *
 * @brief Checks for a channel failure
 *
 * @param[in] i_ocmbTarget The OCMB to check for a channel failure
 * @param[out] o_checkstopExists true if channel failed, false otherwise.
 *
 * @return nullptr if we were able to read the status. Non-nullptr if there
 *         was a SCOM failure in reading status.
 */
errlHndl_t checkChannelCheckstop(const TargetHandle_t i_ocmbTarget,
                                 bool& o_checkstopExists)
{
    bool       l_checkstopExists = false;
    uint64_t   l_scom_data = 0;
    uint64_t   l_scom_mask = 0;

    auto l_err = getProcScom(i_ocmbTarget,
                             P9A_MCC_DSTLFIR,
                             l_scom_data);
    if (l_err)
    {
        TRACFCOMP(g_trac_mmio, ERR_MRK
                 "checkChannelCheckstop: getscom(P9A_MCC_DSTLFIR) failed"
                 " on OCMB[0x%08x]", get_huid(i_ocmbTarget));
    }
    else
    {
        // Check for channel checkstop on our sub-channel
        l_scom_mask = (isSubChannelA(i_ocmbTarget))?
             (1ull << P9A_MC_DSTLFIR_SUBCHANNEL_A_FAIL_ACTION):
             (1ull << P9A_MC_DSTLFIR_SUBCHANNEL_B_FAIL_ACTION);
        if (l_scom_data & l_scom_mask)
        {
            // A channel checkstop has occurred. (our bus is down)
            TRACFCOMP(g_trac_mmio, ERR_MRK
                 "checkChannelCheckstop: there was a channel checkstop on"
                 " OCMB[0x%08x], P9A_MCC_DSTLFIR=0x%llX",
                 get_huid(i_ocmbTarget), l_scom_data);
            l_checkstopExists = true;

        }
    }
    o_checkstopExists = l_checkstopExists;
    return l_err;
}

/*******************************************************************************
 *
 * @brief Validates input parameters and state for an OCMB MMIO operation
 *
 * @param[in] i_opType Operation type, see DeviceFW::OperationType
 *                     in driverif.H
 * @param[in] i_ocmbTarget inband scom target
 * @param[in] i_buffer pointer to read/write buffer
 * @param[in] i_buflen size of i_buffer (in bytes)
 * @param[in] i_addr The base virtual address of the the OCMB MMIO space
 * @param[in] i_offset The offset of the config reg, scom reg, MSCC reg or
 *                     SRAM to be accessed.
 * @param[in/out] io_accessLimit The number of bytes to read/write per MMIO
 *                          transaction.  Will be set to i_buflen if
 *                          io_accessLimit is zero.
 *
 * @return nullptr on success, failure otherwise.
 */
errlHndl_t validateOcmbMmioOp(DeviceFW::OperationType   i_opType,
                             const TargetHandle_t i_ocmbTarget,
                             void*   i_buffer,
                             size_t  i_buflen,
                             const uint64_t i_addr,
                             const uint64_t i_offset,
                             uint64_t& io_accessLimit)
{
    errlHndl_t l_err         = nullptr;

    do
    {
        // Check that this is a supported OCMB chip
        const auto l_ocmbChipId =
                        i_ocmbTarget->getAttr<TARGETING::ATTR_CHIP_ID>();
        switch(l_ocmbChipId)
        {
            case POWER_CHIPID::EXPLORER_16:
            case POWER_CHIPID::GEMINI_16:
                break;
            default:
                TRACFCOMP(g_trac_mmio, ERR_MRK
                   "validateOcmbMmioOp: Unsupported chip ID[0x%08x] "
                   "on OCMB[0x%08x]",
                   l_ocmbChipId, get_huid(i_ocmbTarget));
            /*@
             * @errortype
             * @moduleid         MMIO::MOD_VALIDATE_OCMB_MMIO_OP
             * @reasoncode       MMIO::RC_UNSUPPORTED_CHIPID
             * @userdata1        OCMB HUID
             * @userdata2        OCMB chip ID
             * @devdesc          A MMIO operation was attempted
             *                   on an unsupported OCMB chip.
             * @custdesc         Unexpected memory subsystem firmware error.
             */
            l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    MMIO::MOD_VALIDATE_OCMB_MMIO_OP,
                                    MMIO::RC_UNSUPPORTED_CHIPID,
                                    get_huid(i_ocmbTarget),
                                    l_ocmbChipId,
                                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;
        }
        if(l_err)
        {
            break;
        }

        if (i_addr == 0)
        {
            TRACFCOMP(g_trac_mmio, ERR_MRK
                          "validateOcmbMmioOp: MMIO has not been initialized!");

            /*@
             * @errortype
             * @moduleid         MMIO::MOD_VALIDATE_OCMB_MMIO_OP
             * @reasoncode       MMIO::RC_INVALID_SETUP
             * @userdata1[0:31]  Target huid
             * @userdata1[32:63] Data Offset, if >= 4GB then subtract 2GB
             *                   (allows offsets to fit in 32 bits)
             * @userdata2[0:0]   Operation Type
             * @userdata2[28:31] Access Limit
             * @userdata2[32:63] Buffer Length
             * @devdesc          A MMIO operation was attempted
             *                   before MMIO was initialized.
             * @custdesc         Unexpected memory subsystem firmware error.
             */
            l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    MMIO::MOD_VALIDATE_OCMB_MMIO_OP,
                                    MMIO::RC_INVALID_SETUP,
                                    TWO_UINT32_TO_UINT64(
                                      get_huid(i_ocmbTarget),
                                      (i_offset < (4 * GIGABYTE)) ?
                                                   (i_offset) :
                                                   (i_offset - (2 * GIGABYTE))),
                                    TWO_UINT32_TO_UINT64(
                                      (i_opType << 31) | io_accessLimit,
                                      i_buflen),
                                      ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            break;
        }

        if (i_buffer == nullptr)
        {
            TRACFCOMP(g_trac_mmio, ERR_MRK
                                   "validateOcmbMmioOp: buffer is invalid!");

            /*@
             * @errortype
             * @moduleid         MMIO::MOD_VALIDATE_OCMB_MMIO_OP
             * @reasoncode       MMIO::RC_INVALID_BUFFER
             * @userdata1[0:31]  Target huid
             * @userdata1[32:63] Data Offset, if >= 4GB then subtract 2GB
             *                   (allows offsets to fit in 32 bits)
             * @userdata2[0:0]   Operation Type
             * @userdata2[28:31] Access Limit
             * @userdata2[32:63] Buffer Length
             * @devdesc          Invalid data buffer for a MMIO
             *                   operation.
             * @custdesc         Unexpected memory subsystem firmware error.
             */
            l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    MMIO::MOD_VALIDATE_OCMB_MMIO_OP,
                                    MMIO::RC_INVALID_BUFFER,
                                    TWO_UINT32_TO_UINT64(
                                      get_huid(i_ocmbTarget),
                                      (i_offset < (4 * GIGABYTE)) ?
                                                   (i_offset) :
                                                   (i_offset - (2 * GIGABYTE))),
                                    TWO_UINT32_TO_UINT64(
                                      (i_opType << 31) | io_accessLimit,
                                      i_buflen),
                                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            break;
        }

        switch (io_accessLimit) {
            case 0:
                io_accessLimit = i_buflen; // no access size restriction
            case 4:
            case 8:
                break; // expected values
            default:
                TRACFCOMP(g_trac_mmio, ERR_MRK
                  "validateOcmbMmioOp: accessLimit(%ld) should be 0, 4 or 8!!!",
                   io_accessLimit);

                /*@
                 * @errortype
                 * @moduleid         MMIO::MOD_VALIDATE_OCMB_MMIO_OP
                 * @reasoncode       MMIO::RC_INVALID_ACCESS_LIMIT
                 * @userdata1[0:31]  Target huid
                 * @userdata1[32:63] Data Offset, if >= 4GB then subtract 2GB
                 *                   (allows offsets to fit in 32 bits)
                 * @userdata2[0:0]   Operation Type
                 * @userdata2[28:31] Access Limit
                 * @userdata2[32:63] Buffer Length
                 * @devdesc          Specified access limit was
                 *                   invalid for a MMIO operation.
                 * @custdesc         Unexpected memory subsystem firmware error.
                 */
                l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    MMIO::MOD_VALIDATE_OCMB_MMIO_OP,
                                    MMIO::RC_INVALID_ACCESS_LIMIT,
                                    TWO_UINT32_TO_UINT64(
                                      get_huid(i_ocmbTarget),
                                      (i_offset < (4 * GIGABYTE)) ?
                                                   (i_offset) :
                                                   (i_offset - (2 * GIGABYTE))),
                                    TWO_UINT32_TO_UINT64(
                                      (i_opType << 31) | io_accessLimit,
                                      i_buflen),
                                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                break;
        }

        if (l_err)
        {
            break;
        }

        if (i_buflen < io_accessLimit)
        {
            TRACFCOMP(g_trac_mmio, ERR_MRK
                           "validateOcmbMmioOp: buffer is too small for the"
                           " request, buflen=%d, accessLimit=%ld",
                           i_buflen, io_accessLimit);

            /*@
             * @errortype
             * @moduleid         MMIO::MOD_VALIDATE_OCMB_MMIO_OP
             * @reasoncode       MMIO::RC_INSUFFICIENT_BUFFER
             * @userdata1[0:31]  Target huid
             * @userdata1[32:63] Data Offset, if >= 4GB then subtract 2GB
             *                   (allows offsets to fit in 32 bits)
             * @userdata2[0:0]   Operation Type
             * @userdata2[28:31] Access Limit
             * @userdata2[32:63] Buffer Length
             * @devdesc          Data buffer too small for a
             *                   MMIO operation.
             * @custdesc         Unexpected memory subsystem firmware error.
             */
            l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    MMIO::MOD_VALIDATE_OCMB_MMIO_OP,
                                    MMIO::RC_INSUFFICIENT_BUFFER,
                                    TWO_UINT32_TO_UINT64(
                                      get_huid(i_ocmbTarget),
                                      (i_offset < (4 * GIGABYTE)) ?
                                                   (i_offset) :
                                                   (i_offset - (2 * GIGABYTE))),
                                    TWO_UINT32_TO_UINT64(
                                      (i_opType << 31) | io_accessLimit,
                                      i_buflen),
                                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            break;
        }

        if (i_buflen % io_accessLimit)
        {
            TRACFCOMP(g_trac_mmio, ERR_MRK
                                   "validateOcmbMmioOp: buffer length must be a"
                                   " multiple of the access limit,"
                                   " buflen=%d, accessLimit=%ld",
                                   i_buflen, io_accessLimit);

            /*@
             * @errortype
             * @moduleid         MMIO::MOD_VALIDATE_OCMB_MMIO_OP
             * @reasoncode       MMIO::RC_INCORRECT_BUFFER_LENGTH
             * @userdata1[0:31]  Target huid
             * @userdata1[32:63] Data Offset, if >= 4GB then subtract 2GB
             *                   (allows offsets to fit in 32 bits)
             * @userdata2[0:0]   Operation Type
             * @userdata2[28:31] Access Limit
             * @userdata2[32:63] Buffer Length
             * @devdesc          Buffer length not a multiple of access limit.
             * @custdesc         Unexpected memory subsystem firmware error.
             */
            l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    MMIO::MOD_VALIDATE_OCMB_MMIO_OP,
                                    MMIO::RC_INCORRECT_BUFFER_LENGTH,
                                    TWO_UINT32_TO_UINT64(
                                      get_huid(i_ocmbTarget),
                                      (i_offset < (4 * GIGABYTE)) ?
                                                   (i_offset) :
                                                   (i_offset - (2 * GIGABYTE))),
                                    TWO_UINT32_TO_UINT64(
                                      (i_opType << 31) | io_accessLimit,
                                      i_buflen),
                                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            break;
        }

        if (!(((i_offset >= 0) && (i_offset < (2 * GIGABYTE))) ||
              ((i_offset >= (4 * GIGABYTE)) && (i_offset < (6 * GIGABYTE)))))
        {
            TRACFCOMP(g_trac_mmio, ERR_MRK
                                   "validateOcmbMmioOp: offset(0x%lX) must be"
                                   " either 0-2G or 4G-6G!",
                                   i_offset);

            /*@
             * @errortype
             * @moduleid         MMIO::MOD_VALIDATE_OCMB_MMIO_OP
             * @reasoncode       MMIO::RC_INVALID_OFFSET
             * @userdata1[0:31]  Target huid
             * @userdata1[32:63] Data Offset, if >= 4GB then subtract 2GB
             *                   (allows offsets to fit in 32 bits)
             * @userdata2[0:0]   Operation Type
             * @userdata2[28:31] Access Limit
             * @userdata2[32:63] Buffer Length
             * @devdesc          Invalid offset, requested
             *                   address was out of range for a MMIO operation.
             * @custdesc         Unexpected memory subsystem firmware error.
             */
            l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    MMIO::MOD_VALIDATE_OCMB_MMIO_OP,
                                    MMIO::RC_INVALID_OFFSET,
                                    TWO_UINT32_TO_UINT64(
                                      get_huid(i_ocmbTarget),
                                      (i_offset < (4 * GIGABYTE)) ?
                                                   (i_offset) :
                                                   (i_offset - (2 * GIGABYTE))),
                                    TWO_UINT32_TO_UINT64(
                                      (i_opType << 31) | io_accessLimit,
                                      i_buflen),
                                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            break;
        }

        if ( ((io_accessLimit == 4) || (io_accessLimit == 8)) &&
             ((i_offset % io_accessLimit) != 0) )
        {
            TRACFCOMP(g_trac_mmio, ERR_MRK
                 "validateOcmbMmioOp: offset must be aligned with access limit,"
                 " offset=0x%lX, accessLimit=%ld",
                 i_offset, io_accessLimit);

            /*@
             * @errortype
             * @moduleid         MMIO::MOD_VALIDATE_OCMB_MMIO_OP
             * @reasoncode       MMIO::RC_INVALID_OFFSET_ALIGNMENT
             * @userdata1[0:31]  Target huid
             * @userdata1[32:63] Data Offset, if >= 4GB then subtract 2GB
             *                   (allows offsets to fit in 32 bits)
             * @userdata2[0:0]   Operation Type
             * @userdata2[28:31] Access Limit
             * @userdata2[32:63] Buffer Length
             * @devdesc          Requested MMIO address was not
             *                   aligned properly for the associated device.
             * @custdesc         Unexpected memory subsystem firmware error.
             */
            l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    MMIO::MOD_VALIDATE_OCMB_MMIO_OP,
                                    MMIO::RC_INVALID_OFFSET_ALIGNMENT,
                                    TWO_UINT32_TO_UINT64(
                                      get_huid(i_ocmbTarget),
                                      (i_offset < (4 * GIGABYTE)) ?
                                                   (i_offset) :
                                                   (i_offset - (2 * GIGABYTE))),
                                    TWO_UINT32_TO_UINT64(
                                      (i_opType << 31) | io_accessLimit,
                                      i_buflen),
                                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            break;
        }
    }while(0);
    return l_err;
}


/*******************************************************************************
 *
 * See comments in header file
 *
 */
errlHndl_t ocmbMmioPerformOp(DeviceFW::OperationType i_opType,
                             TargetHandle_t i_ocmbTarget,
                             void*   io_buffer,
                             size_t& io_buflen,
                             int64_t i_accessType,
                             va_list i_args)
{
    errlHndl_t l_err         = nullptr;
    uint64_t   l_offset      = va_arg(i_args, uint64_t);
    uint64_t   l_accessLimit = va_arg(i_args, uint64_t);
    bool invalidParmError = false;

    TRACDCOMP(g_trac_mmio, ENTER_MRK"ocmbMmioPerformOp");
    TRACDCOMP(g_trac_mmio, INFO_MRK"op=%d, target=0x%.8X",
              i_opType, get_huid(i_ocmbTarget));
    TRACDCOMP(g_trac_mmio, INFO_MRK"buffer=%p, length=%d, accessType=%ld",
              io_buffer, io_buflen, i_accessType);
    TRACDCOMP(g_trac_mmio, INFO_MRK"offset=0x%lX, accessLimit=%ld",
              l_offset, l_accessLimit);

    do
    {
        uint64_t   l_addr = i_ocmbTarget->getAttr<ATTR_MMIO_VM_ADDR>();

        TRACDCOMP(g_trac_mmio, INFO_MRK"MMIO Op l_addr=0x%lX ", l_addr);

        // Validate parameters for MMIO operation
        l_err = validateOcmbMmioOp(i_opType,
                                   i_ocmbTarget,
                                   io_buffer,
                                   io_buflen,
                                   l_addr,
                                   l_offset,
                                   l_accessLimit);
        if(l_err)
        {
            invalidParmError = true;
            break;
        }

        // read or write io_buflen bytes, l_accessLimit bytes at a time
        uint8_t* l_mmPtr = reinterpret_cast<uint8_t *>(l_addr + l_offset);
        uint8_t* l_ioPtr = reinterpret_cast<uint8_t *>(io_buffer);
        size_t   l_bytesCopied = 0;
        for (;l_bytesCopied < io_buflen; l_bytesCopied += l_accessLimit)
        {
            if (i_opType == DeviceFW::READ)
            {
                // Perform requested MMIO read
                mmio_memcpy(l_ioPtr + l_bytesCopied,
                            l_mmPtr + l_bytesCopied,
                            l_accessLimit);
                eieio();

                // If there was a UE detected by the processor, a Load UE
                // exception will be raised.  Kernel code will detect
                // that the exception occurred during an OCMB read and
                // will write a unique pattern, MMIO_OCMB_UE_DETECTED, into
                // the read buffer so that we can quickly know that the MMIO
                // read failed.
                if (memcmp(l_ioPtr + l_bytesCopied,
                            &MMIO_OCMB_UE_DETECTED,
                            sizeof(MMIO_OCMB_UE_DETECTED)))
                {
                    //No read failure detected.  Keep going.
                    continue;
                }

                //MMIO Read failed!
                TRACFCOMP(g_trac_mmio, ERR_MRK
                                 "ocmbMmioPerformOp: unable to complete"
                                 " MMIO read of offset 0x%08x from OCMB 0x%08x",
                                 l_offset, get_huid(i_ocmbTarget));

                // Check for channel checkstops (this reads a processor reg)
                bool l_checkstopExists = false;
                l_err = checkChannelCheckstop(i_ocmbTarget, l_checkstopExists);
                if(l_err)
                {
                    // Couldn't deterimine if checkstop exists.
                    break;
                }

                if(l_checkstopExists)
                {
                    /*@
                     * @errortype
                     * @moduleid         MMIO::MOD_MMIO_PERFORM_OP
                     * @reasoncode       MMIO::RC_MMIO_CHAN_CHECKSTOP
                     * @userdata1[0:31]  Target huid
                     * @userdata1[32:63] Data Offset, if >= 4GB then subtract
                     *                   2GB (allows offsets to fit in 32 bits)
                     * @userdata2[0:0]   Operation Type
                     * @userdata2[28:31] Access Limit
                     * @userdata2[32:63] Buffer Length
                     * @devdesc          OCMB MMIO read failed due to
                     *                   channel checkstop
                     * @custdesc         Unexpected memory subsystem error.
                     */
                    l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    MMIO::MOD_MMIO_CHAN_CHECKSTOP,
                                    MMIO::RC_BAD_MMIO_READ,
                                    TWO_UINT32_TO_UINT64(
                                      get_huid(i_ocmbTarget),
                                      (l_offset < (4 * GIGABYTE)) ?
                                                   (l_offset) :
                                                   (l_offset - (2 * GIGABYTE))),
                                    TWO_UINT32_TO_UINT64(
                                      (i_opType << 31) | l_accessLimit,
                                      io_buflen),
                                    ERRORLOG::ErrlEntry::NO_SW_CALLOUT);

                    addDefaultCallouts(l_err, i_ocmbTarget);

                    // Switch to I2C to allow collection of registers on
                    // OCMB.
                    disableInbandScomsOcmb(i_ocmbTarget);

                    // TODO RTC 201778 - Channel fail handling for Explorer
                    // dump some registers to the error log here?

                    // Look for a better PRD error
                    //
                    // TODO RTC 92971
                    // There is a potential deadlock if we call PRD here since
                    // we could recursively call PRD and they are locking a
                    // mutex.  Skip this call for now.
                    //
                    //errlHndl_t l_prd_err = ATTN::checkForIplAttentions();
                    errlHndl_t l_prd_err = NULL;
                    if(l_prd_err)
                    {
                        TRACFCOMP(g_trac_mmio,
                                  ERR_MRK"Error from checkForIplAttentions: "
                                  "PLID=%X",
                                  l_prd_err->plid());

                        //connect up the plids
                        l_err->plid(l_prd_err->plid());

                        //commit my log as info because PRD's log is better
                        l_err->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                        ERRORLOG::errlCommit(l_err, MMIO_COMP_ID);
                        l_err = l_prd_err;
                    }

                    break;
                }

                /*@
                 * @errortype
                 * @moduleid         MMIO::MOD_MMIO_PERFORM_OP
                 * @reasoncode       MMIO::RC_BAD_MMIO_READ
                 * @userdata1[0:31]  Target huid
                 * @userdata1[32:63] Data Offset, if >= 4GB then subtract
                 *                   2GB (allows offsets to fit in 32 bits)
                 * @userdata2[0:0]   Operation Type
                 * @userdata2[28:31] Access Limit
                 * @userdata2[32:63] Buffer Length
                 * @devdesc          OCMB MMIO read failed
                 * @custdesc         Unexpected memory subsystem firmware
                 *                   error.
                 */
                l_err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                MMIO::MOD_MMIO_PERFORM_OP,
                                MMIO::RC_BAD_MMIO_READ,
                                TWO_UINT32_TO_UINT64(
                                  get_huid(i_ocmbTarget),
                                  (l_offset < (4 * GIGABYTE)) ?
                                               (l_offset) :
                                               (l_offset - (2 * GIGABYTE))),
                                TWO_UINT32_TO_UINT64(
                                  (i_opType << 31) | l_accessLimit,
                                  io_buflen),
                                ERRORLOG::ErrlEntry::NO_SW_CALLOUT);

                // NOTE: Explorer error regs cannot be cleared without resetting
                //       the chip.  Error regs may contain failure data from
                //       previous write transaction.
                //
                // Check if OCMB has failure data for this transaction.
                bool l_errorAddressMatches = false;
                bool l_errorAddressIsZero = false;
                auto l_err2 = checkOcmbError(
                             i_ocmbTarget,
                             reinterpret_cast<uint64_t>(l_mmPtr +
                                                        l_bytesCopied),
                             l_accessLimit,
                             l_offset,
                             i_opType,
                             l_errorAddressMatches,
                             l_errorAddressIsZero);
                if (l_err2)
                {
                    // Failed to read ocmb status register after
                    // we just determined that there was not
                    // a channel checkstop?  Commit this error
                    // as informational and add default callouts
                    // to l_err.
                    l_err2->plid(l_err->plid());
                    ERRORLOG::errlCommit(l_err2, MMIO_COMP_ID);
                    addDefaultCallouts(l_err, i_ocmbTarget);
                    break;
                }
                else if(l_errorAddressMatches)
                {
                    // Read additional OCMB regs to determine if this was
                    // a HW or SW error.
                    determineCallouts(i_ocmbTarget, l_offset, i_opType, l_err);
                    break;
                }
                else if(l_errorAddressIsZero)
                {
                    // P9A disagrees with OCMB?
                    TRACFCOMP(g_trac_mmio,
                        "ocmbMmioPerformOp(read): No Error found on OCMB??"
                        " 0x%08x", get_huid(i_ocmbTarget));
                    addDefaultCallouts(l_err, i_ocmbTarget);
                    break;
                }

                // Address does not match ours and is not zero.
                // This was probably caused by an MMIO write failure
                // doing an MMIO read to detect if the MMIO write
                // was successful or not.
                TRACFCOMP(g_trac_mmio,
                    "ocmbMmioPerformOp(read): Previous error detected on"
                    " OCMB 0x%08x", get_huid(i_ocmbTarget));
                break;
            }
            else // i_opType == DeviceFW::WRITE
            {
                // Perform the MMIO write
                mmio_memcpy(l_mmPtr + l_bytesCopied,
                            l_ioPtr + l_bytesCopied,
                            l_accessLimit);
                eieio();

                // MMIO write failures will not cause an exception
                // to be raised on the host processor.  Instead, code
                // needs to check a register on the OCMB to determine
                // if a specific write failed.
                bool l_errorAddressMatches = false;
                bool l_errorAddressIsZero = false;
                l_err = checkOcmbError(
                             i_ocmbTarget,
                             reinterpret_cast<uint64_t>(l_mmPtr +
                                                        l_bytesCopied),
                             l_accessLimit,
                             l_offset,
                             i_opType,
                             l_errorAddressMatches,
                             l_errorAddressIsZero);

                // Check that we were able to read the error register
                // and that it doesn't contain our address.
                if(!l_err && !l_errorAddressMatches)
                {
                    // No errors detected. Keep going.
                    continue;
                }

                // At this point, we know that the write or status read failed.
                // Go ahead and create a basic MMIO Write error log.
                TRACFCOMP(g_trac_mmio, ERR_MRK
                                 "ocmbMmioPerformOp: unable to complete"
                                 " MMIO write to offset 0x%08x on OCMB 0x%08x",
                                 l_offset, get_huid(i_ocmbTarget));

                /*@
                 * @errortype
                 * @moduleid         MMIO::MOD_MMIO_PERFORM_OP
                 * @reasoncode       MMIO::RC_BAD_MMIO_WRITE
                 * @userdata1[0:31]  Target huid
                 * @userdata1[32:63] Data Offset, if >= 4GB then subtract
                 *                   2GB (allows offsets to fit in 32 bits)
                 * @userdata2[0:0]   Operation Type
                 * @userdata2[28:31] Access Limit
                 * @userdata2[32:63] Buffer Length
                 * @devdesc          OCMB MMIO write failed
                 * @custdesc         Unexpected memory subsystem firmware
                 *                   error.
                 */
                auto l_writeErr = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            MMIO::MOD_MMIO_PERFORM_OP,
                            MMIO::RC_BAD_MMIO_WRITE,
                            TWO_UINT32_TO_UINT64(
                              get_huid(i_ocmbTarget),
                              (l_offset < (4 * GIGABYTE)) ?
                                           (l_offset) :
                                           (l_offset - (2 * GIGABYTE))),
                            TWO_UINT32_TO_UINT64(
                              (i_opType << 31) | l_accessLimit,
                              io_buflen),
                            ERRORLOG::ErrlEntry::NO_SW_CALLOUT);

                // Check if the register read failed
                if(l_err)
                {
                    // We were not able to read the error register on the
                    // OCMB.  The most likely scenario here is that there
                    // was a HW failure (possibly a channel checkstop).
                    //
                    // NOTE: If we only logged this error as-is and no
                    // other error, we wouldn't know that the read was
                    // a result of a write. Instead, log both errors
                    // and set the PLID's to be the same.
                    TRACFCOMP(g_trac_mmio,
                        "ocmbMmioPerformOp(write): Fail to read status on"
                        " OCMB 0x%08x", get_huid(i_ocmbTarget));
                    l_writeErr->plid(l_err->plid());

                    // Set severity of write error to match the read
                    // error if there is a channel checkstop.
                    bool l_checkstopExists = false;
                    errlHndl_t l_xstopErr = nullptr;
                    l_xstopErr = checkChannelCheckstop(i_ocmbTarget,
                                                       l_checkstopExists);
                    if(l_xstopErr)
                    {
                        // Couldn't deterimine if checkstop exists.
                        // Commit the xstop error and assume no checkstop.
                        l_xstopErr->collectTrace(MMIO_COMP_NAME);
                        ERRORLOG::errlCommit(l_xstopErr, MMIO_COMP_ID);
                    }
                    if(l_checkstopExists)
                    {
                        l_writeErr->setSev(l_err->sev());
                    }
                    ERRORLOG::errlCommit(l_err, MMIO_COMP_ID);
                    l_err = l_writeErr;
                    break;
                }

                l_err = l_writeErr;
                l_writeErr = nullptr;

                // At this point, we were able to read the error register
                // and determined that it matched the address of our
                // transaction.  No need to check for a channel checkstop
                // on the write operation since we already did that in the
                // read path when we tried to read the OCMB status register.

                // Read additional OCMB regs to determine if this was
                // a HW or SW error.
                determineCallouts(i_ocmbTarget, l_offset, i_opType, l_err);
                break;
            } // end of write block

        } // end of for loop

        io_buflen = l_bytesCopied;
    } while(0);

    if (l_err)
    {
        // Only disable if HW error, not for user parameter failures
        if (!invalidParmError)
        {
            // Switch over to using I2C to prevent further MMIO access
            // to this OCMB (error regs cannot be cleared on Explorer).
            disableInbandScomsOcmb(i_ocmbTarget);
        }

        l_err->collectTrace(MMIO_COMP_NAME);
    }

    TRACDCOMP(g_trac_mmio, EXIT_MRK"ocmbMmioPerformOp");

    return l_err;
}

/*******************************************************************************
 *
 * @brief Finds the processor connected to the target OCMB chip.
 *
 */
static
TargetHandle_t getParentProc(
                                    const TargetHandle_t i_ocmbTarget)
{
    TargetHandle_t   proc = nullptr;
    TargetHandleList list;
    PredicateCTM     pred(CLASS_CHIP, TYPE_PROC);

    targetService().getAssociated( list,
                                   i_ocmbTarget,
                                   TargetService::PARENT_BY_AFFINITY,
                                   TargetService::ALL,
                                   &pred);

    if (list.size() == 1)
    {
        proc = list[0];
    }

    return proc;
}

/*******************************************************************************
 *
 * @brief Reads a scom register on the processor connected to the target OCMB
 *        chip.
 *
 */
static
errlHndl_t getProcScom(const TargetHandle_t i_ocmbTarget,
                       uint64_t i_scomAddr,
                       uint64_t &o_scomData)
{
    errlHndl_t l_err = nullptr;
    auto proc = getParentProc(i_ocmbTarget);

    if (proc == nullptr)
    {
        TRACFCOMP(g_trac_mmio, ERR_MRK
                "getProcScom: Unable to find parent processor for target(0x%X)",
                get_huid(i_ocmbTarget));

        /*@
         * @errortype
         * @moduleid    MMIO::MOD_MMIO_GET_PROC_SCOM
         * @reasoncode  MMIO::RC_PROC_NOT_FOUND
         * @userdata1   Target huid
         * @userdata2   SCOM address
         * @devdesc     Unable to find parent processor for target.
         * @custdesc    Unexpected memory subsystem firmware error.
         */
        l_err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                MMIO::MOD_MMIO_GET_PROC_SCOM,
                                MMIO::RC_PROC_NOT_FOUND,
                                get_huid(i_ocmbTarget),
                                i_scomAddr,
                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
    }
    else
    {
        auto reqSize = sizeof(o_scomData);

        l_err = DeviceFW::deviceRead(proc,
                                     &o_scomData,
                                     reqSize,
                                     DEVICE_SCOM_ADDRESS(i_scomAddr));
    }

    return l_err;
}

/*******************************************************************************
 *
 * @brief Writes a scom register on the processor connected to the target OCMB
 *        chip.
 *
 */
// NOTE: removed static qualifier to prevent compiler from complaining about
//       the function not being used.
errlHndl_t setProcScom(const TargetHandle_t i_ocmbTarget,
                       uint64_t i_scomAddr,
                       uint64_t i_scomData)
{
    errlHndl_t l_err = nullptr;
    auto proc = getParentProc(i_ocmbTarget);

    if (proc == nullptr)
    {
        TRACFCOMP(g_trac_mmio, ERR_MRK
                "setProcScom: Unable to find parent processor for target(0x%X)",
                get_huid(i_ocmbTarget));

        /*@
         * @errortype
         * @moduleid    MMIO::MOD_MMIO_SET_PROC_SCOM
         * @reasoncode  MMIO::RC_PROC_NOT_FOUND
         * @userdata1   Target huid
         * @userdata2   SCOM address
         * @devdesc     Unable to find parent processor for target.
         * @custdesc    Unexpected memory subsystem firmware error.
         */
        l_err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                MMIO::MOD_MMIO_SET_PROC_SCOM,
                                MMIO::RC_PROC_NOT_FOUND,
                                get_huid(i_ocmbTarget),
                                i_scomAddr,
                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
    }
    else
    {
        auto reqSize = sizeof(i_scomData);

        l_err = DeviceFW::deviceWrite(proc,
                                      &i_scomData,
                                      reqSize,
                                      DEVICE_SCOM_ADDRESS(i_scomAddr));
    }

    return l_err;
}


/*******************************************************************************
 *
 * @brief Copies len bytes of data from location pointed to by vsrc to location
 *        pointed to by vdest.
 *
 */
static
void *mmio_memcpy(void *vdest, const void *vsrc, size_t len)
{
    assert((len % 4) == 0, "Length must be a multiple of 4!");
    assert((reinterpret_cast<uintptr_t>(vdest) % 4) == 0,
           "Destination must be 4 byte aligned!");

    // Loop, copying 8 bytes every 5 instructions
    long *ldest = reinterpret_cast<long *>(vdest);
    const long *lsrc = reinterpret_cast<const long *>(vsrc);

    while (len >= sizeof(long))
    {
        *ldest++ = *lsrc++;
        len -= sizeof(long);
    }

    // Loop, copying 4 bytes every 5 instructions
    int *idest = reinterpret_cast<int *>(ldest);
    const int *isrc = reinterpret_cast<const int *>(lsrc);

    while (len >= sizeof(int))
    {
        *idest++ = *isrc++;
        len -= sizeof(int);
    }

    return vdest;
}

}; // end namespace MMIO
