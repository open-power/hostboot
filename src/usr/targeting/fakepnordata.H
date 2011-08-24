//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/targeting/fakepnordata.H $
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

#ifndef TARG_FAKEPNORDATA_H
#define TARG_FAKEPNORDATA_H

/**
 *  @file fakepnordata.H
 *
 *  @brief Interface to generate targets/attributes and fake out PNOR
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <stdint.h>
#include <stdlib.h>
#include <vector>

namespace TARGETING
{

/**
 *  @brief Enum which describes where an attribute resides
 */
enum LOCATION
{
    PNOR, ///< Attribute resides in PNOR
    HEAP, ///< Attribute resides in heap memory, not backed to PNOR
};

/**
 *  @brief Structure which holds attribute information for the PNOR targeting
 *      image generator
 */
struct AttrInfo
{
    uint32_t     size;     ///< Size of attribute
    ATTRIBUTE_ID attrId;   ///< Attribute ID
    LOCATION     location; ///< Location where attribute resides
    const void*  pData;    ///< Address of attribute
};

/**
 *  @brief Property class which maintains info about a property to serialize
 */
template<ATTRIBUTE_ID A,LOCATION L>
class Property
{
    public:

        /**
         *  @brief Map the attribute's type to something more intuitive
         */
        typedef typename AttributeTraits<A>::Type _Type;

        /**
         *  @brief Build a property
         */
        Property()
        {
            info.size = sizeof(_Type);
            info.attrId = A;
            info.location = L;
            info.pData = &iv_data;
            iv_initialized = false;
            memset(&iv_data,0x00,sizeof(iv_data));
        }

        /**
         *  @brief Push attribute info to the attribute array
         *
         *  @param[out] o_info Array of attribute structures
         */
        void addAttrInfo(
            std::vector<AttrInfo>& o_info) const
        {
            if(info.location == PNOR)
            {
                assert(iv_initialized);
            }
            o_info.push_back(info);
        }

        /**
         *  @brief Sets the attribute value
         *
         *  @param[in] i_value Value of the attribute to set
         */
        void set(
            _Type const& i_value)
        {
            iv_data = i_value;
            iv_initialized = true;
        }

        /**
         *  @brief Return size of the attribute
         *
         *  @return uint32_t giving the size of the attribute in bytes
         */
        uint32_t size() const
        {
            return sizeof(iv_data);
        }

        /**
         *  @brief Return attribute's corresponding attribute ID
         *
         *  @return Attribute ID of the attribute
         */
        ATTRIBUTE_ID id() const
        {
            return info.attrId;
        }

        /**
         *  @brief Return address of the attribute data
         *
         *  @return Address of the attribute data
         */
        const _Type* data() const
        {
            return &iv_data;
        }

        /**
         *  @brief Return location where attribute resides
         *
         *  @return Location specifier
         */
        LOCATION location() const
        {
            return info.location;
        }

    public:

        AttrInfo  info;           ///< Attribute information
        _Type     iv_data;        ///< Attribute data
        bool      iv_initialized; ///< Whether attribute was set or not
};

/**
 *  @brief Base class describing attributes that all targets have.
 *
 *  Note: will not repeat documentation for subclasses, since they act the same
 */
class Base
{
    public:

        /**
         *  @brief Build the base object for attributes
         */
        Base()
        {
        }

        /**
         *  @brief Populate the list with information on all the attributes
         *
         *  @param[out] o_info List containing all the attribute information
         */
        void getAttrInfo(
            std::vector<AttrInfo>& o_info) const
        {
            iv_class.addAttrInfo(o_info);
            iv_type.addAttrInfo(o_info);
            iv_model.addAttrInfo(o_info);
            iv_physicalPath.addAttrInfo(o_info);
            iv_affinityPath.addAttrInfo(o_info);
            iv_interfaces.addAttrInfo(o_info);
        }

    public:

