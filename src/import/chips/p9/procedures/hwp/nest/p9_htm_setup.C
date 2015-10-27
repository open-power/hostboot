/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_htm_setup.C $                 */
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
///----------------------------------------------------------------------------
/// @file  p9_htm_setup.C
///
/// @brief Perform p9_htm_setup on a processor chip
///
/// The purpose of this procedure is to setup and start HTM on a processor
/// chip.
/// Some start/setup attributes are used as part of the setup process.
///
///----------------------------------------------------------------------------
/// *HWP HWP Owner   : Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner    : Thi Tran <thi@us.ibm.com>
/// *HWP Team        : Nest
/// *HWP Level       : 1
/// *HWP Consumed by : HB
///----------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_htm_setup.H>
#include <p9_misc_scom_addresses.H>
#include <p9_quad_scom_addresses.H>

extern "C" {


///----------------------------------------------------------------------------
/// Function definitions
///----------------------------------------------------------------------------

///
/// @brief Read the HTM BAR address and size and assign the
///        HTM trace output memory address accordingly.
///
/// @param[in] i_target            Reference to Processor Chip target
/// @param[in] i_htmModeRegAddr    The base HTM Mode Register address
/// @param[out] o_scomData         HTM_MEM reg data to program the
///                                mem addr/size bits.  Other bits
///                                are preserved.
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode setMemBaseSize(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const uint64_t i_htmModeRegAddr,
        fapi2::buffer<uint64_t>& o_scomData)
    {
        FAPI_INF("setupHTMGeneric");
        fapi2::ReturnCode l_rc;

        uint64_t   l_memBaseAddr[NUM_OF_HTM_REGIONS] = { 0 };
        uint64_t   l_memBaseSize[NUM_OF_HTM_REGIONS] = { 0 };
        htm_size_t l_htmSize[NUM_OF_HTM_REGIONS] = { HTM_512M_OR_16M };
        bool       l_smallMemSize[NUM_OF_HTM_REGIONS] = { true };

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_HTM_BAR_BASE_ADDR, i_target,
                               l_memBaseAddr),
                 "setMemBaseSize: Error getting ATTR_PROC_HTM_BAR_BASE_ADDR, "
                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_HTM_BAR_SIZES, i_target,
                               l_memBaseSize),
                 "setMemBaseSize: Error getting ATTR_PROC_HTM_BAR_SIZES, "
                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);

        // Determine if mem size should be small or large
        for (uint8_t ii = 0; ii < NUM_OF_HTM_REGIONS; ii++)
        {
            switch (l_memBaseSize[ii])
            {
                case fapi2::ENUM_ATTR_PROC_HTM_BAR_SIZES_16_MB:
                case fapi2::ENUM_ATTR_PROC_HTM_BAR_SIZES_512_MB:
                    l_htmSize[ii] = HTM_512M_OR_16M;
                    break;

                case fapi2::ENUM_ATTR_PROC_HTM_BAR_SIZES_32_MB:
                case fapi2::ENUM_ATTR_PROC_HTM_BAR_SIZES_1_GB:
                    l_htmSize[ii] = HTM_1G_OR_32M;
                    break;

                case fapi2::ENUM_ATTR_PROC_HTM_BAR_SIZES_64_MB:
                case fapi2::ENUM_ATTR_PROC_HTM_BAR_SIZES_2_GB:
                    l_htmSize[ii] = HTM_2G_OR_64M;
                    break;

                case fapi2::ENUM_ATTR_PROC_HTM_BAR_SIZES_128_MB:
                case fapi2::ENUM_ATTR_PROC_HTM_BAR_SIZES_4_GB:
                    l_htmSize[ii] = HTM_4G_OR_128M;
                    break;

                case fapi2::ENUM_ATTR_PROC_HTM_BAR_SIZES_256_MB:
                case fapi2::ENUM_ATTR_PROC_HTM_BAR_SIZES_8_GB:
                    l_htmSize[ii] = HTM_8G_OR_256M;
                    break;

                case fapi2::ENUM_ATTR_PROC_HTM_BAR_SIZES_16_GB:
                    l_htmSize[ii] = HTM_16G_OR_512M;
                    break;

                case fapi2::ENUM_ATTR_PROC_HTM_BAR_SIZES_32_GB:
                    l_htmSize[ii] = HTM_32G_OR_1G;
                    break;

                case fapi2::ENUM_ATTR_PROC_HTM_BAR_SIZES_64_GB:
                    l_htmSize[ii] = HTM_64G_OR_2G;
                    break;

                case fapi2::ENUM_ATTR_PROC_HTM_BAR_SIZES_128_GB:
                    l_htmSize[ii] = HTM_128G_OR_4G;
                    break;

                case fapi2::ENUM_ATTR_PROC_HTM_BAR_SIZES_256_GB:
                    l_htmSize[ii] = HTM_256G_OR_8G;
                    break;

                default:
                    FAPI_ASSERT(false,
                                fapi2::HTM_SETUP_PROC_BAR_SIZE()
                                .set_PROC_BAR_SIZE(l_memBaseSize[ii]),
                                "setMemBaseSize: Invalid proc BAR size value: "
                                "0x%016llX", l_memBaseSize[ii]);
                    break;
            }

            // If memsize >= 512MB, set small memory size to false
            if (l_memBaseSize[ii] >= fapi2::ENUM_ATTR_PROC_HTM_BAR_SIZES_512_MB)
            {
                l_smallMemSize[ii] = false;
            }
        }

        // Assign HTM trace base address/size
        //   PU_HTM0_HTM_MODE --> HTM region 0
        //   PU_HTM1_HTM_MODE --> HTM region 1
        //
        // TODO: How to assign for Core HTM traces?

        if (i_htmModeRegAddr == PU_HTM0_HTM_MODE)
        {
            // Right shift (24) PROC HTM Bar Base addr in order to fit
            // into bits 8:39 (i.e. drop 24 bits)
            o_scomData.insertFromRight<HTM_MEM_TRC_MEM_BASE_ADDR,
                                       HTM_MEM_TRC_MEM_BASE_ADDR_LEN>
                                       (l_memBaseAddr[0] >> 24);
            o_scomData.insertFromRight<HTM_MEM_TRC_MEM_SIZE,
                                       HTM_MEM_TRC_MEM_SIZE_LEN>
                                       (l_htmSize[0]);

            if (l_smallMemSize[0] == true)
            {
                o_scomData.setBit<HTM_MEM_TRC_MEM_SIZE_SMALL>();
            }
            else
            {
                o_scomData.clearBit<HTM_MEM_TRC_MEM_SIZE_SMALL>();
            }
        }
        else if (i_htmModeRegAddr == PU_HTM1_HTM_MODE)
        {
            // Right shift (24) PROC HTM Bar Base addr in order to fit
            // into bits 8:39 (i.e. drop 24 bits)
            o_scomData.insertFromRight<HTM_MEM_TRC_MEM_BASE_ADDR,
                                       HTM_MEM_TRC_MEM_BASE_ADDR_LEN>
                                       (l_memBaseAddr[1] >> 24);

            o_scomData.insertFromRight<HTM_MEM_TRC_MEM_SIZE,
                                       HTM_MEM_TRC_MEM_SIZE_LEN>
                                       (l_htmSize[1]);

            if (l_smallMemSize[1] == true)
            {
                o_scomData.setBit<HTM_MEM_TRC_MEM_SIZE_SMALL>();
            }
            else
            {
                o_scomData.clearBit<HTM_MEM_TRC_MEM_SIZE_SMALL>();
            }
        }
        else
        {
            // TODO: Need to setup CORE base addresses and mem sizes
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

///
/// @brief Common registers to setup for all HTM trace types.
///        The registers are: HTM_MEM, HTM_CTRL
///
/// @param[in] i_target            Reference to Processor Chip target
/// @param[in] i_htmModeRegAddr    The base HTM Mode Register address
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
    // TODO:
    // See review comments in: http://gfw160.aus.stglabs.ibm.com:8080/gerrit/#/c/21527/
    // Need to templating for different targets (proc for NHTM, Core for CHTM
    fapi2::ReturnCode setupHTMGeneric(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const uint64_t i_htmModeRegAddr)
    {
        FAPI_INF("setupHTMGeneric");
        fapi2::ReturnCode l_rc;
        fapi2::buffer<uint64_t> l_scomData;
        uint8_t l_attrValue_uint8 = 0;

        // First, make sure the HTM status is in the correct state
        FAPI_TRY(fapi2::getScom(i_target, i_htmModeRegAddr + HTM_STAT,
                                l_scomData),
                 "setupHTMGeneric: getScom returns error: Addr 0x%016llX, "
                 "l_rc 0x%.8X", i_htmModeRegAddr + HTM_STAT,
                 (uint64_t)fapi2::current_err);

        // HTM must be in "Complete", "Repair", or "Blank" state
        FAPI_ASSERT( (l_scomData == 0) ||
                     (l_scomData & (HTM_STAT_COMPLETE | HTM_STAT_REPAIR)),
                     fapi2::PROC_HTM_CTRL_BAD_STATE()
                     .set_HTM_STATUS_REG(l_scomData)
                     .set_TARGET(i_target),
                     "setupHTMGeneric: Can not setup HTM with current HTM state "
                     "0x%016llX", l_scomData);

        // ---------------- Setup HTM_MEM reg -----------------/
        l_scomData = 0;

        // Note: MEM_ALLOC must switch from 0->1 for this setup to complete

        // Set MEM_SCOPE
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MEM_SCOPE, i_target,
                               l_attrValue_uint8),
                 "setupHTMGeneric: Error getting ATTR_HTMSC_MEM_SCOPE, "
                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
        l_scomData.insertFromRight<HTM_MEM_TRC_MEM_SCOPE,
                                   HTM_MEM_TRC_MEM_SCOPE_LEN>
                                   (l_attrValue_uint8);

        // Set MEM_PRIORITY
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MEM_PRIORITY, i_target,
                               l_attrValue_uint8),
                 "setupHTMGeneric: Error getting ATTR_HTMSC_MEM_PRIORITY, "
                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);

        if (l_attrValue_uint8 == fapi2::ENUM_ATTR_HTMSC_MEM_PRIORITY_LOW)
        {
            l_scomData.clearBit<HTM_MEM_TRC_MEM_PRIORITY>(); // LOW
        }
        else
        {
            l_scomData.setBit<HTM_MEM_TRC_MEM_PRIORITY>(); // HIGH
        }

        // Set MEM_BASE, MEM_SIZE, and MEM_SIZE_SMALL
        FAPI_TRY(setMemBaseSize(i_target, i_htmModeRegAddr, l_scomData),
                 "setupHTMGeneric: setMemBaseSize() returns an error, "
                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);

        // Display HTM_MEM value to write to HW
        FAPI_INF("setupHTMGeneric: HTM_MEM reg setup: 0x%016llX", l_scomData);

        // Write config data into HTM_MEM
        FAPI_TRY(fapi2::putScom(i_target, i_htmModeRegAddr + HTM_MEM,
                                l_scomData),
                 "setupHTMGeneric: putScom returns error (1): "
                 "Addr 0x%016llX, l_rc 0x%.8X",
                 i_htmModeRegAddr + HTM_MEM,
                 (uint64_t)fapi2::current_err);

        // Set HTM_MEM configured bit (transition from 0 --> 1)
        l_scomData.setBit<HTM_MEM_TRC_MEM_ALLOC>();
        FAPI_TRY(fapi2::putScom(i_target, i_htmModeRegAddr + HTM_MEM,
                                l_scomData),
                 "setupHTMGeneric: putScom returns error (2): "
                 "Addr 0x%016llX, l_rc 0x%.8X",
                 i_htmModeRegAddr + HTM_MEM,
                 (uint64_t)fapi2::current_err);


        // ---------------- Setup HTM_CTRL reg -----------------/
        l_scomData = 0;

        // Set CTRL_TRIG
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_CTRL_TRIG, i_target,
                               l_attrValue_uint8),
                 "setupHTMGeneric: Error getting ATTR_HTMSC_CTRL_TRIG, "
                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
        l_scomData.insertFromRight<HTM_CTRL_TRIG_CTRL,
                                   HTM_CTRL_TRIG_CTRL_LEN>(l_attrValue_uint8);

        // Set CTRL_MARK
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_CTRL_MARK, i_target,
                               l_attrValue_uint8),
                 "setupHTMGeneric: Error getting ATTR_HTMSC_CTRL_MARK, "
                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
        l_scomData.insertFromRight<HTM_CTRL_MARKER_CTRL,
                                   HTM_CTRL_MARKER_CTRL_LEN>(l_attrValue_uint8);

        // Set CTRL_DBG0_STOP
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_CTRL_DBG0_STOP, i_target,
                               l_attrValue_uint8),
                 "setupHTMGeneric: Error getting ATTR_HTMSC_CTRL_DBG0_STOP, "
                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);

        if (l_attrValue_uint8 == fapi2::ENUM_ATTR_HTMSC_CTRL_DBG0_STOP_DISABLE)
        {
            l_scomData.clearBit<HTM_CTRL_STOP_ON_DBG_TRIG0>();
        }
        else
        {
            l_scomData.setBit<HTM_CTRL_STOP_ON_DBG_TRIG0>();
        }

        // Set CTRL_DBG1_STOP
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_CTRL_DBG1_STOP, i_target,
                               l_attrValue_uint8),
                 "setupHTMGeneric: Error getting ATTR_HTMSC_CTRL_DBG1_STOP, "
                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);

        if (l_attrValue_uint8 == fapi2::ENUM_ATTR_HTMSC_CTRL_DBG1_STOP_DISABLE)
        {
            l_scomData.clearBit<HTM_CTRL_STOP_ON_DBG_TRIG1>();
        }
        else
        {
            l_scomData.setBit<HTM_CTRL_STOP_ON_DBG_TRIG1>();
        }

        // Set CTRL_RUN_STOP
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_CTRL_RUN_STOP, i_target,
                               l_attrValue_uint8),
                 "setupHTMGeneric: Error getting ATTR_HTMSC_CTRL_RUN_STOP, "
                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);

        if (l_attrValue_uint8 == fapi2::ENUM_ATTR_HTMSC_CTRL_RUN_STOP_DISABLE)
        {
            l_scomData.clearBit<HTM_CTRL_TRC_RUN_TRIG_ACTION>();
        }
        else
        {
            l_scomData.setBit<HTM_CTRL_TRC_RUN_TRIG_ACTION>();
        }

        // Set CTRL_OTHER_DBG0_STOP
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_CTRL_OTHER_DBG0_STOP, i_target,
                               l_attrValue_uint8),
                 "setupHTMGeneric: Error getting ATTR_HTMSC_CTRL_OTHER_DBG0_STOP, "
                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);

        if (l_attrValue_uint8 == fapi2::ENUM_ATTR_HTMSC_CTRL_OTHER_DBG0_STOP_DISABLE)
        {
            l_scomData.clearBit<HTM_CTRL_STOP_ON_OTHER_DBG_TRIG0>();
        }
        else
        {
            l_scomData.setBit<HTM_CTRL_STOP_ON_OTHER_DBG_TRIG0>();
        }

        // Set CTRL_XSTOP_STOP
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_CTRL_XSTOP_STOP, i_target,
                               l_attrValue_uint8),
                 "setupHTMGeneric: Error getting ATTR_HTMSC_CTRL_XSTOP_STOP, "
                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);

        if (l_attrValue_uint8 == fapi2::ENUM_ATTR_HTMSC_CTRL_XSTOP_STOP_DISABLE)
        {
            l_scomData.clearBit<HTM_CTRL_STOP_ON_CHIPLET_XSTOP>();
        }
        else
        {
            l_scomData.setBit<HTM_CTRL_STOP_ON_CHIPLET_XSTOP>();
        }

        // Display HTM_CTRL reg setup value
        FAPI_INF("setupHTMGeneric: HTM_CTRL reg setup: 0x%016llX", l_scomData);

        // Write data to HTM_CTRL
        FAPI_TRY(fapi2::putScom(i_target, i_htmModeRegAddr + HTM_CTRL,
                                l_scomData),
                 "setupHTMGeneric:: putScom returns error: "
                 "Addr 0x%016llX, l_rc 0x%.8X",
                 i_htmModeRegAddr + HTM_CTRL,
                 (uint64_t)fapi2::current_err);

    fapi_try_exit:
        return fapi2::current_err;
    }

