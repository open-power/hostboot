/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/service/prdfServiceDataCollector.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2004,2013              */
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

/**
    @file prdfServiceDataCollector.C
    @brief ServiceDataCollector definition
*/
//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <string.h>                // for memcpy
#define prdfServiceDataCollector_C
#include <iipServiceDataCollector.h>
#include <prdfPlatServices.H>
#include <prdfTrace.H>
#undef prdfServiceDataCollector_C

using namespace TARGETING;

//------------------------------------------------------------------------------
//  User Types, Constants, macros, prototypes, globals
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Member Function Specifications
//------------------------------------------------------------------------------

namespace PRDF
{

   std::list<ExtensibleChip*> ServiceDataCollector::cv_ruleChipStack;

#ifndef __HOSTBOOT_MODULE

inline void buffer_append(uint8_t *&ptr, uint32_t value)
{
    uint32_t l_tmp32 = htonl(value);
    memcpy(ptr, &l_tmp32, sizeof(uint32_t));
    ptr += sizeof(uint32_t);
}

inline void buffer_append(uint8_t *&ptr, uint16_t value)
{
    uint16_t l_tmp16 = htons(value);
    memcpy(ptr, &l_tmp16, sizeof(uint16_t));
    ptr += sizeof(uint16_t);
}

inline void buffer_append(uint8_t *&ptr, uint8_t value)
{
    memcpy(ptr, &value, sizeof(value));
    ptr += sizeof(uint8_t);
}

inline uint32_t buffer_get32(const uint8_t * &ptr)
{
    uint32_t l_tmp32 = 0;
    memcpy(&l_tmp32, ptr, sizeof(uint32_t));
    ptr += sizeof(uint32_t);
    return ntohl(l_tmp32);
}

inline uint16_t buffer_get16(const uint8_t * &ptr)
{
    uint16_t l_tmp16 = 0;
    memcpy(&l_tmp16, ptr, sizeof(uint16_t));
    ptr += sizeof(uint16_t);
    return ntohs(l_tmp16);
}

inline uint8_t buffer_get8(const uint8_t * &ptr)
{
    uint8_t l_tmp8 = 0;
    memcpy(&l_tmp8, ptr, sizeof(uint8_t));
    ptr += sizeof(uint8_t);
    return l_tmp8;
}

inline void buffer_append( uint8_t *&ptr, const TARGETING::TargetHandle_t i_pGivenHandle )
{
    HUID l_targetHuid = PlatServices::getHuid( i_pGivenHandle );
    l_targetHuid = htonl( l_targetHuid );
    uint32_t l_size = sizeof( l_targetHuid );
    memcpy( ptr, &l_targetHuid, l_size );
    ptr += l_size;
}

inline TARGETING::TargetHandle_t buffer_getTarget( const uint8_t *&ptr )
{
    HUID l_chipHuid = INVALID_HUID;
    uint32_t l_size = sizeof( l_chipHuid );
    memcpy( &l_chipHuid, ptr, l_size );
    l_chipHuid = ntohl( l_chipHuid );
    TARGETING::TargetHandle_t l_tempChipHandle = PlatServices::getTarget( l_chipHuid );
    ptr += l_size;

    return l_tempChipHandle;
}

#endif // ifndef __HOSTBOOT_MODULE

//------------------------------------------------------------------------------

void ServiceDataCollector::SetCallout( PRDcallout mru,
                                       PRDpriority priority )
{
    bool found = false;

    if ( PRDcalloutData::TYPE_TARGET == mru.getType() )
    {
        // Ensuring target is not NULL
        if ( NULL == mru.getTarget() )
        {
            PRDF_ERR( "[ServiceDataCollector::SetCallout] "
                      "skipping NULL callout" );
            return;
        }
    }

    for ( SDC_MRU_LIST::iterator i = xMruList.begin();
          i != xMruList.end() && found == false; ++i )
    {
        if ( i->callout == mru )
        {
            found = true;
            if ( priority < i->priority )
            {
                i->priority = priority;
            }
        }
    }

    if ( found == false )
    {
        xMruList.push_back( SdcCallout(mru, priority) );
    }
}

//------------------------------------------------------------------------------

void ServiceDataCollector::AddSignatureList( TargetHandle_t i_target,
                                             uint32_t i_signature )
{
    #define PRDF_FUNC "[ServiceDataCollector::AddSignatureList] "

    do
    {
        if ( NULL == i_target )
        {
            PRDF_ERR( PRDF_FUNC"Given target is NULL" );
            break;
        }

        bool found = false;
        for ( PRDF_SIGNATURES::iterator i = iv_SignatureList.begin();
              i != iv_SignatureList.end(); i++ )
        {
            if ( (i->target == i_target) && (i->signature == i_signature) )
            {
                found = true;
                break;
            }
        }

        if ( !found )
        {
            iv_SignatureList.push_back( SignatureList(i_target, i_signature) );
        }

    } while (0);

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

TARGETING::TargetHandle_t ServiceDataCollector::getTargetAnalyzed( )
{
    ExtensibleChip * l_pChipAnalyzed = getChipAnalyzed();
    TARGETING::TargetHandle_t l_pTargetAnalyzed = NULL;
    if( NULL != l_pChipAnalyzed )
    {
         l_pTargetAnalyzed = l_pChipAnalyzed->GetChipHandle( );
    }
    return  l_pTargetAnalyzed ;
}
//------------------------------------------------------------------------------

#ifndef __HOSTBOOT_MODULE

uint32_t ServiceDataCollector::Flatten(uint8_t * i_buffer, uint32_t & io_size) const
{
    uint32_t max_size = io_size;
    uint32_t rc = SUCCESS;
    //getting the actual size of prdfHcdbChangeItem and SignatureList that gets saved in memory. since
    //instead of handle we save the entity path
    uint32_t l_sizeHcdbChange = iv_HcdbChangeList.size() * sizeof(HcdbChangeItem);
    uint32_t l_sizeSignList   = iv_SignatureList.size()  * sizeof(SignatureList);
    uint32_t l_sizeMruList    = xMruList.size()          * sizeof(SdcCallout);
    // approximate space needed for essentials.  This estimate is slightly higher than actual
    const uint32_t MIN_FLAT_SIZE = sizeof(ServiceDataCollector) + sizeof(struct Timer::prdftm_t)
                                   + l_sizeMruList + l_sizeHcdbChange + l_sizeSignList;

    uint8_t * current_ptr = i_buffer;

    if(max_size > MIN_FLAT_SIZE)
    {
        // must have this
        uint32_t l_huid = error_signature.getChipId();
        buffer_append(current_ptr,l_huid);
        buffer_append(current_ptr,error_signature.getSigId());
        // callouts
        buffer_append(current_ptr,xMruList.size());
        for ( SDC_MRU_LIST::const_iterator i = xMruList.begin();
              i != xMruList.end(); ++i )
        {
            buffer_append( current_ptr, (uint32_t)i->callout.getType() );
            buffer_append( current_ptr, i->callout.flatten()           );
            buffer_append( current_ptr, (uint32_t)i->priority          );
        }
        buffer_append(current_ptr, iv_HcdbChangeList.size());
        for(HCDB_CHANGE_LIST::const_iterator i = iv_HcdbChangeList.begin();
            i != iv_HcdbChangeList.end(); ++i)
        {
            buffer_append( current_ptr, i->target );
            buffer_append( current_ptr, (uint32_t)i->compSubType );
            buffer_append( current_ptr, (uint32_t)i->compType );
        }
        buffer_append(current_ptr, iv_SignatureList.size());
        for(PRDF_SIGNATURES::const_iterator i = iv_SignatureList.begin();
            i != iv_SignatureList.end(); ++i)
        {
            buffer_append( current_ptr, i->target );
            buffer_append( current_ptr, i->signature );
        }
        buffer_append(current_ptr,maskId);
        buffer_append(current_ptr,(uint32_t)attentionType);
        buffer_append(current_ptr,flags);
        buffer_append(current_ptr,hitCount);
        buffer_append(current_ptr,threshold);
        buffer_append(current_ptr,startingPoint);
        buffer_append(current_ptr,(uint32_t)errorType);
        //@ecdf - Removed ivDumpRequestType.
        buffer_append(current_ptr,ivDumpRequestContent);
        buffer_append(current_ptr,ivpDumpRequestChipHandle);
        Timer::prdftm_t l_tm = ivCurrentEventTime.gettm();
        const uint32_t PRDFTM_SIZE = sizeof(struct Timer::prdftm_t);
        memcpy(current_ptr,&l_tm,PRDFTM_SIZE);
        current_ptr += PRDFTM_SIZE;
        buffer_append(current_ptr,(uint32_t)causeAttentionType);
        buffer_append(current_ptr,ivpThermalChipHandle);

        // Add as much capture data as we have room.
        uint8_t * cap_size_ptr = current_ptr;  // Place for Capture data size
        current_ptr += sizeof(uint32_t);

        uint32_t cap_size = captureData.Copy(current_ptr,max_size - (current_ptr - i_buffer));
        current_ptr += cap_size;
        buffer_append(cap_size_ptr,cap_size);

    }
    else // buffer is not big enough to capture the essentials
    {
        rc = 2;
    }

    io_size = current_ptr - i_buffer;

    return rc;
}

//------------------------------------------------------------------------------

ServiceDataCollector & ServiceDataCollector::operator=(
                                                    const uint8_t * i_flatdata )
{
    using namespace PRDcalloutData;

    error_signature.setChipId( buffer_get32(i_flatdata) );
    error_signature.setSigId(  buffer_get32(i_flatdata) );

    ClearCallouts();
    uint32_t value = buffer_get32(i_flatdata); // number of callouts
    for ( uint32_t i = 0; i < value; ++i )
    {
        MruType mt           = (MruType) buffer_get32(i_flatdata);
        uint32_t mru         = buffer_get32(i_flatdata);
        PRDpriority priority = (PRDpriority) buffer_get32(i_flatdata);

        PRDcallout callout( mru, mt );
        xMruList.push_back( SdcCallout(callout, priority) );
    }

    ClearHcdbList();
    value = buffer_get32(i_flatdata);  // number of HcdbEntries.
    for(uint32_t i = 0; i < value; ++i)
    {
        TARGETING::TargetHandle_t l_pChipHandle = buffer_getTarget(i_flatdata);
        hcdb::comp_subtype_t l_compSubType = (hcdb::comp_subtype_t)buffer_get32(i_flatdata);
        comp_id_t            l_compType =    (comp_id_t)buffer_get32(i_flatdata);
        if(NULL !=l_pChipHandle)
        {
            HcdbChangeItem l_item(l_pChipHandle, l_compSubType, l_compType);
            iv_HcdbChangeList.push_back(l_item);

        }
    }
    ClearSignatureList();
    value = buffer_get32(i_flatdata);  // number of HcdbEntries.
    for(uint32_t i = 0; i < value; ++i)
    {
        TARGETING::TargetHandle_t l_pChipHandle = buffer_getTarget(i_flatdata);
        uint32_t             l_signature   = (uint32_t)  buffer_get32(i_flatdata);
        if(NULL !=l_pChipHandle)
        {
            SignatureList    l_item(l_pChipHandle, l_signature);
            iv_SignatureList.push_back(l_item);
        }
    }

    maskId = buffer_get32(i_flatdata);
    attentionType = (ATTENTION_TYPE)buffer_get32(i_flatdata);
    flags = buffer_get32(i_flatdata);  //mp02 c from buffer_get16
    hitCount = buffer_get8(i_flatdata);
    threshold = buffer_get8(i_flatdata);
    startingPoint = buffer_getTarget(i_flatdata);
    errorType = (GardResolution::ErrorType)buffer_get32(i_flatdata);
    ivDumpRequestContent = (hwTableContent) buffer_get32(i_flatdata); //@ecdf
    ivpDumpRequestChipHandle = buffer_getTarget(i_flatdata);

    Timer::prdftm_t l_tm;
    const uint32_t PRDFTM_SIZE = sizeof(struct Timer::prdftm_t);
    memcpy(&l_tm,i_flatdata,PRDFTM_SIZE);
    i_flatdata += PRDFTM_SIZE;
    ivCurrentEventTime.settm(l_tm);

    causeAttentionType = (ATTENTION_TYPE) buffer_get32(i_flatdata);
    ivpThermalChipHandle = buffer_getTarget(i_flatdata);

    // Capture data - oh joy
    // do we re-expand the data or change capture date to hang onto the already flattened data?
    // lets give it back to the capture data object and let it decide.

    captureData = i_flatdata;

    return *this;
}

//------------------------------------------------------------------------------

void ServiceDataCollector::AddChangeForHcdb( TargetHandle_t i_target,
                                             hcdb::comp_subtype_t i_testType,
                                             comp_id_t i_compType )
{
    #define PRDF_FUNC "[ServiceDataCollector::AddChangeForHcdb] "

    do
    {
        if ( NULL == i_target )
        {
            PRDF_ERR( PRDF_FUNC"Given target is NULL" );
            break;
        }

        bool found = false;
        for ( HCDB_CHANGE_LIST::iterator i = iv_HcdbChangeList.begin();
              i != iv_HcdbChangeList.end(); i++ )
        {
            if ( (i->target      == i_target  ) &&
                 (i->compSubType == i_testType) &&
                 (i->compType    == i_compType) )
            {
                found = true;
                break;
            }
        }

        if ( !found )
        {
            iv_HcdbChangeList.push_back( HcdbChangeItem(i_target, i_testType,
                                                        i_compType) );
        }

    } while (0);

    #undef PRDF_FUNC
}

#endif // #ifndef __HOSTBOOT_MODULE

} // end namespace PRDF


