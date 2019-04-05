/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/hwasPlat.C $                                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2019                        */
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
#include <vpd/mvpdenums.H>
#include <stdio.h>
#include <sys/mm.h>
#include <sys/misc.h>

#include <pnor/pnorif.H>

#include <hwas/common/hwas_reasoncodes.H>
#include <targeting/common/utilFilter.H>
#include <fsi/fsiif.H>
#include <config.h>
#include <targeting/common/targetservice.H>
#include <chipids.H>
#include <vpd/spdenums.H>

#include <map>

#ifdef CONFIG_SUPPORT_EEPROM_CACHING
#include <i2c/eepromif.H>
#endif

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
    errlHndl_t l_errl =
      DeviceFW::deviceWrite(i_target,
                            nullptr,
                            sz,
                            DEVICE_IDEC_ADDRESS());

    return l_errl;
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

    // At the time when we read IDEC, the tp chiplet of Centaur & slave
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

/* @brief A helper function used to convert the contents of the IDEC register
 *        to the CFAM ID format.
 *
 * @param[in]  i_idec       The contents of the IDEC register
 *
 * @return     uint64_t     The converted result.
 */
uint64_t formatOcmbIdecToCfamStandard(const uint64_t i_idec)
{
    uint64_t convertedIdec = 0;

    // Need to convert register contents from Mm0L00CC to MLmCC000
    uint32_t idec = static_cast<uint32_t>(i_idec);
    uint32_t major = 0xF0000000 & idec;
    uint32_t minor = 0x0F000000 & idec;
    uint32_t location = 0x000F0000 & idec;
    convertedIdec = (major | (location << 8) | (minor >> 4)
                    | ((idec & 0x000000FF) << 12));

    return convertedIdec;
}

