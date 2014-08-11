/** 
 * bin.h
 * Author: Zhiyang Su
 * Created on 2014-08-10.
 */ 

#ifndef BIN_H
#define BIN_H

namespace gap
{
class CBin
{
public:
    int m_id;
    int m_size;

public:
    CBin();
    CBin(int id, int size);
    virtual ~CBin();
};
};

#endif
