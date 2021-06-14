/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/hwasPlat.C $                                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
/* [+] Google Inc.                                                        */
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
 *  @file hwasPlat.C
 *
 *  @brief Platform specifics
 */

#include <hwas/common/hwas.H>
#include <hwas/common/hwasCommon.H>
#include <hwas/common/hwasCallout.H>
#include <hwas/common/deconfigGard.H>
#include <hwas/hwasPlat.H>

#include <devicefw/driverif.H>
#include <initservice/taskargs.H>
#include <initservice/mboxRegs.H>
#include <initservice/istepdispatcherif.H>
#include <vpd/mvpdenums.H>
#include <stdio.h>
#include <sys/mmio.h>
#include <sys/misc.h>
#include <arch/pvrformat.H>

#include <pnor/pnorif.H>
#include <fapiwrap/fapiWrapif.H>

#include <fapi2/plat_hwp_invoker.H>
#include <p10_determine_eco_mode.H>

#include <hwas/common/hwas_reasoncodes.H>
#include <targeting/common/utilFilter.H>
#include <fsi/fsiif.H>
#include <targeting/common/targetservice.H>
#include <chipids.H>
#include <vpd/spdenums.H>

#include <map>

#ifdef CONFIG_SUPPORT_EEPROM_CACHING
#include <eeprom/eepromif.H>
#endif

#include <vpd/vpd_if.H>
#include <initservice/initserviceif.H>
#include <util/misc.H>

namespace HWAS
{

class RegisterHWASFunctions
{
    public:
    RegisterHWASFunctions()
    {
        // HWAS is awake

        // register processCallout function for ErrlEntry::commit
        HWAS_DBG("module load: calling errlog::setHwasProcessCalloutFn");
        ERRORLOG::ErrlManager::setHwasProcessCalloutFn(
                    (processCalloutFn)(&processCallout));
    }
};
// this causes the function to get run at module load.
RegisterHWASFunctions registerHWASFunctions;

using   namespace   TARGETING;


//******************************************************************************
// platReadIDEC function
//******************************************************************************
errlHndl_t platReadIDEC(const TargetHandle_t &i_target)
{
    // Call over to the target-specific layer since every chip can have
    //  unique registers
    size_t sz = 0;
    errlHndl_t errl = nullptr;

    // Pass a 1 as va_arg to signal phase 1 of ocmbIDEC to execute.
    // Other IDEC functions will ignore this argument.
    const uint64_t Phase1 = 1;
    errl = DeviceFW::deviceWrite(i_target,
                                 nullptr,
                                 sz,
                                 DEVICE_IDEC_ADDRESS(),
                                 Phase1);


    return errl;
}

/**
 * @brief Read the chipid and EC/DD-level for standard CFAM chips and set
 *    the attributes.
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        Presence detect target
 * @param[in/out] io_buffer     Read: Pointer to output data storage
 *                              Write: Pointer to input data storage
 * @param[in/out] io_buflen     Input: size of io_buffer (bytes, must equal 1)
 *                              Output: Success = 1, Failure = 0
 * @param[in]   i_accessType    DeviceFW::AccessType enum (userif.H)
 * @param[in]   i_args          This is an argument list for DD framework.
 *                              In this function, there are no arguments.
 * @return  errlHndl_t
 */
errlHndl_t cfamIDEC(DeviceFW::OperationType i_opType,
                    TARGETING::Target* i_target,
                    void* io_buffer,
                    size_t& io_buflen,
                    int64_t i_accessType,
                    va_list i_args)
{
    // we got a target - read the ID/EC
    //  and update the appropriate ATTR_ field.
    uint64_t id_ec;
    size_t op_size = sizeof(id_ec);
    errlHndl_t errl = NULL;

    // At the time when we read IDEC, the tp chiplet of slave
    // processors are not yet enabled; therefore, we can not read IDEC
    // using SCOM path.  We must use FSI path to read the IDEC values.
    // For master proc, use scom
    // For everything else, use FSI(0x1028)
    Target* l_pMasterProcChip = NULL;
    targetService().masterProcChipTargetHandle(l_pMasterProcChip);

    if (i_target == l_pMasterProcChip)
    {
        errl = DeviceFW::deviceRead(i_target, &id_ec,
                                    op_size,
                                    DEVICE_SCOM_ADDRESS(0x000F000Full));
    }
    else
    {
        // FSI only reads 4 bytes for id_ec
        op_size = sizeof(uint32_t);

        errl = DeviceFW::deviceRead(i_target, &id_ec, op_size,
                                    DEVICE_FSI_ADDRESS(0x01028));
    }

    //Look for a totally dead chip
    if( (errl == NULL)
        && ((id_ec & 0xFFFFFFFF00000000) == 0xFFFFFFFF00000000) )
    {
        HWAS_ERR("All FFs for chipid read on %.8X",TARGETING::get_huid(i_target));
        /*@
         * @errortype
         * @moduleid     HWAS::MOD_PLAT_READIDEC
         * @reasoncode   HWAS::RC_BAD_CHIPID
         * @userdata1    Target HUID
         * @userdata2    <unused>
         * @devdesc      platReadIDEC> Invalid chipid from hardware (all FFs)
         * @custdesc     Invalid chipid from hardware (all FFs)
         */
        errl = new ERRORLOG::ErrlEntry(
                                       ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       HWAS::MOD_PLAT_READIDEC,
                                       HWAS::RC_BAD_CHIPID,
                                       TARGETING::get_huid(i_target),
                                       0);

        // if things are this broken then chances are there are bigger
        //  problems, we can just make some guesses on what to call out

        // make code the highest since there are other issues
        errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                  HWAS::SRCI_PRIORITY_HIGH);

        // callout this chip as Medium and deconfigure it
        errl->addHwCallout( i_target,
                            HWAS::SRCI_PRIORITY_LOW,
                            HWAS::DECONFIG,
                            HWAS::GARD_NULL );

        // Grab all the FFDC we can think of
        FSI::getFsiFFDC( FSI::FFDC_OPB_FAIL_SLAVE,
                         errl,
                         i_target );
        FSI::getFsiFFDC( FSI::FFDC_READWRITE_FAIL,
                         errl,
                         i_target );
        FSI::getFsiFFDC( FSI::FFDC_PIB_FAIL,
                         errl,
                         i_target );

    }

    if (errl == NULL)
    {   // no error, so we got a valid ID/EC value back
        // EC - nibbles 0,2
        //                        01234567
        uint8_t ec = (((id_ec & 0xF000000000000000ull) >> 56) |
                      ((id_ec & 0x00F0000000000000ull) >> 52));
        i_target->setAttr<ATTR_EC>(ec);

        // until we read ECID, HDAT_EC==EC
        i_target->setAttr<ATTR_HDAT_EC>(ec);

        // ID - nibbles 1,5,3,4
        //                         01234567
        uint32_t id = (((id_ec & 0x0F00000000000000ull) >> 44) |
                       ((id_ec & 0x00000F0000000000ull) >> 32) |
                       ((id_ec & 0x000F000000000000ull) >> 44) |
                       ((id_ec & 0x0000F00000000000ull) >> 44));
        i_target->setAttr<ATTR_CHIP_ID>(id);
        HWAS_DBG( "i_target %.8X - id %x ec %x",
            i_target->getAttr<ATTR_HUID>(), id, ec);
    }
    else
    {   // errl was set - this is an error condition.
        HWAS_ERR( "i_target %.8X - failed ID/EC read",
            i_target->getAttr<ATTR_HUID>());
    }

    return errl;
} // platReadIDEC

// Register the standard CFAM function for IDEC calls for processors
//  and memory buffers
DEVICE_REGISTER_ROUTE(DeviceFW::WRITE,
                      DeviceFW::IDEC,
                      TARGETING::TYPE_PROC,
                      cfamIDEC);
DEVICE_REGISTER_ROUTE(DeviceFW::WRITE,
                      DeviceFW::IDEC,
                      TARGETING::TYPE_MEMBUF,
                      cfamIDEC);

/**
 * @brief During early IPL the OCMB isn't able to be read from so this function,
 *        executed during discover targets, will read from the SPD and set the
 *        CHIP_ID, EC, and HDAT_EC attributes with what is found there.
 *
 * @param[in] i_target        Presence detect target
 *
 * @return  errlHndl_t        An error log if reading from the SPD failed.
 *                            Otherwise, other errors are predictive and
 *                            committed. So nullptr will be returned in those
 *                            cases and on success.
 */
errlHndl_t ocmbIdecPhase1(const TARGETING::TargetHandle_t& i_target);

