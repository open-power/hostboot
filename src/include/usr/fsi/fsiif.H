//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/fsi/fsiif.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END

#ifndef __FSI_FSIIF_H
#define __FSI_FSIIF_H

#include <stdint.h>
#include <builtins.h>
#include <errl/errlentry.H>

namespace FSI
{

/**
 * Master or Cascaded Master
 */
enum MasterType {
    MFSI_TYPE  = 0,
    CMFSI_TYPE = 1,
    NO_MASTER  = 2
};


//@todo - move this into attributes
/**
 * @brief Structure which defines info necessary to access a chip via FSI
 *
 * Structure which defines info necessary for FSI access.  Only applicable
 * for chip targets.  Structure is read-only.  Each chip will have 2 copies
 * of this data, depending on which chip we boot from.
 */
struct FsiChipInfo_t
{
    TARGETING::Target* master; ///< FSI Master  @fixme - convert to EntityPath
    MasterType type; ///< Master or Cascaded Master
    uint8_t port; ///< Which port is this chip hanging off of  
    uint8_t cascade; ///< Slave cascade position
    uint64_t attributes; ///< Reserved for any special flags we might need
};

/**
 * @brief Initialize the FSI hardware
 *
 * @param[out] o_numPorts  Number of FSI ports that were
 *    successfully initialized
 *
 * @return errlHndl_t  NULL on success
 */
errlHndl_t initializeHardware( uint64_t& o_numPorts );


}

#endif 
