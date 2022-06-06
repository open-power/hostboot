/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/runtime/rt_cmds.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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

#include <runtime/interface.h>
#include <stdio.h>
#include <trace/interface.H>
#include <string.h>
#include "../utilbase.H"
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/predicates/predicateattrval.H>
#include <targeting/common/iterators/rangefilter.H>
#include <targeting/common/utilFilter.H>
#include <devicefw/userif.H>
#include <devicefw/driverif.H>
#include <util/util_reasoncodes.H>
#include <errl/errlmanager.H>
#include <errl/errlreasoncodes.H>
#include <vector>
#include <isteps/pm/pm_common_ext.H>
#include <scom/runtime/rt_scomif.H> // sendScomOpToFsp,
                                    // sendMultiScomReadToFsp,
                                    // switchToSbeScomAccess
#ifdef CONFIG_NVDIMM
#include <isteps/nvdimm/nvdimm.H>  // notify NVDIMM protection change
#endif
#include <util/utillidmgr.H>
#include <util/runtime/rt_fwreq_helper.H>

//See rt_sbeio.C
namespace RT_SBEIO
{
    int process_sbe_msg(uint32_t i_procChipId);
}

//See rt_targeting.C
namespace RT_TARG
{
    int hbrt_update_prep(void);
}

#ifdef CONFIG_HTMGT
//See rt_occ.C
namespace HTMGT
{
    int reset_pm_complex_with_reason(const OCC_RESET_REASON i_reason,
                                     const uint64_t i_chipId);
}
#endif

// A flag, that when defined, will include interfaces: writevpd, getscom and putscom
// Comment out to exclude said interfaces
//#define INCLUDE_LAB_ONLY_INTERFACES

extern char hbi_ImageId;

// need this here so compile works, linker will later find this
namespace RTPM
{
    int load_pm_complex( uint64_t i_chip,
                         uint64_t i_homer_addr,
                         uint64_t i_occ_common_addr,
                         uint32_t i_mode );
}

