/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hdat/hdatipmi.H $                                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/**
 *  @file hdatipmi.H
 *
 *  @brief This file contains the class definition for the ipmi sensor data
 *
 */

#ifndef HDATIPMI_H
#define HDATIPMI_H

/*--------------------------------------------------------------------------*/
/* Includes                                                                 */
/*--------------------------------------------------------------------------*/
#include <stdint.h>                   // standard types
#include <hdat/hdat.H>                // HDAT header type definitions
#include "hdathdif.H"                 // HdatHdif base class definition 
#include <hdat/hdat_reasoncodes.H>

namespace HDAT
{

/*--------------------------------------------------------------------------*/
/* Type definitions                                                         */
/*--------------------------------------------------------------------------*/

// The number of data pointers in hdatDataPtrs (defined in hdatipmi.C)
#define HDAT_IPMI_NUM_DATA_PTRS 2
#define HDAT_IPMI_DATA_VERSION 0x0010
#define HDAT_IPMI_PADDING 16

/** @brief eye catcher for the HDIF header for the IPMI  data area*/
const char HDAT_IPMI_STRUCT_NAME[] = "FRUSE ";

/** @enum hdatDataPtrs
 * Enumeration which defines the data sections of the IPMI data
 */
enum hdatIPMIDataPtrs
{
    HDAT_IPMI_FRU_SENSOR_MAPPING      = 0,
    HDAT_IPMI_LED_SENSOR_ID_MAPPING   = 1,
    HDAT_IPMI_DA_LAST                 = 2,
};

struct hdatIPMIFRUSensorMapEntry_t
{
    uint32_t SLCAIndex;
    uint8_t  IPMISensorType;
    uint8_t  IPMISensorID;
    uint16_t Reserved;
}__attribute__ ((packed));

struct hdatIPMILEDSensorMapEntry_t
{
    char     LEDLocCode[80];
    uint8_t  IPMISensorID;
    union {
        uint8_t  value;
        struct {
            uint8_t FaultSupported:1;
            uint8_t BllinkSupported:1;
            uint8_t Reserved1:2;
            uint8_t Blue:1;
            uint8_t Amber:1;
            uint8_t Green:1;
            uint8_t Reserved2:1;
        }LEDCaps;
    } Capabilities;
    uint16_t Reserved;
}__attribute__ ((packed));


/** @brief Defines the IPMI.
 */
struct hdatIPMIData_t
{
    hdatHDIF_t         hdatHdr;
    hdatHDIFDataHdr_t  hdatIPMIIntData[HDAT_IPMI_DA_LAST];
    uint8_t            hdatpadding[16];
} __attribute__ ((packed));



/*----------------------------------------------------------------------------*/
/* C++ class definition                                                       */
/*----------------------------------------------------------------------------*/

/** Begin Class Description
 *
 * @brief  The HdatIpmiData class is used to construct the IPMI Sensor data  object.
 *
 * Description: This class defines a specialized object.  It is not intended
 *      that any component can create an object of this type.
 *
 *      The real purpose of the object is to create the IPMI sensor data 
 *      for all the FRU's in an array format as defined 
 *      by the PHYP Initialization architecture.
 *
 * End Class Description
 */
class HdatIpmi : public HdatHdif
{
    public:
    /**
    * @brief Construct an HdatIpmiData object
    *
    * This is the constructor for the HdatIpmiData object.
    *
    * @pre None
    *
    * @post An HdatIpmiData object pointer would be pointing to the host memory
    *       where the data would be directly written on to the memory.
    *
    * @param[out] o_errlHndl
    *       If any errors occur, the HdatIpmiData object is NOT constructed
    *       and errors are returned in this parameter

    * @param[in] i_msAddr
    *       The main memory address that the IPMI  structure will be populated to.
    *
    * @return A null error log handle if successful, else the return code
    *       pointed to by o_errlHndl.
    *
    */

    HdatIpmi(errlHndl_t &o_errlHndl,
            const hdatMsAddr_t &i_msAddr);

    /**
    * @brief HdatIpmiData object destructor
    *
    *       This is the destructor for an HdatIpmiData object.
    *
    * @pre No preconditions exist
    *
    * @post The HdatIpmiData object has been destroyed and can no longer be used.
    *
    */

   ~HdatIpmi();

   /**
    * @brief Returns IPMI data whole structure size
    */

    uint32_t getIpmiEntrySize();
    /**
     * @brief copies all the ipmi data to mainstore address
     */
    void setIpmiData();

    /** Class (static) Data
    *
    * Only one copy of this data exists in a process.
    * @li cv_actualCnt - a count of how many HdatIpmi objects are created
    */
    static uint32_t   cv_actualCnt;

    private:

    /** Object instance Data
    *
    * @li iv_msAddr         - mainstore phyisical address
    * @li iv_ipmiDataSize   - Size of whole ipmi data structure
    * @li iv_ipmiData       - virtual address for ipmi data
    * @li iv_ipmiFruEntry   - FRU sensor array vactor
    * @li iv_ipmiLedEntry   - LED sensor array vector
    */

    uint64_t        iv_msAddr;
    uint32_t        iv_ipmiDataSize;  // Size of a IPMI entry
    uint8_t *       iv_ipmiData;
    std::vector<hdatIPMIFRUSensorMapEntry_t> iv_ipmiFruEntry;
    std::vector<hdatIPMILEDSensorMapEntry_t> iv_ipmiLedEntry;

};

   /**
    * @brief Load the HdatIpmiData object
    *
    *       This function is used to the load the HdatIpmiData object with all the
    *       sensor data for all the FRU's
    * @param[in]  i_msAddr
    *       Mainstore address to fill up the ipmi data.
    * @param[out] o_size
    *       Size of IPMIData object which are written onto Host memory.
    *
    * @param[out] o_count
    *       Count of IPMI  objects which are written onto Host memory.
    *
    * @pre HdatIpmiData Object should be constructed with the main memory address
    *
    * @post The HdatIpmiData object with all the sensor data  populated.
    *
    * @return A null error log handle if successful, else the return code
    *       pointed to by o_errlHndl.
    */
    errlHndl_t hdatLoadIpmi(const hdatMsAddr_t &i_msAddr,
                        uint32_t &o_size, uint32_t &o_count);



}// HDAT namespace
#endif
