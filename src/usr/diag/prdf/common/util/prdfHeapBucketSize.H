/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/prdfHeapBucketSize.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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

#ifndef PRDFHEAPBUCKETSIZE_H
#define PRDFHEAPBUCKETSIZE_H

namespace PRDF
{
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

} //End namespace PRDF
#endif // define PRDFHEAPBUCKETSIZE_H
