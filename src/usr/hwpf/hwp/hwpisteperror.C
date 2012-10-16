/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/hwpisteperror.C $                            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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
#include <hwpisteperror.H>
#include <hwpistepud.H>

using namespace ISTEP;
using namespace ISTEP_ERROR;

// setup the internal elog pointer and capture error data for the first or
// add error data to top level elog
void IStepError::addErrorDetails(istepReasonCode reasoncode,
                                  istepModuleId modid,
                                  const errlHndl_t i_err )
{
    mutex_lock( &iv_mutex );

    // if internal elog is null, create a new one ad grab some data from the
    // first error that is passed in.
    if( iv_eHandle == NULL )
    {
        // add the PLID and reason code of the first error to user data word 0
        uint64_t data0 = i_err->plid();
        data0 <<= 32;
        data0 |= i_err->reasonCode();

        iv_eHandle = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                             modid, reasoncode, data0, 0);
    }

    // set the plid of the inpout elog to match the summary elog
    i_err->plid( iv_eHandle->plid() );

    // grab the isteps trace and add to the original elog
    i_err->collectTrace("ISTEPS_TRACE", 1024);

    // add some details from the elog to the IStep error object
    ISTEP_ERROR::HwpUserDetailsIstep errorDetails( i_err );

    errorDetails.addToLog( iv_eHandle );

    iv_errorCount++;

    // put iv_errorCount into bytes 0 and 1 of user data 2
    uint64_t data = ((uint64_t)iv_errorCount << 32);

    iv_eHandle->addUserData2(data);

    mutex_unlock( &iv_mutex );
}


