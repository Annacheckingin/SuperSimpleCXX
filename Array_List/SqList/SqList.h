//
//  SqList.h
//  Array_List
//
//  Created by LiZhengGuo on 2020/3/9.
//  Copyright © 2020 LiZhengGuo. All rights reserved.
//

#ifndef SqList_h
#define SqList_h
#include "LzgStatus.h"
typedef struct
{
    short coef;
    short expn;
}polynomial;

typedef struct
{
    polynomial *element;
    int length;
}SqList;
//线性表的初始化
LzgListStatus initList(SqList &L);
/*线性表的取值，需要传入被操作线性表的引用，取值的位置；也可以对取值位置的判断是否合法*/
/*这里可以规定，假如返回NULL则表明取值失败，但是这里已经定义好了Status的枚举，所以可以将返回的值，放入参数中来做。**/
LzgListStatus getElement(SqList &L,int index,polynomial &e);
/*顺序表的查找**/
LzgListStatus findElement(SqList &L,polynomial &e,int &index);
/*插入的函数，也需要操作的SqList的引用，然后是插入的对象，返回插入成功与否的状态码**/
LzgListStatus insertElement(SqList &L,polynomial &e,int index);
/*删除的动作**/
LzgListStatus deleteElement(SqList &L,int index);
LzgListStatus deleteElement(SqList &L,polynomial &e);
void clearSqlist(SqList &L);
void destroySqlist(SqList &L);
//LzgListStatus isIndexValid(int Index,int restrictLenghth);
//void zeroLizepolynomial(polynomial &e);
void outPutAllElement(SqList &L);
//LzgListStatus polynomialCompare(polynomial &fe,polynomial &se);
#endif /* SqList_h */