errlHndl_t ocmbIDEC(DeviceFW::OperationType i_opType,
                    TARGETING::Target* i_target,
                    void* io_buffer,
                    size_t& io_buflen,
                    int64_t i_accessType,
                    va_list i_args)
{
    //@fixme when we know what register to read the IDEC from.
    const uint16_t OCMB_IDEC_REGISTER = 0x2134;

    uint64_t idec = 0;
    size_t op_size = sizeof(idec);
    errlHndl_t error = nullptr;

    // Read the ID/EC
    error = DeviceFW::deviceRead(i_target,
                                 &idec,
                                 op_size,
                                 DEVICE_SCOM_ADDRESS(OCMB_IDEC_REGISTER));

    do {

        if (error != nullptr)
        {
            HWAS_ERR("ocmbIDEC> OCMB 0x%.8X - failed to read ID/EC",
                     TARGETING::get_huid(i_target));

            break;
        }

        assert(op_size == sizeof(idec), "ocmbIDEC> Size returned from OCMB "
              "IDEC read size %d  not the expected size %d",
              op_size, sizeof(idec));

        idec = formatOcmbIdecToCfamStandard(idec);

        uint8_t ec = POWER_CHIPID::extract_ddlevel(idec);
        uint32_t id = POWER_CHIPID::extract_chipid16(idec);

        HWAS_DBG("ocmbIDEC> OCMB 0x%.8X - read ID/EC successful. "
                 "ID = 0x%.4X, EC = 0x%.2X, Full IDEC 0x%x",
                 TARGETING::get_huid(i_target),
                 id,
                 ec,
                 idec);

        // Verify the OCMB ID is an expected value

        // Allocate buffer to hold SPD and init to 0
        size_t spdBufferSize = SPD::OCMB_SPD_EFD_COMBINED_SIZE;
        uint8_t* spdBuffer = new uint8_t[spdBufferSize];
        memset(spdBuffer, 0, spdBufferSize);

        // Read the full SPD.
        error = deviceRead(i_target,
                           spdBuffer,
                           spdBufferSize,
                           DEVICE_SPD_ADDRESS(SPD::ENTIRE_SPD));

        // If unable to retrieve the SPD buffer then can't
        // extract the IDEC data, so return error.
        if (error)
        {
            HWAS_ERR("ocmbIDEC> Error while trying to read "
                     "ENTIRE SPD from 0x%.08X ",
                     TARGETING::get_huid(i_target));
            break;
        }

        // Make sure we got back the size we were expecting.
        assert(spdBufferSize == SPD::OCMB_SPD_EFD_COMBINED_SIZE,
              "ocmbIDEC> OCMB SPD read size %d "
              "doesn't match the expected size %d",
              spdBufferSize,
              SPD::OCMB_SPD_EFD_COMBINED_SIZE);

       // SPD IDEC info is in the following three bytes
       const size_t SPD_ID_LEAST_SIGNIFICANT_BYTE_OFFSET = 198;
       const size_t SPD_ID_MOST_SIGNIFICANT_BYTE_OFFSET  = 199;
       const size_t SPD_EC_OFFSET                        = 200;

       // Get the ID from the SPD and verify that it matches what we read from
       // the IDEC register.
       uint16_t spdId = 0;

       spdId = TWO_UINT8_TO_UINT16(
               *(spdBuffer + SPD_ID_MOST_SIGNIFICANT_BYTE_OFFSET),
               *(spdBuffer + SPD_ID_LEAST_SIGNIFICANT_BYTE_OFFSET));

       uint8_t spdEc = *(spdBuffer + SPD_EC_OFFSET);

        // This map will hold the associated values between what is read from
        // the OCMB's IDEC register and the SPD since they use different
        // standards and thus cannot be directly compared.
        // @TODO RTC 205563 Fix Gemini info when it is known.
        const uint32_t GEMINI_ID        = 0x20D2;
        const uint32_t GEMINI_SPD_ID    = 0x80A4;
        const uint32_t GEMINI_EC        = 0x0000;
        const uint32_t GEMINI_SPD_EC    = 0x0000;
        const uint32_t EXPLORER_SPD_ID  = 0x2980;
        const uint32_t EXPLORER_EC      = 0x0010;
        const uint32_t EXPLORER_SPD_EC  = 0x0000;
        const std::map<uint32_t, uint32_t> OCMB_ID_SPD_ASSOCIATION_MAP
        {
            {POWER_CHIPID::EXPLORER_16, EXPLORER_SPD_ID},
            {GEMINI_ID, GEMINI_SPD_ID},
        };

        const std::map<uint32_t, uint32_t> OCMB_EC_SPD_ASSOCIATION_MAP
        {
            {EXPLORER_EC, EXPLORER_SPD_EC},
            {GEMINI_EC, GEMINI_SPD_EC},
        };

        auto id_it = OCMB_ID_SPD_ASSOCIATION_MAP.find(id);
        auto ec_it = OCMB_EC_SPD_ASSOCIATION_MAP.find(ec);

        if ((  id_it == OCMB_ID_SPD_ASSOCIATION_MAP.end())
            || ec_it == OCMB_EC_SPD_ASSOCIATION_MAP.end())
        {
            HWAS_ERR("ocmbIDEC> Unexpected ID/EC value.");

           /*@
           * @errortype
           * @severity          ERRL_SEV_UNRECOVERABLE
           * @moduleid          MOD_OCMB_IDEC
           * @reasoncode        RC_OCMB_UNEXPECTED_IDEC
           * @userdata1[00:31]  ID (Chip ID)
           * @userdata1[32:63]  EC (Revision)
           * @userdata2         HUID of OCMB target
           * @devdesc           The IDEC values read from the OCMB did not
           *                    appear in the IDEC to SPD association map.
           *                    Please update the map with new values.
           * @custdesc          Firmware Error
           */
           error = hwasError(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                             MOD_OCMB_IDEC,
                             RC_OCMB_UNEXPECTED_IDEC,
                             TWO_UINT32_TO_UINT64(id, ec),
                             TARGETING::get_huid(i_target));

           break;

        }

        if ((id_it->second != spdId) || (ec_it->second != spdEc))
        {
           HWAS_ERR("ocmbIDEC> OCMB IDEC and associated SPD IDEC don't match: "
                    "OCMB ID=0x%.4X, EC=0x%.2X; SPD ID=0x%.4X, EC=0x%.2X; "
                    "Expected SPD ID=0x%.4X, EC=0x%.2X",
                    id, ec, spdId, spdEc, id_it->second, ec_it->second);

           uint32_t bothIds = TWO_UINT16_TO_UINT32(id, spdId);
           uint32_t bothEcs = TWO_UINT16_TO_UINT32(ec, spdEc);

           /*@
           * @errortype
           * @severity          ERRL_SEV_UNRECOVERABLE
           * @moduleid          MOD_OCMB_IDEC
           * @reasoncode        RC_OCMB_SPD_IDEC_MISMATCH
           * @userdata1[00:15]  OCMB ID from device read
           * @userdata1[16:31]  SPD ID from device read
           * @userdata1[32:47]  OCMB EC from device read
           * @userdata1[48:63]  SPD EC from device read
           * @userdata2         HUID of OCMB target
           * @devdesc           The IDEC info read from the OCMB and SPD
           *                    did not match the expected values.
           * @custdesc          Firmware Error
           */
           error = hwasError(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                             MOD_OCMB_IDEC,
                             RC_OCMB_SPD_IDEC_MISMATCH,
                             TWO_UINT32_TO_UINT64(bothIds, bothEcs),
                             TARGETING::get_huid(i_target));

           break;

        }

        // set the explorer chip EC attributes.
        i_target->setAttr<TARGETING::ATTR_EC>(ec);
        i_target->setAttr<TARGETING::ATTR_HDAT_EC>(ec);

        // set the explorer chip id attribute.
        i_target->setAttr<TARGETING::ATTR_CHIP_ID>(id);

    } while(0);

    return error;
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
#if 0
// Unit test. set P8_MURANO.config to have 4 procs, and this code will
//  alter the VPD so that some of the procs and chiplets should get marked
//  as NOT functional.
        {
            // skip past the header
            uint16_t *pgData = reinterpret_cast <uint16_t *>(&pgRaw[VPD_CP00_PG_HDR_LENGTH]);
            if (i_target->getAttr<ATTR_HUID>() == 0x50000)
            {   // 1st proc
                pgData[VPD_CP00_PG_EX0_INDEX+4] = 0xF300;
                pgData[VPD_CP00_PG_EX0_INDEX+5] = 0xF300;
                pgData[VPD_CP00_PG_EX0_INDEX+6] = 0x9300; // off
                pgData[VPD_CP00_PG_EX0_INDEX+12] = 0x9300; // off
                pgData[VPD_CP00_PG_EX0_INDEX+13] = 0x9300; // off
                pgData[VPD_CP00_PG_EX0_INDEX+14] = 0x9300; // off
            }
            else
            if (i_target->getAttr<ATTR_HUID>() == 0x50001)
            {   // 2nd proc
                pgData[VPD_CP00_PG_EX0_INDEX+4] = 0xF300;
                pgData[VPD_CP00_PG_EX0_INDEX+5] = 0xF300;
                pgData[VPD_CP00_PG_EX0_INDEX+6] = 0xF300;
                pgData[VPD_CP00_PG_EX0_INDEX+12] = 0xF300;
                pgData[VPD_CP00_PG_EX0_INDEX+13] = 0xF300;
                pgData[VPD_CP00_PG_EX0_INDEX+14] = 0xF300;
            }
            else
            if (i_target->getAttr<ATTR_HUID>() == 0x50002)
            {   // 3rd proc
                //// mark Pervasive bad - entire chip
                ////  should be marked present and NOT functional
                ////pgData[VPD_CP00_PG_PERVASIVE_INDEX] = 0;

                pgData[VPD_CP00_PG_EX0_INDEX+4] = 0xF300;
                pgData[VPD_CP00_PG_EX0_INDEX+5] = 0xF300;
                pgData[VPD_CP00_PG_EX0_INDEX+6] = 0x9300; // off
                pgData[VPD_CP00_PG_EX0_INDEX+12] = 0x9300; // off
                pgData[VPD_CP00_PG_EX0_INDEX+13] = 0xF300;
                pgData[VPD_CP00_PG_EX0_INDEX+14] = 0xF300;
            }
            else
            if (i_target->getAttr<ATTR_HUID>() == 0x50003)
            {   // 4th proc -  EX13 and EX14 are good
                pgData[VPD_CP00_PG_EX0_INDEX+4] = 0xF300;
                pgData[VPD_CP00_PG_EX0_INDEX+5] = 0xF300;
                pgData[VPD_CP00_PG_EX0_INDEX+6] = 0x9300; // off
                pgData[VPD_CP00_PG_EX0_INDEX+12] = 0x9300; // off
                pgData[VPD_CP00_PG_EX0_INDEX+13] = 0x9300; // off
                pgData[VPD_CP00_PG_EX0_INDEX+14] = 0x9300; // off
            }
        }
#endif

        // skip past the header
        void *pgData = static_cast<void *>(&pgRaw[VPD_CP00_PG_HDR_LENGTH]);
        HWAS_DBG_BIN("PG record", pgData, VPD_CP00_PG_DATA_LENGTH);
        // copy the data back into the caller's buffer
        memcpy(o_pgData, pgData, VPD_CP00_PG_DATA_LENGTH);
    }

    return errl;
} // platReadPartialGood

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
#if    defined(CONFIG_MEMVPD_WRITE_TO_PNOR) || \
       defined(CONFIG_PVPD_WRITE_TO_PNOR)
        errl = PNOR::clearSection( PNOR::CENTAUR_VPD );
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
#ifdef CONFIG_SUPPORT_EEPROM_CACHING
        TARGETING::EepromVpdPrimaryInfo eepromData;
        if (pTarget->tryGetAttr<ATTR_EEPROM_VPD_PRIMARY_INFO>(eepromData))
        {
            HWAS_INF( "Reading EEPROMs for target, eeprom type = %d , target present = %d , eeprom type = %d",
                      DEVICE_CACHE_EEPROM_ADDRESS(present, EEPROM::VPD_PRIMARY));
            errl = deviceRead(pTarget, &present, presentSize,
                            DEVICE_CACHE_EEPROM_ADDRESS(present, EEPROM::VPD_PRIMARY));
            errlCommit(errl, HWAS_COMP_ID);
            // errl is now null, move on to next target
        }
#endif
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

} // namespace HWAS
