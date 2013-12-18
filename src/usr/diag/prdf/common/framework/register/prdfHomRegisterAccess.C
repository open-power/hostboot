/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/prdfHomRegisterAccess.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2002,2014              */
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
  @file prdfHomRegisterAccess.C
  @brief definition of HomRegisterAccess
*/
//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#define prdfHomRegisterAccess_C

#ifdef __HOSTBOOT_MODULE
  #include <ecmdDataBufferBase.H>
  #include <ibscomreasoncodes.H>
#else
  #include <ecmdDataBuffer.H>
  #include <hwsvExecutionService.H>
#endif

#include <prdfHomRegisterAccess.H>
#include <prdf_service_codes.H>
#include <iipbits.h>
#include <prdfMain.H>
#include <prdfPlatServices.H>
#include <prdfGlobal.H>
#include <prdfErrlUtil.H>
#include <prdfTrace.H>

#undef prdfHomRegisterAccess_C


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

//------------------------------------------------------------------------------
// Member Function Specifications
//------------------------------------------------------------------------------

ScomService& getScomService()
{
    return PRDF_GET_SINGLETON(theScomService);
}

ScomService::ScomService() :
    iv_ScomAccessor(NULL)
{
    PRDF_DTRAC("ScomService() initializing default iv_ScomAccessor");
    iv_ScomAccessor = new ScomAccessor();
}

ScomService::~ScomService()
{
    if(NULL != iv_ScomAccessor)
    {
        PRDF_DTRAC("~ScomService() deleting iv_ScomAccessor");
        delete iv_ScomAccessor;
        iv_ScomAccessor = NULL;
    }
}

void ScomService::setScomAccessor(ScomAccessor & i_ScomAccessor)
{
    PRDF_DTRAC("ScomService::setScomAccessor() setting new scom accessor");

    if(NULL != iv_ScomAccessor)
    {
        PRDF_TRAC("ScomService::setScomAccessor() deleting old iv_ScomAccessor");
        delete iv_ScomAccessor;
        iv_ScomAccessor = NULL;
    }

    iv_ScomAccessor = &i_ScomAccessor;
}

uint32_t ScomService::Access(TARGETING::TargetHandle_t i_target,
                                 BIT_STRING_CLASS & bs,
                                 uint64_t registerId,
                                 MopRegisterAccess::Operation operation) const
{
    PRDF_DENTER("ScomService::Access()");
    int32_t rc = SUCCESS;

    errlHndl_t errlH = iv_ScomAccessor->Access( i_target,
                                          bs,
                                          registerId,
                                          operation);
    #ifdef __HOSTBOOT_MODULE
    if( ( NULL != errlH ) && ( MopRegisterAccess::READ == operation )
        && ( IBSCOM::IBSCOM_BUS_FAILURE == errlH->reasonCode() ))
    {
        PRDF_COMMIT_ERRL(errlH, ERRL_ACTION_SA|ERRL_ACTION_REPORT);
        PRDF_INF( "Register access failed with reason code IBSCOM_BUS_FAILURE."
                  " Trying again, Target HUID:0x%08X Register 0x%016X Op:%u",
                  PlatServices::getHuid( i_target), registerId, operation );

        errlH = iv_ScomAccessor->Access( i_target,
                                         bs,
                                         registerId,
                                         operation);
    }
    #endif

    if(errlH)
    {
        rc = PRD_SCANCOM_FAILURE;
        PRDF_ADD_SW_ERR(errlH, rc, PRDF_HOM_SCOM, __LINE__);
        PRDF_ADD_PROCEDURE_CALLOUT(errlH, SRCI_PRIORITY_MED, EPUB_PRC_SP_CODE);

        bool l_isAbort = false;
        PRDF_ABORTING(l_isAbort);
        if (!l_isAbort)
        {
            PRDF_COMMIT_ERRL(errlH, ERRL_ACTION_SA|ERRL_ACTION_REPORT);
        }
        else
        {
            delete errlH;
            errlH = NULL;
        }
    }

    PRDF_DEXIT("ScomService::Access(): rc=%d", rc);

    return rc;
}