/**
 * @brief Once the OCMB is able to be read from the second phase will execute
 *        and cross-check the data given from the SPD is consistent with what
 *        was read from the chip itself. If the data is not consistent then the
 *        CHIP_ID, EC, and HDAT_EC attributes will be updated with what was
 *        found from the OCMB read since that data would be correct.
 *
 * @param[in] i_target        Presence detect target
 *
 * @return  errlHndl_t        An error log if reading from the OCMB ID/EC
 *                            register failed. Otherwise, other errors are
 *                            predictive and committed. So nullptr will be
 *                            returned in those cases and on success.
 */
errlHndl_t ocmbIdecPhase2(const TARGETING::TargetHandle_t& i_target);

/**
 * @brief Read the chipid and EC/DD-level for OCMB chips and set the attributes.
 *        In this function there are two phases that are executed at different
 *        times during IPL. The OCMB is held in reset and unable to be read from
 *        during early IPL. So the first phase, executed during discover
 *        targets, will read from the SPD and set the attributes with what is
 *        found there. Once the OCMB is able to be read from the second phase
 *        will execute and cross-check the data given from the SPD is consistent
 *        with what was read from the chip itself. If the data is not consistent
 *        then the attributes will be updated with what was found from the OCMB
 *        read since that data would be correct.
 *
 * @param[in]     i_opType      Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 *
 * @param[in]     i_target      Presence detect target
 *
 * @param[in/out] io_buffer     Unused by this function
 *
 * @param[in/out] io_buflen     Unused by this function
 *
 * @param[in]     i_accessType  DeviceFW::AccessType enum (userif.H)
 *
 * @param[in]     i_args        This is an argument list for DD framework.
 *                              In this function, there is one argument to
 *                              signal which phase to execute.
 *
 * @return  errlHndl_t          If there is an issue while reading from the SPD
 *                              or the OCMB chip, or an unexpected memory
 *                              interface type then this function will return an
 *                              error. Otherwise, all other errors are
 *                              predictive and committed. So nullptr will be
 *                              returned in that case or on success.
 */
errlHndl_t ocmbIDEC(DeviceFW::OperationType i_opType,
                    TARGETING::Target* i_target,
                    void* io_buffer,
                    size_t& io_buflen,
                    int64_t i_accessType,
                    va_list i_args)
{
    errlHndl_t error = nullptr;

    // Determine which phase of this function to run.
    uint64_t phase = va_arg(i_args, uint64_t);

    // Execute the correct phase based on the va_arg given.
    if (phase == 1)
    {
        error = ocmbIdecPhase1(i_target);
    }
    else
    {
        error = ocmbIdecPhase2(i_target);
    }


    return error;
}

/**
 * @brief This is a small helper function that the ocmb IDEC functions use to
 *        add all the proper callouts and commit errorlogs.
 *
 * @param[in] i_target        Presence detect target
 *
 * @param[in] io_error        The error log to be committed
 *
 */
void ocmbErrlCommit(const TARGETING::TargetHandle_t& i_target,
                          errlHndl_t&                io_error)
{
    io_error->addHwCallout(i_target,
                          SRCI_PRIORITY_HIGH,
                          NO_DECONFIG,
                          GARD_NULL);

    io_error->addPartCallout(i_target,
                            VPD_PART_TYPE,
                            SRCI_PRIORITY_MED,
                            NO_DECONFIG,
                            GARD_NULL);

    io_error->addProcedureCallout(EPUB_PRC_HB_CODE,
                                 SRCI_PRIORITY_LOW);

    ERRORLOG::errlCommit(io_error, HWAS_COMP_ID);

}

/**
 * @brief This helper function will lookup the chip id and ec levels of
 *        a given OCMB based on what is found in a provided SPD buffer.
 *        The target is passed along for trace information.
 *
 * @param[in]  i_target        OCMB target we are looking up IDEC for
 *
 * @param[in]  i_spdBuffer     Buffer of at least SPD::OCMB_SPD_EFD_COMBINED_SIZE
 *                             bytes of the given OCMB's SPD
 *
 * @param[out] o_chipId        Chip Id associated with the given OCMB
 *                             (see src/import/chips/common/utils/chipids.H)
 *
 * @param[out] o_ec            EC level associated with the given OCMB
 *
 * @return                     nullptr if success, error log otherwise
 *
 */
errlHndl_t getOcmbIdecFromSpd(const TARGETING::TargetHandle_t& i_target,
                              uint8_t * i_spdBuffer,
                              uint16_t& o_chipId,
                              uint8_t& o_ec)
{
    errlHndl_t l_errl = nullptr;
    // These bytes are used for FFDC and verification purposes.
    const size_t SPD_REVISION_OFFSET                  = 1;
    const size_t DRAM_INTERFACE_TYPE_OFFSET           = 2;
    const size_t MEMORY_MODULE_INTERFACE_TYPE_OFFSET  = 3;

    // This is the value that signifies the SPD we read is for a DDIMM.
    const uint8_t DDIMM_MEMORY_INTERFACE_TYPE        = 0x0A;

    const uint8_t l_spdModuleRevision =
        *(i_spdBuffer + SPD_REVISION_OFFSET);

    const uint8_t l_spdDRAMInterfaceType =
        *(i_spdBuffer + DRAM_INTERFACE_TYPE_OFFSET);

    const uint8_t l_spdMemoryInterfaceType =
        *(i_spdBuffer + MEMORY_MODULE_INTERFACE_TYPE_OFFSET);

    // Byte 1 SPD Module Revision
    // Byte 2 DRAM Interface Type Presented or Emulated
    // Byte 3 Memory Module Interface Type
    const uint32_t SPD_FFDC_BYTES = TWO_UINT16_TO_UINT32(
        TWO_UINT8_TO_UINT16(l_spdModuleRevision, l_spdDRAMInterfaceType),
        TWO_UINT8_TO_UINT16(l_spdMemoryInterfaceType, 0));

    do{

        // Since the byte offsets used to get the IDEC info out of the SPD are
        // specific to the DDIMM interface type we must first verify that we
        // read from an SPD of that type.
        if (DDIMM_MEMORY_INTERFACE_TYPE != l_spdMemoryInterfaceType)
        {
            HWAS_ERR("getOcmbIdecFromSpd> memory module interface type "
                      "didn't match the expected type. "
                      "Expected 0x%.2X, Actual 0x%.2X",
                      DDIMM_MEMORY_INTERFACE_TYPE,
                      l_spdMemoryInterfaceType);

            /*@
            * @errortype
            * @severity          ERRL_SEV_UNRECOVERABLE
            * @moduleid          MOD_OCMB_IDEC
            * @reasoncode        RC_OCMB_INTERFACE_TYPE_MISMATCH
            * @userdata1[0:7]    SPD Module Revision
            * @userdata1[8:15]   DRAM Interface Type Presented or Emulated
            * @userdata1[16:23]  Memory Module Interface Type
            * @userdata1[24:31]  Unused
            * @userdata1[32:63]  Expected memory interface type
            * @userdata2         HUID of OCMB target
            * @devdesc           The memory interface type read from the SPD did
            *                    not match the DDIMM value. Setting the
            *                    appropriate IDEC values for this target cannot
            *                    continue.
            * @custdesc          Invalid or unsupported memory card installed.
            */
            l_errl = hwasError(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                              MOD_OCMB_IDEC,
                              RC_OCMB_INTERFACE_TYPE_MISMATCH,
                              TWO_UINT32_TO_UINT64(SPD_FFDC_BYTES,
                                DDIMM_MEMORY_INTERFACE_TYPE),
                              TARGETING::get_huid(i_target));

            l_errl->addProcedureCallout(EPUB_PRC_HB_CODE,
                                        SRCI_PRIORITY_LOW);

            l_errl->addHwCallout(i_target,
                                SRCI_PRIORITY_HIGH,
                                NO_DECONFIG,
                                GARD_NULL);


            break;
        }

        // SPD IDEC info is in the following three bytes
        const size_t SPD_ID_LEAST_SIGNIFICANT_BYTE_OFFSET = 198;
        const size_t SPD_ID_MOST_SIGNIFICANT_BYTE_OFFSET  = 199;
        const size_t DMB_REV_OFFSET                        = 200;

        // Get the ID from the SPD and verify that it matches what we read from
        // the IDEC register.
        uint16_t l_spdId = TWO_UINT8_TO_UINT16(
                          *(i_spdBuffer + SPD_ID_LEAST_SIGNIFICANT_BYTE_OFFSET),
                          *(i_spdBuffer + SPD_ID_MOST_SIGNIFICANT_BYTE_OFFSET));

        // Bytes 200 of the SPD contains the DMB Revision, this is essentially the
        // OCMB manufacture's version of the chip. The manufacture can define any
        // format for this field and we must add special logic to convert the
        // manufacture's DMB_REV to the EC level IBM is familiar with.
        uint8_t l_spdDmbRev = *(i_spdBuffer + DMB_REV_OFFSET);

        HWAS_INF("getOcmbIdecFromSpd> OCMB 0x%.8x l_spdId = 0x%.4X l_spdDmbRev = 0x%.2x",
                 TARGETING::get_huid(i_target), l_spdId, l_spdDmbRev);

        if (DDIMM_DMB_ID::EXPLORER == l_spdId)
        {
            o_chipId = POWER_CHIPID::EXPLORER_16;
            // Must convert Explorer's versioning into IBM-style EC levels.
            // Explorer vendor has stated versioning will start at 0xA0 and increment
            // 1st nibble for major revisions and 2nd nibble by 1 for minor revisions
            // Examples :
            // Version 0xA0 =  EC 0x10
            // Version 0xA1 =  EC 0x11
            // Version 0xB2 =  EC 0x22

            // Resulting formula from pattern in examples above is as follows:
            o_ec = (l_spdDmbRev - 0x90);
        }
        else if (DDIMM_DMB_ID::GEMINI == l_spdId)
        {
            o_chipId = POWER_CHIPID::GEMINI_16;

            HWAS_ASSERT(l_spdDmbRev == 0x0,
                        "Invalid Gemini DMB Revision Number, expected to find 0x0 at byte 200 in Gemini SPD");

            // 0x10 is the only valid EC level for Gemini cards. If we find 0x0 @ byte 200 in
            // the Gemini SPD then we will return 0x10 as the EC level
            o_ec = 0x10;
        }
        else
        {
            HWAS_ERR("getOcmbIdecFromSpd> Unknown OCMB chip type discovered in SPD "
                      "ID=0x%.4X OCMB HUID 0x%.8x",
                      l_spdId,
                      TARGETING::get_huid(i_target));

            /*@
            * @errortype
            * @severity          ERRL_SEV_PREDICTIVE
            * @moduleid          MOD_OCMB_IDEC
            * @reasoncode        RC_OCMB_UNKNOWN_CHIP_TYPE
            * @userdata1[0:7]    SPD Module Revision
            * @userdata1[8:15]   DRAM Interface Type Presented or Emulated
            * @userdata1[16:23]  Memory Module Interface Type
            * @userdata1[24:31]  Unused
            * @userdata1[32:63]  SPD Chip Id
            * @userdata2         HUID of OCMB target
            * @devdesc           The ID read from the SPD didn't match any known
            *                    OCMB chip types.
            * @custdesc          Unsupported memory installed.
            */
            l_errl = hwasError(ERRORLOG::ERRL_SEV_PREDICTIVE,
                              MOD_OCMB_IDEC_PHASE_1,
                              RC_OCMB_UNKNOWN_CHIP_TYPE,
                              TWO_UINT32_TO_UINT64(SPD_FFDC_BYTES, l_spdId),
                              TARGETING::get_huid(i_target));

            break;
        }

    }while(0);

    return l_errl;

}


