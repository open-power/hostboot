/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/eeprom_utils.C $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
#include <i2c/eepromif.H>
#include <i2c/i2cif.H>
#include <errl/errlmanager.H>
#include <errl/errludstring.H>
#include <i2c/eepromddreasoncodes.H>
#include <i2c/eeprom_const.H>
#include "i2c_common.H"


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
//-------------------------------------------------------------------
//eepromPresence
//-------------------------------------------------------------------
bool eepromPresence ( TARGETING::Target * i_target )
{
    TRACUCOMP(g_trac_eeprom, ENTER_MRK"eepromPresence()");

    errlHndl_t err = NULL;
    bool l_present = false;
    TARGETING::Target * i2cMasterTarget = NULL;

    eeprom_addr_t i2cInfo;

    i2cInfo.eepromRole = EEPROM::VPD_PRIMARY;
    i2cInfo.offset = 0;
    do
    {

        // Read Attributes needed to complete the operation
        err = eepromReadAttributes( i_target,
                                    i2cInfo );

        if( err )
        {
            TRACFCOMP(g_trac_eeprom,
                     ERR_MRK"Error in eepromPresence::eepromReadAttributes()");
            break;
        }

        // Check to see if we need to find a new target for
        // the I2C Master
        err = eepromGetI2CMasterTarget( i_target,
                                        i2cInfo,
                                        i2cMasterTarget );

        if( err )
        {
            TRACFCOMP(g_trac_eeprom,
                     ERR_MRK"Error in eepromPresence::eepromGetI2Cmaster()");
            break;
        }

        //Check for the target at the I2C level
        l_present = I2C::i2cPresence(i2cMasterTarget,
                          i2cInfo.port,
                          i2cInfo.engine,
                          i2cInfo.devAddr,
                          i2cInfo.i2cMuxBusSelector,
                          i2cInfo.i2cMuxPath);

        if( !l_present )
        {
            TRACDCOMP(g_trac_eeprom,
                     ERR_MRK"i2cPresence returned false! chip NOT present!");
            break;
        }

    } while( 0 );

    // If there was an error commit the error log
    if( err )
    {
        errlCommit( err, I2C_COMP_ID );
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
 * @brief A useful utility to dump (trace out) the eeprom_addr_t data.
 *         Use as needed.
 *
 * @param [in] i_i2cInfo - The eeprom_addr_t data to dump for user
 *
 */
void dumpEepromData(const eeprom_addr_t & i_i2cInfo)
{
    TRACFCOMP (g_trac_eeprom, INFO_MRK"eeprom_addr_t data: \n"
               "engine=%d, port=%d, devAddr=0X%X, writePageSize=%d, \n"
               "devSize_KB=0x%X, chipCount=%d, writeCycleTime=%d \n",
               i_i2cInfo.engine, i_i2cInfo.port, i_i2cInfo.devAddr,
               i_i2cInfo.writePageSize, i_i2cInfo.devSize_KB,
               i_i2cInfo.chipCount, i_i2cInfo.writeCycleTime);

    char* l_masterPath = i_i2cInfo.i2cMasterPath.toString();
    char* l_muxPath = i_i2cInfo.i2cMuxPath.toString();
    TRACFCOMP (g_trac_eeprom, INFO_MRK"eeprom_addr_t data cont.: \n"
              "masterPath=%s, muxSelector=0x%X, muxPath=%s \n",
              l_masterPath, i_i2cInfo.i2cMuxBusSelector, l_muxPath);

    free(l_masterPath);
    free(l_muxPath);
    l_masterPath = l_muxPath = nullptr;
}


// ------------------------------------------------------------------
// eepromReadAttributes
// ------------------------------------------------------------------
errlHndl_t eepromReadAttributes ( TARGETING::Target * i_target,
                                  eeprom_addr_t & o_i2cInfo )
{
    errlHndl_t err = NULL;
    bool fail_reading_attribute = false;

    TRACDCOMP( g_trac_eeprom,
               ENTER_MRK"eepromReadAttributes()" );

    // This variable will be used to hold the EEPROM attribute data
    // Note:  each 'EepromVpd' struct is kept the same via the attributes
    //        so will be copying each to eepromData to save code space
    TARGETING::EepromVpdPrimaryInfo eepromData;

    do
    {

        switch (o_i2cInfo.eepromRole )
        {
            case VPD_PRIMARY:
                if( !( i_target->
                         tryGetAttr<TARGETING::ATTR_EEPROM_VPD_PRIMARY_INFO>
                             ( eepromData ) ) )

                {
                    fail_reading_attribute = true;
                }
                break;

            case VPD_BACKUP:

                if( !(i_target->
                        tryGetAttr<TARGETING::ATTR_EEPROM_VPD_BACKUP_INFO>
                        ( reinterpret_cast<
                            TARGETING::ATTR_EEPROM_VPD_BACKUP_INFO_type&>
                                ( eepromData) ) ) )
                {
                    fail_reading_attribute = true;
                }
                break;

            case SBE_PRIMARY:
                if( !(i_target->
                        tryGetAttr<TARGETING::ATTR_EEPROM_SBE_PRIMARY_INFO>
                        ( reinterpret_cast<
                            TARGETING::ATTR_EEPROM_SBE_PRIMARY_INFO_type&>
                                ( eepromData) ) ) )
                {
                    fail_reading_attribute = true;
                }
                break;

            case SBE_BACKUP:
                if( (!i_target->
                        tryGetAttr<TARGETING::ATTR_EEPROM_SBE_BACKUP_INFO>
                        ( reinterpret_cast<
                            TARGETING::ATTR_EEPROM_SBE_BACKUP_INFO_type&>
                                ( eepromData) ) ) )
                {
                    fail_reading_attribute = true;
                }
                break;

            default:
                TRACFCOMP( g_trac_eeprom,ERR_MRK"eepromReadAttributes() - "
                           "Invalid chip (%d) to read attributes from!",
                            o_i2cInfo.eepromRole );

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
                                           o_i2cInfo.eepromRole,
                                           TARGETING::get_huid(i_target),
                                           true /*Add HB SW Callout*/ );

                err->collectTrace( EEPROM_COMP_NAME );

                break;
        }

        // Check if Attribute Data was found
        if( fail_reading_attribute == true )
        {
            TRACFCOMP( g_trac_eeprom,
                       ERR_MRK"eepromReadAttributes() - ERROR reading "
                       "attributes for eeprom role %d!",
                       o_i2cInfo.eepromRole );

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
                                    o_i2cInfo.eepromRole);

                // Could be FSP or HB code's fault
                err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                         HWAS::SRCI_PRIORITY_MED);
                err->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                         HWAS::SRCI_PRIORITY_MED);

                err->collectTrace( EEPROM_COMP_NAME );

                break;

        }

        // Successful reading of Attribute, so extract the data
        o_i2cInfo.port           = eepromData.port;
        o_i2cInfo.devAddr        = eepromData.devAddr;
        o_i2cInfo.engine         = eepromData.engine;
        o_i2cInfo.i2cMasterPath  = eepromData.i2cMasterPath;
        o_i2cInfo.writePageSize  = eepromData.writePageSize;
        o_i2cInfo.devSize_KB     = eepromData.maxMemorySizeKB;
        o_i2cInfo.chipCount      = eepromData.chipCount;
        o_i2cInfo.writeCycleTime = eepromData.writeCycleTime;
        o_i2cInfo.i2cMuxBusSelector = eepromData.i2cMuxBusSelector;
        o_i2cInfo.i2cMuxPath     = eepromData.i2cMuxPath;

        // Convert attribute info to eeprom_addr_size_t enum
        if ( eepromData.byteAddrOffset == 0x3 )
        {
            o_i2cInfo.addrSize = ONE_BYTE_ADDR;
        }
        else if ( eepromData.byteAddrOffset == 0x2 )
        {
            o_i2cInfo.addrSize = TWO_BYTE_ADDR;
        }
        else if ( eepromData.byteAddrOffset == 0x1 )
        {
            o_i2cInfo.addrSize = ONE_BYTE_ADDR_PAGESELECT;
        }
        else if ( eepromData.byteAddrOffset == 0x0 )
        {
            o_i2cInfo.addrSize = ZERO_BYTE_ADDR;
        }
        else
        {
            TRACFCOMP( g_trac_eeprom,
                       ERR_MRK"eepromReadAttributes() - INVALID ADDRESS "
                       "OFFSET SIZE %d!",
                       o_i2cInfo.addrSize );

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
                                    o_i2cInfo.addrSize,
                                    true /*Add HB SW Callout*/ );

                err->collectTrace( EEPROM_COMP_NAME );

                break;

        }

    } while( 0 );

    TRACUCOMP(g_trac_eeprom,"eepromReadAttributes() tgt=0x%X, %d/%d/0x%X "
              "dsKb=0x%X, aS=%d (%d)",
              TARGETING::get_huid(i_target),
              o_i2cInfo.port, o_i2cInfo.engine, o_i2cInfo.devAddr,
              o_i2cInfo.devSize_KB, o_i2cInfo.addrSize,
              eepromData.byteAddrOffset);



    // Printing mux info separately, if combined, nothing is displayed
    char* l_muxPath = o_i2cInfo.i2cMuxPath.toString();
    TRACUCOMP(g_trac_eeprom, "eepromReadAttributes(): "
              "muxSelector=0x%X, muxPath=%s",
              o_i2cInfo.i2cMuxBusSelector,
              l_muxPath);
    free(l_muxPath);
    l_muxPath = nullptr;

    TRACDCOMP( g_trac_eeprom,
               EXIT_MRK"eepromReadAttributes()" );

    return err;
} // end eepromReadAttributes