namespace Util
{

/**
 * @brief Poor-man's version of strtoul, see man page
 */
uint64_t strtou64(const char *nptr, char **endptr, int base)
{
    uint64_t l_data = 0;
    size_t i = 0;
    while( nptr[i] != '\0' )
    {
        uint64_t l_nib = 0;
        switch(nptr[i])
        {
            // handle leading '0x' or 'x'
            case('x'): case('X'):
                l_data = 0;
                break;
            case('0'): l_nib = 0; break;
            case('1'): l_nib = 1; break;
            case('2'): l_nib = 2; break;
            case('3'): l_nib = 3; break;
            case('4'): l_nib = 4; break;
            case('5'): l_nib = 5; break;
            case('6'): l_nib = 6; break;
            case('7'): l_nib = 7; break;
            case('8'): l_nib = 8; break;
            case('9'): l_nib = 9; break;
            case('A'): case('a'): l_nib = 0xA; break;
            case('B'): case('b'): l_nib = 0xB; break;
            case('C'): case('c'): l_nib = 0xC; break;
            case('D'): case('d'): l_nib = 0xD; break;
            case('E'): case('e'): l_nib = 0xE; break;
            case('F'): case('f'): l_nib = 0xF; break;
            default:
                UTIL_FT( "strtou64> nptr=%s, nptr[%d]=%c", nptr, i, nptr[i] );
                return 0xDEADBEEF;
        }
        l_data <<= 4;
        l_data |= l_nib;
        i++;
    }
    return l_data;
}


/**
 * @brief Fetch a target by HUID
 * @param[in] i_huid  HUID to translate
 * @return  Target Pointer, NULL if no match found
 */
TARGETING::Target* getTargetFromHUID( uint32_t i_huid )
{
    TARGETING::PredicateAttrVal<TARGETING::ATTR_HUID> l_huidMatches(i_huid);
    TARGETING::TargetRangeFilter l_targetsWithHuid(
        TARGETING::targetService().begin(),
        TARGETING::targetService().end(),
        &l_huidMatches);
    if(l_targetsWithHuid)
    {
        return *l_targetsWithHuid;
    }
    else
    {
        UTIL_FT( "bad huid - %.8X!", i_huid );
        return NULL;
    }
}


/**
 * @brief Read the value of an attribute by name
 * @param[out] o_output  Output display buffer, memory allocated here
 * @param[in] i_huid  HUID associated with Target to get attribute from
 * @param[in] i_attrId  Hash of attribute to read
 * @param[in] i_size  Size of attribute data in bytes
 */
void cmd_getattr( char*& o_output,
                  uint32_t i_huid,
                  uint32_t i_attrId,
                  uint32_t i_size )
{
    UTIL_FT( "cmd_getattr> huid=%.8X, attr=%.8X, size=%d",
             i_huid, i_attrId, i_size );

    TARGETING::Target* l_targ{};

    if(0xFFFFFFFF == i_huid)
    {
        TARGETING::targetService().getTopLevelTarget(l_targ);
    }
    else
    {
        l_targ = getTargetFromHUID(i_huid);
    }

    if( l_targ == NULL )
    {
        o_output = new char[100];
        sprintf( o_output, "HUID %.8X not found", i_huid );
        return;
    }

    uint8_t l_data[i_size];
    bool l_try = l_targ->_tryGetAttr( (TARGETING::ATTRIBUTE_ID)i_attrId,
                                      i_size, l_data );
    if( !l_try )
    {
        o_output = new char[100];
        sprintf( o_output, "Error reading %.8X", i_attrId );
        return;
    }

    // "Targ[12345678] Attr[12345678] = 0x12345678...\n"
    o_output = new char[50 + i_size*2];
    if( i_size == 1 )
    {
        uint8_t* l_data8 = (uint8_t*)(l_data);
        sprintf( o_output, "Targ[%.8X] Attr[%.8X] = 0x%.2X\n",
                 i_huid, i_attrId, *l_data8 );
    }
    else if( i_size == 2 )
    {
        uint16_t* l_data16 = (uint16_t*)(l_data);
        sprintf( o_output, "Targ[%.8X] Attr[%.8X] = 0x%.4X\n",
                 i_huid, i_attrId, *l_data16 );
    }
    else if( i_size == 4 )
    {
        uint32_t* l_data32 = (uint32_t*)(l_data);
        sprintf( o_output, "Targ[%.8X] Attr[%.8X] = 0x%.8X\n",
                 i_huid, i_attrId, *l_data32 );
    }
    else if( i_size == 8 )
    {
        uint64_t* l_data64 = (uint64_t*)(l_data);
        sprintf( o_output, "Targ[%.8X] Attr[%.8X] = 0x%.8X%.8X\n",
                 i_huid, i_attrId, (uint32_t)(*l_data64>>32),
                 (uint32_t)*l_data64 );
    }
    else // give up on pretty-printing and just dump the hex
    {
        sprintf( o_output, "Targ[%.8X] Attr[%.8X] = 0x", i_huid, i_attrId );
        size_t l_len1 = strlen(o_output);
        for( size_t i=0; i<i_size; i++ )
        {
            sprintf( &(o_output[l_len1+i]), "%.2X", l_data[i] );
        }
        o_output[l_len1+i_size*2] = '-';
        o_output[l_len1+i_size*2+1] = '\n';
        o_output[l_len1+i_size*2+2] = '\0';
    }
}


/**
 * @brief Read or write data out/into SPD, MVPD or PVPD
 * @param[out] o_output  Output display buffer, memory allocated here
 * @param[in] i_rtCmd  write or read data flag
 * @param[in] i_huid  HUID associated with Target to read/write to/from
 * @param[in] i_keyword keyword to be used for SPD, MVPD or PVPD
 * @param[in] i_record  record to be used for MVPD or PVPD
 * @param[in] i_data The data supplied for a write or returned from a read
 */
void cmd_readwritevpd(char*& o_output, DeviceFW::OperationType i_rtCmd,
                      uint32_t i_huid, uint64_t i_keyword,
                      uint64_t i_record = 0, uint64_t i_data = 0)
{
    UTIL_FT( "cmd_readwritevpd> rtcmd=%s, huid=%.8X, "
             "keyword=%lx, record=%lx, data=%lx",
             (i_rtCmd == DeviceFW::OperationType::READ ? "read" : "write"),
              i_huid, i_keyword, i_record, i_data);

    o_output = new char[100];   // info for user to consume
    char o_readWriteCmd[20];    // repeat the command the user requested
    bool l_isSpd(false);        // are we doing SPD command
    size_t l_size(0);           // size of the date from/to device read/write
    errlHndl_t l_errhdl(nullptr); // handle to capture errors

    do
    {
        // get the target, if it exists from user supplied HUID
        TARGETING::Target* l_target = getTargetFromHUID(i_huid);
        if (nullptr == l_target)
        {
           sprintf( o_output, "HUID %.8X not found", i_huid );
           break;
        }

       // get the TYPE of the HUID (we are looking for DIMM, PROC and NODE)
       TARGETING::AttributeTraits<TARGETING::ATTR_TYPE>::Type l_targetType;
       if (!l_target->tryGetAttr<TARGETING::ATTR_TYPE>(l_targetType))
       {
           sprintf( o_output, "No TARGETING::ATTR_TYPE associated "
                              "with HUID %.8X", i_huid );
           break;
       }

       // vector to hold data that will be returned/sent to device read/write
       std::vector<uint64_t> l_dataVec;

       if (DeviceFW::OperationType::READ == i_rtCmd)   // reading data from vpd
       {
          if (TARGETING::TYPE_DIMM == l_targetType)  // SPD
          {
              sprintf( o_readWriteCmd, "read SPD");
              l_isSpd = true;

              // first get size of data with NULL call
              l_errhdl = deviceRead(l_target, NULL, l_size,
                                    DEVICE_SPD_ADDRESS(i_keyword));
              if (l_errhdl)
              {
                  break;
              }

              // resize buffer to hold data, +1 to get "trailing bytes"
              l_dataVec.resize(l_size/sizeof(uint64_t) + 1);

              // read in the data
              l_errhdl = deviceRead(l_target, &l_dataVec.front(), l_size,
                                    DEVICE_SPD_ADDRESS(i_keyword));
              if (l_errhdl)
              {
                  break;
              }
          }
          else if (TARGETING::TYPE_PROC == l_targetType)  // MVPD
          {
              sprintf( o_readWriteCmd, "read MVPD");

              // first get size of data with NULL call
              l_errhdl = deviceRead(l_target, NULL, l_size,
                                    DEVICE_MVPD_ADDRESS(i_record, i_keyword));
              if (l_errhdl)
              {
                  break;
              }

              // resize buffer to hold data, +1 to get "trailing bytes"
              l_dataVec.resize(l_size/sizeof(uint64_t) + 1);

              // read in the data
              l_errhdl = deviceRead(l_target, &l_dataVec.front(), l_size,
                                    DEVICE_MVPD_ADDRESS(i_record, i_keyword));
              if (l_errhdl)
              {
                  break;
              }
          }
          else if (TARGETING::TYPE_NODE == l_targetType)  // PVPD
          {
              sprintf( o_readWriteCmd, "read PVPD");

              // first get size of data with NULL call
              l_errhdl = deviceRead(l_target, NULL, l_size,
                                    DEVICE_PVPD_ADDRESS(i_record, i_keyword));
              if (l_errhdl)
              {
                  break;
              }

              // resize buffer to hold data, +1 to get "trailing bytes"
              l_dataVec.resize(l_size/sizeof(uint64_t) + 1);

              // read in the data
              l_errhdl = deviceRead(l_target, &l_dataVec.front(), l_size,
                                    DEVICE_PVPD_ADDRESS(i_record, i_keyword));
              if (l_errhdl)
              {
                  break;
              }
          }
          else
          {
              sprintf( o_output, "cmd_readvpd> VPD %.8X is currently not"
                        " supported for HUID %.8x", l_targetType, i_huid);
              break;
          }
       }
       else   // writing data to vpd
       {
          if (TARGETING::TYPE_DIMM == l_targetType)  // SPD
          {
              sprintf( o_readWriteCmd, "write SPD");
              l_isSpd = true;

              // first get size of data with NULL call
              l_errhdl = deviceRead(l_target, NULL, l_size,
                                    DEVICE_SPD_ADDRESS(i_keyword));
              if (l_errhdl)
              {
                  break;
              }

              // resize buffer to hold data, +1 to get "trailing bytes"
              l_dataVec.resize(l_size/sizeof(uint64_t) + 1);

              // populate buffer with user data, repeat user data
              // if necessary to fill buffer
              for (size_t i = 0; i < l_dataVec.size(); ++i)
              {
                 l_dataVec[i] = i_data;
              }

              // write the data to the VPD
              l_errhdl = deviceWrite(l_target, &l_dataVec.front(), l_size,
                                     DEVICE_SPD_ADDRESS(i_keyword));
              if (l_errhdl)
              {
                  break;
              }
          }
          else if (TARGETING::TYPE_PROC == l_targetType)  // MVPD
          {
              sprintf( o_readWriteCmd, "write MVPD");

              // first get size of data with NULL call
              l_errhdl = deviceRead(l_target, NULL, l_size,
                                    DEVICE_MVPD_ADDRESS(i_record, i_keyword));
              if (l_errhdl)
              {
                  break;
              }

              // resize buffer to hold data, +1 to get "trailing bytes"
              l_dataVec.resize(l_size/sizeof(uint64_t) + 1);

              // populate buffer with user data, repeat user data
              // if necessary to fill buffer
              for (size_t i = 0; i < l_dataVec.size(); ++i)
              {
                 l_dataVec[i] = i_data;
              }

              l_errhdl = deviceWrite(l_target, &l_dataVec.front(), l_size,
                                    DEVICE_MVPD_ADDRESS(i_record, i_keyword));
              if (l_errhdl)
              {
                  break;
              }
          }
          else if (TARGETING::TYPE_NODE == l_targetType)  // PVPD
          {
              sprintf( o_readWriteCmd, "write PVPD");

              // first get size of data with NULL call
              l_errhdl = deviceRead(l_target, NULL, l_size,
                                     DEVICE_PVPD_ADDRESS(i_record, i_keyword));
              if (l_errhdl)
              {
                  break;
              }

              // resize buffer to hold data, +1 to get "trailing bytes"
              l_dataVec.resize(l_size/sizeof(uint64_t) + 1);

              // populate buffer with user data, repeat user data
              // if necessary to fill buffer
              for (size_t i = 0; i < l_dataVec.size(); ++i)
              {
                 l_dataVec[i] = i_data;
              }

              l_errhdl = deviceWrite(l_target, &l_dataVec.front(), l_size,
                                     DEVICE_PVPD_ADDRESS(i_record, i_keyword));
              if (l_errhdl)
              {
                  break;
              }
          }
          else
          {
              sprintf( o_output, "cmd_writevpd> VPD %.8X is currently not"
                        " supported for HUID %.8x", l_targetType, i_huid);
              break;
          }
       }

       // resize o_output to hold the extra data from the device read/writes
       delete o_output;
       size_t l_newOutputSize = 100 +
                 (l_dataVec.size() * sizeof(uint64_t) * 2) + l_dataVec.size();
       o_output = new char[l_newOutputSize];

       if (l_isSpd)
       {
           // write out results for SPD
           sprintf( o_output, "%s - HUID=%.8X Keyword=%.8X %.8X, Data=",
                    &o_readWriteCmd,
                    i_huid,
                    (uint32_t)(i_keyword>>32), (uint32_t)i_keyword);
       }
       else
       {
           // write out results for MVPD or PVPD
           sprintf( o_output, "%s - HUID=%.8X Record=%.8X %.8X, "
                              "Keyword=%.8X %.8X, Data=",
                    &o_readWriteCmd,
                    i_huid,
                    (uint32_t)(i_record>>32), (uint32_t)i_record,
                    (uint32_t)(i_keyword>>32), (uint32_t)i_keyword);
       }

       // write out the data from the device read/write
       // first get the data that is a multiple of 8
       size_t l_len(strlen(o_output));
       uint64_t l_tempValue(0);

       size_t i(0);
       for (; i < l_dataVec.size() -1; ++i )
       {
           if( i % 4 == 0 )
           {
               sprintf(&o_output[l_len],"\n");
               l_len = strlen(o_output);
           }

           l_tempValue = l_dataVec[i];
           sprintf(&o_output[l_len],"%.8X ",(uint32_t)(l_tempValue>>32));
           l_len = strlen(o_output);

           sprintf(&o_output[l_len],"%.8X",(uint32_t)(l_tempValue));
           l_len = strlen(o_output);
       }

       // write out the rest of the date that is not a multiple of 8
       uint8_t* l_lastBytes = (uint8_t*)(&(l_dataVec[i]));
       size_t l_numLastBytes = l_size % sizeof(uint64_t);

       if (l_numLastBytes)
       {
           sprintf(&o_output[l_len],"\n");
           l_len = strlen(o_output);

           for (size_t i = 0; i < l_numLastBytes; ++i)
           {
              sprintf(&o_output[l_len],"%.2X", l_lastBytes[i]);
              l_len = strlen(o_output);

              if (i == 4)
              {
                 sprintf(&o_output[l_len]," ");
                 l_len = strlen(o_output);
              }
           }
       }
   } while(0);

   if (l_errhdl)
   {
      sprintf( o_output, "cmd_readwritevpd> FAIL - %s: RC=%.4X",
               &o_readWriteCmd,
               ERRL_GETRC_SAFE(l_errhdl) );
   }
}


/**
 * @brief Read a scom register
 * @param[out] o_output  Output display buffer, memory allocated here
 * @param[in] i_huid  Target to read scom from
 * @param[in] i_addr  Scom address
 */
void cmd_getscom( char*& o_output,
                  uint32_t i_huid,
                  uint64_t i_addr )
{
    UTIL_FT( "cmd_getscom> huid=%.8X, addr=%X%.8X",
             i_huid, (uint32_t)(i_addr>>32), (uint32_t)i_addr );
    o_output = new char[100];

    TARGETING::Target* l_targ = getTargetFromHUID(i_huid);
    if( l_targ == NULL )
    {
        sprintf( o_output, "HUID %.8X not found", i_huid );
        return;
    }

    uint64_t l_data = 0;
    size_t l_size = sizeof(uint64_t);
    errlHndl_t l_errhdl = deviceRead(l_targ,
                                     &l_data,
                                     l_size,
                                     DEVICE_SCOM_ADDRESS(i_addr));
    if( l_errhdl )
    {
        sprintf( o_output, "cmd_getscom> FAIL: RC=%.4X",
                 ERRL_GETRC_SAFE(l_errhdl) );
        return;
    }
    else
    {
        sprintf( o_output, "HUID=%.8X Addr=%X%.8X, Data=%.8X %.8X",
                 i_huid, (uint32_t)(i_addr>>32), (uint32_t)i_addr,
                 (uint32_t)(l_data>>32), (uint32_t)l_data );
        return;
    }
}


/**
 * @brief Write a scom register
 * @param[out] o_output  Output display buffer, memory allocated here
 * @param[in] i_huid  Target to read scom from
 * @param[in] i_addr  Scom address
 * @param[in] i_data  Scom data to write
 */
void cmd_putscom( char*& o_output,
                  uint32_t i_huid,
                  uint64_t i_addr,
                  uint64_t i_data )
{
    UTIL_FT( "cmd_putscom> huid=%.8X, addr=%X%.8X, data=%.8X %.8X",
             i_huid, (uint32_t)(i_addr>>32), (uint32_t)i_addr,
             (uint32_t)(i_data>>32), (uint32_t)i_data );
    o_output = new char[100];

    TARGETING::Target* l_targ = getTargetFromHUID(i_huid);
    if( l_targ == NULL )
    {
        sprintf( o_output, "HUID %.8X not found", i_huid );
        return;
    }

    size_t l_size = sizeof(uint64_t);
    errlHndl_t l_errhdl = deviceWrite( l_targ,
                                       &i_data,
                                       l_size,
                                       DEVICE_SCOM_ADDRESS(i_addr));
    if( l_errhdl )
    {
        sprintf( o_output, "cmd_putscom> FAIL: RC=%.4X",
                 ERRL_GETRC_SAFE(l_errhdl) );
        return;
    }
    else
    {
        sprintf( o_output, "HUID=%.8X Addr=%X%.8X",
                 i_huid, (uint32_t)(i_addr>>32), (uint32_t)i_addr );
        return;
    }
}


/**
 * @brief Create and commit an error log
 * @param[out] o_output  Output display buffer, memory allocated here
 * @param[in] i_word1  Userdata 1 & 2
 * @param[in] i_word2  Userdata 3 & 4
 * @param[in] i_callout  HUID of target to callout (zero if none)
 * @param[in] i_ffdcLength  Additional ffdc data bytes to add to the error log
 * @param[in] i_deconfig  Indication if callout target should be deconfigured
 * @param[in] i_gard  Indication of type of failure for callout
 */
void cmd_errorlog( char*& o_output,
                   uint64_t i_word1,
                   uint64_t i_word2,
                   uint32_t i_callout,
                   uint32_t i_ffdcLength,
                   HWAS::DeconfigEnum i_deconfig,
                   HWAS::GARD_ErrorType i_gard )
{
    UTIL_FT( "cmd_errorlog> word1=%.8X%.8X, word2=%.8X%.8X, i_callout=%.8X ffdcLength=%ld, deconfig=%.2X, gard=%.2X",
             (uint32_t)(i_word1>>32), (uint32_t)i_word1,
             (uint32_t)(i_word2>>32), (uint32_t)i_word2, i_callout,
             i_ffdcLength, i_deconfig, i_gard );
    o_output = new char[100];

    errlHndl_t l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                                Util::UTIL_RT_CMDS,
                                                Util::UTIL_ERC_NONE,
                                                i_word1,
                                                i_word2,
                                                false );
    TARGETING::Target* l_targ = getTargetFromHUID(i_callout);
    if( l_targ != NULL )
    {
        l_err->addHwCallout( l_targ,
                             HWAS::SRCI_PRIORITY_HIGH,
                             i_deconfig,
                             i_gard );
    }
    else
    {
        l_err->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                             HWAS::SRCI_PRIORITY_HIGH);
    }

    if (i_ffdcLength > 0)
    {
        uint8_t l_count = 0;
        uint16_t l_packet_size = 256; // break i_ffdcLength into packets
        uint8_t data[l_packet_size];

        do {
            if (i_ffdcLength > l_packet_size)
            {
                i_ffdcLength -= l_packet_size;
            }
            else
            {
                l_packet_size = i_ffdcLength;
                i_ffdcLength = 0;
            }
            memset(data, l_count, l_packet_size);

            l_err->addFFDC(UTIL_COMP_ID,
                         &data,
                         l_packet_size,
                         0,         // Version
                         ERRORLOG::ERRL_UDT_NOFORMAT,   // parser ignores data
                         false );   // merge
            l_count++;
        } while (i_ffdcLength > 0);
    }

    l_err->collectTrace("UTIL", 1024);
    uint32_t l_plid = l_err->plid();
    sprintf( o_output, "Going to commit plid 0x%.8X", l_plid );
    errlCommit(l_err, UTIL_COMP_ID);
    sprintf( o_output, "Committed plid 0x%.8X", l_plid );
}


