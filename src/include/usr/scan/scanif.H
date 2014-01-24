/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/scan/scanif.H $                               */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
#ifndef __SCANIF_H
#define __SCANIF_H


namespace SCAN
{

    /**
     * SCAN Interface Flags
     *   This is a bitmap to allow the user to specify multiple modes
     */
    enum ScanFlags
    {
       NO_HEADER_CHECK =  0x00000001,   /**< SCAN Do Not do Header Check*/
       SET_PULSE  =       0x00000002    /**< SCAN set pulse */
       //NEXT_FLAG  = 0x00000004 
       //NEXT_FLAG1 = 0x00000008
    };


}

// Standard Traces
#define SCANDD_TRACE_BUF "SCANDD"

// Register Traces
#define SCANDD_RTRACE_BUF "SCANDDR"

#endif 
