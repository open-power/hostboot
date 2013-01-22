/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mbox/plugins/mboxUdParser.H $                         */
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

#include "errluserdetails.H"

namespace MBOX
{
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
              uint64_t * b64 = reinterpret_cast<uint64_t *>(b32 + 4);

              uint32_t msg_id = ntohl(*b32);
              uint32_t msg_q_id = ntohl(*(b32+1));
              uint32_t msg_type = ntohl(*(b32+2));
              uint32_t msg_flag = ntohl(*(b32+3));
              uint64_t msg_dta0 = ntohll(*(b64));
              uint64_t msg_dta1 = ntohll(*(b64+1));
              uint64_t msg_extd = ntohll(*(b64+2));

              i_parser.PrintNumber("MBOX message id","0x%08x",msg_id);
              i_parser.PrintNumber("MBOX queue id","0x%08x",msg_q_id);
              i_parser.PrintNumber("MBOX message type","0x%08x",msg_type);
              if(msg_flag & 0x80000000)
              {
                 i_parser.PrintString(NULL, "MBOX mesage is synchronous");
              }
              else
              {
                 i_parser.PrintString(NULL, "MBOX message is asynchronous");
              }

              i_parser.PrintNumber("MBOX data[0]","0x%016lx",msg_dta0);
              i_parser.PrintNumber("MBOX data[1]","0x%016lx",msg_dta1);
              i_parser.PrintNumber("MBOX Extra data pointer","0x%016lx",msg_extd);


              if(msg_extd != 0 && i_buflen > 40)
              {
                  i_parser.PrintString(NULL, "MBOX extra data:");

                  uint8_t * b08 = reinterpret_cast<uint8_t *>(b64 + 3);
                  size_t len = i_buflen - 40;

                  i_parser.PrintHexDump(b08,len);

              }
          }
    };
}

#endif