errlHndl_t ocmbIdecPhase1(const TARGETING::TargetHandle_t& i_target)
{
    errlHndl_t l_errl = nullptr;

    // Allocate buffer to hold SPD and init to 0
    size_t l_spdBufferSize = SPD::DDIMM_DDR4_SPD_SIZE;
    uint8_t* l_spdBuffer = new uint8_t[l_spdBufferSize];
    memset(l_spdBuffer, 0, l_spdBufferSize);
    uint16_t l_chipId = 0;
    uint8_t l_chipEc = 0;

    do {

        // Read the SPD off the ocmb but skip reading the EFD to save time.
        l_errl = deviceRead(i_target,
                           l_spdBuffer,
                           l_spdBufferSize,
                           DEVICE_SPD_ADDRESS(SPD::ENTIRE_SPD_WITHOUT_EFD));

        // If unable to retrieve the SPD buffer then can't
        // extract the IDEC data, so return error.
        if (l_errl != nullptr)
        {
            HWAS_ERR("ocmbIdecPhase1> Error while trying to read "
                     "ENTIRE SPD from 0x%.08X ",
                     TARGETING::get_huid(i_target));
            break;
        }

        // Make sure we got back the size we were expecting.
        assert(l_spdBufferSize == SPD::DDIMM_DDR4_SPD_SIZE,
               "ocmbIdecPhase1> OCMB SPD read size %d "
               "doesn't match the expected size %d",
               l_spdBufferSize,
               SPD::DDIMM_DDR4_SPD_SIZE);

        l_errl = getOcmbIdecFromSpd(i_target,
                                    l_spdBuffer,
                                    l_chipId,
                                    l_chipEc);

        // If we were unable to read the IDEC information from the SPD
        // then break out early and do not set the associated attributes
        if (l_errl != nullptr)
        {
            HWAS_ERR("ocmbIdecPhase1> Error while trying to parse  "
                     "chip id and ec values from SPD read from OCMB 0x%.08X ",
                     TARGETING::get_huid(i_target));
            break;
        }

        HWAS_INF("ocmbIdecPhase1> Read Chip ID = 0x%x  Chip EC = 0x%x from target 0x%.08X",
                 l_chipId, l_chipEc, TARGETING::get_huid(i_target) );

        // set the explorer chip EC attributes.
        i_target->setAttr<TARGETING::ATTR_EC>(l_chipEc);
        i_target->setAttr<TARGETING::ATTR_HDAT_EC>(l_chipEc);

        // set the explorer chip id attribute.
        i_target->setAttr<TARGETING::ATTR_CHIP_ID>(l_chipId);

    } while(0);

    delete[] l_spdBuffer;
    return l_errl;

}

