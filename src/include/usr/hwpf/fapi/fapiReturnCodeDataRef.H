/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/fapi/fapiReturnCodeDataRef.H $           */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
// $Id: fapiReturnCodeDataRef.H,v 1.7 2013/10/15 13:13:38 dcrowell Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/hwpf/working/fapi/fapiReturnCodeDataRef.H,v $

/**
 *  @file fapiReturnCodeDataRef.H
 *
 *  @brief Defines the ReturnCodeDataRef class that manages the data associated
 *         with a ReturnCode
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     04/13/2011  Created.
 *                          mjjones     07/05/2011. Removed const from data
 *                          mjjones     07/25/2011  Added support for FFDC
 *                          mjjones     09/22/2100  Added support for Error Info
 */

#ifndef FAPIRETURNCODEDATAREF_H_
#define FAPIRETURNCODEDATAREF_H_

#include <stdint.h>
#include <stddef.h>
#include <fapiErrorInfo.H>

namespace fapi
{

/**
 * @class ReturnCodeDataRef
 *
 * This class manages the data associated with a ReturnCode. A ReturnCode
 * contains a pointer to a ReturnCodeDataRef. When a ReturnCode is copied or
 * assigned, both ReturnCodes point to the same ReturnCodeDataRef (the data is
 * not copied) and the ReturnCodeDataRef reference count is incremented. When a
 * ReturnCode is destructed, the ReturnCodeDataRef reference count is
 * decremented and if zero, the ReturnCodeDataRef is deleted which deletes the
 * the data
 *
 * A ReturnCodeDataRef object is not thread safe, multiple threads must not use
 * the same ReturnCodeDataRef object concurrently.
 */
class ReturnCodeDataRef
{
public:

    /**
     * @brief Constructor
     */
    ReturnCodeDataRef();

    /**
     * @brief Destructor
     */
    virtual ~ReturnCodeDataRef();

    /**
     * @brief Increments the ref count
     */
    void incRefCount();

    /**
     * @brief Decrements the ref count
     *
     * @return bool True if zero reached
     */
    bool decRefCountCheckZero();

    /**
     * @brief Associate heap based PlatData (use-case is platform error log)
     *
     * Any existing PlatData is deleted
     *
     * @param[in] i_pPlatData Pointer to PlatData to associate
     */
    void setPlatData(void * i_pPlatData);

    /**
     * @brief Get a pointer to any PlatData. ReturnCodeDataRef is still
     *        responsible for deletion of the data. The caller must not delete
     *
     * The pointer is only meaningful to platform code.
     *
     * @return void *. Pointer to PlatData. If NULL then no data
     */
    void * getPlatData() const;

    /**
     * @brief Get a pointer to any PlatData and release ownership from
     *        ReturnCodeDataRef. The caller is responsible for deletion.
     *
     * The pointer is only meaningful to platform code.
     *
     * @return void *. Pointer to PlatData. If NULL then no data
     */
    void * releasePlatData();

    /**
     * @brief Get a pointer to any ErrorInfo
     *
     * @return ErrorInfo *. Pointer to ErrorInfo. If NULL then no info
     */
    ErrorInfo * getErrorInfo();

    /**
     * @brief Get a reference to the ErrorInfo. If there is no info then
     *        it is created (empty)
     *
     * @return ErrorInfo &. Reference to ErrorInfo.
     */
    ErrorInfo & getCreateErrorInfo();

#ifdef FAPI_CUSTOM_MALLOC
    /**
     * @brief Overload new operator to use platform-specific allocator
     *
     * @param[in] i_sz  Size of memory to allocate in bytes
     *
     * @return  Pointer to allocated memory
     */
    static void * operator new(size_t i_sz);

    /**
     * @brief Overload delete operator to use platform-specific deallocator
     *
     * @param[in] i_ptr Pointer to memory previously allocated with new
     */
    static void operator delete(void * i_ptr);
#endif

private:

    /**
     * @brief Delete any associated PlatData. Implemented by platform code
     *        because only platform code knows the type of the data.
     */
    void deletePlatData();

    // Copy constructor and assignment operator disabled
    ReturnCodeDataRef(const ReturnCodeDataRef & i_right);
    ReturnCodeDataRef & operator=(const ReturnCodeDataRef & i_right);

    // The reference count (how many ReturnCodes are pointing to this object)
    uint32_t iv_refCount;

    // Pointer to associated PlatData
    void * iv_pPlatData;

    // Pointer to HWP Error Information 
    ErrorInfo * iv_pErrorInfo;
};

}

#endif // FAPIRETURNCODEDATAREF_H_