// ------------------------------------------------------------------
// eepromGetI2CMasterTarget
// ------------------------------------------------------------------
errlHndl_t eepromGetI2CMasterTarget ( TARGETING::Target * i_target,
                                      const eeprom_addr_t & i_i2cInfo,
                                      TARGETING::Target * &o_target )
{
    errlHndl_t err = NULL;
    o_target = NULL;

    TRACDCOMP( g_trac_eeprom,
               ENTER_MRK"eepromGetI2CMasterTarget()" );

    do
    {
        TARGETING::TargetService& tS = TARGETING::targetService();

        // The path from i_target to its I2C Master was read from the
        // attribute via eepromReadAttributes() and passed to this function
        // in i_i2cInfo.i2cMasterPath

        // check that the path exists
        bool exists = false;
        tS.exists( i_i2cInfo.i2cMasterPath,
                   exists );

        if( !exists )
        {
            TRACFCOMP( g_trac_eeprom,
                       ERR_MRK"eepromGetI2CMasterTarget() - "
                       "i2cMasterPath attribute path doesn't exist!" );

            // Compress the entity path
            uint64_t l_epCompressed = 0;
            for( uint32_t i = 0; i < i_i2cInfo.i2cMasterPath.size(); i++ )
            {
                // Can only fit 4 path elements into 64 bits
                if ( i <= 3 )
                {
                    // Path element: type:8 instance:8
                    l_epCompressed |=
                        i_i2cInfo.i2cMasterPath[i].type << (16*(3-i));
                    l_epCompressed |=
                        i_i2cInfo.i2cMasterPath[i].instance << ((16*(3-i))-8);
                }

                // Always trace all of the info even if we cannot fit it in error log
                TRACFCOMP( g_trac_eeprom,
                       ERR_MRK"eepromGetI2CMasterTarget() - "
                       "i_i2cInfo.i2cMasterPath[%d].type = %.02X i_i2cInfo.i2cMasterPath[%d].instance =  %.02X",
                        i, i_i2cInfo.i2cMasterPath[i].type, i, i_i2cInfo.i2cMasterPath[i].instance );

            }

            /*@
             * @errortype
             * @reasoncode       EEPROM_I2C_MASTER_PATH_ERROR
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         EEPROM_GETI2CMASTERTARGET
             * @userdata1[00:31] Attribute Chip Type Enum
             * @userdata1[32:63] HUID of target
             * @userdata2        Compressed Entity Path
             * @devdesc          I2C master entity path doesn't exist.
             */
            err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                EEPROM_GETI2CMASTERTARGET,
                                EEPROM_I2C_MASTER_PATH_ERROR,
                                TWO_UINT32_TO_UINT64(
                                    i_i2cInfo.eepromRole,
                                    TARGETING::get_huid(i_target) ),
                                l_epCompressed,
                                true /*Add HB SW Callout*/ );

            err->collectTrace( EEPROM_COMP_NAME );

            char* l_masterPath = i_i2cInfo.i2cMasterPath.toString();
            ERRORLOG::ErrlUserDetailsString(l_masterPath).addToLog(err);
            free(l_masterPath);
            l_masterPath = nullptr;

            break;
        }

        // Since it exists, convert to a target
        o_target = tS.toTarget( i_i2cInfo.i2cMasterPath );

        if( NULL == o_target )
        {
            TRACFCOMP( g_trac_eeprom,
                       ERR_MRK"eepromGetI2CMasterTarget() - I2C Master "
                              "Path target was NULL!" );

            // Compress the entity path
            uint64_t l_epCompressed = 0;
            for( uint32_t i = 0; i < i_i2cInfo.i2cMasterPath.size(); i++ )
            {
                // Can only fit 4 path elements into 64 bits
                if ( i <= 3 )
                {
                    // Path element: type:8 instance:8
                    l_epCompressed |=
                        i_i2cInfo.i2cMasterPath[i].type << (16*(3-i));
                    l_epCompressed |=
                        i_i2cInfo.i2cMasterPath[i].instance << ((16*(3-i))-8);
                }

                // Always trace all of the info even if we cannot fit it in error log
                TRACFCOMP( g_trac_eeprom,
                       ERR_MRK"eepromGetI2CMasterTarget() - "
                       "i_i2cInfo.i2cMasterPath[%d].type = %.02X i_i2cInfo.i2cMasterPath[%d].instance =  %.02X",
                        i, i_i2cInfo.i2cMasterPath[i].type, i, i_i2cInfo.i2cMasterPath[i].instance );

            }

            /*@
             * @errortype
             * @reasoncode       EEPROM_TARGET_NULL
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         EEPROM_GETI2CMASTERTARGET
             * @userdata1[00:31] Attribute Chip Type Enum
             * @userdata1[32:63] HUID of target
             * @userdata2        Compressed Entity Path
             * @devdesc          I2C master path target is null.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           EEPROM_GETI2CMASTERTARGET,
                                           EEPROM_TARGET_NULL,
                                           TWO_UINT32_TO_UINT64(
                                               i_i2cInfo.eepromRole,
                                               TARGETING::get_huid(i_target) ),
                                           l_epCompressed,
                                           true /*Add HB SW Callout*/ );

            err->collectTrace( EEPROM_COMP_NAME );

            char* l_masterPath = i_i2cInfo.i2cMasterPath.toString();
            ERRORLOG::ErrlUserDetailsString(l_masterPath).addToLog(err);
            free(l_masterPath);
            l_masterPath = nullptr;

            break;
        }

    } while( 0 );

    TRACDCOMP( g_trac_eeprom,
               EXIT_MRK"eepromGetI2CMasterTarget()" );

    return err;
} // end eepromGetI2CMasterTarget


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
        return( (iv_first.i2cMaster == i_second.i2cMaster)
                && (iv_first.engine == i_second.engine)
                && (iv_first.port == i_second.port)
                && (iv_first.devAddr == i_second.devAddr) );
    }
  private:
    const EepromInfo_t& iv_first;
};