/**
 * @brief Process an SBE Message with a pass-through request
 * @param[out] o_output  Output display buffer, memory allocated here
 * @param[in] i_chipId   Processor chip ID
 */
void cmd_sbemsg( char*& o_output,
                 uint32_t i_chipId)
{
    UTIL_FT( "cmd_sbemsg> chipId=%.8X",
             i_chipId);
    o_output = new char[100];

    int rc = 0;

    do
    {
        rc = RT_SBEIO::process_sbe_msg(i_chipId);
        if(0 != rc)
        {
            sprintf( o_output, "Unexpected return from RT SBE message passing. "
                     "Return code: 0x%.8X for chipID: 0x%.8X", rc, i_chipId);
            return;
        }
    }while (0);

    sprintf( o_output, "SBE message passing command for chipID 0x%.8X returned "
                       "rc 0x%.8X", i_chipId, rc );
}

int cmd_reload_pm_complex( char*& o_output, uint64_t stopAt )
{
    // NOTE: this is running in a 32K hbrt -exec stack instead of
    //       the normal 64K hbrt stack
    int rc = 0;

// @TODO: RTC 244854 stopImageSection::SprRestoreArea_t for P10 is not defined.
//        Need to define the ADT or rework this method
#if 0
    o_output = new char[100*8];
    char l_tmpstr[100];

    sprintf(o_output, "cmd_reload_pm_complex >>\n");
    UTIL_FT("cmd_reload_pm_complex >>");
    uint64_t l_chip;
    uint64_t l_occ_common_addr;
    uint64_t l_homerPhysAddr;
    uint32_t l_mode = HBRT_PM_RELOAD;

    stopImageSection::SprRestoreArea_t * coreThreadRestoreBEFORE =
        (stopImageSection::SprRestoreArea_t *) new stopImageSection::SprRestoreArea_t[MAX_CORES_PER_CHIP][MAX_THREADS_PER_CORE];
    uint64_t coreThreadRestoreSize = sizeof(stopImageSection::SprRestoreArea_t)*MAX_CORES_PER_CHIP*MAX_THREADS_PER_CORE;

    TARGETING::Target* l_sys = nullptr;
    TARGETING::targetService().getTopLevelTarget(l_sys);
    assert(l_sys != nullptr);
    l_occ_common_addr = l_sys->getAttr<TARGETING::ATTR_OCC_COMMON_AREA_PHYS_ADDR>();

    TARGETING::TargetHandleList l_procChips;
    TARGETING::getAllChips(l_procChips, TARGETING::TYPE_PROC, true);

    // auto run through processor chips using attribute settings
    for (const auto & l_procChip: l_procChips)
    {
        // This attr was set during istep15 HCODE build
        l_homerPhysAddr = l_procChip->
                getAttr<TARGETING::ATTR_HOMER_PHYS_ADDR>();
        l_chip = l_procChip->getAttr<TARGETING::ATTR_POSITION>();

        // GET BEFORE SNAPSHOT OF MEMORY
        // Use this function as the virtual address gets reset to 0
        void* l_homerVAddr = HBPM::convertHomerPhysToVirt(l_procChip,
                                                    l_homerPhysAddr);
        if(nullptr == l_homerVAddr)
        {
            UTIL_FT(ERR_MRK"cmd_reload_pm_complex: "
                       "convertHomerPhysToVirt failed! "
                       "HOMER_Phys=0x%0lX", l_homerPhysAddr );
            break;
        }


        UTIL_FT("Get BEFORE snapshot of memory");
        stopImageSection::HomerSection_t *l_virt_addr =
              reinterpret_cast<stopImageSection::HomerSection_t*>(l_homerVAddr);

        if (l_virt_addr == nullptr)
        {
            sprintf(o_output, "ATTR_HOMER_VIRT_ADDR for %d chip returned 0\n",
                    l_chip);
            break;
        }

        UTIL_FT("%d: memcpy(%p, %p, %ld)", l_chip, coreThreadRestoreBEFORE,
            l_virt_addr->iv_coreThreadRestore, coreThreadRestoreSize);
        sprintf( l_tmpstr, "%d: memcpy(%p, %p, %ld)\n", l_chip,
            coreThreadRestoreBEFORE, l_virt_addr->iv_coreThreadRestore,
            coreThreadRestoreSize );
        strcat( o_output, l_tmpstr );
        if (stopAt == 1)
        {
            break;
        }
        memcpy( coreThreadRestoreBEFORE,
                l_virt_addr->iv_coreThreadRestore,
                coreThreadRestoreSize);

        // RUN LOAD_PM_COMPLEX
        UTIL_FT("Calling reload_pm_complex(%d, 0x%16llX, 0x%16llX, %s)",
                l_chip, l_homerPhysAddr, l_occ_common_addr,
                (HBPM::PM_LOAD == l_mode) ? "LOAD" : "RELOAD");
        sprintf( l_tmpstr,
                "Calling reload_pm_complex(%d, 0x%16llX, 0x%16llX, %s)\n",
                l_chip, l_homerPhysAddr, l_occ_common_addr,
                (HBPM::PM_LOAD == l_mode) ? "LOAD" : "RELOAD");
        strcat( o_output, l_tmpstr );
        if (stopAt == 2)
        {
            break;
        }
        rc = RTPM::load_pm_complex( l_chip, l_homerPhysAddr,
                                    l_occ_common_addr, l_mode );
        if (rc)
        {
            sprintf( l_tmpstr,
             "FAILURE: reload_pm_complex(%x, 0x%llx, 0x%llx, %x) returned %d\n",
             l_chip, l_homerPhysAddr, l_occ_common_addr, l_mode, rc );
            strcat( o_output, l_tmpstr );
            break;
        }

        // GET AFTER SNAPSHOT OF MEMORY
        UTIL_FT("Get AFTER snapshot of memory");
        if (stopAt == 3)
        {
            break;
        }

        // NOW COMPARE THE TWO SNAPSHOTS
        uint8_t lastMatch = memcmp(coreThreadRestoreBEFORE,
                                   l_virt_addr->iv_coreThreadRestore,
                                   coreThreadRestoreSize);
        // Both sections should be equal as
        // hostboot should NOT touch this section of memory
        if (lastMatch == 0)
        {
            // Verify non-zero exists
            stopImageSection::SprRestoreArea_t zeroedSprArea;
            memset(&zeroedSprArea, 0x00, sizeof(zeroedSprArea));
            bool foundNonZero = false;

            for (int x = 0; x < MAX_CORES_PER_CHIP; x++)
            {
                for (int y = 0; y < MAX_THREADS_PER_CORE; y++)
                {
                    // Check for non-zero threadArea
                    if ( 0 != memcmp(&(((stopImageSection::SprRestoreArea_t*)((char*)coreThreadRestoreBEFORE + (sizeof(zeroedSprArea)*x + sizeof(zeroedSprArea)*y)))->iv_threadArea),
                                &zeroedSprArea.iv_threadArea,
                                sizeof(zeroedSprArea.iv_threadArea)))
                    {
                        UTIL_FT("Found non-zero value in row %d, column %d threadArea", x, y);
                        UTIL_FBIN("Thread Area",
                            &(((stopImageSection::SprRestoreArea_t*)((char*)coreThreadRestoreBEFORE + (sizeof(zeroedSprArea)*x + sizeof(zeroedSprArea)*y)))->iv_threadArea),
                            sizeof(zeroedSprArea.iv_threadArea));
                        foundNonZero = true;
                    }
                    // Check for non-zero coreArea
                    if ( 0 != memcmp(&(((stopImageSection::SprRestoreArea_t*)((char*)coreThreadRestoreBEFORE + (sizeof(zeroedSprArea)*x + sizeof(zeroedSprArea)*y)))->iv_coreArea),
                                &zeroedSprArea.iv_coreArea,
                                sizeof(zeroedSprArea.iv_coreArea)))
                    {
                        UTIL_FT("Found non-zero value in row %d, column %d coreArea", x, y);
                        UTIL_FBIN("Core Area",
                            &(((stopImageSection::SprRestoreArea_t*)((char*)coreThreadRestoreBEFORE + (sizeof(zeroedSprArea)*x + sizeof(zeroedSprArea)*y)))->iv_coreArea),
                            sizeof(zeroedSprArea.iv_coreArea));
                        foundNonZero = true;
                    }
                }
            }
            if (foundNonZero)
            {
                UTIL_FT("SUCCESS: reload_pm_complex in %s mode: CHIP %d worked", (HBPM::PM_LOAD == l_mode) ? "LOAD" : "RELOAD", l_chip);
                sprintf( l_tmpstr, "SUCCESS: reload_pm_complex in %s mode: CHIP %d worked\n", (HBPM::PM_LOAD == l_mode) ? "LOAD" : "RELOAD", l_chip);
                strcat( o_output, l_tmpstr );
            }
            else
            {
                UTIL_FT("CONDITIONAL SUCCESS: reload_pm_complex in %s mode: CHIP %d worked with zeroed area", (HBPM::PM_LOAD == l_mode) ? "LOAD" : "RELOAD", l_chip);
                sprintf( l_tmpstr, "CONDITIONAL SUCCESS: reload_pm_complex in %s mode: CHIP %d worked with zeroed area\n", (HBPM::PM_LOAD == l_mode) ? "LOAD" : "RELOAD", l_chip);
                strcat( o_output, l_tmpstr );
            }
        }
        else
        {
            UTIL_FT("FAILURE: reload_pm_complex in %s mode: CHIP %d, first mismatch at %d", (HBPM::PM_LOAD == l_mode) ? "LOAD" : "RELOAD", l_chip, lastMatch);
            sprintf( l_tmpstr, "FAILURE: reload_pm_complex in %s mode: CHIP %d, first mismatch at %d\n", (HBPM::PM_LOAD == l_mode) ? "LOAD" : "RELOAD", l_chip, lastMatch);
            strcat( o_output, l_tmpstr );

            UTIL_FBIN("BEFORE coreThreadRestore", &coreThreadRestoreBEFORE, coreThreadRestoreSize);
            UTIL_FBIN("AFTER  coreThreadRestore", l_virt_addr->iv_coreThreadRestore, coreThreadRestoreSize);
        }
    }
    delete coreThreadRestoreBEFORE;

    sprintf(l_tmpstr, "<< cmd_reload_pm_complex\n");
    strcat(o_output, l_tmpstr);
    UTIL_FT("<< cmd_reload_pm_complex");
#endif  // #if 0
    return rc;
}


