/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/prdfFilters.C $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
 @file iipFilters.C
 @brief Definition of SingleBitFilter, PrioritySingleBitFilter, FilterLink,
 and ScanCommFilter classes.
*/

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#define iipFilters_C

#include <prdfBitKey.H>
#include <prdfFilters.H>
//#include <xspprdScanCommFilter.h>
//#include <xspprdFilterLink.h>
#include <iipstep.h>
#include <iipServiceDataCollector.h>
#undef iipFilters_C

namespace PRDF
{
//----------------------------------------------------------------------
//  User Types
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Constants
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Macros
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Internal Function Prototypes
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Global Variables
//----------------------------------------------------------------------

//----------------------------------------------------------------------
// Member Function Specifications
//----------------------------------------------------------------------

FilterClass::~FilterClass(void)
{}

//-----------------------------------------------------------------------------

bool FilterPriority::Apply( BitKey & ioBitList, STEP_CODE_DATA_STRUCT & io_sdc )
{
    bool modified = false;
    if( ioBitList.isSubset(ivBitKey) )
    {
        ioBitList = ivBitKey;
        modified = true;
    }
    return modified;
}


//------------------------------------------------------------------------------

bool SingleBitFilter::Apply( BitKey & bit_list, STEP_CODE_DATA_STRUCT & io_sdc )
{
    bool rc = false;
    uint32_t list_length = bit_list.size();
    if( list_length > 1 )
    {
        rc = true;
        while( --list_length )
        {
            bit_list.removeBit();
        }
    }
    return( rc );
}


//-----------------------------------------------------------------------------

bool PrioritySingleBitFilter::Apply( BitKey & bit_list,
                                     STEP_CODE_DATA_STRUCT & io_sdc )
{
    bool l_modified = false;

    // Do priority bit.
    for ( size_t i = 0; i < iv_bitList.size(); i++ )
    {
        BitKey l_key = iv_bitList[i];
        if ( bit_list.isSubset(l_key) )
        {
            l_modified = true;
            bit_list = l_key;
            break;
        }
    }
    // Do single bit filter portion.
    if ( !l_modified )
    {
        while ( 1 < bit_list.size() )
        {
            l_modified = true;
            bit_list.removeBit();
        }
    }
    return l_modified;
}

//------------------------------------------------------------------------------

bool FilterTranspose::Apply( BitKey & iBitList, STEP_CODE_DATA_STRUCT & io_sdc )
{
    bool result = false;
    if(iBitList == ivBitKey)
    {
        BitKey bk(ivSingleBitPos);
        iBitList = bk;
        result = true;
    }
    return result;
}

bool FilterTranspose::Undo(BitKey & iBitList)
{
    bool result = false;
    BitKey testbl(ivSingleBitPos);
    if(iBitList.isSubset(testbl))
    {
        iBitList = ivBitKey;
        result = true;
    }

    return result;
}

//-----------------------------------------------------------------------------

bool FilterLink::Apply( BitKey & bit_list, STEP_CODE_DATA_STRUCT & io_sdc )
{
    // NOTE: Apply() for both filters must be called regardless of the rc.
    bool rc1 = xFilter1.Apply( bit_list, io_sdc );
    bool rc2 = xFilter2.Apply( bit_list,io_sdc );
    rc2 = rc1 || rc2;

    return rc2;
}

bool FilterLink::Undo( BitKey & bit_list )
{
    // NOTE: Undo() for both filters must be called regardless of the rc.
    bool rc1 = xFilter1.Undo(bit_list);
    bool  rc2 = xFilter2.Undo(bit_list);
    rc2 = rc1 || rc2;

    return rc2;
}

//------------------------------------------------------------------------------

bool SecondaryBitsFilter::Apply( BitKey & io_bitList,
                                 STEP_CODE_DATA_STRUCT & io_sdc )
{
    #define PRDF_FUNC  "[SecondaryBitsFilter::Apply] "
    bool l_modified = false;
    do
    {
        // This filter should only be applied on the primary passs.
        if ( !io_sdc.service_data->isPrimaryPass() ) break;

        // This filter should only be applied if the primary attention type is
        // CHECK_STOP.
        if ( CHECK_STOP != io_sdc.service_data->getPrimaryAttnType() ) break;

        // This filter should only be applied if the the secondary attention
        // type is RECOVERABLE.
        if ( RECOVERABLE != io_sdc.service_data->getSecondaryAttnType()) break;

        //if there is no secondary bit position to flip or if no bit is set in
        //bit key then let us skip this apply.
        if( ( 0 == iv_secBitList.size() ) || ( 0 == io_bitList.size()) ) break;

        BitKey l_key ( iv_secBitList );
        io_bitList.removeBits( l_key );
        l_modified = true;

        if( 0 == io_bitList.size() )
        {
            // So, we have no primary bits on. We have one or more secondary bit
            // on.
            io_sdc.service_data->setSecondaryErrFlag();
        }

    }while(0);

    return l_modified;

    #undef PRDF_FUNC
}

} //End namespace PRDF

