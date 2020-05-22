//
//  main.cpp
//  Array_List
//
//  Created by LiZhengGuo on 2020/3/9.
//  Copyright © 2020 LiZhengGuo. All rights reserved.
//

#include <iostream>
#include "SqList.h"
#include "SingleNodeList.hpp"
#include "Stack.hpp"
#include "LzgQueue.hpp"
using namespace std;


int main(int argc, const char * argv[])
{
    SqList L;
   LzgListStatus result= initList(L);
    if (result==LzgStatusOK)
    {
         polynomial x={1,2};
        if (insertElement(L, x, 0)==LzgStatusOK)
        {
             outPutAllElement(L);
        }
        else
        {
            cout<<"failed to output"<<endl;
        }
        
    }
   
    clearSqlist(L);
    outPutAllElement(L);
    destroySqlist(L);
    outPutAllElement(L);
    //初始化NodeList
    LNodeList list;
    LzgListStatus x=initList(list);
    //
    book *abook=creatAbook();
    char *nameOfabook=(char *)malloc(sizeof("C++")+1);
    strcpy(nameOfabook, "C++");
    setName(abook,nameOfabook);
    setPrice(abook, 19);
    
    LNodeptr a=creatANode();
    a->data=abook;
    
    //
    book *bbook=creatAbook();
    setPrice(bbook, 16);
    char *nameOfbbook=(char *)malloc(sizeof("objective-c")+1);
       strcpy(nameOfbbook, "objective-c");
    setName(bbook,(char*) nameOfbbook);
    
    LNodeptr b=creatANode();
    b->data=bbook;
    //
    LNodeptr c=creatANode();
    book *cbook=creatAbook();
    setPrice(cbook, 23);
    char *nameOfcbook=(char *)malloc(sizeof("java")+1);
    strcpy(nameOfcbook, "java");
    setName(cbook,nameOfcbook);
    c->data=cbook;
    //
    LNodeptr d=creatANode();
    book *dbook=creatAbook();
    setPrice(dbook, 2);
    char *nameOfdbook=(char *)malloc(sizeof("python")+1);
    strcpy(nameOfdbook, "python");
    setName(dbook,nameOfdbook);
    d->data=dbook;
    //
    LNodeptr e=creatANode();
    book *ebook=creatAbook();
    setPrice(ebook, 2);
    char *nameOfebook=(char *)malloc(sizeof("swift")+1);
    strcpy(nameOfebook, "swift");
    setName(ebook,nameOfebook);
    e->data=ebook;
    if (x==LzgStatusOK)
    {
        insertList(list, a);
        insertList(list, b);
        insertList(list, c);
        insertList(list, d);
        insertList(list, e);
        outPutAllList(list);
        sortNodeList(list);
        outPutAllList(list);
        LNodeptr anode=getItem(list, 2);
        printLNode(anode);
    }
    //////////////////////////////////////////////////////////////////
    cout<<"stack test begin:"<<endl;
    cout<<endl;
    lzgStackPtr astack=nullptr;
    lzgStatus resultCode=initStack(astack);
    if (resultCode==LzgStatusOK)
    {
        stackNodePtr aNode;
        lzgStatus resultStatus=initStackNode(aNode);
        if (resultStatus==LzgStatusOK)
        {
            aNode->num=1;
            push(astack, aNode);
        }
    }
    
    describeStack(astack);
    pop(astack);
     describeStack(astack);
    stackNodePtr newstackNode;
    lzgStatus res =  initStackNode(newstackNode);
    if (res==LzgStatusOK)
    {
        push(astack, newstackNode);
    }
    describeStack(astack);
    cout<<"Queue Operations:"<<endl;
    
    
    
    lzgQueuePtr aqueue=initAQueue();
    if (aqueue!=nullptr)
    {
        QueueItem *aitem=initAItem();
        aitem->num=0;
        pushInQueue(aqueue, aitem);
        //
        QueueItem *bitem=initAItem();
        bitem->num=1;
        pushInQueue(aqueue, bitem);
        QueueItem *citem=initAItem();
               citem->num=2;
               pushInQueue(aqueue, citem);
        QueueItem *ditem=initAItem();
               ditem->num=3;
               pushInQueue(aqueue, ditem);
        QueueItem *eitem=initAItem();
               eitem->num=4;
               pushInQueue(aqueue, eitem);
        QueueItem *fitem=initAItem();
               fitem->num=5;
               pushInQueue(aqueue, fitem);
        QueuePop(aqueue);
        QueuePop(aqueue);
        QueueItem *gitem=initAItem();
                      gitem->num=6;
                      pushInQueue(aqueue, gitem);
        describeQueue(aqueue);
    }
    else
    {
        cout<<"queue was empty"<<endl;
    }
    return 0;
}
