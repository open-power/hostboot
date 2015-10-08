/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_adu_constants.H $             */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/// @file p9_adu_constants.H
/// @brief Constant enums to support ADU get/putmem procedures (FAPI)
///
// *HWP HWP Owner: Christina Graves clgraves@us.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 2
// *HWp Consumed by: SBE

#ifndef _P9_ADU_CONSTANTS_H_
#define _P9_ADU_CONSTANTS_H_

//---------------------------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------------------------

extern "C"
{

    //----------------------------------------------------------------------------------------------
    // Constant definitions
    //----------------------------------------------------------------------------------------------

    //if the flag is more than 1 bit there will be a start and end bit for the flag
    //these give the bit position that is expected for the flags
    enum adu_flags
    {
        //cache-inhibited (true = ci, false = dma partial)
        FLAG_CI = 0x80000000ull,
        //utilize ADU HW auto-increment function (true = use autoinc, false = don't use autoinc)
        FLAG_AUTOINC = 0x40000000ull,
        //pick ADU lock (if required) (true = use lock pick, false = don't pick lock)
        FLAG_LOCK_PICK = 0x20000000ull,
        //in the case of a fail with lock held, reset ADU and release lock (true = , false = )
        FLAG_LEAVE_DIRTY = 0x10000000ull,
        //check status only at the end of read/write stream (true = don't do status check, false = do status check after every read/write)
        FLAG_FASTMODE_ADU = 0x8000000ull,
        //collect/set itag with each 8B read/write (true = collect itag, false = don't collect itag) for a write only set if itag data should be 1
        FLAG_ITAG = 0x4000000ull,
        //collect/set ecc with each 8B read/write (true = collect ecc, false = don't collect ecc)
        FLAG_ECC = 0x2000000ull,
        //overwrite the ecc/itag data
        FLAG_OVERWRITE_ECC = 0x1000000ull,
        //transaction size (choice is 1, 2, 4, or 8)
        FLAG_SIZE = 0xFF0000ull,
        //number of ADU lock acquisitions to attempt before giving up or attempting lock pick
        FLAG_LOCK_TRIES = 0xFFFFull
    };

    const uint64_t FLAG_SIZE_SHIFT = 17;

} //extern "C"

#endif //_P9_ADU_CONSTANTS_H_

