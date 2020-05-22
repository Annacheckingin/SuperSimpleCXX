//
//  LzgQueue.hpp
//  Array_List
//
//  Created by LiZhengGuo on 2020/5/21.
//  Copyright © 2020 LiZhengGuo. All rights reserved.
//

#ifndef LzgQueue_hpp
#define LzgQueue_hpp
#define QueueMaxSize 6
#include <stdio.h>
#include "LzgStatus.h"
typedef struct
{
    int num;
}QueueItem;
typedef struct
{
    int  rear;
    int front;
    QueueItem *queueContent;
}lzgQueue;
typedef lzgQueue* lzgQueuePtr;
lzgQueue *initAQueue();
QueueItem *initAItem();
void clearAQueue(lzgQueue* &q);
void destoryAQueue(lzgQueue* &q);
QueueItem *getTheTop(lzgQueue* &q);
QueueItem *QueuePop(lzgQueue* &q);
bool isEmpty(lzgQueuePtr &q);
bool isFull(lzgQueuePtr &q);
lzgStatus  pushInQueue(lzgQueue* &q,QueueItem* &item);
void describeQueue(lzgQueue *&q);
#endif /* LzgQueue_hpp */
