//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/plat/fapiPlatTarget.C $
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
 *  @file platTarget.C
 *
 *  @brief Implements the platform part of the Target class.
 *
 *  Note that platform code must provide the implementation.
 *
 *  FAPI has provided a default implementation for platforms that use the
 *  handle pointer to point to a Component that is not created/deleted when a
 *  Target object is created/deleted (i.e. two Target objects that reference
 *  the same component have the same pointer). It could be possible for a
 *  platform specific ID structure to be created and pointed to each time a new
 *  Target is created, in that case, the pointed to object's type needs to be
 *  be known in order to do a deep compare/copy and a delete.
 */

#include <fapiTarget.H>
#include <fapiPlatTrace.H>
#include <targeting/common/attributes.H>
#include <string.h>

namespace fapi
{

//******************************************************************************
// Compare the handle
//
// If the pointers point to the same component then the handles are the same
//******************************************************************************
bool Target::compareHandle(const Target & i_right) const
{
    return (iv_pHandle == i_right.iv_pHandle);
}

//******************************************************************************
// Copy the handle
//
// Note shallow copy of iv_pHandle. Both Targets point to the same component
//******************************************************************************
void Target::copyHandle(const Target & i_right)
{
    iv_pHandle = i_right.iv_pHandle;
}

//******************************************************************************
// Delete the handle
//******************************************************************************
void Target::deleteHandle()
{
    // Intentionally does nothing. The component must not be deleted
}

//******************************************************************************
// Get the ECMD String
//******************************************************************************
void Target::toString(char (&o_ecmdString)[MAX_ECMD_STRING_LEN]) const
{
    // Extract the HostBoot target pointer
    TARGETING::Target* l_pTarget =
        reinterpret_cast<TARGETING::Target*>(iv_pHandle);

    if (l_pTarget == NULL)
    {
        FAPI_ERR("toString: Called on NULL target");
        strcpy(o_ecmdString, "ecmd-no-target"); 
    }
    else
    {
        // TODO
        // This is a temporary function that constructs the ECMD String from the
        // target's physical path attribute, eventually, the ECMD String will be
        // its own attribute (sourced from the MRW) and this function will be
        // changed to simply get the attribute

        // Try to get the physical path attribute
        TARGETING::EntityPath l_path;
        if (l_pTarget->tryGetAttr<TARGETING::ATTR_PHYS_PATH>(l_path))
        {
            uint32_t l_sizePath = l_path.size();

            // This function returns the ecmd string for chips and chiplets. The
            // output string is:
            // Chiplet: <chip>.<unit> kX:nX:sX:pXX:cX
            // Chip:    <chip> kX:nX:sX:pXX
            // There is officially a tab character between ">" and "k", this is
            // replaced with the number of spaces seen in the Cronus trace
            // If the k.. string is less than 18 chars, it is padded to 18 chars
            // and a single space is added
            //
            // <chip> = chip type ("p8" = processor, "centaur" = memory buffer)
            // <unit> = unit type ("ex", "mcs", "mbs", "mba")
            // kX     = cage number. Always zero
            // nX     = node number. Always zero in HostBoot (right now)
            // sX     = slot number. Always zero
            // pXX    = chip position
            // cX     = unit position
            //
            // Examples:
            //   "p8 k0:n0:s0:p01       "
            //   "p8.ex      k0:n0:s0:p01:c0    "
            //   "p8.mcs     k0:n0:s0:p01:c0    "
            //   "centaur    k0:n0:s0:p01       "
            const char * const ECMD_CHIP_PROC = "p8";
            const char * const ECMD_CHIP_PROC_SPC = " ";
            const char * const ECMD_CHIP_MEMBUF = "centaur";
            const char * const ECMD_CHIP_MEMBUF_SPC = "    ";
            const char * const ECMD_CHIPLET_EX =  "ex      ";
            const char * const ECMD_CHIPLET_MCS = "mcs     ";
            const char * const ECMD_CHIPLET_MBS = "mbs     ";
            const char * const ECMD_CHIPLET_MBA = "mba     ";

            // Look for a chip in the path
            const char * l_pChipType = NULL;
            const char * l_pChipTypeSpc = NULL;
            uint32_t l_chipPos = 0;

            for (uint32_t i = 0; ((i < l_sizePath) && (l_pChipType == NULL));
                 i++)
            {
                if (l_path[i].type == TARGETING::TYPE_PROC)
                {
                    l_pChipType = ECMD_CHIP_PROC;
                    l_pChipTypeSpc = ECMD_CHIP_PROC_SPC;
                    l_chipPos = l_path[i].instance;
                }
                else if (l_path[i].type == TARGETING::TYPE_MEMBUF)
                {
                    l_pChipType = ECMD_CHIP_MEMBUF;
                    l_pChipTypeSpc = ECMD_CHIP_MEMBUF_SPC;
                    l_chipPos = l_path[i].instance;
                }
            }

            if (l_pChipType == NULL)
            {
                FAPI_ERR("toString: Physical Path does not contain known chip");
                strcpy(o_ecmdString, "ecmd-no-chip");
            }
            else
            {
                // Look for the last chiplet in the path (some chiplets are
                // children of other chiplets in PHYS_PATH e.g. MBS->MBA)
                const char * l_pChipletType = NULL;
                uint32_t l_chipletPos = 0;

                for (int32_t i = l_sizePath - 1;
                     ((i >= 0) && (l_pChipletType == NULL));
                     i--)
                {
                    if (l_path[i].type == TARGETING::TYPE_EX)
                    {
                        l_pChipletType = ECMD_CHIPLET_EX;
                        l_chipletPos = l_path[i].instance;
                    }
                    else if (l_path[i].type == TARGETING::TYPE_MCS)
                    {
                        l_pChipletType = ECMD_CHIPLET_MCS;
                        l_chipletPos = l_path[i].instance;
                    }
                    else if (l_path[i].type == TARGETING::TYPE_MBS)
                    {
                        l_pChipletType = ECMD_CHIPLET_MBS;
                        l_chipletPos = l_path[i].instance;
                    }
                    else if (l_path[i].type == TARGETING::TYPE_MBA)
                    {
                        l_pChipletType = ECMD_CHIPLET_MBA;
                        l_chipletPos = l_path[i].instance;
                    }
                }

                // Construct the ecmd string
                char * l_pStr = &o_ecmdString[0];

                // Chip Type
                strcpy(l_pStr, l_pChipType);
                l_pStr += strlen(l_pChipType);

                if (l_pChipletType != NULL)
                {
                    // Chiplet Type
                    *l_pStr = '.';
                    l_pStr++;

                    strcpy(l_pStr, l_pChipletType);
                    l_pStr += strlen(l_pChipletType);
                }
                else
                {
                    strcpy(l_pStr, l_pChipTypeSpc);
                    l_pStr += strlen(l_pChipTypeSpc);
                }

                // Middle of the string
                strcpy(l_pStr, "k0:n0:s0:p");
                l_pStr += strlen("k0:n0:s0:p");

                // Chip Pos (Note that %02d does not appear to work)
                if (l_chipPos >= 10)
                {
                    sprintf(l_pStr, "%d", l_chipPos / 10);
                }
                else
                {
                    *l_pStr = '0';
                }
                l_pStr++;

                sprintf(l_pStr, "%d", l_chipPos % 10);
                l_pStr++;

                if (l_pChipletType != NULL)
                {
                    // Chiplet Pos
                    strcpy(l_pStr, ":c");
                    l_pStr += strlen(":c");
                    sprintf(l_pStr, "%d", l_chipletPos);
                    l_pStr++;

                    // Pad to 18 chars and add a space
                    sprintf(l_pStr, "    ");
                }
                else
                {
                    // Pad to 18 chars and add a space
                    sprintf(l_pStr, "       ");
                }
            }
        }
        else
        {
            FAPI_ERR("toString: Physical Path Attribute does not exist");
            strcpy(o_ecmdString, "ecmd-no-path");
        }
    }
}

}

