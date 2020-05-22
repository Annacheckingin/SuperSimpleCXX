//
//  Stack.hpp
//  Array_List
//
//  Created by LiZhengGuo on 2020/5/19.
//  Copyright © 2020 LiZhengGuo. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp
#define MAXSIZE 100U
#include <stdio.h>
#include "LzgStatus.h"
typedef struct
{
    void *data;
    int num;
}stackNode;
typedef stackNode* stackNodePtr;
typedef struct
{
    stackNodePtr top;
    stackNodePtr base;
    int stackSize;
//    stackNodePtr content;这个指针多余了，直接在base指针上面分配内存
}LzgStack;
typedef LzgStack* lzgStackPtr;
//
stackNodePtr getTheTop(lzgStackPtr &stack);

lzgStatus initStackNode(stackNodePtr &node);
lzgStatus  initStack(lzgStackPtr &stack);
stackNodePtr pop(lzgStackPtr &stack);
lzgStatus push(lzgStackPtr &stack,stackNodePtr &node);
bool isEmpty(lzgStackPtr &stack);
void describeStack(lzgStackPtr &stack);
#endif /* Stack_hpp */
