/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/mbox/mboxUdParser.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
#if !defined(_MBOXUDPARSER)
#define _MBOXUDPARSER

#include <errl/errluserdetails.H>
#include <mbox/mbox_reasoncodes.H>
#include <util/align.H>

namespace MBOX
{
    class UserDetailsMboxMsg : public ERRORLOG::ErrlUserDetails
    {
        public:

        UserDetailsMboxMsg(uint64_t * i_mbox_msg,
                           size_t i_msg_byte_size,
                           uint64_t * i_extra_data = NULL,
                           size_t i_data_byte_size = 0)
        {
            iv_CompId = MBOX_COMP_ID;
            iv_Version = 1;
            iv_SubSection = MBOX_UDT_MBOXMSG_DATA;
            iv_merge = false;

            if(i_extra_data == NULL)
            {
                i_data_byte_size = 0;
            }

            size_t msg_size = ALIGN_8(i_msg_byte_size);
            size_t dta_size = ALIGN_8(i_data_byte_size);

            uint64_t  * buffer = 
                reinterpret_cast<uint64_t*>(reallocUsrBuf(msg_size+dta_size));

            msg_size /= 8;
            dta_size /= 8;
            for(size_t i = 0; i < msg_size; ++i)
            {
                buffer[i] = i_mbox_msg[i];
            }
            for(size_t i = 0; i < dta_size; ++i)
            {
                buffer[msg_size+i] = i_extra_data[i];
            }
        }

        ~UserDetailsMboxMsg() {}
        
    };
}

#endif