errlHndl_t ocmbIdecPhase2(const TARGETING::TargetHandle_t& i_target)
{
    const uint32_t GEM_IDEC_SCOM_REGISTER = 0x0801240e;
    const TARGETING::ATTR_CHIP_ID_type l_chipIdFromSpd =
                              i_target->getAttr<TARGETING::ATTR_CHIP_ID>();

    errlHndl_t l_errl  = nullptr;
    uint64_t l_idec    = 0;
    size_t   l_op_size = sizeof(l_idec);
    uint8_t  l_ec      = 0;
    uint16_t l_id      = 0;

    do {
        if(l_chipIdFromSpd == POWER_CHIPID::EXPLORER_16)
        {
            // Call platform independent lookup for Explorer OCMBs
            l_errl = FAPIWRAP::explorer_getidec(i_target, l_id, l_ec);

                        if (l_errl != nullptr)
            {
                HWAS_ERR("ocmbIdecPhase2> explorer OCMB 0x%.8X - failed to read ID/EC",
                        TARGETING::get_huid(i_target));

                break;
            }
        }
        else
        {
            // read the register containing IDEC info on Gemini OCMBs
            l_errl = DeviceFW::deviceRead(i_target,
                                        &l_idec,
                                        l_op_size,
                                        DEVICE_SCOM_ADDRESS(GEM_IDEC_SCOM_REGISTER));

            if (l_errl != nullptr)
            {
                HWAS_ERR("ocmbIdecPhase2> gemini OCMB 0x%.8X - failed to read ID/EC",
                        TARGETING::get_huid(i_target));

                break;
            }

            // Need to convert Gemini's IDEC register from MmL000CC
            // to cfam standard format MLmCC000
            uint32_t l_major = 0xF0000000 & static_cast<uint32_t>(l_idec);
            uint32_t l_minor = 0x0F000000 & static_cast<uint32_t>(l_idec);
            uint32_t l_location = 0x00F00000 & static_cast<uint32_t>(l_idec);
            l_idec = (l_major | (l_location << 4) | (l_minor >> 4)
                            | ((l_idec & 0x000000FF) << 12));
            // Parse out the information we need
            l_ec = POWER_CHIPID::extract_ddlevel(l_idec);
            l_id = POWER_CHIPID::extract_chipid16(l_idec);
        }

        HWAS_INF("ocmbIdecPhase2> OCMB 0x%.8X - read ID/EC successful. "
                 "ID = 0x%.4X, EC = 0x%.2X, Full IDEC 0x%x",
                 TARGETING::get_huid(i_target),
                 l_id,
                 l_ec,
                 l_idec);

        if (l_id != l_chipIdFromSpd)
        {
            HWAS_ERR("ocmbIdecPhase2> OCMB Chip Id and associated SPD Chip Id "
                     "don't match: OCMB ID=0x%.4X; SPD ID=0x%.4X;",
                     l_id,
                     l_chipIdFromSpd);

            HWAS_ERR("ocmbIdecPhase2> Previous CHIP_ID 0x%.4X translated from "
                     "SPD read will be overwritten with OCMB IDEC register "
                     "ID=0x%.4X",
                     l_chipIdFromSpd,
                     l_id);
            /*@
            * @errortype
            * @severity          ERRL_SEV_PREDICTIVE
            * @moduleid          MOD_OCMB_IDEC
            * @reasoncode        RC_OCMB_CHIP_ID_MISMATCH
            * @userdata1[00:31]  OCMB IDEC Register ID
            * @userdata1[32:63]  Translated SPD ID
            * @userdata2[32:63]  HUID of OCMB target
            * @devdesc           The IDEC info read from the OCMB and SPD
            *                    did not match the expected values.
            * @custdesc          Firmware Error
            */
            l_errl = hwasError(ERRORLOG::ERRL_SEV_PREDICTIVE,
                              MOD_OCMB_IDEC,
                              RC_OCMB_CHIP_ID_MISMATCH,
                              TWO_UINT32_TO_UINT64(l_id, l_chipIdFromSpd),
                              TARGETING::get_huid(i_target));

            // Add callouts and commit
            ocmbErrlCommit(i_target, l_errl);

            // Since there was an error then the ID values don't agree between
            // the OCMB read and the SPD read. Since the OCMB has the correct
            // answer, set the attributes to the values read from that instead
            // of the SPD.
            i_target->setAttr<TARGETING::ATTR_CHIP_ID>(l_id);
        }

        const uint8_t l_ecFromSpd = i_target->getAttr<TARGETING::ATTR_EC>();

        if (l_ec != l_ecFromSpd)
        {
            HWAS_ERR("ocmbIdecPhase2> OCMB Revision and associated SPD "
                     "Revision don't match: OCMB EC=0x%.2X; "
                     "SPD EC=0x%.2X; ",
                     l_ec, l_ecFromSpd);

            HWAS_ERR("ocmbIdecPhase2> Previous EC and HDAT_EC attributes 0x%.2X,"
                     " which were set with values found in SPD will be overwritten"
                     "  with value from OCMB IDEC register ID=0x%.2X",
                     l_ecFromSpd,
                     l_ec);

            /*@
            * @errortype
            * @severity          ERRL_SEV_PREDICTIVE
            * @moduleid          MOD_OCMB_IDEC
            * @reasoncode        RC_OCMB_SPD_REVISION_MISMATCH
            * @userdata1[00:31]  OCMB IDEC register EC
            * @userdata1[32:63]  Translated SPD EC
            * @userdata2[00:31]  OCMB Chip ID Attribute
            * @userdata2[32:63]  HUID of OCMB target
            * @devdesc           The EC (Revision) info read from the OCMB and
            *                    SPD did not match the expected values.
            * @custdesc          Firmware Error
            */
            l_errl = hwasError(ERRORLOG::ERRL_SEV_PREDICTIVE,
                              MOD_OCMB_IDEC,
                              RC_OCMB_SPD_REVISION_MISMATCH,
                              TWO_UINT32_TO_UINT64(l_ec, l_ecFromSpd),
                              TWO_UINT32_TO_UINT64(
                                  i_target->getAttr<TARGETING::ATTR_CHIP_ID>(),
                                  TARGETING::get_huid(i_target)));

            // Add callouts and commit
            ocmbErrlCommit(i_target, l_errl);

            // Since there was an error then the EC values don't agree between
            // the OCMB read and the SPD read. Since the OCMB has the correct
            // answer, set the attributes to the values read from that instead
            // of the SPD.
            i_target->setAttr<TARGETING::ATTR_EC>(l_ec);
            i_target->setAttr<TARGETING::ATTR_HDAT_EC>(l_ec);
        }

    } while(0);

    return l_errl;

}

// Register the presence detect function with the device framework
DEVICE_REGISTER_ROUTE(DeviceFW::WRITE,
                      DeviceFW::IDEC,
                      TARGETING::TYPE_OCMB_CHIP,
                      ocmbIDEC);

//******************************************************************************
// platIsMinHwCheckingAllowed function
// Description: This function will return false always because when Hostboot
// is running then System cannot be at runtime
//******************************************************************************
errlHndl_t platIsMinHwCheckingAllowed(bool &o_minHwCheckingAllowed)
{
    errlHndl_t errl = NULL;

    // for hostboot, minimum hardware checkign is always allowed
    o_minHwCheckingAllowed = true;

    return errl;
}

//******************************************************************************
// platReadPartialGood function
//******************************************************************************
errlHndl_t platReadPartialGood(const TargetHandle_t &i_target,
        void *o_pgData)
{
    HWAS_DBG( "i_target %.8X",
            i_target->getAttr<ATTR_HUID>());

    // call deviceRead() to find the PartialGood record
    uint8_t pgRaw[VPD_CP00_PG_HDR_LENGTH + VPD_CP00_PG_DATA_LENGTH];
    size_t pgSize = sizeof(pgRaw);

    errlHndl_t errl = deviceRead(i_target, pgRaw, pgSize,
            DEVICE_MVPD_ADDRESS(MVPD::CP00, MVPD::PG));

    if (unlikely(errl != NULL))
    {   // errl was set - this is an error condition.
        HWAS_ERR( "i_target %.8X - failed partialGood read",
            i_target->getAttr<ATTR_HUID>());
    }
    else
    {
        // skip past the header
        void *pgData = static_cast<void *>(&pgRaw[VPD_CP00_PG_HDR_LENGTH]);
        HWAS_DBG_BIN("PG record", pgData, VPD_CP00_PG_DATA_LENGTH);
        // copy the data back into the caller's buffer
        memcpy(o_pgData, pgData, VPD_CP00_PG_DATA_LENGTH);
    }

    return errl;
} // platReadPartialGood

errlHndl_t platDetermineEcoCores(const TARGETING::TargetHandleList &io_cores)
{
    errlHndl_t errl = nullptr;

    do {
        for (const auto core : io_cores)
        {
            fapi2::Target<fapi2::TARGET_TYPE_CORE> fapi_core(core);
            FAPI_INVOKE_HWP(errl,
                            p10_determine_eco_mode,
                            fapi_core);
            if (errl)
            {
                HWAS_ERR("discoverTargets: p10_determine_eco_mode failed for CORE HUID 0x%x",
                         get_huid(core));
                break;
            }
        }
        if (errl)
        {
            break;
        }
    } while(0);

    return errl;
}

//******************************************************************************
// platReadPR function
//******************************************************************************
errlHndl_t platReadPR(const TargetHandle_t &i_target,
        void *o_prData)
{
    HWAS_ERR( "platReadPR is deprecated!!!" );
    return NULL;
} // platReadPR

//******************************************************************************
// platReadLx function
//******************************************************************************
errlHndl_t platReadLx(const TargetHandle_t &i_mca,
                      void *o_lxData)
{
    errlHndl_t errl = nullptr;
    uint8_t l_chip_unit;
    uint8_t l_x;
    const TARGETING::Target* l_proc;

    if (!(i_mca->tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(l_chip_unit)))
    {
        HWAS_ERR("Bad MCA target");
        /*@
         * @errortype    ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid     HWAS::MOD_PLAT_READLX
         * @reasoncode   HWAS::RC_BAD_MCA
         * @userdata1    0
         * @userdata2    0
         * @devdesc      platReadLx> Bad MCA target
         * @custdesc     Bad MCA target
         */
        errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       HWAS::MOD_PLAT_READLX,
                                       HWAS::RC_BAD_MCA,
                                       0,
                                       0);

        // make code the highest callout
        errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                  HWAS::SRCI_PRIORITY_HIGH);
    }
    else
    {
        l_x = VPD_CRP0_LX_MIN_X + l_chip_unit;

        HWAS_DBG( "i_mca %.8X, Lx = L%1d",
                  i_mca->getAttr<ATTR_HUID>(),
                  l_x);

        //Check for an invalid x value
        if( l_x > VPD_CRP0_LX_MAX_X)
        {
            HWAS_ERR("Invalid Lx with x=%1d for MCA %.8X",
                     l_x,
                     i_mca->getAttr<ATTR_HUID>());
            /*@
             * @errortype    ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid     HWAS::MOD_PLAT_READLX
             * @reasoncode   HWAS::RC_BAD_LX
             * @userdata1    Target MCA HUID
             * @userdata2    Value of x for Lx keyword
             * @devdesc      platReadLx> Invalid Lx keyword
             * @custdesc     Invalid Lx keyword
             */
            errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           HWAS::MOD_PLAT_READLX,
                                           HWAS::RC_BAD_LX,
                                           TARGETING::get_huid(i_mca),
                                           l_x);

            // make code the highest callout
            errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                      HWAS::SRCI_PRIORITY_HIGH);
        }
        else
        {
            l_proc = getParentChip( i_mca );

            HWAS_DBG( "i_mca %.8X, Lx = L%1d, l_proc %.8X",
                      i_mca->getAttr<ATTR_HUID>(),
                      l_x,
                      l_proc->getAttr<ATTR_HUID>());
        }
    }

    if (errl == nullptr)
    {   // no error, so we got a valid chip unit value back
        // call deviceRead() to find the Lx record
        size_t l_lxLength = VPD_CRP0_LX_HDR_DATA_LENGTH;
        errl = deviceRead((TARGETING::Target*)l_proc, o_lxData, l_lxLength,
                          DEVICE_MVPD_ADDRESS(MVPD::CRP0,
                                              MVPD::L1 + l_chip_unit));

        if (errl != nullptr)
        {   // trace the error condition
            HWAS_INF( "l_proc %.8X, i_mca %.8X - failed L%1d read",
                      l_proc->getAttr<ATTR_HUID>(),
                      i_mca->getAttr<ATTR_HUID>(),
                      l_x);
        }
    }

    return errl;
} // platReadLx

