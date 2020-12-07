/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/eeprom/eeprom_utils.C $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
#include <eeprom/eepromif.H>
#include <i2c/i2cif.H>
#include <errl/errlmanager.H>
#include <errl/errludstring.H>
#include <eeprom/eepromddreasoncodes.H>
#include <eeprom/eeprom_const.H>
#include <i2c/i2c_common.H>
#include <fsi/fsiif.H>


// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
trace_desc_t* g_trac_eeprom = NULL;
TRAC_INIT( & g_trac_eeprom, EEPROM_COMP_NAME, KILOBYTE );

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

namespace EEPROM
{

#ifndef __HOSTBOOT_RUNTIME

/**
* @brief Check if the target gets its VPD from a remote source
*        such as the BMC. This function will check the VPD_SWITCHES
*        attribute to see if vpdCollectedRemotely is set, if set
*        this indicates a remote source thinks this target is present
*        and has given us the VPD associated with it.
*
* @param[in] i_target Target we want to query for whether it has a remote VPD source or not
*
* @return bool True if vpdCollectedRemotely bit on ATTR_VPD_SWITCHES is true
*
* @note targets that do not have ATTR_VPD_SWITCHES will always return false
*
*/
bool hasRemoteVpdSource(TARGETING::Target * i_target)
{
    bool vpd_source_is_remote = false;
    TARGETING::ATTR_VPD_SWITCHES_type vpd_switch = {0};
    // If the target does not have this attribute we can assume
    // it was not collected remotely
    if(i_target->tryGetAttr<TARGETING::ATTR_VPD_SWITCHES>(vpd_switch))
    {
        vpd_source_is_remote = vpd_switch.vpdCollectedRemotely;
    }
    return vpd_source_is_remote;
}

//-------------------------------------------------------------------
//eepromPresence
//-------------------------------------------------------------------
bool eepromPresence ( TARGETING::Target * i_target )
{
    TRACUCOMP(g_trac_eeprom, ENTER_MRK"eepromPresence() 0x%.8X",
      TARGETING::get_huid(i_target));

    errlHndl_t err = nullptr;
    TARGETING::Target * l_eepromMasterTarget = nullptr;
    TARGETING::Target* l_masterProcTarget = nullptr;
    bool l_present = false;

    eeprom_addr_t eepInfo;

    eepInfo.eepromRole = EEPROM::VPD_PRIMARY;
    eepInfo.offset = 0;
    do
    {
        if(hasRemoteVpdSource(i_target))
        {
            TRACFCOMP(g_trac_eeprom,
                     "eepromPresence: Found that VPD for 0x%8x was remotely sourced this IPL, assuming present",
                     TARGETING::get_huid(i_target));
            l_present = true;
            break;
        }

        // Read Attributes needed to complete the operation
        err = eepromReadAttributes( i_target, eepInfo );
        if( err )
        {
            TRACFCOMP(g_trac_eeprom,
                     ERR_MRK"Error in eepromPresence::eepromReadAttributes()");
            break;
        }

        // Check to see if we need to find a new target for master
        err = eepromGetMasterTarget( i_target,
                                     eepInfo,
                                     l_eepromMasterTarget );
        if( err )
        {
            TRACFCOMP(g_trac_eeprom,
                     ERR_MRK"Error in eepromPresence::eepromGetMasterTarget()");
            break;
        }

        // Master proc is taken as always present. Validate other targets.
        TARGETING::targetService().masterProcChipTargetHandle(l_masterProcTarget );
        if (l_eepromMasterTarget != l_masterProcTarget)
        {
            // Use the FSI slave presence detection to see if master can be found
            if( ! FSI::isSlavePresent(l_eepromMasterTarget) )
            {
                TRACDCOMP( g_trac_eeprom,
                           "eepromPresence> FSI::isSlavePresent returned false for eeprom Master Target %.08X",
                           TARGETING::get_huid(l_eepromMasterTarget) );
                l_present = false;
                break;
            }
        }

        if (eepInfo.accessMethod == EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_I2C)
        {
            // If the target has dynamic device address attribute, then use that instead of the
            // read-only address found in ATTR_EEPROM_XX_INFO attrs. We use the dynamic address
            // attribute because ATTR_EEPROM_XX_INFO attrs are not writable and its difficult
            // to override complex attributes.
            if(i_target->tryGetAttr<TARGETING::ATTR_DYNAMIC_I2C_DEVICE_ADDRESS>(eepInfo.accessAddr.i2c_addr.devAddr))
            {
                TRACDCOMP(g_trac_eeprom,
                         "Using DYNAMIC_I2C_DEVICE_ADDRESS %.2x for HUID %.8x",
                          eepInfo.accessAddr.i2c_addr.devAddr,
                          TARGETING::get_huid(i_target));
            }

            //Check for the target at the I2C level
            l_present = I2C::i2cPresence(l_eepromMasterTarget,
                              eepInfo.accessAddr.i2c_addr.port,
                              eepInfo.accessAddr.i2c_addr.engine,
                              eepInfo.accessAddr.i2c_addr.devAddr,
                              eepInfo.accessAddr.i2c_addr.i2cMuxBusSelector,
                              eepInfo.accessAddr.i2c_addr.i2cMuxPath);
        }
        else if (eepInfo.accessMethod == EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_SPI)
        {
            // RTC 251866 - implement spiPresence
            /*
            // Check for the target at the SPI level
            l_present = SPI::spiPresence(masterTarget,
                                         eepInfo.accessAddr.spi_addr.engine,
                                         eepInfo.accessAddr.spi_addr.devAddr);
            */
            // For now just default to true if the eeprom masterTarget is present
            l_present = true;
        }
        if( !l_present )
        {
            TRACDCOMP(g_trac_eeprom,
                     ERR_MRK"Presence check returned false! chip NOT present!");
            break;
        }

    } while( 0 );

    // If there was an error commit the error log
    if( err )
    {
        errlCommit( err, EEPROM_COMP_ID );
    }

    TRACDCOMP(g_trac_eeprom, EXIT_MRK"eepromPresence()");
    return l_present;
}
#endif // __HOSTBOOT_RUNTIME

/**
 *
 * @brief A useful utility to dump (trace out) the EepromVpdPrimaryInfo data.
 *        Use as needed.
 *
 * @param [in] i_i2cInfo - The EepromVpdPrimaryInfo data to dump for user
 *
 */
void dumpEepromData(const TARGETING::EepromVpdPrimaryInfo & i_i2cInfo)
{
    TRACFCOMP (g_trac_eeprom, INFO_MRK"EepromVpdPrimaryInfo data: "
               "engine=%d, port=%d, devAddr=0X%X, writePageSize=%d, "
               "maxMemorySizeKB=0x%X, chipCount=%d, writeCycleTime=%d",
               i_i2cInfo.engine, i_i2cInfo.port, i_i2cInfo.devAddr,
               i_i2cInfo.writePageSize, i_i2cInfo.maxMemorySizeKB,
               i_i2cInfo.chipCount, i_i2cInfo.writeCycleTime);

    char* l_masterPath = i_i2cInfo.i2cMasterPath.toString();
    char* l_muxPath = i_i2cInfo.i2cMuxPath.toString();
    TRACFCOMP (g_trac_eeprom, INFO_MRK"EepromVpdPrimaryInfo data cont.: "
              "masterPath=%s, muxSelector=0x%X, muxPath=%s",
              l_masterPath, i_i2cInfo.i2cMuxBusSelector, l_muxPath);

    free(l_masterPath);
    free(l_muxPath);
    l_masterPath = l_muxPath = nullptr;
}

/**
 *
 * @brief A useful utility to dump (trace out) the SpiEepromVpdPrimaryInfo data.
 *        Use as needed.
 *
 * @param [in] i_spiInfo - The SpiEepromVpdPrimaryInfo data to dump for user
 *
 */
void dumpEepromData(const TARGETING::SpiEepromVpdPrimaryInfo & i_spiInfo)
{
    char* l_masterPath = i_spiInfo.spiMasterPath.toString();
    TRACFCOMP (g_trac_eeprom, INFO_MRK"SpiEepromVpdPrimaryInfo data: "
               "masterPath=%s engine=%d, dataSizeKB=0x%X, dataOffsetKB=%d",
               l_masterPath, i_spiInfo.engine,
               i_spiInfo.dataSizeKB, i_spiInfo.dataOffsetKB);

    free(l_masterPath);
    l_masterPath = nullptr;
}

/**
 *
 * @brief A useful utility to dump (trace out) the eeprom_addr_t data.
 *         Use as needed.
 *
 * @param [in] i_eepInfo - The eeprom_addr_t data to dump for user
 *
 */
void dumpEepromData(const eeprom_addr_t & i_eepInfo)
{
    switch (i_eepInfo.accessMethod)
    {
        case EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_UNKNOWN:
        {
            TRACFCOMP(g_trac_eeprom, INFO_MRK"eeprom_addr_t data: EEPROM_HW_ACCESS_METHOD_UNKNOWN");
            break;
        }
        case EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_I2C:
        {
            TRACFCOMP (g_trac_eeprom, INFO_MRK"eeprom_addr_t data: "
                "engine=%d, port=%d, devAddr=0X%X, writePageSize=%d, "
                "devSize_KB=0x%X, chipCount=%d, writeCycleTime=%d",
                i_eepInfo.accessAddr.i2c_addr.engine,
                i_eepInfo.accessAddr.i2c_addr.port,
                i_eepInfo.accessAddr.i2c_addr.devAddr,
                i_eepInfo.accessAddr.i2c_addr.writePageSize,
                i_eepInfo.devSize_KB, i_eepInfo.accessAddr.i2c_addr.chipCount,
                i_eepInfo.accessAddr.i2c_addr.writeCycleTime);

            char* l_masterPath = i_eepInfo.accessAddr.i2c_addr.i2cMasterPath.toString();
            char* l_muxPath = i_eepInfo.accessAddr.i2c_addr.i2cMuxPath.toString();
            TRACFCOMP (g_trac_eeprom, INFO_MRK"eeprom_addr_t data cont.: "
                "eepromRole=0x%X, i2cMasterPath=%s, muxSelector=0x%X, muxPath=%s",
                i_eepInfo.eepromRole, l_masterPath,
                i_eepInfo.accessAddr.i2c_addr.i2cMuxBusSelector, l_muxPath);

            free(l_masterPath);
            free(l_muxPath);
            l_masterPath = l_muxPath = nullptr;
            break;
        }
        case EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_SPI:
        {
            char * l_masterPath = i_eepInfo.accessAddr.spi_addr.spiMasterPath.toString();
            TRACFCOMP(g_trac_eeprom, INFO_MRK"eeprom_addr_t data: "
                "eepromRole=0x%X, spiMasterPath=%s, engine=%d, "
                "roleOffset_KB=0x%X, offset=0x%X, devSize_KB=0x%X",
                i_eepInfo.eepromRole, l_masterPath,
                i_eepInfo.accessAddr.spi_addr.engine,
                i_eepInfo.accessAddr.spi_addr.roleOffset_KB,
                i_eepInfo.offset, i_eepInfo.devSize_KB);
            free(l_masterPath);
            l_masterPath = nullptr;
            break;
        }
        default:
        {
            TRACFCOMP(g_trac_eeprom,INFO_MRK"eeprom_addr_t data: \n"
                      "Unknown access method for eeprom_addr_t: %d",
                      i_eepInfo.accessMethod);
        }
    }
}

/**
 *  @brief Get a common user data piece for eepromRecordHeader record
 *         Format returned:
 *           @userdata1[0:31]  HUID of Master
 *           @userdata1[32:39] Port (or 0xFF)
 *           @userdata1[40:47] Engine
 *           @userdata1[48:55] devAddr    (or byte 0 offset_KB)
 *           @userdata1[56:63] mux_select (or byte 1 offset_KB)
 *  @param Filled in eeprom record header
 *  @return userdata for this eeprom record
 */
uint64_t getEepromHeaderUserData(const eepromRecordHeader& i_eepromRecordHeader)
{
    uint64_t l_userdata1 = 0;
    if (i_eepromRecordHeader.completeRecord.accessType ==
        EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_I2C)
    {
        l_userdata1 = TWO_UINT32_TO_UINT64(
            i_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.i2c_master_huid,
            TWO_UINT16_TO_UINT32(
              TWO_UINT8_TO_UINT16(i_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.port,
                                  i_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.engine),
              TWO_UINT8_TO_UINT16(i_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.devAddr,
                                  i_eepromRecordHeader.completeRecord.eepromAccess.i2cAccess.mux_select)));
    }
    else
    {
        l_userdata1 = TWO_UINT32_TO_UINT64(
            i_eepromRecordHeader.completeRecord.eepromAccess.spiAccess.spi_master_huid,

            TWO_UINT16_TO_UINT32(
              TWO_UINT8_TO_UINT16(0xFF,
                i_eepromRecordHeader.completeRecord.eepromAccess.spiAccess.engine),
              i_eepromRecordHeader.completeRecord.eepromAccess.spiAccess.offset_KB) );
    }
    return l_userdata1;
}

// ------------------------------------------------------------------
// eepromReadAttributes
// ------------------------------------------------------------------
errlHndl_t eepromReadAttributes ( TARGETING::Target * i_target,
                                  eeprom_addr_t & io_eepromAddr )
{
    errlHndl_t err = NULL;
    bool found_i2c_eep = false;
    bool found_spi_eep = false;

    TRACUCOMP( g_trac_eeprom,
               ENTER_MRK"eepromReadAttributes(), role %d",
               io_eepromAddr.eepromRole );

    // This variable will be used to hold the EEPROM attribute data
    // Note:  each 'EepromVpd' struct is kept the same via the attributes
    //        so will be copying each to eepromData to save code space
    TARGETING::EepromVpdPrimaryInfo eepromData;
    TARGETING::SpiMvpdPrimaryInfo spiEepromData;

    do
    {
        switch (io_eepromAddr.eepromRole )
        {
            case VPD_AUTO:
            case VPD_PRIMARY:
                if( i_target->
                    tryGetAttr<TARGETING::ATTR_EEPROM_VPD_PRIMARY_INFO>
                    ( eepromData ) )
                {
                    found_i2c_eep = true;
                }
                else if (i_target->
                    tryGetAttr<TARGETING::ATTR_SPI_MVPD_PRIMARY_INFO>
                    (spiEepromData) )
                {
                    found_spi_eep = true;
                }
                break;

            case VPD_BACKUP:

                if( i_target->
                    tryGetAttr<TARGETING::ATTR_EEPROM_VPD_BACKUP_INFO>
                    (reinterpret_cast<
                     TARGETING::ATTR_EEPROM_VPD_BACKUP_INFO_type&>
                     ( eepromData )) )
                {
                    found_i2c_eep = true;
                }
                else if ( i_target->
                          tryGetAttr<TARGETING::ATTR_SPI_MVPD_BACKUP_INFO>
                          (reinterpret_cast<
                           TARGETING::ATTR_SPI_MVPD_BACKUP_INFO_type&>
                           (spiEepromData)) )
                {
                    found_spi_eep = true;
                }
                break;

            case SBE_PRIMARY:
                if ( i_target->
                          tryGetAttr<TARGETING::ATTR_SPI_SBE_BOOT_CODE_PRIMARY_INFO>
                          (reinterpret_cast<
                           TARGETING::ATTR_SPI_SBE_BOOT_CODE_PRIMARY_INFO_type&>
                           (spiEepromData)) )
                {
                    found_spi_eep = true;
                }
                break;

            case SBE_BACKUP:
                if ( i_target->
                          tryGetAttr<TARGETING::ATTR_SPI_SBE_BOOT_CODE_BACKUP_INFO>
                          (reinterpret_cast<
                           TARGETING::ATTR_SPI_SBE_BOOT_CODE_BACKUP_INFO_type&>
                           (spiEepromData)) )
                {
                    found_spi_eep = true;
                }
                break;

            case WOF_DATA:
                if (i_target->tryGetAttr<TARGETING::ATTR_SPI_WOF_DATA_INFO>
                   (reinterpret_cast<TARGETING::ATTR_SPI_WOF_DATA_INFO_type&>
                   (spiEepromData)))
                {
                    found_spi_eep = true;
                }
                break;

            case SPARE_TEST:
                if (
                  i_target->tryGetAttr<TARGETING::ATTR_SPI_EEPROM_SPARE_INFO>
                  ( reinterpret_cast<
                      TARGETING::ATTR_SPI_EEPROM_SPARE_INFO_type&>
                      (spiEepromData) ) )
                {
                    found_spi_eep = true;
                }
                break;

            default:
                TRACFCOMP( g_trac_eeprom,ERR_MRK"eepromReadAttributes() - "
                           "Invalid chip (%d) to read attributes from!",
                            io_eepromAddr.eepromRole );

                /*@
                 * @errortype
                 * @reasoncode       EEPROM_INVALID_CHIP
                 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid         EEPROM_READATTRIBUTES
                 * @userdata1        EEPROM Chip
                 * @userdata2        HUID of target
                 * @devdesc          Invalid EEPROM chip to access
                 */
                err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           EEPROM_READATTRIBUTES,
                                           EEPROM_INVALID_CHIP,
                                           io_eepromAddr.eepromRole,
                                           TARGETING::get_huid(i_target),
                                           true /*Add HB SW Callout*/ );

                err->collectTrace( EEPROM_COMP_NAME );

                break;
        }

        if (err)
        {
            break;
        }

        // Check if Attribute Data was found
        if( !found_i2c_eep && !found_spi_eep )
        {
            TRACFCOMP( g_trac_eeprom,
                       ERR_MRK"eepromReadAttributes() - ERROR reading "
                       "attributes for eeprom role %d!",
                       io_eepromAddr.eepromRole );

                /*@
                 * @errortype
                 * @reasoncode       EEPROM_ATTR_INFO_NOT_FOUND
                 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid         EEPROM_READATTRIBUTES
                 * @userdata1        HUID of target
                 * @userdata2        EEPROM chip
                 * @devdesc          EEPROM attribute was not found
                 */
                err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    EEPROM_READATTRIBUTES,
                                    EEPROM_ATTR_INFO_NOT_FOUND,
                                    TARGETING::get_huid(i_target),
                                    io_eepromAddr.eepromRole);

                // Could be FSP or HB code's fault
                err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                         HWAS::SRCI_PRIORITY_MED);
                err->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                         HWAS::SRCI_PRIORITY_MED);

                err->collectTrace( EEPROM_COMP_NAME );

                break;

        }

        if (found_i2c_eep)
        {
            io_eepromAddr.accessMethod = EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_I2C;

            // Successful reading of Attribute, so extract the data
            io_eepromAddr.accessAddr.i2c_addr.port           = eepromData.port;
            io_eepromAddr.accessAddr.i2c_addr.devAddr        = eepromData.devAddr;
            io_eepromAddr.accessAddr.i2c_addr.engine         = eepromData.engine;
            io_eepromAddr.accessAddr.i2c_addr.i2cMasterPath  = eepromData.i2cMasterPath;
            io_eepromAddr.accessAddr.i2c_addr.writePageSize  = eepromData.writePageSize;
            io_eepromAddr.devSize_KB                         = eepromData.maxMemorySizeKB;
            io_eepromAddr.accessAddr.i2c_addr.chipCount      = eepromData.chipCount;
            io_eepromAddr.accessAddr.i2c_addr.writeCycleTime = eepromData.writeCycleTime;
            io_eepromAddr.accessAddr.i2c_addr.i2cMuxBusSelector = eepromData.i2cMuxBusSelector;
            io_eepromAddr.accessAddr.i2c_addr.i2cMuxPath     = eepromData.i2cMuxPath;

            // Convert attribute info to eeprom_addr_size_t enum
            if ( eepromData.byteAddrOffset == 0x3 )
            {
                io_eepromAddr.accessAddr.i2c_addr.addrSize = ONE_BYTE_ADDR;
            }
            else if ( eepromData.byteAddrOffset == 0x2 )
            {
                io_eepromAddr.accessAddr.i2c_addr.addrSize = TWO_BYTE_ADDR;
            }
            else if ( eepromData.byteAddrOffset == 0x1 )
            {
                //@fixme-CQ:SW493992 - lie and force to 2 bytes because MRW is wrong
                //io_eepromAddr.accessAddr.i2c_addr.addrSize = ONE_BYTE_ADDR_PAGESELECT;
                io_eepromAddr.accessAddr.i2c_addr.addrSize = TWO_BYTE_ADDR;
            }
            else if ( eepromData.byteAddrOffset == 0x0 )
            {
                io_eepromAddr.accessAddr.i2c_addr.addrSize = ZERO_BYTE_ADDR;
            }
            else
            {
                TRACFCOMP( g_trac_eeprom,
                           ERR_MRK"eepromReadAttributes() - INVALID ADDRESS "
                           "OFFSET SIZE %d!",
                           io_eepromAddr.accessAddr.i2c_addr.addrSize );

                    /*@
                     * @errortype
                     * @reasoncode       EEPROM_INVALID_ADDR_OFFSET_SIZE
                     * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                     * @moduleid         EEPROM_READATTRIBUTES
                     * @userdata1        HUID of target
                     * @userdata2        Address Offset Size
                     * @devdesc          Invalid address offset size
                     */
                    err = new ERRORLOG::ErrlEntry(
                                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        EEPROM_READATTRIBUTES,
                                        EEPROM_INVALID_ADDR_OFFSET_SIZE,
                                        TARGETING::get_huid(i_target),
                                        io_eepromAddr.accessAddr.i2c_addr.addrSize,
                                        true /*Add HB SW Callout*/ );

                    err->collectTrace( EEPROM_COMP_NAME );

                    break;
            }

            TRACUCOMP(g_trac_eeprom,"eepromReadAttributes() I2C tgt=0x%X, %d/%d/0x%X "
              "devSize_KB=0x%X, aS=%d (%d)",
              TARGETING::get_huid(i_target),
              io_eepromAddr.accessAddr.i2c_addr.port,
              io_eepromAddr.accessAddr.i2c_addr.engine,
              io_eepromAddr.accessAddr.i2c_addr.devAddr,
              io_eepromAddr.devSize_KB,
              io_eepromAddr.accessAddr.i2c_addr.addrSize,
              eepromData.byteAddrOffset);

            // Printing mux info separately, if combined, nothing is displayed
            char* l_muxPath = io_eepromAddr.accessAddr.i2c_addr.i2cMuxPath.toString();
            TRACUCOMP(g_trac_eeprom, "eepromReadAttributes(): "
                      "muxSelector=0x%X, muxPath=%s",
                      io_eepromAddr.accessAddr.i2c_addr.i2cMuxBusSelector,
                      l_muxPath);
            free(l_muxPath);
            l_muxPath = nullptr;

        }
        else if (found_spi_eep)
        {
            io_eepromAddr.accessMethod = EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_SPI;
            io_eepromAddr.accessAddr.spi_addr.spiMasterPath = spiEepromData.spiMasterPath;
            io_eepromAddr.accessAddr.spi_addr.engine = spiEepromData.engine;
            io_eepromAddr.accessAddr.spi_addr.roleOffset_KB = spiEepromData.dataOffsetKB;
            io_eepromAddr.devSize_KB = spiEepromData.dataSizeKB;

            TRACUCOMP( g_trac_eeprom,
                       "eepromReadAttributes() SPI tgt=0x%X engine=0x%X"
                       " - data at 0x%.8X KB, size 0x%.8X KB",
                       TARGETING::get_huid(i_target),
                       io_eepromAddr.accessAddr.spi_addr.engine,
                       io_eepromAddr.accessAddr.spi_addr.roleOffset_KB,
                       io_eepromAddr.devSize_KB );
        }

    } while( 0 );



    TRACDCOMP( g_trac_eeprom,
               EXIT_MRK"eepromReadAttributes()" );

    return err;
} // end eepromReadAttributes


