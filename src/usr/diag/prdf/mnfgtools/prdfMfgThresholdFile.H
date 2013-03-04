/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/mnfgtools/prdfMfgThresholdFile.H $          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2009,2013              */
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

#ifndef __PRDF_PRDFMFGTHRESHOLDFILE_H
#define __PRDF_PRDFMFGTHRESHOLDFILE_H

namespace PRDF
{

// These macros are needed to keep MfgThresholdMgr common
// no-ops in Hostboot

#define PRDF_MFG_THRESHOLD_FILE_DECLARE(__FILEPTR__)

#define PRDF_MFG_THRESHOLD_FILE_INIT(__FILEPTR__)

#define PRDF_MFG_THRESHOLD_FILE_GET(__FILEPTR__,        \
                                    __THRESHOLDNAME__,  \
                                    __THRESHOLDVALUE__)

#define PRDF_MFG_THRESHOLD_FILE_SETUP(__FILEPTR__)

#define PRDF_MFG_THRESHOLD_FILE_DELETE(__FILEPTR__)

} // end namespace PRDF

#endif
