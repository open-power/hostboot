/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/prdfHeapBucketSize.H $          */
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

#ifndef PRDFHEAPBUCKETSIZE_H
#define PRDFHEAPBUCKETSIZE_H


//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------
#ifdef __HOSTBOOT_MODULE
  #include <kernel/heapmgr.H>
#endif



#ifdef __HOSTBOOT_MODULE
template <uint32_t bucket>
struct HeapBucketSize
{
    static const size_t value = HeapBucketSize<bucket-1>::value +
                         HeapBucketSize<bucket-2>::value;
};

template <>
struct HeapBucketSize<0>
{
    static const size_t value = HeapManager::BUCKET_SIZE0;
};

template <>
struct HeapBucketSize<1>
{
    static const size_t value = HeapManager::BUCKET_SIZE1;
};

template <typename T, uint32_t S, uint32_t bucket = 0>
struct RoundBucketSize
{
    static const size_t value =
        (sizeof(T) * S > (HeapBucketSize<bucket>::value - sizeof(uint64_t))) ?
            (RoundBucketSize<T,S, bucket+1>::value) :
            ((HeapBucketSize<bucket>::value - sizeof(uint64_t)) / sizeof(T));
};

template <typename T, uint32_t S>
struct RoundBucketSize<T,S,HeapManager::BUCKETS>
{
    static const size_t value = S;
};

#else
template <typename T, uint32_t S>
struct RoundBucketSize
{
    static const size_t value = S;
};
#endif


#endif // define PRDFHEAPBUCKETSIZE_H
