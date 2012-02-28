//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/scom/scomtrans.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
/**
 *  @file scomtrans.C
 *
 *  @brief Implementation of SCOM operations
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <assert.h>
#include <devicefw/driverif.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include "scom.H"
#include "scomtrans.H"
#include <scom/scomreasoncodes.H>

// Trace definition
extern trace_desc_t* g_trac_scom;

namespace SCOM
{


DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::SCOM,
                      TARGETING::TYPE_EX,
                      scomTranslate);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::SCOM,
                      TARGETING::TYPE_MBS,
                      scomTranslate);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::SCOM,
                      TARGETING::TYPE_MBA,
                      scomTranslate);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::SCOM,
                      TARGETING::TYPE_MCS,
                      scomTranslate);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::SCOM,
                      TARGETING::TYPE_XBUS,
                      scomTranslate);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::SCOM,
                      TARGETING::TYPE_ABUS,
                      scomTranslate);



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
errlHndl_t scomTranslate(DeviceFW::OperationType i_opType,
                         TARGETING::Target* i_target,
                         void* io_buffer,
                         size_t& io_buflen,
                         int64_t i_accessType,
                         va_list i_args)

{
    errlHndl_t l_err = NULL;

    bool l_invalidAddr = false;

    uint64_t i_addr = va_arg(i_args,uint64_t);

    // Get the attribute type.
    TARGETING::TYPE l_type = i_target->getAttr<TARGETING::ATTR_TYPE>();

    // get the specific entry to determine the address. 
    TARGETING::EntityPath epath;

    if (i_target->tryGetAttr<TARGETING::ATTR_PHYS_PATH>(epath))
    {
        if (l_type == TARGETING::TYPE_EX)
        {
 
        // Below are the assumptions used for the EX translate
        /*EX
         Mask		:  0x1F00_0000
         Range 1	:  0x1000_0000 -  0x10FF_FFFF
         ...
         ...
         bits 3:7 correspond to what EX chiplet is targeted.
         where 0x10XXXXXX is for EX0
         ...
         where 0x13XXXXXX is for EX3
         where 0x14XXXXXX is for EX4
         ...
         where 0x1CXXXXXX is for EX12


         original mask = 0x000000001F000000
         change that to be 0x7F000000 to catch other chiplets.*/

            // check to see that the Address is in the correct range
            if ((i_addr & SCOM_TRANS_EX_MASK) ==  SCOM_TRANS_EX_BASEADDR)
            {
                // Call the function that performs the translate
	        l_err = scomPerformTranslate(epath,
                                             TARGETING::TYPE_EX,
                                             TARGETING::TYPE_PROC,
                                             24,
                                             SCOM_TRANS_EX_MASK,
                                             i_target,
                                             i_addr );
            }
            else
            {
	        // set invalid addr to true.. and create errorlog below.
                l_invalidAddr = true;
            }
        }
        else if (l_type == TARGETING::TYPE_MCS)
        {
        /* ring  6 = MCL
                     MC0 MCS0   = 0x02011800   MCS-0    range 0
                     MC0 MCS1   = 0x02011880   MCS-1    range 0 + remainder
                     MC1 MCS0   = 0x02011900   MCS-2    range 1
                     MC1 MCS0   = 0x02011980   MCS-3    range 1 + remainder
                     IOMC0      = 0x02011A00  -NOT targeting this range..
           ring  7 = MCR
                     MC2 MCS0   = 0x02011C00   MCS-4     range 2
                     MC2 MCS1   = 0x02011C80   MCS-5     range 2 + remainder
                     MC3 MCS0   = 0x02011D00   MCS-6     range 3
                     MC3 MCS1   = 0x02011D80   MCS-7     range 3 + remainder

            original mask = 0x0000000002011D80
            Need the mask to be   0x7FFFFF80*/


            uint64_t l_instance;

            // Check that we are working with the correct address range
            if ((i_addr & SCOM_TRANS_MCS_MASK) == SCOM_TRANS_MCS_BASEADDR )
            {

                // Need to extract what instance of the entity we are at
                l_instance =
                   epath.pathElementOfType(TARGETING::TYPE_MCS).instance;

                // based on the instance, update the address

                // range 1 - add 0x100 to the addr
                if( (l_instance / 2) == 1)
                {
                    i_addr += 0x100;
                }
                // range 2 - add 0x400 to the addr
                else if( (l_instance / 2) == 2)
                {
                    i_addr += 0x400;
                }
                // range 3 - add 0x500 to the addr
                else if( (l_instance / 2) == 3)
                {
                    i_addr += 0x500;
                }

                // add 0x80 if the instance%2 is nonzero.
                if (l_instance % 2)
                {
                    i_addr += 0x80;
                }

                // Call to set the target to the parent target type
                l_err = scomfindParentTarget(epath,
                                             TARGETING::TYPE_PROC,
                                             i_target);
            }
            else
            {
                 l_invalidAddr = true;
            }
        }
        else if (l_type == TARGETING::TYPE_XBUS)
        {
          //*** temporarily put an error log indicating not supported until we
          // have info from the hardware team

            TRACFCOMP(g_trac_scom, "SCOM_TRANSLATE-unsupported target type=0x%X", l_type);

            /*@
             * @errortype
             * @moduleid     SCOM::SCOM_TRANSLATE
             * @reasoncode   SCOM::SCOM_TRANS_UNSUPPORTED_XBUS
             * @userdata1    Address
             * @userdata2    Target Type that failed
             * @devdesc      Scom Translate not supported for this type
             */
             l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                             SCOM_TRANSLATE,
                                             SCOM_TRANS_UNSUPPORTED_XBUS,
                                             i_addr,
                                             l_type);

        }
        else if (l_type == TARGETING::TYPE_ABUS)
        {
          //*** temporarily put an error log indicating not supported until we have info
          // from the hardware team
            TRACFCOMP(g_trac_scom, "SCOM_TRANSLATE-unsupported target type=0x%X", l_type);

            /*@
             * @errortype
             * @moduleid     SCOM::SCOM_TRANSLATE
             * @reasoncode   SCOM::SCOM_TRANS_UNSUPPORTED_ABUS
             * @userdata1    Address
             * @userdata2    Target Type that failed
             * @devdesc      Scom Translate not supported for this type
             */
             l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                             SCOM_TRANSLATE,
                                             SCOM_TRANS_UNSUPPORTED_ABUS,
                                             i_addr,
                                             l_type);


        }
        else if (l_type == TARGETING::TYPE_MBS)
        {
           /*
            MBS
            Mask 		: NA
            Range 1	: 0x02010000 - 0x0201FFFF

            default>physical:sys-0/node-0/membuf-10/mbs-0</default>

            */
            // NO address shifting required.. no mask..
            // just get parent.
            l_err = scomfindParentTarget(epath,
                                         TARGETING::TYPE_MEMBUF,
                                         i_target);

        }
        else if (l_type == TARGETING::TYPE_MBA)
        {
            /*
               MBA
               Mask 		: 0x03010800
               Range	1	: 0x03010400 - 0301043F  # MBA01
               Range	2	: 0x03010600 - 030106FF  # MBA01 MCBIST
               Range	4	: 0x03010C00 - 03010C3F  # MBA23
               Range	5	: 0x03010E00 - 03010EFF  # MBA23 MCBIST

               Original mask from hdw team is: 03010800
               The mask needs to be 0x7FFFF800 in order make sure we
               don't have any other valid address bits on for another
               chiplet.

               bits 20 correspond to what MBA chiplet is targeted.
               where 0x03010000 is for MBA01
               where 0x03010800 is for MBA23

               In the XML.. the
              <default>physical:sys-0/node-0/membuf-10/mbs-0/mba-1</default>

               Assuming the MBA we are accessing is under the Centaur
               not the processor.. for now.
               */
            // check to see that the Address is in the correct range
            if ((i_addr & SCOM_TRANS_MBA_MASK) == SCOM_TRANS_MBA_BASEADDR)
            {

                l_err = scomPerformTranslate(epath,
                                             TARGETING::TYPE_MBA,
                                             TARGETING::TYPE_MEMBUF,
                                             11,
                                             SCOM_TRANS_MBA_MASK,
                                             i_target,
                                             i_addr );
            }
            else
            {
                // got and error.. bad address.. write an errorlog..
                l_invalidAddr = true;
            }
	}
        else
	{
            //*** temporarily put an error log indicating not supported until we have info
            // from the hardware team
            TRACFCOMP(g_trac_scom, "SCOM_TRANSLATE.. Invalid target type=0x%X", l_type);

            /*@
             * @errortype
             * @moduleid     SCOM::SCOM_TRANSLATE
             * @reasoncode   SCOM::SCOM_TRANS_INVALID_TYPE
             * @userdata1    Address
             * @userdata2    Target Type that failed
             * @devdesc      Scom Translate not supported for this type
             */
             l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                             SCOM_TRANSLATE,
                                             SCOM_TRANS_INVALID_TYPE,
                                             i_addr,
                                             l_type);


	}
    }

    if (l_invalidAddr)
    {

        TRACFCOMP(g_trac_scom, "scomTranslate-Invalid Address i_addr=0x%X", i_addr);

       /*@
       * @errortype
       * @moduleid     SCOM::SCOM_TRANSLATE
       * @reasoncode   SCOM::SCOM_INVALID_ADDR
       * @userdata1    Address
       * @userdata2    Unit type that failed
       * @devdesc      Invalid address for that unit
       */
       l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       SCOM_TRANSLATE,
                                       SCOM_INVALID_ADDR,
                                       i_addr,
                                       l_type);
       l_err->collectTrace("SCOM",1024);

    }

    if (l_err == NULL)
    {

       // call the routine that will do the indirect scom
       // and then call the correct device driver.
       l_err = SCOM::checkIndirectAndDoScom(i_opType,
                                            i_target,
                                            io_buffer,
                                            io_buflen,
                                            i_accessType,
                                            i_addr);
    }
    return l_err;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
