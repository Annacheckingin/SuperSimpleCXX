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
using namespace std;
inline LzgListStatus isIndexValid(int Index,int restrictLenghth);
inline void zeroLizepolynomial(polynomial &e);
LzgListStatus polynomialCompare(polynomial &fe,polynomial &se);
LzgListStatus initList(SqList &L)
{
   L.element=(polynomial*)calloc(LzgListMaxSize,sizeof(polynomial));
    if (L.element==NULL)
    {
        return LzgStatusError;
    }
    L.length=0;
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
//LzgListStatus deleteElement(SqList &L,int index)
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
//
LzgListStatus deleteElement(SqList &L,polynomial &e)
{
    if (L.element==NULL)
    {
        return LzgStatusError;
    }
    for (int k=0; k<L.length; k++)
    {
        if (polynomialCompare(e, L.element[k])==LzgStatusOK)
        {
            zeroLizepolynomial(L.element[k]);
            for (int j=k; j<=L.length; j++)
            {
                L.element[j]=L.element[j+1];
                L.length-=1;
            }
        }
    }
//    for (; index<=L.length; index++)
//    {
//        L.element[index]=L.element[index+1];
//    }
    return LzgStatusOK;
}
//插入
LzgListStatus insertElement(SqList &L,polynomial &e,int index)
{
    if (L.element==NULL)
    {
        cout<<"ptr is NULL"<<endl;
        return LzgStatusError;
    }
    if (isIndexValid(index, L.length)==LzgStatusError)
    {
        cout<<"invalid Index"<<endl;
        return LzgStatusError;
    }
    if (L.length==LzgListMaxSize)
    {
        cout<<"reach the Limit Size"<<endl;
        return LzgStatusError;
    }
    L.length+=1;
    for (int j=L.length; j>index; j--)
    {
        L.element[j]=L.element[j-1];
    }
    L.element[index]=e;
    return LzgStatusOK;
}
//输出所有元素
void destroySqlist(SqList &L)
{
    if (L.element==NULL)
    {
        return;
    }
//    free(L.element);
    delete L.element;
    L.element=NULL;
    L.length=0;
}
//
void clearSqlist(SqList &L)
{   
    for (int k=0; k<L.length; k++)
    {
        zeroLizepolynomial(L.element[k]);
    }
    L.length=0;
}
//
void outPutAllElement(SqList &L)
{
    if (L.element==NULL)
    {
        cout<<"Sqlist is not initialized!"<<endl;
        return;
    }
    if (L.length==0) {
        cout<<"this SQList is empty!"<<endl;
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
    //针对初次L的插入
    if (Index==0&&restrictLenghth==0)
    {
        return LzgStatusOK;
    }
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
