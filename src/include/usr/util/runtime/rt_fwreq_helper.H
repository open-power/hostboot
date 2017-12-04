/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/util/runtime/rt_fwreq_helper.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2017                        */
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
#ifndef __RUNTIME_FWREQ_HELPER_H
#define __RUNTIME_FWREQ_HELPER_H

#include <errl/errlentry.H>  // errlHndl_t

/**
 * @brief This is a wrapper function for the
 *        hostInterfaces::firmware_request method.  This method
 *        will do the repetitious job of checking for errors,
 *        retry call if necessary and logging errors.
 * @details
 *   req_len bytes are sent to runtime firmware, and resp_len
 *   bytes received in response.
 *
 *   Both req and resp are allocated by the caller. If resp_len
 *   is not large enough to contain the full response, an error
 *   is returned.
 *
 * @param[in]  i_reqLen       length of request data
 * @param[in]  i_req          request data
 * @param[inout] o_respLen    in: size of request data buffer
 *                            out: length of response data
 * @param[in]  o_resp         response data
 * @return errlHndl_t         NULL if successful, otherwise a pointer
 *                            to the error log.
 * @see  src/include/runtime/interface.h for definition of call
 */
errlHndl_t
firmware_request_helper(uint64_t i_reqLen,
                        void *i_req,
                        uint64_t* o_respLen,
                        void *o_resp);



#endif   // __RUNTIME_FWREQ_HELPER_H