errlHndl_t scomPerformTranslate(TARGETING::EntityPath i_epath,
                                TARGETING::TYPE i_ctype,
                                TARGETING::TYPE i_ptype,
                                int i_shift,
                                int i_mask,
                                TARGETING::Target * &o_target,
                                uint64_t &i_addr )
{

    errlHndl_t l_err = NULL;

    uint64_t l_instance;

    // Need to extract what instance of the entity we are at we are
    // for this target.
    l_instance = i_epath.pathElementOfType(i_ctype).instance;

    // shift the instance variable over specificed number of
    // bits with the chiplet area
    l_instance = l_instance << i_shift;

    // Check the address against the mask
    if (i_addr & i_mask)
    {
       // add the instance of this target to the address
       i_addr = i_addr | l_instance;
    }
    else
    {
        /*@
         * @errortype
         * @moduleid     SCOM::SCOM_PERFORM_TRANSLATE
         * @reasoncode   SCOM::SCOM_INVALID_ADDR
         * @userdata1    Address
         * @userdata2    Unit type that failed
         * @devdesc      Invalid Address for the mask passed in.
         */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        SCOM_PERFORM_TRANSLATE,
                                        SCOM_INVALID_ADDR,
                                        i_addr,
                                        o_target->getAttr<TARGETING::ATTR_TYPE>());

        l_err->collectTrace("SCOM",1024);

        TRACFCOMP(g_trac_scom,"SCOMPERFORMTRANSLATE Invalid Address.i_addr =0x%X for mask = 0x%X", i_addr, i_mask);

        return (l_err);
    }


    l_err = scomfindParentTarget(i_epath,
                                 i_ptype,
                                 o_target);

    return l_err;

}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
errlHndl_t scomfindParentTarget( TARGETING::EntityPath i_epath,
                                 TARGETING::TYPE i_ptype,
                                 TARGETING::Target * &o_target)
{

    errlHndl_t l_err = NULL;

    bool foundParent = false;

    // This routine passes in a given target.. the goal is to find its parent
    // target that matches the passed in parent type.

    // This loop takes the last item off the entity path and
    // checks to see if it matches the parent type.. If it does
    // we exit.. it continues to loop until it either finds
    // a match, or runs out of elements. 
    do
    {
       // remove the last entry from the entity path.. 
        i_epath.removeLast();

        int lastEntry = i_epath.size() - 1;

        // if the type equals the type passed in. then create the target
        if (i_epath[lastEntry].type == i_ptype)
        {
             // return the target to be the parent type.
             o_target = TARGETING::targetService().toTarget(i_epath);

             foundParent = true;

             break;
        }
    }
    while (i_epath.size() != 0);

    if (!foundParent)
    {
        // got and error.. bad address.. write an errorlog..
        /*@
         * @errortype
         * @moduleid     SCOM::SCOM_PERFORM_TRANSLATE
         * @reasoncode   SCOM::SCOM_NO_MATCHING_PARENT
         * @userdata1    Parent type requested
         * @userdata2    Unit type that failed
         * @devdesc      Did not find parent type requested
         */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                     SCOM_FIND_PARENT_TARGET,
                                     SCOM_NO_MATCHING_PARENT,
                                     i_ptype,
                                     o_target->getAttr<TARGETING::ATTR_TYPE>());

        l_err->collectTrace("SCOM",1024);

        // Need to write and errorlog and return..
        TRACFCOMP(g_trac_scom, "TRANSLATE..Did not find parent type=0x%X ", i_ptype);
    }

    return l_err;
}


} // end namespace