//******************************************************************************
// platGetFCO function
//******************************************************************************
errlHndl_t platGetFCO(const TargetHandle_t &i_node,
            uint32_t &o_fco)
{
    errlHndl_t errl = NULL;

    o_fco = i_node->getAttr<ATTR_FIELD_CORE_OVERRIDE>();

    HWAS_DBG("FCO returned: %d", o_fco);

    return errl;
} // platGetFCO

//******************************************************************************
// platPresenceDetect function
//******************************************************************************
errlHndl_t platPresenceDetect(TargetHandleList &io_targets)
{
    errlHndl_t errl = NULL;

#ifdef CONFIG_PNOR_TWO_SIDE_SUPPORT
    // If we're booting from the golden side of PNOR we need
    //  to wipe out our VPD caches to force a re-read of
    //  the data from hardware
    PNOR::SideInfo_t l_pnorInfo;
    errl = PNOR::getSideInfo( PNOR::WORKING, l_pnorInfo );
    if( errl )
    {
        // commit the error but keep going
        errlCommit(errl, HWAS_COMP_ID);
        // force the caches to get wiped out just in case
        l_pnorInfo.isGolden = true;
    }
    if( l_pnorInfo.isGolden )
    {
#ifdef CONFIG_DJVPD_WRITE_TO_PNOR
        errl = PNOR::clearSection( PNOR::DIMM_JEDEC_VPD );
        if( errl )
        {
            // commit the error but keep going
            errlCommit(errl, HWAS_COMP_ID);
        }
#endif
#ifdef CONFIG_MVPD_WRITE_TO_PNOR
        errl = PNOR::clearSection( PNOR::MODULE_VPD );
        if( errl )
        {
            // commit the error but keep going
            errlCommit(errl, HWAS_COMP_ID);
        }
#endif
    }
#endif

    // we got a list of targets - determine if they are present
    //  if not, delete them from the list
    for (TargetHandleList::iterator pTarget_it = io_targets.begin();
            pTarget_it != io_targets.end();
            ) // increment will be done in the loop below
    {
        TargetHandle_t pTarget = *pTarget_it;
        // TODO RTC: 260058
        // Disable Procs1-3 in non-simulation eBMC enviroment for
        // bringup purposes.
#ifdef CONFIG_FORCE_SINGLE_CHIP
        if(!Util::isSimicsRunning() &&
           !INITSERVICE::spBaseServicesEnabled())
        {
            if(pTarget->getAttr<ATTR_HUID>() == 0x50001 ||
               pTarget->getAttr<ATTR_HUID>() == 0x50002 ||
               pTarget->getAttr<ATTR_HUID>() == 0x50003)
            {
                HwasState l_hwasState;
                l_hwasState.functional = false;
                l_hwasState.present = false;
                pTarget->setAttr<ATTR_HWAS_STATE>(l_hwasState);
                pTarget_it = io_targets.erase(pTarget_it);
                continue;
            }
        }
#endif

        // if CLASS_ENC
        // by definition, hostboot only has 1 node/enclosure, and we're
        //  here, so it is functional
        if (pTarget->getAttr<ATTR_CLASS>() == CLASS_ENC)
        {
            HWAS_DBG("pTarget %.8X - detected present",
                pTarget->getAttr<ATTR_HUID>());

        // If there is planar VPD, then don't skip the presence detect.
        // The presence detect will log any problems and load pnor.
#if !defined(CONFIG_HAVE_PVPD)
            // on to the next target if there is no Planar VPD
            pTarget_it++;
            continue;
#endif
        }

        // Cache the attribute type
        auto l_attrType = pTarget->getAttr<ATTR_TYPE>();
        // if CLASS_SP
        // Hostboot is told everything it needs to know about the
        //  SP at compile time so just mark the target as present
        //  by default
        if ((l_attrType == TYPE_SP) || (l_attrType ==  TYPE_BMC))
        {
            HWAS_DBG("pTarget %.8X - detected present",
                pTarget->getAttr<ATTR_HUID>());
            pTarget_it++;
            continue;
        }

        // call deviceRead() to see if they are present
        bool present = false;
        size_t presentSize = sizeof(present);
        errl = deviceRead(pTarget, &present, presentSize,
                                DEVICE_PRESENT_ADDRESS());

        if (unlikely(errl != NULL))
        {   // errl was set - this is an error condition.
            HWAS_ERR( "pTarget %.8X - failed presence detect",
                pTarget->getAttr<ATTR_HUID>());

            // commit the error but keep going
            errlCommit(errl, HWAS_COMP_ID);
            // errl is now NULL

            // target is not present - fall thru
            present = false;
        }

        // if TYPE_MCS
        // Need to handle "special" -- DVPD cache relies on this
        // being called for pnor cache management, however this causes
        // spurious MCS's to be marked present/functional when they are
        // trully tied to processor PG.  So remove from list since
        // the DVPD present detect hook has been called
        // TODO RTC 169572 -- Fix correctly by reworking DVPD
        if (l_attrType == TYPE_MCS)
        {
            // erase this target, and 'increment' to next
            pTarget_it = io_targets.erase(pTarget_it);
            continue;
        }

#if defined(CONFIG_SUPPORT_EEPROM_CACHING) && defined(CONFIG_SUPPORT_EEPROM_HWACCESS)
        // pulling the data from the eeprom can be very slow so be sure to
        //  indicate we're still making progress
        INITSERVICE::sendProgressCode();

        // Now that we know if the part is present or not, we can
        //  cache the EEPROM data.
        EEPROM::cacheEepromVpd(pTarget, present);

        // Validate the ECC data of the VPD cache if target is a PROC and is present
        if ( (TYPE_PROC == l_attrType) && present )
        {
            errl = VPD::validateAllRecordEccData( pTarget );
            if (errl)
            {
                break;
            }
        }
        // Validate the CRC data of the VPD cache if target is a OCMB and is present
        else if ( (TYPE_OCMB_CHIP == l_attrType) && present )
        {
            //P10 DD1 Workaround
            // There is a bug on P10 DD1 that can cause SPD corruption
            // due to some floating i2c lines.  To help the lab we will
            // write our previously cached data out to the hardware.
            PVR_t l_pvr( mmio_pvr_read() & 0xFFFFFFFF );
            if( l_pvr.isP10DD10() )
            {
                HWAS_DBG( "Call SPD::fixEEPROM on %.8X", TARGETING::get_huid(pTarget) );
                errl = SPD::fixEEPROM( pTarget );
                if (errl)
                {
                    // commit the error but remove all deconfig/gard
                    errl->removeGardAndDeconfigure();
                    errlCommit(errl, HWAS_COMP_ID);
                }
            }
            //End P10 DD1 Workaround

            // Simics currently has bad CRC for the serial number portion
            if(!Util::isSimicsRunning())
            {
                HWAS_DBG( "Call SPD::checkCRC on %.8X", TARGETING::get_huid(pTarget) );
                errl = SPD::checkCRC( pTarget, SPD::CHECK );
                if (errl)
                {
                    // commit the error but remove all deconfig/gard
                    errl->removeGardAndDeconfigure();
                    errlCommit(errl, HWAS_COMP_ID);
                    // SPD is busted so mark the part as not present
                    present = false;
                }
            }
            else
            {
                HWAS_DBG( "Ignoring CRC in Simics" );
            }
        }

#endif

        // FSP normally sets PN/SN so if FSP isn't present, do it here
        //(after VPD has been cached if caching is enabled)
        if ((present == true) &&
            (!INITSERVICE::spBaseServicesEnabled()))
        {
            // set part and serial number attributes for current target
            // (error handling is done internally)
            if (l_attrType == TYPE_PROC)
            {
                VPD::setPartAndSerialNumberAttributes(pTarget);
            }
            else if (l_attrType == TYPE_DIMM)
            {
                SPD::setPartAndSerialNumberAttributes(pTarget);
            }

            //otherwise, do nothing.
        }

        // Evaluate presence status, if we determine the target
        // to not be present at the end of this loop then remove
        // it from the list and continue to the next target.
        if (present == true)
        {
            HWAS_INF( "pTarget %.8X - detected present",
                pTarget->getAttr<ATTR_HUID>());

            // advance to next entry in the list
            pTarget_it++;
        }
        else
        {   // chip not present -- remove from list
            HWAS_INF( "pTarget %.8X - no presence",
                pTarget->getAttr<ATTR_HUID>());

            // erase this target, and 'increment' to next
            pTarget_it = io_targets.erase(pTarget_it);
        }

    } // for pTarget_it

    return errl;
} // platPresenceDetect

