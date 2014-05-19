/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimScrDataSet.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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

#ifndef SimScrDataSet_h
#define SimScrDataSet_h


#include <vector>
#include <map>
#include <targeting/common/target.H>

namespace PRDF
{

typedef TARGETING::TargetHandle_t ChipId;
typedef uint64_t ScrAddress;

typedef std::vector< unsigned int > DataList;
typedef std::map< ScrAddress, DataList > ScrMap;
typedef std::map< ChipId, ScrMap > ChipMap;

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------
/**
    Keeps tract of a list of vectors containing srcdata
    @author Doug Gilbert
*/
class SimScrDataSet
{
public:

  SimScrDataSet();
  void AddData(const DataList & dl);

  // GetData requires that AddData() has been called at least once
  //  (ie xPile.size() cannot be zero)
  // Promises to return a DataList
  // if more requests for data are made than data Given then the list will rollover
  DataList GetData();

  // query if any data in xPile has never been requested
  bool HasNoHits();



private:  // functions
private:  // Data

  typedef std::vector< DataList > DataPile;

  unsigned int xIteration;     // current iteration
  DataPile xPile;
  DataList xAccessCount;      // number of times data has been accessed dg01
};

typedef std::map<ScrAddress, SimScrDataSet > PreScrMap;
typedef std::map<ChipId, PreScrMap > PreChipMap;

} // End namespace PRDF

#endif /* SimScrDataSet_h */