/**
 * @brief Read version of HBRT
 * @param[out] o_output  Output display buffer, memory allocated here
 */
void cmd_readHBRTversion( char*& o_output )
{
    UTIL_FT( "cmd_readHBRTversion");

    const char * const l_title = "Hostboot Build ID: ";
    o_output = new char[strlen(l_title) + strlen(&hbi_ImageId) + 1];
    // Set beginning of output string
    strcpy(o_output, l_title);
    // Concatenate the Hostboot Image ID
    strcat(o_output, &hbi_ImageId);

    UTIL_FT( "%s", o_output);
}


/**
 * @brief Execute function to prepare targeting data for an HBRT update
 * @param[out] o_output  Output display buffer, memory allocated here
 */
void cmd_hbrt_update(char*& o_output)
{
    UTIL_FT( "cmd_hbrt_update>");
    o_output = new char[100];

    int rc = 0;

    do
    {
        rc = RT_TARG::hbrt_update_prep();
        if(0 != rc)
        {
            sprintf( o_output, "Unexpected return from RT prepare HBRT update. "
                     "Return code: 0x%.8X", rc);
            return;
        }
    }while (0);

    sprintf( o_output, "Prepare HBRT update command returned rc 0x%.8X", rc );
}


/**
 * @brief Mark a target as requiring access to its SCOMs through the FSP->SBE
 * @param[out] o_output     Output display buffer, memory allocated here
 * @param[in]  i_huid       HUID associated with Target to switch access on
 */
