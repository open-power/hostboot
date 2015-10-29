/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/ipl/hwp/p9_pm_set_homer_bar.C $           */
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
/// @file p9_pm_set_homer_bar.C
/// @brief Setup a PBABAR to locate the HOMER region for the OCC complex

// *HWP HWP Owner       : Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Bilicon Patil <bilpatil@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 1
// *HWP Consumed by     : HS
///
///
/// High-level procedure flow:
/// \verbatim
///
///     Address and size of HOMER for the target (chip) is passed based on
///     where the caller has allocated this memory for this target.
///
///     The Base Address and a size mask for the region is passed.  This is
///     used to establish the PBA BAR and mask hardware to set the legal
///     bounds for OCc complex accesses.
///
///     The BAR defines address bits 14:43 in natural bit alignment (eg no
///     shifting)
///
///     The Size (in MB) of the region where region is located.
///         If not a power of two value, the value will be rounded up to the
///         next power of 2 for setting the hardware mask
///
///         If 0 is defined and the BAR is also defined as 0, then the BAR
///         is set (to 0) but no image accessing is done as this is considered
///         a BAR reset condition.
///
///         If 0 is defined and the BAR is NOT 0, an error is returned as this
///         is defining a zero sized, real region.
///
///     Flow (given BAR and Size are ok per the above)
///        Check that passed address is within the 56 bit real address range
///        Check that image address + image size does not extend past the 56 bit
///            boundary
///
///        Call p9_pba_bar_config to set up PBA BAR 0 with the address and
///            size of the HOMER region as passed via calling parameters
///         i_mem_bar and i_mem_mask.
///
///  Procedure Prereq:
///     - HOMER memory region has been allocated.
///
///  CQ Class:  power_management
/// \endverbatim
///
//-------------------------------------------------------------------------------


// ------------------------------------------------------------------------------
// Includes
// ------------------------------------------------------------------------------
#include <fapi2.H>
#include "p9_misc_scom_addresses.H"
#include "p9_pm_set_homer_bar.H"
#include "p9_pm.H"
#include "p9_pm_pba_init.H"
#include "p9_pm_pba_bar_config.H"


#if 0
// ------------------------------------------------------------------------------
// Constant definitions
// ------------------------------------------------------------------------------

enum STOPGPE_IMG_LOC
  {
    STOPGPE_MEMORY  = 0x0,
    STOPGPE_L3      = 0x1,
    STOPGPE_SRAM    = 0x2
  };

// The value here will yield the appropriate nibble for accessing the PowerBus

enum PBA_BARS
  {
    PBA_BAR0    = 0x0,
    PBA_BAR1    = 0x1,
    PBA_BAR2    = 0x2,
    PBA_BAR3    = 0x3
  };

enum PBA_SLAVES
  {
    PBA_SLAVE0    = 0x0,
    PBA_SLAVE1    = 0x1,
    PBA_SLAVE2    = 0x2,
    PBA_SLAVE3    = 0x3
  };
#endif


// ------------------------------------------------------------------------------
// Function definitions
// ------------------------------------------------------------------------------


/// \param[in] i_target     Procesor Chip target
/// \param[in] i_mem_bar    Base address of the region where image is located
/// \param[in] i_mem_size   Size (in MB) of the region where image is located
///                         if not a power of two value, the value will be
///                         rounded up to the next power of 2 for setting the
///                         hardware mask.  The value of 0 is only legal if
///                         i_mem_bar is also 0;  else an error is indicated.
///
fapi2::ReturnCode
p9_pm_set_homer_bar(  const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
		      const uint64_t i_mem_bar,
		      const uint64_t i_mem_size)
{

  fapi2::ReturnCode    l_rc;
#if 0
  uint32_t            l_ecmdRc = 0;
  ecmdDataBufferBase  data(64);

  uint64_t            image_address;
  uint64_t            image_size;
  uint64_t            region_masked_address;

  pba_slvctln_t       ps;                         // PBA Slave

  // Hardcoded use of PBA BAR and Slave
  const uint32_t      pba_bar = PBA_BAR2;
  const uint32_t      pba_bar_slw = PBA_SLW_BAR2;
  const uint32_t      pba_slave = PBA_SLAVE2;

  const uint64_t      slw_pba_cmd_scope = 0x2;    // Set to SYSTEM

  const uint32_t      occ_pba_bar = PBA_BAR0;
  uint64_t            occ_mem_bar =  0x0;
  const uint64_t      occ_mem_size = 0x4;         // in MB
  const uint64_t      occ_pba_cmd_scope = 0x0;    // Set to NODAL


  // -----------------------------------------------------------------
  do
    {
      FAPI2_INF("Entering p9_pm_set_homer_bar ...");

      // Check if this is a BAR reset case.
      if (i_mem_size == 0)
	{
	  if(i_mem_bar != 0)
	    {
	      FAPI2_ERR("HOMER Size is 0 but BAR is non-zero:  0x%16llx", i_mem_bar );
	      const fapi2::Target& CHIP = i_target;
	      const uint32_t&      MEMSIZE = i_mem_size;
	      const uint64_t&      MEMBAR = i_mem_bar;
	      FAPI2_SET_HWP_ERROR(rc, RC_PROCPM_HOMER_BAR_SIZE0_ERROR);
	      break;
	    }
	  else
	    {
	      FAPI2_DBG("Calling pba_bar_config to BAR %x Addr: 0x%16llX  Size: 0x%16llX",
			pba_bar, i_mem_bar, i_mem_size);

	      // Set the PBA BAR for HOMER
	      FAPI2_EXEC_HWP(rc, p8_pba_bar_config, i_target,
			     pba_bar,
			     i_mem_bar,
			     i_mem_size,
			     slw_pba_cmd_scope);

	      // No rc check is made as we're exiting anyway.

	      break;
	    }
	}


      // Check that the image address passed is within the memory region that
      // is also passed.
      //
      // The PBA Mask indicates which bits from 23:43 (1MB grandularity) are
      // enabled to be passed from the OCI addresses.  Inverting this mask
      // indicates which address bits are going to come from the PBA BAR value.
      // The image address (the starting address) must match these post mask bits
      // to be resident in the range.
      //
      // Starting bit number: 64 bit Big Endian
      //                                          12223344
      //                                          60482604
      // region_inverted_mask = i_mem_mask ^ BAR_MASK_LIMIT;  // XOR

      // Set bits 14:22 as these are unconditional address bits
      //region_inverted_mask = region_inverted_mask | BAR_ADDR_UNMASKED;
      //computed_image_address = region_inverted_mask && image_address;
      // Need to AND the address
      //if (computed_image_address != i_mem_bar )
      //{
      //    FAPI2_ERR("SLW image address check failure. ");
      //    FAPI2_SET_HWP_ERROR(rc, RC_PROCPM_POREBAR_IMAGE_ADDR_ERROR);
      //    break;
      //}

      FAPI2_DBG("Calling pba_bar_config to BAR %x Addr: 0x%16llX  Size: 0x%16llX",
		pba_bar, i_mem_bar, i_mem_size);

      // Set the PBA BAR for the SLW region
      FAPI2_EXEC_HWP(rc, p9_pba_bar_config, i_target,
		     pba_bar,
		     i_mem_bar,
		     i_mem_size,
		     slw_pba_cmd_scope);

      if(rc)
	{
	  break;
	}


    }
  while (0);

#endif
  l_rc = fapi2::FAPI2_RC_SUCCESS;
  return l_rc;
}
