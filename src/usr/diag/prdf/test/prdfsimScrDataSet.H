/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimScrDataSet.H $                  */
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