void cmd_switchToSbeScomAccess( char*& o_output, uint32_t i_huid)
{
    UTIL_FT( "switchToSbeScomAccess> huid=%.8X", i_huid );

    TARGETING::Target* l_targ{};

    if(0xFFFFFFFF == i_huid)
    {
        TARGETING::targetService().getTopLevelTarget(l_targ);
    }
    else
    {
        l_targ = getTargetFromHUID(i_huid);
    }

    o_output = new char[100];
    if( l_targ == NULL )
    {
        sprintf( o_output, "HUID %.8X not found", i_huid );
        return;
    }

    SBESCOM::switchToSbeScomAccess(l_targ);

    sprintf( o_output, "switchToSbeScomAccess executed");
}


/**
 * @brief Send a scom operation (read/write) to the FSP
 * @param[out] o_output     Output display buffer, memory allocated here
 * @param[in]  i_op         Operation: r or w
 * @param[in]  i_huid       HUID associated with Target to get the SCOM from
 * @param[in]  i_scomAddr   Address of SCOM to read or write
 * @param[in]  io_scomValue Buffer for read SCOM value, or value to write
 */
void cmd_sendScomOpToFSP( char*&   o_output,
                          char     i_op,
                          uint32_t i_huid,
                          uint64_t i_scomAddr,
                          uint64_t *io_scomValue )
{
    UTIL_FT( "cmd_getScomFromFSP> op=%c, huid=%.8X, addr=%.8X, size=%d",
             i_op, i_huid, i_scomAddr, *io_scomValue );

    TARGETING::Target* l_targ{};

    if(0xFFFFFFFF == i_huid)
    {
        TARGETING::targetService().getTopLevelTarget(l_targ);
    }
    else
    {
        l_targ = getTargetFromHUID(i_huid);
    }

    o_output = new char[100];
    if( l_targ == NULL )
    {
        sprintf( o_output, "HUID %.8X not found", i_huid );
        return;
    }

    DeviceFW::OperationType l_op;
    switch (i_op) {
        case 'r':
        case 'R':
            l_op = DeviceFW::READ;
            break;
        case 'w':
        case 'W':
            l_op = DeviceFW::WRITE;
            break;
        default:
            sprintf( o_output, "Operation must be r or w: %c", i_op );
            return;
    }

    errlHndl_t l_err = nullptr;
    l_err = FSISCOM::sendScomOpToFsp(l_op, l_targ, i_scomAddr,
                                     (void *)io_scomValue);
    if (l_err)
    {
            sprintf( o_output, "Error on call to sendScomOpToFsp, rc=%.4X",
                     ERRL_GETRC_SAFE(l_err) );
            return;
    }

    sprintf( o_output, "op=%c, huid=%.16llX, scomAddr=%.16llX, scomValue=%.16llX",
             i_op, i_huid, i_scomAddr, *io_scomValue);
}


