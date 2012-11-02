/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/prdfResolutionMap.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2004,2012              */
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

/** @file  prdfResolutionMap.C
 *  @brief prdfResolutionMap definition
 */

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <string.h>

#include <prdfResolutionMap.H>
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

void ResolutionMap::LookUp( ResolutionList & o_list,
                            BitKey & io_bitList,
                            STEP_CODE_DATA_STRUCT & scd )
{
    uint32_t lsize = o_list.size();

    if(iv_filter != NULL)
    {
        iv_filter->Apply(io_bitList);
    }

    ErrorSignature * esig = scd.service_data->GetErrorSignature();
    switch(io_bitList.size())
    {
        case 0:
            esig->setErrCode(PRD_SCAN_COMM_REGISTER_ZERO);
            break;
        case 1:
            esig->setErrCode(io_bitList.getListValue(0));
            break;
        default:
            for(uint32_t index = 0; index < io_bitList.size(); ++index)
            {
                esig->setErrCode(io_bitList.getListValue(index));
            }
            esig->setErrCode(PRD_MULTIPLE_ERRORS);
    };

    for(MapList::iterator i = iv_list.begin(); i != iv_list.end(); ++i)
    {
        if((i->iv_blist).isSubset(io_bitList))
        {
            o_list.push_back(i->iv_res);
        }
    }
    if(lsize == o_list.size()) // we didn't find anything to add, so use default
    {
        o_list.push_back(defaultRes);
    }

    if(iv_filter != NULL)
    {
        iv_filter->Undo(io_bitList); // so returned bit list will have proper
                                     // value for reset
    }
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

