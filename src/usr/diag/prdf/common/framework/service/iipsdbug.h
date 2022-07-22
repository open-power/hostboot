/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/service/iipsdbug.h $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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

#ifndef IIPSDBUG_H
#define IIPSDBUG_H

/*!
 @file iipsdbug.h
 @brief PRD wrapper to the system debug data
*/

/* Module Description *************************************************/
/*                                                                    */
/*  Name:  iipsdbug.h                                                 */
/*                                                                    */
/*  Description:  This module contains the Processor Runtime
                  Diagnostics System Debug area class declaration.    */
/*                                                                    */
/* End Module Description *********************************************/

/*--------------------------------------------------------------------*/
/* Reference the virtual function tables and inline function
   defintions in another translation unit.                            */
/*--------------------------------------------------------------------*/
#ifdef __GNUC__
 #pragma interface
#endif

/*--------------------------------------------------------------------*/
/*  Includes                                                          */
/*--------------------------------------------------------------------*/

#include <stdint.h>
#include <prdfMain.H>
#include <prdfTargetFwdRef.H>

namespace PRDF
{

/*--------------------------------------------------------------------*/
/*  Forward References                                                */
/*--------------------------------------------------------------------*/

//class CHIP_CLASS;
struct PRD_SRC_TYPE;
struct STEP_CODE_DATA_STRUCT;

/*--------------------------------------------------------------------*/
/*  User Types                                                        */
/*--------------------------------------------------------------------*/

typedef uint8_t ATTENTION_TYPE;


/*--------------------------------------------------------------------*/
/*  Constants                                                         */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*  Macros                                                            */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*  Global Variables                                                  */
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/
/*  Function Prototypes                                               */
/*--------------------------------------------------------------------*/

/* Class Specification ************************************************/
/*                                                                    */
/*  Title:  System Debug                                              */
/*                                                                    */
/*  Purpose:  SYSTEM_DEBUG_CLASS is an interface to the Service
              Processor Communcation Area (SPCA) System Debug common
              memory area.                                            */
/*                                                                    */
/*  Usage:  Concrete class                                            */
/*                                                                    */
/*  Notes:  This System Debug specifies an interface for accessing
            data in the SPCA sysdbug structure.                       */
/*                                                                    */
/*  Cardinality:  N                                                   */
/*                                                                    */
/*  Space Complexity:  Constant                                       */
/*                                                                    */
/* End Class Specification ********************************************/
/**
 Provide services associated with the service processor system debug area
 @author Douglas R. Gilbert
 @version V4R5
*/
class SYSTEM_DEBUG_CLASS
{
public:

  /**
   Constructor
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Requirements:</b> sp virtuals established
   <br><b>Promises:    </b> Object instantiated
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  SYSTEM_DEBUG_CLASS(void);


  /**
   Re-read attention data
   <ul>
   <br><b>Parameters:  </b> i_attnList list of chips at attention
   <br><b>Returns:     </b> None.
   <br><b>Requirements:</b> sp virtuals established
   <br><b>Promises:    </b> object resurrected
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  uint32_t Reinitialize(const AttnList & i_attnList);

  /**
   * @brief      Indicates if an attention is active and still not analyzed
   * @param      i_chipTrgt  chip under investigation for pending active attn.
   * @param      i_attn      Attn for which analysis status is to be determined.
   * @return     [true | false]
   */
  bool isActiveAttentionPending(
                        TARGETING::TargetHandle_t i_chipTrgt,
                        ATTENTION_TYPE i_attn = INVALID_ATTENTION_TYPE ) const;

  /**
   * @brief     clears the active attention pending status
   * @param     i_chipTrgt  chip for which pending status is set to false.
   * @param     i_attn      Attn for which analysis status is to be determined.
   */
  void clearAttnPendingStatus( TARGETING::TargetHandle_t i_chipTgt,
                               ATTENTION_TYPE i_attn );

  /**
   * @brief     sets attention analysis pending status to true for all chips in
   *            the attention list for each type of attention.
   */
  void initAttnPendingtatus( );