errlHndl_t ScomAccessor::Access(TARGETING::TargetHandle_t i_target,
                                  BIT_STRING_CLASS & bs,
                                  uint64_t registerId,
                                  MopRegisterAccess::Operation operation) const
{
    PRDF_DENTER("ScomAccessor::Access()");

    errlHndl_t errH = NULL;
    uint32_t bsize = bs.GetLength();

    if(i_target != NULL)
    {
        #ifdef __HOSTBOOT_MODULE

        ecmdDataBufferBase buffer(bsize);

        #else

        ecmdDataBuffer buffer(bsize);

        #endif

        switch (operation)
        {
            case MopRegisterAccess::WRITE:
                for(unsigned int i = 0; i < bsize; ++i)
                {
                    if(bs.IsSet(i)) buffer.setBit(i);
                }

                // FIXME: If register is in a EX chiplet, need to also update
                //        PORE image ????

                PRD_FAPI_TO_ERRL(errH,
                                 fapiPutScom,
                                 PlatServices::getFapiTarget(i_target),
                                 registerId,
                                 buffer);

                break;

            case MopRegisterAccess::READ:
                bs.Pattern(0x00000000); // clear all bits

                PRD_FAPI_TO_ERRL(errH,
                                 fapiGetScom,
                                 PlatServices::getFapiTarget(i_target),
                                 registerId,
                                 buffer);

                for(unsigned int i = 0; i < bsize; ++i)
                {
                    if(buffer.isBitSet(i)) bs.Set(i);
                }

                break;

            default:
                PRDF_ERR("ScomAccessor::Access() unsuppported scom op: 0x%08X", operation);
                break;

        } // end switch operation

    }
    else // Invalid target
    {
        /*@
         * @errortype
         * @subsys     EPUB_FIRMWARE_SP
         * @reasoncode PRDF_CODE_FAIL
         * @moduleid   PRDF_HOM_SCOM
         * @userdata1  PRD Return code =  SCR_ACCESS_FAILED
         * @userdata2  The invalid ID causing the fail
         * @devdesc    Access SCOM failed due to NULL target handle
         * @procedure  EPUB_PRC_SP_CODE
         */

        // create an error log
        PRDF_CREATE_ERRL(errH,
                         ERRL_SEV_PREDICTIVE,        // error on diagnostic
                         ERRL_ETYPE_NOT_APPLICABLE,
                         SRCI_MACH_CHECK,
                         SRCI_NO_ATTR,
                         PRDF_HOM_SCOM,              // module id
                         FSP_DEFAULT_REFCODE,        // refcode What do we use???
                         PRDF_CODE_FAIL,             // Reason code
                         SCR_ACCESS_FAILED,          // user data word 1
                         PlatServices::getHuid(i_target),   // user data word 2
                         0x0000,                     // user data word 3
                         0x0000                      // user data word 4
                         );
    }

    PRDF_DEXIT("ScomAccessor::Access()");

    return errH;
}

//------------------------------------------------------------------------------

uint32_t HomRegisterAccessScom::Access( BIT_STRING_CLASS & bs,
                                        uint64_t registerId,
                                        Operation operation) const
{
    PRDF_DENTER("HomRegisterAccessScom::Access()");

    uint32_t rc = getScomService().Access(iv_ptargetHandle,
                                           bs,
                                           registerId,
                                           operation);

    PRDF_DEXIT("HomRegisterAccessScom::Access() rc=%d", rc);

    return rc;
}

//------------------------------------------------------------------------------

HomRegisterAccessScan::HomRegisterAccessScan(
                                    TARGETING::TargetHandle_t i_ptargetHandle,
                                    ScanRingField * start, ScanRingField * end )
: MopRegisterAccess(), iv_punitHandle(i_ptargetHandle)
{
    iv_aliasIds.reserve(end-start);
    while(start != end)
    {
        iv_aliasIds.push_back(*start);
        ++start;
    }
}

//------------------------------------------------------------------------------

