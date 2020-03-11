//
//  SingleNodeList.hpp
//  Array_List
//
//  Created by LiZhengGuo on 2020/3/11.
//  Copyright © 2020 LiZhengGuo. All rights reserved.
//

#ifndef SingleNodeList_hpp
#define SingleNodeList_hpp
#include "LzgStatus.h"
#include "book.hpp"
#include <stdio.h>

//typedef struct LNode;
typedef struct LNode
{
    book *data;
    LNode *next;
}LNode;
typedef LNode* LNodeptr;
typedef LNode* LNodeList;
//failed with returned value nullptr
LNodeptr creatANode();
LzgListStatus initList(LNodeList &L);
LzgListStatus insertList(LNodeList &L,LNodeptr &n,int index);
LzgListStatus deleteList(LNodeList &L,LNodeptr &n);
LzgListStatus deleteListWithIndex(LNodeList &L,int index);
void outPutAllList(LNodeList &L);
void sortNodeList(LNodeList &L);
//LzgStatusCompare lNodeCompare(LNodeptr lh,LNodeptr rh);
#endif /* SingleNodeList_hpp */