        Property<ATTR_CLASS,PNOR>                iv_class;
        Property<ATTR_TYPE,PNOR>                 iv_type;
        Property<ATTR_MODEL,PNOR>                iv_model;
        Property<ATTR_PHYS_PATH,PNOR>            iv_physicalPath;
        Property<ATTR_AFFINITY_PATH,PNOR>        iv_affinityPath;
        Property<ATTR_PRIMARY_CAPABILITIES,PNOR> iv_interfaces;
};

/**
 *  @brief Class describing the data for all cards
 */
class Card : public Base
{
    public:

        Card()
        {
            iv_class.set(CLASS_CARD);

            PrimaryCapabilities l_capabilities = {0};
            iv_interfaces.set(l_capabilities);
        }

        void getAttrInfo(
            std::vector<AttrInfo>& o_info) const
        {
            Base::getAttrInfo(o_info);
        }
};

/**
 *  @brief Class describing the data for all DCM cards
 */
class CardScmPower8 : public Card
{
    public:

        CardScmPower8()
        {
            iv_type.set(TYPE_SCM);
            iv_model.set(MODEL_POWER8);
        }

        void getAttrInfo(std::vector<AttrInfo>& o_info) const
        {
            Card::getAttrInfo(o_info);
        }
};

/**
 *  @brief Class describing the data for the top level system
 */
class SysSysPower8 : public Base
{
    public:

        SysSysPower8()
        {
            iv_class.set(CLASS_SYS);
            iv_type.set(TYPE_SYS);
            iv_model.set(MODEL_POWER8);

            PrimaryCapabilities l_capabilities = {0};
            iv_interfaces.set(l_capabilities);
        }

        void getAttrInfo(std::vector<AttrInfo>& o_info) const
        {
            Base::getAttrInfo(o_info);

            iv_xscomBaseAddr.addAttrInfo(o_info);
        }

        Property<ATTR_XSCOM_BASE_ADDRESS,PNOR> iv_xscomBaseAddr;
};

/**
 *  @brief Class describing the data for a chip
 */
class Chip : public Base
{
    public:

        Chip()
        {
            iv_class.set(CLASS_CHIP);
        }

        void getAttrInfo(std::vector<AttrInfo>& o_info) const
        {
            Base::getAttrInfo(o_info);
        }
};

/**
 *  @brief Class describing the data for a node
 */
class EncNodePower8 : public Base
{
    public:

        EncNodePower8()
        {
            iv_class.set(CLASS_ENC);
            iv_type.set(TYPE_NODE);
            iv_model.set(MODEL_POWER8);

            PrimaryCapabilities l_capabilities = {0};
            iv_interfaces.set(l_capabilities);
        }

        void getAttrInfo(std::vector<AttrInfo>& o_info) const
        {
            Base::getAttrInfo(o_info);
        }
};

/**
 *  @brief Class describing the data for the Salerno chip
 */
class ProcChipSalerno : public Chip
{
    public:

        ProcChipSalerno()
        {
            iv_type.set(TYPE_PROC);
            iv_model.set(MODEL_SALERNO);

            TARGETING::PrimaryCapabilities l_capabilities = {0};
            l_capabilities.supportsFsiScom = true;
            l_capabilities.supportsXscom = true;
            iv_interfaces.set(l_capabilities);

            ScomSwitches l_switches = {0};
            l_switches.useXscom = 1;
            iv_scomSwitches.set(l_switches);

            iv_dummyRw.set(0);
        }

        void getAttrInfo(std::vector<AttrInfo>& o_info) const
        {
            Chip::getAttrInfo(o_info);

            iv_dummyRw.addAttrInfo(o_info);
            iv_scomSwitches.addAttrInfo(o_info);
            iv_xscomChipInfo.addAttrInfo(o_info);
        }

        Property<ATTR_DUMMY_RW,PNOR> iv_dummyRw;
        Property<ATTR_SCOM_SWITCHES,HEAP> iv_scomSwitches;
        Property<ATTR_XSCOM_CHIP_INFO,PNOR> iv_xscomChipInfo;

};

/**
 *  @brief Class describing the data for a logical entity
 */
class Logical : public Base
{
    public:

        Logical()
        {
            iv_class.set(CLASS_UNIT);
        }

