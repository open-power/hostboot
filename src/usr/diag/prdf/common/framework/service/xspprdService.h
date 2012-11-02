/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/service/xspprdService.h $  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1999,2012              */
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

// Class Description *************************************************
//
//  Name:  ServiceGeneratorClass
//  Base class: None
//
//  Description: Service interface for PRD
//  Usage:
//  ServiceGenerator serv_generator
//  bool latent_machine_check_flag = false;
//  ATTENTION_TYPE attentionType = MACHINE_CHECK;  (see iipsdbug.h)
//
//  ///// Set time + see if latent machine check
//  serv_generator.SetErrorTod(attentionType, &latent_machine_check_flag);
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


#if !defined(IIPSDBUG_H)
 #include <iipsdbug.h>          // for ATTENTION_TYPE
#endif

#include <errlentry.H> //for errlHndl_t  //mp01 a



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
   *
   * @param[in] i_errDataService new err data service
   */
  virtual void setErrDataService(ErrDataService & i_errDataService)=0;

  /**
   Set the TOD of the current error and check for latent Machine check
   <ul>
   <br><b>Parameter:   </b> the_attention (see iipsdbug.h)
   <br><b>Returns:     </b> is_latent [true | false]
   <br><b>Requirements:</b> None.
   <br><b>Promises:    </b> Error timestamped with TOD, latency state modifed
   <br><b>Notes:       </b> Uses the SPC interface to get the TOD
   </ul><br>
   */
  virtual void SetErrorTod(ATTENTION_TYPE the_attention,bool *is_latent,ServiceDataCollector & sdc)=0;

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

  virtual errlHndl_t GenerateSrcPfa(ATTENTION_TYPE attn_type, ServiceDataCollector & sdc)=0; // mp01 c

private:


};

} // End namespace PRDF

#endif /* xspprdService_h */

