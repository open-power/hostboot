/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/xscom/piberror.H $                            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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

#ifndef __PIB_ERROR_H
#define __PIB_ERROR_H


namespace PIB
{

    /**
     * @brief Enumerations for the each PIB error possbility
     */
    enum
    {
        PIB_NO_ERROR          = 0,//0x00000000,
        PIB_RESOURCE_OCCUPIED = 1,//0x00000001,
        PIB_CHIPLET_OFFLINE   = 2,//0x00000010,
        PIB_PARTIAL_GOOD      = 3,//0x00000011,
        PIB_INVALID_ADDRESS   = 4,//0x00000100,
        PIB_CLOCK_ERROR       = 5,//0x00000101,
        PIB_PARITY_ERROR      = 6,//0x00000110,
        PIB_TIMEOUT           = 7,//0x00000111,
    };


/**
 * @brief Add callouts to an errorlog based on the type of PIB error passed in
 *        could be a hardware or procedure callout
 *
 * @param[in]  i_target        Operation target
 * @param[in]  i_pibErrStatus  Error Status bits retrieved
 * @param[in/out] io_errl      Originating errorlog that we will add Fru
 *                             Callouts to.
 * @return none
 */
void addFruCallouts(TARGETING::Target* i_target,
                    uint32_t  i_pibErrStatus,
                    errlHndl_t& io_errl);


}

#endif
