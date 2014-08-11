/** 
 * gap.h
 * Author: Zhiyang Su
 * Created on 2014-08-10.
 */ 

#ifndef GAP_H
#define GAP_H

#include <vector>
#include "item.h"
#include "bin.h"

using namespace std;

/* Definition of GAP:
 * https://en.wikipedia.org/wiki/Generalized_assignment_problem
 */
namespace gap
{
class CGap
{
public:
    vector<vector<int> > m_sizematrix;
    vector<vector<int> > m_profitmatrix;
    vector<CItem> m_items;
    vector<CBin> m_bins;
    int m_maxprofit;
public:
    CGap();
    ~CGap();

    void AddItem(CItem &item);
    void AddBin(CBin &bin);
    
    void Approximate();
    void Print();
    void PrintAssignment(); // The result is stored in each item object
};
};

#endif