// ------------------------------------------------------------------
// eepromGetMasterTarget
// ------------------------------------------------------------------
errlHndl_t eepromGetMasterTarget ( TARGETING::Target * i_target,
                                   const eeprom_addr_t & i_eepromInfo,
                                   TARGETING::Target * &o_target )
{
    errlHndl_t err = NULL;
    o_target = NULL;
    TARGETING::EntityPath masterPath;
    char masterTypeStr[4];

    TRACDCOMP( g_trac_eeprom,
               ENTER_MRK"eepromGetMasterTarget()" );

    do
    {
        // The path from i_target to its Master was read from the
        // attribute via eepromReadAttributes() and passed to this function
        // in i_eepromInfo
        if (i_eepromInfo.accessMethod ==
            EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_I2C)
        {
            masterPath = i_eepromInfo.accessAddr.i2c_addr.i2cMasterPath;
            strcpy(masterTypeStr, "i2c");
        }
        else
        {
            masterPath = i_eepromInfo.accessAddr.spi_addr.spiMasterPath;
            strcpy(masterTypeStr, "spi");
        }

        TARGETING::TargetService& tS = TARGETING::targetService();

        // check that the path exists
        bool exists = false;
        tS.exists( masterPath, exists );

        if( !exists )
        {
            char * l_masterPathStr = masterPath.toString();
            TRACFCOMP( g_trac_eeprom,
                       ERR_MRK"eepromGetMasterTarget() - "
                       "%sMaster path doesn't exist! %s",
                       masterTypeStr, l_masterPathStr);

            // Compress the entity path
            uint64_t l_epCompressed = 0;
            for( uint32_t i = 0; i < masterPath.size(); i++ )
            {
                // Can only fit 4 path elements into 64 bits
                if ( i <= 3 )
                {
                    // Path element: type:8 instance:8
                    l_epCompressed |=
                        masterPath[i].type << (16*(3-i));
                    l_epCompressed |=
                        masterPath[i].instance << ((16*(3-i))-8);
                }

                // Always trace all of the info even if we cannot fit it in error log
                TRACFCOMP( g_trac_eeprom,
                       ERR_MRK"eepromGetMasterTarget() - "
                       "i_eepromInfo.%sMasterPath[%d].type = %.02X i_eepromInfo.%sMasterPath[%d].instance =  %.02X",
                        masterTypeStr, i, masterPath[i].type,
                        masterTypeStr, i, masterPath[i].instance );

            }

            /*@
             * @errortype
             * @reasoncode       EEPROM_MASTER_PATH_ERROR
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         EEPROM_GET_MASTERTARGET
             * @userdata1[00:31] Attribute Chip Type Enum
             * @userdata1[32:63] HUID of target
             * @userdata2        Compressed Entity Path
             * @devdesc          I2C master entity path doesn't exist.
             */
            err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                EEPROM_GET_MASTERTARGET,
                                EEPROM_MASTER_PATH_ERROR,
                                TWO_UINT32_TO_UINT64(
                                    i_eepromInfo.eepromRole,
                                    TARGETING::get_huid(i_target) ),
                                l_epCompressed,
                                true /*Add HB SW Callout*/ );

            err->collectTrace( EEPROM_COMP_NAME );
            ERRORLOG::ErrlUserDetailsString(l_masterPathStr).addToLog(err);
            free(l_masterPathStr);
            l_masterPathStr = nullptr;

            break;
        }

        // Since it exists, convert to a target
        o_target = tS.toTarget( masterPath );

        if( NULL == o_target )
        {
            TRACFCOMP( g_trac_eeprom,
                       ERR_MRK"eepromGetMasterTarget() - Master "
                              "Path target was NULL!" );

            // Compress the entity path
            uint64_t l_epCompressed = 0;
            for( uint32_t i = 0; i < masterPath.size(); i++ )
            {
                // Can only fit 4 path elements into 64 bits
                if ( i <= 3 )
                {
                    // Path element: type:8 instance:8
                    l_epCompressed |=
                        masterPath[i].type << (16*(3-i));
                    l_epCompressed |=
                        masterPath[i].instance << ((16*(3-i))-8);
                }

                // Always trace all of the info even if we cannot fit it in error log
                TRACFCOMP( g_trac_eeprom,
                       ERR_MRK"eepromGetMasterTarget() - "
                       "masterPath[%d].type = 0x%.02X, "
                       "masterPath[%d].instance = 0x%.02X",
                        i, masterPath[i].type, i, masterPath[i].instance );

            }

            /*@
             * @errortype
             * @reasoncode       EEPROM_TARGET_NULL
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         EEPROM_GET_MASTERTARGET
             * @userdata1[00:31] Eeprom role
             * @userdata1[32:63] HUID of target
             * @userdata2        Compressed Entity Path
             * @devdesc          Master path target is null.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           EEPROM_GET_MASTERTARGET,
                                           EEPROM_TARGET_NULL,
                                           TWO_UINT32_TO_UINT64(
                                               i_eepromInfo.eepromRole,
                                               TARGETING::get_huid(i_target) ),
                                           l_epCompressed,
                                           true /*Add HB SW Callout*/ );

            err->collectTrace( EEPROM_COMP_NAME );

            char* l_masterPathStr = masterPath.toString();
            ERRORLOG::ErrlUserDetailsString(l_masterPathStr).addToLog(err);
            free(l_masterPathStr);
            l_masterPathStr = nullptr;

            break;
        }

    } while( 0 );

    TRACDCOMP( g_trac_eeprom,
               EXIT_MRK"eepromGetMasterTarget()" );

    return err;
} // end eepromGetMasterTarget


