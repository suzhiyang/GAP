/** 
 * test.cpp
 * Author: Zhiyang Su
 * Created on 2014-08-10.
 */ 

#include "test.h"
#include "item.h"
#include "bin.h"
#include "knapsack.h"
#include "gap.h"
#include <iostream>
#include <fstream>

using namespace std;

namespace gap
{
void TestKnapsack()
{
    /* Get input data from testcaseforknapsack.txt
     * Format:
     * --------------------------------------
     * item_num bin_size
     * item_size1 item_size2 ...
     * item_profit1 item_profit2 ...
     * --------------------------------------
     */
    ifstream file("testcaseforknapsack.txt");
    int casenum = 1, itemnum, binsize;
    if (file.is_open())
    {
        while(file>>itemnum>>binsize)
        {
            cout<<"Case "<<casenum<<":"<<endl;
            CKnapsack knapsack;
            CBin bin(1, binsize);
            knapsack.SetBin(bin);
            for(int i = 0; i < itemnum; ++i)
            {
                int weight;
                file>>weight;
                CItem item(i + 1, weight, -1);
                knapsack.AddItem(item);
            }
            for(int i = 0; i < itemnum; ++i)
            {
                int profit;
                file>>profit;
                knapsack.m_items[i].m_profit = profit;
            }
            knapsack.Print();
            knapsack.Dp();
            cout<<"Max Profit:"<<knapsack.m_maxprofit<<endl;
            knapsack.PrintAssignment();
            cout<<endl;
            ++casenum;
        }
        file.close();
    }
}

void TestGap()
{
    /* Get input data from testcaseforgap.txt
     * Format:
     * --------------------------------------
     * item_num bin_num
     * bin_size1 bin_size2 ...
     *
     * sizematrix (item_num * bin_num)
     *
     * profitmatrix (item_num * bin_num)
     * --------------------------------------
     */
    ifstream file("testcaseforgap.txt");
    int casenum = 1, itemnum, binnum;
    if (file.is_open())
    {
        while(file>>itemnum>>binnum)
        {
            cout<<"Case "<<casenum<<":"<<endl;
            CGap gap;
            for(int i = 0; i < itemnum; ++i)
            {
                CItem item(i + 1, -1, -1);
                item.m_cost = -1;
                gap.AddItem(item);
            }
            for(int i = 0; i < binnum; ++i)
            {
                int binsize;
                file>>binsize;
                CBin bin(i + 1, binsize);
                gap.AddBin(bin);
            }
            for(int i = 0; i < itemnum; ++i)
            {
                vector<int> line(binnum);
                for(int j = 0; j < binnum; ++j)
                    file>>line[j];
                gap.m_sizematrix.push_back(line);
            }
            for(int i = 0; i < itemnum; ++i)
            {
                vector<int> line(binnum);
                for(int j = 0; j < binnum; ++j)
                    file>>line[j];
                gap.m_profitmatrix.push_back(line);
            }
            gap.Print();
            cout<<endl;
            gap.Approximate();
            ++casenum;
        }
        file.close();
    }
}
};
