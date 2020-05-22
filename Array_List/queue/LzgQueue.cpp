//
//  LzgQueue.cpp
//  Array_List
//
//  Created by LiZhengGuo on 2020/5/21.
//  Copyright © 2020 LiZhengGuo. All rights reserved.
//

#include "LzgQueue.hpp"
#include <iostream>
using namespace std;
bool isEmpty(lzgQueuePtr &q)
{
    int rear=q->rear;
    int front=q->front;
    if (rear==front)
    {
        return true;
    }
    return false;
}
bool isFull(lzgQueuePtr &q)
{
    int rear=q->rear;
    int front=q->front;
    if ((rear+1)%(QueueMaxSize+1)==front)
    {
        return true;
    }
    return false;
}
QueueItem *initAItem()
{
    QueueItem *aitem=(QueueItem *)calloc(1, sizeof(QueueItem));
    return aitem;
}
lzgQueue *initAQueue()
{
    lzgQueuePtr queue=(lzgQueuePtr)calloc(1, sizeof(lzgQueue));
    if (queue!=nullptr)
    {
        queue->front=0;
        queue->rear=0;
        queue->queueContent=(QueueItem *)calloc(QueueMaxSize+1, sizeof(QueueItem));
    }
    return queue;
}
void clearAQueue(lzgQueue* &q)
{
    
}
void destoryAQueue(lzgQueue* &q)
{
    delete q;
}
QueueItem *getTheTop(lzgQueue* &q)
{
    QueueItem *ct=q->queueContent;
    int index=q->front;
    QueueItem *nt=ct+index;
    return nt;
}
QueueItem *QueuePop(lzgQueue* &q)
{
    if (isEmpty(q))
    {
        cout<<"queue poped failed because its empty"<<endl;
        return nullptr;
    }
    QueueItem *bg=q->queueContent;
    int index = q->front;
    q->front=(++(q->front))%(QueueMaxSize+1);
    return bg+index;
}
lzgStatus  pushInQueue(lzgQueue* &q,QueueItem *&item)
{
    if (isFull(q))
    {
        cout<<"push failed ,queue is full"<<endl;
        return LzgStatusError;
    }
    int index=q->rear;
    lzgQueuePtr queueptr=q;
    QueueItem *queue=queueptr->queueContent;
    *(queue+index)=*item;
    q->rear=(++(q->rear))%(QueueMaxSize+1);
    return LzgStatusOK;
}
void describeQueue(lzgQueue *&q)
{
    for (int pt=q->front; pt!=q->rear;pt=(++pt)%(QueueMaxSize+1))
    {
        QueueItem *theItem=(q->queueContent)+pt;
        cout<<"item:"<<theItem->num<<endl;
    }
}