/**
 * @brief Compare predicate for EepromInfo_t
 */
class isSameEeprom
{
  public:
    isSameEeprom( const EepromInfo_t& i_first )
    : iv_first(i_first)
    {}

    bool operator()( const EepromInfo_t& i_second )
    {
        bool match = false;
        if (iv_first.accessMethod == EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_I2C)
        {
            if ((iv_first.eepromAccess.i2cInfo.i2cMaster == i_second.eepromAccess.i2cInfo.i2cMaster)
                && (iv_first.eepromAccess.i2cInfo.engine == i_second.eepromAccess.i2cInfo.engine)
                && (iv_first.eepromAccess.i2cInfo.port == i_second.eepromAccess.i2cInfo.port)
                && (iv_first.eepromAccess.i2cInfo.devAddr == i_second.eepromAccess.i2cInfo.devAddr))
            {
                match = true;
            }
        }
        else
        {
            if ((iv_first.eepromAccess.spiInfo.spiMaster == i_second.eepromAccess.spiInfo.spiMaster)
                && (iv_first.eepromAccess.spiInfo.engine == i_second.eepromAccess.spiInfo.engine))
            {
                match = true;
            }
        }
        return match;
    }
  private:
    const EepromInfo_t& iv_first;
};

/**
 * @brief Add any new EEPROMs associated with this target
 *   to the list
 * @param[in/out] io_list : list of discovered EEPROMs (builds on this list)
 * @param[in] i_targ : owner of EEPROMs to add
 * @param[in] i_allowDups : allow duplicate eepromInfo entries
 */
