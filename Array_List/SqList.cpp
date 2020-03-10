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
using namespace std;
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
//取值
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
    e=L.element[index];
    return LzgStatusOK;
}
//查找
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
            //返回参数
            index=k;
            return LzgStatusOK;
        }
    }
       return LzgStatusError;
}
//删除
LzgListStatus deleteElement(SqList &L,int index)
{
    if (L.element==NULL)
    {
        return LzgStatusError;
    }
    if (isIndexValid(index, L.length)==LzgStatusError)
    {
        return LzgStatusError;
    }
    zeroLizepolynomial(L.element[index]);
    for (; index<=L.length; index++)
    {
        L.element[index]=L.element[index+1];
    }
    L.length-=1;
    return LzgStatusOK;
}
//输出所有元素
void outPutAllElement(SqList &L)
{
    if (L.element==NULL)
    {
        cout<<"L is not initialized!"<<endl;
        return;
    }
    for (int k=0; k<L.length; k++)
    {
        cout<<"{"<<L.element[k].coef<<","<<L.element[k].expn<<"}"<<endl;
    }
}
//元素比较
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
//索引是否合法
inline LzgListStatus isIndexValid(int Index,int restrictLenghth)
{
    if (Index<restrictLenghth&&Index>=0)
    {
        return LzgStatusOK;
    }
    return LzgStatusError;
}
inline void zeroLizepolynomial(polynomial &e)
{
    e.coef=0;
    e.expn=0;
}