/**
 * @brief Send a multi scom read to the FSP
 * @param[out] o_output     Output display buffer, memory allocated here
 * @param[in]  i_huid       HUID associated with Target to get the SCOMs from
 * @param[in]  i_scomAddr   Addresses of SCOMs to read
 * @param[in]  o_scomValue  Values of read SCOMs
 */
void cmd_sendMultiScomReadToFSP( char*                 &o_output,
                                 uint32_t               i_huid,
                                 std::vector<uint64_t> &i_scomAddr,
                                 std::vector<uint64_t> &o_scomValue )
{
    UTIL_FT( "cmd_sendMultiScomReadToFSP> huid=%.8X, num_SCOMs=%d,"
             " num_outSCOMs=%d",
             i_huid, i_scomAddr.size(), o_scomValue.size() );

    TARGETING::Target* l_targ{};

    if(0xFFFFFFFF == i_huid)
    {
        TARGETING::targetService().getTopLevelTarget(l_targ);
    }
    else
    {
        l_targ = getTargetFromHUID(i_huid);
    }

    o_output = new char[500];
    if( l_targ == NULL )
    {
        sprintf( o_output, "HUID %.8X not found", i_huid );
        return;
    }

    errlHndl_t l_err = nullptr;
    l_err = FSISCOM::sendMultiScomReadToFsp( l_targ, i_scomAddr, o_scomValue);
    if (l_err)
    {
            sprintf( o_output, "Error on call to sendMultiScomReadToFsp,"
                               " rc=%.4X", ERRL_GETRC_SAFE(l_err) );
            return;
    }

    sprintf( o_output, "num_outSCOMs=%d", o_scomValue.size());
    for (auto scom: o_scomValue)
    {
        char tmp_str[100];

        sprintf( tmp_str, ", %.8llX", scom);
        strcat( o_output, tmp_str);
    }
}

#ifdef CONFIG_NVDIMM
void cmd_nvdimm_protection_msg( char* &o_output, uint32_t i_huid,
                               uint32_t protection )
{
    errlHndl_t l_err = nullptr;
    o_output = new char[500];
    uint8_t l_notifyType = NVDIMM::NOT_PROTECTED;

    TARGETING::Target* l_targ{};
    l_targ = getTargetFromHUID(i_huid);
    if (l_targ != NULL)
    {
      if (protection == 1)
      {
          l_notifyType = NVDIMM::PROTECTED;
          l_err = notifyNvdimmProtectionChange(l_targ, NVDIMM::PROTECTED);
      }
      else if (protection == 2)
      {
          l_notifyType = NVDIMM::UNPROTECTED_BECAUSE_ERROR;
          l_err = notifyNvdimmProtectionChange(l_targ, NVDIMM::UNPROTECTED_BECAUSE_ERROR);
      }
      else
      {
          l_err = notifyNvdimmProtectionChange(l_targ, NVDIMM::NOT_PROTECTED);
      }
      if (l_err)
      {
          sprintf( o_output, "Error on call to notifyNvdimmProtectionChange"
                  "(0x%.8X, %d), rc=0x%.8X, plid=0x%.8X",
                  i_huid, l_notifyType, ERRL_GETRC_SAFE(l_err), l_err->plid() );
          errlCommit(l_err, UTIL_COMP_ID);
          return;
      }
    }
    else
    {
        sprintf( o_output, "cmd_nvdimm_protection_msg: HUID 0x%.8X not found",
            i_huid );
        return;
    }
}
#endif

/**
 * @brief  Execute an arbitrary command inside Hostboot Runtime
 * @param[in]   Number of arguments (standard C args)
 * @param[in]   Array of argument values (standard C args)
 * @param[out]  Response message (NULL terminated), memory allocated
 *              by hbrt, if o_outString is NULL then no response will
 *              be sent
 * @return 0 on success, else error code
 */