void add_to_list( std::list<EepromInfo_t>& io_list,
                  TARGETING::Target* i_targ,
                  bool i_allowDups)
{
    TRACFCOMP(g_trac_eeprom,"add_to_list(): Targ %.8X",TARGETING::get_huid(i_targ));

    // try all defined types of EEPROMs
    for( EEPROM_ROLE eep_type = FIRST_CHIP_TYPE;
         eep_type < LAST_CHIP_TYPE;
         eep_type = static_cast<EEPROM_ROLE>(eep_type+1) )
    {
        bool found_i2c_eep = false;
        bool found_spi_eep = false;
        TARGETING::EepromVpdPrimaryInfo eepromData;
        TARGETING::SpiMvpdPrimaryInfo spiEepromData;

        switch( eep_type )
        {
            case VPD_PRIMARY:
                if( i_targ->
                    tryGetAttr<TARGETING::ATTR_EEPROM_VPD_PRIMARY_INFO>
                    ( eepromData ) )
                {
                    found_i2c_eep = true;
                }
                else if (i_targ->
                    tryGetAttr<TARGETING::ATTR_SPI_MVPD_PRIMARY_INFO>
                    (spiEepromData) )
                {
                    found_spi_eep = true;
                }
                break;

            case VPD_BACKUP:
                if( i_targ->
                    tryGetAttr<TARGETING::ATTR_EEPROM_VPD_BACKUP_INFO>
                    ( reinterpret_cast<
                      TARGETING::ATTR_EEPROM_VPD_BACKUP_INFO_type&>
                      ( eepromData) ) )
                {
                    found_i2c_eep = true;
                }
                else if (
                  i_targ->tryGetAttr<TARGETING::ATTR_SPI_MVPD_BACKUP_INFO>
                  ( reinterpret_cast<
                      TARGETING::ATTR_SPI_MVPD_BACKUP_INFO_type&>
                      (spiEepromData) ) )
                {
                    found_spi_eep = true;
                }
                break;

            case VPD_AUTO:
                assert(false, "add_to_list: Unexpected eep_type VPD_AUTO");

            case SBE_PRIMARY:
                if (
                  i_targ->tryGetAttr<TARGETING::ATTR_SPI_SBE_BOOT_CODE_PRIMARY_INFO>
                  ( reinterpret_cast<
                      TARGETING::ATTR_SPI_SBE_BOOT_CODE_PRIMARY_INFO_type&>
                      (spiEepromData) ) )
                {
                    found_spi_eep = true;
                }
                break;

            case SBE_BACKUP:
                if (
                  i_targ->tryGetAttr<TARGETING::ATTR_SPI_SBE_BOOT_CODE_BACKUP_INFO>
                  ( reinterpret_cast<
                      TARGETING::ATTR_SPI_SBE_BOOT_CODE_BACKUP_INFO_type&>
                      (spiEepromData) ) )
                {

                    found_spi_eep = true;
                }
                break;

            case WOF_DATA:
                if (i_targ->tryGetAttr<TARGETING::ATTR_SPI_WOF_DATA_INFO>
                   (reinterpret_cast<TARGETING::ATTR_SPI_WOF_DATA_INFO_type&>
                   (spiEepromData)))
                {
                    found_spi_eep = true;
                }
                break;

            case SPARE_TEST:
                if (
                  i_targ->tryGetAttr<TARGETING::ATTR_SPI_EEPROM_SPARE_INFO>
                  ( reinterpret_cast<
                      TARGETING::ATTR_SPI_EEPROM_SPARE_INFO_type&>
                      (spiEepromData) ) )
                {
                    TRACUCOMP(g_trac_eeprom,"SPARE_INFO found");
                    found_spi_eep = true;
                }
                break;

            case LAST_CHIP_TYPE:
                //only included to catch additional types later on
                found_i2c_eep = false;
                found_spi_eep = false;
                break;
        }

        TARGETING::EntityPath masterPath;
        if ( found_i2c_eep )
        {
            masterPath = eepromData.i2cMasterPath;
        }
        else if ( found_spi_eep )
        {
            masterPath = spiEepromData.spiMasterPath;
        }
        else
        {
            TRACDCOMP(g_trac_eeprom,"eep_type=%d not found",eep_type);
            //nothing to do
            continue;
        }

        // check that the path exists
        bool exists = false;
        TARGETING::targetService().exists( masterPath, exists );
        if( !exists )
        {
            TRACDCOMP(g_trac_eeprom,"no master path");
            continue;
        }

        // Since it exists, convert to a target
        TARGETING::Target* pMaster = TARGETING::targetService()
          .toTarget( masterPath );
        if( nullptr == pMaster )
        {
            //not sure how this could happen, but just skip it
            TRACDCOMP(g_trac_eeprom,"no target");
            continue;
        }

        // ignore anything with junk data
        TARGETING::Target * sys = NULL;
        TARGETING::targetService().getTopLevelTarget( sys );
        if( pMaster == sys )
        {
            TRACDCOMP(g_trac_eeprom,"sys target");
            continue;
        }

        // copy all the data out
        EepromInfo_t eep_info;
        if ( found_i2c_eep )
        {
            eep_info.accessMethod = EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_I2C;
            eep_info.eepromAccess.i2cInfo.i2cMaster = pMaster;
            eep_info.eepromAccess.i2cInfo.engine = eepromData.engine;
            eep_info.eepromAccess.i2cInfo.port = eepromData.port;
            eep_info.eepromAccess.i2cInfo.devAddr = eepromData.devAddr;
            eep_info.eepromAccess.i2cInfo.chipCount = eepromData.chipCount;
            eep_info.eepromAccess.i2cInfo.addrBytes = eepromData.byteAddrOffset;
            //one more lookup for the speed
            TARGETING::ATTR_I2C_BUS_SPEED_ARRAY_type speeds;
            if( pMaster->tryGetAttr<TARGETING::ATTR_I2C_BUS_SPEED_ARRAY>
                (speeds) )
            {
                if( (eep_info.eepromAccess.i2cInfo.engine > I2C_BUS_MAX_ENGINE(speeds))
                    || (eep_info.eepromAccess.i2cInfo.port > I2C_BUS_MAX_PORT(speeds)) )
                {
                    TRACDCOMP(g_trac_eeprom,"bad engine/port");
                    continue;
                }
                eep_info.eepromAccess.i2cInfo.busFreq = speeds[eep_info.eepromAccess.i2cInfo.engine][eep_info.eepromAccess.i2cInfo.port];
                eep_info.eepromAccess.i2cInfo.busFreq *= 1000; //convert KHz->Hz
            }
            else
            {
                TRACDCOMP(g_trac_eeprom,"eep_type=%d, Speed=0",eep_type);
                continue;
            }
        }
        else
        {
            eep_info.accessMethod = EepromHwAccessMethodType::EEPROM_HW_ACCESS_METHOD_SPI;
            eep_info.eepromAccess.spiInfo.spiMaster = pMaster;
            eep_info.eepromAccess.spiInfo.engine = spiEepromData.engine;
        }
        eep_info.deviceRole = eep_type;
        eep_info.assocTarg = i_targ;

        // check if the eeprom is already in our list
        std::list<EepromInfo_t>::iterator oldeep =
          find_if( io_list.begin(), io_list.end(),
                   isSameEeprom(eep_info) );
        if( oldeep == io_list.end() || i_allowDups)
        {
            // didn't find it in our list so stick it into the output list
            io_list.push_back(eep_info);
            if ( found_i2c_eep )
            {
                TRACFCOMP(g_trac_eeprom,"--Adding i2cMaster=%.8X, type=%d, eng=%d, port=%d, addr=%.2X for %.8X", TARGETING::get_huid(pMaster),eep_type,eepromData.engine,eepromData.port, eep_info.eepromAccess.i2cInfo.devAddr,  TARGETING::get_huid(eep_info.assocTarg));
            }
            else
            {
                TRACFCOMP(g_trac_eeprom,"--Adding spiMaster=%.8X, type=%d, eng=%d for %.8X", TARGETING::get_huid(pMaster),eep_type,spiEepromData.engine, TARGETING::get_huid(eep_info.assocTarg));
            }
        }
        else
        {
            if ( found_i2c_eep )
            {
                TRACFCOMP(g_trac_eeprom,"--Skipping duplicate i2cMaster=%.8X, type=%d, eng=%d, port=%d, addr=%.2X for %.8X", TARGETING::get_huid(pMaster),eep_type,eepromData.engine,eepromData.port, eep_info.eepromAccess.i2cInfo.devAddr,  TARGETING::get_huid(eep_info.assocTarg));
            }
            else
            {
                TRACFCOMP(g_trac_eeprom,"--Skipping duplicate spiMaster=%.8X, type=%d, eng=%d for %.8X", TARGETING::get_huid(pMaster),eep_type,spiEepromData.engine, TARGETING::get_huid(eep_info.assocTarg));
            }
        }
    }
}

