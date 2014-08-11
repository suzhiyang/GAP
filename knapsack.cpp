/** 
 * knapsack.cpp
 * Author: Zhiyang Su
 * Created on 2014-08-10.
 */ 

#include "knapsack.h"
#include "item.h"
#include "bin.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace gap
{
CKnapsack::CKnapsack() : m_maxprofit(-1)
{
}

CKnapsack::~CKnapsack()
{
}

void CKnapsack::AddItem(CItem &item)
{
    m_items.push_back(item);
}

void CKnapsack::SetBin(CBin &bin)
{
    m_bin = bin;
}

void CKnapsack::Print()
{
    cout<<"Bin:"<<m_bin.m_size<<endl;
    cout<<"Items(id, weight, profit):"<<endl;
    for(int i = 0; i < m_items.size(); ++i)
    {
        cout<<m_items[i].m_id<<" "<<m_items[i].m_weight<<" "
            <<m_items[i].m_profit<<endl;
    }
}

void CKnapsack::PrintAssignment()
{
    cout<<"Knapsack assignment (itemid, binid):"<<endl;
    for(int i = 0; i < m_items.size(); ++i)
    {
        if (m_items[i].m_assignedbinid != -1)
            cout<<m_items[i].m_id<<"->"<<m_items[i].m_assignedbinid<<"  ";
    }
    cout<<endl;
}

void CKnapsack::Dp()
{
    /* Here we do not optimize the space usage from O(nW) to O(W),
     * since we need to trace the chose items later.
     */
    vector<vector<int> > d(m_items.size() + 1, vector<int>(m_bin.m_size + 1, 0));
    for(int i = 1; i <= m_items.size(); ++i)
    {
        for(int j = 1; j <= m_bin.m_size; ++j)
        {
            if (m_items[i - 1].m_weight <= j)
            {
                int t = d[i - 1][j - m_items[i - 1].m_weight] + m_items[i - 1].m_profit;
                if (t > d[i - 1][j]) d[i][j] = t;
                else d[i][j] = d[i - 1][j];
            }
            else d[i][j] = d[i - 1][j];
        }
    }
    m_maxprofit = d[m_items.size()][m_bin.m_size];
    // Trace the chose items
    int w = m_bin.m_size;
    for(int i = m_items.size(); i > 0; --i)
    {
        if (d[i][w] != d[i - 1][w])
        {
            // Item i is chose, continue tracing d[i - 1][w - w(i)]
            m_items[i - 1].m_assignedbinid = m_bin.m_id;
            w -= m_items[i - 1].m_weight;
        }
    }
        
    // Print the dp matrix
//     for(int i = 1; i <= m_items.size(); ++i)
//     {
//         for(int j = 0; j <= m_bin.m_size; ++j)
//             cout<<d[i][j]<<" ";
//         cout<<endl;
//     }
}

void CKnapsack::Greedy()
{
}
};