uint32_t HomRegisterAccessScan::Access(BIT_STRING_CLASS & bs,
                                   uint64_t registerId,
                                   Operation operation) const
{

    uint32_t rc = SUCCESS;
    errlHndl_t errH = NULL;
    HUID l_chipHUID = PlatServices::getHuid(iv_punitHandle);
    if(operation == MopRegisterAccess::READ)
    {
        if(iv_punitHandle != NULL)
        {
            #ifdef __HOSTBOOT_MODULE
            ecmdDataBufferBase buf(bs.GetLength());
            #else
            ecmdDataBuffer buf(bs.GetLength());
            #endif

            uint32_t curbit = 0;
            bs.Pattern(0x00000000); // clear desination bit string
            for(AliasIdList::const_iterator i = iv_aliasIds.begin(); i != iv_aliasIds.end(); ++i)
            {
                for(uint32_t j = 0; j != i->length; ++j)
                {
                    if(buf.isBitSet(j)) bs.Set(j+curbit);
                }
                curbit += i->length;
            }
        }
        else
        {

            /*@
             * @errortype
             * @subsys     EPUB_FIRMWARE_SP
             * @reasoncode PRDF_CODE_FAIL
             * @moduleid   PRDF_HOM_SCAN
             * @userdata1  PRD Return code =  SCR_ACCESS_FAILED
             * @userdata2  The invalid ID causing the fail
             * @userdata3  Code location = 0x0001
             * @devdesc Access Scan failed due to an invalid function unit
             * @procedure EPUB_PRC_SP_CODE
             */
            // create an error log
            PRDF_CREATE_ERRL(errH,
                             ERRL_SEV_PREDICTIVE,       // error on diagnostic
                             ERRL_ETYPE_NOT_APPLICABLE,
                             SRCI_MACH_CHECK,
                             SRCI_NO_ATTR,
                             PRDF_HOM_SCAN,             // module id
                             FSP_DEFAULT_REFCODE,       // refcode What do we use???
                             PRDF_CODE_FAIL,            // Reason code
                             SCR_ACCESS_FAILED,         // user data word 1
                             l_chipHUID,                // user data word 2
                             0x0001,                    // user data word 3
                             0x0000                     // user data word 4
                             );
        }
    }
    // PRD does not ever expect to write scan rings - create an error log
    else
    {
        PRDF_ERR( "HomRegisterAccessScan::Access "
                  "only scan read is supported.  Invalid Scan Op: 0x%.8X", operation );

        /*@
         * @errortype
         * @subsys     EPUB_FIRMWARE_SP
         * @reasoncode PRDF_UNSUPPORTED_SCAN_WRITE
         * @moduleid   PRDF_HOM_SCAN
         * @userdata1  PRD Return code =  SCR_ACCESS_FAILED
         * @userdata2  The ID for the scan
         * @userdata3  Code location = 0x0002
         * @devdesc Access Scan failed. PRD does not ever expect to write scan rings.
         * @procedure EPUB_PRC_SP_CODE
         */
        // create an error log
        PRDF_CREATE_ERRL(errH,
                         ERRL_SEV_PREDICTIVE,       // error on diagnostic
                         ERRL_ETYPE_NOT_APPLICABLE,
                         SRCI_MACH_CHECK,
                         SRCI_NO_ATTR,
                         PRDF_HOM_SCAN,             // module id
                         FSP_DEFAULT_REFCODE,       // refcode What do we use???
                         PRDF_UNSUPPORTED_SCAN_WRITE, // Reason code
                         SCR_ACCESS_FAILED,         // user data word 1
                         l_chipHUID,                // user data word 2
                         0x0002,                    // user data word 3
                         0x0000                     // user data word 4
                         );
    }
    if(errH)
    {
        rc = PRD_SCANCOM_FAILURE;
        PRDF_ADD_SW_ERR(errH, rc, PRDF_HOM_SCAN, __LINE__);
        PRDF_ADD_PROCEDURE_CALLOUT(errH, SRCI_PRIORITY_MED, EPUB_PRC_SP_CODE);

        bool l_isAbort = false;
        PRDF_ABORTING(l_isAbort);
        if (!l_isAbort)
        {
            PRDF_COMMIT_ERRL(errH, ERRL_ACTION_SA|ERRL_ACTION_REPORT);

        }
        else
        {
            delete errH;
            errH = NULL;
        }
    }

    return rc;
}

} // End namespace PRDF
