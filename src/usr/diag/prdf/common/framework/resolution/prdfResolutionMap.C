/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/prdfResolutionMap.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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

/** @file  prdfResolutionMap.C
 *  @brief prdfResolutionMap definition
 */

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <string.h>

#include <prdfResolutionMap.H>
#include <iipResolutionFactory.h>
#include <iipstep.h>
#include <iipServiceDataCollector.h>
#include <prdfErrorSignature.H>
#include <prdfMain.H>

namespace PRDF
{

//------------------------------------------------------------------------------

void ResolutionMap::Add( uint8_t i_bitPos, Resolution * i_res )
{
    MapList::iterator i = iv_list.begin();
    while(i != iv_list.end())
    {
        if (i->iv_blist == BitKey()) // If empty bit string, skip.
        {
        }
        else if( (i->iv_res == i_res) || (*(i->iv_res) == *i_res))
        {
            i->iv_blist.setBit(i_bitPos);
            break;
        }
        ++i;
    }
    if(i == iv_list.end())
    {
        if(iv_list.capacity() == iv_list.size())
        {
            iv_list.reserve(iv_list.size() + 10);
        }
        iv_list.push_back( RmPair(i_bitPos,i_res) );
    }
}

//------------------------------------------------------------------------------

void ResolutionMap::Add( uint8_t i_bitPos, Resolution * i_r1,
                         Resolution * i_r2 )
{
    Add(i_bitPos,i_r1);
    Add(i_bitPos,i_r2);
}

//------------------------------------------------------------------------------

void ResolutionMap::Add(uint8_t i_bitPos,
                            Resolution * i_r1,
                            Resolution * i_r2,
                            Resolution * i_r3)
{
    Add(i_bitPos,i_r1,i_r2);
    Add(i_bitPos,i_r3);
}

//------------------------------------------------------------------------------

void ResolutionMap::Add(uint8_t i_bitPos,
                            Resolution * i_r1,
                            Resolution * i_r2,
                            Resolution * i_r3,
                            Resolution * i_r4)
{
    Add(i_bitPos,i_r1,i_r2);
    Add(i_bitPos,i_r3,i_r4);
}

//------------------------------------------------------------------------------

void ResolutionMap::Add(uint8_t i_bitPos,
                            Resolution * i_r1,
                            Resolution * i_r2,
                            Resolution * i_r3,
                            Resolution * i_r4,
                            Resolution * i_r5)
{
    Add(i_bitPos,i_r1,i_r2,i_r3);
    Add(i_bitPos,i_r4,i_r5);
}

//------------------------------------------------------------------------------

void ResolutionMap::Add(uint8_t i_bitPos,
                            Resolution * i_r1,
                            Resolution * i_r2,
                            Resolution * i_r3,
                            Resolution * i_r4,
                            Resolution * i_r5,
                            Resolution * i_r6)
{
    Add(i_bitPos,i_r1,i_r2,i_r3);
    Add(i_bitPos,i_r4,i_r5,i_r6);
}

//------------------------------------------------------------------------------

void ResolutionMap::Add(uint8_t i_bitPos,
                            Resolution * i_r1,
                            Resolution * i_r2,
                            Resolution * i_r3,
                            Resolution * i_r4,
                            Resolution * i_r5,
                            Resolution * i_r6,
                            Resolution * i_r7)
{
    Add(i_bitPos,i_r1,i_r2,i_r3);
    Add(i_bitPos,i_r4,i_r5,i_r6,i_r7);
}

//------------------------------------------------------------------------------

void ResolutionMap::Add( const uint8_t *i_ble,
                         uint8_t i_bleLen,
                         Resolution * i_res )
{
    MapList::iterator i = iv_list.begin();
    while(i != iv_list.end())
    {
        if ((i->iv_blist == BitKey()) || (0 == i_bleLen))
        {
            // Empty bit string, skip.
        }
        else if( (i->iv_res == i_res) || (*(i->iv_res) == *i_res))
        {
            for(uint32_t j = 0; j < (uint32_t)i_bleLen; ++j)
            {
                i->iv_blist.setBit(i_ble[j]);
            }
            break;
        }
        ++i;
    }
    if(i == iv_list.end())
    {
        RmPair rmp;
        rmp.iv_res = i_res;
        for(uint32_t j = 0; j < (uint32_t)i_bleLen; ++j)
        {
            rmp.iv_blist.setBit(i_ble[j]);
        }
        if(iv_list.capacity() == iv_list.size())
        {
            iv_list.reserve(iv_list.size() + 10);
        }
        iv_list.push_back(rmp);
    }
}

//------------------------------------------------------------------------------

void ResolutionMap::Add(const uint8_t *i_ble,
                            uint8_t i_bleLen,
                            Resolution * r1,
                            Resolution * r2)
{
    Add(i_ble,i_bleLen,r1);
    Add(i_ble,i_bleLen,r2);
}

//------------------------------------------------------------------------------

void ResolutionMap::Add(const uint8_t *i_ble,
                            uint8_t i_bleLen,
                            Resolution * r1,
                            Resolution * r2,
                            Resolution * r3)
{
    Add(i_ble,i_bleLen,r1,r2);
    Add(i_ble,i_bleLen,r3);
}

//------------------------------------------------------------------------------

void ResolutionMap::Add(const uint8_t *i_ble,
                            uint8_t i_bleLen,
                            Resolution * r1,
                            Resolution * r2,
                            Resolution * r3,
                            Resolution * r4)
{
    Add(i_ble,i_bleLen,r1,r2);
    Add(i_ble,i_bleLen,r3,r4);
}

//------------------------------------------------------------------------------

void ResolutionMap::Add(const uint8_t *i_ble,
                            uint8_t i_bleLen,
                            Resolution * r1,
                            Resolution * r2,
                            Resolution * r3,
                            Resolution * r4,
                            Resolution * r5)
{
    Add(i_ble,i_bleLen,r1,r2);
    Add(i_ble,i_bleLen,r3,r4,r5);
}

//------------------------------------------------------------------------------

void ResolutionMap::Add(const uint8_t *i_ble,
                            uint8_t i_bleLen,
                            Resolution * r1,
                            Resolution * r2,
                            Resolution * r3,
                            Resolution * r4,
                            Resolution * r5,
                            Resolution * r6)
{
    Add(i_ble,i_bleLen,r1,r2,r3);
    Add(i_ble,i_bleLen,r4,r5,r6);
}

//------------------------------------------------------------------------------

int32_t ResolutionMap::LookUp( ResolutionList & o_list,
                               BitKey & io_bitList,
                               STEP_CODE_DATA_STRUCT & scd,
                               bool & o_default )
{
    o_default = false;
    uint32_t lsize = o_list.size();
    int32_t l_rc = SUCCESS;

    if(iv_filter != nullptr)
    {
        iv_filter->Apply( io_bitList,scd );
    }

    ErrorSignature * esig = scd.service_data->GetErrorSignature();
    switch( io_bitList.size() )
    {
            // we are setting rc to PRD_SCAN_COMM_REGISTER_ZERO in case 0 below.
            // But we don't set rc to bit found set ( case 1 ) or
            // PRD_MULTIPLE_ERRORS. It's because for the code calling this
            // function, one bit set or  multiple bit set make little
            // difference. In both cases, it has to do same set of actions.
            // We need to treat case 0 separately. It is because we want to
            // know the outcome of action of csRootCause filter. If csRootCause
            // filter yields 0xdd02, we know we need to launch one more pass
            // with filter turned off.
        case 0:
            esig->setErrCode( PRD_SCAN_COMM_REGISTER_ZERO );
            l_rc = PRD_SCAN_COMM_REGISTER_ZERO;
            break;
        case 1:
            esig->setErrCode( io_bitList.getListValue(0) );
            break;
        default:
            for( uint32_t index = 0; index < io_bitList.size(); ++index )
            {
                esig->setErrCode( io_bitList.getListValue(index) );
            }
           esig->setErrCode( PRD_MULTIPLE_ERRORS );
    };

    for( MapList::iterator i = iv_list.begin(); i != iv_list.end(); ++i )
    {
        if( ( i->iv_blist ).isSubset( io_bitList ) )
        {
            o_list.push_back( i->iv_res );
        }
    }

    // we didn't find anything to add, so use default
    // if it is a primary pass and we haven't found any bit set, let us
    // prevent default resolution from getting executed. It is primarily
    // because end of primary pass doesn't necessarily mean end of analysis.
    // There may be a case when a FIR has only a secondary bit on. In that
    // case, primary pass shall fail to find any bit set and initiate
    // secondary pass. In secondary pass, bits set shall be identified and
    // associated resolution shall be executed.

    if ( lsize == o_list.size() &&
         CHECK_STOP == scd.service_data->getPrimaryAttnType() &&
         (!scd.service_data->isPrimaryPass() ||
          !scd.service_data->isSecondaryErrFound()) )
    {
        o_default = true;
        ResolutionFactory & resFac = ResolutionFactory::Access();
        Resolution & defRes = resFac.getCalloutGardResol( nullptr, MRU_MED, GARD );
        o_list.push_back( &defRes );
    }

    if( iv_filter != nullptr )
    {
        iv_filter->Undo(io_bitList); // so returned bit list will have proper
                                     // value for reset
    }

    return l_rc;
}

//------------------------------------------------------------------------------

void ResolutionMap::Add( const char *i_ble, Resolution * res )
{
    uint8_t len = strlen(i_ble);
    uint8_t * bl = new uint8_t[len];
    for(uint8_t i = 0; i < len; ++i)
    {
        bl[i] = (uint8_t)(i_ble[i] - 1);
    }
    Add(bl,len,res);
    delete [] bl;
}

void ResolutionMap::Add( const char *i_ble,
                         Resolution * r1, Resolution * r2 )
{
    Add(i_ble,r1);
    Add(i_ble,r2);
}

void ResolutionMap::Add( const char *i_ble,
                         Resolution * r1, Resolution * r2, Resolution * r3 )
{
    Add(i_ble,r1,r2);
    Add(i_ble,r3);
}

void ResolutionMap::Add( const char *i_ble,
                         Resolution * r1, Resolution * r2, Resolution * r3,
                         Resolution * r4 )
{
    Add(i_ble,r1,r2);
    Add(i_ble,r3,r4);
}

void ResolutionMap::Add( const char *i_ble,
                         Resolution * r1, Resolution * r2, Resolution * r3,
                         Resolution * r4, Resolution * r5 )
{
    Add(i_ble,r1,r2);
    Add(i_ble,r3,r4,r5);
}

void ResolutionMap::Add( const char *i_ble,
                         Resolution * r1, Resolution * r2, Resolution * r3,
                         Resolution * r4, Resolution * r5, Resolution * r6 )

{
    Add(i_ble,r1,r2,r3);
    Add(i_ble,r4,r5,r6);
}

//------------------------------------------------------------------------------

void ResolutionMap::Add( const char *i_ble,
                         Resolution * r1, Resolution * r2, Resolution * r3,
                         Resolution * r4, Resolution * r5, Resolution * r6,
                         Resolution * r7 )

{
    Add(i_ble,r1,r2,r3);
    Add(i_ble,r4,r5,r6,r7);
}

} // end namespace PRDF

