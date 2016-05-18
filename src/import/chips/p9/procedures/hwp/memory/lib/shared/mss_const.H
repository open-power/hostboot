/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/shared/mss_const.H $       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

///
/// @mss_const.H
/// @This file contains constants for the memory team.
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_CONST_H_
#define _MSS_CONST_H_


namespace mss
{

enum sizes
{
    PORTS_PER_MCS = 2,
    PORTS_PER_MCBIST = 4,
    MC_PER_MODULE = 2,
    MCBIST_PER_MC = 1,
    MAX_DIMM_PER_PORT = 2,
    MAX_RANK_PER_DIMM = 4,
    RANK_MID_POINT = 4,            ///< Which rank number indicates the switch to the other DIMM
    DEFAULT_POLL_LIMIT = 10,       ///< the number of poll attempts in the event we can't calculate another
    MAX_NUM_IMP = 4,               ///< number of impedances valid per slew type
    MAX_NUM_CAL_SLEW_RATES = 4,    ///< 3V/ns, 4V/ns, 5V/ns, 6V/n
    MAX_SLEW_VALUE = 15,           ///< 4 bit value
    MAX_SUPPORTED_FREQUENCIES = 1, ///< Number of supported frequencies. Right now it's only 2400

    // All need to be attributes - BRS
    // 48:51, 0b1100, (def_is_sim);       # BIG_STEP = 12 (changed from default for SIM)
    // 48:51, 0b0000, any;       # BIG_STEP = 0  SWyatt
    // #48:51, 0b0010, any;       # BIG_STEP = 2  (default)
    // 52:54,  0b000,  any;       # SMALL_STEP = 0 (default)      SWyatt
    //#52:54,  0b001,  any;       # SMALL_STEP = 1        (!! recommend setting to 0)
    // 55:60,  0b101010, any;     # WR_PRE_DLY = 42
    WR_LVL_BIG_STEP = 0b1100,
    WR_LVL_SMALL_STEP = 0b000,
    WR_LVL_PRE_DLY = 0b101010,
    WR_LVL_NUM_VALID_SAMPLES = 0x5,

    // THIS IS LIKELY INCORRECT - Should be defined in the DDR4 write centering protocol BRS
    // This field must be set to the larger of the two values in number of memory clock cycles.
    // FW_RD_WR = max(tWTR + 11, AL + tRTP + 3)
    WR_CNTR_FW_RD_WR = 0x11 + 4,
    WR_CNTR_FW_WR_RD = 0x0,

    // Attribute? BRS
    COARSE_CAL_STEP_SIZE = 0x4,
    CONSEQ_PASS = 0x8,
};

enum times
{
    CONVERT_PS_IN_A_NS      = 1000,     ///< 1000 pico in an nano
    CONVERT_PS_IN_A_US      = 1000000,  ///< 1000000 picos in a micro

    DELAY_1NS               = 1,
    DELAY_10NS              = 10 ,      ///< general purpose 10  ns delay for HW mode
    DELAY_100NS             = 100,      ///< general purpose 100 ns delay for HW mode
    DELAY_1US               = 1000,     ///< general purpose 1 usec delay for HW mode
    DELAY_100US             = 100000,   ///< general purpose 100 usec delay for HW mode
    DELAY_1MS               = 1000000,  ///< general purpose 1 ms delay for HW mode

    // From the DDR4spec 2400 speed - need to be changed to read attributes. BRS
    tWLO = 10,
    tWLOE = 2,
};

enum states
{
    LOW = 0,
    HIGH = 1,
    START = 1,
    STOP = 0,
    START_N = 0,
    STOP_N = 1,
    ON = 1,
    OFF = 0,
    ON_N = 0,
    OFF_N = 1,
    YES = 1,
    NO = 0,
    YES_N = 0,
    NO_N = 1,
    INVALID = 0xFF,

