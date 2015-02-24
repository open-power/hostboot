/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/occ_firdata/prdfReadPnorFirData.C $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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

#include <prdfReadPnorFirData.H>

#include <pnorData_common.h>

#include <prdfPlatServices.H>
#include <prdfTrace.H>

#include <pnor/pnorif.H>
#include <prdfErrlUtil.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

class FirData
{
  public:

    /** @brief Constructor
     *  @param i_pBuf        Pointer to the PNOR data buffer
     *  @param i_maxPBufSize Maximum size of the PNOR data buffer
     */
    FirData( uint8_t * i_pBuf, size_t i_maxPBufSize ) :
        iv_pBuf(i_pBuf), iv_maxPBufSize(i_maxPBufSize), iv_pBufSize(0)
    {}

    /** @brief  Template function to get data from the PNOR buffer.
     *  @param  o_data Data to extract from the buffer.
     *  @return True if the PNOR buffer is full, false if there was room.
     */
    template <typename T>
    bool getData( T & o_data )
    {
        size_t sz_data = sizeof(*o_data);
        bool full = (iv_maxPBufSize < iv_pBufSize + sz_data);
        if ( !full )
        {
            o_data = reinterpret_cast<T>(&iv_pBuf[iv_pBufSize]);
            iv_pBufSize += sz_data;
        }
        return full;
    }

  private:

    uint8_t  * iv_pBuf;        ///< Pointer to the PNOR data buffer
    uint32_t   iv_maxPBufSize; ///< Maximum size of the PNOR data buffer
    size_t     iv_pBufSize;    ///< Current size of the PNOR data buffer
};

//------------------------------------------------------------------------------

TargetHandle_t getTargetHandle( PNOR_Trgt_t * i_pTrgt )
{
    TargetHandle_t o_trgt = NULL;

    do
    {
        // Get the target type.
        TYPE type = TYPE_LAST_IN_RANGE;
        switch ( i_pTrgt->type )
        {
            case PROC:  type = TYPE_PROC;   break;
            case EX:    type = TYPE_EX;     break;
            case MCS:   type = TYPE_MCS;    break;
            case MEMB:  type = TYPE_MEMBUF; break;
            case MBA:   type = TYPE_MBA;    break;
        }
        if ( TYPE_LAST_IN_RANGE == type ) break;

        // Get the PROC target.
        TargetHandle_t procTrgt = NULL;
        TargetHandleList procList = getFunctionalTargetList( TYPE_PROC );
        for ( TargetHandleList::iterator i = procList.begin();
              i != procList.end(); ++i )
        {
            if ( i_pTrgt->procPos == getTargetPosition(*i) )
            {
                procTrgt = *i;
                break;
            }
        }
        if ( NULL == procTrgt ) break;

        if ( TYPE_PROC == type )
        {
            o_trgt = procTrgt; // nothing more to do.
        }
        else if ( TYPE_EX == type || TYPE_MCS == type || TYPE_MEMBUF == type )
        {
            // Get the connected child
            o_trgt = getConnectedChild( procTrgt, type, i_pTrgt->unitPos );
        }
        else if ( TYPE_MBA == type )
        {
            uint32_t membPos = i_pTrgt->unitPos / MAX_MBA_PER_MEMBUF;
            uint32_t mbaPos  = i_pTrgt->unitPos % MAX_MBA_PER_MEMBUF;

            // Get the connected MEMBUF
            TargetHandle_t membTrgt = getConnectedChild( procTrgt, TYPE_MEMBUF,
                                                         membPos );
            if ( NULL != membTrgt )
            {
                // Get the connected MBA
                o_trgt = getConnectedChild( membTrgt, type, mbaPos );
            }
        }

    } while (0);

    return o_trgt;
}

//------------------------------------------------------------------------------

errlHndl_t readPnorData( uint8_t * & o_pBuf, size_t & o_pBufSize )
{
    #define FUNC "[PRDF::readPnorData] "

    PNOR::SectionInfo_t info;
    errlHndl_t errl = PNOR::getSectionInfo( PNOR::FIRDATA, info );
    if ( NULL != errl )
    {
        PRDF_ERR( FUNC"getSectionInfo() failed" );
    }
    else
    {
        o_pBuf     = reinterpret_cast<uint8_t *>(info.vaddr);
        o_pBufSize = info.size;
    }

    return errl;

    #undef FUNC
}

