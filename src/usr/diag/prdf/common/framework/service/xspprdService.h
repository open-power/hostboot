/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/service/xspprdService.h $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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

// Class Description *************************************************
//
//  Name:  ServiceGeneratorClass
//  Base class: None
//
//  Description: Service interface for PRD
//  Usage:
//  ServiceGenerator serv_generator
//  ATTENTION_TYPE attentionType = MACHINE_CHECK;  (see iipsdbug.h)
//
//
//  ///// Query for flooding condition
//  if(serv_generator.QueryLoggingBufferFull())
//  {  WE ARE FLOODING.... mask errors }
//
//  ///// Save a bad return code to be in th SRC
//  serv_generator.SaveRcForSrc((int32_t)analyzeRc);
//
//  ServiceDataCollector serviceData;
//  // serviceData = results from PRD Analysis;
//  ///// Make an SRC for PRD
//  rc = serv_generator.GenerateSrcPfa(attentionType, serviceData);
//
//
// End Class Description *********************************************


#if !(defined (xspprdService_h) || defined(IIPSERVICEGENERATOR_H))
#define xspprdService_h
#define IIPSERVICEGENERATOR_H


#include <iipsdbug.h>       // for ATTENTION_TYPE
#include <errlentry.H>      //for errlHndl_t



namespace PRDF
{

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------
class ServiceDataCollector;
class ErrDataService;


/**
 Provide error loging and SRC generation services for PRD
 <b>Owner:</b> S. Bailey
 <b>CSP Only</b>
 */
class ServiceGeneratorClass
{
public:

  // dg00 start
  /**
   Access the current concrete service generator
   <ul>
   <br><b>Paramters:   </b> None
   <br><b>Returns:     </b> Reference to active ServiceGenerator
   <br><b>Requirements:</b> None
   <br><b>Promises:    </b> ServiceGenerator
   <br><b>Notes:       </b> The definition of this function should exist
                            in the *.C of the derived class
   </ul><br>
   */
  static ServiceGeneratorClass & ThisServiceGenerator(void);
  // dg00 end

  /**
   Constructor
   <ul>
   <br><b>Parameters:  </b> None
   <br><b>Returns:     </b> Nothing
   <br><b>Requirements:</b> None
   <br><b>Promises:    </b> Object created
   <br><b>Exceptions:  </b> None
   </ul><br>
   */
  ServiceGeneratorClass(void){}

  /*
   Destructor
   <ul>
   <br><b>Parameters:  </b> None.
   <br><b>Returns:     </b> No value returned
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> None.
   <br><b>Exceptions:  </b> None.
   <br><b>Notes:       </b> Compiler default is sufficient
   </ul><br>
   */
  virtual ~ServiceGeneratorClass(void) {};


  virtual void Initialize()=0;

  /**
   * @brief set the err data service to be used
   * @param[in] i_errDataService new err data service
   */
  virtual void setErrDataService(ErrDataService & i_errDataService)=0;

  /**
   Set the TOD of the current error
   <ul>
   <br><b>Parameter:   </b> the_attention (see iipsdbug.h)
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> Error timestamped with TOD, latency state modifed
   <br><b>Notes:       </b> Uses the SPC interface to get the TOD
   </ul><br>
   */
  virtual void SetErrorTod( ATTENTION_TYPE the_attention,
                            ServiceDataCollector & sdc)=0;

  /**
   Query if logging buffer full - indicates attention flooding
   <ul>
   <br><b>Parameters:  </b> none.
   <br><b>Returns:     </b> [true | false]
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> None.
   </ul><br>
   */
  virtual bool QueryLoggingBufferFull(void) const=0;

  /**
   Save a return code for inclusion in the SRC (something failed)
   <ul>
   <br><b>Parameters:  </b> a return code
   <br><b>Returns:     </b> none.
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> Rc stored
   </ul><br>
   */
  virtual void SaveRcForSrc(int32_t the_rc)=0;

  /**
   @brief Create an SRC, PFA data, and Error log for the ServiceData provided
   @param[in] attn_type  (see iipsdbug.h)
   @param[in,out] sdc  (see iipServiceData.h)
   @param[out] o_initiateHwudump whether or not to initiate hwudump
   @param[out] o_dumpTrgt The DUMP target.
   @param[out] o_dumpErrl The DUMP error handle
   @param[out] o_dumpErrlActions DUMP error action flags
   @return Error Log - Null if successfully committed
   @pre SetErrorTod()?
   @post Error log(s) build and logged, SRC built, etc.
   @exception None.
   */
  virtual errlHndl_t GenerateSrcPfa(ATTENTION_TYPE attn_type,
                                    ServiceDataCollector & sdc,
                                    bool & o_initiateHwudump,
                                    TARGETING::TargetHandle_t & o_dumpTrgt,
                                    errlHndl_t & o_dumpErrl,
                                    uint32_t & o_dumpErrlActions )=0;

    /**
     * @brief Create initial error log for analyze( attn analysis) code flow.
     * @param i_attnType attention type.
     */
    virtual void createInitialErrl( ATTENTION_TYPE i_attnType ) = 0;

    /**
     * @brief  Return error log associated with current analysis flow.
     * @return error log handle.
     */
    virtual errlHndl_t getErrl() = 0;

private:


};

} // End namespace PRDF

#endif /* xspprdService_h */