///
/// @brief Specific registers to setup for Nest HTM FABRIC.
///        The registers are: NHTM_TTYPE_FILT, NHTM_FILT, and HTM_MODE
///
/// @param[in] i_target             Reference to Processor Chip target
/// @param[in] i_htmModeRegAddr    The base HTM Mode Register address
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode setupHtmFabric(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const uint64_t i_htmModeRegAddr)

    {
        FAPI_INF("setupHtmFabric");
        fapi2::ReturnCode l_rc;
        fapi2::buffer<uint64_t> l_scomData;
        uint8_t l_attrValue_uint8 = 0;
        uint32_t l_attrValue_uint32 = 0;


        // ---------- Setup NHTM_TTYPE_FILT reg ------------
        l_scomData = 0;

        // Set TTYPEFILT_PAT
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_TTYPEFILT_PAT, i_target,
                               l_attrValue_uint8),
                 "setupHtmFabric: Error getting ATTR_HTMSC_TTYPEFILT_PAT, "
                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
        l_scomData.insertFromRight<NHTM_TTYPE_FILT_TTYPE_PATTERN,
                                   NHTM_TTYPE_FILT_TTYPE_PATTERN_LEN>
                                   (l_attrValue_uint8);

        // Set TSIZEFILT_PAT
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_TSIZEFILT_PAT, i_target,
                               l_attrValue_uint8),
                 "setupHtmFabric: Error getting ATTR_HTMSC_TSIZEFILT_PAT, "
                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
        l_scomData.insertFromRight<NHTM_TTYPE_FILT_TSIZE_PATTERN,
                                   NHTM_TTYPE_FILT_TSIZE_PATTERN_LEN>
                                   (l_attrValue_uint8);

        // Set TTYPEFILT_MASK
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_TTYPEFILT_MASK, i_target,
                               l_attrValue_uint8),
                 "setupHtmFabric: Error getting ATTR_HTMSC_TTYPEFILT_MASK, "
                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
        l_scomData.insertFromRight<NHTM_TTYPE_FILT_TTYPE_MASK,
                                   NHTM_TTYPE_FILT_TTYPE_MASK_LEN>
                                   (l_attrValue_uint8);

        // Set TSIZEFILT_MASK
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_TSIZEFILT_MASK, i_target,
                               l_attrValue_uint8),
                 "setupHtmFabric: Error getting ATTR_HTMSC_TSIZEFILT_MASK, "
                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
        l_scomData.insertFromRight<NHTM_TTYPE_FILT_TSIZE_MASK,
                                   NHTM_TTYPE_FILT_TSIZE_MASK_LEN>
                                   (l_attrValue_uint8);

        // Set TTYPEFILT_INVERT
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_TTYPEFILT_INVERT, i_target,
                               l_attrValue_uint8),
                 "setupHtmFabric: Error getting ATTR_HTMSC_TTYPEFILT_INVERT, "
                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);

        if (l_attrValue_uint8 == fapi2::ENUM_ATTR_HTMSC_TTYPEFILT_INVERT_MATCH)
        {
            l_scomData.clearBit<NHTM_TTYPE_FILT_TTYPEFILT_INV>();
        }
        else
        {
            l_scomData.setBit<NHTM_TTYPE_FILT_TTYPEFILT_INV>();
        }

        // Set CRESPFILT_INVERT
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_CRESPFILT_INVERT, i_target,
                               l_attrValue_uint8),
                 "setupHtmFabric: Error getting ATTR_HTMSC_CRESPFILT_INVERT, "
                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);

        if (l_attrValue_uint8 == fapi2::ENUM_ATTR_HTMSC_CRESPFILT_INVERT_MATCH)
        {
            l_scomData.clearBit<NHTM_TTYPE_FILT_CRESPFILT_INV>();
        }
        else
        {
            l_scomData.setBit<NHTM_TTYPE_FILT_CRESPFILT_INV>();
        }

        // Display NHTM_TTYPE_FILT reg setup value
        FAPI_INF("setupHtmFabric: NHTM_TTYPE_FILT reg setup: 0x%016llX",
                 l_scomData);

        // Write HW
        FAPI_TRY(fapi2::putScom(i_target, i_htmModeRegAddr + NHTM_TTYPE_FILT,
                                l_scomData),
                 "setupHtmFabric: putScom returns error: "
                 "Addr 0x%016llX, l_rc 0x%.8X",
                 i_htmModeRegAddr + NHTM_TTYPE_FILT,
                 (uint64_t)fapi2::current_err);

        // ------------------ Setup NHTM_FILT reg ------------------
        l_scomData = 0;

        // Set HTMSC_FILT_PAT
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_FILT_PAT, i_target,
                               l_attrValue_uint32),
                 "setupHtmFabric: Error getting ATTR_HTMSC_FILT_PAT, "
                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
        l_scomData.insertFromRight<NHTM_FILT_FILTER_PATTERN,
                                   NHTM_FILT_FILTER_PATTERN_LEN>
                                   (l_attrValue_uint32);

        // Set HTMSC_FILT_CRESP_PAT
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_FILT_CRESP_PAT, i_target,
                               l_attrValue_uint8),
                 "setupHtmFabric: Error getting ATTR_HTMSC_FILT_CRESP_PAT, "
                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
        l_scomData.insertFromRight<NHTM_FILT_FILTER_CRESP_PATTERN,
                                   NHTM_FILT_FILTER_CRESP_PATTERN_LEN>
                                   (l_attrValue_uint8);

        // Set HTMSC_FILT_MASK
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_FILT_MASK, i_target,
                               l_attrValue_uint32),
                 "setupHtmFabric: Error getting ATTR_HTMSC_FILT_MASK, "
                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
        l_scomData.insertFromRight<NHTM_FILT_FILTER_MASK,
                                   NHTM_FILT_FILTER_MASK_LEN>
                                   (l_attrValue_uint32);

        // Set HTMSC_FILT_CRESP_MASK
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_FILT_CRESP_MASK, i_target,
                               l_attrValue_uint8),
                 "setupHtmFabric: Error getting ATTR_HTMSC_FILT_CRESP_MASK, "
                 "l_rc 0x%.8X",  (uint64_t)fapi2::current_err);
        l_scomData.insertFromRight<NHTM_FILT_FILTER_CRESP_MASK,
                                   NHTM_FILT_FILTER_CRESP_MASK_LEN>
                                   (l_attrValue_uint8);

        // Display NHTM_TTYPE_FILT reg setup value
        FAPI_INF("setupHtmFabric: NHTM_FILT reg setup: 0x%016llX",
                 l_scomData);

        // Write HW
        FAPI_TRY(fapi2::putScom(i_target, i_htmModeRegAddr + NHTM_FILT,
                                l_scomData),
                 "setupHtmFabric: putScom returns error: "
                 "Addr 0x%016llX, l_rc 0x%.8X",
                 i_htmModeRegAddr + NHTM_FILT,
                 (uint64_t)fapi2::current_err);

        // -------------- Setup HTM_MODE reg -----------------
        l_scomData = 0;

        // Enable HTM
        l_scomData.setBit<HTM_MODE_TRACE_ENABLE>();

        // CONTENT_SEL
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MODE_CONTENT_SEL, i_target,
                               l_attrValue_uint8),
                 "setupHtmFabric: Error getting ATTR_HTMSC_MODE_CONTENT_SEL, "
                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
        l_scomData.insertFromRight<HTM_MODE_CONTENT_SEL,
                                   HTM_MODE_CONTENT_SEL_LEN>
                                   (l_attrValue_uint8);

        // CAPTURE
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MODE_CAPTURE, i_target,
                               l_attrValue_uint32),
                 "setupHtmFabric: Error getting ATTR_HTMSC_MODE_CAPTURE, "
                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
        l_scomData.insertFromRight<HTM_MODE_CAPTURE,
                                   HTM_MODE_CAPTURE_LEN>
                                   (l_attrValue_uint32);

        // WRAP mode
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MODE_WRAP, i_target,
                               l_attrValue_uint8),
                 "setupHtmFabric: Error getting ATTR_HTMSC_MODE_WRAP, "
                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);

        if (l_attrValue_uint8 == fapi2::ENUM_ATTR_HTMSC_MODE_WRAP_DISABLE)
        {
            l_scomData.clearBit<HTM_MODE_WRAP_MODE>();
        }
        else
        {
            l_scomData.setBit<HTM_MODE_WRAP_MODE>();
        }

        // DISABLE_TSTAMPS mode
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MODE_DIS_TSTAMP, i_target,
                               l_attrValue_uint8),
                 "setupHtmFabric: Error getting ATTR_HTMSC_MODE_DIS_TSTAMP, "
                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);

        if (l_attrValue_uint8 == fapi2::ENUM_ATTR_HTMSC_MODE_DIS_TSTAMP_DISABLE)
        {
            l_scomData.setBit<HTM_MODE_DISABLE_TSTAMPS>();
        }
        else
        {
            l_scomData.clearBit<HTM_MODE_DISABLE_TSTAMPS>();
        }

        // SINGLE_TSTAMPS mode
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MODE_SINGLE_TSTAMP, i_target,
                               l_attrValue_uint8),
                 "setupHtmFabric: Error getting ATTR_HTMSC_MODE_SINGLE_TSTAMP, "
                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);

        if (l_attrValue_uint8 == fapi2::ENUM_ATTR_HTMSC_MODE_SINGLE_TSTAMP_DISABLE)
        {
            l_scomData.clearBit<HTM_MODE_SINGLE_TSTAMPS>();
        }
        else
        {
            l_scomData.setBit<HTM_MODE_SINGLE_TSTAMPS>();
        }

        // MARKERS_ONLY mode
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MODE_MARKERS_ONLY, i_target,
                               l_attrValue_uint8),
                 "setupHtmFabric: Error getting ATTR_HTMSC_MODE_MARKERS_ONLY, "
                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);

        if (l_attrValue_uint8 ==
            fapi2::ENUM_ATTR_HTMSC_MODE_MARKERS_ONLY_DISABLE)
        {
            l_scomData.clearBit<HTM_MODE_MARKERS_ONLY>();
        }
        else
        {
            l_scomData.setBit<HTM_MODE_MARKERS_ONLY>();
        }

        // DISABLE_GROUP_SCOPE mode
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MODE_DIS_FORCE_GROUP_SCOPE,
                               i_target, l_attrValue_uint8),
                 "setupHtmFabric: Error getting "
                 "ATTR_HTMSC_MODE_DIS_FORCE_GROUP_SCOPE, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        if (l_attrValue_uint8 ==
            fapi2::ENUM_ATTR_HTMSC_MODE_DIS_FORCE_GROUP_SCOPE_DISABLE)
        {
            l_scomData.clearBit<HTM_MODE_DISABLE_FORCE_GRP_SCOPE>();
        }
        else
        {
            l_scomData.setBit<HTM_MODE_DISABLE_FORCE_GRP_SCOPE>();
        }

        // SYNC_STAMP_FORCE mode
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MODE_SYNC_STAMP_FORCE, i_target,
                               l_attrValue_uint8),
                 "setupHtmFabric: Error getting ATTR_HTMSC_MODE_SYNC_STAMP_FORCE, "
                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
        l_scomData.insertFromRight<HTM_MODE_SYNC_STAMP_FORCE,
                                   HTM_MODE_SYNC_STAMP_FORCE_LEN>
                                   (l_attrValue_uint8);

        // WRITETOIO mode
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MODE_WRITETOIO,
                               i_target, l_attrValue_uint8),
                 "setupHtmFabric: Error getting ATTR_HTMSC_MODE_WRITETOIO, "
                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);

        if (l_attrValue_uint8 == fapi2::ENUM_ATTR_HTMSC_MODE_WRITETOIO_DISABLE)
        {
            l_scomData.clearBit<HTM_MODE_WRITETOIO>();
        }
        else
        {
            l_scomData.setBit<HTM_MODE_WRITETOIO>();
        }

        // VGTARGET mode
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MODE_VGTARGET, i_target,
                               l_attrValue_uint32),
                 "setupHtmFabric: Error getting ATTR_HTMSC_MODE_VGTARGET, "
                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
        l_scomData.insertFromRight<HTM_MODE_VGTARGET,
                                   HTM_MODE_VGTARGET_LEN>
                                   (l_attrValue_uint32);

        // Display HTM_MODE reg setup value
        FAPI_INF("setupHtmFabric: HTM_MODE reg setup: 0x%016llX", l_scomData);

        // Write HW
        FAPI_TRY(fapi2::putScom(i_target, i_htmModeRegAddr, l_scomData),
                 "setupHtmFabric: putScom returns error: "
                 "Addr 0x%016llX, l_rc 0x%.8X",
                 i_htmModeRegAddr,  (uint64_t)fapi2::current_err);

    fapi_try_exit:
        return fapi2::current_err;
    }


