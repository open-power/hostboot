//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/fapi/fapiHwAccess.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
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
    char l_string[fapi::MAX_ECMD_STRING_LEN] = {0};
    bool l_traceit = fapi::platIsScanTraceEnabled(); 


    if( l_traceit )
    {
        // get the string representation of the target  
        i_target.toString(l_string);


        FAPI_SCAN( "TRACE : GETSCOM     : START : %s : %.16llX", 
                   l_string,
                   i_address ); 
    }

    // call the platform implementation
    l_rc = platGetScom( i_target, i_address, o_data );


    if( l_traceit )
    {
        FAPI_SCAN( "TRACE : GETSCOM     : END   : %s : %.16llX %.16llX", 
                   l_string,
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
    char l_string[fapi::MAX_ECMD_STRING_LEN] = {0};
    bool l_traceit = fapi::platIsScanTraceEnabled(); 

    if( l_traceit )
    {
        // get the string representation of the target  
        i_target.toString(l_string);

        FAPI_SCAN( "TRACE : PUTSCOM     : START : %s : %.16llX %.16llX", 
                   l_string,
                   i_address,
                   i_data.getDoubleWord( 0 )  ); 
    }

    // call the platform implemenation  
    l_rc = platPutScom( i_target, i_address, i_data );


    if( l_traceit )
    {
        FAPI_SCAN( "TRACE : PUTSCOM     : END   : %s : %.16llX", 
                   l_string,
                   i_address );
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
    char l_string[fapi::MAX_ECMD_STRING_LEN] = {0};
    bool l_traceit = fapi::platIsScanTraceEnabled(); 

    if( l_traceit )
    {
        // get the string representation of the target
        i_target.toString(l_string);

        FAPI_SCAN( "TRACE : PUTSCOMMASK : START : %s : %.16llX %.16llX %.16llX", 
               l_string,
               i_address,
               i_data.getDoubleWord(0),
               i_mask.getDoubleWord(0));
    }

    // call the platform implementation
    l_rc = platPutScomUnderMask( i_target, i_address, i_data, i_mask );

    if( l_traceit )
    {
        FAPI_SCAN( "TRACE : PUTSCOMMASK : END   : %s : %.16llX", 
               l_string,
               i_address );
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
    char l_string[fapi::MAX_ECMD_STRING_LEN] = {0};
    bool l_traceit = fapi::platIsScanTraceEnabled();

    if( l_traceit )
    {
        // get the string representation of the target
        i_target.toString(l_string);

        FAPI_SCAN( "TRACE : GETCFAMREG  : START : %s : %.16llX", 
               l_string,
               i_address ); 
    }

    // call the platform implementation
    l_rc = platGetCfamRegister( i_target, i_address, o_data );

    if( l_traceit )
    {
        FAPI_SCAN( "TRACE : GETCFAMREG  : END   : %s : %.16llX %.16llX", 
               l_string,
               i_address,
               o_data.getDoubleWord(0) ); 
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
    char l_string[fapi::MAX_ECMD_STRING_LEN] = {0};
    bool l_traceit = fapi::platIsScanTraceEnabled(); 

    if( l_traceit )
    {
        // get the string representation of the target  
        i_target.toString(l_string);

        FAPI_SCAN( "TRACE : PUTCFAMREG  : START : %s : %.16llX %.16llX", 
               l_string,
               i_address,
               i_data.getDoubleWord(0) );
    } 

    // call the platform implementation
    l_rc = platPutCfamRegister( i_target, i_address, i_data );


    if( l_traceit )
    {
        FAPI_SCAN( "TRACE : PUTCFAMREG  : END   : %s : %.16llX", 
               l_string,
               i_address ); 
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
    char l_string[fapi::MAX_ECMD_STRING_LEN] = {0};
    bool l_traceit = fapi::platIsScanTraceEnabled(); 
    const char * l_pMode = NULL;

    if( l_traceit )
    {
        // get the string representation of the target  
        i_target.toString(l_string);

        // get string representation of the modify mode
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

        FAPI_SCAN( "TRACE : MODCFAMREG  : START : %s : %.16llX %.16llX %s", 
               l_string,
               i_address,
               i_data.getDoubleWord(0),
               l_pMode ); 
    }

    // call the platform implementation
    l_rc = platModifyCfamRegister( i_target, i_address, i_data, i_modifyMode );

    if( l_traceit )
    {
        FAPI_SCAN( "TRACE : MODCFAMREG  : END   : %s : %llX %s", 
               l_string,
               i_address,
               l_pMode ); 
    }

    return l_rc;
}

} // extern "C"
