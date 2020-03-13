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
//    LNodeptr anode=L->next;
//    LNodeptr lowestPriceNode=anode;
//    LNodeptr nextNode=anode->next;
//
//    for (LNodeptr preNode=L; anode->next->next!=nullptr; anode=anode->next,preNode=preNode->next,nextNode=nextNode->next)
//    {
//                //
//
//        LNodeptr prefor=preNode;
//        LNodeptr forWardNode=anode;
//        LNodeptr nextforward=forWardNode->next;
//        //
//        for (;forWardNode->next!=nullptr; forWardNode=forWardNode->next,prefor=prefor->next,nextforward=nextforward->next)
//        {
//            printf("x");
//            book *lhbook=lowestPriceNode->data;
//            book *rhbook=forWardNode->data;
//            if (lhbook->price>rhbook->price)
//            {
//                printf("lowest change");
//                lowestPriceNode=forWardNode;
//            }
//
//        }
//        //
////        prefor->next=nextforward;
////        preNode->next=lowestPriceNode;
////        lowestPriceNode->next=nextNode;
//        //
//        prefor->next=lowestPriceNode->next;
////        forWardNode->next=nextforward;
//        preNode->next=lowestPriceNode;
//        lowestPriceNode->next=nextNode;
//        static int i=0;
//        i++;
//        printf("%ld",i);
//    }
//    LNodeptr headestPtr=L;
    LNodeptr preNode=L;
    LNodeptr currentNode=L->next;
    
    for (;currentNode->next!=nullptr; preNode=preNode->next,currentNode=currentNode->next)
    {
//        cout<<"currentNide:"<<currentNode->data->name<<endl;
//        cout<<"nextNodel"<<currentNode->next->data->name<<endl;
//        cout<<"ok"<<endl;
        LNodeptr nextNode=currentNode->next;
        LNodeptr matchPre=preNode;
        LNodeptr minNode=currentNode;
        LNodeptr minnextNode=minNode->next;
        LNodeptr inerBeginNode=currentNode;
     for (;inerBeginNode!=nullptr;
     inerBeginNode=inerBeginNode->next)
        {
//            if (inerBeginNode==nullptr) {
////                cout<<"innerBeginNode:null"<<endl;
//            }
//            cout<<"innerBeginNode:"<<inerBeginNode->data->name<<endl;
//            cout<<"hereh"<<endl;
            book *lh=minNode->data;
            LNodeptr innerNextNode=inerBeginNode->next;
            if (innerNextNode==nullptr)
            {
//                cout<<"gonnan break"<<endl;
                break;
            }
            book *rh=innerNextNode->data;
//            cout<<"compare:"<<lh->price<<"-"<<rh->price<<endl;
            if (lh->price>rh->price)
            {
                matchPre=inerBeginNode;
                minNode=innerNextNode;
                minnextNode=minNode->next;
//                cout<<"minchange-min"<<minNode->data->price<<endl;
            }
        }
//        if (preNode->data!=nullptr) {
//            cout<<preNode->data->price<<endl;
//        }
//        else
//        {
//            cout<<"blank"<<endl;
//        }
//
//        cout<<"current:"<<currentNode->data->price<<endl;
//        if (matchPre->data!=nullptr)
//
//        {
//             cout<<"match"<<matchPre->data->price<<endl;
//        }
//
//        cout<<currentNode->next->data->price<<endl;
//        cout<<minNode->data->price<<endl;
        if (matchPre!=currentNode)
        {
            matchPre->next=currentNode;
        }
        if (minNode->next!=nullptr)
        {
//            cout<<"min->notnull"<<endl;
            preNode->next=minNode;
            minNode->next=nextNode;
            //
            currentNode->next=minnextNode;
//            preNode->next=minNode;
//            minNode->next=currentNode;
            matchPre->next=currentNode;
            currentNode=minNode;
            
        }
        else
        {
//            cout<<"min->null"<<endl;
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
//            if ( matchPre->next!=currentNode)
//            {
//                 matchPre->next=currentNode;
//            }
//            else
//            {
//                matchPre->next=nullptr;
//            }


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