///
/// @brief Specific registers to setup for Core HTM CORE.
///        The registers are: TODO: list registers
///
/// @param[in] i_target             Reference to Processor Chip target
/// @param[in] i_htmModeRegAddr    The base HTM Mode Register address
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///

    fapi2::ReturnCode setupHtmCore(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const uint64_t i_htmModeRegAddr)
    {
        FAPI_INF("setupHtmCore");
        fapi2::ReturnCode l_rc;

        // TODO: Implement setupHtmCore when information is available.

        return fapi2::current_err;
    }

///
/// @brief Specific HTM setup for Core HTM_LLAT
///
/// @param[in] i_target          Reference to Processor Chip target
/// @param[in] i_htmModeRegAddr  The base HTM Mode Register address
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode setupHtmLlat(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const uint64_t i_htmModeRegAddr)
    {
        FAPI_INF("setupHtmLlat");
        fapi2::ReturnCode l_rc;

        // TODO: Implement setupHtmLlat when information is available.

        return fapi2::current_err;
    }

///
/// @brief p9_htm_setup procedure entry point
/// See doxygen in p9_htm_setup.H
///
    fapi2::ReturnCode p9_htm_setup(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
    {
        FAPI_DBG("Entering p9_htm_setup");
        fapi2::ReturnCode l_rc;
        uint8_t l_nhtm_trace_type = 0;
        uint8_t l_chtm_trace_type = 0;
        auto l_modeRegList = std::vector<uint64_t>();

        // Get NTHM trace option
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_NHTM_TRACE_TYPE, i_target,
                               l_nhtm_trace_type),
                 "p9_htm_setup: Error getting ATTR_NHTM_TRACE_TYPE, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Get CTHM trace option
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHTM_TRACE_TYPE, i_target,
                               l_chtm_trace_type),
                 "p9_htm_setup: Error getting ATTR_CHTM_TRACE_TYPE, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Display enabled HTM trace types
        FAPI_INF("p9_htm_setup: NHTM type: 0x%.8X, CHTM type: 0x%.8X",
                 l_nhtm_trace_type, l_chtm_trace_type);

        // If no HTM trace collection is enabled, exit.
        if ( (l_nhtm_trace_type == fapi2::ENUM_ATTR_NHTM_TRACE_TYPE_DISABLE) &&
             (l_chtm_trace_type == fapi2::ENUM_ATTR_CHTM_TRACE_TYPE_DISABLE) )
        {
            FAPI_INF("p9_htm_setup: HTM traces are disabled.");
            return l_rc;
        }

        // ------------------------------------------------------
        //     HTM is enabled, proceed with setup HTM
        // ------------------------------------------------------

        // --- Make a list of HTM_MODE register addresses to be setup ---
        if (l_nhtm_trace_type != fapi2::ENUM_ATTR_NHTM_TRACE_TYPE_DISABLE)
        {
            l_modeRegList.push_back(PU_HTM0_HTM_MODE);
            l_modeRegList.push_back(PU_HTM1_HTM_MODE);
        }

        if (l_chtm_trace_type != fapi2::ENUM_ATTR_CHTM_TRACE_TYPE_DISABLE)
        {
            //TODO: Need to handle CHTM trace targets.
            // See review comments in: http://gfw160.aus.stglabs.ibm.com:8080/gerrit/#/c/21527/
        }

        // --------- Do setup for each register in list ----------------------
        for (auto itr = l_modeRegList.begin(); itr != l_modeRegList.end();
             ++itr)
        {
            // Setup generic registers
            FAPI_TRY(setupHTMGeneric(i_target, (*itr)),
                     "p9_htm_setup: setupHTMGeneric returns an error, RegAddr "
                     "0x%016llX, l_rc 0x%.8X", (*itr), (uint64_t)fapi2::current_err);

            // Specific setup for Nest HTM FABRIC
            if (l_nhtm_trace_type == fapi2::ENUM_ATTR_NHTM_TRACE_TYPE_FABRIC)
            {
                FAPI_TRY(setupHtmFabric(i_target, (*itr)),
                         "p9_htm_setup: setupHtmFabric returns an error, l_rc 0x%.8X",
                         (uint64_t)fapi2::current_err);
            }
            else // Other Nest HTM trace type are not yet supported
            {
                FAPI_ASSERT(false, fapi2::NHTM_TRACE_TYPE_NOT_SUPPORTED()
                            .set_NHTM_TRACE_TYPE(l_nhtm_trace_type),
                            "p9_htm_setup: Nest HTM trace type is not supported: "
                            "0x%.8X", l_nhtm_trace_type);
            }

            // Specific setup for Core HTM
            if (l_chtm_trace_type ==  fapi2::ENUM_ATTR_CHTM_TRACE_TYPE_CORE)
            {
                FAPI_TRY(setupHtmCore(i_target, (*itr)),
                         "p9_htm_setup: setupHtmCore returns an error, l_rc 0x%.8X",
                         (uint64_t)fapi2::current_err);
            }

            // Specific setup for CHTM_LLAT
            else if (l_chtm_trace_type ==
                     fapi2::ENUM_ATTR_CHTM_TRACE_TYPE_LLAT)
            {
                FAPI_TRY(setupHtmLlat(i_target, (*itr)),
                         "p9_htm_setup: setupHtmLlat returns an error, l_rc 0x%.8X",
                         (uint64_t)fapi2::current_err);
            }
            // The rest of Core HTM trace types are not yet supported
            else
            {
                FAPI_ASSERT(false, fapi2::CHTM_TRACE_TYPE_NOT_SUPPORTED()
                            .set_CHTM_TRACE_TYPE(l_chtm_trace_type),
                            "p9_htm_setup: Core HTM trace type is not supported: "
                            "0x%.8X", l_chtm_trace_type);
            }
        }

    fapi_try_exit:
        FAPI_DBG("Exiting p9_htm_setup");
        return fapi2::current_err;
    }

} // extern "C"
