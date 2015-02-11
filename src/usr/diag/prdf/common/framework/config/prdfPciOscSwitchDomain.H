/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/prdfPciOscSwitchDomain.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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

#ifndef prdfPciOscDomain_H
#define prdfPciOscDomain_H

#include <iipDomain.h>
#include <prdfExtensibleDomain.H>
#include <prdfParentDomain.H>
#include <prdfRuleChipDomain.H>


namespace PRDF
{
struct PciOscSwitchDetails
{
    ExtensibleChip * pciParentProc;
    TARGETING::TargetHandle_t pciOscCard;
    uint32_t pciOscPosition;
    TARGETING::TargetHandle_t procPciEndPoint;
    TARGETING::TargetHandle_t oscPciEndPoint;
    bool pciOscSwitchDone;
};

typedef std::vector <PciOscSwitchDetails> PciOscConnList;

//------------------------------------------------------------------------------

class PciOscSwitchDomain : public RuleChipDomain, public ExtensibleDomain,
                           public ParentDomain<ExtensibleDomain>
{
  public:

    /**
     * @brief Constructor
     * @param DOMAIN_ID  the domain ID
     */
    PciOscSwitchDomain( DOMAIN_ID domain_id );

    /**
     *  @brief Perform any initialization required by the hardware
     *  @returns error code
     */
    virtual int32_t Initialize(void);

    /**
     * @brief Query if anything in this domain is reporting given attention.
     * @param Attention type to query for. (@see iipsdbug.h)
     * @returns [true|false]
     * @pre Initialize()
     */
    virtual bool Query(ATTENTION_TYPE attentionType);

    /**
     * @brief Analyze errors within the domain
     * @param service data collector
     * @param attentiont type (@see iipsdbug.h)
     * @return return code
     * @pre Initialize(); Query() == true
     * @post domain element order may be modified.
     */
    virtual int32_t Analyze( STEP_CODE_DATA_STRUCT & i_sc,
                           ATTENTION_TYPE attentionType );
protected:

    /**
     * @brief Order the domain - with detecting element at the top
     * @param Attention type (@see iipsdbug.h)
     * @post domain elemenet order may be altered
     * @note this is called by Analyze()
     */
    virtual void Order( ATTENTION_TYPE i_attentionType );

  private: // function

    /**
     * @brief analyzes all the procs reporting switchover from a given pci osc.
     * @param     i_chip  A P8 chip.
     * @param     i_sc    The step code data struct.
     * @param     o_pciOscSwitchData  contains pci osc switch over data.
     * @note this is called by Analyze()
     */
    int32_t  analyzePciOscSwitch( ExtensibleChip * i_chip,
                                STEP_CODE_DATA_STRUCT & i_sc,
                                PciOscConnList & o_pciOscSwitchData );
    /**
     * @brief     clears few bits to reset PCI Osc switch over bit.
     * @param     io_oscSwitchData list of procs connected to faulty PCI OSC.
     * @return    SUCCESS if clearing of bit is success, FAIL otherwise.
     */
    int32_t clearPciSwitchError( PciOscConnList & io_oscSwitchData );

    /**
     * @brief  callout hardware parts and add signature based analysis data.
     * @param   i_sc    The step code data struct.
     * @param   i_pciOscSwitchData contains PCI osc failover data.
     */
    void addHwCalloutAndSignature( STEP_CODE_DATA_STRUCT & i_sc,
                                 PciOscConnList & i_pciOscSwitchData );
    /**
     * @brief checks if there is multiple PCI Osc failure.
     * @param  pciOscSwitchData PCI Osc fault data.
     * @return True if there is multiple PCI Osc failure, false otherwise.
     */
    bool checkMultiOscFailure( PciOscConnList & i_pciOscSwitchData );

    /**
     * @brief finds Rulechip associated with proc target.
     * @param     i_chipTgt   target associated with proc Rulechip.
     * @return    Rulechip associated with proc target
     */
    ExtensibleChip * findChip( TARGETING::TargetHandle_t i_chipTgt );

  private:  // Data
    enum { CONTAINER_SIZE = 16 };


};

inline PciOscSwitchDomain::PciOscSwitchDomain( DOMAIN_ID i_domainId ) :
    RuleChipDomain( i_domainId, PciOscSwitchDomain::CONTAINER_SIZE ),
    ExtensibleDomain( "PciOscSwitchDomain")
{}

} // end namespace PRDF

#endif /* prdfPciOscDomain_H */

