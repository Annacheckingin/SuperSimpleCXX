//
//  LzgStatus.h
//  Array_List
//
//  Created by LiZhengGuo on 2020/3/11.
//  Copyright © 2020 LiZhengGuo. All rights reserved.
//

#ifndef LzgStatus_h
#define LzgStatus_h

//typedef enum LzgStatus:int LzgStatus
//{
//    LzgStatusOK,
//    LzgStatusError
//};
typedef enum LzgListStatus :int  LzgListStatus;
enum LzgListStatus :int
{
    LzgStatusOK,
    LzgStatusError,
};

typedef LzgListStatus lzgStatus;
//下面是NS_OPTIONS的宏定义，针对C++在NS_ENUM枚举值之间的计算结果无法隐式转化为枚举的底层数据的情况
typedef int LzgStatusCompare;
enum:int{
    LzgStatusCompareBigger=1<<0,
    LzgStatusCompareSmaller=1<<1,
    LzgStatusCompareSame1=1<<2,
   LzgStatusCompareDifferent
};

#endif /* LzgStatus_h */
