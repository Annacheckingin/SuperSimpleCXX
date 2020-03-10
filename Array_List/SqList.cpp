//
//  SqList.cpp
//  Array_List
//
//  Created by LiZhengGuo on 2020/3/9.
//  Copyright © 2020 LiZhengGuo. All rights reserved.
//

#include <stdio.h>
#include "SqList.h"
#include <iostream>
#define LzgListMaxSize 100
LzgListStatus initList(SqList &L)
{
   L.element=(polynomial*)calloc(LzgListMaxSize,sizeof(polynomial));
    if (L.element==NULL)
    {
        return LzgStatusError;
    }
    L.length=1;
    return LzgStatusOK;
}
//
LzgListStatus getElement(SqList &L,int index,polynomial &e)
{
   
    if (L.element==NULL)
    {
        return LzgStatusError;
    }
    if (isIndexValid(index, L.length)!=LzgStatusOK)
    {
        return LzgStatusError;
    }
    
}
LzgListStatus findElement(SqList &L,polynomial &e,int &index)
{
     //这里不能对L进行null判断，因为不是一个指针
    if (L.element==NULL)
       {
           return LzgStatusError;
       }
    
    for (int k=0;k<L.length; k++)
    {
        if (polynomialCompare(L.element[k], e)==LzgStatusOK)
        {
            index=k;
            return LzgStatusOK;
        }
    }
//
//       LzgListStatus comResult=polynomialCompare(L.element[index], e);
//       if (comResult==LzgStatusOK)
//       {
//
//           return LzgStatusOK;
//       }
       return LzgStatusError;
}
//
LzgListStatus polynomialCompare(polynomial &fe,polynomial &se)
{
    if (fe.coef!=se.coef)
    {
        return LzgStatusError;
    }
    else if (fe.expn!=se.expn)
    {
        return LzgStatusError;
    }
    return LzgStatusOK;
}
inline LzgListStatus isIndexValid(int Index,int restrictLenghth)
{
    if (Index<restrictLenghth&&Index>=0)
    {
        return LzgStatusOK;
    }
    return LzgStatusError;
}
