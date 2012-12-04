/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/prdfMemoryMru.H $               */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2008,2013              */
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

#ifndef prdfMemoryMru_H
#define prdfMemoryMru_H

/** @file  prdfMemoryMru.H
 */

#include <stdint.h>

#ifndef CONTEXT_x86_nfp
    #include <targeting/common/target.H>
#endif

// FIXME: RTC 47288 Will need to wrap this in PRDF namespace once external
//        interfaces are removed/modified.

class PrdfMemoryMru
{
  public:

    /**
     * @brief Used to specify the PrdfMemoryMru type.
     *
     * One requirement for all memory MRUs is that it must be able to be
     * converted into a 32-bit representation of the object. This number is then
     * passed around is different places, one in particular is word 9 of the
     * SRC. Eventually, data will need to be retrieved from the number. Since
     * the structure of each memory MRU may change, bits[0:2] of the 32-bit
     * number is reserved for the version type of the memory MRU. Based on the
     * version a new memory MRU can be constructed.
     *
     * NOTE: The reason MEMMRU_ECLIPZ starts with 3 is because in the original
     *       P6 memory MRU there was a 4-bit field for the version type in which
     *       the value was 6 (for P6). To save as much space as possible the
     *       version field was reduced to 3 bits and the P6 version as changed
     *       to 3. Thus, saving a bit of space without compromising the value of
     *       that field.
     */
    enum PrdfMemMruVersion
    {
        MEMMRU_INVALID = 0, ///< An invalid memory MRU
        MEMMRU_ECLIPZ  = 3, ///< A P6 MC memory MRU
        MEMMRU_APOLLO  = 5, ///< A P7 MC memory MRU
    };

  public:

    /**
     * @brief Default contructor.
     */
    PrdfMemoryMru() : iv_memMruUint32( 0 ) {}

    /**
     * @brief Constructor from 32-bit representation of a memory MRU.
     * @param i_memMruUint32 A 32-bit representation of a memory MRU.
     */
    explicit PrdfMemoryMru( uint32_t i_memMruUint32 ) :
        iv_memMruUint32( i_memMruUint32 )
    {}

    /**
     * @brief Default destructor.
     */
    virtual ~PrdfMemoryMru() {}

    /**
     * @brief  Returns the 32-bit representation of this memory MRU.
     * @return The 32-bit representation of this memory MRU.
     */
    virtual uint32_t toUint32() const
    { return iv_memMruUint32; }

#ifndef CONTEXT_x86_nfp

    /**
     * @brief  Returns a list of targets that are represented by this
     *         memory MRU.
     * @return The number of targets in the callout list  is returned.
     */
    virtual TARGETING::TargetHandleList getCalloutList() const;

#endif

  private:

    /** The 32-bit representation of this memory MRU. */
    uint32_t iv_memMruUint32;

};

#endif /* prdfMemoryMru_H */

