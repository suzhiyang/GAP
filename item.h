/** 
 * item.h
 * Author: Zhiyang Su
 * Created on 2014-08-10.
 */ 

#ifndef ITEM_H
#define ITEM_H

namespace gap
{
class CItem
{
public:
    int m_id;
    int m_weight;
    int m_profit;
    double m_cost; // cost = profit / weight

    int m_assignedbinid;
public:
    CItem();
    CItem(int id, int weight, int profit);
    virtual ~CItem();
    void UpdateCost();
};
};

#endif
