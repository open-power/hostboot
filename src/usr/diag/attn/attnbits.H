/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/attnbits.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
#ifndef ATTN_ATTNBITS_H
#define ATTN_ATTNBITS_H

/**
 * @file attnbits.H
 *
 * @brief Utility functions and types provided by the attnbits module.
 */

namespace ATTN
{
namespace IPOLL
{

/**
 * @brief address IPOLL mask register SCOM address.
 */
extern const uint64_t address;

/**
 * @brief getCheckbits Obtain the associated mask bit(s) in the ipoll
 *                     mask register.
 *
 * @param[in] i_type The attention type for which to obtain the mask bit(s).
 * @param[out] o_bits The mask bits associated with the attention type.
 *
 * @retval[true] Bits found for supplied attention type.
 * @retval[false] No bits found for supplied attention type.
 */
bool getCheckbits(
        uint64_t i_type,
        uint64_t & o_bits);

/**
 * @brief forEach Call a function for each masked attention type
 *                 in the ipoll mask register.
 *
 * @param[in] i_scomData The register content to decode.
 * @param[in] i_data User pointer.
 * @param[in] i_func User function.
 */
void forEach(
        uint64_t i_scomData,
        void * i_data,
        void (*i_func)(uint64_t, void *));
}

namespace GFIR
{

/**
 * @brief getAddress Get the GFir address for the given attention type.
 *
 * @param[in] i_type The type for which to obtain the address.
 * @param[out] o_address The address associated with the attention type.
 *
 * @retval[false] No address found for the supplied attention type.
 * @retval[true] Address found for the supplied attention type.
 */
bool getAddress(
        uint64_t i_type,
        uint64_t & o_address);

/**
 * @brief getCheckbits Obtain the associated bits for the given
 *                               attention type.
 *
 * @param[in] i_type The attention type for which to obtain the bits.
 * @param[out] o_bits The bits associated with the attention type.
 *
 * @retval[false] No bits found for the supplied attention type.
 * @retval[true] Bits found for the supplied attention type.
 */
bool getCheckbits(
        uint64_t i_type,
        uint64_t & o_bits);
}

namespace MCI
{

/**
 * @brief address MCI FIR register SCOM address.
 */
extern const uint64_t address;

/**
 * @brief getCheckbits Obtain the associated mask bit(s) in the MCI Fir.
 *
 * @param[in] i_type The attention type for which to obtain the mask bit(s).
 * @param[out] o_bits The mask bits associated with the attention type.
 *
 * @retval[true] Bits found for supplied attention type.
 * @retval[false] No bits found for supplied attention type.
 */
bool getCheckbits(
        uint64_t i_type,
        uint64_t & o_bits);

/**
 * @brief forEach Call a function for each membuf attention
 *          type reported by the MCI FIR.
 *
 * @param[in] i_scomData The register content to decode.
 * @param[in] i_data User pointer.
 * @param[in] i_func User function.
 */
void forEach(
        uint64_t i_scomData,
        void * i_data,
        void (*i_func)(uint64_t, void *));
}

namespace GP1
{

/**
 * @brief address GP1 nest register SCOM address.
 */
extern const uint64_t address;

/**
 * @brief forEach Call a function for each MCS position reporting
 *                  an attention.
 *
 * @param[in] i_scomData The register content to decode.
 * @param[in] i_data User pointer.
 * @param[in] i_func User function.
 */
void forEach(
        uint64_t i_scomData,
        void * i_data,
        void (*i_func)(uint64_t, void *));

/**
 * @brief getCheckbits Obtain the associated mask bit(s) in the GP1 nest
 *        register.
 *
 * @param[in] i_pos The MCS position for which to obtain the mask bit(s).
 * @param[out] o_bits The mask bits associated with the MCS position.
 *
 * @retval[true] Bits found for supplied MCS position.
 * @retval[false] No bits found for supplied MCS position.
 */
bool getCheckbits(
        uint64_t i_pos,
        uint64_t & o_bits);
}

/**
 * @brief PsiHbXivr Layout for XIVR registers.
 */
struct PsiHbXivr
{
    union
    {
        uint64_t u64;

        struct
        {
            uint64_t res1:8;       // zeros
            uint64_t pir:14;       // interrupt destination (server)
            uint64_t linkptr:2;    // which link reg in intr presenter
            uint64_t priority:8;   // intr priority level
            uint64_t source:3;     // source number
            uint64_t res2:4;       // zeros
            uint64_t intr_pend:25; // interrupt is pending
        } PACKED;
    };

    PsiHbXivr() : u64(0) {}
};

/**
 * @brief IcpXisr The XISR fields of the XIRR register.
 */
struct IcpXisr
{
    union
    {
        uint64_t u64;

        struct
        {
            uint64_t res1:44;    // zeros
            uint64_t node:4;     // isn - node
            uint64_t chip:3;     // isn - chip
            uint64_t unit:2;     // isn - unit
            uint64_t source:11;  // isn - source
        } PACKED;
    };

    IcpXisr() : u64(0) {}
};

/**
 * @brief PsiHbIrqSrcCmp Layout for the IRQ source compare register.
 *
 * FIXME: This can go away when RTC 47105 in place.
 */
struct PsiHbIrqSrcCmp
{
    union
    {
        uint64_t u64;

        struct
        {
            uint64_t irsn:19;
            uint64_t res1:10;
            uint64_t reset:1;
            uint64_t die:1;
            uint64_t uie:1;
            uint64_t mask:19;
            uint64_t res2:13;
        } PACKED;
    };

    PsiHbIrqSrcCmp() : u64(0) {}
};

/**
 * @brief PSI host bridge interrupt
 *        config related constants
 */
enum
{
    PSI_HB_IC_ENABLE        = 1,
    LCL_ERR_ISN             = 4,
    LCL_ERR_XIVR_ADDR       = 0x02010919,
    LCL_ERR_PRIO_DISABLED   = 0xff,
    LCL_ERR_PRIO            = 0x20,
    PSI_HB_IRQ_SRC_CMP_ADDR = 0x0201091b,
    PSI_HB_IRSN             = 0x18,
    PSI_HB_IRSN_MASK        = 0x7FFF8,
};
}
#endif
