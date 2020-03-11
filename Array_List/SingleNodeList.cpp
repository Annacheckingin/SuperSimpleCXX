//
//  SingleNodeList.cpp
//  Array_List
//
//  Created by LiZhengGuo on 2020/3/11.
//  Copyright © 2020 LiZhengGuo. All rights reserved.
//

#include "SingleNodeList.hpp"
#include <iostream>
using namespace std;
inline void assginLNodeValue(LNodeptr &from,LNodeptr &to);
inline LzgStatusCompare lNodeCompare(LNodeptr lh,LNodeptr rh);
LNodeptr creatANode()
{
    LNodeptr anode=(LNodeptr)calloc(1, sizeof(LNode));
    return anode;
}
LzgListStatus initList(LNodeList &L)
{
    book *abook=creatAbook();
    if (abook==nullptr)
    {
        return LzgStatusError;
    }
//    L->data=abook;
    LNode *node=(LNode *)calloc(1, sizeof(LNode));
    node->next=nullptr;
    node->data=abook;
    //
     L->next=node;
    return LzgStatusOK;
}
LzgListStatus insertList(LNodeList &L,LNodeptr &n,int index)
{
    //跳过头指针
    LNode *headfor=L->next;
    for (int k=0; headfor->next!=nullptr;headfor=headfor->next)
    {
        if (k<index)
        {
            k++;
        }
        else if(k==index)
        {
            assginLNodeValue(headfor, n);
            return LzgStatusOK;
        }
    }
    return LzgStatusError;
}
LzgListStatus deleteList(LNodeList &L,LNodeptr &n)
{
    LNodeptr anode=L->next;
    LNodeptr pre=nullptr;
    bool doseDeleteItem=false;
    for (; anode!=nullptr;pre=anode,anode=anode->next)
    {
        if (lNodeCompare(n, anode)==LzgStatusCompareSame1 )
        {
            pre->next=anode->next;
            anode->next=nullptr;
            free(anode);
            doseDeleteItem=true;
        }
    }
    if (doseDeleteItem==true)
    {
        return LzgStatusOK;
    }
    return LzgStatusError;
}
LzgListStatus deleteListWithIndex(LNodeList &L,int index)
{
    if (L->next==nullptr)
    {
        return LzgStatusError;
    }
    int lenghth=0;
    LNodeptr anode=L->next;
    for (;anode!=nullptr;anode=anode->next)
    {
        lenghth++;
    }
    if (index<0||index>lenghth-1)
    {
        return LzgStatusError;
    }
    LNodeptr anode_a=L->next;
    LNodeptr pre=nullptr;
//    for (;anode_a!=nullptr;pre=anode_a,anode_a=anode_a->next)
//    {
//        index--;
//        if (index==0)
//        {
//            pre->next=anode_a->next;
//            free(anode_a);
//        }
//    }
    
    for (int k=index+1; k>0; k--)
    {
        pre=anode_a;
        anode_a=anode_a->next;
        k--;
    }
    pre->next=anode_a->next;
    free(anode_a);
    return LzgStatusOK;
}
void outPutAllList(LNodeList &L)
{
    
    LNodeptr node=L->next;
    if (node==nullptr)
    {
        cout<<"NodeList was not initialized"<<endl;
    }
    for (; node!=nullptr; node=node->next)
    {
        printf("%s:%lf->",node->data->name,node->data->price);
    }
}
void sortNodeList(LNodeList &L)
{
    //冒泡法-按照价格
    
    
}
inline void assginLNodeValue(LNodeptr &from,LNodeptr &to)
{
    if (to!=nullptr&&from!=nullptr)
    {
        to->data=from->data;
        to->next=from->next;
    }
    
}
inline LzgStatusCompare lNodeCompare(LNodeptr lh,LNodeptr rh)
{
    bool forname=false;
    bool forprice=false;
    char *ls=lh->data->name;
    char *rs=rh->data->name;
    if (strcmp(ls, rs)==0){forname=true;}
//
    float lf=lh->data->price;
    float rf=rh->data->price;
   if(lf==rf){forprice=true;}
    //
   if ((forprice&forprice)==true)
    {
        return LzgStatusCompareSame1;
    }
    return LzgStatusCompareDifferent;
}
