/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/io/p9_io_gcr.H $                      */
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
///
/// @file p9_io_gcr.H
/// @brief Register Access.
///----------------------------------------------------------------------------
/// *HWP HWP Owner   : Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP FW Owner    : Jamie Knight <rjknight@us.ibm.com>
/// *HWP Team        : IO
/// *HWP Level       : 2
/// *HWP Consumed by : FSP:HB
///----------------------------------------------------------------------------
///
/// @verbatim
/// Register Access via scom.
///
/// @endverbatim
///----------------------------------------------------------------------------

#ifndef P9_IO_GCR_H_
#define P9_IO_GCR_H_

//* *****************************
//* Defines
//* *****************************

// @brief IO Base Addresses
#define P9_PSI_PHY_BASE_0x00000000       0x00000000
#define P9_XBUS_PHY_BASE_0x06010C3F      0x06010C3F
#define P9_ABUS0_PHY_BASE_0x0901103F     0x0901103F
#define P9_ABUS3_PHY_BASE_0x0C01103F     0x0C01103F
#define P9_NVBUS0_PHY_BASE_0x0901103F    0x0901103F
#define P9_NVBUS3_PHY_BASE_0x0C01103F    0x0C01103F
#define P9_NVBUS1_PHY_BASE_0x08010C7F    0x08010C7F
#define P9_DMI0_PHY_BASE_0x02011A3F      0x02011A3F
#define P9_DMI1_PHY_BASE_0x02011E3F      0x02011E3F
#define CEN_PHY_BASE_0x0201043F          0x0201043F

#define BROADCAST_GROUP 0xF
#define BROADCAST_LANE  0x1F
//-----------------------------------------------------------------------------
//  FAPI Includes
//-----------------------------------------------------------------------------
#include <fapi2.H>

/**
 * @class Register
 * This class provides a generic template for a register to read/write SCOMs.
 * @tparam[in] REG_ID Specific Register ID that matches Field IDs that belong to
 * that specific register.  Used with a static assert for compile time errors.
 * @tparam[in] SCOM_ADDR Upper 32bits of a 64bit scom register address.  If the reg
 * is a flat scom register, this is all 0's.  If the register is an I/O GCR reg,
 * this contains direction, R/W, indirect address, etc.
 * @tparam[in] REG_WIDTH Size of the Register.  64 for flat scom register and 16 for
 * I/O GCR registers
 */
template < uint16_t REG_ID, uint64_t SCOM_ADDR, uint8_t REG_WIDTH>
class Register
{
    public:

        /**
         * @brief Class Constructor
         */
        Register() : _shadow(0) {};

        /**
         * @brief Class Destructor
         */
        ~Register(void) = default;


        /**
         * @brief SCOM read Function
         * @tparam[in] K fapi2::TargetType
         * @param[in]  i_target Target to operate on
         * @param[in]  i_group Group to operate on
         * @param[in]  i_lane Lane to operate on
         * @return return code. Zero on success, else platform specified error
         */
        template < fapi2::TargetType K >
        inline fapi2::ReturnCode read(const fapi2::Target < K > i_target,
                                      const uint8_t i_group = 0,
                                      const uint8_t i_lane = 0)
        {
            fapi2::buffer < uint64_t > data;
            uint64_t address = buildScomAddress(i_target, i_group, i_lane);
            FAPI_TRY( fapi2::getScom(i_target, address, data),
                      "getScom Failed(0x%X): Addr(0x%016llX) Data(0x%016llX)",
                      (uint64_t) fapi2::current_err, address, data);
            _shadow = data;
        fapi_try_exit:
            return fapi2::current_err;
        }

        /**
         * @brief SCOM write Function
         * @tparam[in] K fapi2::TargetType
         * @param[in]  i_target Target to operate on
         * @param[in]  i_group Group to operate on
         * @param[in]  i_lane Lane to operate on
         * @return return code. Zero on success, else platform specified error
         */
        template < fapi2::TargetType K >
        inline fapi2::ReturnCode write(const fapi2::Target < K > i_target,
                                       const uint8_t i_group = 0,
                                       const uint8_t i_lane = 0)
        {
            fapi2::buffer < uint64_t > data(_shadow);
            uint64_t address = buildScomAddress(i_target, i_group, i_lane);
            FAPI_TRY( fapi2::putScom(i_target, address, data),
                      "putScom Failed(0x%X): Addr(0x%016llX) Data(0x%016llX)",
                      (uint64_t) fapi2::current_err, address, data);
        fapi_try_exit:
            return fapi2::current_err;
        }

        /**
         * @brief Gets field data from the register data
         * @tparam[in] FIELD_ID Corresponds with the REG_ID to provide a compile
         * time error if the field does not below to the register
         * @tparam[in] START Represents the start bit of the field within the reg
         * @tparam[in] WIDTH Represents the width of the field within the reg
         * @return Field Data
         */
        template<uint16_t FIELD_ID, uint8_t START, uint8_t WIDTH>
        inline uint16_t get()
        {
            static_assert(FIELD_ID == REG_ID, "Field does not belong to Register");
            const uint8_t shift = REG_WIDTH - START - WIDTH;
            const uint64_t mask = ( (0x1 << WIDTH) - 1) << shift;
            return ((_shadow & mask) >> shift);
        }

