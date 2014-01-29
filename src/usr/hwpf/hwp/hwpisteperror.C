/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/hwpisteperror.C $                            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
#include <istepdispatcher.H>

using namespace ISTEP;
using namespace ISTEP_ERROR;

// setup the internal elog pointer and capture error data for the first or
// add error data to top level elog
void IStepError::addErrorDetails( const errlHndl_t i_err )
{
    mutex_lock( &iv_mutex );

    iv_errorCount++;

    // if internal elog is null, create a new one and grab some data from the
    // first error that is passed in.
    if( iv_eHandle == NULL )
    {
        uint8_t l_iStep = 0;
        uint8_t l_subStep = 0;

        // Set the eid and reason code of the first error to user data word 1
        uint64_t data1=TWO_UINT32_TO_UINT64(i_err->eid(),i_err->reasonCode());

        // Set the error count and iStep/subStep to user data word 2
        INITSERVICE::IStepDispatcher::
                       getTheInstance().getIstepInfo(l_iStep,l_subStep);
        uint64_t data2 = TWO_UINT32_TO_UINT64(iv_errorCount,  //first error
                             TWO_UINT8_TO_UINT16(l_iStep,l_subStep));

        /*@
         * @errortype
         * @reasoncode  ISTEP_FAILURE
         * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid    ISTEP_REPORTING_ERROR
         * @userdata1[0:31] eid of first error
         * @userdata1[32:63] Reason code of first error
         * @userdata2[0:31] Total number of elogs included
         * @userdata2[32:64] iStep and SubStep that failed
         * @devdesc     IStep failed, see other log(s) with the same PLID
         *              for reason.
         *
         */
        iv_eHandle = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                             ISTEP_REPORTING_ERROR,
                                             ISTEP_FAILURE,
                                             data1, data2);

        // Set the PLID of this istep elog to match the first error
        iv_eHandle->plid(i_err->plid());
    }
    else
    {
        // retrieve iStep and subStep
        uint32_t l_iStepSubStep = (iv_eHandle->getUserData2() & 0xFFFFFFFF);
        // update the error count and keep iStep/subStep in user data word 1
        uint64_t l_data2 = TWO_UINT32_TO_UINT64 (iv_errorCount,l_iStepSubStep);
        iv_eHandle->addUserData2(l_data2);

        // set the plid of the input elog to match the first and istep elog
        i_err->plid( iv_eHandle->plid() );
    }

    // grab the istep's trace and add to the input elog
    i_err->collectTrace("ISTEPS_TRACE", 1024);

    // add some details from the input elog to the istep error object
    ISTEP_ERROR::HwpUserDetailsIstep errorDetails( i_err );

    // cross reference input error log to istep error object
    errorDetails.addToLog( iv_eHandle );

    mutex_unlock( &iv_mutex );
}
