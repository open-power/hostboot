/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/prdfFabricDomain.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2002,2013              */
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

#ifndef prdfFabricDomain_H
#define prdfFabricDomain_H

//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------
#if !defined(iipCallResolutionTemplate_h)
  #include <iipCallResolutionTemplate.h>
#endif

#include <prdfRuleChipDomain.H>
#include <prdfPlatServices.H>

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------
/**
 @file prdfFabricDomain.H
 @brief Fabric Domain, contains Fabric Chips
 @author Mike Kobler
*/

namespace PRDF
{

class FabricDomain : public RuleChipDomain
{
  public:

    /**
     * @brief Constructor
     * @param i_did  The domain ID
     * @param i_size The projected size of the domain
     */
    FabricDomain( DOMAIN_ID i_did, uint32_t i_size = PROC_DOMAIN_SIZE ) :
        RuleChipDomain( i_did, i_size )
    {}

  /*
   Destructor
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> No value returned
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> Compiler default sufficient
   </ul><br>
   */
  //~FabricDomain();

  /*
   Determin which chip to Analyze and call it's Analyze() function
   <ul>
   <br><b>Parameter:   </b> serviceData (See iipServiceDataCollector.h)
   <br><b>Parameter:   </b> attentionType [MACHINE_CHECK|RECOVERED|SPECIAL]
   <br><b>Returns:     </b> return code (0 == SUCCESS)
   <br><b>Requirements:</b> Query() == true, Initialize()
   <br><b>Promises:    </b> serviceData complete
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> This implementation calls Order() to determin
   which chip to analyze and calls that chips
   Analyze() function.
   </ul><br>
   */
   virtual int32_t Analyze( STEP_CODE_DATA_STRUCT & serviceData,
                            ATTENTION_TYPE attentionType );

    /**
     * @brief  Determine which chip to Analyze in a list of chips in this domain.
     * @note   This main only analyze one chip in the domain.  Not the whole domain.
     * @param  serviceData   Service data collector.
     * @param  attentionType Attention of the chip.
     * @param  i_chips       List of chips in the domain to analyze.
     * @return SUCCESS
     */
   virtual int32_t AnalyzeTheseChips( STEP_CODE_DATA_STRUCT & serviceData,
                                      ATTENTION_TYPE attentionType,
                                      TARGETING::TargetHandleList & i_chips );
    /**
     * @brief  Order chips in a list of chips in this domain.
     * @note
     * @param  attentionType Attention of the chip.
     * @param  i_chips       List of chips in the domain to analyze.
     * @return SUCCESS
     */
    virtual int32_t OrderTheseChips( ATTENTION_TYPE attentionType,
                                     TARGETING::TargetHandleList & i_chips );

    /**
     * @brief  Finds the pointer to the appropriate chip to do analysis or other.
     * @note   Just a function to help keep order in a subset of the domain.
     * @param  i_chipId      Handle of the chip to find.
     * @param  i_chips       List of chips in the domain to analyze.
     * @return SUCCESS
     */
    virtual RuleChip * FindChipInTheseChips( TARGETING::TargetHandle_t i_chipId,
                                             TARGETING::TargetHandleList & i_chips );

    /**
     * @brief  Moves the chip in question to the front of the list of chips.
     * @note   This gives analysis some good chance of finding the correct chip first.
     * @param  i_chipToFront The chip that should be in the front of the list.
     * @param  i_chips       List of chips in the domain to analyze.
     * @return SUCCESS
     */
   virtual void MoveToFrontInTheseChips( uint32_t i_chipToFront,
                                         TARGETING::TargetHandleList & i_chips );

protected:

  /**
   Determin which chip to Analyze and call it's Analyze() function
   <ul>
   <br><b>Parameter:   </b> attentionType [MACHINE_CHECK|RECOVERED|SPECIAL]
   <br><b>Returns:     </b> return code (0 == SUCCESS)
   <br><b>Requirements:</b> Query() == true, Initialize()
   <br><b>Promises:    </b> chip at attention at top of list
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b>
   </ul><br>
   */
  virtual void Order(ATTENTION_TYPE attentionType);

  /**
   Determine which chip to Analyze on checkstop and put at front of list.
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:        </b> None.
   <br><b>Requirements:</b> Query() == true, Initialize()
   <br><b>Promises:    </b> chip at attention at top of list
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b>
   </ul><br>
   */
  virtual void SortForXstop();
  virtual void SortForRecov();

private:  // functions
private:  // Data

};

} // end namespace PRDF

#endif /* prdfFabricDomain_H */