        void getAttrInfo(std::vector<AttrInfo>& o_info) const
        {
            Base::getAttrInfo(o_info);
        }
};

/**
 *  @brief Class describing the data for an EX unit
 */
class UnitExSalerno : public Logical
{
    public:

        UnitExSalerno()
        {
            iv_type.set(TYPE_EX);
            iv_model.set(MODEL_SALERNO);

            TARGETING::PrimaryCapabilities l_capabilities = {0};
            iv_interfaces.set(l_capabilities);
        }

        void getAttrInfo(std::vector<AttrInfo>& o_info) const
        {
            Logical::getAttrInfo(o_info);
        }
};

/**
 *  @brief Class describing the data for a core unit
 */
class UnitCoreSalerno : public Logical
{
    public:

        UnitCoreSalerno()
        {
            iv_type.set(TYPE_CORE);
            iv_model.set(MODEL_SALERNO);

            TARGETING::PrimaryCapabilities l_capabilities = {0};
            iv_interfaces.set(l_capabilities);
        }

        void getAttrInfo(std::vector<AttrInfo>& o_info) const
        {
            Logical::getAttrInfo(o_info);
        }
};

/**
 *  @brief Class describing the data for an L3 unit
 */
class UnitL3Salerno : public Logical
{
    public:

        UnitL3Salerno()
        {
            iv_type.set(TYPE_L3);
            iv_model.set(MODEL_SALERNO);

            TARGETING::PrimaryCapabilities l_capabilities = {0};
            iv_interfaces.set(l_capabilities);
        }

        void getAttrInfo(std::vector<AttrInfo>& o_info) const
        {
            Logical::getAttrInfo(o_info);
        }

};

/**
 *  @brief Class describing the data for an L2 unit
 */
class UnitL2Salerno : public Logical
{
    public:

        UnitL2Salerno()
        {
            iv_type.set(TYPE_L2);
            iv_model.set(MODEL_SALERNO);

            TARGETING::PrimaryCapabilities l_capabilities = {0};
            iv_interfaces.set(l_capabilities);
        }

        void getAttrInfo(std::vector<AttrInfo>& o_info) const
        {
            Logical::getAttrInfo(o_info);
        }
};

/**
 *  @brief Class describing the data for an MCA unit
 */
class UnitMcsSalerno : public Logical
{
    public:

        UnitMcsSalerno()
        {
            iv_type.set(TYPE_MCS);
            iv_model.set(MODEL_SALERNO);

            TARGETING::PrimaryCapabilities l_capabilities = {0};
            iv_interfaces.set(l_capabilities);
        }

        void getAttrInfo(std::vector<AttrInfo>& o_info) const
        {
            Logical::getAttrInfo(o_info);
        }

        Property<ATTR_SCOM_SWITCHES,HEAP> iv_scomSwitches;
};

/**
 *  @brief Class describing the data for an MCA unit
 */
class UnitMbaSalerno : public Logical
{
    public:

        UnitMbaSalerno()
        {
            iv_type.set(TYPE_MBA);
            iv_model.set(MODEL_SALERNO);

            TARGETING::PrimaryCapabilities l_capabilities = {0};
            iv_interfaces.set(l_capabilities);
        }

        void getAttrInfo(std::vector<AttrInfo>& o_info) const
        {
            Logical::getAttrInfo(o_info);
        }
};

/**
 *  @brief Class describing the data for the pervasive unit
 */
class UnitPervasiveSalerno : public Logical
{
    public:

        UnitPervasiveSalerno()
        {
            iv_type.set(TYPE_PERVASIVE);
            iv_model.set(MODEL_SALERNO);

            TARGETING::PrimaryCapabilities l_capabilities = {0};
            iv_interfaces.set(l_capabilities);
        }

        void getAttrInfo(std::vector<AttrInfo>& o_info) const
        {
            Logical::getAttrInfo(o_info);
        }

};

class UnitPciSalerno : public Logical
{
    public:

        UnitPciSalerno()
        {
            iv_type.set(TYPE_PCI);
            iv_model.set(MODEL_SALERNO);

            TARGETING::PrimaryCapabilities l_capabilities = {0};
            iv_interfaces.set(l_capabilities);
        }

