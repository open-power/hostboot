/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/scomtrans.C $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
/**
 *  @file scomtrans.C
 *
 *  @brief Implementation of SCOM operations
 */


// Code up to date for version: p8 1.9/s1 1.3 of p8.chipunit.scominfo

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
#include <errl/errludtarget.H>

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
    uint64_t l_instance = 0;

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
        // EX
        // Mask		:  0x1F00_0000
        // Range 1	:  0x1000_0000 -  0x10FF_FFFF
        //
        //  bits 3:7 correspond to what EX chiplet is targeted.
        //  where 0x10XXXXXX is for EX0
        // 
        // where 0x13XXXXXX is for EX3
        // where 0x14XXXXXX is for EX4
        //  ...
        // where 0x1CXXXXXX is for EX12

        // EX Mask = 0x7F000000 to catch other chiplets.

        // no indirect addresses to worry about*/

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
        
            // MC0 MCS0   = 0x02011800   MCS-0    range 0
            // MC0 MCS1   = 0x02011880   MCS-1    range 0 + remainder
            // MC1 MCS0   = 0x02011900   MCS-2    range 1
            // MC1 MCS0   = 0x02011980   MCS-3    range 1 + remainder
            // IOMC0      = 0x02011A00  -NOT targeting this range..
           
            // MC2 MCS0   = 0x02011C00   MCS-4     range 2
            // MC2 MCS1   = 0x02011C80   MCS-5     range 2 + remainder
            // MC3 MCS0   = 0x02011D00   MCS-6     range 3
            // MC3 MCS1   = 0x02011D80   MCS-7     range 3 + remainder

            
            // SCOM_TRANS_MCS_MASK =         0xFFFFFFFF7FFFFF80


            // Check that we are working with the correct MCS direct address range
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
            // 0x00000000_02011A00      MCS         0-3 # MCS/DMI0 Direct SCOM
            // 0x00000000_02011E00      MCS         4-7 # MCS/DMI4 Direct SCOM
            //                 Address translation from DMI0 (A->E)
            // SCOM_TRANS_MCS_DMI_BASEADDR =     0x0000000002011A00,
            // If the base address passed in is 0x2011A00 - we are dealing with
            // MCS/DMI.  Use the instance to determine which one wanted.  If
            // MCS 4-7 is targeted, translations is required.
            //
            // Also if we have a indirect address then we need to update the
            // same address bits as above whether indirect or not.. for
            // indirect specifically need to update bits 25-26 to get the
            // correct address range.

            // MCS Indirect mask = 0x80000060_FFFFFFFF
            //   0x80000060_02011A3F      MCS      0  # DMI0 Indirect SCOM RX3
            //   0x80000040_02011A3F      MCS      1  # DMI1 Indirect SCOM RX2
            //   0x80000000_02011A3F      MCS      2  # DMI3 Indirect SCOM RX0 
            //   0x80000020_02011A3F      MCS      3  # DMI2 Indirect SCOM RX1
            //
            //   0x80000060_02011E3F      MCS      4  # DMI4 Indirect SCOM RX3
            //   0x80000040_02011E3F      MCS      5  # DMI5 Indirect SCOM RX2
            //   0x80000000_02011E3F      MCS      6  # DMI7 Indirect SCOM RX0
            //   0x80000020_02011E3F      MCS      7  # DMI6 Indirect SCOM RX1
            //
            //   0x80000460_02011A3F      MCS      0  # DMI0 Indirect SCOM TX3
            //   0x80000440_02011A3F      MCS      1  # DMI1 Indirect SCOM TX2
            //   0x80000400_02011A3F      MCS      2  # DMI3 Indirect SCOM TX0
            //   0x80000420_02011A3F      MCS      3  # DMI2 Indirect SCOM TX1
            //
            //   0x80000460_02011E3F      MCS      4  # DMI4 Indirect SCOM TX3
            //   0x80000440_02011E3F      MCS      5  # DMI5 Indirect SCOM TX2
            //   0x80000400_02011E3F      MCS      6  # DMI7 Indirect SCOM TX0
            //   0x80000420_02011E3F      MCS      7  # DMI6 Indirect SCOM TX1
            //
            //  SCOM_TRANS_IND_MCS_BASEADDR =     0x8000006002011A00,


            // check that we are working with a MCS/DMI address range..
            // can be indirect or direct.
            else if (((i_addr & SCOM_TRANS_MCS_MASK) ==
                     SCOM_TRANS_MCS_DMI_BASEADDR) || ((i_addr & SCOM_TRANS_IND_MCS_DMI_MASK) ==
                     SCOM_TRANS_IND_MCS_DMI_BASEADDR))
            {

                // Need to extract what instance of the entity we are at
                l_instance =
                   epath.pathElementOfType(TARGETING::TYPE_MCS).instance;

                // If we are dealing with an indirect SCOM MCS address
                // Need to update the address based on instance
                if ((i_addr & SCOM_TRANS_IND_MCS_DMI_MASK) ==
                     SCOM_TRANS_IND_MCS_DMI_BASEADDR)
                {
                    // based on the instance, update the address
                    // If instance 0 or 4 then no updating required.
                    if (l_instance % 4 != 0)
                    {
                        // zero out the instance bits that need to change
                        i_addr = i_addr & 0xFFFFFF9FFFFFFFFF;

                        // instance 1 or 5  - update instance in the addr
                        if (l_instance % 4 == 1)
                        {
                            i_addr |= 0x4000000000;
                        }
                        // instance 3 or 7
                        else if (l_instance % 4 == 3)
                        {
                            i_addr |= 0x2000000000;
                        }
                        // instance 2 or 6 is 0 so no bits to turn on.
                    }
                }

                // Need to update the address whether we are indirect or not
                // for the MCS/DMI address ranges.
                // need to do this check after above because we modify the base
                // address based on instance and the mask check would then fail
                if (l_instance > 3)
                {
                    // or 0x400 to change 0x2011Axx to 0x2011Exx
                    i_addr = i_addr | 0x400;
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
            // XBUS Direct Address info
            // XBUS mask = 0xFFFFFC00
            // default>physical:sys-0/node-0/proc-0/xbus-0</default>
            //   startAddr   target  
            //  0x04011000   XBUS 0    # XBUS0 Direct SCOM 
            //  0x04011400   XBUS 1    # XBUS1 Direct SCOM 
            //  0x04011C00   XBUS 2    # XBUS2 Direct SCOM
            //  0x04011800   XBUS 3    # XBUS3 Direct SCOM
            //
            // XBUS Indirect Address info
            //  mask = 0x80000000_FFFFFFC0
            //   0x800000000401103F   XBUS  0   # XBUS0 RX0 Indirect SCOM
            //   0x800000000401143F   XBUS  1   # XBUS1 RX1 Indirect SCOM
            //   0x8000000004011C3F   XBUS  2   # XBUS2 RX2 Indirect SCOM
            //   0x800000000401183F   XBUS  3   # XBUS3 RX3 Indirect SCOM
            //
            //   0x800004000401103F   XBUS  0   # XBUS0 TX0 Indirect SCOM
            //   0x800004000401143F   XBUS  1   # XBUS1 TX1 Indirect SCOM
            //   0x8000040004011C3F   XBUS  2   # XBUS2 TX2 Indirect SCOM
            //   0x800004000401183F   XBUS  3   # XBUS3 TX3 Indirect SCOM


            // no differentiation between direct and indirect.. translate the same way
            // Check that we are working with the correct address range
            if ((i_addr & SCOM_TRANS_XBUS_MASK) == SCOM_TRANS_XBUS_BASEADDR )
            {

                // Need to extract what instance of the entity we are at
                l_instance =
                  epath.pathElementOfType(TARGETING::TYPE_XBUS).instance;

                // based on the instance, update the address
                if (l_instance != 0)
                {
                    // zero out the address bits that need to change
                    i_addr = i_addr & 0xFFFFFFFFFFFFF3FF;

                    // range 1 - add 0x400 to the addr
                    if (l_instance == 1)
                    {
                        i_addr += 0x400;
                    }
                    // range 2 - add 0xC00 to the addr
                    else if (l_instance == 2)
                    {
                        i_addr += 0xC00;
                    }
                    // range 3 - add 0x800 to the addr
                    else if (l_instance == 3)
                    {
                        i_addr += 0x800;
                    }

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
        else if (l_type == TARGETING::TYPE_ABUS)
        {
           // ABUS
           // Mask 		: 0xFFFFFC00
           // Range 1	: 0x08010C00 - 0x08010C3F

           // default>physical:sys-0/node-0/proc-0/abus-0</default>
           // ABUS Direct addresses
           // ABUS mask 0x000000FF_FFFFFF80
           // 0x00000000_08010C00   # ABUS0-2 Direct SCOM
           //
           // Abus Indirect Addresses
           // Abus Indirect MASK =   0x80000060FFFFFFFF
           //  0x80000000_08010C3F  ABUS 0   # ABUS0 RX0 Indirect SCOM
           //  0x80000020_08010C3F  ABUS 1   # ABUS1 RX1 Indirect SCOM 
           //  0x80000040_08010C3F  ABUS 2   # ABUS2 RX2 Indirect SCOM
           //
           //  0x80000400_08010C3F  ABUS 0   # ABUS0 TX0 Indirect SCOM
           //  0x80000420_08010C3F  ABUS 1   # ABUS1 TX1 Indirect SCOM 
           //  0x80000440_08010C3F  ABUS 2   # ABUS2 TX2 Indirect SCOM



            // Check that we are working with the correct address range
            // the base address bits 32 to 64 are the same for both
            if ((i_addr & SCOM_TRANS_ABUS_MASK) == SCOM_TRANS_ABUS_BASEADDR )
            {
               // If we have an indirect address.. then need to translate
               if ((i_addr & SCOM_TRANS_INDIRECT_MASK) == SCOM_TRANS_INDIRECT_ADDRESS)
               {
                  
                   // Need to extract what instance of the entity we are at
                   l_instance =
                     epath.pathElementOfType(TARGETING::TYPE_ABUS).instance;


                   // Need to update the upper bits of the indirect scom address.
                   uint64_t temp_instance = l_instance << 37;
                   i_addr = i_addr | temp_instance;

               }
                // get the parent.. 
                l_err = scomfindParentTarget(epath,
                                             TARGETING::TYPE_PROC,
                                             i_target);
            }
            
            else
            {
                // got and error.. bad address.. write an errorlog..
                l_invalidAddr = true;
            }


        }
        else if (l_type == TARGETING::TYPE_MBA)
        {
           // MBA
           // SCOM_TRANS_MBA_MASK =     0xFFFFFFFF7FFFFC00,
           // SCOM_TRANS_MBA_BASEADDR = 0x0000000003010400,
           //
           // SCOM_TRANS_TCM_MBA_MASK =     0xFFFFFFFFFFFFFC00
           // SCOM_TRANS_TCM_MBA_BASEADDR = 0x0000000003010800
           //
           //     In the XML.. the
           //    <default>physical:sys-0/node-0/membuf-10/mbs-0/mba-1</default>
           //
           //    Assuming the MBA we are accessing is under the Centaur
           //    not the processor.. for now.
           //
           // 0x00000000_03010400   MBA 0   # MBA01
           // 0x00000000_03010C00   MBA 1   # MBA23

           // 0x00000000_03010880   MBA 0    # Trace for MBA01
           // 0x00000000_030110C0   MBA 1    # Trace for MBA23 

           // 0x00000000_03011400   MBA 0   # DPHY01 (indirect addressing)
           // 0x00000000_03011800   MBA 1   # DPHY23 (indirect addressing)

           // 0x80000000_0301143f   MBA  0  # DPHY01 (indirect addressing) 
           // 0x80000000_0301183f   MBA  1  # DPHY23 (indirect addressing)

           // 0x80000000_0701143f   MBA 0   # DPHY01 (indirect addressing) 
           // 0x80000000_0701183f   MBA 1   # DPHY23 (indirect addressing)
           //

           // SCOM_TRANS_IND_MBA_MASK =      0x80000000FFFFFFFF,
           // SCOM_TRANS_IND_MBA_BASEADDR =  0x800000000301143f,

           // check to see that the Address is in the correct direct
           // scom MBA address range.
            if ( (i_addr & SCOM_TRANS_MBA_MASK) == SCOM_TRANS_MBA_BASEADDR )
            {

                l_err = scomPerformTranslate(epath,
                                             TARGETING::TYPE_MBA,
                                             TARGETING::TYPE_MEMBUF,
                                             11,
                                             SCOM_TRANS_MBA_MASK,
                                             i_target,
                                             i_addr );
            }

            // New TCM MBA registers for DD2.0
            else if ( (i_addr & SCOM_TRANS_TCM_MBA_MASK) ==
                                SCOM_TRANS_TCM_MBA_BASEADDR )
            {
                l_instance = epath.pathElementOfType(TARGETING::TYPE_MBA).instance;
                i_addr = i_addr + (l_instance * SCOM_TRANS_TCM_MBA_OFFSET);
                // Call to set the target to the parent target type
                l_err = scomfindParentTarget(epath,
                                             TARGETING::TYPE_MEMBUF,
                                             i_target);
            }
            
            // check to see if valid MBA 0 indirect address range
            else if ((i_addr & SCOM_TRANS_IND_MBA_MASK) ==
                     SCOM_TRANS_IND_MBA_BASEADDR)
            {
               // Need to extract what instance of the entity we are
                l_instance =
                  epath.pathElementOfType(TARGETING::TYPE_MBA).instance;

                // If instance is 1 then need to update address
                if (l_instance == 1)
                {
                  // Have address 0301143f need address 0301183f
                  i_addr = i_addr & 0xFFFFFFFFFFFFFBFF;
                  i_addr = i_addr | 0x00000800;
                }

                // Call to set the target to the parent target type
                l_err = scomfindParentTarget(epath,
                                             TARGETING::TYPE_MEMBUF,
                                             i_target);
            }
             else
            {
                // got and error.. bad address.. write an errorlog..
                l_invalidAddr = true;
            }
	}
        else
	{
            // Send an errorlog because we are called with an unsupported type.
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
                                             l_type,
                                             true/*SW Error*/);
             //Add this target to the FFDC
             ERRORLOG::ErrlUserDetailsTarget(i_target,"SCOM Target")
               .addToLog(l_err);
	}
    }

    if (l_invalidAddr)
    {

        TRACFCOMP(g_trac_scom, "scomTranslate-Invalid Address i_addr=0x%X, Type 0x%.8X, HUID 0x%.8X",
                  i_addr, l_type, TARGETING::get_huid(i_target));

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
                                       l_type,
                                       true/*SW Error*/);
       //Add this target to the FFDC
       ERRORLOG::ErrlUserDetailsTarget(i_target,"SCOM Target")
         .addToLog(l_err);
       l_err->collectTrace(SCOM_COMP_NAME,1024);

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
                                uint64_t i_mask,
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
        TRACFCOMP(g_trac_scom,"SCOMPERFORMTRANSLATE Invalid Address.i_addr =0x%X for mask = 0x%X", i_addr, i_mask);

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
                                    o_target->getAttr<TARGETING::ATTR_TYPE>(),
                                    true/*SW Error*/);
        //Add this target to the FFDC
        ERRORLOG::ErrlUserDetailsTarget(o_target,"SCOM Target")
          .addToLog(l_err);

        l_err->collectTrace(SCOM_COMP_NAME,1024);

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
        TRACFCOMP(g_trac_scom, "TRANSLATE..Did not find parent type=0x%X ", i_ptype);
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
                                     o_target->getAttr<TARGETING::ATTR_TYPE>(),
                                     true/*SW Error*/);

        //Add this target to the FFDC
        ERRORLOG::ErrlUserDetailsTarget(o_target,"SCOM Target")
          .addToLog(l_err);

        l_err->collectTrace(SCOM_COMP_NAME,1024);
    }

    return l_err;
}


} // end namespace
