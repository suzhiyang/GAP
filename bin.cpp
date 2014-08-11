/** 
 * bin.cpp
 * Author: Zhiyang Su
 * Created on 2014-08-10.
 */ 

#include "bin.h"

namespace gap
{
CBin::CBin() : m_id(-1), m_size(-1)
{
}

CBin::CBin(int id, int size) : m_id(id), m_size(size)
{
}

CBin::~CBin()
{
}
};