/**
 * @brief Return a set of information related to every unique
 *        EEPROM in the system
 */
void getEEPROMs( std::list<EepromInfo_t>& o_info )
{
    TRACFCOMP(g_trac_eeprom,">>getEEPROMs()");

    // We only want to have a single entry in our list per
    //  physical EEPROM.  Since multiple targets could be
    //  using the same EEPROM, we need to have a hierarchy
    //  of importance.
    //    node/planar > proc > membuf > dimm

    // predicate to only look for this that are actually there
    TARGETING::PredicateHwas isPresent;
    isPresent.reset().poweredOn(true).present(true);

    bool allowDupEntries = false;

    // #1 - Nodes
    TARGETING::PredicateCTM nodes( TARGETING::CLASS_ENC,
                                   TARGETING::TYPE_NODE,
                                   TARGETING::MODEL_NA );
    TARGETING::PredicatePostfixExpr l_nodeFilter;
    l_nodeFilter.push(&isPresent).push(&nodes).And();
    TARGETING::TargetRangeFilter node_itr( TARGETING::targetService().begin(),
                                           TARGETING::targetService().end(),
                                           &l_nodeFilter );
    for( ; node_itr; ++node_itr )
    {
        add_to_list( o_info, *node_itr, allowDupEntries );
    }

    // #2 - Procs
    TARGETING::PredicateCTM procs( TARGETING::CLASS_CHIP,
                                   TARGETING::TYPE_PROC,
                                   TARGETING::MODEL_NA );
    TARGETING::PredicatePostfixExpr l_procFilter;
    l_procFilter.push(&isPresent).push(&procs).And();
    TARGETING::TargetRangeFilter proc_itr( TARGETING::targetService().begin(),
                                           TARGETING::targetService().end(),
                                           &l_procFilter );
    for( ; proc_itr; ++proc_itr )
    {
        add_to_list( o_info, *proc_itr, allowDupEntries );
    }

    // #3 - DIMMs
    TARGETING::PredicateCTM dimms( TARGETING::CLASS_LOGICAL_CARD,
                                   TARGETING::TYPE_DIMM,
                                   TARGETING::MODEL_NA );
    TARGETING::PredicatePostfixExpr l_dimmFilter;
    l_dimmFilter.push(&isPresent).push(&dimms).And();
    TARGETING::TargetRangeFilter dimm_itr( TARGETING::targetService().begin(),
                                           TARGETING::targetService().end(),
                                           &l_dimmFilter );
    for( ; dimm_itr; ++dimm_itr )
    {
        add_to_list( o_info, *dimm_itr, allowDupEntries );
    }

    TRACFCOMP(g_trac_eeprom,"<<getEEPROMs()");
}