int hbrtCommand( int argc,
                 const char** argv,
                 char** o_outString )
{
    int rc = 0;
    UTIL_FT("Executing run_command : argc=%d, o_outString=%p",
                argc, o_outString);

    if( !argc )
    {
        UTIL_FT("run_command : Number of arguments = 0");
        return rc;
    }

    if( argv == NULL )
    {
        UTIL_FT("run_command : Argument array is empty");
        return rc;
    }

    for( int aa=0; aa<argc; aa++ )
    {
        UTIL_FT("run_command : %d='%s'",aa,argv[aa]);
    }

    // If no output is specified, trace it instead
    bool l_traceOut = false;
    char* l_outPtr = NULL; //local value to use if needed
    char** l_output = o_outString;
    if( o_outString == NULL )
    {
        l_output = &l_outPtr;
        l_traceOut = true;
    }

    // Test path
    if( (argc == 2) && !strcmp( argv[0], "testRunCommand" ) )
    {
        *l_output = new char[strlen(argv[1])+1+5];//arg0+arg1+\0
        sprintf( *l_output, "TEST:%s", argv[1] );
    }
    else if( !strcmp( argv[0], "readvpd" ))
    {
        // readvpd <huid> <keyword> [<record>]
        if (argc == 3)
        {
            cmd_readwritevpd( *l_output,
                         DeviceFW::OperationType::READ,
                         strtou64( argv[1], NULL, 16 ),   // huid
                         strtou64( argv[2], NULL, 16 ));  // keyword

        }
        else if (argc == 4)
        {
            cmd_readwritevpd( *l_output,
                         DeviceFW::OperationType::READ,
                         strtou64( argv[1], NULL, 16 ),   // huid
                         strtou64( argv[2], NULL, 16 ),   // keyword
                         strtou64( argv[3], NULL, 16 ));  // record
        }
        else
        {
            *l_output = new char[100];
            sprintf( *l_output,
                     "ERROR: readvpd <huid> <keyword> [<record>]\n" );
        }
    }
#ifdef INCLUDE_LAB_ONLY_INTERFACES
    else if( !strcmp( argv[0], "writevpd" ) )
    {
        // writevpd <vpd> <huid> <keyword> [<record>] <data>
        if( argc == 4 )
        {
            cmd_readwritevpd( *l_output,
                         DeviceFW::OperationType::WRITE,
                         strtou64( argv[1], NULL, 16 ),   // huid
                         strtou64( argv[2], NULL, 16 ),   // keyword
                         0,                               // record
                         strtou64( argv[3], NULL, 16 ));   // data
        }
        else if (argc == 5)
        {
            cmd_readwritevpd( *l_output,
                         DeviceFW::OperationType::WRITE,
                         strtou64( argv[1], NULL, 16 ),   // huid
                         strtou64( argv[2], NULL, 16 ),   // keyword
                         strtou64( argv[3], NULL, 16 ),   // record
                         strtou64( argv[4], NULL, 16 ));  // data
        }
        else
        {
            *l_output = new char[100];
            sprintf( *l_output,
                     "ERROR: writevpd <huid> <keyword> [<record>] <data>\n" );
        }
    }
#endif // #ifdef INCLUDE_LAB_ONLY_INTERFACES
    else if( !strcmp( argv[0], "getattr" ) )
    {
        // getattr <huid> <attribute id> <size>
        if( argc == 4 )
        {
            cmd_getattr( *l_output,
                         strtou64( argv[1], NULL, 16 ),
                         strtou64( argv[2], NULL, 16 ),
                         strtou64( argv[3], NULL, 16 ) );
        }
        else
        {
            *l_output = new char[100];
            sprintf( *l_output,
                     "ERROR: getattr <huid> <attribute id> <size>\n" );
        }
    }
#ifdef INCLUDE_LAB_ONLY_INTERFACES
    else if( !strcmp( argv[0], "getscom" ) )
    {
        // getscom <huid> <address>
        if( argc == 3 )
        {
            cmd_getscom( *l_output,
                         strtou64( argv[1], NULL, 16 ),
                         strtou64( argv[2], NULL, 16 ) );
        }
        else
        {
            *l_output = new char[100];
            sprintf( *l_output, "ERROR: getscom <huid> <address>\n" );
        }
    }
    else if( !strcmp( argv[0], "putscom" ) )
    {
        // putscom <huid> <address> <data>
        if( argc == 4 )
        {
            cmd_putscom( *l_output,
                         strtou64( argv[1], NULL, 16 ),
                         strtou64( argv[2], NULL, 16 ),
                         strtou64( argv[3], NULL, 16 ) );
        }
        else
        {
            *l_output = new char[100];
            sprintf( *l_output, "ERROR: putscom <huid> <address> <data>\n" );
        }
    }
#endif  // #ifdef INCLUDE_LAB_ONLY_INTERFACES
    else if( !strcmp( argv[0], "errorlog" ) )
    {
        // errorlog <word1> <word2> <huid to callout> <size> <deconfig> <gard>
        if( (argc == 3) || (argc == 4) || (argc == 5) || (argc == 6) ||
            (argc == 7) )
        {
            uint32_t l_huid = 0;
            uint32_t l_ffdcLength = 0;
            HWAS::DeconfigEnum l_deconfig = HWAS::NO_DECONFIG;
            HWAS::GARD_ErrorType l_gard = HWAS::GARD_NULL;
            if( argc >= 4 )
            {
                l_huid = strtou64( argv[3], NULL, 16 );
            }
            if (argc >= 5)
            {
                l_ffdcLength = strtou64( argv[4], NULL, 16 );
            }
            if( argc >= 6 )
            {
                l_deconfig = static_cast<HWAS::DeconfigEnum>(
                                 strtou64( argv[5], NULL, 16 ));
            }
            if( argc >= 7 )
            {
                l_gard = static_cast<HWAS::GARD_ErrorType>(
                             strtou64( argv[6], NULL, 16 ));
            }
            cmd_errorlog( *l_output,
                          strtou64( argv[1], NULL, 16 ),
                          strtou64( argv[2], NULL, 16 ),
                          l_huid,
                          l_ffdcLength,
                          l_deconfig,
                          l_gard );
        }
        else
        {
            *l_output = new char[100];
            sprintf( *l_output, "ERROR: errorlog <word1> <word2>\n" );
        }
    }
    else if( !strcmp( argv[0], "sbemsg" ) )
    {
        // sbemsg <chipid>
        if( argc == 2 )
        {
            cmd_sbemsg( *l_output,
                         strtou64( argv[1], NULL, 16 ) );
        }
        else
        {
            *l_output = new char[100];
            sprintf( *l_output, "ERROR: sbemsg <chipid>\n" );
        }
    }
    else if( !strcmp( argv[0], "reload_pm_complex" ) )
    {
        uint64_t breakPoint = 0;
        if (argc == 2)
        {
            breakPoint = strtou64( argv[1], NULL, 16 );
        }
        rc = cmd_reload_pm_complex(*l_output, breakPoint);
    }
    else if( !strcmp( argv[0], "readHBRTversion" ) )
    {
        // readHBRTversion
        if( argc == 1 )
        {
            cmd_readHBRTversion( *l_output );
        }
        else
        {
            *l_output = new char[100];
            sprintf( *l_output,
                     "ERROR: readHBRTversion\n" );
        }
    }
    else if( !strcmp( argv[0], "hbrt_update" ) )
    {
        // hbrt_update
        if( argc == 1 )
        {
            cmd_hbrt_update( *l_output );
        }
        else
        {
            *l_output = new char[100];
            sprintf( *l_output,
                     "ERROR: hbrt_update\n" );
        }
    }
    else if( !strcmp( argv[0], "switchToSbeScomAccess" ) )
    {
        if (argc == 2)
        {
            cmd_switchToSbeScomAccess( *l_output,
                                       strtou64(argv[1], NULL, 16)); // huid
        }
        else
        {
            *l_output = new char[100];
            sprintf(*l_output,
                    "ERROR: switchToSbeScomAccess <ocmb huid>");
        }
    }
    else if( !strcmp( argv[0], "scomOpToFsp" ) )
    {
        if ((argc == 4) || (argc == 5))
        {
            uint64_t l_scomValue = 0;

            if (argc == 5)
                l_scomValue = strtou64( argv[4], NULL, 16 );  // value

            cmd_sendScomOpToFSP( *l_output,
                                 argv[1][0],                  // op
                                 strtou64(argv[2], NULL, 16), // huid
                                 strtou64(argv[3], NULL, 16), // addr
                                 &l_scomValue );
        }
        else
        {
            *l_output = new char[100];
            sprintf(*l_output,
                    "ERROR: scomOpToFsp <op> <huid> <scomAddr> [<scomValue>]");
        }
    }
    else if( !strcmp( argv[0], "multiScomReadToFsp" ) )
    {
        if (argc >= 3)
        {
            std::vector<uint64_t> l_scomAddrs, l_scomValues;

            for (int i = 2;i < argc;++i)
                l_scomAddrs.push_back(strtou64( argv[i], NULL, 16 ));
            l_scomValues.reserve(argc - 2);

            cmd_sendMultiScomReadToFSP( *l_output,
                                        strtou64(argv[1], NULL, 16), // huid
                                        l_scomAddrs,
                                        l_scomValues );
        }
        else
        {
            *l_output = new char[100];
            sprintf(*l_output,
                    "ERROR: multiScomReadToFsp <huid> <scomAddrs>");
        }
    }
#ifdef CONFIG_NVDIMM
    else if( !strcmp( argv[0], "nvdimm_protection" ) )
    {
        if (argc >= 3)
        {
          uint32_t huid = strtou64(argv[1], NULL, 16);
          uint32_t protection = strtou64( argv[2], NULL, 16);
          cmd_nvdimm_protection_msg( *l_output, huid, protection );
        }
        else
        {
            *l_output = new char[100];
            sprintf(*l_output, "ERROR: nvdimm_protection <huid> <0 or 1>");
        }
    }
#endif
    else if( !strcmp( argv[0], "lidload" ) )
    {
        if (argc == 2)
        {
            *l_output = new char[100];
            uint32_t i_lidnumber = strtou64(argv[1], NULL, 16);
            size_t lidsize = 0;
            UtilLidMgr thelid(i_lidnumber);
            errlHndl_t l_err = thelid.getLidSize(lidsize);
            if( l_err )
            {
                sprintf( *l_output, "Error calling getLidSize()"
                         "(lid=0x%.8X), rc=0x%.8X, plid=0x%.8X",
                         i_lidnumber, ERRL_GETRC_SAFE(l_err),
                         l_err->plid() );
                errlCommit(l_err, UTIL_COMP_ID);
            }
            else
            {
                sprintf( *l_output, "Lid %.8x is %d bytes",
                         i_lidnumber, lidsize );
            }
        }
        else
        {
            *l_output = new char[100];
            sprintf(*l_output, "ERROR: lidload <lidnumber>");
        }
    }
    else if( !strcmp( argv[0], "getcaps" ) )
    {
        if (argc == 1)
        {
            *l_output = new char[300];
            char tmpstr[100];

            sprintf(*l_output, "get_interface_capabilities> ");
            UTIL_FT("::%s",*l_output);

            uint64_t l_caps = g_hostInterfaces->
              get_interface_capabilities(HBRT_CAPS_SET0_COMMON);
            sprintf( tmpstr, "SET0_COMMON=%.16llX ", l_caps );
            strcat( *l_output, tmpstr );
            UTIL_FT("::%s",*l_output);

            l_caps = g_hostInterfaces->
              get_interface_capabilities(HBRT_CAPS_SET1_OPAL);
            sprintf( tmpstr, "SET1_OPAL=%.16llX ", l_caps );
            strcat( *l_output, tmpstr );
            UTIL_FT("::%s",*l_output);

            l_caps = g_hostInterfaces->
              get_interface_capabilities(HBRT_CAPS_SET2_PHYP);
            sprintf( tmpstr, "SET2_PHYP=%.16llX ", l_caps );
            strcat( *l_output, tmpstr );
            UTIL_FT("::%s",*l_output);
        }
        else
        {
            *l_output = new char[100];
            sprintf(*l_output, "ERROR: getcaps");
        }
    }
#ifdef CONFIG_HTMGT
    else if( !strcmp( argv[0], "resetPmComplexWithReason" ) )
    {
        // resetPmComplexWithReason [<OCC_RESET_REASON>] [<chipId>]
        if(argc <= 3)
        {
            int rc = 0;
            uint64_t occ_reset_reason = 0;
            uint64_t chipId = 0;

            *l_output = new char[300];
            char tmpstr[100];

            sprintf(*l_output, "resetPmComplexWithReason> ");

            if (argc == 2)
            {
                occ_reset_reason = strtou64( argv[1], NULL, 16 ); // OCC_RESET_REASON
                sprintf(tmpstr, "occ_reason=0x%.16llX (chipId defaults to 0)", occ_reset_reason);
            }
            else if (argc == 3)
            {
                occ_reset_reason = strtou64( argv[1], NULL, 16 ); // OCC_RESET_REASON
                chipId  = strtou64( argv[2], NULL, 16 ); // chipId
                sprintf(tmpstr, "occ_reason=0x%.16llX, chipId=0x%.16llX", occ_reset_reason, chipId);
            }
            else // arc==1
            {
                sprintf(tmpstr, "defaulting occ_reason to 0 and chipId defaults to 0", occ_reset_reason);
            }

            strcat( *l_output, tmpstr );
            UTIL_FT("::%s",*l_output);

            rc = HTMGT::reset_pm_complex_with_reason(
                         static_cast<OCC_RESET_REASON>(occ_reset_reason),
                         chipId);
            sprintf(*l_output, "back from resetPmComplexWithReason> rc=%d", rc);
            UTIL_FT("::%s",*l_output);
        }
        else
        {
            *l_output = new char[100];
            sprintf( *l_output,
                     "ERROR: resetPmComplexWithReason [0x<OCC_RESET_REASON>] [0x<chipId>]\n");
        }
    }
#endif
    else
    {
        *l_output = new char[50+100*12];
        char l_tmpstr[100];
        sprintf( *l_output, "HBRT Commands:\n" );
        sprintf( l_tmpstr, "testRunCommand <arg>\n" );
        strcat( *l_output, l_tmpstr );
        sprintf( l_tmpstr, "getattr <huid> <attribute id> <size>\n" );
        strcat( *l_output, l_tmpstr );
#ifdef INCLUDE_LAB_ONLY_INTERFACES
        sprintf( l_tmpstr, "getscom <huid> <address>\n" );
        strcat( *l_output, l_tmpstr );
        sprintf( l_tmpstr, "putscom <huid> <address> <data>\n" );
        strcat( *l_output, l_tmpstr );
#endif
        sprintf( l_tmpstr, "errorlog <word1> <word2> [<huid to callout>] [size] [deconfig] [gard]\n" );
        strcat( *l_output, l_tmpstr );
        sprintf( l_tmpstr, "sbemsg <chipid>\n" );
        strcat( *l_output, l_tmpstr );
        sprintf( l_tmpstr, "readvpd <huid> <keyword> [record]\n" );
        strcat( *l_output, l_tmpstr );
#ifdef INCLUDE_LAB_ONLY_INTERFACES
        sprintf( l_tmpstr, "writevpd <huid> <keyword> [<record>] <data>\n" );
        strcat( *l_output, l_tmpstr );
#endif
        sprintf( l_tmpstr, "reload_pm_complex [<breakPoint>]\n");
        strcat( *l_output, l_tmpstr );
        sprintf( l_tmpstr, "readHBRTversion\n");
        strcat( *l_output, l_tmpstr );
        sprintf( l_tmpstr, "hbrt_update\n");
        strcat( *l_output, l_tmpstr );
        sprintf( l_tmpstr, "switchToSbeScomAccess <ocmb huid>\n");
        strcat( *l_output, l_tmpstr );
        sprintf( l_tmpstr, "scomOpToFsp <op> <huid> <scomAddr> [<scomValue>]\n"
                           "            <op> == r|w\n");
        strcat( *l_output, l_tmpstr );
        sprintf( l_tmpstr, "multiScomReadToFsp <huid> <scomAddrs>\n");
        strcat( *l_output, l_tmpstr );
#ifdef CONFIG_NVDIMM
        sprintf( l_tmpstr, "nvdimm_protection <huid> <0 or 1>\n");
        strcat( *l_output, l_tmpstr );
#endif
        sprintf( l_tmpstr, "lidload <lid number>\n");
        strcat( *l_output, l_tmpstr );
        sprintf( l_tmpstr, "getcaps\n");
        strcat( *l_output, l_tmpstr );
#ifdef CONFIG_HTMGT
        sprintf( l_tmpstr, "resetPmComplexWithReason [0x<OCC_RESET_REASON>] [0x<chipId>]\n");
        strcat( *l_output, l_tmpstr );
#endif
    }

    if( l_traceOut && (*l_output != NULL) )
    {
        UTIL_FT("Output::%s",*l_output);
        delete *l_output;
    }

    return rc;
}

};


struct registerCmds
{
    registerCmds()
    {
        getRuntimeInterfaces()->run_command =
                                    DISABLE_MCTP_WRAPPER(Util::hbrtCommand);
    }
};

registerCmds g_registerCmds;



