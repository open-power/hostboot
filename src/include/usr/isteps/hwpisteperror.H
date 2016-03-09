/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/hwpisteperror.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
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
#ifndef __ISTEPERROR_H
#define __ISTEPERROR_H
/**
 *  @file isteperror.H
 *
 *  Defines the following classes:
 *
 *  IStepError: Handles creation of a top level error to incidate that a
 *              particular ISTEP has failed
 */

#include <errl/errlentry.H>
#include <isteps/istep_reasoncodes.H>


namespace ISTEP_ERROR
{
    /**
     * @class IStepError
     *
     * Contains a top-level IStep failed error log.
     *
     * Isteps can perform operations on multiple components regardless of errors
     * in order to initialize as much hardware as possible. Each IStep creates
     * an IstepError object and for each sub-error, the addErrorDetails()
     * function is called before the caller commits the sub-error. At the end
     * of an IStep, the getErrorHandle() function is called to return the
     * top-level istep error (if any) to the IStep Dispatcher.
     *
     * The top-level IStep error and all sub-errors have the same PLID (matching
     * the EID of the first sub-error) so that the IStep error is linked to all
     * errors that caused the IStep failure.
     */
    class IStepError
    {
        public:
            /**
             *  @brief
             */
            IStepError()
             : iv_eHandle(NULL), iv_errorCount(0)
             {
                 mutex_init( &iv_mutex );
             };

            /**
             *  @brief Destructor
             *
             *  Will free internal storage if getErrorHandle is not called
             */
            ~IStepError()
            {
                 mutex_destroy( &iv_mutex );

                 if( iv_eHandle )
                 {
                     delete iv_eHandle;
                 }
            };

            /**
             *  @brief  Adds selected error details from the passed in
             *          error to the top level istep error log object
             *
             *          The first call will initialize the internal object
             *          pointer allocating a new errl object as needed.
             *          The iStep and subStep is retrieved from the
             *          istepdispatcher and added to the log.
             *          Subsequent calls to this function will result in a new
             *          user data section being added to the top level error
             *          log with additional error data from the error handle
             *          passed in.
             *
             *          NOTE: This function is thread safe.
             *
             *  @param  i_err     - error handle passed in, the internal code
             *                      will parse specific details from the log
             *                      passed in to include in the top level elog.
             */
            void addErrorDetails( errlHndl_t i_err );

            /**
             *  @brief  Return an errlHndl_t which points to the internal error
             *          log object.
             *
             *  Note:   Caller must delete the errlHndl_t after use.
             *          This function is not thread safe
             *
             *  @return  iv_eHandle - error handle of top level ISTEP error to
             *           be returned to the ISTEP dispatcher.
             *
             */
            errlHndl_t getErrorHandle();

            /**
             *  @brief  Utility function to determine if the internal error
             *          handle is null.
             *
             *  @return  boolean
             *                  true indicates errl handle is currently NULL;
             *                  false indicates error object has been
             *                  allocated;
             *
             *  Note: This funciton is not thread safe
             *
             */
            bool isNull() const { return ((iv_eHandle==NULL ) ? true : false);};

        private:

            // disable copy constructor
            IStepError(const IStepError&);

            // serialize access to the internal data area
            mutex_t     iv_mutex;

            // pointer to the top level ISTEP error log, this log will be
            // passed back to the istep dispatcher when a hardware proceudre
            // fails.
            errlHndl_t  iv_eHandle;

            // count placed in user data 3 of the error log to indicate how
            // many errors were captured in this top level elog
            uint32_t    iv_errorCount;

    };

    inline errlHndl_t IStepError::getErrorHandle()
    {
        errlHndl_t l_err = iv_eHandle;

        // storage will be freed by destructor if the pointer is non-null
        iv_eHandle = NULL;

        return l_err;
    };


};

#endif