        /**
         * @brief Sets the register data from the passed in field data
         * @tparam[in] FIELD_ID Corresponds with the REG_ID to provide a compile
         * time error if the field does not below to the register
         * @tparam[in] START Represents the start bit of the field within the reg
         * @tparam[in] WIDTH Represents the width of the field within the reg
         * @return void
         */
        template<uint16_t FIELD_ID, uint8_t START, uint8_t WIDTH>
        inline void set(const uint16_t i_data)
        {
            static_assert(FIELD_ID == REG_ID, "Field does not belong to Register");
            const uint8_t shift = REG_WIDTH - START - WIDTH;
            const uint64_t mask = ( (0x1 << WIDTH) - 1) << shift;
            set((_shadow & ~mask) | ((i_data << shift) & mask));
            return;
        }

        /**
         * @brief Gets field data from the register data.  Method to override
         * which data is recorded
         * @tparam[in] START Represents the start bit of the field within the reg
         * @tparam[in] WIDTH Represents the width of the field within the reg
         * @return Field Data
         */
        template<uint8_t START, uint8_t WIDTH>
        inline uint16_t get()
        {
            const uint8_t shift = REG_WIDTH - START - WIDTH;
            const uint64_t mask = ( (0x1 << WIDTH) - 1) << shift;
            return ((_shadow & mask) >> shift);
        }

        /**
         * @brief Sets the register data from the passed in field data.  Method
         * to override which data is recorded.
         * @tparam[in] START Represents the start bit of the field within the reg
         * @tparam[in] WIDTH Represents the width of the field within the reg
         * @param[in] i_data Data to be set to shadow register
         * @return void
         */
        template<uint8_t START, uint8_t WIDTH>
        inline void set(const uint16_t i_data)
        {
            const uint8_t shift = REG_WIDTH - START - WIDTH;
            const uint64_t mask = ( (0x1 << WIDTH) - 1) << shift;
            set((_shadow & ~mask) | ((i_data << shift) & mask));
            return;
        }

        /**
         * @brief Gets the register data
         * @return Register Data
         */
        inline uint64_t get() const
        {
            return _shadow;
        }

        /**
         * @brief Sets the register data
         * @param[in] i_data Data to be set to shadow register
         * @return void
         */
        inline void set(const uint64_t i_data)
        {
            _shadow = i_data;
            return;
        }

    private:

        /**
         * @brief Stores the Register read/write data for scoms
         */
        uint64_t _shadow;

        /**
         * @brief Builds the base scom address, group, and lane into the full
         *   scom address
         * @tparam[in] K fapi2::TargetType
         * @param[in] i_target FAPI2 Target
         * @param[in] i_group Group encoded into the scom address
         * @param[in] i_lane Lane encoded into the scom address
         * @return Full 64bit encoded scom address
         */
        template < fapi2::TargetType K >
        inline uint64_t buildScomAddress(const fapi2::Target < K > i_target,
                                         const uint8_t i_group,
                                         const uint8_t i_lane)
        {
            const uint8_t ADDRESS_SIZE = 64;
            const uint8_t GROUP_SHIFT  = ADDRESS_SIZE - 22 - 5;
            const uint8_t LANE_SHIFT   = ADDRESS_SIZE - 27 - 5;
            uint64_t address = SCOM_ADDR | getBaseAddress(i_target);


            // If information is > 0x3F, then the register must be a GCR indirect
            // access register.
            if(SCOM_ADDR > 0x3F)
            {
                address |= (uint64_t) i_group << GROUP_SHIFT; // Set Group
                address |= (uint64_t) i_lane << LANE_SHIFT; // Set Lane
            }
            // Flat Scom Register, the first 6 bits are unique.
            else
            {
                address = (address & 0xFFFFFFC0) | (SCOM_ADDR & 0x0000003F);
            }

            return address;
        }

        /**
         * @brief Builds the base scom address
         * @tparam[in] K fapi2::TargetType
         * @param[in] i_target FAPI2 Target
         * @return 32bit encoded base scom address
         */
        template < fapi2::TargetType K >
        inline uint32_t getBaseAddress(const fapi2::Target <K> i_target)
        {
            if(i_target.getType() == fapi2::TargetType::TARGET_TYPE_XBUS)
            {
                return P9_XBUS_PHY_BASE_0x06010C3F;
            }
            else if(i_target.getType() == fapi2::TargetType::TARGET_TYPE_ABUS)
            {
                return P9_ABUS0_PHY_BASE_0x0901103F;
            }
            else if(i_target.getType() == fapi2::TargetType::TARGET_TYPE_MCS)
            {
                return P9_DMI0_PHY_BASE_0x02011A3F;
            }
            else if(i_target.getType() == fapi2::TargetType::TARGET_TYPE_MEMBUF_CHIP)
            {
                return CEN_PHY_BASE_0x0201043F;
            }
            else
            {
                fapi2::IO_GCR_TARGET_TYPE_NOT_FOUND().set_TARGET(i_target).execute();
                FAPI_ERR("TargetType not found(0x%X)", i_target.getType());
            }

            return 0x0;
        }

};

#endif /* P9_IO_GCR_H_ */