  /**
   Get the attention type for the attention that is active on this chip
   <ul>
   <br><b>Parameters:  </b> i_pTargetHandle
   <br><b>Returns:     </b> ATTENTION_TYPE
   <br><b>Requirements:</b> IsAttentionActive() == true
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  uint8_t getPrimaryAttnType(TARGETING::TargetHandle_t i_ptargetHandle ) const;

    /**
     * @brief  Get the first target in this attention list with the given target
     *         type and given attention type.
     * @param  i_trgtType Target type.
     * @param  i_attnType Attention type.
     * @return A target matching the given parameters. Otherwise, nullptr if not
     *         found.
     * @pre    IsAttentionActive() == true
     */
    TARGETING::TargetHandle_t getTargetWithAttn(
        TARGETING::TYPE i_trgtType, ATTENTION_VALUE_TYPE i_attnType) const;

  /**
   Get the attention type for the attention that is active on this chip
   <ul>
   <br><b>Parameters:  </b> ChipClass
   <br><b>Returns:     </b> ATTENTION_TYPE
   <br><b>Requirements:</b> IsAttentionActive() == true
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
//  uint8_t getPrimaryAttnType(const CHIP_CLASS & chip) const;

  /**
   Get the global(overall) attention type
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> ATTENTION_TYPE
   <br><b>Requirements:</b> None,
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  uint32_t GetGlobalAttentionType(void) const;


  /**
   Set the sysdebug SRC pointer to the PRD generated SRC
   <ul>
   <br><b>Parameters:  </b> ptr to SRC
   <br><b>Returns:     </b> None
   <br><b>Requirements:</b> src_ptr is valid
   <br><b>Promises:    </b> sysdebug modified
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  void SetPrdSrcPointer(uint32_t*);
  void SetPrdSrcPointer(); // called by main - can we remove it?


  /**
   Create an SRC in the SOT (obsolete)
   <ul>
   <br><b>Parameters:  </b> reference code, step code, analysis return code
   <br><b>Returns:     </b> return code
   <br><b>Requirements:</b> none.
   <br><b>Promises:    </b> SRC written to SOT
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> No implementation after V3R7
   </ul><br>
   */
//  int32_t SrcFill(uint16_t ref_code, uint16_t step_code, uint16_t mop_rc) const;

  /**
   Callout all chips at attention
   <ul>
   <br><b>Parameters:  </b> ServiceData
   <br><b>Returns:     </b> None.
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> Hardware called out low and 2nd level support high
   <br><b>Exceptions:  </b> None.
   </ul><br>
   */
  void CalloutThoseAtAttention(STEP_CODE_DATA_STRUCT & serviceData) const;

  enum { MAX_ERROR_ENTRY_INDEX = 80 };

  /**
   Clear the attentions
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> None.
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> Nothing is at attention
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b>
   </ul><br>
   */
  void Clear(void);

  // Functions used by the simulator only
  /**
   Get the pointer to the PRD SRC in sysdebug (Simulator only)
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> ptr to SRC
   <br><b>Requirements:</b> SetPrdSrcPointer()
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> Available in PRD simulator only
   </ul><br>
   */
  const uint32_t *GetPrdSrcPointer(void) const;

  /**
   Set the attention type for the specified chip (Simulator only)
   <ul>
   <br><b>Parameters:  </b> i_pTargetHandle, ATTENTION_TYPE
   <br><b>Returns:     </b> None.
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> getPrimaryAttnType() == at
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> Available in PRD simulator only
   </ul><br>
   */
  void setPrimaryAttnType( TARGETING::TargetHandle_t i_pTargetHandle,
                           ATTENTION_VALUE_TYPE i_eAttentionType );

  /**
   * @brief   Adds a chip to the list of chips reporting attention.
   * @param   i_chipTgt  chip to be added to the list.
   * @param   i_attnType attn associated with the chip
  */
  void addChipToAttnList( TARGETING::TargetHandle_t i_chipTgt,
                          ATTENTION_VALUE_TYPE i_attnType );

private:

  enum
  {
    SRCFILL_FORMAT = 1,
    SRCFILL_GROUP = 7
  };
};

} // end namespace PRDF

#endif //IIPSDBUG_H

