/** 
 * item.cpp
 * Author: Zhiyang Su
 * Created on 2014-08-10.
 */ 

#include "item.h"

namespace gap
{
CItem::CItem() : m_id(-1), m_weight(-1), m_profit(-1), m_cost(-1),
                 m_assignedbinid(-1)
{
}

CItem::CItem(int id, int weight, int profit) :
    m_id(id), m_weight(weight), m_profit(profit), m_assignedbinid(-1)
{
    UpdateCost();
}

CItem::~CItem()
{
}

void CItem::UpdateCost()
{
    m_cost = m_profit / m_weight;
}
};
