/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/prdfErrorRegister.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1996,2012              */
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

/**
 @file iipErrorRegister.C
 @brief ErrorRegister class definition
*/
// Module Description **************************************************
//
// Description: Definition of ErrorRegister class
//
// End Module Description **********************************************
//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#define iipErrorRegister_C

#include <prdfMain.H>
#include <prdfAssert.h>
#include <iipstep.h>
#include <iipbits.h>
#include <iipResolution.h>
#include <iipscr.h>
#include <prdfErrorSignature.H>
#include <iipServiceDataCollector.h>
#include <prdfResolutionMap.H>
#include <iipErrorRegister.h>

#include <iipconst.h>
#include <iipglobl.h>
#undef iipErrorRegister_C
//----------------------------------------------------------------------
//  User Types
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Constants
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Macros
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Internal Function Prototypes
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Global Variables
//----------------------------------------------------------------------

//---------------------------------------------------------------------
// Member Function Specifications
//---------------------------------------------------------------------

int32_t ErrorRegister::SetErrorSignature(STEP_CODE_DATA_STRUCT & error,prdfBitKey & bl)
{
  using namespace PRDF;

  int32_t rc = SUCCESS;
  ErrorSignature * esig = error.service_data->GetErrorSignature();
  uint32_t blen = bl.size();
  switch(blen)
  {
    case 0:
      (error.service_data->GetErrorSignature())->setErrCode(PRD_SCAN_COMM_REGISTER_ZERO);
      if(xNoErrorOnZeroScr != true) rc = PRD_SCAN_COMM_REGISTER_ZERO;
      break;

    case 1:
      esig->setErrCode(bl.getListValue(0));
      break;

    default:
      for(uint32_t index = 0; index < blen; ++index)  //dg01a
      {                                                             //dg01a
        esig->setErrCode(bl.getListValue(index));                 //dg01a
      }                                                             //dg01a
      esig->setErrCode(PRD_MULTIPLE_ERRORS);
  };
  return rc;
}

/*---------------------------------------------------------------------*/

ErrorRegister::ErrorRegister
(SCAN_COMM_REGISTER_CLASS & r, prdfResolutionMap & rm, uint16_t scrId)
: ErrorRegisterType(), scr(r), scr_rc(SUCCESS), rMap(rm),  xNoErrorOnZeroScr(false), xScrId(scrId)
{
  PRDF_ASSERT(&r != NULL);
  PRDF_ASSERT(&rm != NULL);
}

/*---------------------------------------------------------------------*/

int32_t ErrorRegister::Analyze(STEP_CODE_DATA_STRUCT & error)
{
  using namespace PRDF;

  int32_t rc = SUCCESS;

  uint32_t l_savedErrSig = 0;  // @pw01

  if(xScrId == 0x0fff)
  {
    (error.service_data->GetErrorSignature())->setRegId(scr.GetAddress());
  }
  else
  {
    (error.service_data->GetErrorSignature())->setRegId(xScrId);
  }

  // Get Data from hardware
  const BIT_STRING_CLASS &bs = Read(error.service_data->GetCauseAttentionType()); // @pw02
  prdfBitKey bl;     // null bit list has length 0

  if (scr_rc == SUCCESS)
  {
    bl = Filter(bs);
    rc = SetErrorSignature(error,bl);  //dg02c - made function of this block of code
    // @pw01
    // Save signature to determine if it changes during resolution execution.
    l_savedErrSig = (error.service_data->GetErrorSignature())->getSigId();
  }

  uint32_t res_rc = Lookup(error, bl); // lookup and execute the resolutions
  if(SUCCESS == rc) rc = res_rc; // previous rc has prioity over res_rc


  // @pw01
  // If we had a DD02 and the signature changes, ignore DD02.
  if ((rc == PRD_SCAN_COMM_REGISTER_ZERO) &&
      ((error.service_data->GetErrorSignature())->getSigId()
        != l_savedErrSig)
     )
  {
      // Found a better answer during the DD02 analysis.
      rc = res_rc;
  }


  if(scr_rc == SUCCESS)
  {
    FilterUndo(bl); // dg03a
    // NOTE:  This is an unusual work-a-round for NOT clearing
    //        particular FIR bits in a register because they are cleared
    //        in another part of the plugin code.  jl01
    if(rc == PRD_NO_CLEAR_FIR_BITS)
    {
        rc = SUCCESS;  //Return success to indicate that we understand the DDFF
    }
    else
    {
        int32_t reset_rc;
        reset_rc = Reset(bl,error);
        if(rc == SUCCESS)rc = reset_rc;
    }
  }
  else // scr read failed
  {
    (error.service_data->GetErrorSignature())->setErrCode(PRD_SCANCOM_FAILURE);
    rc = scr_rc;
  }

  return(rc);
}

/*---------------------------------------------------------------------*/

const BIT_STRING_CLASS & ErrorRegister::Read(ATTENTION_TYPE i_attn)
{
  scr_rc = scr.Read();
  return (*scr.GetBitString(i_attn));
}

/*---------------------------------------------------------------------*/

prdfBitKey ErrorRegister::Filter
(const BIT_STRING_CLASS & bs)
{
  prdfBitKey bit_list;
  bit_list = bs;
  return(bit_list);
}

/*---------------------------------------------------------------------*/

int32_t ErrorRegister::Lookup(STEP_CODE_DATA_STRUCT & sdc, prdfBitKey & bl) // dg02c dg03c
{
  int32_t rc = SUCCESS;
//  if (bl.GetListLength() == 0) return(rMap.GetDefault());  /dg00d
  prdfResolutionList rList;
  rMap.LookUp(rList,bl,sdc); // dg04c
  // SetErrorSignature(sdc,bl);   // LookUp may have changed bl dg02a dg04d
  for(prdfResolutionList::iterator i = rList.begin(); i != rList.end(); ++i)
  {
    rc |= (*i)->Resolve(sdc);
  }
  return rc;
}

/*---------------------------------------------------------------------*/

int32_t ErrorRegister::Reset(const prdfBitKey & bit_list, STEP_CODE_DATA_STRUCT & error)
{
  return(SUCCESS);
}