/**
 * @brief Add any new EEPROMs associated with this target
 *   to the list
 * @param[in] i_list : list of previously discovered EEPROMs
 * @param[out] i_targ : owner of EEPROMs to add
 */
void add_to_list( std::list<EepromInfo_t>& i_list,
                  TARGETING::Target* i_targ )
{
    TRACFCOMP(g_trac_eeprom,"Targ %.8X",TARGETING::get_huid(i_targ));

    // try all defined types of EEPROMs
    for( EEPROM_ROLE eep_type = FIRST_CHIP_TYPE;
         eep_type < LAST_CHIP_TYPE;
         eep_type = static_cast<EEPROM_ROLE>(eep_type+1) )
    {
        bool found_eep = false;
        TARGETING::EepromVpdPrimaryInfo eepromData;

        switch( eep_type )
        {
            case VPD_PRIMARY:
                if( i_targ->
                    tryGetAttr<TARGETING::ATTR_EEPROM_VPD_PRIMARY_INFO>
                    ( eepromData ) )

                {
                    found_eep = true;
                }
                break;

            case VPD_BACKUP:
                if( i_targ->
                    tryGetAttr<TARGETING::ATTR_EEPROM_VPD_BACKUP_INFO>
                    ( reinterpret_cast<
                      TARGETING::ATTR_EEPROM_VPD_BACKUP_INFO_type&>
                      ( eepromData) ) )
                {
                    found_eep = true;
                }
                break;

            case SBE_PRIMARY:
                if( i_targ->
                    tryGetAttr<TARGETING::ATTR_EEPROM_SBE_PRIMARY_INFO>
                    ( reinterpret_cast<
                      TARGETING::ATTR_EEPROM_SBE_PRIMARY_INFO_type&>
                      ( eepromData) ) )
                {
                    found_eep = true;
                }
                break;

            case SBE_BACKUP:
                if( i_targ->
                    tryGetAttr<TARGETING::ATTR_EEPROM_SBE_BACKUP_INFO>
                    ( reinterpret_cast<
                      TARGETING::ATTR_EEPROM_SBE_BACKUP_INFO_type&>
                      ( eepromData) ) )
                {
                    found_eep = true;
                }
                break;

            case LAST_CHIP_TYPE:
                //only included to catch additional types later on
                found_eep = false;
                break;
        }

        if( !found_eep )
        {
            TRACDCOMP(g_trac_eeprom,"eep_type=%d not found",eep_type);
            //nothing to do
            continue;
        }

        // check that the path exists
        bool exists = false;
        TARGETING::targetService().exists( eepromData.i2cMasterPath,
                                           exists );
        if( !exists )
        {
            TRACDCOMP(g_trac_eeprom,"no master path");
            continue;
        }

        // Since it exists, convert to a target
        TARGETING::Target* i2cm = TARGETING::targetService()
          .toTarget( eepromData.i2cMasterPath );
        if( NULL == i2cm )
        {
            //not sure how this could happen, but just skip it
            TRACDCOMP(g_trac_eeprom,"no target");
            continue;
        }

        // ignore anything with junk data
        TARGETING::Target * sys = NULL;
        TARGETING::targetService().getTopLevelTarget( sys );
        if( i2cm == sys )
        {
            TRACDCOMP(g_trac_eeprom,"sys target");
            continue;
        }

        // copy all the data out
        EepromInfo_t eep_info;
        eep_info.i2cMaster = i2cm;
        eep_info.engine = eepromData.engine;
        eep_info.port = eepromData.port;
        eep_info.devAddr = eepromData.devAddr;
        eep_info.device = eep_type;
        eep_info.assocTarg = i_targ;
        eep_info.chipCount = eepromData.chipCount;
        eep_info.sizeKB = eepromData.maxMemorySizeKB;
        eep_info.addrBytes = eepromData.byteAddrOffset;
        //one more lookup for the speed
        TARGETING::ATTR_I2C_BUS_SPEED_ARRAY_type speeds;
        if( i2cm->tryGetAttr<TARGETING::ATTR_I2C_BUS_SPEED_ARRAY>
            (speeds) )
        {
            if( (eep_info.engine > I2C_BUS_MAX_ENGINE(speeds))
                || (eep_info.port > I2C_BUS_MAX_PORT(speeds)) )
            {
                TRACDCOMP(g_trac_eeprom,"bad engine/port");
                continue;
            }
            eep_info.busFreq = speeds[eep_info.engine][eep_info.port];
            eep_info.busFreq *= 1000; //convert KHz->Hz
        }
        else
        {
            TRACDCOMP(g_trac_eeprom,"eep_type=%d, Speed=0",eep_type);
            continue;
        }

        // check if the eeprom is already in our list
        std::list<EepromInfo_t>::iterator oldeep =
          find_if( i_list.begin(), i_list.end(),
                   isSameEeprom(eep_info) );
        if( oldeep == i_list.end() )
        {
            // didn't find it in our list so stick it into the output list
            i_list.push_back(eep_info);
            TRACFCOMP(g_trac_eeprom,"--Adding i2cm=%.8X, type=%d, eng=%d, port=%d, addr=%.2X for %.8X", TARGETING::get_huid(i2cm),eep_type,eepromData.engine,eepromData.port, eep_info.devAddr,  TARGETING::get_huid(eep_info.assocTarg));
        }
        else
        {
            TRACFCOMP(g_trac_eeprom,"--Skipping duplicate i2cm=%.8X, type=%d, eng=%d, port=%d, addr=%.2X for %.8X", TARGETING::get_huid(i2cm),eep_type,eepromData.engine,eepromData.port, eep_info.devAddr,  TARGETING::get_huid(eep_info.assocTarg));
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
        add_to_list( o_info, *node_itr );
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
        add_to_list( o_info, *proc_itr );
    }

    // #3 - Membufs
    TARGETING::PredicateCTM membs( TARGETING::CLASS_CHIP,
                                   TARGETING::TYPE_MEMBUF,
                                   TARGETING::MODEL_NA );
    TARGETING::PredicatePostfixExpr l_membFilter;
    l_membFilter.push(&isPresent).push(&membs).And();
    TARGETING::TargetRangeFilter memb_itr( TARGETING::targetService().begin(),
                                           TARGETING::targetService().end(),
                                           &l_membFilter );
    for( ; memb_itr; ++memb_itr )
    {
        add_to_list( o_info, *memb_itr );
    }

    // #4 - DIMMs
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
    #ifdef CONFIG_NVDIMM
        // Skip if this is an NVDIMM as this will get added later
        if (TARGETING::isNVDIMM( *dimm_itr ))
            continue;
    #endif
        add_to_list( o_info, *dimm_itr );
    }

    TRACFCOMP(g_trac_eeprom,"<<getEEPROMs()");
}

}