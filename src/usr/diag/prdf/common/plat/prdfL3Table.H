/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/prdfL3Table.H $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2004,2014              */
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
#include <prdfTargetFwdRef.H>
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

