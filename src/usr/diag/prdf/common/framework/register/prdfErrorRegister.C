/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/prdfErrorRegister.C $ */
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
 @file iipErrorRegister.C
 @brief ErrorRegister class definition
*/
// Module Description **************************************************
//
// Description: Definition of ErrorRegister class
//
// End Module Description **********************************************
//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#define iipErrorRegister_C

#include <prdfMain.H>
#include <prdfAssert.h>
#include <iipstep.h>
#include <iipbits.h>
#include <iipResolution.h>
#include <iipscr.h>
#include <prdfErrorSignature.H>
#include <iipServiceDataCollector.h>
#include <prdfResolutionMap.H>
#include <iipErrorRegister.h>

#include <iipconst.h>
#include <prdfGlobal.H>
#undef iipErrorRegister_C

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

//---------------------------------------------------------------------
// Member Function Specifications
//---------------------------------------------------------------------

int32_t ErrorRegister::SetErrorSignature( STEP_CODE_DATA_STRUCT & error,
                                          BitKey & bl )
{
    int32_t rc = SUCCESS;
    ErrorSignature * esig = error.service_data->GetErrorSignature();
    uint32_t blen = bl.size();
    switch( blen )
    {
        case 0:
            esig->setErrCode( PRD_SCAN_COMM_REGISTER_ZERO );
            if( error.service_data->isPrimaryPass() )
            {
                rc = PRD_SCAN_COMM_REGISTER_ZERO;
            }
            else if( !xNoErrorOnZeroScr )
            {
                rc = PRD_SCAN_COMM_REGISTER_ZERO;
            }
            break;

        case 1:
            esig->setErrCode(bl.getListValue(0));
            break;

        default:
            for( uint32_t index = 0; index < blen; ++index )
            {
                esig->setErrCode(bl.getListValue(index));
            }
            esig->setErrCode(PRD_MULTIPLE_ERRORS);
    };
    return rc;
}

/*---------------------------------------------------------------------*/

ErrorRegister::ErrorRegister( SCAN_COMM_REGISTER_CLASS & r, ResolutionMap & rm,
                              uint16_t scrId ) :
    ErrorRegisterType(), scr(r), scr_rc(SUCCESS), rMap(rm),
    xNoErrorOnZeroScr(false), xScrId(scrId)
{
}

/*---------------------------------------------------------------------*/

int32_t ErrorRegister::Analyze( STEP_CODE_DATA_STRUCT & io_sdc )
{
    int32_t rc = SUCCESS;
    uint32_t l_savedErrSig = 0;

    ErrorSignature * esig = io_sdc.service_data->GetErrorSignature();

    if(xScrId == 0x0fff)
    {
        esig->setRegId(scr.GetAddress());
    }
    else
    {
        esig->setRegId( xScrId );
    }

    // Get Data from hardware
    const BIT_STRING_CLASS &bs =
                Read( io_sdc.service_data->getSecondaryAttnType() );
    BitKey bl;     // null bit list has length 0

    if ( scr_rc == SUCCESS )
    {
        bl = Filter( bs );
        rc = SetErrorSignature( io_sdc, bl );

        // Save signature to determine if it changes during resolution
        // execution.
        l_savedErrSig = esig->getSigId();
    }

    // This loop will iterate through all bits in the bit list until an active
    // attention is found. This is useful in the cases where a global or chiplet
    // level FIR has multiple bits set, but the associated local FIRs may not
    // have an active attention because of a filter or hardware bug.
    uint32_t res_rc = SUCCESS;
    BitKey analyzed_bl;       // Keep track of bits that have been analyzed.
    BitKey remaining_bl = bl; // Keep track of bits that need to be analyzed.
    do
    {
        BitKey res_bl = remaining_bl;
        BitKey tmp_bl = remaining_bl;

        // lookup and execute the resolutions
        res_rc = Lookup( io_sdc, res_bl );

        // Add the resolved bits to the analyzed list.
        // TODO: RTC 126267 Should modify BitKey to have a more efficient way of
        //       adding bits to a list.
        for ( uint32_t i = 0; i < res_bl.size(); i++ )
            analyzed_bl.setBit(res_bl.getListValue(i));

        // Remove the resolved bits from the remaining list.
        remaining_bl.removeBits(res_bl);

        // Make sure forward progress is made.
        if ( tmp_bl == remaining_bl ) break;

    } while ( (PRD_SCAN_COMM_REGISTER_ZERO == res_rc) &&
              (0 != remaining_bl.size()) );

    if ( SUCCESS == rc ) rc = res_rc; // previous rc has prioity over res_rc

    // If we had a DD02 and the signature changes, ignore DD02.
    if ( rc == PRD_SCAN_COMM_REGISTER_ZERO )
    {
        uint32_t l_currentSig = esig->getSigId();
        if( l_currentSig != l_savedErrSig )
        {
            // Found a better answer during the DD02 analysis.
            rc = res_rc;
        }
    }

    if( scr_rc == SUCCESS )
    {
        FilterUndo( analyzed_bl );
        // NOTE:  This is an unusual work-a-round for NOT clearing
        //        particular FIR bits in a register because they are cleared
        //        in another part of the plugin code.
        if( rc == PRD_NO_CLEAR_FIR_BITS )
        {
            //Return success to indicate that we understand the DDFF
            rc = SUCCESS;
        }
        else
        {
            int32_t reset_rc;
            reset_rc = Reset( analyzed_bl, io_sdc );
            if( rc == SUCCESS ) rc = reset_rc;
        }
    }
    else // scr read failed
    {
        esig->setErrCode( PRD_SCANCOM_FAILURE );
        rc = scr_rc;
    }

    return(rc);
}

/*---------------------------------------------------------------------*/

const BIT_STRING_CLASS & ErrorRegister::Read(ATTENTION_TYPE i_attn)
{
    scr_rc = scr.Read();
    return (*scr.GetBitString(i_attn));
}

/*---------------------------------------------------------------------*/

BitKey ErrorRegister::Filter( const BIT_STRING_CLASS & bs )
{
    BitKey bit_list;
    bit_list = bs;
    return( bit_list );
}

/*---------------------------------------------------------------------*/

int32_t ErrorRegister::Lookup(STEP_CODE_DATA_STRUCT & sdc, BitKey & bl)
{
    int32_t rc = SUCCESS;
    ResolutionList rList;
    rc = rMap.LookUp( rList,bl,sdc );
    for( ResolutionList::iterator i = rList.begin(); i != rList.end(); ++i )
    {
        rc |= (*i)->Resolve( sdc );
    }

    return rc;
}

/*---------------------------------------------------------------------*/

int32_t ErrorRegister::Reset( const BitKey & bit_list,
                              STEP_CODE_DATA_STRUCT & error )
{
    return(SUCCESS);
}

} // end namespace PRDF

