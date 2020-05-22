//
//  Stack.cpp
//  Array_List
//
//  Created by LiZhengGuo on 2020/5/19.
//  Copyright © 2020 LiZhengGuo. All rights reserved.
//

#include "Stack.hpp"
#include <iostream>
using namespace std;
lzgStatus  initStack(lzgStackPtr &stack)
{
    lzgStackPtr nodes=(lzgStackPtr)calloc(1, sizeof(LzgStack));
    if (nodes)
    {
         nodes->stackSize=MAXSIZE;
         nodes->top=nodes->base=(stackNodePtr)calloc(MAXSIZE, sizeof(stackNode));
        stack=nodes;
         return LzgStatusOK;
    }
    return LzgStatusError;
}
stackNodePtr pop(lzgStackPtr &stack)
{
    //判断是否为空栈
    if (stack->base==stack->top)
    {
        return nullptr;
    }
    stackNodePtr node=(stack->top)-1;
    (stack->top)--;
    return node;
    
}
lzgStatus initStackNode(stackNodePtr &node)
{
    node=(stackNodePtr)calloc(1, sizeof(stackNode));
    if (node!=nullptr)
    {
        return LzgStatusOK;
    }
    return LzgStatusError;
}
lzgStatus push(lzgStackPtr &stack,stackNodePtr &node)
{
    if ((stack->top)-(stack->base)==MAXSIZE)
    {
        return LzgStatusError;
    }
    *(stack->top)=*node;
    (stack->top)++;
    return LzgStatusOK;
}
bool isEmpty(lzgStackPtr &stack)
{
    if (stack->base==stack->top)
    {
        return 1;
    }
    return 0;
}
void describeStack(lzgStackPtr &stack)
{
    if (stack==nullptr)
   {
       cout<<"stack is null"<<endl;
    return;
    }
    if (isEmpty(stack)==1)
    {
       cout<<"stack is empty"<<endl;
        return;
    }
    stackNodePtr node=--(stack->top);
    while (node!=stack->base)
    {
        cout<<"<<"<<node->num<<endl;
        node--;
    }
    cout<<"<<"<<node->num<<endl;
}