//******************************************************************************
// hwasPLDDetection function
//******************************************************************************
bool hwasPLDDetection()
{
    bool rc = false;

    // TODO: RTC: 76459
    HWAS_DBG("hwasPLDDetection");

    Target *l_pTopLevel = NULL;
    targetService().getTopLevelTarget( l_pTopLevel );

    // check if SP doesn't support this,
    if (l_pTopLevel->getAttr<ATTR_SP_FUNCTIONS>().powerLineDisturbance)
    {
        // SP supports this - return false as this will get handled later.
        rc = false;
    }
    else
    {
        // TBD - detect power fault
        rc = false;
    }

    return rc;
} // hwasPLDDetection

//******************************************************************************
// markTargetChanged function
//******************************************************************************
#ifdef CONFIG_HOST_HCDB_SUPPORT
void markTargetChanged(TARGETING::TargetHandle_t i_target)
{
    TargetHandleList l_pChildList;

    HWAS_INF("Marking target and all children as changed for parent HUID %.8X",
                TARGETING::get_huid(i_target) );

    //Call update mask on the target
    update_hwas_changed_mask(i_target);

    //Get all children under this target, and set them into the list
    targetService().getAssociated(l_pChildList, i_target,
           TargetService::CHILD, TargetService::ALL);

    //Iterate through the child list that was populated, and update mask
    for (TargetHandleList::iterator l_pChild_it = l_pChildList.begin();
            l_pChild_it != l_pChildList.end(); ++l_pChild_it)
    {
        TargetHandle_t l_pChild = *l_pChild_it;
        update_hwas_changed_mask(l_pChild);
    }

} // markTargetChanged
#endif

//******************************************************************************
//  platCheckMinimumHardware()
//******************************************************************************
void platCheckMinimumHardware(uint32_t & io_plid,
                              const TARGETING::ConstTargetHandle_t i_node,
                              bool *o_bootable)
{
    errlHndl_t l_errl = NULL;

    Target* l_pMasterProcChip = NULL;
    targetService().masterProcChipTargetHandle(l_pMasterProcChip);

    // NVDIMM only supported on Nimbus
    ATTR_MODEL_type l_model = l_pMasterProcChip->getAttr<ATTR_MODEL>();
    if (l_model == MODEL_NIMBUS)
    {
        l_errl = checkForHbOnNvdimm();
        if (l_errl)
        {
            HWAS_ERR("platCheckMinimumHardware::checkForHbOnNvdimm() failed.");

            if(o_bootable)
            {
                *o_bootable = false;
            }

            // Add procedure callout, update common plid, commit
            hwasErrorAddProcedureCallout(l_errl,
                                        EPUB_PRC_FIND_DECONFIGURED_PART,
                                        SRCI_PRIORITY_HIGH);
            hwasErrorUpdatePlid(l_errl, io_plid);
            errlCommit(l_errl, HWAS_COMP_ID);
        }
    }

}

//******************************************************************************
//  checkForHbOnNvdimm()
//******************************************************************************
errlHndl_t checkForHbOnNvdimm(void)
{
    errlHndl_t l_errl = nullptr;

    do
    {
        HWAS_DBG("Check if HB is running on a proc with only NVDIMMs.");

        // Get all functional proc chip targets
        TargetHandleList l_procList;
        getAllChips(l_procList, TARGETING::TYPE_PROC);
        assert(l_procList.size() != 0, "Empty proc list returned!");

        // Use the hrmor to find which proc HB is running on
        const auto l_hbHrmor = cpu_spr_value(CPU_SPR_HRMOR);

        // Use the MemBases and MemSizes to find which group
        // includes the hrmor
        ATTR_PROC_MEM_BASES_type l_memBases = {0};
        ATTR_PROC_MEM_SIZES_type l_memSizes = {0};
        size_t l_numGroups = sizeof(ATTR_PROC_MEM_SIZES_type)/sizeof(uint64_t);

        // checkMinimumHardware may be called before the groups are set up
        // If the MemSizes are all zero the groups are not set up yet
        // Break out of the check
        bool l_memSizesAllZero = true;

        // Save the HB proc target and group number
        Target *l_hbProc = nullptr;
        uint32_t l_hbGroup = 0;

        for (auto l_pProc : l_procList)
        {
            // Get the memory group ranges under this proc
            assert(l_pProc->tryGetAttr<ATTR_PROC_MEM_BASES>(l_memBases),
                "Unable to get ATTR_PROC_MEM_BASES attribute");
            assert(l_pProc->tryGetAttr<ATTR_PROC_MEM_SIZES>(l_memSizes),
                "Unable to get ATTR_PROC_MEM_SIZES attribute");


            for (size_t l_grp=0; l_grp < l_numGroups; l_grp++)
            {
                // Non-zero size means that there is memory present
                if (l_memSizes[l_grp])
                {
                    l_memSizesAllZero = false;
                    // Check if hrmor is in this group's memory range
                    if ( (l_hbHrmor >= l_memBases[l_grp]) &&
                         (l_hbHrmor < (l_memBases[l_grp] +
                                       l_memSizes[l_grp])) )
                    {
                        l_hbProc = l_pProc;
                        l_hbGroup = l_grp;
                        break;
                    }
                }
            }
            if (l_hbProc != nullptr)
            {
                break;
            }
        }

        if (l_memSizesAllZero)
        {
            break;
        }

        if (l_hbProc != nullptr)
        {
            // Found the proc/group HB is running in, now check the dimms
            // If we find a regular dimm then we assume that is where
            // HB is running
            bool l_foundNonNvdimm = false;

            // Get the array of mcas/group from the attribute
            // The attr contains 8 8-bit entries, one entry per group
            // The bits specify which mcas are included in the group
            ATTR_MSS_MEM_MC_IN_GROUP_type l_memMcGroup = {0};
            assert(l_hbProc->tryGetAttr<ATTR_MSS_MEM_MC_IN_GROUP>(l_memMcGroup),
                "Unable to get ATTR_MSS_MEM_MC_IN_GROUP attribute");

            // Get list of mcas under this proc
            TargetHandleList l_mcaList;
            getChildAffinityTargets( l_mcaList,
                                     l_hbProc,
                                     CLASS_UNIT,
                                     TYPE_MCA );

            // Loop through the mcas on this proc
            for (const auto & l_mcaTarget : l_mcaList)
            {
                // Get the chip unit for this mca
                ATTR_CHIP_UNIT_type l_mcaUnit = 0;
                l_mcaUnit = l_mcaTarget->getAttr<ATTR_CHIP_UNIT>();

                // Check if this mca is included in the hb memory group
                const uint8_t l_mcMask = 0x80;
                if (l_memMcGroup[l_hbGroup] & (l_mcMask >> l_mcaUnit))
                {
                    // Get the list of dimms under this mca
                    TargetHandleList l_dimmList;
                    getChildAffinityTargets( l_dimmList,
                                             l_mcaTarget,
                                             CLASS_NA,
                                             TYPE_DIMM );
                    for (const auto & l_dimmTarget : l_dimmList)
                    {
                        if (!isNVDIMM(l_dimmTarget))
                        {
                            // Found a regular dimm, exit
                            l_foundNonNvdimm = true;
                            break;
                        }
                    }
                }
                if (l_foundNonNvdimm)
                {
                    break;
                }
            }

            // If only nvdimms then error
            if (!l_foundNonNvdimm)
            {
                HWAS_ERR("checkForHbOnNvdimm: HB is running on a proc with only NVDIMMS.");
                /*@
                * @errortype    ERRORLOG::ERRL_SEV_UNRECOVERABLE
                * @moduleid     HWAS::MOD_CHECK_HB_NVDIMM
                * @reasoncode   HWAS::RC_HB_PROC_ONLY_NVDIMM
                * @userdata1    Hostboot Proc Target HUID
                * @userdata2    Hostboot Memory Group
                * @devdesc      Hostboot running on proc with only NVDIMMs
                * @custdesc     Insufficient DIMM resources
                */
                l_errl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    HWAS::MOD_CHECK_HB_NVDIMM,
                                    HWAS::RC_HB_PROC_ONLY_NVDIMM,
                                    get_huid(l_hbProc),
                                    l_hbGroup);
            }
        }
        else
        {
            // Should never get here, would be caught elsewhere
            HWAS_ERR("checkForHbOnNvdimm: HB execution proc not found.");
        }

    } while(0);

    return l_errl;
}