    // This needs to be an attribute I think - BRS. Used as a boolean.
    CAL_ABORT_ON_ERROR = 1,
};

// Static consts describing the bits used in the cal_step_enable attribute
// These are bit positions. 0 is the left most bit.
enum cal_steps
{
    EXT_ZQCAL         = 0,
    WR_LEVEL          = 1,
    DQS_ALIGN         = 2,
    RDCLK_ALIGN       = 3,
    READ_CTR          = 4,
    READ_CTR_2D_VREF  = 5,
    WRITE_CTR         = 6,
    WRITE_CTR_2D_VREF = 7,
    COARSE_WR         = 8,
    COARSE_RD         = 9,
};

// Static consts for DDR4 voltages used in p9_mss_volt
enum voltages : uint64_t
{
    DDR4_NOMINAL_VOLTAGE = 1200,
    DDR4_VPP_VOLTAGE = 2500,
};

namespace mcbist
{
enum data_mode
{
    // MCBIST test data modes
    FIXED_DATA_MODE   = 0b000,
    RAND_FWD_MODE     = 0b001,
    RAND_REV_MODE     = 0b010,
    RAND_FWD_MAINT    = 0b011,
    RAND_REV_MAINT    = 0b100,
    DATA_EQ_ADDR      = 0b101,
    ROTATE_LEFT_MODE  = 0b110,
    ROTATE_RIGHT_MODE = 0b111,
};

// 0:3  Operation Type
enum op_type
{
    WRITE            = 0b0000, // fast, with no concurrent traffic
    READ             = 0b0001, // fast, with no concurrent traffic
    READ_WRITE       = 0b0010,
    WRITE_READ       = 0b0011,
    READ_WRITE_READ  = 0b0100,
    READ_WRITE_WRITE = 0b0101,
    RAND_SEQ         = 0b0110,
    READ_READ_WRITE  = 0b1000,
    SCRUB_RRWR       = 0b1001,
    STEER_RW         = 0b1010,
    ALTER            = 0b1011, // (W)
    DISPLAY          = 0b1100, // (R, slow)
    CCS_EXECUTE      = 0b1111,

    // if bits 9:11 (Data Mode bits)  = 000  (bits 4:8 used to specify which subtest to go to)
    // Refresh only cmd if bits 9:11 (Data Mode bits) /= 000
    GOTO_SUBTEST_N = 0b0111,
};

enum test_type
{
    USER_MODE = 0,
    CENSHMOO = 1,
    SUREFAIL = 2,
    MEMWRITE = 3,
    MEMREAD = 4,
    CBR_REFRESH = 5,
    MCBIST_SHORT = 6,
    SHORT_SEQ = 7,
    DELTA_I = 8,
    DELTA_I_LOOP = 9,
    SHORT_RAND = 10,
    LONG1 = 11,
    BUS_TAT = 12,
    SIMPLE_FIX = 13,
    SIMPLE_RAND = 14,
    SIMPLE_RAND_2W = 15,
    SIMPLE_RAND_FIXD = 16,
    SIMPLE_RA_RD_WR = 17,
    SIMPLE_RA_RD_R = 18,
    SIMPLE_RA_FD_R = 19,
    SIMPLE_RA_FD_R_INF = 20,
    SIMPLE_SA_FD_R = 21,
    SIMPLE_RA_FD_W = 22,
    INFINITE = 23,
    WR_ONLY = 24,
    W_ONLY = 25,
    R_ONLY = 26,
    W_ONLY_RAND = 27,
    R_ONLY_RAND = 28,
    R_ONLY_MULTI = 29,
    SHORT = 30,
    SIMPLE_RAND_BARI = 31,
    W_R_INFINITE = 32,
    W_R_RAND_INFINITE = 33,
    R_INFINITE1 = 34,
    R_INFINITE_RF = 35,
    MARCH = 36,
    SIMPLE_FIX_RF = 37,
    SHMOO_STRESS = 38,
    SIMPLE_RAND_RA = 39,
    SIMPLE_FIX_RA = 40,
    SIMPLE_FIX_RF_RA = 41,
    TEST_RR = 42,
    TEST_RF = 43,
    W_ONLY_INFINITE_RAND = 44,
    MCB_2D_CUP_SEQ = 45,
    MCB_2D_CUP_RAND = 46,
    SHMOO_STRESS_INFINITE = 47,
    HYNIX_1_COL = 48,
    RMWFIX = 49,
    RMWFIX_I = 50,
    W_INFINITE = 51,
    R_INFINITE = 52,
};

} // namespace mcbist


}
#endif
