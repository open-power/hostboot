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
     * @brief  Creates an SRC, PFA data, and error log from the SDC provided.
     * @param  i_attnType Analysis attention type.
     * @param  i_sdc      Target SDC.
     * @param  o_initiateHwudump whether or not to initiate hwudump
     * @param  o_dumpTrgt The DUMP target
     * @param  o_dumpErrl The DUMP error handle
     * @param  o_dumpErrlActions DUMP error action flags
     * @return A non-NULL error log indicates a system termination is required.
     *         Otherwise, PRD will commit the error log generated.
     * @pre    The Time of Error must be set in the given SDC.
     */
    virtual errlHndl_t GenerateSrcPfa( ATTENTION_TYPE i_attnType,
                                       ServiceDataCollector & i_sdc,
                                       bool & o_initiateHwudump,
                                       TARGETING::TargetHandle_t & o_dumpTrgt,
                                       errlHndl_t & o_dumpErrl,
                                       uint32_t & o_dumpErrlActions ) = 0;

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

