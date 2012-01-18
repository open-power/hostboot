//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/errl/errlUserDetailsTarget.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
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
/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include    <hbotcompid.H>             // list of compid's supported
#include    <errl/errlentry.H>
#include    <errl/errlUserDetailsTarget.H>
#include    <targeting/targetservice.H>

namespace ERRORLOG
{

//#ifndef PARSER

// Constructor
ErrlUserDetailsTarget::ErrlUserDetailsTarget( TARGETING::Target * i_target ) :
    ErrlUserDetails()
{
    iv_pTarget = i_target;
}

// Destructor
ErrlUserDetailsTarget::~ErrlUserDetailsTarget() {}

// @brief Add FFDC to an user detailed data section of the errorlog
//        Each data is always terminated with nul-char
void ErrlUserDetailsTarget::addToLog( errlHndl_t i_errl,
                                      void *i_buf, const uint32_t i_len )
{
    if (i_errl != NULL)
    {
        if (iv_pTarget == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
        {
            const char *l_bufPtr = "MASTER_PROCESSOR_CHIP_TARGET_SENTINEL";
            iv_pErrlFFDC = i_errl->addFFDC( ERRL_COMP_ID,
                                            l_bufPtr, strlen(l_bufPtr)+1,
                                            ERRL_UDV_DEFAULT_VER_1,
                                            ERRL_UDT_TARGET_FFDC );
        }
        else
        {
            uint32_t l_bufSize = 0;
            char * l_bufPtr = NULL;

            l_bufPtr = iv_pTarget->targetFFDC( l_bufSize );
            if (l_bufPtr)
            {
                iv_pErrlFFDC = i_errl->addFFDC( ERRL_COMP_ID,
                                                l_bufPtr, l_bufSize,
                                                ERRL_UDV_DEFAULT_VER_1,
                                                ERRL_UDT_TARGET_FFDC );
                free (l_bufPtr);
            }
        }
    }
}

}
