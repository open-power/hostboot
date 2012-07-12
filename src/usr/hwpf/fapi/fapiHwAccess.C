/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/fapi/fapiHwAccess.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2011-2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
/**
 *  @file fapiHwAccess.C
 *
 *  @brief Implements the fapiHwAccess.H functions at a high level,
 *  allowing for scand common tracing to occur before and after
 *  the call to the platform-specific worker. 
 *
 *  Note that platform code must provide the implementation.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          copelanm    09/13/2011  new for common scan traces
 *                          mjjones     09/14/2011  Prepended fapi to functions
 *                                                  and enabled all functions
 *                          mjjones     10/13/2011  util namespace change
 *                          mjjones     02/21/2012  Use high performance Target
 *                                                  toEcmdString
 *          836579          thi         May 18,2012 Spy/ring supports
 *                          mjjones     07/12/2012  Add Pulse mode option to Ring funcs
 */

#include <fapi.H>
#include <fapiPlatHwAccess.H>

extern "C"
{

//******************************************************************************
// fapiGetScom function
//******************************************************************************
fapi::ReturnCode fapiGetScom(const fapi::Target& i_target,
                             const uint64_t i_address,
                             ecmdDataBufferBase & o_data)
{
    fapi::ReturnCode l_rc;
    bool l_traceit = platIsScanTraceEnabled();

    // call the platform implementation
    l_rc = platGetScom( i_target, i_address, o_data );

    if (l_rc)
    {
        FAPI_ERR("fapiGetScom failed - Target %s, Addr %.16llX", i_target.toEcmdString(), i_address);
    }

    if( l_traceit )
    {
        FAPI_SCAN( "TRACE : GETSCOM     : %s : %.16llX %.16llX", 
                   i_target.toEcmdString(),
                   i_address,
                   o_data.getDoubleWord( 0 ) );
    }

    return l_rc;
}


//******************************************************************************
// fapiPutScom function
//******************************************************************************
fapi::ReturnCode fapiPutScom(const fapi::Target& i_target,
                             const uint64_t i_address,
                             ecmdDataBufferBase & i_data)
{
    fapi::ReturnCode l_rc;
    bool l_traceit = platIsScanTraceEnabled();

    // call the platform implementation
    l_rc = platPutScom( i_target, i_address, i_data );

    if (l_rc)
    {
        FAPI_ERR("fapiPutScom failed - Target %s, Addr %.16llX", i_target.toEcmdString(), i_address);
    }

    if( l_traceit )
    {
        FAPI_SCAN( "TRACE : PUTSCOM     : %s : %.16llX %.16llX",
                   i_target.toEcmdString(),
                   i_address,
                   i_data.getDoubleWord( 0 )  );
    }

    return l_rc;
}

//******************************************************************************
// fapiPutScomUnderMask function
//******************************************************************************
fapi::ReturnCode fapiPutScomUnderMask(const fapi::Target& i_target,
                                      const uint64_t i_address,
                                      ecmdDataBufferBase & i_data,
                                      ecmdDataBufferBase & i_mask)
{
    fapi::ReturnCode l_rc;
    bool l_traceit = platIsScanTraceEnabled();

    // call the platform implementation
    l_rc = platPutScomUnderMask( i_target, i_address, i_data, i_mask );

    if (l_rc)
    {
        FAPI_ERR("fapiPutScomUnderMask failed - Target %s, Addr %.16llX", i_target.toEcmdString(), i_address);
    }

    if( l_traceit )
    {
        FAPI_SCAN( "TRACE : PUTSCOMMASK : %s : %.16llX %.16llX %.16llX",
               i_target.toEcmdString(),
               i_address,
               i_data.getDoubleWord(0),
               i_mask.getDoubleWord(0));
    }

    return l_rc;
}

//******************************************************************************
// fapiGetCfamRegister function
//******************************************************************************
fapi::ReturnCode fapiGetCfamRegister(const fapi::Target& i_target,
                                     const uint32_t i_address,
                                     ecmdDataBufferBase & o_data)
{
    fapi::ReturnCode l_rc;
    bool l_traceit = platIsScanTraceEnabled();

    // call the platform implementation
    l_rc = platGetCfamRegister( i_target, i_address, o_data );

    if (l_rc)
    {
        FAPI_ERR("fapiGetCfamRegister failed - Target %s, Addr %.8X", i_target.toEcmdString(), i_address);
    }

    if( l_traceit )
    {
        FAPI_SCAN( "TRACE : GETCFAMREG  : %s : %.8X %.8X",
               i_target.toEcmdString(),
               i_address,
               o_data.getWord(0) );
    }

    return l_rc;
}

//******************************************************************************
// fapiPutCfamRegister function
//******************************************************************************
fapi::ReturnCode fapiPutCfamRegister(const fapi::Target& i_target,
                                     const uint32_t i_address,
                                     ecmdDataBufferBase & i_data)
{
    fapi::ReturnCode l_rc;
    bool l_traceit = platIsScanTraceEnabled();

    // call the platform implementation
    l_rc = platPutCfamRegister( i_target, i_address, i_data );

    if (l_rc)
    {
        FAPI_ERR("platPutCfamRegister failed - Target %s, Addr %.8X", i_target.toEcmdString(), i_address);
    }

    if( l_traceit )
    {
        FAPI_SCAN( "TRACE : PUTCFAMREG  : %s : %.8X %.8X",
               i_target.toEcmdString(),
               i_address,
               i_data.getWord(0) );
    }

    return l_rc;
}

//******************************************************************************
// fapiModifyCfamRegister function
//******************************************************************************
fapi::ReturnCode fapiModifyCfamRegister(const fapi::Target& i_target,
                                        const uint32_t i_address,
                                        ecmdDataBufferBase & i_data,
                                        const fapi::ChipOpModifyMode i_modifyMode)
{
    fapi::ReturnCode l_rc;
    bool l_traceit = platIsScanTraceEnabled();

    // call the platform implementation
    l_rc = platModifyCfamRegister( i_target, i_address, i_data, i_modifyMode );

    if (l_rc)
    {
        FAPI_ERR("platModifyCfamRegister failed - Target %s, Addr %.8X", i_target.toEcmdString(), i_address);
    }

    if( l_traceit )
    {
        // get string representation of the modify mode
        const char * l_pMode = NULL;

        if (i_modifyMode == fapi::CHIP_OP_MODIFY_MODE_OR)
        {
            l_pMode = "OR";
        }
        else if (i_modifyMode == fapi::CHIP_OP_MODIFY_MODE_AND)
        {
            l_pMode = "AND";
        }
        else if (i_modifyMode == fapi::CHIP_OP_MODIFY_MODE_XOR)
        {
            l_pMode = "XOR";
        }
        else
        {
            l_pMode = "?";
        }

        FAPI_SCAN( "TRACE : MODCFAMREG  : %s : %.8X %.8X %s",
               i_target.toEcmdString(),
               i_address,
               i_data.getWord(0),
               l_pMode );
    }

    return l_rc;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
fapi::ReturnCode fapiGetRing(const fapi::Target& i_target,
                             const uint32_t i_address,
                             ecmdDataBufferBase & o_data,
                             const uint32_t i_ringMode)
{
    fapi::ReturnCode l_rc;
    bool l_traceit = platIsScanTraceEnabled();

    // call the platform implementation
    l_rc = platGetRing( i_target, i_address, o_data, i_ringMode );

    if (l_rc)
    {
        FAPI_ERR("fapiGetRing failed - Target %s, Addr 0x%.8X", i_target.toEcmdString(), i_address);
    }

    if( l_traceit )
    {
        FAPI_SCAN( "TRACE : GETRING     : %s : %.8X %.16llX", 
                   i_target.toEcmdString(),
                   i_address,
                   o_data.getDoubleWord( 0 ) );
    }

    return l_rc;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
fapi::ReturnCode fapiPutRing(const fapi::Target& i_target,
                             const uint32_t i_address,
                             ecmdDataBufferBase & i_data,
                             const uint32_t i_ringMode)
{
    fapi::ReturnCode l_rc;
    bool l_traceit = platIsScanTraceEnabled();

    // call the platform implementation
    l_rc = platPutRing( i_target, i_address, i_data, i_ringMode );

    if (l_rc)
    {
        FAPI_ERR("fapiPutRing failed - Target %s, Addr 0x%.8X", i_target.toEcmdString(), i_address);
    }

    if( l_traceit )
    {
        FAPI_SCAN( "TRACE : PUTRING     : %s : %.8X %.16llX",
                   i_target.toEcmdString(),
                   i_address,
                   i_data.getDoubleWord(0));
    }

    return l_rc;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
fapi::ReturnCode fapiModifyRing(const fapi::Target& i_target,
                                const uint32_t i_address,
                                ecmdDataBufferBase & i_data,
                                const fapi::ChipOpModifyMode i_modifyMode,
                                const uint32_t i_ringMode)
{
    fapi::ReturnCode l_rc;
    bool l_traceit = platIsScanTraceEnabled();

    // call the platform implementation
    l_rc = platModifyRing( i_target, i_address, i_data, i_modifyMode, i_ringMode );

    if (l_rc)
    {
        FAPI_ERR("platModifyRing failed - Target %s, Addr 0x%.8X, ModifyMode 0x%.8X",
                  i_target.toEcmdString(), i_address, i_modifyMode);
    }

    if( l_traceit )
    {
        // get string representation of the modify mode
        const char * l_pMode = NULL;

        if (i_modifyMode == fapi::CHIP_OP_MODIFY_MODE_OR)
        {
            l_pMode = "OR";
        }
        else if (i_modifyMode == fapi::CHIP_OP_MODIFY_MODE_AND)
        {
            l_pMode = "AND";
        }
        else if (i_modifyMode == fapi::CHIP_OP_MODIFY_MODE_XOR)
        {
            l_pMode = "XOR";
        }
        else
        {
            l_pMode = "?";
        }

        FAPI_SCAN( "TRACE : MODRING     : %s : %.8X %.16llX %s",
               i_target.toEcmdString(),
               i_address,
               i_data.getDoubleWord(0),
               l_pMode);
    }

    return l_rc;
}

// --------------------------------------------------------------------------
// NOTE:
// These spy access interfaces are only used in FSP.
// HB does not allow spy access

#ifndef _NO_SPY_ACCESS
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
fapi::ReturnCode fapiGetSpy(const fapi::Target& i_target,
                            const uint32_t i_spyId,
                            ecmdDataBufferBase & o_data)
{
    fapi::ReturnCode l_rc;
    bool l_traceit = platIsScanTraceEnabled();

    // call the platform implementation
    l_rc = platGetSpy( i_target, i_spyId, o_data );

    if (l_rc)
    {
        FAPI_ERR("fapiGetSpy failed - Target %s, SpyId 0x%.8X", i_target.toEcmdString(), i_spyId);
    }

    if( l_traceit )
    {
        FAPI_SCAN( "TRACE : GETSPY      : %s : %.8X %.16llX", 
                   i_target.toEcmdString(),
                   i_spyId,
                   o_data.getDoubleWord(0));
    }

    return l_rc;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
fapi::ReturnCode fapiPutSpy(const fapi::Target& i_target,
                            const uint32_t i_spyId,
                            ecmdDataBufferBase & i_data)
{
    fapi::ReturnCode l_rc;
    bool l_traceit = platIsScanTraceEnabled();

    // call the platform implementation
    l_rc = platPutSpy( i_target, i_spyId, i_data );

    if (l_rc)
    {
        FAPI_ERR("fapiPutSpy failed - Target %s, SpyId 0x%.8X", i_target.toEcmdString(), i_spyId);
    }

    if( l_traceit )
    {
        FAPI_SCAN( "TRACE : PUTSPY      : %s : %.8X %.16llX",
                   i_target.toEcmdString(),
                   i_spyId,
                   i_data.getDoubleWord(0));
    }

    return l_rc;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
fapi::ReturnCode fapiGetSpyEnum(const fapi::Target& i_target,
                                const uint32_t i_spyId,
                                uint32_t& o_enumVal)
{
    fapi::ReturnCode l_rc;
    bool l_traceit = platIsScanTraceEnabled();

    // call the platform implementation
    l_rc = platGetSpyEnum( i_target, i_spyId, o_enumVal );

    if (l_rc)
    {
        FAPI_ERR("fapiGetSpyEnum failed - Target %s, SpyId 0x%.8X", i_target.toEcmdString(), i_spyId);
    }

    if( l_traceit )
    {
        FAPI_SCAN( "TRACE : GETSPYENUM  : %s : %.8X %.8X", 
                   i_target.toEcmdString(),
                   i_spyId,
                   o_enumVal);
    }

    return l_rc;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
fapi::ReturnCode fapiPutSpyEnum(const fapi::Target& i_target,
                                const uint32_t i_spyId,
                                const uint32_t i_enumVal)
{
    fapi::ReturnCode l_rc;
    bool l_traceit = platIsScanTraceEnabled();

    // call the platform implementation
    l_rc = platPutSpyEnum( i_target, i_spyId, i_enumVal );

    if (l_rc)
    {
        FAPI_ERR("fapiPutSpyEnum failed - Target %s, SpyId 0x%.8X, EnumVal %d",
                 i_target.toEcmdString(), i_spyId, i_enumVal);
    }

    if( l_traceit )
    {
        FAPI_SCAN( "TRACE : PUTSPYENUM  : %s : %.8X %.8X",
                   i_target.toEcmdString(),
                   i_spyId,
                   i_enumVal);
    }

    return l_rc;
}

#endif

} // extern "C"
