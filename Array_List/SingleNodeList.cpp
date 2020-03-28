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
    anode->next=nullptr;
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
      L=creatANode();
//    LNodeptr node=creatANode();
     L->next=nullptr;
    
    //
    return LzgStatusOK;
}
LNodeptr getItem(LNodeList &list,int index)
{
    if (index<0)
    {
        return nullptr;
    }
    
    LNodeptr headitem=list;
    for (;index>=0;index--)
    {
        if (headitem==nullptr)
        {
            break;
        }
        headitem=headitem->next;
       
    }
    return headitem;
}
LzgListStatus findeNode(LNodeList &L,LNodeptr &anode)
{
    if (anode==nullptr||L==nullptr)
    {
        return LzgStatusError;
    }
    LNodeptr node=L;
    for (;node!=nullptr;node=node->next)
    {
        if (strcmp(node->data->name, anode->data->name)==0)
        {
            
            return LzgStatusOK;
        }
    }
    return LzgStatusError;
}
LzgListStatus copyNode(LNodeptr from,LNodeptr to)
{
    if (from==nullptr||to==nullptr)
    {
        return LzgStatusError;
    }
    strcpy(to->data->name, from->data->name);
    to->next=nullptr;
    return LzgStatusOK;
}
void printLNode(LNodeptr node)
{
    if (node==nullptr)
    {
        cout<<"null node!"<<endl;
    }
    cout<<"node:["<<"name:"<<node->data->name<<" "<<"price:"<<node->data->price<<"]"<<endl;
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
LzgListStatus insertList(LNodeList &L,LNodeptr &n)
{
    LNode *headfor=L;
    for (; headfor->next!=nullptr;headfor=headfor->next);
    headfor->next=n;
    n->next=nullptr;
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
    cout<<"outPut:"<<endl;
//    static int i=0;
    LNodeptr node=L->next;
    if (node==nullptr)
    {
        cout<<"NodeList was not initialized"<<endl;
        return;
    }
    printf("|");
    for (; node!=nullptr; node=node->next)
    {
//        i++;
//        printf("%ld\n",i);
        printf("%s:%lf->",node->data->name,node->data->price);
    }
    cout<<"|"<<endl;
}
void sortNodeList(LNodeList &L)
{
    //冒泡法-按照价格

    LNodeptr preNode=L;
    LNodeptr currentNode=L->next;
    
    for (;currentNode->next!=nullptr; preNode=preNode->next,currentNode=currentNode->next)
    {
        LNodeptr nextNode=currentNode->next;
        LNodeptr matchPre=preNode;
        LNodeptr minNode=currentNode;
        LNodeptr minnextNode=minNode->next;
        LNodeptr inerBeginNode=currentNode;
     for (;inerBeginNode!=nullptr;
     inerBeginNode=inerBeginNode->next)
        {
            book *lh=minNode->data;
            LNodeptr innerNextNode=inerBeginNode->next;
            if (innerNextNode==nullptr)
            {

                break;
            }
            book *rh=innerNextNode->data;

            if (lh->price>rh->price)
            {
                matchPre=inerBeginNode;
                minNode=innerNextNode;
                minnextNode=minNode->next;
            }
        }
        if (matchPre!=currentNode)
        {
            matchPre->next=currentNode;
        }
        if (minNode->next!=nullptr)
        {
            preNode->next=minNode;
            minNode->next=nextNode;
            currentNode->next=minnextNode;
            matchPre->next=currentNode;
            currentNode=minNode;
        }
        else
        {
            preNode->next=minNode;
            if (minNode!=nextNode)
            {
                minNode->next=nextNode;
            }
            else
            {
                minNode->next=currentNode;
                currentNode->next=nullptr;
            }
            currentNode->next=nullptr;
            currentNode=minNode;
        }
    }
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