void cacheEepromVpd(TARGETING::Target * i_target, bool i_present)
{
    errlHndl_t errl = nullptr;

    TARGETING::EepromVpdPrimaryInfo eepromData;
    TARGETING::SpiEepromVpdPrimaryInfo spiEepromData;
    if ( i_target->tryGetAttr<TARGETING::ATTR_EEPROM_VPD_PRIMARY_INFO>(eepromData) ||
         i_target->tryGetAttr<TARGETING::ATTR_SPI_EEPROM_VPD_PRIMARY_INFO>
          (spiEepromData) )
    {
        TRACFCOMP(g_trac_eeprom, "Reading EEPROMs for target 0x%.8X, eeprom cache = %d VPD_AUTO, target present = %d , eeprom type = %d",
                  TARGETING::get_huid(i_target), DEVICE_CACHE_EEPROM_ADDRESS(i_present, EEPROM::VPD_AUTO));

        void * empty_buffer = nullptr;
        size_t empty_size = 0;
        errl = deviceRead(i_target, empty_buffer, empty_size,
                        DEVICE_CACHE_EEPROM_ADDRESS(i_present, EEPROM::VPD_AUTO));
        if (errl != nullptr)
        {
            TRACFCOMP(g_trac_eeprom,"pTarget %.8X - failed reading VPD eeprom",
                i_target->getAttr<TARGETING::ATTR_HUID>());
            errlCommit(errl, EEPROM_COMP_ID);
        }
    }
}

