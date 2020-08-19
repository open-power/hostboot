/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/service/xspprdService.h $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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

    /** Access the current service generator */
    static ServiceGeneratorClass & ThisServiceGenerator();

    /** @brief Constructor */
    ServiceGeneratorClass() {}

    /** @brief Destructor */
    virtual ~ServiceGeneratorClass() {}

    /** @brief Initializer */
    virtual void Initialize() = 0;

    /**
     * @brief Sets the ErrDataService to be used.
     * @param i_eds Target ErrDataService.
     */
    virtual void setErrDataService( ErrDataService & i_eds ) = 0;

    /**
     * @brief  Creates an SRC, PFA data, and error log from the SDC provided.
     * @param  i_attnType Analysis attention type.
     * @param  io_sdc     Target SDC.
     * @return A non-nullptr error log indicates a system termination is required.
     *         Otherwise, PRD will commit the error log generated.
     * @pre    The Time of Error must be set in the given SDC.
     */
    virtual errlHndl_t GenerateSrcPfa( ATTENTION_TYPE i_attnType,
                                       ServiceDataCollector & io_sdc ) = 0;

    /**
     * @brief Creates the initial error log for PRDF::main() analysis path.
     * @param i_attnType Analysis attention type.
     */
    virtual void createInitialErrl( ATTENTION_TYPE i_attnType ) = 0;

    /**
     * @brief  Return error log associated with current analysis flow.
     * @note   For normal analysis paths only. Will return nullptr if
               createInitialErrl() has not been called in PRDF::main().
     * @return An error log.
     */
    virtual errlHndl_t getErrl() const = 0;

};

} // End namespace PRDF

#endif /* xspprdService_h */

