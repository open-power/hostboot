/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsim_ras_services.H $               */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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

#ifndef PRDFSIM_RAS_SERVICES_H
#define PRDFSIM_RAS_SERVICES_H
/**
   @file prdf_ras_services.H
   @brief Description
*/

#include <prdf_ras_services.H>

namespace PRDF
{

/**
 Interface to RAS services provided to PRD
*/
class SimErrDataService: public ErrDataService
{
public:


  /**
   Default ctor
   */
  inline SimErrDataService() {}

  /**
   Default dtor
   */
  inline virtual ~SimErrDataService() {}

  /**
   Create an SRC, PFA data, and Error log for the ServiceData provided
   <ul>
   <br><b>Parameter:   </b> attn_type  (see iipsdbug.h)
   <br><b>Parameter:   </b> sdc  (see iipServiceData.h)
   <br><b>Returns:     </b> Error Log - Null if successfully committed
   <br><b>Requirements:</b> SetErrorTod()?
   <br><b>Promises:    </b> Error log(s) build and logged, SRC built, etc.
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b>
   </ul><br>
   */
  virtual errlHndl_t GenerateSrcPfa(ATTENTION_TYPE attn_type, ServiceDataCollector & sdc);


private:  // functions


private:  // Data



};

} // End namespace PRDF

#endif