//------------------------------------------------------------------------------

errlHndl_t readPnorFirData( bool & o_validData, PnorTrgtMap & o_trgtMap,
                            PnorFfdc & o_ffdc, PnorTrgtFfdcMap & o_trgtFfdc )
{
    #define FUNC "[PRDF::readPnorFirData] "

    errlHndl_t errl = NULL;

    o_validData = false;

    bool full = false;
    uint8_t * pBuf = NULL;
    size_t sz_pBuf = 0;

    do
    {
        // Read the PNOR data.
        errl = readPnorData( pBuf, sz_pBuf );
        if ( NULL != errl )
        {
            PRDF_ERR( FUNC"readPnorData() failed" );
            break;
        }

        FirData firData ( pBuf, sz_pBuf );

        // Get the PNOR header data.
        PNOR_Data_t * data = NULL;
        bool full = firData.getData( data );
        if ( full ) break;

        // Check the header for valid data.
        if ( PNOR_FIR1 != data->header )
        {
            break; // nothing to analyze
        }

        // Gather FFDC from header data.
        o_ffdc.trgts = data->trgts;
        o_ffdc.full  = (0 == data->full) ? false : true;

        // Iterate each target and get the register data.
        for ( uint32_t t = 0; t < data->trgts; t++ )
        {
            PNOR_Trgt_t * pTrgt = NULL;
            full = firData.getData( pTrgt );
            if ( full ) break;

            TargetHandle_t trgtHndl = getTargetHandle( pTrgt );
            if ( NULL == trgtHndl )
            {
                PRDF_ERR( FUNC"getTargetHandle() failed" );

                /*@
                 * @errortype
                 * @reasoncode PRDF_NULL_VALUE_RETURNED
                 * @severity   ERRL_SEV_UNRECOVERABLE
                 * @moduleid   PRDF_CS_FIRDATA_READ
                 * @userdata1  0
                 * @userdata2  0
                 * @devdesc    NULL system target.
                 */
                errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               PRDF_CS_FIRDATA_READ,
                                               PRDF_NULL_VALUE_RETURNED, 0, 0);
                break;
            }

            // Gather FFDC from target.
            if ( 0 != pTrgt->scomErrs )
            {
                o_trgtFfdc[trgtHndl].scomErrs = pTrgt->scomErrs;
            }

            // Iterate the regular registers.
            for ( uint32_t r = 0; r < pTrgt->regs; r++ )
            {
                PNOR_Reg_t * reg = NULL;
                full = firData.getData( reg );
                if ( full ) break;

                o_trgtMap[trgtHndl][(uint64_t)reg->addr] = reg->val;
            }
            if ( full ) break;

            // Iterate the indirect-SCOM registers.
            for ( uint32_t r = 0; r < pTrgt->idRegs; r++ )
            {
                PNOR_IdReg_t * reg = NULL;
                full = firData.getData( reg );
                if ( full ) break;

                o_trgtMap[trgtHndl][reg->addr] = (uint64_t)reg->val;
            }
            if ( full ) break;

        }
        if ( full ) break;

        o_validData = true;

    } while (0);

    if ( full )
    {
        PRDF_ERR( FUNC"Needed more data than availabe in PNOR (%d bytes)",
                  sz_pBuf );
        /*@
         * @errortype
         * @reasoncode PRDF_INVALID_CONFIG
         * @severity   ERRL_SEV_UNRECOVERABLE
         * @moduleid   PRDF_CS_FIRDATA_READ
         * @userdata1  Size needed
         * @userdata2  0
         * @devdesc    PNOR data is of inefficient size.
         */
        errl = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        PRDF_CS_FIRDATA_READ,
                                        PRDF_INVALID_CONFIG, sz_pBuf, 0);
    }

    return errl;

    #undef FUNC
}

//------------------------------------------------------------------------------

errlHndl_t clearPnorFirData()
{
    return PNOR::clearSection( PNOR::FIRDATA );
}

}; // end namespace PRDF