errlHndl_t cacheEepromBuffer(TARGETING::Target * const i_target,
                             const bool i_present,
                             const std::vector<uint8_t>& i_eeprom_data)
{
    errlHndl_t errl = nullptr;

    TARGETING::EepromVpdPrimaryInfo eepromData;
    TARGETING::SpiEepromVpdPrimaryInfo spiEepromData;
    if ( i_target->tryGetAttr<TARGETING::ATTR_EEPROM_VPD_PRIMARY_INFO>(eepromData) ||
         i_target->tryGetAttr<TARGETING::ATTR_SPI_EEPROM_VPD_PRIMARY_INFO>
          (spiEepromData) )
    {
        TRACFCOMP(g_trac_eeprom, "Reading EEPROMs for target 0x%.8X, eeprom cache = %d VPD_AUTO, target present = %d , eeprom type = %d",
                  TARGETING::get_huid(i_target), DEVICE_CACHE_EEPROM_ADDRESS(i_present, EEPROM::VPD_AUTO));

        size_t eeprom_data_size = i_eeprom_data.size();
        errl = deviceRead(i_target,
                          const_cast<uint8_t *>(i_eeprom_data.data()),
                          eeprom_data_size,
                          DEVICE_CACHE_EEPROM_ADDRESS(i_present,
                                                      EEPROM::VPD_AUTO));
    }

    return errl;
}


