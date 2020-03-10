//
//  main.cpp
//  Array_List
//
//  Created by LiZhengGuo on 2020/3/9.
//  Copyright © 2020 LiZhengGuo. All rights reserved.
//

#include <iostream>
#include "SqList.h"
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
   
    return 0;
}
