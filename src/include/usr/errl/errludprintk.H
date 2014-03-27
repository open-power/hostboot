/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/errl/errludprintk.H $                         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2014                   */
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
#ifndef ERRL_UDPRINTK_H
#define ERRL_UDPRINTK_H

/**
 *  @file errludprintk.H
 *
 *  Defines the ErrlUserDetailsPrintk class that adds a portion of the printk
 *  buffers as FFDC to an error log as user detail data.
 */

#include <stdint.h>
#include <errl/errluserdetails.H>

namespace ERRORLOG
{

    class ErrlUserDetailsPrintk : public ErrlUserDetails
    {
        public:
            enum { DEFAULT_SIZE_BYTES = 256 };

            /** @brief Constructor
             *
             *  Captures the printk buffer.
             *
             *  @param[in] i_size - Amount (in bytes) of data to capture.
             */
            explicit ErrlUserDetailsPrintk(size_t i_size = DEFAULT_SIZE_BYTES)
            {
                _capturePrintk(i_size);
            }

            /** @brief Destructor
             */
            virtual ~ErrlUserDetailsPrintk() {};

        private:
            //Disabled.
            ErrlUserDetailsPrintk(const ErrlUserDetailsPrintk&);
            ErrlUserDetailsPrintk& operator=(const ErrlUserDetailsPrintk&);

            void _capturePrintk(size_t);
    };

}

#endif