void cacheEepromAncillaryRoles()
{
    errlHndl_t errl = nullptr;
    std::list<EepromInfo_t> l_eepromTargets;

    TRACFCOMP(g_trac_eeprom,">> cacheEepromAncillaryRoles()");

    // Grab list of all present targets that potentially have eeproms

    // predicate to only look for those that are actually present
    TARGETING::PredicateHwas isPresent;
    isPresent.reset().poweredOn(true).present(true);

    TARGETING::PredicateCTM nodes( TARGETING::CLASS_ENC,
                                   TARGETING::TYPE_NODE,
                                   TARGETING::MODEL_NA );

    TARGETING::PredicateCTM procs( TARGETING::CLASS_CHIP,
                                   TARGETING::TYPE_PROC,
                                   TARGETING::MODEL_NA );

    TARGETING::PredicateCTM dimms( TARGETING::CLASS_LOGICAL_CARD,
                                   TARGETING::TYPE_DIMM,
                                   TARGETING::MODEL_NA );

    TARGETING::PredicatePostfixExpr l_eepromTargetFilter;
    l_eepromTargetFilter.push(&nodes).push(&procs).Or().push(&dimms).Or().
                         push(&isPresent).And();

    TARGETING::TargetRangeFilter eepromTarget_itr( TARGETING::targetService().begin(),
                                                   TARGETING::targetService().end(),
                                                   &l_eepromTargetFilter );

    int numTarget = 0;
    bool allowDupEntries = true;
    for( ; eepromTarget_itr; ++eepromTarget_itr )
    {
        numTarget++;
        TRACUCOMP(g_trac_eeprom,"cacheEepromAncillaryRoles(): calling add_to_list for target 0x%.8X",
            TARGETING::get_huid(*eepromTarget_itr));
        // loop for eeproms associated with the target and add
        // them to the list.  Allow duplicate eeproms to show up to account
        // for different roles present
        add_to_list( l_eepromTargets, *eepromTarget_itr, allowDupEntries );
    }
    TRACUCOMP(g_trac_eeprom,"cacheEepromAncillaryRoles(): called add_to_list on %d targets, resulted in %d eeprom targets",
        numTarget, l_eepromTargets.size());

    // Go through list and call cachedEeprom on each non-VPD and non-SBE type
    for (auto eepromTarget : l_eepromTargets)
    {
        // Only update ancillary roles (non-VPD and non-SBE)
        if ( (eepromTarget.deviceRole != VPD_PRIMARY) &&
             (eepromTarget.deviceRole != VPD_BACKUP) &&
             (eepromTarget.deviceRole != SBE_PRIMARY) &&
             (eepromTarget.deviceRole != SBE_BACKUP) )
        {
            bool present = true;
            void * empty_buffer = nullptr;
            size_t empty_size = 0;

            TRACFCOMP(g_trac_eeprom,"cacheEepromAncillaryRoles(): "
                "Reading EEPROMs for target %.8X, eeprom cache = %d,"
                " target present = %d , eeprom type = %d",
                TARGETING::get_huid(eepromTarget.assocTarg),
                DEVICE_CACHE_EEPROM_ADDRESS(present, eepromTarget.deviceRole));
            errl = deviceRead(eepromTarget.assocTarg, empty_buffer, empty_size,
                            DEVICE_CACHE_EEPROM_ADDRESS(present, eepromTarget.deviceRole));
            if (errl != nullptr)
            {
                TRACFCOMP(g_trac_eeprom, ERR_MRK "pTarget %.8X - failed reading eeprom for type %d",
                    TARGETING::get_huid(eepromTarget.assocTarg), eepromTarget.deviceRole);
                errlCommit(errl, EEPROM_COMP_ID);
            }
        }
    }
} // END cacheEepromAncillaryRoles()

} // END namespace EEPROM