//******************************************************************************
//  verificationMatchHandler()
//******************************************************************************
errlHndl_t HWASPlatVerification::verificationMatchHandler(Target * i_target,
                                                          const bool i_hbFunctional,
                                                          const bool i_sbeFunctional)
{
    errlHndl_t l_errLog = nullptr;

    // Hostboot must deconfigure at least what the SBE deconfigures.
    if (i_hbFunctional && !i_sbeFunctional)
    {
        HWAS_ERR("verifyDeconfiguration: ATTR_PG does not match mbox "
            "scratch registers for chip unit type %s with HUID %.8X "
            "(SBE marked functional: %s  HB marked functional: %s)",
            i_target->getAttrAsString<ATTR_TYPE>(),
            i_target->getAttr<ATTR_HUID>(),
            ((i_sbeFunctional) ? "True" : "False"),
            ((i_hbFunctional) ? "True" : "False") );

        // Create error due to mismatching HB and SBE deconfigs
        /*@
        * @errortype        ERRL_SEV_INFORMATIONAL
        * @moduleid         MOD_DECONFIG_TARGETS_FROM_GARD_AND_VPD
        * @reasoncode       RC_HB_SBE_DECONFIG_MISMATCH
        * @userdata1        Target HUID
        * @userdata2[0:31]  SBE target functional? (0: no, 1: yes)
        * @userdata2[32:63] HB target functional? (0: no, 1: yes)
        * @devdesc          SBE and HB targets configuration do not
        *                   match.
        * @custdesc         Firmware error during IPL
        */
        l_errLog = new ERRORLOG::ErrlEntry (
            ERRORLOG::ERRL_SEV_INFORMATIONAL,
            MOD_DECONFIG_TARGETS_FROM_GARD_AND_VPD,
            RC_HB_SBE_DECONFIG_MISMATCH,
            i_target->getAttr<ATTR_HUID>(),
            TWO_UINT32_TO_UINT64 (
                i_sbeFunctional, i_hbFunctional
            )
        );

        l_errLog->collectTrace(HWAS_COMP_NAME);
    }
    else
    {
        HWAS_DBG("verifyDeconfiguration: ATTR_PG matches mbox "
            "scratch registers for chip unit type %s with HUID %.8X "
            "(SBE marked functional: %s  HB marked functional: %s)",
            i_target->getAttrAsString<ATTR_TYPE>(),
            i_target->getAttr<ATTR_HUID>(),
            ((i_sbeFunctional) ? "True" : "False"),
            ((i_hbFunctional) ? "True" : "False") );
    }

    return l_errLog;
} // verificationMatchHandler

//******************************************************************************
//  verifyDeconfiguration()
//******************************************************************************
errlHndl_t HWASPlatVerification::verifyDeconfiguration(Target* i_target,
                                                       const ATTR_MASTER_MBOX_SCRATCH_typeStdArr& i_scratchRegs)
{
    HWAS_INF(ENTER_MRK"verifyDeconfiguration");

    using namespace INITSERVICE::SPLESS;

    // Structure to pair unit type with corresponding scratch register and
    // location range in that scratch register
    struct UnitMboxOffsetData
    {
        ATTR_TYPE_type type;
        uint32_t mboxReg;
        uint32_t startBitPosition;
        uint32_t endBitPosition;
    };

    // UnitMboxOffsetData
    // Struct containing every unit type in MboxScratch1_t and MboxScratch2_t
    // see: src/include/usr/initservice/mboxRegs.H
    // For each unit type, this struct contains the scratch register it is in
    // and its offset (inclusive) range within each scratch register
    static const UnitMboxOffsetData l_unitMboxOffsetData[] =
    {
        {TYPE_CORE, MboxScratch1_t::REG_IDX, 0, 31},
        {TYPE_PEC, MboxScratch2_t::REG_IDX, 0, 1},
        {TYPE_NMMU, MboxScratch2_t::REG_IDX, 2, 2},
        {TYPE_MC, MboxScratch2_t::REG_IDX, 4, 7},
        {TYPE_PAUC, MboxScratch2_t::REG_IDX, 8, 11},
        {TYPE_PAU, MboxScratch2_t::REG_IDX, 12, 19},
        {TYPE_IOHS, MboxScratch2_t::REG_IDX, 20, 27}
    };

    errlHndl_t l_errLog = nullptr;

    do
    {
        // In the following loops, for every l_unitTypeOffset the
        // l_hostbootFunctional and l_sbeFunctional values are calculated for
        // every individual part.
        // l_hostbootFunctional is a bool stating whether or not HB has marked a
        // part functional. This is done by reading the ATTR_PG value of that
        // part.
        // l_sbeFunctional is a bool stating whether or not SBE has marked a
        // part functional. This is done by shifting out the correspoonding gard
        // bit for the part.

        for (const auto l_unitTypeOffset: l_unitMboxOffsetData)
        {
            //Find all child chiplets related to the target passed in
            TargetHandleList l_childChiplets;
            getChildAffinityTargetsByState (l_childChiplets,
                                            i_target,
                                            CLASS_NA,
                                            l_unitTypeOffset.type,
                                            UTIL_FILTER_ALL);

            for (const auto l_chiplet: l_childChiplets)
            {
                // Getting functional state as saved from SBE
                AttributeTraits<ATTR_CHIP_UNIT>::Type l_chipUnit;
                if(!l_chiplet->tryGetAttr<ATTR_CHIP_UNIT>(l_chipUnit))
                {
                    HWAS_ERR("verifyDeconfiguration: Failed to get chip unit "
                             "for %s with HUID %.8X",
                             l_chiplet->getAttrAsString<ATTR_TYPE>(),
                             l_chiplet->getAttr<ATTR_HUID>()
                             );
                    continue;
                }

                // see src/include/usr/initservice/mboxRegs.H, MboxScratch2_t
                // There's a gard bit only for NMMU with CHIP_UNIT value
                // of 1, therefore CHIP_UNIT value of 0 is ignored
                if (l_unitTypeOffset.type == TYPE_NMMU && l_chipUnit == 0)
                {
                    continue;
                }

                // Calculating the offset at which this l_chiplet's gard data is
                // written in the scratch register
                uint32_t l_chipUnitOffset = l_chipUnit + l_unitTypeOffset.startBitPosition;

                if (l_unitTypeOffset.type == TYPE_NMMU && l_chipUnit == 1)
                {
                    // Value for TYPE_NMMU with l_chipUnit equal to 1 does not
                    // use l_chipUnit to calculate offset
                    l_chipUnitOffset = l_unitTypeOffset.startBitPosition;
                }

                if (l_chipUnitOffset > l_unitTypeOffset.endBitPosition)
                {
                    HWAS_ERR("verifyDeconfiguration: l_chipUnitOffset %u is "
                             "going beyond l_unitTypeOffset.endBitPosition %u",
                             l_chipUnitOffset, l_unitTypeOffset.endBitPosition);
                    continue;
                }

                const uint32_t l_scratchReg = i_scratchRegs[l_unitTypeOffset.mboxReg];

                bool l_sbeFunctional =
                      ((0x80000000ull >> l_chipUnitOffset) & l_scratchReg) == 0;

                // Getting functional state as known to HB from ATTR_PG

                Target* const l_perv = getTargetWithPGAttr(*l_chiplet);
                bool l_hostbootFunctional = false;

                if (l_perv)
                {
                    pg_entry_t l_attrPGMask = getDeconfigMaskedPGValue(*l_chiplet);
                    l_hostbootFunctional =
                          (l_attrPGMask & l_perv->getAttr<ATTR_PG>()) == 0;
                }
                else
                {
                    HWAS_ERR("verifyDeconfiguration: Failed to get pervasive "
                             "target for chip unit type %s with HUID  %.8X",
                             l_chiplet->getAttrAsString<ATTR_TYPE>(),
                             l_chiplet->getAttr<ATTR_HUID>());
                    continue;
                }

                errlHndl_t matchError =
                        verificationMatchHandler(l_chiplet, l_hostbootFunctional,
                                                 l_sbeFunctional);

                if (matchError)
                {
                    if (!l_errLog)
                    {
                        HWAS_ERR("verifyDeconfiguration: One or more SBE/HB deconfiguration mismatches exist");

                        /*@
                         * @errortype  ERRL_SEV_INFORMATIONAL
                         * @moduleid   MOD_DECONFIG_TARGETS_FROM_GARD_AND_VPD
                         * @reasoncode RC_HB_SBE_DECONFIG_MISMATCHES_EXIST
                         * @devdesc    One or more SBE/HB deconfiguration mismatches exist; see other logs
                         * @custdesc   Firmware error during IPL
                         */
                        l_errLog = new ERRORLOG::ErrlEntry (
                                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                MOD_DECONFIG_TARGETS_FROM_GARD_AND_VPD,
                                RC_HB_SBE_DECONFIG_MISMATCHES_EXIST,
                                0,
                                0);

                        l_errLog->collectTrace(HWAS_COMP_NAME);
                    }

                    matchError->plid(l_errLog->plid());
                    errlCommit(matchError, HWAS_COMP_ID);
                }
            }
        }
    } while (0);

    HWAS_INF(EXIT_MRK"verifyDeconfiguration");

    return l_errLog;
} // verifyDeconfiguration


