/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/prdfL3Table.H $                 */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2004,2012              */
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

#ifndef PRDFL3TABLE_H
#define PRDFL3TABLE_H
/**
   @file prdfL3Table.H
   @brief Description
*/


//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#include <stdint.h>
#include <targeting/common/target.H>
#include <errlentry.H>

namespace PRDF
{

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------

enum l3TableEnum
{
  LineDeleteTableSize   = 10,                   ///< Size of line delete table
  TableSizeBytes        = LineDeleteTableSize*4,       // wl01
  allFox                = 0xffffffff,           ///< uint of -1
  l3AddressMask         = 0x007ffff0
};

 /**
  Add a cache line address to the cache line delete table
  <ul>
  <br><b>Parameters:  </b> L3 target Handle, cacheline address in format from ReadDataErLg2 register
  <br><b>Returns:     </b> 0 = address already in table, 1-LineDeleteTableSize = position added to table, LineDeleteTableSize + 1 = table overflow
  <br><b>Requirements:</b> preconditions
  <br><b>Promises:    </b> postconditions
  <br><b>Exceptions:  </b> None.
  <br><b>Notes:       </b>
  </ul><br>
*/
extern int32_t L3TableAdd(TARGETING::TargetHandle_t i_pl3targetHandle, uint32_t address);

 /**
  Copies the line delete table to memory address passed in
  <ul>
  <br><b>Parameters:  </b> L3 target Handle, address of int32[10]
  <br><b>Returns:     </b> returns void
  <br><b>Requirements:</b> preconditions
  <br><b>Promises:    </b> postconditions
  <br><b>Exceptions:  </b> None.
  <br><b>Notes:       </b>
  </ul><br>
*/
extern void L3TableGet(TARGETING::TargetHandle_t i_pl3targetHandle, uint32_t table[LineDeleteTableSize]);

 /**
  Get the count of line deletes in the table
  <ul>
  <br><b>Parameters:  </b> L3 target Handle
  <br><b>Returns:     </b> returns the number of line deletes in the table
  <br><b>Requirements:</b> preconditions
  <br><b>Promises:    </b> postconditions
  <br><b>Exceptions:  </b> None.
  <br><b>Notes:       </b>
  </ul><br>
*/
extern int32_t prdfL3TableCount(TARGETING::TargetHandle_t i_pl3targetHandle);

 /**
  Makes the call to DA to do the line delete
  <ul>
  <br><b>Parameters:  </b> L3 target Handle, cacheline address in format from ReadDataErLg2 register
  <br><b>Returns:     </b> returns return code from D/a
  <br><b>Requirements:</b> preconditions
  <br><b>Promises:    </b> postconditions
  <br><b>Exceptions:  </b> None.
  <br><b>Notes:       </b>
  </ul><br>
*/
extern errlHndl_t prdfL3LineDelete(TARGETING::TargetHandle_t i_pl3targetHandle, uint32_t address);

} // end namespace PRDF

#endif /* PRDFL3TABLE_H */

