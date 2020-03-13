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
    if (x==LzgStatusOK)
    {
        insertList(list, a);
        insertList(list, b);
        insertList(list, c);
        insertList(list, d);
        outPutAllList(list);
        sortNodeList(list);
        outPutAllList(list);
    }
    return 0;
}
