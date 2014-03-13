/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/plat/fapiPlatAttrOverrideSync.H $        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
/**
 *  @file fapiPlatAttrOverrideSync.H
 *
 *  @brief Defines the AttrOverrideSync class that contains functions for
 *         Attribute Override and Sync
 */

#ifndef FAPIPLATATTROVERRIDESYNC_H_
#define FAPIPLATATTROVERRIDESYNC_H_

//******************************************************************************
// Includes
//******************************************************************************
#include <stdint.h>
#include <errl/errlentry.H>
#include <mbox/mboxif.H>
#include <fapiAttributeIds.H>
#include <targeting/common/attributeTank.H>

//******************************************************************************
// Interface
//******************************************************************************
namespace fapi
{

// Forward references
class AttrOverrideSync;
class Target;

/**
 *  @brief Return the AttrOverrideSync Singleton. Other modules must call this
 *         rather than using Singleton<>
 *
 *  @return Reference to the AttrOverrideSync Singleton
 */
AttrOverrideSync & theAttrOverrideSync();

/**
 * @class AttrOverrideSync
 *
 * This class contains the FAPI Attribute Override and Sync tanks. It provides
 * functions to:
 * - Monitor for incoming attribute override/sync messages from the FSP
 * - Send attribute override/syncs to the FSP
 * - Return any attribute override on an attribute get
 * - Cancel any non-const attribute override and save the attribute in the sync
 *   tank on an attribute set
 */
class AttrOverrideSync
{
public:
    /**
     * @brief Allow a debug tool to directly access the override tank
     */
    friend void directOverride();

    /**
     * @brief Maximum size of a direct attribute override
     */
    static const size_t MAX_DIRECT_OVERRIDE_ATTR_SIZE_BYTES = 64;

    /**
     * @brief Attribute Override/Sync Mailbox Message Type Constants
     *        These must be kept in sync with FSP firmware
     */
    enum MAILBOX_MSG_TYPE
    {
        MSG_SET_OVERRIDES       = MBOX::FIRST_UNSECURE_MSG + 0x10, // FSP<->Hb
        MSG_CLEAR_ALL_OVERRIDES = MBOX::FIRST_UNSECURE_MSG + 0x11, // FSP<->Hb
        MSG_SET_SYNC_ATTS       = MBOX::FIRST_UNSECURE_MSG + 0x12, // FSP<--Hb
        MSG_GET_OVERRIDES       = MBOX::FIRST_UNSECURE_MSG + 0x13, // FSP<--Hb
    };

    /**
     * @brief Default constructor
     */
    AttrOverrideSync();

    /**
     * @brief Destructor
     */
    ~AttrOverrideSync();

    /**
     * @brief Monitors for incoming attribute override messages from the FSP.
     *        This function never returns and must be called by a task
     *        specifically started to monitor for these messages
     */
    void monitorForFspMessages();

    /**
     * @brief Sends Attribute Overrides and Syncs to the FSP
     *
     * This is called at the end of an IStep. For both FAPI/TARG tanks it:
     * - Clears the FSP Attribute Overrides
     * - Sends the Hostboot Attribute Overrides to the FSP
     * - Sends the Hostboot Attribute Syncs to the FSP
     */
    void sendAttrOverridesAndSyncsToFsp();

    /**
     * @brief Gets Attribute Overrides and Syncs from the FSP
     *
     * This is called at the start of a normal (non-istep) IPL if an attribute
     * is set indicating that the FSP has attribute overrides in place
     */
    void getAttrOverridesFromFsp();

    /**
     * @brief This function gets any Attribute Override on an attribute get
     *
     * This is called for those FAPI Attributes that do not map to Targeting
     * attributes - their overrides live in the FAPI Attribute tanks.
     *
     * @param[in] i_attrId  FAPI Attribute ID
     * @param[in] i_pTarget Pointer to FAPI Target
     * @param[in] o_pVal    Pointer to attribute value
     *
     * @return true if an override exists and was written to o_pVal
     */
    bool getAttrOverride(const fapi::AttributeId i_attrId,
                         const fapi::Target * const i_pTarget,
                         void * o_pVal) const;

    /**
     * @brief This function gets any Attribute Override on an attribute get
     *
     * This is a wrapper that calls getAttrOverride on the AttrOverrideSync
     * singleton, it should be called by external modules to avoid the
     * performance penalty of calling theAttrOverrideSync() then getAttrOverride
     *
     * @param[in] i_attrId  FAPI Attribute ID
     * @param[in] i_pTarget Pointer to FAPI Target
     * @param[in] o_pVal    Pointer to attribute value
     *
     * @return true if an override exists and was written to o_pVal
     */
    static bool getAttrOverrideFunc(const fapi::AttributeId i_attrId,
                                    const fapi::Target * const i_pTarget,
                                    void * o_pVal);

    /**
     * @brief This function performs the actions required on an attribute set
     *
     * This is called for those FAPI Attributes that do not map to Targeting
     * attributes - their overrides/syncs live in the FAPI Attribute tanks.
     *
     * - Any non-const attribute override is cleared
     * - The attribute is saved to be synced to Cronus (if Cronus Sync enabled)
     *
     * @param[in] i_attrId  FAPI Attribute ID
     * @param[in] i_pTarget Pointer to FAPI Target
     * @param[in] i_size    Size of attribute value
     * @param[in] i_pVal    Pointer to attribute value
     */
    void setAttrActions(const fapi::AttributeId i_attrId,
                        const fapi::Target * const i_pTarget,
                        const uint32_t i_size,
                        const void * i_pVal);

    /**
     * @brief This function performs the actions required on an attribute set
     *
     * This is a wrapper that calls setAttrActions on the AttrOverrideSync
     * singleton, it should be called by external modules to avoid the
     * performance penalty of calling theAttrOverrideSync() then setAttrActions
     *
     * @param[in] i_attrId  FAPI Attribute ID
     * @param[in] i_pTarget Pointer to FAPI Target
     * @param[in] i_size    Size of attribute value
     * @param[in] i_pVal    Pointer to attribute value
     */
    static void setAttrActionsFunc(const fapi::AttributeId i_attrId,
                                   const fapi::Target * const i_pTarget,
                                   const uint32_t i_size,
                                   const void * i_pVal);
private:

    /**
     * @brief Utility function that sends attributes to the FSP
     *
     * This function frees the allocated memory in the input vector of chunks
     * and empties the vector
     *
     * @param[in] i_msgType     Message type (ID) to send
     * @param[in] i_tankLayer   Tank Layer to send attribute to
     * @param[io] io_attributes Attributes to send.
     *
     * @return error log handle
     */
    static errlHndl_t sendAttrsToFsp(
        const MAILBOX_MSG_TYPE i_msgType,
        const TARGETING::AttributeTank::TankLayer i_tankLayer,
        std::vector<TARGETING::AttributeTank::AttributeSerializedChunk> &
            io_attributes);

    /**
     * @brief Utility function that gets the target type of a FAPI Target as
     *        used in an attribute tank
     *
     * @param[in] i_pTarget Pointer to FAPI Target (NULL = system)
     *
     * @return Target Type
     */
    static uint32_t getTargetType(const fapi::Target * const i_pTarget);

    // The FAPI Attribute Tanks
    TARGETING::AttributeTank iv_overrideTank;
    TARGETING::AttributeTank iv_syncTank;
};

} // namespace fapi

#endif // FAPIPLATATTROVERRIDESYNC_H_
