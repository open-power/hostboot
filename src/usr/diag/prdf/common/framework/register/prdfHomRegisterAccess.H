/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/prdfHomRegisterAccess.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2002,2014              */
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

#ifndef PRDFHOMREGISTERACCESS_H
#define PRDFHOMREGISTERACCESS_H
/**
   @file prdfHomRegisterAccess.H
   @brief Provide access to scan & scan com registers via the HOM
*/


//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#include <iipMopRegisterAccess.h>
#include <vector>
#include <prdfPlatServices.H>
#include <prdfErrlUtil.H>
#include <prdfGlobal.H>
//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------

namespace PRDF
{

class ScomAccessor
{
  public:

    /**
     * @brief ctor
     */
    inline ScomAccessor() {}

    /**
     * @brief dtor
     */
    inline virtual ~ScomAccessor() {}

    /**
     * @brief Access the scan com register
     * @param i_target    Target to access the register
     * @param bs holds    data read or to write
     * @param registerId  register address
     * @param operation   [READ|WRITE]
     * @returns NULL if Success, valid error handle otherwise.
     * @pre bs.Length() must be size of register data to read/write
     * @post For read operation, bs is modified to reflect hardware
     *       register state
     */
    virtual errlHndl_t  Access( TARGETING::TargetHandle_t i_target,
                                BIT_STRING_CLASS & bs,
                                uint64_t registerId,
                                MopRegisterAccess::Operation operation) const;

  private:

    /**
     * @brief disable copy
     */
    ScomAccessor(const ScomAccessor &);

    /**
     * @brief disable assignment
     */
    ScomAccessor & operator=(const ScomAccessor &);

};

/**
 *  @brief Singleton to access the only ScomService
 */
class ScomService;
PRDF_DECLARE_SINGLETON(ScomService, theScomService);

/**
 *  @brief Returns a reference to the ScomService singleton
 *
 *  @return Reference to the ScomService
 */
ScomService& getScomService();

/**
 *  @brief ScomService class
 */
class ScomService
{
  public:

    /**
     *  @brief Construct ScomService
     */
    ScomService();

    /**
     *  @brief Destroys ScomService
     */
    ~ScomService();

    /**
     * @brief set the scom accessor to be used
     *
     * @param[in] i_ScomAccessor new scom accessor
     */
    void setScomAccessor(ScomAccessor & i_ScomAccessor);

    /**
     Access the scan com register
     @param i_target Target to access the register
     @param BIT_STRING_CLASS - holds data read or to write
     @param register address
     @param [READ|WRITE]
     @returns [SUCCESS|FAIL]
     @pre bs.Length() must be size of register data to read/write
     @post For read operation, bs is modified to reflect hardware register state
     @note
     */
    virtual uint32_t Access(TARGETING::TargetHandle_t i_target,
                            BIT_STRING_CLASS & bs,
                            uint64_t registerId,
                            MopRegisterAccess::Operation operation) const;

  private:

    // Disable copy constructor / assignment operator
    ScomService(const ScomService& i_right);
    ScomService& operator=(const ScomService& i_right);

    // Scom access to actual HW or Sim
    ScomAccessor * iv_ScomAccessor;
};

/**
    Access Scan comm via the HOM
    @author Doug Gilbert
    @par
    @code
    @endcode
*/
class HomRegisterAccessScom : public MopRegisterAccess
{
public:
  /**
   Constructor
   @param
   @returns
   @pre
   @post
   @see
   @note
   */
  inline HomRegisterAccessScom(TARGETING::TargetHandle_t i_ptargetHandle );
  inline HomRegisterAccessScom(void);

  /*
   Destructor
   */
  //  ~HomRegisterAccessScom();

  /**
   Access the scan com register
   @param BIT_STRING_CLASS - holds data read or to write
   @param register address
   @param [READ|WRITE]
   @returns [SUCCESS|FAIL]
   @pre bs.Length() must be size of register data to read/write
   @post For read operation, bs is modified to reflect hardware register state
   @note
   */
  virtual uint32_t Access(BIT_STRING_CLASS & bs,
                          uint64_t registerId,
                          Operation operation) const;

  /**
   Get the handle used to pass to access (obsolite???)
   @param returnes number of targethandles in TargetHandle list
   @returns list of targethandles
   @pre none
   @post none
   @note  Can this be removed from the framework???
   */
  inline virtual const TARGETING::TargetHandle_t * GetChipIds(int & count) const { count = 0; return NULL;}

  bool operator==(const HomRegisterAccessScom & hrm)
  {
    return (hrm.iv_ptargetHandle == iv_ptargetHandle);
  }

private:  // functions
private:  // Data

  // maybe we should store the functionalUnitPtr instead
 TARGETING::TargetHandle_t  iv_ptargetHandle;

};

struct ScanRingField
{
  uint64_t registerId;
  uint32_t length;
};
/**
    Access Scan ring registers via the HOM
    @author Doug Gilbert
    @par
    @code
    @endcode
*/
class HomRegisterAccessScan : public MopRegisterAccess
{
public:
  /**
   Constructor
   @param
   @returns
   @pre
   @post
   @see
   @note
   */
  HomRegisterAccessScan(TARGETING::TargetHandle_t i_ptargetHandle ,ScanRingField * start, ScanRingField * end);
  inline HomRegisterAccessScan(void);

  /*
   Destructor
   */
  //  ~HomRegisterAccessScan();

  /**
   Access the scan com register
   @param BIT_STRING_CLASS - holds data read or to write
   @param register address
   @param [READ|WRITE]
   @returns [SUCCESS|FAIL]
   @pre bs.Length() must be size of register data to read/write
   @post For read operation, bs is modified to reflect hardware register state
   @note
   */
  virtual uint32_t Access(BIT_STRING_CLASS & bs,
                          uint64_t registerId,
                          Operation operation) const;


  /**
   Get the Id(s) used to pass to access (obsolite???)
   @param returnes number of targetHandle
   @returns list of targetHandles
   @pre none
   @post none
   @note  Can this be removed from the framework???
   */
  inline virtual const TARGETING::TargetHandle_t * GetChipIds(int & count) const { count = 0; return NULL;}

  bool operator==(const HomRegisterAccessScan & hrm)
  {
    return (hrm.iv_punitHandle == iv_punitHandle);
  }

private:  // functions
private:  // Data

  typedef std::vector<ScanRingField> AliasIdList;

  // maybe we should store the functionalUnitPtr instead
  TARGETING::TargetHandle_t iv_punitHandle;

  // list of fields to extract
  AliasIdList iv_aliasIds;

};




inline HomRegisterAccessScom::HomRegisterAccessScom(TARGETING::TargetHandle_t i_ptargetHandle )
: MopRegisterAccess(), iv_ptargetHandle(i_ptargetHandle )
{}

inline HomRegisterAccessScom::HomRegisterAccessScom()
: MopRegisterAccess(), iv_ptargetHandle(NULL)
{}

inline HomRegisterAccessScan::HomRegisterAccessScan()
: MopRegisterAccess(),iv_punitHandle(NULL)
{}

} // End namespace PRDF

#endif /* PRDFHOMREGISTERACCESS_H */