void crosscheck_sp_presence()
{
    errlHndl_t l_errhdl = nullptr;
    errlHndl_t firstErr = nullptr;

    // Loop through every target to check any with the attribute
    for( TARGETING::TargetIterator target = TARGETING::targetService().begin();
         target != TARGETING::targetService().end();
         ++target )
    {
        l_errhdl = crosscheck_sp_presence_target(*target);
        if(l_errhdl)
        {
            // Store the first error in order to link any later related errors
            // to it
            if(!firstErr)
            {
                firstErr = l_errhdl;
                l_errhdl = nullptr;
            }
            else
            {
                l_errhdl->plid(firstErr->plid());
                errlCommit (l_errhdl, HWAS_COMP_ID);
            }
        }
    }

    if(firstErr)
    {
        errlCommit (firstErr, HWAS_COMP_ID);
    }
}

errlHndl_t crosscheck_sp_presence_target(TARGETING::Target * i_target)
{
    errlHndl_t l_errhdl = nullptr;

    assert (i_target != nullptr, "crosscheck_sp_presence_target i_target == nullptr");

    HWAS_DBG(ENTER_MRK"crosscheck_sp_presence_target: i_target=0x%.8X",
             TARGETING::get_huid(i_target));

    do
    {
        TARGETING::ATTR_FOUND_PRESENT_BY_SP_type sp_presence =
          TARGETING::FOUND_PRESENT_BY_SP_NO_ATTEMPT;
        if( !(i_target->tryGetAttr<TARGETING::ATTR_FOUND_PRESENT_BY_SP>(sp_presence)) )
        {
            // not relevant for this target
            break;
        }

        // check what we determined
        bool hb_presence = i_target->getAttr<TARGETING::ATTR_HWAS_STATE>().present;

        // SP did not attempt presence-detection, nothing to cross-check
        if( (TARGETING::FOUND_PRESENT_BY_SP_NO_ATTEMPT == sp_presence)
            || (TARGETING::FOUND_PRESENT_BY_SP_SKIP == sp_presence) )
        {
            // nothing to do here
            break;
        }
        // HB sees it but the SP didn't
        else if( hb_presence &&
                 (TARGETING::FOUND_PRESENT_BY_SP_MISSING == sp_presence) )
        {
            HWAS_INF("0x%.8X detected by Hostboot but not by the Service Processor",
                     TARGETING::get_huid(i_target));
            /*@
             * @errortype
             * @moduleid     MOD_CROSSCHECK_SP_PRESENCE
             * @reasoncode   RC_PRESENCE_MISMATCH_SP
             * @userdata1    HUID of missing target
             * @devdesc      Hostboot detected a part that the service
             *               processor did not.
             * @custdesc     A problem occurred during the IPL
             *               of the system.
             */
            l_errhdl = new ERRORLOG::ErrlEntry(
                             ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                             MOD_CROSSCHECK_SP_PRESENCE,
                             RC_PRESENCE_MISMATCH_SP,
                             TARGETING::get_huid(i_target),
                             0);
            // most likely to be a hardware issue of some kind
            //  knock it out so we agree with the SP
            l_errhdl->addHwCallout( i_target,
                                    HWAS::SRCI_PRIORITY_HIGH,
                                    HWAS::DECONFIG,
                                    HWAS::GARD_NULL);
            // could also be a code bug on the SP
            l_errhdl->addProcedureCallout( HWAS::EPUB_PRC_SP_CODE,
                                           HWAS::SRCI_PRIORITY_MED );
            l_errhdl->collectTrace(ISTEP_COMP_NAME,256);
            l_errhdl->collectTrace(HWAS_COMP_NAME,256);

        }
        // The SP sees it but HB didn't
        else if( !hb_presence &&
                 (TARGETING::FOUND_PRESENT_BY_SP_FOUND == sp_presence) )
        {
            HWAS_INF("0x%.8X detected by the Service Processor but not by Hostboot",
                     TARGETING::get_huid(i_target));

            HWAS::GARD_ErrorType gardType = HWAS::GARD_NULL;
            if(i_target->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_TPM)
            {
                // If target could have a deferred presence detect, fatally
                // guard it to prevent Hostboot from inadvertently resurrecting
                // it later and triggering endless failovers.  One such case,
                // absent this mitigation, is if both TPMs in a node hit
                // this flavor of mismatch and the "TPM Required Policy" is
                // "Required".  In that case the system flags the primary TPM
                // as bad, then fails over to the other FSP and attempts a new
                // boot.  On that boot, discovery assumes the backup TPM
                // is present and functional until it can check it in istep
                // 10.3, but the bad primary TPM leads to a termination first,
                // causing the backup's "good" present/functional status to
                // replicate down to the FSP.  This fools the alignment check to
                // think the original primary TPM is now good and thus the
                // alignment check forces a fail over back to the original FSP
                // where the cycle starts over.
                //
                // Guard records can only be placed on present targets, so
                // force state to what SP believes and guard it. Force the TPM
                // to be functional too so that the EID can be correctly
                // displayed in the gard tool.
                auto state = i_target->getAttr<TARGETING::ATTR_HWAS_STATE>();
                state.present = 0b1;
                state.functional = 0b1;
                i_target->setAttr<TARGETING::ATTR_HWAS_STATE>(state);
                gardType = HWAS::GARD_Fatal;
            }

            /*@
             * @errortype
             * @moduleid     MOD_CROSSCHECK_SP_PRESENCE
             * @reasoncode   RC_PRESENCE_MISMATCH_HB
             * @userdata1    HUID of missing target
             * @devdesc      Hostboot did not detect a part that the service
             *               processor found.
             * @custdesc     A problem occurred during the IPL
             *               of the system.
             */
            l_errhdl = new ERRORLOG::ErrlEntry(
                             ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                             MOD_CROSSCHECK_SP_PRESENCE,
                             RC_PRESENCE_MISMATCH_HB,
                             TARGETING::get_huid(i_target),
                             0);

            // Problem is most likely a hardware issue of some kind; knock
            // it out so Hostboot agrees with the SP.
            l_errhdl->addHwCallout( i_target,
                                    HWAS::SRCI_PRIORITY_HIGH,
                                    HWAS::DECONFIG,
                                    gardType);
            // could also be a code bug in HB
            l_errhdl->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                           HWAS::SRCI_PRIORITY_MED );
            l_errhdl->collectTrace(ISTEP_COMP_NAME,256);
            l_errhdl->collectTrace(HWAS_COMP_NAME,256);
            l_errhdl->collectTrace(FSI_COMP_NAME,256);
            l_errhdl->collectTrace(I2C_COMP_NAME,256);
            l_errhdl->collectTrace(SPI_COMP_NAME,256);
            l_errhdl->collectTrace(EEPROM_COMP_NAME,256);
        }
        // otherwise we match so we're fine

    } while (0);

    HWAS_DBG(EXIT_MRK"crosscheck_sp_presence_target");

    return l_errhdl;
}

} // namespace HWAS
