/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/usr/mbox/mboxUdParser.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
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
#if !defined(_MBOXUDPARSER)
#define _MBOXUDPARSER

#include <errl/errluserdetails.H>
#include <errl/errludparser.H>
#include <util/align.H>
#include <mbox/mbox_reasoncodes.H>

namespace MBOX
{
#if defined(PARSER)

    /**
     * Parses mbox message user detail in an error log
     */
    class UserDetailsParserMboxMsg : public ERRORLOG::ErrlUserDetailsParser
    {
        public:

           /**
            * Constructor
            */
           UserDetailsParserMboxMsg() {}

           /**
            * Destructor
            */
          virtual ~UserDetailsParserMboxMsg() {}

          /**
           * Parses a mbox msg in an error log.
           *
           * @param[in] i_version Version of the data
           * @param[in] i_parse   ErrlUsrParser object for the output info
           * @param[in] i_pBuffer Pointer to the buffer containing detail data
           * @param[in] i_buflen  Length of the buffer
           */
          virtual void parse(errlver_t i_version,
                             ErrlUsrParser & i_parser,
                             void * i_pBuffer,
                             const uint32_t i_buflen) const
          {
              uint32_t * b32 = static_cast<uint32_t *>(i_pBuffer);
              uint64_t * b64 = static_cast<uint64_t *>(b32 + 4);

              uint32_t msg_id = ntohl(*b32);
              uint32_t msg_q_id = ntohl(*(b32+1));
              uint32_t msg_type = ntohl(*(b32+2));
              uint32_t msg_flag = ntohl(*(b32+3));
              uint64_t msg_dta0 = ntohll(*(b64));
              uint64_t msg_dta1 = ntohll(*(b64+1));
              uint64_t msg_extd = ntohll(*(b64+2));

              i_parser.PrintNumber("MBOX message id:   0x%08x",msg_id);
              i_parser.PrintNumber("MBOX queue id:     0x%08x",msg_q_id);
              i_parser.PrintNumber("MBOX message type: 0x%08x",msg_type);
              if(msg_flag & 0x80000000)
              {
                 i_parser.PrintString("MBOX mesage is synchronous");
              }
              else
              {
                 i_parser.PrintString("MBOX message is asynchronous");
              }

              i_parser.PrintNumber("MBOX data[0]: 0x%016lx",msg_dta0);
              i_parser.PrintNumber("MBOX data[1]: 0x%016lx",msg_dta1);
              i_parser.PrintNumber("MBOX Extra data pointer: 0x%016lx",msg_extd);


              if(msg_extd != 0 && i_buflen > 40)
              {
                  i_parser.PrintString("MBOX extra data:");

                  uint8_t * b08 = static_cast<uint8_t *>(b64 + 3);
                  size_t len = i_buflen - 40;

                  i_parser.PrintHexDump(b08,len);

              }
          }
    };

#else
    class UserDetailsMboxMsg : public ERRORLOG::ErrlUserDetails
    {
        public:

        UserDetailsMboxMsg(uint64_t * i_mbox_msg,
                           size_t i_msg_byte_size,
                           uint64_t * i_extra_data = NULL,
                           size_t i_data_byte_size = 0)
        {
            iv_CompId = HBMBOX_COMP_ID;
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

#endif
};
#endif
