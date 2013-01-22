/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/mbox/mboxUdParser.H $                         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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

