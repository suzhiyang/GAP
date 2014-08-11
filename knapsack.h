/** 
 * knapsack.h
 * Author: Zhiyang Su
 * Created on 2014-08-10.
 */ 

#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <vector>
#include "item.h"
#include "bin.h"

using namespace std;

namespace gap
{
/* 0-1 knapsack problem solver
 */
class CKnapsack
{
public:
    CBin m_bin;
    vector<CItem> m_items;
    int m_maxprofit;
private:
    void SortItemsByCost();
public:
    CKnapsack();
    virtual ~CKnapsack();

    void AddItem(CItem &item);
    void SetBin(CBin &bin);

    void Print();
    void PrintAssignment();
    
    void Dp();
    void Greedy(); // 2-approximate algorithm
};
};

#endif
