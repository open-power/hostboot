/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMembuf.C $       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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

/** @file  prdfCenMembuf.C
 *  @brief Contains all the plugin code for the PRD Centaur Membuf
 */

#include <iipServiceDataCollector.h>
#include <prdfCalloutUtil.H>
#include <prdfExtensibleChip.H>
#include <prdfMemUtil.H>
#include <prdfPlatServices.H>
#include <prdfPluginMap.H>
#include <prdfGlobal.H>
#include <iipSystem.h>

namespace PRDF
{
namespace Membuf
{

/**
 * @brief Data container for the Centaur Membuf chip.
 */
class CenMembufDataBundle : public DataBundle
{
  public:

    /**
     * @brief Constructor.
     * @param i_membChip The membuf chip.
     */
    CenMembufDataBundle( ExtensibleChip * i_membChip ) :
        iv_analyzeMba1Starvation(false) { };

    /**
     * @brief Destructor.
     */
    ~CenMembufDataBundle() { };

  private: // functions

    CenMembufDataBundle( const CenMembufDataBundle & );
    const CenMembufDataBundle & operator=( const CenMembufDataBundle & );

  public:

    // Toggles to solve MBA1 starvation issue
    bool iv_analyzeMba1Starvation;
};

/**
 * @brief  Wrapper function for the CenMembufDataBundle.
 * @param  i_membChip The centaur chip.
 * @return This centaur's data bundle.
 */
CenMembufDataBundle * getCenMembufDataBundle( ExtensibleChip * i_membChip )
{
    return static_cast<CenMembufDataBundle *>(i_membChip->getDataBundle());
}


//##############################################################################
//
//                             Special plugins
//
//##############################################################################

/**
 * @brief  Plugin that initializes the P8 Centaur Membuf data bundle.
 * @param  i_mbaChip A Centaur Membuf chip.
 * @return SUCCESS
 */
int32_t Initialize( ExtensibleChip * i_mbaChip )
{
    i_mbaChip->getDataBundle() = new CenMembufDataBundle( i_mbaChip );
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( Membuf, Initialize );

//------------------------------------------------------------------------------

/**
 * @fn CheckForRecovered
 * @brief Used when the chip has a CHECK_STOP attention to check for the
 * presence of recovered errors.
 *
 * @param  i_chip       The Centaur chip.
 * @param  o_hasRecovered TRUE if a recoverable attention exists in the Centaur.
 *
 * @return SUCCESS.

 */
int32_t CheckForRecovered(ExtensibleChip * i_chip,
                          bool & o_hasRecovered)
{
    o_hasRecovered = false;

    int32_t l_rc = SUCCESS;

    SCAN_COMM_REGISTER_CLASS * l_grer = i_chip->getRegister("GLOBAL_RE_FIR");
    l_rc = l_grer->Read();

    if ( SUCCESS != l_rc )
    {
        PRDF_ERR("[CheckForRecovered] GLOBAL_RE_FIR read failed"
                 "for 0x%08x", i_chip->GetId());
    }
    else if ( 0 != l_grer->GetBitFieldJustified(1,3) )
    {
        o_hasRecovered = true;
    }

    return SUCCESS;

} PRDF_PLUGIN_DEFINE( Membuf, CheckForRecovered );

//------------------------------------------------------------------------------

/**
 * @brief  MBA0 is always analyzed before MBA1 in the rule code.
 *         This plugin will help prevent starvation of MBA1.
 * @param  i_membChip The Centaur Membuf chip.
 * @param  i_sc     The step code data struct.
 * @return FAIL if MBA1 is not analyzed.
 */
int32_t MBA1_Starvation( ExtensibleChip * i_membChip,
                         STEP_CODE_DATA_STRUCT & i_sc )
{
    using namespace TARGETING;
    CenMembufDataBundle * l_membdb = getCenMembufDataBundle(i_membChip);

    do
    {
        // Get MBA1 chip object
        TargetHandle_t l_mba1Target = NULL;
        TargetHandleList l_mbaList =
            PlatServices::getConnected( i_membChip->GetChipHandle(),
                                        TYPE_MBA );

        TargetHandleList::iterator iter = l_mbaList.begin();
        for( ; iter != l_mbaList.end(); ++iter)
        {
            if( 1 == PlatServices::getTargetPosition( *iter ) )
            {
                l_mba1Target = *iter;
                break;
            }
        }

        if( NULL == l_mba1Target )
        {
            break; // No MBA1 target, exit early
        }

        if ( l_membdb->iv_analyzeMba1Starvation )
        {
            // Get the mem chiplet register
            SCAN_COMM_REGISTER_CLASS * l_memcFir = NULL;
            uint32_t l_checkBits = 0;
            switch ( i_sc.service_data->GetCauseAttentionType() )
            {
                case CHECK_STOP:
                    l_memcFir = i_membChip->getRegister("MEM_CHIPLET_CS_FIR");
                    // mba1 CS: bits 6, 8, 10, 13
                    l_checkBits = 0x02A40000;
                    break;
                case RECOVERABLE:
                    l_memcFir = i_membChip->getRegister("MEM_CHIPLET_RE_FIR");
                    // mba1 RE: bits 4, 6, 8, 11
                    l_checkBits = 0x0A900000;
                    break;
                case SPECIAL:
                    l_memcFir = i_membChip->getRegister("MEM_CHIPLET_SPA");
                    // mba1 SA: bit 1
                    l_checkBits = 0x40000000;
                    break;
                default: ;
            }

            if( NULL == l_memcFir )
            {
                break;
            }

            // Check if MBA1 from Mem Chiplet is reporting an attention
            int32_t l_rc = l_memcFir->Read();
            if ( SUCCESS != l_rc )
            {
                PRDF_ERR("[MBA1_Starvation] SCOM fail on 0x%08x",
                         i_membChip->GetId());
                break;
            }

            uint32_t l_val = l_memcFir->GetBitFieldJustified(0,32);
            if ( 0 == ( l_val & l_checkBits ) )
            {
                break; // No MBA1 attentions
            }

            // MBA0 takes priority next
            l_membdb->iv_analyzeMba1Starvation = false;

            ExtensibleChip * l_mbaChip =
                (ExtensibleChip *)systemPtr->GetChip(l_mba1Target);

            if( NULL == l_mbaChip )
            {
                break; // no MBA1 target, break out
            }

            // Analyze MBA1
            return l_mbaChip->Analyze(i_sc,
                                      i_sc.service_data->GetCauseAttentionType());
        }
        else
        {
            if( NULL != l_mba1Target )
            {
                // MBA1 takes priority next
                l_membdb->iv_analyzeMba1Starvation = true;
            }
        }

    } while (0);

    return FAIL;
}
PRDF_PLUGIN_DEFINE( Membuf, MBA1_Starvation );


//------------------------------------------------------------------------------

/**
 * @brief  Plugin function called after analysis is complete but before PRD
 *         exits.
 * @param  i_membufChip A Centaur Membuf chip.
 * @param  i_sc      The step code data struct.
 * @note   This is especially useful for any analysis that still needs to be
 *         done after the framework clears the FIR bits that were at attention.
 * @return SUCCESS.
 */
int32_t PostAnalysis( ExtensibleChip * i_membufChip,
                      STEP_CODE_DATA_STRUCT & i_sc )
{
    //FIXME: need to implement

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( Membuf, PostAnalysis );


} // end namespace Membuf
} // end namespace PRDF