        void getAttrInfo(std::vector<AttrInfo>& o_info) const
        {
            Logical::getAttrInfo(o_info);
        }
};

class UnitPowerbusSalerno : public Logical
{
    public:

        UnitPowerbusSalerno()
        {
            iv_type.set(TYPE_POWERBUS);
            iv_model.set(MODEL_SALERNO);

            TARGETING::PrimaryCapabilities l_capabilities = {0};
            iv_interfaces.set(l_capabilities);
        }

        void getAttrInfo(std::vector<AttrInfo>& o_info) const
        {
            Logical::getAttrInfo(o_info);
        }
};

class UnitMemPortSalerno : public Logical
{
    public:

        UnitMemPortSalerno()
        {
            iv_type.set(TYPE_MEM_PORT);
            iv_model.set(MODEL_SALERNO);

            TARGETING::PrimaryCapabilities l_capabilities = {0};
            iv_interfaces.set(l_capabilities);
        }

        void getAttrInfo(std::vector<AttrInfo>& o_info) const
        {
            Logical::getAttrInfo(o_info);
        }
};

//******************************************************************************
// PNOR Builder Service
//******************************************************************************

/**
 *  @brief Class which builds fake PNOR image for bringup
 */
class PnorBuilderService
{
    public:

        /**
         *  @brief Initial PNOR sizes
         */
        static const uint32_t PNOR_SIZE = 8000;
        static const uint32_t HEAP_SIZE = 8000;

        /**
         *  @brief Constructs the PnorBuilderService
         */
        PnorBuilderService();

        /**
         *  @brief Destructs the PnorBuilderService
         */
        ~PnorBuilderService();

        /**
         *  @brief Returns pointer to the start of the heap section
         */
        uint8_t* heapBase() const;

        /**
         *  @brief Returns pointer to the start of the PNOR section
         */
        uint8_t* pnorBase() const;

        /**
          *  @brief Clears the PNOR section
          */
        void clearPnorSection();

        /**
         *  @brief Clears the PNOR section
         */
        void clearHeapSection();

        /**
         *  @brief Populates attributes valid attributes for a class/type/model
         *      into the targeting image
         *
         *  @param[in] i_pPnor On input and output, pointer to next valid
         *      location to write to in PNOR
         *  @param[in] i_attrInfo   List of attributes to process
         *  @param[in] o_pAttrNames Pointer to where the list was stored
         */
        void populateValidAttrIds(
                  uint8_t*&              io_pPnor,
            const std::vector<AttrInfo>& i_attrInfo,
                  ATTRIBUTE_ID*&         o_pAttrNames);

        /**
         *  @brief Populates attributes into the targeting image
         *
         *  @param[in] i_pAttrNames Pointer to array of valid attributes for
         *      the class/type/model in question
         *  @param[in/out] io_pPnor On both input and output, a pointer to the
         *      next free position in PNOR to populate.
         *  @param[in/out] io_pHeap On both input and output, a pointer to the
         *      next free position on the heap to populate.
         *  @param[out] o_targets List of targets to serialize
         *  @param[in] i_attrInfo List of attribute infor structures
         */
        void populateAttrs(
                   const ATTRIBUTE_ID*     i_pAttrNames,
                   uint8_t*&               io_pPnor,
                   uint8_t*&               io_pHeap,
                   std::vector< Target* >& o_targets,
             const std::vector<AttrInfo>&  i_attrInfo);

        /**
         *  @brief Builds the targeting image
         */
        void buildTargetingImage();

        /**
         *  @brief Updates caller's pointer with the address of the targeting
         *      layout
         *
         *  @param[out] o_pTargetsArea Pointer to the address of the targeting
         *      layout
         */
        void getTargetingImageBaseAddress(
            const void*& o_pTargetsArea);

        uint8_t* iv_pPnor;
        uint8_t* iv_pHeap;

} PACKED;

typedef Singleton<PnorBuilderService> thePnorBuilderService;

} // End namespace TARGETING

#endif // TARG_FAKEPNORDATA_H
